
























#include <stdint.h>
#include <stdlib.h>

#include <vector>

#include "absl/types/span.h"
#include "ortools/base/logging.h"
#include "ortools/sat/cp_model.h"
#include "ortools/sat/cp_model.pb.h"
#include "ortools/sat/cp_model_solver.h"
#include "ortools/util/sorted_interval_list.h"

namespace operations_research {
namespace sat {

void RankingSampleSat() {
  CpModelBuilder cp_model;
  const int kHorizon = 100;
  const int kNumTasks = 4;

  auto add_task_ranking = [&cp_model](absl::Span<const IntVar> starts,
                                      absl::Span<const BoolVar> presences,
                                      absl::Span<const IntVar> ranks) {
    const int num_tasks = starts.size();

    

    std::vector<std::vector<BoolVar>> precedences(num_tasks);
    for (int i = 0; i < num_tasks; ++i) {
      precedences[i].resize(num_tasks);
      for (int j = 0; j < num_tasks; ++j) {
        if (i == j) {
          precedences[i][i] = presences[i];
        } else {
          BoolVar prec = cp_model.NewBoolVar();
          precedences[i][j] = prec;
          cp_model.AddLessOrEqual(starts[i], starts[j]).OnlyEnforceIf(prec);
        }
      }
    }

    

    for (int i = 0; i < num_tasks - 1; ++i) {
      for (int j = i + 1; j < num_tasks; ++j) {
        

        

        cp_model.AddImplication(~presences[i], ~precedences[i][j]);
        cp_model.AddImplication(~presences[i], ~precedences[j][i]);
        

        

        cp_model.AddImplication(~presences[j], ~precedences[i][j]);
        cp_model.AddImplication(~presences[j], ~precedences[j][i]);
        

        

        

        cp_model.AddBoolOr({precedences[i][j], precedences[j][i], ~presences[i],
                            ~presences[j]});
        

        

        cp_model.AddImplication(precedences[i][j], ~precedences[j][i]);
        cp_model.AddImplication(precedences[j][i], ~precedences[i][j]);
      }
    }
    

    for (int i = 0; i < num_tasks; ++i) {
      LinearExpr sum_of_predecessors(-1);
      for (int j = 0; j < num_tasks; ++j) {
        sum_of_predecessors += precedences[j][i];
      }
      cp_model.AddEquality(ranks[i], sum_of_predecessors);
    }
  };

  std::vector<IntVar> starts;
  std::vector<IntVar> ends;
  std::vector<IntervalVar> intervals;
  std::vector<BoolVar> presences;
  std::vector<IntVar> ranks;

  const Domain horizon(0, kHorizon);
  const Domain possible_ranks(-1, kNumTasks - 1);

  for (int t = 0; t < kNumTasks; ++t) {
    const IntVar start = cp_model.NewIntVar(horizon);
    const int64_t duration = t + 1;
    const IntVar end = cp_model.NewIntVar(horizon);
    const BoolVar presence =
        t < kNumTasks / 2 ? cp_model.TrueVar() : cp_model.NewBoolVar();
    const IntervalVar interval =
        cp_model.NewOptionalIntervalVar(start, duration, end, presence);
    const IntVar rank = cp_model.NewIntVar(possible_ranks);

    starts.push_back(start);
    ends.push_back(end);
    intervals.push_back(interval);
    presences.push_back(presence);
    ranks.push_back(rank);
  }

  

  cp_model.AddNoOverlap(intervals);

  

  add_task_ranking(starts, presences, ranks);

  

  cp_model.AddLessThan(ranks[0], ranks[1]);

  

  const IntVar makespan = cp_model.NewIntVar(horizon);
  for (int t = 0; t < kNumTasks; ++t) {
    cp_model.AddLessOrEqual(ends[t], makespan).OnlyEnforceIf(presences[t]);
  }

  

  

  LinearExpr objective = 2 * makespan;
  for (int t = 0; t < kNumTasks; ++t) {
    objective -= 7 * presences[t];
  }
  cp_model.Minimize(objective);

  

  const CpSolverResponse response = Solve(cp_model.Build());
  LOG(INFO) << CpSolverResponseStats(response);

  if (response.status() == CpSolverStatus::OPTIMAL) {
    LOG(INFO) << "Optimal cost: " << response.objective_value();
    LOG(INFO) << "Makespan: " << SolutionIntegerValue(response, makespan);
    for (int t = 0; t < kNumTasks; ++t) {
      if (SolutionBooleanValue(response, presences[t])) {
        LOG(INFO) << "task " << t << " starts at "
                  << SolutionIntegerValue(response, starts[t]) << " with rank "
                  << SolutionIntegerValue(response, ranks[t]);
      } else {
        LOG(INFO) << "task " << t << " is not performed and ranked at "
                  << SolutionIntegerValue(response, ranks[t]);
      }
    }
  }
}

}  

}  


int main() {
  operations_research::sat::RankingSampleSat();

  return EXIT_SUCCESS;
}
































#include <stdlib.h>

#include <numeric>
#include <vector>

#include "absl/strings/str_format.h"
#include "ortools/base/logging.h"
#include "ortools/sat/cp_model.h"
#include "ortools/sat/cp_model.pb.h"
#include "ortools/sat/cp_model_solver.h"



namespace operations_research {
namespace sat {

void AssignmentTeamsSat() {
  

  

  const std::vector<std::vector<int>> costs = {{
      {{90, 76, 75, 70}},
      {{35, 85, 55, 65}},
      {{125, 95, 90, 105}},
      {{45, 110, 95, 115}},
      {{60, 105, 80, 75}},
      {{45, 65, 110, 95}},
  }};
  const int num_workers = static_cast<int>(costs.size());
  std::vector<int> all_workers(num_workers);
  std::iota(all_workers.begin(), all_workers.end(), 0);

  const int num_tasks = static_cast<int>(costs[0].size());
  std::vector<int> all_tasks(num_tasks);
  std::iota(all_tasks.begin(), all_tasks.end(), 0);

  const std::vector<int> team1 = {{0, 2, 4}};
  const std::vector<int> team2 = {{1, 3, 5}};
  

  const int team_max = 2;
  


  

  

  CpModelBuilder cp_model;
  


  

  

  

  

  std::vector<std::vector<BoolVar>> x(num_workers,
                                      std::vector<BoolVar>(num_tasks));
  for (int worker : all_workers) {
    for (int task : all_tasks) {
      x[worker][task] = cp_model.NewBoolVar().WithName(
          absl::StrFormat("x[%d,%d]", worker, task));
    }
  }
  


  

  

  

  for (int worker : all_workers) {
    cp_model.AddAtMostOne(x[worker]);
  }
  

  for (int task : all_tasks) {
    std::vector<BoolVar> tasks;
    for (int worker : all_workers) {
      tasks.push_back(x[worker][task]);
    }
    cp_model.AddExactlyOne(tasks);
  }

  

  LinearExpr team1_tasks;
  for (int worker : team1) {
    for (int task : all_tasks) {
      team1_tasks += x[worker][task];
    }
  }
  cp_model.AddLessOrEqual(team1_tasks, team_max);

  LinearExpr team2_tasks;
  for (int worker : team2) {
    for (int task : all_tasks) {
      team2_tasks += x[worker][task];
    }
  }
  cp_model.AddLessOrEqual(team2_tasks, team_max);
  


  

  

  LinearExpr total_cost;
  for (int worker : all_workers) {
    for (int task : all_tasks) {
      total_cost += x[worker][task] * costs[worker][task];
    }
  }
  cp_model.Minimize(total_cost);
  


  

  

  const CpSolverResponse response = Solve(cp_model.Build());
  


  

  

  if (response.status() == CpSolverStatus::INFEASIBLE) {
    LOG(FATAL) << "No solution found.";
  }
  LOG(INFO) << "Total cost: " << response.objective_value();
  LOG(INFO);
  for (int worker : all_workers) {
    for (int task : all_tasks) {
      if (SolutionBooleanValue(response, x[worker][task])) {
        LOG(INFO) << "Worker " << worker << " assigned to task " << task
                  << ".  Cost: " << costs[worker][task];
      }
    }
  }
  

}
}  

}  


int main(int argc, char** argv) {
  operations_research::sat::AssignmentTeamsSat();
  return EXIT_SUCCESS;
}



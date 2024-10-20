
























#include <algorithm>
#include <cstdint>
#include <numeric>
#include <string>
#include <vector>

#include "absl/flags/flag.h"
#include "absl/log/check.h"
#include "absl/strings/numbers.h"
#include "absl/strings/str_cat.h"
#include "absl/strings/str_split.h"
#include "absl/types/span.h"
#include "ortools/base/init_google.h"
#include "ortools/base/logging.h"
#include "ortools/sat/cp_model.h"
#include "ortools/sat/cp_model.pb.h"
#include "ortools/sat/cp_model_solver.h"
#include "ortools/sat/model.h"
#include "ortools/sat/sat_parameters.pb.h"
#include "ortools/util/filelineiter.h"
#include "ortools/util/sorted_interval_list.h"

ABSL_FLAG(std::string, input, "examples/cpp/wt40.txt", "wt data file name.");
ABSL_FLAG(int, size, 40, "Size of the problem in the wt file.");
ABSL_FLAG(int, n, 28, "1-based instance number in the wt file.");
ABSL_FLAG(std::string, params, "", "Sat parameters in text proto format.");
ABSL_FLAG(int, upper_bound, -1, "If positive, look for a solution <= this.");

namespace operations_research {
namespace sat {



void Solve(absl::Span<const int64_t> durations,
           absl::Span<const int64_t> due_dates,
           absl::Span<const int64_t> weights) {
  const int num_tasks = durations.size();
  CHECK_EQ(due_dates.size(), num_tasks);
  CHECK_EQ(weights.size(), num_tasks);

  

  int horizon = 0;
  for (int i = 0; i < num_tasks; ++i) {
    horizon += durations[i];
    LOG(INFO) << "#" << i << " duration:" << durations[i]
              << " due_date:" << due_dates[i] << " weight:" << weights[i];
  }

  

  

  std::vector<bool> is_taken(num_tasks, false);
  int64_t heuristic_bound = 0;
  int64_t end = horizon;
  for (int i = 0; i < num_tasks; ++i) {
    int next_task = -1;
    int64_t next_cost;
    for (int j = 0; j < num_tasks; ++j) {
      if (is_taken[j]) continue;
      const int64_t cost =
          weights[j] * std::max<int64_t>(0, end - due_dates[j]);
      if (next_task == -1 || cost < next_cost) {
        next_task = j;
        next_cost = cost;
      }
    }
    CHECK_NE(-1, next_task);
    is_taken[next_task] = true;
    end -= durations[next_task];
    heuristic_bound += next_cost;
  }
  LOG(INFO) << "num_tasks: " << num_tasks;
  LOG(INFO) << "The time horizon is " << horizon;
  LOG(INFO) << "Trival cost bound = " << heuristic_bound;

  

  CpModelBuilder cp_model;

  std::vector<IntervalVar> task_intervals(num_tasks);
  std::vector<IntVar> task_starts(num_tasks);
  std::vector<LinearExpr> tardiness_expressions(num_tasks);
  LinearExpr objective;

  for (int i = 0; i < num_tasks; ++i) {
    task_starts[i] = cp_model.NewIntVar(Domain(0, horizon - durations[i]));
    task_intervals[i] =
        cp_model.NewFixedSizeIntervalVar(task_starts[i], durations[i]);

    if (due_dates[i] == 0) {
      tardiness_expressions[i] = task_starts[i] + durations[i];
    } else {
      tardiness_expressions[i] = cp_model.NewIntVar(
          Domain(0, std::max<int64_t>(0, horizon - due_dates[i])));

      

      cp_model.AddGreaterOrEqual(tardiness_expressions[i],
                                 task_starts[i] + durations[i] - due_dates[i]);
    }
    objective += weights[i] * tardiness_expressions[i];
  }

  

  

  

  

  cp_model.AddDecisionStrategy(task_starts,
                               DecisionStrategyProto::CHOOSE_HIGHEST_MAX,
                               DecisionStrategyProto::SELECT_MAX_VALUE);

  cp_model.AddNoOverlap(task_intervals);

  

  

  

  

  

  

  

  

  

  

  

  

  

  cp_model.Minimize(objective);

  

  

  

  

  

  

  

  int num_added_precedences = 0;
  for (int i = 0; i < num_tasks; ++i) {
    for (int j = 0; j < num_tasks; ++j) {
      if (i == j) continue;
      if (due_dates[i] <= due_dates[j] && durations[i] <= durations[j] &&
          weights[i] >= weights[j]) {
        

        

        if (due_dates[i] == due_dates[j] && durations[i] == durations[j] &&
            weights[i] == weights[j] && i > j) {
          continue;
        }

        ++num_added_precedences;
        cp_model.AddLessOrEqual(task_starts[i] + durations[i], task_starts[j]);
      }
    }
  }
  LOG(INFO) << "Added " << num_added_precedences
            << " precedences that will not affect the optimal solution value.";

  

  

  

  

  Model model;
  model.Add(NewSatParameters(absl::GetFlag(FLAGS_params)));
  model.GetOrCreate<SatParameters>()->set_log_search_progress(true);
  model.Add(NewFeasibleSolutionObserver([&, due_dates, durations,
                                         weights](const CpSolverResponse& r) {
    

    

    

    


    int64_t objective = 0;
    for (int i = 0; i < num_tasks; ++i) {
      const int64_t end =
          SolutionIntegerValue(r, task_starts[i]) + durations[i];
      objective += weights[i] * std::max<int64_t>(0, end - due_dates[i]);
    }
    LOG(INFO) << "Cost " << objective;

    

    std::vector<int> sorted_tasks(num_tasks);
    std::iota(sorted_tasks.begin(), sorted_tasks.end(), 0);
    std::sort(sorted_tasks.begin(), sorted_tasks.end(), [&](int v1, int v2) {
      return SolutionIntegerValue(r, task_starts[v1]) <
             SolutionIntegerValue(r, task_starts[v2]);
    });
    std::string solution = "0";
    int end = 0;
    for (const int i : sorted_tasks) {
      const int64_t cost =
          weights[i] * SolutionIntegerValue(r, tardiness_expressions[i]);
      absl::StrAppend(&solution, "| #", i, " ");
      if (cost > 0) {
        

        absl::StrAppend(&solution, "\033[1;31m(+", cost, ") \033[0m");
      }
      absl::StrAppend(&solution, "|",
                      SolutionIntegerValue(r, task_starts[i]) + durations[i]);
      end += durations[i];
    }
    LOG(INFO) << "solution: " << solution;
  }));

  

  const CpSolverResponse response = SolveCpModel(cp_model.Build(), &model);
}

void ParseAndSolve() {
  std::vector<int> numbers;
  std::vector<std::string> entries;
  for (const std::string& line : FileLines(absl::GetFlag(FLAGS_input))) {
    entries = absl::StrSplit(line, ' ', absl::SkipEmpty());
    for (const std::string& entry : entries) {
      numbers.push_back(0);
      CHECK(absl::SimpleAtoi(entry, &numbers.back()));
    }
  }

  const int instance_size = absl::GetFlag(FLAGS_size) * 3;
  LOG(INFO) << numbers.size() << " numbers in '" << absl::GetFlag(FLAGS_input)
            << "'.";
  LOG(INFO) << "This correspond to " << numbers.size() / instance_size
            << " instances of size " << absl::GetFlag(FLAGS_size);
  LOG(INFO) << "Loading instance #" << absl::GetFlag(FLAGS_n);
  CHECK_GE(absl::GetFlag(FLAGS_n), 0);
  CHECK_LE(absl::GetFlag(FLAGS_n) * instance_size, numbers.size());

  

  int index = (absl::GetFlag(FLAGS_n) - 1) * instance_size;
  std::vector<int64_t> durations;
  for (int j = 0; j < absl::GetFlag(FLAGS_size); ++j)
    durations.push_back(numbers[index++]);
  std::vector<int64_t> weights;
  for (int j = 0; j < absl::GetFlag(FLAGS_size); ++j)
    weights.push_back(numbers[index++]);
  std::vector<int64_t> due_dates;
  for (int j = 0; j < absl::GetFlag(FLAGS_size); ++j)
    due_dates.push_back(numbers[index++]);

  Solve(durations, due_dates, weights);
}

}  

}  


int main(int argc, char** argv) {
  absl::SetFlag(&FLAGS_stderrthreshold, 0);
  InitGoogle(argv[0], &argc, &argv, true);
  if (absl::GetFlag(FLAGS_input).empty()) {
    LOG(FATAL) << "Please supply a data file with --input=";
  }
  operations_research::sat::ParseAndSolve();
  return EXIT_SUCCESS;
}

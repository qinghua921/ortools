






























#include <stdlib.h>

#include <atomic>
#include <map>
#include <numeric>
#include <string>
#include <tuple>
#include <vector>

#include "absl/strings/str_format.h"
#include "ortools/base/logging.h"
#include "ortools/sat/cp_model.h"
#include "ortools/sat/cp_model.pb.h"
#include "ortools/sat/cp_model_solver.h"
#include "ortools/sat/model.h"
#include "ortools/sat/sat_parameters.pb.h"
#include "ortools/util/time_limit.h"



namespace operations_research {
namespace sat {

void NurseSat() {
  

  const int num_nurses = 4;
  const int num_shifts = 3;
  const int num_days = 3;

  std::vector<int> all_nurses(num_nurses);
  std::iota(all_nurses.begin(), all_nurses.end(), 0);

  std::vector<int> all_shifts(num_shifts);
  std::iota(all_shifts.begin(), all_shifts.end(), 0);

  std::vector<int> all_days(num_days);
  std::iota(all_days.begin(), all_days.end(), 0);
  


  

  

  CpModelBuilder cp_model;
  


  

  

  

  std::map<std::tuple<int, int, int>, BoolVar> shifts;
  for (int n : all_nurses) {
    for (int d : all_days) {
      for (int s : all_shifts) {
        auto key = std::make_tuple(n, d, s);
        shifts[key] = cp_model.NewBoolVar().WithName(
            absl::StrFormat("shift_n%dd%ds%d", n, d, s));
      }
    }
  }
  


  

  

  for (int d : all_days) {
    for (int s : all_shifts) {
      std::vector<BoolVar> nurses;
      for (int n : all_nurses) {
        auto key = std::make_tuple(n, d, s);
        nurses.push_back(shifts[key]);
      }
      cp_model.AddExactlyOne(nurses);
    }
  }
  


  

  

  for (int n : all_nurses) {
    for (int d : all_days) {
      std::vector<BoolVar> work;
      for (int s : all_shifts) {
        auto key = std::make_tuple(n, d, s);
        work.push_back(shifts[key]);
      }
      cp_model.AddAtMostOne(work);
    }
  }
  


  

  

  

  

  

  int min_shifts_per_nurse = (num_shifts * num_days) / num_nurses;
  int max_shifts_per_nurse;
  if ((num_shifts * num_days) % num_nurses == 0) {
    max_shifts_per_nurse = min_shifts_per_nurse;
  } else {
    max_shifts_per_nurse = min_shifts_per_nurse + 1;
  }
  for (int n : all_nurses) {
    std::vector<BoolVar> shifts_worked;
    for (int d : all_days) {
      for (int s : all_shifts) {
        auto key = std::make_tuple(n, d, s);
        shifts_worked.push_back(shifts[key]);
      }
    }
    cp_model.AddLessOrEqual(min_shifts_per_nurse,
                            LinearExpr::Sum(shifts_worked));
    cp_model.AddLessOrEqual(LinearExpr::Sum(shifts_worked),
                            max_shifts_per_nurse);
  }
  


  

  Model model;
  SatParameters parameters;
  parameters.set_linearization_level(0);
  

  parameters.set_enumerate_all_solutions(true);
  model.Add(NewSatParameters(parameters));
  


  

  

  

  std::atomic<bool> stopped(false);
  model.GetOrCreate<TimeLimit>()->RegisterExternalBooleanAsLimit(&stopped);

  const int kSolutionLimit = 5;
  int num_solutions = 0;
  model.Add(NewFeasibleSolutionObserver([&](const CpSolverResponse& r) {
    LOG(INFO) << "Solution " << num_solutions;
    for (int d : all_days) {
      LOG(INFO) << "Day " << std::to_string(d);
      for (int n : all_nurses) {
        bool is_working = false;
        for (int s : all_shifts) {
          auto key = std::make_tuple(n, d, s);
          if (SolutionIntegerValue(r, shifts[key])) {
            is_working = true;
            LOG(INFO) << "  Nurse " << std::to_string(n) << " works shift "
                      << std::to_string(s);
          }
        }
        if (!is_working) {
          LOG(INFO) << "  Nurse " << std::to_string(n) << " does not work";
        }
      }
    }
    num_solutions++;
    if (num_solutions >= kSolutionLimit) {
      stopped = true;
      LOG(INFO) << "Stop search after " << kSolutionLimit << " solutions.";
    }
  }));
  


  

  const CpSolverResponse response = SolveCpModel(cp_model.Build(), &model);
  


  

  

  LOG(INFO) << "Statistics";
  LOG(INFO) << CpSolverResponseStats(response);
  LOG(INFO) << "solutions found : " << std::to_string(num_solutions);
  

}

}  

}  


int main() {
  operations_research::sat::NurseSat();
  return EXIT_SUCCESS;
}


































#include <stdlib.h>

#include <cstdint>
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



namespace operations_research {
namespace sat {

void ScheduleRequestsSat() {
  

  const int num_nurses = 5;
  const int num_days = 7;
  const int num_shifts = 3;

  std::vector<int> all_nurses(num_nurses);
  std::iota(all_nurses.begin(), all_nurses.end(), 0);

  std::vector<int> all_days(num_days);
  std::iota(all_days.begin(), all_days.end(), 0);

  std::vector<int> all_shifts(num_shifts);
  std::iota(all_shifts.begin(), all_shifts.end(), 0);

  std::vector<std::vector<std::vector<int64_t>>> shift_requests = {
      {
          {0, 0, 1},
          {0, 0, 0},
          {0, 0, 0},
          {0, 0, 0},
          {0, 0, 1},
          {0, 1, 0},
          {0, 0, 1},
      },
      {
          {0, 0, 0},
          {0, 0, 0},
          {0, 1, 0},
          {0, 1, 0},
          {1, 0, 0},
          {0, 0, 0},
          {0, 0, 1},
      },
      {
          {0, 1, 0},
          {0, 1, 0},
          {0, 0, 0},
          {1, 0, 0},
          {0, 0, 0},
          {0, 1, 0},
          {0, 0, 0},
      },
      {
          {0, 0, 1},
          {0, 0, 0},
          {1, 0, 0},
          {0, 1, 0},
          {0, 0, 0},
          {1, 0, 0},
          {0, 0, 0},
      },
      {
          {0, 0, 0},
          {0, 0, 1},
          {0, 1, 0},
          {0, 0, 0},
          {1, 0, 0},
          {0, 1, 0},
          {0, 0, 0},
      },
  };
  


  

  

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
    LinearExpr num_worked_shifts;
    for (int d : all_days) {
      for (int s : all_shifts) {
        auto key = std::make_tuple(n, d, s);
        num_worked_shifts += shifts[key];
      }
    }
    cp_model.AddLessOrEqual(min_shifts_per_nurse, num_worked_shifts);
    cp_model.AddLessOrEqual(num_worked_shifts, max_shifts_per_nurse);
  }
  


  

  LinearExpr objective_expr;
  for (int n : all_nurses) {
    for (int d : all_days) {
      for (int s : all_shifts) {
        if (shift_requests[n][d][s] == 1) {
          auto key = std::make_tuple(n, d, s);
          objective_expr += shifts[key] * shift_requests[n][d][s];
        }
      }
    }
  }
  cp_model.Maximize(objective_expr);
  


  

  const CpSolverResponse response = Solve(cp_model.Build());
  


  

  if (response.status() == CpSolverStatus::OPTIMAL) {
    LOG(INFO) << "Solution:";
    for (int d : all_days) {
      LOG(INFO) << "Day " << std::to_string(d);
      for (int n : all_nurses) {
        for (int s : all_shifts) {
          auto key = std::make_tuple(n, d, s);
          if (SolutionIntegerValue(response, shifts[key]) == 1) {
            if (shift_requests[n][d][s] == 1) {
              LOG(INFO) << "  Nurse " << std::to_string(n) << " works shift "
                        << std::to_string(s) << " (requested).";
            } else {
              LOG(INFO) << "  Nurse " << std::to_string(n) << " works shift "
                        << std::to_string(s) << " (not requested).";
            }
          }
        }
      }
      LOG(INFO) << "";
    }
    LOG(INFO) << "Number of shift requests met = " << response.objective_value()
              << " (out of " << num_nurses * min_shifts_per_nurse << ")";
  } else {
    LOG(INFO) << "No optimal solution found !";
  }
  


  

  

  LOG(INFO) << "Statistics";
  LOG(INFO) << CpSolverResponseStats(response);
  

}

}  

}  


int main() {
  operations_research::sat::ScheduleRequestsSat();
  return EXIT_SUCCESS;
}



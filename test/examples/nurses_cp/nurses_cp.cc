
























#include <array>
#include <iterator>
#include <numeric>  

#include <sstream>
#include <vector>

#include "absl/flags/flag.h"
#include "absl/log/flags.h"
#include "ortools/base/init_google.h"
#include "ortools/base/logging.h"
#include "ortools/constraint_solver/constraint_solver.h"

namespace operations_research {
void SolveNursesExample() {
  

  Solver solver("NursesExample");
  std::array<int, 4> nurses;
  std::iota(std::begin(nurses), std::end(nurses), 0);
  {
    std::ostringstream oss;
    for (auto i : nurses) oss << ' ' << i;
    LOG(INFO) << "Nurses:" << oss.str();
  }

  

  std::array<int, 4> shifts;
  std::iota(std::begin(shifts), std::end(shifts), 0);
  {
    std::ostringstream oss;
    for (auto i : shifts) oss << ' ' << i;
    LOG(INFO) << "Shifts:" << oss.str();
  }

  std::array<int, 7> days;
  std::iota(std::begin(days), std::end(days), 0);
  {
    std::ostringstream oss;
    for (auto i : days) oss << ' ' << i;
    LOG(INFO) << "Days:" << oss.str();
  }

  

  std::vector<std::vector<IntVar*>> shifts_matrix(nurses.size());
  std::vector<IntVar*> shifts_flat;
  for (const auto nurse : nurses) {
    for (const auto day : days) {
      std::ostringstream oss;
      oss << "shifts(nurse: " << nurse << ", day: " << day << ")";
      IntVar* var = solver.MakeIntVar(shifts.front(), shifts.back(), oss.str());
      shifts_matrix[nurse].push_back(var);
      shifts_flat.push_back(var);
    }
  }

  

  std::vector<std::vector<IntVar*>> nurses_matrix(shifts.size());
  for (const auto shift : shifts) {
    for (const auto day : days) {
      std::ostringstream oss;
      oss << "nurses(shift: " << shift << ", day: " << day << ")";
      IntVar* var = solver.MakeIntVar(nurses.front(), nurses.back(), oss.str());
      nurses_matrix[shift].push_back(var);
    }
  }

  

  for (const auto day : days) {
    std::vector<IntVar*> nurses_for_day(shifts.size());
    for (const auto shift : shifts) {
      nurses_for_day[shift] = nurses_matrix[shift][day];
    }
    for (const auto nurse : nurses) {
      IntVar* s = shifts_matrix[nurse][day];
      solver.AddConstraint(
          solver.MakeEquality(solver.MakeElement(nurses_for_day, s), nurse));
    }
  }

  

  for (const auto day : days) {
    

    std::vector<IntVar*> shifts_for_day(nurses.size());
    for (const auto nurse : nurses) {
      shifts_for_day[nurse] = shifts_matrix[nurse][day];
    }
    solver.AddConstraint(solver.MakeAllDifferent(shifts_for_day));

    

    std::vector<IntVar*> nurses_for_day(shifts.size());
    for (const auto shift : shifts) {
      nurses_for_day[shift] = nurses_matrix[shift][day];
    }
    solver.AddConstraint(solver.MakeAllDifferent(nurses_for_day));
  }

  

  for (const auto nurse : nurses) {
    std::vector<IntVar*> nurse_is_working;
    for (const auto day : days) {
      nurse_is_working.push_back(
          solver.MakeIsGreaterOrEqualCstVar(shifts_matrix[nurse][day], 1));
    }
    solver.AddConstraint(solver.MakeSumGreaterOrEqual(nurse_is_working, 5));
    solver.AddConstraint(solver.MakeSumLessOrEqual(nurse_is_working, 6));
  }

  

  

  

  std::vector<std::vector<IntVar*>> works_shift_matrix(nurses.size());
  for (const auto nurse : nurses) {
    for (const auto shift : shifts) {
      std::ostringstream oss;
      oss << "work_shift(nurse: " << nurse << ", shift: " << shift << ")";
      works_shift_matrix[nurse].push_back(solver.MakeBoolVar(oss.str()));
    }
  }

  for (const auto nurse : nurses) {
    for (const auto shift : shifts) {
      std::vector<IntVar*> shift_s_for_nurse;
      for (const auto day : days) {
        shift_s_for_nurse.push_back(
            solver.MakeIsEqualCstVar(shifts_matrix[nurse][day], shift));
      }
      solver.AddConstraint(
          solver.MakeEquality(works_shift_matrix[nurse][shift],
                              solver.MakeMax(shift_s_for_nurse)->Var()));
    }
  }

  

  

  for (std::size_t shift = 1; shift < shifts.size(); ++shift) {
    std::vector<IntVar*> nurses_for_shift;
    for (const auto nurse : nurses) {
      nurses_for_shift.push_back(works_shift_matrix[nurse][shift]);
    }
    solver.AddConstraint(solver.MakeSumLessOrEqual(nurses_for_shift, 2));
  }

  

  

  for (const auto shift : {2, 3}) {
    for (const auto day : days) {
      IntVar* v0 = solver.MakeIsEqualVar(nurses_matrix[shift][day],
                                         nurses_matrix[shift][(day + 1) % 7]);
      IntVar* v1 = solver.MakeIsEqualVar(nurses_matrix[shift][(day + 1) % 7],
                                         nurses_matrix[shift][(day + 2) % 7]);
      solver.AddConstraint(solver.MakeEquality(solver.MakeMax(v0, v1), 1));
    }
  }

  


  

  DecisionBuilder* const main_phase = solver.MakePhase(
      shifts_flat, Solver::CHOOSE_FIRST_UNBOUND, Solver::ASSIGN_MIN_VALUE);

  

  SearchMonitor* const search_log = nullptr;

  SearchLimit* limit = nullptr;

  

  SolutionCollector* const collector = solver.MakeAllSolutionCollector();
  collector->Add(shifts_flat);

  

  solver.Solve(main_phase, search_log, nullptr, limit, collector);
  LOG(INFO) << "Number of solutions: " << collector->solution_count();
  LOG(INFO) << "";

  

  std::array<int, 4> a_few_solutions = {859, 2034, 5091, 7003};
  for (const auto solution : a_few_solutions) {
    LOG(INFO) << "Solution " << solution << ":";
    for (const auto day : days) {
      LOG(INFO) << "Day " << day << ":";
      for (const auto nurse : nurses) {
        LOG(INFO) << "Nurse " << nurse << " assigned to Task "
                  << collector->Value(solution,
                                      shifts_flat[nurse * days.size() + day]);
      }
    }
  }
  LOG(INFO) << "Advanced usage:";
  LOG(INFO) << "Time: " << solver.wall_time() << "ms";
}
}  


int main(int argc, char** argv) {
  InitGoogle(argv[0], &argc, &argv, true);
  absl::SetFlag(&FLAGS_stderrthreshold, 0);
  operations_research::SolveNursesExample();
  return EXIT_SUCCESS;
}

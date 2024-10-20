
































#include <vector>

#include "absl/log/flags.h"
#include "ortools/base/init_google.h"
#include "ortools/base/logging.h"
#include "ortools/constraint_solver/constraint_solver.h"
#include "ortools/constraint_solver/constraint_solveri.h"

namespace operations_research {
class OneVarLns : public BaseLns {
 public:
  explicit OneVarLns(const std::vector<IntVar*>& vars)
      : BaseLns(vars), index_(0) {}

  ~OneVarLns() override {}

  void InitFragments() override { index_ = 0; }

  bool NextFragment() override {
    if (index_ < Size()) {
      AppendToFragment(index_);
      ++index_;
      return true;
    } else {
      return false;
    }
  }

 private:
  int index_;
};

class MoveOneVar : public IntVarLocalSearchOperator {
 public:
  explicit MoveOneVar(const std::vector<IntVar*>& variables)
      : IntVarLocalSearchOperator(variables),
        variable_index_(0),
        move_up_(false) {}

  ~MoveOneVar() override {}

 protected:
  

  bool MakeOneNeighbor() override {
    const int64_t current_value = OldValue(variable_index_);
    if (move_up_) {
      SetValue(variable_index_, current_value + 1);
      variable_index_ = (variable_index_ + 1) % Size();
    } else {
      SetValue(variable_index_, current_value - 1);
    }
    move_up_ = !move_up_;
    return true;
  }

 private:
  void OnStart() override {
    CHECK_GE(variable_index_, 0);
    CHECK_LT(variable_index_, Size());
  }

  

  int64_t variable_index_;
  

  bool move_up_;
};

class SumFilter : public IntVarLocalSearchFilter {
 public:
  explicit SumFilter(const std::vector<IntVar*>& vars)
      : IntVarLocalSearchFilter(vars), sum_(0) {}

  ~SumFilter() override {}

  void OnSynchronize(const Assignment* delta) override {
    sum_ = 0;
    for (int index = 0; index < Size(); ++index) {
      sum_ += Value(index);
    }
  }

  bool Accept(const Assignment* delta, const Assignment* unused_deltadelta,
              int64_t objective_min, int64_t objective_max) override {
    const Assignment::IntContainer& solution_delta = delta->IntVarContainer();
    const int solution_delta_size = solution_delta.Size();

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    for (int i = 0; i < solution_delta_size; ++i) {
      if (!solution_delta.Element(i).Activated()) {
        VLOG(1) << "Element #" << i << " of the delta assignment given to"
                << " SumFilter::Accept() is not activated (i.e. its variable"
                << " is not bound to a single value anymore). This means that"
                << " we are in a LNS phase, and the DobbleFilter won't be able"
                << " to filter anything. Returning true.";
        return true;
      }
    }
    int64_t new_sum = sum_;
    VLOG(1) << "No LNS, size = " << solution_delta_size;
    for (int index = 0; index < solution_delta_size; ++index) {
      int64_t touched_var = -1;
      FindIndex(solution_delta.Element(index).Var(), &touched_var);
      const int64_t old_value = Value(touched_var);
      const int64_t new_value = solution_delta.Element(index).Value();
      new_sum += new_value - old_value;
    }
    VLOG(1) << "new sum = " << new_sum << ", old sum = " << sum_;
    return new_sum < sum_;
  }

 private:
  int64_t sum_;
};

enum SolveType { LNS, LS, LS_WITH_FILTER };

void SolveProblem(SolveType solve_type) {
  Solver s("Sample");
  std::vector<IntVar*> vars;
  s.MakeIntVarArray(4, 0, 4, &vars);
  IntVar* const sum_var = s.MakeSum(vars)->Var();
  OptimizeVar* const obj = s.MakeMinimize(sum_var, 1);
  DecisionBuilder* const db =
      s.MakePhase(vars, Solver::CHOOSE_FIRST_UNBOUND, Solver::ASSIGN_MAX_VALUE);
  DecisionBuilder* ls = nullptr;
  switch (solve_type) {
    case LNS: {
      LOG(INFO) << "Large Neighborhood Search";
      OneVarLns* const one_var_lns = s.RevAlloc(new OneVarLns(vars));
      LocalSearchPhaseParameters* const ls_params =
          s.MakeLocalSearchPhaseParameters(sum_var, one_var_lns, db);
      ls = s.MakeLocalSearchPhase(vars, db, ls_params);
      break;
    }
    case LS: {
      LOG(INFO) << "Local Search";
      MoveOneVar* const one_var_ls = s.RevAlloc(new MoveOneVar(vars));
      LocalSearchPhaseParameters* const ls_params =
          s.MakeLocalSearchPhaseParameters(sum_var, one_var_ls, db);
      ls = s.MakeLocalSearchPhase(vars, db, ls_params);
      break;
    }
    case LS_WITH_FILTER: {
      LOG(INFO) << "Local Search with Filter";
      MoveOneVar* const one_var_ls = s.RevAlloc(new MoveOneVar(vars));
      std::vector<LocalSearchFilter*> filters;
      filters.push_back(s.RevAlloc(new SumFilter(vars)));
      LocalSearchFilterManager* filter_manager =
          s.RevAlloc(new LocalSearchFilterManager(filters));

      LocalSearchPhaseParameters* const ls_params =
          s.MakeLocalSearchPhaseParameters(sum_var, one_var_ls, db, nullptr,
                                           filter_manager);
      ls = s.MakeLocalSearchPhase(vars, db, ls_params);
      break;
    }
  }
  SolutionCollector* const collector = s.MakeLastSolutionCollector();
  collector->Add(vars);
  collector->AddObjective(sum_var);
  SearchMonitor* const log = s.MakeSearchLog(1000, obj);
  s.Solve(ls, collector, obj, log);
  LOG(INFO) << "Objective value = " << collector->objective_value(0);
}
}  


int main(int argc, char** argv) {
  InitGoogle(argv[0], &argc, &argv, true);
  absl::SetFlag(&FLAGS_stderrthreshold, 0);
  operations_research::SolveProblem(operations_research::LNS);
  operations_research::SolveProblem(operations_research::LS);
  operations_research::SolveProblem(operations_research::LS_WITH_FILTER);
  return EXIT_SUCCESS;
}

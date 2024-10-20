
























#include <stdlib.h>

#include "absl/types/span.h"
#include "ortools/base/logging.h"
#include "ortools/sat/cp_model.h"
#include "ortools/sat/cp_model.pb.h"
#include "ortools/sat/cp_model_solver.h"
#include "ortools/sat/model.h"
#include "ortools/sat/sat_parameters.pb.h"
#include "ortools/util/sorted_interval_list.h"

namespace operations_research {
namespace sat {

void StepFunctionSampleSat() {
  

  CpModelBuilder cp_model;

  

  const IntVar x = cp_model.NewIntVar({0, 20});

  

  

  

  

  

  

  

  

  

  IntVar expr = cp_model.NewIntVar({0, 3});

  

  BoolVar b0 = cp_model.NewBoolVar();
  cp_model.AddLinearConstraint(x, Domain::FromValues({5, 6, 8, 9, 10}))
      .OnlyEnforceIf(b0);
  cp_model.AddEquality(expr, 0).OnlyEnforceIf(b0);

  

  BoolVar b2 = cp_model.NewBoolVar();
  cp_model
      .AddLinearConstraint(x, Domain::FromIntervals({{0, 1}, {3, 4}, {11, 20}}))
      .OnlyEnforceIf(b2);
  cp_model.AddEquality(expr, 2).OnlyEnforceIf(b2);

  

  BoolVar b3 = cp_model.NewBoolVar();
  cp_model.AddEquality(x, 7).OnlyEnforceIf(b3);
  cp_model.AddEquality(expr, 3).OnlyEnforceIf(b3);

  

  cp_model.AddBoolOr({b0, b2, b3});

  

  cp_model.AddDecisionStrategy({x}, DecisionStrategyProto::CHOOSE_FIRST,
                               DecisionStrategyProto::SELECT_MIN_VALUE);

  

  Model model;
  SatParameters parameters;
  parameters.set_search_branching(SatParameters::FIXED_SEARCH);
  parameters.set_enumerate_all_solutions(true);
  model.Add(NewSatParameters(parameters));
  model.Add(NewFeasibleSolutionObserver([&](const CpSolverResponse& r) {
    LOG(INFO) << "x=" << SolutionIntegerValue(r, x) << " expr"
              << SolutionIntegerValue(r, expr);
  }));
  SolveCpModel(cp_model.Build(), &model);
}

}  

}  


int main() {
  operations_research::sat::StepFunctionSampleSat();

  return EXIT_SUCCESS;
}

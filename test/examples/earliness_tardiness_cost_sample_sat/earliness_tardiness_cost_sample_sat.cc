
























#include <stdlib.h>

#include <cstdint>

#include "absl/types/span.h"
#include "ortools/base/logging.h"
#include "ortools/sat/cp_model.h"
#include "ortools/sat/cp_model.pb.h"
#include "ortools/sat/cp_model_solver.h"
#include "ortools/sat/model.h"
#include "ortools/sat/sat_parameters.pb.h"

namespace operations_research {
namespace sat {

void EarlinessTardinessCostSampleSat() {
  const int64_t kEarlinessDate = 5;
  const int64_t kEarlinessCost = 8;
  const int64_t kLatenessDate = 15;
  const int64_t kLatenessCost = 12;

  

  CpModelBuilder cp_model;

  

  const IntVar x = cp_model.NewIntVar({0, 20});

  

  

  

  

  

  

  const int64_t kLargeConstant = 1000;
  const IntVar expr = cp_model.NewIntVar({0, kLargeConstant});

  

  cp_model.AddMaxEquality(expr, {(kEarlinessDate - x) * kEarlinessCost, 0,
                                 (x - kLatenessDate) * kLatenessCost});

  

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
  operations_research::sat::EarlinessTardinessCostSampleSat();

  return EXIT_SUCCESS;
}

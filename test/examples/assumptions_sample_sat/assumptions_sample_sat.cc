




























#include <stdlib.h>

#include "absl/types/span.h"
#include "ortools/base/logging.h"
#include "ortools/sat/cp_model.h"
#include "ortools/sat/cp_model.pb.h"
#include "ortools/sat/cp_model_solver.h"
#include "ortools/util/sorted_interval_list.h"



namespace operations_research {
namespace sat {

void AssumptionsSampleSat() {
  

  CpModelBuilder cp_model;
  


  

  const Domain domain(0, 10);
  const IntVar x = cp_model.NewIntVar(domain).WithName("x");
  const IntVar y = cp_model.NewIntVar(domain).WithName("y");
  const IntVar z = cp_model.NewIntVar(domain).WithName("z");
  const BoolVar a = cp_model.NewBoolVar().WithName("a");
  const BoolVar b = cp_model.NewBoolVar().WithName("b");
  const BoolVar c = cp_model.NewBoolVar().WithName("c");
  


  

  cp_model.AddGreaterThan(x, y).OnlyEnforceIf(a);
  cp_model.AddGreaterThan(y, z).OnlyEnforceIf(b);
  cp_model.AddGreaterThan(z, x).OnlyEnforceIf(c);
  


  

  cp_model.AddAssumptions({a, b, c});

  

  

  const CpSolverResponse response = Solve(cp_model.Build());
  


  

  

  LOG(INFO) << CpSolverResponseStats(response);
  if (response.status() == CpSolverStatus::INFEASIBLE) {
    for (const int index :
         response.sufficient_assumptions_for_infeasibility()) {
      LOG(INFO) << index;
    }
  }
  

}
}  

}  


int main(int argc, char** argv) {
  operations_research::sat::AssumptionsSampleSat();
  return EXIT_SUCCESS;
}



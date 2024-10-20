


























#include <stdlib.h>

#include "ortools/base/logging.h"
#include "ortools/sat/cp_model.h"
#include "ortools/sat/cp_model.pb.h"
#include "ortools/sat/cp_model_solver.h"
#include "ortools/sat/model.h"
#include "ortools/util/sorted_interval_list.h"

namespace operations_research {
namespace sat {

void SolveAndPrintIntermediateSolutionsSampleSat() {
  

  CpModelBuilder cp_model;
  


  

  const Domain domain(0, 2);
  const IntVar x = cp_model.NewIntVar(domain).WithName("x");
  const IntVar y = cp_model.NewIntVar(domain).WithName("y");
  const IntVar z = cp_model.NewIntVar(domain).WithName("z");
  


  

  cp_model.AddNotEqual(x, y);
  


  

  cp_model.Maximize(x + 2 * y + 3 * z);
  


  

  Model model;
  int num_solutions = 0;
  model.Add(NewFeasibleSolutionObserver([&](const CpSolverResponse& r) {
    LOG(INFO) << "Solution " << num_solutions;
    LOG(INFO) << "  objective value = " << r.objective_value();
    LOG(INFO) << "  x = " << SolutionIntegerValue(r, x);
    LOG(INFO) << "  y = " << SolutionIntegerValue(r, y);
    LOG(INFO) << "  z = " << SolutionIntegerValue(r, z);
    num_solutions++;
  }));
  


  

  const CpSolverResponse response = SolveCpModel(cp_model.Build(), &model);
  


  LOG(INFO) << "Number of solutions found: " << num_solutions;
}

}  

}  


int main() {
  operations_research::sat::SolveAndPrintIntermediateSolutionsSampleSat();

  return EXIT_SUCCESS;
}



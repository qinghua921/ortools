































#include <stdlib.h>

#include "ortools/base/logging.h"
#include "ortools/sat/cp_model.h"
#include "ortools/sat/cp_model_solver.h"

namespace operations_research {
namespace sat {

void NonLinearSatProgram() {
  CpModelBuilder cp_model;

  const int perimeter = 20;
  const Domain sides_domain(0, perimeter);

  const IntVar x = cp_model.NewIntVar(sides_domain);
  const IntVar y = cp_model.NewIntVar(sides_domain);

  cp_model.AddEquality(2 * (x + y), perimeter);

  const Domain area_domain(0, perimeter * perimeter);
  const IntVar area = cp_model.NewIntVar(area_domain);

  cp_model.AddMultiplicationEquality(area, x, y);

  cp_model.Maximize(area);

  const CpSolverResponse response = Solve(cp_model.Build());

  if (response.status() == CpSolverStatus::OPTIMAL ||
      response.status() == CpSolverStatus::FEASIBLE) {
    

    LOG(INFO) << "x = " << SolutionIntegerValue(response, x);
    LOG(INFO) << "y = " << SolutionIntegerValue(response, y);
    LOG(INFO) << "s = " << SolutionIntegerValue(response, area);
  } else {
    LOG(INFO) << "No solution found.";
  }
}

}  

}  


int main() {
  operations_research::sat::NonLinearSatProgram();
  return EXIT_SUCCESS;
}



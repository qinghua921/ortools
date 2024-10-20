






























#include <iostream>
#include <ostream>

#include "ortools/glop/lp_solver.h"
#include "ortools/lp_data/lp_data.h"
#include "ortools/lp_data/lp_types.h"



namespace operations_research::glop {
int RunLinearExample() {
  LinearProgram lp;
  

  ColIndex col_x = lp.FindOrCreateVariable("x");
  lp.SetVariableBounds(col_x, 0.0, 1.0);
  ColIndex col_y = lp.FindOrCreateVariable("y");
  lp.SetVariableBounds(col_y, 0.0, 2.0);

  

  RowIndex row_r1 = lp.FindOrCreateConstraint("r1");
  lp.SetConstraintBounds(row_r1, 0.0, 2.0);
  lp.SetCoefficient(row_r1, col_x, 1);
  lp.SetCoefficient(row_r1, col_y, 1);

  

  lp.SetObjectiveCoefficient(col_x, 3);
  lp.SetObjectiveCoefficient(col_y, 1);
  lp.SetMaximizationProblem(true);

  lp.CleanUp();

  std::cout << "Number of variables = " << lp.num_variables() << std::endl;
  std::cout << "Number of constraints = " << lp.num_constraints() << std::endl;

  LPSolver solver;
  GlopParameters parameters;
  parameters.set_provide_strong_optimal_guarantee(true);
  solver.SetParameters(parameters);

  ProblemStatus status = solver.Solve(lp);
  if (status == ProblemStatus::OPTIMAL) {
    std::cout << "Optimal solution found !" << std::endl;
    

    std::cout << "Optimal objective value = " << solver.GetObjectiveValue()
              << std::endl;
    

    const DenseRow& values = solver.variable_values();
    std::cout << "Solution:" << std::endl
              << "x = " << values[col_x] << std::endl
              << ", y = " << values[col_y] << std::endl;
    return EXIT_SUCCESS;
  } else {
    return EXIT_FAILURE;
  }
}
}  


int main(int argc, char** argv) {
  return operations_research::glop::RunLinearExample();
}



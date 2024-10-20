






























#include <memory>
#include <ostream>

#include "ortools/linear_solver/linear_solver.h"



namespace operations_research {
void SimpleLpProgram() {
  

  

  std::unique_ptr<MPSolver> solver(MPSolver::CreateSolver("GLOP"));
  


  

  const double infinity = solver->infinity();
  

  MPVariable* const x = solver->MakeNumVar(0.0, infinity, "x");
  MPVariable* const y = solver->MakeNumVar(0.0, infinity, "y");

  LOG(INFO) << "Number of variables = " << solver->NumVariables();
  


  

  

  MPConstraint* const c0 = solver->MakeRowConstraint(-infinity, 17.5, "c0");
  c0->SetCoefficient(x, 1);
  c0->SetCoefficient(y, 7);

  

  MPConstraint* const c1 = solver->MakeRowConstraint(-infinity, 3.5, "c1");
  c1->SetCoefficient(x, 1);
  c1->SetCoefficient(y, 0);

  LOG(INFO) << "Number of constraints = " << solver->NumConstraints();
  


  

  

  MPObjective* const objective = solver->MutableObjective();
  objective->SetCoefficient(x, 1);
  objective->SetCoefficient(y, 10);
  objective->SetMaximization();
  


  

  const MPSolver::ResultStatus result_status = solver->Solve();
  

  if (result_status != MPSolver::OPTIMAL) {
    LOG(FATAL) << "The problem does not have an optimal solution!";
  }
  


  

  LOG(INFO) << "Solution:" << std::endl;
  LOG(INFO) << "Objective value = " << objective->Value();
  LOG(INFO) << "x = " << x->solution_value();
  LOG(INFO) << "y = " << y->solution_value();
  


  

  LOG(INFO) << "\nAdvanced usage:";
  LOG(INFO) << "Problem solved in " << solver->wall_time() << " milliseconds";
  LOG(INFO) << "Problem solved in " << solver->iterations() << " iterations";
  

}
}  


int main() {
  operations_research::SimpleLpProgram();
  return EXIT_SUCCESS;
}



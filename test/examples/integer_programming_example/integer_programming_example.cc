




























#include <iostream>
#include <memory>

#include "ortools/linear_solver/linear_solver.h"



namespace operations_research {
void IntegerProgrammingExample() {
  

  

  std::unique_ptr<MPSolver> solver(MPSolver::CreateSolver("SCIP"));
  if (!solver) {
    LOG(WARNING) << "SCIP solver unavailable.";
    return;
  }
  


  

  

  MPVariable* const x = solver->MakeIntVar(0.0, solver->infinity(), "x");
  MPVariable* const y = solver->MakeIntVar(0.0, solver->infinity(), "y");
  MPVariable* const z = solver->MakeIntVar(0.0, solver->infinity(), "z");
  LOG(INFO) << "Number of variables = " << solver->NumVariables();
  


  

  

  MPConstraint* const constraint0 =
      solver->MakeRowConstraint(-solver->infinity(), 50);
  constraint0->SetCoefficient(x, 2);
  constraint0->SetCoefficient(y, 7);
  constraint0->SetCoefficient(z, 3);

  

  MPConstraint* const constraint1 =
      solver->MakeRowConstraint(-solver->infinity(), 45);
  constraint1->SetCoefficient(x, 3);
  constraint1->SetCoefficient(y, -5);
  constraint1->SetCoefficient(z, 7);

  

  MPConstraint* const constraint2 =
      solver->MakeRowConstraint(-solver->infinity(), 37);
  constraint2->SetCoefficient(x, 5);
  constraint2->SetCoefficient(y, 2);
  constraint2->SetCoefficient(z, -6);
  LOG(INFO) << "Number of constraints = " << solver->NumConstraints();
  


  

  

  MPObjective* const objective = solver->MutableObjective();
  objective->SetCoefficient(x, 2);
  objective->SetCoefficient(y, 2);
  objective->SetCoefficient(z, 3);
  objective->SetMaximization();
  


  

  const MPSolver::ResultStatus result_status = solver->Solve();
  

  if (result_status != MPSolver::OPTIMAL) {
    LOG(FATAL) << "The problem does not have an optimal solution!";
  }
  


  

  LOG(INFO) << "Solution:";
  LOG(INFO) << "Optimal objective value = " << objective->Value();
  LOG(INFO) << x->name() << " = " << x->solution_value();
  LOG(INFO) << y->name() << " = " << y->solution_value();
  LOG(INFO) << z->name() << " = " << z->solution_value();
  

}
}  


int main(int argc, char** argv) {
  operations_research::IntegerProgrammingExample();
  return EXIT_SUCCESS;
}



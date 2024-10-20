




























#include <memory>
#include <vector>

#include "ortools/linear_solver/linear_solver.h"





namespace operations_research {


struct DataModel {
  const std::vector<std::vector<double>> constraint_coeffs{
      {5, 7, 9, 2, 1},
      {18, 4, -9, 10, 12},
      {4, 7, 3, 8, 5},
      {5, 13, 16, 3, -7},
  };
  const std::vector<double> bounds{250, 285, 211, 315};
  const std::vector<double> obj_coeffs{7, 8, 2, 9, 6};
  const int num_vars = 5;
  const int num_constraints = 4;
};



void MipVarArray() {
  

  DataModel data;
  

  


  

  

  std::unique_ptr<MPSolver> solver(MPSolver::CreateSolver("SCIP"));
  if (!solver) {
    LOG(WARNING) << "SCIP solver unavailable.";
    return;
  }
  


  

  

  const double infinity = solver->infinity();
  

  std::vector<const MPVariable*> x(data.num_vars);
  for (int j = 0; j < data.num_vars; ++j) {
    x[j] = solver->MakeIntVar(0.0, infinity, "");
  }
  LOG(INFO) << "Number of variables = " << solver->NumVariables();
  


  

  

  for (int i = 0; i < data.num_constraints; ++i) {
    MPConstraint* constraint = solver->MakeRowConstraint(0, data.bounds[i], "");
    for (int j = 0; j < data.num_vars; ++j) {
      constraint->SetCoefficient(x[j], data.constraint_coeffs[i][j]);
    }
  }
  LOG(INFO) << "Number of constraints = " << solver->NumConstraints();
  


  

  

  MPObjective* const objective = solver->MutableObjective();
  for (int j = 0; j < data.num_vars; ++j) {
    objective->SetCoefficient(x[j], data.obj_coeffs[j]);
  }
  objective->SetMaximization();
  


  

  const MPSolver::ResultStatus result_status = solver->Solve();
  


  

  

  if (result_status != MPSolver::OPTIMAL) {
    LOG(FATAL) << "The problem does not have an optimal solution.";
  }
  LOG(INFO) << "Solution:";
  LOG(INFO) << "Optimal objective value = " << objective->Value();

  for (int j = 0; j < data.num_vars; ++j) {
    LOG(INFO) << "x[" << j << "] = " << x[j]->solution_value();
  }
  

}
}  


int main(int argc, char** argv) {
  operations_research::MipVarArray();
  return EXIT_SUCCESS;
}





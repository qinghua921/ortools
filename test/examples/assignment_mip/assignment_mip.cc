




























#include <memory>
#include <vector>

#include "ortools/base/logging.h"
#include "ortools/linear_solver/linear_solver.h"



namespace operations_research {
void AssignmentMip() {
  

  

  const std::vector<std::vector<double>> costs{
      {90, 80, 75, 70},   {35, 85, 55, 65},   {125, 95, 90, 95},
      {45, 110, 95, 115}, {50, 100, 90, 100},
  };
  const int num_workers = costs.size();
  const int num_tasks = costs[0].size();
  


  

  

  

  std::unique_ptr<MPSolver> solver(MPSolver::CreateSolver("SCIP"));
  if (!solver) {
    LOG(WARNING) << "SCIP solver unavailable.";
    return;
  }
  


  

  

  

  

  std::vector<std::vector<const MPVariable*>> x(
      num_workers, std::vector<const MPVariable*>(num_tasks));
  for (int i = 0; i < num_workers; ++i) {
    for (int j = 0; j < num_tasks; ++j) {
      x[i][j] = solver->MakeIntVar(0, 1, "");
    }
  }
  


  

  

  

  for (int i = 0; i < num_workers; ++i) {
    LinearExpr worker_sum;
    for (int j = 0; j < num_tasks; ++j) {
      worker_sum += x[i][j];
    }
    solver->MakeRowConstraint(worker_sum <= 1.0);
  }
  

  for (int j = 0; j < num_tasks; ++j) {
    LinearExpr task_sum;
    for (int i = 0; i < num_workers; ++i) {
      task_sum += x[i][j];
    }
    solver->MakeRowConstraint(task_sum == 1.0);
  }
  


  

  

  MPObjective* const objective = solver->MutableObjective();
  for (int i = 0; i < num_workers; ++i) {
    for (int j = 0; j < num_tasks; ++j) {
      objective->SetCoefficient(x[i][j], costs[i][j]);
    }
  }
  objective->SetMinimization();
  


  

  

  const MPSolver::ResultStatus result_status = solver->Solve();
  


  

  

  

  if (result_status != MPSolver::OPTIMAL &&
      result_status != MPSolver::FEASIBLE) {
    LOG(FATAL) << "No solution found.";
  }

  LOG(INFO) << "Total cost = " << objective->Value() << "\n\n";

  for (int i = 0; i < num_workers; ++i) {
    for (int j = 0; j < num_tasks; ++j) {
      

      

      if (x[i][j]->solution_value() > 0.5) {
        LOG(INFO) << "Worker " << i << " assigned to task " << j
                  << ".  Cost = " << costs[i][j];
      }
    }
  }
  

}
}  


int main(int argc, char** argv) {
  operations_research::AssignmentMip();
  return EXIT_SUCCESS;
}



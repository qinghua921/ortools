




























#include <iostream>
#include <memory>
#include <numeric>
#include <ostream>
#include <vector>

#include "ortools/linear_solver/linear_expr.h"
#include "ortools/linear_solver/linear_solver.h"





namespace operations_research {


struct DataModel {
  const std::vector<double> weights = {48, 30, 19, 36, 36, 27,
                                       42, 42, 36, 24, 30};
  const int num_items = weights.size();
  const int num_bins = weights.size();
  const int bin_capacity = 100;
};



void BinPackingMip() {
  

  DataModel data;
  

  


  

  

  std::unique_ptr<MPSolver> solver(MPSolver::CreateSolver("SCIP"));
  if (!solver) {
    LOG(WARNING) << "SCIP solver unavailable.";
    return;
  }
  


  

  

  std::vector<std::vector<const MPVariable*>> x(
      data.num_items, std::vector<const MPVariable*>(data.num_bins));
  for (int i = 0; i < data.num_items; ++i) {
    for (int j = 0; j < data.num_bins; ++j) {
      x[i][j] = solver->MakeIntVar(0.0, 1.0, "");
    }
  }
  

  std::vector<const MPVariable*> y(data.num_bins);
  for (int j = 0; j < data.num_bins; ++j) {
    y[j] = solver->MakeIntVar(0.0, 1.0, "");
  }
  


  

  

  

  for (int i = 0; i < data.num_items; ++i) {
    LinearExpr sum;
    for (int j = 0; j < data.num_bins; ++j) {
      sum += x[i][j];
    }
    solver->MakeRowConstraint(sum == 1.0);
  }
  

  

  for (int j = 0; j < data.num_bins; ++j) {
    LinearExpr weight;
    for (int i = 0; i < data.num_items; ++i) {
      weight += data.weights[i] * LinearExpr(x[i][j]);
    }
    solver->MakeRowConstraint(weight <= LinearExpr(y[j]) * data.bin_capacity);
  }
  


  

  

  MPObjective* const objective = solver->MutableObjective();
  LinearExpr num_bins_used;
  for (int j = 0; j < data.num_bins; ++j) {
    num_bins_used += y[j];
  }
  objective->MinimizeLinearExpr(num_bins_used);
  


  

  const MPSolver::ResultStatus result_status = solver->Solve();
  


  

  

  if (result_status != MPSolver::OPTIMAL) {
    std::cerr << "The problem does not have an optimal solution!";
    return;
  }
  std::cout << "Number of bins used: " << objective->Value() << std::endl
            << std::endl;
  double total_weight = 0;
  for (int j = 0; j < data.num_bins; ++j) {
    if (y[j]->solution_value() == 1) {
      std::cout << "Bin " << j << std::endl << std::endl;
      double bin_weight = 0;
      for (int i = 0; i < data.num_items; ++i) {
        if (x[i][j]->solution_value() == 1) {
          std::cout << "Item " << i << " - Weight: " << data.weights[i]
                    << std::endl;
          bin_weight += data.weights[i];
        }
      }
      std::cout << "Packed bin weight: " << bin_weight << std::endl
                << std::endl;
      total_weight += bin_weight;
    }
  }
  std::cout << "Total packed weight: " << total_weight << std::endl;
  

}
}  


int main(int argc, char** argv) {
  operations_research::BinPackingMip();
  return EXIT_SUCCESS;
}





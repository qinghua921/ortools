






























#include <stdlib.h>

#include <map>
#include <numeric>
#include <tuple>
#include <vector>

#include "absl/strings/str_format.h"
#include "ortools/base/logging.h"
#include "ortools/sat/cp_model.h"
#include "ortools/sat/cp_model.pb.h"
#include "ortools/sat/cp_model_solver.h"



namespace operations_research {
namespace sat {

void MultipleKnapsackSat() {
  

  const std::vector<int> weights = {
      {48, 30, 42, 36, 36, 48, 42, 42, 36, 24, 30, 30, 42, 36, 36}};
  const std::vector<int> values = {
      {10, 30, 25, 50, 35, 30, 15, 40, 30, 35, 45, 10, 20, 30, 25}};
  const int num_items = static_cast<int>(weights.size());
  std::vector<int> all_items(num_items);
  std::iota(all_items.begin(), all_items.end(), 0);

  const std::vector<int> bin_capacities = {{100, 100, 100, 100, 100}};
  const int num_bins = static_cast<int>(bin_capacities.size());
  std::vector<int> all_bins(num_bins);
  std::iota(all_bins.begin(), all_bins.end(), 0);
  


  

  CpModelBuilder cp_model;
  


  

  

  

  std::map<std::tuple<int, int>, BoolVar> x;
  for (int i : all_items) {
    for (int b : all_bins) {
      auto key = std::make_tuple(i, b);
      x[key] = cp_model.NewBoolVar().WithName(absl::StrFormat("x_%d_%d", i, b));
    }
  }
  


  

  

  

  for (int i : all_items) {
    std::vector<BoolVar> copies;
    for (int b : all_bins) {
      copies.push_back(x[std::make_tuple(i, b)]);
    }
    cp_model.AddAtMostOne(copies);
  }

  

  for (int b : all_bins) {
    LinearExpr bin_weight;
    for (int i : all_items) {
      bin_weight += x[std::make_tuple(i, b)] * weights[i];
    }
    cp_model.AddLessOrEqual(bin_weight, bin_capacities[b]);
  }
  


  

  

  

  LinearExpr objective;
  for (int i : all_items) {
    for (int b : all_bins) {
      objective += x[std::make_tuple(i, b)] * values[i];
    }
  }
  cp_model.Maximize(objective);
  


  

  const CpSolverResponse response = Solve(cp_model.Build());
  


  

  if (response.status() == CpSolverStatus::OPTIMAL ||
      response.status() == CpSolverStatus::FEASIBLE) {
    LOG(INFO) << "Total packed value: " << response.objective_value();
    double total_weight = 0.0;
    for (int b : all_bins) {
      LOG(INFO) << "Bin " << b;
      double bin_weight = 0.0;
      double bin_value = 0.0;
      for (int i : all_items) {
        auto key = std::make_tuple(i, b);
        if (SolutionIntegerValue(response, x[key]) > 0) {
          LOG(INFO) << "Item " << i << " weight: " << weights[i]
                    << " value: " << values[i];
          bin_weight += weights[i];
          bin_value += values[i];
        }
      }
      LOG(INFO) << "Packed bin weight: " << bin_weight;
      LOG(INFO) << "Packed bin value: " << bin_value;
      total_weight += bin_weight;
    }
    LOG(INFO) << "Total packed weight: " << total_weight;
  } else {
    LOG(INFO) << "The problem does not have an optimal solution.";
  }
  


  

  

  LOG(INFO) << "Statistics";
  LOG(INFO) << CpSolverResponseStats(response);
  

}
}  

}  


int main() {
  operations_research::sat::MultipleKnapsackSat();
  return EXIT_SUCCESS;
}



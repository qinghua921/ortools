




























#include <algorithm>
#include <cstdint>
#include <iterator>
#include <numeric>
#include <sstream>
#include <vector>

#include "ortools/algorithms/knapsack_solver.h"



namespace operations_research {
namespace algorithms {

void SimpleKnapsackProgram() {
  

  KnapsackSolver solver(KnapsackSolver::KNAPSACK_DYNAMIC_PROGRAMMING_SOLVER,
                        "SimpleKnapsackExample");
  


  

  std::vector<std::vector<int64_t>> weights = {{565, 406, 194, 130, 435, 367,
                                                230, 315, 393, 125, 670, 892,
                                                600, 293, 712, 147, 421, 255}};
  std::vector<int64_t> capacities = {850};
  const std::vector<int64_t>& values = weights[0];
  


  

  solver.Init(values, weights, capacities);
  int64_t computed_value = solver.Solve();
  


  

  std::vector<int> packed_items;
  for (std::size_t i = 0; i < values.size(); ++i) {
    if (solver.BestSolutionContains(i)) packed_items.push_back(i);
  }
  std::ostringstream packed_items_ss;
  std::copy(packed_items.begin(), packed_items.end() - 1,
            std::ostream_iterator<int>(packed_items_ss, ", "));
  packed_items_ss << packed_items.back();

  std::vector<int64_t> packed_weights;
  packed_weights.reserve(packed_items.size());
  for (const auto& it : packed_items) {
    packed_weights.push_back(weights[0][it]);
  }
  std::ostringstream packed_weights_ss;
  std::copy(packed_weights.begin(), packed_weights.end() - 1,
            std::ostream_iterator<int>(packed_weights_ss, ", "));
  packed_weights_ss << packed_weights.back();

  int64_t total_weights =
      std::accumulate(packed_weights.begin(), packed_weights.end(), int64_t{0});

  LOG(INFO) << "Total value: " << computed_value;
  LOG(INFO) << "Packed items: {" << packed_items_ss.str() << "}";
  LOG(INFO) << "Total weight: " << total_weights;
  LOG(INFO) << "Packed weights: {" << packed_weights_ss.str() << "}";
  

}

}  

}  


int main() {
  operations_research::algorithms::SimpleKnapsackProgram();
  return EXIT_SUCCESS;
}



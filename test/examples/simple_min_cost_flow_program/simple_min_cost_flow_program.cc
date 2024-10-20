






























#include <cstdint>
#include <vector>

#include "ortools/graph/min_cost_flow.h"



namespace operations_research {


void SimpleMinCostFlowProgram() {
  

  

  SimpleMinCostFlow min_cost_flow;
  


  

  

  

  

  std::vector<int64_t> start_nodes = {0, 0, 1, 1, 1, 2, 2, 3, 4};
  std::vector<int64_t> end_nodes = {1, 2, 2, 3, 4, 3, 4, 4, 2};
  std::vector<int64_t> capacities = {15, 8, 20, 4, 10, 15, 4, 20, 5};
  std::vector<int64_t> unit_costs = {4, 4, 2, 2, 6, 1, 3, 2, 3};

  

  std::vector<int64_t> supplies = {20, 0, 0, -5, -15};
  


  

  

  for (int i = 0; i < start_nodes.size(); ++i) {
    int arc = min_cost_flow.AddArcWithCapacityAndUnitCost(
        start_nodes[i], end_nodes[i], capacities[i], unit_costs[i]);
    if (arc != i) LOG(FATAL) << "Internal error";
  }

  

  for (int i = 0; i < supplies.size(); ++i) {
    min_cost_flow.SetNodeSupply(i, supplies[i]);
  }
  


  

  

  int status = min_cost_flow.Solve();
  


  

  if (status == MinCostFlow::OPTIMAL) {
    LOG(INFO) << "Minimum cost flow: " << min_cost_flow.OptimalCost();
    LOG(INFO) << "";
    LOG(INFO) << " Arc   Flow / Capacity  Cost";
    for (std::size_t i = 0; i < min_cost_flow.NumArcs(); ++i) {
      int64_t cost = min_cost_flow.Flow(i) * min_cost_flow.UnitCost(i);
      LOG(INFO) << min_cost_flow.Tail(i) << " -> " << min_cost_flow.Head(i)
                << "  " << min_cost_flow.Flow(i) << "  / "
                << min_cost_flow.Capacity(i) << "       " << cost;
    }
  } else {
    LOG(INFO) << "Solving the min cost flow problem failed. Solver status: "
              << status;
  }
  

}

}  


int main() {
  operations_research::SimpleMinCostFlowProgram();
  return EXIT_SUCCESS;
}



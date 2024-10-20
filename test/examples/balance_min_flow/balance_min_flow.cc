




























#include <cstdint>
#include <vector>

#include "ortools/graph/min_cost_flow.h"



namespace operations_research {


void BalanceMinFlow() {
  

  

  SimpleMinCostFlow min_cost_flow;
  


  

  

  const std::vector<int64_t> team_A = {1, 3, 5};
  const std::vector<int64_t> team_B = {2, 4, 6};

  const std::vector<int64_t> start_nodes = {
      0, 0, 11, 11, 11, 12, 12, 12, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3,
      3, 3, 4,  4,  4,  4,  5,  5,  5, 5, 6, 6, 6, 6, 7, 8, 9, 10};
  const std::vector<int64_t> end_nodes = {
      11, 12, 1, 3, 5, 2,  4, 6, 7, 8,  9, 10, 7, 8,  9,  10, 7,  8,
      9,  10, 7, 8, 9, 10, 7, 8, 9, 10, 7, 8,  9, 10, 13, 13, 13, 13};
  const std::vector<int64_t> capacities = {2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  const std::vector<int64_t> unit_costs = {
      0,  0,   0,  0,  0,   0,  0,   0,   90, 76,  75, 70,
      35, 85,  55, 65, 125, 95, 90,  105, 45, 110, 95, 115,
      60, 105, 80, 75, 45,  65, 110, 95,  0,  0,   0,  0};

  const int64_t source = 0;
  const int64_t sink = 13;
  const int64_t tasks = 4;
  

  const std::vector<int64_t> supplies = {tasks, 0, 0, 0, 0, 0, 0,
                                         0,     0, 0, 0, 0, 0, -tasks};
  


  

  

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
    LOG(INFO) << "Total cost: " << min_cost_flow.OptimalCost();
    LOG(INFO) << "";
    for (std::size_t i = 0; i < min_cost_flow.NumArcs(); ++i) {
      

      

      if (min_cost_flow.Tail(i) != source && min_cost_flow.Tail(i) != 11 &&
          min_cost_flow.Tail(i) != 12 && min_cost_flow.Head(i) != sink) {
        

        

        if (min_cost_flow.Flow(i) > 0) {
          LOG(INFO) << "Worker " << min_cost_flow.Tail(i)
                    << " assigned to task " << min_cost_flow.Head(i)
                    << " Cost: " << min_cost_flow.UnitCost(i);
        }
      }
    }
  } else {
    LOG(INFO) << "Solving the min cost flow problem failed.";
    LOG(INFO) << "Solver status: " << status;
  }
  

}

}  


int main() {
  operations_research::BalanceMinFlow();
  return EXIT_SUCCESS;
}



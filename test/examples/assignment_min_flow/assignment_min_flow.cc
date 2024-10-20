




























#include <cstdint>
#include <vector>

#include "ortools/graph/min_cost_flow.h"



namespace operations_research {


void AssignmentMinFlow() {
  

  

  SimpleMinCostFlow min_cost_flow;
  


  

  

  

  

  const std::vector<int64_t> start_nodes = {0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2,
                                            3, 3, 3, 3, 4, 4, 4, 4, 5, 6, 7, 8};
  const std::vector<int64_t> end_nodes = {1, 2, 3, 4, 5, 6, 7, 8, 5, 6, 7, 8,
                                          5, 6, 7, 8, 5, 6, 7, 8, 9, 9, 9, 9};
  const std::vector<int64_t> capacities = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  const std::vector<int64_t> unit_costs = {0,  0,   0,  0,   90,  76, 75, 70,
                                           35, 85,  55, 65,  125, 95, 90, 105,
                                           45, 110, 95, 115, 0,   0,  0,  0};

  const int64_t source = 0;
  const int64_t sink = 9;
  const int64_t tasks = 4;
  

  const std::vector<int64_t> supplies = {tasks, 0, 0, 0, 0, 0, 0, 0, 0, -tasks};
  


  

  

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
      

      if (min_cost_flow.Tail(i) != source && min_cost_flow.Head(i) != sink) {
        

        

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
  operations_research::AssignmentMinFlow();
  return EXIT_SUCCESS;
}



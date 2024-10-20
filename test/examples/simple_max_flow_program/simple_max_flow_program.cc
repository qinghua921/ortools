






























#include <cstdint>
#include <vector>

#include "ortools/graph/max_flow.h"



namespace operations_research {


void SimpleMaxFlowProgram() {
  

  

  SimpleMaxFlow max_flow;
  


  

  

  

  

  std::vector<int64_t> start_nodes = {0, 0, 0, 1, 1, 2, 2, 3, 3};
  std::vector<int64_t> end_nodes = {1, 2, 3, 2, 4, 3, 4, 2, 4};
  std::vector<int64_t> capacities = {20, 30, 10, 40, 30, 10, 20, 5, 20};
  


  

  

  for (int i = 0; i < start_nodes.size(); ++i) {
    max_flow.AddArcWithCapacity(start_nodes[i], end_nodes[i], capacities[i]);
  }
  


  

  

  int status = max_flow.Solve(0, 4);
  


  

  if (status == MaxFlow::OPTIMAL) {
    LOG(INFO) << "Max flow: " << max_flow.OptimalFlow();
    LOG(INFO) << "";
    LOG(INFO) << "  Arc    Flow / Capacity";
    for (std::size_t i = 0; i < max_flow.NumArcs(); ++i) {
      LOG(INFO) << max_flow.Tail(i) << " -> " << max_flow.Head(i) << "  "
                << max_flow.Flow(i) << "  / " << max_flow.Capacity(i);
    }
  } else {
    LOG(INFO) << "Solving the max flow problem failed. Solver status: "
              << status;
  }
  

}

}  


int main() {
  operations_research::SimpleMaxFlowProgram();
  return EXIT_SUCCESS;
}



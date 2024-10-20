
























#include <cstdint>
#include <iostream>
#include <vector>

#include "absl/log/check.h"
#include "absl/status/status.h"
#include "absl/strings/str_join.h"
#include "ortools/base/init_google.h"
#include "ortools/base/status_macros.h"
#include "ortools/graph/dag_shortest_path.h"
#include "ortools/graph/graph.h"
#include "ortools/graph/topologicalsorter.h"

namespace {

absl::Status Main() {
  util::StaticGraph<> graph;
  std::vector<double> weights;
  graph.AddArc(0, 2);
  weights.push_back(5.0);
  graph.AddArc(0, 3);
  weights.push_back(4.0);
  graph.AddArc(1, 3);
  weights.push_back(1.0);
  graph.AddArc(2, 4);
  weights.push_back(-3.0);
  graph.AddArc(3, 4);
  weights.push_back(0.0);

  

  

  std::vector<int32_t> permutation;
  graph.Build(&permutation);
  util::Permute(permutation, &weights);

  

  

  ASSIGN_OR_RETURN(const std::vector<int32_t> topological_order,
                   util::graph::FastTopologicalSort(graph));

  operations_research::ShortestPathsOnDagWrapper<util::StaticGraph<>>
      shortest_path_on_dag(&graph, &weights, topological_order);
  const int source = 0;
  shortest_path_on_dag.RunShortestPathOnDag({source});

  

  for (int i = 1; i < 5; ++i) {
    if (shortest_path_on_dag.IsReachable(i)) {
      std::cout << "Length of shortest path to node " << i << ": "
                << shortest_path_on_dag.LengthTo(i) << std::endl;
      std::cout << "Shortest path to node " << i << ": "
                << absl::StrJoin(shortest_path_on_dag.NodePathTo(i), ", ")
                << std::endl;

    } else {
      std::cout << "No path to node: " << i << std::endl;
    }
  }
  return absl::OkStatus();
}

}  


int main(int argc, char** argv) {
  InitGoogle(argv[0], &argc, &argv, true);
  QCHECK_OK(Main());
  return 0;
}

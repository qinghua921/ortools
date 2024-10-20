
























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
  graph.AddArc(0, 1);
  weights.push_back(2.0);
  graph.AddArc(0, 2);
  weights.push_back(5.0);
  graph.AddArc(1, 4);
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

  operations_research::KShortestPathsOnDagWrapper<util::StaticGraph<>>
      shortest_paths_on_dag(&graph, &weights, topological_order,
                            
2);
  const int source = 0;
  shortest_paths_on_dag.RunKShortestPathOnDag({source});

  

  for (int node = 1; node < 5; ++node) {
    std::cout << "Node " << node << ":\n";
    if (!shortest_paths_on_dag.IsReachable(node)) {
      std::cout << "\tNo path to node " << node << std::endl;
      continue;
    }
    const std::vector<double> lengths = shortest_paths_on_dag.LengthsTo(node);
    const std::vector<std::vector<int32_t>> paths =
        shortest_paths_on_dag.NodePathsTo(node);
    for (int path_index = 0; path_index < lengths.size(); ++path_index) {
      std::cout << "\t#" << (path_index + 1) << " shortest path to node "
                << node << " has length: " << lengths[path_index] << std::endl;
      std::cout << "\t#" << (path_index + 1) << " shortest path to node "
                << node << " is: " << absl::StrJoin(paths[path_index], ", ")
                << std::endl;
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

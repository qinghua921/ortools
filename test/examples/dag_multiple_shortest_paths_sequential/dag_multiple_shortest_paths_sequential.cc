


























#include <cstdint>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "absl/strings/str_cat.h"
#include "absl/strings/str_join.h"
#include "ortools/base/init_google.h"
#include "ortools/graph/dag_shortest_path.h"
#include "ortools/graph/graph.h"



int main(int argc, char** argv) {
  InitGoogle(argv[0], &argc, &argv, true);

  

  

  

  

  

  

  

  

  

  

  const int n = 10;
  const int source = n;
  const int dest = n + 1;
  util::StaticGraph<> graph;
  

  

  

  std::vector<double> weights(3 * n - 1);

  for (int i = 0; i < n; ++i) {
    graph.AddArc(source, i);
    weights[i] = 100.0 + i;
  }
  for (int i = 0; i < n; ++i) {
    graph.AddArc(i, dest);
    weights[n + i] = 100.0 + i;
  }
  for (int i = 0; i + 1 < n; ++i) {
    graph.AddArc(i, i + 1);
    weights[2 * n + i] = 10.0;
  }

  

  

  std::vector<int32_t> permutation;
  graph.Build(&permutation);
  util::Permute(permutation, &weights);
  


  

  

  

  

  std::vector<int32_t> topological_order = {source};
  for (int32_t i = 0; i < n; ++i) {
    topological_order.push_back(i);
  }
  topological_order.push_back(dest);

  operations_research::KShortestPathsOnDagWrapper<util::StaticGraph<>>
      shortest_paths_on_dag(&graph, &weights, topological_order,
                            
2);
  shortest_paths_on_dag.RunKShortestPathOnDag({source});

  const std::vector<double> initial_lengths =
      shortest_paths_on_dag.LengthsTo(dest);
  const std::vector<std::vector<int32_t>> initial_paths =
      shortest_paths_on_dag.NodePathsTo(dest);

  std::cout << "No free arcs" << std::endl;
  for (int path_index = 0; path_index < initial_lengths.size(); ++path_index) {
    std::cout << "\t#" << (path_index + 1)
              << " shortest path has length: " << initial_lengths[path_index]
              << std::endl;
    std::cout << "\t#" << (path_index + 1) << " shortest path is: "
              << absl::StrJoin(initial_paths[path_index], ", ") << std::endl;
  }
  


  

  

  

  

  

  std::vector<std::pair<int, int>> fast_paths = {
      {2, 4}, {8, 1}, {3, 3}, {0, 0}};
  for (const auto [free_from_source, free_to_dest] : fast_paths) {
    weights[permutation[free_from_source]] = 0;
    weights[permutation[n + free_to_dest]] = 0;

    shortest_paths_on_dag.RunKShortestPathOnDag({source});
    std::cout << "source -> " << free_from_source << " and " << free_to_dest
              << " -> dest are now free" << std::endl;
    std::string label =
        absl::StrCat(" (", free_from_source, ", ", free_to_dest, ")");

    const std::vector<double> lengths = shortest_paths_on_dag.LengthsTo(dest);
    const std::vector<std::vector<int32_t>> paths =
        shortest_paths_on_dag.NodePathsTo(dest);

    for (int path_index = 0; path_index < lengths.size(); ++path_index) {
      std::cout << "\t#" << (path_index + 1) << " shortest path" << label
                << " has length: " << lengths[path_index] << std::endl;
      std::cout << "\t#" << (path_index + 1) << " shortest path" << label
                << " is: " << absl::StrJoin(paths[path_index], ", ")
                << std::endl;
    }

    

    weights[permutation[free_from_source]] = 100 + free_from_source;
    weights[permutation[n + free_to_dest]] = 100 + free_to_dest;
  }
  

  return 0;
}




























#include <cstdint>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "absl/strings/str_cat.h"
#include "absl/strings/str_join.h"
#include "ortools/base/init_google.h"
#include "ortools/graph/dag_constrained_shortest_path.h"
#include "ortools/graph/dag_shortest_path.h"
#include "ortools/graph/graph.h"



int main(int argc, char** argv) {
  InitGoogle(argv[0], &argc, &argv, true);

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  const int n = 5;
  const int source = n;
  const int dest = n + 1;
  const int num_arcs = 3 * n - 1;
  util::StaticGraph<> graph;
  

  

  

  std::vector<double> weights(num_arcs);
  

  std::vector<std::vector<double>> resources(1, std::vector<double>(num_arcs));

  for (int i = 0; i < n; ++i) {
    graph.AddArc(source, i);
    weights[i] = 100.0;
    resources[0][i] = 0.0;
  }
  for (int i = 0; i < n; ++i) {
    graph.AddArc(i, dest);
    weights[n + i] = 100.0;
    resources[0][n + i] = 0.0;
  }
  for (int i = 0; i + 1 < n; ++i) {
    graph.AddArc(i, i + 1);
    weights[2 * n + i] = 1.0;
    resources[0][2 * n + i] = 1.0;
  }

  

  

  std::vector<int32_t> permutation;
  graph.Build(&permutation);
  util::Permute(permutation, &weights);
  util::Permute(permutation, &resources[0]);
  


  

  

  

  

  std::vector<int32_t> topological_order = {source};
  for (int32_t i = 0; i < n; ++i) {
    topological_order.push_back(i);
  }
  topological_order.push_back(dest);

  const std::vector<int> sources = {source};
  const std::vector<int> destinations = {dest};
  const std::vector<double> max_resources = {1.0};

  operations_research::ConstrainedShortestPathsOnDagWrapper<util::StaticGraph<>>
      constrained_shortest_path_on_dag(&graph, &weights, &resources,
                                       topological_order, sources, destinations,
                                       &max_resources);
  operations_research::PathWithLength initial_constrained_shortest_path =
      constrained_shortest_path_on_dag.RunConstrainedShortestPathOnDag();

  std::cout << "Initial distance: " << initial_constrained_shortest_path.length
            << std::endl;
  std::cout << "Initial path: "
            << absl::StrJoin(initial_constrained_shortest_path.node_path, ", ")
            << std::endl;
  


  

  

  

  

  

  std::vector<std::pair<int, int>> fast_paths = {{2, 3}, {8, 1}, {3, 7}};
  for (const auto [free_from_source, free_to_dest] : fast_paths) {
    weights[permutation[free_from_source]] = 0;
    weights[permutation[n + free_to_dest]] = 0;

    operations_research::PathWithLength constrained_shortest_path =
        constrained_shortest_path_on_dag.RunConstrainedShortestPathOnDag();
    std::cout << "source -> " << free_from_source << " and " << free_to_dest
              << " -> dest are now free" << std::endl;
    std::string label = absl::StrCat("_", free_from_source, "_", free_to_dest);
    std::cout << "Distance" << label << ": " << constrained_shortest_path.length
              << std::endl;
    std::cout << "Path" << label << ": "
              << absl::StrJoin(constrained_shortest_path.node_path, ", ")
              << std::endl;

    

    weights[permutation[free_from_source]] = 100;
    weights[permutation[n + free_to_dest]] = 100;
  }
  

  return 0;
}

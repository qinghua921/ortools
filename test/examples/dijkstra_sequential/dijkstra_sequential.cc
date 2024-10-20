


























#include <cstdint>
#include <iostream>
#include <limits>
#include <string>
#include <utility>
#include <vector>

#include "absl/log/check.h"
#include "absl/strings/str_cat.h"
#include "absl/strings/str_join.h"
#include "ortools/base/init_google.h"
#include "ortools/graph/bounded_dijkstra.h"
#include "ortools/graph/graph.h"



int main(int argc, char** argv) {
  InitGoogle(argv[0], &argc, &argv, true);

  

  

  

  

  

  

  

  

  

  

  

  

  

  const int n = 10;
  const int source = n;
  const int dest = n + 1;
  util::StaticGraph<> graph;
  

  

  

  std::vector<int> weights(3 * n);

  for (int i = 0; i < n; ++i) {
    graph.AddArc(source, i);
    weights[i] = 100;
  }
  for (int i = 0; i < n; ++i) {
    graph.AddArc(i, (i + 1) % n);
    weights[n + i] = 1;
  }
  for (int i = 0; i < n; ++i) {
    graph.AddArc(i, dest);
    weights[2 * n + i] = 100;
  }

  

  

  std::vector<int32_t> permutation;
  graph.Build(&permutation);
  util::Permute(permutation, &weights);
  


  

  

  operations_research::BoundedDijkstraWrapper<util::StaticGraph<>, int>
      dijkstra(&graph, &weights);

  

  

  

  CHECK(dijkstra.OneToOneShortestPath(
      source, dest, 
std::numeric_limits<int>::max()));
  std::cout << "Initial distance: " << dijkstra.distances()[dest] << std::endl;
  std::cout << "Initial path: "
            << absl::StrJoin(dijkstra.NodePathTo(dest), ", ") << std::endl;
  


  

  

  

  

  std::vector<std::pair<int, int>> fast_paths = {{2, 4}, {8, 1}, {3, 7}};
  for (const auto [free_from_source, free_to_dest] : fast_paths) {
    weights[permutation[free_from_source]] = 0;
    weights[permutation[2 * n + free_to_dest]] = 0;

    CHECK(dijkstra.OneToOneShortestPath(
        source, dest, 
std::numeric_limits<int>::max()));
    std::cout << "source -> " << free_from_source << " and " << free_to_dest
              << " -> dest are now free" << std::endl;
    std::string label = absl::StrCat("_", free_from_source, "_", free_to_dest);
    std::cout << "Distance" << label << ": " << dijkstra.distances()[dest]
              << std::endl;
    std::cout << "Path" << label << ": "
              << absl::StrJoin(dijkstra.NodePathTo(dest), ", ") << std::endl;

    

    weights[permutation[free_from_source]] = 100;
    weights[permutation[2 * n + free_to_dest]] = 100;
  }
  

  return 0;
}

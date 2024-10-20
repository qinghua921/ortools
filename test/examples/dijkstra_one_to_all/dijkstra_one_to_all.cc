
























#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>

#include "absl/strings/str_join.h"
#include "ortools/base/init_google.h"
#include "ortools/graph/bounded_dijkstra.h"
#include "ortools/graph/graph.h"

int main(int argc, char** argv) {
  InitGoogle(argv[0], &argc, &argv, true);

  

  util::StaticGraph<> graph;
  std::vector<int> weights;
  graph.AddArc(0, 1);
  weights.push_back(2);
  graph.AddArc(1, 2);
  weights.push_back(4);
  graph.AddArc(1, 3);
  weights.push_back(0);
  graph.AddArc(2, 3);
  weights.push_back(6);
  graph.AddArc(3, 0);
  weights.push_back(8);
  graph.AddArc(4, 2);
  weights.push_back(1);

  

  

  std::vector<int32_t> permutation;
  graph.Build(&permutation);
  util::Permute(permutation, &weights);

  

  operations_research::BoundedDijkstraWrapper<util::StaticGraph<>, int>
      dijkstra(&graph, &weights);
  const std::vector<int> reachable_from_zero = dijkstra.RunBoundedDijkstra(
      
0, 
std::numeric_limits<int>::max());

  

  for (const int dest : reachable_from_zero) {
    const int distance = dijkstra.distances()[dest];
    const std::vector<int32_t> path = dijkstra.NodePathTo(dest);
    std::cout << "Distance to " << dest << ": " << distance << std::endl;
    std::cout << "Path to " << dest << ": " << absl::StrJoin(path, ", ")
              << std::endl;
  }
}

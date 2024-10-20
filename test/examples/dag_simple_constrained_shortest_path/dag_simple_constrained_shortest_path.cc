
























#include <iostream>
#include <vector>

#include "absl/strings/str_join.h"
#include "ortools/base/init_google.h"
#include "ortools/graph/dag_constrained_shortest_path.h"
#include "ortools/graph/dag_shortest_path.h"

int main(int argc, char** argv) {
  InitGoogle(argv[0], &argc, &argv, true);

  

  std::vector<operations_research::ArcWithLengthAndResources> arcs = {
      {.from = 0, .to = 1, .length = 5, .resources = {1, 2}},
      {.from = 0, .to = 2, .length = 4, .resources = {3, 2}},
      {.from = 0, .to = 2, .length = 1, .resources = {2, 3}},
      {.from = 1, .to = 3, .length = -3, .resources = {8, 0}},
      {.from = 2, .to = 3, .length = 0, .resources = {3, 1}}};
  const int num_nodes = 4;
  const std::vector<double> max_resources = {6, 3};

  const int source = 0;
  const int destination = 3;
  const operations_research::PathWithLength path_with_length =
      operations_research::ConstrainedShortestPathsOnDag(
          num_nodes, arcs, source, destination, max_resources);

  

  std::cout << "Constrained shortest path length: " << path_with_length.length
            << std::endl;
  std::cout << "Constrained shortest path nodes: "
            << absl::StrJoin(path_with_length.node_path, ", ") << std::endl;
  return 0;
}

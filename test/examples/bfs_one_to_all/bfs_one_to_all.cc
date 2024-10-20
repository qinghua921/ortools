
























#include <iostream>
#include <utility>
#include <vector>

#include "absl/log/check.h"
#include "absl/status/status.h"
#include "absl/strings/str_join.h"
#include "ortools/base/init_google.h"
#include "ortools/base/status_macros.h"
#include "ortools/graph/bfs.h"

namespace {

absl::Status Main() {
  

  

  const std::vector<std::pair<int, int>> arcs = {{0, 1}, {1, 2}, {1, 3},
                                                 {2, 3}, {3, 0}, {4, 2}};
  const int num_nodes = 5;

  

  std::vector<std::vector<int>> adjacency_list(num_nodes);
  for (const auto& [start, end] : arcs) {
    adjacency_list[start].push_back(end);
  }

  

  const int source = 0;
  ASSIGN_OR_RETURN(
      const std::vector<int> bfs_tree,
      util::graph::GetBFSRootedTree(adjacency_list, num_nodes, source));
  

  ASSIGN_OR_RETURN(const std::vector<int> node_distances,
                   util::graph::GetBFSDistances(bfs_tree));
  for (int t = 0; t < num_nodes; ++t) {
    if (t == source) {
      continue;
    }
    if (node_distances[t] >= 0) {
      ASSIGN_OR_RETURN(const std::vector<int> shortest_path,
                       util::graph::GetBFSShortestPath(bfs_tree, t));
      std::cout << "Shortest path from 0 to " << t
                << " has length: " << node_distances[t] << std::endl;
      std::cout << "Path is: " << absl::StrJoin(shortest_path, ", ")
                << std::endl;
    } else {
      std::cout << "No path from 0 to " << t << std::endl;
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

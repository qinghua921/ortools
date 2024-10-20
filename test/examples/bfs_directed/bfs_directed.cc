
























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
  

  

  const std::vector<std::pair<int, int>> arcs = {
      {0, 1}, {0, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 0}, {3, 5}, {4, 5}};
  const int num_nodes = 6;

  

  std::vector<std::vector<int>> adjacency_list(num_nodes);
  for (const auto& [start, end] : arcs) {
    adjacency_list[start].push_back(end);
  }

  

  const int source = 0;
  const int terminal = 5;
  ASSIGN_OR_RETURN(
      const std::vector<int> bfs_tree,
      util::graph::GetBFSRootedTree(adjacency_list, num_nodes, source));
  ASSIGN_OR_RETURN(const std::vector<int> shortest_path,
                   util::graph::GetBFSShortestPath(bfs_tree, terminal));

  

  std::cout << "Shortest path length (in arcs): " << shortest_path.size() - 1
            << std::endl;
  std::cout << "Shortest path nodes: " << absl::StrJoin(shortest_path, ", ")
            << std::endl;

  return absl::OkStatus();
}

}  


int main(int argc, char** argv) {
  InitGoogle(argv[0], &argc, &argv, true);
  QCHECK_OK(Main());
  return 0;
}

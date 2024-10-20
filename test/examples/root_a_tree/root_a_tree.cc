
























#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

#include "absl/log/check.h"
#include "absl/status/status.h"
#include "absl/strings/str_join.h"
#include "ortools/base/init_google.h"
#include "ortools/base/status_macros.h"
#include "ortools/graph/graph.h"
#include "ortools/graph/rooted_tree.h"

namespace {

absl::Status Main() {
  

  

  const int32_t num_nodes = 5;
  std::vector<std::pair<int32_t, int32_t>> arcs = {
      {0, 1}, {1, 2}, {2, 3}, {1, 4}};
  util::ListGraph<> graph(num_nodes, 2 * static_cast<int32_t>(arcs.size()));
  for (const auto [s, t] : arcs) {
    graph.AddArc(s, t);
    graph.AddArc(t, s);
  }

  

  int root = 2;
  std::vector<int32_t> topological_order;
  std::vector<int32_t> depth;
  ASSIGN_OR_RETURN(const operations_research::RootedTree<int32_t> tree,
                   operations_research::RootedTreeFromGraph(
                       root, graph, &topological_order, &depth));

  

  

  

  

  

  

  std::cout << "Parents:" << std::endl;
  for (int i = 0; i < num_nodes; ++i) {
    std::cout << "  " << i << " -> " << tree.parents()[i] << std::endl;
  }

  

  

  

  

  

  

  std::cout << "Depths:" << std::endl;
  for (int i = 0; i < num_nodes; ++i) {
    std::cout << "  " << i << " -> " << depth[i] << std::endl;
  }

  

  

  

  std::cout << "Topological order: " << absl::StrJoin(topological_order, ", ")
            << std::endl;

  return absl::OkStatus();
}

}  


int main(int argc, char** argv) {
  InitGoogle(argv[0], &argc, &argv, true);
  QCHECK_OK(Main());
  return 0;
}


























#include <iostream>
#include <vector>

#include "absl/log/check.h"
#include "absl/status/status.h"
#include "absl/strings/str_join.h"
#include "ortools/base/init_google.h"
#include "ortools/base/status_macros.h"
#include "ortools/graph/rooted_tree.h"

namespace {

absl::Status Main() {
  

  

  

  

  

  

  ASSIGN_OR_RETURN(
      const operations_research::RootedTree<int> tree,
      operations_research::RootedTree<int>::Create(2, {1, 2, -1, 2, 1}));

  

  const std::vector<int> depths = tree.AllDepths();

  

  for (int s = 0; s < 5; ++s) {
    for (int t = 0; t < 5; ++t) {
      int lca = tree.LowestCommonAncestorByDepth(s, t, depths);
      const std::vector<int> path = tree.Path(s, t, lca);
      std::cout << s << " -> " << t << " [" << absl::StrJoin(path, ", ") << "]"
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

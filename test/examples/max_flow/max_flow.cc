
























#include "ortools/graph/max_flow.h"

#include <utility>
#include <vector>

#include "absl/flags/flag.h"
#include "ortools/base/init_google.h"
#include "ortools/base/logging.h"

namespace operations_research {
void SolveMaxFlow() {
  const int num_nodes = 5;
  

  

  

  

  std::vector<std::pair<std::pair<NodeIndex, NodeIndex>, FlowQuantity> > arcs =
      {{{0, 1}, 20}, {{0, 2}, 30}, {{0, 3}, 10}, {{1, 2}, 40}, {{1, 4}, 30},
       {{2, 3}, 10}, {{2, 4}, 20}, {{3, 2}, 5},  {{3, 4}, 20}};
  StarGraph graph(num_nodes, arcs.size());
  MaxFlow max_flow(&graph, 0, num_nodes - 1);
  for (const auto& it : arcs) {
    ArcIndex arc = graph.AddArc(it.first.first, it.first.second);
    max_flow.SetArcCapacity(arc, it.second);
  }

  LOG(INFO) << "Solving max flow with: " << graph.num_nodes() << " nodes, and "
            << graph.num_arcs() << " arcs.";

  

  max_flow.Solve();
  if (MaxFlow::OPTIMAL != max_flow.status()) {
    LOG(FATAL) << "Solving the max flow is not optimal!";
  }
  FlowQuantity total_flow = max_flow.GetOptimalFlow();
  LOG(INFO) << "Maximum flow: " << total_flow;
  LOG(INFO) << "";
  LOG(INFO) << " Arc  : Flow / Capacity";
  for (int i = 0; i < arcs.size(); ++i) {
    LOG(INFO) << graph.Tail(i) << " -> " << graph.Head(i) << ": "
              << max_flow.Flow(i) << " / " << max_flow.Capacity(i);
  }
}
}  


int main(int argc, char** argv) {
  absl::SetFlag(&FLAGS_stderrthreshold, 0);
  InitGoogle(argv[0], &argc, &argv, true);
  operations_research::SolveMaxFlow();
  return EXIT_SUCCESS;
}

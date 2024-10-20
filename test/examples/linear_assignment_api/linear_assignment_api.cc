
























#include <cstdlib>
#include <vector>

#include "ortools/base/init_google.h"
#include "ortools/base/logging.h"
#include "ortools/graph/ebert_graph.h"
#include "ortools/graph/linear_assignment.h"

namespace operations_research {







void AssignmentOn4x4Matrix() {
  LOG(INFO) << "Assignment on 4x4 Matrix";
  const int kNumSources = 4;
  const int kNumTargets = 4;
  const CostValue kCost[kNumSources][kNumTargets] = {{90, 76, 75, 80},
                                                     {35, 85, 55, 65},
                                                     {125, 95, 90, 105},
                                                     {45, 110, 95, 115}};
  const CostValue kExpectedCost =
      kCost[0][3] + kCost[1][2] + kCost[2][1] + kCost[3][0];
  ForwardStarGraph graph(kNumSources + kNumTargets, kNumSources * kNumTargets);
  LinearSumAssignment<ForwardStarGraph> assignment(graph, kNumSources);
  for (NodeIndex source = 0; source < kNumSources; ++source) {
    for (NodeIndex target = 0; target < kNumTargets; ++target) {
      ArcIndex arc = graph.AddArc(source, kNumSources + target);
      assignment.SetArcCost(arc, kCost[source][target]);
    }
  }
  CHECK(assignment.ComputeAssignment());
  CostValue total_cost = assignment.GetCost();
  CHECK_EQ(kExpectedCost, total_cost);
}

void AnotherAssignment() {
  LOG(INFO) << "Another assignment on 4x4 matrix";
  std::vector<std::vector<int>> matrice(
      {{8, 7, 9, 9}, {5, 2, 7, 8}, {6, 1, 4, 9}, {2, 3, 2, 6}});
  const int kSize = matrice.size();
  ForwardStarGraph graph(2 * kSize, kSize * kSize);
  LinearSumAssignment<ForwardStarGraph> assignment(graph, kSize);
  for (int i = 0; i < kSize; ++i) {
    CHECK_EQ(kSize, matrice[i].size());
    for (int j = 0; j < kSize; ++j) {
      int arcIndex = graph.AddArc(i, j + kSize);
      assignment.SetArcCost(arcIndex, matrice[i][j]);
    }
  }

  assignment.ComputeAssignment();
  LOG(INFO) << "Cost : " << assignment.GetCost();
}

}  


int main(int argc, char** argv) {
  InitGoogle(argv[0], &argc, &argv, true);
  operations_research::AssignmentOn4x4Matrix();
  operations_research::AnotherAssignment();
  return EXIT_SUCCESS;
}

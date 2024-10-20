
























#include <iostream>
#include <utility>
#include <vector>

#include "absl/strings/str_join.h"
#include "ortools/base/init_google.h"
#include "ortools/graph/bounded_dijkstra.h"

namespace {


struct Edge {
  int endpoint1 = 0;
  int endpoint2 = 0;
  int length = 0;
};
}  


int main(int argc, char** argv) {
  InitGoogle(argv[0], &argc, &argv, true);

  

  std::vector<Edge> edges = {
      {.endpoint1 = 0, .endpoint2 = 1, .length = 8},
      {.endpoint1 = 0, .endpoint2 = 2, .length = 1},
      {.endpoint1 = 1, .endpoint2 = 2, .length = 0},
      {.endpoint1 = 1, .endpoint2 = 3, .length = 1},
      {.endpoint1 = 1, .endpoint2 = 4, .length = 4},
      {.endpoint1 = 2, .endpoint2 = 4, .length = 5},
      {.endpoint1 = 3, .endpoint2 = 4, .length = 2},
  };

  

  std::vector<int> tails;
  std::vector<int> heads;
  std::vector<int> lengths;
  for (const Edge& edge : edges) {
    

    tails.push_back(edge.endpoint1);
    heads.push_back(edge.endpoint2);
    lengths.push_back(edge.length);
    

    tails.push_back(edge.endpoint2);
    heads.push_back(edge.endpoint1);
    lengths.push_back(edge.length);
  }

  

  std::pair<int, std::vector<int>> result =
      operations_research::SimpleOneToOneShortestPath<int>(0, 4, tails, heads,
                                                           lengths);

  

  std::cout << "Shortest path length: " << result.first << std::endl;
  std::cout << "Shortest path nodes: " << absl::StrJoin(result.second, ", ")
            << std::endl;
  return 0;
}

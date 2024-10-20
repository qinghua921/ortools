
























#include <iostream>
#include <utility>
#include <vector>

#include "absl/strings/str_join.h"
#include "ortools/base/init_google.h"
#include "ortools/graph/bounded_dijkstra.h"

namespace {
struct Arc {
  int start = 0;
  int end = 0;
  int length = 0;
};
}  


int main(int argc, char** argv) {
  InitGoogle(argv[0], &argc, &argv, true);

  

  std::vector<Arc> arcs = {
      {.start = 0, .end = 1, .length = 3}, {.start = 0, .end = 2, .length = 5},
      {.start = 1, .end = 2, .length = 1}, {.start = 1, .end = 3, .length = 4},
      {.start = 1, .end = 4, .length = 0}, {.start = 2, .end = 4, .length = 2},
      {.start = 3, .end = 2, .length = 2}, {.start = 3, .end = 5, .length = 4},
      {.start = 4, .end = 3, .length = 2}, {.start = 4, .end = 5, .length = 5}};

  

  std::vector<int> tails;
  std::vector<int> heads;
  std::vector<int> lengths;
  for (const Arc& arc : arcs) {
    tails.push_back(arc.start);
    heads.push_back(arc.end);
    lengths.push_back(arc.length);
  }

  

  std::pair<int, std::vector<int>> result =
      operations_research::SimpleOneToOneShortestPath<int>(0, 5, tails, heads,
                                                           lengths);

  

  std::cout << "Shortest path length: " << result.first << std::endl;
  std::cout << "Shortest path nodes: " << absl::StrJoin(result.second, ", ")
            << std::endl;
  return 0;
}

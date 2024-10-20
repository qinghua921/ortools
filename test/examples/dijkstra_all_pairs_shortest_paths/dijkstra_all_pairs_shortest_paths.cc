



















































#define _USE_MATH_DEFINES  

#include <cmath>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

#include "absl/algorithm/container.h"
#include "absl/flags/flag.h"
#include "absl/log/check.h"
#include "absl/random/random.h"
#include "absl/time/clock.h"
#include "absl/time/time.h"
#include "ortools/base/init_google.h"
#include "ortools/graph/bounded_dijkstra.h"
#include "ortools/graph/graph.h"

ABSL_FLAG(int32_t, num_nodes, 50,
          "How many nodes to create in the random graph");

ABSL_FLAG(double, expected_neighbors, 5,
          "The average number of neighbors of a node, if < 2, then most nodes "
          "will not be connected.");

namespace {

constexpr double kPi = M_PI;  


std::vector<std::pair<double, double>> GenerateRandomPoints(int32_t n) {
  absl::BitGen bit_gen;
  std::vector<std::pair<double, double>> result(n);
  for (int32_t i = 0; i < n; ++i) {
    result[i].first = absl::Uniform(bit_gen, 0.0, 1.0);
    result[i].second = absl::Uniform(bit_gen, 0.0, 1.0);
  }
  absl::c_sort(result);
  return result;
}

double Distance(const std::pair<double, double>& node1,
                const std::pair<double, double>& node2) {
  const double dx = node1.first - node2.first;
  const double dy = node1.second - node2.second;
  return std::sqrt(dx * dx + dy * dy);
}

std::pair<util::StaticGraph<int32_t, int32_t>, std::vector<double>> MakeGraph(
    const std::vector<std::pair<double, double>>& points,
    double max_edge_distance) {
  util::StaticGraph<int32_t, int32_t> graph;
  CHECK_LE(points.size(),
           static_cast<size_t>(std::numeric_limits<int32_t>::max()));
  const int32_t num_nodes = static_cast<int32_t>(points.size());
  if (num_nodes > 0) {
    graph.AddNode(num_nodes - 1);
  }
  std::vector<double> arcs;
  for (int32_t i = 0; i < num_nodes; ++i) {
    for (int32_t j = i + 1; j < num_nodes; ++j) {
      

      

      

      

      if (points[j].first - points[i].first > max_edge_distance) {
        break;
      }
      const double dist = Distance(points[i], points[j]);
      if (dist <= max_edge_distance) {
        graph.AddArc(i, j);
        arcs.push_back(dist);
        graph.AddArc(j, i);
        arcs.push_back(dist);
      }
    }
  }
  std::vector<int32_t> permutation;
  graph.Build(&permutation);
  util::Permute(permutation, &arcs);

  return {std::move(graph), std::move(arcs)};
}

std::vector<std::pair<int32_t, int32_t>> AllPairsWithinDistance(
    const util::StaticGraph<int32_t, int32_t>& graph,
    const std::vector<double>& arc_lengths, double limit) {
  operations_research::BoundedDijkstraWrapper<util::StaticGraph<>, double>
      dijkstra(&graph, &arc_lengths);
  std::vector<std::pair<int32_t, int32_t>> result;
  for (int32_t start = 0; start < graph.num_nodes(); ++start) {
    const std::vector<int32_t> reachable =
        dijkstra.RunBoundedDijkstra(start, limit);
    for (const int32_t dest : reachable) {
      result.push_back({start, dest});
    }
  }
  return result;
}

}  


int main(int argc, char** argv) {
  InitGoogle(argv[0], &argc, &argv, true);
  const int32_t n = absl::GetFlag(FLAGS_num_nodes);
  CHECK_GE(n, 2);  

  const double expected_neighbors = absl::GetFlag(FLAGS_expected_neighbors);
  CHECK_GE(expected_neighbors, 0);
  const std::vector<std::pair<double, double>> node_locations =
      GenerateRandomPoints(n);
  const double expected_edges = n * expected_neighbors / 2.0;
  

  

  

  const double max_edge_distance =
      std::sqrt(expected_neighbors / ((n - 1) * kPi));
  std::cout << "Building graph..." << std::endl;
  const auto [graph, arc_lengths] =
      MakeGraph(node_locations, max_edge_distance);
  std::cout << "Done building graph" << std::endl;
  const double limit = 3 * max_edge_distance;
  

  

  

  

  const double estimated_connected_pairs = (kPi * limit * limit * n) * n / 2;
  std::cout << "Nodes: " << n << std::endl;
  std::cout << "Estimated neighbors per node: " << expected_neighbors
            << std::endl;
  std::cout << "Max distance for edge: " << max_edge_distance << std::endl;
  std::cout << "Estimated edges: " << expected_edges << std::endl;
  std::cout << "Actual edges: " << graph.num_arcs() / 2 << std::endl;
  std::cout << "All pairs shortest path distance limit: " << limit << std::endl;
  std::cout << "Upper bound (estimated) on pairs of points within limit: "
            << estimated_connected_pairs << std::endl;

  const absl::Time start = absl::Now();
  const std::vector<std::pair<int, int>> all_pairs_within_distance =
      AllPairsWithinDistance(graph, arc_lengths, limit);
  const absl::Duration shortest_path_time = absl::Now() - start;
  

  std::cout << "Actual pairs of points within distance limit: "
            << all_pairs_within_distance.size() / 2 << std::endl;
  std::cout << "Shortest path time: " << shortest_path_time << std::endl;
  return 0;
}

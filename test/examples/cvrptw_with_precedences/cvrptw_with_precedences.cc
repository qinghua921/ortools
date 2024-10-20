











































#include <cstdint>
#include <random>
#include <utility>
#include <vector>

#include "absl/random/random.h"
#include "google/protobuf/text_format.h"
#include "ortools/base/commandlineflags.h"
#include "ortools/base/init_google.h"
#include "ortools/base/logging.h"
#include "ortools/base/types.h"
#include "ortools/constraint_solver/routing.h"
#include "ortools/constraint_solver/routing_index_manager.h"
#include "ortools/constraint_solver/routing_parameters.h"
#include "ortools/constraint_solver/routing_parameters.pb.h"
#include "ortools/graph/graph_builder.h"
#include "ortools/routing/parsers/cvrptw_lib.h"

using operations_research::Assignment;
using operations_research::DefaultRoutingSearchParameters;
using operations_research::GetSeed;
using operations_research::LocationContainer;
using operations_research::RandomDemand;
using operations_research::RoutingDimension;
using operations_research::RoutingIndexManager;
using operations_research::RoutingModel;
using operations_research::RoutingNodeIndex;
using operations_research::RoutingSearchParameters;
using operations_research::ServiceTimePlusTransition;

ABSL_FLAG(int, vrp_orders, 100, "Nodes in the problem.");
ABSL_FLAG(int, vrp_vehicles, 20,
          "Size of Traveling Salesman Problem instance.");
ABSL_FLAG(bool, vrp_use_deterministic_random_seed, false,
          "Use deterministic random seeds.");
ABSL_FLAG(bool, vrp_use_same_vehicle_costs, false,
          "Use same vehicle costs in the routing model");
ABSL_FLAG(std::string, routing_search_parameters, "",
          "Text proto RoutingSearchParameters (possibly partial) that will "
          "override the DefaultRoutingSearchParameters()");
ABSL_FLAG(int, vrp_precedences, 5,
          "Number of precedence indices. Precedences will be chosen "
          "randomly with the constraint that they don't form cycles.");
ABSL_FLAG(int64_t, vrp_precedence_offset, 100,
          "The offset that applies to the precedences. For each pair linked "
          "by a precedence constraint, pair.second can only start after the "
          "start of pair.first + offset.");

const char* kTime = "Time";
const char* kCapacity = "Capacity";
const int64_t kMaxNodesPerGroup = 10;
const int64_t kSameVehicleCost = 1000;

int main(int argc, char** argv) {
  InitGoogle(argv[0], &argc, &argv, true);
  CHECK_LT(0, absl::GetFlag(FLAGS_vrp_orders))
      << "Specify an instance size greater than 0.";
  CHECK_LT(0, absl::GetFlag(FLAGS_vrp_vehicles))
      << "Specify a non-null vehicle fleet size.";
  

  

  

  const RoutingIndexManager::NodeIndex kDepot(0);
  RoutingIndexManager manager(absl::GetFlag(FLAGS_vrp_orders) + 1,
                              absl::GetFlag(FLAGS_vrp_vehicles), kDepot);
  RoutingModel routing(manager);

  

  const int64_t kXMax = 100000;
  const int64_t kYMax = 100000;
  const int64_t kSpeed = 10;
  LocationContainer locations(
      kSpeed, absl::GetFlag(FLAGS_vrp_use_deterministic_random_seed));
  for (int location = 0; location <= absl::GetFlag(FLAGS_vrp_orders);
       ++location) {
    locations.AddRandomLocation(kXMax, kYMax);
  }

  

  const int vehicle_cost = routing.RegisterTransitCallback(
      [&locations, &manager](int64_t i, int64_t j) {
        return locations.ManhattanDistance(manager.IndexToNode(i),
                                           manager.IndexToNode(j));
      });
  routing.SetArcCostEvaluatorOfAllVehicles(vehicle_cost);

  

  const int64_t kVehicleCapacity = 40;
  const int64_t kNullCapacitySlack = 0;
  RandomDemand demand(manager.num_nodes(), kDepot,
                      absl::GetFlag(FLAGS_vrp_use_deterministic_random_seed));
  demand.Initialize();
  routing.AddDimension(routing.RegisterTransitCallback(
                           [&demand, &manager](int64_t i, int64_t j) {
                             return demand.Demand(manager.IndexToNode(i),
                                                  manager.IndexToNode(j));
                           }),
                       kNullCapacitySlack, kVehicleCapacity,
                       
true, kCapacity);

  

  const int64_t kTimePerDemandUnit = 300;
  const int64_t kHorizon = 24 * 3600;
  ServiceTimePlusTransition time(
      kTimePerDemandUnit,
      [&demand](RoutingNodeIndex i, RoutingNodeIndex j) {
        return demand.Demand(i, j);
      },
      [&locations](RoutingNodeIndex i, RoutingNodeIndex j) {
        return locations.ManhattanTime(i, j);
      });
  routing.AddDimension(
      routing.RegisterTransitCallback([&time, &manager](int64_t i, int64_t j) {
        return time.Compute(manager.IndexToNode(i), manager.IndexToNode(j));
      }),
      kHorizon, kHorizon, 
true, kTime);
  RoutingDimension* time_dimension = routing.GetMutableDimension(kTime);

  

  std::mt19937 randomizer(
      GetSeed(absl::GetFlag(FLAGS_vrp_use_deterministic_random_seed)));
  const int64_t kTWDuration = 5 * 3600;
  for (int order = 1; order < manager.num_nodes(); ++order) {
    const int64_t start =
        absl::Uniform<int32_t>(randomizer, 0, kHorizon - kTWDuration);
    time_dimension->CumulVar(order)->SetRange(start, start + kTWDuration);
  }

  

  const int64_t kPenalty = 10000000;
  const RoutingIndexManager::NodeIndex kFirstNodeAfterDepot(1);
  for (RoutingIndexManager::NodeIndex order = kFirstNodeAfterDepot;
       order < manager.num_nodes(); ++order) {
    std::vector<int64_t> orders(1, manager.NodeToIndex(order));
    routing.AddDisjunction(orders, kPenalty);
  }

  

  if (absl::GetFlag(FLAGS_vrp_use_same_vehicle_costs)) {
    std::vector<int64_t> group;
    for (RoutingIndexManager::NodeIndex order = kFirstNodeAfterDepot;
         order < manager.num_nodes(); ++order) {
      group.push_back(manager.NodeToIndex(order));
      if (group.size() == kMaxNodesPerGroup) {
        routing.AddSoftSameVehicleConstraint(group, kSameVehicleCost);
        group.clear();
      }
    }
    if (!group.empty()) {
      routing.AddSoftSameVehicleConstraint(group, kSameVehicleCost);
    }
  }

  

  

  

  

  if (absl::GetFlag(FLAGS_vrp_precedences) > 0) {
    

    std::vector<std::pair<int, int>> precedences;
    GraphBuilder::RandomEdges(
        GraphBuilder::DISALLOW_ALL_CYCLES, absl::GetFlag(FLAGS_vrp_orders),
        absl::GetFlag(FLAGS_vrp_precedences), randomizer, &precedences);

    LOG(INFO) << "Adding precedences: ";
    for (const std::pair<int, int>& precedence : precedences) {
      LOG(INFO) << precedence.first << " -> " << precedence.second;
      time_dimension->AddNodePrecedence(
          {precedence.first, precedence.second,
           absl::GetFlag(FLAGS_vrp_precedence_offset)});
    }
  }
  

  RoutingSearchParameters parameters = DefaultRoutingSearchParameters();
  CHECK(google::protobuf::TextFormat::MergeFromString(
      absl::GetFlag(FLAGS_routing_search_parameters), &parameters));
  const Assignment* solution = routing.SolveWithParameters(parameters);
  if (solution != nullptr) {
    DisplayPlan(manager, routing, *solution,
                absl::GetFlag(FLAGS_vrp_use_same_vehicle_costs),
                kMaxNodesPerGroup, kSameVehicleCost,
                routing.GetDimensionOrDie(kCapacity),
                routing.GetDimensionOrDie(kTime));
  } else {
    LOG(INFO) << "No solution found.";
  }

  return 0;
}

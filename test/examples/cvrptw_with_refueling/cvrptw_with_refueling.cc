







































#include <cstdint>
#include <random>
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
ABSL_FLAG(std::string, routing_search_parameters, "",
          "Text proto RoutingSearchParameters (possibly partial) that will "
          "override the DefaultRoutingSearchParameters()");

const char* kTime = "Time";
const char* kCapacity = "Capacity";
const char* kFuel = "Fuel";



bool IsRefuelNode(int64_t node) {
  const int64_t kRefuelNodeRatio = 10;
  return (node % kRefuelNodeRatio == 0);
}

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
  const RoutingDimension& time_dimension = routing.GetDimensionOrDie(kTime);
  

  

  

  

  

  std::mt19937 randomizer(
      144 + GetSeed(absl::GetFlag(FLAGS_vrp_use_deterministic_random_seed)));
  const int64_t kTWDuration = 5 * 3600;
  for (int order = 1; order < manager.num_nodes(); ++order) {
    if (!IsRefuelNode(order)) {
      const int64_t start =
          absl::Uniform<int32_t>(randomizer, 0, kHorizon - kTWDuration);
      time_dimension.CumulVar(order)->SetRange(start, start + kTWDuration);
    }
  }

  

  

  

  const int64_t kFuelCapacity = kXMax + kYMax;
  routing.AddDimension(
      routing.RegisterTransitCallback(
          [&locations, &manager](int64_t i, int64_t j) {
            return locations.NegManhattanDistance(manager.IndexToNode(i),
                                                  manager.IndexToNode(j));
          }),
      kFuelCapacity, kFuelCapacity, 
false, kFuel);
  const RoutingDimension& fuel_dimension = routing.GetDimensionOrDie(kFuel);
  for (int order = 0; order < routing.Size(); ++order) {
    

    if (!IsRefuelNode(order) || routing.IsStart(order)) {
      fuel_dimension.SlackVar(order)->SetValue(0);
    }
    

    routing.AddVariableMinimizedByFinalizer(fuel_dimension.CumulVar(order));
  }

  

  const int64_t kPenalty = 100000;
  const RoutingIndexManager::NodeIndex kFirstNodeAfterDepot(1);
  for (RoutingIndexManager::NodeIndex order = kFirstNodeAfterDepot;
       order < routing.nodes(); ++order) {
    std::vector<int64_t> orders(1, manager.NodeToIndex(order));
    routing.AddDisjunction(orders, kPenalty);
  }

  

  RoutingSearchParameters parameters = DefaultRoutingSearchParameters();
  CHECK(google::protobuf::TextFormat::MergeFromString(
      absl::GetFlag(FLAGS_routing_search_parameters), &parameters));
  const Assignment* solution = routing.SolveWithParameters(parameters);
  if (solution != nullptr) {
    DisplayPlan(manager, routing, *solution, 
false,
                
0, 
0,
                routing.GetDimensionOrDie(kCapacity),
                routing.GetDimensionOrDie(kTime));
  } else {
    LOG(INFO) << "No solution found.";
  }
  return EXIT_SUCCESS;
}

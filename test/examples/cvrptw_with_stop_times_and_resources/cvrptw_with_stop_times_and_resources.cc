







































#include <cstdint>
#include <random>
#include <vector>

#include "absl/random/random.h"
#include "absl/strings/str_cat.h"
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
using operations_research::IntervalVar;
using operations_research::IntVar;
using operations_research::LocationContainer;
using operations_research::RandomDemand;
using operations_research::RoutingDimension;
using operations_research::RoutingIndexManager;
using operations_research::RoutingModel;
using operations_research::RoutingNodeIndex;
using operations_research::RoutingSearchParameters;
using operations_research::Solver;
using operations_research::StopServiceTimePlusTransition;

ABSL_FLAG(int, vrp_stops, 25, "Stop locations in the problem.");
ABSL_FLAG(int, vrp_orders_per_stop, 5, "Nodes for each stop.");
ABSL_FLAG(int, vrp_vehicles, 20,
          "Size of Traveling Salesman Problem instance.");
ABSL_FLAG(bool, vrp_use_deterministic_random_seed, false,
          "Use deterministic random seeds.");
ABSL_FLAG(std::string, routing_search_parameters, "",
          "Text proto RoutingSearchParameters (possibly partial) that will "
          "override the DefaultRoutingSearchParameters()");

const char* kTime = "Time";
const char* kCapacity = "Capacity";

int main(int argc, char** argv) {
  InitGoogle(argv[0], &argc, &argv, true);
  CHECK_LT(0, absl::GetFlag(FLAGS_vrp_stops))
      << "Specify an instance size greater than 0.";
  CHECK_LT(0, absl::GetFlag(FLAGS_vrp_orders_per_stop))
      << "Specify an instance size greater than 0.";
  CHECK_LT(0, absl::GetFlag(FLAGS_vrp_vehicles))
      << "Specify a non-null vehicle fleet size.";
  const int vrp_orders =
      absl::GetFlag(FLAGS_vrp_stops) * absl::GetFlag(FLAGS_vrp_orders_per_stop);
  

  

  const RoutingIndexManager::NodeIndex kDepot(0);
  RoutingIndexManager manager(vrp_orders + 1, absl::GetFlag(FLAGS_vrp_vehicles),
                              kDepot);
  RoutingModel routing(manager);

  

  const int64_t kXMax = 100000;
  const int64_t kYMax = 100000;
  const int64_t kSpeed = 10;
  LocationContainer locations(
      kSpeed, absl::GetFlag(FLAGS_vrp_use_deterministic_random_seed));
  for (int stop = 0; stop <= absl::GetFlag(FLAGS_vrp_stops); ++stop) {
    const int num_orders =
        stop == 0 ? 1 : absl::GetFlag(FLAGS_vrp_orders_per_stop);
    locations.AddRandomLocation(kXMax, kYMax, num_orders);
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

  

  const int64_t kStopTime = 300;
  const int64_t kHorizon = 24 * 3600;
  StopServiceTimePlusTransition time(
      kStopTime, locations,
      [&locations](RoutingNodeIndex i, RoutingNodeIndex j) {
        return locations.ManhattanTime(i, j);
      });
  routing.AddDimension(
      routing.RegisterTransitCallback([&time, &manager](int64_t i, int64_t j) {
        return time.Compute(manager.IndexToNode(i), manager.IndexToNode(j));
      }),
      kHorizon, kHorizon, 
false, kTime);
  const RoutingDimension& time_dimension = routing.GetDimensionOrDie(kTime);

  

  std::mt19937 randomizer(
      GetSeed(absl::GetFlag(FLAGS_vrp_use_deterministic_random_seed)));
  const int64_t kTWDuration = 5 * 3600;
  for (int stop = 0; stop < absl::GetFlag(FLAGS_vrp_stops); ++stop) {
    const int64_t start =
        absl::Uniform<int32_t>(randomizer, 0, kHorizon - kTWDuration);
    for (int stop_order = 0;
         stop_order < absl::GetFlag(FLAGS_vrp_orders_per_stop); ++stop_order) {
      const int order =
          stop * absl::GetFlag(FLAGS_vrp_orders_per_stop) + stop_order + 1;
      time_dimension.CumulVar(order)->SetRange(start, start + kTWDuration);
    }
  }

  

  Solver* const solver = routing.solver();
  std::vector<IntervalVar*> intervals;
  for (int stop = 0; stop < absl::GetFlag(FLAGS_vrp_stops); ++stop) {
    std::vector<IntervalVar*> stop_intervals;
    for (int stop_order = 0;
         stop_order < absl::GetFlag(FLAGS_vrp_orders_per_stop); ++stop_order) {
      const int order =
          stop * absl::GetFlag(FLAGS_vrp_orders_per_stop) + stop_order + 1;
      IntervalVar* const interval = solver->MakeFixedDurationIntervalVar(
          0, kHorizon, kStopTime, true, absl::StrCat("Order", order));
      intervals.push_back(interval);
      stop_intervals.push_back(interval);
      

      IntVar* const order_start = time_dimension.CumulVar(order);
      solver->AddConstraint(
          solver->MakeIsEqualCt(interval->SafeStartExpr(0), order_start,
                                interval->PerformedExpr()->Var()));
      

      

      

      IntVar* const is_null_duration =
          solver
              ->MakeElement(
                  [&locations, order](int64_t index) {
                    return locations.SameLocationFromIndex(order, index);
                  },
                  routing.NextVar(order))
              ->Var();
      solver->AddConstraint(
          solver->MakeNonEquality(interval->PerformedExpr(), is_null_duration));
      routing.AddIntervalToAssignment(interval);
      

      

      routing.AddVariableMaximizedByFinalizer(order_start);
    }
    

    std::vector<int64_t> location_usage(stop_intervals.size(), 1);
    solver->AddConstraint(solver->MakeCumulative(
        stop_intervals, location_usage, 1, absl::StrCat("Client", stop)));
  }
  

  for (int vehicle = 0; vehicle < manager.num_vehicles(); ++vehicle) {
    routing.AddVariableMinimizedByFinalizer(
        time_dimension.CumulVar(routing.End(vehicle)));
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
    LOG(INFO) << "Stop intervals:";
    for (IntervalVar* const interval : intervals) {
      if (solution->PerformedValue(interval)) {
        LOG(INFO) << interval->name() << ": " << solution->StartValue(interval);
      }
    }
  } else {
    LOG(INFO) << "No solution found.";
  }
  return EXIT_SUCCESS;
}

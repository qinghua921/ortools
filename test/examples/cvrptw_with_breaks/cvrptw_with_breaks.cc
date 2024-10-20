



















































#include <cstdint>
#include <random>
#include <utility>
#include <vector>

#include "absl/random/random.h"
#include "absl/strings/str_cat.h"
#include "google/protobuf/text_format.h"
#include "ortools/base/commandlineflags.h"
#include "ortools/base/init_google.h"
#include "ortools/base/logging.h"
#include "ortools/base/types.h"
#include "ortools/constraint_solver/routing.h"
#include "ortools/constraint_solver/routing_enums.pb.h"
#include "ortools/constraint_solver/routing_index_manager.h"
#include "ortools/constraint_solver/routing_parameters.h"
#include "ortools/constraint_solver/routing_parameters.pb.h"
#include "ortools/routing/parsers/cvrptw_lib.h"

using operations_research::Assignment;
using operations_research::DefaultRoutingSearchParameters;
using operations_research::FirstSolutionStrategy;
using operations_research::GetSeed;
using operations_research::IntervalVar;
using operations_research::LocationContainer;
using operations_research::RandomDemand;
using operations_research::RoutingDimension;
using operations_research::RoutingIndexManager;
using operations_research::RoutingModel;
using operations_research::RoutingNodeIndex;
using operations_research::RoutingSearchParameters;
using operations_research::ServiceTimePlusTransition;
using operations_research::Solver;

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
  RoutingSearchParameters parameters = DefaultRoutingSearchParameters();
  CHECK(google::protobuf::TextFormat::MergeFromString(
      absl::GetFlag(FLAGS_routing_search_parameters), &parameters));
  parameters.set_first_solution_strategy(
      FirstSolutionStrategy::PARALLEL_CHEAPEST_INSERTION);

  

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
false, kTime);
  RoutingDimension* const time_dimension = routing.GetMutableDimension(kTime);

  

  std::mt19937 randomizer(
      GetSeed(absl::GetFlag(FLAGS_vrp_use_deterministic_random_seed)));
  const int64_t kTWDuration = 5 * 3600;
  for (int order = 1; order < manager.num_nodes(); ++order) {
    const int64_t start =
        absl::Uniform<int32_t>(randomizer, 0, kHorizon - kTWDuration);
    time_dimension->CumulVar(order)->SetRange(start, start + kTWDuration);
    routing.AddToAssignment(time_dimension->SlackVar(order));
  }

  

  for (int i = 0; i < routing.Size(); ++i) {
    routing.AddVariableMinimizedByFinalizer(time_dimension->CumulVar(i));
  }
  for (int j = 0; j < absl::GetFlag(FLAGS_vrp_vehicles); ++j) {
    routing.AddVariableMinimizedByFinalizer(
        time_dimension->CumulVar(routing.Start(j)));
    routing.AddVariableMinimizedByFinalizer(
        time_dimension->CumulVar(routing.End(j)));
  }

  

  

  

  

  

  std::vector<int64_t> service_times(routing.Size());
  for (int node = 0; node < routing.Size(); node++) {
    if (node >= routing.nodes()) {
      service_times[node] = 0;
    } else {
      const RoutingIndexManager::NodeIndex index(node);
      service_times[node] = kTimePerDemandUnit * demand.Demand(index, index);
    }
  }
  const std::vector<std::vector<int>> break_data = {
      {
 11, 
 13, 
 2400},
      {
 10, 
 15, 
 1800},
      {
 10, 
 15, 
 1800}};
  Solver* const solver = routing.solver();
  for (int vehicle = 0; vehicle < absl::GetFlag(FLAGS_vrp_vehicles);
       ++vehicle) {
    std::vector<IntervalVar*> breaks;
    for (int i = 0; i < break_data.size(); ++i) {
      IntervalVar* const break_interval = solver->MakeFixedDurationIntervalVar(
          break_data[i][0] * 3600, break_data[i][1] * 3600, break_data[i][2],
          true, absl::StrCat("Break ", i, " on vehicle ", vehicle));
      breaks.push_back(break_interval);
    }
    

    solver->AddConstraint(solver->MakeEquality(breaks[1]->PerformedExpr(),
                                               breaks[2]->PerformedExpr()));
    

    solver->AddConstraint(solver->MakeIntervalVarRelationWithDelay(
        breaks[2], Solver::STARTS_AFTER_END, breaks[1], 3600));
    

    solver->AddConstraint(solver->MakeNonEquality(breaks[0]->PerformedExpr(),
                                                  breaks[2]->PerformedExpr()));

    time_dimension->SetBreakIntervalsOfVehicle(std::move(breaks), vehicle,
                                               service_times);
  }

  

  const int64_t kPenalty = 10000000;
  const RoutingIndexManager::NodeIndex kFirstNodeAfterDepot(1);
  for (RoutingIndexManager::NodeIndex order = kFirstNodeAfterDepot;
       order < routing.nodes(); ++order) {
    std::vector<int64_t> orders(1, manager.NodeToIndex(order));
    routing.AddDisjunction(orders, kPenalty);
  }

  

  const Assignment* solution = routing.SolveWithParameters(parameters);
  if (solution != nullptr) {
    LOG(INFO) << "Breaks: ";
    for (const auto& break_interval :
         solution->IntervalVarContainer().elements()) {
      if (break_interval.PerformedValue() == 1) {
        LOG(INFO) << break_interval.Var()->name() << " "
                  << break_interval.DebugString();
      } else {
        LOG(INFO) << break_interval.Var()->name() << " unperformed";
      }
    }
    DisplayPlan(manager, routing, *solution, false, 0, 0,
                routing.GetDimensionOrDie(kCapacity),
                routing.GetDimensionOrDie(kTime));
  } else {
    LOG(INFO) << "No solution found.";
  }
  return EXIT_SUCCESS;
}

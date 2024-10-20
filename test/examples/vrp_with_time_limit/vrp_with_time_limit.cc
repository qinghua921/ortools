




























#include <algorithm>
#include <cstdint>
#include <sstream>
#include <vector>

#include "google/protobuf/duration.pb.h"
#include "ortools/constraint_solver/routing.h"
#include "ortools/constraint_solver/routing_enums.pb.h"
#include "ortools/constraint_solver/routing_index_manager.h"
#include "ortools/constraint_solver/routing_parameters.h"



namespace operations_research {










void PrintSolution(const RoutingIndexManager& manager,
                   const RoutingModel& routing, const Assignment& solution) {
  int64_t max_route_distance = 0;
  for (int vehicle_id = 0; vehicle_id < manager.num_vehicles(); ++vehicle_id) {
    int64_t index = routing.Start(vehicle_id);
    LOG(INFO) << "Route for Vehicle " << vehicle_id << ":";
    int64_t route_distance = 0;
    std::stringstream route;
    while (!routing.IsEnd(index)) {
      route << manager.IndexToNode(index).value() << " -> ";
      const int64_t previous_index = index;
      index = solution.Value(routing.NextVar(index));
      route_distance += const_cast<RoutingModel&>(routing).GetArcCostForVehicle(
          previous_index, index, int64_t{vehicle_id});
    }
    LOG(INFO) << route.str() << manager.IndexToNode(index).value();
    LOG(INFO) << "Distance of the route: " << route_distance << "m";
    max_route_distance = std::max(route_distance, max_route_distance);
  }
  LOG(INFO) << "Maximum of the route distances: " << max_route_distance << "m";
  LOG(INFO) << "";
  LOG(INFO) << "Problem solved in " << routing.solver()->wall_time() << "ms";
}



void VrpGlobalSpan() {
  

  

  const int num_locations = 20;
  const int num_vehicles = 5;
  const RoutingIndexManager::NodeIndex depot{0};
  


  

  

  RoutingIndexManager manager(num_locations, num_vehicles, depot);
  


  

  

  RoutingModel routing(manager);
  


  

  

  const int transit_callback_index = routing.RegisterTransitCallback(
      [](int64_t from_index, int64_t to_index) -> int64_t {
        (void)from_index;
        (void)to_index;
        return 1;
      });
  


  

  

  routing.SetArcCostEvaluatorOfAllVehicles(transit_callback_index);
  


  

  

  routing.AddDimension(transit_callback_index,
                       
0,
                       
3000,
                       
true, "Distance");
  const RoutingDimension& distance_dimension =
      routing.GetDimensionOrDie("Distance");
  const_cast<RoutingDimension&>(distance_dimension)
      .SetGlobalSpanCostCoefficient(100);
  


  

  

  RoutingSearchParameters search_parameters = DefaultRoutingSearchParameters();
  search_parameters.set_first_solution_strategy(
      FirstSolutionStrategy::PATH_CHEAPEST_ARC);
  search_parameters.set_local_search_metaheuristic(
      LocalSearchMetaheuristic::GUIDED_LOCAL_SEARCH);
  search_parameters.set_log_search(true);
  search_parameters.mutable_time_limit()->set_seconds(5);
  


  

  

  const Assignment* solution = routing.SolveWithParameters(search_parameters);
  


  

  

  PrintSolution(manager, routing, *solution);
  

}
}  


int main(int 
, char* 
[]) {
  operations_research::VrpGlobalSpan();
  return EXIT_SUCCESS;
}



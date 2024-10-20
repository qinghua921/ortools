




























#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <sstream>

#include "ortools/constraint_solver/routing.h"
#include "ortools/constraint_solver/routing_enums.pb.h"
#include "ortools/constraint_solver/routing_index_manager.h"
#include "ortools/constraint_solver/routing_parameters.h"



namespace operations_research {

void SimpleRoutingProgram() {
  

  

  int num_location = 5;
  int num_vehicles = 1;
  RoutingIndexManager::NodeIndex depot{0};
  


  

  

  RoutingIndexManager manager(num_location, num_vehicles, depot);
  


  

  

  RoutingModel routing(manager);
  


  

  

  int distance_call_index = routing.RegisterTransitCallback(
      [&manager](int64_t from_index, int64_t to_index) -> int64_t {
        

        auto from_node = manager.IndexToNode(from_index).value();
        auto to_node = manager.IndexToNode(to_index).value();
        return std::abs(to_node - from_node);
      });
  routing.SetArcCostEvaluatorOfAllVehicles(distance_call_index);
  


  

  

  RoutingSearchParameters searchParameters = DefaultRoutingSearchParameters();
  searchParameters.set_first_solution_strategy(
      FirstSolutionStrategy::PATH_CHEAPEST_ARC);
  


  

  

  const Assignment* solution = routing.SolveWithParameters(searchParameters);
  


  

  

  LOG(INFO) << "Objective: " << solution->ObjectiveValue();
  

  int64_t index = routing.Start(0);
  LOG(INFO) << "Route for Vehicle 0:";
  int64_t route_distance = 0;
  std::ostringstream route;
  while (!routing.IsEnd(index)) {
    route << manager.IndexToNode(index).value() << " -> ";
    const int64_t previous_index = index;
    index = solution->Value(routing.NextVar(index));
    route_distance +=
        routing.GetArcCostForVehicle(previous_index, index, int64_t{0});
  }
  LOG(INFO) << route.str() << manager.IndexToNode(index).value();
  LOG(INFO) << "Distance of the route: " << route_distance << "m";
  

}

}  


int main(int 
, char* 
[]) {
  operations_research::SimpleRoutingProgram();
  return EXIT_SUCCESS;
}



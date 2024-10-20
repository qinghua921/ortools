




























#include <cstdint>
#include <sstream>
#include <vector>

#include "ortools/constraint_solver/routing.h"
#include "ortools/constraint_solver/routing_enums.pb.h"
#include "ortools/constraint_solver/routing_index_manager.h"
#include "ortools/constraint_solver/routing_parameters.h"



namespace operations_research {


struct DataModel {
  const std::vector<std::vector<int64_t>> distance_matrix{
      {0, 548, 776, 696, 582, 274, 502, 194, 308, 194, 536, 502, 388, 354, 468,
       776, 662},
      {548, 0, 684, 308, 194, 502, 730, 354, 696, 742, 1084, 594, 480, 674,
       1016, 868, 1210},
      {776, 684, 0, 992, 878, 502, 274, 810, 468, 742, 400, 1278, 1164, 1130,
       788, 1552, 754},
      {696, 308, 992, 0, 114, 650, 878, 502, 844, 890, 1232, 514, 628, 822,
       1164, 560, 1358},
      {582, 194, 878, 114, 0, 536, 764, 388, 730, 776, 1118, 400, 514, 708,
       1050, 674, 1244},
      {274, 502, 502, 650, 536, 0, 228, 308, 194, 240, 582, 776, 662, 628, 514,
       1050, 708},
      {502, 730, 274, 878, 764, 228, 0, 536, 194, 468, 354, 1004, 890, 856, 514,
       1278, 480},
      {194, 354, 810, 502, 388, 308, 536, 0, 342, 388, 730, 468, 354, 320, 662,
       742, 856},
      {308, 696, 468, 844, 730, 194, 194, 342, 0, 274, 388, 810, 696, 662, 320,
       1084, 514},
      {194, 742, 742, 890, 776, 240, 468, 388, 274, 0, 342, 536, 422, 388, 274,
       810, 468},
      {536, 1084, 400, 1232, 1118, 582, 354, 730, 388, 342, 0, 878, 764, 730,
       388, 1152, 354},
      {502, 594, 1278, 514, 400, 776, 1004, 468, 810, 536, 878, 0, 114, 308,
       650, 274, 844},
      {388, 480, 1164, 628, 514, 662, 890, 354, 696, 422, 764, 114, 0, 194, 536,
       388, 730},
      {354, 674, 1130, 822, 708, 628, 856, 320, 662, 388, 730, 308, 194, 0, 342,
       422, 536},
      {468, 1016, 788, 1164, 1050, 514, 514, 662, 320, 274, 388, 650, 536, 342,
       0, 764, 194},
      {776, 868, 1552, 560, 674, 1050, 1278, 742, 1084, 810, 1152, 274, 388,
       422, 764, 0, 798},
      {662, 1210, 754, 1358, 1244, 708, 480, 856, 514, 468, 354, 844, 730, 536,
       194, 798, 0},
  };
  const int num_vehicles = 4;
  const RoutingIndexManager::NodeIndex depot{0};
};





void PrintSolution(
    const std::vector<std::vector<RoutingIndexManager::NodeIndex>>& routes) {
  

  DataModel data;
  int64_t total_distance = 0;
  for (int i = 0; i < routes.size(); ++i) {
    std::vector<RoutingIndexManager::NodeIndex> route = routes[i];
    int64_t route_distance{0};
    std::stringstream route_text;
    LOG(INFO) << "Route for Vehicle " << i << ":";
    route_text << route[0];
    for (int j = 1; j < route.size(); ++j) {
      route_text << " -> " << route[j];
      route_distance +=
          data.distance_matrix[route[j - 1].value()][route[j].value()];
    }
    LOG(INFO) << route_text.str();
    LOG(INFO) << "Distance of the route: " << route_distance << "m";
    total_distance += route_distance;
  }
  LOG(INFO) << "Total distance of all routes: " << total_distance << "m";
}



void Vrp() {
  

  

  DataModel data;
  


  

  

  RoutingIndexManager manager(data.distance_matrix.size(), data.num_vehicles,
                              data.depot);
  


  

  

  RoutingModel routing(manager);
  


  

  

  const int transit_callback_index = routing.RegisterTransitCallback(
      [&data, &manager](const int64_t from_index,
                        const int64_t to_index) -> int64_t {
        

        const int from_node = manager.IndexToNode(from_index).value();
        const int to_node = manager.IndexToNode(to_index).value();
        return data.distance_matrix[from_node][to_node];
      });
  


  

  

  routing.SetArcCostEvaluatorOfAllVehicles(transit_callback_index);
  


  

  

  RoutingSearchParameters searchParameters = DefaultRoutingSearchParameters();
  searchParameters.set_first_solution_strategy(
      FirstSolutionStrategy::PATH_CHEAPEST_ARC);
  


  

  

  const Assignment* solution = routing.SolveWithParameters(searchParameters);
  


  

  

  std::vector<std::vector<RoutingIndexManager::NodeIndex>> routes;
  for (const std::vector<int64_t>& route_indices :
       routing.GetRoutesFromAssignment(*solution)) {
    routes.push_back(manager.IndicesToNodes(route_indices));
  }
  


  

  PrintSolution(routes);
  

}
}  


int main(int 
, char* 
[]) {
  operations_research::Vrp();
  return EXIT_SUCCESS;
}



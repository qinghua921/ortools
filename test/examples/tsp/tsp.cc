




























#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <sstream>
#include <vector>

#include "ortools/base/init_google.h"
#include "ortools/constraint_solver/routing.h"
#include "ortools/constraint_solver/routing_enums.pb.h"
#include "ortools/constraint_solver/routing_index_manager.h"
#include "ortools/constraint_solver/routing_parameters.h"



namespace operations_research {


struct DataModel {
  const std::vector<std::vector<int>> locations{
      {4, 4}, {2, 0}, {8, 0}, {0, 1}, {1, 1}, {5, 2}, {7, 2}, {3, 3}, {6, 3},
      {5, 5}, {8, 5}, {1, 6}, {2, 6}, {3, 7}, {6, 7}, {0, 8}, {7, 8},
  };
  const int num_vehicles = 1;
  const RoutingIndexManager::NodeIndex depot{0};
  DataModel() {
    

    for (auto& it : const_cast<std::vector<std::vector<int>>&>(locations)) {
      it[0] *= 114;
      it[1] *= 80;
    }
  }
};







std::vector<std::vector<int64_t>> GenerateManhattanDistanceMatrix(
    const std::vector<std::vector<int>>& locations) {
  std::vector<std::vector<int64_t>> distances =
      std::vector<std::vector<int64_t>>(
          locations.size(), std::vector<int64_t>(locations.size(), int64_t{0}));
  for (int from_node = 0; from_node < locations.size(); from_node++) {
    for (int to_node = 0; to_node < locations.size(); to_node++) {
      if (from_node != to_node)
        distances[from_node][to_node] =
            int64_t{std::abs(locations[to_node][0] - locations[from_node][0]) +
                    std::abs(locations[to_node][1] - locations[from_node][1])};
    }
  }
  return distances;
}













void PrintSolution(const RoutingIndexManager& manager,
                   const RoutingModel& routing, const Assignment& solution) {
  LOG(INFO) << "Objective: " << solution.ObjectiveValue();
  

  int64_t index = routing.Start(0);
  LOG(INFO) << "Route for Vehicle 0:";
  int64_t distance{0};
  std::stringstream route;
  while (!routing.IsEnd(index)) {
    route << manager.IndexToNode(index).value() << " -> ";
    const int64_t previous_index = index;
    index = solution.Value(routing.NextVar(index));
    distance += routing.GetArcCostForVehicle(previous_index, index, int64_t{0});
  }
  LOG(INFO) << route.str() << manager.IndexToNode(index).value();
  LOG(INFO) << "Distance of the route: " << distance << "m";
  LOG(INFO) << "";
  LOG(INFO) << "Advanced usage:";
  LOG(INFO) << "Problem solved in " << routing.solver()->wall_time() << "ms";
}



void Tsp() {
  

  

  DataModel data;
  


  

  

  RoutingIndexManager manager(data.locations.size(), data.num_vehicles,
                              data.depot);
  


  

  

  RoutingModel routing(manager);
  


  

  

  const auto distance_matrix = GenerateManhattanDistanceMatrix(data.locations);
  const int transit_callback_index = routing.RegisterTransitCallback(
      [&distance_matrix, &manager](const int64_t from_index,
                                   const int64_t to_index) -> int64_t {
        

        const int from_node = manager.IndexToNode(from_index).value();
        const int to_node = manager.IndexToNode(to_index).value();
        return distance_matrix[from_node][to_node];
      });
  


  

  

  routing.SetArcCostEvaluatorOfAllVehicles(transit_callback_index);
  


  

  

  RoutingSearchParameters searchParameters = DefaultRoutingSearchParameters();
  searchParameters.set_first_solution_strategy(
      FirstSolutionStrategy::PATH_CHEAPEST_ARC);
  


  

  

  const Assignment* solution = routing.SolveWithParameters(searchParameters);
  


  

  

  PrintSolution(manager, routing, *solution);
  

}

}  


int main(int argc, char* argv[]) {
  InitGoogle(argv[0], &argc, &argv, true);
  operations_research::Tsp();
  return EXIT_SUCCESS;
}



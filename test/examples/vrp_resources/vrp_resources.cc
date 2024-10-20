




























#include <cstdint>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "ortools/constraint_solver/routing.h"
#include "ortools/constraint_solver/routing_enums.pb.h"
#include "ortools/constraint_solver/routing_index_manager.h"
#include "ortools/constraint_solver/routing_parameters.h"



namespace operations_research {


struct DataModel {
  const std::vector<std::vector<int64_t>> time_matrix{
      {0, 6, 9, 8, 7, 3, 6, 2, 3, 2, 6, 6, 4, 4, 5, 9, 7},
      {6, 0, 8, 3, 2, 6, 8, 4, 8, 8, 13, 7, 5, 8, 12, 10, 14},
      {9, 8, 0, 11, 10, 6, 3, 9, 5, 8, 4, 15, 14, 13, 9, 18, 9},
      {8, 3, 11, 0, 1, 7, 10, 6, 10, 10, 14, 6, 7, 9, 14, 6, 16},
      {7, 2, 10, 1, 0, 6, 9, 4, 8, 9, 13, 4, 6, 8, 12, 8, 14},
      {3, 6, 6, 7, 6, 0, 2, 3, 2, 2, 7, 9, 7, 7, 6, 12, 8},
      {6, 8, 3, 10, 9, 2, 0, 6, 2, 5, 4, 12, 10, 10, 6, 15, 5},
      {2, 4, 9, 6, 4, 3, 6, 0, 4, 4, 8, 5, 4, 3, 7, 8, 10},
      {3, 8, 5, 10, 8, 2, 2, 4, 0, 3, 4, 9, 8, 7, 3, 13, 6},
      {2, 8, 8, 10, 9, 2, 5, 4, 3, 0, 4, 6, 5, 4, 3, 9, 5},
      {6, 13, 4, 14, 13, 7, 4, 8, 4, 4, 0, 10, 9, 8, 4, 13, 4},
      {6, 7, 15, 6, 4, 9, 12, 5, 9, 6, 10, 0, 1, 3, 7, 3, 10},
      {4, 5, 14, 7, 6, 7, 10, 4, 8, 5, 9, 1, 0, 2, 6, 4, 8},
      {4, 8, 13, 9, 8, 7, 10, 3, 7, 4, 8, 3, 2, 0, 4, 5, 6},
      {5, 12, 9, 14, 12, 6, 6, 7, 3, 3, 4, 7, 6, 4, 0, 9, 2},
      {9, 10, 18, 6, 8, 12, 15, 8, 13, 9, 13, 3, 4, 5, 9, 0, 9},
      {7, 14, 9, 16, 14, 8, 5, 10, 6, 5, 4, 10, 8, 6, 2, 9, 0},
  };
  const std::vector<std::pair<int64_t, int64_t>> time_windows{
      {0, 5},    

      {7, 12},   

      {10, 15},  

      {5, 14},   

      {5, 13},   

      {0, 5},    

      {5, 10},   

      {0, 10},   

      {5, 10},   

      {0, 5},    

      {10, 16},  

      {10, 15},  

      {0, 5},    

      {5, 10},   

      {7, 12},   

      {10, 15},  

      {5, 15},   

  };
  const int num_vehicles = 4;
  

  const int vehicle_load_time = 5;
  const int vehicle_unload_time = 5;
  const int depot_capacity = 2;
  

  const RoutingIndexManager::NodeIndex depot{0};
};















void PrintSolution(const DataModel& data, const RoutingIndexManager& manager,
                   const RoutingModel& routing, const Assignment& solution) {
  const RoutingDimension& time_dimension = routing.GetDimensionOrDie("Time");
  int64_t total_time{0};
  for (int vehicle_id = 0; vehicle_id < data.num_vehicles; ++vehicle_id) {
    int64_t index = routing.Start(vehicle_id);
    LOG(INFO) << "Route for vehicle " << vehicle_id << ":";
    std::ostringstream route;
    while (!routing.IsEnd(index)) {
      auto time_var = time_dimension.CumulVar(index);
      route << manager.IndexToNode(index).value() << " Time("
            << solution.Min(time_var) << ", " << solution.Max(time_var)
            << ") -> ";
      index = solution.Value(routing.NextVar(index));
    }
    auto time_var = time_dimension.CumulVar(index);
    LOG(INFO) << route.str() << manager.IndexToNode(index).value() << " Time("
              << solution.Min(time_var) << ", " << solution.Max(time_var)
              << ")";
    LOG(INFO) << "Time of the route: " << solution.Min(time_var) << "min";
    total_time += solution.Min(time_var);
  }
  LOG(INFO) << "Total time of all routes: " << total_time << "min";
  LOG(INFO) << "";
  LOG(INFO) << "Advanced usage:";
  LOG(INFO) << "Problem solved in " << routing.solver()->wall_time() << "ms";
}



void VrpTimeWindows() {
  

  

  DataModel data;
  


  

  

  RoutingIndexManager manager(data.time_matrix.size(), data.num_vehicles,
                              data.depot);
  


  

  

  RoutingModel routing(manager);
  


  

  

  const int transit_callback_index = routing.RegisterTransitCallback(
      [&data, &manager](const int64_t from_index,
                        const int64_t to_index) -> int64_t {
        

        const int from_node = manager.IndexToNode(from_index).value();
        const int to_node = manager.IndexToNode(to_index).value();
        return data.time_matrix[from_node][to_node];
      });
  


  

  

  routing.SetArcCostEvaluatorOfAllVehicles(transit_callback_index);
  


  

  

  const std::string time = "Time";
  routing.AddDimension(transit_callback_index,  

                       int64_t{30},             

                       int64_t{30},             

                       false,  

                       time);
  const RoutingDimension& time_dimension = routing.GetDimensionOrDie(time);
  

  for (int i = 1; i < data.time_windows.size(); ++i) {
    const int64_t index =
        manager.NodeToIndex(RoutingIndexManager::NodeIndex(i));
    time_dimension.CumulVar(index)->SetRange(data.time_windows[i].first,
                                             data.time_windows[i].second);
  }
  

  for (int i = 0; i < data.num_vehicles; ++i) {
    const int64_t index = routing.Start(i);
    time_dimension.CumulVar(index)->SetRange(data.time_windows[0].first,
                                             data.time_windows[0].second);
  }
  


  

  

  Solver* solver = routing.solver();
  std::vector<IntervalVar*> intervals;
  for (int i = 0; i < data.num_vehicles; ++i) {
    

    intervals.push_back(solver->MakeFixedDurationIntervalVar(
        time_dimension.CumulVar(routing.Start(i)), data.vehicle_load_time,
        "depot_interval"));
    

    intervals.push_back(solver->MakeFixedDurationIntervalVar(
        time_dimension.CumulVar(routing.End(i)), data.vehicle_unload_time,
        "depot_interval"));
  }
  


  

  std::vector<int64_t> depot_usage(intervals.size(), 1);
  solver->AddConstraint(solver->MakeCumulative(intervals, depot_usage,
                                               data.depot_capacity, "depot"));
  


  

  

  for (int i = 0; i < data.num_vehicles; ++i) {
    routing.AddVariableMinimizedByFinalizer(
        time_dimension.CumulVar(routing.Start(i)));
    routing.AddVariableMinimizedByFinalizer(
        time_dimension.CumulVar(routing.End(i)));
  }
  


  

  

  RoutingSearchParameters searchParameters = DefaultRoutingSearchParameters();
  searchParameters.set_first_solution_strategy(
      FirstSolutionStrategy::PATH_CHEAPEST_ARC);
  


  

  

  const Assignment* solution = routing.SolveWithParameters(searchParameters);
  


  

  

  PrintSolution(data, manager, routing, *solution);
  

}
}  


int main(int 
, char* 
[]) {
  operations_research::VrpTimeWindows();
  return EXIT_SUCCESS;
}



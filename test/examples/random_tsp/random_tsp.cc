

















































#include <cstdint>
#include <memory>
#include <string>

#include "absl/flags/parse.h"
#include "absl/random/random.h"
#include "absl/strings/str_cat.h"
#include "google/protobuf/text_format.h"
#include "ortools/base/logging.h"
#include "ortools/constraint_solver/routing.h"
#include "ortools/constraint_solver/routing_index_manager.h"
#include "ortools/constraint_solver/routing_parameters.h"
#include "ortools/constraint_solver/routing_parameters.pb.h"
#include "ortools/util/random_engine.h"

ABSL_FLAG(int, tsp_size, 10, "Size of Traveling Salesman Problem instance.");
ABSL_FLAG(bool, tsp_use_random_matrix, true, "Use random cost matrix.");
ABSL_FLAG(int, tsp_random_forbidden_connections, 0,
          "Number of random forbidden connections.");
ABSL_FLAG(bool, tsp_use_deterministic_random_seed, false,
          "Use deterministic random seeds.");
ABSL_FLAG(std::string, routing_search_parameters,
          "local_search_operators {"
          "  use_path_lns:BOOL_TRUE"
          "  use_inactive_lns:BOOL_TRUE"
          "}",
          "Text proto RoutingSearchParameters (possibly partial) that will "
          "override the DefaultRoutingSearchParameters()");

namespace operations_research {



int32_t GetSeed() {
  if (absl::GetFlag(FLAGS_tsp_use_deterministic_random_seed)) {
    return 0;
  } else {
    return std::random_device()();
  }
}






int64_t MyDistance(RoutingIndexManager::NodeIndex from,
                   RoutingIndexManager::NodeIndex to) {
  

  return (from + to).value();  

}



class RandomMatrix {
 public:
  explicit RandomMatrix(int size) : size_(size) {}
  void Initialize() {
    matrix_ = std::make_unique<int64_t[]>(size_ * size_);
    const int64_t kDistanceMax = 100;
    random_engine_t randomizer(GetSeed());
    for (RoutingIndexManager::NodeIndex from(0); from < size_; ++from) {
      for (RoutingIndexManager::NodeIndex to(0); to < size_; ++to) {
        if (to != from) {
          matrix_[MatrixIndex(from, to)] =
              absl::Uniform(randomizer, 0, kDistanceMax);
        } else {
          matrix_[MatrixIndex(from, to)] = 0LL;
        }
      }
    }
  }
  int64_t Distance(RoutingIndexManager::NodeIndex from,
                   RoutingIndexManager::NodeIndex to) const {
    return matrix_[MatrixIndex(from, to)];
  }

 private:
  int64_t MatrixIndex(RoutingIndexManager::NodeIndex from,
                      RoutingIndexManager::NodeIndex to) const {
    return (from * size_ + to).value();
  }
  std::unique_ptr<int64_t[]> matrix_;
  const int size_;
};

void Tsp() {
  if (absl::GetFlag(FLAGS_tsp_size) > 0) {
    

    

    

    

    

    RoutingIndexManager manager(absl::GetFlag(FLAGS_tsp_size), 1,
                                RoutingIndexManager::NodeIndex(0));
    RoutingModel routing(manager);
    RoutingSearchParameters parameters = DefaultRoutingSearchParameters();
    CHECK(google::protobuf::TextFormat::MergeFromString(
        absl::GetFlag(FLAGS_routing_search_parameters), &parameters));

    

    

    

    

    RandomMatrix matrix(absl::GetFlag(FLAGS_tsp_size));
    if (absl::GetFlag(FLAGS_tsp_use_random_matrix)) {
      matrix.Initialize();
      const int vehicle_cost = routing.RegisterTransitCallback(
          [&matrix, &manager](int64_t i, int64_t j) {
            return matrix.Distance(manager.IndexToNode(i),
                                   manager.IndexToNode(j));
          });
      routing.SetArcCostEvaluatorOfAllVehicles(vehicle_cost);
    } else {
      const int vehicle_cost =
          routing.RegisterTransitCallback([&manager](int64_t i, int64_t j) {
            return MyDistance(manager.IndexToNode(i), manager.IndexToNode(j));
          });
      routing.SetArcCostEvaluatorOfAllVehicles(vehicle_cost);
    }
    

    random_engine_t randomizer(GetSeed());
    int64_t forbidden_connections = 0;
    while (forbidden_connections <
           absl::GetFlag(FLAGS_tsp_random_forbidden_connections)) {
      const int64_t from =
          absl::Uniform(randomizer, 0, absl::GetFlag(FLAGS_tsp_size) - 1);
      const int64_t to =
          absl::Uniform(randomizer, 0, absl::GetFlag(FLAGS_tsp_size) - 1) + 1;
      if (routing.NextVar(from)->Contains(to)) {
        LOG(INFO) << "Forbidding connection " << from << " -> " << to;
        routing.NextVar(from)->RemoveValue(to);
        ++forbidden_connections;
      }
    }
    

    const Assignment* solution = routing.SolveWithParameters(parameters);
    if (solution != nullptr) {
      

      LOG(INFO) << "Cost " << solution->ObjectiveValue();
      

      

      const int route_number = 0;
      std::string route;
      for (int64_t node = routing.Start(route_number); !routing.IsEnd(node);
           node = solution->Value(routing.NextVar(node))) {
        absl::StrAppend(&route, manager.IndexToNode(node).value(), " (", node,
                        ") -> ");
      }
      const int64_t end = routing.End(route_number);
      absl::StrAppend(&route, manager.IndexToNode(end).value(), " (", end, ")");
      LOG(INFO) << route;
    } else {
      LOG(INFO) << "No solution found.";
    }
  } else {
    LOG(INFO) << "Specify an instance size greater than 0.";
  }
}
}  


int main(int argc, char** argv) {
  absl::ParseCommandLine(argc, argv);
  operations_research::Tsp();
  return EXIT_SUCCESS;
}

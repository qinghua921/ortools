




























#include "ortools/graph/assignment.h"

#include <cstdint>
#include <numeric>
#include <string>
#include <vector>



namespace operations_research {


void AssignmentLinearSumAssignment() {
  

  SimpleLinearSumAssignment assignment;
  


  

  const int num_workers = 4;
  std::vector<int> all_workers(num_workers);
  std::iota(all_workers.begin(), all_workers.end(), 0);

  const int num_tasks = 4;
  std::vector<int> all_tasks(num_tasks);
  std::iota(all_tasks.begin(), all_tasks.end(), 0);

  const std::vector<std::vector<int>> costs = {{
      {{90, 76, 75, 70}},    

      {{35, 85, 55, 65}},    

      {{125, 95, 90, 105}},  

      {{45, 110, 95, 115}},  

  }};
  


  

  for (int w : all_workers) {
    for (int t : all_tasks) {
      if (costs[w][t]) {
        assignment.AddArcWithCost(w, t, costs[w][t]);
      }
    }
  }
  


  

  SimpleLinearSumAssignment::Status status = assignment.Solve();
  


  

  if (status == SimpleLinearSumAssignment::OPTIMAL) {
    LOG(INFO) << "Total cost: " << assignment.OptimalCost();
    for (int worker : all_workers) {
      LOG(INFO) << "Worker " << std::to_string(worker) << " assigned to task "
                << std::to_string(assignment.RightMate(worker)) << ". Cost: "
                << std::to_string(assignment.AssignmentCost(worker)) << ".";
    }
  } else {
    LOG(INFO) << "Solving the linear assignment problem failed.";
  }
  

}

}  


int main() {
  operations_research::AssignmentLinearSumAssignment();
  return EXIT_SUCCESS;
}



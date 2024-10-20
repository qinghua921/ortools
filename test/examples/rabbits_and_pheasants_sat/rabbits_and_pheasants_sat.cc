
























#include <stdlib.h>

#include "ortools/base/logging.h"
#include "ortools/sat/cp_model.h"
#include "ortools/sat/cp_model.pb.h"
#include "ortools/sat/cp_model_solver.h"
#include "ortools/util/sorted_interval_list.h"

namespace operations_research {
namespace sat {

void RabbitsAndPheasantsSat() {
  CpModelBuilder cp_model;

  const Domain all_animals(0, 20);
  const IntVar rabbits = cp_model.NewIntVar(all_animals).WithName("rabbits");
  const IntVar pheasants =
      cp_model.NewIntVar(all_animals).WithName("pheasants");

  cp_model.AddEquality(rabbits + pheasants, 20);
  cp_model.AddEquality(4 * rabbits + 2 * pheasants, 56);

  const CpSolverResponse response = Solve(cp_model.Build());

  if (response.status() == CpSolverStatus::OPTIMAL) {
    

    LOG(INFO) << SolutionIntegerValue(response, rabbits) << " rabbits, and "
              << SolutionIntegerValue(response, pheasants) << " pheasants";
  }
}

}  

}  


int main() {
  operations_research::sat::RabbitsAndPheasantsSat();

  return EXIT_SUCCESS;
}

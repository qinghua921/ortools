


























#include <stdlib.h>

#include "ortools/base/logging.h"
#include "ortools/sat/cp_model.h"
#include "ortools/sat/cp_model.pb.h"
#include "ortools/sat/cp_model_solver.h"
#include "ortools/util/sorted_interval_list.h"

namespace operations_research {
namespace sat {

void CloneModelSampleSat() {
  

  CpModelBuilder cp_model;
  


  

  const Domain domain(0, 2);
  const IntVar x = cp_model.NewIntVar(domain).WithName("x");
  const IntVar y = cp_model.NewIntVar(domain).WithName("y");
  const IntVar z = cp_model.NewIntVar(domain).WithName("z");
  


  

  cp_model.AddNotEqual(x, y);
  


  

  cp_model.Maximize(x + 2 * y + 3 * z);
  


  const CpSolverResponse initial_response = Solve(cp_model.Build());
  LOG(INFO) << "Optimal value of the original model: "
            << initial_response.objective_value();

  

  CpModelBuilder copy = cp_model.Clone();

  

  IntVar copy_of_x = copy.GetIntVarFromProtoIndex(x.index());
  IntVar copy_of_y = copy.GetIntVarFromProtoIndex(y.index());

  copy.AddLessOrEqual(copy_of_x + copy_of_y, 1);
  


  const CpSolverResponse modified_response = Solve(copy.Build());
  LOG(INFO) << "Optimal value of the modified model: "
            << modified_response.objective_value();
}

}  

}  


int main() {
  operations_research::sat::CloneModelSampleSat();

  return EXIT_SUCCESS;
}




























#include <stdlib.h>

#include "ortools/base/logging.h"
#include "ortools/sat/cp_model.h"
#include "ortools/util/sorted_interval_list.h"

namespace operations_research {
namespace sat {

void OptionalIntervalSampleSat() {
  CpModelBuilder cp_model;
  const int kHorizon = 100;
  const Domain horizon(0, kHorizon);

  

  

  const IntVar x = cp_model.NewIntVar(horizon).WithName("x");
  const IntVar y = cp_model.NewIntVar({2, 4}).WithName("y");
  const IntVar z = cp_model.NewIntVar(horizon).WithName("z");
  const BoolVar presence_var = cp_model.NewBoolVar().WithName("presence");

  const IntervalVar interval_var =
      cp_model.NewOptionalIntervalVar(x, y, z + 2, presence_var)
          .WithName("interval");
  LOG(INFO) << "start = " << interval_var.StartExpr()
            << ", size = " << interval_var.SizeExpr()
            << ", end = " << interval_var.EndExpr()
            << ", presence = " << interval_var.PresenceBoolVar()
            << ", interval_var = " << interval_var;

  

  

  const IntervalVar fixed_size_interval_var =
      cp_model.NewOptionalFixedSizeIntervalVar(x, 10, presence_var)
          .WithName("fixed_size_interval_var");
  LOG(INFO) << "start = " << fixed_size_interval_var.StartExpr()
            << ", size = " << fixed_size_interval_var.SizeExpr()
            << ", end = " << fixed_size_interval_var.EndExpr()
            << ", presence = " << fixed_size_interval_var.PresenceBoolVar()
            << ", interval_var = " << fixed_size_interval_var;
}

}  

}  


int main() {
  operations_research::sat::OptionalIntervalSampleSat();

  return EXIT_SUCCESS;
}

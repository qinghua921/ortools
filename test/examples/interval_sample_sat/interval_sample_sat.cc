
























#include <stdlib.h>

#include "ortools/base/logging.h"
#include "ortools/sat/cp_model.h"
#include "ortools/util/sorted_interval_list.h"

namespace operations_research {
namespace sat {

void IntervalSampleSat() {
  CpModelBuilder cp_model;
  const int kHorizon = 100;
  const Domain horizon(0, kHorizon);

  

  const IntVar x = cp_model.NewIntVar(horizon).WithName("x");
  const IntVar y = cp_model.NewIntVar({2, 4}).WithName("y");
  const IntVar z = cp_model.NewIntVar(horizon).WithName("z");

  const IntervalVar interval_var =
      cp_model.NewIntervalVar(x, y, z + 2).WithName("interval");
  LOG(INFO) << "start = " << interval_var.StartExpr()
            << ", size = " << interval_var.SizeExpr()
            << ", end = " << interval_var.EndExpr()
            << ", interval_var = " << interval_var;

  

  

  const IntervalVar fixed_size_interval_var =
      cp_model.NewFixedSizeIntervalVar(x, 10).WithName(
          "fixed_size_interval_var");
  LOG(INFO) << "start = " << fixed_size_interval_var.StartExpr()
            << ", size = " << fixed_size_interval_var.SizeExpr()
            << ", end = " << fixed_size_interval_var.EndExpr()
            << ", fixed_size_interval_var = " << fixed_size_interval_var;

  

  const IntervalVar fixed_interval =
      cp_model.NewFixedSizeIntervalVar(5, 10).WithName("fixed_interval");
  LOG(INFO) << "start = " << fixed_interval.StartExpr()
            << ", size = " << fixed_interval.SizeExpr()
            << ", end = " << fixed_interval.EndExpr()
            << ", fixed_interval = " << fixed_interval;
}

}  

}  


int main() {
  operations_research::sat::IntervalSampleSat();

  return EXIT_SUCCESS;
}

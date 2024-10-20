
























#include <stdlib.h>

#include "absl/types/span.h"
#include "ortools/sat/cp_model.h"

namespace operations_research {
namespace sat {

void ReifiedSampleSat() {
  CpModelBuilder cp_model;

  const BoolVar x = cp_model.NewBoolVar();
  const BoolVar y = cp_model.NewBoolVar();
  const BoolVar b = cp_model.NewBoolVar();

  

  cp_model.AddBoolAnd({x, ~y}).OnlyEnforceIf(b);

  

  cp_model.AddImplication(b, x);
  cp_model.AddImplication(b, ~y);

  

  cp_model.AddBoolOr({~b, x});
  cp_model.AddBoolOr({~b, ~y});
}

}  

}  


int main() {
  operations_research::sat::ReifiedSampleSat();

  return EXIT_SUCCESS;
}

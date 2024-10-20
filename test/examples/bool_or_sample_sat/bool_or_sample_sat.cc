
























#include <stdlib.h>

#include "absl/types/span.h"
#include "ortools/sat/cp_model.h"

namespace operations_research {
namespace sat {

void BoolOrSampleSat() {
  CpModelBuilder cp_model;

  const BoolVar x = cp_model.NewBoolVar();
  const BoolVar y = cp_model.NewBoolVar();
  cp_model.AddBoolOr({x, ~y});
  

  cp_model.AddBoolOr({x, ~y});
}

}  

}  


int main() {
  operations_research::sat::BoolOrSampleSat();

  return EXIT_SUCCESS;
}

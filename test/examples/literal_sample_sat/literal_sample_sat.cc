
























#include <stdlib.h>

#include "ortools/base/logging.h"
#include "ortools/sat/cp_model.h"

namespace operations_research {
namespace sat {

void LiteralSampleSat() {
  CpModelBuilder cp_model;

  const BoolVar x = cp_model.NewBoolVar().WithName("x");
  const BoolVar not_x = ~x;
  LOG(INFO) << "x = " << x << ", not(x) = " << not_x;
}

}  

}  


int main() {
  operations_research::sat::LiteralSampleSat();

  return EXIT_SUCCESS;
}

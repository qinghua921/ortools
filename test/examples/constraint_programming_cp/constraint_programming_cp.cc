



























#include <vector>

#include "ortools/base/init_google.h"
#include "ortools/base/logging.h"
#include "ortools/constraint_solver/constraint_solver.h"

namespace operations_research {
void RunConstraintProgrammingExample() {
  

  Solver solver("ConstraintProgrammingExample");
  const int64_t numVals = 3;

  

  IntVar* const x = solver.MakeIntVar(0, numVals - 1, "x");
  IntVar* const y = solver.MakeIntVar(0, numVals - 1, "y");
  IntVar* const z = solver.MakeIntVar(0, numVals - 1, "z");

  

  std::vector<IntVar*> xyvars = {x, y};
  solver.AddConstraint(solver.MakeAllDifferent(xyvars));

  LOG(INFO) << "Number of constraints: " << solver.constraints();

  

  std::vector<IntVar*> allvars = {x, y, z};
  DecisionBuilder* const db = solver.MakePhase(
      allvars, Solver::CHOOSE_FIRST_UNBOUND, Solver::ASSIGN_MIN_VALUE);

  solver.NewSearch(db);
  while (solver.NextSolution()) {
    LOG(INFO) << "Solution" << ": x = " << x->Value() << "; y = " << y->Value()
              << "; z = " << z->Value();
  }
  solver.EndSearch();
  LOG(INFO) << "Number of solutions: " << solver.solutions();
  LOG(INFO) << "";
  LOG(INFO) << "Advanced usage:";
  LOG(INFO) << "Problem solved in " << solver.wall_time() << "ms";
  LOG(INFO) << "Memory usage: " << Solver::MemoryUsage() << " bytes";
}
}  


int main(int argc, char** argv) {
  absl::SetFlag(&FLAGS_stderrthreshold, 0);
  InitGoogle(argv[0], &argc, &argv, true);
  operations_research::RunConstraintProgrammingExample();
  return EXIT_SUCCESS;
}

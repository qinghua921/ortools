




























#include "absl/flags/flag.h"
#include "absl/log/flags.h"
#include "ortools/base/init_google.h"
#include "ortools/base/logging.h"
#include "ortools/constraint_solver/constraint_solver.h"

namespace operations_research {
void RunConstraintProgrammingExample() {
  

  Solver solver("RabbitsPheasantsExample");

  

  IntVar* const rabbits = solver.MakeIntVar(0, 20, "rabbits");
  IntVar* const pheasants = solver.MakeIntVar(0, 20, "pheasants");

  

  IntExpr* const heads = solver.MakeSum(rabbits, pheasants);
  Constraint* const c0 = solver.MakeEquality(heads, 20);
  solver.AddConstraint(c0);

  IntExpr* const legs = solver.MakeSum(solver.MakeProd(rabbits, 4),
                                       solver.MakeProd(pheasants, 2));
  Constraint* const c1 = solver.MakeEquality(legs, 56);
  solver.AddConstraint(c1);

  DecisionBuilder* const db =
      solver.MakePhase(rabbits, pheasants, Solver::CHOOSE_FIRST_UNBOUND,
                       Solver::ASSIGN_MIN_VALUE);

  int count = 0;
  solver.NewSearch(db);
  while (solver.NextSolution()) {
    count++;
    LOG(INFO) << "Solution " << count << ":";
    LOG(INFO) << "rabbits = " << rabbits->Value();
    LOG(INFO) << "pheasants = " << rabbits->Value();
  }
  solver.EndSearch();
  LOG(INFO) << "Number of solutions: " << count;
  LOG(INFO) << "";
  LOG(INFO) << "Advanced usage:";
  LOG(INFO) << "Problem solved in " << solver.wall_time() << " milliseconds";
}
}  


int main(int argc, char** argv) {
  InitGoogle(argv[0], &argc, &argv, true);
  absl::SetFlag(&FLAGS_stderrthreshold, 0);
  operations_research::RunConstraintProgrammingExample();
  return EXIT_SUCCESS;
}

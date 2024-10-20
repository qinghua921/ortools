



























#include <string>
#include <vector>

#include "absl/strings/match.h"
#include "absl/strings/string_view.h"
#include "ortools/base/init_google.h"
#include "ortools/base/logging.h"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research {
void RunIntegerProgrammingExample(absl::string_view solver_id) {
  LOG(INFO) << "---- Integer programming example with " << solver_id << " ----";

  MPSolver::OptimizationProblemType problem_type;
  if (!MPSolver::ParseSolverType(solver_id, &problem_type)) {
    LOG(INFO) << "Solver id " << solver_id << " not recognized";
    return;
  }

  if (!MPSolver::SupportsProblemType(problem_type)) {
    LOG(INFO) << "Supports for solver " << solver_id << " not linked in.";
    return;
  }

  MPSolver solver("IntegerProgrammingExample", problem_type);

  const double infinity = solver.infinity();
  

  MPVariable* const x = solver.MakeIntVar(0.0, infinity, "x");
  MPVariable* const y = solver.MakeIntVar(0.0, infinity, "y");

  

  MPObjective* const objective = solver.MutableObjective();
  objective->SetCoefficient(x, 1);
  objective->SetCoefficient(y, 10);
  objective->SetMaximization();

  

  MPConstraint* const c0 = solver.MakeRowConstraint(-infinity, 17.5);
  c0->SetCoefficient(x, 1);
  c0->SetCoefficient(y, 7);

  

  MPConstraint* const c1 = solver.MakeRowConstraint(-infinity, 3.5);
  c1->SetCoefficient(x, 1);
  c1->SetCoefficient(y, 0);

  LOG(INFO) << "Number of variables = " << solver.NumVariables();
  LOG(INFO) << "Number of constraints = " << solver.NumConstraints();

  const MPSolver::ResultStatus result_status = solver.Solve();
  

  if (result_status != MPSolver::OPTIMAL) {
    LOG(FATAL) << "The problem does not have an optimal solution!";
  }
  LOG(INFO) << "Solution:";
  LOG(INFO) << "x = " << x->solution_value();
  LOG(INFO) << "y = " << y->solution_value();
  LOG(INFO) << "Optimal objective value = " << objective->Value();
  LOG(INFO) << "";
  LOG(INFO) << "Advanced usage:";
  LOG(INFO) << "Problem solved in " << solver.wall_time() << " milliseconds";
  LOG(INFO) << "Problem solved in " << solver.iterations() << " iterations";
  LOG(INFO) << "Problem solved in " << solver.nodes()
            << " branch-and-bound nodes";
}

void RunAllExamples() {
  RunIntegerProgrammingExample("CBC");
  RunIntegerProgrammingExample("SAT");
  RunIntegerProgrammingExample("SCIP");
  RunIntegerProgrammingExample("GUROBI");
  RunIntegerProgrammingExample("GLPK");
  RunIntegerProgrammingExample("CPLEX");
  RunIntegerProgrammingExample("XPRESS");
}
}  


int main(int argc, char** argv) {
  absl::SetFlag(&FLAGS_stderrthreshold, 0);
  InitGoogle(argv[0], &argc, &argv, true);
  operations_research::RunAllExamples();
  return EXIT_SUCCESS;
}

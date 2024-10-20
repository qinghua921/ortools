



























#include <cstdlib>
#include <string>
#include <vector>

#include "absl/flags/flag.h"
#include "absl/strings/match.h"
#include "absl/strings/string_view.h"
#include "ortools/base/commandlineflags.h"
#include "ortools/base/init_google.h"
#include "ortools/base/logging.h"
#include "ortools/linear_solver/linear_solver.h"
#include "ortools/linear_solver/linear_solver.pb.h"

namespace operations_research {
void RunLinearProgrammingExample(absl::string_view solver_id) {
  LOG(INFO) << "---- Linear programming example with " << solver_id << " ----";
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
  

  MPVariable* const x1 = solver.MakeNumVar(0.0, infinity, "x1");
  MPVariable* const x2 = solver.MakeNumVar(0.0, infinity, "x2");
  MPVariable* const x3 = solver.MakeNumVar(0.0, infinity, "x3");

  

  MPObjective* const objective = solver.MutableObjective();
  objective->SetCoefficient(x1, 10);
  objective->SetCoefficient(x2, 6);
  objective->SetCoefficient(x3, 4);
  objective->SetMaximization();

  

  MPConstraint* const c0 = solver.MakeRowConstraint(-infinity, 100.0);
  c0->SetCoefficient(x1, 1);
  c0->SetCoefficient(x2, 1);
  c0->SetCoefficient(x3, 1);

  

  MPConstraint* const c1 = solver.MakeRowConstraint(-infinity, 600.0);
  c1->SetCoefficient(x1, 10);
  c1->SetCoefficient(x2, 4);
  c1->SetCoefficient(x3, 5);

  

  MPConstraint* const c2 = solver.MakeRowConstraint(-infinity, 300.0);
  c2->SetCoefficient(x1, 2);
  c2->SetCoefficient(x2, 2);
  c2->SetCoefficient(x3, 6);

  


  LOG(INFO) << "Number of variables = " << solver.NumVariables();
  LOG(INFO) << "Number of constraints = " << solver.NumConstraints();

  const MPSolver::ResultStatus result_status = solver.Solve();

  

  if (result_status != MPSolver::OPTIMAL) {
    LOG(FATAL) << "The problem does not have an optimal solution!";
  }

  LOG(INFO) << "Problem solved in " << solver.wall_time() << " milliseconds";

  

  LOG(INFO) << "Optimal objective value = " << objective->Value();

  

  LOG(INFO) << "x1 = " << x1->solution_value();
  LOG(INFO) << "x2 = " << x2->solution_value();
  LOG(INFO) << "x3 = " << x3->solution_value();

  LOG(INFO) << "Advanced usage:";
  LOG(INFO) << "Problem solved in " << solver.iterations() << " iterations";
  LOG(INFO) << "x1: reduced cost = " << x1->reduced_cost();
  LOG(INFO) << "x2: reduced cost = " << x2->reduced_cost();
  LOG(INFO) << "x3: reduced cost = " << x3->reduced_cost();
  const std::vector<double> activities = solver.ComputeConstraintActivities();
  LOG(INFO) << "c0: dual value = " << c0->dual_value()
            << " activity = " << activities[c0->index()];
  LOG(INFO) << "c1: dual value = " << c1->dual_value()
            << " activity = " << activities[c1->index()];
  LOG(INFO) << "c2: dual value = " << c2->dual_value()
            << " activity = " << activities[c2->index()];
}

void RunAllExamples() {
  RunLinearProgrammingExample("GLOP");
  RunLinearProgrammingExample("CLP");
  RunLinearProgrammingExample("GUROBI_LP");
  RunLinearProgrammingExample("CPLEX_LP");
  RunLinearProgrammingExample("GLPK_LP");
  RunLinearProgrammingExample("XPRESS_LP");
  RunLinearProgrammingExample("PDLP");
}
}  


int main(int argc, char** argv) {
  absl::SetFlag(&FLAGS_stderrthreshold, 0);
  InitGoogle(argv[0], &argc, &argv, true);
  operations_research::RunAllExamples();
  return EXIT_SUCCESS;
}

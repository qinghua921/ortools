



























#include <cstdlib>

#include "ortools/base/commandlineflags.h"
#include "ortools/base/init_google.h"
#include "ortools/base/logging.h"
#include "ortools/linear_solver/linear_solver.h"

using namespace operations_research;



void useXpressSolver(bool solveAsMip, bool useFactory) {
  std::unique_ptr<MPSolver> solver = nullptr;
  if (useFactory) {
    

    std::string xpressName = (solveAsMip ? "XPRESS" : "XPRESS_LP");
    solver.reset(MPSolver::CreateSolver(xpressName));
  } else {
    MPSolver::OptimizationProblemType problemType = (solveAsMip ?
                                            MPSolver::XPRESS_MIXED_INTEGER_PROGRAMMING
                                            : MPSolver::XPRESS_LINEAR_PROGRAMMING);
    

    if (MPSolver::SupportsProblemType(problemType)) {
        solver.reset(new MPSolver("IntegerProgrammingExample", problemType));
    }
  }
  if (solver == nullptr) {
       LOG(WARNING) << "Xpress solver is not available";
       return;
  }
  

  

  const double infinity = MPSolver::infinity();
  const MPVariable* x1 = solver->MakeIntVar(0, 5, "x1");
  const MPVariable* x2 = solver->MakeNumVar(0.0, infinity, "x2");

  MPObjective* const objective = solver->MutableObjective();
  objective->SetCoefficient(x1, -100);
  objective->SetCoefficient(x2, 10);
  objective->SetMaximization();

  MPConstraint* const c0 = solver->MakeRowConstraint(-infinity, 0.0);
  c0->SetCoefficient(x1, -20.0);
  c0->SetCoefficient(x2, 1);

  MPConstraint* const c1 = solver->MakeRowConstraint(-infinity, 350.0);
  c1->SetCoefficient(x1, 30.0);
  c1->SetCoefficient(x2, 3.5);


  const MPSolver::ResultStatus result_status = solver->Solve();

  

  if (result_status != MPSolver::OPTIMAL) {
    LOG(FATAL) << "Solver returned with non-optimal status.";
  } else {
    LOG(WARNING) << "Optimal solution found: obj=" << objective->Value();
  }
}
#define ABSL_MIN_LOG_LEVEL INFO;
int main(int argc, char** argv) {
  absl::SetFlag(&FLAGS_stderrthreshold, 0);
  InitGoogle(argv[0], &argc, &argv, true);
  std::cout << "start\n";
  LOG(WARNING) << "start";
  for (bool solveAsMip: {true, false}) {
    for (bool useFactory: {true, false}) {
        useXpressSolver(solveAsMip, useFactory);
    }
  }
  return EXIT_SUCCESS;
}

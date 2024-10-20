
























#include "absl/flags/flag.h"
#include "absl/log/check.h"
#include "absl/status/status.h"
#include "absl/strings/str_format.h"
#include "ortools/base/commandlineflags.h"
#include "ortools/base/init_google.h"
#include "ortools/base/logging.h"
#include "ortools/linear_solver/linear_solver.h"
#include "ortools/linear_solver/samples/network_design_ilph.h"
#include "ortools/routing/parsers/capacity_planning.pb.h"
#include "ortools/routing/parsers/dow_parser.h"

ABSL_FLAG(std::string, input, "", "File path of the problem.");

using operations_research::MPSolver;

int main(int argc, char* argv[]) {
  InitGoogle(argv[0], &argc, &argv, true);
  operations_research::CapacityPlanningInstance request;
  operations_research::CapacityPlanningProblem problem;
  ::absl::Status status =
      operations_research::ReadFile(absl::GetFlag(FLAGS_input), &request);
  CHECK_OK(status);
  LOG(INFO) << "File was read.";
  status = operations_research::Convert(request, &problem);
  LOG(INFO) << "Proto was transformed into graph problem.";
  CHECK_OK(status);
  operations_research::CapacityPlanningILPH ilph;
  ilph.Build(problem);
  LOG(INFO) << "ILPH model was built";
  switch (ilph.Solve()) {
    case MPSolver::OPTIMAL:
      absl::PrintF("Model solved to optimality.");
      return 0;
    case MPSolver::FEASIBLE:
      absl::PrintF("Model was solved, but is not optimal.");
      return 0;
    case MPSolver::INFEASIBLE:
      absl::PrintF("Model is infeasible.");
      return 1;
    case MPSolver::UNBOUNDED:
      absl::PrintF("Model is unbounded.");
      return 1;
    case MPSolver::ABNORMAL:
      absl::PrintF("Abnormal computation.");
      return 1;
    case MPSolver::MODEL_INVALID:
      absl::PrintF("Invalid model.");
      return 1;
    case MPSolver::NOT_SOLVED:
      absl::PrintF("Not solved.");
      return 1;
      

      

  }
  return 0;  

}

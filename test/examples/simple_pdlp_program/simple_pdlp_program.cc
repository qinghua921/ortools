




































#include <cstdint>
#include <iostream>
#include <limits>
#include <optional>
#include <vector>

#include "Eigen/Core"
#include "Eigen/SparseCore"
#include "ortools/base/init_google.h"
#include "ortools/pdlp/iteration_stats.h"
#include "ortools/pdlp/primal_dual_hybrid_gradient.h"
#include "ortools/pdlp/quadratic_program.h"
#include "ortools/pdlp/solve_log.pb.h"
#include "ortools/pdlp/solvers.pb.h"

namespace pdlp = ::operations_research::pdlp;

constexpr double kInfinity = std::numeric_limits<double>::infinity();





















pdlp::QuadraticProgram SimpleLp() {
  pdlp::QuadraticProgram lp(4, 4);
  

  lp.constraint_lower_bounds << 12, -kInfinity, -4, -1;
  lp.constraint_upper_bounds << 12, 7, kInfinity, 1;
  lp.variable_lower_bounds << -kInfinity, -2, -kInfinity, 2.5;
  lp.variable_upper_bounds << kInfinity, kInfinity, 6, 3.5;
  const std::vector<Eigen::Triplet<double, int64_t>>
      constraint_matrix_triplets = {{0, 0, 2}, {0, 1, 1},   {0, 2, 1},
                                    {0, 3, 2}, {1, 0, 1},   {1, 2, 1},
                                    {2, 0, 4}, {3, 2, 1.5}, {3, 3, -1}};
  lp.constraint_matrix.setFromTriplets(constraint_matrix_triplets.begin(),
                                       constraint_matrix_triplets.end());
  lp.objective_vector << 5.5, -2, -1, 1;
  lp.objective_offset = -14;
  return lp;
}

int main(int argc, char* argv[]) {
  InitGoogle(argv[0], &argc, &argv, 
true);

  pdlp::PrimalDualHybridGradientParams params;
  

  

  params.mutable_termination_criteria()
      ->mutable_simple_optimality_criteria()
      ->set_eps_optimal_relative(1.0e-6);
  params.mutable_termination_criteria()
      ->mutable_simple_optimality_criteria()
      ->set_eps_optimal_absolute(1.0e-6);
  params.mutable_termination_criteria()->set_time_sec_limit(kInfinity);
  params.set_num_threads(1);
  params.set_verbosity_level(0);
  params.mutable_presolve_options()->set_use_glop(false);

  const pdlp::SolverResult result =
      pdlp::PrimalDualHybridGradient(SimpleLp(), params);
  const pdlp::SolveLog& solve_log = result.solve_log;

  if (solve_log.termination_reason() == pdlp::TERMINATION_REASON_OPTIMAL) {
    std::cout << "Solve successful" << '\n';
  } else {
    std::cout << "Solve not successful. Status: "
              << pdlp::TerminationReason_Name(solve_log.termination_reason())
              << '\n';
  }

  

  

  

  

  std::cout << "Primal solution:\n" << result.primal_solution << '\n';
  std::cout << "Dual solution:\n" << result.dual_solution << '\n';
  std::cout << "Reduced costs:\n" << result.reduced_costs << '\n';

  const pdlp::PointType solution_type = solve_log.solution_type();
  std::cout << "Solution type: " << pdlp::PointType_Name(solution_type) << '\n';
  const std::optional<pdlp::ConvergenceInformation> ci =
      pdlp::GetConvergenceInformation(solve_log.solution_stats(),
                                      solution_type);
  if (ci.has_value()) {
    std::cout << "Primal objective: " << ci->primal_objective() << '\n';
    std::cout << "Dual objective: " << ci->dual_objective() << '\n';
  }

  std::cout << "Iterations: " << solve_log.iteration_count() << '\n';
  std::cout << "Solve time (sec): " << solve_log.solve_time_sec() << '\n';

  return 0;
}

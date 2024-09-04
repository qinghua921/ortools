import { operations_research } from 'ts-ortools';

test('cp_sat_example', () =>
{
  let cp_model = new operations_research.sat.CpModelBuilder();

  let var_upper_bound = Math.max(50, 45, 37);
  let domain = new operations_research.Domain(0, var_upper_bound);


  let x = cp_model.NewIntVar(domain).WithName("x");
  let y = cp_model.NewIntVar(domain).WithName("y");
  let z = cp_model.NewIntVar(domain).WithName("z");

  // cp_model.AddLessOrEqual(2 * x + 7 * y + 3 * z, 50);
  cp_model.AddLessOrEqual(
    operations_research.sat.operator_plus(operations_research.sat.operator_times(2, x),
      operations_research.sat.operator_plus(operations_research.sat.operator_times(7, y),
        operations_research.sat.operator_times(3, z)))
    , 50);
  // cp_model.AddLessOrEqual(3 * x - 5 * y + 7 * z, 45);
  cp_model.AddLessOrEqual(
    operations_research.sat.operator_plus(operations_research.sat.operator_times(3, x),
      operations_research.sat.operator_minus(operations_research.sat.operator_times(5, y),
        operations_research.sat.operator_times(7, z)))
    , 45);
  // cp_model.AddLessOrEqual(5 * x + 2 * y - 6 * z, 37);
  cp_model.AddLessOrEqual(
    operations_research.sat.operator_plus(operations_research.sat.operator_times(5, x),
      operations_research.sat.operator_plus(operations_research.sat.operator_times(2, y),
        operations_research.sat.operator_times(6, z)))
    , 37);


  // cp_model.Maximize(2 * x + 2 * y + 3 * z);
  cp_model.Maximize(
    operations_research.sat.operator_plus(operations_research.sat.operator_times(2, x),
      operations_research.sat.operator_plus(operations_research.sat.operator_times(2, y),
        operations_research.sat.operator_times(3, z))));

  let response = operations_research.sat.Solve(cp_model.Build());
  expect(response.status()).toBe(operations_research.sat.CpSolverStatus.OPTIMAL);
  operations_research.sat.SolutionIntegerValue(response, x)
  // // [START print_solution]
  // if (response.status() == CpSolverStatus::OPTIMAL ||
  //     response.status() == CpSolverStatus::FEASIBLE) {
  //   // Get the value of x in the solution.
  //   LOG(INFO) << "Maximum of objective function: "
  //             << response.objective_value();
  //   LOG(INFO) << "x = " << SolutionIntegerValue(response, x);
  //   LOG(INFO) << "y = " << SolutionIntegerValue(response, y);
  //   LOG(INFO) << "z = " << SolutionIntegerValue(response, z);
  // } else {
  //   LOG(INFO) << "No solution found.";
  // }
  // // [END print_solution]

  // // Statistics.
  // // [START statistics]
  // LOG(INFO) << "Statistics";
  // LOG(INFO) << CpSolverResponseStats(response);
  // // [END statistics]
})
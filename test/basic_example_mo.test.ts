import { operations_research } from "../src";

test('cp_sat_example', () =>
{
  // math_opt::Model model("my_model");
  // const math_opt::Variable x = model.AddBinaryVariable("x");
  // const math_opt::Variable y = model.AddContinuousVariable(0.0, 2.5, "y");
  // // We can directly use linear combinations of variables ...
  // model.AddLinearConstraint(x + y <= 1.5, "c");
  // // ... or build them incrementally.
  // math_opt::LinearExpression objective_expression;
  // objective_expression += 2 * x;
  // objective_expression += y;
  // model.Maximize(objective_expression);
  // ASSIGN_OR_RETURN(const math_opt::SolveResult result,
  //                  Solve(model, math_opt::SolverType::kGscip));
  // switch (result.termination.reason) {
  //   case math_opt::TerminationReason::kOptimal:
  //   case math_opt::TerminationReason::kFeasible:
  //     std::cout << "Objective value: " << result.objective_value() << std::endl
  //               << "Value for variable x: " << result.variable_values().at(x)
  //               << std::endl;
  //     return absl::OkStatus();
  //   default:
  //     return util::InternalErrorBuilder()
  //            << "model failed to solve: " << result.termination;
  // }
});

import { operations_research } from "../src";

test('ts-ortools', () =>
{
  // CpModelBuilder cp_model;
  // // [END model]

  // // [START variables]
  // const Domain domain(0, 10);
  // const IntVar x = cp_model.NewIntVar(domain).WithName("x");
  // const IntVar y = cp_model.NewIntVar(domain).WithName("y");
  // const IntVar z = cp_model.NewIntVar(domain).WithName("z");
  // const BoolVar a = cp_model.NewBoolVar().WithName("a");
  // const BoolVar b = cp_model.NewBoolVar().WithName("b");
  // const BoolVar c = cp_model.NewBoolVar().WithName("c");
  // // [END variables]

  // // [START constraints]
  // cp_model.AddGreaterThan(x, y).OnlyEnforceIf(a);
  // cp_model.AddGreaterThan(y, z).OnlyEnforceIf(b);
  // cp_model.AddGreaterThan(z, x).OnlyEnforceIf(c);
  // // [END constraints]

  // // Add assumptions
  // cp_model.AddAssumptions({a, b, c});

  // // Solving part.
  // // [START solve]
  // const CpSolverResponse response = Solve(cp_model.Build());
  // // [END solve]

  // // Print solution.
  // // [START print_solution]
  // LOG(INFO) << CpSolverResponseStats(response);
  // if (response.status() == CpSolverStatus::INFEASIBLE) {
  //   for (const int index :
  //        response.sufficient_assumptions_for_infeasibility()) {
  //     LOG(INFO) << index;
  //   }
  // }
  let cp_model = new operations_research.sat.CpModelBuilder();
  let domain = new operations_research.Domain(0, 10);

  let x = cp_model.NewIntVar(domain).WithName("x");
  let y = cp_model.NewIntVar(domain).WithName("y");
  let z = cp_model.NewIntVar(domain).WithName("z");
  let a = cp_model.NewBoolVar().WithName("a");
  let b = cp_model.NewBoolVar().WithName("b");
  let c = cp_model.NewBoolVar().WithName("c");

  cp_model.AddGreaterThan(x, y).OnlyEnforceIf(a);
  cp_model.AddGreaterThan(y, z).OnlyEnforceIf(b);
  cp_model.AddGreaterThan(z, x).OnlyEnforceIf(c);
  cp_model.AddAssumptions([a, b, c]);

  let response = operations_research.sat.Solve(cp_model.Build());
  expect(response.status()).toBe(operations_research.sat.CpSolverStatus.INFEASIBLE);
});
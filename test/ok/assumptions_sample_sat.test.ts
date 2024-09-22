import { operations_research } from "../../src";

test('ts-ortools', () =>
{

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
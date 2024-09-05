import { operations_research } from "../../src";

test('cp_sat_example', () =>
{
  let solver =  operations_research.MPSolver.CreateSolver("GLOP");
  
  let x = solver.MakeNumVar(0.0, 1, "x");
  let y = solver.MakeNumVar(0.0, 2, "y");
  
  
  let ct = solver.MakeRowConstraint(0.0, 2.0, "ct");
  ct.SetCoefficient(x, 1);
  ct.SetCoefficient(y, 1);
  
  
  let objective = solver.MutableObjective();
  objective.SetCoefficient(x, 3);
  objective.SetCoefficient(y, 1);
  objective.SetMaximization();
  
  solver.Solve();
  
  expect(objective.Value()).toBe(4)
});

import { operations_research } from "../../src";

class DataModel
{
  weights: number[] = [48, 30, 19, 36, 36, 27, 42, 42, 36, 24, 30];
  num_items: number = this.weights.length;
  num_bins: number = this.weights.length;
  bin_capacity: number = 100;
}

test('ts-ortools', () =>
{
  const data = new DataModel();
  const solver = operations_research.MPSolver.CreateSolver('SCIP');
  if (!solver)
  {
    console.log('SCIP solver unavailable.');
    return;
  }
  const x: operations_research.MPVariable[][] = [];
  for (let i = 0; i < data.num_items; ++i)
  {
    x[i] = [];
    for (let j = 0; j < data.num_bins; ++j)
    {
      x[i][j] = solver.MakeIntVar(0, 1, '');
    }
  }
  const y = [];
  for (let j = 0; j < data.num_bins; ++j)
  {
    y[j] = solver.MakeIntVar(0, 1, '');
  }

  for (let i = 0; i < data.num_items; ++i)
  {
    let sum = new operations_research.LinearExpr();
    for (let j = 0; j < data.num_bins; ++j)
    {
      sum.operator_plus_equals(x[i][j]);
    }
  }


  for (let j = 0; j < data.num_bins; ++j)
  {
    let weight = new operations_research.LinearExpr();
    for (let i = 0; i < data.num_items; ++i)
    {
      weight.operator_plus_equals(operations_research.operator_times(data.weights[i], x[i][j]));
    }
    solver.MakeRowConstraint(
      operations_research.operator_less_equals(
        weight,
        operations_research.operator_times(y[j], data.bin_capacity)
      )
    );
  }
  const objective = solver.MutableObjective();
  const num_bins_used = new operations_research.LinearExpr();
  for (let j = 0; j < data.num_bins; ++j)
  {
    num_bins_used.operator_plus_equals(y[j]);
  }
  objective.MinimizeLinearExpr(num_bins_used);
  const result_status = solver.Solve();
  expect(result_status).toBe(operations_research.MPSolver.ResultStatus.OPTIMAL);

});
import { operator_EQ, operator_LEQ } from "../operations_research/GFunc";
import { LinearExpr } from "../operations_research/GLinearExpr";
import { MPSolver, ResultStatus } from "../operations_research/GMPSolver";

test("assignment_min_flow", () =>
{
  let costs = [
    [90, 80, 75, 70],
    [35, 85, 55, 65],
    [125, 95, 90, 95],
    [45, 110, 95, 115],
    [50, 100, 90, 100],
  ];
  let num_workers = costs.length;
  let num_tasks = costs[0].length;

  let solver = MPSolver.CreateSolver("SCIP");
  expect(solver).not.toBeUndefined();


  let x = [];
  for (let i = 0; i < num_workers; ++i)
  {
    let row = [];
    for (let j = 0; j < num_tasks; ++j)
    {
      let var_ = solver.MakeIntVar(0, 1, "");
      row.push(var_);
    }
    x.push(row);
  }

  for (let i = 0; i < num_workers; ++i)
  {
    let worker_sum = new LinearExpr();
    for (let j = 0; j < num_tasks; ++j)
    {
      worker_sum.operator_plus(x[i][j]);
    }
    solver.MakeRowConstraint(operator_LEQ(worker_sum, 1.0));
  }

  for (let j = 0; j < num_tasks; ++j)
  {
    let task_sum = new LinearExpr();
    for (let i = 0; i < num_workers; ++i)
    {
      task_sum.operator_plus(x[i][j]);
    }
    solver.MakeRowConstraint(operator_EQ(task_sum, 1.0));
  }

  let objective = solver.MutableObjective();
  for (let i = 0; i < num_workers; ++i)
  {
    for (let j = 0; j < num_tasks; ++j)
    {
      objective.SetCoefficient(x[i][j], costs[i][j]);
    }
  }
  objective.SetMinimization();


  let result_status = solver.Solve();
  expect(result_status).toBe(ResultStatus.OPTIMAL);

});
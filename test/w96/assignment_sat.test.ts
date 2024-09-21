import { operations_research } from "../../src";


test('ts-ortools', () =>
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

  let cp_model = new operations_research.sat.CpModelBuilder();

  let x = [];

  for (let i = 0; i < num_workers; i++)
  {
    let tasks = [];
    for (let j = 0; j < num_tasks; j++)
    {
      tasks.push(cp_model.NewBoolVar());
    }
    x.push(tasks);
  }

  for (let i = 0; i < num_workers; i++)
  {
    cp_model.AddAtMostOne(x[i])
  }

  for (let i = 0; i < num_workers; i++)
  {
    let tasks = [];
    for (let j = 0; j < num_tasks; j++)
    {
      tasks.push(x[i][j]);
    }
    cp_model.AddExactlyOne(tasks)
  }

  let total_cost = new operations_research.sat.LinearExpr();
  for (let i = 0; i < num_workers; i++)
  {
    for (let j = 0; j < num_tasks; j++)
    {
      total_cost.operator_plus_equals(operations_research.sat.operator_times(x[i][j], costs[i][j]));
    }
  }

  cp_model.Minimize(total_cost);

  const newLocal = cp_model.Build();
  let response = operations_research.sat.Solve(newLocal)

  // expect(response.status()).toBe(operations_research.sat.CpSolverStatus.OPTIMAL);
});
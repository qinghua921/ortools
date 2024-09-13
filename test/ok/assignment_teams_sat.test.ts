import { operations_research } from "../../src";

test('ts-ortools', async () =>
{
  let costs = [
    [90, 76, 75, 70],
    [35, 85, 55, 65],
    [125, 95, 90, 105],
    [45, 110, 95, 115],
    [60, 105, 80, 75],
    [45, 65, 110, 95],
  ];

  let num_workers = costs.length;
  let all_workers = Array.from({ length: num_workers }, (_, i) => i);

  let num_tasks = costs[0].length;
  let all_tasks = Array.from({ length: num_tasks }, (_, i) => i);

  let team1 = [0, 2, 4];
  let team2 = [1, 3, 5];
  let team_max = 2;

  let cp_model = new operations_research.sat.CpModelBuilder();

  let x: operations_research.sat.BoolVar[][] = [];
  for (let worker of all_workers)
  {
    x[worker] = [];
    for (let task of all_tasks)
    {
      x[worker][task] = cp_model.NewBoolVar().WithName(
        `x_${worker}_${task}`);
    }
  }

  for (let worker of all_workers)
  {
    cp_model.AddAtMostOne(x[worker]);
  }

  for (let task of all_tasks)
  {
    let tasks: operations_research.sat.BoolVar[] = [];
    for (let worker of all_workers)
    {
      tasks.push(x[worker][task]);
    }
    cp_model.AddExactlyOne(tasks);
  }

  let team1_tasks = new operations_research.sat.LinearExpr();
  for (let worker of team1)
  {
    for (let task of all_tasks)
    {
      team1_tasks.operator_plus_equals(x[worker][task]);
    }
  }
  cp_model.AddLessOrEqual(team1_tasks, team_max);

  let team2_tasks = new operations_research.sat.LinearExpr();
  for (let worker of team2)
  {
    for (let task of all_tasks)
    {
      team2_tasks.operator_plus_equals(x[worker][task]);
    }
  }
  cp_model.AddLessOrEqual(team2_tasks, team_max);

  let total_cost = new operations_research.sat.LinearExpr();
  for (let worker of all_workers)
  {
    for (let task of all_tasks)
    {
      total_cost.operator_plus_equals(operations_research.sat.operator_times(x[worker][task], costs[worker][task]));
    }
  }
  cp_model.Minimize(total_cost);

  const solver = await operations_research.sat.Solve(cp_model.Build())
  expect(solver.status()).toBe(operations_research.sat.CpSolverStatus.OPTIMAL);

});

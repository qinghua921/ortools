import { operations_research } from 'ts-ortools';


test('assignment_mip', () =>
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
  //   for (int j = 0; j < num_tasks; ++j) {
  //     std::vector<BoolVar> tasks;
  //     for (int i = 0; i < num_workers; ++i) {
  //       tasks.push_back(x[i][j]);
  //     }
  //     cp_model.AddExactlyOne(tasks);
  //   }

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

  let response = operations_research.sat.Solve(cp_model.Build())

  expect(response.status()).toBe(operations_research.sat.CpSolverStatus.OPTIMAL);
});
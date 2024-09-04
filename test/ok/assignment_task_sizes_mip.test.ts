import { operations_research } from "../../src";

test('assignment_mip', () =>
{
  let costs = [
    [90, 76, 75, 70, 50, 74, 12, 68],
    [35, 85, 55, 65, 48, 101, 70, 83],
    [125, 95, 90, 105, 59, 120, 36, 73],
    [45, 110, 95, 115, 104, 83, 37, 71],
    [60, 105, 80, 75, 59, 62, 93, 88],
    [45, 65, 110, 95, 47, 31, 81, 34],
    [38, 51, 107, 41, 69, 99, 115, 48],
    [47, 85, 57, 71, 92, 77, 109, 36],
    [39, 63, 97, 49, 118, 56, 92, 61],
    [47, 101, 71, 60, 88, 109, 52, 90]
  ];

  let num_workers = costs.length;
  let all_workers = Array.from({ length: num_workers }, (_, i) => i);

  let num_tasks = costs[0].length;
  let all_tasks = Array.from({ length: num_tasks }, (_, i) => i);

  let task_sizes = [10, 7, 3, 12, 15, 4, 11, 5];
  let total_size_max = 15;

  let solver = operations_research.MPSolver.CreateSolver('SCIP');
  expect(solver).not.toBeUndefined();

  let x = [];
  for (let worker of all_workers)
  {
    let row = [];
    for (let task of all_tasks)
    {
      let var_ = solver.MakeBoolVar(`x[${worker},${task}]`);
      row.push(var_);
    }
    x.push(row);
  }

  for (let worker of all_workers)
  {
    let worker_sum = new operations_research.LinearExpr();
    for (let task of all_tasks)
    {
      worker_sum.operator_plus_equals(new operations_research.LinearExpr(x[worker][task]).operator_times_equals(task_sizes[task]));
    }
    solver.MakeRowConstraint(operations_research.operator_less_equals(worker_sum, total_size_max));
  }

  for (let task of all_tasks)
  {
    let task_sum = new operations_research.LinearExpr();
    for (let worker of all_workers)
    {
      task_sum.operator_plus_equals(x[worker][task]);
    }
    solver.MakeRowConstraint(operations_research.operator_equals(task_sum, 1));
  }

  let objective = solver.MutableObjective();

  for (let worker of all_workers)
  {
    for (let task of all_tasks)
    {
      objective.SetCoefficient(x[worker][task], costs[worker][task]);
    }
  }
  objective.SetMinimization();

  let result_status = solver.Solve();
  expect(result_status).toBe(operations_research.MPSolver.ResultStatus.OPTIMAL);

});
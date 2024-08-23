import { MPSolver, ResultStatus } from "../src/operations_research/GMPSolver";
import { LinearExpr } from "../src/operations_research/GLinearExpr";
import { operator_EQ } from "../src/operations_research/GFunc";

test("assignment_groups_mip", () =>
{
  const costs =
    [
      [90, 76, 75, 70, 50, 74],
      [35, 85, 55, 65, 48, 101],
      [125, 95, 90, 105, 59, 120],
      [45, 110, 95, 115, 104, 83],
      [60, 105, 80, 75, 59, 62],
      [45, 65, 110, 95, 47, 31],
      [38, 51, 107, 41, 69, 99],
      [47, 85, 57, 71, 92, 77],
      [39, 63, 97, 49, 118, 56],
      [47, 101, 71, 60, 88, 109],
      [17, 39, 103, 64, 61, 92],
      [101, 45, 83, 59, 92, 27]
    ]

  const num_workers = costs.length;

  const all_workers = Array.from({ length: num_workers }, (_, i) => i);

  const num_tasks = costs[0].length;

  const all_tasks = Array.from({ length: num_tasks }, (_, i) => i);

  const group1 = [[2, 3], [1, 3], [1, 2], [0, 1], [0, 2]];

  const group2 = [[6, 7], [5, 7], [5, 6], [4, 5], [4, 7]];

  const group3 = [[10, 11], [9, 11], [9, 10], [8, 10], [8, 11]];

  const solver = MPSolver.CreateSolver('SCIP');
  expect(solver).not.toBeNull();


  const x = new Array(num_workers).fill(0)
    .map((_, worker) => new Array(num_tasks).fill(0)
      .map((_, task) => solver.MakeBoolVar(`x[${worker},${task}]`)));

  for (const worker of all_workers)
  {
    const worker_sum = new LinearExpr();
    for (const task of all_tasks)
    {
      worker_sum.operator_plus(x[worker][task]);
    }
  }

  for (const task of all_tasks)
  {
    const task_sum = new LinearExpr();
    for (const worker of all_workers)
    {
      task_sum.operator_plus(x[worker][task]);
      expect(solver.OwnsVariable(x[worker][task])).toBe(true);
    }
    let tmp = operator_EQ(task_sum, 1.0)
    expect(tmp).not.toBeUndefined();
    solver.MakeRowConstraint(tmp);
  }

  const work = new Array(num_workers).fill(0)
    .map((_, worker) => solver.MakeBoolVar(`work[${worker}]`));

  for (const worker of all_workers)
  {
    const task_sum = new LinearExpr();
    for (const task of all_tasks)
    {
      task_sum.operator_plus(x[worker][task]);
    }
    let tmp = operator_EQ(work[worker], task_sum)
    expect(tmp).not.toBeUndefined();
    solver.MakeRowConstraint(tmp);
  }

  const g1 = solver.MakeRowConstraint(1, 1);

  for (let i = 0; i < group1.length; ++i)
  {
    const tmp = solver.MakeRowConstraint(0, 1);
    tmp.SetCoefficient(work[group1[i][0]], 1);
    tmp.SetCoefficient(work[group1[i][1]], 1);
    const p = solver.MakeBoolVar(`g1_p${i}`);
    tmp.SetCoefficient(p, -2);

    g1.SetCoefficient(p, 1);
  }

  const g2 = solver.MakeRowConstraint(1, 1);

  for (let i = 0; i < group2.length; ++i)
  {
    const tmp = solver.MakeRowConstraint(0, 1);
    tmp.SetCoefficient(work[group2[i][0]], 1);
    tmp.SetCoefficient(work[group2[i][1]], 1);
    const p = solver.MakeBoolVar(`g2_p${i}`);
    tmp.SetCoefficient(p, -2);

    g2.SetCoefficient(p, 1);
  }

  const g3 = solver.MakeRowConstraint(1, 1);

  for (let i = 0; i < group3.length; ++i)
  {
    const tmp = solver.MakeRowConstraint(0, 1);
    tmp.SetCoefficient(work[group3[i][0]], 1);
    tmp.SetCoefficient(work[group3[i][1]], 1);
    const p = solver.MakeBoolVar(`g3_p${i}`);
    tmp.SetCoefficient(p, -2);

    g3.SetCoefficient(p, 1);
  }

  const objective = solver.MutableObjective();

  for (const worker of all_workers)
  {
    for (const task of all_tasks)
    {
      objective.SetCoefficient(x[worker][task], costs[worker][task]);
    }
  }

  objective.SetMaximization();

  const result_status = solver.Solve();

  expect(result_status).toBe(ResultStatus.OPTIMAL);

  expect(objective.Value().toFixed(0)).toBe('669');
})

import
{
  MPSolver,
  OptimizationProblemType,
  ResultStatus,
} from "../tssrc/operations_research/MPSolver";
import { MPVariable } from "../tssrc/operations_research/MPVariable";
import { LinearExpr } from "../tssrc/operations_research/LinearExpr";
import
{
  operator_EQ,
  operator_LEQ,
} from "../tssrc/operations_research/Func";

test("AssignmentTeamsMip", () =>
{
  const costs: number[][] = [
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
    [101, 45, 83, 59, 92, 27],
  ];

  const num_workers = costs.length;

  const all_workers: number[] = Array(num_workers).fill(0);

  for (let i = 0; i < num_workers; i++)
  {
    all_workers[i] = i;
  }

  const num_tasks = costs[0].length;

  const all_tasks: number[] = Array(num_tasks).fill(0);

  for (let i = 0; i < num_tasks; i++)
  {
    all_tasks[i] = i;
  }

  type WorkerIndex = number;

  type Binome = [WorkerIndex, WorkerIndex];

  type AllowedBinomes = Binome[];
  const group1: AllowedBinomes = [
    [2, 3],
    [1, 3],
    [1, 2],
    [0, 1],
    [0, 2],
  ];

  const group2: AllowedBinomes = [
    [6, 7],
    [5, 7],
    [5, 6],
    [4, 5],
    [4, 7],
  ];

  const group3: AllowedBinomes = [
    [10, 11],
    [9, 11],
    [9, 10],
    [8, 10],
    [8, 11],
  ];
  const solver = new MPSolver(
    "SCIP",
    OptimizationProblemType.SCIP_MIXED_INTEGER_PROGRAMMING
  );

  expect(solver).not.toBeUndefined();

  const x: MPVariable[][] = Array(num_workers)
    .fill(0)
    .map((_, worker) =>
      Array(num_tasks)
        .fill(0)
        .map((_, task) => solver.MakeBoolVar(`x[${worker},${task}]`))
    );

  for (let worker of all_workers)
  {
    const worker_sum: LinearExpr = new LinearExpr();
    for (let task of all_tasks)
    {
      let t = x[worker][task];
      worker_sum.operator_plus(t);
    }
    let c = operator_LEQ(worker_sum, 1.0);
    solver.MakeRowConstraint(c);
  }
  expect(1).toBe(1);
  for (let task of all_tasks)
  {
    const task_sum: LinearExpr = new LinearExpr();
    for (let worker of all_workers)
    {
      let t = x[worker][task];
      task_sum.operator_plus(t);
    }
    let c = operator_EQ(task_sum, 1.0);
    solver.MakeRowConstraint(c);
  }

  for (let task of all_tasks)
  {
    const task_sum: LinearExpr = new LinearExpr();
    for (let worker of all_workers)
    {
      let t = x[worker][task];
      task_sum.operator_plus(t);
    }
  }

  const work: MPVariable[] = all_workers.map(worker =>
    solver.MakeBoolVar(`work[${worker}]`)
  );

  for (let worker of all_workers)
  {
    const task_sum: LinearExpr = new LinearExpr();
    for (let task of all_tasks)
    {
      let t = x[worker][task];
      task_sum.operator_plus(t);
    }
    let c = operator_EQ(work[worker], task_sum);
    solver.MakeRowConstraint(c);
  }


  let g1 = solver.MakeRowConstraint(1, 1);
  for (let i = 0; i < group1.length; ++i)
  {
    let tmp = solver.MakeRowConstraint(0, 1);
    tmp.SetCoefficient(work[group1[i][0]], 1);
    tmp.SetCoefficient(work[group1[i][1]], 1);
    let p = solver.MakeBoolVar(`g1_p${i}`);
    tmp.SetCoefficient(p, -2);

    g1.SetCoefficient(p, 1);
  }

  let g2 = solver.MakeRowConstraint(1, 1);
  for (let i = 0; i < group2.length; ++i)
  {
    let tmp = solver.MakeRowConstraint(0, 1);
    tmp.SetCoefficient(work[group2[i][0]], 1);
    tmp.SetCoefficient(work[group2[i][1]], 1);
    let p = solver.MakeBoolVar(`g2_p${i}`);
    tmp.SetCoefficient(p, -2);

    g2.SetCoefficient(p, 1);
  }

  let g3 = solver.MakeRowConstraint(1, 1);
  for (let i = 0; i < group3.length; ++i)
  {
    let tmp = solver.MakeRowConstraint(0, 1);


    tmp.SetCoefficient(work[group3[i][0]], 1);
    tmp.SetCoefficient(work[group3[i][1]], 1);
    let p = solver.MakeBoolVar(`g3_p${i}`);
    tmp.SetCoefficient(p, -2);

    g3.SetCoefficient(p, 1);
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

  const result_status = solver.Solve();
  if (result_status != ResultStatus.OPTIMAL && result_status != ResultStatus.FEASIBLE)
  {
    console.log("No solution found.");
  }

  expect(objective.Value().toFixed(0)).toBe('239')

  // for (let worker of all_workers)
  // {
  //   for (let task of all_tasks)
  //   {
  //     if (x[worker][task].solution_value() > 0.5)
  //     {
  //       console.log(`Worker ${worker} assigned to task ${task}.  Cost: ${costs[worker][task]}`);
  //     }
  //   }
  // }

});

test("new", () =>
{
  let mPSolver = new MPSolver(
    "SCIP",
    OptimizationProblemType.CBC_MIXED_INTEGER_PROGRAMMING
  );
  expect(mPSolver).not.toBeUndefined();
});

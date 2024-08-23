import { BoolVar } from "../src/operations_research/sat/GBoolVar";
import { IntVar } from "../src/operations_research/sat/GIntVar";
import { CpModelBuilder } from "../src/operations_research/sat/GCpModelBuilder";
import { LinearExpr } from "../src/operations_research/sat/GLinearExpr";
import { operator_times } from "../src/operations_research/sat/GFunc";

test("assignment_groups_sat", () =>
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
      [101, 45, 83, 59, 92, 27],
    ]

  let num_workers = costs.length;
  let all_workers = Array.from({ length: num_workers }, (_, i) => i);

  let num_tasks = costs[0].length;
  let all_tasks = Array.from({ length: num_tasks }, (_, i) => i);


  let group1 =
    [
      [0, 0, 1, 1],
      [0, 1, 0, 1],
      [0, 1, 1, 0],
      [1, 1, 0, 0],
      [1, 0, 1, 0],
    ]


  let group2 =
    [
      [0, 0, 1, 1],
      [0, 1, 0, 1],
      [0, 1, 1, 0],
      [1, 1, 0, 0],
      [1, 0, 0, 1],
    ]

  let group3 =
    [
      [0, 0, 1, 1],
      [0, 1, 0, 1],
      [0, 1, 1, 0],
      [1, 1, 0, 0],
      [1, 0, 0, 1],
    ]

  let cp_model = new CpModelBuilder();

  let x = Array.from({ length: num_workers }, (_, i) =>
    Array.from({ length: num_tasks }, (_, j) =>
      cp_model.NewBoolVar().WithName(`x[${i},${j}]`)
    )
  );

  for (const worker of all_workers)
  {
    cp_model.AddAtMostOne(x[worker]);
  }

  for (const task of all_tasks)
  {
    let tasks: BoolVar[] = [];
    for (const worker of all_workers)
    {
      tasks.push(x[worker][task]);
    }
    cp_model.AddAtMostOne(tasks);
  }

  const work = Array.from({ length: num_workers }, (_, i) =>
    new IntVar(cp_model.NewBoolVar().WithName(`work[${i}]`))
  );

  for (const worker of all_workers)
  {
    let task_sum = new LinearExpr();
    for (const task of all_tasks)
    {
      task_sum.operator_plus(x[worker][task]);
    }
    cp_model.AddEquality(work[worker], task_sum);
  }


  let table1 = cp_model.AddAllowedAssignments([work[0], work[1], work[2], work[3]]);
  for (const t of group1)
  {
    table1.AddTuple(t);
  }


  let table3 = cp_model.AddAllowedAssignments([work[4], work[5], work[6], work[7]]);
  for (const t of group2)
  {
    table3.AddTuple(t);
  }

  let table2 = cp_model.AddAllowedAssignments([work[8], work[9], work[10], work[11]]);
  for (const t of group3)
  {
    table2.AddTuple(t);
  }

  let total_cost = new LinearExpr();

  // for (int worker : all_workers )
  // {
  //   for (int task : all_tasks )
  //   {
  //     total_cost += x[worker][task] * costs[worker][task];
  //   }
  // }
  for (const worker of all_workers)
  {
    for (const task of all_tasks)
    {
      let letf = x[worker][task]
      let right = costs[worker][task]
      total_cost.operator_plus(operator_times(letf, right));
    }
  }
  cp_model.Maximize(total_cost);

  // const CpSolverResponse response = Solve(cp_model.Build());
  let response = cp_model.Solve();
  // // [END solve]

  // // Print solution.
  // // [START print_solution]
  // if (response.status() == CpSolverStatus::INFEASIBLE )
  // {
  //   LOG(FATAL) << "No solution found.";
  // }
  // LOG(INFO) << "Total cost: " << response.objective_value();
  // LOG(INFO);
  // for (int worker : all_workers )
  // {
  //   for (int task : all_tasks )
  //   {
  //     if (SolutionBooleanValue(response, x[worker][task]))
  //     {
  //       LOG(INFO) << "Worker " << worker << " assigned to task " << task
  //         << ".  Cost: " << costs[worker][task];
  //     }
  //   }
  // }
  // [END print_solution]
}
);
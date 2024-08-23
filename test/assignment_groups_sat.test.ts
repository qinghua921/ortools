import { BoolVar } from "../src/operations_research/sat/GBoolVar";

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

  //   std:: vector < std:: vector < BoolVar > > x(num_workers,
  //     std:: vector<BoolVar>(num_tasks));
  //   for (int worker : all_workers )
  // {
  //   for (int task : all_tasks )
  //   {
  //     x[worker][task] = cp_model.NewBoolVar().WithName(
  //       absl:: StrFormat("x[%d,%d]", worker, task));
  //   }
  // }
  let x = Array.from({ length: num_workers }, (_, i) =>
    Array.from({ length: num_tasks }, (_, j) =>
      new BoolVar("x[" + i + "," + j + "]")));
  


  // // [END variables]

  // // Constraints
  // // [START constraints]
  // // Each worker is assigned to at most one task.
  // for (int worker : all_workers )
  // {
  //   cp_model.AddAtMostOne(x[worker]);
  // }
  // // Each task is assigned to exactly one worker.
  // for (int task : all_tasks )
  // {
  //   std:: vector < BoolVar > tasks;
  //   for (int worker : all_workers )
  //   {
  //     tasks.push_back(x[worker][task]);
  //   }
  //   cp_model.AddExactlyOne(tasks);
  // }
  // // [END constraints]

  // // [START assignments]
  // // Create variables for each worker, indicating whether they work on some
  // // task.
  // std:: vector < IntVar > work(num_workers);
  // for (int worker : all_workers )
  // {
  //   work[worker] = IntVar(
  //     cp_model.NewBoolVar().WithName(absl:: StrFormat("work[%d]", worker)));
  // }

  // for (int worker : all_workers )
  // {
  //         LinearExpr task_sum;
  //   for (int task : all_tasks )
  //   {
  //     task_sum += x[worker][task];
  //   }
  //   cp_model.AddEquality(work[worker], task_sum);
  // }

  //     // Define the allowed groups of worders
  //     auto table1 =
  //   cp_model.AddAllowedAssignments({ work[0], work[1], work[2], work[3] });
  // for (const auto& t : group1 )
  // {
  //   table1.AddTuple(t);
  // }
  //     auto table2 =
  //   cp_model.AddAllowedAssignments({ work[4], work[5], work[6], work[7] });
  // for (const auto& t : group2 )
  // {
  //   table2.AddTuple(t);
  // }
  //     auto table3 =
  //   cp_model.AddAllowedAssignments({ work[8], work[9], work[10], work[11] });
  // for (const auto& t : group3 )
  // {
  //   table3.AddTuple(t);
  // }
  //     // [END assignments]

  //     // Objective
  //     // [START objective]
  //     LinearExpr total_cost;
  // for (int worker : all_workers )
  // {
  //   for (int task : all_tasks )
  //   {
  //     total_cost += x[worker][task] * costs[worker][task];
  //   }
  // }
  // cp_model.Minimize(total_cost);
  // // [END objective]

  // // Solve
  // // [START solve]
  // const CpSolverResponse response = Solve(cp_model.Build());
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
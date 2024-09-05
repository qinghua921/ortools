import { operations_research } from "../../src";

test('assignment_groups_mip', () =>
{


  //     std:: vector < std:: vector < BoolVar >> x(num_workers,
  //       std:: vector<BoolVar>(num_tasks));
  //     for (int worker : all_workers) {
  //       for (int task : all_tasks) {
  //         x[worker][task] = cp_model.NewBoolVar().WithName(
  //           absl:: StrFormat("x[%d,%d]", worker, task));
  //       }
  //     }
  //     // [END variables]

  //     // Constraints
  //     // [START constraints]
  //     // Each worker is assigned to at most one task.
  //     for (int worker : all_workers) {
  //       cp_model.AddAtMostOne(x[worker]);
  //     }

  //     // Each task is assigned to exactly one worker.
  //     for (int task : all_tasks) {
  //       std:: vector < BoolVar > tasks;
  //       for (int worker : all_workers) {
  //         tasks.push_back(x[worker][task]);
  //       }
  //       cp_model.AddExactlyOne(tasks);
  //     }

  //////////////////////////////////////
  // // Each team takes at most two tasks.
  // LinearExpr team1_tasks;
  //     for (int worker : team1) {
  //       for (int task : all_tasks) {
  //         team1_tasks += x[worker][task];
  //       }
  //     }
  //     cp_model.AddLessOrEqual(team1_tasks, team_max);

  // LinearExpr team2_tasks;
  //     for (int worker : team2) {
  //       for (int task : all_tasks) {
  //         team2_tasks += x[worker][task];
  //       }
  //     }
  //     cp_model.AddLessOrEqual(team2_tasks, team_max);
  // // [END constraints]

  // // Objective
  // // [START objective]
  // LinearExpr total_cost;
  //     for (int worker : all_workers) {
  //       for (int task : all_tasks) {
  //         total_cost += x[worker][task] * costs[worker][task];
  //       }
  //     }
  //     cp_model.Minimize(total_cost);
  //     // [END objective]

  //     // Solve
  //     // [START solve]
  //     const CpSolverResponse response = Solve(cp_model.Build());
  //     // [END solve]

  //     // Print solution.
  //     // [START print_solution]
  //     if (response.status() == CpSolverStatus::INFEASIBLE) {
  //       LOG(FATAL) << "No solution found.";
  //     }
  //     LOG(INFO) << "Total cost: " << response.objective_value();
  //     LOG(INFO)log
  //     for (int worker : all_workers) {
  //       for (int task : all_tasks) {
  //         if (SolutionBooleanValue(response, x[worker][task]))
  //         {
  //           LOG(INFO) << "Worker " << worker << " assigned to task " << task
  //             << ".  Cost: " << costs[worker][task];
  //         }
  //       }
  //     }
  // [END print_solution]

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

  const solver = operations_research.sat.Solve(cp_model.Build())
  expect(solver.status()).toBe(operations_research.sat.CpSolverStatus.OPTIMAL);

});

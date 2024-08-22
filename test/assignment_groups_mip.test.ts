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

  const num_workers = costs.length;

  const all_workers = Array.from({ length: num_workers }, (_, i) => i);

  const num_tasks = costs[0].length;

  const all_tasks = Array.from({ length: num_tasks }, (_, i) => i);

  const group1 = [[2, 3], [1, 3], [1, 2], [0, 1], [0, 2]]

  const group2 = [[6, 7], [5, 7], [5, 6], [4, 5], [4, 7]]

  const group3 = [[10, 11], [9, 11], [9, 10], [8, 10], [8, 11]]

  // std:: unique_ptr < MPSolver > solver(MPSolver:: CreateSolver("SCIP"));
  const solver = new MPSolver("SCIP");
  // if (!solver)
  // {
  //   LOG(WARNING) << "SCIP solver unavailable.";
  //   return;
  // }
  // // [END solver]

  // // Variables
  // // [START variables]
  // // x[i][j] is an array of 0-1 variables, which will be 1
  // // if worker i is assigned to task j.
  // std:: vector < std:: vector <const MPVariable*>> x(
  //   num_workers, std:: vector <const MPVariable*> (num_tasks));
  // for (int worker : all_workers) {
  //   for (int task : all_tasks) {
  //     x[worker][task] =
  //       solver -> MakeBoolVar(absl:: StrFormat("x[%d,%d]", worker, task));
  //   }
  // }
  // // [END variables]

  // // Constraints
  // // [START constraints]
  // // Each worker is assigned to at most one task.
  // for (int worker : all_workers) {
  //     LinearExpr worker_sum;
  //   for (int task : all_tasks) {
  //     worker_sum += x[worker][task];
  //   }
  //   solver -> MakeRowConstraint(worker_sum <= 1.0);
  // }
  // // Each task is assigned to exactly one worker.
  // for (int task : all_tasks) {
  //     LinearExpr task_sum;
  //   for (int worker : all_workers) {
  //     task_sum += x[worker][task];
  //   }
  //   solver -> MakeRowConstraint(task_sum == 1.0);
  // }
  // // [END constraints]

  // // [START assignments]
  // // Create variables for each worker, indicating whether they work on some
  // // task.
  // std:: vector <const MPVariable*> work(num_workers);
  // for (int worker : all_workers) {
  //   work[worker] = solver -> MakeBoolVar(absl:: StrFormat("work[%d]", worker));
  // }

  // for (int worker : all_workers) {
  //     LinearExpr task_sum;
  //   for (int task : all_tasks) {
  //     task_sum += x[worker][task];
  //   }
  //   solver -> MakeRowConstraint(work[worker] == task_sum);
  // }

  // // Group1
  // {
  //   MPConstraint * g1 = solver -> MakeRowConstraint(1, 1);
  //   for (int i = 0; i < group1.size(); ++i) {
  //     // a*b can be transformed into 0 <= a + b - 2*p <= 1 with p in [0,1]
  //     // p is true if a AND b, false otherwise
  //     MPConstraint * tmp = solver -> MakeRowConstraint(0, 1);
  //     tmp -> SetCoefficient(work[group1[i].first], 1);
  //     tmp -> SetCoefficient(work[group1[i].second], 1);
  //     MPVariable * p = solver -> MakeBoolVar(absl:: StrFormat("g1_p%d", i));
  //     tmp -> SetCoefficient(p, -2);

  //     g1 -> SetCoefficient(p, 1);
  //   }
  // }
  // // Group2
  // {
  //   MPConstraint * g2 = solver -> MakeRowConstraint(1, 1);
  //   for (int i = 0; i < group2.size(); ++i) {
  //     // a*b can be transformed into 0 <= a + b - 2*p <= 1 with p in [0,1]
  //     // p is true if a AND b, false otherwise
  //     MPConstraint * tmp = solver -> MakeRowConstraint(0, 1);
  //     tmp -> SetCoefficient(work[group2[i].first], 1);
  //     tmp -> SetCoefficient(work[group2[i].second], 1);
  //     MPVariable * p = solver -> MakeBoolVar(absl:: StrFormat("g2_p%d", i));
  //     tmp -> SetCoefficient(p, -2);

  //     g2 -> SetCoefficient(p, 1);
  //   }
  // }
  // // Group3
  // {
  //   MPConstraint * g3 = solver -> MakeRowConstraint(1, 1);
  //   for (int i = 0; i < group3.size(); ++i) {
  //     // a*b can be transformed into 0 <= a + b - 2*p <= 1 with p in [0,1]
  //     // p is true if a AND b, false otherwise
  //     MPConstraint * tmp = solver -> MakeRowConstraint(0, 1);
  //     tmp -> SetCoefficient(work[group3[i].first], 1);
  //     tmp -> SetCoefficient(work[group3[i].second], 1);
  //     MPVariable * p = solver -> MakeBoolVar(absl:: StrFormat("g3_p%d", i));
  //     tmp -> SetCoefficient(p, -2);

  //     g3 -> SetCoefficient(p, 1);
  //   }
  // }
  // // [END assignments]

  // // Objective.
  // // [START objective]
  // MPObjective * const objective = solver -> MutableObjective();
  // for (int worker : all_workers) {
  //   for (int task : all_tasks) {
  //     objective -> SetCoefficient(x[worker][task], costs[worker][task]);
  //   }
  // }
  // objective -> SetMinimization();
  // // [END objective]

  // // Solve
  // // [START solve]
  // const MPSolver:: ResultStatus result_status = solver -> Solve();
  // // [END solve]

  // // Print solution.
  // // [START print_solution]
  // // Check that the problem has a feasible solution.
  // if (result_status != MPSolver:: OPTIMAL &&
  //   result_status != MPSolver::FEASIBLE) {
  //   LOG(FATAL) << "No solution found.";
  // }
  // LOG(INFO) << "Total cost = " << objective -> Value() << "\n\n";
  // for (int worker : all_workers) {
  //   for (int task : all_tasks) {
  //     // Test if x[i][j] is 0 or 1 (with tolerance for floating point
  //     // arithmetic).
  //     if (x[worker][task] -> solution_value() > 0.5)
  //     {
  //       LOG(INFO) << "Worker " << worker << " assigned to task " << task
  //         << ".  Cost: " << costs[worker][task];
  //     }
  //   }
  // }
  // [END print_solution]
})

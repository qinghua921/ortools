import { operations_research as op } from '../src'
import { MPVariable } from '../src/operations_research/MPVariable';


function AssignmentLinearSumAssignment()
{

    // const std::vector<std::vector<int64_t>> costs = {{
    //     {{90, 76, 75, 70, 50, 74}},
    //     {{35, 85, 55, 65, 48, 101}},
    //     {{125, 95, 90, 105, 59, 120}},
    //     {{45, 110, 95, 115, 104, 83}},
    //     {{60, 105, 80, 75, 59, 62}},
    //     {{45, 65, 110, 95, 47, 31}},
    //     {{38, 51, 107, 41, 69, 99}},
    //     {{47, 85, 57, 71, 92, 77}},
    //     {{39, 63, 97, 49, 118, 56}},
    //     {{47, 101, 71, 60, 88, 109}},
    //     {{17, 39, 103, 64, 61, 92}},
    //     {{101, 45, 83, 59, 92, 27}},
    // }};
    // const int num_workers                         = costs.size();
    // std::vector<int> all_workers(num_workers);
    // std::iota(all_workers.begin(), all_workers.end(), 0);

    // const int num_tasks = costs[0].size();
    // std::vector<int> all_tasks(num_tasks);
    // std::iota(all_tasks.begin(), all_tasks.end(), 0);

    // using WorkerIndex           = int;
    // using Binome                = std::pair<WorkerIndex, WorkerIndex>;
    // using AllowedBinomes        = std::vector<Binome>;
    // const AllowedBinomes group1 = {{
    //     {2, 3},
    //     {1, 3},
    //     {1, 2},
    //     {0, 1},
    //     {0, 2},
    // }};

    // const AllowedBinomes group2 = {{
    //     {6, 7},
    //     {5, 7},
    //     {5, 6},
    //     {4, 5},
    //     {4, 7},
    // }};

    // const AllowedBinomes group3 = {{
    //     {10, 11},
    //     {9, 11},
    //     {9, 10},
    //     {8, 10},
    //     {8, 11},
    // }};

    // std::unique_ptr<MPSolver> solver(MPSolver::CreateSolver("SCIP"));
    // if (!solver)
    // {
    //     LOG(WARNING) << "SCIP solver unavailable.";
    //     return;
    // }

    // std::vector<std::vector<const MPVariable *>> x(
    //     num_workers, std::vector<const MPVariable *>(num_tasks)
    // );
    // for (int worker : all_workers)
    // {
    //     for (int task : all_tasks)
    //     {
    //         x[worker][task] =
    //             solver->MakeBoolVar(absl::StrFormat("x[%d,%d]", worker, task));
    //     }
    // }

    // for (int worker : all_workers)
    // {
    //     LinearExpr worker_sum;
    //     for (int task : all_tasks)
    //     {
    //         worker_sum += x[worker][task];
    //     }
    //     solver->MakeRowConstraint(worker_sum <= 1.0);
    // }


    // for (int task : all_tasks)
    // {
    //     LinearExpr task_sum;
    //     for (int worker : all_workers)
    //     {
    //         task_sum += x[worker][task];
    //     }
    //     solver->MakeRowConstraint(task_sum == 1.0);
    // }

    // std::vector<const MPVariable *> work(num_workers);
    // for (int worker : all_workers)
    // {
    //     work[worker] = solver->MakeBoolVar(absl::StrFormat("work[%d]", worker));
    // }

    // for (int worker : all_workers)
    // {
    //     LinearExpr task_sum;
    //     for (int task : all_tasks)
    //     {
    //         task_sum += x[worker][task];
    //     }
    //     solver->MakeRowConstraint(work[worker] == task_sum);
    // }

    // {
    //     MPConstraint *g1 = solver->MakeRowConstraint(1, 1);
    //     for (int i = 0; i < group1.size(); ++i)
    //     {
    //         MPConstraint *tmp = solver->MakeRowConstraint(0, 1);
    //         tmp->SetCoefficient(work[group1[i].first], 1);
    //         tmp->SetCoefficient(work[group1[i].second], 1);
    //         MPVariable *p = solver->MakeBoolVar(absl::StrFormat("g1_p%d", i));
    //         tmp->SetCoefficient(p, -2);

    //         g1->SetCoefficient(p, 1);
    //     }
    // }
    // {
    //     MPConstraint *g2 = solver->MakeRowConstraint(1, 1);
    //     for (int i = 0; i < group2.size(); ++i)
    //     {
    //         MPConstraint *tmp = solver->MakeRowConstraint(0, 1);
    //         tmp->SetCoefficient(work[group2[i].first], 1);
    //         tmp->SetCoefficient(work[group2[i].second], 1);
    //         MPVariable *p = solver->MakeBoolVar(absl::StrFormat("g2_p%d", i));
    //         tmp->SetCoefficient(p, -2);

    //         g2->SetCoefficient(p, 1);
    //     }
    // }
    // {
    //     MPConstraint *g3 = solver->MakeRowConstraint(1, 1);
    //     for (int i = 0; i < group3.size(); ++i)
    //     {
    //         MPConstraint *tmp = solver->MakeRowConstraint(0, 1);
    //         tmp->SetCoefficient(work[group3[i].first], 1);
    //         tmp->SetCoefficient(work[group3[i].second], 1);
    //         MPVariable *p = solver->MakeBoolVar(absl::StrFormat("g3_p%d", i));
    //         tmp->SetCoefficient(p, -2);

    //         g3->SetCoefficient(p, 1);
    //     }
    // }

    // MPObjective *const objective = solver->MutableObjective();
    // for (int worker : all_workers)
    // {
    //     for (int task : all_tasks)
    //     {
    //         objective->SetCoefficient(x[worker][task], costs[worker][task]);
    //     }
    // }
    // objective->SetMinimization();

    // const MPSolver::ResultStatus result_status = solver->Solve();

    // if (result_status != MPSolver::OPTIMAL &&
    //     result_status != MPSolver::FEASIBLE)
    // {
    //     LOG(FATAL) << "No solution found.";
    // }
    // LOG(INFO) << "Total cost = " << objective->Value() << "\n\n";
    // for (int worker : all_workers)
    // {
    //     for (int task : all_tasks)
    //     {
    //         if (x[worker][task]->solution_value() > 0.5)
    //         {
    //             LOG(INFO) << "Worker " << worker << " assigned to task " << task
    //                       << ".  Cost: " << costs[worker][task];
    //         }
    //     }
    // }

    let costs = [
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

    let num_workers = costs.length;
    let all_workers = [];
    for (let i = 0; i < num_workers; ++i)
    {
        all_workers.push(i);
    }

    let num_tasks = costs[0].length;
    let all_tasks = [];
    for (let i = 0; i < num_tasks; ++i)
    {
        all_tasks.push(i);
    }

    let group1 = [
        [2, 3],
        [1, 3],
        [1, 2],
        [0, 1],
        [0, 2],
    ];

    let group2 = [
        [6, 7],
        [5, 7],
        [5, 6],
        [4, 5],
        [4, 7],
    ];

    let group3 = [
        [10, 11],
        [9, 11],
        [9, 10],
        [8, 10],
        [8, 11],
    ];

    let solver = op.MPSolver.CreateSolver("SCIP");
    if (!solver)
    {
        console.log("SCIP solver unavailable.");
        return;
    }

    let x: MPVariable[][] = [];
    for (let worker of all_workers)
    {
        x[worker] = [];
        for (let task of all_tasks)
        {
            x[worker][task] = solver.MakeBoolVar(
                `x[${worker},${task}]`
            );
        }
    }

    for (let worker of all_workers)
    {
        let worker_sum = new op.LinearExpr();
        for (let task of all_tasks)
        {
            worker_sum = worker_sum.operator_plus_eq(x[worker][task]);
        }
        solver.MakeRowConstraint(op.operator_le(worker_sum, 1));
    }

    for (let task of all_tasks)
    {
        let task_sum = new op.LinearExpr();
        for (let worker of all_workers)
        {
            task_sum = task_sum.operator_plus_eq(x[worker][task]);
        }
        solver.MakeRowConstraint(op.operator_eq(task_sum, 1));
    }

    let work: MPVariable[] = [];
    for (let worker of all_workers)
    {
        work[worker] = solver.MakeBoolVar(`work[${worker}]`);
    }

    for (let worker of all_workers)
    {
        let task_sum = new op.LinearExpr();
        for (let task of all_tasks)
        {
            task_sum = task_sum.operator_plus_eq(x[worker][task]);
        }
        solver.MakeRowConstraint(op.operator_eq(task_sum, work[worker]));
    }

    {
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
    }

    {
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
    }

    {
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

    if (result_status != op.MPSolver.ResultStatus.OPTIMAL &&
        result_status != op.MPSolver.ResultStatus.FEASIBLE)
    {
        console.log("No solution found.");
        return;
    }

    console.log("Total cost = " + objective.Value());

    for (let worker of all_workers)
    {
        for (let task of all_tasks)
        {
            if (x[worker][task].solution_value() > 0.5)
            {
                console.log(`Worker ${worker} assigned to task ${task}.  Cost: ${costs[worker][task]}`);
            }
        }
    }




}

AssignmentLinearSumAssignment();

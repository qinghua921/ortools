import { operations_research as op } from '../src'

function test()
{

    // const std::vector<std::vector<int64_t>> costs = {{
    //     {{90, 76, 75, 70, 50, 74, 12, 68}},
    //     {{35, 85, 55, 65, 48, 101, 70, 83}},
    //     {{125, 95, 90, 105, 59, 120, 36, 73}},
    //     {{45, 110, 95, 115, 104, 83, 37, 71}},
    //     {{60, 105, 80, 75, 59, 62, 93, 88}},
    //     {{45, 65, 110, 95, 47, 31, 81, 34}},
    //     {{38, 51, 107, 41, 69, 99, 115, 48}},
    //     {{47, 85, 57, 71, 92, 77, 109, 36}},
    //     {{39, 63, 97, 49, 118, 56, 92, 61}},
    //     {{47, 101, 71, 60, 88, 109, 52, 90}},
    // }};
    // const int num_workers                         = costs.size();
    // std::vector<int> all_workers(num_workers);
    // std::iota(all_workers.begin(), all_workers.end(), 0);

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
        [47, 101, 71, 60, 88, 109, 52, 90],
    ];
    let num_workers = costs.length;
    let all_workers = Array.from({ length: num_workers }, (_, i) => i);

    // const int num_tasks = costs[0].size();
    // std::vector<int> all_tasks(num_tasks);
    // std::iota(all_tasks.begin(), all_tasks.end(), 0);

    // const std::vector<int64_t> task_sizes = {{10, 7, 3, 12, 15, 4, 11, 5}};
    // const int total_size_max              = 15;

    let num_tasks = costs[0].length;
    let all_tasks = Array.from({ length: num_tasks }, (_, i) => i);

    let task_sizes = [10, 7, 3, 12, 15, 4, 11, 5];
    let total_size_max = 15;

    // std::unique_ptr<MPSolver> solver(MPSolver::CreateSolver("SCIP"));
    // if (!solver)
    // {
    //     LOG(WARNING) << "SCIP solver unavailable.";
    //     return;
    // }

    let solver = op.MPSolver.CreateSolver("SCIP");
    if (!solver)
    {
        console.log("SCIP solver unavailable.");
        return;
    }

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

    let x = Array.from({ length: num_workers }, (_, worker) => Array.from({ length: num_tasks }, (_, task) => solver.MakeBoolVar(`x[${worker},${task}]`)));

    // for (int worker : all_workers)
    // {
    //     LinearExpr worker_sum;
    //     for (int task : all_tasks)
    //     {
    //         worker_sum += LinearExpr(x[worker][task]) * task_sizes[task];
    //     }
    //     solver->MakeRowConstraint(worker_sum <= total_size_max);
    // }
    for (let worker of all_workers)
    {
        let worker_sum = new op.LinearExpr();
        for (let task of all_tasks)
        {
            worker_sum.operator_plus_eq(new op.LinearExpr(x[worker][task]).operator_times(task_sizes[task]));
        }
        solver.makeRowConstraint(worker_sum, op.MPSolver.MPSolver.LESS_EQUAL, total_size_max);
    }
    // for (int task : all_tasks)
    // {
    //     LinearExpr task_sum;
    //     for (int worker : all_workers)
    //     {
    //         task_sum += x[worker][task];
    //     }
    //     solver->MakeRowConstraint(task_sum == 1.0);
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
}

test();

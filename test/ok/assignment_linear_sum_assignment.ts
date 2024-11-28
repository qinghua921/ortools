import { operations_research as op } from '../../src'


function test()
{

    // SimpleLinearSumAssignment assignment;
    let assignment = new op.SimpleLinearSumAssignment();

    // const int num_workers = 4;
    // std::vector<int> all_workers(num_workers);
    // std::iota(all_workers.begin(), all_workers.end(), 0);

    let num_workers = 4;
    let all_workers = Array.from({ length: num_workers }, (_, i) => i);

    // const int num_tasks = 4;
    // std::vector<int> all_tasks(num_tasks);
    // std::iota(all_tasks.begin(), all_tasks.end(), 0);
    let num_tasks = 4;
    let all_tasks = Array.from({ length: num_tasks }, (_, i) => i);

    // const std::vector<std::vector<int>> costs = {{
    //     {{90, 76, 75, 70}},   // Worker 0
    //     {{35, 85, 55, 65}},   // Worker 1
    //     {{125, 95, 90, 105}}, // Worker 2
    //     {{45, 110, 95, 115}}, // Worker 3
    // }};
    let costs = [
        [90, 76, 75, 70],
        [35, 85, 55, 65],
        [125, 95, 90, 105],
        [45, 110, 95, 115]
    ];

    // for (int w : all_workers)
    // {
    //     for (int t : all_tasks)
    //     {
    //         if (costs[w][t])
    //         {
    //             assignment.AddArcWithCost(w, t, costs[w][t]);
    //         }
    //     }
    // }

    for (let w of all_workers)
    {
        for (let t of all_tasks)
        {
            if (costs[w][t])
            {
                assignment.AddArcWithCost(w, t, costs[w][t]);
            }
        }
    }

    // SimpleLinearSumAssignment::Status status = assignment.Solve();
    let status = assignment.Solve();

    // if (status == SimpleLinearSumAssignment::OPTIMAL)
    // {
    //     LOG(INFO) << "Total cost: " << assignment.OptimalCost();
    //     for (int worker : all_workers)
    //     {
    //         LOG(INFO) << "Worker " << std::to_string(worker) << " assigned to task "
    //                   << std::to_string(assignment.RightMate(worker)) << ". Cost: "
    //                   << std::to_string(assignment.AssignmentCost(worker)) << ".";
    //     }
    // }
    // else
    // {
    //     LOG(INFO) << "Solving the linear assignment problem failed.";
    // }

    if (status == op.SimpleLinearSumAssignment.Status.OPTIMAL)
    {
        console.log("Total cost: " + assignment.OptimalCost());
        for (let worker of all_workers)
        {
            console.log("Worker " + worker + " assigned to task " + assignment.RightMate(worker) + ". Cost: " + assignment.AssignmentCost(worker) + ".");
        }
    }
    else
    {
        console.log("Solving the linear assignment problem failed.");
    }
}

test();

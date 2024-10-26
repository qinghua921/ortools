import { operations_research } from '../src'



function AssignmentLinearSumAssignment()
{

    //SimpleLinearSumAssignment assignment;

    //const int num_workers = 4;
    //std::vector<int> all_workers(num_workers);
    //std::iota(all_workers.begin(), all_workers.end(), 0);

    //const int num_tasks = 4;
    //std::vector<int> all_tasks(num_tasks);
    //std::iota(all_tasks.begin(), all_tasks.end(), 0);

    //const std::vector<std::vector<int>> costs = {{
    //    {{90, 76, 75, 70}},

    //    {{35, 85, 55, 65}},

    //    {{125, 95, 90, 105}},

    //    {{45, 110, 95, 115}},

    //}};

    //for (int w : all_workers)
    //{
    //    for (int t : all_tasks)
    //    {
    //        if (costs[w][t])
    //        {
    //            assignment.AddArcWithCost(w, t, costs[w][t]);
    //        }
    //    }
    //}

    //SimpleLinearSumAssignment::Status status = assignment.Solve();

    //if (status == SimpleLinearSumAssignment::OPTIMAL)
    //{
    //    LOG(INFO) << "Total cost: " << assignment.OptimalCost();
    //    for (int worker : all_workers)
    //    {
    //        LOG(INFO) << "Worker " << std::to_string(worker) << " assigned to task "
    //                  << std::to_string(assignment.RightMate(worker)) << ". Cost: "
    //                  << std::to_string(assignment.AssignmentCost(worker)) << ".";
    //    }
    //}
    //else
    //{
    //    LOG(INFO) << "Solving the linear assignment problem failed.";
    //}

    const assignment = new operations_research.SimpleLinearSumAssignment();
    const num_workers = 4;
    const all_workers = Array.from({ length: num_workers }, (_, i) => i);
    const num_tasks = 4;
    const all_tasks = Array.from({ length: num_tasks }, (_, i) => i);
    const costs = [
        [90, 76, 75, 70],
        [35, 85, 55, 65],
        [125, 95, 90, 105],
        [45, 110, 95, 115],
    ];

    for (const w of all_workers)
    {
        for (const t of all_tasks)
        {
            if (costs[w][t])
            {
                assignment.AddArcWithCost(w, t, costs[w][t]);
            }
        }
    }

    const status = assignment.Solve();

    if (status === operations_research.SimpleLinearSumAssignment.Status.OPTIMAL)
    {
        console.log(`Total cost: ${assignment.OptimalCost()}`);
        for (const worker of all_workers)
        {
            console.log(`Worker ${worker} assigned to task ${assignment.RightMate(worker)}. Cost: ${assignment.AssignmentCost(worker)}.`);
        }
    } else
    {
        console.log("Solving the linear assignment problem failed.");
    }
}

AssignmentLinearSumAssignment();

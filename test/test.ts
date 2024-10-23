import { operations_research } from '../src'

function AssignmentGroups()
{


    //for (int worker : all_workers)
    //{
    //    LinearExpr task_sum;
    //    for (int task : all_tasks)
    //    {
    //        task_sum += x[worker][task];
    //    }
    //    cp_model.AddEquality(work[worker], task_sum);
    //}
    //auto table1 =
    //    cp_model.AddAllowedAssignments({work[0], work[1], work[2], work[3]});
    //for (const auto &t : group1)
    //{
    //    table1.AddTuple(t);
    //}
    //auto table2 =        cp_model.AddAllowedAssignments({work[4], work[5], work[6], work[7]});
    //for (const auto &t : group2)
    //{
    //    table2.AddTuple(t);
    //}
    //auto table3 =        cp_model.AddAllowedAssignments({work[8], work[9], work[10], work[11]});
    //for (const auto &t : group3)
    //{
    //    table3.AddTuple(t);
    //}
    //LinearExpr total_cost;
    //for (int worker : all_workers)
    //{
    //    for (int task : all_tasks)
    //    {
    //        total_cost += x[worker][task] * costs[worker][task];
    //    }
    //}
    //cp_model.Minimize(total_cost);
    //const CpSolverResponse response = Solve(cp_model.Build());
    //if (response.status() == CpSolverStatus::INFEASIBLE)
    //{
    //    LOG(FATAL) << "No solution found.";
    //}
    //LOG(INFO) << "Total cost: " << response.objective_value();
    //LOG(INFO);
    //for (int worker : all_workers)
    //{
    //    for (int task : all_tasks)
    //    {
    //        if (SolutionBooleanValue(response, x[worker][task]))
    //        {
    //            LOG(INFO) << "Worker " << worker << " assigned to task " << task
    //                      << ".  Cost: " << costs[worker][task];
    //        }
    //    }
    //}

    const costs = [
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
    const all_workers = Array.from({ length: num_workers }, (_, i) => i);
    const num_tasks = costs[0].length;
    const all_tasks = Array.from({ length: num_tasks }, (_, i) => i);
    const group1 = [
        [0, 0, 1, 1],
        [0, 1, 0, 1],
        [0, 1, 1, 0],
        [1, 1, 0, 0],
        [1, 0, 1, 0],
    ];
    const group2 = [
        [0, 0, 1, 1],
        [0, 1, 0, 1],
        [0, 1, 1, 0],
        [1, 1, 0, 0],
        [1, 0, 0, 1],
    ];
    const group3 = [
        [0, 0, 1, 1],
        [0, 1, 0, 1],
        [0, 1, 1, 0],
        [1, 0, 1, 0],
        [1, 0, 0, 1],
    ];
    const cp_model = new operations_research.sat.CpModelBuilder();
    const x = Array.from({ length: num_workers }, (_, worker) =>
        Array.from({ length: num_tasks }, (_, task) =>
            cp_model.NewBoolVar().WithName(`x[${worker},${task}]`)
        )
    );
    for (let worker of all_workers)
    {
        cp_model.AddBoolOr(x[worker]);
    }
    for (let task of all_tasks)
    {
       let tasks = [];
       for (let worker of all_workers)
       {
           tasks.push(x[worker][task]);
        }
        cp_model.AddExactlyOne(tasks);
    }
    const work = Array.from({ length: num_workers }, (_, worker) =>
        cp_model.NewBoolVar().WithName(`work[${worker}]`)
    );
    for (let worker of all_workers)
    {
        let task_sum = new operations_research.sat.LinearExpr();
        for (let task of all_tasks)
        {
            task_sum.op(1, x[worker][task]);
        }
    }
    const table1 = cp_model.newAllowedAssignments(
        [work[0], work[1], work[2], work[3]]
    );
    for (const t of group1)
    {
        table1.addTuple(t);
    }
    const table2 = cp_model.newAllowedAssignments(
        [work[4], work[5], work[6], work[7]]
    );
    for (const t of group2)
    {
        table2.addTuple(t);
    }
    const table3 = cp_model.newAllowedAssignments(
        [work[8], work[9], work[10], work[11]]
    );
    for (const t of group3)
    {
        table3.addTuple(t);
    }
    const total_cost = all_workers.reduce((acc, worker) =>
        all_tasks.reduce((acc2, task) =>
            acc2.add(x[worker][task].mul(costs[worker][task])),
            acc
        ),
        cp_model.newConstant(0)
    );
    cp_model.minimize(total_cost);
    const solver = new operations_research.CpSolver();
    const status = solver.solve(cp_model);
    if (status !== 'OPTIMAL')
    {
        throw new Error('No solution found.');
    }
    console.log(`Total cost: ${solver.objectiveValue}`);
    for (let worker of all_workers)
    {
        for (let task of all_tasks)
        {
            if (solver.booleanValue(x[worker][task]))
            {
                console.log(`Worker ${worker} assigned to task ${task}.  Cost: ${costs[worker][task]}`);
            }
        }
    }
}

AssignmentGroups();

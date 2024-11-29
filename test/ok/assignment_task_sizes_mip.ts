import { operations_research as op } from '../../src'

function test()
{
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


    let num_tasks = costs[0].length;
    let all_tasks = Array.from({ length: num_tasks }, (_, i) => i);

    let task_sizes = [10, 7, 3, 12, 15, 4, 11, 5];
    let total_size_max = 15;

    let solver = op.MPSolver.CreateSolver("SCIP");
    if (!solver)
    {
        console.log("SCIP solver unavailable.");
        return;
    }

    let x = Array.from({ length: num_workers }, (_, worker) => Array.from({ length: num_tasks }, (_, task) => solver.MakeBoolVar(`x[${worker},${task}]`)));

    for (let worker of all_workers)
    {
        let worker_sum = new op.LinearExpr();
        for (let task of all_tasks)
        {
            worker_sum.operator_plus_eq(op.operator_times(x[worker][task], task_sizes[task]));
        }
        solver.MakeRowConstraint(op.operator_le(worker_sum, total_size_max));
    }

    for (let task of all_tasks)
    {
        let task_sum = new op.LinearExpr();
        for (let worker of all_workers)
        {
            task_sum.operator_plus_eq(x[worker][task]);
        }
        solver.MakeRowConstraint(op.operator_eq(task_sum, 1));
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
    }
    console.log(`Total cost = ${objective.Value()}`);
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

test();

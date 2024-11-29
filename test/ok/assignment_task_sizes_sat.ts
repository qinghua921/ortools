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
        [47, 101, 71, 60, 88, 109, 52, 90]
    ];
    let num_workers = costs.length;
    let all_workers = Array.from({ length: num_workers }, (_, i) => i);


    let num_tasks = costs[0].length;
    let all_tasks = Array.from({ length: num_tasks }, (_, i) => i);


    let task_sizes = [10, 7, 3, 12, 15, 4, 11, 5];
    let total_size_max = 15;


    let cp_model = new op.sat.CpModelBuilder();


    let x = Array.from({ length: num_workers },
        (_, i) => Array.from({ length: num_tasks },
            (_, j) => cp_model.NewBoolVar().WithName(`x[${i},${j}]`)));


    for (let worker of all_workers)
    {
        let task_sum = new op.sat.LinearExpr();
        for (let task of all_tasks)
        {
            task_sum.operator_plus_eq(op.sat.operator_times(x[worker][task], task_sizes[task]))
        }
        cp_model.AddLessOrEqual(task_sum, total_size_max);
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


    let total_cost = new op.sat.LinearExpr();
    for (let worker of all_workers)
    {
        for (let task of all_tasks)
        {
            total_cost.operator_plus_eq(op.sat.operator_times(x[worker][task], costs[worker][task]));
        }
    }
    cp_model.Minimize(total_cost);

    let response = op.sat.Solve(cp_model.Build());


    if (response.status() == op.sat.CpSolverStatus.INFEASIBLE)
    {
        console.log("No solution found.");
    }
    console.log(`Total cost: ${response.objective_value()}`);
    console.log();
    for (let worker of all_workers)
    {
        for (let task of all_tasks)
        {
            if (op.sat.SolutionBooleanValue(response, x[worker][task]))
            {
                console.log(`Worker ${worker} assigned to task ${task}.  Cost: ${costs[worker][task]}`);
            }
        }
    }
}

test();

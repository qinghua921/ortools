import { operations_research } from "../../src";

test('cp_sat_example', () =>
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

    let cp_model = new operations_research.sat.CpModelBuilder();

    let x = [];
    for (let worker of all_workers)
    {
        let row = [];
        for (let task of all_tasks)
        {
            let var_ = cp_model.NewBoolVar().WithName(`x[${worker},${task}]`);
            row.push(var_);
        }
        x.push(row);
    }


    for (let worker of all_workers)
    {
        let task_sum = new operations_research.sat.LinearExpr();
        for (let task of all_tasks)
        {
            task_sum.operator_plus_equals(
                operations_research.sat.operator_times(x[worker][task], task_sizes[task])
            );
        }
        cp_model.AddLessOrEqual(task_sum, total_size_max)
    }

    for (let worker of all_workers)
    {
        let tasks = [];
        for (let task of all_tasks)
        {
            tasks.push(x[worker][task]);
        }
        cp_model.AddExactlyOne(tasks);
    }

    let total_cost = new operations_research.sat.LinearExpr();
    for (let worker of all_workers)
    {
        for (let task of all_tasks)
        {
            total_cost.operator_plus_equals(
                operations_research.sat.operator_times(x[worker][task], costs[worker][task])
            );
        }
    }
    cp_model.Minimize(total_cost);

    let response=operations_research.sat.Solve(cp_model.Build());
    expect(response.status()).toBe(operations_research.sat.CpSolverStatus.OPTIMAL);
});

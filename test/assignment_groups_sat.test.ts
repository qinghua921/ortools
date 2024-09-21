import { operations_research } from "../src";


test('ts-ortools', () =>
{
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
    let all_workers = Array.from({ length: num_workers }, (_, i) => i);

    let num_tasks = costs[0].length;
    let all_tasks = Array.from({ length: num_tasks }, (_, i) => i);

    let group1 = [
        [0, 0, 1, 1],  // Workers 2, 3
        [0, 1, 0, 1],  // Workers 1, 3
        [0, 1, 1, 0],  // Workers 1, 2
        [1, 1, 0, 0],  // Workers 0, 1
        [1, 0, 1, 0],  // Workers 0, 2
    ];

    let group2 = [
        [0, 0, 1, 1],  // Workers 6, 7
        [0, 1, 0, 1],  // Workers 5, 7
        [0, 1, 1, 0],  // Workers 5, 6
        [1, 1, 0, 0],  // Workers 4, 5
        [1, 0, 0, 1],  // Workers 4, 7
    ];

    let group3 = [
        [0, 0, 1, 1],  // Workers 10, 11
        [0, 1, 0, 1],  // Workers 9, 11
        [0, 1, 1, 0],  // Workers 9, 10
        [1, 0, 1, 0],  // Workers 8, 10
        [1, 0, 0, 1],  // Workers 8, 11
    ];

    let cp_model = new operations_research.sat.CpModelBuilder();
    expect(cp_model).not.toBeUndefined();

    let x: operations_research.sat.BoolVar[][] = [];
    for (let worker = 0; worker < num_workers; worker++)
    {
        x.push([])
        for (let task = 0; task < num_tasks; task++)
        {
            x[worker].push(cp_model.NewBoolVar().WithName(
                `x[${worker},${task}]`));
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

    let work: operations_research.sat.IntVar[] = [];
    for (let worker of all_workers)
    {
        work.push(new operations_research.sat.IntVar(
            cp_model.NewBoolVar().WithName(`work[${worker}]`)
        ));
    }

    for (let worker of all_workers)
    {
        let task_sum = new operations_research.sat.LinearExpr();
        for (let task of all_tasks)
        {
            task_sum.operator_plus_equals(x[worker][task]);
        }
        cp_model.AddEquality(work[worker], task_sum);
    }

    let table1 = cp_model.AddAllowedAssignments([work[0], work[1], work[2], work[3]]);
    for (let t of group1)
    {
        table1.AddTuple(t);
    }
    let table2 = cp_model.AddAllowedAssignments([work[4], work[5], work[6], work[7]]);
    for (let t of group2)
    {
        table2.AddTuple(t);
    }
    let table3 = cp_model.AddAllowedAssignments([work[8], work[9], work[10], work[11]]);
    for (let t of group3)
    {
        table3.AddTuple(t);
    }

    let total_cost = new operations_research.sat.LinearExpr();
    for (let worker of all_workers)
    {
        for (let task of all_tasks)
        {
            total_cost.operator_plus_equals(operations_research.sat.operator_times(x[worker][task], costs[worker][task]))
        }
    }
    cp_model.Minimize(total_cost);
    let x1 = cp_model.Build();
    // let response = operations_research.sat.Solve(x1);

    // expect(response.status()).toBe(operations_research.sat.CpSolverStatus.OPTIMAL)
});

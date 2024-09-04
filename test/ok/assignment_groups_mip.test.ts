import { operations_research } from "../../src";

test('assignment_groups_mip', () =>
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
        [101, 45, 83, 59, 92, 27]
    ];

    let num_workers = costs.length;
    let all_workers = Array.from({ length: num_workers }, (_, i) => i);
    let num_tasks = costs[0].length;
    let all_tasks = Array.from({ length: num_tasks }, (_, i) => i);

    let group1 = [[2, 3], [1, 3], [1, 2], [0, 1], [0, 2]];
    let group2 = [[6, 7], [5, 7], [5, 6], [4, 5], [4, 7]];
    let group3 = [[10, 11], [9, 11], [9, 10], [8, 10], [8, 11]];

    let solver = operations_research.MPSolver.CreateSolver("SCIP")
    expect(solver).not.toBeUndefined();

    let x = [];
    for (let worker of all_workers)
    {
        let row = [];
        for (let task of all_tasks)
        {
            let var_ = solver.MakeBoolVar(`x[${worker},${task}]`);
            row.push(var_);
        }
        x.push(row);
    }

    for (let worker of all_workers)
    {
        let worker_sum = new operations_research.LinearExpr();
        for (let task of all_tasks)
        {
            worker_sum.operator_plus_equals(x[worker][task]);
        }
        solver.MakeRowConstraint(operations_research.operator_less_equals(worker_sum, 1.0));
    }

    for (let task of all_tasks)
    {
        let task_sum = new operations_research.LinearExpr();
        for (let worker of all_workers)
        {
            task_sum.operator_plus_equals(x[worker][task]);
        }
        solver.MakeRowConstraint(operations_research.operator_equals(task_sum, 1.0));
    }

    let work = [];
    for (let worker of all_workers)
    {
        let var_ = solver.MakeBoolVar(`work[${worker}]`);
        work.push(var_);
    }

    for (let worker of all_workers)
    {
        let worker_sum = new operations_research.LinearExpr();
        for (let task of all_tasks)
        {
            worker_sum.operator_plus_equals(x[worker][task]);
        }
        solver.MakeRowConstraint(operations_research.operator_equals(work[worker], worker_sum));
    }

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
    expect(result_status).toBe(operations_research.MPSolver.ResultStatus.OPTIMAL);

});
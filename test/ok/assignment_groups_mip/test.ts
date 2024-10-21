import { operations_research } from '../src'

function AssignmentTeamsMip()
{
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
        [2, 3],
        [1, 3],
        [1, 2],
        [0, 1],
        [0, 2],
    ];



    const group2 = [
        [6, 7],
        [5, 7],
        [5, 6],
        [4, 5],
        [4, 7],
    ];



    const group3 = [
        [10, 11],
        [9, 11],
        [9, 10],
        [8, 10],
        [8, 11],
    ];


    const solver = operations_research.MPSolver.CreateSolver("SCIP")
    if (!solver)
    {
        console.log("SCIP solver unavailable.");
        return;
    }



    const x = Array.from(
        { length: num_workers },
        (_, i) => Array.from(
            { length: num_tasks },
            (_, j) => solver.MakeBoolVar(`x[${i},${j}]`)));


    for (let worker of all_workers)
    {
        const worker_sum = new operations_research.LinearExpr();
        for (let task of all_tasks)
        {
            worker_sum.operator_plus_equals(x[worker][task]);
        }
        solver.MakeRowConstraint(operations_research.operator_le(worker_sum, 1.0));
    }


    for (let task of all_tasks)
    {
        const task_sum = new operations_research.LinearExpr();
        for (let worker of all_workers)
        {
            task_sum.operator_plus_equals(x[worker][task]);
        }
        solver.MakeRowConstraint(operations_research.operator_eq(task_sum, 1.0));
    }


    const work = Array.from(
        { length: num_workers },
        (_, i) => solver.MakeBoolVar(`work[${i}]`));


    for (let worker of all_workers)
    {
        const task_sum = new operations_research.LinearExpr();
        for (let task of all_tasks)
        {
            task_sum.operator_plus_equals(x[worker][task]);
        }
        solver.MakeRowConstraint(operations_research.operator_eq(work[worker], task_sum));
    }




    {
        const g1 = solver.MakeRowConstraint(1, 1);
        for (let i = 0; i < group1.length; ++i)
        {
            const tmp = solver.MakeRowConstraint(0, 1);
            tmp.SetCoefficient(work[group1[i][0]], 1);
            tmp.SetCoefficient(work[group1[i][1]], 1);
            const p = solver.MakeBoolVar(`g1_p${i}`);
            tmp.SetCoefficient(p, -2);
            g1.SetCoefficient(p, 1);
        }
    }




    {
        const g2 = solver.MakeRowConstraint(1, 1);
        for (let i = 0; i < group2.length; ++i)
        {
            const tmp = solver.MakeRowConstraint(0, 1);
            tmp.SetCoefficient(work[group2[i][0]], 1);
            tmp.SetCoefficient(work[group2[i][1]], 1);
            const p = solver.MakeBoolVar(`g2_p${i}`);
            tmp.SetCoefficient(p, -2);
            g2.SetCoefficient(p, 1);
        }
    }




    {
        const g3 = solver.MakeRowConstraint(1, 1);
        for (let i = 0; i < group3.length; ++i)
        {
            const tmp = solver.MakeRowConstraint(0, 1);
            tmp.SetCoefficient(work[group3[i][0]], 1);
            tmp.SetCoefficient(work[group3[i][1]], 1);
            const p = solver.MakeBoolVar(`g3_p${i}`);
            tmp.SetCoefficient(p, -2);
            g3.SetCoefficient(p, 1);
        }
    }


    const objective = solver.MutableObjective();
    for (let worker of all_workers)
    {
        for (let task of all_tasks)
        {
            objective.SetCoefficient(x[worker][task], costs[worker][task]);
        }
    }
    objective.SetMinimization();


    const result_status = solver.Solve();



    if (result_status != operations_research.MPSolver.ResultStatus.OPTIMAL &&
        result_status != operations_research.MPSolver.ResultStatus.FEASIBLE)
    {
        console.log("No solution found.");
        return;
    }
    console.log(`Total cost = ${objective.Value()}\n\n`);
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

AssignmentTeamsMip();

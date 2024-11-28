import { operations_research as op } from '../../src'

function test()
{
    let costs = [
        [90, 80, 75, 70],
        [35, 85, 55, 65],
        [125, 95, 90, 95],
        [45, 110, 95, 115],
        [50, 100, 90, 100],
    ];
    let num_workers = costs.length;
    let num_tasks = costs[0].length;
    let solver = op.MPSolver.CreateSolver("SCIP");
    if (!solver)
    {
        console.log("SCIP solver unavailable.");
        return;
    }
    let x = [];
    for (let i = 0; i < num_workers; ++i)
    {
        let row = [];
        for (let j = 0; j < num_tasks; ++j)
        {
            row.push(solver.MakeIntVar(0, 1, ""));
        }
        x.push(row);
    }
    for (let i = 0; i < num_workers; ++i)
    {
        let worker_sum = new op.LinearExpr();
        for (let j = 0; j < num_tasks; ++j)
        {
            worker_sum.operator_plus_eq(x[i][j]);
        }
        solver.MakeRowConstraint(op.operator_le(worker_sum, 1.0));
    }
    for (let j = 0; j < num_tasks; ++j)
    {
        let task_sum = new op.LinearExpr();
        for (let i = 0; i < num_workers; ++i)
        {
            task_sum.operator_plus_eq(x[i][j]);
        }
        solver.MakeRowConstraint(op.operator_eq(task_sum, 1.0));
    }
    let objective = solver.MutableObjective();
    for (let i = 0; i < num_workers; ++i)
    {
        for (let j = 0; j < num_tasks; ++j)
        {
            objective.SetCoefficient(x[i][j], costs[i][j]);
        }
    }
    objective.SetMinimization();
    let result_status = solver.Solve();
    if (result_status != op.MPSolver.ResultStatus.OPTIMAL &&
        result_status != op.MPSolver.ResultStatus.FEASIBLE)
    {
        console.log("No solution found.");
        return;
    }
    console.log("Total cost = " + objective.Value() + "\n\n");
    for (let i = 0; i < num_workers; ++i)
    {
        for (let j = 0; j < num_tasks; ++j)
        {
            if (x[i][j].solution_value() > 0.5)
            {
                console.log("Worker " + i + " assigned to task " + j +
                    ".  Cost = " + costs[i][j]);
            }
        }
    }
}

test();

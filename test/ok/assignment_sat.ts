import { operations_research as op } from '../../src'

function test()
{

    let costs = [
        [90, 80, 75, 70],
        [35, 85, 55, 65],
        [125, 95, 90, 95],
        [45, 110, 95, 115],
        [50, 100, 90, 100]
    ];
    let num_workers = costs.length;
    let num_tasks = costs[0].length;

    let cp_model = new op.sat.CpModelBuilder();

    let x = [];
    for (let i = 0; i < num_workers; ++i)
    {
        let row = [];
        for (let j = 0; j < num_tasks; ++j)
        {
            row.push(cp_model.NewBoolVar());
        }
        x.push(row);
    }

    for (let i = 0; i < num_workers; ++i)
    {
        cp_model.AddAtMostOne(x[i]);
    }


    for (let j = 0; j < num_tasks; ++j)
    {
        let tasks = [];
        for (let i = 0; i < num_workers; ++i)
        {
            tasks.push(x[i][j]);
        }
        cp_model.AddExactlyOne(tasks);
    }


    let total_cost = new op.sat.LinearExpr();
    for (let i = 0; i < num_workers; ++i)
    {
        for (let j = 0; j < num_tasks; ++j)
        {
            total_cost.operator_plus_eq(op.sat.operator_times(x[i][j], costs[i][j]));
        }
    }



    let response = op.sat.Solve(cp_model.Build());

    if (response.status() == op.sat.CpSolverStatus.INFEASIBLE)
    {
        console.log("No solution found.");
        return;
    }

    console.log("Total cost: " + response.objective_value());
    console.log();
    for (let i = 0; i < num_workers; ++i)
    {
        for (let j = 0; j < num_tasks; ++j)
        {
            if (op.sat.SolutionBooleanValue(response, x[i][j]))
            {
                console.log("Task " + i + " assigned to worker " + j +
                    ".  Cost: " + costs[i][j]);
            }
        }
    }
}

test();

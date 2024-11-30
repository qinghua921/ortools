import { operations_research as op } from '../../src'
const DataModel = {
    weights: [48, 30, 19, 36, 36, 27, 42, 42, 36, 24, 30],
    num_items: 11,
    num_bins: 11,
    bin_capacity: 100
}
function test()
{
    let solver = op.MPSolver.CreateSolver("SCIP");
    if (!solver)
    {
        console.log("SCIP solver unavailable.");
        return;
    }
    let x: op.MPVariable[][] = [];
    for (let i = 0; i < DataModel.num_items; ++i)
    {
        let row = [];
        for (let j = 0; j < DataModel.num_bins; ++j)
        {
            row.push(solver.MakeIntVar(0, 1, ""));
        }
        x.push(row);
    }
    let y = [];
    for (let j = 0; j < DataModel.num_bins; ++j)
    {
        y.push(solver.MakeIntVar(0, 1, ""));
    }
    for (let i = 0; i < DataModel.num_items; ++i)
    {
        let sum = new op.LinearExpr();
        for (let j = 0; j < DataModel.num_bins; ++j)
        {
            sum.operator_plus_eq(x[i][j]);
        }
        solver.MakeRowConstraint(op.operator_eq(sum, 1));
    }
    for (let j = 0; j < DataModel.num_bins; ++j)
    {
        let weight = new op.LinearExpr();
        for (let i = 0; i < DataModel.num_items; ++i)
        {
            weight.operator_plus_eq(op.operator_times(DataModel.weights[i], new op.LinearExpr(x[i][j])));
        }
        solver.MakeRowConstraint(op.operator_le(weight, op.operator_times(new op.LinearExpr(y[j]), DataModel.bin_capacity)));
    }
    let objective = solver.MutableObjective();
    let num_bins_used = new op.LinearExpr();
    for (let j = 0; j < DataModel.num_bins; ++j)
    {
        num_bins_used.operator_plus_eq(y[j]);
    }
    objective.MinimizeLinearExpr(num_bins_used);
    let result_status = solver.Solve();
    if (result_status != op.MPSolver.ResultStatus.OPTIMAL)
    {
        console.log("The problem does not have an optimal solution!");
        return;
    }
    console.log("Number of bins used: " + objective.Value());
    console.log("");
    let total_weight = 0;
    for (let j = 0; j < DataModel.num_bins; ++j)
    {
        if (y[j].solution_value() == 1)
        {
            console.log("Bin " + j);
            console.log("");
            let bin_weight = 0;
            for (let i = 0; i < DataModel.num_items; ++i)
            {
                if (x[i][j].solution_value() == 1)
                {
                    console.log("Item " + i + " - Weight: " + DataModel.weights[i]);
                    bin_weight += DataModel.weights[i];
                }
            }
            console.log("Packed bin weight: " + bin_weight);
            console.log("");
            total_weight += bin_weight;
        }
    }
    console.log("Total packed weight: " + total_weight);
}
test();

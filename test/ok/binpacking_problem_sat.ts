import { operations_research as op } from '../../src'

function test()
{
    let kBinCapacity = 100;
    let kSlackCapacity = 20;
    let kNumBins = 5;
    let items = [
        [20, 6], [15, 6], [30, 4], [45, 3]
    ];
    let num_items = items.length;
    let cp_model = new op.sat.CpModelBuilder();
    let x: op.sat.IntVar[][] = [];
    for (let i = 0; i < num_items; ++i)
    {
        x[i] = [];
        let num_copies = items[i][1];
        for (let b = 0; b < kNumBins; ++b)
        {
            x[i][b] = cp_model.NewIntVar(new op.Domain(0, num_copies));
        }
    }
    let load: op.sat.IntVar[] = [];
    for (let b = 0; b < kNumBins; ++b)
    {
        load[b] = cp_model.NewIntVar(new op.Domain(0, kBinCapacity));
    }
    let slacks: op.sat.BoolVar[] = [];
    for (let b = 0; b < kNumBins; ++b)
    {
        slacks[b] = cp_model.NewBoolVar();
    }
    for (let b = 0; b < kNumBins; ++b)
    {
        let expr = new op.sat.LinearExpr();
        for (let i = 0; i < num_items; ++i)
        {
            expr.operator_plus_eq(op.sat.operator_times(x[i][b], items[i][0]))
        }
        cp_model.AddEquality(expr, load[b]);
    }
    for (let i = 0; i < num_items; ++i)
    {
        cp_model.AddEquality(op.sat.LinearExpr.Sum(x[i]), items[i][1]);
    }
    const safe_capacity = kBinCapacity - kSlackCapacity;
    for (let b = 0; b < kNumBins; ++b)
    {
        cp_model.AddLessOrEqual(load[b], safe_capacity).OnlyEnforceIf(slacks[b]);
        cp_model.AddGreaterThan(load[b], safe_capacity).OnlyEnforceIf(slacks[b].Not());
    }
    cp_model.Maximize(op.sat.LinearExpr.Sum(slacks));
    const response = op.sat.Solve(cp_model.Build());
    console.log("response ------- ", op.sat.CpSolverResponseStats(response));
}
test();

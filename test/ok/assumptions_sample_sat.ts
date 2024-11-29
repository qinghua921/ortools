import { operations_research as op } from '../../src'
function test()
{
    let cp_model = new op.sat.CpModelBuilder();
    let domain = new op.Domain(0, 10);
    let x = cp_model.NewIntVar(domain).WithName("x");
    let y = cp_model.NewIntVar(domain).WithName("y");
    let z = cp_model.NewIntVar(domain).WithName("z");
    let a = cp_model.NewBoolVar().WithName("a");
    let b = cp_model.NewBoolVar().WithName("b");
    let c = cp_model.NewBoolVar().WithName("c");
    cp_model.AddGreaterThan(x, y).OnlyEnforceIf(a);
    cp_model.AddGreaterThan(y, z).OnlyEnforceIf(b);
    cp_model.AddGreaterThan(z, x).OnlyEnforceIf(c);
    cp_model.AddAssumptions([a, b, c]);
    let response = op.sat.Solve(cp_model.Build());
    console.log(op.sat.CpSolverResponseStats(response));
    if (response.status() === op.sat.CpSolverStatus.INFEASIBLE) 
    {
        for (const index of response.sufficient_assumptions_for_infeasibility()) 
        {
            console.log(index);
        }
    }
}
test();

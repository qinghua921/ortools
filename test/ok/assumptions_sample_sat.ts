import { operations_research as op } from '../../src'

function test()
{
    // CpModelBuilder cp_model;

    let cp_model = new op.sat.CpModelBuilder();

    // const Domain domain(0, 10);
    // const IntVar x  = cp_model.NewIntVar(domain).WithName("x");
    // const IntVar y  = cp_model.NewIntVar(domain).WithName("y");
    // const IntVar z  = cp_model.NewIntVar(domain).WithName("z");
    // const BoolVar a = cp_model.NewBoolVar().WithName("a");
    // const BoolVar b = cp_model.NewBoolVar().WithName("b");
    // const BoolVar c = cp_model.NewBoolVar().WithName("c");

    let domain = new op.Domain(0, 10);
    let x = cp_model.NewIntVar(domain).WithName("x");
    let y = cp_model.NewIntVar(domain).WithName("y");
    let z = cp_model.NewIntVar(domain).WithName("z");
    let a = cp_model.NewBoolVar().WithName("a");
    let b = cp_model.NewBoolVar().WithName("b");
    let c = cp_model.NewBoolVar().WithName("c");

    // cp_model.AddGreaterThan(x, y).OnlyEnforceIf(a);
    // cp_model.AddGreaterThan(y, z).OnlyEnforceIf(b);
    // cp_model.AddGreaterThan(z, x).OnlyEnforceIf(c);
    cp_model.AddGreaterThan(x, y).OnlyEnforceIf(a);
    cp_model.AddGreaterThan(y, z).OnlyEnforceIf(b);
    cp_model.AddGreaterThan(z, x).OnlyEnforceIf(c);

    // cp_model.AddAssumptions({a, b, c});
    cp_model.AddAssumptions([a, b, c]);

    // const CpSolverResponse response = Solve(cp_model.Build());
    let response = op.sat.Solve(cp_model.Build());

    // LOG(INFO) << CpSolverResponseStats(response);
    // if (response.status() == CpSolverStatus::INFEASIBLE)
    // {
    //     for (const int index :
    //          response.sufficient_assumptions_for_infeasibility())
    //     {
    //         LOG(INFO) << index;
    //     }
    // }

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

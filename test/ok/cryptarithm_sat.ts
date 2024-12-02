import { operations_research as op } from '../../src'


function test()
{
    let cp_model = new op.sat.CpModelBuilder();
    let all_digits = new op.Domain(0, 9);
    let non_zero_digits = new op.Domain(1, 9);

    let s = cp_model.NewIntVar(non_zero_digits);
    let e = cp_model.NewIntVar(all_digits);
    let n = cp_model.NewIntVar(all_digits);
    let d = cp_model.NewIntVar(all_digits);

    let m = cp_model.NewIntVar(non_zero_digits);
    let o = cp_model.NewIntVar(all_digits);
    let r = cp_model.NewIntVar(all_digits);
    let y = cp_model.NewIntVar(all_digits);

    let c0 = cp_model.NewBoolVar();
    let c1 = cp_model.NewBoolVar();
    let c2 = cp_model.NewBoolVar();
    let c3 = cp_model.NewBoolVar();

    cp_model.AddAllDifferent([s, e, n, d, m, o, r, y]);

    cp_model.AddEquality(c0, m);

    let lexpr = op.sat.operator_plus(c1, s);
    lexpr = op.sat.operator_plus(lexpr, m);
    let rexpr = op.sat.operator_plus(o, op.sat.operator_times(10, c0))
    cp_model.AddEquality(lexpr, rexpr);

    lexpr = op.sat.operator_plus(c2, e);
    lexpr = op.sat.operator_plus(lexpr, o);
    rexpr = op.sat.operator_plus(n, op.sat.operator_times(10, c1))
    cp_model.AddEquality(lexpr, rexpr);

    lexpr = op.sat.operator_plus(c3, n);
    lexpr = op.sat.operator_plus(lexpr, r);
    rexpr = op.sat.operator_plus(e, op.sat.operator_times(10, c2))
    cp_model.AddEquality(lexpr, rexpr);

    lexpr = op.sat.operator_plus(d, e);
    rexpr = op.sat.operator_plus(y, op.sat.operator_times(10, c3))
    cp_model.AddEquality(lexpr, rexpr);

    let response = op.sat.Solve(cp_model.Build());
    console.log(op.sat.CpSolverResponseStats(response));
    console.log("s: " + op.sat.SolutionIntegerValue(response, s));
    console.log("e: " + op.sat.SolutionIntegerValue(response, e));
    console.log("n: " + op.sat.SolutionIntegerValue(response, n));
    console.log("d: " + op.sat.SolutionIntegerValue(response, d));
    console.log("m: " + op.sat.SolutionIntegerValue(response, m));
    console.log("o: " + op.sat.SolutionIntegerValue(response, o));
    console.log("r: " + op.sat.SolutionIntegerValue(response, r));
    console.log("y: " + op.sat.SolutionIntegerValue(response, y));
}
test();

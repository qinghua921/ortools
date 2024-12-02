import { operations_research as op } from '../../src'


function test()
{

    function MakeBaseLine4(s: op.Solver, v1: op.IntVar, v2: op.IntVar, v3: op.IntVar, v4: op.IntVar, base: number): op.IntVar
    {
        let tmp_vars = [v1, v2, v3, v4];
        let coefficients = [base * base * base, base * base, base, 1];
        return s.MakeScalProd(tmp_vars, coefficients).Var();
    }
    function MakeBaseLine3(s: op.Solver, v1: op.IntVar, v2: op.IntVar, v3: op.IntVar, base: number): op.IntVar
    {
        let tmp_vars = [v1, v2, v3];
        let coefficients = [base * base, base, 1];
        return s.MakeScalProd(tmp_vars, coefficients).Var();
    }
    function MakeBaseLine2(s: op.Solver, v1: op.IntVar, v2: op.IntVar, base: number): op.IntVar
    {
        const newLocal = s.MakeProd(v1, base);

        const newLocal_1 = s.MakeSum(newLocal, v2);
        console.log('eeeeeeeeeee');
        return newLocal_1.Var();
    }

    let solver = new op.Solver("CP is fun!");
    let kBase = 10;

    let c = solver.MakeIntVar(1, kBase - 1, "C");
    let p = solver.MakeIntVar(0, kBase - 1, "P");
    let i = solver.MakeIntVar(1, kBase - 1, "I");
    let s = solver.MakeIntVar(0, kBase - 1, "S");
    let f = solver.MakeIntVar(1, kBase - 1, "F");
    let u = solver.MakeIntVar(0, kBase - 1, "U");
    let n = solver.MakeIntVar(0, kBase - 1, "N");
    let t = solver.MakeIntVar(1, kBase - 1, "T");
    let r = solver.MakeIntVar(0, kBase - 1, "R");
    let e = solver.MakeIntVar(0, kBase - 1, "E");

    let letters = [c, p, i, s, f, u, n, t, r, e];


    solver.AddConstraint(solver.MakeAllDifferent(letters));

    let term1 = MakeBaseLine2(solver, c, p, kBase);
    let term2 = MakeBaseLine2(solver, i, s, kBase);
    let term3 = MakeBaseLine3(solver, f, u, n, kBase);
    let sum_terms = solver.MakeSum(solver.MakeSum(term1, term2), term3).Var();

    let sum = MakeBaseLine4(solver, t, r, u, e, kBase);
    solver.AddConstraint(solver.MakeEquality(sum_terms, sum));

    let num_solutions = 0;

    let db = solver.MakePhase(letters, op.Solver.CHOOSE_FIRST_UNBOUND, op.Solver.ASSIGN_MIN_VALUE);
    solver.NewSearch(db);
    while (solver.NextSolution())
    {
        console.log("C=" + c.Value() + " " + "P=" + p.Value() + " " + "I=" + i.Value() + " " + "S=" + s.Value() + " " + "F=" + f.Value() + " " + "U=" + u.Value() + " " + "N=" + n.Value() + " " + "T=" + t.Value() + " " + "R=" + r.Value() + " " + "E=" + e.Value());
        num_solutions++;
    }
    solver.EndSearch();
    console.log("Number of solutions found: " + num_solutions);

}
test();

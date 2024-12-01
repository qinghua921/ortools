import { operations_research as op } from '../../src'

function test()
{
    let solver = new op.Solver("ConstraintProgrammingExample");
    let numVals = 3;

    let x = solver.MakeIntVar(0, numVals - 1, "x");
    let y = solver.MakeIntVar(0, numVals - 1, "y");
    let z = solver.MakeIntVar(0, numVals - 1, "z");

    let xyvars = [x, y];
    solver.AddConstraint(solver.MakeAllDifferent(xyvars));
    console.log("Number of constraints: " + solver.constraints());

    let allvars = [x, y, z];
    let db = solver.MakePhase(
        allvars,
        op.Solver.IntVarStrategy.CHOOSE_FIRST_UNBOUND,
        op.Solver.IntValueStrategy.ASSIGN_MIN_VALUE);

    solver.NewSearch(db);
    while (solver.NextSolution())
    {
        console.log("Solution" + ": x = " + x.Value() + "; y = " + y.Value() + "; z = " + z.Value());
    }
    solver.EndSearch();
    console.log("Number of solutions: " + solver.solutions());
    console.log("");
    console.log("Advanced usage:");
    console.log("Problem solved in " + solver.wall_time() + "ms");
    console.log("Memory usage: " + op.Solver.MemoryUsage() + " bytes");

}
test();

import { operations_research as op } from '../../src'
function test()
{
    console.log("Google OR-Tools version : " + op.OrToolsVersion.VersionString());

    let solver = op.MPSolver.CreateSolver("GLOP");
    if (!solver)
    {
        console.log("Could not create solver GLOP");
        return;
    }
    let x = solver.MakeNumVar(0.0, 1, "x");
    let y = solver.MakeNumVar(0.0, 2, "y");
    console.log("Number of variables = " + solver.NumVariables());
    let infinity = op.MPSolver.infinity();
    let ct = solver.MakeRowConstraint(-infinity, 2.0, "ct");
    ct.SetCoefficient(x, 1);
    ct.SetCoefficient(y, 1);
    console.log("Number of constraints = " + solver.NumConstraints());
    let objective = solver.MutableObjective();
    objective.SetCoefficient(x, 3);
    objective.SetCoefficient(y, 1);
    objective.SetMaximization();

    console.log("Solving with " + solver.SolverVersion());
    let result_status = solver.Solve();
    console.log("Status: " + result_status);
    if (result_status != op.MPSolver.ResultStatus.OPTIMAL)
    {
        console.log("The problem does not have an optimal solution!");
        if (result_status == op.MPSolver.ResultStatus.FEASIBLE)
        {
            console.log("A potentially suboptimal solution was found");
        }
        else
        {
            console.log("The solver could not solve the problem.");
            return;
        }
    }
    console.log("Solution:");
    console.log("Objective value = " + objective.Value());
    console.log("x = " + x.solution_value());
    console.log("y = " + y.solution_value());
    console.log("Advanced usage:");
    console.log("Problem solved in " + solver.wall_time() + " milliseconds");
    console.log("Problem solved in " + solver.iterations() + " iterations");
}
test();

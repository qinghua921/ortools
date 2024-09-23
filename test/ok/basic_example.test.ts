import { operations_research } from "../../src";

test('ts-ortools', () =>
{
    console.log("Google OR-Tools version : " + operations_research.OrToolsVersion.VersionString())
    // Create the linear solver with the GLOP backend.
    const solver = operations_research.MPSolver.CreateSolver("GLOP");
    if (!solver)
    {
        console.log("Could not create solver GLOP");
        return;
    }

    // Create the variables x and y.
    const x = solver.MakeNumVar(0.0, 1, "x");
    const y = solver.MakeNumVar(0.0, 2, "y");
    console.log("Number of variables = " + solver.NumVariables());

    // Create a linear constraint, x + y <= 2.
    const infinity = operations_research.MPSolver.infinity();
    const ct = solver.MakeRowConstraint(-infinity, 2.0, "ct");
    ct.SetCoefficient(x, 1);
    ct.SetCoefficient(y, 1);
    console.log("Number of constraints = " + solver.NumConstraints());
    // Create the objective function, 3 * x + y.
    const objective = solver.MutableObjective();
    objective.SetCoefficient(x, 3);
    objective.SetCoefficient(y, 1);
    objective.SetMaximization();

    console.log("Solving with " + solver.SolverVersion());
    const result_status = solver.Solve();

    // Check that the problem has an optimal solution.
    console.log("Status: " + result_status);
    if (result_status !== operations_research.MPSolver.ResultStatus.OPTIMAL)
    {
        console.log("The problem does not have an optimal solution!");
        if (result_status === operations_research.MPSolver.ResultStatus.FEASIBLE)
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
});
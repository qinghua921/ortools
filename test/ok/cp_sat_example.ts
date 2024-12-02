import { operations_research as op } from '../../src'


function test()
{
    let cp_model = new op.sat.CpModelBuilder();
    let var_upper_bound = Math.max(50, 45, 37);
    let domain = new op.Domain(0, var_upper_bound);
    let x = cp_model.NewIntVar(domain).WithName("x");
    let y = cp_model.NewIntVar(domain).WithName("y");
    let z = cp_model.NewIntVar(domain).WithName("z");

    let expr = op.sat.operator_times(2, x)
    expr = op.sat.operator_plus(expr, op.sat.operator_times(7, y))
    expr = op.sat.operator_plus(expr, op.sat.operator_times(3, z))
    cp_model.AddLessOrEqual(expr, 50);

    expr = op.sat.operator_times(3, x)
    expr = op.sat.operator_minus(expr, op.sat.operator_times(5, y))
    expr = op.sat.operator_plus(expr, op.sat.operator_times(7, z))
    cp_model.AddLessOrEqual(expr, 45);

    expr = op.sat.operator_times(5, x)
    expr = op.sat.operator_plus(expr, op.sat.operator_times(2, y))
    expr = op.sat.operator_minus(expr, op.sat.operator_times(6, z))
    cp_model.AddLessOrEqual(expr, 37);

    expr = op.sat.operator_times(2, x)
    expr = op.sat.operator_plus(expr, op.sat.operator_times(2, y))
    expr = op.sat.operator_plus(expr, op.sat.operator_times(3, z))
    cp_model.Maximize(expr);

    let response = op.sat.Solve(cp_model.Build());

    if (response.status() == op.sat.CpSolverStatus.OPTIMAL ||
        response.status() == op.sat.CpSolverStatus.FEASIBLE)
    {
        console.log("Maximum of objective function: " + response.objective_value());
        console.log("x = " + op.sat.SolutionIntegerValue(response, x));
        console.log("y = " + op.sat.SolutionIntegerValue(response, y));
        console.log("z = " + op.sat.SolutionIntegerValue(response, z));
    } else
    {
        console.log("No solution found.");
    }

    console.log("Statistics");
    console.log(op.sat.CpSolverResponseStats(response));
}
test();

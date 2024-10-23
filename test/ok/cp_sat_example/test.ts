import { operations_research } from '../src'

function CpSatExample()
{
    const cp_model = new operations_research.sat.CpModelBuilder();
    const var_upper_bound = Math.max(50, 45, 37);
    const domain = new operations_research.Domain(0, var_upper_bound);
    const x = cp_model.NewIntVar(domain).WithName("x");
    const y = cp_model.NewIntVar(domain).WithName("y");
    const z = cp_model.NewIntVar(domain).WithName("z");

    cp_model.AddLessOrEqual(
        operations_research.sat.operator_plus(
            [operations_research.sat.operator_times(2, x),
            operations_research.sat.operator_times(7, y),
            operations_research.sat.operator_times(3, z)]
        ),
        50);
    cp_model.AddLessOrEqual(
        operations_research.sat.operator_plus(
            [operations_research.sat.operator_times(3, x),
            operations_research.sat.operator_times(-5, y),
            operations_research.sat.operator_times(7, z)])
        , 45);
    cp_model.AddLessOrEqual(
        operations_research.sat.operator_plus(
            [operations_research.sat.operator_times(5, x),
            operations_research.sat.operator_times(2, y),
            operations_research.sat.operator_times(-6, z)])
        , 37);
    cp_model.Maximize(
        operations_research.sat.operator_plus(
            [operations_research.sat.operator_times(2, x),
            operations_research.sat.operator_times(2, y),
            operations_research.sat.operator_times(3, z)])
    );

    const response = operations_research.sat.Solve(cp_model.Build());

    if (response.status() === operations_research.sat.CpSolverStatus.OPTIMAL ||
        response.status() === operations_research.sat.CpSolverStatus.FEASIBLE)
    {

        console.log("Maximum of objective function: " + response.objective_value());
        console.log("x = " + operations_research.sat.SolutionIntegerValue(response, x));
        console.log("y = " + operations_research.sat.SolutionIntegerValue(response, y));
        console.log("z = " + operations_research.sat.SolutionIntegerValue(response, z));
    } else
    {
        console.log("No solution found.");
    }

    console.log("Statistics");
    console.log(operations_research.sat.CpSolverResponseStats(response));
}

CpSatExample();

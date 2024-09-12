import { operations_research } from "../../src";

test('ts-ortools', async () =>
{
    let cp_model = new operations_research.sat.CpModelBuilder();
    const domain = new operations_research.Domain(0, 2);
    const x = cp_model.NewIntVar(domain).WithName("x")
    const y = cp_model.NewIntVar(domain).WithName("y")
    const z = cp_model.NewIntVar(domain).WithName("z")

    cp_model.AddNotEqual(x, y);
    cp_model.Maximize(
        operations_research.sat.operator_plus(
            x,
            operations_research.sat.operator_plus(
                operations_research.sat.operator_times(2, y),
                operations_research.sat.operator_times(3, z),
            ))
    );

    const initial_response = await operations_research.sat.Solve(cp_model.Build());
    console.log("Optimal value of the original model: " + initial_response.objective_value());

    const copy = new operations_research.sat.CpModelBuilder();
    copy.CopyFrom(cp_model.Proto());
    const copy_of_x = copy.GetIntVarFromProtoIndex(x.index());
    const copy_of_y = copy.GetIntVarFromProtoIndex(y.index());

    copy.AddLessOrEqual(
        operations_research.sat.operator_plus(copy_of_x, copy_of_y), 1);

    const modified_response = await operations_research.sat.Solve(copy.Build());
    console.log("Optimal value of the modified model: " + modified_response.objective_value());
});
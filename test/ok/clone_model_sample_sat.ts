import { operations_research as op } from '../../src'

function test()
{
    let cp_model = new op.sat.CpModelBuilder();
    const domain = new op.Domain(0, 2);
    const x = cp_model.NewIntVar(domain).WithName("x");
    const y = cp_model.NewIntVar(domain).WithName("y");
    const z = cp_model.NewIntVar(domain).WithName("z");

    cp_model.AddNotEqual(x, y);

    cp_model.Maximize(
        op.sat.operator_plus(
            op.sat.operator_plus(
                x, op.sat.operator_times(2, y)
            ),
            op.sat.operator_times(3, z))
    );

    const initial_response = op.sat.Solve(cp_model.Build());
    console.log("Optimal value of the original model: "
        + initial_response.objective_value());
    const copy = cp_model.Clone();
    const copy_of_x = copy.GetIntVarFromProtoIndex(x.index());
    const copy_of_y = copy.GetIntVarFromProtoIndex(y.index());
    copy.AddLessOrEqual(op.sat.operator_plus(copy_of_x, copy_of_y), 1);
    const modified_response = op.sat.Solve(copy.Build());
    console.log("Optimal value of the modified model: "
        + modified_response.objective_value());

}
test();

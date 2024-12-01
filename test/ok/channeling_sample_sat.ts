import { operations_research as op } from '../../src'

function test()
{
    let cp_model = new op.sat.CpModelBuilder();

    let x = cp_model.NewIntVar(new op.Domain(0, 10));
    let y = cp_model.NewIntVar(new op.Domain(0, 10));

    let b = cp_model.NewBoolVar();
    cp_model.AddGreaterOrEqual(x, 5).OnlyEnforceIf(b);
    cp_model.AddLessThan(x, 5).OnlyEnforceIf(b.Not());

    cp_model.AddEquality(op.sat.operator_plus(x, y), 10).OnlyEnforceIf(b);

    cp_model.AddEquality(y, 0).OnlyEnforceIf(b.Not());

    cp_model.AddDecisionStrategy([x], op.sat.DecisionStrategyProto.CHOOSE_FIRST, op.sat.DecisionStrategyProto.SELECT_MIN_VALUE);

    let model = new op.sat.Model();
    let parameters = new op.sat.SatParameters();
    parameters.set_search_branching(op.sat.SatParameters.FIXED_SEARCH);
    parameters.set_enumerate_all_solutions(true);
    model.Add(op.sat.NewSatParameters(parameters));
    model.Add(op.sat.NewFeasibleSolutionObserver((response) =>
    {
        console.log("x=" + op.sat.SolutionIntegerValue(response, x) + " y=" + op.sat.SolutionIntegerValue(response, y) + " b=" + op.sat.SolutionBooleanValue(response, b));
    }));

    op.sat.SolveCpModel(cp_model.Build(), model);
}
test();

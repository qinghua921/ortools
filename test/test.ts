import { operations_research as op } from '../src'

function test()
{
    // CpModelBuilder cp_model;

    // const IntVar x  = cp_model.NewIntVar({0, 10});
    // const IntVar y  = cp_model.NewIntVar({0, 10});

    // const BoolVar b = cp_model.NewBoolVar();

    // cp_model.AddGreaterOrEqual(x, 5).OnlyEnforceIf(b);
    // cp_model.AddLessThan(x, 5).OnlyEnforceIf(~b);

    // cp_model.AddEquality(x + y, 10).OnlyEnforceIf(b);

    // cp_model.AddEquality(y, 0).OnlyEnforceIf(~b);

    // cp_model.AddDecisionStrategy({x}, DecisionStrategyProto::CHOOSE_FIRST, DecisionStrategyProto::SELECT_MIN_VALUE);

    // Model model;
    // SatParameters parameters;
    // parameters.set_search_branching(SatParameters::FIXED_SEARCH);
    // parameters.set_enumerate_all_solutions(true);
    // model.Add(NewSatParameters(parameters));
    // model.Add(NewFeasibleSolutionObserver([&](const CpSolverResponse &r)
    //                                       { LOG(INFO) << "x=" << SolutionIntegerValue(r, x)
    //                                                   << " y=" << SolutionIntegerValue(r, y)
    //                                                   << " b=" << SolutionBooleanValue(r, b); }));
    // SolveCpModel(cp_model.Build(), &model);

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
    model.Add(new op.sat.NewSatParameters(parameters));
}
test();

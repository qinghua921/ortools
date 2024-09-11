import { operations_research } from "../src";
process.on('uncaughtException', (err) =>
{
    console.error('Unhandled Exception:', err);
    // 你可以选择终止进程或其他清理工作
    process.exit(1);
});

process.on('unhandledRejection', (reason, promise) =>
{
    console.error('Unhandled Rejection at:', promise, 'reason:', reason);
    // 你可以选择终止进程或其他清理工作
    process.exit(1);
});

test('assignment_groups_mip', async () =>
{
    const cp_model = new operations_research.sat.CpModelBuilder();


    const x = cp_model.NewIntVar(new operations_research.Domain(0, 10));
    const y = cp_model.NewIntVar(new operations_research.Domain(0, 10));
    const b = cp_model.NewBoolVar();

    cp_model.AddGreaterOrEqual(x, 5).OnlyEnforceIf(b);
    cp_model.AddLessThan(x, 5).OnlyEnforceIf(operations_research.sat.Not(b));

    cp_model.AddEquality(operations_research.sat.operator_plus(x, y), 10).OnlyEnforceIf(b);
    cp_model.AddEquality(y, 0).OnlyEnforceIf(operations_research.sat.Not(b));

    cp_model.AddDecisionStrategy([x],
        operations_research.sat.DecisionStrategyProto_VariableSelectionStrategy.CHOOSE_FIRST,
        operations_research.sat.DecisionStrategyProto_DomainReductionStrategy.SELECT_MIN_VALUE);

    const model = new operations_research.sat.Model();
    const parameters = new operations_research.sat.SatParameters();
    parameters.set_search_branching(operations_research.sat.SatParameters.SearchBranching.FIXED_SEARCH);
    parameters.set_enumerate_all_solutions(true);

    model.Add(operations_research.sat.NewFeasibleSolutionObserver(
        (response: operations_research.sat.CpSolverResponse) =>
        {
            console.log(`x=${operations_research.sat.SolutionIntegerValue(response, x)} ` +
                `y=${operations_research.sat.SolutionIntegerValue(response, y)} ` +
                `b=${operations_research.sat.SolutionBooleanValue(response, b)}`);
        }
    ));
    model.Add(operations_research.sat.NewSatParameters(parameters));

    let response = await operations_research.sat.SolveCpModel(cp_model.Build(), model);

    expect(response.status()).toBe(operations_research.sat.CpSolverStatus.OPTIMAL)
    console.log(`x=${operations_research.sat.SolutionIntegerValue(response, x)} ` +
        `y=${operations_research.sat.SolutionIntegerValue(response, y)} ` +
        `b=${operations_research.sat.SolutionBooleanValue(response, b)}`);
}, 10000000);
import { Domain } from "../tssrc/operations_research/Domain"
import { CpModelBuilder } from "../tssrc/operations_research/sat/CpModelBuilder"
import { NewFeasibleSolutionObserver, SolutionIntegerValue, NewSatParameters, SolveCpModel } from "../tssrc/operations_research/sat/Func"
import { Model } from "../tssrc/operations_research/sat/Model"
import { SatParameters } from "../tssrc/operations_research/sat/SatParameters"

test('001', async () =>
{
    let domain = Domain.FromValues([1, 3])

    expect(domain.FlattenedIntervals()).toStrictEqual([1, 1, 3, 3])
})

test('002', async () =>
{

    let moxing = new CpModelBuilder()
    let bianliang = moxing.NewIntVar(new Domain(1, 30))
    moxing.AddLinearConstraint(bianliang, Domain.FromValues([1, 4, 7, 88, 40]))

    let model = new Model('Model Name')

    let parameters = new SatParameters()
    parameters.set_enumerate_all_solutions(true);

    let all: number[] = []
    let fnModel = NewFeasibleSolutionObserver((d) =>
    {
        let x = SolutionIntegerValue(d, bianliang)
        all.push(x)
    })
    model.Add(fnModel)
    model.Add(NewSatParameters(parameters));
    await SolveCpModel(moxing.Build(), model)

    expect(all).toStrictEqual([1, 4, 7])


})


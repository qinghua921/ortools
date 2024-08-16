import { Domain } from "../tssrc/operations_research/Domain"
import { CpModelBuilder } from "../tssrc/operations_research/sat/CpModelBuilder"
import { NewFeasibleSolutionObserver, SolutionIntegerValue, NewSatParameters, SolveCpModel } from "../tssrc/operations_research/sat/Func"
import { Model } from "../tssrc/operations_research/sat/Model"
import { SatParameters } from "../tssrc/operations_research/sat/SatParameters"

(async () =>
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
        console.log(x);

        all.push(x)
    })
    model.Add(fnModel)
    model.Add(NewSatParameters(parameters));
    await SolveCpModel(moxing.Build(), model)



})().then((d) =>
{
    console.log(d);

})

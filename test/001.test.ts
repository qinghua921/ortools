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

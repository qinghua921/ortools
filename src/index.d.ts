import { MPSolver } from './operations_research/GMPSolver'
import { LinearExpr } from './operations_research/GLinearExpr'
import { operator_equals, operator_greater_equals, operator_less_equals } from './operations_research/GFunc'

export namespace operations_research
{
    export
    {
        operator_equals, operator_greater_equals, operator_less_equals,
        MPSolver,
        LinearExpr
    }
}
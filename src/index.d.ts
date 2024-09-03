import { MPSolver } from './operations_research/GMPSolver'
import { LinearExpr } from './operations_research/GLinearExpr'
import { operator_equals, operator_greater_equals, operator_less_equals } from './operations_research/GFunc'

import { CpModelBuilder } from './operations_research/sat/GCpModelBuilder'
import { BoolVar } from './operations_research/sat/GBoolVar'
import { IntVar } from './operations_research/sat/GIntVar'
import { LinearExpr as satLinearExpr } from './operations_research/sat/GLinearExpr'
import { TableConstraint } from './operations_research/sat/GTableConstraint'
import { operator_minus, operator_negate, operator_plus, operator_times } from './operations_research/sat/GFunc'

export namespace operations_research
{
    export
    {
        operator_equals, operator_greater_equals, operator_less_equals,
        MPSolver,
        LinearExpr
    }

    export namespace sat
    {
        export
        {
            CpModelBuilder,
            BoolVar,
            IntVar,
            satLinearExpr as LinearExpr,
            TableConstraint,
            operator_minus, operator_negate, operator_plus, operator_times
        }
    }
}
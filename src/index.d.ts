
/************************************************************************/

import
{
    operator_eq as operations_research_operator_eq,
    operator_ge as operations_research_operator_ge,
    operator_le as operations_research_operator_le,
} from "./operations_research/Func"
import
{
    LinearExpr as operations_research_LinearExpr,
    CanAsLinearExpr as operations_research_CanAsLinearExpr,
} from './operations_research/LinearExpr'
import { LinearRange as operations_research_LinearRange } from './operations_research/LinearRange'
import { MPConstraint as operations_research_MPConstraint } from './operations_research/MPConstraint'
import { MPObjective as operations_research_MPObjective } from './operations_research/MPObjective'
import { MPSolver as operations_research_MPSolver } from './operations_research/MPSolver'
import { MPVariable as operations_research_MPVariable } from './operations_research/MPVariable'

/************************************************************************/

import { BoolVar as operations_research_sat_BoolVar } from './operations_research/sat/BoolVar'
import { Constraint as operations_research_sat_Constraint } from './operations_research/sat/Constraint'
import { CpModelBuilder as operations_research_sat_CpModelBuilder } from './operations_research/sat/CpModelBuilder'
import { IntVar as operations_research_sat_IntVar } from './operations_research/sat/IntVar'
import
{
    LinearExpr as operations_research_sat_LinearExpr,
    CanAsLinearExpr as operations_research_sat_CanAsLinearExpr,
} from './operations_research/sat/LinearExpr'

export namespace operations_research
{
    export
    {
        operations_research_operator_eq as operator_eq,
        operations_research_operator_ge as operator_ge,
        operations_research_operator_le as operator_le,
        operations_research_LinearExpr as LinearExpr,
        operations_research_CanAsLinearExpr as CanAsLinearExpr,
        operations_research_LinearRange as LinearRange,
        operations_research_MPConstraint as MPConstraint,
        operations_research_MPObjective as MPObjective,
        operations_research_MPSolver as MPSolver,
        operations_research_MPVariable as MPVariable,
    }

    export namespace sat
    {
        export
        {
            operations_research_sat_BoolVar as BoolVar,
            operations_research_sat_Constraint as Constraint,
            operations_research_sat_CpModelBuilder as CpModelBuilder,
            operations_research_sat_IntVar as IntVar,
            operations_research_sat_LinearExpr as LinearExpr,
            operations_research_sat_CanAsLinearExpr as CanAsLinearExpr,
        }
    }
}

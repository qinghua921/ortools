/**** operations_research *******************************************************************************/

import { MPSolver as or_MPSolver } from './operations_research/MPSolver'
import { MPVariable as or_MPVariable } from './operations_research/MPVariable'
import { LinearExpr as or_LinearExpr } from './operations_research/LinearExpr'
import { MPConstraint as or_MPConstraint } from './operations_research/MPConstraint'
import { LinearRange as or_LinearRange } from './operations_research/LinearRange'
import { MPObjective as or_MPObjective } from './operations_research/MPObjective'
import
{
    operator_eq as or_operator_eq,
    operator_le as or_operator_le,
    operator_ge as or_operator_ge,
} from './operations_research/FuncInit'

/**** operations_research / sat *******************************************************************************/

import { CpModelBuilder as or_sat_CpModelBuilder } from './operations_research/sat/CpModelBuilder'
import { BoolVar as or_sat_BoolVar } from './operations_research/sat/BoolVar'
import { Constraint as or_sat_Constraint } from './operations_research/sat/Constraint'
import { LinearExpr as or_sat_LinearExpr } from './operations_research/sat/LinearExpr'

declare module operations_research
{
    export
    {
        or_MPSolver as MPSolver,
        or_MPVariable as MPVariable,
        or_LinearExpr as LinearExpr,
        or_MPConstraint as MPConstraint,
        or_LinearRange as LinearRange,
        or_MPObjective as MPObjective,
        or_operator_eq as operator_eq,
        or_operator_le as operator_le,
        or_operator_ge as operator_ge,
    }
    export namespace sat
    {
        export
        {
            or_sat_CpModelBuilder as CpModelBuilder,
            or_sat_BoolVar as BoolVar,
            or_sat_Constraint as Constraint,
            or_sat_LinearExpr as LinearExpr,
        }
    }
};

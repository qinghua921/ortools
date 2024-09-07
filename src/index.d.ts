import { MPSolver } from './operations_research/GMPSolver'
import { LinearExpr } from './operations_research/GLinearExpr'
import { SimpleLinearSumAssignment } from './operations_research/GSimpleLinearSumAssignment'
import { SimpleMinCostFlow } from './operations_research/GSimpleMinCostFlow'
import
{
    operator_equals,
    operator_greater_equals,
    operator_less_equals,
    operator_divide,
    operator_plus,
    operator_minus,
    operator_times,
} from './operations_research/GFunc'
import { Domain } from './operations_research/GDomain'
import { MPVariable } from './operations_research/GMPVariable'

import { CpModelBuilder } from './operations_research/sat/GCpModelBuilder'
import { BoolVar } from './operations_research/sat/GBoolVar'
import { IntVar } from './operations_research/sat/GIntVar'
import { LinearExpr as satLinearExpr } from './operations_research/sat/GLinearExpr'
import { TableConstraint } from './operations_research/sat/GTableConstraint'
import { CpSolverResponse } from './operations_research/sat/GCpSolverResponse'
import
{
    operator_minus,
    operator_negate,
    operator_plus,
    operator_times,
    Solve,
    SolutionIntegerValue,
    CpSolverResponseStats,
    SolutionBooleanValue,
} from './operations_research/sat/GFunc'
import { CpSolverStatus } from './operations_research/sat/GEnum'

import { Model } from './operations_research/math_opt/GModel'
import { GVariable } from './operations_research/math_opt/GVariable'
import { GLinearConstraint } from './operations_research/math_opt/GLinearConstraint'

export namespace operations_research
{
    export
    {
        operator_equals, operator_greater_equals, operator_less_equals,
        operator_divide, operator_plus, operator_minus, operator_times,
        MPSolver,
        LinearExpr,
        SimpleLinearSumAssignment,
        SimpleMinCostFlow,
        Domain,
        MPVariable,
    }

    export namespace math_opt
    {
        export
        {
            // TODO  math_opt
            // Model,
            // GVariable,
            // GLinearConstraint
        }
    }

    export namespace sat
    {
        export
        {
            CpSolverResponse,
            CpModelBuilder,
            BoolVar,
            IntVar,
            satLinearExpr as LinearExpr,
            TableConstraint,
            operator_minus,
            operator_negate,
            operator_plus,
            operator_times,
            Solve,
            SolutionIntegerValue,
            CpSolverStatus,
            CpSolverResponseStats,
            SolutionBooleanValue
        }
    }
}
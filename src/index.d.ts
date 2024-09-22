
/************************************************************************/

import { Domain as operations_research_Domain } from './operations_research/Domain'
import
{
    operator_eq as operations_research_operator_eq,
    operator_ge as operations_research_operator_ge,
    operator_le as operations_research_operator_le,
} from "./operations_research/Func"
import
{
    CanAsLinearExpr as operations_research_CanAsLinearExpr,
    LinearExpr as operations_research_LinearExpr,
} from './operations_research/LinearExpr'
import { LinearRange as operations_research_LinearRange } from './operations_research/LinearRange'
import { MPConstraint as operations_research_MPConstraint } from './operations_research/MPConstraint'
import { MPObjective as operations_research_MPObjective } from './operations_research/MPObjective'
import { MPSolver as operations_research_MPSolver } from './operations_research/MPSolver'
import { MPVariable as operations_research_MPVariable } from './operations_research/MPVariable'
import { SimpleLinearSumAssignment as operations_research_SimpleLinearSumAssignment } from './operations_research/SimpleLinearSumAssignment'
import { SimpleMinCostFlow as operations_research_SimpleMinCostFlow } from './operations_research/SimpleMinCostFlow'

/************************************************************************/

import { BoolVar as operations_research_sat_BoolVar } from './operations_research/sat/BoolVar'
import { Constraint as operations_research_sat_Constraint } from './operations_research/sat/Constraint'
import { CpModelBuilder as operations_research_sat_CpModelBuilder } from './operations_research/sat/CpModelBuilder'
import { CpModelProto as operations_research_sat_CpModelProto } from './operations_research/sat/CpModelProto'
import { CpSolverResponse as operations_research_sat_CpSolverResponse } from './operations_research/sat/CpSolverResponse'
import { CpSolverStatus as operations_research_sat_CpSolverStatus } from './operations_research/sat/Enum'
import
{
    Goperator_times as operations_research_sat_operator_times,
    GSolve as operations_research_sat_Solve
} from './operations_research/sat/Func'
import { IntVar as operations_research_sat_IntVar } from './operations_research/sat/IntVar'
import
{
    CanAsLinearExpr as operations_research_sat_CanAsLinearExpr,
    LinearExpr as operations_research_sat_LinearExpr,
} from './operations_research/sat/LinearExpr'
import { TableConstraint as operations_research_sat_TableConstraint } from './operations_research/sat/TableConstraint'

export namespace operations_research
{
    export
    {
        operations_research_Domain as Domain,
        
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
        operations_research_SimpleLinearSumAssignment as SimpleLinearSumAssignment,
        operations_research_SimpleMinCostFlow as SimpleMinCostFlow,
    }

    export namespace sat
    {
        export
        {
            operations_research_sat_BoolVar as BoolVar,
            operations_research_sat_Constraint as Constraint,
            operations_research_sat_CpModelBuilder as CpModelBuilder,
            operations_research_sat_CpModelProto as CpModelProto,
            operations_research_sat_CpSolverResponse as CpSolverResponse,

            operations_research_sat_CpSolverStatus as CpSolverStatus,

            operations_research_sat_operator_times as operator_times,
            operations_research_sat_Solve as Solve,

            operations_research_sat_IntVar as IntVar,
            operations_research_sat_LinearExpr as LinearExpr,
            operations_research_sat_CanAsLinearExpr as CanAsLinearExpr,
            operations_research_sat_TableConstraint as TableConstraint,
        }
    }
}

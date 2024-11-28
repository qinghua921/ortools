/**** operations_research *******************************************************************************/

import { MPSolver as or_MPSolver } from './operations_research/MPSolver'
import { MPVariable as or_MPVariable } from './operations_research/MPVariable'
import { LinearExpr as or_LinearExpr } from './operations_research/LinearExpr'
import { MPConstraint as or_MPConstraint } from './operations_research/MPConstraint'
import { LinearRange as or_LinearRange } from './operations_research/LinearRange'
import { MPObjective as or_MPObjective } from './operations_research/MPObjective'
import { SimpleLinearSumAssignment as or_SimpleLinearSumAssignment } from './operations_research/SimpleLinearSumAssignment'
import { SimpleMinCostFlow as or_SimpleMinCostFlow } from './operations_research/SimpleMinCostFlow'
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
import { IntVar as or_sat_IntVar } from './operations_research/sat/IntVar'
import { CpModelProto as or_sat_CpModelProto } from './operations_research/sat/CpModelProto'
import { CpSolverResponse as or_sat_CpSolverResponse } from './operations_research/sat/CpSolverResponse'
import { TableConstraint as or_sat_TableConstraint } from './operations_research/sat/TableConstraint'
import
{
    operator_times as or_sat_operator_times,
    Solve as or_sat_Solve,
    SolutionBooleanValue as or_sat_SolutionBooleanValue,
    CpSolverStatus as or_sat_CpSolverStatus,
} from './operations_research/sat/FuncInit'

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
        or_SimpleLinearSumAssignment as SimpleLinearSumAssignment,
        or_SimpleMinCostFlow as SimpleMinCostFlow,

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
            or_sat_IntVar as IntVar,
            or_sat_CpModelProto as CpModelProto,
            or_sat_CpSolverResponse as CpSolverResponse,
            or_sat_TableConstraint as TableConstraint,

            or_sat_operator_times as operator_times,
            or_sat_Solve as Solve,
            or_sat_SolutionBooleanValue as SolutionBooleanValue,

            or_sat_CpSolverStatus as CpSolverStatus,
        }
    }
};

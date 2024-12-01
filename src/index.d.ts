/**** operations_research *******************************************************************************/

import { MPSolver as or_MPSolver } from './operations_research/MPSolver'
import { MPVariable as or_MPVariable } from './operations_research/MPVariable'
import { LinearExpr as or_LinearExpr } from './operations_research/LinearExpr'
import { MPConstraint as or_MPConstraint } from './operations_research/MPConstraint'
import { LinearRange as or_LinearRange } from './operations_research/LinearRange'
import { MPObjective as or_MPObjective } from './operations_research/MPObjective'
import { SimpleLinearSumAssignment as or_SimpleLinearSumAssignment } from './operations_research/SimpleLinearSumAssignment'
import { SimpleMinCostFlow as or_SimpleMinCostFlow } from './operations_research/SimpleMinCostFlow'
import { Domain as or_Domain } from './operations_research/Domain'
import { OrToolsVersion as or_OrToolsVersion } from './operations_research/OrToolsVersion'
import { Solver as or_Solver } from './operations_research/Solver'
import { IntVar as or_IntVar } from './operations_research/IntVar'
import { Constraint as or_Constraint } from './operations_research/Constraint'
import { DecisionBuilder as or_DecisionBuilder } from './operations_research/DecisionBuilder'
import
{
    operator_eq as or_operator_eq,
    operator_le as or_operator_le,
    operator_ge as or_operator_ge,
    operator_times as or_operator_times,

} from './operations_research/FuncInit'

/**** operations_research / packing *******************************************************************************/

import { BinPacking2dParser as or_packing_BinPacking2dParser } from './operations_research/packing/BinPacking2dParser'
import { MultipleDimensionsBinPackingProblem as or_packing_MultipleDimensionsBinPackingProblem } from './operations_research/packing/MultipleDimensionsBinPackingProblem'
import { MultipleDimensionsBinPackingShape as or_packing_MultipleDimensionsBinPackingShape } from './operations_research/packing/MultipleDimensionsBinPackingShape'
import { MultipleDimensionsBinPackingItem as or_packing_MultipleDimensionsBinPackingItem } from './operations_research/packing/MultipleDimensionsBinPackingItem'

/**** operations_research / sat *******************************************************************************/

import { CpModelBuilder as or_sat_CpModelBuilder } from './operations_research/sat/CpModelBuilder'
import { BoolVar as or_sat_BoolVar } from './operations_research/sat/BoolVar'
import { Constraint as or_sat_Constraint } from './operations_research/sat/Constraint'
import { LinearExpr as or_sat_LinearExpr } from './operations_research/sat/LinearExpr'
import { IntVar as or_sat_IntVar } from './operations_research/sat/IntVar'
import { CpModelProto as or_sat_CpModelProto } from './operations_research/sat/CpModelProto'
import { CpSolverResponse as or_sat_CpSolverResponse } from './operations_research/sat/CpSolverResponse'
import { TableConstraint as or_sat_TableConstraint } from './operations_research/sat/TableConstraint'
import { IntervalVar as or_sat_IntervalVar } from './operations_research/sat/IntervalVar'
import { NoOverlap2DConstraint as or_sat_NoOverlap2DConstraint } from './operations_research/sat/NoOverlap2DConstraint'
import { SatParameters as or_sat_SatParameters } from './operations_research/sat/SatParameters'
import { DecisionStrategyProto as or_sat_DecisionStrategyProto } from './operations_research/sat/DecisionStrategyProto'
import { Model as or_sat_Model } from './operations_research/sat/Model'
import
{
    operator_times as or_sat_operator_times,
    Solve as or_sat_Solve,
    SolutionBooleanValue as or_sat_SolutionBooleanValue,
    CpSolverStatus as or_sat_CpSolverStatus,
    CpSolverResponseStats as or_sat_CpSolverResponseStats,
    SolveWithParameters as or_sat_SolveWithParameters,
    operator_plus as or_sat_operator_plus,
    NewSatParameters as or_sat_NewSatParameters,
    NewFeasibleSolutionObserver as or_sat_NewFeasibleSolutionObserver,
    SolutionIntegerValue as or_sat_SolutionIntegerValue,
    SolveCpModel as or_sat_SolveCpModel,
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
        or_Domain as Domain,
        or_OrToolsVersion as OrToolsVersion,
        or_Solver as Solver,
        or_IntVar as IntVar,
        or_Constraint as Constraint,
        or_DecisionBuilder as DecisionBuilder,

        or_operator_eq as operator_eq,
        or_operator_le as operator_le,
        or_operator_ge as operator_ge,
        or_operator_times as operator_times,

    }
    export namespace packing
    {
        export
        {
            or_packing_BinPacking2dParser as BinPacking2dParser,
            or_packing_MultipleDimensionsBinPackingProblem as MultipleDimensionsBinPackingProblem,
            or_packing_MultipleDimensionsBinPackingShape as MultipleDimensionsBinPackingShape,
            or_packing_MultipleDimensionsBinPackingItem as MultipleDimensionsBinPackingItem,
        }
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
            or_sat_IntervalVar as IntervalVar,
            or_sat_NoOverlap2DConstraint as NoOverlap2DConstraint,
            or_sat_SatParameters as SatParameters,
            or_sat_DecisionStrategyProto as DecisionStrategyProto,
            or_sat_Model as Model,

            or_sat_operator_times as operator_times,
            or_sat_Solve as Solve,
            or_sat_SolutionBooleanValue as SolutionBooleanValue,
            or_sat_CpSolverResponseStats as CpSolverResponseStats,
            or_sat_SolveWithParameters as SolveWithParameters,
            or_sat_operator_plus as operator_plus,
            or_sat_NewSatParameters as NewSatParameters,
            or_sat_NewFeasibleSolutionObserver as NewFeasibleSolutionObserver,
            or_sat_SolutionIntegerValue as SolutionIntegerValue,
            or_sat_SolveCpModel as SolveCpModel,

            or_sat_CpSolverStatus as CpSolverStatus,
        }
    }
};

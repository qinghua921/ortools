/***********************************************************************************
 * ./operations_research
 ***********************************************************************************/

import { MPSolver as operations_research_MPSolver } from './operations_research/GMPSolver'
import { LinearExpr as operations_research_LinearExpr } from './operations_research/GLinearExpr'
import { SimpleLinearSumAssignment as operations_research_SimpleLinearSumAssignment } from './operations_research/GSimpleLinearSumAssignment'
import { SimpleMinCostFlow as operations_research_SimpleMinCostFlow } from './operations_research/GSimpleMinCostFlow'
import
{
    operator_equals as operations_research_operator_equals,
    operator_greater_equals as operations_research_operator_greater_equals,
    operator_less_equals as operations_research_operator_less_equals,
    operator_divide as operations_research_operator_divide,
    operator_plus as operations_research_operator_plus,
    operator_minus as operations_research_operator_minus,
    operator_times as operations_research_operator_times,
} from './operations_research/GFunc'
import { Domain as operations_research_Domain } from './operations_research/GDomain'
import { MPVariable as operations_research_MPVariable } from './operations_research/GMPVariable'
import { Solver as operations_research_Solver } from './operations_research/GSolver'
import { IntVar as operations_research_IntVar } from './operations_research/GIntVar'
import { Constraint as operations_research_Constraint } from './operations_research/GConstraint'
import { DecisionBuilder as operations_research_DecisionBuilder } from './operations_research/GDecisionBuilder'
import { SequenceVar as operations_research_SequenceVar } from './operations_research/GSequenceVar'
import { IntervalVar as operations_research_IntervalVar } from './operations_research/GIntervalVar'
import { SearchMonitor as operations_research_SearchMonitor } from './operations_research/GSearchMonitor'

/***********************************************************************************
 * ./operations_research/sat
 ***********************************************************************************/

import { CpModelBuilder as operations_research_sat_CpModelBuilder } from './operations_research/sat/GCpModelBuilder'
import { BoolVar as operations_research_sat_BoolVar } from './operations_research/sat/GBoolVar'
import { IntVar as operations_research_sat_IntVar } from './operations_research/sat/GIntVar'
import { LinearExpr as operations_research_sat_LinearExpr } from './operations_research/sat/GLinearExpr'
import { TableConstraint as operations_research_sat_TableConstraint } from './operations_research/sat/GTableConstraint'
import { CpSolverResponse as operations_research_sat_CpSolverResponse } from './operations_research/sat/GCpSolverResponse'
import
{
    operator_minus as operations_research_sat_operator_minus,
    operator_negate as operations_research_sat_operator_negate,
    operator_plus as operations_research_sat_operator_plus,
    operator_times as operations_research_sat_operator_times,
    Solve as operations_research_sat_Solve,
    SolutionIntegerValue as operations_research_sat_SolutionIntegerValue,
    CpSolverResponseStats as operations_research_sat_CpSolverResponseStats,
    SolutionBooleanValue as operations_research_sat_SolutionBooleanValue,
    SolveWithParameters as operations_research_sat_SolveWithParameters,
    Not as operations_research_sat_Not,
    NewSatParameters as operations_research_sat_NewSatParameters,
    SolveCpModel as operations_research_sat_SolveCpModel,
    NewFeasibleSolutionObserver as operations_research_sat_NewFeasibleSolutionObserver,
} from './operations_research/sat/GFunc'
import
{
    DecisionStrategyProto_DomainReductionStrategy as operations_research_sat_DecisionStrategyProto_DomainReductionStrategy,
    DecisionStrategyProto_VariableSelectionStrategy as operations_research_sat_DecisionStrategyProto_VariableSelectionStrategy,
    CpSolverStatus as operations_research_sat_CpSolverStatus,
} from './operations_research/sat/GEnum'
import { IntervalVar as operations_research_sat_IntervalVar } from './operations_research/sat/GIntervalVar'
import { NoOverlap2DConstraint as operations_research_sat_NoOverlap2DConstraint } from './operations_research/sat/GNoOverlap2DConstraint'
import { SatParameters as operations_research_sat_SatParameters } from './operations_research/sat/GSatParameters'
import { Model as operations_research_sat_Model } from './operations_research/sat/GModel'

/***********************************************************************************
 * ./operations_research/math_opt
 ***********************************************************************************/

import { Model as operations_research_math_opt_Model } from './operations_research/math_opt/GModel'
import { GVariable as operations_research_math_opt_GVariable } from './operations_research/math_opt/GVariable'
import { GLinearConstraint as operations_research_math_opt_GLinearConstraint } from './operations_research/math_opt/GLinearConstraint'

/***********************************************************************************
 * ./operations_research/packing
 ***********************************************************************************/

import { BinPacking2dParser as operations_research_packing_BinPacking2dParser } from './operations_research/packing/GBinPacking2dParser'
import { MultipleDimensionsBinPackingProblem as operations_research_packing_MultipleDimensionsBinPackingProblem } from './operations_research/packing/GMultipleDimensionsBinPackingProblem'
import { MultipleDimensionsBinPackingShape as operations_research_packing_MultipleDimensionsBinPackingShape } from './operations_research/packing/GMultipleDimensionsBinPackingShape'
import { MultipleDimensionsBinPackingItem as operations_research_packing_MultipleDimensionsBinPackingItem } from './operations_research/packing/GMultipleDimensionsBinPackingItem'


export namespace operations_research
{
    export
    {
        operations_research_MPSolver as MPSolver,
        operations_research_LinearExpr as LinearExpr,
        operations_research_SimpleLinearSumAssignment as SimpleLinearSumAssignment,
        operations_research_SimpleMinCostFlow as SimpleMinCostFlow,
        operations_research_operator_equals as operator_equals,
        operations_research_operator_greater_equals as operator_greater_equals,
        operations_research_operator_less_equals as operator_less_equals,
        operations_research_operator_divide as operator_divide,
        operations_research_operator_plus as operator_plus,
        operations_research_operator_minus as operator_minus,
        operations_research_operator_times as operator_times,
        operations_research_Domain as Domain,
        operations_research_MPVariable as MPVariable,
        operations_research_Solver as Solver,
        operations_research_IntVar as IntVar,
        operations_research_Constraint as Constraint,
        operations_research_DecisionBuilder as DecisionBuilder,
        operations_research_SequenceVar as SequenceVar,
        operations_research_IntervalVar as IntervalVar,
        operations_research_SearchMonitor as SearchMonitor,
    }

    export namespace math_opt
    {
        export
        {
            // FIXME  math_opt
            // operations_research_math_opt_Model as Model,
            // operations_research_math_opt_GVariable as GVariable,
            // operations_research_math_opt_GLinearConstraint as GLinearConstraint,
        }
    }

    export namespace packing
    {
        export
        {
            operations_research_packing_BinPacking2dParser as BinPacking2dParser,
            operations_research_packing_MultipleDimensionsBinPackingProblem as MultipleDimensionsBinPackingProblem,
            operations_research_packing_MultipleDimensionsBinPackingShape as MultipleDimensionsBinPackingShape,
            operations_research_packing_MultipleDimensionsBinPackingItem as MultipleDimensionsBinPackingItem,
        }
    }

    export namespace sat
    {
        export
        {
            operations_research_sat_CpModelBuilder as CpModelBuilder,
            operations_research_sat_BoolVar as BoolVar,
            operations_research_sat_IntVar as IntVar,
            operations_research_sat_LinearExpr as LinearExpr,
            operations_research_sat_TableConstraint as TableConstraint,
            operations_research_sat_CpSolverResponse as CpSolverResponse,
            operations_research_sat_operator_minus as operator_minus,
            operations_research_sat_operator_negate as operator_negate,
            operations_research_sat_operator_plus as operator_plus,
            operations_research_sat_operator_times as operator_times,
            operations_research_sat_Solve as Solve,
            operations_research_sat_SolutionIntegerValue as SolutionIntegerValue,
            operations_research_sat_CpSolverResponseStats as CpSolverResponseStats,
            operations_research_sat_SolutionBooleanValue as SolutionBooleanValue,
            operations_research_sat_SolveWithParameters as SolveWithParameters,
            operations_research_sat_Not as Not,
            operations_research_sat_NewSatParameters as NewSatParameters,
            operations_research_sat_SolveCpModel as SolveCpModel,
            operations_research_sat_NewFeasibleSolutionObserver as NewFeasibleSolutionObserver,
            operations_research_sat_CpSolverStatus as CpSolverStatus,
            operations_research_sat_DecisionStrategyProto_DomainReductionStrategy as DecisionStrategyProto_DomainReductionStrategy,
            operations_research_sat_DecisionStrategyProto_VariableSelectionStrategy as DecisionStrategyProto_VariableSelectionStrategy,
            operations_research_sat_IntervalVar as IntervalVar,
            operations_research_sat_NoOverlap2DConstraint as NoOverlap2DConstraint,
            operations_research_sat_SatParameters as SatParameters,
            operations_research_sat_Model as Model,
        }
    }
}

/***********************************************************************************
 *  ./google/protobuf
 ***********************************************************************************/

import { RepeatedField_Int64 as google_protobuf_RepeatedField_Int64 } from './google/protobuf/GRepeatedField'

export namespace google
{
    export namespace protobuf
    {
        export
        {
            google_protobuf_RepeatedField_Int64 as RepeatedField_Int64,
        }
    }
}
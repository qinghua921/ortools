import { CanAsLinearExpr, ortools } from "../../nodeaddon"
import { CpModelProto } from "./CpModelProto"
import { CpSolverResponse } from "./CpSolverResponse"
import { Model } from "./Model"
import { SatParameters } from "./SatParameters"


/**  
 * 求解模型 
 */
export const Solve: (cpModelProto: CpModelProto) => Promise<CpSolverResponse>
    = ortools.operations_research.sat.Solve

/**
 * Solves the given CpModelProto.
 *
 * This advanced API accept a Model* which allows to access more adavanced
 * features by configuring some classes in the Model before solve.
 *
 * For instance:
 * - model->Add(NewSatParameters(parameters_as_string_or_proto));
 * - model->GetOrCreate<TimeLimit>()->RegisterExternalBooleanAsLimit(&stop);
 * - model->Add(NewFeasibleSolutionObserver(observer));
 */
export const SolveCpModel: (model_proto: CpModelProto, model: Model) => Promise<CpSolverResponse>
    = ortools.operations_research.sat.SolveCpModel

/**
 * Creates parameters for the solver, which you can add to the model with
 * \code
 * model->Add(NewSatParameters(parameters_as_string_or_proto))
 * \endcode
 * before calling \c SolveCpModel().
 */
export const NewSatParameters: (satParameters: SatParameters) => (model: Model) => SatParameters
    = ortools.operations_research.sat.NewSatParameters

/**
 * Creates a solution observer with the model with
 *   model.Add(NewFeasibleSolutionObserver([](response){...}));
 *
 * The given function will be called on each improving feasible solution found
 * during the search. For a non-optimization problem, if the option to find all
 * solution was set, then this will be called on each new solution.
 *
 * WARNING: Except when enumerate_all_solution() is true, one shouldn't rely on
 * this to get a set of "diverse" solutions since any future change to the
 * solver might completely kill any diversity in the set of solutions observed.
 *
 * Valid usage of this includes implementing features like:
 *  - Enumerating all solution via enumerate_all_solution(). If only n solutions
 *    are needed, this can also be used to abort when this number is reached.
 *  - Aborting early if a good enough solution is found.
 *  - Displaying log progress.
 *  - etc...
 */
export const NewFeasibleSolutionObserver: (func: (response: CpSolverResponse) => void) => (model: Model) => void
    = ortools.operations_research.sat.NewFeasibleSolutionObserver

/**
 * Returns a more readable and compact DebugString() than
 * proto.variables(index).DebugString(). This is used by IntVar::DebugString()
 * but also allow to get the same string from a const proto.
 */
export const VarDebugString: (proto: CpModelProto, index: number) => string
    = ortools.operations_research.sat.VarDebugString

/**
 * Returns a string with some statistics on the given CpModelProto.
 */
export const CpModelStats: (proto: CpModelProto) => string
    = ortools.operations_research.sat.CpModelStats

/**  
 * 计算结果中 线性表达式的值  
 */
export const SolutionIntegerValue: (cpSolverResponse: CpSolverResponse, linearExpr: CanAsLinearExpr) => number
    = ortools.operations_research.sat.SolutionIntegerValue

/** 
 * 获取结果中的统计信息
 */
export const CpSolverResponseStats: (cpSolverResponse: CpSolverResponse) => string
    = ortools.operations_research.sat.CpSolverResponseStats

export enum CpSolverStatus
{
    /**
     * 未知状态
     */
    UNKNOWN = 0,
    /**
     * 建模错误
     */
    MODEL_INVALID = 1,
    /**
     * 可行解
     */
    FEASIBLE = 2,
    /**
     * 无解
     */
    INFEASIBLE = 3,
    /**
     * 最优解
     */
    OPTIMAL = 4,
};

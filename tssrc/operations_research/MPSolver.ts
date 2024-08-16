import { ortools } from "../fuzhu"
import { MPConstraint } from "./MPConstraint"
import { MPObjective } from "./MPObjective"
import { MPVariable } from "./MPVariable"
import { ResultStatus } from "./ResultStatus"


/**
 * 创建数学问题并求解的主要类
 */
export interface MPSolver
{
    /**
     * 正无限. -MPSolver::infinity() 负无限.
     */
    infinity(): number

    /**
     * 创建连续型变量
     * @param lb 下限
     * @param ub 上限
     * @param name 名称
     */
    MakeNumVar(lb: number, ub: number, name: string): MPVariable

    /**
     * 创建整型变量
     * @param lb 下限
     * @param ub 上限
     * @param name 名称
     */
    MakeIntVar(lb: number, ub: number, name: string): MPVariable

    /**
     * 当前已经创建的变量个数
     */
    NumVariables(): number

    /**
     * 创建线性约束
     * @param lb 下线 
     * @param ub 上限
     */

    MakeRowConstraint(lb: number, ub: number): MPConstraint

    /**
     * 当前已经创建的约束个数
     */
    NumConstraints(): number

    /**
     * 创建目标函数
     */
    MutableObjective(): MPObjective

    /**
     * 求解
     */
    Solve(): Promise<ResultStatus>

    /**  DEPRECATED: Use DurationSinceConstruction() instead. */
    wall_time(): number

    /**
     * 返回单纯形迭代次数
     */
    iterations(): number

    /**
     * 获取模型名称
     */
    Name(): string

    /**
     * Returns the number of branch-and-bound nodes evaluated during the solve.
     * Only available for discrete problems.
     */
    nodes(): number
}


export const MPSolver: {

    /**
     * 创建 MPSolver
     * @param solver_id 类型
     */
    CreateSolver(solver_id:
        'CLP_LINEAR_PROGRAMMING'
        | 'CBC_MIXED_INTEGER_PROGRAMMING'
        | 'GLOP_LINEAR_PROGRAMMING'
        | 'BOP_INTEGER_PROGRAMMING'
        | 'SAT_INTEGER_PROGRAMMING'
        | 'SCIP_MIXED_INTEGER_PROGRAMMING'
        | 'GUROBI_LINEAR_PROGRAMMING'
        | 'GUROBI_MIXED_INTEGER_PROGRAMMING'
        | 'CPLEX_LINEAR_PROGRAMMING'
        | 'CPLEX_MIXED_INTEGER_PROGRAMMING'
        | 'XPRESS_LINEAR_PROGRAMMING'
        | 'XPRESS_MIXED_INTEGER_PROGRAMMING'
        | 'GLPK_LINEAR_PROGRAMMING'
        | 'GLPK_MIXED_INTEGER_PROGRAMMING'
    ): MPSolver

} = ortools.operations_research.MPSolver

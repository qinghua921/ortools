import { ortools } from "../fuzhu"
import { MPVariable } from "./MPVariable"


/**
 * 线性目标方程
 */
export interface MPObjective
{
    /**
     * 设定方程的变量的系数, 如果 variable 不属于 MPObjective 可能引起进程崩溃
     * @param variable 变量
     * @param fractional 系数
     */
    SetCoefficient(variable: MPVariable, fractional: number): void

    /**
     * 设定最小化优化
     */
    SetMinimization(): void

    /**
     * 设定最大化优化
     */
    SetMaximization(): void

    /**
     * Returns the objective value of the best solution found so far.
     *
     * It is the optimal objective value if the problem has been solved to optimality.
     *
     * Note: the objective value may be slightly different than what you could
     * compute yourself using MPVariable::solution_value(); 
     * 
     * please use the --verify_solution flag to gain confidence about the numerical stability of
     * your solution.
     */
    Value(): number
}

/**  FIXME  考虑 C++ 日志 返回到 JS */

export const MPObjective: {
} = ortools.operations_research.MPObjective

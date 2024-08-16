import { ortools } from "../nodeaddon"
import { MPVariable } from "./MPVariable"


/**
 * 线性约束 
 */
export interface MPConstraint
{
    /**
     * 设定方程的变量的系数, 如果 variable 不属于 MPConstraint 可能引起进程崩溃
     * @param variable 变量
     * @param fractional 系数
     */
    SetCoefficient(variable: MPVariable, fractional: number): void
}

export const MPConstraint: {
} = ortools.operations_research.MPConstraint
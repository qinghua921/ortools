import { ortools } from "../fuzhu"


/**
 * 变量, 针对  Mathematical Programming (MP) model
 */
export interface MPVariable
{
    /**
     * 获取当前解中该变量的值. 
     * 如果为整型变量, 则值为整数(底层使用浮点数求解, 返回最近的整数)
     */
    solution_value(): number

    /**
     * 获取变量名称
     */
    name(): string
}

export const MPVariable: {} = ortools.operations_research.MPVariable

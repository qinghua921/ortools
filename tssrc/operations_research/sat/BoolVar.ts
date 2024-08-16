import { ortools } from "../../fuzhu"


/**
 * Boolean 变量.
 *
 * 是 domain [0, 1] 的 IntVar, 只能使用 CpModelBuilder.NewBoolVar() 构造.
 */
export interface BoolVar
{
    /**
    * 设置名称
    */
    WithName(name: string): BoolVar

    DebugString(): string

    /**
     * Returns the index of the variable in the model.
     *
     * Warning: If the variable is the negation of another variable v, its index
     * is -v.index() - 1. So this can be negative.
     */
    index(): number

    /** Returns the logical negation of the current Boolean variable. */
    Not(): BoolVar
}
export const BoolVar: {} = ortools.operations_research.sat.BoolVar

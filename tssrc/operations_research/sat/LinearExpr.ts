import { CanAsLinearExpr, ortools } from "../../fuzhu"
import { BoolVar } from "./BoolVar"
import { CpModelProto } from "./CpModelProto"
import { IntVar } from "./IntVar"



/**
 * 线性表达式.
 *
 * Note that Not(x) will be silently transformed into 1 - x when added to the linear expression. 
 * BoolVar b = model.NewBoolVar().WithName("b");
 * LinearExpr e5 = b.Not();  // 1 - b.
*/
export interface LinearExpr
{
    /**  表达式为常量 */
    IsConstant(): boolean

    /**
     * Debug string. If the CpModelBuilder is passed, the string will include
     * variable names and domains. Otherwise, you will get a shorter string with
     * only variable indices.
     */
    DebugString(proto: CpModelProto): string

    Plus(other: CanAsLinearExpr): LinearExpr

    Minus(other: CanAsLinearExpr): LinearExpr

    Multi(other: number): LinearExpr
}

export const LinearExpr:
    {
        /**  vars, coeffs 的点积表达式 */
        WeightedSum(vars: IntVar[] | BoolVar[], coeffs: number[]): LinearExpr,

        /**  left * right */
        NumberLinearExprMult(left: number, right: CanAsLinearExpr): LinearExpr

        /**  left + right */
        LinearExprPlus(left: CanAsLinearExpr, right: CanAsLinearExpr): LinearExpr

        /** Constructs var * coefficient. */
        Term(var_: IntVar | BoolVar, coefficient: number): LinearExpr

        /**  创建常量表达式 0 */
        new(): LinearExpr,

        /**  创建 bool 表达式 */
        new(b: boolean): LinearExpr,

        /**  创建常量表达式 n  */
        new(n: number): LinearExpr,

        /**  创建整型表达式 */
        new(v: IntVar): LinearExpr,
    } = ortools.operations_research.sat.LinearExpr

import { ortools } from "../../nodeaddon"
import { BoolVar } from "./BoolVar"



/**
 * 约束, 必须使用 CpModelBuilder::AddXXX 构建
 */
export interface Constraint
{
    /**
     * 设置名称
     */
    WithName(name: string): Constraint

    /**
     * 获取名称
     */
    Name(): string

    /**
     * The constraint will be enforced iff all literals listed here are true.
     *
     * If this is empty, then the constraint will always be enforced. An enforced
     * constraint must be satisfied, and an un-enforced one will simply be
     * ignored.
     *
     * This is also called half-reification. To have an equivalence between a
     * literal and a constraint (full reification), one must add both a constraint
     * (controlled by a literal l) and its negation (controlled by the negation of
     * l).
     *
     * [Important] currently, only a few constraints support enforcement:
     * - bool_or, bool_and, linear: fully supported.
     * - interval: only support a single enforcement literal.
     * - other: no support (but can be added on a per-demand basis).
     */
    OnlyEnforceIf(boolVar: BoolVar | BoolVar[]): Constraint
}

export const Constraint: {} = ortools.operations_research.sat.Constraint

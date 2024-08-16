import { ortools } from "../../fuzhu";

/**
 * Represents a Interval variable.
 *
 * An interval variable is both a constraint and a variable. It is defined by
 * three objects: start, size, and end. All three can be an integer variable, a
 * constant, or an affine expression.
 *
 * It is a constraint because, internally, it enforces that start + size == end.
 *
 * It is also a variable as it can appear in specific scheduling constraints:
 * NoOverlap, NoOverlap2D, Cumulative.
 *
 * Optionally, a presence literal can be added to this constraint. This presence
 * literal is understood by the same constraints. These constraints ignore
 * interval variables with precence literals assigned to false. Conversely,
 * these constraints will also set these presence literals to false if they
 * cannot fit these intervals into the schedule.
 *
 * It can only be constructed via \c CpModelBuilder.NewIntervalVar().
 */
export interface IntervalVar
{
    /** 设置名称 */
    WithName(name: string): IntervalVar

    /** Returns the index of the interval constraint in the model. */
    index(): number
}

export const IntervalVar: {} = ortools.operations_research.sat.IntervalVar

import { ortools } from "../../nodeaddon"


/**
 * Specialized assignment constraint.
 *
 * This constraint allows adding tuples to the allowed/forbidden assignment
 * constraint incrementally.
 */
export interface TableConstraint
{
    /**
     * Adds a tuple of possible values to the constraint.
     */
    AddTuple(tuple: number[]): void
}
export const TableConstraint: {} = ortools.operations_research.sat.TableConstraint

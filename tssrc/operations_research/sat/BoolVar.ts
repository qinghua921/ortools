import { ortools } from "../../nodeaddon"


/**
 * A Boolean variable.
 *
 * This class refer to an IntegerVariableProto with domain [0, 1] or to its
 * logical negation (Not). This is called a Boolean Literal in other context.
 *
 * This can only be constructed via \c CpModelBuilder.NewBoolVar().
 */
export interface BoolVar
{
    /**
     * Sets the name of the variable.
     * Note that this will always set the "positive" version of this Boolean.
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

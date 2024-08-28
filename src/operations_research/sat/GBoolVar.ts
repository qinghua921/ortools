import { ortools } from "../../addon";

/**
 * A Boolean variable.
 *
 * This class refer to an IntegerVariableProto with domain [0, 1] or to its
 * logical negation (Not). This is called a Boolean Literal in other context.
 *
 * This can only be constructed via \c CpModelBuilder.NewBoolVar().
 */
export interface GBoolVar 
{
    /**
     * Sets the name of the variable.
     * Note that this will always set the "positive" version of this Boolean.
     */
    WithName(name: string): GBoolVar;
}

export const GBoolVar:
    {
        /**
         * A default constructed BoolVar can be used to mean not defined yet.
         * However, it shouldn't be passed to any of the functions in this file.
         * Doing so will crash in debug mode and will result in an invalid model in
         * opt mode.
         */
        new(): GBoolVar;

    } = ortools.operations_research.sat.BoolVar;


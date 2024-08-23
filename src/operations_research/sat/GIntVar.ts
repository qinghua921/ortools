import { ortools } from "../../addon";

/**
 * An integer variable.
 *
 * This class wraps an IntegerVariableProto.
 * This can only be constructed via \c CpModelBuilder.NewIntVar().
 */
export interface IntVar { }

export const IntVar:
    {
        // A default constructed IntVar can be used to mean not defined yet.
        // However, it shouldn't be passed to any of the functions in this file.
        // Doing so will crash in debug mode and will result in an invalid model in
        // opt mode.
        new(): IntVar;

    } = ortools.operations_research.sat.IntVar;
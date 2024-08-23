import { ortools } from "../../addon";
import { BoolVar } from "./GBoolVar";

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

        // Cast BoolVar -> IntVar.
        // The IntVar will take the value 1 (when the bool is true) and 0 otherwise.
        //
        // Warning: If you construct an IntVar from a negated BoolVar, this might
        // create a new variable in the model. Otherwise this just point to the same
        // underlying variable.
        new(boolVar: BoolVar): IntVar;

    } = ortools.operations_research.sat.IntVar;
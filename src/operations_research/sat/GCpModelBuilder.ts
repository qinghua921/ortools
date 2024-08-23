import { ortools } from "../../addon";
import { BoolVar } from "./GBoolVar";
import { Constraint } from "./GConstraint";

/**
 * Wrapper class around the cp_model proto.
 *
 * This class provides two types of methods:
 *  - NewXXX to create integer, boolean, or interval variables.
 *  - AddXXX to create new constraints and add them to the model.
 */
export interface CpModelBuilder
{
    // Sets the name of the model.
    SetName(name: string): void;

    //     /// Creates an integer variable with the given domain.
    //     IntVar NewIntVar( const Domain& domain );

    // Creates a Boolean variable.
    NewBoolVar(): BoolVar;


    /// At most one literal is true. Sum literals <= 1.
    AddAtMostOne(literals: BoolVar[]): Constraint;
}

export const CpModelBuilder:
    {
        new(): CpModelBuilder
    } = ortools.operations_research.sat.CpModelBuilder;
import { ortools } from "../../addon";

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

    //     /// Creates a Boolean variable.
    //     BoolVar NewBoolVar();
}

export const CpModelBuilder: {} = ortools.operations_research.sat.CpModelBuilder;
import { Constraint } from "./GConstraint";

/**
 * Specialized assignment constraint.
 *
 * This constraint allows adding tuples to the allowed/forbidden assignment
 * constraint incrementally.
 */
export class TableConstraint  
{
    //     /// Adds a tuple of possible values to the constraint.
    //     void AddTuple( absl::Span< const int64_t > tuple );
    AddTuple(tuple: number[]): void;
}

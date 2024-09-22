/**
 * Specialized assignment constraint.
 *
 * This constraint allows adding tuples to the allowed/forbidden assignment
 * constraint incrementally.
 */
export class TableConstraint // : public Constraint
{
    /**
     * Adds a tuple of possible values to the constraint.
     *
     * C++ void AddTuple( absl::Span< const int64_t > tuple );
     */
    AddTuple(tuple: number[]): void;
};


/**
 * A constraint.
 *
 * This class enables you to modify the constraint that was previously added to
 * the model.
 *
 * The constraint must be built using the different \c CpModelBuilder::AddXXX
 * methods.
 */
export class Constraint
{
    //public:
    //    /**
    //     * The constraint will be enforced iff all literals listed here are true.
    //     *
    //     * If this is empty, then the constraint will always be enforced. An enforced
    //     * constraint must be satisfied, and an un-enforced one will simply be
    //     * ignored.
    //     *
    //     * This is also called half-reification. To have an equivalence between a
    //     * literal and a constraint (full reification), one must add both a constraint
    //     * (controlled by a literal l) and its negation (controlled by the negation of
    //     * l).
    //     *
    //     * [Important] currently, only a few constraints support enforcement:
    //     * - bool_or, bool_and, linear: fully supported.
    //     * - interval: only support a single enforcement literal.
    //     * - other: no support (but can be added on a per-demand basis).
    //     */
    //    Constraint OnlyEnforceIf( absl::Span< const BoolVar > literals );

    //    /// See OnlyEnforceIf(absl::Span<const BoolVar> literals).
    //    Constraint OnlyEnforceIf( BoolVar literal );

    //    /// Sets the name of the constraint.
    //    Constraint WithName( absl::string_view name );

    //    /// Returns the name of the constraint (or the empty string if not set).
    //    absl::string_view Name() const;

    //    /// Returns the underlying protobuf object (useful for testing).
    //    const ConstraintProto& Proto() const
    //    {
    //        return *proto_;
    //    }

    //    /// Returns the mutable underlying protobuf object (useful for model edition).
    //    ConstraintProto* MutableProto() const
    //    {
    //        return proto_;
    //    }

};

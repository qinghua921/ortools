import { BoolVar } from "./BoolVar";

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
    //  Constraint OnlyEnforceIf(absl::Span<const BoolVar> literals);

    OnlyEnforceIf(literals: BoolVar): Constraint;

    //  /// Sets the name of the constraint.
    //  Constraint WithName(absl::string_view name);

    //  /// Returns the name of the constraint (or the empty string if not set).
    //  absl::string_view Name() const;

    //  /// Returns the underlying protobuf object (useful for testing).
    //  const ConstraintProto &Proto() const
    //  {
    //      return *proto_;
    //  }

    //  /// Returns the mutable underlying protobuf object (useful for model edition).
    //  ConstraintProto *MutableProto() const
    //  {
    //      return proto_;
    //  }

    //protected:
    //  friend class CpModelBuilder;

    //  explicit Constraint(ConstraintProto *proto);

    //  ConstraintProto *proto_ = nullptr;
};

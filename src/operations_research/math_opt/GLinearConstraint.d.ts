// A value type that references a linear constraint from ModelStorage. Usually
// this type is passed by copy.
export class LinearConstraint
{
    // public:
    //  // The typed integer used for ids.
    //  using IdType = LinearConstraintId;

    //  inline LinearConstraint(const ModelStorage* storage, LinearConstraintId id);

    //  inline int64_t id() const;

    //  inline LinearConstraintId typed_id() const;
    //  inline const ModelStorage* storage() const;

    //  inline double lower_bound() const;
    //  inline double upper_bound() const;
    //  inline absl::string_view name() const;

    //  inline bool is_coefficient_nonzero(Variable variable) const;

    //  // Returns 0.0 if the variable is not used in the constraint.
    //  inline double coefficient(Variable variable) const;

    //  inline BoundedLinearExpression AsBoundedLinearExpression() const;

    //  // Returns a detailed string description of the contents of the constraint
    //  // (not its name, use `<<` for that instead).
    //  inline std::string ToString() const;

    //  friend inline bool operator==(const LinearConstraint& lhs,
    //                                const LinearConstraint& rhs);
    //  friend inline bool operator!=(const LinearConstraint& lhs,
    //                                const LinearConstraint& rhs);
    //  template <typename H>
    //  friend H AbslHashValue(H h, const LinearConstraint& linear_constraint);
    //  friend std::ostream& operator<<(std::ostream& ostr,
    //                                  const LinearConstraint& linear_constraint);

    // private:
    //  const ModelStorage* storage_;
    //  LinearConstraintId id_;
};

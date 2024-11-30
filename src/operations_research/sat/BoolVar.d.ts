export class BoolVar
{
    //public:
    //  /// A default constructed BoolVar can be used to mean not defined yet.
    //  /// However, it shouldn't be passed to any of the functions in this file.
    //  /// Doing so will crash in debug mode and will result in an invalid model in
    //  /// opt mode.
    //  BoolVar() = default;

    WithName(name: string): BoolVar;

    //  /// Returns the name of the variable.
    //  std::string Name() const;

    Not(): BoolVar;

    //  bool operator==(const BoolVar &other) const
    //  {
    //      return other.builder_ == builder_ && other.index_ == index_;
    //  }

    //  bool operator!=(const BoolVar &other) const
    //  {
    //      return other.builder_ != builder_ || other.index_ != index_;
    //  }


    //  std::string DebugString() const;

    //  /**
    //   * Returns the index of the variable in the model.
    //   *
    //   * Warning: If the variable is the negation of another variable v, its index
    //   * is -v.index() - 1. So this can be negative.
    //   */
    //  int index() const
    //  {
    //      return index_;
    //  }

    //private:
    //  friend class CircuitConstraint;
    //  friend class Constraint;
    //  friend class CpModelBuilder;
    //  friend class DoubleLinearExpr;
    //  friend class IntVar;
    //  friend class IntervalVar;
    //  friend class MultipleCircuitConstraint;
    //  friend class LinearExpr;
    //  friend class ReservoirConstraint;
    //  friend bool SolutionBooleanValue(const CpSolverResponse &r, BoolVar x);

    //  BoolVar(int index, CpModelBuilder *builder);

    //  CpModelBuilder *builder_ = nullptr;
    //  int index_               = std::numeric_limits<int32_t>::min();
};

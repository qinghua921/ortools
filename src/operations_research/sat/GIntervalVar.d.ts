
/**
 * Represents a Interval variable.
 *
 * An interval variable is both a constraint and a variable. It is defined by
 * three objects: start, size, and end. All three can be an integer variable, a
 * constant, or an affine expression.
 *
 * It is a constraint because, internally, it enforces that start + size == end.
 *
 * It is also a variable as it can appear in specific scheduling constraints:
 * NoOverlap, NoOverlap2D, Cumulative.
 *
 * Optionally, a presence literal can be added to this constraint. This presence
 * literal is understood by the same constraints. These constraints ignore
 * interval variables with precence literals assigned to false. Conversely,
 * these constraints will also set these presence literals to false if they
 * cannot fit these intervals into the schedule.
 *
 * It can only be constructed via \c CpModelBuilder.NewIntervalVar().
 */
export class IntervalVar
{
    // public:
    //  /// A default constructed IntervalVar can be used to mean not defined yet.
    //  /// However, it shouldn't be passed to any of the functions in this file.
    //  /// Doing so will crash in debug mode and will result in an invalid model in
    //  /// opt mode.
    //  IntervalVar();

    //  /// Sets the name of the variable.
    //  IntervalVar WithName(const std::string& name);

    //  /// Returns the name of the interval (or the empty string if not set).
    //  std::string Name() const;

    //  /// Returns the start linear expression. Note that this rebuilds the
    //  /// expression each time this method is called.
    //  LinearExpr StartExpr() const;

    //  /// Returns the size linear expression. Note that this rebuilds the
    //  /// expression each time this method is called.
    //  LinearExpr SizeExpr() const;

    //  /// Returns the end linear expression. Note that this rebuilds the
    //  /// expression each time this method is called.
    //  LinearExpr EndExpr() const;

    //  /**
    //   * Returns a BoolVar indicating the presence of this interval.
    //   *
    //   * It returns \c CpModelBuilder.TrueVar() if the interval is not optional.
    //   */
    //  BoolVar PresenceBoolVar() const;

    //  /// Equality test with another interval variable.
    //  bool operator==(const IntervalVar& other) const {
    //    return other.builder_ == builder_ && other.index_ == index_;
    //  }

    //  /// Difference test with another interval variable.
    //  bool operator!=(const IntervalVar& other) const {
    //    return other.builder_ != builder_ || other.index_ != index_;
    //  }

    //  /// Returns a debug string.
    //  std::string DebugString() const;

    //  /// Returns the index of the interval constraint in the model.
    //  int index() const { return index_; }

    // private:
    //  friend class CpModelBuilder;
    //  friend class CumulativeConstraint;
    //  friend class NoOverlap2DConstraint;
    //  friend std::ostream& operator<<(std::ostream& os, const IntervalVar& var);

    //  IntervalVar(int index, CpModelBuilder* builder);

    //  CpModelBuilder* builder_ = nullptr;
    //  int index_ = std::numeric_limits<int32_t>::min();
};

import { BoolVar } from "./BoolVar";
import { IntVar } from "./IntVar";

export type CanAsLinearExpr = IntVar | BoolVar | LinearExpr | number;

export class LinearExpr
{
    //public:
    //  /// Creates an empty linear expression with value zero.
    //  LinearExpr() = default;

    //  // NOLINTBEGIN(google-explicit-constructor)

    //  /// Constructs a linear expression from a Boolean variable.
    //  /// It deals with logical negation correctly.
    //  LinearExpr(BoolVar var);

    //  /// Constructs a linear expression from an integer variable.
    //  LinearExpr(IntVar var);

    //  /// Constructs a constant linear expression.
    //  LinearExpr(int64_t constant);

    //  // NOLINTEND(google-explicit-constructor)

    static Sum(vars: IntVar[] | BoolVar[]): LinearExpr;

    //  /// Constructs the scalar product of variables and coefficients.
    //  static LinearExpr WeightedSum(absl::Span<const IntVar> vars, absl::Span<const int64_t> coeffs);

    //  /// Constructs the scalar product of Boolean variables and coefficients.
    //  static LinearExpr WeightedSum(absl::Span<const BoolVar> vars, absl::Span<const int64_t> coeffs);

    //  /// Constructs var * coefficient.
    //  static LinearExpr Term(IntVar var, int64_t coefficient);

    //  /// Constructs bool * coefficient.
    //  static LinearExpr Term(BoolVar var, int64_t coefficient);

    //  /// Constructs a linear expr from its proto representation.
    //  static LinearExpr FromProto(const LinearExpressionProto &proto);

    operator_plus_eq(other: CanAsLinearExpr): LinearExpr;
    operator_plus_eq(other: BoolVar): LinearExpr;

    //  LinearExpr &operator-=(const LinearExpr &other);
    operator_times_eq(other: LinearExpr): LinearExpr;

    //  /// Returns the vector of variable indices.
    //  const std::vector<int> &variables() const
    //  {
    //      return variables_;
    //  }

    //  /// Returns the vector of coefficients.
    //  const std::vector<int64_t> &coefficients() const
    //  {
    //      return coefficients_;
    //  }

    //  /// Returns true if the expression has no variables.
    //  bool IsConstant() const
    //  {
    //      return variables_.empty();
    //  }

    //  /// Returns the constant term.
    //  int64_t constant() const
    //  {
    //      return constant_;
    //  }

    //  /**
    //   * Debug string. If the CpModelBuilder is passed, the string will include
    //   * variable names and domains. Otherwise, you will get a shorter string with
    //   * only variable indices.
    //   */
    //  std::string DebugString(const CpModelProto *proto = nullptr) const;

    //private:
    //  std::vector<int> variables_;
    //  std::vector<int64_t> coefficients_;
    //  int64_t constant_ = 0;
};

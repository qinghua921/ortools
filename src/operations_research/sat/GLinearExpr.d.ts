import { BoolVar } from "./GBoolVar";
import { IntVar } from "./GIntVar";

export type CanAsLinearExpr = LinearExpr | BoolVar | number | IntVar;

/**
 * A dedicated container for linear expressions.
 *
 * With the use of implicit constructors, it can accept integer values, Boolean
 * and Integer variables. Note that Not(x) will be silently transformed into 1 -
 * x when added to the linear expression. It also support operator overloads to
 * construct the linear expression naturally.
 *
 * Furthermore, static methods allow to construct a linear expression from sums
 * or scalar products.
 *
 * Usage:
 * \code
  CpModelBuilder cp_model;
  IntVar x = model.NewIntVar({0, 10}).WithName("x");
  IntVar y = model.NewIntVar({0, 10}).WithName("y");
  BoolVar b = model.NewBoolVar().WithName("b");
  BoolVar c = model.NewBoolVar().WithName("c");
  LinearExpr e1(x);  // Or e1 = x.
  LinearExpr e2 = x + y + 5;
  LinearExpr e3 = 2 * x - y;
  LinearExpr e4 = b;
  LinearExpr e5 = b.Not();  // 1 - b.
  std::vector<BoolVar> bools = {b, Not(c)};
  LinearExpr e6 = LinearExpr::Sum(bools);   // b + 1 - c;
  LinearExpr e7 = -3 * b + Not(c);  // -3 * b + 1 - c;
  \endcode
 *  This can be used implicitly in some of the CpModelBuilder methods.
 * \code
  cp_model.AddGreaterThan(x, 5);
  cp_model.AddEquality(x, y + 5);
  \endcode
  */
export class LinearExpr
{
  //   public:
  //       /// Creates an empty linear expression with value zero.
  //       LinearExpr() = default;
  constructor();

  //       // NOLINTBEGIN(google-explicit-constructor)

  //       /// Constructs a linear expression from a Boolean variable.
  //       /// It deals with logical negation correctly.
  //       LinearExpr( BoolVar var );

  //       /// Constructs a linear expression from an integer variable.
  //       LinearExpr( IntVar var );

  //       /// Constructs a constant linear expression.
  //       LinearExpr( int64_t constant );

  //       // NOLINTEND(google-explicit-constructor)

  //       /// Constructs the sum of a list of variables.
  //       static LinearExpr Sum( absl::Span< const IntVar > vars );

  //       /// Constructs the sum of a list of Boolean variables.
  //       static LinearExpr Sum( absl::Span< const BoolVar > vars );

  //       /// Constructs the scalar product of variables and coefficients.
  //       static LinearExpr WeightedSum( absl::Span< const IntVar >  vars,
  //                                      absl::Span< const int64_t > coeffs );

  //       /// Constructs the scalar product of Boolean variables and coefficients.
  //       static LinearExpr WeightedSum( absl::Span< const BoolVar > vars,
  //                                      absl::Span< const int64_t > coeffs );

  //       /// Constructs var * coefficient.
  //       static LinearExpr Term( IntVar var, int64_t coefficient );

  //       /// Constructs bool * coefficient.
  //       static LinearExpr Term( BoolVar var, int64_t coefficient );

  //       /// Constructs a linear expr from its proto representation.
  //       static LinearExpr FromProto( const LinearExpressionProto& proto );

  //       // Operators.
  //       LinearExpr& operator+=( const LinearExpr& other );
  operator_plus_equals(other: LinearExpr | BoolVar): LinearExpr;
  //       LinearExpr& operator-=( const LinearExpr& other );
  operator_minus_equals(other: LinearExpr): LinearExpr;
  //       LinearExpr& operator*=( int64_t factor );
  operator_times_equals(factor: number): LinearExpr;

  //       /// Returns the vector of variable indices.
  //       const std::vector< int >& variables() const
  //       {
  //           return variables_;
  //       }

  //       /// Returns the vector of coefficients.
  //       const std::vector< int64_t >& coefficients() const
  //       {
  //           return coefficients_;
  //       }

  //       /// Returns true if the expression has no variables.
  //       const bool IsConstant() const
  //       {
  //           return variables_.empty();
  //       }

  //       /// Returns the constant term.
  //       int64_t constant() const
  //       {
  //           return constant_;
  //       }

  //       /**
  //        * Debug string. If the CpModelBuilder is passed, the string will include
  //        * variable names and domains. Otherwise, you will get a shorter string with
  //        * only variable indices.
  //        */
  //       std::string DebugString( const CpModelProto* proto = nullptr ) const;
}

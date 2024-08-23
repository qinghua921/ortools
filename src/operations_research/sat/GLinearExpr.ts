import { ortools } from "../../addon";
import { BoolVar } from "./GBoolVar";
import { IntVar } from "./GIntVar";

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
export interface LinearExpr 
{
  //     LinearExpr& operator+=( const LinearExpr& other );
  operator_plus(other: LinearExpr | BoolVar): LinearExpr;

  //     LinearExpr& operator-=( const LinearExpr& other );
  operator_minus(other: LinearExpr | BoolVar): LinearExpr;

  //     LinearExpr& operator*=( int64_t factor );
  operator_times(factor: number): LinearExpr;
}

export const LinearExpr:
  {
    // Creates an empty linear expression with value zero.
    new(): LinearExpr;

    // Constructs a linear expression from a Boolean variable.
    // It deals with logical negation correctly.
    new(var_: BoolVar): LinearExpr;

    // Constructs a linear expression from an integer variable.
    new(var_: IntVar): LinearExpr;

    // Constructs a constant linear expression.
    new(constant: number): LinearExpr;

  } = ortools.operations_research.sat.LinearExpr;
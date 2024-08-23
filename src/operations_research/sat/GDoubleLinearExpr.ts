import { ortools } from "../../addon";


/**
 * A dedicated container for linear expressions with double coefficients.
 * This is currently only usable to define a floating point objective.
 *
 * Usage:
 * \code
  CpModelBuilder cp_model;
  IntVar x = model.NewIntVar({0, 10}).WithName("x");
  IntVar y = model.NewIntVar({0, 10}).WithName("y");
  BoolVar b = model.NewBoolVar().WithName("b");
  BoolVar c = model.NewBoolVar().WithName("c");
  DoubleLinearExpr e1(x);  // e1 = x.
  // e2 = x + y + 5
  DoubleLinearExpr e2 = DoubleLinearExpr::Sum({x, y}).AddConstant(5.0);
  // e3 = 2 * x - y
  DoubleLinearExpr e3 = DoubleLinearExpr::WeightedSum({x, y}, {2, -1});
  DoubleLinearExpr e4(b);  // e4 = b.
  DoubleLinearExpr e5(b.Not());  // e5 = 1 - b.
  // If passing a std::vector<BoolVar>, a specialized method must be called.
  std::vector<BoolVar> bools = {b, Not(c)};
  DoubleLinearExpr e6 = DoubleLinearExpr::Sum(bools);  // e6 = b + 1 - c;
  // e7 = -3.0 * b + 1.5 - 1.5 * c;
  DoubleLinearExpr e7 = DoubleLinearExpr::WeightedSum(bools, {-3.0, 1.5});
  \endcode
 *  This can be used in the objective definition.
 * \code
  // Minimize 3.4 * y + 5.2
  cp_model.Minimize(DoubleLinearExpr::Term(y, 3.4).AddConstant(5.2));
  \endcode
  */
export interface DoubleLinearExpr { }

export const DoubleLinearExpr: {} = ortools.operations_research.sat.DoubleLinearExpr;
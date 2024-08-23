import { ortools } from "../addon";
import { LinearExpr } from "./GLinearExpr";

/**
 * An expression of the form:
 *
 * \code lower_bound <= sum_{i in S} a_i*x_i <= upper_bound. \endcode
 * The sum is represented as a LinearExpr with offset 0.
 *
 * Must be added to model with
 * \code
   MPSolver::AddRowConstraint(const LinearRange& range,
                              const std::string& name);
   \endcode
 */
export interface LinearRange 
{
  //     double lower_bound() const
  lower_bound(): number;

  //     const LinearExpr& linear_expr() const
  linear_expr(): LinearExpr;

  //     double upper_bound() const
  upper_bound(): number;
}

export const LinearRange:
  {
    //     LinearRange()
    new(): LinearRange;

    /**
     * The bounds of the linear range are updated so that they include the offset
     * from "linear_expr", i.e., we form the range:
     * \code
       lower_bound - offset <= linear_expr - offset <= upper_bound - offset.
       \endcode
     */
    new(lower_bound: number, linear_expr: LinearExpr, upper_bound: number): LinearRange;

  } = ortools.operations_research.LinearRange;
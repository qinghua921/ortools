import { ortools } from "../nodeaddon";
import { MPVariable } from "./MPVariable";

/**
 * The class for constraints of a Mathematical Programming (MP) model.
 *
 * A constraint is represented as a linear equation or inequality.
 */
export interface MPConstraint
{
    /**
     * Sets the coefficient of the variable on the constraint.
     *
     * If the variable does not belong to the solver, the function just returns,
     * or crashes in non-opt mode.
     */
    SetCoefficient(ver: MPVariable, coeff: number): void;
}

export const MPConstraint: {} = ortools.operations_research.MPConstraint;

// class MPConstraint {
//     public:
//      /// Returns the name of the constraint.
//      const std::string& name() const { return name_; }

//      /// Clears all variables and coefficients. Does not clear the bounds.
//      void Clear();

//      /**
//       * Gets the coefficient of a given variable on the constraint (which is 0 if
//       * the variable does not appear in the constraint).
//       */
//      double GetCoefficient(const MPVariable* const var) const;

//      /**
//       * Returns a map from variables to their coefficients in the constraint.
//       *
//       * If a variable is not present in the map, then its coefficient is zero.
//       */
//      const absl::flat_hash_map<const MPVariable*, double>& terms() const {
//        return coefficients_;
//      }

//      /// Returns the lower bound.
//      double lb() const { return lb_; }

//      /// Returns the upper bound.
//      double ub() const { return ub_; }

//      /// Sets the lower bound.
//      void SetLB(double lb) { SetBounds(lb, ub_); }

//      /// Sets the upper bound.
//      void SetUB(double ub) { SetBounds(lb_, ub); }

//      /// Sets both the lower and upper bounds.
//      void SetBounds(double lb, double ub);

//      /// Advanced usage: returns true if the constraint is "lazy" (see below).
//      bool is_lazy() const { return is_lazy_; }

//      /**
//       * Advanced usage: sets the constraint "laziness".
//       *
//       * <em>This is only supported for SCIP and has no effect on other
//       * solvers.</em>
//       *
//       * When \b laziness is true, the constraint is only considered by the Linear
//       * Programming solver if its current solution violates the constraint. In this
//       * case, the constraint is definitively added to the problem. This may be
//       * useful in some MIP problems, and may have a dramatic impact on performance.
//       *
//       * For more info see: http://tinyurl.com/lazy-constraints.
//       */
//      void set_is_lazy(bool laziness) { is_lazy_ = laziness; }

//      const MPVariable* indicator_variable() const { return indicator_variable_; }
//      bool indicator_value() const { return indicator_value_; }

//      /// Returns the index of the constraint in the MPSolver::constraints_.
//      int index() const { return index_; }

//      /**
//       * Advanced usage: returns the dual value of the constraint in the current
//       * solution (only available for continuous problems).
//       */
//      double dual_value() const;

//      /**
//       * Advanced usage: returns the basis status of the constraint.
//       *
//       * It is only available for continuous problems).
//       *
//       * Note that if a constraint "linear_expression in [lb, ub]" is transformed
//       * into "linear_expression + slack = 0" with slack in [-ub, -lb], then this
//       * status is the same as the status of the slack variable with AT_UPPER_BOUND
//       * and AT_LOWER_BOUND swapped.
//       *
//       * @see MPSolver::BasisStatus.
//       */
//      MPSolver::BasisStatus basis_status() const;

//    };

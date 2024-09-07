import { MPVariable } from "./GMPVariable";

export type CanAsLinearExpr = LinearExpr | number | MPVariable

/**
 * LinearExpr models a quantity that is linear in the decision variables
 * (MPVariable) of an optimization problem, i.e.
 *
 * offset + sum_{i in S} a_i*x_i,
 *
 * where the a_i and offset are constants and the x_i are MPVariables. You can
 * use a LinearExpr "linear_expr" with an MPSolver "solver" to:
 *   * Set as the objective of your optimization problem, e.g.
 *
 *     solver.MutableObjective()->MaximizeLinearExpr(linear_expr);
 *
 *   * Create a constraint in your optimization, e.g.
 *
 *     solver.MakeRowConstraint(linear_expr1 <= linear_expr2);
 *
 *   * Get the value of the quantity after solving, e.g.
 *
 *     solver.Solve();
 *     linear_expr.SolutionValue();
 *
 * LinearExpr is allowed to delete variables with coefficient zero from the map,
 * but is not obligated to do so.
 */
export class LinearExpr
{
    //     LinearExpr();
    constructor();

    //     /// Possible implicit conversions are intentional.
    //     LinearExpr( double constant );  // NOLINT
    constructor(constant: number);

    //     /***
    //      * Possible implicit conversions are intentional.
    //      *
    //      * Warning: var is not owned.
    //      */
    //     LinearExpr( const MPVariable* var );  // NOLINT
    constructor(var_: MPVariable);

    //     /**
    //      * Returns 1-var.
    //      *
    //      * NOTE(user): if var is binary variable, this corresponds to the logical
    //      * negation of var.
    //      * Passing by value is intentional, see the discussion on binary ops.
    //      */
    //     static LinearExpr NotVar( LinearExpr var );

    //     LinearExpr& operator+=( const LinearExpr& rhs );
    operator_plus_equals(rhs: CanAsLinearExpr): LinearExpr;

    //     LinearExpr& operator-=( const LinearExpr& rhs );
    operator_minus_equals(rhs: LinearExpr): LinearExpr;

    //     LinearExpr& operator*=( double rhs );
    operator_times_equals(rhs: number): LinearExpr;

    //     LinearExpr& operator/=( double rhs );
    operator_divide_equals(rhs: number): LinearExpr;

    //     LinearExpr  operator-() const;
    operator_negate(): LinearExpr;

    //     double offset() const
    //     {
    //         return offset_;
    //     }
    //     const absl::flat_hash_map< const MPVariable*, double >& terms() const
    //     {
    //         return terms_;
    //     }

    //     /**
    //      * Evaluates the value of this expression at the solution found.
    //      *
    //      * It must be called only after calling MPSolver::Solve.
    //      */
    //     double SolutionValue() const;

    //     /**
    //      * A human readable representation of this. Variables will be printed in order
    //      * of lowest index first.
    //      */
    //     std::string ToString() const;

}

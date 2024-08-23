﻿import { ortools } from "../addon";
import { MPVariable } from "./GMPVariable";


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
export interface LinearExpr
{
    //     LinearExpr& operator+=( const LinearExpr& rhs );
    operator_plus(rhs: LinearExpr | MPVariable): LinearExpr;

    //     LinearExpr& operator-=( const LinearExpr& rhs );
    operator_minus(rhs: LinearExpr | MPVariable): LinearExpr;

    //     LinearExpr& operator*=( double rhs );
    operator_times(rhs: number): LinearExpr;

    //     LinearExpr& operator/=( double rhs );
    operator_divide(rhs: number): LinearExpr;

    //     LinearExpr  operator-() const;
    operator_negate(): LinearExpr;
}

export const LinearExpr:
    {
        new(): LinearExpr;

        // Possible implicit conversions are intentional.
        new(constant: number): LinearExpr;

        /***
         * Possible implicit conversions are intentional.
         *
         * Warning: var is not owned.
         */
        new(var_: MPVariable): LinearExpr;

    } = ortools.operations_research.LinearExpr;
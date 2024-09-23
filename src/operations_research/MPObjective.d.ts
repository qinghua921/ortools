import { MPVariable } from "./MPVariable";

/**
 * A class to express a linear objective.
 */
export class MPObjective
{
    //public:

    /**
     * Clears the offset, all variables and coefficients, and the optimization
     * direction.
     * 
     * C++ void Clear();
     */
    Clear(): void;

    /**
     * Sets the coefficient of the variable in the objective.
     *
     * If the variable does not belong to the solver, the function just returns,
     * or crashes in non-opt mode.
     * 
     * C++ void SetCoefficient( const MPVariable* var, double coeff );
     */
    SetCoefficient(var_: MPVariable, coeff: number): void;

    //    /**
    //     *  Gets the coefficient of a given variable in the objective
    //     *
    //     * It returns 0 if the variable does not appear in the objective).
    //     */
    //    double GetCoefficient( const MPVariable* var ) const;

    //    /**
    //     * Returns a map from variables to their coefficients in the objective.
    //     *
    //     * If a variable is not present in the map, then its coefficient is zero.
    //     */
    //    const absl::flat_hash_map< const MPVariable*, double >& terms() const
    //    {
    //        return coefficients_;
    //    }

    //    /// Sets the constant term in the objective.
    //    void SetOffset( double value );

    //    /// Gets the constant term in the objective.
    //    double offset() const
    //    {
    //        return offset_;
    //    }

    //    /**
    //     * Resets the current objective to take the value of linear_expr, and sets the
    //     * objective direction to maximize if "is_maximize", otherwise minimizes.
    //     */
    //    void OptimizeLinearExpr( const LinearExpr& linear_expr, bool is_maximization );

    //    /// Resets the current objective to maximize linear_expr.
    //    void MaximizeLinearExpr( const LinearExpr& linear_expr )
    //    {
    //        OptimizeLinearExpr( linear_expr, true );
    //    }

    //    /// Resets the current objective to minimize linear_expr.
    //    void MinimizeLinearExpr( const LinearExpr& linear_expr )
    /**
     * Resets the current objective to minimize linear_expr.
     * 
     * C++ void MinimizeLinearExpr( const LinearExpr& linear_expr );
     */
    MinimizeLinearExpr(linear_expr: LinearExpr): void;

    //    /// Adds linear_expr to the current objective, does not change the direction.
    //    void AddLinearExpr( const LinearExpr& linear_expr );

    //    /// Sets the optimization direction (maximize: true or minimize: false).
    //    void SetOptimizationDirection( bool maximize );

    /**
     * Sets the optimization direction to minimize.
     * 
     * C++ void SetMinimization();
     */
    SetMinimization(): void;

    //    /// Sets the optimization direction to maximize.
    //    void SetMaximization()
    //    {
    //        SetOptimizationDirection( true );
    //    }
    /**
     * Sets the optimization direction to maximize.
     * 
     * C++ void SetMaximization();
     */
    SetMaximization(): void;

    //    /// Is the optimization direction set to maximize?
    //    bool maximization() const;

    //    /// Is the optimization direction set to minimize?
    //    bool minimization() const;

    //    /**
    //     * Returns the objective value of the best solution found so far.
    //     *
    //     * It is the optimal objective value if the problem has been solved to
    //     * optimality.
    //     *
    //     * Note: the objective value may be slightly different than what you could
    //     * compute yourself using \c MPVariable::solution_value(); please use the
    //     * --verify_solution flag to gain confidence about the numerical stability of
    //     * your solution.
    //     */
    //    double Value() const;
    /**
     * Returns the objective value of the best solution found so far.
     *
     * It is the optimal objective value if the problem has been solved to
     * optimality.
     *
     * Note: the objective value may be slightly different than what you could
     * compute yourself using \c MPVariable::solution_value(); please use the
     * --verify_solution flag to gain confidence about the numerical stability of
     * your solution.
     * 
     * C++ double Value() const;
     */
    Value(): number;

    //    /**
    //     * Returns the best objective bound.
    //     *
    //     * In case of minimization, it is a lower bound on the objective value of the
    //     * optimal integer solution. Only available for discrete problems.
    //     */
    //    double BestBound() const;

};

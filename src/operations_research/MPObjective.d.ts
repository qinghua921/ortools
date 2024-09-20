declare namespace operations_research
{
    /**
     * A class to express a linear objective.
     */
    declare class MPObjective
    {
        // public:
        // #ifndef SWIG
        //     // This type is neither copyable nor movable.
        //     MPObjective( const MPObjective& )            = delete;
        //     MPObjective& operator=( const MPObjective& ) = delete;
        // #endif

        //     /**
        //      *  Clears the offset, all variables and coefficients, and the optimization
        //      * direction.
        //      */
        //     void Clear();

        //     /**
        //      * Sets the coefficient of the variable in the objective.
        //      *
        //      * If the variable does not belong to the solver, the function just returns,
        //      * or crashes in non-opt mode.
        //      */
        //     void SetCoefficient( const MPVariable* var, double coeff );

        //     /**
        //      *  Gets the coefficient of a given variable in the objective
        //      *
        //      * It returns 0 if the variable does not appear in the objective).
        //      */
        //     double GetCoefficient( const MPVariable* var ) const;

        //     /**
        //      * Returns a map from variables to their coefficients in the objective.
        //      *
        //      * If a variable is not present in the map, then its coefficient is zero.
        //      */
        //     const absl::flat_hash_map< const MPVariable*, double >& terms() const
        //     {
        //         return coefficients_;
        //     }

        //     /// Sets the constant term in the objective.
        //     void SetOffset( double value );

        //     /// Gets the constant term in the objective.
        //     double offset() const
        //     {
        //         return offset_;
        //     }

        //     /**
        //      * Resets the current objective to take the value of linear_expr, and sets the
        //      * objective direction to maximize if "is_maximize", otherwise minimizes.
        //      */
        //     void OptimizeLinearExpr( const LinearExpr& linear_expr, bool is_maximization );

        //     /// Resets the current objective to maximize linear_expr.
        //     void MaximizeLinearExpr( const LinearExpr& linear_expr )
        //     {
        //         OptimizeLinearExpr( linear_expr, true );
        //     }
        //     /// Resets the current objective to minimize linear_expr.
        //     void MinimizeLinearExpr( const LinearExpr& linear_expr )
        //     {
        //         OptimizeLinearExpr( linear_expr, false );
        //     }

        //     /// Adds linear_expr to the current objective, does not change the direction.
        //     void AddLinearExpr( const LinearExpr& linear_expr );

        //     /// Sets the optimization direction (maximize: true or minimize: false).
        //     void SetOptimizationDirection( bool maximize );

        //     /// Sets the optimization direction to minimize.
        //     void SetMinimization()
        //     {
        //         SetOptimizationDirection( false );
        //     }

        //     /// Sets the optimization direction to maximize.
        //     void SetMaximization()
        //     {
        //         SetOptimizationDirection( true );
        //     }

        //     /// Is the optimization direction set to maximize?
        //     bool maximization() const;

        //     /// Is the optimization direction set to minimize?
        //     bool minimization() const;

        //     /**
        //      * Returns the objective value of the best solution found so far.
        //      *
        //      * It is the optimal objective value if the problem has been solved to
        //      * optimality.
        //      *
        //      * Note: the objective value may be slightly different than what you could
        //      * compute yourself using \c MPVariable::solution_value(); please use the
        //      * --verify_solution flag to gain confidence about the numerical stability of
        //      * your solution.
        //      */
        //     double Value() const;

        //     /**
        //      * Returns the best objective bound.
        //      *
        //      * In case of minimization, it is a lower bound on the objective value of the
        //      * optimal integer solution. Only available for discrete problems.
        //      */
        //     double BestBound() const;

        // private:
        //     friend class MPSolver;
        //     friend class MPSolverInterface;
        //     friend class CBCInterface;
        //     friend class CLPInterface;
        //     friend class GLPKInterface;
        //     friend class SCIPInterface;
        //     friend class SLMInterface;
        //     friend class GurobiInterface;
        //     friend class CplexInterface;
        //     friend class XpressInterface;
        //     friend class GLOPInterface;
        //     friend class BopInterface;
        //     friend class SatInterface;
        //     friend class PdlpInterface;
        //     friend class HighsInterface;
        //     friend class KnapsackInterface;

        //     // Constructor. An objective points to a single MPSolverInterface
        //     // that is specified in the constructor. An objective cannot belong
        //     // to several models.
        //     // At construction, an MPObjective has no terms (which is equivalent
        //     // on having a coefficient of 0 for all variables), and an offset of 0.
        //     explicit MPObjective( MPSolverInterface* const interface_in )
        //         : interface_( interface_in ), coefficients_( 1 ), offset_( 0.0 ) {}

        //     MPSolverInterface* const interface_;

        //     // Mapping var -> coefficient.
        //     absl::flat_hash_map< const MPVariable*, double > coefficients_;
        //     // Constant term.
        //     double offset_;
    };

}
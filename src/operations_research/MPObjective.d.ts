import { LinearExpr } from "./LinearExpr";
import { MPVariable } from "./MPVariable";

/// A class to express a linear objective.
export class MPObjective
{
    //   public:
    // #ifndef SWIG
    //     // This type is neither copyable nor movable.
    //     MPObjective(const MPObjective &)            = delete;
    //     MPObjective &operator=(const MPObjective &) = delete;
    // #endif

    //     /**
    //      *  Clears the offset, all variables and coefficients, and the optimization
    //      * direction.
    //      */
    //     void Clear();

    SetCoefficient(var_: MPVariable, coeff: number): void;

    //     /**
    //      *  Gets the coefficient of a given variable in the objective
    //      *
    //      * It returns 0 if the variable does not appear in the objective).
    //      */
    //     double GetCoefficient(const MPVariable *var) const;

    //     /**
    //      * Returns a map from variables to their coefficients in the objective.
    //      *
    //      * If a variable is not present in the map, then its coefficient is zero.
    //      */
    //     const absl::flat_hash_map<const MPVariable *, double> &terms() const
    //     {
    //         return coefficients_;
    //     }

    //     /// Sets the constant term in the objective.
    //     void SetOffset(double value);

    //     /// Gets the constant term in the objective.
    //     double offset() const
    //     {
    //         return offset_;
    //     }

    //     /**
    //      * Resets the current objective to take the value of linear_expr, and sets the
    //      * objective direction to maximize if "is_maximize", otherwise minimizes.
    //      */
    //     void OptimizeLinearExpr(const LinearExpr &linear_expr, bool is_maximization);

    //     /// Resets the current objective to maximize linear_expr.
    //     void MaximizeLinearExpr(const LinearExpr &linear_expr)
    //     {
    //         OptimizeLinearExpr(linear_expr, true);
    //     }
    MinimizeLinearExpr(linear_expr: LinearExpr): void;

    //     /// Adds linear_expr to the current objective, does not change the direction.
    //     void AddLinearExpr(const LinearExpr &linear_expr);

    //     /// Sets the optimization direction (maximize: true or minimize: false).
    //     void SetOptimizationDirection(bool maximize);

    SetMinimization(): void;

    SetMaximization(): void;

    //     /// Is the optimization direction set to maximize?
    //     bool maximization() const;

    //     /// Is the optimization direction set to minimize?
    //     bool minimization() const;

    Value(): number;
    //     /**
    //      * Returns the best objective bound.
    //      *
    //      * In case of minimization, it is a lower bound on the objective value of the
    //      * optimal integer solution. Only available for discrete problems.
    //      */
    //     double BestBound() const;


};

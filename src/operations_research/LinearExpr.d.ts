import { MPVariable } from "./MPVariable";

export type CanAsLinearExpr = LinearExpr | number | MPVariable;

export class LinearExpr
{
    //   public:
    constructor();
    constructor(constant: number);
    constructor(var_: MPVariable);

    //     /**
    //      * Returns 1-var.
    //      *
    //      * NOTE(user): if var is binary variable, this corresponds to the logical
    //      * negation of var.
    //      * Passing by value is intentional, see the discussion on binary ops.
    //      */
    //     static LinearExpr NotVar(LinearExpr var);

    operator_plus_eq(rhs: LinearExpr): LinearExpr;
    operator_plus_eq(rhs: MPVariable): LinearExpr;
    //     LinearExpr &operator-=(const LinearExpr &rhs);
    //     LinearExpr &operator*=(double rhs);
    //     LinearExpr &operator/=(double rhs);
    //     LinearExpr operator-() const;

    //     double offset() const
    //     {
    //         return offset_;
    //     }
    //     const absl::flat_hash_map<const MPVariable *, double> &terms() const
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

    //   private:
    //     double offset_;
    //     absl::flat_hash_map<const MPVariable *, double> terms_;
};

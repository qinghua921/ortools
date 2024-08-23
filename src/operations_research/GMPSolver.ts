import { ortools } from '../addon'
import { LinearRange } from './GLinearRange'
import { MPConstraint } from './GMPConstraint'
import { MPObjective } from './GMPObjective'
import { MPSolverParameters } from './GMPSolverParameters'
import { MPVariable } from './GMPVariable'


/**
 * This mathematical programming (MP) solver class is the main class
 * though which users build and solve problems.
 */
export interface MPSolver
{
    /**
     * Creates a boolean variable.
     */
    MakeBoolVar(name: string): MPVariable

    /**
     * Creates a linear constraint with given bounds.
     *
     * Bounds can be finite or +/- MPSolver::infinity(). The MPSolver class
     * assumes ownership of the constraint.
     *
     * @return a pointer to the newly created constraint.
     */
    MakeRowConstraint(lb: number, ub: number): MPConstraint

    /**
     * Creates a constraint with -infinity and +infinity bounds.
     */
    MakeRowConstraint(): MPConstraint

    /**
     * Creates a named constraint with given bounds.
     */
    MakRowConstraint(lb: number, ub: number, name: string): MPConstraint

    /**
     * Creates a named constraint with -infinity and +infinity bounds. 
     */
    MakeRowConstraint(name: string): MPConstraint

    /**
     * Creates a constraint owned by MPSolver enforcing:
     *     range.lower_bound() <= range.linear_expr() <= range.upper_bound()
     */
    MakeRowConstraint(range: LinearRange): MPConstraint

    /**
     *  As above, but also names the constraint.
     */
    MakeRowConstraint(range: LinearRange, name: string): MPConstraint

    // Debugging: verify that the given MPVariable* belongs to this solver.
    OwnsVariable(var_: MPVariable): boolean

    /// Returns the mutable objective object.
    MutableObjective(): MPObjective;


    // Solves the problem using the default parameter values.
    Solve(): ResultStatus

    // Solves the problem using the specified parameter values.
    Solve(param: MPSolverParameters): ResultStatus
}

export const MPSolver:
    {

        // Create a solver with the given name and underlying solver backend.
        new(name: string, problem_type: OptimizationProblemType): MPSolver

        /**
         * Recommended factory method to create a MPSolver instance, especially in
         * non C++ languages.
         *
         * It returns a newly created solver instance if successful, or a nullptr
         * otherwise. This can occur if the relevant interface is not linked in, or if
         * a needed license is not accessible for commercial solvers.
         *
         * Ownership of the solver is passed on to the caller of this method.
         * It will accept both string names of the OptimizationProblemType enum, as
         * well as a short version (i.e. "SCIP_MIXED_INTEGER_PROGRAMMING" or "SCIP").
         *
         * solver_id is case insensitive, and the following names are supported:
         *   - CLP_LINEAR_PROGRAMMING or CLP
         *   - CBC_MIXED_INTEGER_PROGRAMMING or CBC
         *   - GLOP_LINEAR_PROGRAMMING or GLOP
         *   - BOP_INTEGER_PROGRAMMING or BOP
         *   - SAT_INTEGER_PROGRAMMING or SAT or CP_SAT
         *   - SCIP_MIXED_INTEGER_PROGRAMMING or SCIP
         *   - GUROBI_LINEAR_PROGRAMMING or GUROBI_LP
         *   - GUROBI_MIXED_INTEGER_PROGRAMMING or GUROBI or GUROBI_MIP
         *   - CPLEX_LINEAR_PROGRAMMING or CPLEX_LP
         *   - CPLEX_MIXED_INTEGER_PROGRAMMING or CPLEX or CPLEX_MIP
         *   - XPRESS_LINEAR_PROGRAMMING or XPRESS_LP
         *   - XPRESS_MIXED_INTEGER_PROGRAMMING or XPRESS or XPRESS_MIP
         *   - GLPK_LINEAR_PROGRAMMING or GLPK_LP
         *   - GLPK_MIXED_INTEGER_PROGRAMMING or GLPK or GLPK_MIP
         */
        CreateSolver: (solver_id:
            "CLP_LINEAR_PROGRAMMING" | "CLP" |
            "CBC_MIXED_INTEGER_PROGRAMMING" | "CBC" |
            "GLOP_LINEAR_PROGRAMMING" | "GLOP" |
            "BOP_INTEGER_PROGRAMMING" | "BOP" |
            "SAT_INTEGER_PROGRAMMING" | "SAT" | "CP_SAT" |
            "SCIP_MIXED_INTEGER_PROGRAMMING" | "SCIP" |
            "GUROBI_LINEAR_PROGRAMMING" | "GUROBI_LP" |
            "GUROBI_MIXED_INTEGER_PROGRAMMING" | "GUROBI" | "GUROBI_MIP" |
            "CPLEX_LINEAR_PROGRAMMING" | "CPLEX_LP" |
            "CPLEX_MIXED_INTEGER_PROGRAMMING" | "CPLEX_MIP" |
            "XPRESS_LINEAR_PROGRAMMING" | "XPRESS_LP" |
            "XPRESS_MIXED_INTEGER_PROGRAMMING" | "XPRESS" | "XPRESS_MIP" |
            "GLPK_LINEAR_PROGRAMMING" | "GLPK_LP" |
            "GLPK_MIXED_INTEGER_PROGRAMMING" | "GLPK" | "GLPK_MIP"
        ) => MPSolver

    } = ortools.operations_research.MPSolver


/**
 * The status of solving the problem. The straightforward translation to
 * homonymous enum values of MPSolverResponseStatus (see
 * ./linear_solver.proto) is guaranteed by ./enum_consistency_test.cc, you may
 * rely on it.
 */
export enum ResultStatus
{
    /// optimal.
    OPTIMAL,
    /// feasible, or stopped by limit.
    FEASIBLE,
    /// proven infeasible.
    INFEASIBLE,
    /// proven unbounded.
    UNBOUNDED,
    /// abnormal, i.e., error of some kind.
    ABNORMAL,
    /// the model is trivially invalid (NaN coefficients, etc).
    MODEL_INVALID,
    /// not been solved yet.
    NOT_SOLVED = 6
};

/**
 * The type of problems (LP or MIP) that will be solved and the underlying
 *  solver (GLOP, GLPK, CLP, CBC or SCIP) that will solve them. This must
 * remain consistent with MPModelRequest::OptimizationProblemType
 *  (take particular care of the open-source version).
 */
export enum OptimizationProblemType
{
    // Linear programming problems.
    // ----------------------------
    CLP_LINEAR_PROGRAMMING = 0,
    GLPK_LINEAR_PROGRAMMING = 1,
    GLOP_LINEAR_PROGRAMMING = 2,  // Recommended default value. Made in Google.
    // In-house linear programming solver based on the primal-dual hybrid
    // gradient method. Sometimes faster than Glop for medium-size problems and
    // scales to much larger problems than Glop.
    PDLP_LINEAR_PROGRAMMING = 8,
    HIGHS_LINEAR_PROGRAMMING = 15,

    // Integer programming problems.
    // -----------------------------
    // Recommended default value for MIP problems.
    SCIP_MIXED_INTEGER_PROGRAMMING = 3,
    GLPK_MIXED_INTEGER_PROGRAMMING = 4,
    CBC_MIXED_INTEGER_PROGRAMMING = 5,

    // Commercial software (need license).
    GUROBI_LINEAR_PROGRAMMING = 6,
    GUROBI_MIXED_INTEGER_PROGRAMMING = 7,
    CPLEX_LINEAR_PROGRAMMING = 10,
    CPLEX_MIXED_INTEGER_PROGRAMMING = 11,
    XPRESS_LINEAR_PROGRAMMING = 101,
    XPRESS_MIXED_INTEGER_PROGRAMMING = 102,
    HIGHS_MIXED_INTEGER_PROGRAMMING = 16,

    // Boolean optimization problem (requires only integer variables and works
    // best with only Boolean variables).
    BOP_INTEGER_PROGRAMMING = 12,

    // SAT based solver (requires only integer and Boolean variables).
    // If you pass it mixed integer problems, it will scale coefficients to
    // integer values, and solver continuous variables as integral variables.
    //
    // Recommended default value for pure integral problems problems.
    SAT_INTEGER_PROGRAMMING = 14,

    // Dedicated knapsack solvers.
    KNAPSACK_MIXED_INTEGER_PROGRAMMING = 13,
};

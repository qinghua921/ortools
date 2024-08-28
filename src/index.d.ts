﻿export namespace operations_research
{
    export namespace MPSolver
    {
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
        }

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
        }
    }

    /**
     * This mathematical programming (MP) solver class is the main class
     * though which users build and solve problems.
     */
    export class MPSolver
    {
        //     /// Create a solver with the given name and underlying solver backend.
        //     MPSolver( const std::string& name, OptimizationProblemType problem_type );
        //     virtual ~MPSolver();

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
         * 
         * C++: static MPSolver* CreateSolver( const std::string& solver_id );
         */
        static CreateSolver(solver_id:
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
        ): MPSolver;

        //     /**
        //      * Whether the given problem type is supported (this will depend on the
        //      * targets that you linked).
        //      */
        //     static bool SupportsProblemType( OptimizationProblemType problem_type );

        //     /**
        //      * Parses the name of the solver. Returns true if the solver type is
        //      * successfully parsed as one of the OptimizationProblemType.
        //      * See the documentation of CreateSolver() for the list of supported names.
        //      */
        //     static bool ParseSolverType( absl::string_view        solver_id,
        //                                  OptimizationProblemType* type );

        //     /**
        //      * Parses the name of the solver and returns the correct optimization type or
        //      * dies. Invariant: ParseSolverTypeOrDie(ToString(type)) = type.
        //      */
        //     static OptimizationProblemType ParseSolverTypeOrDie(
        //         const std::string& solver_id );

        //     bool IsMIP() const;

        //     /// Returns the name of the model set at construction.
        //     const std::string& Name() const
        //     {
        //         return name_;  // Set at construction.
        //     }

        //     /// Returns the optimization problem type set at construction.
        //     virtual OptimizationProblemType ProblemType() const
        //     {
        //         return problem_type_;  // Set at construction.
        //     }

        //     /**
        //      * Clears the objective (including the optimization direction), all variables
        //      * and constraints. All the other properties of the MPSolver (like the time
        //      * limit) are kept untouched.
        //      */
        //     void Clear();

        //     /// Returns the number of variables.
        //     int NumVariables() const
        //     {
        //         return variables_.size();
        //     }

        //     /**
        //      * Returns the array of variables handled by the MPSolver. (They are listed in
        //      * the order in which they were created.)
        //      */
        //     const std::vector< MPVariable* >& variables() const
        //     {
        //         return variables_;
        //     }

        //     /**
        //      * Returns the variable at position index.
        //      */
        //     MPVariable* variable( int index ) const
        //     {
        //         return variables_[ index ];
        //     }

        //     /**
        //      * Looks up a variable by name, and returns nullptr if it does not exist. The
        //      * first call has a O(n) complexity, as the variable name index is lazily
        //      * created upon first use. Will crash if variable names are not unique.
        //      */
        //     MPVariable* LookupVariableOrNull( const std::string& var_name ) const;

        //     /**
        //      * Creates a variable with the given bounds, integrality requirement and
        //      * name. Bounds can be finite or +/- MPSolver::infinity(). The MPSolver owns
        //      * the variable (i.e. the returned pointer is borrowed). Variable names are
        //      * optional. If you give an empty name, name() will auto-generate one for you
        //      * upon request.
        //      */
        //     MPVariable* MakeVar( double lb, double ub, bool integer,
        //                          const std::string& name );

        //     /// Creates a continuous variable.
        //     MPVariable* MakeNumVar( double lb, double ub, const std::string& name );

        //     /// Creates an integer variable.
        //     MPVariable* MakeIntVar( double lb, double ub, const std::string& name );

        /**
         * Creates a boolean variable.
         *  
         * C++: MPVariable* MakeBoolVar( const std::string& name );
         */
        MakeBoolVar(name: string): MPVariable;

        //     /**
        //      * Creates an array of variables. All variables created have the same bounds
        //      * and integrality requirement. If nb <= 0, no variables are created, the
        //      * function crashes in non-opt mode.
        //      *
        //      * @param nb the number of variables to create.
        //      * @param lb the lower bound of created variables
        //      * @param ub the upper bound of created variables
        //      * @param integer controls whether the created variables are continuous or
        //      * integral.
        //      * @param name_prefix the prefix of the variable names. Variables are named
        //      * name_prefix0, name_prefix1, ...
        //      * @param[out] vars the vector of variables to fill with variables.
        //      */
        //     void MakeVarArray( int nb, double lb, double ub, bool integer,
        //                        const std::string&          name_prefix,
        //                        std::vector< MPVariable* >* vars );

        //     /// Creates an array of continuous variables.
        //     void MakeNumVarArray( int nb, double lb, double ub, const std::string& name,
        //                           std::vector< MPVariable* >* vars );

        //     ///  Creates an array of integer variables.
        //     void MakeIntVarArray( int nb, double lb, double ub, const std::string& name,
        //                           std::vector< MPVariable* >* vars );

        //     /// Creates an array of boolean variables.
        //     void MakeBoolVarArray( int nb, const std::string& name,
        //                            std::vector< MPVariable* >* vars );

        //     /// Returns the number of constraints.
        //     int NumConstraints() const
        //     {
        //         return constraints_.size();
        //     }

        //     /**
        //      * Returns the array of constraints handled by the MPSolver.
        //      *
        //      * They are listed in the order in which they were created.
        //      */
        //     const std::vector< MPConstraint* >& constraints() const
        //     {
        //         return constraints_;
        //     }

        //     /** Returns the constraint at the given index. */
        //     MPConstraint* constraint( int index ) const
        //     {
        //         return constraints_[ index ];
        //     }

        //     /**
        //      *  Looks up a constraint by name, and returns nullptr if it does not exist.
        //      *
        //      * The first call has a O(n) complexity, as the constraint name index is
        //      * lazily created upon first use. Will crash if constraint names are not
        //      * unique.
        //      */
        //     MPConstraint* LookupConstraintOrNull(
        //         const std::string& constraint_name ) const;

        /**
         * Creates a linear constraint with given bounds.
         *
         * Bounds can be finite or +/- MPSolver::infinity(). The MPSolver class
         * assumes ownership of the constraint.
         * 
         * C++: MPConstraint* MakeRowConstraint( double lb, double ub );
         * 
         * @return a pointer to the newly created constraint.
         */
        MakeRowConstraint(lb: number, ub: number): MPConstraint;

        /**
         * Creates a constraint with -infinity and +infinity bounds.
         * 
         * C++: MPConstraint* MakeRowConstraint();
         */
        MakeRowConstraint(): MPConstraint;

        /**
         * Creates a named constraint with given bounds.
         * 
         * C++: MPConstraint* MakeRowConstraint( double lb, double ub, const std::string& name );
         */
        MakeRowConstraint(lb: number, ub: number, name: string): MPConstraint;

        /**
         * Creates a named constraint with -infinity and +infinity bounds.
         * 
         * C++: MPConstraint* MakeRowConstraint( const std::string& name );
         */
        MakeRowConstraint(name: string): MPConstraint;

        /**
         * Creates a constraint owned by MPSolver enforcing:
         *     range.lower_bound() <= range.linear_expr() <= range.upper_bound()
         * 
         * C++: MPConstraint* MakeRangeConstraint( const LinearRange& range );
         */
        MakeRowConstraint(range: LinearRange): MPConstraint;

        /**
         * As above, but also names the constraint.
         * 
         * C++: MPConstraint* MakeRowConstraint( const LinearRange& range, const std::string& name );
         */
        MakeRowConstraint(range: LinearRange, name: string): MPConstraint;

        //     /**
        //      * Returns the objective object.
        //      *
        //      * Note that the objective is owned by the solver, and is initialized to its
        //      * default value (see the MPObjective class below) at construction.
        //      */
        //     const MPObjective& Objective() const
        //     {
        //         return *objective_;
        //     }

        /**
         * Returns the mutable objective object.
         * 
         * C++: MPObjective* MutableObjective();
         */
        MutableObjective(): MPObjective;



        //     /// Solves the problem using the default parameter values.
        //     ResultStatus Solve();
        /**
         * Solves the problem using the default parameter values.
         * 
         * C++: ResultStatus Solve();
         */
        Solve(): MPSolver.ResultStatus;


        //     /// Solves the problem using the specified parameter values.
        //     ResultStatus Solve( const MPSolverParameters& param );
        /**
         * Solves the problem using the specified parameter values.
         * 
         * C++: ResultStatus Solve( const MPSolverParameters& param );
         */
        // Solve(param: MPSolverParameters): MPSolver.ResultStatus;

        //     /**
        //      * Writes the model using the solver internal write function.  Currently only
        //      * available for Gurobi.
        //      */
        //     void Write( const std::string& file_name );

        //     /**
        //      * Advanced usage: compute the "activities" of all constraints, which are the
        //      * sums of their linear terms. The activities are returned in the same order
        //      * as constraints(), which is the order in which constraints were added; but
        //      * you can also use MPConstraint::index() to get a constraint's index.
        //      */
        //     std::vector< double > ComputeConstraintActivities() const;

        //     /**
        //      * Advanced usage: Verifies the *correctness* of the solution.
        //      *
        //      * It verifies that all variables must be within their domains, all
        //      * constraints must be satisfied, and the reported objective value must be
        //      * accurate.
        //      *
        //      * Usage:
        //      * - This can only be called after Solve() was called.
        //      * - "tolerance" is interpreted as an absolute error threshold.
        //      * - For the objective value only, if the absolute error is too large,
        //      *   the tolerance is interpreted as a relative error threshold instead.
        //      * - If "log_errors" is true, every single violation will be logged.
        //      * - If "tolerance" is negative, it will be set to infinity().
        //      *
        //      * Most users should just set the --verify_solution flag and not bother using
        //      * this method directly.
        //      */
        //     bool VerifySolution( double tolerance, bool log_errors ) const;

        //     /**
        //      * Advanced usage: resets extracted model to solve from scratch.
        //      *
        //      * This won't reset the parameters that were set with
        //      * SetSolverSpecificParametersAsString() or set_time_limit() or even clear the
        //      * linear program. It will just make sure that next Solve() will be as if
        //      * everything was reconstructed from scratch.
        //      */
        //     void Reset();

        //     /** Interrupts the Solve() execution to terminate processing if possible.
        //      *
        //      * If the underlying interface supports interruption; it does that and returns
        //      * true regardless of whether there's an ongoing Solve() or not. The Solve()
        //      * call may still linger for a while depending on the conditions.  If
        //      * interruption is not supported; returns false and does nothing.
        //      * MPSolver::SolverTypeSupportsInterruption can be used to check if
        //      * interruption is supported for a given solver type.
        //      */
        //     bool InterruptSolve();

        //     /**
        //      * Loads model from protocol buffer.
        //      *
        //      * Returns MPSOLVER_MODEL_IS_VALID if the model is valid, and another status
        //      * otherwise (currently only MPSOLVER_MODEL_INVALID and MPSOLVER_INFEASIBLE).
        //      * If the model isn't valid, populates "error_message".
        //      */
        //     MPSolverResponseStatus LoadModelFromProto( const MPModelProto& input_model,
        //                                                std::string*        error_message );
        //     /**
        //      * Loads model from protocol buffer.
        //      *
        //      * The same as above, except that the loading keeps original variable and
        //      * constraint names. Caller should make sure that all variable names and
        //      * constraint names are unique, respectively.
        //      */
        //     MPSolverResponseStatus LoadModelFromProtoWithUniqueNamesOrDie(
        //         const MPModelProto& input_model, std::string* error_message );

        //     /// Encodes the current solution in a solution response protocol buffer.
        //     void FillSolutionResponseProto( MPSolutionResponse* response ) const;

        //     /**
        //      * Solves the model encoded by a MPModelRequest protocol buffer and fills the
        //      * solution encoded as a MPSolutionResponse. The solve is stopped prematurely
        //      * if interrupt is non-null at set to true during (or before) solving.
        //      * Interruption is only supported if SolverTypeSupportsInterruption() returns
        //      * true for the requested solver. Passing a non-null interruption with any
        //      * other solver type immediately returns an MPSOLVER_INCOMPATIBLE_OPTIONS
        //      * error.
        //      *
        //      * Note(user): This attempts to first use `DirectlySolveProto()` (if
        //      * implemented). Consequently, this most likely does *not* override any of
        //      * the default parameters of the underlying solver. This behavior *differs*
        //      * from `MPSolver::Solve()` which by default sets the feasibility tolerance
        //      * and the gap limit (as of 2020/02/11, to 1e-7 and 0.0001, respectively).
        //      */
        //     static void SolveWithProto( const MPModelRequest& model_request,
        //                                 MPSolutionResponse*   response,
        //                                 // `interrupt` is non-const because the internal
        //                                 // solver may set it to true itself, in some cases.
        //                                 std::atomic< bool >* interrupt = nullptr );

        //     static bool SolverTypeSupportsInterruption(
        //         const MPModelRequest::SolverType solver )
        //     {
        //         // Interruption requires that MPSolver::InterruptSolve is supported for the
        //         // underlying solver. Interrupting requests using SCIP is also not supported
        //         // as of 2021/08/23, since InterruptSolve is not go/thread-safe
        //         // for SCIP (see e.g. cl/350545631 for details).
        //         return solver == MPModelRequest::GLOP_LINEAR_PROGRAMMING || solver == MPModelRequest::GUROBI_LINEAR_PROGRAMMING || solver == MPModelRequest::GUROBI_MIXED_INTEGER_PROGRAMMING || solver == MPModelRequest::SAT_INTEGER_PROGRAMMING || solver == MPModelRequest::PDLP_LINEAR_PROGRAMMING;
        //     }

        //     /// Exports model to protocol buffer.
        //     void ExportModelToProto( MPModelProto* output_model ) const;

        //     /**
        //      * Load a solution encoded in a protocol buffer onto this solver for easy
        //     access via the MPSolver interface.
        //      *
        //      * IMPORTANT: This may only be used in conjunction with ExportModel(),
        //     following this example:
        //      *
        //      \code
        //        MPSolver my_solver;
        //        ... add variables and constraints ...
        //        MPModelProto model_proto;
        //        my_solver.ExportModelToProto(&model_proto);
        //        MPSolutionResponse solver_response;
        //        MPSolver::SolveWithProto(model_proto, &solver_response);
        //        if (solver_response.result_status() == MPSolutionResponse::OPTIMAL) {
        //          CHECK_OK(my_solver.LoadSolutionFromProto(solver_response));
        //          ... inspect the solution using the usual API: solution_value(), etc...
        //        }
        //     \endcode
        //      *
        //      * The response must be in OPTIMAL or FEASIBLE status.
        //      *
        //      * Returns a non-OK status if a problem arised (typically, if it wasn't used
        //      *     like it should be):
        //      * - loading a solution whose variables don't correspond to the solver's
        //      *   current variables
        //      * - loading a dual solution whose constraints don't correspond to the
        //      *   solver's current constraints
        //      * - loading a solution with a status other than OPTIMAL / FEASIBLE.
        //      *
        //      * Note: the objective value isn't checked. You can use VerifySolution() for
        //      *       that.
        //      */
        //     absl::Status LoadSolutionFromProto(
        //         const MPSolutionResponse& response,
        //         double                    tolerance = std::numeric_limits< double >::infinity() );

        //     /**
        //      * Resets values of out of bound variables to the corresponding bound and
        //      * returns an error if any of the variables have NaN value.
        //      */
        //     absl::Status ClampSolutionWithinBounds();

        //     /**
        //      * Shortcuts to the homonymous MPModelProtoExporter methods, via exporting to
        //      * a MPModelProto with ExportModelToProto() (see above).
        //      *
        //      * Produces empty std::string on portable platforms (e.g. android, ios).
        //      */
        //     bool ExportModelAsLpFormat( bool obfuscate, std::string* model_str ) const;
        //     bool ExportModelAsMpsFormat( bool fixed_format, bool obfuscate,
        //                                  std::string* model_str ) const;

        //     /**
        //      *  Sets the number of threads to use by the underlying solver.
        //      *
        //      * Returns OkStatus if the operation was successful. num_threads must be equal
        //      * to or greater than 1. Note that the behaviour of this call depends on the
        //      * underlying solver. E.g., it may set the exact number of threads or the max
        //      * number of threads (check the solver's interface implementation for
        //      * details). Also, some solvers may not (yet) support this function, but still
        //      * enable multi-threading via SetSolverSpecificParametersAsString().
        //      */
        //     absl::Status SetNumThreads( int num_threads );

        //     /// Returns the number of threads to be used during solve.
        //     int GetNumThreads() const
        //     {
        //         return num_threads_;
        //     }

        //     /**
        //      * Advanced usage: pass solver specific parameters in text format.
        //      *
        //      * The format is solver-specific and is the same as the corresponding solver
        //      * configuration file format. Returns true if the operation was successful.
        //      */
        //     bool        SetSolverSpecificParametersAsString( const std::string& parameters );
        //     std::string GetSolverSpecificParametersAsString() const
        //     {
        //         return solver_specific_parameter_string_;
        //     }

        //     /**
        //      * Sets a hint for solution.
        //      *
        //      * If a feasible or almost-feasible solution to the problem is already known,
        //      * it may be helpful to pass it to the solver so that it can be used. A solver
        //      * that supports this feature will try to use this information to create its
        //      * initial feasible solution.
        //      *
        //      * Note: It may not always be faster to give a hint like this to the
        //      * solver. There is also no guarantee that the solver will use this hint or
        //      * try to return a solution "close" to this assignment in case of multiple
        //      * optimal solutions.
        //      *
        //      * Calling SetHint clears all previous hints.
        //      */
        //     void SetHint( std::vector< std::pair< const MPVariable*, double > > hint );

        //     /**
        //      * Advanced usage: possible basis status values for a variable and the slack
        //      * variable of a linear constraint.
        //      */
        //     enum BasisStatus
        //     {
        //         FREE = 0,
        //         AT_LOWER_BOUND,
        //         AT_UPPER_BOUND,
        //         FIXED_VALUE,
        //         BASIC
        //     };

        //     /**
        //      * Advanced usage: Incrementality.
        //      *
        //      * This function takes a starting basis to be used in the next LP Solve()
        //      * call. The statuses of a current solution can be retrieved via the
        //      * basis_status() function of a MPVariable or a MPConstraint.
        //      *
        //      * WARNING: With Glop, you should disable presolve when using this because
        //      * this information will not be modified in sync with the presolve and will
        //      * likely not mean much on the presolved problem.
        //      */
        //     void SetStartingLpBasis(
        //         const std::vector< MPSolver::BasisStatus >& variable_statuses,
        //         const std::vector< MPSolver::BasisStatus >& constraint_statuses );

        //     /**
        //      * Infinity.
        //      *
        //      * You can use -MPSolver::infinity() for negative infinity.
        //      */
        //     static double infinity()
        //     {
        //         return std::numeric_limits< double >::infinity();
        //     }

        //     /**
        //      * Controls (or queries) the amount of output produced by the underlying
        //      * solver. The output can surface to LOGs, or to stdout or stderr, depending
        //      * on the implementation. The amount of output will greatly vary with each
        //      * implementation and each problem.
        //      *
        //      * Output is suppressed by default.
        //      */
        //     bool OutputIsEnabled() const;

        //     /// Enables solver logging.
        //     void EnableOutput();

        //     /// Suppresses solver logging.
        //     void SuppressOutput();

        //     absl::Duration TimeLimit() const
        //     {
        //         return time_limit_;
        //     }
        //     void SetTimeLimit( absl::Duration time_limit )
        //     {
        //         DCHECK_GE( time_limit, absl::ZeroDuration() );
        //         time_limit_ = time_limit;
        //     }

        //     absl::Duration DurationSinceConstruction() const
        //     {
        //         return absl::Now() - construction_time_;
        //     }

        //     /// Returns the number of simplex iterations.
        //     int64_t iterations() const;

        //     /**
        //      * Returns the number of branch-and-bound nodes evaluated during the solve.
        //      *
        //      * Only available for discrete problems.
        //      */
        //     int64_t nodes() const;

        //     /// Returns a string describing the underlying solver and its version.
        //     std::string SolverVersion() const;

        //     /**
        //      * Advanced usage: returns the underlying solver.
        //      *
        //      * Returns the underlying solver so that the user can use solver-specific
        //      * features or features that are not exposed in the simple API of MPSolver.
        //      * This method is for advanced users, use at your own risk! In particular, if
        //      * you modify the model or the solution by accessing the underlying solver
        //      * directly, then the underlying solver will be out of sync with the
        //      * information kept in the wrapper (MPSolver, MPVariable, MPConstraint,
        //      * MPObjective). You need to cast the void* returned back to its original type
        //      * that depends on the interface (CBC: OsiClpSolverInterface*, CLP:
        //      * ClpSimplex*, GLPK: glp_prob*, SCIP: SCIP*).
        //      */
        //     void* underlying_solver();

        //     /** Advanced usage: computes the exact condition number of the current scaled
        //      * basis: L1norm(B) * L1norm(inverse(B)), where B is the scaled basis.
        //      *
        //      * This method requires that a basis exists: it should be called after Solve.
        //      * It is only available for continuous problems. It is implemented for GLPK
        //      * but not CLP because CLP does not provide the API for doing it.
        //      *
        //      * The condition number measures how well the constraint matrix is conditioned
        //      * and can be used to predict whether numerical issues will arise during the
        //      * solve: the model is declared infeasible whereas it is feasible (or
        //      * vice-versa), the solution obtained is not optimal or violates some
        //      * constraints, the resolution is slow because of repeated singularities.
        //      *
        //      * The rule of thumb to interpret the condition number kappa is:
        //      *   - o kappa <= 1e7: virtually no chance of numerical issues
        //      *   - o 1e7 < kappa <= 1e10: small chance of numerical issues
        //      *   - o 1e10 < kappa <= 1e13: medium chance of numerical issues
        //      *   - o kappa > 1e13: high chance of numerical issues
        //      *
        //      * The computation of the condition number depends on the quality of the LU
        //      * decomposition, so it is not very accurate when the matrix is ill
        //      * conditioned.
        //      */
        //     double ComputeExactConditionNumber() const;

        //     /**
        //      * Some solvers (MIP only, not LP) can produce multiple solutions to the
        //      * problem. Returns true when another solution is available, and updates the
        //      * MPVariable* objects to make the new solution queryable. Call only after
        //      * calling solve.
        //      *
        //      * The optimality properties of the additional solutions found, and whether or
        //      * not the solver computes them ahead of time or when NextSolution() is called
        //      * is solver specific.
        //      *
        //      * As of 2020-02-10, only Gurobi and SCIP support NextSolution(), see
        //      * linear_solver_interfaces_test for an example of how to configure these
        //      * solvers for multiple solutions. Other solvers return false unconditionally.
        //      */
        //     ABSL_MUST_USE_RESULT bool NextSolution();

        //     // Does not take ownership of "mp_callback".
        //     //
        //     // As of 2019-10-22, only SCIP and Gurobi support Callbacks.
        //     // SCIP does not support suggesting a heuristic solution in the callback.
        //     //
        //     // See go/mpsolver-callbacks for additional documentation.
        //     void SetCallback( MPCallback* mp_callback );
        //     bool SupportsCallbacks() const;

        //     // Global counters of variables and constraints ever created across all
        //     // MPSolver instances. Those are only updated after the destruction
        //     // (or Clear()) of each MPSolver instance.
        //     static int64_t global_num_variables();
        //     static int64_t global_num_constraints();

        //     // DEPRECATED: Use TimeLimit() and SetTimeLimit(absl::Duration) instead.
        //     // NOTE: These deprecated functions used the convention time_limit = 0 to mean
        //     // "no limit", which now corresponds to time_limit_ = InfiniteDuration().
        //     int64_t time_limit() const
        //     {
        //         return time_limit_ == absl::InfiniteDuration()
        //                    ? 0
        //                    : absl::ToInt64Milliseconds( time_limit_ );
        //     }
        //     void set_time_limit( int64_t time_limit_milliseconds )
        //     {
        //         SetTimeLimit( time_limit_milliseconds == 0
        //                           ? absl::InfiniteDuration()
        //                           : absl::Milliseconds( time_limit_milliseconds ) );
        //     }
        //     double time_limit_in_secs() const
        //     {
        //         return static_cast< double >( time_limit() ) / 1000.0;
        //     }

        //     // DEPRECATED: Use DurationSinceConstruction() instead.
        //     int64_t wall_time() const
        //     {
        //         return absl::ToInt64Milliseconds( DurationSinceConstruction() );
        //     }


        //     // Debugging: verify that the given MPVariable* belongs to this solver.
        //     bool OwnsVariable( const MPVariable* var ) const;

    }

    /**
     * The class for variables of a Mathematical Programming (MP) model.
     */
    export class MPVariable
    {
        //     /// Returns the name of the variable.
        //     const std::string& name() const
        //     {
        //         return name_;
        //     }

        //     /// Sets the integrality requirement of the variable.
        //     void SetInteger( bool integer );

        //     /// Returns the integrality requirement of the variable.
        //     bool integer() const
        //     {
        //         return integer_;
        //     }

        //     /**
        //      * Returns the value of the variable in the current solution.
        //      *
        //      * If the variable is integer, then the value will always be an integer (the
        //      * underlying solver handles floating-point values only, but this function
        //      * automatically rounds it to the nearest integer; see: man 3 round).
        //      */
        //     double solution_value() const;

        //     /// Returns the index of the variable in the MPSolver::variables_.
        //     int index() const
        //     {
        //         return index_;
        //     }

        //     /// Returns the lower bound.
        //     double lb() const
        //     {
        //         return lb_;
        //     }

        //     /// Returns the upper bound.
        //     double ub() const
        //     {
        //         return ub_;
        //     }

        //     /// Sets the lower bound.
        //     void SetLB( double lb )
        //     {
        //         SetBounds( lb, ub_ );
        //     }

        //     /// Sets the upper bound.
        //     void SetUB( double ub )
        //     {
        //         SetBounds( lb_, ub );
        //     }

        //     /// Sets both the lower and upper bounds.
        //     void SetBounds( double lb, double ub );

        //     /**
        //      * Advanced usage: unrounded solution value.
        //      *
        //      * The returned value won't be rounded to the nearest integer even if the
        //      * variable is integer.
        //      */
        //     double unrounded_solution_value() const;

        //     /**
        //      * Advanced usage: returns the reduced cost of the variable in the current
        //      * solution (only available for continuous problems).
        //      */
        //     double reduced_cost() const;

        //     /**
        //      * Advanced usage: returns the basis status of the variable in the current
        //      * solution (only available for continuous problems).
        //      *
        //      * @see MPSolver::BasisStatus.
        //      */
        //     MPSolver::BasisStatus basis_status() const;

        //     /**
        //      * Advanced usage: Certain MIP solvers (e.g. Gurobi or SCIP) allow you to set
        //      * a per-variable priority for determining which variable to branch on.
        //      *
        //      * A value of 0 is treated as default, and is equivalent to not setting the
        //      * branching priority. The solver looks first to branch on fractional
        //      * variables in higher priority levels. As of 2019-05, only Gurobi and SCIP
        //      * support setting branching priority; all other solvers will simply ignore
        //      * this annotation.
        //      */
        //     int branching_priority() const
        //     {
        //         return branching_priority_;
        //     }
        //     void SetBranchingPriority( int priority );


    }

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
        /**
         * C++: LinearExpr();
         */
        constructor();

        /**
         * Possible implicit conversions are intentional.
         * 
         * C++: LinearExpr( double constant );  // NOLINT
         */
        constructor(constant: number);

        /***
         * Possible implicit conversions are intentional.
         *
         * Warning: var is not owned.
         * 
         * C++: LinearExpr( const MPVariable* var );  // NOLINT
         */
        constructor(var_: MPVariable);

        //     /**
        //      * Returns 1-var.
        //      *
        //      * NOTE(user): if var is binary variable, this corresponds to the logical
        //      * negation of var.
        //      * Passing by value is intentional, see the discussion on binary ops.
        //      */
        //     static LinearExpr NotVar( LinearExpr var );

        /**
         * C++: LinearExpr& operator+=( const LinearExpr& rhs );
         */
        operator_plus_equals(rhs: LinearExpr | number | MPVariable): LinearExpr;

        /**
         * C++: LinearExpr& operator-=( const LinearExpr& rhs );
         */
        operator_minus_equals(rhs: LinearExpr | number | MPVariable): LinearExpr;

        /**
         * C++: LinearExpr& operator*=( double rhs );
         */
        operator_times_equals(rhs: number): LinearExpr;

        /**
         * C++: LinearExpr& operator/=( double rhs );
         */
        operator_divide_equals(rhs: number): LinearExpr;

        /**
         * C++: LinearExpr  operator-() const;
         */
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

    // LinearRange operator<=( const LinearExpr& lhs, const LinearExpr& rhs );
    export function operator_less_equals(lhs: LinearExpr | number | MPVariable, rhs: LinearExpr | number | MPVariable): LinearRange;
    // LinearRange operator==( const LinearExpr& lhs, const LinearExpr& rhs );
    export function operator_equals(lhs: LinearExpr | number | MPVariable, rhs: LinearExpr | number | MPVariable): LinearRange;
    // LinearRange operator>=( const LinearExpr& lhs, const LinearExpr& rhs );
    export function operator_greater_equals(lhs: LinearExpr | number | MPVariable, rhs: LinearExpr | number | MPVariable): LinearRange;



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
    export class LinearRange
    {
        /**
         * C++: LinearRange() : lower_bound_( 0 ), upper_bound_( 0 ) {}
         */
        constructor();
        /**
         * The bounds of the linear range are updated so that they include the offset
         * from "linear_expr", i.e., we form the range:
         * \code
           lower_bound - offset <= linear_expr - offset <= upper_bound - offset.
           \endcode

           C++: LinearRange( double lower_bound, const LinearExpr& linear_expr, double upper_bound );
         */
        constructor(lower_bound: number, linear_expr: LinearExpr, upper_bound: number);

        //     double lower_bound() const
        //     {
        //         return lower_bound_;
        //     }
        //     const LinearExpr& linear_expr() const
        //     {
        //         return linear_expr_;
        //     }
        //     double upper_bound() const
        //     {
        //         return upper_bound_;
        //     }

    }


    /**
     * The class for constraints of a Mathematical Programming (MP) model.
     *
     * A constraint is represented as a linear equation or inequality.
     */
    export class MPConstraint
    {
        // public:
        //     /// Returns the name of the constraint.
        //     const std::string& name() const
        //     {
        //         return name_;
        //     }

        //     /// Clears all variables and coefficients. Does not clear the bounds.
        //     void Clear();

        /**
         * Sets the coefficient of the variable on the constraint.
         *
         * If the variable does not belong to the solver, the function just returns,
         * or crashes in non-opt mode.
         * 
         * C++: void SetCoefficient( const MPVariable* const var, double coeff );
         */
        SetCoefficient(var_: MPVariable, coeff: number): void;

        //     /**
        //      * Gets the coefficient of a given variable on the constraint (which is 0 if
        //      * the variable does not appear in the constraint).
        //      */
        //     double GetCoefficient( const MPVariable* const var ) const;

        //     /**
        //      * Returns a map from variables to their coefficients in the constraint.
        //      *
        //      * If a variable is not present in the map, then its coefficient is zero.
        //      */
        //     const absl::flat_hash_map< const MPVariable*, double >& terms() const
        //     {
        //         return coefficients_;
        //     }

        //     /// Returns the lower bound.
        //     double lb() const
        //     {
        //         return lb_;
        //     }

        //     /// Returns the upper bound.
        //     double ub() const
        //     {
        //         return ub_;
        //     }

        //     /// Sets the lower bound.
        //     void SetLB( double lb )
        //     {
        //         SetBounds( lb, ub_ );
        //     }

        //     /// Sets the upper bound.
        //     void SetUB( double ub )
        //     {
        //         SetBounds( lb_, ub );
        //     }

        //     /// Sets both the lower and upper bounds.
        //     void SetBounds( double lb, double ub );

        //     /// Advanced usage: returns true if the constraint is "lazy" (see below).
        //     bool is_lazy() const
        //     {
        //         return is_lazy_;
        //     }

        //     /**
        //      * Advanced usage: sets the constraint "laziness".
        //      *
        //      * <em>This is only supported for SCIP and has no effect on other
        //      * solvers.</em>
        //      *
        //      * When \b laziness is true, the constraint is only considered by the Linear
        //      * Programming solver if its current solution violates the constraint. In this
        //      * case, the constraint is definitively added to the problem. This may be
        //      * useful in some MIP problems, and may have a dramatic impact on performance.
        //      *
        //      * For more info see: http://tinyurl.com/lazy-constraints.
        //      */
        //     void set_is_lazy( bool laziness )
        //     {
        //         is_lazy_ = laziness;
        //     }

        //     const MPVariable* indicator_variable() const
        //     {
        //         return indicator_variable_;
        //     }
        //     bool indicator_value() const
        //     {
        //         return indicator_value_;
        //     }

        //     /// Returns the index of the constraint in the MPSolver::constraints_.
        //     int index() const
        //     {
        //         return index_;
        //     }

        //     /**
        //      * Advanced usage: returns the dual value of the constraint in the current
        //      * solution (only available for continuous problems).
        //      */
        //     double dual_value() const;

        //     /**
        //      * Advanced usage: returns the basis status of the constraint.
        //      *
        //      * It is only available for continuous problems).
        //      *
        //      * Note that if a constraint "linear_expression in [lb, ub]" is transformed
        //      * into "linear_expression + slack = 0" with slack in [-ub, -lb], then this
        //      * status is the same as the status of the slack variable with AT_UPPER_BOUND
        //      * and AT_LOWER_BOUND swapped.
        //      *
        //      * @see MPSolver::BasisStatus.
        //      */
        //     MPSolver::BasisStatus basis_status() const;


    }

    /**
     * A class to express a linear objective.
     */
    export class MPObjective
    {
        // public:
        //     /**
        //      *  Clears the offset, all variables and coefficients, and the optimization
        //      * direction.
        //      */
        //     void Clear();

        /**
         * Sets the coefficient of the variable in the objective.
         *
         * If the variable does not belong to the solver, the function just returns,
         * or crashes in non-opt mode.
         * 
         * C++: void SetCoefficient( const MPVariable* const var, double coeff );
         */
        SetCoefficient(var_: MPVariable, coeff: number): void;

        //     /**
        //      *  Gets the coefficient of a given variable in the objective
        //      *
        //      * It returns 0 if the variable does not appear in the objective).
        //      */
        //     double GetCoefficient( const MPVariable* const var ) const;

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

        /**
         * Sets the optimization direction to minimize.
         * 
         * C++: void SetMinimization();
         */
        SetMinimization(): void;

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

    }



}
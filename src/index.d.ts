export namespace operations_research
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

    export class SimpleLinearSumAssignment
    {
        // public:
        //     // The constructor takes no size.
        //     // New node indices will be created lazily by AddArcWithCost().
        //     SimpleLinearSumAssignment();

        //     // Adds an arc from a left node to a right node with a given cost.
        //     // * Node indices must be non-negative (>= 0). For a perfect
        //     //   matching to exist on n nodes, the values taken by "left_node"
        //     //   must cover [0, n), same for "right_node".
        //     // * The arc cost can be any integer, negative, positive or zero.
        //     // * After the method finishes, NumArcs() == the returned ArcIndex + 1.
        //     ArcIndex AddArcWithCost( NodeIndex left_node, NodeIndex right_node,
        //                              CostValue cost );

        //     // Returns the current number of left nodes which is the same as the
        //     // number of right nodes. This is one greater than the largest node
        //     // index seen so far in AddArcWithCost().
        //     NodeIndex NumNodes() const;

        //     // Returns the current number of arcs in the graph.
        //     ArcIndex NumArcs() const;

        //     // Returns user-provided data.
        //     // The implementation will crash if "arc" is not in [0, NumArcs()).
        //     NodeIndex LeftNode( ArcIndex arc ) const;
        //     NodeIndex RightNode( ArcIndex arc ) const;
        //     CostValue Cost( ArcIndex arc ) const;

        //     // Solves the problem (finds the perfect matching that minimizes the
        //     // cost) and returns the solver status.
        //     enum Status
        //     {
        //         OPTIMAL,            // The algorithm found a minimum-cost perfect matching.
        //         INFEASIBLE,         // The given problem admits no perfect matching.
        //         POSSIBLE_OVERFLOW,  // Some cost magnitude is too large.
        //     };
        //     Status Solve();

        //     // Returns the cost of an assignment with minimal cost.
        //     // This is 0 if the last Solve() didn't return OPTIMAL.
        //     CostValue OptimalCost() const
        //     {
        //         return optimal_cost_;
        //     }

        //     // Returns the right node assigned to the given left node in the
        //     // last solution computed by Solve(). This works only if Solve()
        //     // returned OPTIMAL.
        //     //
        //     // Note: It is possible that there is more than one optimal
        //     // solution. The algorithm is deterministic so it will always return
        //     // the same solution for a given problem. There is no such guarantee
        //     // from one code version to the next, but the code does not change
        //     // often.
        //     NodeIndex RightMate( NodeIndex left_node ) const
        //     {
        //         return arc_head_[ assignment_arcs_[ left_node ] ];
        //     }

        //     // Returns the cost of the arc used for "left_node"'s assignment.
        //     // This works only if Solve() returned OPTIMAL.
        //     CostValue AssignmentCost( NodeIndex left_node ) const
        //     {
        //         return arc_cost_[ assignment_arcs_[ left_node ] ];
        //     }

    }


    export namespace sat
    {
        /**
         * Solves the given CpModelProto and returns an instance of CpSolverResponse.
         * 
         * C++: CpSolverResponse Solve( const CpModelProto& model_proto );
         */
        export function Solve(model_proto: CpModelProto): CpSolverResponse;

        /**
         * Wrapper class around the cp_model proto.
         *
         * This class provides two types of methods:
         *  - NewXXX to create integer, boolean, or interval variables.
         *  - AddXXX to create new constraints and add them to the model.
         */
        export class CpModelBuilder
        {
            constructor();
            // public:
            //     /// Sets the name of the model.
            //     void SetName( const std::string& name );

            /**
             * Creates an integer variable with the given domain.
             * 
             * C++: IntVar NewIntVar( const Domain& domain );
             */
            // NewIntVar(domain: Domain): IntVar;

            /**
             * Creates a Boolean variable.
             * 
             * C++:  BoolVar NewBoolVar();
             */
            NewBoolVar(): BoolVar;

            //     /// Creates a constant variable. This is a shortcut for
            //     /// NewVariable(Domain(value)).but it will return the same variable if used
            //     /// twice with the same constant.
            //     IntVar NewConstant( int64_t value );

            //     /// Creates an always true Boolean variable.
            //     /// If this is called multiple times, the same variable will always be
            //     /// returned.
            //     BoolVar TrueVar();

            //     /// Creates an always false Boolean variable.
            //     /// If this is called multiple times, the same variable will always be
            //     /// returned.
            //     BoolVar FalseVar();

            //     /// Creates an interval variable from 3 affine expressions.
            //     IntervalVar NewIntervalVar( const LinearExpr& start, const LinearExpr& size,
            //                                 const LinearExpr& end );

            //     /// Creates an interval variable with a fixed size.
            //     IntervalVar NewFixedSizeIntervalVar( const LinearExpr& start, int64_t size );

            //     /// Creates an optional interval variable from 3 affine expressions and a
            //     /// Boolean variable.
            //     IntervalVar NewOptionalIntervalVar( const LinearExpr& start,
            //                                         const LinearExpr& size,
            //                                         const LinearExpr& end, BoolVar presence );

            //     /// Creates an optional interval variable with a fixed size.
            //     IntervalVar NewOptionalFixedSizeIntervalVar( const LinearExpr& start,
            //                                                  int64_t size, BoolVar presence );

            //     /// It is sometime convenient when building a model to create a bunch of
            //     /// variables that will later be fixed. Instead of doing AddEquality(var,
            //     /// value) which add a constraint, these functions modify directly the
            //     /// underlying variable domain.
            //     ///
            //     /// Note that this ignore completely the original variable domain and just fix
            //     /// the given variable to the given value, even if it was outside the given
            //     /// variable domain. You can still use AddEquality() if this is not what you
            //     /// want.
            //     void FixVariable( IntVar var, int64_t value );
            //     void FixVariable( BoolVar var, bool value );

            //     /// Adds the constraint that at least one of the literals must be true.
            //     Constraint AddBoolOr( absl::Span< const BoolVar > literals );

            //     /// Same as AddBoolOr(). Sum literals >= 1.
            //     Constraint AddAtLeastOne( absl::Span< const BoolVar > literals );

            /**
             * At most one literal is true. Sum literals <= 1.
             * 
             * C++: Constraint AddAtMostOne( absl::Span< const BoolVar > literals );
             */
            AddAtMostOne(literals: Array<BoolVar>): Constraint;

            /**
             * Exactly one literal is true. Sum literals == 1.
             * 
             * C++: Constraint AddExactlyOne( absl::Span< const BoolVar > literals );
             */
            AddExactlyOne(literals: Array<BoolVar>): Constraint;

            //     /// Adds the constraint that all literals must be true.
            //     Constraint AddBoolAnd( absl::Span< const BoolVar > literals );

            //     /// Adds the constraint that an odd number of literals is true.
            //     Constraint AddBoolXor( absl::Span< const BoolVar > literals );

            //     /// Adds a => b.
            //     Constraint AddImplication( BoolVar a, BoolVar b )
            //     {
            //         return AddBoolOr( { a.Not(), b } );
            //     }

            //     /// Adds implication: if all lhs vars are true then all rhs vars must be true.
            //     Constraint AddImplication( absl::Span< const BoolVar > lhs,
            //                                absl::Span< const BoolVar > rhs )
            //     {
            //         return AddBoolAnd( rhs ).OnlyEnforceIf( lhs );
            //     }

            /**
             * Adds left == right.
             * 
             * C++: Constraint AddEquality( const LinearExpr& left, const LinearExpr& right );
             */
            AddEquality(left: LinearExpr | IntVar | BoolVar | number, right: LinearExpr | IntVar | BoolVar | number): Constraint;

            //     /// Adds left >= right.
            //     Constraint AddGreaterOrEqual( const LinearExpr& left, const LinearExpr& right );

            //     /// Adds left > right.
            //     Constraint AddGreaterThan( const LinearExpr& left, const LinearExpr& right );

            //     /// Adds left <= right.
            //     Constraint AddLessOrEqual( const LinearExpr& left, const LinearExpr& right );

            //     /// Adds left < right.
            //     Constraint AddLessThan( const LinearExpr& left, const LinearExpr& right );

            //     /// Adds expr in domain.
            //     Constraint AddLinearConstraint( const LinearExpr& expr, const Domain& domain );

            //     /// Adds left != right.
            //     Constraint AddNotEqual( const LinearExpr& left, const LinearExpr& right );

            //     /// This constraint forces all variables to have different values.
            //     Constraint AddAllDifferent( absl::Span< const IntVar > vars );

            //     /// This constraint forces all expressions to have different values.
            //     Constraint AddAllDifferent( absl::Span< const LinearExpr > exprs );

            //     /// This constraint forces all expressions to have different values.
            //     Constraint AddAllDifferent( std::initializer_list< LinearExpr > exprs );

            //     /// Adds the element constraint: variables[index] == target
            //     Constraint AddVariableElement( IntVar                     index,
            //                                    absl::Span< const IntVar > variables,
            //                                    IntVar                     target );

            //     /// Adds the element constraint: values[index] == target
            //     Constraint AddElement( IntVar index, absl::Span< const int64_t > values,
            //                            IntVar target );

            //     /**
            //      * Adds a circuit constraint.
            //      *
            //      * The circuit constraint is defined on a graph where the arc presence is
            //      * controlled by literals. That is the arc is part of the circuit of its
            //      * corresponding literal is assigned to true.
            //      *
            //      * For now, we ignore node indices with no incident arc. All the other nodes
            //      * must have exactly one incoming and one outgoing selected arc (i.e. literal
            //      * at true). All the selected arcs that are not self-loops must form a single
            //      * circuit.
            //      *
            //      * It returns a circuit constraint that allows adding arcs incrementally after
            //      * construction.
            //      *
            //      */
            //     CircuitConstraint AddCircuitConstraint();

            //     /**
            //      * Adds a multiple circuit constraint, aka the "VRP" (Vehicle Routing Problem)
            //      * constraint.
            //      *
            //      * The direct graph where arc #i (from tails[i] to head[i]) is present iff
            //      * literals[i] is true must satisfy this set of properties:
            //      * - #incoming arcs == 1 except for node 0.
            //      * - #outgoing arcs == 1 except for node 0.
            //      * - for node zero, #incoming arcs == #outgoing arcs.
            //      * - There are no duplicate arcs.
            //      * - Self-arcs are allowed except for node 0.
            //      * - There is no cycle in this graph, except through node 0.
            //      */
            //     MultipleCircuitConstraint AddMultipleCircuitConstraint();

            /**
             * Adds an allowed assignments constraint.
             *
             * An AllowedAssignments constraint is a constraint on an array of variables
             * that forces, when all variables are fixed to a single value, that the
             * corresponding list of values is equal to one of the tuples added to the
             * constraint.
             *
             * It returns a table constraint that allows adding tuples incrementally after
             * construction.
             * 
             * C++: TableConstraint AddAllowedAssignments( absl::Span< const IntVar > vars );
             */
            AddAllowedAssignments(vars: Array<IntVar>): TableConstraint;

            //     /**
            //      * Adds an forbidden assignments constraint.
            //      *
            //      * A ForbiddenAssignments constraint is a constraint on an array of variables
            //      * where the list of impossible combinations is provided in the tuples added
            //      * to the constraint.
            //      *
            //      * It returns a table constraint that allows adding tuples incrementally after
            //      * construction.
            //      */
            //     TableConstraint AddForbiddenAssignments( absl::Span< const IntVar > vars );

            //     /** An inverse constraint.
            //      *
            //      * It enforces that if 'variables[i]' is assigned a value
            //      * 'j', then inverse_variables[j] is assigned a value 'i'. And vice versa.
            //      */
            //     Constraint AddInverseConstraint( absl::Span< const IntVar > variables,
            //                                      absl::Span< const IntVar > inverse_variables );

            //     /**
            //      * Adds a reservoir constraint with optional refill/emptying events.
            //      *
            //      * Maintain a reservoir level within bounds. The water level starts at 0, and
            //      * at any time, it must be within [min_level, max_level].
            //      *
            //      * Given an event (time, level_change, active), if active is true, and if time
            //      * is assigned a value t, then the level of the reservoir changes by
            //      * level_change (which is constant) at time t. Therefore, at any time t:
            //      *
            //      *     sum(level_changes[i] * actives[i] if times[i] <= t)
            //      *         in [min_level, max_level]
            //      *
            //      * Note that min level must be <= 0, and the max level must be >= 0.
            //      * Please use fixed level_changes to simulate an initial state.
            //      *
            //      * It returns a ReservoirConstraint that allows adding optional and non
            //      * optional events incrementally after construction.
            //      */
            //     ReservoirConstraint AddReservoirConstraint( int64_t min_level,
            //                                                 int64_t max_level );

            //     /**
            //      * An automaton constraint.
            //      *
            //      * An automaton constraint takes a list of variables (of size n), an initial
            //      * state, a set of final states, and a set of transitions. A transition is a
            //      * triplet ('tail', 'head', 'label'), where 'tail' and 'head' are states,
            //      * and 'label' is the label of an arc from 'head' to 'tail',
            //      * corresponding to the value of one variable in the list of variables.
            //      *
            //      * This automaton will be unrolled into a flow with n + 1 phases. Each phase
            //      * contains the possible states of the automaton. The first state contains the
            //      * initial state. The last phase contains the final states.
            //      *
            //      * Between two consecutive phases i and i + 1, the automaton creates a set of
            //      * arcs. For each transition (tail, head, label), it will add an arc from
            //      * the state 'tail' of phase i and the state 'head' of phase i + 1. This arc
            //      * labeled by the value 'label' of the variables 'variables[i]'. That is,
            //      * this arc can only be selected if 'variables[i]' is assigned the value
            //      * 'label'. A feasible solution of this constraint is an assignment of
            //      * variables such that, starting from the initial state in phase 0, there is a
            //      * path labeled by the values of the variables that ends in one of the final
            //      * states in the final phase.
            //      *
            //      * It returns an AutomatonConstraint that allows adding transition
            //      * incrementally after construction.
            //      */
            //     AutomatonConstraint AddAutomaton(
            //         absl::Span< const IntVar > transition_variables, int starting_state,
            //         absl::Span< const int > final_states );

            //     /// Adds target == min(vars).
            //     Constraint AddMinEquality( const LinearExpr&          target,
            //                                absl::Span< const IntVar > vars );

            //     /// Adds target == min(exprs).
            //     Constraint AddMinEquality( const LinearExpr&              target,
            //                                absl::Span< const LinearExpr > exprs );

            //     /// Adds target == min(exprs).
            //     Constraint AddMinEquality( const LinearExpr&                   target,
            //                                std::initializer_list< LinearExpr > exprs );

            //     /// Adds target == max(vars).
            //     Constraint AddMaxEquality( const LinearExpr&          target,
            //                                absl::Span< const IntVar > vars );

            //     /// Adds target == max(exprs).
            //     Constraint AddMaxEquality( const LinearExpr&              target,
            //                                absl::Span< const LinearExpr > exprs );

            //     /// Adds target == max(exprs).
            //     Constraint AddMaxEquality( const LinearExpr&                   target,
            //                                std::initializer_list< LinearExpr > exprs );

            //     /// Adds target = num / denom (integer division rounded towards 0).
            //     Constraint AddDivisionEquality( const LinearExpr& target,
            //                                     const LinearExpr& numerator,
            //                                     const LinearExpr& denominator );

            //     /// Adds target == abs(expr).
            //     Constraint AddAbsEquality( const LinearExpr& target, const LinearExpr& expr );

            //     /// Adds target = var % mod.
            //     Constraint AddModuloEquality( const LinearExpr& target, const LinearExpr& var,
            //                                   const LinearExpr& mod );

            //     /// Adds target == prod(exprs).
            //     Constraint AddMultiplicationEquality( const LinearExpr&              target,
            //                                           absl::Span< const LinearExpr > exprs );

            //     /// Adds target == prod(vars).
            //     Constraint AddMultiplicationEquality( const LinearExpr&          target,
            //                                           absl::Span< const IntVar > vars );

            //     /// Adds target == prod(vars).
            //     Constraint AddMultiplicationEquality( const LinearExpr&                   target,
            //                                           std::initializer_list< LinearExpr > exprs );

            //     /// Adds target == left * right.
            //     Constraint AddMultiplicationEquality( const LinearExpr& target,
            //                                           const LinearExpr& left,
            //                                           const LinearExpr& right );

            //     /**
            //      * Adds a no-overlap constraint that ensures that all present intervals do
            //      * not overlap in time.
            //      */
            //     Constraint AddNoOverlap( absl::Span< const IntervalVar > vars );

            //     /**
            //      * The no_overlap_2d constraint prevents a set of boxes from overlapping.
            //      */
            //     NoOverlap2DConstraint AddNoOverlap2D();

            //     /**
            //      * The cumulative constraint
            //      *
            //      * It ensures that for any integer point, the sum of the demands of the
            //      * intervals containing that point does not exceed the capacity.
            //      */
            //     CumulativeConstraint AddCumulative( LinearExpr capacity );

            // Adds a linear minimization objective.
            // void Minimize( const LinearExpr& expr );
            Minimize(expr: LinearExpr): void;


            //     /// Adds a linear floating point minimization objective.
            //     /// Note that the coefficients will be internally scaled to integer.
            //     void Minimize( const DoubleLinearExpr& expr );

            //     /// Adds a linear maximization objective.
            //     void Maximize( const LinearExpr& expr );

            //     /// Adds a linear floating point maximization objective.
            //     /// Note that the coefficients will be internally scaled to integer.
            //     void Maximize( const DoubleLinearExpr& expr );

            //     /// Removes the objective from the model.
            //     void ClearObjective();

            //     /// Checks whether the model contains an objective.
            //     bool HasObjective() const;

            //     /// Adds a decision strategy on a list of integer variables.
            //     void AddDecisionStrategy(
            //         absl::Span< const IntVar >                       variables,
            //         DecisionStrategyProto::VariableSelectionStrategy var_strategy,
            //         DecisionStrategyProto::DomainReductionStrategy   domain_strategy );

            //     /// Adds a decision strategy on a list of boolean variables.
            //     void AddDecisionStrategy(
            //         absl::Span< const BoolVar >                      variables,
            //         DecisionStrategyProto::VariableSelectionStrategy var_strategy,
            //         DecisionStrategyProto::DomainReductionStrategy   domain_strategy );

            //     /// Adds hinting to a variable.
            //     void AddHint( IntVar var, int64_t value );

            //     /// Adds hinting to a Boolean variable.
            //     void AddHint( BoolVar var, bool value );

            //     /// Removes all hints.
            //     void ClearHints();

            //     /// Adds a literal to the model as assumptions.
            //     void AddAssumption( BoolVar lit );

            //     /// Adds multiple literals to the model as assumptions.
            //     void AddAssumptions( absl::Span< const BoolVar > literals );

            //     /// Remove all assumptions from the model.
            //     void ClearAssumptions();

            Build(): CpModelProto;

            //     const CpModelProto& Proto() const
            //     {
            //         return cp_model_;
            //     }
            //     CpModelProto* MutableProto()
            //     {
            //         return &cp_model_;
            //     }

            //     /// Export the model to file.
            //     bool ExportToFile( const std::string& filename ) const;

            //     /// Replaces the current model with the one from the given proto.
            //     void CopyFrom( const CpModelProto& model_proto );

            //     /// Returns the Boolean variable from its index in the proto.
            //     BoolVar GetBoolVarFromProtoIndex( int index );

            //     /// Returns the integer variable from its index in the proto.
            //     IntVar GetIntVarFromProtoIndex( int index );

            //     /// Returns the interval variable from its index in the proto.
            //     IntervalVar GetIntervalVarFromProtoIndex( int index );

        }

        /**
         * A Boolean variable.
         *
         * This class refer to an IntegerVariableProto with domain [0, 1] or to its
         * logical negation (Not). This is called a Boolean Literal in other context.
         *
         * This can only be constructed via \c CpModelBuilder.NewBoolVar().
         */
        export class BoolVar
        {
            /**
             * A default constructed BoolVar can be used to mean not defined yet.
             * However, it shouldn't be passed to any of the functions in this file.
             * Doing so will crash in debug mode and will result in an invalid model in
             * opt mode.
             * 
             * C++: BoolVar() = default;
             */
            constructor();

            /**
             * Sets the name of the variable.
             * Note that this will always set the "positive" version of this Boolean.
             * 
             * C++: BoolVar WithName( const std::string& name )
             */
            WithName(name: string): BoolVar;

            //     /// Returns the name of the variable.
            //     std::string Name() const;

            //     /// Returns the logical negation of the current Boolean variable.
            //     BoolVar Not() const
            //     {
            //         return BoolVar( NegatedRef( index_ ), builder_ );
            //     }

            //     bool operator==( const BoolVar& other ) const
            //     {
            //         return other.builder_ == builder_ && other.index_ == index_;
            //     }

            //     bool operator!=( const BoolVar& other ) const
            //     {
            //         return other.builder_ != builder_ || other.index_ != index_;
            //     }

            //     std::string DebugString() const;

            //     /**
            //      * Returns the index of the variable in the model.
            //      *
            //      * Warning: If the variable is the negation of another variable v, its index
            //      * is -v.index() - 1. So this can be negative.
            //      */
            //     int index() const
            //     {
            //         return index_;
            //     }
        }

        /**
         * A constraint.
         *
         * This class enables you to modify the constraint that was previously added to
         * the model.
         *
         * The constraint must be built using the different \c CpModelBuilder::AddXXX
         * methods.
         */
        export class Constraint
        {
            // public:
            //     /**
            //      * The constraint will be enforced iff all literals listed here are true.
            //      *
            //      * If this is empty, then the constraint will always be enforced. An enforced
            //      * constraint must be satisfied, and an un-enforced one will simply be
            //      * ignored.
            //      *
            //      * This is also called half-reification. To have an equivalence between a
            //      * literal and a constraint (full reification), one must add both a constraint
            //      * (controlled by a literal l) and its negation (controlled by the negation of
            //      * l).
            //      *
            //      * [Important] currently, only a few constraints support enforcement:
            //      * - bool_or, bool_and, linear: fully supported.
            //      * - interval: only support a single enforcement literal.
            //      * - other: no support (but can be added on a per-demand basis).
            //      */
            //     Constraint OnlyEnforceIf( absl::Span< const BoolVar > literals );

            //     /// See OnlyEnforceIf(absl::Span<const BoolVar> literals).
            //     Constraint OnlyEnforceIf( BoolVar literal );

            //     /// Sets the name of the constraint.
            //     Constraint WithName( const std::string& name );

            //     /// Returns the name of the constraint (or the empty string if not set).
            //     const std::string& Name() const;

            //     /// Returns the underlying protobuf object (useful for testing).
            //     const ConstraintProto& Proto() const
            //     {
            //         return *proto_;
            //     }

            //     /// Returns the mutable underlying protobuf object (useful for model edition).
            //     ConstraintProto* MutableProto() const
            //     {
            //         return proto_;
            //     }

        }

        /**
         * An integer variable.
         *
         * This class wraps an IntegerVariableProto.
         * This can only be constructed via \c CpModelBuilder.NewIntVar().
         */
        export class IntVar
        {
            /**
             * A default constructed IntVar can be used to mean not defined yet.
             * However, it shouldn't be passed to any of the functions in this file.
             * Doing so will crash in debug mode and will result in an invalid model in
             * opt mode.
             * 
             * C++: IntVar() = default;
             */
            constructor();

            /**
             * Cast BoolVar -> IntVar.
             * The IntVar will take the value 1 (when the bool is true) and 0 otherwise.
             * 
             * Warning: If you construct an IntVar from a negated BoolVar, this might
             * create a new variable in the model. Otherwise this just point to the same
             * underlying variable.
             * 
             * C++: explicit IntVar( const BoolVar& var );
             */
            constructor(var_: BoolVar);

            //     /// Cast IntVar -> BoolVar.
            //     ///
            //     /// Warning: The domain of the var must be within {0,1}. If not, we crash
            //     /// in debug mode, and in opt mode you will get an invalid model if you use
            //     /// this BoolVar anywhere since it will not have a valid domain.
            //     BoolVar ToBoolVar() const;

            //     /// Sets the name of the variable.
            //     IntVar WithName( const std::string& name );

            //     /// Returns the name of the variable (or the empty string if not set).
            //     std::string Name() const;

            //     bool operator==( const IntVar& other ) const
            //     {
            //         return other.builder_ == builder_ && other.index_ == index_;
            //     }

            //     bool operator!=( const IntVar& other ) const
            //     {
            //         return other.builder_ != builder_ || other.index_ != index_;
            //     }

            //     // Returns the domain of the variable.
            //     // Note that we keep the fully qualified return type as compilation fails with
            //     // gcc otherwise.
            //     ::operations_research::Domain Domain() const;

            //     std::string DebugString() const;

            //     /// Returns the index of the variable in the model. This will be non-negative.
            //     int index() const
            //     {
            //         return index_;
            //     }

        }

        /**
         * A dedicated container for linear expressions.
         *
         * With the use of implicit constructors, it can accept integer values, Boolean
         * and Integer variables. Note that Not(x) will be silently transformed into 1 -
         * x when added to the linear expression. It also support operator overloads to
         * construct the linear expression naturally.
         *
         * Furthermore, static methods allow to construct a linear expression from sums
         * or scalar products.
         *
         * Usage:
         * \code
          CpModelBuilder cp_model;
          IntVar x = model.NewIntVar({0, 10}).WithName("x");
          IntVar y = model.NewIntVar({0, 10}).WithName("y");
          BoolVar b = model.NewBoolVar().WithName("b");
          BoolVar c = model.NewBoolVar().WithName("c");
          LinearExpr e1(x);  // Or e1 = x.
          LinearExpr e2 = x + y + 5;
          LinearExpr e3 = 2 * x - y;
          LinearExpr e4 = b;
          LinearExpr e5 = b.Not();  // 1 - b.
          std::vector<BoolVar> bools = {b, Not(c)};
          LinearExpr e6 = LinearExpr::Sum(bools);   // b + 1 - c;
          LinearExpr e7 = -3 * b + Not(c);  // -3 * b + 1 - c;
          \endcode
         *  This can be used implicitly in some of the CpModelBuilder methods.
         * \code
          cp_model.AddGreaterThan(x, 5);
          cp_model.AddEquality(x, y + 5);
          \endcode
          */
        export class LinearExpr
        {
            /**
             * Creates an empty linear expression with value zero.
             * 
             * C++: LinearExpr() = default;
             */
            constructor();


            /**
             * Constructs a linear expression from an integer variable.
             * It deals with logical negation correctly.
             * 
             * C++: LinearExpr( BoolVar var );
             */
            constructor(var_: BoolVar);

            /**
             * Constructs a linear expression from an integer variable.
             * 
             * C++: LinearExpr( IntVar var );
             */
            constructor(var_: IntVar);

            /**
             * Constructs a constant linear expression.
             * 
             * C++: LinearExpr( int64_t constant );
             */
            constructor(constant: number);

            //       // NOLINTEND(google-explicit-constructor)

            //       /// Constructs the sum of a list of variables.
            //       static LinearExpr Sum( absl::Span< const IntVar > vars );

            //       /// Constructs the sum of a list of Boolean variables.
            //       static LinearExpr Sum( absl::Span< const BoolVar > vars );

            //       /// Constructs the scalar product of variables and coefficients.
            //       static LinearExpr WeightedSum( absl::Span< const IntVar >  vars,
            //                                      absl::Span< const int64_t > coeffs );

            //       /// Constructs the scalar product of Boolean variables and coefficients.
            //       static LinearExpr WeightedSum( absl::Span< const BoolVar > vars,
            //                                      absl::Span< const int64_t > coeffs );

            //       /// Constructs var * coefficient.
            //       static LinearExpr Term( IntVar var, int64_t coefficient );

            //       /// Constructs bool * coefficient.
            //       static LinearExpr Term( BoolVar var, int64_t coefficient );

            //       /// Constructs a linear expr from its proto representation.
            //       static LinearExpr FromProto( const LinearExpressionProto& proto );

            /**
             * C++: LinearExpr& operator+=( const LinearExpr& other );
             */
            operator_plus_equals(other: LinearExpr | number | BoolVar): LinearExpr;

            /**
             * LinearExpr& operator-=( const LinearExpr& other );
             */
            operator_minus_equals(other: LinearExpr | number | BoolVar): LinearExpr;

            /**
             * LinearExpr& operator*=( int64_t factor );
             */
            operator_times_equals(factor: number): LinearExpr;

            //       /// Returns the vector of variable indices.
            //       const std::vector< int >& variables() const
            //       {
            //           return variables_;
            //       }

            //       /// Returns the vector of coefficients.
            //       const std::vector< int64_t >& coefficients() const
            //       {
            //           return coefficients_;
            //       }

            //       /// Returns true if the expression has no variables.
            //       const bool IsConstant() const
            //       {
            //           return variables_.empty();
            //       }

            //       /// Returns the constant term.
            //       int64_t constant() const
            //       {
            //           return constant_;
            //       }

            //       /**
            //        * Debug string. If the CpModelBuilder is passed, the string will include
            //        * variable names and domains. Otherwise, you will get a shorter string with
            //        * only variable indices.
            //        */
            //       std::string DebugString( const CpModelProto* proto = nullptr ) const;

        }

        /**
         * Specialized assignment constraint.
         *
         * This constraint allows adding tuples to the allowed/forbidden assignment
         * constraint incrementally.
         */
        export class TableConstraint extends Constraint
        {
            /**
             * Adds a tuple of possible values to the constraint.
             * 
             * C++: void AddTuple( absl::Span< const int64_t > tuple );
             */
            AddTuple(tuple: number[]): void;
        }

        // inline LinearExpr operator-( LinearExpr expr )
        export function operator_negate(expr: LinearExpr): LinearExpr;

        // inline LinearExpr operator+( LinearExpr&& lhs, LinearExpr&& rhs )
        // inline LinearExpr operator+( LinearExpr&& lhs, const LinearExpr& rhs )
        // inline LinearExpr operator+( const LinearExpr& lhs, LinearExpr&& rhs )
        // inline LinearExpr operator+( const LinearExpr& lhs, const LinearExpr& rhs )
        export function operator_plus(lhs: LinearExpr, rhs: LinearExpr): LinearExpr;

        // inline LinearExpr operator-( LinearExpr&& lhs, LinearExpr&& rhs )
        // inline LinearExpr operator-( const LinearExpr& lhs, LinearExpr&& rhs )
        // inline LinearExpr operator-( LinearExpr&& lhs, const LinearExpr& rhs )
        // inline LinearExpr operator-( const LinearExpr& lhs, const LinearExpr& rhs )
        export function operator_minus(lhs: LinearExpr, rhs: LinearExpr): LinearExpr;

        // inline LinearExpr operator*( LinearExpr expr, int64_t factor )
        export function operator_times(expr: LinearExpr | BoolVar, factor: number): LinearExpr;
        // inline LinearExpr operator*( int64_t factor, LinearExpr expr )
        export function operator_times(factor: number, expr: LinearExpr | BoolVar): LinearExpr;


        export class CpModelProto 
        {
            //     public:
            //         inline CpModelProto()
            //             : CpModelProto( nullptr ) {}
            //         ~CpModelProto() override;
            //         explicit PROTOBUF_CONSTEXPR CpModelProto( ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized );

            //         CpModelProto( const CpModelProto& from );
            //         CpModelProto( CpModelProto&& from ) noexcept
            //             : CpModelProto()
            //         {
            //             *this = ::std::move( from );
            //         }

            //         inline CpModelProto& operator=( const CpModelProto& from )
            //         {
            //             CopyFrom( from );
            //             return *this;
            //         }
            //         inline CpModelProto& operator=( CpModelProto&& from ) noexcept
            //         {
            //             if ( this == &from ) return *this;
            //             if ( GetOwningArena() == from.GetOwningArena()
            // #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
            //                  && GetOwningArena() != nullptr
            // #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
            //             )
            //             {
            //                 InternalSwap( &from );
            //             }
            //             else
            //             {
            //                 CopyFrom( from );
            //             }
            //             return *this;
            //         }

            //         static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor()
            //         {
            //             return GetDescriptor();
            //         }
            //         static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor()
            //         {
            //             return default_instance().GetMetadata().descriptor;
            //         }
            //         static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection()
            //         {
            //             return default_instance().GetMetadata().reflection;
            //         }
            //         static const CpModelProto& default_instance()
            //         {
            //             return *internal_default_instance();
            //         }
            //         static inline const CpModelProto* internal_default_instance()
            //         {
            //             return reinterpret_cast< const CpModelProto* >(
            //                 &_CpModelProto_default_instance_ );
            //         }
            //         static constexpr int kIndexInFileMessages =
            //             27;

            //         friend void swap( CpModelProto& a, CpModelProto& b )
            //         {
            //             a.Swap( &b );
            //         }
            //         inline void Swap( CpModelProto* other )
            //         {
            //             if ( other == this ) return;
            // #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
            //             if ( GetOwningArena() != nullptr && GetOwningArena() == other->GetOwningArena() )
            //             {
            // #else   // PROTOBUF_FORCE_COPY_IN_SWAP
            //             if ( GetOwningArena() == other->GetOwningArena() )
            //             {
            // #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
            //                 InternalSwap( other );
            //             }
            //             else
            //             {
            //                 ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap( this, other );
            //             }
            //         }
            //         void UnsafeArenaSwap( CpModelProto* other )
            //         {
            //             if ( other == this ) return;
            //             GOOGLE_DCHECK( GetOwningArena() == other->GetOwningArena() );
            //             InternalSwap( other );
            //         }

            //         // implements Message ----------------------------------------------

            //         CpModelProto* New( ::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr ) const final
            //         {
            //             return CreateMaybeMessage< CpModelProto >( arena );
            //         }
            //         using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
            //         void CopyFrom( const CpModelProto& from );
            //         using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
            //         void MergeFrom( const CpModelProto& from )
            //         {
            //             CpModelProto::MergeImpl( *this, from );
            //         }


            //     public:
            //         PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
            //         bool                                  IsInitialized() const final;

            //         size_t      ByteSizeLong() const final;
            //         const char* _InternalParse( const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx ) final;
            //         uint8_t*    _InternalSerialize(
            //                uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream ) const final;
            //         int GetCachedSize() const final
            //         {
            //             return _impl_._cached_size_.Get();
            //         }


            //     public:
            //         static const ClassData                             _class_data_;
            //         const ::PROTOBUF_NAMESPACE_ID::Message::ClassData* GetClassData() const final;

            //         ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

            //         // nested types ----------------------------------------------------

            //         // accessors -------------------------------------------------------

            //         enum : int
            //         {
            //             kVariablesFieldNumber              = 2,
            //             kConstraintsFieldNumber            = 3,
            //             kSearchStrategyFieldNumber         = 5,
            //             kAssumptionsFieldNumber            = 7,
            //             kNameFieldNumber                   = 1,
            //             kObjectiveFieldNumber              = 4,
            //             kSolutionHintFieldNumber           = 6,
            //             kSymmetryFieldNumber               = 8,
            //             kFloatingPointObjectiveFieldNumber = 9,
            //         };
            //         // repeated .operations_research.sat.IntegerVariableProto variables = 2;
            //         int variables_size() const;


            //     public:
            //         void                                              clear_variables();
            //         ::operations_research::sat::IntegerVariableProto* mutable_variables( int index );
            //         ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::IntegerVariableProto >*
            //         mutable_variables();


            //     public:
            //         const ::operations_research::sat::IntegerVariableProto& variables( int index ) const;
            //         ::operations_research::sat::IntegerVariableProto*       add_variables();
            //         const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::IntegerVariableProto >&
            //         variables() const;

            //         // repeated .operations_research.sat.ConstraintProto constraints = 3;
            //         int constraints_size() const;


            //     public:
            //         void                                         clear_constraints();
            //         ::operations_research::sat::ConstraintProto* mutable_constraints( int index );
            //         ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::ConstraintProto >*
            //         mutable_constraints();


            //     public:
            //         const ::operations_research::sat::ConstraintProto& constraints( int index ) const;
            //         ::operations_research::sat::ConstraintProto*       add_constraints();
            //         const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::ConstraintProto >&
            //         constraints() const;

            //         // repeated .operations_research.sat.DecisionStrategyProto search_strategy = 5;
            //         int search_strategy_size() const;


            //     public:
            //         void                                               clear_search_strategy();
            //         ::operations_research::sat::DecisionStrategyProto* mutable_search_strategy( int index );
            //         ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::DecisionStrategyProto >*
            //         mutable_search_strategy();


            //     public:
            //         const ::operations_research::sat::DecisionStrategyProto& search_strategy( int index ) const;
            //         ::operations_research::sat::DecisionStrategyProto*       add_search_strategy();
            //         const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::DecisionStrategyProto >&
            //         search_strategy() const;

            //         // repeated int32 assumptions = 7;
            //         int assumptions_size() const;


            //     public:
            //         void clear_assumptions();


            //     public:
            //         int32_t assumptions( int index ) const;
            //         void    set_assumptions( int index, int32_t value );
            //         void    add_assumptions( int32_t value );
            //         const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
            //         assumptions() const;
            //         ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
            //         mutable_assumptions();

            //         // string name = 1;
            //         void               clear_name();
            //         const std::string& name() const;
            //         template < typename ArgT0 = const std::string&, typename... ArgT >
            //         void               set_name( ArgT0&& arg0, ArgT... args );
            //         std::string*       mutable_name();
            //         PROTOBUF_NODISCARD std::string* release_name();
            //         void                            set_allocated_name( std::string* name );


            //     public:
            //         // .operations_research.sat.CpObjectiveProto objective = 4;
            //         bool has_objective() const;


            //     public:
            //         void                                                             clear_objective();
            //         const ::operations_research::sat::CpObjectiveProto&              objective() const;
            //         PROTOBUF_NODISCARD ::operations_research::sat::CpObjectiveProto* release_objective();
            //         ::operations_research::sat::CpObjectiveProto*                    mutable_objective();
            //         void                                                             set_allocated_objective( ::operations_research::sat::CpObjectiveProto* objective );


            //     public:
            //         void unsafe_arena_set_allocated_objective(
            //             ::operations_research::sat::CpObjectiveProto* objective );
            //         ::operations_research::sat::CpObjectiveProto* unsafe_arena_release_objective();

            //         // .operations_research.sat.PartialVariableAssignment solution_hint = 6;
            //         bool has_solution_hint() const;


            //     public:
            //         void                                                                      clear_solution_hint();
            //         const ::operations_research::sat::PartialVariableAssignment&              solution_hint() const;
            //         PROTOBUF_NODISCARD ::operations_research::sat::PartialVariableAssignment* release_solution_hint();
            //         ::operations_research::sat::PartialVariableAssignment*                    mutable_solution_hint();
            //         void                                                                      set_allocated_solution_hint( ::operations_research::sat::PartialVariableAssignment* solution_hint );


            //     public:
            //         void unsafe_arena_set_allocated_solution_hint(
            //             ::operations_research::sat::PartialVariableAssignment* solution_hint );
            //         ::operations_research::sat::PartialVariableAssignment* unsafe_arena_release_solution_hint();

            //         // .operations_research.sat.SymmetryProto symmetry = 8;
            //         bool has_symmetry() const;


            //     public:
            //         void                                                          clear_symmetry();
            //         const ::operations_research::sat::SymmetryProto&              symmetry() const;
            //         PROTOBUF_NODISCARD ::operations_research::sat::SymmetryProto* release_symmetry();
            //         ::operations_research::sat::SymmetryProto*                    mutable_symmetry();
            //         void                                                          set_allocated_symmetry( ::operations_research::sat::SymmetryProto* symmetry );


            //     public:
            //         void unsafe_arena_set_allocated_symmetry(
            //             ::operations_research::sat::SymmetryProto* symmetry );
            //         ::operations_research::sat::SymmetryProto* unsafe_arena_release_symmetry();

            //         // .operations_research.sat.FloatObjectiveProto floating_point_objective = 9;
            //         bool has_floating_point_objective() const;


            //     public:
            //         void                                                                clear_floating_point_objective();
            //         const ::operations_research::sat::FloatObjectiveProto&              floating_point_objective() const;
            //         PROTOBUF_NODISCARD ::operations_research::sat::FloatObjectiveProto* release_floating_point_objective();
            //         ::operations_research::sat::FloatObjectiveProto*                    mutable_floating_point_objective();
            //         void                                                                set_allocated_floating_point_objective( ::operations_research::sat::FloatObjectiveProto* floating_point_objective );


            //     public:
            //         void unsafe_arena_set_allocated_floating_point_objective(
            //             ::operations_research::sat::FloatObjectiveProto* floating_point_objective );
            //         ::operations_research::sat::FloatObjectiveProto* unsafe_arena_release_floating_point_objective();

            //         // @@protoc_insertion_point(class_scope:operations_research.sat.CpModelProto)
        }

        export class CpSolverResponse  
        {
            //     public:
            //         inline CpSolverResponse()
            //             : CpSolverResponse( nullptr ) {}
            //         ~CpSolverResponse() override;
            //         explicit PROTOBUF_CONSTEXPR CpSolverResponse( ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized );

            //         CpSolverResponse( const CpSolverResponse& from );
            //         CpSolverResponse( CpSolverResponse&& from ) noexcept
            //             : CpSolverResponse()
            //         {
            //             *this = ::std::move( from );
            //         }

            //         inline CpSolverResponse& operator=( const CpSolverResponse& from )
            //         {
            //             CopyFrom( from );
            //             return *this;
            //         }
            //         inline CpSolverResponse& operator=( CpSolverResponse&& from ) noexcept
            //         {
            //             if ( this == &from ) return *this;
            //             if ( GetOwningArena() == from.GetOwningArena()
            // #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
            //                  && GetOwningArena() != nullptr
            // #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
            //             )
            //             {
            //                 InternalSwap( &from );
            //             }
            //             else
            //             {
            //                 CopyFrom( from );
            //             }
            //             return *this;
            //         }

            //         static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor()
            //         {
            //             return GetDescriptor();
            //         }
            //         static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor()
            //         {
            //             return default_instance().GetMetadata().descriptor;
            //         }
            //         static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection()
            //         {
            //             return default_instance().GetMetadata().reflection;
            //         }
            //         static const CpSolverResponse& default_instance()
            //         {
            //             return *internal_default_instance();
            //         }
            //         static inline const CpSolverResponse* internal_default_instance()
            //         {
            //             return reinterpret_cast< const CpSolverResponse* >(
            //                 &_CpSolverResponse_default_instance_ );
            //         }
            //         static constexpr int kIndexInFileMessages =
            //             29;

            //         friend void swap( CpSolverResponse& a, CpSolverResponse& b )
            //         {
            //             a.Swap( &b );
            //         }
            //         inline void Swap( CpSolverResponse* other )
            //         {
            //             if ( other == this ) return;
            // #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
            //             if ( GetOwningArena() != nullptr && GetOwningArena() == other->GetOwningArena() )
            //             {
            // #else   // PROTOBUF_FORCE_COPY_IN_SWAP
            //             if ( GetOwningArena() == other->GetOwningArena() )
            //             {
            // #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
            //                 InternalSwap( other );
            //             }
            //             else
            //             {
            //                 ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap( this, other );
            //             }
            //         }
            //         void UnsafeArenaSwap( CpSolverResponse* other )
            //         {
            //             if ( other == this ) return;
            //             GOOGLE_DCHECK( GetOwningArena() == other->GetOwningArena() );
            //             InternalSwap( other );
            //         }

            //         // implements Message ----------------------------------------------

            //         CpSolverResponse* New( ::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr ) const final
            //         {
            //             return CreateMaybeMessage< CpSolverResponse >( arena );
            //         }
            //         using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
            //         void CopyFrom( const CpSolverResponse& from );
            //         using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
            //         void MergeFrom( const CpSolverResponse& from )
            //         {
            //             CpSolverResponse::MergeImpl( *this, from );
            //         }


            //     public:
            //         PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
            //         bool                                  IsInitialized() const final;

            //         size_t      ByteSizeLong() const final;
            //         const char* _InternalParse( const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx ) final;
            //         uint8_t*    _InternalSerialize(
            //                uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream ) const final;
            //         int GetCachedSize() const final
            //         {
            //             return _impl_._cached_size_.Get();
            //         }




            //     public:
            //         static const ClassData                             _class_data_;
            //         const ::PROTOBUF_NAMESPACE_ID::Message::ClassData* GetClassData() const final;

            //         ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

            //         // nested types ----------------------------------------------------

            //         // accessors -------------------------------------------------------

            //         enum : int
            //         {
            //             kSolutionFieldNumber                              = 2,
            //             kTightenedVariablesFieldNumber                    = 21,
            //             kSufficientAssumptionsForInfeasibilityFieldNumber = 23,
            //             kAdditionalSolutionsFieldNumber                   = 27,
            //             kSolutionInfoFieldNumber                          = 20,
            //             kSolveLogFieldNumber                              = 26,
            //             kIntegerObjectiveFieldNumber                      = 28,
            //             kObjectiveValueFieldNumber                        = 3,
            //             kBestObjectiveBoundFieldNumber                    = 4,
            //             kNumBooleansFieldNumber                           = 10,
            //             kNumConflictsFieldNumber                          = 11,
            //             kNumBranchesFieldNumber                           = 12,
            //             kNumBinaryPropagationsFieldNumber                 = 13,
            //             kNumIntegerPropagationsFieldNumber                = 14,
            //             kWallTimeFieldNumber                              = 15,
            //             kUserTimeFieldNumber                              = 16,
            //             kDeterministicTimeFieldNumber                     = 17,
            //             kGapIntegralFieldNumber                           = 22,
            //             kNumRestartsFieldNumber                           = 24,
            //             kNumLpIterationsFieldNumber                       = 25,
            //             kInnerObjectiveLowerBoundFieldNumber              = 29,
            //             kNumIntegersFieldNumber                           = 30,
            //             kStatusFieldNumber                                = 1,
            //         };
            //         // repeated int64 solution = 2;
            //         int solution_size() const;


            //     public:
            //         void clear_solution();


            //     public:
            //         int64_t solution( int index ) const;
            //         void    set_solution( int index, int64_t value );
            //         void    add_solution( int64_t value );
            //         const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
            //         solution() const;
            //         ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
            //         mutable_solution();

            //         // repeated .operations_research.sat.IntegerVariableProto tightened_variables = 21;
            //         int tightened_variables_size() const;


            //     public:
            //         void                                              clear_tightened_variables();
            //         ::operations_research::sat::IntegerVariableProto* mutable_tightened_variables( int index );
            //         ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::IntegerVariableProto >*
            //         mutable_tightened_variables();


            //     public:
            //         const ::operations_research::sat::IntegerVariableProto& tightened_variables( int index ) const;
            //         ::operations_research::sat::IntegerVariableProto*       add_tightened_variables();
            //         const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::IntegerVariableProto >&
            //         tightened_variables() const;

            //         // repeated int32 sufficient_assumptions_for_infeasibility = 23;
            //         int sufficient_assumptions_for_infeasibility_size() const;


            //     public:
            //         void clear_sufficient_assumptions_for_infeasibility();


            //     public:
            //         int32_t sufficient_assumptions_for_infeasibility( int index ) const;
            //         void    set_sufficient_assumptions_for_infeasibility( int index, int32_t value );
            //         void    add_sufficient_assumptions_for_infeasibility( int32_t value );
            //         const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
            //         sufficient_assumptions_for_infeasibility() const;
            //         ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
            //         mutable_sufficient_assumptions_for_infeasibility();

            //         // repeated .operations_research.sat.CpSolverSolution additional_solutions = 27;
            //         int additional_solutions_size() const;


            //     public:
            //         void                                          clear_additional_solutions();
            //         ::operations_research::sat::CpSolverSolution* mutable_additional_solutions( int index );
            //         ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::CpSolverSolution >*
            //         mutable_additional_solutions();


            //     public:
            //         const ::operations_research::sat::CpSolverSolution& additional_solutions( int index ) const;
            //         ::operations_research::sat::CpSolverSolution*       add_additional_solutions();
            //         const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::CpSolverSolution >&
            //         additional_solutions() const;

            //         // string solution_info = 20;
            //         void               clear_solution_info();
            //         const std::string& solution_info() const;
            //         template < typename ArgT0 = const std::string&, typename... ArgT >
            //         void               set_solution_info( ArgT0&& arg0, ArgT... args );
            //         std::string*       mutable_solution_info();
            //         PROTOBUF_NODISCARD std::string* release_solution_info();
            //         void                            set_allocated_solution_info( std::string* solution_info );


            //     public:
            //         // string solve_log = 26;
            //         void               clear_solve_log();
            //         const std::string& solve_log() const;
            //         template < typename ArgT0 = const std::string&, typename... ArgT >
            //         void               set_solve_log( ArgT0&& arg0, ArgT... args );
            //         std::string*       mutable_solve_log();
            //         PROTOBUF_NODISCARD std::string* release_solve_log();
            //         void                            set_allocated_solve_log( std::string* solve_log );


            //     public:
            //         // .operations_research.sat.CpObjectiveProto integer_objective = 28;
            //         bool has_integer_objective() const;


            //     public:
            //         void                                                             clear_integer_objective();
            //         const ::operations_research::sat::CpObjectiveProto&              integer_objective() const;
            //         PROTOBUF_NODISCARD ::operations_research::sat::CpObjectiveProto* release_integer_objective();
            //         ::operations_research::sat::CpObjectiveProto*                    mutable_integer_objective();
            //         void                                                             set_allocated_integer_objective( ::operations_research::sat::CpObjectiveProto* integer_objective );


            //     public:
            //         void unsafe_arena_set_allocated_integer_objective(
            //             ::operations_research::sat::CpObjectiveProto* integer_objective );
            //         ::operations_research::sat::CpObjectiveProto* unsafe_arena_release_integer_objective();

            //         // double objective_value = 3;
            //         void   clear_objective_value();
            //         double objective_value() const;
            //         void   set_objective_value( double value );


            //     public:
            //         // double best_objective_bound = 4;
            //         void   clear_best_objective_bound();
            //         double best_objective_bound() const;
            //         void   set_best_objective_bound( double value );


            //     public:
            //         // int64 num_booleans = 10;
            //         void    clear_num_booleans();
            //         int64_t num_booleans() const;
            //         void    set_num_booleans( int64_t value );


            //     public:
            //         // int64 num_conflicts = 11;
            //         void    clear_num_conflicts();
            //         int64_t num_conflicts() const;
            //         void    set_num_conflicts( int64_t value );


            //     public:
            //         // int64 num_branches = 12;
            //         void    clear_num_branches();
            //         int64_t num_branches() const;
            //         void    set_num_branches( int64_t value );


            //     public:
            //         // int64 num_binary_propagations = 13;
            //         void    clear_num_binary_propagations();
            //         int64_t num_binary_propagations() const;
            //         void    set_num_binary_propagations( int64_t value );


            //     public:
            //         // int64 num_integer_propagations = 14;
            //         void    clear_num_integer_propagations();
            //         int64_t num_integer_propagations() const;
            //         void    set_num_integer_propagations( int64_t value );


            //     public:
            //         // double wall_time = 15;
            //         void   clear_wall_time();
            //         double wall_time() const;
            //         void   set_wall_time( double value );


            //     public:
            //         // double user_time = 16;
            //         void   clear_user_time();
            //         double user_time() const;
            //         void   set_user_time( double value );


            //     public:
            //         // double deterministic_time = 17;
            //         void   clear_deterministic_time();
            //         double deterministic_time() const;
            //         void   set_deterministic_time( double value );


            //     public:
            //         // double gap_integral = 22;
            //         void   clear_gap_integral();
            //         double gap_integral() const;
            //         void   set_gap_integral( double value );


            //     public:
            //         // int64 num_restarts = 24;
            //         void    clear_num_restarts();
            //         int64_t num_restarts() const;
            //         void    set_num_restarts( int64_t value );


            //     public:
            //         // int64 num_lp_iterations = 25;
            //         void    clear_num_lp_iterations();
            //         int64_t num_lp_iterations() const;
            //         void    set_num_lp_iterations( int64_t value );


            //     public:
            //         // int64 inner_objective_lower_bound = 29;
            //         void    clear_inner_objective_lower_bound();
            //         int64_t inner_objective_lower_bound() const;
            //         void    set_inner_objective_lower_bound( int64_t value );


            //     public:
            //         // int64 num_integers = 30;
            //         void    clear_num_integers();
            //         int64_t num_integers() const;
            //         void    set_num_integers( int64_t value );


            //         // .operations_research.sat.CpSolverStatus status = 1;
            //         void                                       clear_status();
            // ::operations_research::sat::CpSolverStatus status() const;
            status(): CpSolverStatus
            //         void                                       set_status( ::operations_research::sat::CpSolverStatus value );


            //     public:
            //         // @@protoc_insertion_point(class_scope:operations_research.sat.CpSolverResponse)
        }

        export enum CpSolverStatus 
        {
            UNKNOWN = 0,
            MODEL_INVALID = 1,
            FEASIBLE = 2,
            INFEASIBLE = 3,
            OPTIMAL = 4,
        }
    }
}
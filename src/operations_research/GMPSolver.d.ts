export namespace operations_research
{
    export namespace MPSolver
    {
        export enum OptimizationProblemType
        {
            CLP_LINEAR_PROGRAMMING = 0,
            GLPK_LINEAR_PROGRAMMING = 1,
            GLOP_LINEAR_PROGRAMMING = 2,
            PDLP_LINEAR_PROGRAMMING = 8,
            HIGHS_LINEAR_PROGRAMMING = 15,
            SCIP_MIXED_INTEGER_PROGRAMMING = 3,
            GLPK_MIXED_INTEGER_PROGRAMMING = 4,
            CBC_MIXED_INTEGER_PROGRAMMING = 5,
            HIGHS_MIXED_INTEGER_PROGRAMMING = 16,
            BOP_INTEGER_PROGRAMMING = 12,
            SAT_INTEGER_PROGRAMMING = 14,
            KNAPSACK_MIXED_INTEGER_PROGRAMMING = 13,
            GUROBI_LINEAR_PROGRAMMING = 6,
            GUROBI_MIXED_INTEGER_PROGRAMMING = 7,
            CPLEX_LINEAR_PROGRAMMING = 10,
            CPLEX_MIXED_INTEGER_PROGRAMMING = 11,
            XPRESS_LINEAR_PROGRAMMING = 101,
            XPRESS_MIXED_INTEGER_PROGRAMMING = 102,
            COPT_LINEAR_PROGRAMMING = 103,
            COPT_MIXED_INTEGER_PROGRAMMING = 104,
        };

        export enum ResultStatus
        {
            OPTIMAL,
            FEASIBLE,
            INFEASIBLE,
            UNBOUNDED,
            ABNORMAL,
            MODEL_INVALID,
            NOT_SOLVED = 6
        };

        export enum BasisStatus
        {
            FREE = 0,
            AT_LOWER_BOUND,
            AT_UPPER_BOUND,
            FIXED_VALUE,
            BASIC
        };
    }
    export class MPSolver
    {
        // MPSolver( const std::string& name, OptimizationProblemType problem_type );
        constructor(name: string, problem_type: MPSolver.OptimizationProblemType);

        // static MPSolver* CreateSolver( const std::string& solver_id );
        static CreateSolver(solver_id: string): MPSolver;

        // static bool SupportsProblemType( OptimizationProblemType problem_type );
        static SupportsProblemType(problem_type: MPSolver.OptimizationProblemType): boolean;

        // static bool ParseSolverType( absl::string_view solver_id, OptimizationProblemType* type );
        static ParseSolverType(solver_id: string): { return: boolean, type: MPSolver.OptimizationProblemType };

        // static OptimizationProblemType ParseSolverTypeOrDie( const std::string& solver_id );
        static ParseSolverTypeOrDie(solver_id: string): MPSolver.OptimizationProblemType;

        // bool IsMIP() const;
        IsMIP(): boolean;

        // const std::string& Name() const;
        Name(): string;

        // virtual OptimizationProblemType ProblemType() const;
        ProblemType(): MPSolver.OptimizationProblemType;

        // void Clear();
        Clear(): void;

        // int NumVariables() const;
        NumVariables(): number;

        // const std::vector< MPVariable* >& variables() const;
        variables(): Array<MPVariable>;

        // MPVariable* variable( int index ) const;
        variable(index: number): MPVariable;

        // MPVariable* LookupVariableOrNull( const std::string& var_name ) const;
        LookupVariableOrNull(var_name: string): MPVariable;

        // MPVariable* MakeVar( double lb, double ub, bool integer, const std::string& name );
        MakeVar(lb: number, ub: number, integer: boolean, name: string): MPVariable;

        // MPVariable* MakeNumVar( double lb, double ub, const std::string& name );
        MakeNumVar(lb: number, ub: number, name: string): MPVariable;

        // MPVariable* MakeIntVar( double lb, double ub, const std::string& name );
        MakeIntVar(lb: number, ub: number, name: string): MPVariable;

        // MPVariable* MakeBoolVar( const std::string& name );
        MakeBoolVar(name: string): MPVariable;

        // void MakeVarArray( int nb, double lb, double ub, bool integer, const std::string& name_prefix, std::vector< MPVariable* >* vars );

        // void MakeNumVarArray( int nb, double lb, double ub, const std::string& name, std::vector< MPVariable* >* vars );

        // void MakeIntVarArray( int nb, double lb, double ub, const std::string& name, std::vector< MPVariable* >* vars );

        // void MakeBoolVarArray( int nb, const std::string& name, std::vector< MPVariable* >* vars );

        // int NumConstraints() const;

        // const std::vector< MPConstraint* >& constraints() const;

        // MPConstraint* constraint( int index ) const;

        // MPConstraint* LookupConstraintOrNull( const std::string& constraint_name ) const;

        // MPConstraint* MakeRowConstraint( double lb, double ub );

        // MPConstraint* MakeRowConstraint();

        // MPConstraint* MakeRowConstraint( double lb, double ub, const std::string& name );

        // MPConstraint* MakeRowConstraint( const std::string& name );

        // MPConstraint* MakeRowConstraint( const LinearRange& range );

        // MPConstraint* MakeRowConstraint( const LinearRange& range, const std::string& name );

        // const MPObjective& Objective() const;

        // MPObjective* MutableObjective();

        // ResultStatus Solve();

        // ResultStatus Solve( const MPSolverParameters& param );

        // void Write( const std::string& file_name );

        // std::vector< double > ComputeConstraintActivities() const;

        // bool VerifySolution( double tolerance, bool log_errors ) const;

        // void Reset();

        // bool InterruptSolve();

        // MPSolverResponseStatus LoadModelFromProto( const MPModelProto& input_model, std::string* error_message, bool clear_names = true );

        // MPSolverResponseStatus LoadModelFromProtoWithUniqueNamesOrDie( const MPModelProto& input_model, std::string* error_message );

        // void FillSolutionResponseProto( MPSolutionResponse* response ) const;

        // ABSL_DEPRECATED( "Prefer SolveMPModel() from solve_mp_model.h." )

        // static void SolveWithProto( const MPModelRequest& model_request, MPSolutionResponse* response, std::atomic< bool >* interrupt = nullptr );

        // ABSL_DEPRECATED( "Prefer SolveMPModel() from solve_mp_model.h." )

        // static void SolveLazyMutableRequest( LazyMutableCopy< MPModelRequest > request, MPSolutionResponse* response, std::atomic< bool >* interrupt = nullptr );

        // ABSL_DEPRECATED( "Prefer SolverTypeSupportsInterruption() from solve_mp_model.h." )

        // static bool SolverTypeSupportsInterruption( const MPModelRequest::SolverType solver );

        // void ExportModelToProto( MPModelProto* output_model ) const;

        // absl::Status LoadSolutionFromProto( const MPSolutionResponse& response, double tolerance = std::numeric_limits< double >::infinity() );

        // absl::Status ClampSolutionWithinBounds();

        // bool ExportModelAsLpFormat( bool obfuscate, std::string* model_str ) const;

        // bool ExportModelAsMpsFormat( bool fixed_format, bool obfuscate, std::string* model_str ) const;

        // absl::Status SetNumThreads( int num_threads );

        // int GetNumThreads() const;

        // bool SetSolverSpecificParametersAsString( const std::string& parameters );

        // std::string GetSolverSpecificParametersAsString() const;

        // void SetHint( std::vector< std::pair< const MPVariable*, double > > hint );

        // ABSL_DEPRECATED( "Prefer MPModelRequestLoggingInfo() from solve_mp_model.h." )

        // static std::string GetMPModelRequestLoggingInfo( const MPModelRequest& request );

        // void SetStartingLpBasis( const std::vector< MPSolver::BasisStatus >& variable_statuses, const std::vector< MPSolver::BasisStatus >& constraint_statuses );

        // static double infinity();

        // double solver_infinity();

        // bool OutputIsEnabled() const;

        // void EnableOutput();

        // void SuppressOutput();

        // absl::Duration TimeLimit() const;

        // void SetTimeLimit( absl::Duration time_limit );

        // absl::Duration DurationSinceConstruction() const;

        // int64_t iterations() const;

        // int64_t nodes() const;

        // std::string SolverVersion() const;

        // void* underlying_solver();

        // double ComputeExactConditionNumber() const;

        // ABSL_MUST_USE_RESULT bool NextSolution();

        // void SetCallback( MPCallback* mp_callback );

        // bool SupportsCallbacks() const;

        // static int64_t global_num_variables();

        // static int64_t global_num_constraints();

        // int64_t time_limit() const;

        // void set_time_limit( int64_t time_limit_milliseconds );

        // double time_limit_in_secs() const;

        // int64_t wall_time() const;

        // bool OwnsVariable( const MPVariable* var ) const;
    };

}
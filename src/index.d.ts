
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
        export enum BasisStatus
        {
            FREE = 0,
            AT_LOWER_BOUND,
            AT_UPPER_BOUND,
            FIXED_VALUE,
            BASIC
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
    }
    export class MPSolver
    {
        constructor(name: string, problem_type: MPSolver.OptimizationProblemType);

        static CreateSolver(solver_id: string): MPSolver;
        static SupportsProblemType(problem_type: MPSolver.OptimizationProblemType): boolean;
        static ParseSolverType(solver_id: string): { return: boolean, type: MPSolver.OptimizationProblemType };
        static ParseSolverTypeOrDie(solver_id: string): MPSolver.OptimizationProblemType;
        IsMIP(): boolean;
        Name(): string;
        ProblemType(): MPSolver.OptimizationProblemType;
        Clear(): void;
        NumVariables(): number;
        variables(): MPVariable[];
        // MPVariable *variable(int index) const;
        variable(index: number): MPVariable;
        // MPVariable *LookupVariableOrNull(const std::string &var_name) const;
        LookupVariableOrNull(var_name: string): MPVariable;
        // MPVariable *MakeVar(double lb, double ub, bool integer, const std::string &name);
        MakeVar(lb: number, ub: number, integer: boolean, name: string): MPVariable;
        // MPVariable *MakeNumVar(double lb, double ub, const std::string &name);
        MakeNumVar(lb: number, ub: number, name: string): MPVariable;
        // MPVariable *MakeIntVar(double lb, double ub, const std::string &name);
        MakeIntVar(lb: number, ub: number, name: string): MPVariable;
        // MPVariable *MakeBoolVar(const std::string &name);
        MakeBoolVar(name: string): MPVariable;
        // void MakeVarArray(int nb, double lb, double ub, bool integer, const std::string &name_prefix, std::vector<MPVariable *> *vars);
        MakeVarArray(nb: number, lb: number, ub: number, integer: boolean, name_prefix: string, vars: std.Vector<MPVariable>): void;
        // void MakeNumVarArray(int nb, double lb, double ub, const std::string &name, std::vector<MPVariable *> *vars);
        MakeNumVarArray(nb: number, lb: number, ub: number, name: string, vars: std.Vector<MPVariable>): void;
        // void MakeIntVarArray(int nb, double lb, double ub, const std::string &name, std::vector<MPVariable *> *vars);
        MakeIntVarArray(nb: number, lb: number, ub: number, name: string, vars: std.Vector<MPVariable>): void;
        // void MakeBoolVarArray(int nb, const std::string &name, std::vector<MPVariable *> *vars);
        MakeBoolVarArray(nb: number, name: string, vars: std.Vector<MPVariable>): void;
        // int NumConstraints() const;
        NumConstraints(): number;
        // const std::vector<MPConstraint *> &constraints() const;
        constraints(): std.Vector<MPConstraint>;
        // MPConstraint *constraint(int index) const;
        constraint(index: number): MPConstraint;
        // MPConstraint *LookupConstraintOrNull(const std::string &constraint_name) const;
        LookupConstraintOrNull(constraint_name: string): MPConstraint;
        // MPConstraint *MakeRowConstraint(double lb, double ub);
        MakeRowConstraint(lb: number, ub: number): MPConstraint;
        // MPConstraint *MakeRowConstraint();
        MakeRowConstraint(): MPConstraint;
        // MPConstraint *MakeRowConstraint(double lb, double ub, const std::string &name);
        MakeRowConstraint(lb: number, ub: number, name: string): MPConstraint;
        // MPConstraint *MakeRowConstraint(const std::string &name);
        MakeRowConstraint(name: string): MPConstraint;
        // MPConstraint *MakeRowConstraint(const LinearRange &range);
        MakeRowConstraint(range: LinearRange): MPConstraint;
        // MPConstraint *MakeRowConstraint(const LinearRange &range, const std::string &name);
        MakeRowConstraint(range: LinearRange, name: string): MPConstraint;
        // const MPObjective &Objective() const;
        Objective(): MPObjective;
        // MPObjective *MutableObjective();
        MutableObjective(): MPObjective;
        // ResultStatus Solve();
        Solve(): MPSolver.ResultStatus;
        // ResultStatus Solve(const MPSolverParameters &param);
        Solve(param: MPSolverParameters): MPSolver.ResultStatus;
        // void Write(const std::string &file_name);
        Write(file_name: string): void;
        // std::vector<double> ComputeConstraintActivities() const;
        ComputeConstraintActivities(): std.Vector<number>;
        // bool VerifySolution(double tolerance, bool log_errors) const;
        VerifySolution(tolerance: number, log_errors: boolean): boolean;
        // void Reset();
        Reset(): void;
        // bool InterruptSolve();
        InterruptSolve(): boolean;
        // MPSolverResponseStatus LoadModelFromProto(const MPModelProto &input_model, std::string *error_message, bool clear_names = true);
        LoadModelFromProto(input_model: MPModelProto, error_message: string, clear_names: boolean): MPSolver.MPSolverResponseStatus;
        // MPSolverResponseStatus LoadModelFromProtoWithUniqueNamesOrDie(const MPModelProto &input_model, std::string *error_message);
        LoadModelFromProtoWithUniqueNamesOrDie(input_model: MPModelProto, error_message: string): MPSolver.MPSolverResponseStatus;
        // void FillSolutionResponseProto(MPSolutionResponse *response) const;
        FillSolutionResponseProto(response: MPSolutionResponse): void;
        // static void SolveWithProto(const MPModelRequest &model_request, MPSolutionResponse *response, std::atomic<bool> *interrupt = nullptr);
        static SolveWithProto(model_request: MPModelRequest, response: MPSolutionResponse, interrupt: std.Atomic<boolean>): void;
        // static void SolveLazyMutableRequest(LazyMutableCopy<MPModelRequest> request, MPSolutionResponse *response, std::atomic<bool> *interrupt = nullptr);
        static SolveLazyMutableRequest(request: LazyMutableCopy<MPModelRequest>, response: MPSolutionResponse, interrupt: std.Atomic<boolean>): void;
        // static bool SolverTypeSupportsInterruption(const MPModelRequest::SolverType solver);
        static SolverTypeSupportsInterruption(solver: MPModelRequest.SolverType): boolean;
        // void ExportModelToProto(MPModelProto *output_model) const;
        ExportModelToProto(output_model: MPModelProto): void;
        // absl::Status LoadSolutionFromProto(const MPSolutionResponse &response, double tolerance = std::numeric_limits<double>::infinity());
        LoadSolutionFromProto(response: MPSolutionResponse, tolerance: number): absl.Status;
        // absl::Status ClampSolutionWithinBounds();
        ClampSolutionWithinBounds(): absl.Status;
        // bool ExportModelAsLpFormat(bool obfuscate, std::string *model_str) const;
        ExportModelAsLpFormat(obfuscate: boolean, model_str: string): boolean;
        ExportModelAsMpsFormat(fixed_format: boolean, obfuscate: boolean): { return: boolean, model_str: string };
        SetNumThreads(num_threads: number): boolean;
        GetNumThreads(): number;
        SetSolverSpecificParametersAsString(parameters: string): boolean;
        GetSolverSpecificParametersAsString(): string;
        SetHint(hint: [[MPVariable, number]]): void;
        static GetMPModelRequestLoggingInfo(request: MPModelRequest): string;
        SetStartingLpBasis(variable_statuses: MPSolver.BasisStatus[], constraint_statuses: MPSolver.BasisStatus[]): void;
        static infinity(): number;
        solver_infinity(): number;
        OutputIsEnabled(): boolean;
        EnableOutput(): void;
        SuppressOutput(): void;
        TimeLimit(): number; // Milliseconds TimeLimit() const;
        SetTimeLimit(time_limit: number): void; // void SetTimeLimit(Milliseconds time_limit);
        DurationSinceConstruction(): number; // Milliseconds DurationSinceConstruction() const;
        iterations(): number;
        nodes(): number;
        SolverVersion(): string;
        // void *underlying_solver();
        ComputeExactConditionNumber(): number;
        NextSolution(): boolean;
        SetCallback(mp_callback: MPCallback): void;
        SupportsCallbacks(): boolean;
        static global_num_variables(): number;
        static global_num_constraints(): number;
        time_limit(): number;
        set_time_limit(time_limit_milliseconds: number): void;
        time_limit_in_secs(): number;
        wall_time(): number;
        OwnsVariable(var_: MPVariable): boolean;
    };
}

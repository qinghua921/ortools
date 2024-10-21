import { MPVariable } from "./operations_research/MPVariable";

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
        variable(index: number): MPVariable;
        LookupVariableOrNull(var_name: string): MPVariable;
        MakeVar(lb: number, ub: number, integer: boolean, name: string): MPVariable;
        MakeNumVar(lb: number, ub: number, name: string): MPVariable;
        MakeIntVar(lb: number, ub: number, name: string): MPVariable;
        MakeBoolVar(name: string): MPVariable;
        MakeVarArray(nb: number, lb: number, ub: number, integer: boolean, name_prefix: string): MPVariable[];
        MakeNumVarArray(nb: number, lb: number, ub: number, name: string): MPVariable[];
        MakeIntVarArray(nb: number, lb: number, ub: number, name: string): MPVariable[];
        MakeBoolVarArray(nb: number, name: string): MPVariable[];
        NumConstraints(): number;
        constraints(): std.Vector<MPConstraint>;
        constraint(index: number): MPConstraint;
        LookupConstraintOrNull(constraint_name: string): MPConstraint;
        MakeRowConstraint(lb: number, ub: number): MPConstraint;
        MakeRowConstraint(): MPConstraint;
        MakeRowConstraint(lb: number, ub: number, name: string): MPConstraint;
        MakeRowConstraint(name: string): MPConstraint;
        MakeRowConstraint(range: LinearRange): MPConstraint;
        MakeRowConstraint(range: LinearRange, name: string): MPConstraint;
        // const MPObjective &Objective() const;
        MutableObjective(): MPObjective;
        Solve(): MPSolver.ResultStatus;
        Solve(param: MPSolverParameters): MPSolver.ResultStatus;
        Write(file_name: string): void;
        ComputeConstraintActivities(): number[];
        VerifySolution(tolerance: number, log_errors: boolean): boolean;
        Reset(): void;
        InterruptSolve(): boolean;
        // MPSolverResponseStatus LoadModelFromProto(const MPModelProto &input_model, std::string *error_message, bool clear_names = true);
        // MPSolverResponseStatus LoadModelFromProtoWithUniqueNamesOrDie(const MPModelProto &input_model, std::string *error_message);
        FillSolutionResponseProto(response: MPSolutionResponse): void;
        // static void SolveWithProto(const MPModelRequest &model_request, MPSolutionResponse *response, std::atomic<bool> *interrupt = nullptr);
        // static void SolveLazyMutableRequest(LazyMutableCopy<MPModelRequest> request, MPSolutionResponse *response, std::atomic<bool> *interrupt = nullptr);
        static SolverTypeSupportsInterruption(solver: MPModelRequest.SolverType): boolean;
        // void ExportModelToProto(MPModelProto *output_model) const;
        LoadSolutionFromProto(response: MPSolutionResponse, tolerance: number): boolean;
        ClampSolutionWithinBounds(): boolean;
        ExportModelAsLpFormat(obfuscate: boolean): { return: boolean, model_str: string };
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

    export class MPVariable
    {
        name(): string;
        SetInteger(integer: boolean): void;
        integer(): boolean;
        solution_value(): number;
        index(): number;
        lb(): number;
        ub(): number;
        SetLB(lb: number): void;
        SetUB(ub: number): void;
        SetBounds(lb: number, ub: number): void;
        unrounded_solution_value(): number;
        reduced_cost(): number;
        basis_status(): MPSolver.BasisStatus;
        branching_priority(): number;
        SetBranchingPriority(priority: number): void;
    };

    export class MPCallback
    {
        RunCallback(callback_context: MPCallbackContext): void;
        might_add_cuts(): boolean;
        might_add_lazy_constraints(): boolean;
    };

    export class MPModelRequest { }
    export class MPSolutionResponse { }

    export class LinearRange
    {
        constructor();
        constructor(lower_bound: number, linear_expr: LinearExpr, upper_bound: number);

        lower_bound(): number;
        linear_expr(): LinearExpr;
        upper_bound(): number;
    };

    export class MPConstraint
    {
        // TODO continue here
        //const std::string &name() const;
        //void Clear();
        //void SetCoefficient(const MPVariable *var, double coeff);
        //double GetCoefficient(const MPVariable *var) const;
        //const absl::flat_hash_map<const MPVariable *, double> &terms() const;
        //double lb() const;
        //double ub() const;
        //void SetLB(double lb);
        //void SetUB(double ub);
        //void SetBounds(double lb, double ub);
        //bool is_lazy() const;
        //void set_is_lazy(bool laziness);
        //const MPVariable *indicator_variable() const;
        //bool indicator_value() const;
        //int index() const；
        //double dual_value() const;
        //MPSolver::BasisStatus basis_status() const;
    };
};

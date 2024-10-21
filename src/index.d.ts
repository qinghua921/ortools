export namespace operations_research
{
    export function operator_le(lhs: CanAsLinearExpr, rhs: CanAsLinearExpr): LinearRange;
    export function operator_eq(lhs: CanAsLinearExpr, rhs: CanAsLinearExpr): LinearRange;
    export function operator_ge(lhs: CanAsLinearExpr, rhs: CanAsLinearExpr): LinearRange;
    export function operator_times(lhs: CanAsLinearExpr, rhs: number): LinearExpr;
    export function operator_times(lhs: number, rhs: CanAsLinearExpr): LinearExpr;

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
        name(): string;
        Clear(): void;
        SetCoefficient(var_: MPVariable, coeff: number): void;
        GetCoefficient(var_: MPVariable): number;
        terms(): { [key: string]: number };
        lb(): number;
        ub(): number;
        SetLB(lb: number): void;
        SetUB(ub: number): void;
        SetBounds(lb: number, ub: number): void;
        is_lazy(): boolean;
        set_is_lazy(laziness: boolean): void;
        indicator_variable(): MPVariable;
        indicator_value(): boolean;
        index(): number;
        dual_value(): number;
        basis_status(): MPSolver.BasisStatus;
    };

    export class MPObjective
    {
        Clear(): void;
        SetCoefficient(var_: MPVariable, coeff: number): void;
        GetCoefficient(var_: MPVariable): number;
        terms(): { [key: string]: number };
        SetOffset(value: number): void;
        offset(): number;
        OptimizeLinearExpr(linear_expr: LinearExpr, is_maximization: boolean): void;
        MaximizeLinearExpr(linear_expr: LinearExpr): void;
        MinimizeLinearExpr(linear_expr: LinearExpr): void;
        AddLinearExpr(linear_expr: LinearExpr): void;
        SetOptimizationDirection(maximize: boolean): void;
        SetMinimization(): void;
        SetMaximization(): void;
        maximization(): boolean;
        minimization(): boolean;
        Value(): number;
        BestBound(): number;
    };

    export namespace MPSolverParameters
    {
        export enum DoubleParam
        {
            RELATIVE_MIP_GAP = 0,
            PRIMAL_TOLERANCE = 1,
            DUAL_TOLERANCE = 2
        };
        export enum IntegerParam
        {
            PRESOLVE = 1000,
            LP_ALGORITHM = 1001,
            INCREMENTALITY = 1002,
            SCALING = 1003
        };
        export enum PresolveValues
        {
            PRESOLVE_OFF = 0,
            PRESOLVE_ON = 1
        };
        export enum LpAlgorithmValues
        {
            DUAL = 10,
            PRIMAL = 11,
            BARRIER = 12
        };
        export enum IncrementalityValues
        {
            INCREMENTALITY_OFF = 0,
            INCREMENTALITY_ON = 1
        };
        export enum ScalingValues
        {
            SCALING_OFF = 0,
            SCALING_ON = 1
        };
    }
    export class MPSolverParameters
    {
        static readonly kDefaultDoubleParamValue: number;
        static readonly kDefaultIntegerParamValue: number;
        static readonly kUnknownDoubleParamValue: number;
        static readonly kUnknownIntegerParamValue: number;
        static readonly kDefaultRelativeMipGap: number;
        static readonly kDefaultPrimalTolerance: number;
        static readonly kDefaultDualTolerance: number;
        static readonly kDefaultPresolve: MPSolverParameters.PresolveValues;
        static readonly kDefaultIncrementality: MPSolverParameters.IncrementalityValues;

        SetDoubleParam(param: MPSolverParameters.DoubleParam, value: number): void;
        SetIntegerParam(param: MPSolverParameters.IntegerParam, value: number): void;
        ResetDoubleParam(param: MPSolverParameters.DoubleParam): void;
        ResetIntegerParam(param: MPSolverParameters.IntegerParam): void;
        Reset(): void;
        GetDoubleParam(param: MPSolverParameters.DoubleParam): number;
        GetIntegerParam(param: MPSolverParameters.IntegerParam): number;
    };

    export type CanAsLinearExpr = LinearExpr | number | MPVariable;

    export class LinearExpr
    {
        static NotVar(var_: LinearExpr): LinearExpr;
        operator_plus_equals(rhs: CanAsLinearExpr): LinearExpr;
        operator_minus_equals(rhs: CanAsLinearExpr): LinearExpr;
        operator_times_equals(rhs: number): LinearExpr;
        operator_divide_equals(rhs: number): LinearExpr;
        operator_negate(): LinearExpr;
        offset(): number;
        terms(): { [key: string]: number };
        SolutionValue(): number;
        ToString(): string;
    };

    export namespace sat
    {
        export class CpModelBuilder
        {
            //void SetName(absl::string_view name);
            //IntVar NewIntVar(const Domain &domain);
            //BoolVar NewBoolVar();
            //IntVar NewConstant(int64_t value);
            //BoolVar TrueVar();
            //BoolVar FalseVar();
            //IntervalVar NewIntervalVar(const LinearExpr &start, const LinearExpr &size, const LinearExpr &end);
            //IntervalVar NewFixedSizeIntervalVar(const LinearExpr &start, int64_t size);
            //IntervalVar NewOptionalIntervalVar(const LinearExpr &start, const LinearExpr &size, const LinearExpr &end, BoolVar presence);
            //IntervalVar NewOptionalFixedSizeIntervalVar(const LinearExpr &start, int64_t size, BoolVar presence);
            //void FixVariable(IntVar var, int64_t value);
            //void FixVariable(BoolVar var, bool value);
            //Constraint AddBoolOr(absl::Span<const BoolVar> literals);
            //Constraint AddAtLeastOne(absl::Span<const BoolVar> literals);
            //Constraint AddAtMostOne(absl::Span<const BoolVar> literals);
            //Constraint AddExactlyOne(absl::Span<const BoolVar> literals);
            //Constraint AddBoolAnd(absl::Span<const BoolVar> literals);
            //Constraint AddBoolXor(absl::Span<const BoolVar> literals);
            //Constraint AddImplication(BoolVar a, BoolVar b);
            //Constraint AddImplication(absl::Span<const BoolVar> lhs, absl::Span<const BoolVar> rhs);
            //Constraint AddEquality(const LinearExpr &left, const LinearExpr &right);
            //Constraint AddGreaterOrEqual(const LinearExpr &left, const LinearExpr &right);
            //Constraint AddGreaterThan(const LinearExpr &left, const LinearExpr &right);
            //Constraint AddLessOrEqual(const LinearExpr &left, const LinearExpr &right);
            //Constraint AddLessThan(const LinearExpr &left, const LinearExpr &right);
            //Constraint AddLinearConstraint(const LinearExpr &expr, const Domain &domain);
            //Constraint AddNotEqual(const LinearExpr &left, const LinearExpr &right);
            //Constraint AddAllDifferent(absl::Span<const IntVar> vars);
            //Constraint AddAllDifferent(absl::Span<const LinearExpr> exprs);
            //Constraint AddAllDifferent(std::initializer_list<LinearExpr> exprs);
            //Constraint AddVariableElement(IntVar index, absl::Span<const IntVar> variables, IntVar target);
            //Constraint AddElement(IntVar index, absl::Span<const int64_t> values, IntVar target);
            //CircuitConstraint AddCircuitConstraint();
            //MultipleCircuitConstraint AddMultipleCircuitConstraint();
            //TableConstraint AddAllowedAssignments(absl::Span<const IntVar> vars);
            //TableConstraint AddForbiddenAssignments(absl::Span<const IntVar> vars);
            //Constraint AddInverseConstraint(absl::Span<const IntVar> variables, absl::Span<const IntVar> inverse_variables);
            //ReservoirConstraint AddReservoirConstraint(int64_t min_level, int64_t max_level);
            //AutomatonConstraint AddAutomaton(absl::Span<const IntVar> transition_variables, int starting_state, absl::Span<const int> final_states);
            //Constraint AddMinEquality(const LinearExpr &target, absl::Span<const IntVar> vars);
            //Constraint AddMinEquality(const LinearExpr &target, absl::Span<const LinearExpr> exprs);
            //Constraint AddMinEquality(const LinearExpr &target, std::initializer_list<LinearExpr> exprs);
            //Constraint AddMaxEquality(const LinearExpr &target, absl::Span<const IntVar> vars);
            //Constraint AddMaxEquality(const LinearExpr &target, absl::Span<const LinearExpr> exprs);
            //Constraint AddMaxEquality(const LinearExpr &target, std::initializer_list<LinearExpr> exprs);
            //Constraint AddDivisionEquality(const LinearExpr &target, const LinearExpr &numerator, const LinearExpr &denominator);
            //Constraint AddAbsEquality(const LinearExpr &target, const LinearExpr &expr);
            //Constraint AddModuloEquality(const LinearExpr &target, const LinearExpr &var, const LinearExpr &mod);
            //Constraint AddMultiplicationEquality(const LinearExpr &target, absl::Span<const LinearExpr> exprs);
            //Constraint AddMultiplicationEquality(const LinearExpr &target, absl::Span<const IntVar> vars);
            //Constraint AddMultiplicationEquality(const LinearExpr &target, std::initializer_list<LinearExpr> exprs);
            //Constraint AddMultiplicationEquality(const LinearExpr &target, const LinearExpr &left, const LinearExpr &right);
            //Constraint AddNoOverlap(absl::Span<const IntervalVar> vars);
            //NoOverlap2DConstraint AddNoOverlap2D();
            //CumulativeConstraint AddCumulative(LinearExpr capacity);
            //void Minimize(const LinearExpr &expr);
            //void Minimize(const DoubleLinearExpr &expr);
            //void Maximize(const LinearExpr &expr);
            //void Maximize(const DoubleLinearExpr &expr);
            //void ClearObjective();
            //bool HasObjective() const;
            //void AddDecisionStrategy(absl::Span<const IntVar> variables, DecisionStrategyProto::VariableSelectionStrategy var_strategy, DecisionStrategyProto::DomainReductionStrategy domain_strategy);
            //void AddDecisionStrategy(absl::Span<const BoolVar> variables, DecisionStrategyProto::VariableSelectionStrategy var_strategy, DecisionStrategyProto::DomainReductionStrategy domain_strategy);
            //void AddDecisionStrategy(absl::Span<const LinearExpr> expressions, DecisionStrategyProto::VariableSelectionStrategy var_strategy, DecisionStrategyProto::DomainReductionStrategy domain_strategy);
            //void AddDecisionStrategy(std::initializer_list<LinearExpr> expressions, DecisionStrategyProto::VariableSelectionStrategy var_strategy, DecisionStrategyProto::DomainReductionStrategy domain_strategy);
            //void AddHint(IntVar var, int64_t value);
            //void AddHint(BoolVar var, bool value);
            //void ClearHints();
            //void AddAssumption(BoolVar lit);
            //void AddAssumptions(absl::Span<const BoolVar> literals);
            //void ClearAssumptions();
            //const CpModelProto &Build() const;
            //const CpModelProto &Proto() const;
            //CpModelProto *MutableProto();
            //bool ExportToFile(absl::string_view filename) const;
            //CpModelBuilder Clone() const;
            //BoolVar GetBoolVarFromProtoIndex(int index);
            //IntVar GetIntVarFromProtoIndex(int index);
            //IntervalVar GetIntervalVarFromProtoIndex(int index);
        };
    }
};

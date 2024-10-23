export namespace operations_research
{
    export function operator_le(lhs: CanAsLinearExpr, rhs: CanAsLinearExpr): LinearRange;
    export function operator_eq(lhs: CanAsLinearExpr, rhs: CanAsLinearExpr): LinearRange;
    export function operator_ge(lhs: CanAsLinearExpr, rhs: CanAsLinearExpr): LinearRange;
    export function operator_times(lhs: CanAsLinearExpr, rhs: number): LinearExpr;
    export function operator_times(lhs: number, rhs: CanAsLinearExpr): LinearExpr;

    export class Domain
    {
        constructor()
        constructor(value: number)
        constructor(left: number, right: number)
        AllValues(): Domain;
        FromValues(values: number[]): Domain;
        FromIntervals(intervals: ClosedInterval[]): Domain;
        FromFlatSpanOfIntervals(flat_intervals: number[]): Domain;
        FromVectorIntervals(intervals: number[][]): Domain;
        FromFlatIntervals(flat_intervals: number[]): Domain;
        FlattenedIntervals(): number[];
        IsEmpty(): boolean;
        Size(): number;
        HasTwoValues(): boolean;
        Min(): number;
        Max(): number;
        SmallestValue(): number;
        ClosestValue(wanted: number): number;
        ValueAtOrBefore(input: number): number;
        ValueAtOrAfter(input: number): number;
        PartAroundZero(): Domain;
        IsFixed(): boolean;
        FixedValue(): number;
        Contains(value: number): boolean;
        Distance(value: number): number;
        IsIncludedIn(domain: Domain): boolean;
        Complement(): Domain;
        Negation(): Domain;
        IntersectionWith(domain: Domain): Domain;
        UnionWith(domain: Domain): Domain;
        AdditionWith(domain: Domain): Domain;
        MultiplicationBy(coeff: number): { return: Domain, exact: boolean };
        RelaxIfTooComplex(): Domain;
        ContinuousMultiplicationBy(coeff: number): Domain;
        ContinuousMultiplicationBy(domain: Domain): Domain;
        DivisionBy(coeff: number): Domain;
        InverseMultiplicationBy(coeff: number): Domain;
        PositiveModuloBySuperset(modulo: Domain): Domain;
        PositiveDivisionBySuperset(divisor: Domain): Domain;
        SquareSuperset(): Domain;
        SimplifyUsingImpliedDomain(implied_domain: Domain): Domain;
        ToString(): string;
        operator_lt(domain: Domain): boolean;
        operator_eq(domain: Domain): boolean;
        operator_nq(domain: Domain): boolean;
        NumIntervals(): number;
        operator_brackets(i: number): ClosedInterval;
    };

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
        constructor(lower_bound: number, linear_expr: CanAsLinearExpr, upper_bound: number);

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
        OptimizeLinearExpr(linear_expr: CanAsLinearExpr, is_maximization: boolean): void;
        MaximizeLinearExpr(linear_expr: CanAsLinearExpr): void;
        MinimizeLinearExpr(linear_expr: CanAsLinearExpr): void;
        AddLinearExpr(linear_expr: CanAsLinearExpr): void;
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
        static NotVar(var_: CanAsLinearExpr): LinearExpr;
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

    export class ClosedInterval
    {
        DebugString(): string;
        operator_eq(other: ClosedInterval): boolean;
        operator_lt(other: ClosedInterval): boolean;
        start: number = 0;
        end: number = 0;
    };

    export namespace sat
    {
        export enum CpSolverStatus
        {
            UNKNOWN = 0,
            MODEL_INVALID = 1,
            FEASIBLE = 2,
            INFEASIBLE = 3,
            OPTIMAL = 4,
        };

        export function operator_nagate(expr: CanAsLinearExpr): LinearExpr;
        export function operator_plus(exprs: CanAsLinearExpr[]): LinearExpr;
        export function operator_minus(lhs: CanAsLinearExpr, rhs: CanAsLinearExpr): LinearExpr;
        export function operator_times(expr: CanAsLinearExpr, factor: number): LinearExpr;
        export function operator_times(factor: number, expr: CanAsLinearExpr): LinearExpr;
        export function Solve(model_proto: CpModelProto): CpSolverResponse;
        export function SolutionIntegerValue(response: CpSolverResponse, expr: CanAsLinearExpr): number;
        export function CpSolverResponseStats(response: CpSolverResponse, has_objective: boolean = true): string;

        export class CpSolverResponse
        {
            status(): CpSolverStatus;
            objective_value(): number;
        }

        export class CpModelBuilder
        {
            SetName(name: string): void;
            NewIntVar(domain: Domain): IntVar;
            NewBoolVar(): BoolVar;
            NewConstant(value: number): IntVar;
            TrueVar(): BoolVar;
            FalseVar(): BoolVar;
            NewIntervalVar(start: CanAsLinearExpr, size: CanAsLinearExpr, end: CanAsLinearExpr): IntervalVar;
            NewFixedSizeIntervalVar(start: CanAsLinearExpr, size: number): IntervalVar;
            NewOptionalIntervalVar(start: CanAsLinearExpr, size: CanAsLinearExpr, end: CanAsLinearExpr, presence: BoolVar): IntervalVar;
            NewOptionalFixedSizeIntervalVar(start: CanAsLinearExpr, size: number, presence: BoolVar): IntervalVar;
            FixVariable(var_: IntVar, value: number): void;
            FixVariable(var_: BoolVar, value: boolean): void;
            AddBoolOr(literals: Array<BoolVar>): Constraint;
            AddAtLeastOne(literals: Array<BoolVar>): Constraint;
            AddAtMostOne(literals: Array<BoolVar>): Constraint;
            AddExactlyOne(literals: Array<BoolVar>): Constraint;
            AddBoolAnd(literals: Array<BoolVar>): Constraint;
            AddBoolXor(literals: Array<BoolVar>): Constraint;
            AddImplication(a: BoolVar, b: BoolVar): Constraint;
            AddImplication(lhs: Array<BoolVar>, rhs: Array<BoolVar>): Constraint;
            AddEquality(left: CanAsLinearExpr, right: CanAsLinearExpr): Constraint;
            AddGreaterOrEqual(left: CanAsLinearExpr, right: CanAsLinearExpr): Constraint;
            AddGreaterThan(left: CanAsLinearExpr, right: CanAsLinearExpr): Constraint;
            AddLessOrEqual(left: CanAsLinearExpr, right: CanAsLinearExpr): Constraint;
            AddLessThan(left: CanAsLinearExpr, right: CanAsLinearExpr): Constraint;
            AddLinearConstraint(expr: CanAsLinearExpr, domain: Domain): Constraint;
            AddNotEqual(left: CanAsLinearExpr, right: CanAsLinearExpr): Constraint;
            AddAllDifferent(exprs: Array<CanAsLinearExpr>): Constraint;
            AddVariableElement(index: IntVar, variables: Array<IntVar>, target: IntVar): Constraint;
            AddElement(index: IntVar, values: Array<number>, target: IntVar): Constraint;
            AddCircuitConstraint(): CircuitConstraint;
            AddMultipleCircuitConstraint(): MultipleCircuitConstraint;
            AddAllowedAssignments(vars: Array<IntVar>): TableConstraint;
            AddForbiddenAssignments(vars: Array<IntVar>): TableConstraint;
            AddInverseConstraint(variables: Array<IntVar>, inverse_variables: Array<IntVar>): Constraint;
            AddReservoirConstraint(min_level: number, max_level: number): ReservoirConstraint;
            AddAutomaton(transition_variables: Array<IntVar>, starting_state: number, final_states: Array<number>): AutomatonConstraint;
            AddMinEquality(target: CanAsLinearExpr, exprs: Array<CanAsLinearExpr>): Constraint;
            AddMaxEquality(target: CanAsLinearExpr, exprs: Array<CanAsLinearExpr>): Constraint;
            AddDivisionEquality(target: CanAsLinearExpr, numerator: CanAsLinearExpr, denominator: CanAsLinearExpr): Constraint;
            AddAbsEquality(target: CanAsLinearExpr, expr: CanAsLinearExpr): Constraint;
            AddModuloEquality(target: CanAsLinearExpr, var_: CanAsLinearExpr, mod: CanAsLinearExpr): Constraint;
            AddMultiplicationEquality(target: CanAsLinearExpr, exprs: Array<CanAsLinearExpr>): Constraint;
            AddMultiplicationEquality(target: CanAsLinearExpr, left: CanAsLinearExpr, right: CanAsLinearExpr): Constraint;
            AddNoOverlap(vars: Array<IntervalVar>): Constraint;
            AddNoOverlap2D(): NoOverlap2DConstraint;
            AddCumulative(capacity: CanAsLinearExpr): CumulativeConstraint;
            Minimize(expr: CanAsLinearExpr): void;
            //Minimize(expr: DoubleLinearExpr): void;
            Maximize(expr: CanAsLinearExpr): void;
            //Maximize(expr: DoubleLinearExpr): void;
            ClearObjective(): void;
            HasObjective(): boolean;
            AddDecisionStrategy(variables: Array<IntVar>, var_strategy: DecisionStrategyProto.VariableSelectionStrategy, domain_strategy: DecisionStrategyProto.DomainReductionStrategy): void;
            AddDecisionStrategy(variables: Array<BoolVar>, var_strategy: DecisionStrategyProto.VariableSelectionStrategy, domain_strategy: DecisionStrategyProto.DomainReductionStrategy): void;
            AddDecisionStrategy(expressions: Array<CanAsLinearExpr>, var_strategy: DecisionStrategyProto.VariableSelectionStrategy, domain_strategy: DecisionStrategyProto.DomainReductionStrategy): void;
            AddDecisionStrategy(expressions: Array<CanAsLinearExpr>, var_strategy: DecisionStrategyProto.VariableSelectionStrategy, domain_strategy: DecisionStrategyProto.DomainReductionStrategy): void;
            AddHint(var_: IntVar, value: number): void;
            AddHint(var_: BoolVar, value: boolean): void;
            ClearHints(): void;
            AddAssumption(lit: BoolVar): void;
            AddAssumptions(literals: Array<BoolVar>): void;
            ClearAssumptions(): void;
            Build(): CpModelProto;
            Proto(): CpModelProto;
            MutableProto(): CpModelProto;
            ExportToFile(filename: string): boolean;
            Clone(): CpModelBuilder;
            GetBoolVarFromProtoIndex(index: number): BoolVar;
            GetIntVarFromProtoIndex(index: number): IntVar;
            GetIntervalVarFromProtoIndex(index: number): IntervalVar;
        };

        export class IntVar
        {
            constructor()
            constructor(var_: BoolVar)
            ToBoolVar(): BoolVar;
            WithName(name: string): IntVar;
            Name(): string;
            operator_eq(other: IntVar): boolean;
            operator_neq(other: IntVar): boolean;
            Domain(): Domain;
            DebugString(): string;
            index(): number;
        };

        export type CanAsLinearExpr = LinearExpr | BoolVar | number | IntVar;
    }
};

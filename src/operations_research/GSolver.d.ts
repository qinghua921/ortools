
import { Constraint } from "./GConstraint";
import { DecisionBuilder } from "./GDecisionBuilder";
import { SearchMonitor } from "./GSearchMonitor";
import { SequenceVar } from "./GSequenceVar";

export namespace Solver
{
    export enum IntVarStrategy
    {
        INT_VAR_DEFAULT,
        INT_VAR_SIMPLE,
        CHOOSE_FIRST_UNBOUND,
        CHOOSE_RANDOM,
        CHOOSE_MIN_SIZE_LOWEST_MIN,
        CHOOSE_MIN_SIZE_HIGHEST_MIN,
        CHOOSE_MIN_SIZE_LOWEST_MAX,
        CHOOSE_MIN_SIZE_HIGHEST_MAX,
        CHOOSE_LOWEST_MIN,
        CHOOSE_HIGHEST_MAX,
        CHOOSE_MIN_SIZE,
        CHOOSE_MAX_SIZE,
        CHOOSE_MAX_REGRET_ON_MIN,
        CHOOSE_PATH,
    };

    export enum IntValueStrategy
    {
        INT_VALUE_DEFAULT,
        INT_VALUE_SIMPLE,
        ASSIGN_MIN_VALUE,
        ASSIGN_MAX_VALUE,
        ASSIGN_RANDOM_VALUE,
        ASSIGN_CENTER_VALUE,
        SPLIT_LOWER_HALF,
        SPLIT_UPPER_HALF,
    };

    export enum SequenceStrategy
    {
        SEQUENCE_DEFAULT,
        SEQUENCE_SIMPLE,
        CHOOSE_MIN_SLACK_RANK_FORWARD,
        CHOOSE_RANDOM_RANK_FORWARD,
    };

    export enum EvaluatorStrategy
    {
        CHOOSE_STATIC_GLOBAL_BEST,
        CHOOSE_DYNAMIC_GLOBAL_BEST,
    };

    export enum IntervalStrategy
    {
        INTERVAL_DEFAULT,
        INTERVAL_SIMPLE,
        INTERVAL_SET_TIMES_FORWARD,
        INTERVAL_SET_TIMES_BACKWARD
    };

    export enum LocalSearchOperators
    {
        TWOOPT,
        OROPT,
        RELOCATE,
        EXCHANGE,
        CROSS,
        MAKEACTIVE,
        MAKEINACTIVE,
        MAKECHAININACTIVE,
        SWAPACTIVE,
        EXTENDEDSWAPACTIVE,
        PATHLNS,
        FULLPATHLNS,
        UNACTIVELNS,
        INCREMENT,
        DECREMENT,
        SIMPLELNS
    };

    export enum EvaluatorLocalSearchOperators
    {
        LK,
        TSPOPT,
        TSPLNS
    };

    export enum LocalSearchFilterBound
    {
        GE,
        LE,
        EQ
    };

    export enum DemonPriority
    {
        DELAYED_PRIORITY = 0,
        VAR_PRIORITY = 1,
        NORMAL_PRIORITY = 2,
    };

    export enum BinaryIntervalRelation
    {
        ENDS_AFTER_END,
        ENDS_AFTER_START,
        ENDS_AT_END,
        ENDS_AT_START,
        STARTS_AFTER_END,
        STARTS_AFTER_START,
        STARTS_AT_END,
        STARTS_AT_START,
        STAYS_IN_SYNC
    };

    export enum UnaryIntervalRelation
    {
        ENDS_AFTER,
        ENDS_AT,
        ENDS_BEFORE,
        STARTS_AFTER,
        STARTS_AT,
        STARTS_BEFORE,
        CROSS_DATE,
        AVOID_DATE
    };

    export enum DecisionModification
    {
        NO_CHANGE,
        KEEP_LEFT,
        KEEP_RIGHT,
        KILL_BOTH,
        SWITCH_BRANCHES
    };

    export enum MarkerType { SENTINEL, SIMPLE_MARKER, CHOICE_POINT, REVERSIBLE_ACTION };

    export enum SolverState
    {
        OUTSIDE_SEARCH,
        IN_ROOT_NODE,
        IN_SEARCH,
        AT_SOLUTION,
        NO_MORE_SOLUTIONS,
        PROBLEM_INFEASIBLE
    };

    export enum OptimizationDirection { NOT_SET, MAXIMIZATION, MINIMIZATION };

}

//      typedef std::function<int64_t(int64_t)> IndexEvaluator1;
type IndexEvaluator1 = (index: number) => number;
//      typedef std::function<int64_t(int64_t, int64_t)> IndexEvaluator2;
type IndexEvaluator2 = (index1: number, index2: number) => number;
//      typedef std::function<int64_t(int64_t, int64_t, int64_t)> IndexEvaluator3;
type IndexEvaluator3 = (index1: number, index2: number, index3: number) => number;

//      typedef std::function<bool(int64_t)> IndexFilter1;
type IndexFilter1 = (index: number) => boolean;
//      typedef std::function<IntVar*(int64_t)> Int64ToIntVar;
type Int64ToIntVar = (index: number) => IntVar;

//      typedef std::function<int64_t(Solver* solver,
//                                    const std::vector<IntVar*>& vars,
//                                    int64_t first_unbound, int64_t last_unbound)>
//          VariableIndexSelector;
type VariableIndexSelector = (solver: Solver, vars: IntVar[], first_unbound: number, last_unbound: number) => number;

//      typedef std::function<int64_t(const IntVar* v, int64_t id)>
//          VariableValueSelector;
type VariableValueSelector = (v: IntVar, id: number) => number;
//      typedef std::function<bool(int64_t, int64_t, int64_t)>
//          VariableValueComparator;
type VariableValueComparator = (index1: number, index2: number, index3: number) => boolean;
//      typedef std::function<DecisionModification()> BranchSelector;
type BranchSelector = () => DecisionModification;
//      // TODO(user): wrap in swig.
//      typedef std::function<void(Solver*)> Action;
//      typedef std::function<void()> Closure;

/// For the time being, Solver is neither MT_SAFE nor MT_HOT.
export class Solver
{
    //     public:
    //      struct IntegerCastInfo {
    //        IntegerCastInfo()
    //            : variable(nullptr), expression(nullptr), maintainer(nullptr) {}
    //        IntegerCastInfo(IntVar* const v, IntExpr* const e, Constraint* const c)
    //            : variable(v), expression(e), maintainer(c) {}
    //        IntVar* variable;
    //        IntExpr* expression;
    //        Constraint* maintainer;
    //      };

    //      static constexpr int kNumPriorities = 3;



    //    #ifndef SWIG
    //      enum class MonitorEvent : int {
    //        kEnterSearch = 0,
    //        kRestartSearch,
    //        kExitSearch,
    //        kBeginNextDecision,
    //        kEndNextDecision,
    //        kApplyDecision,
    //        kRefuteDecision,
    //        kAfterDecision,
    //        kBeginFail,
    //        kEndFail,
    //        kBeginInitialPropagation,
    //        kEndInitialPropagation,
    //        kAcceptSolution,
    //        kAtSolution,
    //        kNoMoreSolutions,
    //        kLocalOptimum,
    //        kAcceptDelta,
    //        kAcceptNeighbor,
    //        kAcceptUncheckedNeighbor,
    //        kIsUncheckedSolutionLimitReached,
    //        kPeriodicCheck,
    //        kProgressPercent,
    //        kAccept,
    //        // Dummy event whose underlying int is the number of MonitorEvent enums.
    //        kLast,
    //      };
    //    #endif  // SWIG



    //      explicit Solver(const std::string& name);
    constructor(name: string);

    //      Solver(const std::string& name, const ConstraintSolverParameters& parameters);
    //      ~Solver();

    //      ConstraintSolverParameters parameters() const { return parameters_; }
    //      // Read-only.
    //      const ConstraintSolverParameters& const_parameters() const {
    //        return parameters_;
    //      }
    //      // TODO(user): Move to constraint_solver_parameters.h.
    //      static ConstraintSolverParameters DefaultSolverParameters();


    //      template <class T>
    //      void SaveValue(T* o) {
    //        InternalSaveValue(o);
    //      }

    //      template <typename T>
    //      T* RevAlloc(T* object) {
    //        return reinterpret_cast<T*>(SafeRevAlloc(object));
    //      }

    //      template <typename T>
    //      T* RevAllocArray(T* object) {
    //        return reinterpret_cast<T*>(SafeRevAllocArray(object));
    //      }

    //      void AddConstraint(Constraint* const c);
    AddConstraint(c: Constraint): void;

    //      void AddCastConstraint(CastConstraint* const constraint,
    //                             IntVar* const target_var, IntExpr* const expr);

    //      bool Solve(DecisionBuilder* const db,
    //                 const std::vector<SearchMonitor*>& monitors);
    //      bool Solve(DecisionBuilder* const db);
    //      bool Solve(DecisionBuilder* const db, SearchMonitor* const m1);
    //      bool Solve(DecisionBuilder* const db, SearchMonitor* const m1,
    //                 SearchMonitor* const m2);
    //      bool Solve(DecisionBuilder* const db, SearchMonitor* const m1,
    //                 SearchMonitor* const m2, SearchMonitor* const m3);
    //      bool Solve(DecisionBuilder* const db, SearchMonitor* const m1,
    //                 SearchMonitor* const m2, SearchMonitor* const m3,
    //                 SearchMonitor* const m4);


    //      void NewSearch(DecisionBuilder* const db,
    //                     const std::vector<SearchMonitor*>& monitors);
    NewSearch(db: DecisionBuilder, monitors: SearchMonitor[]): void;
    //      void NewSearch(DecisionBuilder* const db);
    NewSearch(db: DecisionBuilder): void;
    //      void NewSearch(DecisionBuilder* const db, SearchMonitor* const m1);
    NewSearch(db: DecisionBuilder, m1: SearchMonitor): void;
    //      void NewSearch(DecisionBuilder* const db, SearchMonitor* const m1,
    //                     SearchMonitor* const m2);
    NewSearch(db: DecisionBuilder, m1: SearchMonitor, m2: SearchMonitor): void;
    //      void NewSearch(DecisionBuilder* const db, SearchMonitor* const m1,
    //                     SearchMonitor* const m2, SearchMonitor* const m3);
    NewSearch(db: DecisionBuilder, m1: SearchMonitor, m2: SearchMonitor, m3: SearchMonitor): void;
    //      void NewSearch(DecisionBuilder* const db, SearchMonitor* const m1,
    //                     SearchMonitor* const m2, SearchMonitor* const m3,
    //                     SearchMonitor* const m4);
    NewSearch(db: DecisionBuilder, m1: SearchMonitor, m2: SearchMonitor, m3: SearchMonitor, m4: SearchMonitor): void;

    //      bool NextSolution();
    NextSolution(): boolean;

    //      void RestartSearch();
    //      void EndSearch();
    EndSearch(): void;


    //      bool SolveAndCommit(DecisionBuilder* const db,
    //                          const std::vector<SearchMonitor*>& monitors);
    //      bool SolveAndCommit(DecisionBuilder* const db);
    //      bool SolveAndCommit(DecisionBuilder* const db, SearchMonitor* const m1);
    //      bool SolveAndCommit(DecisionBuilder* const db, SearchMonitor* const m1,
    //                          SearchMonitor* const m2);
    //      bool SolveAndCommit(DecisionBuilder* const db, SearchMonitor* const m1,
    //                          SearchMonitor* const m2, SearchMonitor* const m3);

    //      bool CheckAssignment(Assignment* const solution);

    //      bool CheckConstraint(Constraint* const ct);

    //      SolverState state() const { return state_; }

    //      void Fail();

    //    #if !defined(SWIG)
    //      void AddBacktrackAction(Action a, bool fast);
    //    #endif  /// !defined(SWIG)

    //      std::string DebugString() const;

    //      static int64_t MemoryUsage();
    static MemoryUsage(): number;

    //      absl::Time Now() const;

    //      int64_t wall_time() const;
    wall_time(): number;

    //      int64_t branches() const { return branches_; }

    //      int64_t solutions() const;
    solutions(): number;

    //      int64_t unchecked_solutions() const;

    //      int64_t demon_runs(DemonPriority p) const { return demon_runs_[p]; }

    //      int64_t failures() const { return fails_; }

    //      int64_t neighbors() const { return neighbors_; }

    //      int64_t filtered_neighbors() const { return filtered_neighbors_; }

    //      int64_t accepted_neighbors() const { return accepted_neighbors_; }

    //      uint64_t stamp() const;

    //      uint64_t fail_stamp() const;

    //      void set_context(const std::string& context) { context_ = context; }

    //      const std::string& context() const { return context_; }

    //      OptimizationDirection optimization_direction() const {
    //        return optimization_direction_;
    //      }
    //      void set_optimization_direction(OptimizationDirection direction) {
    //        optimization_direction_ = direction;
    //      }

    //      IntVar* MakeIntVar(int64_t min, int64_t max, const std::string& name);
    MakeIntVar(min: number, max: number, name: string): IntVar;

    //      IntVar* MakeIntVar(const std::vector<int64_t>& values,
    //                         const std::string& name);
    //      IntVar* MakeIntVar(const std::vector<int>& values, const std::string& name);
    MakeIntVar(values: number[], name: string): IntVar;

    //      IntVar* MakeIntVar(int64_t min, int64_t max);
    MakeIntVar(min: number, max: number): IntVar;

    //      IntVar* MakeIntVar(const std::vector<int64_t>& values);
    //      IntVar* MakeIntVar(const std::vector<int>& values);
    MakeIntVar(values: number[]): IntVar;


    //      IntVar* MakeBoolVar(const std::string& name);

    //      IntVar* MakeBoolVar();

    //      IntVar* MakeIntConst(int64_t val, const std::string& name);

    //      IntVar* MakeIntConst(int64_t val);

    //      void MakeIntVarArray(int var_count, int64_t vmin, int64_t vmax,
    //                           const std::string& name, std::vector<IntVar*>* vars);
    //      void MakeIntVarArray(int var_count, int64_t vmin, int64_t vmax,
    //                           std::vector<IntVar*>* vars);
    //      IntVar** MakeIntVarArray(int var_count, int64_t vmin, int64_t vmax,
    //                               const std::string& name);

    //      void MakeBoolVarArray(int var_count, const std::string& name,
    //                            std::vector<IntVar*>* vars);
    //      void MakeBoolVarArray(int var_count, std::vector<IntVar*>* vars);
    //      IntVar** MakeBoolVarArray(int var_count, const std::string& name);


    //      IntExpr* MakeSum(IntExpr* const left, IntExpr* const right);
    //      IntExpr* MakeSum(IntExpr* const expr, int64_t value);
    //      IntExpr* MakeSum(const std::vector<IntVar*>& vars);

    //      IntExpr* MakeScalProd(const std::vector<IntVar*>& vars,
    //                            const std::vector<int64_t>& coefs);
    //      IntExpr* MakeScalProd(const std::vector<IntVar*>& vars,
    //                            const std::vector<int>& coefs);

    //      IntExpr* MakeDifference(IntExpr* const left, IntExpr* const right);
    //      IntExpr* MakeDifference(int64_t value, IntExpr* const expr);
    //      IntExpr* MakeOpposite(IntExpr* const expr);

    //      IntExpr* MakeProd(IntExpr* const left, IntExpr* const right);
    //      IntExpr* MakeProd(IntExpr* const expr, int64_t value);

    //      IntExpr* MakeDiv(IntExpr* const expr, int64_t value);
    //      IntExpr* MakeDiv(IntExpr* const numerator, IntExpr* const denominator);

    //      IntExpr* MakeAbs(IntExpr* const expr);
    //      IntExpr* MakeSquare(IntExpr* const expr);
    //      IntExpr* MakePower(IntExpr* const expr, int64_t n);

    //      IntExpr* MakeElement(const std::vector<int64_t>& values, IntVar* const index);
    //      IntExpr* MakeElement(const std::vector<int>& values, IntVar* const index);

    //      IntExpr* MakeElement(IndexEvaluator1 values, IntVar* const index);
    //      IntExpr* MakeMonotonicElement(IndexEvaluator1 values, bool increasing,
    //                                    IntVar* const index);
    //      IntExpr* MakeElement(IndexEvaluator2 values, IntVar* const index1,
    //                           IntVar* const index2);

    //      IntExpr* MakeElement(const std::vector<IntVar*>& vars, IntVar* const index);

    //    #if !defined(SWIG)
    //      IntExpr* MakeElement(Int64ToIntVar vars, int64_t range_start,
    //                           int64_t range_end, IntVar* argument);
    //    #endif  // SWIG


    //      template <typename F>
    //      Constraint* MakeLightElement(F values, IntVar* const var, IntVar* const index,
    //                                   std::function<bool()> deep_serialize = nullptr) {
    //        return RevAlloc(new LightIntFunctionElementCt<F>(
    //            this, var, index, std::move(values), std::move(deep_serialize)));
    //      }

    //      template <typename F>
    //      Constraint* MakeLightElement(F values, IntVar* const var,
    //                                   IntVar* const index1, IntVar* const index2,
    //                                   std::function<bool()> deep_serialize = nullptr) {
    //        return RevAlloc(new LightIntIntFunctionElementCt<F>(
    //            this, var, index1, index2, std::move(values),
    //            std::move(deep_serialize)));
    //      }

    //      IntExpr* MakeIndexExpression(const std::vector<IntVar*>& vars, int64_t value);

    //      Constraint* MakeIfThenElseCt(IntVar* const condition,
    //                                   IntExpr* const then_expr,
    //                                   IntExpr* const else_expr,
    //                                   IntVar* const target_var);

    //      IntExpr* MakeMin(const std::vector<IntVar*>& vars);
    //      IntExpr* MakeMin(IntExpr* const left, IntExpr* const right);
    //      IntExpr* MakeMin(IntExpr* const expr, int64_t value);
    //      IntExpr* MakeMin(IntExpr* const expr, int value);

    //      IntExpr* MakeMax(const std::vector<IntVar*>& vars);
    //      IntExpr* MakeMax(IntExpr* const left, IntExpr* const right);
    //      IntExpr* MakeMax(IntExpr* const expr, int64_t value);
    //      IntExpr* MakeMax(IntExpr* const expr, int value);

    //      IntExpr* MakeConvexPiecewiseExpr(IntExpr* expr, int64_t early_cost,
    //                                       int64_t early_date, int64_t late_date,
    //                                       int64_t late_cost);

    //      IntExpr* MakeSemiContinuousExpr(IntExpr* const expr, int64_t fixed_charge,
    //                                      int64_t step);

    //      // TODO(user): Investigate if we can merge all three piecewise linear
    //    #ifndef SWIG
    //      IntExpr* MakePiecewiseLinearExpr(IntExpr* expr,
    //                                       const PiecewiseLinearFunction& f);
    //    #endif

    //      IntExpr* MakeModulo(IntExpr* const x, int64_t mod);

    //      IntExpr* MakeModulo(IntExpr* const x, IntExpr* const mod);

    //      IntExpr* MakeConditionalExpression(IntVar* const condition,
    //                                         IntExpr* const expr,
    //                                         int64_t unperformed_value);

    //      Constraint* MakeTrueConstraint();
    //      Constraint* MakeFalseConstraint();
    //      Constraint* MakeFalseConstraint(const std::string& explanation);

    //      Constraint* MakeIsEqualCstCt(IntExpr* const var, int64_t value,
    //                                   IntVar* const boolvar);
    //      IntVar* MakeIsEqualCstVar(IntExpr* const var, int64_t value);
    //      Constraint* MakeIsEqualCt(IntExpr* const v1, IntExpr* v2, IntVar* const b);
    //      IntVar* MakeIsEqualVar(IntExpr* const v1, IntExpr* v2);
    //      Constraint* MakeEquality(IntExpr* const left, IntExpr* const right);
    //      Constraint* MakeEquality(IntExpr* const expr, int64_t value);
    //      Constraint* MakeEquality(IntExpr* const expr, int value);

    //      Constraint* MakeIsDifferentCstCt(IntExpr* const var, int64_t value,
    //                                       IntVar* const boolvar);
    //      IntVar* MakeIsDifferentCstVar(IntExpr* const var, int64_t value);
    //      IntVar* MakeIsDifferentVar(IntExpr* const v1, IntExpr* const v2);
    //      Constraint* MakeIsDifferentCt(IntExpr* const v1, IntExpr* const v2,
    //                                    IntVar* const b);
    //      Constraint* MakeNonEquality(IntExpr* const left, IntExpr* const right);
    //      Constraint* MakeNonEquality(IntExpr* const expr, int64_t value);
    //      Constraint* MakeNonEquality(IntExpr* const expr, int value);

    //      Constraint* MakeIsLessOrEqualCstCt(IntExpr* const var, int64_t value,
    //                                         IntVar* const boolvar);
    //      IntVar* MakeIsLessOrEqualCstVar(IntExpr* const var, int64_t value);
    //      IntVar* MakeIsLessOrEqualVar(IntExpr* const left, IntExpr* const right);
    //      Constraint* MakeIsLessOrEqualCt(IntExpr* const left, IntExpr* const right,
    //                                      IntVar* const b);
    //      Constraint* MakeLessOrEqual(IntExpr* const left, IntExpr* const right);
    //      Constraint* MakeLessOrEqual(IntExpr* const expr, int64_t value);
    //      Constraint* MakeLessOrEqual(IntExpr* const expr, int value);

    //      Constraint* MakeIsGreaterOrEqualCstCt(IntExpr* const var, int64_t value,
    //                                            IntVar* const boolvar);
    //      IntVar* MakeIsGreaterOrEqualCstVar(IntExpr* const var, int64_t value);
    //      IntVar* MakeIsGreaterOrEqualVar(IntExpr* const left, IntExpr* const right);
    //      Constraint* MakeIsGreaterOrEqualCt(IntExpr* const left, IntExpr* const right,
    //                                         IntVar* const b);
    //      Constraint* MakeGreaterOrEqual(IntExpr* const left, IntExpr* const right);
    //      Constraint* MakeGreaterOrEqual(IntExpr* const expr, int64_t value);
    //      Constraint* MakeGreaterOrEqual(IntExpr* const expr, int value);

    //      Constraint* MakeIsGreaterCstCt(IntExpr* const v, int64_t c, IntVar* const b);
    //      IntVar* MakeIsGreaterCstVar(IntExpr* const var, int64_t value);
    //      IntVar* MakeIsGreaterVar(IntExpr* const left, IntExpr* const right);
    //      Constraint* MakeIsGreaterCt(IntExpr* const left, IntExpr* const right,
    //                                  IntVar* const b);
    //      Constraint* MakeGreater(IntExpr* const left, IntExpr* const right);
    //      Constraint* MakeGreater(IntExpr* const expr, int64_t value);
    //      Constraint* MakeGreater(IntExpr* const expr, int value);

    //      Constraint* MakeIsLessCstCt(IntExpr* const v, int64_t c, IntVar* const b);
    //      IntVar* MakeIsLessCstVar(IntExpr* const var, int64_t value);
    //      IntVar* MakeIsLessVar(IntExpr* const left, IntExpr* const right);
    //      Constraint* MakeIsLessCt(IntExpr* const left, IntExpr* const right,
    //                               IntVar* const b);
    //      Constraint* MakeLess(IntExpr* const left, IntExpr* const right);
    //      Constraint* MakeLess(IntExpr* const expr, int64_t value);
    //      Constraint* MakeLess(IntExpr* const expr, int value);

    //      Constraint* MakeSumLessOrEqual(const std::vector<IntVar*>& vars, int64_t cst);
    //      Constraint* MakeSumGreaterOrEqual(const std::vector<IntVar*>& vars,
    //                                        int64_t cst);
    //      Constraint* MakeSumEquality(const std::vector<IntVar*>& vars, int64_t cst);
    //      Constraint* MakeSumEquality(const std::vector<IntVar*>& vars,
    //                                  IntVar* const var);
    //      Constraint* MakeScalProdEquality(const std::vector<IntVar*>& vars,
    //                                       const std::vector<int64_t>& coefficients,
    //                                       int64_t cst);
    //      Constraint* MakeScalProdEquality(const std::vector<IntVar*>& vars,
    //                                       const std::vector<int>& coefficients,
    //                                       int64_t cst);
    //      Constraint* MakeScalProdEquality(const std::vector<IntVar*>& vars,
    //                                       const std::vector<int64_t>& coefficients,
    //                                       IntVar* const target);
    //      Constraint* MakeScalProdEquality(const std::vector<IntVar*>& vars,
    //                                       const std::vector<int>& coefficients,
    //                                       IntVar* const target);
    //      Constraint* MakeScalProdGreaterOrEqual(const std::vector<IntVar*>& vars,
    //                                             const std::vector<int64_t>& coeffs,
    //                                             int64_t cst);
    //      Constraint* MakeScalProdGreaterOrEqual(const std::vector<IntVar*>& vars,
    //                                             const std::vector<int>& coeffs,
    //                                             int64_t cst);
    //      Constraint* MakeScalProdLessOrEqual(const std::vector<IntVar*>& vars,
    //                                          const std::vector<int64_t>& coefficients,
    //                                          int64_t cst);
    //      Constraint* MakeScalProdLessOrEqual(const std::vector<IntVar*>& vars,
    //                                          const std::vector<int>& coefficients,
    //                                          int64_t cst);

    //      Constraint* MakeMinEquality(const std::vector<IntVar*>& vars,
    //                                  IntVar* const min_var);
    //      Constraint* MakeMaxEquality(const std::vector<IntVar*>& vars,
    //                                  IntVar* const max_var);

    //      Constraint* MakeElementEquality(const std::vector<int64_t>& vals,
    //                                      IntVar* const index, IntVar* const target);
    //      Constraint* MakeElementEquality(const std::vector<int>& vals,
    //                                      IntVar* const index, IntVar* const target);
    //      Constraint* MakeElementEquality(const std::vector<IntVar*>& vars,
    //                                      IntVar* const index, IntVar* const target);
    //      Constraint* MakeElementEquality(const std::vector<IntVar*>& vars,
    //                                      IntVar* const index, int64_t target);
    //      Constraint* MakeAbsEquality(IntVar* const var, IntVar* const abs_var);
    //      Constraint* MakeIndexOfConstraint(const std::vector<IntVar*>& vars,
    //                                        IntVar* const index, int64_t target);

    //      Demon* MakeConstraintInitialPropagateCallback(Constraint* const ct);
    //      Demon* MakeDelayedConstraintInitialPropagateCallback(Constraint* const ct);
    //    #if !defined(SWIG)
    //      Demon* MakeActionDemon(Action action);
    //    #endif  /// !defined(SWIG)
    //      Demon* MakeClosureDemon(Closure closure);

    //      // ----- Between and related constraints -----

    //      Constraint* MakeBetweenCt(IntExpr* const expr, int64_t l, int64_t u);

    //      Constraint* MakeNotBetweenCt(IntExpr* const expr, int64_t l, int64_t u);

    //      Constraint* MakeIsBetweenCt(IntExpr* const expr, int64_t l, int64_t u,
    //                                  IntVar* const b);
    //      IntVar* MakeIsBetweenVar(IntExpr* const v, int64_t l, int64_t u);

    //      // ----- Member and related constraints -----

    //      Constraint* MakeMemberCt(IntExpr* const expr,
    //                               const std::vector<int64_t>& values);
    //      Constraint* MakeMemberCt(IntExpr* const expr, const std::vector<int>& values);

    //      Constraint* MakeNotMemberCt(IntExpr* const expr,
    //                                  const std::vector<int64_t>& values);
    //      Constraint* MakeNotMemberCt(IntExpr* const expr,
    //                                  const std::vector<int>& values);

    //      Constraint* MakeNotMemberCt(IntExpr* const expr, std::vector<int64_t> starts,
    //                                  std::vector<int64_t> ends);
    //      Constraint* MakeNotMemberCt(IntExpr* const expr, std::vector<int> starts,
    //                                  std::vector<int> ends);
    //    #if !defined(SWIG)
    //      Constraint* MakeNotMemberCt(IntExpr* expr,
    //                                  SortedDisjointIntervalList intervals);
    //    #endif  // !defined(SWIG)

    //      Constraint* MakeIsMemberCt(IntExpr* const expr,
    //                                 const std::vector<int64_t>& values,
    //                                 IntVar* const boolvar);
    //      Constraint* MakeIsMemberCt(IntExpr* const expr,
    //                                 const std::vector<int>& values,
    //                                 IntVar* const boolvar);
    //      IntVar* MakeIsMemberVar(IntExpr* const expr,
    //                              const std::vector<int64_t>& values);
    //      IntVar* MakeIsMemberVar(IntExpr* const expr, const std::vector<int>& values);

    //      Constraint* MakeAtMost(std::vector<IntVar*> vars, int64_t value,
    //                             int64_t max_count);
    //      Constraint* MakeCount(const std::vector<IntVar*>& vars, int64_t value,
    //                            int64_t max_count);
    //      Constraint* MakeCount(const std::vector<IntVar*>& vars, int64_t value,
    //                            IntVar* const max_count);

    //      Constraint* MakeDistribute(const std::vector<IntVar*>& vars,
    //                                 const std::vector<int64_t>& values,
    //                                 const std::vector<IntVar*>& cards);
    //      Constraint* MakeDistribute(const std::vector<IntVar*>& vars,
    //                                 const std::vector<int>& values,
    //                                 const std::vector<IntVar*>& cards);
    //      Constraint* MakeDistribute(const std::vector<IntVar*>& vars,
    //                                 const std::vector<IntVar*>& cards);
    //      Constraint* MakeDistribute(const std::vector<IntVar*>& vars, int64_t card_min,
    //                                 int64_t card_max, int64_t card_size);
    //      Constraint* MakeDistribute(const std::vector<IntVar*>& vars,
    //                                 const std::vector<int64_t>& card_min,
    //                                 const std::vector<int64_t>& card_max);
    //      Constraint* MakeDistribute(const std::vector<IntVar*>& vars,
    //                                 const std::vector<int>& card_min,
    //                                 const std::vector<int>& card_max);
    //      Constraint* MakeDistribute(const std::vector<IntVar*>& vars,
    //                                 const std::vector<int64_t>& values,
    //                                 const std::vector<int64_t>& card_min,
    //                                 const std::vector<int64_t>& card_max);
    //      Constraint* MakeDistribute(const std::vector<IntVar*>& vars,
    //                                 const std::vector<int>& values,
    //                                 const std::vector<int>& card_min,
    //                                 const std::vector<int>& card_max);

    //      Constraint* MakeDeviation(const std::vector<IntVar*>& vars,
    //                                IntVar* const deviation_var, int64_t total_sum);

    //      Constraint* MakeAllDifferent(const std::vector<IntVar*>& vars);
    MakeAllDifferent(vars: IntVar[]): Constraint;

    //      Constraint* MakeAllDifferent(const std::vector<IntVar*>& vars,
    //                                   bool stronger_propagation);
    MakeAllDifferent(vars: IntVar[], stronger_propagation: boolean): Constraint;

    //      Constraint* MakeAllDifferentExcept(const std::vector<IntVar*>& vars,
    //                                         int64_t escape_value);
    //      // TODO(user): Do we need a version with an array of escape values.

    //      Constraint* MakeSortingConstraint(const std::vector<IntVar*>& vars,
    //                                        const std::vector<IntVar*>& sorted);
    //      // TODO(user): Add void MakeSortedArray(
    //      //                             const std::vector<IntVar*>& vars,
    //      //                             std::vector<IntVar*>* const sorted);

    //      Constraint* MakeLexicalLess(const std::vector<IntVar*>& left,
    //                                  const std::vector<IntVar*>& right);

    //      Constraint* MakeLexicalLessOrEqual(const std::vector<IntVar*>& left,
    //                                         const std::vector<IntVar*>& right);

    //      Constraint* MakeInversePermutationConstraint(
    //          const std::vector<IntVar*>& left, const std::vector<IntVar*>& right);

    //      Constraint* MakeIndexOfFirstMaxValueConstraint(
    //          IntVar* index, const std::vector<IntVar*>& vars);

    //      Constraint* MakeIndexOfFirstMinValueConstraint(
    //          IntVar* index, const std::vector<IntVar*>& vars);

    //      Constraint* MakeNullIntersect(const std::vector<IntVar*>& first_vars,
    //                                    const std::vector<IntVar*>& second_vars);

    //      Constraint* MakeNullIntersectExcept(const std::vector<IntVar*>& first_vars,
    //                                          const std::vector<IntVar*>& second_vars,
    //                                          int64_t escape_value);

    //      // TODO(user): Implement MakeAllNullIntersect taking an array of
    //      // variable vectors.

    //      Constraint* MakeNoCycle(const std::vector<IntVar*>& nexts,
    //                              const std::vector<IntVar*>& active,
    //                              IndexFilter1 sink_handler = nullptr);
    //      Constraint* MakeNoCycle(const std::vector<IntVar*>& nexts,
    //                              const std::vector<IntVar*>& active,
    //                              IndexFilter1 sink_handler, bool assume_paths);

    //      Constraint* MakeCircuit(const std::vector<IntVar*>& nexts);

    //      Constraint* MakeSubCircuit(const std::vector<IntVar*>& nexts);

    //      Constraint* MakePathCumul(const std::vector<IntVar*>& nexts,
    //                                const std::vector<IntVar*>& active,
    //                                const std::vector<IntVar*>& cumuls,
    //                                const std::vector<IntVar*>& transits);
    //      // TODO(user): Merge with other path-cumuls constraints.
    //      Constraint* MakeDelayedPathCumul(const std::vector<IntVar*>& nexts,
    //                                       const std::vector<IntVar*>& active,
    //                                       const std::vector<IntVar*>& cumuls,
    //                                       const std::vector<IntVar*>& transits);
    //      Constraint* MakePathCumul(const std::vector<IntVar*>& nexts,
    //                                const std::vector<IntVar*>& active,
    //                                const std::vector<IntVar*>& cumuls,
    //                                IndexEvaluator2 transit_evaluator);

    //      Constraint* MakePathCumul(const std::vector<IntVar*>& nexts,
    //                                const std::vector<IntVar*>& active,
    //                                const std::vector<IntVar*>& cumuls,
    //                                const std::vector<IntVar*>& slacks,
    //                                IndexEvaluator2 transit_evaluator);
    //      // TODO(user): Only does checking on WhenBound events on next variables.
    //      Constraint* MakePathConnected(std::vector<IntVar*> nexts,
    //                                    std::vector<int64_t> sources,
    //                                    std::vector<int64_t> sinks,
    //                                    std::vector<IntVar*> status);
    //    #ifndef SWIG
    //      // TODO(user): This constraint does not make holes in variable domains;
    //      Constraint* MakePathPrecedenceConstraint(
    //          std::vector<IntVar*> nexts,
    //          const std::vector<std::pair<int, int>>& precedences);
    //      Constraint* MakePathPrecedenceConstraint(
    //          std::vector<IntVar*> nexts,
    //          const std::vector<std::pair<int, int>>& precedences,
    //          const std::vector<int>& lifo_path_starts,
    //          const std::vector<int>& fifo_path_starts);
    //      Constraint* MakePathTransitPrecedenceConstraint(
    //          std::vector<IntVar*> nexts, std::vector<IntVar*> transits,
    //          const std::vector<std::pair<int, int>>& precedences);
    //    #endif  // !SWIG
    //      Constraint* MakeMapDomain(IntVar* const var,
    //                                const std::vector<IntVar*>& actives);

    //      Constraint* MakeAllowedAssignments(const std::vector<IntVar*>& vars,
    //                                         const IntTupleSet& tuples);

    //      Constraint* MakeTransitionConstraint(
    //          const std::vector<IntVar*>& vars, const IntTupleSet& transition_table,
    //          int64_t initial_state, const std::vector<int64_t>& final_states);

    //      Constraint* MakeTransitionConstraint(const std::vector<IntVar*>& vars,
    //                                           const IntTupleSet& transition_table,
    //                                           int64_t initial_state,
    //                                           const std::vector<int>& final_states);

    //    #if defined(SWIGPYTHON)
    //      Constraint* MakeAllowedAssignments(
    //          const std::vector<IntVar*>& vars,
    //          const std::vector<std::vector<int64_t> /*keep for swig*/>& raw_tuples) {
    //        IntTupleSet tuples(vars.size());
    //        tuples.InsertAll(raw_tuples);
    //        return MakeAllowedAssignments(vars, tuples);
    //      }

    //      Constraint* MakeTransitionConstraint(
    //          const std::vector<IntVar*>& vars,
    //          const std::vector<std::vector<int64_t> /*keep for swig*/>&
    //              raw_transitions,
    //          int64_t initial_state, const std::vector<int>& final_states) {
    //        IntTupleSet transitions(3);
    //        transitions.InsertAll(raw_transitions);
    //        return MakeTransitionConstraint(vars, transitions, initial_state,
    //                                        final_states);
    //      }
    //    #endif

    //      Constraint* MakeNonOverlappingBoxesConstraint(
    //          const std::vector<IntVar*>& x_vars, const std::vector<IntVar*>& y_vars,
    //          const std::vector<IntVar*>& x_size, const std::vector<IntVar*>& y_size);
    //      Constraint* MakeNonOverlappingBoxesConstraint(
    //          const std::vector<IntVar*>& x_vars, const std::vector<IntVar*>& y_vars,
    //          const std::vector<int64_t>& x_size, const std::vector<int64_t>& y_size);
    //      Constraint* MakeNonOverlappingBoxesConstraint(
    //          const std::vector<IntVar*>& x_vars, const std::vector<IntVar*>& y_vars,
    //          const std::vector<int>& x_size, const std::vector<int>& y_size);

    //      Constraint* MakeNonOverlappingNonStrictBoxesConstraint(
    //          const std::vector<IntVar*>& x_vars, const std::vector<IntVar*>& y_vars,
    //          const std::vector<IntVar*>& x_size, const std::vector<IntVar*>& y_size);
    //      Constraint* MakeNonOverlappingNonStrictBoxesConstraint(
    //          const std::vector<IntVar*>& x_vars, const std::vector<IntVar*>& y_vars,
    //          const std::vector<int64_t>& x_size, const std::vector<int64_t>& y_size);
    //      Constraint* MakeNonOverlappingNonStrictBoxesConstraint(
    //          const std::vector<IntVar*>& x_vars, const std::vector<IntVar*>& y_vars,
    //          const std::vector<int>& x_size, const std::vector<int>& y_size);

    //      Pack* MakePack(const std::vector<IntVar*>& vars, int number_of_bins);

    //      IntervalVar* MakeFixedDurationIntervalVar(int64_t start_min,
    //                                                int64_t start_max, int64_t duration,
    //                                                bool optional,
    //                                                const std::string& name);

    //      void MakeFixedDurationIntervalVarArray(
    //          int count, int64_t start_min, int64_t start_max, int64_t duration,
    //          bool optional, const std::string& name,
    //          std::vector<IntervalVar*>* const array);

    //      IntervalVar* MakeFixedDurationIntervalVar(IntVar* const start_variable,
    //                                                int64_t duration,
    //                                                const std::string& name);

    //      IntervalVar* MakeFixedDurationIntervalVar(IntVar* const start_variable,
    //                                                int64_t duration,
    //                                                IntVar* const performed_variable,
    //                                                const std::string& name);

    //      void MakeFixedDurationIntervalVarArray(
    //          const std::vector<IntVar*>& start_variables, int64_t duration,
    //          const std::string& name, std::vector<IntervalVar*>* const array);

    //      void MakeFixedDurationIntervalVarArray(
    //          const std::vector<IntVar*>& start_variables,
    //          const std::vector<int64_t>& durations, const std::string& name,
    //          std::vector<IntervalVar*>* const array);
    //      void MakeFixedDurationIntervalVarArray(
    //          const std::vector<IntVar*>& start_variables,
    //          const std::vector<int>& durations, const std::string& name,
    //          std::vector<IntervalVar*>* const array);

    //      void MakeFixedDurationIntervalVarArray(
    //          const std::vector<IntVar*>& start_variables,
    //          const std::vector<int64_t>& durations,
    //          const std::vector<IntVar*>& performed_variables, const std::string& name,
    //          std::vector<IntervalVar*>* const array);

    //      void MakeFixedDurationIntervalVarArray(
    //          const std::vector<IntVar*>& start_variables,
    //          const std::vector<int>& durations,
    //          const std::vector<IntVar*>& performed_variables, const std::string& name,
    //          std::vector<IntervalVar*>* const array);

    //      IntervalVar* MakeFixedInterval(int64_t start, int64_t duration,
    //                                     const std::string& name);

    //      IntervalVar* MakeIntervalVar(int64_t start_min, int64_t start_max,
    //                                   int64_t duration_min, int64_t duration_max,
    //                                   int64_t end_min, int64_t end_max, bool optional,
    //                                   const std::string& name);

    //      void MakeIntervalVarArray(int count, int64_t start_min, int64_t start_max,
    //                                int64_t duration_min, int64_t duration_max,
    //                                int64_t end_min, int64_t end_max, bool optional,
    //                                const std::string& name,
    //                                std::vector<IntervalVar*>* const array);

    //      IntervalVar* MakeMirrorInterval(IntervalVar* const interval_var);

    //      IntervalVar* MakeFixedDurationStartSyncedOnStartIntervalVar(
    //          IntervalVar* const interval_var, int64_t duration, int64_t offset);

    //      IntervalVar* MakeFixedDurationStartSyncedOnEndIntervalVar(
    //          IntervalVar* const interval_var, int64_t duration, int64_t offset);

    //      IntervalVar* MakeFixedDurationEndSyncedOnStartIntervalVar(
    //          IntervalVar* const interval_var, int64_t duration, int64_t offset);

    //      IntervalVar* MakeFixedDurationEndSyncedOnEndIntervalVar(
    //          IntervalVar* const interval_var, int64_t duration, int64_t offset);

    //      IntervalVar* MakeIntervalRelaxedMin(IntervalVar* const interval_var);

    //      IntervalVar* MakeIntervalRelaxedMax(IntervalVar* const interval_var);

    //      Constraint* MakeIntervalVarRelation(IntervalVar* const t,
    //                                          UnaryIntervalRelation r, int64_t d);

    //      Constraint* MakeIntervalVarRelation(IntervalVar* const t1,
    //                                          BinaryIntervalRelation r,
    //                                          IntervalVar* const t2);

    //      Constraint* MakeIntervalVarRelationWithDelay(IntervalVar* const t1,
    //                                                   BinaryIntervalRelation r,
    //                                                   IntervalVar* const t2,
    //                                                   int64_t delay);

    //      Constraint* MakeTemporalDisjunction(IntervalVar* const t1,
    //                                          IntervalVar* const t2, IntVar* const alt);

    //      Constraint* MakeTemporalDisjunction(IntervalVar* const t1,
    //                                          IntervalVar* const t2);

    //      DisjunctiveConstraint* MakeDisjunctiveConstraint(
    //          const std::vector<IntervalVar*>& intervals, const std::string& name);

    //      DisjunctiveConstraint* MakeStrictDisjunctiveConstraint(
    //          const std::vector<IntervalVar*>& intervals, const std::string& name);

    //      Constraint* MakeCumulative(const std::vector<IntervalVar*>& intervals,
    //                                 const std::vector<int64_t>& demands,
    //                                 int64_t capacity, const std::string& name);

    //      Constraint* MakeCumulative(const std::vector<IntervalVar*>& intervals,
    //                                 const std::vector<int>& demands, int64_t capacity,
    //                                 const std::string& name);

    //      Constraint* MakeCumulative(const std::vector<IntervalVar*>& intervals,
    //                                 const std::vector<int64_t>& demands,
    //                                 IntVar* const capacity, const std::string& name);

    //      Constraint* MakeCumulative(const std::vector<IntervalVar*>& intervals,
    //                                 const std::vector<int>& demands,
    //                                 IntVar* const capacity, const std::string& name);

    //      Constraint* MakeCumulative(const std::vector<IntervalVar*>& intervals,
    //                                 const std::vector<IntVar*>& demands,
    //                                 int64_t capacity, const std::string& name);

    //      Constraint* MakeCumulative(const std::vector<IntervalVar*>& intervals,
    //                                 const std::vector<IntVar*>& demands,
    //                                 IntVar* const capacity, const std::string& name);

    //      Constraint* MakeCover(const std::vector<IntervalVar*>& vars,
    //                            IntervalVar* const target_var);

    //      Constraint* MakeEquality(IntervalVar* const var1, IntervalVar* const var2);

    //      Assignment* MakeAssignment();

    //      Assignment* MakeAssignment(const Assignment* const a);

    //      SolutionCollector* MakeFirstSolutionCollector(
    //          const Assignment* const assignment);
    //      SolutionCollector* MakeFirstSolutionCollector();

    //      SolutionCollector* MakeLastSolutionCollector(
    //          const Assignment* const assignment);
    //      SolutionCollector* MakeLastSolutionCollector();

    //      SolutionCollector* MakeBestValueSolutionCollector(
    //          const Assignment* const assignment, bool maximize);
    //      SolutionCollector* MakeBestValueSolutionCollector(bool maximize);

    //      SolutionCollector* MakeNBestValueSolutionCollector(
    //          const Assignment* const assignment, int solution_count, bool maximize);
    //      SolutionCollector* MakeNBestValueSolutionCollector(int solution_count,
    //                                                         bool maximize);

    //      SolutionCollector* MakeAllSolutionCollector(
    //          const Assignment* const assignment);
    //      SolutionCollector* MakeAllSolutionCollector();

    //      OptimizeVar* MakeMinimize(IntVar* const v, int64_t step);

    //      OptimizeVar* MakeMaximize(IntVar* const v, int64_t step);

    //      OptimizeVar* MakeOptimize(bool maximize, IntVar* const v, int64_t step);

    //      OptimizeVar* MakeWeightedMinimize(const std::vector<IntVar*>& sub_objectives,
    //                                        const std::vector<int64_t>& weights,
    //                                        int64_t step);

    //      OptimizeVar* MakeWeightedMinimize(const std::vector<IntVar*>& sub_objectives,
    //                                        const std::vector<int>& weights,
    //                                        int64_t step);

    //      OptimizeVar* MakeWeightedMaximize(const std::vector<IntVar*>& sub_objectives,
    //                                        const std::vector<int64_t>& weights,
    //                                        int64_t step);

    //      OptimizeVar* MakeWeightedMaximize(const std::vector<IntVar*>& sub_objectives,
    //                                        const std::vector<int>& weights,
    //                                        int64_t step);

    //      OptimizeVar* MakeWeightedOptimize(bool maximize,
    //                                        const std::vector<IntVar*>& sub_objectives,
    //                                        const std::vector<int64_t>& weights,
    //                                        int64_t step);

    //      OptimizeVar* MakeWeightedOptimize(bool maximize,
    //                                        const std::vector<IntVar*>& sub_objectives,
    //                                        const std::vector<int>& weights,
    //                                        int64_t step);



    //      SearchMonitor* MakeTabuSearch(bool maximize, IntVar* const v, int64_t step,
    //                                    const std::vector<IntVar*>& vars,
    //                                    int64_t keep_tenure, int64_t forbid_tenure,
    //                                    double tabu_factor);

    //      SearchMonitor* MakeGenericTabuSearch(bool maximize, IntVar* const v,
    //                                           int64_t step,
    //                                           const std::vector<IntVar*>& tabu_vars,
    //                                           int64_t forbid_tenure);

    //      // TODO(user): document behavior
    //      SearchMonitor* MakeSimulatedAnnealing(bool maximize, IntVar* const v,
    //                                            int64_t step,
    //                                            int64_t initial_temperature);

    //      SearchMonitor* MakeGuidedLocalSearch(
    //          bool maximize, IntVar* objective, IndexEvaluator2 objective_function,
    //          int64_t step, const std::vector<IntVar*>& vars, double penalty_factor,
    //          bool reset_penalties_on_new_best_solution = false);
    //      SearchMonitor* MakeGuidedLocalSearch(
    //          bool maximize, IntVar* objective, IndexEvaluator3 objective_function,
    //          int64_t step, const std::vector<IntVar*>& vars,
    //          const std::vector<IntVar*>& secondary_vars, double penalty_factor,
    //          bool reset_penalties_on_new_best_solution = false);

    //      SearchMonitor* MakeLubyRestart(int scale_factor);

    //      SearchMonitor* MakeConstantRestart(int frequency);

    //      ABSL_MUST_USE_RESULT RegularLimit* MakeTimeLimit(absl::Duration time);
    //    #if !defined(SWIG)
    //      ABSL_DEPRECATED("Use the version taking absl::Duration() as argument")
    //    #endif  // !defined(SWIG)
    //      ABSL_MUST_USE_RESULT RegularLimit* MakeTimeLimit(int64_t time_in_ms) {
    //        return MakeTimeLimit(time_in_ms == kint64max
    //                                 ? absl::InfiniteDuration()
    //                                 : absl::Milliseconds(time_in_ms));
    //      }

    //      ABSL_MUST_USE_RESULT RegularLimit* MakeBranchesLimit(int64_t branches);

    //      ABSL_MUST_USE_RESULT RegularLimit* MakeFailuresLimit(int64_t failures);

    //      ABSL_MUST_USE_RESULT RegularLimit* MakeSolutionsLimit(int64_t solutions);

    //      // timer by estimating the number of remaining calls, and 'cumulative' means
    //      // that the limit applies cumulatively, instead of search-by-search.
    //      ABSL_MUST_USE_RESULT RegularLimit* MakeLimit(absl::Duration time,
    //                                                   int64_t branches,
    //                                                   int64_t failures,
    //                                                   int64_t solutions,
    //                                                   bool smart_time_check = false,
    //                                                   bool cumulative = false);
    //      ABSL_MUST_USE_RESULT RegularLimit* MakeLimit(
    //          const RegularLimitParameters& proto);

    //    #if !defined(SWIG)
    //      ABSL_DEPRECATED("Use other MakeLimit() versions")
    //    #endif  // !defined(SWIG)
    //      ABSL_MUST_USE_RESULT RegularLimit* MakeLimit(int64_t time, int64_t branches,
    //                                                   int64_t failures,
    //                                                   int64_t solutions,
    //                                                   bool smart_time_check = false,
    //                                                   bool cumulative = false);

    //      RegularLimitParameters MakeDefaultRegularLimitParameters() const;

    //      ABSL_MUST_USE_RESULT SearchLimit* MakeLimit(SearchLimit* const limit_1,
    //                                                  SearchLimit* const limit_2);

    //      ABSL_MUST_USE_RESULT ImprovementSearchLimit* MakeImprovementLimit(
    //          IntVar* objective_var, bool maximize, double objective_scaling_factor,
    //          double objective_offset, double improvement_rate_coefficient,
    //          int improvement_rate_solutions_distance);

    //      ABSL_MUST_USE_RESULT SearchLimit* MakeCustomLimit(
    //          std::function<bool()> limiter);

    //      // TODO(user): DEPRECATE API of MakeSearchLog(.., IntVar* var,..).

    //      SearchMonitor* MakeSearchLog(int branch_period);

    //      SearchMonitor* MakeSearchLog(int branch_period, IntVar* const var);

    //      SearchMonitor* MakeSearchLog(int branch_period,
    //                                   std::function<std::string()> display_callback);

    //      SearchMonitor* MakeSearchLog(int branch_period, IntVar* var,
    //                                   std::function<std::string()> display_callback);

    //      SearchMonitor* MakeSearchLog(int branch_period, OptimizeVar* const opt_var);

    //      SearchMonitor* MakeSearchLog(int branch_period, OptimizeVar* const opt_var,
    //                                   std::function<std::string()> display_callback);

    //      struct SearchLogParameters {
    //        int branch_period = 1;
    //        OptimizeVar* objective = nullptr;
    //        IntVar* variable = nullptr;
    //        double scaling_factor = 1.0;
    //        double offset = 0;
    //        std::function<std::string()> display_callback;
    //        bool display_on_new_solutions_only = true;
    //      };
    //      SearchMonitor* MakeSearchLog(SearchLogParameters parameters);

    //      SearchMonitor* MakeSearchTrace(const std::string& prefix);

    //      SearchMonitor* MakeEnterSearchCallback(std::function<void()> callback);
    //      SearchMonitor* MakeExitSearchCallback(std::function<void()> callback);
    //      SearchMonitor* MakeAtSolutionCallback(std::function<void()> callback);

    //      ModelVisitor* MakePrintModelVisitor();
    //      ModelVisitor* MakeStatisticsModelVisitor();
    //    #if !defined(SWIG)
    //      ModelVisitor* MakeVariableDegreeVisitor(
    //          absl::flat_hash_map<const IntVar*, int>* const map);
    //    #endif  // !defined(SWIG)

    //      SearchMonitor* MakeSymmetryManager(
    //          const std::vector<SymmetryBreaker*>& visitors);
    //      SearchMonitor* MakeSymmetryManager(SymmetryBreaker* const v1);
    //      SearchMonitor* MakeSymmetryManager(SymmetryBreaker* const v1,
    //                                         SymmetryBreaker* const v2);
    //      SearchMonitor* MakeSymmetryManager(SymmetryBreaker* const v1,
    //                                         SymmetryBreaker* const v2,
    //                                         SymmetryBreaker* const v3);
    //      SearchMonitor* MakeSymmetryManager(SymmetryBreaker* const v1,
    //                                         SymmetryBreaker* const v2,
    //                                         SymmetryBreaker* const v3,
    //                                         SymmetryBreaker* const v4);

    //      Decision* MakeAssignVariableValue(IntVar* const var, int64_t val);
    //      Decision* MakeVariableLessOrEqualValue(IntVar* const var, int64_t value);
    //      Decision* MakeVariableGreaterOrEqualValue(IntVar* const var, int64_t value);
    //      Decision* MakeSplitVariableDomain(IntVar* const var, int64_t val,
    //                                        bool start_with_lower_half);
    //      Decision* MakeAssignVariableValueOrFail(IntVar* const var, int64_t value);
    //      Decision* MakeAssignVariableValueOrDoNothing(IntVar* const var,
    //                                                   int64_t value);
    //      Decision* MakeAssignVariablesValues(const std::vector<IntVar*>& vars,
    //                                          const std::vector<int64_t>& values);
    //      Decision* MakeAssignVariablesValuesOrDoNothing(
    //          const std::vector<IntVar*>& vars, const std::vector<int64_t>& values);
    //      Decision* MakeAssignVariablesValuesOrFail(const std::vector<IntVar*>& vars,
    //                                                const std::vector<int64_t>& values);
    //      Decision* MakeFailDecision();
    //      Decision* MakeDecision(Action apply, Action refute);

    //      DecisionBuilder* Compose(DecisionBuilder* const db1,
    //                               DecisionBuilder* const db2);
    //      DecisionBuilder* Compose(DecisionBuilder* const db1,
    //                               DecisionBuilder* const db2,
    //                               DecisionBuilder* const db3);
    //      DecisionBuilder* Compose(DecisionBuilder* const db1,
    //                               DecisionBuilder* const db2,
    //                               DecisionBuilder* const db3,
    //                               DecisionBuilder* const db4);
    //      DecisionBuilder* Compose(const std::vector<DecisionBuilder*>& dbs);

    //      // TODO(user): The search tree can be balanced by using binary
    //      DecisionBuilder* Try(DecisionBuilder* const db1, DecisionBuilder* const db2);
    //      DecisionBuilder* Try(DecisionBuilder* const db1, DecisionBuilder* const db2,
    //                           DecisionBuilder* const db3);
    //      DecisionBuilder* Try(DecisionBuilder* const db1, DecisionBuilder* const db2,
    //                           DecisionBuilder* const db3, DecisionBuilder* const db4);
    //      DecisionBuilder* Try(const std::vector<DecisionBuilder*>& dbs);

    //      // TODO(user): name each of them differently, and document them (and do that
    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IntVarStrategy var_str, IntValueStrategy val_str);
    MakePhase_01(vars: IntVar[], var_str: Solver.IntVarStrategy, val_str: Solver.IntValueStrategy): DecisionBuilder;

    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IndexEvaluator1 var_evaluator,
    //                                 IntValueStrategy val_str);
    MakePhase_02(vars: IntVar[], var_evaluator: IndexEvaluator1, val_str: Solver.IntValueStrategy): DecisionBuilder;

    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IntVarStrategy var_str,
    //                                 IndexEvaluator2 value_evaluator);
    MakePhase_03(vars: IntVar[], var_str: Solver.IntVarStrategy, value_evaluator: IndexEvaluator2): DecisionBuilder;

    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IntVarStrategy var_str,
    //                                 VariableValueComparator var_val1_val2_comparator);
    MakePhase_04(vars: IntVar[], var_str: Solver.IntVarStrategy, var_val1_val2_comparator: VariableValueComparator): DecisionBuilder;

    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IndexEvaluator1 var_evaluator,
    //                                 IndexEvaluator2 value_evaluator);
    MakePhase_05(vars: IntVar[], var_evaluator: IndexEvaluator1, value_evaluator: IndexEvaluator2): DecisionBuilder;

    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IntVarStrategy var_str,
    //                                 IndexEvaluator2 value_evaluator,
    //                                 IndexEvaluator1 tie_breaker);
    MakePhase_06(vars: IntVar[], var_str: Solver.IntVarStrategy, value_evaluator: IndexEvaluator2, tie_breaker: IndexEvaluator1): DecisionBuilder;

    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IndexEvaluator1 var_evaluator,
    //                                 IndexEvaluator2 value_evaluator,
    //                                 IndexEvaluator1 tie_breaker);
    MakePhase_07(vars: IntVar[], var_evaluator: IndexEvaluator1, value_evaluator: IndexEvaluator2, tie_breaker: IndexEvaluator1): DecisionBuilder;

    //      DecisionBuilder* MakeDefaultPhase(const std::vector<IntVar*>& vars);
    //      DecisionBuilder* MakeDefaultPhase(const std::vector<IntVar*>& vars,
    //                                        const DefaultPhaseParameters& parameters);

    //      DecisionBuilder* MakePhase(IntVar* const v0, IntVarStrategy var_str,
    //                                 IntValueStrategy val_str);
    MakePhase_08(v0: IntVar, var_str: Solver.IntVarStrategy, val_str: Solver.IntValueStrategy): DecisionBuilder;

    //      DecisionBuilder* MakePhase(IntVar* const v0, IntVar* const v1,
    //                                 IntVarStrategy var_str, IntValueStrategy val_str);
    MakePhase_09(v0: IntVar, v1: IntVar, var_str: Solver.IntVarStrategy, val_str: Solver.IntValueStrategy): DecisionBuilder;

    //      DecisionBuilder* MakePhase(IntVar* const v0, IntVar* const v1,
    //                                 IntVar* const v2, IntVarStrategy var_str,
    //                                 IntValueStrategy val_str);
    MakePhase_10(v0: IntVar, v1: IntVar, v2: IntVar, var_str: Solver.IntVarStrategy, val_str: Solver.IntValueStrategy): DecisionBuilder;

    //      DecisionBuilder* MakePhase(IntVar* const v0, IntVar* const v1,
    //                                 IntVar* const v2, IntVar* const v3,
    //                                 IntVarStrategy var_str, IntValueStrategy val_str);
    MakePhase_11(v0: IntVar, v1: IntVar, v2: IntVar, v3: IntVar, var_str: Solver.IntVarStrategy, val_str: Solver.IntValueStrategy): DecisionBuilder;

    //      Decision* MakeScheduleOrPostpone(IntervalVar* const var, int64_t est,
    //                                       int64_t* const marker);

    //      Decision* MakeScheduleOrExpedite(IntervalVar* const var, int64_t est,
    //                                       int64_t* const marker);

    //      Decision* MakeRankFirstInterval(SequenceVar* const sequence, int index);

    //      Decision* MakeRankLastInterval(SequenceVar* const sequence, int index);

    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IndexEvaluator2 eval, EvaluatorStrategy str);
    MakePhase_12(vars: IntVar[], eval: IndexEvaluator2, str: Solver.EvaluatorStrategy): DecisionBuilder;

    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IndexEvaluator2 eval, IndexEvaluator1 tie_breaker,
    //                                 EvaluatorStrategy str);
    MakePhase_13(vars: IntVar[], eval: IndexEvaluator2, tie_breaker: IndexEvaluator1, str: Solver.EvaluatorStrategy): DecisionBuilder;

    //      DecisionBuilder* MakePhase(const std::vector<IntervalVar*>& intervals,
    //                                 IntervalStrategy str);
    MakePhase_14(intervals: IntervalVar[], str: Solver.IntervalStrategy): DecisionBuilder;

    //      DecisionBuilder* MakePhase(const std::vector<SequenceVar*>& sequences,
    //                                 SequenceStrategy str);
    MakePhase_15(sequences: SequenceVar[], str: Solver.SequenceStrategy): DecisionBuilder;

    //      DecisionBuilder* MakeDecisionBuilderFromAssignment(
    //          Assignment* const assignment, DecisionBuilder* const db,
    //          const std::vector<IntVar*>& vars);

    //      DecisionBuilder* MakeConstraintAdder(Constraint* const ct);

    //      DecisionBuilder* MakeSolveOnce(DecisionBuilder* const db);
    //      DecisionBuilder* MakeSolveOnce(DecisionBuilder* const db,
    //                                     SearchMonitor* const monitor1);
    //      DecisionBuilder* MakeSolveOnce(DecisionBuilder* const db,
    //                                     SearchMonitor* const monitor1,
    //                                     SearchMonitor* const monitor2);
    //      DecisionBuilder* MakeSolveOnce(DecisionBuilder* const db,
    //                                     SearchMonitor* const monitor1,
    //                                     SearchMonitor* const monitor2,
    //                                     SearchMonitor* const monitor3);
    //      DecisionBuilder* MakeSolveOnce(DecisionBuilder* const db,
    //                                     SearchMonitor* const monitor1,
    //                                     SearchMonitor* const monitor2,
    //                                     SearchMonitor* const monitor3,
    //                                     SearchMonitor* const monitor4);
    //      DecisionBuilder* MakeSolveOnce(DecisionBuilder* const db,
    //                                     const std::vector<SearchMonitor*>& monitors);

    //      DecisionBuilder* MakeNestedOptimize(DecisionBuilder* const db,
    //                                          Assignment* const solution, bool maximize,
    //                                          int64_t step);
    //      DecisionBuilder* MakeNestedOptimize(DecisionBuilder* const db,
    //                                          Assignment* const solution, bool maximize,
    //                                          int64_t step,
    //                                          SearchMonitor* const monitor1);
    //      DecisionBuilder* MakeNestedOptimize(DecisionBuilder* const db,
    //                                          Assignment* const solution, bool maximize,
    //                                          int64_t step,
    //                                          SearchMonitor* const monitor1,
    //                                          SearchMonitor* const monitor2);
    //      DecisionBuilder* MakeNestedOptimize(DecisionBuilder* const db,
    //                                          Assignment* const solution, bool maximize,
    //                                          int64_t step,
    //                                          SearchMonitor* const monitor1,
    //                                          SearchMonitor* const monitor2,
    //                                          SearchMonitor* const monitor3);
    //      DecisionBuilder* MakeNestedOptimize(DecisionBuilder* const db,
    //                                          Assignment* const solution, bool maximize,
    //                                          int64_t step,
    //                                          SearchMonitor* const monitor1,
    //                                          SearchMonitor* const monitor2,
    //                                          SearchMonitor* const monitor3,
    //                                          SearchMonitor* const monitor4);
    //      DecisionBuilder* MakeNestedOptimize(
    //          DecisionBuilder* const db, Assignment* const solution, bool maximize,
    //          int64_t step, const std::vector<SearchMonitor*>& monitors);

    //      DecisionBuilder* MakeRestoreAssignment(Assignment* assignment);

    //      DecisionBuilder* MakeStoreAssignment(Assignment* assignment);

    //      LocalSearchOperator* MakeOperator(const std::vector<IntVar*>& vars,
    //                                        LocalSearchOperators op);
    //      LocalSearchOperator* MakeOperator(const std::vector<IntVar*>& vars,
    //                                        const std::vector<IntVar*>& secondary_vars,
    //                                        LocalSearchOperators op);
    //      // TODO(user): Make the callback an IndexEvaluator2 when there are no
    //      // secondary variables.
    //      LocalSearchOperator* MakeOperator(const std::vector<IntVar*>& vars,
    //                                        IndexEvaluator3 evaluator,
    //                                        EvaluatorLocalSearchOperators op);
    //      LocalSearchOperator* MakeOperator(const std::vector<IntVar*>& vars,
    //                                        const std::vector<IntVar*>& secondary_vars,
    //                                        IndexEvaluator3 evaluator,
    //                                        EvaluatorLocalSearchOperators op);

    //      LocalSearchOperator* MakeRandomLnsOperator(const std::vector<IntVar*>& vars,
    //                                                 int number_of_variables);
    //      LocalSearchOperator* MakeRandomLnsOperator(const std::vector<IntVar*>& vars,
    //                                                 int number_of_variables,
    //                                                 int32_t seed);

    //      LocalSearchOperator* MakeMoveTowardTargetOperator(const Assignment& target);

    //      LocalSearchOperator* MakeMoveTowardTargetOperator(
    //          const std::vector<IntVar*>& variables,
    //          const std::vector<int64_t>& target_values);

    //      LocalSearchOperator* ConcatenateOperators(
    //          const std::vector<LocalSearchOperator*>& ops);
    //      LocalSearchOperator* ConcatenateOperators(
    //          const std::vector<LocalSearchOperator*>& ops, bool restart);
    //      LocalSearchOperator* ConcatenateOperators(
    //          const std::vector<LocalSearchOperator*>& ops,
    //          std::function<int64_t(int, int)> evaluator);
    //      LocalSearchOperator* RandomConcatenateOperators(
    //          const std::vector<LocalSearchOperator*>& ops);

    //      LocalSearchOperator* RandomConcatenateOperators(
    //          const std::vector<LocalSearchOperator*>& ops, int32_t seed);

    //      LocalSearchOperator* MultiArmedBanditConcatenateOperators(
    //          const std::vector<LocalSearchOperator*>& ops, double memory_coefficient,
    //          double exploration_coefficient, bool maximize);

    //      LocalSearchOperator* MakeNeighborhoodLimit(LocalSearchOperator* const op,
    //                                                 int64_t limit);

    //      // TODO(user): Make a variant which runs a local search after each
    //      //                solution found in a DFS.

    //      DecisionBuilder* MakeLocalSearchPhase(
    //          Assignment* const assignment,
    //          LocalSearchPhaseParameters* const parameters);
    //      DecisionBuilder* MakeLocalSearchPhase(
    //          const std::vector<IntVar*>& vars, DecisionBuilder* const first_solution,
    //          LocalSearchPhaseParameters* const parameters);
    //      DecisionBuilder* MakeLocalSearchPhase(
    //          const std::vector<IntVar*>& vars, DecisionBuilder* const first_solution,
    //          DecisionBuilder* const first_solution_sub_decision_builder,
    //          LocalSearchPhaseParameters* const parameters);
    //      DecisionBuilder* MakeLocalSearchPhase(
    //          const std::vector<SequenceVar*>& vars,
    //          DecisionBuilder* const first_solution,
    //          LocalSearchPhaseParameters* const parameters);

    //      SolutionPool* MakeDefaultSolutionPool();

    //      LocalSearchPhaseParameters* MakeLocalSearchPhaseParameters(
    //          IntVar* objective, LocalSearchOperator* const ls_operator,
    //          DecisionBuilder* const sub_decision_builder);
    //      LocalSearchPhaseParameters* MakeLocalSearchPhaseParameters(
    //          IntVar* objective, LocalSearchOperator* const ls_operator,
    //          DecisionBuilder* const sub_decision_builder, RegularLimit* const limit);
    //      LocalSearchPhaseParameters* MakeLocalSearchPhaseParameters(
    //          IntVar* objective, LocalSearchOperator* const ls_operator,
    //          DecisionBuilder* const sub_decision_builder, RegularLimit* const limit,
    //          LocalSearchFilterManager* filter_manager);

    //      LocalSearchPhaseParameters* MakeLocalSearchPhaseParameters(
    //          IntVar* objective, SolutionPool* const pool,
    //          LocalSearchOperator* const ls_operator,
    //          DecisionBuilder* const sub_decision_builder);
    //      LocalSearchPhaseParameters* MakeLocalSearchPhaseParameters(
    //          IntVar* objective, SolutionPool* const pool,
    //          LocalSearchOperator* const ls_operator,
    //          DecisionBuilder* const sub_decision_builder, RegularLimit* const limit);
    //      LocalSearchPhaseParameters* MakeLocalSearchPhaseParameters(
    //          IntVar* objective, SolutionPool* const pool,
    //          LocalSearchOperator* const ls_operator,
    //          DecisionBuilder* const sub_decision_builder, RegularLimit* const limit,
    //          LocalSearchFilterManager* filter_manager);

    //      LocalSearchFilter* MakeAcceptFilter();
    //      LocalSearchFilter* MakeRejectFilter();
    //      LocalSearchFilter* MakeVariableDomainFilter();
    //      IntVarLocalSearchFilter* MakeSumObjectiveFilter(
    //          const std::vector<IntVar*>& vars, IndexEvaluator2 values,
    //          Solver::LocalSearchFilterBound filter_enum);
    //      IntVarLocalSearchFilter* MakeSumObjectiveFilter(
    //          const std::vector<IntVar*>& vars,
    //          const std::vector<IntVar*>& secondary_vars, IndexEvaluator3 values,
    //          Solver::LocalSearchFilterBound filter_enum);

    //      void TopPeriodicCheck();
    //      int TopProgressPercent();

    //      void PushState();
    //      void PopState();

    //      int SearchDepth() const;

    //      int SearchLeftDepth() const;

    //      int SolveDepth() const;

    //      void SetBranchSelector(BranchSelector bs);

    //      DecisionBuilder* MakeApplyBranchSelector(BranchSelector bs);

    //      template <class T>
    //      void SaveAndSetValue(T* adr, T val) {
    //        if (*adr != val) {
    //          InternalSaveValue(adr);
    //          *adr = val;
    //        }
    //      }

    //      template <class T>
    //      void SaveAndAdd(T* adr, T val) {
    //        if (val != 0) {
    //          InternalSaveValue(adr);
    //          (*adr) += val;
    //        }
    //      }

    //      int64_t Rand64(int64_t size) {
    //        DCHECK_GT(size, 0);
    //        return absl::Uniform<int64_t>(random_, 0, size);
    //      }

    //      int32_t Rand32(int32_t size) {
    //        DCHECK_GT(size, 0);
    //        return absl::Uniform<int32_t>(random_, 0, size);
    //      }

    //      void ReSeed(int32_t seed) { random_.seed(seed); }

    //      void ExportProfilingOverview(const std::string& filename);

    //      // TODO(user): Merge demon and local search profiles.
    //      std::string LocalSearchProfile() const;

    //    #if !defined(SWIG)
    //      ConstraintSolverStatistics GetConstraintSolverStatistics() const;
    //      LocalSearchStatistics GetLocalSearchStatistics() const;
    //    #endif  // !defined(SWIG)

    //      bool CurrentlyInSolve() const;

    //      int constraints() const { return constraints_list_.size(); }

    //      void Accept(ModelVisitor* const visitor) const;

    //      Decision* balancing_decision() const { return balancing_decision_.get(); }

    //    #if !defined(SWIG)
    //      void set_fail_intercept(std::function<void()> fail_intercept) {
    //        fail_intercept_ = std::move(fail_intercept);
    //      }
    //    #endif  // !defined(SWIG)
    //      void clear_fail_intercept() { fail_intercept_ = nullptr; }
    //      DemonProfiler* demon_profiler() const { return demon_profiler_; }
    //      // TODO(user): Get rid of the following methods once fast local search is
    //      void SetUseFastLocalSearch(bool use_fast_local_search) {
    //        use_fast_local_search_ = use_fast_local_search;
    //      }
    //      bool UseFastLocalSearch() const { return use_fast_local_search_; }
    //      bool HasName(const PropagationBaseObject* object) const;
    //      Demon* RegisterDemon(Demon* const demon);
    //      IntExpr* RegisterIntExpr(IntExpr* const expr);
    //      IntVar* RegisterIntVar(IntVar* const var);
    //      IntervalVar* RegisterIntervalVar(IntervalVar* const var);

    //      Search* ActiveSearch() const;
    //      ModelCache* Cache() const;
    //      bool InstrumentsDemons() const;
    //      bool IsProfilingEnabled() const;
    //      bool IsLocalSearchProfilingEnabled() const;
    //      bool InstrumentsVariables() const;
    //      bool NameAllVariables() const;
    //      std::string model_name() const;
    //      PropagationMonitor* GetPropagationMonitor() const;
    //      void AddPropagationMonitor(PropagationMonitor* const monitor);
    //      LocalSearchMonitor* GetLocalSearchMonitor() const;
    //      void AddLocalSearchMonitor(LocalSearchMonitor* monitor);
    //      void SetSearchContext(Search* search, const std::string& search_context);
    //      std::string SearchContext() const;
    //      std::string SearchContext(const Search* search) const;
    //      // TODO(user): Investigate if this should be moved to Search.
    //      Assignment* GetOrCreateLocalSearchState();
    //      void ClearLocalSearchState() { local_search_state_.reset(nullptr); }

    //      std::vector<int64_t> tmp_vector_;

    //      friend class BaseIntExpr;
    //      friend class Constraint;
    //      friend class DemonProfiler;
    //      friend class FindOneNeighbor;
    //      friend class IntVar;
    //      friend class PropagationBaseObject;
    //      friend class Queue;
    //      friend class SearchMonitor;
    //      friend class SearchLimit;
    //      friend class RoutingModel;
    //      friend class LocalSearchProfiler;

    //    #if !defined(SWIG)
    //      friend void InternalSaveBooleanVarValue(Solver* const, IntVar* const);
    //      template <class>
    //      friend class SimpleRevFIFO;
    //      template <class K, class V>
    //      friend class RevImmutableMultiMap;

    //      bool IsBooleanVar(IntExpr* const expr, IntVar** inner_var,
    //                        bool* is_negated) const;

    //      bool IsProduct(IntExpr* const expr, IntExpr** inner_expr,
    //                     int64_t* coefficient);
    //    #endif  /// !defined(SWIG)

    //      IntExpr* CastExpression(const IntVar* const var) const;

    //      void FinishCurrentSearch();
    //      void RestartCurrentSearch();

    //      void ShouldFail() { should_fail_ = true; }
    //      void CheckFail() {
    //        if (!should_fail_) return;
    //        should_fail_ = false;
    //        Fail();
    //      }

    //      DecisionBuilder* MakeProfiledDecisionBuilderWrapper(DecisionBuilder* db);

};

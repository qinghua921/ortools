import { Constraint } from "./Constraint";
import { DecisionBuilder } from "./DecisionBuilder";
import { IntVar } from "./IntVar";

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
}
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


    //      enum EvaluatorStrategy {
    //        /// Pairs are compared at the first call of the selector, and results are
    //        /// cached. Next calls to the selector use the previous computation, and so
    //        /// are not up-to-date, e.g. some <variable, value> pairs may not be
    //        /// possible anymore due to propagation since the first to call.
    //        CHOOSE_STATIC_GLOBAL_BEST,

    //        /// Pairs are compared each time a variable is selected. That way all pairs
    //        /// are relevant and evaluation is accurate.
    //        /// This strategy runs in O(number-of-pairs) at each variable selection,
    //        /// versus O(1) in the static version.
    //        CHOOSE_DYNAMIC_GLOBAL_BEST,
    //      };

    //      enum SequenceStrategy {
    //        SEQUENCE_DEFAULT,
    //        SEQUENCE_SIMPLE,
    //        CHOOSE_MIN_SLACK_RANK_FORWARD,
    //        CHOOSE_RANDOM_RANK_FORWARD,
    //      };

    //      enum IntervalStrategy {
    //        /// The default is INTERVAL_SET_TIMES_FORWARD.
    //        INTERVAL_DEFAULT,
    //        /// The simple is INTERVAL_SET_TIMES_FORWARD.
    //        INTERVAL_SIMPLE,
    //        /// Selects the variable with the lowest starting time of all variables,
    //        /// and fixes its starting time to this lowest value.
    //        INTERVAL_SET_TIMES_FORWARD,
    //        /// Selects the variable with the highest ending time of all variables,
    //        /// and fixes the ending time to this highest values.
    //        INTERVAL_SET_TIMES_BACKWARD
    //      };

    //      enum LocalSearchOperators {
    //        /// Operator which reverses a sub-chain of a path. It is called TwoOpt
    //        /// because it breaks two arcs on the path; resulting paths are called
    //        /// two-optimal.
    //        /// Possible neighbors for the path 1 -> 2 -> 3 -> 4 -> 5
    //        /// (where (1, 5) are first and last nodes of the path and can therefore not
    //        /// be moved):
    //        ///   1 -> [3 -> 2] -> 4  -> 5
    //        ///   1 -> [4 -> 3  -> 2] -> 5
    //        ///   1 ->  2 -> [4 -> 3] -> 5
    //        TWOOPT,

    //        /// Relocate: OROPT and RELOCATE.
    //        /// Operator which moves a sub-chain of a path to another position; the
    //        /// specified chain length is the fixed length of the chains being moved.
    //        /// When this length is 1, the operator simply moves a node to another
    //        /// position.
    //        /// Possible neighbors for the path 1 -> 2 -> 3 -> 4 -> 5, for a chain
    //        /// length of 2 (where (1, 5) are first and last nodes of the path and can
    //        /// therefore not be moved):
    //        ///   1 ->  4 -> [2 -> 3] -> 5
    //        ///   1 -> [3 -> 4] -> 2  -> 5
    //        ///
    //        /// Using Relocate with chain lengths of 1, 2 and 3 together is equivalent
    //        /// to the OrOpt operator on a path. The OrOpt operator is a limited
    //        ///  version of 3Opt (breaks 3 arcs on a path).
    //        OROPT,

    //        /// Relocate neighborhood with length of 1 (see OROPT comment).
    //        RELOCATE,

    //        /// Operator which exchanges the positions of two nodes.
    //        /// Possible neighbors for the path 1 -> 2 -> 3 -> 4 -> 5
    //        /// (where (1, 5) are first and last nodes of the path and can therefore not
    //        /// be moved):
    //        ///   1 -> [3] -> [2] ->  4  -> 5
    //        ///   1 -> [4] ->  3  -> [2] -> 5
    //        ///   1 ->  2  -> [4] -> [3] -> 5
    //        EXCHANGE,

    //        /// Operator which cross exchanges the starting chains of 2 paths, including
    //        /// exchanging the whole paths.
    //        /// First and last nodes are not moved.
    //        /// Possible neighbors for the paths 1 -> 2 -> 3 -> 4 -> 5 and 6 -> 7 -> 8
    //        /// (where (1, 5) and (6, 8) are first and last nodes of the paths and can
    //        /// therefore not be moved):
    //        ///   1 -> [7] -> 3 -> 4 -> 5  6 -> [2] -> 8
    //        ///   1 -> [7] -> 4 -> 5       6 -> [2 -> 3] -> 8
    //        ///   1 -> [7] -> 5            6 -> [2 -> 3 -> 4] -> 8
    //        CROSS,

    //        /// Operator which inserts an inactive node into a path.
    //        /// Possible neighbors for the path 1 -> 2 -> 3 -> 4 with 5 inactive
    //        /// (where 1 and 4 are first and last nodes of the path) are:
    //        ///   1 -> [5] ->  2  ->  3  -> 4
    //        ///   1 ->  2  -> [5] ->  3  -> 4
    //        ///   1 ->  2  ->  3  -> [5] -> 4
    //        MAKEACTIVE,

    //        /// Operator which makes path nodes inactive.
    //        /// Possible neighbors for the path 1 -> 2 -> 3 -> 4 (where 1 and 4 are
    //        /// first and last nodes of the path) are:
    //        ///   1 -> 3 -> 4 with 2 inactive
    //        ///   1 -> 2 -> 4 with 3 inactive
    //        MAKEINACTIVE,

    //        /// Operator which makes a "chain" of path nodes inactive.
    //        /// Possible neighbors for the path 1 -> 2 -> 3 -> 4 (where 1 and 4 are
    //        /// first and last nodes of the path) are:
    //        ///   1 -> 3 -> 4 with 2 inactive
    //        ///   1 -> 2 -> 4 with 3 inactive
    //        ///   1 -> 4 with 2 and 3 inactive
    //        MAKECHAININACTIVE,

    //        /// Operator which replaces an active node by an inactive one.
    //        /// Possible neighbors for the path 1 -> 2 -> 3 -> 4 with 5 inactive
    //        /// (where 1 and 4 are first and last nodes of the path) are:
    //        ///   1 -> [5] ->  3  -> 4 with 2 inactive
    //        ///   1 ->  2  -> [5] -> 4 with 3 inactive
    //        SWAPACTIVE,

    //        /// Operator which makes an inactive node active and an active one inactive.
    //        /// It is similar to SwapActiveOperator except that it tries to insert the
    //        /// inactive node in all possible positions instead of just the position of
    //        /// the node made inactive.
    //        /// Possible neighbors for the path 1 -> 2 -> 3 -> 4 with 5 inactive
    //        /// (where 1 and 4 are first and last nodes of the path) are:
    //        ///   1 -> [5] ->  3  -> 4 with 2 inactive
    //        ///   1 ->  3  -> [5] -> 4 with 2 inactive
    //        ///   1 -> [5] ->  2  -> 4 with 3 inactive
    //        ///   1 ->  2  -> [5] -> 4 with 3 inactive
    //        EXTENDEDSWAPACTIVE,

    //        /// Operator which relaxes two sub-chains of three consecutive arcs each.
    //        /// Each sub-chain is defined by a start node and the next three arcs. Those
    //        /// six arcs are relaxed to build a new neighbor.
    //        /// PATHLNS explores all possible pairs of starting nodes and so defines
    //        /// n^2 neighbors, n being the number of nodes.
    //        /// Note that the two sub-chains can be part of the same path; they even may
    //        /// overlap.
    //        PATHLNS,

    //        /// Operator which relaxes one entire path and all inactive nodes, thus
    //        /// defining num_paths neighbors.
    //        FULLPATHLNS,

    //        /// Operator which relaxes all inactive nodes and one sub-chain of six
    //        /// consecutive arcs. That way the path can be improved by inserting
    //        /// inactive nodes or swapping arcs.
    //        UNACTIVELNS,

    //        /// Operator which defines one neighbor per variable. Each neighbor tries to
    //        /// increment by one the value of the corresponding variable. When a new
    //        /// solution is found the neighborhood is rebuilt from scratch, i.e., tries
    //        /// to increment values in the variable order.
    //        /// Consider for instance variables x and y. x is incremented one by one to
    //        /// its max, and when it is not possible to increment x anymore, y is
    //        /// incremented once. If this is a solution, then next neighbor tries to
    //        /// increment x.
    //        INCREMENT,

    //        /// Operator which defines a neighborhood to decrement values.
    //        /// The behavior is the same as INCREMENT, except values are decremented
    //        /// instead of incremented.
    //        DECREMENT,

    //        /// Operator which defines one neighbor per variable. Each neighbor relaxes
    //        /// one variable.
    //        /// When a new solution is found the neighborhood is rebuilt from scratch.
    //        /// Consider for instance variables x and y. First x is relaxed and the
    //        /// solver is looking for the best possible solution (with only x relaxed).
    //        /// Then y is relaxed, and the solver is looking for a new solution.
    //        /// If a new solution is found, then the next variable to be relaxed is x.
    //        SIMPLELNS
    //      };

    //      enum EvaluatorLocalSearchOperators {
    //        /// Lin-Kernighan local search.
    //        /// While the accumulated local gain is positive, perform a 2opt or a 3opt
    //        /// move followed by a series of 2opt moves. Return a neighbor for which the
    //        /// global gain is positive.
    //        LK,

    //        /// Sliding TSP operator.
    //        /// Uses an exact dynamic programming algorithm to solve the TSP
    //        /// corresponding to path sub-chains.
    //        /// For a subchain 1 -> 2 -> 3 -> 4 -> 5 -> 6, solves the TSP on
    //        /// nodes A, 2, 3, 4, 5, where A is a merger of nodes 1 and 6 such that
    //        /// cost(A,i) = cost(1,i) and cost(i,A) = cost(i,6).
    //        TSPOPT,

    //        /// TSP-base LNS.
    //        /// Randomly merge consecutive nodes until n "meta"-nodes remain and solve
    //        /// the corresponding TSP.
    //        /// This is an "unlimited" neighborhood which must be stopped by search
    //        /// limits. To force diversification, the operator iteratively forces each
    //        /// node to serve as base of a meta-node.
    //        TSPLNS
    //      };

    //      enum LocalSearchFilterBound {
    //        /// Move is accepted when the current objective value >= objective.Min.
    //        GE,
    //        /// Move is accepted when the current objective value <= objective.Max.
    //        LE,
    //        /// Move is accepted when the current objective value is in the interval
    //        /// objective.Min .. objective.Max.
    //        EQ
    //      };

    //      enum DemonPriority {
    //        /// DELAYED_PRIORITY is the lowest priority: Demons will be processed after
    //        /// VAR_PRIORITY and NORMAL_PRIORITY demons.
    //        DELAYED_PRIORITY = 0,

    //        /// VAR_PRIORITY is between DELAYED_PRIORITY and NORMAL_PRIORITY.
    //        VAR_PRIORITY = 1,

    //        /// NORMAL_PRIORITY is the highest priority: Demons will be processed first.
    //        NORMAL_PRIORITY = 2,
    //      };

    //      enum BinaryIntervalRelation {
    //        /// t1 ends after t2 end, i.e. End(t1) >= End(t2) + delay.
    //        ENDS_AFTER_END,

    //        /// t1 ends after t2 start, i.e. End(t1) >= Start(t2) + delay.
    //        ENDS_AFTER_START,

    //        /// t1 ends at t2 end, i.e. End(t1) == End(t2) + delay.
    //        ENDS_AT_END,

    //        /// t1 ends at t2 start, i.e. End(t1) == Start(t2) + delay.
    //        ENDS_AT_START,

    //        /// t1 starts after t2 end, i.e. Start(t1) >= End(t2) + delay.
    //        STARTS_AFTER_END,

    //        /// t1 starts after t2 start, i.e. Start(t1) >= Start(t2) + delay.
    //        STARTS_AFTER_START,

    //        /// t1 starts at t2 end, i.e. Start(t1) == End(t2) + delay.
    //        STARTS_AT_END,

    //        /// t1 starts at t2 start, i.e. Start(t1) == Start(t2) + delay.
    //        STARTS_AT_START,

    //        /// STARTS_AT_START and ENDS_AT_END at the same time.
    //        /// t1 starts at t2 start, i.e. Start(t1) == Start(t2) + delay.
    //        /// t1 ends at t2 end, i.e. End(t1) == End(t2).
    //        STAYS_IN_SYNC
    //      };

    //      enum UnaryIntervalRelation {
    //        /// t ends after d, i.e. End(t) >= d.
    //        ENDS_AFTER,

    //        /// t ends at d, i.e. End(t) == d.
    //        ENDS_AT,

    //        /// t ends before d, i.e. End(t) <= d.
    //        ENDS_BEFORE,

    //        /// t starts after d, i.e. Start(t) >= d.
    //        STARTS_AFTER,

    //        /// t starts at d, i.e. Start(t) == d.
    //        STARTS_AT,

    //        /// t starts before d, i.e. Start(t) <= d.
    //        STARTS_BEFORE,

    //        /// STARTS_BEFORE and ENDS_AFTER at the same time, i.e. d is in t.
    //        /// t starts before d, i.e. Start(t) <= d.
    //        /// t ends after d, i.e. End(t) >= d.
    //        CROSS_DATE,

    //        /// STARTS_AFTER or ENDS_BEFORE, i.e. d is not in t.
    //        /// t starts after d, i.e. Start(t) >= d.
    //        /// t ends before d, i.e. End(t) <= d.
    //        AVOID_DATE
    //      };

    //      enum DecisionModification {
    //        /// Keeps the default behavior, i.e. apply left branch first, and then right
    //        /// branch in case of backtracking.
    //        NO_CHANGE,

    //        /// Right branches are ignored. This is used to make the code faster when
    //        /// backtrack makes no sense or is not useful.
    //        /// This is faster as there is no need to create one new node per decision.
    //        KEEP_LEFT,

    //        /// Left branches are ignored. This is used to make the code faster when
    //        /// backtrack makes no sense or is not useful.
    //        /// This is faster as there is no need to create one new node per decision.
    //        KEEP_RIGHT,

    //        /// Backtracks to the previous decisions, i.e. left and right branches are
    //        /// not applied.
    //        KILL_BOTH,

    //        /// Applies right branch first. Left branch will be applied in case of
    //        /// backtracking.
    //        SWITCH_BRANCHES
    //      };

    //      enum MarkerType { SENTINEL, SIMPLE_MARKER, CHOICE_POINT, REVERSIBLE_ACTION };

    //      enum SolverState {
    //        /// Before search, after search.
    //        OUTSIDE_SEARCH,
    //        /// Executing the root node.
    //        IN_ROOT_NODE,
    //        /// Executing the search code.
    //        IN_SEARCH,
    //        /// After successful NextSolution and before EndSearch.
    //        AT_SOLUTION,
    //        /// After failed NextSolution and before EndSearch.
    //        NO_MORE_SOLUTIONS,
    //        /// After search, the model is infeasible.
    //        PROBLEM_INFEASIBLE
    //      };

    //      enum OptimizationDirection { NOT_SET, MAXIMIZATION, MINIMIZATION };

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

    //      typedef std::function<int64_t(int64_t)> IndexEvaluator1;
    //      typedef std::function<int64_t(int64_t, int64_t)> IndexEvaluator2;
    //      typedef std::function<int64_t(int64_t, int64_t, int64_t)> IndexEvaluator3;

    //      typedef std::function<bool(int64_t)> IndexFilter1;

    //      typedef std::function<IntVar*(int64_t)> Int64ToIntVar;

    //      typedef std::function<int64_t(Solver* solver,
    //                                    const std::vector<IntVar*>& vars,
    //                                    int64_t first_unbound, int64_t last_unbound)>
    //          VariableIndexSelector;

    //      typedef std::function<int64_t(const IntVar* v, int64_t id)>
    //          VariableValueSelector;
    //      typedef std::function<bool(int64_t, int64_t, int64_t)>
    //          VariableValueComparator;
    //      typedef std::function<DecisionModification()> BranchSelector;
    //      // TODO(user): wrap in swig.
    //      typedef std::function<void(Solver*)> Action;
    //      typedef std::function<void()> Closure;

    constructor(name: string);
    //      Solver(const std::string& name, const ConstraintSolverParameters& parameters);

    //    #ifndef SWIG
    //      // This type is neither copyable nor movable.
    //      Solver(const Solver&) = delete;
    //      Solver& operator=(const Solver&) = delete;
    //    #endif

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

    AddConstraint(c: Constraint): void;
    //      void AddCastConstraint(CastConstraint* constraint, IntVar* target_var,
    //                             IntExpr* expr);

    //      bool Solve(DecisionBuilder* db, const std::vector<SearchMonitor*>& monitors);
    //      bool Solve(DecisionBuilder* db);
    //      bool Solve(DecisionBuilder* db, SearchMonitor* m1);
    //      bool Solve(DecisionBuilder* db, SearchMonitor* m1, SearchMonitor* m2);
    //      bool Solve(DecisionBuilder* db, SearchMonitor* m1, SearchMonitor* m2,
    //                 SearchMonitor* m3);
    //      bool Solve(DecisionBuilder* db, SearchMonitor* m1, SearchMonitor* m2,
    //                 SearchMonitor* m3, SearchMonitor* m4);


    //      void NewSearch(DecisionBuilder* db,
    //                     const std::vector<SearchMonitor*>& monitors);
    NewSearch(db: DecisionBuilder): void;
    //      void NewSearch(DecisionBuilder* db, SearchMonitor* m1);
    //      void NewSearch(DecisionBuilder* db, SearchMonitor* m1, SearchMonitor* m2);
    //      void NewSearch(DecisionBuilder* db, SearchMonitor* m1, SearchMonitor* m2,
    //                     SearchMonitor* m3);
    //      void NewSearch(DecisionBuilder* db, SearchMonitor* m1, SearchMonitor* m2,
    //                     SearchMonitor* m3, SearchMonitor* m4);

    NextSolution(): boolean;
    //      void RestartSearch();
    EndSearch(): void;

    //      bool SolveAndCommit(DecisionBuilder* db,
    //                          const std::vector<SearchMonitor*>& monitors);
    //      bool SolveAndCommit(DecisionBuilder* db);
    //      bool SolveAndCommit(DecisionBuilder* db, SearchMonitor* m1);
    //      bool SolveAndCommit(DecisionBuilder* db, SearchMonitor* m1,
    //                          SearchMonitor* m2);
    //      bool SolveAndCommit(DecisionBuilder* db, SearchMonitor* m1, SearchMonitor* m2,
    //                          SearchMonitor* m3);

    //      bool CheckAssignment(Assignment* solution);

    //      bool CheckConstraint(Constraint* ct);

    //      SolverState state() const { return state_; }

    //      void Fail();

    //    #if !defined(SWIG)
    //      void AddBacktrackAction(Action a, bool fast);
    //    #endif  /// !defined(SWIG)

    //      std::string DebugString() const;

    static MemoryUsage(): number;

    //      absl::Time Now() const;

    wall_time(): number;

    //      int64_t branches() const { return branches_; }

    solutions(): number;

    //      int64_t unchecked_solutions() const;

    //      int64_t demon_runs(DemonPriority p) const { return demon_runs_[p]; }

    //      int64_t failures() const { return fails_; }

    //      int64_t neighbors() const { return neighbors_; }

    //      void ClearNeighbors() { neighbors_ = 0; }
    //      void IncrementNeighbors() { ++neighbors_; }

    //      int64_t filtered_neighbors() const { return filtered_neighbors_; }

    //      int64_t accepted_neighbors() const { return accepted_neighbors_; }

    //      uint64_t stamp() const;

    //      uint64_t fail_stamp() const;

    //      void set_context(absl::string_view context) { context_ = context; }

    //      const std::string& context() const { return context_; }

    //      OptimizationDirection optimization_direction() const {
    //        return optimization_direction_;
    //      }
    //      void set_optimization_direction(OptimizationDirection direction) {
    //        optimization_direction_ = direction;
    //      }

    //      // All factories (MakeXXX methods) encapsulate creation of objects
    //      // through RevAlloc(). Hence, the Solver used for allocating the
    //      // returned object will retain ownership of the allocated memory.
    //      // Destructors are called upon backtrack, or when the Solver is
    //      // itself destructed.

    //      // ----- Int Variables and Constants -----

    MakeIntVar(min: number, max: number, name: string): IntVar;
    MakeIntVar(values: number[], name: string): IntVar;
    //      IntVar* MakeIntVar(const std::vector<int>& values, const std::string& name);
    //      IntVar* MakeIntVar(int64_t min, int64_t max);
    //      IntVar* MakeIntVar(const std::vector<int64_t>& values);
    //      IntVar* MakeIntVar(const std::vector<int>& values);

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

    //      // ----- Integer Expressions -----

    //      IntExpr* MakeSum(IntExpr* left, IntExpr* right);
    //      IntExpr* MakeSum(IntExpr* expr, int64_t value);
    //      IntExpr* MakeSum(const std::vector<IntVar*>& vars);

    //      IntExpr* MakeScalProd(const std::vector<IntVar*>& vars,
    //                            const std::vector<int64_t>& coefs);
    //      IntExpr* MakeScalProd(const std::vector<IntVar*>& vars,
    //                            const std::vector<int>& coefs);

    //      IntExpr* MakeDifference(IntExpr* left, IntExpr* right);
    //      IntExpr* MakeDifference(int64_t value, IntExpr* expr);
    //      IntExpr* MakeOpposite(IntExpr* expr);

    //      IntExpr* MakeProd(IntExpr* left, IntExpr* right);
    //      IntExpr* MakeProd(IntExpr* expr, int64_t value);

    //      IntExpr* MakeDiv(IntExpr* expr, int64_t value);
    //      IntExpr* MakeDiv(IntExpr* numerator, IntExpr* denominator);

    //      IntExpr* MakeAbs(IntExpr* expr);
    //      IntExpr* MakeSquare(IntExpr* expr);
    //      IntExpr* MakePower(IntExpr* expr, int64_t n);

    //      IntExpr* MakeElement(const std::vector<int64_t>& values, IntVar* index);
    //      IntExpr* MakeElement(const std::vector<int>& values, IntVar* index);

    //      IntExpr* MakeElement(IndexEvaluator1 values, IntVar* index);
    //      IntExpr* MakeMonotonicElement(IndexEvaluator1 values, bool increasing,
    //                                    IntVar* index);
    //      IntExpr* MakeElement(IndexEvaluator2 values, IntVar* index1, IntVar* index2);

    //      IntExpr* MakeElement(const std::vector<IntVar*>& vars, IntVar* index);

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

    //      Constraint* MakeIfThenElseCt(IntVar* condition, IntExpr* then_expr,
    //                                   IntExpr* else_expr, IntVar* target_var);

    //      IntExpr* MakeMin(const std::vector<IntVar*>& vars);
    //      IntExpr* MakeMin(IntExpr* left, IntExpr* right);
    //      IntExpr* MakeMin(IntExpr* expr, int64_t value);
    //      IntExpr* MakeMin(IntExpr* expr, int value);

    //      IntExpr* MakeMax(const std::vector<IntVar*>& vars);
    //      IntExpr* MakeMax(IntExpr* left, IntExpr* right);
    //      IntExpr* MakeMax(IntExpr* expr, int64_t value);
    //      IntExpr* MakeMax(IntExpr* expr, int value);

    //      IntExpr* MakeConvexPiecewiseExpr(IntExpr* expr, int64_t early_cost,
    //                                       int64_t early_date, int64_t late_date,
    //                                       int64_t late_cost);

    //      IntExpr* MakeSemiContinuousExpr(IntExpr* expr, int64_t fixed_charge,
    //                                      int64_t step);

    //      // TODO(user): Investigate if we can merge all three piecewise linear
    //    #ifndef SWIG
    //      IntExpr* MakePiecewiseLinearExpr(IntExpr* expr,
    //                                       const PiecewiseLinearFunction& f);
    //    #endif

    //      IntExpr* MakeModulo(IntExpr* x, int64_t mod);

    //      IntExpr* MakeModulo(IntExpr* x, IntExpr* mod);

    //      IntExpr* MakeConditionalExpression(IntVar* condition, IntExpr* expr,
    //                                         int64_t unperformed_value);

    //      Constraint* MakeTrueConstraint();
    //      Constraint* MakeFalseConstraint();
    //      Constraint* MakeFalseConstraint(const std::string& explanation);

    //      Constraint* MakeIsEqualCstCt(IntExpr* var, int64_t value, IntVar* boolvar);
    //      IntVar* MakeIsEqualCstVar(IntExpr* var, int64_t value);
    //      Constraint* MakeIsEqualCt(IntExpr* v1, IntExpr* v2, IntVar* b);
    //      IntVar* MakeIsEqualVar(IntExpr* v1, IntExpr* v2);
    //      Constraint* MakeEquality(IntExpr* left, IntExpr* right);
    //      Constraint* MakeEquality(IntExpr* expr, int64_t value);
    //      Constraint* MakeEquality(IntExpr* expr, int value);

    //      Constraint* MakeIsDifferentCstCt(IntExpr* var, int64_t value,
    //                                       IntVar* boolvar);
    //      IntVar* MakeIsDifferentCstVar(IntExpr* var, int64_t value);
    //      IntVar* MakeIsDifferentVar(IntExpr* v1, IntExpr* v2);
    //      Constraint* MakeIsDifferentCt(IntExpr* v1, IntExpr* v2, IntVar* b);
    //      Constraint* MakeNonEquality(IntExpr* left, IntExpr* right);
    //      Constraint* MakeNonEquality(IntExpr* expr, int64_t value);
    //      Constraint* MakeNonEquality(IntExpr* expr, int value);

    //      Constraint* MakeIsLessOrEqualCstCt(IntExpr* var, int64_t value,
    //                                         IntVar* boolvar);
    //      IntVar* MakeIsLessOrEqualCstVar(IntExpr* var, int64_t value);
    //      IntVar* MakeIsLessOrEqualVar(IntExpr* left, IntExpr* right);
    //      Constraint* MakeIsLessOrEqualCt(IntExpr* left, IntExpr* right, IntVar* b);
    //      Constraint* MakeLessOrEqual(IntExpr* left, IntExpr* right);
    //      Constraint* MakeLessOrEqual(IntExpr* expr, int64_t value);
    //      Constraint* MakeLessOrEqual(IntExpr* expr, int value);

    //      Constraint* MakeIsGreaterOrEqualCstCt(IntExpr* var, int64_t value,
    //                                            IntVar* boolvar);
    //      IntVar* MakeIsGreaterOrEqualCstVar(IntExpr* var, int64_t value);
    //      IntVar* MakeIsGreaterOrEqualVar(IntExpr* left, IntExpr* right);
    //      Constraint* MakeIsGreaterOrEqualCt(IntExpr* left, IntExpr* right, IntVar* b);
    //      Constraint* MakeGreaterOrEqual(IntExpr* left, IntExpr* right);
    //      Constraint* MakeGreaterOrEqual(IntExpr* expr, int64_t value);
    //      Constraint* MakeGreaterOrEqual(IntExpr* expr, int value);

    //      Constraint* MakeIsGreaterCstCt(IntExpr* v, int64_t c, IntVar* b);
    //      IntVar* MakeIsGreaterCstVar(IntExpr* var, int64_t value);
    //      IntVar* MakeIsGreaterVar(IntExpr* left, IntExpr* right);
    //      Constraint* MakeIsGreaterCt(IntExpr* left, IntExpr* right, IntVar* b);
    //      Constraint* MakeGreater(IntExpr* left, IntExpr* right);
    //      Constraint* MakeGreater(IntExpr* expr, int64_t value);
    //      Constraint* MakeGreater(IntExpr* expr, int value);

    //      Constraint* MakeIsLessCstCt(IntExpr* v, int64_t c, IntVar* b);
    //      IntVar* MakeIsLessCstVar(IntExpr* var, int64_t value);
    //      IntVar* MakeIsLessVar(IntExpr* left, IntExpr* right);
    //      Constraint* MakeIsLessCt(IntExpr* left, IntExpr* right, IntVar* b);
    //      Constraint* MakeLess(IntExpr* left, IntExpr* right);
    //      Constraint* MakeLess(IntExpr* expr, int64_t value);
    //      Constraint* MakeLess(IntExpr* expr, int value);

    //      Constraint* MakeSumLessOrEqual(const std::vector<IntVar*>& vars, int64_t cst);
    //      Constraint* MakeSumGreaterOrEqual(const std::vector<IntVar*>& vars,
    //                                        int64_t cst);
    //      Constraint* MakeSumEquality(const std::vector<IntVar*>& vars, int64_t cst);
    //      Constraint* MakeSumEquality(const std::vector<IntVar*>& vars, IntVar* var);
    //      Constraint* MakeScalProdEquality(const std::vector<IntVar*>& vars,
    //                                       const std::vector<int64_t>& coefficients,
    //                                       int64_t cst);
    //      Constraint* MakeScalProdEquality(const std::vector<IntVar*>& vars,
    //                                       const std::vector<int>& coefficients,
    //                                       int64_t cst);
    //      Constraint* MakeScalProdEquality(const std::vector<IntVar*>& vars,
    //                                       const std::vector<int64_t>& coefficients,
    //                                       IntVar* target);
    //      Constraint* MakeScalProdEquality(const std::vector<IntVar*>& vars,
    //                                       const std::vector<int>& coefficients,
    //                                       IntVar* target);
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
    //                                  IntVar* min_var);
    //      Constraint* MakeMaxEquality(const std::vector<IntVar*>& vars,
    //                                  IntVar* max_var);

    //      Constraint* MakeElementEquality(const std::vector<int64_t>& vals,
    //                                      IntVar* index, IntVar* target);
    //      Constraint* MakeElementEquality(const std::vector<int>& vals, IntVar* index,
    //                                      IntVar* target);
    //      Constraint* MakeElementEquality(const std::vector<IntVar*>& vars,
    //                                      IntVar* index, IntVar* target);
    //      Constraint* MakeElementEquality(const std::vector<IntVar*>& vars,
    //                                      IntVar* index, int64_t target);
    //      Constraint* MakeAbsEquality(IntVar* var, IntVar* abs_var);
    //      Constraint* MakeIndexOfConstraint(const std::vector<IntVar*>& vars,
    //                                        IntVar* index, int64_t target);

    //      Demon* MakeConstraintInitialPropagateCallback(Constraint* ct);
    //      Demon* MakeDelayedConstraintInitialPropagateCallback(Constraint* ct);
    //    #if !defined(SWIG)
    //      Demon* MakeActionDemon(Action action);
    //    #endif  /// !defined(SWIG)
    //      Demon* MakeClosureDemon(Closure closure);

    //      // ----- Between and related constraints -----

    //      Constraint* MakeBetweenCt(IntExpr* expr, int64_t l, int64_t u);

    //      Constraint* MakeNotBetweenCt(IntExpr* expr, int64_t l, int64_t u);

    //      Constraint* MakeIsBetweenCt(IntExpr* expr, int64_t l, int64_t u, IntVar* b);
    //      IntVar* MakeIsBetweenVar(IntExpr* v, int64_t l, int64_t u);

    //      // ----- Member and related constraints -----

    //      Constraint* MakeMemberCt(IntExpr* expr, const std::vector<int64_t>& values);
    //      Constraint* MakeMemberCt(IntExpr* expr, const std::vector<int>& values);

    //      Constraint* MakeNotMemberCt(IntExpr* expr,
    //                                  const std::vector<int64_t>& values);
    //      Constraint* MakeNotMemberCt(IntExpr* expr, const std::vector<int>& values);

    //      Constraint* MakeNotMemberCt(IntExpr* expr, std::vector<int64_t> starts,
    //                                  std::vector<int64_t> ends);
    //      Constraint* MakeNotMemberCt(IntExpr* expr, std::vector<int> starts,
    //                                  std::vector<int> ends);
    //    #if !defined(SWIG)
    //      Constraint* MakeNotMemberCt(IntExpr* expr,
    //                                  SortedDisjointIntervalList intervals);
    //    #endif  // !defined(SWIG)

    //      Constraint* MakeIsMemberCt(IntExpr* expr, const std::vector<int64_t>& values,
    //                                 IntVar* boolvar);
    //      Constraint* MakeIsMemberCt(IntExpr* expr, const std::vector<int>& values,
    //                                 IntVar* boolvar);
    //      IntVar* MakeIsMemberVar(IntExpr* expr, const std::vector<int64_t>& values);
    //      IntVar* MakeIsMemberVar(IntExpr* expr, const std::vector<int>& values);

    //      Constraint* MakeAtMost(std::vector<IntVar*> vars, int64_t value,
    //                             int64_t max_count);
    //      Constraint* MakeCount(const std::vector<IntVar*>& vars, int64_t value,
    //                            int64_t max_count);
    //      Constraint* MakeCount(const std::vector<IntVar*>& vars, int64_t value,
    //                            IntVar* max_count);

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
    //                                IntVar* deviation_var, int64_t total_sum);

    MakeAllDifferent(vars: IntVar[]): Constraint;

    //      Constraint* MakeAllDifferent(const std::vector<IntVar*>& vars,
    //                                   bool stronger_propagation);

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

    //      Constraint* MakeLexicalLessOrEqualWithOffsets(std::vector<IntVar*> left,
    //                                                    std::vector<IntVar*> right,
    //                                                    std::vector<int64_t> offsets);

    //      // Semi-reified version of the above: boolvar -> LexLE(left, right, offsets).
    //      Constraint* MakeIsLexicalLessOrEqualWithOffsetsCt(
    //          std::vector<IntVar*> left, std::vector<IntVar*> right,
    //          std::vector<int64_t> offsets, IntVar* boolvar);

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
    //          absl::Span<const int> lifo_path_starts,
    //          absl::Span<const int> fifo_path_starts);
    //      Constraint* MakePathTransitPrecedenceConstraint(
    //          std::vector<IntVar*> nexts, std::vector<IntVar*> transits,
    //          const std::vector<std::pair<int, int>>& precedences);
    //      struct PathEnergyCostConstraintSpecification {
    //        std::vector<IntVar*> nexts;
    //        std::vector<IntVar*> paths;
    //        std::vector<IntVar*> forces;
    //        std::vector<IntVar*> distances;
    //        std::vector<int64_t> path_unit_costs;
    //        std::vector<bool> path_used_when_empty;
    //        std::vector<int64_t> path_starts;
    //        std::vector<int64_t> path_ends;
    //        std::vector<IntVar*> costs;
    //      };
    //      Constraint* MakePathEnergyCostConstraint(
    //          PathEnergyCostConstraintSpecification specification);
    //    #endif  // !SWIG
    //      Constraint* MakeMapDomain(IntVar* var, const std::vector<IntVar*>& actives);

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
    //          absl::Span<const int64_t> x_size, absl::Span<const int64_t> y_size);
    //      Constraint* MakeNonOverlappingBoxesConstraint(
    //          const std::vector<IntVar*>& x_vars, const std::vector<IntVar*>& y_vars,
    //          absl::Span<const int> x_size, absl::Span<const int> y_size);

    //      Constraint* MakeNonOverlappingNonStrictBoxesConstraint(
    //          const std::vector<IntVar*>& x_vars, const std::vector<IntVar*>& y_vars,
    //          const std::vector<IntVar*>& x_size, const std::vector<IntVar*>& y_size);
    //      Constraint* MakeNonOverlappingNonStrictBoxesConstraint(
    //          const std::vector<IntVar*>& x_vars, const std::vector<IntVar*>& y_vars,
    //          absl::Span<const int64_t> x_size, absl::Span<const int64_t> y_size);
    //      Constraint* MakeNonOverlappingNonStrictBoxesConstraint(
    //          const std::vector<IntVar*>& x_vars, const std::vector<IntVar*>& y_vars,
    //          absl::Span<const int> x_size, absl::Span<const int> y_size);

    //      Pack* MakePack(const std::vector<IntVar*>& vars, int number_of_bins);

    //      IntervalVar* MakeFixedDurationIntervalVar(int64_t start_min,
    //                                                int64_t start_max, int64_t duration,
    //                                                bool optional,
    //                                                const std::string& name);

    //      void MakeFixedDurationIntervalVarArray(int count, int64_t start_min,
    //                                             int64_t start_max, int64_t duration,
    //                                             bool optional, absl::string_view name,
    //                                             std::vector<IntervalVar*>* array);

    //      IntervalVar* MakeFixedDurationIntervalVar(IntVar* start_variable,
    //                                                int64_t duration,
    //                                                const std::string& name);

    //      IntervalVar* MakeFixedDurationIntervalVar(IntVar* start_variable,
    //                                                int64_t duration,
    //                                                IntVar* performed_variable,
    //                                                const std::string& name);

    //      void MakeFixedDurationIntervalVarArray(
    //          const std::vector<IntVar*>& start_variables, int64_t duration,
    //          absl::string_view name, std::vector<IntervalVar*>* array);

    //      void MakeFixedDurationIntervalVarArray(
    //          const std::vector<IntVar*>& start_variables,
    //          absl::Span<const int64_t> durations, absl::string_view name,
    //          std::vector<IntervalVar*>* array);
    //      void MakeFixedDurationIntervalVarArray(
    //          const std::vector<IntVar*>& start_variables,
    //          absl::Span<const int> durations, absl::string_view name,
    //          std::vector<IntervalVar*>* array);

    //      void MakeFixedDurationIntervalVarArray(
    //          const std::vector<IntVar*>& start_variables,
    //          absl::Span<const int64_t> durations,
    //          const std::vector<IntVar*>& performed_variables, absl::string_view name,
    //          std::vector<IntervalVar*>* array);

    //      void MakeFixedDurationIntervalVarArray(
    //          const std::vector<IntVar*>& start_variables,
    //          absl::Span<const int> durations,
    //          const std::vector<IntVar*>& performed_variables, absl::string_view name,
    //          std::vector<IntervalVar*>* array);

    //      IntervalVar* MakeFixedInterval(int64_t start, int64_t duration,
    //                                     const std::string& name);

    //      IntervalVar* MakeIntervalVar(int64_t start_min, int64_t start_max,
    //                                   int64_t duration_min, int64_t duration_max,
    //                                   int64_t end_min, int64_t end_max, bool optional,
    //                                   const std::string& name);

    //      void MakeIntervalVarArray(int count, int64_t start_min, int64_t start_max,
    //                                int64_t duration_min, int64_t duration_max,
    //                                int64_t end_min, int64_t end_max, bool optional,
    //                                absl::string_view name,
    //                                std::vector<IntervalVar*>* array);

    //      IntervalVar* MakeMirrorInterval(IntervalVar* interval_var);

    //      IntervalVar* MakeFixedDurationStartSyncedOnStartIntervalVar(
    //          IntervalVar* interval_var, int64_t duration, int64_t offset);

    //      IntervalVar* MakeFixedDurationStartSyncedOnEndIntervalVar(
    //          IntervalVar* interval_var, int64_t duration, int64_t offset);

    //      IntervalVar* MakeFixedDurationEndSyncedOnStartIntervalVar(
    //          IntervalVar* interval_var, int64_t duration, int64_t offset);

    //      IntervalVar* MakeFixedDurationEndSyncedOnEndIntervalVar(
    //          IntervalVar* interval_var, int64_t duration, int64_t offset);

    //      IntervalVar* MakeIntervalRelaxedMin(IntervalVar* interval_var);

    //      IntervalVar* MakeIntervalRelaxedMax(IntervalVar* interval_var);

    //      Constraint* MakeIntervalVarRelation(IntervalVar* t, UnaryIntervalRelation r,
    //                                          int64_t d);

    //      Constraint* MakeIntervalVarRelation(IntervalVar* t1, BinaryIntervalRelation r,
    //                                          IntervalVar* t2);

    //      Constraint* MakeIntervalVarRelationWithDelay(IntervalVar* t1,
    //                                                   BinaryIntervalRelation r,
    //                                                   IntervalVar* t2, int64_t delay);

    //      Constraint* MakeTemporalDisjunction(IntervalVar* t1, IntervalVar* t2,
    //                                          IntVar* alt);

    //      Constraint* MakeTemporalDisjunction(IntervalVar* t1, IntervalVar* t2);

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
    //                                 IntVar* capacity, absl::string_view name);

    //      Constraint* MakeCumulative(const std::vector<IntervalVar*>& intervals,
    //                                 const std::vector<int>& demands, IntVar* capacity,
    //                                 const std::string& name);

    //      Constraint* MakeCumulative(const std::vector<IntervalVar*>& intervals,
    //                                 const std::vector<IntVar*>& demands,
    //                                 int64_t capacity, const std::string& name);

    //      Constraint* MakeCumulative(const std::vector<IntervalVar*>& intervals,
    //                                 const std::vector<IntVar*>& demands,
    //                                 IntVar* capacity, const std::string& name);

    //      Constraint* MakeCover(const std::vector<IntervalVar*>& vars,
    //                            IntervalVar* target_var);

    //      Constraint* MakeEquality(IntervalVar* var1, IntervalVar* var2);

    //      Assignment* MakeAssignment();

    //      Assignment* MakeAssignment(const Assignment* a);

    //      SolutionCollector* MakeFirstSolutionCollector(const Assignment* assignment);
    //      SolutionCollector* MakeFirstSolutionCollector();

    //      SolutionCollector* MakeLastSolutionCollector(const Assignment* assignment);
    //      SolutionCollector* MakeLastSolutionCollector();

    //      SolutionCollector* MakeBestValueSolutionCollector(
    //          const Assignment* assignment, bool maximize);
    //      SolutionCollector* MakeBestLexicographicValueSolutionCollector(
    //          const Assignment* assignment, std::vector<bool> maximize);
    //      SolutionCollector* MakeBestValueSolutionCollector(bool maximize);
    //      SolutionCollector* MakeBestLexicographicValueSolutionCollector(
    //          std::vector<bool> maximize);

    //      SolutionCollector* MakeNBestValueSolutionCollector(
    //          const Assignment* assignment, int solution_count, bool maximize);
    //      SolutionCollector* MakeNBestValueSolutionCollector(int solution_count,
    //                                                         bool maximize);
    //      SolutionCollector* MakeNBestLexicographicValueSolutionCollector(
    //          const Assignment* assignment, int solution_count,
    //          std::vector<bool> maximize);
    //      SolutionCollector* MakeNBestLexicographicValueSolutionCollector(
    //          int solution_count, std::vector<bool> maximize);

    //      SolutionCollector* MakeAllSolutionCollector(const Assignment* assignment);
    //      SolutionCollector* MakeAllSolutionCollector();

    //      OptimizeVar* MakeMinimize(IntVar* v, int64_t step);

    //      OptimizeVar* MakeMaximize(IntVar* v, int64_t step);

    //      OptimizeVar* MakeOptimize(bool maximize, IntVar* v, int64_t step);

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

    //      OptimizeVar* MakeLexicographicOptimize(std::vector<bool> maximize,
    //                                             std::vector<IntVar*> variables,
    //                                             std::vector<int64_t> steps);



    //      ObjectiveMonitor* MakeTabuSearch(bool maximize, IntVar* objective,
    //                                       int64_t step,
    //                                       const std::vector<IntVar*>& vars,
    //                                       int64_t keep_tenure, int64_t forbid_tenure,
    //                                       double tabu_factor);

    //      ObjectiveMonitor* MakeLexicographicTabuSearch(
    //          const std::vector<bool>& maximize, std::vector<IntVar*> objectives,
    //          std::vector<int64_t> steps, const std::vector<IntVar*>& vars,
    //          int64_t keep_tenure, int64_t forbid_tenure, double tabu_factor);

    //      ObjectiveMonitor* MakeGenericTabuSearch(bool maximize, IntVar* v,
    //                                              int64_t step,
    //                                              const std::vector<IntVar*>& tabu_vars,
    //                                              int64_t forbid_tenure);

    //      // TODO(user): document behavior
    //      ObjectiveMonitor* MakeSimulatedAnnealing(bool maximize, IntVar* v,
    //                                               int64_t step,
    //                                               int64_t initial_temperature);
    //      ObjectiveMonitor* MakeLexicographicSimulatedAnnealing(
    //          const std::vector<bool>& maximize, std::vector<IntVar*> vars,
    //          std::vector<int64_t> steps, std::vector<int64_t> initial_temperatures);

    //      ObjectiveMonitor* MakeGuidedLocalSearch(
    //          bool maximize, IntVar* objective, IndexEvaluator2 objective_function,
    //          int64_t step, const std::vector<IntVar*>& vars, double penalty_factor,
    //          bool reset_penalties_on_new_best_solution = false);
    //      ObjectiveMonitor* MakeGuidedLocalSearch(
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

    //      ABSL_MUST_USE_RESULT SearchLimit* MakeLimit(SearchLimit* limit_1,
    //                                                  SearchLimit* limit_2);

    //      ABSL_MUST_USE_RESULT ImprovementSearchLimit* MakeImprovementLimit(
    //          IntVar* objective_var, bool maximize, double objective_scaling_factor,
    //          double objective_offset, double improvement_rate_coefficient,
    //          int improvement_rate_solutions_distance);
    //      ABSL_MUST_USE_RESULT ImprovementSearchLimit*
    //      MakeLexicographicImprovementLimit(
    //          std::vector<IntVar*> objective_vars, std::vector<bool> maximize,
    //          std::vector<double> objective_scaling_factors,
    //          std::vector<double> objective_offsets,
    //          double improvement_rate_coefficient,
    //          int improvement_rate_solutions_distance);

    //      ABSL_MUST_USE_RESULT SearchLimit* MakeCustomLimit(
    //          std::function<bool()> limiter);

    //      // TODO(user): DEPRECATE API of MakeSearchLog(.., IntVar* var,..).

    //      SearchMonitor* MakeSearchLog(int branch_period);

    //      SearchMonitor* MakeSearchLog(int branch_period, IntVar* var);

    //      SearchMonitor* MakeSearchLog(int branch_period,
    //                                   std::function<std::string()> display_callback);

    //      SearchMonitor* MakeSearchLog(int branch_period, IntVar* var,
    //                                   std::function<std::string()> display_callback);

    //      SearchMonitor* MakeSearchLog(int branch_period, std::vector<IntVar*> vars,
    //                                   std::function<std::string()> display_callback);

    //      SearchMonitor* MakeSearchLog(int branch_period, OptimizeVar* opt_var);

    //      SearchMonitor* MakeSearchLog(int branch_period, OptimizeVar* opt_var,
    //                                   std::function<std::string()> display_callback);

    //      struct SearchLogParameters {
    //        /// SearchMonitors will display a periodic search log every branch_period
    //        /// branches explored.
    //        int branch_period = 1;
    //        /// SearchMonitors will display values of objective or variables (both
    //        /// cannot be used together).
    //        OptimizeVar* objective = nullptr;
    //        std::vector<IntVar*> variables;
    //        /// When displayed, objective or var values will be scaled and offset by
    //        /// the given values in the following way:
    //        /// scaling_factor * (value + offset).
    //        std::vector<double> scaling_factors;
    //        std::vector<double> offsets;
    //        /// SearchMonitors will display the result of display_callback at each new
    //        /// solution found and when the search finishes if
    //        /// display_on_new_solutions_only is false.
    //        std::function<std::string()> display_callback;
    //        /// To be used to protect from cases where display_callback assumes
    //        /// variables are instantiated, which only happens in AtSolution().
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
    //          absl::flat_hash_map<const IntVar*, int>* map);
    //    #endif  // !defined(SWIG)

    //      SearchMonitor* MakeSymmetryManager(
    //          const std::vector<SymmetryBreaker*>& visitors);
    //      SearchMonitor* MakeSymmetryManager(SymmetryBreaker* v1);
    //      SearchMonitor* MakeSymmetryManager(SymmetryBreaker* v1, SymmetryBreaker* v2);
    //      SearchMonitor* MakeSymmetryManager(SymmetryBreaker* v1, SymmetryBreaker* v2,
    //                                         SymmetryBreaker* v3);
    //      SearchMonitor* MakeSymmetryManager(SymmetryBreaker* v1, SymmetryBreaker* v2,
    //                                         SymmetryBreaker* v3, SymmetryBreaker* v4);

    //      Decision* MakeAssignVariableValue(IntVar* var, int64_t val);
    //      Decision* MakeVariableLessOrEqualValue(IntVar* var, int64_t value);
    //      Decision* MakeVariableGreaterOrEqualValue(IntVar* var, int64_t value);
    //      Decision* MakeSplitVariableDomain(IntVar* var, int64_t val,
    //                                        bool start_with_lower_half);
    //      Decision* MakeAssignVariableValueOrFail(IntVar* var, int64_t value);
    //      Decision* MakeAssignVariableValueOrDoNothing(IntVar* var, int64_t value);
    //      Decision* MakeAssignVariablesValues(const std::vector<IntVar*>& vars,
    //                                          const std::vector<int64_t>& values);
    //      Decision* MakeAssignVariablesValuesOrDoNothing(
    //          const std::vector<IntVar*>& vars, const std::vector<int64_t>& values);
    //      Decision* MakeAssignVariablesValuesOrFail(const std::vector<IntVar*>& vars,
    //                                                const std::vector<int64_t>& values);
    //      Decision* MakeFailDecision();
    //      Decision* MakeDecision(Action apply, Action refute);

    //      DecisionBuilder* Compose(DecisionBuilder* db1, DecisionBuilder* db2);
    //      DecisionBuilder* Compose(DecisionBuilder* db1, DecisionBuilder* db2,
    //                               DecisionBuilder* db3);
    //      DecisionBuilder* Compose(DecisionBuilder* db1, DecisionBuilder* db2,
    //                               DecisionBuilder* db3, DecisionBuilder* db4);
    //      DecisionBuilder* Compose(const std::vector<DecisionBuilder*>& dbs);

    //      // TODO(user): The search tree can be balanced by using binary
    //      DecisionBuilder* Try(DecisionBuilder* db1, DecisionBuilder* db2);
    //      DecisionBuilder* Try(DecisionBuilder* db1, DecisionBuilder* db2,
    //                           DecisionBuilder* db3);
    //      DecisionBuilder* Try(DecisionBuilder* db1, DecisionBuilder* db2,
    //                           DecisionBuilder* db3, DecisionBuilder* db4);
    //      DecisionBuilder* Try(const std::vector<DecisionBuilder*>& dbs);

    MakePhase(vars: IntVar[], var_str: IntVarStrategy, val_str: IntValueStrategy): DecisionBuilder;
    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IndexEvaluator1 var_evaluator,
    //                                 IntValueStrategy val_str);

    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IntVarStrategy var_str,
    //                                 IndexEvaluator2 value_evaluator);

    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IntVarStrategy var_str,
    //                                 VariableValueComparator var_val1_val2_comparator);

    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IndexEvaluator1 var_evaluator,
    //                                 IndexEvaluator2 value_evaluator);

    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IntVarStrategy var_str,
    //                                 IndexEvaluator2 value_evaluator,
    //                                 IndexEvaluator1 tie_breaker);

    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IndexEvaluator1 var_evaluator,
    //                                 IndexEvaluator2 value_evaluator,
    //                                 IndexEvaluator1 tie_breaker);

    //      DecisionBuilder* MakeDefaultPhase(const std::vector<IntVar*>& vars);
    //      DecisionBuilder* MakeDefaultPhase(const std::vector<IntVar*>& vars,
    //                                        const DefaultPhaseParameters& parameters);

    //      DecisionBuilder* MakePhase(IntVar* v0, IntVarStrategy var_str,
    //                                 IntValueStrategy val_str);
    //      DecisionBuilder* MakePhase(IntVar* v0, IntVar* v1, IntVarStrategy var_str,
    //                                 IntValueStrategy val_str);
    //      DecisionBuilder* MakePhase(IntVar* v0, IntVar* v1, IntVar* v2,
    //                                 IntVarStrategy var_str, IntValueStrategy val_str);
    //      DecisionBuilder* MakePhase(IntVar* v0, IntVar* v1, IntVar* v2, IntVar* v3,
    //                                 IntVarStrategy var_str, IntValueStrategy val_str);

    //      Decision* MakeScheduleOrPostpone(IntervalVar* var, int64_t est,
    //                                       int64_t* marker);

    //      Decision* MakeScheduleOrExpedite(IntervalVar* var, int64_t est,
    //                                       int64_t* marker);

    //      Decision* MakeRankFirstInterval(SequenceVar* sequence, int index);

    //      Decision* MakeRankLastInterval(SequenceVar* sequence, int index);

    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IndexEvaluator2 eval, EvaluatorStrategy str);

    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IndexEvaluator2 eval, IndexEvaluator1 tie_breaker,
    //                                 EvaluatorStrategy str);

    //      DecisionBuilder* MakePhase(const std::vector<IntervalVar*>& intervals,
    //                                 IntervalStrategy str);

    //      DecisionBuilder* MakePhase(const std::vector<SequenceVar*>& sequences,
    //                                 SequenceStrategy str);

    //      DecisionBuilder* MakeDecisionBuilderFromAssignment(
    //          Assignment* assignment, DecisionBuilder* db,
    //          const std::vector<IntVar*>& vars);

    //      DecisionBuilder* MakeConstraintAdder(Constraint* ct);

    //      DecisionBuilder* MakeSolveOnce(DecisionBuilder* db);
    //      DecisionBuilder* MakeSolveOnce(DecisionBuilder* db, SearchMonitor* monitor1);
    //      DecisionBuilder* MakeSolveOnce(DecisionBuilder* db, SearchMonitor* monitor1,
    //                                     SearchMonitor* monitor2);
    //      DecisionBuilder* MakeSolveOnce(DecisionBuilder* db, SearchMonitor* monitor1,
    //                                     SearchMonitor* monitor2,
    //                                     SearchMonitor* monitor3);
    //      DecisionBuilder* MakeSolveOnce(DecisionBuilder* db, SearchMonitor* monitor1,
    //                                     SearchMonitor* monitor2,
    //                                     SearchMonitor* monitor3,
    //                                     SearchMonitor* monitor4);
    //      DecisionBuilder* MakeSolveOnce(DecisionBuilder* db,
    //                                     const std::vector<SearchMonitor*>& monitors);

    //      DecisionBuilder* MakeNestedOptimize(DecisionBuilder* db, Assignment* solution,
    //                                          bool maximize, int64_t step);
    //      DecisionBuilder* MakeNestedOptimize(DecisionBuilder* db, Assignment* solution,
    //                                          bool maximize, int64_t step,
    //                                          SearchMonitor* monitor1);
    //      DecisionBuilder* MakeNestedOptimize(DecisionBuilder* db, Assignment* solution,
    //                                          bool maximize, int64_t step,
    //                                          SearchMonitor* monitor1,
    //                                          SearchMonitor* monitor2);
    //      DecisionBuilder* MakeNestedOptimize(DecisionBuilder* db, Assignment* solution,
    //                                          bool maximize, int64_t step,
    //                                          SearchMonitor* monitor1,
    //                                          SearchMonitor* monitor2,
    //                                          SearchMonitor* monitor3);
    //      DecisionBuilder* MakeNestedOptimize(DecisionBuilder* db, Assignment* solution,
    //                                          bool maximize, int64_t step,
    //                                          SearchMonitor* monitor1,
    //                                          SearchMonitor* monitor2,
    //                                          SearchMonitor* monitor3,
    //                                          SearchMonitor* monitor4);
    //      DecisionBuilder* MakeNestedOptimize(
    //          DecisionBuilder* db, Assignment* solution, bool maximize, int64_t step,
    //          const std::vector<SearchMonitor*>& monitors);

    //      DecisionBuilder* MakeRestoreAssignment(Assignment* assignment);

    //      DecisionBuilder* MakeStoreAssignment(Assignment* assignment);

    //      LocalSearchOperator* MakeOperator(
    //          const std::vector<IntVar*>& vars, LocalSearchOperators op,
    //          std::function<const std::vector<int>&(int, int)> get_neighbors = nullptr);
    //      LocalSearchOperator* MakeOperator(
    //          const std::vector<IntVar*>& vars,
    //          const std::vector<IntVar*>& secondary_vars, LocalSearchOperators op,
    //          std::function<const std::vector<int>&(int, int)> get_neighbors = nullptr);
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

    //      LocalSearchOperator* MakeNeighborhoodLimit(LocalSearchOperator* op,
    //                                                 int64_t limit);

    //      // TODO(user): Make a variant which runs a local search after each
    //      //                solution found in a DFS.

    //      DecisionBuilder* MakeLocalSearchPhase(Assignment* assignment,
    //                                            LocalSearchPhaseParameters* parameters);
    //      DecisionBuilder* MakeLocalSearchPhase(const std::vector<IntVar*>& vars,
    //                                            DecisionBuilder* first_solution,
    //                                            LocalSearchPhaseParameters* parameters);
    //      DecisionBuilder* MakeLocalSearchPhase(
    //          const std::vector<IntVar*>& vars, DecisionBuilder* first_solution,
    //          DecisionBuilder* first_solution_sub_decision_builder,
    //          LocalSearchPhaseParameters* parameters);
    //      DecisionBuilder* MakeLocalSearchPhase(const std::vector<SequenceVar*>& vars,
    //                                            DecisionBuilder* first_solution,
    //                                            LocalSearchPhaseParameters* parameters);

    //      Assignment* RunUncheckedLocalSearch(
    //          const Assignment* initial_solution,
    //          LocalSearchFilterManager* filter_manager,
    //          LocalSearchOperator* ls_operator,
    //          const std::vector<SearchMonitor*>& monitors, RegularLimit* limit,
    //          absl::flat_hash_set<IntVar*>* touched = nullptr);

    //      SolutionPool* MakeDefaultSolutionPool();

    //      LocalSearchPhaseParameters* MakeLocalSearchPhaseParameters(
    //          IntVar* objective, LocalSearchOperator* ls_operator,
    //          DecisionBuilder* sub_decision_builder);
    //      LocalSearchPhaseParameters* MakeLocalSearchPhaseParameters(
    //          IntVar* objective, LocalSearchOperator* ls_operator,
    //          DecisionBuilder* sub_decision_builder, RegularLimit* limit);
    //      LocalSearchPhaseParameters* MakeLocalSearchPhaseParameters(
    //          IntVar* objective, LocalSearchOperator* ls_operator,
    //          DecisionBuilder* sub_decision_builder, RegularLimit* limit,
    //          LocalSearchFilterManager* filter_manager);

    //      LocalSearchPhaseParameters* MakeLocalSearchPhaseParameters(
    //          IntVar* objective, SolutionPool* pool, LocalSearchOperator* ls_operator,
    //          DecisionBuilder* sub_decision_builder);
    //      LocalSearchPhaseParameters* MakeLocalSearchPhaseParameters(
    //          IntVar* objective, SolutionPool* pool, LocalSearchOperator* ls_operator,
    //          DecisionBuilder* sub_decision_builder, RegularLimit* limit);
    //      LocalSearchPhaseParameters* MakeLocalSearchPhaseParameters(
    //          IntVar* objective, SolutionPool* pool, LocalSearchOperator* ls_operator,
    //          DecisionBuilder* sub_decision_builder, RegularLimit* limit,
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

    constraints(): number;

    //      void Accept(ModelVisitor* visitor) const;

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
    //      Demon* RegisterDemon(Demon* demon);
    //      IntExpr* RegisterIntExpr(IntExpr* expr);
    //      IntVar* RegisterIntVar(IntVar* var);
    //      IntervalVar* RegisterIntervalVar(IntervalVar* var);

    //      Search* ActiveSearch() const;
    //      ModelCache* Cache() const;
    //      bool InstrumentsDemons() const;
    //      bool IsProfilingEnabled() const;
    //      bool IsLocalSearchProfilingEnabled() const;
    //      bool InstrumentsVariables() const;
    //      bool NameAllVariables() const;
    //      std::string model_name() const;
    //      PropagationMonitor* GetPropagationMonitor() const;
    //      void AddPropagationMonitor(PropagationMonitor* monitor);
    //      LocalSearchMonitor* GetLocalSearchMonitor() const;
    //      void AddLocalSearchMonitor(LocalSearchMonitor* monitor);
    //      void SetSearchContext(Search* search, absl::string_view search_context);
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
    //      friend class LocalSearch;
    //      friend class LocalSearchProfiler;

    //    #if !defined(SWIG)
    //      friend void InternalSaveBooleanVarValue(Solver*, IntVar*);
    //      template <class>
    //      friend class SimpleRevFIFO;
    //      template <class K, class V>
    //      friend class RevImmutableMultiMap;

    //      bool IsBooleanVar(IntExpr* expr, IntVar** inner_var, bool* is_negated) const;

    //      bool IsProduct(IntExpr* expr, IntExpr** inner_expr, int64_t* coefficient);
    //    #endif  /// !defined(SWIG)

    //      IntExpr* CastExpression(const IntVar* var) const;

    //      void FinishCurrentSearch();
    //      void RestartCurrentSearch();

    //      void ShouldFail() { should_fail_ = true; }
    //      void CheckFail() {
    //        if (!should_fail_) return;
    //        should_fail_ = false;
    //        Fail();
    //      }

    //      DecisionBuilder* MakeProfiledDecisionBuilderWrapper(DecisionBuilder* db);

    //     private:
    //      void Init();  /// Initialization. To be called by the constructors only.
    //      void PushState(MarkerType t, const StateInfo& info);
    //      MarkerType PopState(StateInfo* info);
    //      void PushSentinel(int magic_code);
    //      void BacktrackToSentinel(int magic_code);
    //      void ProcessConstraints();
    //      bool BacktrackOneLevel(Decision** fail_decision);
    //      void JumpToSentinelWhenNested();
    //      void JumpToSentinel();
    //      void check_alloc_state();
    //      void FreezeQueue();
    //      void EnqueueVar(Demon* d);
    //      void EnqueueDelayedDemon(Demon* d);
    //      void ExecuteAll(const SimpleRevFIFO<Demon*>& demons);
    //      void EnqueueAll(const SimpleRevFIFO<Demon*>& demons);
    //      void UnfreezeQueue();
    //      void reset_action_on_fail();
    //      void set_action_on_fail(Action a);
    //      void set_variable_to_clean_on_fail(IntVar* v);
    //      void IncrementUncheckedSolutionCounter();
    //      bool IsUncheckedSolutionLimitReached();

    //      void InternalSaveValue(int* valptr);
    //      void InternalSaveValue(int64_t* valptr);
    //      void InternalSaveValue(uint64_t* valptr);
    //      void InternalSaveValue(double* valptr);
    //      void InternalSaveValue(bool* valptr);
    //      void InternalSaveValue(void** valptr);
    //      void InternalSaveValue(int64_t** valptr) {
    //        InternalSaveValue(reinterpret_cast<void**>(valptr));
    //      }

    //      BaseObject* SafeRevAlloc(BaseObject* ptr);

    //      int* SafeRevAllocArray(int* ptr);
    //      int64_t* SafeRevAllocArray(int64_t* ptr);
    //      uint64_t* SafeRevAllocArray(uint64_t* ptr);
    //      double* SafeRevAllocArray(double* ptr);
    //      BaseObject** SafeRevAllocArray(BaseObject** ptr);
    //      IntVar** SafeRevAllocArray(IntVar** ptr);
    //      IntExpr** SafeRevAllocArray(IntExpr** ptr);
    //      Constraint** SafeRevAllocArray(Constraint** ptr);
    //      void* UnsafeRevAllocAux(void* ptr);
    //      template <class T>
    //      T* UnsafeRevAlloc(T* ptr) {
    //        return reinterpret_cast<T*>(
    //            UnsafeRevAllocAux(reinterpret_cast<void*>(ptr)));
    //      }
    //      void** UnsafeRevAllocArrayAux(void** ptr);
    //      template <class T>
    //      T** UnsafeRevAllocArray(T** ptr) {
    //        return reinterpret_cast<T**>(
    //            UnsafeRevAllocArrayAux(reinterpret_cast<void**>(ptr)));
    //      }

    //      void InitCachedIntConstants();
    //      void InitCachedConstraint();

    //      Search* TopLevelSearch() const { return searches_.at(1); }
    //      Search* ParentSearch() const {
    //        const size_t search_size = searches_.size();
    //        DCHECK_GT(search_size, 1);
    //        return searches_[search_size - 2];
    //      }

    //      template <bool is_profile_active>
    //      Assignment* RunUncheckedLocalSearchInternal(
    //          const Assignment* initial_solution,
    //          LocalSearchFilterManager* filter_manager,
    //          LocalSearchOperator* ls_operator,
    //          const std::vector<SearchMonitor*>& monitors, RegularLimit* limit,
    //          absl::flat_hash_set<IntVar*>* touched);

    //      std::string GetName(const PropagationBaseObject* object);
    //      void SetName(const PropagationBaseObject* object, absl::string_view name);

    //      int GetNewIntVarIndex() { return num_int_vars_++; }

    //      bool IsADifference(IntExpr* expr, IntExpr** left, IntExpr** right);

    //      const std::string name_;
    //      const ConstraintSolverParameters parameters_;
    //      absl::flat_hash_map<const PropagationBaseObject*, std::string>
    //          propagation_object_names_;
    //      absl::flat_hash_map<const PropagationBaseObject*, IntegerCastInfo>
    //          cast_information_;
    //      absl::flat_hash_set<const Constraint*> cast_constraints_;
    //      const std::string empty_name_;
    //      std::unique_ptr<Queue> queue_;
    //      std::unique_ptr<Trail> trail_;
    //      std::vector<Constraint*> constraints_list_;
    //      std::vector<Constraint*> additional_constraints_list_;
    //      std::vector<int> additional_constraints_parent_list_;
    //      SolverState state_;
    //      int64_t branches_;
    //      int64_t fails_;
    //      int64_t decisions_;
    //      int64_t demon_runs_[kNumPriorities];
    //      int64_t neighbors_;
    //      int64_t filtered_neighbors_;
    //      int64_t accepted_neighbors_;
    //      std::string context_;
    //      OptimizationDirection optimization_direction_;
    //      std::unique_ptr<ClockTimer> timer_;
    //      std::vector<Search*> searches_;
    //      std::mt19937 random_;
    //      uint64_t fail_stamp_;
    //      std::unique_ptr<Decision> balancing_decision_;
    //      std::function<void()> fail_intercept_;
    //      DemonProfiler* const demon_profiler_;
    //      bool use_fast_local_search_;
    //      LocalSearchProfiler* const local_search_profiler_;
    //      std::unique_ptr<Assignment> local_search_state_;

    //      enum { MIN_CACHED_INT_CONST = -8, MAX_CACHED_INT_CONST = 8 };
    //      IntVar* cached_constants_[MAX_CACHED_INT_CONST + 1 - MIN_CACHED_INT_CONST];

    //      Constraint* true_constraint_;
    //      Constraint* false_constraint_;

    //      std::unique_ptr<Decision> fail_decision_;
    //      int constraint_index_;
    //      int additional_constraint_index_;
    //      int num_int_vars_;

    //      std::unique_ptr<ModelCache> model_cache_;
    //      std::unique_ptr<PropagationMonitor> propagation_monitor_;
    //      PropagationMonitor* print_trace_;
    //      std::unique_ptr<LocalSearchMonitor> local_search_monitor_;
    //      int anonymous_variable_index_;
    //      bool should_fail_;
};

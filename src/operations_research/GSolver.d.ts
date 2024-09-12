
/// Solver Class
///
/// A solver represents the main computation engine. It implements the entire
/// range of Constraint Programming protocols:
///   - Reversibility
///   - Propagation
///   - Search
///
/// Usually, Constraint Programming code consists of
///   - the creation of the Solver,
///   - the creation of the decision variables of the model,
///   - the creation of the constraints of the model and their addition to the
///     solver() through the AddConstraint() method,
///   - the creation of the main DecisionBuilder class,
///   - the launch of the solve() method with the decision builder.
///

import { Constraint } from "./GConstraint";

/// For the time being, Solver is neither MT_SAFE nor MT_HOT.
export class Solver
{
    //     public:
    //      /// Holds semantic information stating that the 'expression' has been
    //      /// cast into 'variable' using the Var() method, and that
    //      /// 'maintainer' is responsible for maintaining the equality between
    //      /// 'variable' and 'expression'.
    //      struct IntegerCastInfo {
    //        IntegerCastInfo()
    //            : variable(nullptr), expression(nullptr), maintainer(nullptr) {}
    //        IntegerCastInfo(IntVar* const v, IntExpr* const e, Constraint* const c)
    //            : variable(v), expression(e), maintainer(c) {}
    //        IntVar* variable;
    //        IntExpr* expression;
    //        Constraint* maintainer;
    //      };

    //      /// Number of priorities for demons.
    //      static constexpr int kNumPriorities = 3;

    //      /// This enum describes the strategy used to select the next branching
    //      /// variable at each node during the search.
    //      enum IntVarStrategy {
    //        /// The default behavior is CHOOSE_FIRST_UNBOUND.
    //        INT_VAR_DEFAULT,

    //        /// The simple selection is CHOOSE_FIRST_UNBOUND.
    //        INT_VAR_SIMPLE,

    //        /// Select the first unbound variable.
    //        /// Variables are considered in the order of the vector of IntVars used
    //        /// to create the selector.
    //        CHOOSE_FIRST_UNBOUND,

    //        /// Randomly select one of the remaining unbound variables.
    //        CHOOSE_RANDOM,

    //        /// Among unbound variables, select the variable with the smallest size,
    //        /// i.e., the smallest number of possible values.
    //        /// In case of a tie, the selected variables is the one with the lowest min
    //        /// value.
    //        /// In case of a tie, the first one is selected, first being defined by the
    //        /// order in the vector of IntVars used to create the selector.
    //        CHOOSE_MIN_SIZE_LOWEST_MIN,

    //        /// Among unbound variables, select the variable with the smallest size,
    //        /// i.e., the smallest number of possible values.
    //        /// In case of a tie, the selected variable is the one with the highest min
    //        /// value.
    //        /// In case of a tie, the first one is selected, first being defined by the
    //        /// order in the vector of IntVars used to create the selector.
    //        CHOOSE_MIN_SIZE_HIGHEST_MIN,

    //        /// Among unbound variables, select the variable with the smallest size,
    //        /// i.e., the smallest number of possible values.
    //        /// In case of a tie, the selected variables is the one with the lowest max
    //        /// value.
    //        /// In case of a tie, the first one is selected, first being defined by the
    //        /// order in the vector of IntVars used to create the selector.
    //        CHOOSE_MIN_SIZE_LOWEST_MAX,

    //        /// Among unbound variables, select the variable with the smallest size,
    //        /// i.e., the smallest number of possible values.
    //        /// In case of a tie, the selected variable is the one with the highest max
    //        /// value.
    //        /// In case of a tie, the first one is selected, first being defined by the
    //        /// order in the vector of IntVars used to create the selector.
    //        CHOOSE_MIN_SIZE_HIGHEST_MAX,

    //        /// Among unbound variables, select the variable with the smallest minimal
    //        /// value.
    //        /// In case of a tie, the first one is selected, "first" defined by the
    //        /// order in the vector of IntVars used to create the selector.
    //        CHOOSE_LOWEST_MIN,

    //        /// Among unbound variables, select the variable with the highest maximal
    //        /// value.
    //        /// In case of a tie, the first one is selected, first being defined by the
    //        /// order in the vector of IntVars used to create the selector.
    //        CHOOSE_HIGHEST_MAX,

    //        /// Among unbound variables, select the variable with the smallest size.
    //        /// In case of a tie, the first one is selected, first being defined by the
    //        /// order in the vector of IntVars used to create the selector.
    //        CHOOSE_MIN_SIZE,

    //        /// Among unbound variables, select the variable with the highest size.
    //        /// In case of a tie, the first one is selected, first being defined by the
    //        /// order in the vector of IntVars used to create the selector.
    //        CHOOSE_MAX_SIZE,

    //        /// Among unbound variables, select the variable with the largest
    //        /// gap between the first and the second values of the domain.
    //        CHOOSE_MAX_REGRET_ON_MIN,

    //        /// Selects the next unbound variable on a path, the path being defined by
    //        /// the variables: var[i] corresponds to the index of the next of i.
    //        CHOOSE_PATH,
    //      };
    //      // TODO(user): add HIGHEST_MIN and LOWEST_MAX.

    //      /// This enum describes the strategy used to select the next variable value to
    //      /// set.
    //      enum IntValueStrategy {
    //        /// The default behavior is ASSIGN_MIN_VALUE.
    //        INT_VALUE_DEFAULT,

    //        /// The simple selection is ASSIGN_MIN_VALUE.
    //        INT_VALUE_SIMPLE,

    //        /// Selects the min value of the selected variable.
    //        ASSIGN_MIN_VALUE,

    //        /// Selects the max value of the selected variable.
    //        ASSIGN_MAX_VALUE,

    //        /// Selects randomly one of the possible values of the selected variable.
    //        ASSIGN_RANDOM_VALUE,

    //        /// Selects the first possible value which is the closest to the center
    //        /// of the domain of the selected variable.
    //        /// The center is defined as (min + max) / 2.
    //        ASSIGN_CENTER_VALUE,

    //        /// Split the domain in two around the center, and choose the lower
    //        /// part first.
    //        SPLIT_LOWER_HALF,

    //        /// Split the domain in two around the center, and choose the lower
    //        /// part first.
    //        SPLIT_UPPER_HALF,
    //      };

    //      /// This enum is used by Solver::MakePhase to specify how to select variables
    //      /// and values during the search.
    //      /// In Solver::MakePhase(const std::vector<IntVar*>&, IntVarStrategy,
    //      /// IntValueStrategy), variables are selected first, and then the associated
    //      /// value.
    //      /// In Solver::MakePhase(const std::vector<IntVar*>& vars, IndexEvaluator2,
    //      /// EvaluatorStrategy), the selection is done scanning every pair
    //      /// <variable, possible value>. The next selected pair is then the best among
    //      /// all possibilities, i.e. the pair with the smallest evaluation.
    //      /// As this is costly, two options are offered: static or dynamic evaluation.
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

    //      /// Used for scheduling. Not yet implemented.
    //      enum SequenceStrategy {
    //        SEQUENCE_DEFAULT,
    //        SEQUENCE_SIMPLE,
    //        CHOOSE_MIN_SLACK_RANK_FORWARD,
    //        CHOOSE_RANDOM_RANK_FORWARD,
    //      };

    //      /// This enum describes the straregy used to select the next interval variable
    //      /// and its value to be fixed.
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

    //      /// This enum is used in Solver::MakeOperator to specify the neighborhood to
    //      /// create.
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

    //      /// This enum is used in Solver::MakeOperator associated with an evaluator
    //      /// to specify the neighborhood to create.
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

    //      /// This enum is used in Solver::MakeLocalSearchObjectiveFilter. It specifies
    //      /// the behavior of the objective filter to create. The goal is to define
    //      /// under which condition a move is accepted based on the current objective
    //      /// value.
    //      enum LocalSearchFilterBound {
    //        /// Move is accepted when the current objective value >= objective.Min.
    //        GE,
    //        /// Move is accepted when the current objective value <= objective.Max.
    //        LE,
    //        /// Move is accepted when the current objective value is in the interval
    //        /// objective.Min .. objective.Max.
    //        EQ
    //      };

    //      /// This enum represents the three possible priorities for a demon in the
    //      /// Solver queue.
    //      /// Note: this is for advanced users only.
    //      enum DemonPriority {
    //        /// DELAYED_PRIORITY is the lowest priority: Demons will be processed after
    //        /// VAR_PRIORITY and NORMAL_PRIORITY demons.
    //        DELAYED_PRIORITY = 0,

    //        /// VAR_PRIORITY is between DELAYED_PRIORITY and NORMAL_PRIORITY.
    //        VAR_PRIORITY = 1,

    //        /// NORMAL_PRIORITY is the highest priority: Demons will be processed first.
    //        NORMAL_PRIORITY = 2,
    //      };

    //      /// This enum is used in Solver::MakeIntervalVarRelation to specify the
    //      /// temporal relation between the two intervals t1 and t2.
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

    //      /// This enum is used in Solver::MakeIntervalVarRelation to specify the
    //      /// temporal relation between an interval t and an integer d.
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

    //      /// The Solver is responsible for creating the search tree. Thanks to the
    //      /// DecisionBuilder, it creates a new decision with two branches at each node:
    //      /// left and right.
    //      /// The DecisionModification enum is used to specify how the branch selector
    //      /// should behave.
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

    //      /// This enum is used internally in private methods Solver::PushState and
    //      /// Solver::PopState to tag states in the search tree.
    //      enum MarkerType { SENTINEL, SIMPLE_MARKER, CHOICE_POINT, REVERSIBLE_ACTION };

    //      /// This enum represents the state of the solver w.r.t. the search.
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

    //      /// Optimization directions.
    //      enum OptimizationDirection { NOT_SET, MAXIMIZATION, MINIMIZATION };

    //    #ifndef SWIG
    //      /// Search monitor events.
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

    //      /// Callback typedefs
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

    //      /// Solver API
    //      explicit Solver(const std::string& name);
    constructor(name: string);
    //      Solver(const std::string& name, const ConstraintSolverParameters& parameters);
    //      ~Solver();

    //      /// Stored Parameters.
    //      ConstraintSolverParameters parameters() const { return parameters_; }
    //      // Read-only.
    //      const ConstraintSolverParameters& const_parameters() const {
    //        return parameters_;
    //      }
    //      /// Create a ConstraintSolverParameters proto with all the default values.
    //      // TODO(user): Move to constraint_solver_parameters.h.
    //      static ConstraintSolverParameters DefaultSolverParameters();

    //      /// reversibility

    //      /// SaveValue() saves the value of the corresponding object. It must be
    //      /// called before modifying the object. The value will be restored upon
    //      /// backtrack.
    //      template <class T>
    //      void SaveValue(T* o) {
    //        InternalSaveValue(o);
    //      }

    //      /// Registers the given object as being reversible. By calling this method,
    //      /// the caller gives ownership of the object to the solver, which will
    //      /// delete it when there is a backtrack out of the current state.
    //      ///
    //      /// Returns the argument for convenience: this way, the caller may directly
    //      /// invoke a constructor in the argument, without having to store the pointer
    //      /// first.
    //      ///
    //      /// This function is only for users that define their own subclasses of
    //      /// BaseObject: for all subclasses predefined in the library, the
    //      /// corresponding factory methods (e.g., MakeIntVar(...),
    //      /// MakeAllDifferent(...) already take care of the registration.
    //      template <typename T>
    //      T* RevAlloc(T* object) {
    //        return reinterpret_cast<T*>(SafeRevAlloc(object));
    //      }

    //      /// Like RevAlloc() above, but for an array of objects: the array
    //      /// must have been allocated with the new[] operator. The entire array
    //      /// will be deleted when backtracking out of the current state.
    //      ///
    //      /// This method is valid for arrays of int, int64_t, uint64_t, bool,
    //      /// BaseObject*, IntVar*, IntExpr*, and Constraint*.
    //      template <typename T>
    //      T* RevAllocArray(T* object) {
    //        return reinterpret_cast<T*>(SafeRevAllocArray(object));
    //      }

    //      /// Adds the constraint 'c' to the model.
    //      ///
    //      /// After calling this method, and until there is a backtrack that undoes the
    //      /// addition, any assignment of variables to values must satisfy the given
    //      /// constraint in order to be considered feasible. There are two fairly
    //      /// different use cases:
    //      ///
    //      /// - the most common use case is modeling: the given constraint is really
    //      /// part of the problem that the user is trying to solve. In this use case,
    //      /// AddConstraint is called outside of search (i.e., with <tt>state() ==
    //      /// OUTSIDE_SEARCH</tt>). Most users should only use AddConstraint in this
    //      /// way. In this case, the constraint will belong to the model forever: it
    //      /// cannot not be removed by backtracking.
    //      ///
    //      /// - a rarer use case is that 'c' is not a real constraint of the model. It
    //      /// may be a constraint generated by a branching decision (a constraint whose
    //      /// goal is to restrict the search space), a symmetry breaking constraint (a
    //      /// constraint that does restrict the search space, but in a way that cannot
    //      /// have an impact on the quality of the solutions in the subtree), or an
    //      /// inferred constraint that, while having no semantic value to the model (it
    //      /// does not restrict the set of solutions), is worth having because we
    //      /// believe it may strengthen the propagation. In these cases, it happens
    //      /// that the constraint is added during the search (i.e., with state() ==
    //      /// IN_SEARCH or state() == IN_ROOT_NODE). When a constraint is
    //      /// added during a search, it applies only to the subtree of the search tree
    //      /// rooted at the current node, and will be automatically removed by
    //      /// backtracking.
    //      ///
    //      /// This method does not take ownership of the constraint. If the constraint
    //      /// has been created by any factory method (Solver::MakeXXX), it will
    //      /// automatically be deleted. However, power users who implement their own
    //      /// constraints should do: solver.AddConstraint(solver.RevAlloc(new
    //      /// MyConstraint(...));
    //      void AddConstraint(Constraint* const c);
    AddConstraint(c: Constraint): void;

    //      /// Adds 'constraint' to the solver and marks it as a cast constraint, that
    //      /// is, a constraint created calling Var() on an expression. This is used
    //      /// internally.
    //      void AddCastConstraint(CastConstraint* const constraint,
    //                             IntVar* const target_var, IntExpr* const expr);

    //      /// @{
    //      /// Solves the problem using the given DecisionBuilder and returns true if a
    //      /// solution was found and accepted.
    //      ///
    //      /// These methods are the ones most users should use to search for a solution.
    //      /// Note that the definition of 'solution' is subtle. A solution here is
    //      /// defined as a leaf of the search tree with respect to the given decision
    //      /// builder for which there is no failure. What this means is that, contrary
    //      /// to intuition, a solution may not have all variables of the model bound.
    //      /// It is the responsibility of the decision builder to keep returning
    //      /// decisions until all variables are indeed bound. The most extreme
    //      /// counterexample is calling Solve with a trivial decision builder whose
    //      /// Next() method always returns nullptr. In this case, Solve immediately
    //      /// returns 'true', since not assigning any variable to any value is a
    //      /// solution, unless the root node propagation discovers that the model is
    //      /// infeasible.
    //      ///
    //      /// This function must be called either from outside of search,
    //      /// or from within the Next() method of a decision builder.
    //      ///
    //      /// Solve will terminate whenever any of the following event arise:
    //      /// * A search monitor asks the solver to terminate the search by calling
    //      ///   solver()->FinishCurrentSearch().
    //      /// * A solution is found that is accepted by all search monitors, and none of
    //      ///   the search monitors decides to search for another one.
    //      ///
    //      /// Upon search termination, there will be a series of backtracks all the way
    //      /// to the top level. This means that a user cannot expect to inspect the
    //      /// solution by querying variables after a call to Solve(): all the
    //      /// information will be lost. In order to do something with the solution, the
    //      /// user must either:
    //      ///
    //      /// * Use a search monitor that can process such a leaf. See, in particular,
    //      ///     the SolutionCollector class.
    //      /// * Do not use Solve. Instead, use the more fine-grained approach using
    //      ///     methods NewSearch(...), NextSolution(), and EndSearch().
    //      ///
    //      /// @param db The decision builder that will generate the search tree.
    //      /// @param monitors A vector of search monitors that will be notified of
    //      /// various events during the search. In their reaction to these events, such
    //      /// monitors may influence the search.
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
    //      /// @}

    //      /// @{
    //      /// Decomposed search.
    //      /// The code for a top level search should look like
    //      /// solver->NewSearch(db);
    //      /// while (solver->NextSolution()) {
    //      ///   //.. use the current solution
    //      /// }
    //      /// solver()->EndSearch();

    //      void NewSearch(DecisionBuilder* const db,
    //                     const std::vector<SearchMonitor*>& monitors);
    //      void NewSearch(DecisionBuilder* const db);
    //      void NewSearch(DecisionBuilder* const db, SearchMonitor* const m1);
    //      void NewSearch(DecisionBuilder* const db, SearchMonitor* const m1,
    //                     SearchMonitor* const m2);
    //      void NewSearch(DecisionBuilder* const db, SearchMonitor* const m1,
    //                     SearchMonitor* const m2, SearchMonitor* const m3);
    //      void NewSearch(DecisionBuilder* const db, SearchMonitor* const m1,
    //                     SearchMonitor* const m2, SearchMonitor* const m3,
    //                     SearchMonitor* const m4);

    //      bool NextSolution();
    //      void RestartSearch();
    //      void EndSearch();
    //      /// @}

    //      /// SolveAndCommit using a decision builder and up to three
    //      ///   search monitors, usually one for the objective, one for the limits
    //      ///   and one to collect solutions.
    //      ///
    //      /// The difference between a SolveAndCommit() and a Solve() method
    //      /// call is the fact that SolveAndCommit will not backtrack all
    //      /// modifications at the end of the search. This method is only
    //      /// usable during the Next() method of a decision builder.
    //      bool SolveAndCommit(DecisionBuilder* const db,
    //                          const std::vector<SearchMonitor*>& monitors);
    //      bool SolveAndCommit(DecisionBuilder* const db);
    //      bool SolveAndCommit(DecisionBuilder* const db, SearchMonitor* const m1);
    //      bool SolveAndCommit(DecisionBuilder* const db, SearchMonitor* const m1,
    //                          SearchMonitor* const m2);
    //      bool SolveAndCommit(DecisionBuilder* const db, SearchMonitor* const m1,
    //                          SearchMonitor* const m2, SearchMonitor* const m3);

    //      /// Checks whether the given assignment satisfies all relevant constraints.
    //      bool CheckAssignment(Assignment* const solution);

    //      /// Checks whether adding this constraint will lead to an immediate
    //      /// failure. It will return false if the model is already inconsistent, or if
    //      /// adding the constraint makes it inconsistent.
    //      bool CheckConstraint(Constraint* const ct);

    //      /// State of the solver.
    //      SolverState state() const { return state_; }

    //      /// Abandon the current branch in the search tree. A backtrack will follow.
    //      void Fail();

    //    #if !defined(SWIG)
    //      /// When SaveValue() is not the best way to go, one can create a reversible
    //      /// action that will be called upon backtrack. The "fast" parameter
    //      /// indicates whether we need restore all values saved through SaveValue()
    //      /// before calling this method.
    //      void AddBacktrackAction(Action a, bool fast);
    //    #endif  /// !defined(SWIG)

    //      /// misc debug string.
    //      std::string DebugString() const;

    //      /// Current memory usage in bytes
    //      static int64_t MemoryUsage();

    //      /// The 'absolute time' as seen by the solver. Unless a user-provided clock
    //      /// was injected via SetClock() (eg. for unit tests), this is a real walltime,
    //      /// shifted so that it was 0 at construction. All so-called "walltime" limits
    //      /// are relative to this time.
    //      absl::Time Now() const;

    //      /// DEPRECATED: Use Now() instead.
    //      /// Time elapsed, in ms since the creation of the solver.
    //      int64_t wall_time() const;

    //      /// The number of branches explored since the creation of the solver.
    //      int64_t branches() const { return branches_; }

    //      /// The number of solutions found since the start of the search.
    //      int64_t solutions() const;

    //      /// The number of unchecked solutions found by local search.
    //      int64_t unchecked_solutions() const;

    //      /// The number of demons executed during search for a given priority.
    //      int64_t demon_runs(DemonPriority p) const { return demon_runs_[p]; }

    //      /// The number of failures encountered since the creation of the solver.
    //      int64_t failures() const { return fails_; }

    //      /// The number of neighbors created.
    //      int64_t neighbors() const { return neighbors_; }

    //      /// The number of filtered neighbors (neighbors accepted by filters).
    //      int64_t filtered_neighbors() const { return filtered_neighbors_; }

    //      /// The number of accepted neighbors.
    //      int64_t accepted_neighbors() const { return accepted_neighbors_; }

    //      /// The stamp indicates how many moves in the search tree we have performed.
    //      /// It is useful to detect if we need to update same lazy structures.
    //      uint64_t stamp() const;

    //      /// The fail_stamp() is incremented after each backtrack.
    //      uint64_t fail_stamp() const;

    //      /// Sets the current context of the search.
    //      void set_context(const std::string& context) { context_ = context; }

    //      /// Gets the current context of the search.
    //      const std::string& context() const { return context_; }

    //      /// The direction of optimization, getter and setter.
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

    //      /// MakeIntVar will create the best range based int var for the bounds given.
    //      IntVar* MakeIntVar(int64_t min, int64_t max, const std::string& name);
    MakeIntVar(min: number, max: number, name: string): IntVar;

    //      /// MakeIntVar will create a variable with the given sparse domain.
    //      IntVar* MakeIntVar(const std::vector<int64_t>& values,
    //                         const std::string& name);
    //      /// MakeIntVar will create a variable with the given sparse domain.
    //      IntVar* MakeIntVar(const std::vector<int>& values, const std::string& name);
    MakeIntVar(values: number[], name: string): IntVar;

    //      /// MakeIntVar will create the best range based int var for the bounds given.
    //      IntVar* MakeIntVar(int64_t min, int64_t max);
    MakeIntVar(min: number, max: number): IntVar;

    //      /// MakeIntVar will create a variable with the given sparse domain.
    //      IntVar* MakeIntVar(const std::vector<int64_t>& values);
    //      /// MakeIntVar will create a variable with the given sparse domain.
    //      IntVar* MakeIntVar(const std::vector<int>& values);
    MakeIntVar(values: number[]): IntVar;


    //      /// MakeBoolVar will create a variable with a {0, 1} domain.
    //      IntVar* MakeBoolVar(const std::string& name);

    //      /// MakeBoolVar will create a variable with a {0, 1} domain.
    //      IntVar* MakeBoolVar();

    //      /// IntConst will create a constant expression.
    //      IntVar* MakeIntConst(int64_t val, const std::string& name);

    //      /// IntConst will create a constant expression.
    //      IntVar* MakeIntConst(int64_t val);

    //      /// This method will append the vector vars with 'var_count' variables
    //      /// having bounds vmin and vmax and having name "name<i>" where <i> is
    //      /// the index of the variable.
    //      void MakeIntVarArray(int var_count, int64_t vmin, int64_t vmax,
    //                           const std::string& name, std::vector<IntVar*>* vars);
    //      /// This method will append the vector vars with 'var_count' variables
    //      /// having bounds vmin and vmax and having no names.
    //      void MakeIntVarArray(int var_count, int64_t vmin, int64_t vmax,
    //                           std::vector<IntVar*>* vars);
    //      /// Same but allocates an array and returns it.
    //      IntVar** MakeIntVarArray(int var_count, int64_t vmin, int64_t vmax,
    //                               const std::string& name);

    //      /// This method will append the vector vars with 'var_count' boolean
    //      /// variables having name "name<i>" where <i> is the index of the
    //      /// variable.
    //      void MakeBoolVarArray(int var_count, const std::string& name,
    //                            std::vector<IntVar*>* vars);
    //      /// This method will append the vector vars with 'var_count' boolean
    //      /// variables having no names.
    //      void MakeBoolVarArray(int var_count, std::vector<IntVar*>* vars);
    //      /// Same but allocates an array and returns it.
    //      IntVar** MakeBoolVarArray(int var_count, const std::string& name);

    //      // ----- Integer Expressions -----

    //      /// left + right.
    //      IntExpr* MakeSum(IntExpr* const left, IntExpr* const right);
    //      /// expr + value.
    //      IntExpr* MakeSum(IntExpr* const expr, int64_t value);
    //      /// sum of all vars.
    //      IntExpr* MakeSum(const std::vector<IntVar*>& vars);

    //      /// scalar product
    //      IntExpr* MakeScalProd(const std::vector<IntVar*>& vars,
    //                            const std::vector<int64_t>& coefs);
    //      /// scalar product
    //      IntExpr* MakeScalProd(const std::vector<IntVar*>& vars,
    //                            const std::vector<int>& coefs);

    //      /// left - right
    //      IntExpr* MakeDifference(IntExpr* const left, IntExpr* const right);
    //      /// value - expr
    //      IntExpr* MakeDifference(int64_t value, IntExpr* const expr);
    //      /// -expr
    //      IntExpr* MakeOpposite(IntExpr* const expr);

    //      /// left * right
    //      IntExpr* MakeProd(IntExpr* const left, IntExpr* const right);
    //      /// expr * value
    //      IntExpr* MakeProd(IntExpr* const expr, int64_t value);

    //      /// expr / value (integer division)
    //      IntExpr* MakeDiv(IntExpr* const expr, int64_t value);
    //      /// numerator / denominator (integer division). Terms need to be positive.
    //      IntExpr* MakeDiv(IntExpr* const numerator, IntExpr* const denominator);

    //      /// |expr|
    //      IntExpr* MakeAbs(IntExpr* const expr);
    //      /// expr * expr
    //      IntExpr* MakeSquare(IntExpr* const expr);
    //      /// expr ^ n (n > 0)
    //      IntExpr* MakePower(IntExpr* const expr, int64_t n);

    //      /// values[index]
    //      IntExpr* MakeElement(const std::vector<int64_t>& values, IntVar* const index);
    //      /// values[index]
    //      IntExpr* MakeElement(const std::vector<int>& values, IntVar* const index);

    //      /// Function-based element. The constraint takes ownership of the
    //      /// callback. The callback must be able to cope with any possible
    //      /// value in the domain of 'index' (potentially negative ones too).
    //      IntExpr* MakeElement(IndexEvaluator1 values, IntVar* const index);
    //      /// Function based element. The constraint takes ownership of the
    //      /// callback.  The callback must be monotonic. It must be able to
    //      /// cope with any possible value in the domain of 'index'
    //      /// (potentially negative ones too). Furtermore, monotonicity is not
    //      /// checked. Thus giving a non-monotonic function, or specifying an
    //      /// incorrect increasing parameter will result in undefined behavior.
    //      IntExpr* MakeMonotonicElement(IndexEvaluator1 values, bool increasing,
    //                                    IntVar* const index);
    //      /// 2D version of function-based element expression, values(expr1, expr2).
    //      IntExpr* MakeElement(IndexEvaluator2 values, IntVar* const index1,
    //                           IntVar* const index2);

    //      /// vars[expr]
    //      IntExpr* MakeElement(const std::vector<IntVar*>& vars, IntVar* const index);

    //    #if !defined(SWIG)
    //      /// vars(argument)
    //      IntExpr* MakeElement(Int64ToIntVar vars, int64_t range_start,
    //                           int64_t range_end, IntVar* argument);
    //    #endif  // SWIG

    //      /// Light versions of function-based elements, in constraint version only,
    //      /// well-suited for use within Local Search.
    //      /// These constraints are "checking" constraints, only triggered on WhenBound
    //      /// events. They provide very little (or no) domain filtering.

    //      /// Returns a light one-dimension function-based element constraint ensuring
    //      /// var == values(index).
    //      /// The constraint does not perform bound reduction of the resulting variable
    //      /// until the index variable is bound.
    //      /// If deep_serialize returns false, the model visitor will not extract all
    //      /// possible values from the values function.
    //      template <typename F>
    //      Constraint* MakeLightElement(F values, IntVar* const var, IntVar* const index,
    //                                   std::function<bool()> deep_serialize = nullptr) {
    //        return RevAlloc(new LightIntFunctionElementCt<F>(
    //            this, var, index, std::move(values), std::move(deep_serialize)));
    //      }

    //      /// Light two-dimension function-based element constraint ensuring
    //      /// var == values(index1, index2).
    //      /// The constraint does not perform bound reduction of the resulting variable
    //      /// until the index variables are bound.
    //      /// If deep_serialize returns false, the model visitor will not extract all
    //      /// possible values from the values function.
    //      template <typename F>
    //      Constraint* MakeLightElement(F values, IntVar* const var,
    //                                   IntVar* const index1, IntVar* const index2,
    //                                   std::function<bool()> deep_serialize = nullptr) {
    //        return RevAlloc(new LightIntIntFunctionElementCt<F>(
    //            this, var, index1, index2, std::move(values),
    //            std::move(deep_serialize)));
    //      }

    //      /// Returns the expression expr such that vars[expr] == value.
    //      /// It assumes that vars are all different.
    //      IntExpr* MakeIndexExpression(const std::vector<IntVar*>& vars, int64_t value);

    //      /// Special cases with arrays of size two.
    //      Constraint* MakeIfThenElseCt(IntVar* const condition,
    //                                   IntExpr* const then_expr,
    //                                   IntExpr* const else_expr,
    //                                   IntVar* const target_var);

    //      /// std::min(vars)
    //      IntExpr* MakeMin(const std::vector<IntVar*>& vars);
    //      /// std::min (left, right)
    //      IntExpr* MakeMin(IntExpr* const left, IntExpr* const right);
    //      /// std::min(expr, value)
    //      IntExpr* MakeMin(IntExpr* const expr, int64_t value);
    //      /// std::min(expr, value)
    //      IntExpr* MakeMin(IntExpr* const expr, int value);

    //      /// std::max(vars)
    //      IntExpr* MakeMax(const std::vector<IntVar*>& vars);
    //      /// std::max(left, right)
    //      IntExpr* MakeMax(IntExpr* const left, IntExpr* const right);
    //      /// std::max(expr, value)
    //      IntExpr* MakeMax(IntExpr* const expr, int64_t value);
    //      /// std::max(expr, value)
    //      IntExpr* MakeMax(IntExpr* const expr, int value);

    //      /// Convex piecewise function.
    //      IntExpr* MakeConvexPiecewiseExpr(IntExpr* expr, int64_t early_cost,
    //                                       int64_t early_date, int64_t late_date,
    //                                       int64_t late_cost);

    //      /// Semi continuous Expression (x <= 0 -> f(x) = 0; x > 0 -> f(x) = ax + b)
    //      /// a >= 0 and b >= 0
    //      IntExpr* MakeSemiContinuousExpr(IntExpr* const expr, int64_t fixed_charge,
    //                                      int64_t step);

    //      /// General piecewise-linear function expression, built from f(x) where f is
    //      /// piecewise-linear. The resulting expression is f(expr).
    //      // TODO(user): Investigate if we can merge all three piecewise linear
    //      /// expressions.
    //    #ifndef SWIG
    //      IntExpr* MakePiecewiseLinearExpr(IntExpr* expr,
    //                                       const PiecewiseLinearFunction& f);
    //    #endif

    //      /// Modulo expression x % mod (with the python convention for modulo).
    //      IntExpr* MakeModulo(IntExpr* const x, int64_t mod);

    //      /// Modulo expression x % mod (with the python convention for modulo).
    //      IntExpr* MakeModulo(IntExpr* const x, IntExpr* const mod);

    //      /// Conditional Expr condition ? expr : unperformed_value
    //      IntExpr* MakeConditionalExpression(IntVar* const condition,
    //                                         IntExpr* const expr,
    //                                         int64_t unperformed_value);

    //      /// This constraint always succeeds.
    //      Constraint* MakeTrueConstraint();
    //      /// This constraint always fails.
    //      Constraint* MakeFalseConstraint();
    //      Constraint* MakeFalseConstraint(const std::string& explanation);

    //      /// boolvar == (var == value)
    //      Constraint* MakeIsEqualCstCt(IntExpr* const var, int64_t value,
    //                                   IntVar* const boolvar);
    //      /// status var of (var == value)
    //      IntVar* MakeIsEqualCstVar(IntExpr* const var, int64_t value);
    //      /// b == (v1 == v2)
    //      Constraint* MakeIsEqualCt(IntExpr* const v1, IntExpr* v2, IntVar* const b);
    //      /// status var of (v1 == v2)
    //      IntVar* MakeIsEqualVar(IntExpr* const v1, IntExpr* v2);
    //      /// left == right
    //      Constraint* MakeEquality(IntExpr* const left, IntExpr* const right);
    //      /// expr == value
    //      Constraint* MakeEquality(IntExpr* const expr, int64_t value);
    //      /// expr == value
    //      Constraint* MakeEquality(IntExpr* const expr, int value);

    //      /// boolvar == (var != value)
    //      Constraint* MakeIsDifferentCstCt(IntExpr* const var, int64_t value,
    //                                       IntVar* const boolvar);
    //      /// status var of (var != value)
    //      IntVar* MakeIsDifferentCstVar(IntExpr* const var, int64_t value);
    //      /// status var of (v1 != v2)
    //      IntVar* MakeIsDifferentVar(IntExpr* const v1, IntExpr* const v2);
    //      /// b == (v1 != v2)
    //      Constraint* MakeIsDifferentCt(IntExpr* const v1, IntExpr* const v2,
    //                                    IntVar* const b);
    //      /// left != right
    //      Constraint* MakeNonEquality(IntExpr* const left, IntExpr* const right);
    //      /// expr != value
    //      Constraint* MakeNonEquality(IntExpr* const expr, int64_t value);
    //      /// expr != value
    //      Constraint* MakeNonEquality(IntExpr* const expr, int value);

    //      /// boolvar == (var <= value)
    //      Constraint* MakeIsLessOrEqualCstCt(IntExpr* const var, int64_t value,
    //                                         IntVar* const boolvar);
    //      /// status var of (var <= value)
    //      IntVar* MakeIsLessOrEqualCstVar(IntExpr* const var, int64_t value);
    //      /// status var of (left <= right)
    //      IntVar* MakeIsLessOrEqualVar(IntExpr* const left, IntExpr* const right);
    //      /// b == (left <= right)
    //      Constraint* MakeIsLessOrEqualCt(IntExpr* const left, IntExpr* const right,
    //                                      IntVar* const b);
    //      /// left <= right
    //      Constraint* MakeLessOrEqual(IntExpr* const left, IntExpr* const right);
    //      /// expr <= value
    //      Constraint* MakeLessOrEqual(IntExpr* const expr, int64_t value);
    //      /// expr <= value
    //      Constraint* MakeLessOrEqual(IntExpr* const expr, int value);

    //      /// boolvar == (var >= value)
    //      Constraint* MakeIsGreaterOrEqualCstCt(IntExpr* const var, int64_t value,
    //                                            IntVar* const boolvar);
    //      /// status var of (var >= value)
    //      IntVar* MakeIsGreaterOrEqualCstVar(IntExpr* const var, int64_t value);
    //      /// status var of (left >= right)
    //      IntVar* MakeIsGreaterOrEqualVar(IntExpr* const left, IntExpr* const right);
    //      /// b == (left >= right)
    //      Constraint* MakeIsGreaterOrEqualCt(IntExpr* const left, IntExpr* const right,
    //                                         IntVar* const b);
    //      /// left >= right
    //      Constraint* MakeGreaterOrEqual(IntExpr* const left, IntExpr* const right);
    //      /// expr >= value
    //      Constraint* MakeGreaterOrEqual(IntExpr* const expr, int64_t value);
    //      /// expr >= value
    //      Constraint* MakeGreaterOrEqual(IntExpr* const expr, int value);

    //      /// b == (v > c)
    //      Constraint* MakeIsGreaterCstCt(IntExpr* const v, int64_t c, IntVar* const b);
    //      /// status var of (var > value)
    //      IntVar* MakeIsGreaterCstVar(IntExpr* const var, int64_t value);
    //      /// status var of (left > right)
    //      IntVar* MakeIsGreaterVar(IntExpr* const left, IntExpr* const right);
    //      /// b == (left > right)
    //      Constraint* MakeIsGreaterCt(IntExpr* const left, IntExpr* const right,
    //                                  IntVar* const b);
    //      /// left > right
    //      Constraint* MakeGreater(IntExpr* const left, IntExpr* const right);
    //      /// expr > value
    //      Constraint* MakeGreater(IntExpr* const expr, int64_t value);
    //      /// expr > value
    //      Constraint* MakeGreater(IntExpr* const expr, int value);

    //      /// b == (v < c)
    //      Constraint* MakeIsLessCstCt(IntExpr* const v, int64_t c, IntVar* const b);
    //      /// status var of (var < value)
    //      IntVar* MakeIsLessCstVar(IntExpr* const var, int64_t value);
    //      /// status var of (left < right)
    //      IntVar* MakeIsLessVar(IntExpr* const left, IntExpr* const right);
    //      /// b == (left < right)
    //      Constraint* MakeIsLessCt(IntExpr* const left, IntExpr* const right,
    //                               IntVar* const b);
    //      /// left < right
    //      Constraint* MakeLess(IntExpr* const left, IntExpr* const right);
    //      /// expr < value
    //      Constraint* MakeLess(IntExpr* const expr, int64_t value);
    //      /// expr < value
    //      Constraint* MakeLess(IntExpr* const expr, int value);

    //      /// Variation on arrays.
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
    //      /// Creates the constraint abs(var) == abs_var.
    //      Constraint* MakeAbsEquality(IntVar* const var, IntVar* const abs_var);
    //      /// This constraint is a special case of the element constraint with
    //      /// an array of integer variables, where the variables are all
    //      /// different and the index variable is constrained such that
    //      /// vars[index] == target.
    //      Constraint* MakeIndexOfConstraint(const std::vector<IntVar*>& vars,
    //                                        IntVar* const index, int64_t target);

    //      /// This method is a specialized case of the MakeConstraintDemon
    //      /// method to call the InitiatePropagate of the constraint 'ct'.
    //      Demon* MakeConstraintInitialPropagateCallback(Constraint* const ct);
    //      /// This method is a specialized case of the MakeConstraintDemon
    //      /// method to call the InitiatePropagate of the constraint 'ct' with
    //      /// low priority.
    //      Demon* MakeDelayedConstraintInitialPropagateCallback(Constraint* const ct);
    //    #if !defined(SWIG)
    //      /// Creates a demon from a callback.
    //      Demon* MakeActionDemon(Action action);
    //    #endif  /// !defined(SWIG)
    //      /// Creates a demon from a closure.
    //      Demon* MakeClosureDemon(Closure closure);

    //      // ----- Between and related constraints -----

    //      /// (l <= expr <= u)
    //      Constraint* MakeBetweenCt(IntExpr* const expr, int64_t l, int64_t u);

    //      /// (expr < l || expr > u)
    //      /// This constraint is lazy as it will not make holes in the domain of
    //      /// variables. It will propagate only when expr->Min() >= l
    //      /// or expr->Max() <= u.
    //      Constraint* MakeNotBetweenCt(IntExpr* const expr, int64_t l, int64_t u);

    //      /// b == (l <= expr <= u)
    //      Constraint* MakeIsBetweenCt(IntExpr* const expr, int64_t l, int64_t u,
    //                                  IntVar* const b);
    //      IntVar* MakeIsBetweenVar(IntExpr* const v, int64_t l, int64_t u);

    //      // ----- Member and related constraints -----

    //      /// expr in set. Propagation is lazy, i.e. this constraint does not
    //      /// creates holes in the domain of the variable.
    //      Constraint* MakeMemberCt(IntExpr* const expr,
    //                               const std::vector<int64_t>& values);
    //      Constraint* MakeMemberCt(IntExpr* const expr, const std::vector<int>& values);

    //      /// expr not in set.
    //      Constraint* MakeNotMemberCt(IntExpr* const expr,
    //                                  const std::vector<int64_t>& values);
    //      Constraint* MakeNotMemberCt(IntExpr* const expr,
    //                                  const std::vector<int>& values);

    //      /// expr should not be in the list of forbidden intervals [start[i]..end[i]].
    //      Constraint* MakeNotMemberCt(IntExpr* const expr, std::vector<int64_t> starts,
    //                                  std::vector<int64_t> ends);
    //      /// expr should not be in the list of forbidden intervals [start[i]..end[i]].
    //      Constraint* MakeNotMemberCt(IntExpr* const expr, std::vector<int> starts,
    //                                  std::vector<int> ends);
    //    #if !defined(SWIG)
    //      /// expr should not be in the list of forbidden intervals.
    //      Constraint* MakeNotMemberCt(IntExpr* expr,
    //                                  SortedDisjointIntervalList intervals);
    //    #endif  // !defined(SWIG)

    //      /// boolvar == (expr in set)
    //      Constraint* MakeIsMemberCt(IntExpr* const expr,
    //                                 const std::vector<int64_t>& values,
    //                                 IntVar* const boolvar);
    //      Constraint* MakeIsMemberCt(IntExpr* const expr,
    //                                 const std::vector<int>& values,
    //                                 IntVar* const boolvar);
    //      IntVar* MakeIsMemberVar(IntExpr* const expr,
    //                              const std::vector<int64_t>& values);
    //      IntVar* MakeIsMemberVar(IntExpr* const expr, const std::vector<int>& values);

    //      /// |{i | vars[i] == value}| <= max_count
    //      Constraint* MakeAtMost(std::vector<IntVar*> vars, int64_t value,
    //                             int64_t max_count);
    //      /// |{i | vars[i] == value}| == max_count
    //      Constraint* MakeCount(const std::vector<IntVar*>& vars, int64_t value,
    //                            int64_t max_count);
    //      /// |{i | vars[i] == value}| == max_count
    //      Constraint* MakeCount(const std::vector<IntVar*>& vars, int64_t value,
    //                            IntVar* const max_count);

    //      /// Aggregated version of count:  |{i | v[i] == values[j]}| == cards[j]
    //      Constraint* MakeDistribute(const std::vector<IntVar*>& vars,
    //                                 const std::vector<int64_t>& values,
    //                                 const std::vector<IntVar*>& cards);
    //      /// Aggregated version of count:  |{i | v[i] == values[j]}| == cards[j]
    //      Constraint* MakeDistribute(const std::vector<IntVar*>& vars,
    //                                 const std::vector<int>& values,
    //                                 const std::vector<IntVar*>& cards);
    //      /// Aggregated version of count:  |{i | v[i] == j}| == cards[j]
    //      Constraint* MakeDistribute(const std::vector<IntVar*>& vars,
    //                                 const std::vector<IntVar*>& cards);
    //      /// Aggregated version of count with bounded cardinalities:
    //      /// forall j in 0 .. card_size - 1: card_min <= |{i | v[i] == j}| <= card_max
    //      Constraint* MakeDistribute(const std::vector<IntVar*>& vars, int64_t card_min,
    //                                 int64_t card_max, int64_t card_size);
    //      /// Aggregated version of count with bounded cardinalities:
    //      /// forall j in 0 .. card_size - 1:
    //      ///    card_min[j] <= |{i | v[i] == j}| <= card_max[j]
    //      Constraint* MakeDistribute(const std::vector<IntVar*>& vars,
    //                                 const std::vector<int64_t>& card_min,
    //                                 const std::vector<int64_t>& card_max);
    //      /// Aggregated version of count with bounded cardinalities:
    //      /// forall j in 0 .. card_size - 1:
    //      ///    card_min[j] <= |{i | v[i] == j}| <= card_max[j]
    //      Constraint* MakeDistribute(const std::vector<IntVar*>& vars,
    //                                 const std::vector<int>& card_min,
    //                                 const std::vector<int>& card_max);
    //      /// Aggregated version of count with bounded cardinalities:
    //      /// forall j in 0 .. card_size - 1:
    //      ///    card_min[j] <= |{i | v[i] == values[j]}| <= card_max[j]
    //      Constraint* MakeDistribute(const std::vector<IntVar*>& vars,
    //                                 const std::vector<int64_t>& values,
    //                                 const std::vector<int64_t>& card_min,
    //                                 const std::vector<int64_t>& card_max);
    //      /// Aggregated version of count with bounded cardinalities:
    //      /// forall j in 0 .. card_size - 1:
    //      ///    card_min[j] <= |{i | v[i] == values[j]}| <= card_max[j]
    //      Constraint* MakeDistribute(const std::vector<IntVar*>& vars,
    //                                 const std::vector<int>& values,
    //                                 const std::vector<int>& card_min,
    //                                 const std::vector<int>& card_max);

    //      /// Deviation constraint:
    //      /// sum_i |n * vars[i] - total_sum| <= deviation_var and
    //      /// sum_i vars[i] == total_sum
    //      /// n = #vars
    //      Constraint* MakeDeviation(const std::vector<IntVar*>& vars,
    //                                IntVar* const deviation_var, int64_t total_sum);

    //      /// All variables are pairwise different. This corresponds to the
    //      /// stronger version of the propagation algorithm.
    //      Constraint* MakeAllDifferent(const std::vector<IntVar*>& vars);
    MakeAllDifferent(vars: IntVar[]): Constraint;

    //      /// All variables are pairwise different.  If 'stronger_propagation'
    //      /// is true, stronger, and potentially slower propagation will
    //      /// occur. This API will be deprecated in the future.
    //      Constraint* MakeAllDifferent(const std::vector<IntVar*>& vars,
    //                                   bool stronger_propagation);
    MakeAllDifferent(vars: IntVar[], stronger_propagation: boolean): Constraint;

    //      /// All variables are pairwise different, unless they are assigned to
    //      /// the escape value.
    //      Constraint* MakeAllDifferentExcept(const std::vector<IntVar*>& vars,
    //                                         int64_t escape_value);
    //      // TODO(user): Do we need a version with an array of escape values.

    //      /// Creates a constraint binding the arrays of variables "vars" and
    //      /// "sorted_vars": sorted_vars[0] must be equal to the minimum of all
    //      /// variables in vars, and so on: the value of sorted_vars[i] must be
    //      /// equal to the i-th value of variables invars.
    //      ///
    //      /// This constraint propagates in both directions: from "vars" to
    //      /// "sorted_vars" and vice-versa.
    //      ///
    //      /// Behind the scenes, this constraint maintains that:
    //      ///   - sorted is always increasing.
    //      ///   - whatever the values of vars, there exists a permutation that
    //      ///     injects its values into the sorted variables.
    //      ///
    //      /// For more info, please have a look at:
    //      ///   https://mpi-inf.mpg.de/~mehlhorn/ftp/Mehlhorn-Thiel.pdf
    //      Constraint* MakeSortingConstraint(const std::vector<IntVar*>& vars,
    //                                        const std::vector<IntVar*>& sorted);
    //      // TODO(user): Add void MakeSortedArray(
    //      //                             const std::vector<IntVar*>& vars,
    //      //                             std::vector<IntVar*>* const sorted);

    //      /// Creates a constraint that enforces that left is lexicographically less
    //      /// than right.
    //      Constraint* MakeLexicalLess(const std::vector<IntVar*>& left,
    //                                  const std::vector<IntVar*>& right);

    //      /// Creates a constraint that enforces that left is lexicographically less
    //      /// than or equal to right.
    //      Constraint* MakeLexicalLessOrEqual(const std::vector<IntVar*>& left,
    //                                         const std::vector<IntVar*>& right);

    //      /// Creates a constraint that enforces that 'left' and 'right' both
    //      /// represent permutations of [0..left.size()-1], and that 'right' is
    //      /// the inverse permutation of 'left', i.e. for all i in
    //      /// [0..left.size()-1], right[left[i]] = i.
    //      Constraint* MakeInversePermutationConstraint(
    //          const std::vector<IntVar*>& left, const std::vector<IntVar*>& right);

    //      /// Creates a constraint that binds the index variable to the index of the
    //      /// first variable with the maximum value.
    //      Constraint* MakeIndexOfFirstMaxValueConstraint(
    //          IntVar* index, const std::vector<IntVar*>& vars);

    //      /// Creates a constraint that binds the index variable to the index of the
    //      /// first variable with the minimum value.
    //      Constraint* MakeIndexOfFirstMinValueConstraint(
    //          IntVar* index, const std::vector<IntVar*>& vars);

    //      /// Creates a constraint that states that all variables in the first
    //      /// vector are different from all variables in the second
    //      /// group. Thus the set of values in the first vector does not
    //      /// intersect with the set of values in the second vector.
    //      Constraint* MakeNullIntersect(const std::vector<IntVar*>& first_vars,
    //                                    const std::vector<IntVar*>& second_vars);

    //      /// Creates a constraint that states that all variables in the first
    //      /// vector are different from all variables from the second group,
    //      /// unless they are assigned to the escape value. Thus the set of
    //      /// values in the first vector minus the escape value does not
    //      /// intersect with the set of values in the second vector.
    //      Constraint* MakeNullIntersectExcept(const std::vector<IntVar*>& first_vars,
    //                                          const std::vector<IntVar*>& second_vars,
    //                                          int64_t escape_value);

    //      // TODO(user): Implement MakeAllNullIntersect taking an array of
    //      // variable vectors.

    //      /// Prevent cycles. The "nexts" variables represent the next in the chain.
    //      /// "active" variables indicate if the corresponding next variable is active;
    //      /// this could be useful to model unperformed nodes in a routing problem.
    //      /// A callback can be added to specify sink values (by default sink values
    //      /// are values >= vars.size()). Ownership of the callback is passed to the
    //      /// constraint.
    //      /// If assume_paths is either not specified or true, the constraint assumes
    //      /// the "nexts" variables represent paths (and performs a faster propagation);
    //      /// otherwise the constraint assumes they represent a forest.
    //      Constraint* MakeNoCycle(const std::vector<IntVar*>& nexts,
    //                              const std::vector<IntVar*>& active,
    //                              IndexFilter1 sink_handler = nullptr);
    //      Constraint* MakeNoCycle(const std::vector<IntVar*>& nexts,
    //                              const std::vector<IntVar*>& active,
    //                              IndexFilter1 sink_handler, bool assume_paths);

    //      /// Force the "nexts" variable to create a complete Hamiltonian path.
    //      Constraint* MakeCircuit(const std::vector<IntVar*>& nexts);

    //      /// Force the "nexts" variable to create a complete Hamiltonian path
    //      /// for those that do not loop upon themselves.
    //      Constraint* MakeSubCircuit(const std::vector<IntVar*>& nexts);

    //      /// Creates a constraint which accumulates values along a path such that:
    //      /// cumuls[next[i]] = cumuls[i] + transits[i].
    //      /// Active variables indicate if the corresponding next variable is active;
    //      /// this could be useful to model unperformed nodes in a routing problem.
    //      Constraint* MakePathCumul(const std::vector<IntVar*>& nexts,
    //                                const std::vector<IntVar*>& active,
    //                                const std::vector<IntVar*>& cumuls,
    //                                const std::vector<IntVar*>& transits);
    //      /// Delayed version of the same constraint: propagation on the nexts variables
    //      /// is delayed until all constraints have propagated.
    //      // TODO(user): Merge with other path-cumuls constraints.
    //      Constraint* MakeDelayedPathCumul(const std::vector<IntVar*>& nexts,
    //                                       const std::vector<IntVar*>& active,
    //                                       const std::vector<IntVar*>& cumuls,
    //                                       const std::vector<IntVar*>& transits);
    //      /// Creates a constraint which accumulates values along a path such that:
    //      /// cumuls[next[i]] = cumuls[i] + transit_evaluator(i, next[i]).
    //      /// Active variables indicate if the corresponding next variable is active;
    //      /// this could be useful to model unperformed nodes in a routing problem.
    //      /// Ownership of transit_evaluator is taken and it must be a repeatable
    //      /// callback.
    //      Constraint* MakePathCumul(const std::vector<IntVar*>& nexts,
    //                                const std::vector<IntVar*>& active,
    //                                const std::vector<IntVar*>& cumuls,
    //                                IndexEvaluator2 transit_evaluator);

    //      /// Creates a constraint which accumulates values along a path such that:
    //      /// cumuls[next[i]] = cumuls[i] + transit_evaluator(i, next[i]) + slacks[i].
    //      /// Active variables indicate if the corresponding next variable is active;
    //      /// this could be useful to model unperformed nodes in a routing problem.
    //      /// Ownership of transit_evaluator is taken and it must be a repeatable
    //      /// callback.
    //      Constraint* MakePathCumul(const std::vector<IntVar*>& nexts,
    //                                const std::vector<IntVar*>& active,
    //                                const std::vector<IntVar*>& cumuls,
    //                                const std::vector<IntVar*>& slacks,
    //                                IndexEvaluator2 transit_evaluator);
    //      /// Constraint enforcing that status[i] is true iff there's a path defined on
    //      /// next variables from sources[i] to sinks[i].
    //      // TODO(user): Only does checking on WhenBound events on next variables.
    //      /// Check whether more propagation is needed.
    //      Constraint* MakePathConnected(std::vector<IntVar*> nexts,
    //                                    std::vector<int64_t> sources,
    //                                    std::vector<int64_t> sinks,
    //                                    std::vector<IntVar*> status);
    //    #ifndef SWIG
    //      /// Constraint enforcing, for each pair (i,j) in precedences, i to be before j
    //      /// in paths defined by next variables.
    //      // TODO(user): This constraint does not make holes in variable domains;
    //      /// the implementation can easily be modified to do that; evaluate the impact
    //      /// on models solved with local search.
    //      Constraint* MakePathPrecedenceConstraint(
    //          std::vector<IntVar*> nexts,
    //          const std::vector<std::pair<int, int>>& precedences);
    //      /// Same as MakePathPrecedenceConstraint but ensures precedence pairs on some
    //      /// paths follow a LIFO or FIFO order.
    //      /// LIFO order: given 2 pairs (a,b) and (c,d), if a is before c on the path
    //      /// then d must be before b or b must be before c.
    //      /// FIFO order: given 2 pairs (a,b) and (c,d), if a is before c on the path
    //      /// then b must be before d.
    //      /// LIFO (resp. FIFO) orders are enforced only on paths starting by indices in
    //      /// lifo_path_starts (resp. fifo_path_start).
    //      Constraint* MakePathPrecedenceConstraint(
    //          std::vector<IntVar*> nexts,
    //          const std::vector<std::pair<int, int>>& precedences,
    //          const std::vector<int>& lifo_path_starts,
    //          const std::vector<int>& fifo_path_starts);
    //      /// Same as MakePathPrecedenceConstraint but will force i to be before j if
    //      /// the sum of transits on the path from i to j is strictly positive.
    //      Constraint* MakePathTransitPrecedenceConstraint(
    //          std::vector<IntVar*> nexts, std::vector<IntVar*> transits,
    //          const std::vector<std::pair<int, int>>& precedences);
    //    #endif  // !SWIG
    //      /// This constraint maps the domain of 'var' onto the array of
    //      /// variables 'actives'. That is
    //      /// for all i in [0 .. size - 1]: actives[i] == 1 <=> var->Contains(i);
    //      Constraint* MakeMapDomain(IntVar* const var,
    //                                const std::vector<IntVar*>& actives);

    //      /// This method creates a constraint where the graph of the relation
    //      /// between the variables is given in extension. There are 'arity'
    //      /// variables involved in the relation and the graph is given by a
    //      /// integer tuple set.
    //      Constraint* MakeAllowedAssignments(const std::vector<IntVar*>& vars,
    //                                         const IntTupleSet& tuples);

    //      /// This constraint create a finite automaton that will check the
    //      /// sequence of variables vars. It uses a transition table called
    //      /// 'transition_table'. Each transition is a triple
    //      ///    (current_state, variable_value, new_state).
    //      /// The initial state is given, and the set of accepted states is decribed
    //      /// by 'final_states'. These states are hidden inside the constraint.
    //      /// Only the transitions (i.e. the variables) are visible.
    //      Constraint* MakeTransitionConstraint(
    //          const std::vector<IntVar*>& vars, const IntTupleSet& transition_table,
    //          int64_t initial_state, const std::vector<int64_t>& final_states);

    //      /// This constraint create a finite automaton that will check the
    //      /// sequence of variables vars. It uses a transition table called
    //      /// 'transition_table'. Each transition is a triple
    //      ///    (current_state, variable_value, new_state).
    //      /// The initial state is given, and the set of accepted states is decribed
    //      /// by 'final_states'. These states are hidden inside the constraint.
    //      /// Only the transitions (i.e. the variables) are visible.
    //      Constraint* MakeTransitionConstraint(const std::vector<IntVar*>& vars,
    //                                           const IntTupleSet& transition_table,
    //                                           int64_t initial_state,
    //                                           const std::vector<int>& final_states);

    //    #if defined(SWIGPYTHON)
    //      /// Compatibility layer for Python API.
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

    //      /// This constraint states that all the boxes must not overlap.
    //      /// The coordinates of box i are:
    //      ///   (x_vars[i], y_vars[i]),
    //      ///   (x_vars[i], y_vars[i] + y_size[i]),
    //      ///   (x_vars[i] + x_size[i], y_vars[i]),
    //      ///   (x_vars[i] + x_size[i], y_vars[i] + y_size[i]).
    //      /// The sizes must be non-negative. Boxes with a zero dimension can be
    //      /// pushed like any box.
    //      Constraint* MakeNonOverlappingBoxesConstraint(
    //          const std::vector<IntVar*>& x_vars, const std::vector<IntVar*>& y_vars,
    //          const std::vector<IntVar*>& x_size, const std::vector<IntVar*>& y_size);
    //      Constraint* MakeNonOverlappingBoxesConstraint(
    //          const std::vector<IntVar*>& x_vars, const std::vector<IntVar*>& y_vars,
    //          const std::vector<int64_t>& x_size, const std::vector<int64_t>& y_size);
    //      Constraint* MakeNonOverlappingBoxesConstraint(
    //          const std::vector<IntVar*>& x_vars, const std::vector<IntVar*>& y_vars,
    //          const std::vector<int>& x_size, const std::vector<int>& y_size);

    //      /// This constraint states that all the boxes must not overlap.
    //      /// The coordinates of box i are:
    //      ///   (x_vars[i], y_vars[i]),
    //      ///   (x_vars[i], y_vars[i] + y_size[i]),
    //      ///   (x_vars[i] + x_size[i], y_vars[i]),
    //      ///   (x_vars[i] + x_size[i], y_vars[i] + y_size[i]).
    //      /// The sizes must be positive.
    //      /// Boxes with a zero dimension can be placed anywhere.
    //      Constraint* MakeNonOverlappingNonStrictBoxesConstraint(
    //          const std::vector<IntVar*>& x_vars, const std::vector<IntVar*>& y_vars,
    //          const std::vector<IntVar*>& x_size, const std::vector<IntVar*>& y_size);
    //      Constraint* MakeNonOverlappingNonStrictBoxesConstraint(
    //          const std::vector<IntVar*>& x_vars, const std::vector<IntVar*>& y_vars,
    //          const std::vector<int64_t>& x_size, const std::vector<int64_t>& y_size);
    //      Constraint* MakeNonOverlappingNonStrictBoxesConstraint(
    //          const std::vector<IntVar*>& x_vars, const std::vector<IntVar*>& y_vars,
    //          const std::vector<int>& x_size, const std::vector<int>& y_size);

    //      /// This constraint packs all variables onto 'number_of_bins'
    //      /// variables.  For any given variable, a value of 'number_of_bins'
    //      /// indicates that the variable is not assigned to any bin.
    //      /// Dimensions, i.e., cumulative constraints on this packing, can be
    //      /// added directly from the pack class.
    //      Pack* MakePack(const std::vector<IntVar*>& vars, int number_of_bins);

    //      /// Creates an interval var with a fixed duration. The duration must
    //      /// be greater than 0. If optional is true, then the interval can be
    //      /// performed or unperformed. If optional is false, then the interval
    //      /// is always performed.
    //      IntervalVar* MakeFixedDurationIntervalVar(int64_t start_min,
    //                                                int64_t start_max, int64_t duration,
    //                                                bool optional,
    //                                                const std::string& name);

    //      /// This method fills the vector with 'count' interval variables built with
    //      /// the corresponding parameters.
    //      void MakeFixedDurationIntervalVarArray(
    //          int count, int64_t start_min, int64_t start_max, int64_t duration,
    //          bool optional, const std::string& name,
    //          std::vector<IntervalVar*>* const array);

    //      /// Creates a performed interval var with a fixed duration. The duration must
    //      /// be greater than 0.
    //      IntervalVar* MakeFixedDurationIntervalVar(IntVar* const start_variable,
    //                                                int64_t duration,
    //                                                const std::string& name);

    //      /// Creates an interval var with a fixed duration, and performed_variable.
    //      /// The duration must be greater than 0.
    //      IntervalVar* MakeFixedDurationIntervalVar(IntVar* const start_variable,
    //                                                int64_t duration,
    //                                                IntVar* const performed_variable,
    //                                                const std::string& name);

    //      /// This method fills the vector with 'count' interval var built with
    //      /// the corresponding start variables.
    //      void MakeFixedDurationIntervalVarArray(
    //          const std::vector<IntVar*>& start_variables, int64_t duration,
    //          const std::string& name, std::vector<IntervalVar*>* const array);

    //      /// This method fills the vector with interval variables built with
    //      /// the corresponding start variables.
    //      void MakeFixedDurationIntervalVarArray(
    //          const std::vector<IntVar*>& start_variables,
    //          const std::vector<int64_t>& durations, const std::string& name,
    //          std::vector<IntervalVar*>* const array);
    //      /// This method fills the vector with interval variables built with
    //      /// the corresponding start variables.
    //      void MakeFixedDurationIntervalVarArray(
    //          const std::vector<IntVar*>& start_variables,
    //          const std::vector<int>& durations, const std::string& name,
    //          std::vector<IntervalVar*>* const array);

    //      /// This method fills the vector with interval variables built with
    //      /// the corresponding start and performed variables.
    //      void MakeFixedDurationIntervalVarArray(
    //          const std::vector<IntVar*>& start_variables,
    //          const std::vector<int64_t>& durations,
    //          const std::vector<IntVar*>& performed_variables, const std::string& name,
    //          std::vector<IntervalVar*>* const array);

    //      /// This method fills the vector with interval variables built with
    //      /// the corresponding start and performed variables.
    //      void MakeFixedDurationIntervalVarArray(
    //          const std::vector<IntVar*>& start_variables,
    //          const std::vector<int>& durations,
    //          const std::vector<IntVar*>& performed_variables, const std::string& name,
    //          std::vector<IntervalVar*>* const array);

    //      /// Creates a fixed and performed interval.
    //      IntervalVar* MakeFixedInterval(int64_t start, int64_t duration,
    //                                     const std::string& name);

    //      /// Creates an interval var by specifying the bounds on start,
    //      /// duration, and end.
    //      IntervalVar* MakeIntervalVar(int64_t start_min, int64_t start_max,
    //                                   int64_t duration_min, int64_t duration_max,
    //                                   int64_t end_min, int64_t end_max, bool optional,
    //                                   const std::string& name);

    //      /// This method fills the vector with 'count' interval var built with
    //      /// the corresponding parameters.
    //      void MakeIntervalVarArray(int count, int64_t start_min, int64_t start_max,
    //                                int64_t duration_min, int64_t duration_max,
    //                                int64_t end_min, int64_t end_max, bool optional,
    //                                const std::string& name,
    //                                std::vector<IntervalVar*>* const array);

    //      /// Creates an interval var that is the mirror image of the given one, that
    //      /// is, the interval var obtained by reversing the axis.
    //      IntervalVar* MakeMirrorInterval(IntervalVar* const interval_var);

    //      /// Creates an interval var with a fixed duration whose start is
    //      /// synchronized with the start of another interval, with a given
    //      /// offset. The performed status is also in sync with the performed
    //      /// status of the given interval variable.
    //      IntervalVar* MakeFixedDurationStartSyncedOnStartIntervalVar(
    //          IntervalVar* const interval_var, int64_t duration, int64_t offset);

    //      /// Creates an interval var with a fixed duration whose start is
    //      /// synchronized with the end of another interval, with a given
    //      /// offset. The performed status is also in sync with the performed
    //      /// status of the given interval variable.
    //      IntervalVar* MakeFixedDurationStartSyncedOnEndIntervalVar(
    //          IntervalVar* const interval_var, int64_t duration, int64_t offset);

    //      /// Creates an interval var with a fixed duration whose end is
    //      /// synchronized with the start of another interval, with a given
    //      /// offset. The performed status is also in sync with the performed
    //      /// status of the given interval variable.
    //      IntervalVar* MakeFixedDurationEndSyncedOnStartIntervalVar(
    //          IntervalVar* const interval_var, int64_t duration, int64_t offset);

    //      /// Creates an interval var with a fixed duration whose end is
    //      /// synchronized with the end of another interval, with a given
    //      /// offset. The performed status is also in sync with the performed
    //      /// status of the given interval variable.
    //      IntervalVar* MakeFixedDurationEndSyncedOnEndIntervalVar(
    //          IntervalVar* const interval_var, int64_t duration, int64_t offset);

    //      /// Creates and returns an interval variable that wraps around the given one,
    //      /// relaxing the min start and end. Relaxing means making unbounded when
    //      /// optional. If the variable is non-optional, this method returns
    //      /// interval_var.
    //      ///
    //      /// More precisely, such an interval variable behaves as follows:
    //      /// * When the underlying must be performed, the returned interval variable
    //      ///     behaves exactly as the underlying;
    //      /// * When the underlying may or may not be performed, the returned interval
    //      ///     variable behaves like the underlying, except that it is unbounded on
    //      ///     the min side;
    //      /// * When the underlying cannot be performed, the returned interval variable
    //      ///     is of duration 0 and must be performed in an interval unbounded on
    //      ///     both sides.
    //      ///
    //      /// This is very useful to implement propagators that may only modify
    //      /// the start max or end max.
    //      IntervalVar* MakeIntervalRelaxedMin(IntervalVar* const interval_var);

    //      /// Creates and returns an interval variable that wraps around the given one,
    //      /// relaxing the max start and end. Relaxing means making unbounded when
    //      /// optional. If the variable is non optional, this method returns
    //      /// interval_var.
    //      ///
    //      /// More precisely, such an interval variable behaves as follows:
    //      /// * When the underlying must be performed, the returned interval variable
    //      ///     behaves exactly as the underlying;
    //      /// * When the underlying may or may not be performed, the returned interval
    //      ///     variable behaves like the underlying, except that it is unbounded on
    //      ///     the max side;
    //      /// * When the underlying cannot be performed, the returned interval variable
    //      ///     is of duration 0 and must be performed in an interval unbounded on
    //      ///     both sides.
    //      ///
    //      /// This is very useful for implementing propagators that may only modify
    //      /// the start min or end min.
    //      IntervalVar* MakeIntervalRelaxedMax(IntervalVar* const interval_var);

    //      /// This method creates a relation between an interval var and a
    //      /// date.
    //      Constraint* MakeIntervalVarRelation(IntervalVar* const t,
    //                                          UnaryIntervalRelation r, int64_t d);

    //      /// This method creates a relation between two interval vars.
    //      Constraint* MakeIntervalVarRelation(IntervalVar* const t1,
    //                                          BinaryIntervalRelation r,
    //                                          IntervalVar* const t2);

    //      /// This method creates a relation between two interval vars.
    //      /// The given delay is added to the second interval.
    //      /// i.e.: t1 STARTS_AFTER_END of t2 with a delay of 2
    //      /// means t1 will start at least two units of time after the end of t2.
    //      Constraint* MakeIntervalVarRelationWithDelay(IntervalVar* const t1,
    //                                                   BinaryIntervalRelation r,
    //                                                   IntervalVar* const t2,
    //                                                   int64_t delay);

    //      /// This constraint implements a temporal disjunction between two
    //      /// interval vars t1 and t2. 'alt' indicates which alternative was
    //      /// chosen (alt == 0 is equivalent to t1 before t2).
    //      Constraint* MakeTemporalDisjunction(IntervalVar* const t1,
    //                                          IntervalVar* const t2, IntVar* const alt);

    //      /// This constraint implements a temporal disjunction between two
    //      /// interval vars.
    //      Constraint* MakeTemporalDisjunction(IntervalVar* const t1,
    //                                          IntervalVar* const t2);

    //      /// This constraint forces all interval vars into an non-overlapping
    //      /// sequence. Intervals with zero duration can be scheduled anywhere.
    //      DisjunctiveConstraint* MakeDisjunctiveConstraint(
    //          const std::vector<IntervalVar*>& intervals, const std::string& name);

    //      /// This constraint forces all interval vars into an non-overlapping
    //      /// sequence. Intervals with zero durations cannot overlap with over
    //      /// intervals.
    //      DisjunctiveConstraint* MakeStrictDisjunctiveConstraint(
    //          const std::vector<IntervalVar*>& intervals, const std::string& name);

    //      /// This constraint forces that, for any integer t, the sum of the demands
    //      /// corresponding to an interval containing t does not exceed the given
    //      /// capacity.
    //      ///
    //      /// Intervals and demands should be vectors of equal size.
    //      ///
    //      /// Demands should only contain non-negative values. Zero values are
    //      /// supported, and the corresponding intervals are filtered out, as they
    //      /// neither impact nor are impacted by this constraint.
    //      Constraint* MakeCumulative(const std::vector<IntervalVar*>& intervals,
    //                                 const std::vector<int64_t>& demands,
    //                                 int64_t capacity, const std::string& name);

    //      /// This constraint forces that, for any integer t, the sum of the demands
    //      /// corresponding to an interval containing t does not exceed the given
    //      /// capacity.
    //      ///
    //      /// Intervals and demands should be vectors of equal size.
    //      ///
    //      /// Demands should only contain non-negative values. Zero values are
    //      /// supported, and the corresponding intervals are filtered out, as they
    //      /// neither impact nor are impacted by this constraint.
    //      Constraint* MakeCumulative(const std::vector<IntervalVar*>& intervals,
    //                                 const std::vector<int>& demands, int64_t capacity,
    //                                 const std::string& name);

    //      /// This constraint forces that, for any integer t, the sum of the demands
    //      /// corresponding to an interval containing t does not exceed the given
    //      /// capacity.
    //      ///
    //      /// Intervals and demands should be vectors of equal size.
    //      ///
    //      /// Demands should only contain non-negative values. Zero values are
    //      /// supported, and the corresponding intervals are filtered out, as they
    //      /// neither impact nor are impacted by this constraint.
    //      Constraint* MakeCumulative(const std::vector<IntervalVar*>& intervals,
    //                                 const std::vector<int64_t>& demands,
    //                                 IntVar* const capacity, const std::string& name);

    //      /// This constraint enforces that, for any integer t, the sum of the demands
    //      /// corresponding to an interval containing t does not exceed the given
    //      /// capacity.
    //      ///
    //      /// Intervals and demands should be vectors of equal size.
    //      ///
    //      /// Demands should only contain non-negative values. Zero values are
    //      /// supported, and the corresponding intervals are filtered out, as they
    //      /// neither impact nor are impacted by this constraint.
    //      Constraint* MakeCumulative(const std::vector<IntervalVar*>& intervals,
    //                                 const std::vector<int>& demands,
    //                                 IntVar* const capacity, const std::string& name);

    //      /// This constraint enforces that, for any integer t, the sum of demands
    //      /// corresponding to an interval containing t does not exceed the given
    //      /// capacity.
    //      ///
    //      /// Intervals and demands should be vectors of equal size.
    //      ///
    //      /// Demands should be positive.
    //      Constraint* MakeCumulative(const std::vector<IntervalVar*>& intervals,
    //                                 const std::vector<IntVar*>& demands,
    //                                 int64_t capacity, const std::string& name);

    //      /// This constraint enforces that, for any integer t, the sum of demands
    //      /// corresponding to an interval containing t does not exceed the given
    //      /// capacity.
    //      ///
    //      /// Intervals and demands should be vectors of equal size.
    //      ///
    //      /// Demands should be positive.
    //      Constraint* MakeCumulative(const std::vector<IntervalVar*>& intervals,
    //                                 const std::vector<IntVar*>& demands,
    //                                 IntVar* const capacity, const std::string& name);

    //      /// This constraint states that the target_var is the convex hull of
    //      /// the intervals. If none of the interval variables is performed,
    //      /// then the target var is unperformed too. Also, if the target
    //      /// variable is unperformed, then all the intervals variables are
    //      /// unperformed too.
    //      Constraint* MakeCover(const std::vector<IntervalVar*>& vars,
    //                            IntervalVar* const target_var);

    //      /// This constraints states that the two interval variables are equal.
    //      Constraint* MakeEquality(IntervalVar* const var1, IntervalVar* const var2);

    //      /// This method creates an empty assignment.
    //      Assignment* MakeAssignment();

    //      /// This method creates an assignment which is a copy of 'a'.
    //      Assignment* MakeAssignment(const Assignment* const a);

    //      /// Collect the first solution of the search.
    //      SolutionCollector* MakeFirstSolutionCollector(
    //          const Assignment* const assignment);
    //      /// Collect the first solution of the search. The variables will need to
    //      /// be added later.
    //      SolutionCollector* MakeFirstSolutionCollector();

    //      /// Collect the last solution of the search.
    //      SolutionCollector* MakeLastSolutionCollector(
    //          const Assignment* const assignment);
    //      /// Collect the last solution of the search. The variables will need to
    //      /// be added later.
    //      SolutionCollector* MakeLastSolutionCollector();

    //      /// Collect the solution corresponding to the optimal value of the objective
    //      /// of 'assignment'; if 'assignment' does not have an objective no solution is
    //      /// collected. This collector only collects one solution corresponding to the
    //      /// best objective value (the first one found).
    //      SolutionCollector* MakeBestValueSolutionCollector(
    //          const Assignment* const assignment, bool maximize);
    //      /// Collect the solution corresponding to the optimal value of the
    //      /// objective of 'assignment'; if 'assignment' does not have an objective no
    //      /// solution is collected. This collector only collects one solution
    //      /// corresponding to the best objective value (the first one
    //      /// found). The variables will need to be added later.
    //      SolutionCollector* MakeBestValueSolutionCollector(bool maximize);

    //      /// Same as MakeBestValueSolutionCollector but collects the best
    //      /// solution_count solutions. Collected solutions are sorted in increasing
    //      /// optimality order (the best solution is the last one).
    //      SolutionCollector* MakeNBestValueSolutionCollector(
    //          const Assignment* const assignment, int solution_count, bool maximize);
    //      SolutionCollector* MakeNBestValueSolutionCollector(int solution_count,
    //                                                         bool maximize);

    //      /// Collect all solutions of the search.
    //      SolutionCollector* MakeAllSolutionCollector(
    //          const Assignment* const assignment);
    //      /// Collect all solutions of the search. The variables will need to
    //      /// be added later.
    //      SolutionCollector* MakeAllSolutionCollector();

    //      /// Creates a minimization objective.
    //      OptimizeVar* MakeMinimize(IntVar* const v, int64_t step);

    //      /// Creates a maximization objective.
    //      OptimizeVar* MakeMaximize(IntVar* const v, int64_t step);

    //      /// Creates a objective with a given sense (true = maximization).
    //      OptimizeVar* MakeOptimize(bool maximize, IntVar* const v, int64_t step);

    //      /// Creates a minimization weighted objective. The actual objective is
    //      /// scalar_prod(sub_objectives, weights).
    //      OptimizeVar* MakeWeightedMinimize(const std::vector<IntVar*>& sub_objectives,
    //                                        const std::vector<int64_t>& weights,
    //                                        int64_t step);

    //      /// Creates a minimization weighted objective. The actual objective is
    //      /// scalar_prod(sub_objectives, weights).
    //      OptimizeVar* MakeWeightedMinimize(const std::vector<IntVar*>& sub_objectives,
    //                                        const std::vector<int>& weights,
    //                                        int64_t step);

    //      /// Creates a maximization weigthed objective.
    //      OptimizeVar* MakeWeightedMaximize(const std::vector<IntVar*>& sub_objectives,
    //                                        const std::vector<int64_t>& weights,
    //                                        int64_t step);

    //      /// Creates a maximization weigthed objective.
    //      OptimizeVar* MakeWeightedMaximize(const std::vector<IntVar*>& sub_objectives,
    //                                        const std::vector<int>& weights,
    //                                        int64_t step);

    //      /// Creates a weighted objective with a given sense (true = maximization).
    //      OptimizeVar* MakeWeightedOptimize(bool maximize,
    //                                        const std::vector<IntVar*>& sub_objectives,
    //                                        const std::vector<int64_t>& weights,
    //                                        int64_t step);

    //      /// Creates a weighted objective with a given sense (true = maximization).
    //      OptimizeVar* MakeWeightedOptimize(bool maximize,
    //                                        const std::vector<IntVar*>& sub_objectives,
    //                                        const std::vector<int>& weights,
    //                                        int64_t step);

    //      /// MetaHeuristics which try to get the search out of local optima.

    //      /// Creates a Tabu Search monitor.
    //      /// In the context of local search the behavior is similar to MakeOptimize(),
    //      /// creating an objective in a given sense. The behavior differs once a local
    //      /// optimum is reached: thereafter solutions which degrade the value of the
    //      /// objective are allowed if they are not "tabu". A solution is "tabu" if it
    //      /// doesn't respect the following rules:
    //      /// - improving the best solution found so far
    //      /// - variables in the "keep" list must keep their value, variables in the
    //      /// "forbid" list must not take the value they have in the list.
    //      /// Variables with new values enter the tabu lists after each new solution
    //      /// found and leave the lists after a given number of iterations (called
    //      /// tenure). Only the variables passed to the method can enter the lists.
    //      /// The tabu criterion is softened by the tabu factor which gives the number
    //      /// of "tabu" violations which is tolerated; a factor of 1 means no violations
    //      /// allowed; a factor of 0 means all violations are allowed.

    //      SearchMonitor* MakeTabuSearch(bool maximize, IntVar* const v, int64_t step,
    //                                    const std::vector<IntVar*>& vars,
    //                                    int64_t keep_tenure, int64_t forbid_tenure,
    //                                    double tabu_factor);

    //      /// Creates a Tabu Search based on the vars |vars|.
    //      /// A solution is "tabu" if all the vars in |vars| keep their value.
    //      SearchMonitor* MakeGenericTabuSearch(bool maximize, IntVar* const v,
    //                                           int64_t step,
    //                                           const std::vector<IntVar*>& tabu_vars,
    //                                           int64_t forbid_tenure);

    //      /// Creates a Simulated Annealing monitor.
    //      // TODO(user): document behavior
    //      SearchMonitor* MakeSimulatedAnnealing(bool maximize, IntVar* const v,
    //                                            int64_t step,
    //                                            int64_t initial_temperature);

    //      /// Creates a Guided Local Search monitor.
    //      /// Description here: http://en.wikipedia.org/wiki/Guided_Local_Search
    //      SearchMonitor* MakeGuidedLocalSearch(
    //          bool maximize, IntVar* objective, IndexEvaluator2 objective_function,
    //          int64_t step, const std::vector<IntVar*>& vars, double penalty_factor,
    //          bool reset_penalties_on_new_best_solution = false);
    //      SearchMonitor* MakeGuidedLocalSearch(
    //          bool maximize, IntVar* objective, IndexEvaluator3 objective_function,
    //          int64_t step, const std::vector<IntVar*>& vars,
    //          const std::vector<IntVar*>& secondary_vars, double penalty_factor,
    //          bool reset_penalties_on_new_best_solution = false);

    //      /// This search monitor will restart the search periodically.
    //      /// At the iteration n, it will restart after scale_factor * Luby(n) failures
    //      /// where Luby is the Luby Strategy (i.e. 1 1 2 1 1 2 4 1 1 2 1 1 2 4 8...).
    //      SearchMonitor* MakeLubyRestart(int scale_factor);

    //      /// This search monitor will restart the search periodically after 'frequency'
    //      /// failures.
    //      SearchMonitor* MakeConstantRestart(int frequency);

    //      /// Creates a search limit that constrains the running time.
    //      ABSL_MUST_USE_RESULT RegularLimit* MakeTimeLimit(absl::Duration time);
    //    #if !defined(SWIG)
    //      ABSL_DEPRECATED("Use the version taking absl::Duration() as argument")
    //    #endif  // !defined(SWIG)
    //      ABSL_MUST_USE_RESULT RegularLimit* MakeTimeLimit(int64_t time_in_ms) {
    //        return MakeTimeLimit(time_in_ms == kint64max
    //                                 ? absl::InfiniteDuration()
    //                                 : absl::Milliseconds(time_in_ms));
    //      }

    //      /// Creates a search limit that constrains the number of branches
    //      /// explored in the search tree.
    //      ABSL_MUST_USE_RESULT RegularLimit* MakeBranchesLimit(int64_t branches);

    //      /// Creates a search limit that constrains the number of failures
    //      /// that can happen when exploring the search tree.
    //      ABSL_MUST_USE_RESULT RegularLimit* MakeFailuresLimit(int64_t failures);

    //      /// Creates a search limit that constrains the number of solutions found
    //      /// during the search.
    //      ABSL_MUST_USE_RESULT RegularLimit* MakeSolutionsLimit(int64_t solutions);

    //      /// Limits the search with the 'time', 'branches', 'failures' and
    //      /// 'solutions' limits. 'smart_time_check' reduces the calls to the wall
    //      // timer by estimating the number of remaining calls, and 'cumulative' means
    //      // that the limit applies cumulatively, instead of search-by-search.
    //      ABSL_MUST_USE_RESULT RegularLimit* MakeLimit(absl::Duration time,
    //                                                   int64_t branches,
    //                                                   int64_t failures,
    //                                                   int64_t solutions,
    //                                                   bool smart_time_check = false,
    //                                                   bool cumulative = false);
    //      /// Creates a search limit from its protobuf description
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

    //      /// Creates a regular limit proto containing default values.
    //      RegularLimitParameters MakeDefaultRegularLimitParameters() const;

    //      /// Creates a search limit that is reached when either of the underlying limit
    //      /// is reached. That is, the returned limit is more stringent than both
    //      /// argument limits.
    //      ABSL_MUST_USE_RESULT SearchLimit* MakeLimit(SearchLimit* const limit_1,
    //                                                  SearchLimit* const limit_2);

    //      /// Limits the search based on the improvements of 'objective_var'. Stops the
    //      /// search when the improvement rate gets lower than a threshold value. This
    //      /// threshold value is computed based on the improvement rate during the first
    //      /// phase of the search.
    //      ABSL_MUST_USE_RESULT ImprovementSearchLimit* MakeImprovementLimit(
    //          IntVar* objective_var, bool maximize, double objective_scaling_factor,
    //          double objective_offset, double improvement_rate_coefficient,
    //          int improvement_rate_solutions_distance);

    //      /// Callback-based search limit. Search stops when limiter returns true; if
    //      /// this happens at a leaf the corresponding solution will be rejected.
    //      ABSL_MUST_USE_RESULT SearchLimit* MakeCustomLimit(
    //          std::function<bool()> limiter);

    //      // TODO(user): DEPRECATE API of MakeSearchLog(.., IntVar* var,..).

    //      /// The SearchMonitors below will display a periodic search log
    //      /// on LOG(INFO) every branch_period branches explored.
    //      SearchMonitor* MakeSearchLog(int branch_period);

    //      /// At each solution, this monitor also display the var value.
    //      SearchMonitor* MakeSearchLog(int branch_period, IntVar* const var);

    //      /// At each solution, this monitor will also display result of @p
    //      /// display_callback.
    //      SearchMonitor* MakeSearchLog(int branch_period,
    //                                   std::function<std::string()> display_callback);

    //      /// At each solution, this monitor will display the 'var' value and the
    //      /// result of @p display_callback.
    //      SearchMonitor* MakeSearchLog(int branch_period, IntVar* var,
    //                                   std::function<std::string()> display_callback);

    //      /// OptimizeVar Search Logs
    //      /// At each solution, this monitor will also display the 'opt_var' value.
    //      SearchMonitor* MakeSearchLog(int branch_period, OptimizeVar* const opt_var);

    //      /// Creates a search monitor that will also print the result of the
    //      /// display callback.
    //      SearchMonitor* MakeSearchLog(int branch_period, OptimizeVar* const opt_var,
    //                                   std::function<std::string()> display_callback);

    //      /// Creates a search monitor from logging parameters.
    //      struct SearchLogParameters {
    //        /// SearchMonitors will display a periodic search log every branch_period
    //        /// branches explored.
    //        int branch_period = 1;
    //        /// SearchMonitors will display values of objective or variable (both cannot
    //        /// be used together).
    //        OptimizeVar* objective = nullptr;
    //        IntVar* variable = nullptr;
    //        /// When displayed, objective or var values will be scaled and offset by
    //        /// the given values in the following way:
    //        /// scaling_factor * (value + offset).
    //        double scaling_factor = 1.0;
    //        double offset = 0;
    //        /// SearchMonitors will display the result of display_callback at each new
    //        /// solution found and when the search finishes if
    //        /// display_on_new_solutions_only is false.
    //        std::function<std::string()> display_callback;
    //        /// To be used to protect from cases where display_callback assumes
    //        /// variables are instantiated, which only happens in AtSolution().
    //        bool display_on_new_solutions_only = true;
    //      };
    //      SearchMonitor* MakeSearchLog(SearchLogParameters parameters);

    //      /// Creates a search monitor that will trace precisely the behavior of the
    //      /// search. Use this only for low level debugging.
    //      SearchMonitor* MakeSearchTrace(const std::string& prefix);

    //      /// ----- Callback-based search monitors -----
    //      SearchMonitor* MakeEnterSearchCallback(std::function<void()> callback);
    //      SearchMonitor* MakeExitSearchCallback(std::function<void()> callback);
    //      SearchMonitor* MakeAtSolutionCallback(std::function<void()> callback);

    //      /// Prints the model.
    //      ModelVisitor* MakePrintModelVisitor();
    //      /// Displays some nice statistics on the model.
    //      ModelVisitor* MakeStatisticsModelVisitor();
    //    #if !defined(SWIG)
    //      /// Compute the number of constraints a variable is attached to.
    //      ModelVisitor* MakeVariableDegreeVisitor(
    //          absl::flat_hash_map<const IntVar*, int>* const map);
    //    #endif  // !defined(SWIG)

    //      /// Symmetry Breaking.
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

    //      /// Decisions.
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

    //      /// Creates a decision builder which sequentially composes decision builders.
    //      /// At each leaf of a decision builder, the next decision builder is therefore
    //      /// called. For instance, Compose(db1, db2) will result in the following tree:
    //      ///          d1 tree              |
    //      ///         /   |   \             |
    //      ///         db1 leaves            |
    //      ///       /     |     \           |
    //      ///  db2 tree db2 tree db2 tree   |
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

    //      /// Creates a decision builder which will create a search tree where each
    //      /// decision builder is called from the top of the search tree. For instance
    //      /// the decision builder Try(db1, db2) will entirely explore the search tree
    //      /// of db1 then the one of db2, resulting in the following search tree:
    //      ///        Tree root            |
    //      ///        /       \            |
    //      ///  db1 tree     db2 tree      |
    //      ///
    //      /// This is very handy to try a decision builder which partially explores the
    //      /// search space and if it fails to try another decision builder.
    //      ///
    //      // TODO(user): The search tree can be balanced by using binary
    //      /// "Try"-builders "recursively". For instance, Try(a,b,c,d) will give a tree
    //      /// unbalanced to the right, whereas Try(Try(a,b), Try(b,c)) will give a
    //      /// balanced tree. Investigate if we should only provide the binary version
    //      /// and/or if we should balance automatically.
    //      DecisionBuilder* Try(DecisionBuilder* const db1, DecisionBuilder* const db2);
    //      DecisionBuilder* Try(DecisionBuilder* const db1, DecisionBuilder* const db2,
    //                           DecisionBuilder* const db3);
    //      DecisionBuilder* Try(DecisionBuilder* const db1, DecisionBuilder* const db2,
    //                           DecisionBuilder* const db3, DecisionBuilder* const db4);
    //      DecisionBuilder* Try(const std::vector<DecisionBuilder*>& dbs);

    //      /// Phases on IntVar arrays.
    //      // TODO(user): name each of them differently, and document them (and do that
    //      /// for all other functions that have several homonyms in this .h).
    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IntVarStrategy var_str, IntValueStrategy val_str);
    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IndexEvaluator1 var_evaluator,
    //                                 IntValueStrategy val_str);

    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IntVarStrategy var_str,
    //                                 IndexEvaluator2 value_evaluator);

    //      /// var_val1_val2_comparator(var, val1, val2) is true iff assigning value
    //      /// "val1" to variable "var" is better than assigning value "val2".
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

    //      /// Shortcuts for small arrays.
    //      DecisionBuilder* MakePhase(IntVar* const v0, IntVarStrategy var_str,
    //                                 IntValueStrategy val_str);
    //      DecisionBuilder* MakePhase(IntVar* const v0, IntVar* const v1,
    //                                 IntVarStrategy var_str, IntValueStrategy val_str);
    //      DecisionBuilder* MakePhase(IntVar* const v0, IntVar* const v1,
    //                                 IntVar* const v2, IntVarStrategy var_str,
    //                                 IntValueStrategy val_str);
    //      DecisionBuilder* MakePhase(IntVar* const v0, IntVar* const v1,
    //                                 IntVar* const v2, IntVar* const v3,
    //                                 IntVarStrategy var_str, IntValueStrategy val_str);

    //      /// Returns a decision that tries to schedule a task at a given time.
    //      /// On the Apply branch, it will set that interval var as performed and set
    //      /// its start to 'est'. On the Refute branch, it will just update the
    //      /// 'marker' to 'est' + 1. This decision is used in the
    //      /// INTERVAL_SET_TIMES_FORWARD strategy.
    //      Decision* MakeScheduleOrPostpone(IntervalVar* const var, int64_t est,
    //                                       int64_t* const marker);

    //      /// Returns a decision that tries to schedule a task at a given time.
    //      /// On the Apply branch, it will set that interval var as performed and set
    //      /// its end to 'est'. On the Refute branch, it will just update the
    //      /// 'marker' to 'est' - 1. This decision is used in the
    //      /// INTERVAL_SET_TIMES_BACKWARD strategy.
    //      Decision* MakeScheduleOrExpedite(IntervalVar* const var, int64_t est,
    //                                       int64_t* const marker);

    //      /// Returns a decision that tries to rank first the ith interval var
    //      /// in the sequence variable.
    //      Decision* MakeRankFirstInterval(SequenceVar* const sequence, int index);

    //      /// Returns a decision that tries to rank last the ith interval var
    //      /// in the sequence variable.
    //      Decision* MakeRankLastInterval(SequenceVar* const sequence, int index);

    //      /// Returns a decision builder which assigns values to variables which
    //      /// minimize the values returned by the evaluator. The arguments passed to the
    //      /// evaluator callback are the indices of the variables in vars and the values
    //      /// of these variables. Ownership of the callback is passed to the decision
    //      /// builder.
    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IndexEvaluator2 eval, EvaluatorStrategy str);

    //      /// Returns a decision builder which assigns values to variables
    //      /// which minimize the values returned by the evaluator. In case of
    //      /// tie breaks, the second callback is used to choose the best index
    //      /// in the array of equivalent pairs with equivalent evaluations. The
    //      /// arguments passed to the evaluator callback are the indices of the
    //      /// variables in vars and the values of these variables. Ownership of
    //      /// the callback is passed to the decision builder.
    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IndexEvaluator2 eval, IndexEvaluator1 tie_breaker,
    //                                 EvaluatorStrategy str);

    //      /// Scheduling phases.
    //      DecisionBuilder* MakePhase(const std::vector<IntervalVar*>& intervals,
    //                                 IntervalStrategy str);

    //      DecisionBuilder* MakePhase(const std::vector<SequenceVar*>& sequences,
    //                                 SequenceStrategy str);

    //      /// Returns a decision builder for which the left-most leaf corresponds
    //      /// to assignment, the rest of the tree being explored using 'db'.
    //      DecisionBuilder* MakeDecisionBuilderFromAssignment(
    //          Assignment* const assignment, DecisionBuilder* const db,
    //          const std::vector<IntVar*>& vars);

    //      /// Returns a decision builder that will add the given constraint to
    //      /// the model.
    //      DecisionBuilder* MakeConstraintAdder(Constraint* const ct);

    //      /// SolveOnce will collapse a search tree described by a decision
    //      /// builder 'db' and a set of monitors and wrap it into a single point.
    //      /// If there are no solutions to this nested tree, then SolveOnce will
    //      /// fail. If there is a solution, it will find it and returns nullptr.
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

    //      /// NestedOptimize will collapse a search tree described by a
    //      /// decision builder 'db' and a set of monitors and wrap it into a
    //      /// single point. If there are no solutions to this nested tree, then
    //      /// NestedOptimize will fail. If there are solutions, it will find
    //      /// the best as described by the mandatory objective in the solution
    //      /// as well as the optimization direction, instantiate all variables
    //      /// to this solution, and return nullptr.
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

    //      /// Returns a DecisionBuilder which restores an Assignment
    //      /// (calls void Assignment::Restore())
    //      DecisionBuilder* MakeRestoreAssignment(Assignment* assignment);

    //      /// Returns a DecisionBuilder which stores an Assignment
    //      /// (calls void Assignment::Store())
    //      DecisionBuilder* MakeStoreAssignment(Assignment* assignment);

    //      /// Local Search Operators.
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

    //      /// Creates a large neighborhood search operator which creates fragments (set
    //      /// of relaxed variables) with up to number_of_variables random variables
    //      /// (sampling with replacement is performed meaning that at most
    //      /// number_of_variables variables are selected). Warning: this operator will
    //      /// always return neighbors; using it without a search limit will result in a
    //      /// non-ending search.
    //      /// Optionally a random seed can be specified.
    //      LocalSearchOperator* MakeRandomLnsOperator(const std::vector<IntVar*>& vars,
    //                                                 int number_of_variables);
    //      LocalSearchOperator* MakeRandomLnsOperator(const std::vector<IntVar*>& vars,
    //                                                 int number_of_variables,
    //                                                 int32_t seed);

    //      /// Creates a local search operator that tries to move the assignment of some
    //      /// variables toward a target. The target is given as an Assignment. This
    //      /// operator generates neighbors in which the only difference compared to the
    //      /// current state is that one variable that belongs to the target assignment
    //      /// is set to its target value.
    //      LocalSearchOperator* MakeMoveTowardTargetOperator(const Assignment& target);

    //      /// Creates a local search operator that tries to move the assignment of some
    //      /// variables toward a target. The target is given either as two vectors: a
    //      /// vector of variables and a vector of associated target values. The two
    //      /// vectors should be of the same length. This operator generates neighbors in
    //      /// which the only difference compared to the current state is that one
    //      /// variable that belongs to the given vector is set to its target value.
    //      LocalSearchOperator* MakeMoveTowardTargetOperator(
    //          const std::vector<IntVar*>& variables,
    //          const std::vector<int64_t>& target_values);

    //      /// Creates a local search operator which concatenates a vector of operators.
    //      /// Each operator from the vector is called sequentially. By default, when a
    //      /// neighbor is found the neighborhood exploration restarts from the last
    //      /// active operator (the one which produced the neighbor).
    //      /// This can be overridden by setting restart to true to force the exploration
    //      /// to start from the first operator in the vector.
    //      ///
    //      /// The default behavior can also be overridden using an evaluation callback
    //      /// to set the order in which the operators are explored (the callback is
    //      /// called in LocalSearchOperator::Start()). The first argument of the
    //      /// callback is the index of the operator which produced the last move, the
    //      /// second argument is the index of the operator to be evaluated. Ownership of
    //      /// the callback is taken by ConcatenateOperators.
    //      ///
    //      /// Example:
    //      ///
    //      ///  const int kPriorities = {10, 100, 10, 0};
    //      ///  int64_t Evaluate(int active_operator, int current_operator) {
    //      ///    return kPriorities[current_operator];
    //      ///  }
    //      ///
    //      ///  LocalSearchOperator* concat =
    //      ///    solver.ConcatenateOperators(operators,
    //      ///                                NewPermanentCallback(&Evaluate));
    //      ///
    //      /// The elements of the vector operators will be sorted by increasing priority
    //      /// and explored in that order (tie-breaks are handled by keeping the relative
    //      /// operator order in the vector). This would result in the following order:
    //      /// operators[3], operators[0], operators[2], operators[1].
    //      ///
    //      LocalSearchOperator* ConcatenateOperators(
    //          const std::vector<LocalSearchOperator*>& ops);
    //      LocalSearchOperator* ConcatenateOperators(
    //          const std::vector<LocalSearchOperator*>& ops, bool restart);
    //      LocalSearchOperator* ConcatenateOperators(
    //          const std::vector<LocalSearchOperator*>& ops,
    //          std::function<int64_t(int, int)> evaluator);
    //      /// Randomized version of local search concatenator; calls a random operator
    //      /// at each call to MakeNextNeighbor().
    //      LocalSearchOperator* RandomConcatenateOperators(
    //          const std::vector<LocalSearchOperator*>& ops);

    //      /// Randomized version of local search concatenator; calls a random operator
    //      /// at each call to MakeNextNeighbor(). The provided seed is used to
    //      /// initialize the random number generator.
    //      LocalSearchOperator* RandomConcatenateOperators(
    //          const std::vector<LocalSearchOperator*>& ops, int32_t seed);

    //      /// Creates a local search operator which concatenates a vector of operators.
    //      /// Uses Multi-Armed Bandit approach for choosing the next operator to use.
    //      /// Sorts operators based on Upper Confidence Bound Algorithm which evaluates
    //      /// each operator as sum of average improvement and exploration function.
    //      ///
    //      /// Updates the order of operators when accepts a neighbor with objective
    //      /// improvement.
    //      LocalSearchOperator* MultiArmedBanditConcatenateOperators(
    //          const std::vector<LocalSearchOperator*>& ops, double memory_coefficient,
    //          double exploration_coefficient, bool maximize);

    //      /// Creates a local search operator that wraps another local search
    //      /// operator and limits the number of neighbors explored (i.e., calls
    //      /// to MakeNextNeighbor from the current solution (between two calls
    //      /// to Start()). When this limit is reached, MakeNextNeighbor()
    //      /// returns false. The counter is cleared when Start() is called.
    //      LocalSearchOperator* MakeNeighborhoodLimit(LocalSearchOperator* const op,
    //                                                 int64_t limit);

    //      /// Local Search decision builders factories.
    //      /// Local search is used to improve a given solution. This initial solution
    //      /// can be specified either by an Assignment or by a DecisionBulder, and the
    //      /// corresponding variables, the initial solution being the first solution
    //      /// found by the DecisionBuilder.
    //      /// The LocalSearchPhaseParameters parameter holds the actual definition of
    //      /// the local search phase:
    //      /// - a local search operator used to explore the neighborhood of the current
    //      ///   solution,
    //      /// - a decision builder to instantiate unbound variables once a neighbor has
    //      ///   been defined; in the case of LNS-based operators instantiates fragment
    //      ///   variables; search monitors can be added to this sub-search by wrapping
    //      ///   the decision builder with MakeSolveOnce.
    //      /// - a search limit specifying how long local search looks for neighbors
    //      ///   before accepting one; the last neighbor is always taken and in the case
    //      ///   of a greedy search, this corresponds to the best local neighbor;
    //      ///   first-accept (which is the default behavior) can be modeled using a
    //      ///   solution found limit of 1,
    //      /// - a vector of local search filters used to speed up the search by pruning
    //      ///   unfeasible neighbors.
    //      /// Metaheuristics can be added by defining specialized search monitors;
    //      /// currently down/up-hill climbing is available through OptimizeVar, as well
    //      /// as Guided Local Search, Tabu Search and Simulated Annealing.
    //      ///
    //      // TODO(user): Make a variant which runs a local search after each
    //      //                solution found in a DFS.

    //      DecisionBuilder* MakeLocalSearchPhase(
    //          Assignment* const assignment,
    //          LocalSearchPhaseParameters* const parameters);
    //      DecisionBuilder* MakeLocalSearchPhase(
    //          const std::vector<IntVar*>& vars, DecisionBuilder* const first_solution,
    //          LocalSearchPhaseParameters* const parameters);
    //      /// Variant with a sub_decison_builder specific to the first solution.
    //      DecisionBuilder* MakeLocalSearchPhase(
    //          const std::vector<IntVar*>& vars, DecisionBuilder* const first_solution,
    //          DecisionBuilder* const first_solution_sub_decision_builder,
    //          LocalSearchPhaseParameters* const parameters);
    //      DecisionBuilder* MakeLocalSearchPhase(
    //          const std::vector<SequenceVar*>& vars,
    //          DecisionBuilder* const first_solution,
    //          LocalSearchPhaseParameters* const parameters);

    //      /// Solution Pool.
    //      SolutionPool* MakeDefaultSolutionPool();

    //      /// Local Search Phase Parameters
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

    //      /// Local Search Filters
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

    //      /// Performs PeriodicCheck on the top-level search; for instance, can be
    //      /// called from a nested solve to check top-level limits.
    //      void TopPeriodicCheck();
    //      /// Returns a percentage representing the propress of the search before
    //      /// reaching the limits of the top-level search (can be called from a nested
    //      /// solve).
    //      int TopProgressPercent();

    //      /// The PushState and PopState methods manipulates the states
    //      /// of the reversible objects. They are visible only because they
    //      /// are useful to write unitary tests.
    //      void PushState();
    //      void PopState();

    //      /// Gets the search depth of the current active search. Returns -1 if
    //      /// there is no active search opened.
    //      int SearchDepth() const;

    //      /// Gets the search left depth of the current active search. Returns -1 if
    //      /// there is no active search opened.
    //      int SearchLeftDepth() const;

    //      /// Gets the number of nested searches. It returns 0 outside search,
    //      /// 1 during the top level search, 2 or more in case of nested searches.
    //      int SolveDepth() const;

    //      /// Sets the given branch selector on the current active search.
    //      void SetBranchSelector(BranchSelector bs);

    //      /// Creates a decision builder that will set the branch selector.
    //      DecisionBuilder* MakeApplyBranchSelector(BranchSelector bs);

    //      /// All-in-one SaveAndSetValue.
    //      template <class T>
    //      void SaveAndSetValue(T* adr, T val) {
    //        if (*adr != val) {
    //          InternalSaveValue(adr);
    //          *adr = val;
    //        }
    //      }

    //      /// All-in-one SaveAndAdd_value.
    //      template <class T>
    //      void SaveAndAdd(T* adr, T val) {
    //        if (val != 0) {
    //          InternalSaveValue(adr);
    //          (*adr) += val;
    //        }
    //      }

    //      /// Returns a random value between 0 and 'size' - 1;
    //      int64_t Rand64(int64_t size) {
    //        DCHECK_GT(size, 0);
    //        return absl::Uniform<int64_t>(random_, 0, size);
    //      }

    //      /// Returns a random value between 0 and 'size' - 1;
    //      int32_t Rand32(int32_t size) {
    //        DCHECK_GT(size, 0);
    //        return absl::Uniform<int32_t>(random_, 0, size);
    //      }

    //      /// Reseed the solver random generator.
    //      void ReSeed(int32_t seed) { random_.seed(seed); }

    //      /// Exports the profiling information in a human readable overview.
    //      /// The parameter profile_level used to create the solver must be
    //      /// set to true.
    //      void ExportProfilingOverview(const std::string& filename);

    //      /// Returns local search profiling information in a human readable format.
    //      // TODO(user): Merge demon and local search profiles.
    //      std::string LocalSearchProfile() const;

    //    #if !defined(SWIG)
    //      /// Returns detailed cp search statistics.
    //      ConstraintSolverStatistics GetConstraintSolverStatistics() const;
    //      /// Returns detailed local search statistics.
    //      LocalSearchStatistics GetLocalSearchStatistics() const;
    //    #endif  // !defined(SWIG)

    //      /// Returns true whether the current search has been
    //      /// created using a Solve() call instead of a NewSearch one. It
    //      /// returns false if the solver is not in search at all.
    //      bool CurrentlyInSolve() const;

    //      /// Counts the number of constraints that have been added
    //      /// to the solver before the search.
    //      int constraints() const { return constraints_list_.size(); }

    //      /// Accepts the given model visitor.
    //      void Accept(ModelVisitor* const visitor) const;

    //      Decision* balancing_decision() const { return balancing_decision_.get(); }

    //      /// Internal
    //    #if !defined(SWIG)
    //      void set_fail_intercept(std::function<void()> fail_intercept) {
    //        fail_intercept_ = std::move(fail_intercept);
    //      }
    //    #endif  // !defined(SWIG)
    //      void clear_fail_intercept() { fail_intercept_ = nullptr; }
    //      /// Access to demon profiler.
    //      DemonProfiler* demon_profiler() const { return demon_profiler_; }
    //      // TODO(user): Get rid of the following methods once fast local search is
    //      /// enabled for metaheuristics.
    //      /// Disables/enables fast local search.
    //      void SetUseFastLocalSearch(bool use_fast_local_search) {
    //        use_fast_local_search_ = use_fast_local_search;
    //      }
    //      /// Returns true if fast local search is enabled.
    //      bool UseFastLocalSearch() const { return use_fast_local_search_; }
    //      /// Returns whether the object has been named or not.
    //      bool HasName(const PropagationBaseObject* object) const;
    //      /// Adds a new demon and wraps it inside a DemonProfiler if necessary.
    //      Demon* RegisterDemon(Demon* const demon);
    //      /// Registers a new IntExpr and wraps it inside a TraceIntExpr if necessary.
    //      IntExpr* RegisterIntExpr(IntExpr* const expr);
    //      /// Registers a new IntVar and wraps it inside a TraceIntVar if necessary.
    //      IntVar* RegisterIntVar(IntVar* const var);
    //      /// Registers a new IntervalVar and wraps it inside a TraceIntervalVar
    //      /// if necessary.
    //      IntervalVar* RegisterIntervalVar(IntervalVar* const var);

    //      /// Returns the active search, nullptr outside search.
    //      Search* ActiveSearch() const;
    //      /// Returns the cache of the model.
    //      ModelCache* Cache() const;
    //      /// Returns whether we are instrumenting demons.
    //      bool InstrumentsDemons() const;
    //      /// Returns whether we are profiling the solver.
    //      bool IsProfilingEnabled() const;
    //      /// Returns whether we are profiling local search.
    //      bool IsLocalSearchProfilingEnabled() const;
    //      /// Returns whether we are tracing variables.
    //      bool InstrumentsVariables() const;
    //      /// Returns whether all variables should be named.
    //      bool NameAllVariables() const;
    //      /// Returns the name of the model.
    //      std::string model_name() const;
    //      /// Returns the propagation monitor.
    //      PropagationMonitor* GetPropagationMonitor() const;
    //      /// Adds the propagation monitor to the solver. This is called internally when
    //      /// a propagation monitor is passed to the Solve() or NewSearch() method.
    //      void AddPropagationMonitor(PropagationMonitor* const monitor);
    //      /// Returns the local search monitor.
    //      LocalSearchMonitor* GetLocalSearchMonitor() const;
    //      /// Adds the local search monitor to the solver. This is called internally
    //      /// when a propagation monitor is passed to the Solve() or NewSearch() method.
    //      void AddLocalSearchMonitor(LocalSearchMonitor* monitor);
    //      void SetSearchContext(Search* search, const std::string& search_context);
    //      std::string SearchContext() const;
    //      std::string SearchContext(const Search* search) const;
    //      /// Returns (or creates) an assignment representing the state of local search.
    //      // TODO(user): Investigate if this should be moved to Search.
    //      Assignment* GetOrCreateLocalSearchState();
    //      /// Clears the local search state.
    //      void ClearLocalSearchState() { local_search_state_.reset(nullptr); }

    //      /// Unsafe temporary vector. It is used to avoid leaks in operations
    //      /// that need storage and that may fail. See IntVar::SetValues() for
    //      /// instance. It is not locked; do not use in a multi-threaded or reentrant
    //      /// setup.
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

    //      /// Returns true if expr represents either boolean_var or 1 -
    //      /// boolean_var.  In that case, it fills inner_var and is_negated to be
    //      /// true if the expression is 1 - boolean_var -- equivalent to
    //      /// not(boolean_var).
    //      bool IsBooleanVar(IntExpr* const expr, IntVar** inner_var,
    //                        bool* is_negated) const;

    //      /// Returns true if expr represents a product of a expr and a
    //      /// constant.  In that case, it fills inner_expr and coefficient with
    //      /// these, and returns true. In the other case, it fills inner_expr
    //      /// with expr, coefficient with 1, and returns false.
    //      bool IsProduct(IntExpr* const expr, IntExpr** inner_expr,
    //                     int64_t* coefficient);
    //    #endif  /// !defined(SWIG)

    //      /// Internal. If the variables is the result of expr->Var(), this
    //      /// method returns expr, nullptr otherwise.
    //      IntExpr* CastExpression(const IntVar* const var) const;

    //      /// Tells the solver to kill or restart the current search.
    //      void FinishCurrentSearch();
    //      void RestartCurrentSearch();

    //      /// These methods are only useful for the SWIG wrappers, which need a way
    //      /// to externally cause the Solver to fail.
    //      void ShouldFail() { should_fail_ = true; }
    //      void CheckFail() {
    //        if (!should_fail_) return;
    //        should_fail_ = false;
    //        Fail();
    //      }

    //      /// Activates profiling on a decision builder.
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
    //      void EnqueueVar(Demon* const d);
    //      void EnqueueDelayedDemon(Demon* const d);
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
    //      /// UnsafeRevAlloc is used internally for cells in SimpleRevFIFO
    //      /// and other structures like this.
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

    //      /// Returns the Search object that is at the bottom of the search stack.
    //      /// Contrast with ActiveSearch(), which returns the search at the
    //      /// top of the stack.
    //      Search* TopLevelSearch() const { return searches_.at(1); }
    //      /// Returns the Search object which is the parent of the active search, i.e.,
    //      /// the search below the top of the stack. If the active search is at the
    //      /// bottom of the stack, returns the active search.
    //      Search* ParentSearch() const {
    //        const size_t search_size = searches_.size();
    //        DCHECK_GT(search_size, 1);
    //        return searches_[search_size - 2];
    //      }

    //      /// Naming
    //      std::string GetName(const PropagationBaseObject* object);
    //      void SetName(const PropagationBaseObject* object, const std::string& name);

    //      /// Variable indexing (note that indexing is not reversible).
    //      /// Returns a new index for an IntVar.
    //      int GetNewIntVarIndex() { return num_int_vars_++; }

    //      /// Internal.
    //      bool IsADifference(IntExpr* expr, IntExpr** const left,
    //                         IntExpr** const right);

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
    //      /// intercept failures
    //      std::function<void()> fail_intercept_;
    //      /// Demon monitor
    //      DemonProfiler* const demon_profiler_;
    //      /// Local search mode
    //      bool use_fast_local_search_;
    //      /// Local search profiler monitor
    //      LocalSearchProfiler* const local_search_profiler_;
    //      /// Local search state.
    //      std::unique_ptr<Assignment> local_search_state_;

    //      /// interval of constants cached, inclusive:
    //      enum { MIN_CACHED_INT_CONST = -8, MAX_CACHED_INT_CONST = 8 };
    //      IntVar* cached_constants_[MAX_CACHED_INT_CONST + 1 - MIN_CACHED_INT_CONST];

    //      /// Cached constraints.
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

    //      DISALLOW_COPY_AND_ASSIGN(Solver);
};

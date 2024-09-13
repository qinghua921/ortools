import { Domain } from "../GDomain";
import { BoolVar } from "./GBoolVar";
import { Constraint } from "./GConstraint";
import { CpModelProto } from "./GCpModelProto";
import { IntervalVar } from "./GIntervalVar";
import { IntVar } from "./GIntVar";
import { CanAsLinearExpr, LinearExpr } from "./GLinearExpr";
import { NoOverlap2DConstraint } from "./GNoOverlap2DConstraint";
import { TableConstraint } from "./GTableConstraint";

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
    //     void SetName( const std::string& name );

    //     IntVar NewIntVar( const Domain& domain );
    NewIntVar(domain: Domain): IntVar;

    //     BoolVar NewBoolVar();
    NewBoolVar(): BoolVar;

    //     IntVar NewConstant( int64_t value );

    //     BoolVar TrueVar();

    //     BoolVar FalseVar();

    //     IntervalVar NewIntervalVar( const LinearExpr& start, const LinearExpr& size,
    //                                 const LinearExpr& end );

    //     IntervalVar NewFixedSizeIntervalVar( const LinearExpr& start, int64_t size );

    //     IntervalVar NewOptionalIntervalVar( const LinearExpr& start,
    //                                         const LinearExpr& size,
    //                                         const LinearExpr& end, BoolVar presence );

    //     IntervalVar NewOptionalFixedSizeIntervalVar( const LinearExpr& start,
    //                                                  int64_t size, BoolVar presence );
    NewOptionalFixedSizeIntervalVar(start: CanAsLinearExpr, size: number, presence: BoolVar): IntervalVar;

    //     ///
    //     void FixVariable( IntVar var, int64_t value );
    //     void FixVariable( BoolVar var, bool value );

    //     Constraint AddBoolOr( absl::Span< const BoolVar > literals );
    AddBoolOr(literals: BoolVar[]): Constraint;

    //     Constraint AddAtLeastOne( absl::Span< const BoolVar > literals );

    //     Constraint AddAtMostOne( absl::Span< const BoolVar > literals );
    AddAtMostOne(literals: BoolVar[]): Constraint;

    //     Constraint AddExactlyOne( absl::Span< const BoolVar > literals );
    AddExactlyOne(literals: BoolVar[]): Constraint;

    //     Constraint AddBoolAnd( absl::Span< const BoolVar > literals );

    //     Constraint AddBoolXor( absl::Span< const BoolVar > literals );

    //     Constraint AddImplication( BoolVar a, BoolVar b )
    AddImplication(a: BoolVar, b: BoolVar): Constraint;

    //     Constraint AddImplication( absl::Span< const BoolVar > lhs,
    //                                absl::Span< const BoolVar > rhs )
    AddImplication(lhs: BoolVar[], rhs: BoolVar[]): Constraint;

    //     Constraint AddEquality( const LinearExpr& left, const LinearExpr& right );
    AddEquality(left: CanAsLinearExpr, right: CanAsLinearExpr): Constraint;

    //     Constraint AddGreaterOrEqual( const LinearExpr& left, const LinearExpr& right );
    AddGreaterOrEqual(left: CanAsLinearExpr, right: CanAsLinearExpr): Constraint;

    //     Constraint AddGreaterThan( const LinearExpr& left, const LinearExpr& right );
    AddGreaterThan(left: CanAsLinearExpr, right: CanAsLinearExpr): Constraint;

    //     Constraint AddLessOrEqual( const LinearExpr& left, const LinearExpr& right );
    AddLessOrEqual(left: CanAsLinearExpr, right: CanAsLinearExpr): Constraint;

    //     Constraint AddLessThan( const LinearExpr& left, const LinearExpr& right );
    AddLessThan(left: CanAsLinearExpr, right: CanAsLinearExpr): Constraint;

    //     Constraint AddLinearConstraint( const LinearExpr& expr, const Domain& domain );

    //     Constraint AddNotEqual( const LinearExpr& left, const LinearExpr& right );
    AddNotEqual(left: CanAsLinearExpr, right: CanAsLinearExpr): Constraint;

    //     Constraint AddAllDifferent( absl::Span< const IntVar > vars );
    AddAllDifferent(vars: IntVar[]): Constraint;

    //     Constraint AddAllDifferent( absl::Span< const LinearExpr > exprs );
    //     Constraint AddAllDifferent( std::initializer_list< LinearExpr > exprs );
    AddAllDifferent(exprs: LinearExpr[]): Constraint;

    //     Constraint AddVariableElement( IntVar                     index,
    //                                    absl::Span< const IntVar > variables,
    //                                    IntVar                     target );

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

    //     /**
    //      * Adds an allowed assignments constraint.
    //      *
    //      * An AllowedAssignments constraint is a constraint on an array of variables
    //      * that forces, when all variables are fixed to a single value, that the
    //      * corresponding list of values is equal to one of the tuples added to the
    //      * constraint.
    //      *
    //      * It returns a table constraint that allows adding tuples incrementally after
    //      * construction.
    //      */
    //     TableConstraint AddAllowedAssignments( absl::Span< const IntVar > vars );
    AddAllowedAssignments(vars: IntVar[]): TableConstraint;

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

    //     Constraint AddMinEquality( const LinearExpr&          target,
    //                                absl::Span< const IntVar > vars );

    //     Constraint AddMinEquality( const LinearExpr&              target,
    //                                absl::Span< const LinearExpr > exprs );

    //     Constraint AddMinEquality( const LinearExpr&                   target,
    //                                std::initializer_list< LinearExpr > exprs );

    //     Constraint AddMaxEquality( const LinearExpr&          target,
    //                                absl::Span< const IntVar > vars );

    //     Constraint AddMaxEquality( const LinearExpr&              target,
    //                                absl::Span< const LinearExpr > exprs );

    //     Constraint AddMaxEquality( const LinearExpr&                   target,
    //                                std::initializer_list< LinearExpr > exprs );

    //     Constraint AddDivisionEquality( const LinearExpr& target,
    //                                     const LinearExpr& numerator,
    //                                     const LinearExpr& denominator );

    //     Constraint AddAbsEquality( const LinearExpr& target, const LinearExpr& expr );

    //     Constraint AddModuloEquality( const LinearExpr& target, const LinearExpr& var,
    //                                   const LinearExpr& mod );

    //     Constraint AddMultiplicationEquality( const LinearExpr&              target,
    //                                           absl::Span< const LinearExpr > exprs );

    //     Constraint AddMultiplicationEquality( const LinearExpr&          target,
    //                                           absl::Span< const IntVar > vars );

    //     Constraint AddMultiplicationEquality( const LinearExpr&                   target,
    //                                           std::initializer_list< LinearExpr > exprs );

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
    AddNoOverlap2D(): NoOverlap2DConstraint;

    //     /**
    //      * The cumulative constraint
    //      *
    //      * It ensures that for any integer point, the sum of the demands of the
    //      * intervals containing that point does not exceed the capacity.
    //      */
    //     CumulativeConstraint AddCumulative( LinearExpr capacity );

    //     void Minimize( const LinearExpr& expr );
    Minimize(expr: CanAsLinearExpr): void;

    //     void Minimize( const DoubleLinearExpr& expr );

    //     void Maximize( const LinearExpr& expr );
    Maximize(expr: LinearExpr): void;

    //     void Maximize( const DoubleLinearExpr& expr );

    //     void ClearObjective();

    //     bool HasObjective() const;

    //     void AddDecisionStrategy(
    //         absl::Span< const IntVar >                       variables,
    //         DecisionStrategyProto::VariableSelectionStrategy var_strategy,
    //         DecisionStrategyProto::DomainReductionStrategy   domain_strategy );
    AddDecisionStrategy(variables: IntVar[], var_strategy: DecisionStrategyProto.VariableSelectionStrategy, domain_strategy: DecisionStrategyProto.DomainReductionStrategy): void;

    //     void AddDecisionStrategy(
    //         absl::Span< const BoolVar >                      variables,
    //         DecisionStrategyProto::VariableSelectionStrategy var_strategy,
    //         DecisionStrategyProto::DomainReductionStrategy   domain_strategy );
    AddDecisionStrategy(variables: BoolVar[], var_strategy: DecisionStrategyProto.VariableSelectionStrategy, domain_strategy: DecisionStrategyProto.DomainReductionStrategy): void;


    //     void AddHint( IntVar var, int64_t value );

    //     void AddHint( BoolVar var, bool value );

    //     void ClearHints();

    //     void AddAssumption( BoolVar lit );

    //     void AddAssumptions( absl::Span< const BoolVar > literals );
    AddAssumptions(literals: BoolVar[]): void;

    //     void ClearAssumptions();

    //     const CpModelProto& Build() const
    Build(): CpModelProto;

    //     const CpModelProto& Proto() const
    Proto(): CpModelProto;
    //     CpModelProto* MutableProto()
    //     {
    //         return &cp_model_;
    //     }

    //     bool ExportToFile( const std::string& filename ) const;

    //     void CopyFrom( const CpModelProto& model_proto );
    CopyFrom(model_proto: CpModelProto): void;

    //     BoolVar GetBoolVarFromProtoIndex( int index );

    //     IntVar GetIntVarFromProtoIndex( int index );
    GetIntVarFromProtoIndex(index: number): IntVar;

    //     IntervalVar GetIntervalVarFromProtoIndex( int index );

}

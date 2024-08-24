﻿#pragma once

#include <napi.h>

#include "ortools/sat/cp_model.h"
#include "../../commonheader.hpp"
#include "GBoolVar.hpp"
#include "GConstraint.hpp"
#include "GLinearExpr.hpp"
#include "GIntVar.hpp"
#include "GTableConstraint.hpp"
#include "GCpModelProto.hpp"
#include "GDoubleLinearExpr.hpp"

namespace operations_research
{
namespace sat
{
    class GCpModelBuilder : public Napi::ObjectWrap< GCpModelBuilder >
    {
    public:
        static Napi::FunctionReference constructor;
        CpModelBuilder*                pCpModelBuilder = nullptr;

        GCpModelBuilder( const Napi::CallbackInfo& info )
            : Napi::ObjectWrap< GCpModelBuilder >( info )
        {
            if ( info.Length() == 0 )
            {
                pCpModelBuilder = new CpModelBuilder();
                return;
            }

            ThrowJsError( GCpModelBuilder::Constructor : Invalid arguments );
        };

        ~GCpModelBuilder()
        {
            if ( pCpModelBuilder )
            {
                delete pCpModelBuilder;
                pCpModelBuilder = nullptr;
            }
        };

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "CpModelBuilder",
                {
                    InstanceMethod( "SetName", &GCpModelBuilder::SetName ),
                    InstanceMethod( "NewBoolVar", &GCpModelBuilder::NewBoolVar ),
                    InstanceMethod( "AddAtMostOne", &GCpModelBuilder::AddAtMostOne ),
                    InstanceMethod( "AddEquality", &GCpModelBuilder::AddEquality ),
                    InstanceMethod( "AddAllowedAssignments", &GCpModelBuilder::AddAllowedAssignments ),
                    InstanceMethod( "Maximize", &GCpModelBuilder::Maximize ),
                    InstanceMethod( "Build", &GCpModelBuilder::Build ),
                } );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( "CpModelBuilder", func );
            return exports;
        };

        //     void SetName( const std::string& name );
        Napi::Value SetName( const Napi::CallbackInfo& info )
        {
            if ( info.Length() == 1 && info[ 0 ].IsString() )
            {
                std::string name = info[ 0 ].As< Napi::String >().Utf8Value();
                pCpModelBuilder->SetName( name );
                return info.Env().Undefined();
            }

            ThrowJsError( GCpModelBuilder::SetName : Invalid arguments );
            return info.Env().Undefined();
        };

        //     /// Creates an integer variable with the given domain.
        //     IntVar NewIntVar( const Domain& domain );

        //     BoolVar NewBoolVar();
        Napi::Value NewBoolVar( const Napi::CallbackInfo& info )
        {
            if ( info.Length() == 0 )
            {
                auto boolVar     = new BoolVar( pCpModelBuilder->NewBoolVar() );
                auto externalVar = Napi::External< BoolVar >::New( info.Env(), boolVar );
                return GBoolVar::constructor.New( { externalVar } );
            }

            ThrowJsError( GCpModelBuilder::NewBoolVar : Invalid arguments );
            return info.Env().Undefined();
        };

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

        //     Constraint AddAtMostOne( absl::Span< const BoolVar > literals );
        Napi::Value AddAtMostOne( const Napi::CallbackInfo& info )
        {
            if ( info.Length() == 1 && info[ 0 ].IsArray() )
            {
                std::vector< BoolVar > literals;
                auto                   array = info[ 0 ].As< Napi::Array >();

                for ( int i = 0; i < array.Length(); i++ )
                {
                    auto obj = array.Get( i );
                    if ( obj.IsObject() && obj.As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
                    {
                        auto gBoolVar = obj.As< Napi::Object >();
                        auto boolVar  = Napi::ObjectWrap< GBoolVar >::Unwrap( gBoolVar );
                        literals.push_back( BoolVar( *boolVar->pBoolVar ) );
                    }
                    else
                    {
                        ThrowJsError( GCpModelBuilder::AddAtMostOne : Invalid arguments );
                        return info.Env().Undefined();
                    }
                }

                if ( literals.size() > 0 )
                {
                    auto constraint  = pCpModelBuilder->AddAtMostOne( literals );
                    auto pConstraint = new Constraint( constraint );
                    auto externalVar = Napi::External< Constraint >::New( info.Env(), pConstraint );
                    return GConstraint::constructor.New( { externalVar } );
                }
                else
                {
                    ThrowJsError( GCpModelBuilder::AddAtMostOne : Invalid arguments );
                    return info.Env().Undefined();
                }
            }

            ThrowJsError( GCpModelBuilder::AddAtMostOne : Invalid arguments );
            return info.Env().Undefined();
        };

        //     /// Exactly one literal is true. Sum literals == 1.
        //     Constraint AddExactlyOne( absl::Span< const BoolVar > literals );

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

        //     Constraint AddEquality( const LinearExpr& left, const LinearExpr& right );
        Napi::Value AddEquality( const Napi::CallbackInfo& info )
        {
            if ( info.Length() != 2 )
            {
                ThrowJsError( GCpModelBuilder::AddEquality : Invalid arguments );
                return info.Env().Undefined();
            }

            LinearExpr left;
            if ( info[ 0 ].IsObject() && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
            {
                auto gLinearExpr = info[ 0 ].As< Napi::Object >();
                auto linearExpr  = Napi::ObjectWrap< GLinearExpr >::Unwrap( gLinearExpr );
                left             = *linearExpr->pLinearExpr;
            }
            else if ( info[ 0 ].IsNumber() )
            {
                left = info[ 0 ].As< Napi::Number >().DoubleValue();
            }
            else if ( info[ 0 ].IsObject() && info[ 0 ].As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
            {
                auto gIntVar = info[ 0 ].As< Napi::Object >();
                auto intVar  = Napi::ObjectWrap< GIntVar >::Unwrap( gIntVar );
                left         = LinearExpr( *intVar->pIntVar );
            }
            else if ( info[ 0 ].IsObject() && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
            {
                auto gBoolVar = info[ 0 ].As< Napi::Object >();
                auto boolVar  = Napi::ObjectWrap< GBoolVar >::Unwrap( gBoolVar );
                left          = LinearExpr( *boolVar->pBoolVar );
            }
            else
            {
                ThrowJsError( GCpModelBuilder::AddEquality : Invalid arguments );
                return info.Env().Undefined();
            }

            LinearExpr right;
            if ( info[ 1 ].IsObject() && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
            {
                auto gLinearExpr = info[ 1 ].As< Napi::Object >();
                auto linearExpr  = Napi::ObjectWrap< GLinearExpr >::Unwrap( gLinearExpr );
                right            = *linearExpr->pLinearExpr;
            }
            else if ( info[ 1 ].IsNumber() )
            {
                right = info[ 1 ].As< Napi::Number >().DoubleValue();
            }
            else if ( info[ 1 ].IsObject() && info[ 1 ].As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
            {
                auto gIntVar = info[ 1 ].As< Napi::Object >();
                auto intVar  = Napi::ObjectWrap< GIntVar >::Unwrap( gIntVar );
                right        = LinearExpr( *intVar->pIntVar );
            }
            else if ( info[ 1 ].IsObject() && info[ 1 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
            {
                auto gBoolVar = info[ 1 ].As< Napi::Object >();
                auto boolVar  = Napi::ObjectWrap< GBoolVar >::Unwrap( gBoolVar );
                right         = LinearExpr( *boolVar->pBoolVar );
            }
            else
            {
                ThrowJsError( GCpModelBuilder::AddEquality : Invalid arguments );
                return info.Env().Undefined();
            }

            auto constraint  = pCpModelBuilder->AddEquality( left, right );
            auto pConstraint = new Constraint( constraint );
            auto externalVar = Napi::External< Constraint >::New( info.Env(), pConstraint );
            return GConstraint::constructor.New( { externalVar } );
        }

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

        //     TableConstraint AddAllowedAssignments( absl::Span< const IntVar > vars );
        Napi::Value AddAllowedAssignments( const Napi::CallbackInfo& info )
        {
            if ( info.Length() == 1 && info[ 0 ].IsArray() )
            {
                std::vector< IntVar > vars;
                auto                  array = info[ 0 ].As< Napi::Array >();

                for ( int i = 0; i < array.Length(); i++ )
                {
                    auto obj = array.Get( i );
                    if ( obj.IsObject() && obj.As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
                    {
                        auto gIntVar = obj.As< Napi::Object >();
                        auto intVar  = Napi::ObjectWrap< GIntVar >::Unwrap( gIntVar );
                        vars.push_back( *intVar->pIntVar );
                    }
                    else
                    {
                        ThrowJsError( GCpModelBuilder::AddAllowedAssignments : Invalid arguments );
                        return info.Env().Undefined();
                    }
                }

                if ( vars.size() > 0 )
                {
                    auto constraint  = pCpModelBuilder->AddAllowedAssignments( vars );
                    auto pConstraint = new Constraint( constraint );
                    auto externalVar = Napi::External< Constraint >::New( info.Env(), pConstraint );
                    return GTableConstraint::constructor.New( { externalVar } );
                }
            }

            ThrowJsError( GCpModelBuilder::AddAllowedAssignments : Invalid arguments );
            return info.Env().Undefined();
        }

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

        //     /// Adds a linear minimization objective.
        //     void Minimize( const LinearExpr& expr );

        //     /// Adds a linear floating point minimization objective.
        //     /// Note that the coefficients will be internally scaled to integer.
        //     void Minimize( const DoubleLinearExpr& expr );

        Napi::Value Maximize( const Napi::CallbackInfo& info )
        {
            //     void Maximize( const LinearExpr& expr );
            if ( info.Length() == 1
                 && info[ 0 ].IsObject()
                 && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
            {
                auto gLinearExpr = info[ 0 ].As< Napi::Object >();
                auto linearExpr  = Napi::ObjectWrap< GLinearExpr >::Unwrap( gLinearExpr );
                pCpModelBuilder->Maximize( *linearExpr->pLinearExpr );
                return info.Env().Undefined();
            }

            //     void Maximize( const DoubleLinearExpr& expr );
            if ( info.Length() == 1
                 && info[ 0 ].IsObject()
                 && info[ 0 ].As< Napi::Object >().InstanceOf( GDoubleLinearExpr::constructor.Value() ) )
            {
                auto gDoubleLinearExpr = info[ 0 ].As< Napi::Object >();
                auto doubleLinearExpr  = Napi::ObjectWrap< GDoubleLinearExpr >::Unwrap( gDoubleLinearExpr );
                pCpModelBuilder->Maximize( *doubleLinearExpr->pDoubleLinearExpr );
                return info.Env().Undefined();
            }

            ThrowJsError( GCpModelBuilder::Maximize : Invalid arguments );
            return info.Env().Undefined();
        }

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

        //     const CpModelProto& Build() const
        Napi::Value Build( const Napi::CallbackInfo& info )
        {
            if ( info.Length() == 0 )
            {
                auto proto    = pCpModelBuilder->Build();
                auto cppProto = new CpModelProto( proto );
                auto obj      = Napi::External< CpModelProto >::New( info.Env(), cppProto );
                return GCpModelProto::constructor.New( { obj } );
            }

            ThrowJsError( GCpModelBuilder::Build : Invalid arguments );
            return info.Env().Undefined();
        }

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

        // };
    };

    Napi::FunctionReference GCpModelBuilder::constructor;
};  // namespace sat
};  // namespace operations_research

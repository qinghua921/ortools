#pragma once

#include "commonheader.hpp"
#include "ortools/sat/cp_model.h"
#include "GBoolVar.hpp"
#include "GConstraint.hpp"
#include "GLinearExpr.hpp"
#include "GCpModelProto.hpp"
#include "GTableConstraint.hpp"
#include "operations_research/GDomain.hpp"
#include "GIntervalVar.hpp"
#include "GNoOverlap2DConstraint.hpp"

namespace operations_research
{
namespace sat
{
    class GCpModelBuilder : public Napi::ObjectWrap< GCpModelBuilder >
    {
    public:
        static inline Napi::FunctionReference constructor;
        CpModelBuilder*                       pCpModelBuilder = nullptr;
        GCpModelBuilder( const Napi::CallbackInfo& info );
        ~GCpModelBuilder();
        static Napi::Object Init( Napi::Env env, Napi::Object exports );

        Napi::Value Maximize( const Napi::CallbackInfo& info );
        Napi::Value AddLessOrEqual( const Napi::CallbackInfo& info );
        Napi::Value NewIntVar( const Napi::CallbackInfo& info );
        Napi::Value AddAtMostOne( const Napi::CallbackInfo& info );
        Napi::Value Build( const Napi::CallbackInfo& info );
        Napi::Value Minimize( const Napi::CallbackInfo& info );
        Napi::Value AddAllowedAssignments( const Napi::CallbackInfo& info );
        Napi::Value AddEquality( const Napi::CallbackInfo& info );
        Napi::Value AddExactlyOne( const Napi::CallbackInfo& info );
        Napi::Value NewBoolVar( const Napi::CallbackInfo& info );
        Napi::Value AddGreaterThan( const Napi::CallbackInfo& info );
        Napi::Value AddAssumptions( const Napi::CallbackInfo& info );
        Napi::Value NewOptionalFixedSizeIntervalVar( const Napi::CallbackInfo& info );
        Napi::Value AddNoOverlap2D( const Napi::CallbackInfo& info );
        Napi::Value AddGreaterOrEqual( const Napi::CallbackInfo& info );
        Napi::Value AddImplication( const Napi::CallbackInfo& info );
        Napi::Value AddBoolOr( const Napi::CallbackInfo& info );
        Napi::Value AddLessThan( const Napi::CallbackInfo& info );
        Napi::Value AddDecisionStrategy( const Napi::CallbackInfo& info );
    };
};  // namespace sat
};  // namespace operations_research

inline operations_research::sat::GCpModelBuilder::GCpModelBuilder( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GCpModelBuilder >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external   = info[ 0 ].As< Napi::External< CpModelBuilder > >();
        pCpModelBuilder = dynamic_cast< CpModelBuilder* >( external.Data() );
        if ( pCpModelBuilder != nullptr ) return;
    }

    if ( info.Length() == 0 )
    {
        pCpModelBuilder = new CpModelBuilder();
        return;
    }

    ThrowJsError( operations_research::GCpModelBuilder::GCpModelBuilder : Invalid argument );
}

inline operations_research::sat::GCpModelBuilder::~GCpModelBuilder()
{
    delete pCpModelBuilder;
}

inline Napi::Object operations_research::sat::GCpModelBuilder::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "CpModelBuilder",
        {
            InstanceMethod( "AddLessOrEqual", &GCpModelBuilder::AddLessOrEqual ),
            InstanceMethod( "NewIntVar", &GCpModelBuilder::NewIntVar ),
            InstanceMethod( "Build", &GCpModelBuilder::Build ),
            InstanceMethod( "AddAtMostOne", &GCpModelBuilder::AddAtMostOne ),
            InstanceMethod( "Minimize", &GCpModelBuilder::Minimize ),
            InstanceMethod( "AddAllowedAssignments", &GCpModelBuilder::AddAllowedAssignments ),
            InstanceMethod( "AddEquality", &GCpModelBuilder::AddEquality ),
            InstanceMethod( "AddExactlyOne", &GCpModelBuilder::AddExactlyOne ),
            InstanceMethod( "NewBoolVar", &GCpModelBuilder::NewBoolVar ),
            InstanceMethod( "Maximize", &GCpModelBuilder::Maximize ),
            InstanceMethod( "AddGreaterThan", &GCpModelBuilder::AddGreaterThan ),
            InstanceMethod( "AddAssumptions", &GCpModelBuilder::AddAssumptions ),
            InstanceMethod( "NewOptionalFixedSizeIntervalVar", &GCpModelBuilder::NewOptionalFixedSizeIntervalVar ),
            InstanceMethod( "AddNoOverlap2D", &GCpModelBuilder::AddNoOverlap2D ),
            InstanceMethod( "AddGreaterOrEqual", &GCpModelBuilder::AddGreaterOrEqual ),
            InstanceMethod( "AddImplication", &GCpModelBuilder::AddImplication ),
            InstanceMethod( "AddBoolOr", &GCpModelBuilder::AddBoolOr ),
            InstanceMethod( "AddLessThan", &GCpModelBuilder::AddLessThan ),
            InstanceMethod( "AddDecisionStrategy", &GCpModelBuilder::AddDecisionStrategy ),

        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "CpModelBuilder" ), func );
    return exports;
}

inline Napi::Value operations_research::sat::GCpModelBuilder::AddDecisionStrategy( const Napi::CallbackInfo& info )
{
    //     void AddDecisionStrategy(
    //         absl::Span< const IntVar >                       variables,
    //         DecisionStrategyProto::VariableSelectionStrategy var_strategy,
    //         DecisionStrategyProto::DomainReductionStrategy   domain_strategy );
    if ( info.Length() == 3 && info[ 0 ].IsArray() && info[ 1 ].IsNumber() && info[ 2 ].IsNumber()
         && info[ 0 ].As< Napi::Array >().Length() > 0
         && info[ 0 ].As< Napi::Array >().Get( static_cast< uint32_t >( 0 ) ).IsObject()
         && info[ 0 ].As< Napi::Array >().Get( static_cast< uint32_t >( 0 ) ).As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
    {
        auto                  arr = info[ 0 ].As< Napi::Array >();
        std::vector< IntVar > variables;
        for ( int i = 0; i < arr.Length(); i++ )
        {
            if ( arr.Get( i ).IsObject()
                 && arr.Get( i ).As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
            {
                auto gintvar = GIntVar::Unwrap( arr.Get( i ).As< Napi::Object >() );
                variables.push_back( *gintvar->pIntVar );
                continue;
            }

            ThrowJsError( operations_research::sat::GCpModelBuilder::AddDecisionStrategy : Invalid argument );
            return info.Env().Undefined();
        }

        auto var_strategy    = static_cast< DecisionStrategyProto::VariableSelectionStrategy >( info[ 1 ].As< Napi::Number >().Int32Value() );
        auto domain_strategy = static_cast< DecisionStrategyProto::DomainReductionStrategy >( info[ 2 ].As< Napi::Number >().Int32Value() );
        pCpModelBuilder->AddDecisionStrategy( variables, var_strategy, domain_strategy );
        return info.Env().Undefined();
    }

    //     void AddDecisionStrategy(
    //         absl::Span< const BoolVar >                      variables,
    //         DecisionStrategyProto::VariableSelectionStrategy var_strategy,
    //         DecisionStrategyProto::DomainReductionStrategy   domain_strategy );
    if ( info.Length() == 3 && info[ 0 ].IsArray() && info[ 1 ].IsNumber() && info[ 2 ].IsNumber()
         && info[ 0 ].As< Napi::Array >().Length() > 0
         && info[ 0 ].As< Napi::Array >().Get( static_cast< uint32_t >( 0 ) ).IsObject()
         && info[ 0 ].As< Napi::Array >().Get( static_cast< uint32_t >( 0 ) ).As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        auto                   arr = info[ 0 ].As< Napi::Array >();
        std::vector< BoolVar > variables;
        for ( int i = 0; i < arr.Length(); i++ )
        {
            if ( arr.Get( i ).IsObject()
                 && arr.Get( i ).As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
            {
                auto gboolvar = GBoolVar::Unwrap( arr.Get( i ).As< Napi::Object >() );
                variables.push_back( *gboolvar->pBoolVar );
                continue;
            }

            ThrowJsError( operations_research::sat::GCpModelBuilder::AddDecisionStrategy : Invalid argument );
            return info.Env().Undefined();
        }

        auto var_strategy    = static_cast< DecisionStrategyProto::VariableSelectionStrategy >( info[ 1 ].As< Napi::Number >().Int32Value() );
        auto domain_strategy = static_cast< DecisionStrategyProto::DomainReductionStrategy >( info[ 2 ].As< Napi::Number >().Int32Value() );
        pCpModelBuilder->AddDecisionStrategy( variables, var_strategy, domain_strategy );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::AddDecisionStrategy : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GCpModelBuilder::AddLessThan( const Napi::CallbackInfo& info )
{
    //     Constraint AddLessThan( const LinearExpr& left, const LinearExpr& right );
    LinearExpr left, right;
    if ( info.Length() == 2 && GLinearExpr::ToLinearExpr( info[ 0 ], left ) && GLinearExpr::ToLinearExpr( info[ 1 ], right ) )
    {
        auto constraint = pCpModelBuilder->AddLessThan( left, right );
        return GConstraint::FromExternal( new Constraint( constraint ) );
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::AddLessThan : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GCpModelBuilder::AddBoolOr( const Napi::CallbackInfo& info )
{
    //     Constraint AddBoolOr( absl::Span< const BoolVar > literals );
    if ( info.Length() == 1 && info[ 0 ].IsArray() )
    {
        auto                   arr = info[ 0 ].As< Napi::Array >();
        std::vector< BoolVar > literals;
        for ( int i = 0; i < arr.Length(); i++ )
        {
            if ( arr.Get( i ).IsObject()
                 && arr.Get( i ).As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
            {
                auto gboolvar = GBoolVar::Unwrap( arr.Get( i ).As< Napi::Object >() );
                literals.push_back( *gboolvar->pBoolVar );
                continue;
            }

            ThrowJsError( operations_research::sat::GCpModelBuilder::AddBoolOr : Invalid argument );
            return info.Env().Undefined();
        }

        auto constraint = pCpModelBuilder->AddBoolOr( literals );
        return GConstraint::FromExternal( new Constraint( constraint ) );
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::AddBoolOr : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GCpModelBuilder::AddImplication( const Napi::CallbackInfo& info )
{
    //     Constraint AddImplication( BoolVar a, BoolVar b )
    if ( info.Length() == 2 && info[ 0 ].IsObject() && info[ 1 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() )
         && info[ 1 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        auto gboolvar_a = GBoolVar::Unwrap( info[ 0 ].As< Napi::Object >() );
        auto gboolvar_b = GBoolVar::Unwrap( info[ 1 ].As< Napi::Object >() );
        auto constraint = pCpModelBuilder->AddImplication( *gboolvar_a->pBoolVar, *gboolvar_b->pBoolVar );
        return GConstraint::FromExternal( new Constraint( constraint ) );
    }

    //     Constraint AddImplication( absl::Span< const BoolVar > lhs,
    //                                absl::Span< const BoolVar > rhs )
    if ( info.Length() == 2 && info[ 0 ].IsArray() && info[ 1 ].IsArray() )
    {
        auto                   arr_lhs = info[ 0 ].As< Napi::Array >();
        std::vector< BoolVar > lhs;
        for ( int i = 0; i < arr_lhs.Length(); i++ )
        {
            if ( arr_lhs.Get( i ).IsObject()
                 && arr_lhs.Get( i ).As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
            {
                auto gboolvar = GBoolVar::Unwrap( arr_lhs.Get( i ).As< Napi::Object >() );
                lhs.push_back( *gboolvar->pBoolVar );
                continue;
            }

            ThrowJsError( operations_research::sat::GCpModelBuilder::AddImplication : Invalid argument );
            return info.Env().Undefined();
        }

        auto                   arr_rhs = info[ 1 ].As< Napi::Array >();
        std::vector< BoolVar > rhs;
        for ( int i = 0; i < arr_rhs.Length(); i++ )
        {
            if ( arr_rhs.Get( i ).IsObject()
                 && arr_rhs.Get( i ).As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
            {
                auto gboolvar = GBoolVar::Unwrap( arr_rhs.Get( i ).As< Napi::Object >() );
                rhs.push_back( *gboolvar->pBoolVar );
                continue;
            }

            ThrowJsError( operations_research::sat::GCpModelBuilder::AddImplication : Invalid argument );
            return info.Env().Undefined();
        }

        auto constraint = pCpModelBuilder->AddImplication( lhs, rhs );
        return GConstraint::FromExternal( new Constraint( constraint ) );
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::AddImplication : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GCpModelBuilder::AddGreaterOrEqual( const Napi::CallbackInfo& info )
{
    //     Constraint AddGreaterOrEqual( const LinearExpr& left, const LinearExpr& right );
    LinearExpr left, right;
    if ( info.Length() == 2 && GLinearExpr::ToLinearExpr( info[ 0 ], left ) && GLinearExpr::ToLinearExpr( info[ 1 ], right ) )
    {
        auto constraint = pCpModelBuilder->AddGreaterOrEqual( left, right );
        return GConstraint::FromExternal( new Constraint( constraint ) );
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::AddGreaterOrEqual : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GCpModelBuilder::AddNoOverlap2D( const Napi::CallbackInfo& info )
{
    //     NoOverlap2DConstraint AddNoOverlap2D();
    if ( info.Length() == 0 )
    {
        auto constraint = pCpModelBuilder->AddNoOverlap2D();
        auto external   = Napi::External< NoOverlap2DConstraint >::New( info.Env(), new NoOverlap2DConstraint( constraint ) );
        return GNoOverlap2DConstraint::constructor.New( { external } );
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::AddNoOverlap2D : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GCpModelBuilder::NewOptionalFixedSizeIntervalVar( const Napi::CallbackInfo& info )
{
    //     IntervalVar NewOptionalFixedSizeIntervalVar( const LinearExpr& start,
    //                                                  int64_t size, BoolVar presence );
    LinearExpr start;
    if ( info.Length() == 3
         && GLinearExpr::ToLinearExpr( info[ 0 ], start )
         && info[ 1 ].IsNumber()
         && info[ 2 ].IsObject()
         && info[ 2 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        auto size     = info[ 1 ].As< Napi::Number >().Int64Value();
        auto gboolvar = GBoolVar::Unwrap( info[ 2 ].As< Napi::Object >() );
        auto expr     = pCpModelBuilder->NewOptionalFixedSizeIntervalVar( start, size, *gboolvar->pBoolVar );
        auto external = Napi::External< IntervalVar >::New( info.Env(), new IntervalVar( expr ) );
        return GIntervalVar::constructor.New( { external } );
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::NewOptionalFixedSizeIntervalVar : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GCpModelBuilder::AddAssumptions( const Napi::CallbackInfo& info )
{
    //     void AddAssumptions( absl::Span< const BoolVar > literals );
    if ( info.Length() == 1 && info[ 0 ].IsArray() )
    {
        auto                   arr = info[ 0 ].As< Napi::Array >();
        std::vector< BoolVar > literals;
        for ( int i = 0; i < arr.Length(); i++ )
        {
            if ( arr.Get( i ).IsObject()
                 && arr.Get( i ).As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
            {
                auto gboolvar = GBoolVar::Unwrap( arr.Get( i ).As< Napi::Object >() );
                literals.push_back( *gboolvar->pBoolVar );
                continue;
            }

            ThrowJsError( operations_research::sat::GCpModelBuilder::AddAssumptions : Invalid argument );
            return info.Env().Undefined();
        }

        pCpModelBuilder->AddAssumptions( literals );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::AddAssumptions : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GCpModelBuilder::AddGreaterThan( const Napi::CallbackInfo& info )
{
    //     Constraint AddGreaterThan( const LinearExpr& left, const LinearExpr& right );
    LinearExpr left, right;
    if ( info.Length() == 2 && GLinearExpr::ToLinearExpr( info[ 0 ], left ) && GLinearExpr::ToLinearExpr( info[ 1 ], right ) )
    {
        auto constraint = pCpModelBuilder->AddGreaterThan( left, right );
        return GConstraint::FromExternal( new Constraint( constraint ) );
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::AddGreaterThan : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GCpModelBuilder::Maximize( const Napi::CallbackInfo& info )
{
    //     void Maximize( const LinearExpr& expr );
    if ( info.Length() == 1 && info[ 0 ].IsObject() && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        auto glinearexpr = GLinearExpr::Unwrap( info[ 0 ].As< Napi::Object >() );
        pCpModelBuilder->Maximize( *glinearexpr->pLinearExpr );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::Maximize : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GCpModelBuilder::AddLessOrEqual( const Napi::CallbackInfo& info )
{
    //     Constraint AddLessOrEqual( const LinearExpr& left, const LinearExpr& right );
    LinearExpr left, right;
    if ( info.Length() == 2 && GLinearExpr::ToLinearExpr( info[ 0 ], left ) && GLinearExpr::ToLinearExpr( info[ 1 ], right ) )
    {
        auto constraint = pCpModelBuilder->AddLessOrEqual( left, right );
        return GConstraint::FromExternal( new Constraint( constraint ) );
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::AddLessOrEqual : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GCpModelBuilder::NewIntVar( const Napi::CallbackInfo& info )
{
    //     IntVar NewIntVar( const Domain& domain );
    if ( info.Length() == 1 && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GDomain::constructor.Value() ) )
    {
        auto gdomain  = GDomain::Unwrap( info[ 0 ].As< Napi::Object >() );
        auto expr     = pCpModelBuilder->NewIntVar( *gdomain->pDomain );
        auto external = Napi::External< IntVar >::New( info.Env(), new IntVar( expr ) );
        return GIntVar::constructor.New( { external } );
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::NewIntVar : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GCpModelBuilder::AddAtMostOne( const Napi::CallbackInfo& info )
{
    //     Constraint AddAtMostOne( absl::Span< const BoolVar > literals );
    if ( info.Length() == 1 && info[ 0 ].IsArray() )
    {
        auto                   arr = info[ 0 ].As< Napi::Array >();
        std::vector< BoolVar > literals;
        for ( int i = 0; i < arr.Length(); i++ )
        {
            if ( arr.Get( i ).IsObject()
                 && arr.Get( i ).As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
            {
                auto gboolvar = GBoolVar::Unwrap( arr.Get( i ).As< Napi::Object >() );
                literals.push_back( *gboolvar->pBoolVar );
            }
        }
        auto constraint = pCpModelBuilder->AddAtMostOne( literals );
        return GConstraint::FromExternal( new Constraint( constraint ) );
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::AddAtMostOne : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GCpModelBuilder::Build( const Napi::CallbackInfo& info )
{
    //     const CpModelProto& Build() const
    if ( info.Length() == 0 )
    {
        auto model    = pCpModelBuilder->Build();
        auto external = Napi::External< CpModelProto >::New( info.Env(), new CpModelProto( model ) );
        return GCpModelProto::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GCpModelBuilder::Build : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GCpModelBuilder::Minimize( const Napi::CallbackInfo& info )
{
    //     void Minimize( const LinearExpr& expr );
    LinearExpr linearExpr;
    if ( info.Length() == 1 && GLinearExpr::ToLinearExpr( info[ 0 ], linearExpr ) )
    {
        pCpModelBuilder->Minimize( linearExpr );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::Minimize : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GCpModelBuilder::AddAllowedAssignments( const Napi::CallbackInfo& info )
{
    //     TableConstraint AddAllowedAssignments( absl::Span< const IntVar > vars );
    if ( info.Length() == 1 && info[ 0 ].IsArray() )
    {
        auto                  arr = info[ 0 ].As< Napi::Array >();
        std::vector< IntVar > vars;
        for ( int i = 0; i < arr.Length(); i++ )
        {
            if ( arr.Get( i ).IsObject()
                 && arr.Get( i ).As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
            {
                auto gintvar = GIntVar::Unwrap( arr.Get( i ).As< Napi::Object >() );
                vars.push_back( *gintvar->pIntVar );
                continue;
            }

            ThrowJsError( operations_research::sat::GCpModelBuilder::AddAllowedAssignments : Invalid argument111 );
            return info.Env().Undefined();
        }

        auto constraint = pCpModelBuilder->AddAllowedAssignments( vars );
        return GConstraint::FromExternal( new Constraint( constraint ) );
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::AddAllowedAssignments : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GCpModelBuilder::AddEquality( const Napi::CallbackInfo& info )
{
    //     Constraint AddEquality( const LinearExpr& left, const LinearExpr& right );
    LinearExpr left, right;
    if ( info.Length() == 2 && GLinearExpr::ToLinearExpr( info[ 0 ], left ) && GLinearExpr::ToLinearExpr( info[ 1 ], right ) )
    {
        auto constraint = pCpModelBuilder->AddEquality( left, right );
        return GConstraint::FromExternal( new Constraint( constraint ) );
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::AddEquality : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GCpModelBuilder::AddExactlyOne( const Napi::CallbackInfo& info )
{
    //     Constraint AddExactlyOne( absl::Span< const BoolVar > literals );
    if ( info.Length() == 1 && info[ 0 ].IsArray() )
    {
        auto                   arr = info[ 0 ].As< Napi::Array >();
        std::vector< BoolVar > literals;
        for ( int i = 0; i < arr.Length(); i++ )
        {
            if ( arr.Get( i ).IsObject()
                 && arr.Get( i ).As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
            {
                auto gboolvar = GBoolVar::Unwrap( arr.Get( i ).As< Napi::Object >() );
                literals.push_back( *gboolvar->pBoolVar );
            }
        }
        auto constraint = pCpModelBuilder->AddExactlyOne( literals );
        return GConstraint::FromExternal( new Constraint( constraint ) );
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::AddExactlyOne : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GCpModelBuilder::NewBoolVar( const Napi::CallbackInfo& info )
{
    //     BoolVar NewBoolVar();
    if ( info.Length() == 0 )
    {
        auto expr     = pCpModelBuilder->NewBoolVar();
        auto external = Napi::External< BoolVar >::New( info.Env(), new BoolVar( expr ) );
        return GBoolVar::constructor.New( { external } );
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::NewBoolVar : Invalid argument );
    return info.Env().Undefined();
}

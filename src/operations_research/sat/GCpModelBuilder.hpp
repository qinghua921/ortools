#pragma once

#include <napi.h>
#include "../../commonheader.hpp"
#include "ortools/sat/cp_model.h"
#include "GBoolVar.hpp"
#include "GConstraint.hpp"
#include "GLinearExpr.hpp"
#include "GCpModelProto.hpp"
#include "GTableConstraint.hpp"
#include "../GDomain.hpp"

namespace operations_research
{
namespace sat
{
    class GCpModelBuilder : public Napi::ObjectWrap< GCpModelBuilder >
    {
    public:
        static Napi::FunctionReference constructor;
        CpModelBuilder*                pCpModelBuilder = nullptr;
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
    };
};  // namespace sat
};  // namespace operations_research

Napi::FunctionReference operations_research::sat::GCpModelBuilder::constructor;

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

        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "CpModelBuilder" ), func );
    return exports;
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
        auto external   = Napi::External< Constraint >::New( info.Env(), new Constraint( constraint ) );
        return GConstraint::constructor.New( { external } );
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
        auto external   = Napi::External< Constraint >::New( info.Env(), new Constraint( constraint ) );
        return GConstraint::constructor.New( { external } );
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
        auto external   = Napi::External< Constraint >::New( info.Env(), new Constraint( constraint ) );
        return GConstraint::constructor.New( { external } );
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
    if ( info.Length() == 1 && info[ 0 ].IsObject() && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        auto glinearexpr = GLinearExpr::Unwrap( info[ 0 ].As< Napi::Object >() );
        pCpModelBuilder->Minimize( *glinearexpr->pLinearExpr );
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
        auto external   = Napi::External< Constraint >::New( info.Env(), new Constraint( constraint ) );
        return GTableConstraint::constructor.New( { external } );
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
        auto external   = Napi::External< Constraint >::New( info.Env(), new Constraint( constraint ) );
        return GConstraint::constructor.New( { external } );
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
        auto external   = Napi::External< Constraint >::New( info.Env(), new Constraint( constraint ) );
        return GConstraint::constructor.New( { external } );
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

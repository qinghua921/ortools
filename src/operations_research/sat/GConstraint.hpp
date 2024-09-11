#pragma once

#include "commonheader.hpp"
#include "ortools/sat/cp_model.h"
#include "GBoolVar.hpp"
#include "GConstraint.hpp"

namespace operations_research
{
namespace sat
{
    class GConstraint : public Napi::ObjectWrap< GConstraint >
    {
    public:
        static inline Napi::FunctionReference constructor;
        std::shared_ptr< Constraint >         shared_ptr;
        GConstraint( const Napi::CallbackInfo& info );
        static Napi::Object Init( Napi::Env env, Napi::Object exports );

        Napi::Value OnlyEnforceIf( const Napi::CallbackInfo& info );
    };
};  // namespace sat
};  // namespace operations_research

inline operations_research::sat::GConstraint::GConstraint( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GConstraint >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< Constraint > >();
        shared_ptr    = std::shared_ptr< Constraint >( external.Data());
        return;
    }

    ThrowJsError( operations_research::GConstraint::GConstraint : Invalid argument );
}

inline Napi::Object operations_research::sat::GConstraint::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "Constraint",
        {
            InstanceMethod( "OnlyEnforceIf", &GConstraint::OnlyEnforceIf ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "Constraint" ), func );
    return exports;
}

inline Napi::Value operations_research::sat::GConstraint::OnlyEnforceIf( const Napi::CallbackInfo& info )
{
    //     Constraint OnlyEnforceIf( BoolVar literal );
    if ( info.Length() == 1 && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        GBoolVar*  pLiteral   = Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 0 ].As< Napi::Object >() );
        Constraint constraint = shared_ptr->OnlyEnforceIf( *pLiteral->pBoolVar );
        auto       external   = Napi::External< Constraint >::New( info.Env(), new Constraint( constraint ) );
        return GConstraint::constructor.New( { external } );
    }

    //     Constraint OnlyEnforceIf( absl::Span< const BoolVar > literals );
    if ( info.Length() == 1 && info[ 0 ].IsArray() )
    {
        auto                   array = info[ 0 ].As< Napi::Array >();
        std::vector< BoolVar > literals;
        for ( auto i = 0; i < array.Length(); i++ )
        {
            auto arrayElement = array.Get( i );
            if ( arrayElement.IsObject() && arrayElement.As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
            {
                GBoolVar* pLiteral = Napi::ObjectWrap< GBoolVar >::Unwrap( arrayElement.As< Napi::Object >() );
                literals.push_back( *pLiteral->pBoolVar );
                continue;
            }

            ThrowJsError( operations_research::GConstraint::OnlyEnforceIf : Invalid argument );
            return info.Env().Undefined();
        }

        auto constraint = shared_ptr->OnlyEnforceIf( literals );
        auto external   = Napi::External< Constraint >::New( info.Env(), new Constraint( constraint ) );
        return GConstraint::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GConstraint::OnlyEnforceIf : Invalid argument );
    return info.Env().Undefined();
}

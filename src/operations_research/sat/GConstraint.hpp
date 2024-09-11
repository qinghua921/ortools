#pragma once

#include "commonheader.hpp"
#include "ortools/sat/cp_model.h"
#include "GBoolVar.hpp"
#include "GConstraint.hpp"

namespace operations_research
{
namespace sat
{
    WrapOrToolsClass(
        Constraint,
        WrapOrToolsMethod( OnlyEnforceIf ); );
};  // namespace sat
};  // namespace operations_research

inline operations_research::sat::GConstraint::GConstraint( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GConstraint >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< Constraint > >();
        shared_ptr    = std::shared_ptr< Constraint >( external.Data() );
        return;
    }

    ThrowJsError( operations_research::GConstraint::GConstraint : Invalid argument );
}

inline void operations_research::sat::GConstraint::Init( Napi::Env env, Napi::Object exports )
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
}

inline Napi::Value operations_research::sat::GConstraint::OnlyEnforceIf( const Napi::CallbackInfo& info )
{
    //     Constraint OnlyEnforceIf( BoolVar literal );
    if ( info.Length() == 1 && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        GBoolVar*  pLiteral   = Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 0 ].As< Napi::Object >() );
        Constraint constraint = shared_ptr->OnlyEnforceIf( *pLiteral->shared_ptr );
        return GConstraint::FromExternal( new Constraint( constraint ) );
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
                literals.push_back( *pLiteral->shared_ptr );
                continue;
            }

            ThrowJsError( operations_research::GConstraint::OnlyEnforceIf : Invalid argument );
            return info.Env().Undefined();
        }

        auto constraint = shared_ptr->OnlyEnforceIf( literals );
        return GConstraint::FromExternal( new Constraint( constraint ) );
    }

    ThrowJsError( operations_research::GConstraint::OnlyEnforceIf : Invalid argument );
    return info.Env().Undefined();
}

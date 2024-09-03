#pragma once

#include <napi.h>
#include "../commonheader.hpp"
#include "ortools/linear_solver/linear_solver.h"
#include "GLinearRange.hpp"
#include "GLinearExpr.hpp"
#include "GMPVariable.hpp"

namespace operations_research
{

static Napi::Object GFuncInit( Napi::Env env, Napi::Object exports );
Napi::Value         operator_equals( const Napi::CallbackInfo& info );
Napi::Value         operator_greater_equals( const Napi::CallbackInfo& info );
Napi::Value         operator_less_equals( const Napi::CallbackInfo& info );
};  // namespace operations_research

inline Napi::Object operations_research::GFuncInit( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );

    exports.Set( Napi::String::New( env, "operator_equals" ), Napi::Function::New( env, operator_equals ) );
    exports.Set( Napi::String::New( env, "operator_greater_equals" ), Napi::Function::New( env, operator_greater_equals ) );
    exports.Set( Napi::String::New( env, "operator_less_equals" ), Napi::Function::New( env, operator_less_equals ) );

    return exports;
}

Napi::Value operations_research::operator_equals( const Napi::CallbackInfo& info )
{
    // LinearRange operator==( const LinearExpr& lhs, const LinearExpr& rhs );
    if ( info.Length() != 2 )
    {
        ThrowJsError( operations_research::operator_equals : Invalid arguments );
        return info.Env().Undefined();
    }

    LinearExpr lhs;
    if ( !GLinearExpr::ToLinearExpr( info[ 0 ], lhs ) )
    {
        ThrowJsError( operations_research::operator_equals : Invalid arguments );
        return info.Env().Undefined();
    }

    LinearExpr rhs;
    if ( !GLinearExpr::ToLinearExpr( info[ 1 ], rhs ) )
    {
        ThrowJsError( operations_research::operator_equals : Invalid arguments );
        return info.Env().Undefined();
    }

    auto pRange = new LinearRange( lhs == rhs );

    return GLinearRange::constructor.New( { Napi::External< LinearRange >::New( info.Env(), pRange ) } );
}

Napi::Value operations_research::operator_greater_equals( const Napi::CallbackInfo& info )
{
    // LinearRange operator>=( const LinearExpr& lhs, const LinearExpr& rhs );
    if ( info.Length() != 2 )
    {
        ThrowJsError( operations_research::operator_greater_equals : Invalid arguments );
        return info.Env().Undefined();
    }

    LinearExpr lhs;
    if ( !GLinearExpr::ToLinearExpr( info[ 0 ], lhs ) )
    {
        ThrowJsError( operations_research::operator_greater_equals : Invalid arguments );
        return info.Env().Undefined();
    }

    LinearExpr rhs;
    if ( !GLinearExpr::ToLinearExpr( info[ 1 ], rhs ) )
    {
        ThrowJsError( operations_research::operator_greater_equals : Invalid arguments );
        return info.Env().Undefined();
    }

    auto pRange = new LinearRange( lhs >= rhs );

    return GLinearRange::constructor.New( { Napi::External< LinearRange >::New( info.Env(), pRange ) } );
}

inline Napi::Value operations_research::operator_less_equals( const Napi::CallbackInfo& info )
{
    // LinearRange operator<=( const LinearExpr& lhs, const LinearExpr& rhs );
    if ( info.Length() != 2 )
    {
        ThrowJsError( operations_research::operator_less_equals : Invalid arguments );
        return info.Env().Undefined();
    }

    LinearExpr lhs;
    if ( !GLinearExpr::ToLinearExpr( info[ 0 ], lhs ) )
    {
        ThrowJsError( operations_research::operator_less_equals : Invalid arguments );
        return info.Env().Undefined();
    }

    LinearExpr rhs;
    if ( !GLinearExpr::ToLinearExpr( info[ 1 ], rhs ) )
    {
        ThrowJsError( operations_research::operator_less_equals : Invalid arguments );
        return info.Env().Undefined();
    }

    auto pRange = new LinearRange( lhs <= rhs );

    return GLinearRange::constructor.New( { Napi::External< LinearRange >::New( info.Env(), pRange ) } );
}

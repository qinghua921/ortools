#pragma once

#include "napi.h"
#include "LinearExpr.hpp"
#include "LinearRange.hpp"

namespace operations_research
{
// LinearRange operator>=( const LinearExpr& lhs, const LinearExpr& rhs );
Napi::Value operator_ge( const Napi::CallbackInfo& info )
{
    Napi::Env         env = info.Env();
    Napi::HandleScope scope( env );

    LinearExpr lhs, rhs;
    if ( info.Length() == 2
         && GLinearExpr::ToLinearExpr( info[ 0 ], lhs )
         && GLinearExpr::ToLinearExpr( info[ 1 ], rhs ) )
    {
        auto result   = lhs >= rhs;
        auto external = Napi::External< LinearRange >::New( env, new LinearRange( result ) );
        return GLinearRange::constructor.New( { external } );
    }

    Napi::TypeError::New( env, "operations_research::operator_ge : Invalid arguments" ).ThrowAsJavaScriptException();
    return env.Null();
};

// LinearRange operator==( const LinearExpr& lhs, const LinearExpr& rhs );
Napi::Value operator_eq( const Napi::CallbackInfo& info )
{
    Napi::Env         env = info.Env();
    Napi::HandleScope scope( env );

    LinearExpr lhs, rhs;
    if ( info.Length() == 2
         && GLinearExpr::ToLinearExpr( info[ 0 ], lhs )
         && GLinearExpr::ToLinearExpr( info[ 1 ], rhs ) )
    {
        auto result   = lhs == rhs;
        auto external = Napi::External< LinearRange >::New( env, new LinearRange( result ) );
        return GLinearRange::constructor.New( { external } );
    }

    Napi::TypeError::New( env, "operations_research::operator_eq : Invalid arguments" ).ThrowAsJavaScriptException();
    return env.Null();
};

// LinearRange operator<=( const LinearExpr& lhs, const LinearExpr& rhs );
Napi::Value operator_le( const Napi::CallbackInfo& info )
{
    Napi::Env         env = info.Env();
    Napi::HandleScope scope( env );

    LinearExpr lhs, rhs;
    if ( info.Length() == 2
         && GLinearExpr::ToLinearExpr( info[ 0 ], lhs )
         && GLinearExpr::ToLinearExpr( info[ 1 ], rhs ) )
    {
        auto result   = lhs <= rhs;
        auto external = Napi::External< LinearRange >::New( env, new LinearRange( result ) );
        return GLinearRange::constructor.New( { external } );
    }

    Napi::TypeError::New( env, "operations_research::operator_le : Invalid arguments" ).ThrowAsJavaScriptException();
    return env.Null();
};

static Napi::Object FuncInit( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );

    exports.Set( "operator_ge", Napi::Function::New( env, operator_ge ) );
    exports.Set( "operator_eq", Napi::Function::New( env, operator_eq ) );
    exports.Set( "operator_le", Napi::Function::New( env, operator_le ) );

    return exports;
};

};  // namespace operations_research
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

Napi::Value operator_times( const Napi::CallbackInfo& info )
{
    Napi::Env         env = info.Env();
    Napi::HandleScope scope( env );

    // LinearExpr operator*( LinearExpr lhs, double rhs );
    LinearExpr lhs;
    if ( info.Length() == 2
         && GLinearExpr::ToLinearExpr( info[ 0 ], lhs )
         && info[ 1 ].IsNumber() )
    {
        double rhs    = info[ 1 ].As< Napi::Number >().DoubleValue();
        auto   result = lhs * rhs;
        return GLinearExpr::constructor.New( { Napi::External< LinearExpr >::New( env, new LinearExpr( result ) ) } );
    }

    // LinearExpr operator*( double lhs, LinearExpr rhs );
    LinearExpr rhs;
    if ( info.Length() == 2
         && info[ 0 ].IsNumber()
         && GLinearExpr::ToLinearExpr( info[ 1 ], rhs ) )
    {
        double lhs    = info[ 0 ].As< Napi::Number >().DoubleValue();
        auto   result = lhs * rhs;
        return GLinearExpr::constructor.New( { Napi::External< LinearExpr >::New( env, new LinearExpr( result ) ) } );
    }

    Napi::TypeError::New( env, "operations_research::operator_times : Invalid arguments" ).ThrowAsJavaScriptException();
    return env.Null();
};

static Napi::Object FuncInit( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );

    exports.Set( "operator_ge", Napi::Function::New( env, operator_ge ) );
    exports.Set( "operator_eq", Napi::Function::New( env, operator_eq ) );
    exports.Set( "operator_le", Napi::Function::New( env, operator_le ) );
    exports.Set( "operator_times", Napi::Function::New( env, operator_times ) );

    return exports;
};

};  // namespace operations_research
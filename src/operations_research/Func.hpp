#pragma once

#include "napi.h"
#include "LinearExpr.hpp"

namespace operations_research
{

// LinearRange operator == ( const LinearExpr& lhs, const LinearExpr& rhs );
Napi::Value operator_equals( const Napi::CallbackInfo& info )
{
    Napi::Env         env = info.Env();
    Napi::HandleScope scope( env );

    LinearExpr lhs, rhs;
    if ( info.Length() == 2 && GLinearExpr::ToLinearExpr( info[ 0 ], lhs ) && GLinearExpr::ToLinearExpr( info[ 1 ], rhs ) )
    {
        auto result = lhs == rhs;
        auto ext    = Napi::External< LinearRange >::New( env, new LinearRange( result ) );
        return GLinearExpr::constructor.New( { ext } );
    }

    Napi::TypeError::New( env, "operations_research::operator_equals : Invalid arguments" ).ThrowAsJavaScriptException();
    return env.Null();
}

// LinearRange operator <= ( const LinearExpr& lhs, const LinearExpr& rhs );
Napi::Value operator_less_equals( const Napi::CallbackInfo& info )
{
    Napi::Env         env = info.Env();
    Napi::HandleScope scope( env );

    LinearExpr lhs, rhs;
    if ( info.Length() == 2 && GLinearExpr::ToLinearExpr( info[ 0 ], lhs ) && GLinearExpr::ToLinearExpr( info[ 1 ], rhs ) )
    {
        auto result = lhs <= rhs;
        auto ext    = Napi::External< LinearRange >::New( env, new LinearRange( result ) );
        return GLinearExpr::constructor.New( { ext } );
    }

    Napi::TypeError::New( env, "operations_research::operator_less_equals : Invalid arguments" ).ThrowAsJavaScriptException();
    return env.Null();
};

static Napi::Object FuncInit( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );

    exports.Set( "operator_less_equals", Napi::Function::New( env, operator_less_equals ) );
    exports.Set( "operator_equals", Napi::Function::New( env, operator_equals ) );

    return exports;
};

};  // namespace operations_research
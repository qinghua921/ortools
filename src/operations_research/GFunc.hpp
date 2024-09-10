#pragma once

#include <napi.h>
#include "commonheader.hpp"
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
Napi::Value         operator_plus( const Napi::CallbackInfo& info );
Napi::Value         operator_minus( const Napi::CallbackInfo& info );
Napi::Value         operator_times( const Napi::CallbackInfo& info );
Napi::Value         operator_divide( const Napi::CallbackInfo& info );

};  // namespace operations_research

inline Napi::Object operations_research::GFuncInit( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );

    exports.Set( Napi::String::New( env, "operator_equals" ), Napi::Function::New( env, operator_equals ) );
    exports.Set( Napi::String::New( env, "operator_greater_equals" ), Napi::Function::New( env, operator_greater_equals ) );
    exports.Set( Napi::String::New( env, "operator_less_equals" ), Napi::Function::New( env, operator_less_equals ) );
    exports.Set( Napi::String::New( env, "operator_plus" ), Napi::Function::New( env, operator_plus ) );
    exports.Set( Napi::String::New( env, "operator_minus" ), Napi::Function::New( env, operator_minus ) );
    exports.Set( Napi::String::New( env, "operator_times" ), Napi::Function::New( env, operator_times ) );
    exports.Set( Napi::String::New( env, "operator_divide" ), Napi::Function::New( env, operator_divide ) );

    return exports;
}

inline Napi::Value operations_research::operator_plus( const Napi::CallbackInfo& info )
{
    // LinearExpr operator+(LinearExpr lhs, const LinearExpr& rhs);
    LinearExpr lhs, rhs;
    if ( info.Length() == 2
         && GLinearExpr::ToLinearExpr( info[ 0 ], lhs )
         && GLinearExpr::ToLinearExpr( info[ 1 ], rhs ) )
    {
        auto pExpr = new LinearExpr( lhs + rhs );
        return GLinearExpr::constructor.New( { Napi::External< LinearExpr >::New( info.Env(), pExpr ) } );
    }

    ThrowJsError( operations_research::operator_plus : Invalid arguments );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::operator_minus( const Napi::CallbackInfo& info )
{
    // LinearExpr operator-(LinearExpr lhs, const LinearExpr& rhs);
    LinearExpr lhs, rhs;
    if ( info.Length() == 2
         && GLinearExpr::ToLinearExpr( info[ 0 ], lhs )
         && GLinearExpr::ToLinearExpr( info[ 1 ], rhs ) )
    {
        auto pExpr = new LinearExpr( lhs - rhs );
        return GLinearExpr::constructor.New( { Napi::External< LinearExpr >::New( info.Env(), pExpr ) } );
    }

    ThrowJsError( operations_research::operator_minus : Invalid arguments );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::operator_times( const Napi::CallbackInfo& info )
{
    // LinearExpr operator*(LinearExpr lhs, double rhs);
    LinearExpr linearExpr;
    if ( info.Length() == 2
         && info[ 1 ].IsNumber()
         && GLinearExpr::ToLinearExpr( info[ 0 ], linearExpr ) )
    {
        auto rhs   = info[ 1 ].As< Napi::Number >().DoubleValue();
        auto pExpr = new LinearExpr( linearExpr * rhs );
        return GLinearExpr::constructor.New( { Napi::External< LinearExpr >::New( info.Env(), pExpr ) } );
    }

    // LinearExpr operator*(double lhs, LinearExpr rhs);
    if ( info.Length() == 2
         && info[ 0 ].IsNumber()
         && GLinearExpr::ToLinearExpr( info[ 1 ], linearExpr ) )
    {
        auto lhs   = info[ 0 ].As< Napi::Number >().DoubleValue();
        auto pExpr = new LinearExpr( lhs * linearExpr );
        return GLinearExpr::constructor.New( { Napi::External< LinearExpr >::New( info.Env(), pExpr ) } );
    }

    ThrowJsError( operations_research::operator_times : Invalid arguments );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::operator_divide( const Napi::CallbackInfo& info )
{
    // LinearExpr operator/(LinearExpr lhs, double rhs);
    if ( info.Length() == 2
         && info[ 1 ].IsNumber()
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        auto lhs   = GLinearExpr::Unwrap( info[ 0 ].As< Napi::Object >() );
        auto rhs   = info[ 1 ].As< Napi::Number >().DoubleValue();
        auto pExpr = new LinearExpr( *lhs->pLinearExpr / rhs );  // lhs / rhs
        return GLinearExpr::constructor.New( { Napi::External< LinearExpr >::New( info.Env(), pExpr ) } );
    }

    ThrowJsError( operations_research::operator_divide : Invalid arguments );
    return info.Env().Undefined();
}

Napi::Value operations_research::operator_equals( const Napi::CallbackInfo& info )
{
    // LinearRange operator==( const LinearExpr& lhs, const LinearExpr& rhs );
    LinearExpr lhs, rhs;
    if ( info.Length() == 2
         && GLinearExpr::ToLinearExpr( info[ 0 ], lhs )
         && GLinearExpr::ToLinearExpr( info[ 1 ], rhs ) )
    {
        auto pRange = new LinearRange( lhs == rhs );
        return GLinearRange::constructor.New( { Napi::External< LinearRange >::New( info.Env(), pRange ) } );
    }

    ThrowJsError( operations_research::operator_equals : Invalid arguments );
    return info.Env().Undefined();
}

Napi::Value operations_research::operator_greater_equals( const Napi::CallbackInfo& info )
{
    // LinearRange operator>=( const LinearExpr& lhs, const LinearExpr& rhs );
    LinearExpr lhs, rhs;
    if ( info.Length() == 2
         && GLinearExpr::ToLinearExpr( info[ 0 ], lhs )
         && GLinearExpr::ToLinearExpr( info[ 1 ], rhs ) )
    {
        auto pRange = new LinearRange( lhs >= rhs );
        return GLinearRange::constructor.New( { Napi::External< LinearRange >::New( info.Env(), pRange ) } );
    }

    ThrowJsError( operations_research::operator_greater_equals : Invalid arguments );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::operator_less_equals( const Napi::CallbackInfo& info )
{
    // LinearRange operator<=( const LinearExpr& lhs, const LinearExpr& rhs );
    LinearExpr lhs, rhs;
    if ( info.Length() == 2
         && GLinearExpr::ToLinearExpr( info[ 0 ], lhs )
         && GLinearExpr::ToLinearExpr( info[ 1 ], rhs ) )
    {
        auto pRange = new LinearRange( lhs <= rhs );
        return GLinearRange::constructor.New( { Napi::External< LinearRange >::New( info.Env(), pRange ) } );
    }

    ThrowJsError( operations_research::operator_less_equals : Invalid arguments );
    return info.Env().Undefined();
}

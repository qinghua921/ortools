#pragma once

#include <napi.h>
#include "GLinearExpr.hpp"
#include "../../commonheader.hpp"

namespace operations_research
{
namespace sat
{

    static Napi::Object GFuncInit( Napi::Env env, Napi::Object exports );

    Napi::Value operator_negate( const Napi::CallbackInfo& info );
    Napi::Value operator_plus( const Napi::CallbackInfo& info );
    Napi::Value operator_minus( const Napi::CallbackInfo& info );
    Napi::Value operator_times( const Napi::CallbackInfo& info );

};  // namespace sat
};  // namespace operations_research

inline Napi::Object operations_research::sat::GFuncInit( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );

    exports.Set( Napi::String::New( env, "operator_negate" ), Napi::Function::New( env, operator_negate ) );
    exports.Set( Napi::String::New( env, "operator_plus" ), Napi::Function::New( env, operator_plus ) );
    exports.Set( Napi::String::New( env, "operator_minus" ), Napi::Function::New( env, operator_minus ) );
    exports.Set( Napi::String::New( env, "operator_times" ), Napi::Function::New( env, operator_times ) );

    return exports;
}

Napi::Value operations_research::sat::operator_negate( const Napi::CallbackInfo& info )
{
    // inline LinearExpr operator-( LinearExpr expr )
    LinearExpr expr;
    if ( info.Length() == 1 && GLinearExpr::ToLinearExpr( info[ 0 ], expr ) )
    {
        auto result   = -expr;
        auto exterior = Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) );
        return GLinearExpr::constructor.New( { exterior } );
    }

    ThrowJsError( operations_research::sat::operator_negate : Invalid arguments );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::operator_plus( const Napi::CallbackInfo& info )
{
    // inline LinearExpr operator+( const LinearExpr& lhs, const LinearExpr& rhs )
    LinearExpr lhs;
    LinearExpr rhs;
    if ( info.Length() == 2
         && GLinearExpr::ToLinearExpr( info[ 0 ], lhs )
         && GLinearExpr::ToLinearExpr( info[ 1 ], rhs ) )
    {
        auto result   = lhs + rhs;
        auto exterior = Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) );
        return GLinearExpr::constructor.New( { exterior } );
    }

    ThrowJsError( operations_research::sat::operator_plus : Invalid arguments );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::operator_minus( const Napi::CallbackInfo& info )
{
    // inline LinearExpr operator-( const LinearExpr& lhs, const LinearExpr& rhs )
    LinearExpr lhs;
    LinearExpr rhs;
    if ( info.Length() == 2
         && GLinearExpr::ToLinearExpr( info[ 0 ], lhs )
         && GLinearExpr::ToLinearExpr( info[ 1 ], rhs ) )
    {
        auto result   = lhs - rhs;
        auto exterior = Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) );
        return GLinearExpr::constructor.New( { exterior } );
    }

    ThrowJsError( operations_research::sat::operator_minus : Invalid arguments );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::operator_times( const Napi::CallbackInfo& info )
{
    // inline LinearExpr operator*( LinearExpr expr, int64_t factor )
    if ( info.Length() == 2 && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() )
         && info[ 1 ].IsNumber() )
    {
        GLinearExpr* expr     = GLinearExpr::Unwrap( info[ 0 ].As< Napi::Object >() );
        int64_t      factor   = info[ 1 ].As< Napi::Number >().Int64Value();
        auto         result   = *expr->pLinearExpr * factor;
        auto         exterior = Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) );
        return GLinearExpr::constructor.New( { exterior } );
    }

    // inline LinearExpr operator*( int64_t factor, LinearExpr expr )
    if ( info.Length() == 2 && info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() )
         && info[ 0 ].IsNumber() )
    {
        GLinearExpr* expr     = GLinearExpr::Unwrap( info[ 1 ].As< Napi::Object >() );
        int64_t      factor   = info[ 0 ].As< Napi::Number >().Int64Value();
        auto         result   = *expr->pLinearExpr * factor;
        auto         exterior = Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) );
        return GLinearExpr::constructor.New( { exterior } );
    }

    ThrowJsError( operations_research::sat::operator_times : Invalid arguments );
    return info.Env().Undefined();
}

// inline DoubleLinearExpr operator-( DoubleLinearExpr expr )
// inline DoubleLinearExpr operator+( const DoubleLinearExpr& lhs, const DoubleLinearExpr& rhs )
// inline DoubleLinearExpr operator+( DoubleLinearExpr&&      lhs, const DoubleLinearExpr& rhs )
// inline DoubleLinearExpr operator+( const DoubleLinearExpr& lhs, DoubleLinearExpr&&      rhs )
// inline DoubleLinearExpr operator+( DoubleLinearExpr&& lhs, DoubleLinearExpr&& rhs )
// inline DoubleLinearExpr operator+( DoubleLinearExpr expr, double rhs )
// inline DoubleLinearExpr operator+( double lhs, DoubleLinearExpr expr )
// inline DoubleLinearExpr operator-( const DoubleLinearExpr& lhs, const DoubleLinearExpr& rhs )
// inline DoubleLinearExpr operator-( DoubleLinearExpr&&      lhs, const DoubleLinearExpr& rhs )
// inline DoubleLinearExpr operator-( const DoubleLinearExpr& lhs, DoubleLinearExpr&&      rhs )
// inline DoubleLinearExpr operator-( DoubleLinearExpr&& lhs, DoubleLinearExpr&& rhs )
// inline DoubleLinearExpr operator-( DoubleLinearExpr epxr, double rhs )
// inline DoubleLinearExpr operator-( double lhs, DoubleLinearExpr expr )
// inline DoubleLinearExpr operator*( DoubleLinearExpr expr, double factor )
// inline DoubleLinearExpr operator*( double factor, DoubleLinearExpr expr )

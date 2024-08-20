#pragma once

#include <napi.h>
#include "GLinearExpr.hpp"
#include "GLinearRange.hpp"
#include "../commonheader.hpp"

namespace operations_research
{

// LinearRange operator<=( const LinearExpr& lhs, const LinearExpr& rhs );
Napi::Value Goperator_LEQ( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 2 && info[ 0 ].IsObject() && info[ 1 ].IsObject() )
    {
        GLinearExpr* pLhs = GLinearExpr::Unwrap( info[ 0 ].As< Napi::Object >() );
        GLinearExpr* pRhs = GLinearExpr::Unwrap( info[ 1 ].As< Napi::Object >() );

        if ( typeid( *pLhs ) == typeid( GLinearExpr ) && typeid( *pRhs ) == typeid( GLinearExpr ) )
        {
            LinearRange result     = ( *pLhs->pLinearExpr ) <= ( *pRhs->pLinearExpr );
            auto        pResult    = new LinearRange( result );
            auto        asExternal = Napi::External< LinearRange >::New( info.Env(), pResult );
            return GLinearRange::constructor.New( { asExternal } );
        }

        ThrowJsError( Goperator_LEQ Error );
        return info.Env().Undefined();
    }
}

// LinearRange operator==( const LinearExpr& lhs, const LinearExpr& rhs );
Napi::Value Goperator_EQ( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 2 && info[ 0 ].IsObject() && info[ 1 ].IsObject() )
    {
        GLinearExpr* pLhs = GLinearExpr::Unwrap( info[ 0 ].As< Napi::Object >() );
        GLinearExpr* pRhs = GLinearExpr::Unwrap( info[ 1 ].As< Napi::Object >() );

        if ( typeid( *pLhs ) == typeid( GLinearExpr ) && typeid( *pRhs ) == typeid( GLinearExpr ) )
        {
            LinearRange result     = ( *pLhs->pLinearExpr ) == ( *pRhs->pLinearExpr );
            auto        pResult    = new LinearRange( result );
            auto        asExternal = Napi::External< LinearRange >::New( info.Env(), pResult );
            return GLinearRange::constructor.New( { asExternal } );
        }

        ThrowJsError( Goperator_EQ Error );
        return info.Env().Undefined();
    }
}

// LinearRange operator>=( const LinearExpr& lhs, const LinearExpr& rhs );
Napi::Value Goperator_GEQ( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 2 && info[ 0 ].IsObject() && info[ 1 ].IsObject() )
    {
        GLinearExpr* pLhs = GLinearExpr::Unwrap( info[ 0 ].As< Napi::Object >() );
        GLinearExpr* pRhs = GLinearExpr::Unwrap( info[ 1 ].As< Napi::Object >() );

        if ( typeid( *pLhs ) == typeid( GLinearExpr ) && typeid( *pRhs ) == typeid( GLinearExpr ) )
        {
            LinearRange result     = ( *pLhs->pLinearExpr ) >= ( *pRhs->pLinearExpr );
            auto        pResult    = new LinearRange( result );
            auto        asExternal = Napi::External< LinearRange >::New( info.Env(), pResult );
            return GLinearRange::constructor.New( { asExternal } );
        }

        ThrowJsError( Goperator_GEQ Error );
        return info.Env().Undefined();
    }
}

Napi::Object FuncInit( Napi::Env env, Napi::Object exports )
{
    exports.Set( "operator_LEQ", Napi::Function::New( env, Goperator_LEQ ) );
    exports.Set( "operator_EQ", Napi::Function::New( env, Goperator_EQ ) );
    exports.Set( "operator_GEQ", Napi::Function::New( env, Goperator_GEQ ) );

    return exports;
}

}  // namespace operations_research

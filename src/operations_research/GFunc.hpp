#pragma once

#include <napi.h>
#include "GLinearExpr.hpp"
#include "GLinearRange.hpp"
#include "../commonheader.hpp"
#include "GMPVariable.hpp"

namespace operations_research
{

// LinearRange operator<=( const LinearExpr& lhs, const LinearExpr& rhs );
Napi::Value Goperator_LEQ( const Napi::CallbackInfo& info )
{
    if ( info.Length() != 2 )
    {
        ThrowJsError( Goperator_LEQ Error );
        return info.Env().Undefined();
    }

    LinearExpr pLhs;
    bool       lhsIsOK = false;
    if ( info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        pLhs    = *GLinearExpr::Unwrap( info[ 0 ].As< Napi::Object >() )->pLinearExpr;
        lhsIsOK = true;
    }
    else if ( info[ 0 ].IsObject()
              && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        pLhs    = LinearExpr( GMPVariable::Unwrap( info[ 0 ].As< Napi::Object >() )->pMPVariable );
        lhsIsOK = true;
    }
    else if ( info[ 0 ].IsNumber() )
    {
        pLhs    = LinearExpr( info[ 0 ].As< Napi::Number >().DoubleValue() );
        lhsIsOK = true;
    }

    LinearExpr pRhs;
    bool       rhsIsOK = false;
    if ( info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        pRhs    = *GLinearExpr::Unwrap( info[ 1 ].As< Napi::Object >() )->pLinearExpr;
        rhsIsOK = true;
    }
    else if ( info[ 1 ].IsObject()
              && info[ 1 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        pRhs    = LinearExpr( GMPVariable::Unwrap( info[ 1 ].As< Napi::Object >() )->pMPVariable );
        rhsIsOK = true;
    }
    else if ( info[ 1 ].IsNumber() )
    {
        pRhs    = LinearExpr( info[ 1 ].As< Napi::Number >().DoubleValue() );
        rhsIsOK = true;
    }

    if ( lhsIsOK && rhsIsOK )
    {
        LinearRange result     = ( pLhs ) <= ( pRhs );
        auto        pResult    = new LinearRange( result );
        auto        asExternal = Napi::External< LinearRange >::New( info.Env(), pResult );
        return GLinearRange::constructor.New( { asExternal } );
    }

    ThrowJsError( Goperator_LEQ Error );
    return info.Env().Undefined();
}

// LinearRange operator==( const LinearExpr& lhs, const LinearExpr& rhs );
Napi::Value Goperator_EQ( const Napi::CallbackInfo& info )
{
    if ( info.Length() != 2 )
    {
        ThrowJsError( Goperator_EQ Error );
        return info.Env().Undefined();
    }

    LinearExpr pLhs;
    bool       lhsIsOK = false;
    if ( info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        pLhs    = *GLinearExpr::Unwrap( info[ 0 ].As< Napi::Object >() )->pLinearExpr;
        lhsIsOK = true;
    }
    else if ( info[ 0 ].IsObject()
              && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        pLhs    = LinearExpr( GMPVariable::Unwrap( info[ 0 ].As< Napi::Object >() )->pMPVariable );
        lhsIsOK = true;
    }
    else if ( info[ 0 ].IsNumber() )
    {
        pLhs    = LinearExpr( info[ 0 ].As< Napi::Number >().DoubleValue() );
        lhsIsOK = true;
    }

    LinearExpr pRhs;
    bool       rhsIsOK = false;
    if ( info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        pRhs    = *GLinearExpr::Unwrap( info[ 1 ].As< Napi::Object >() )->pLinearExpr;
        rhsIsOK = true;
    }
    else if ( info[ 1 ].IsObject()
              && info[ 1 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        pRhs    = LinearExpr( GMPVariable::Unwrap( info[ 1 ].As< Napi::Object >() )->pMPVariable );
        rhsIsOK = true;
    }
    else if ( info[ 1 ].IsNumber() )
    {
        pRhs    = LinearExpr( info[ 1 ].As< Napi::Number >().DoubleValue() );
        rhsIsOK = true;
    }

    if ( lhsIsOK && rhsIsOK )
    {
        LinearRange result     = ( pLhs ) == ( pRhs );
        auto        pResult    = new LinearRange( result );
        auto        asExternal = Napi::External< LinearRange >::New( info.Env(), pResult );
        return GLinearRange::constructor.New( { asExternal } );
    }

    ThrowJsError( Goperator_EQ Error );
    return info.Env().Undefined();
}

// LinearRange operator>=( const LinearExpr& lhs, const LinearExpr& rhs );
Napi::Value Goperator_GEQ( const Napi::CallbackInfo& info )
{
    if ( info.Length() != 2 )
    {
        ThrowJsError( Goperator_GEQ Error );
        return info.Env().Undefined();
    }

    LinearExpr pLhs;
    bool       lhsIsOK = false;
    if ( info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        pLhs    = *GLinearExpr::Unwrap( info[ 0 ].As< Napi::Object >() )->pLinearExpr;
        lhsIsOK = true;
    }
    else if ( info[ 0 ].IsObject()
              && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        pLhs    = LinearExpr( GMPVariable::Unwrap( info[ 0 ].As< Napi::Object >() )->pMPVariable );
        lhsIsOK = true;
    }
    else if ( info[ 0 ].IsNumber() )
    {
        pLhs    = LinearExpr( info[ 0 ].As< Napi::Number >().DoubleValue() );
        lhsIsOK = true;
    }

    LinearExpr pRhs;
    bool       rhsIsOK = false;
    if ( info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        pRhs    = *GLinearExpr::Unwrap( info[ 1 ].As< Napi::Object >() )->pLinearExpr;
        rhsIsOK = true;
    }
    else if ( info[ 1 ].IsObject()
              && info[ 1 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        pRhs    = LinearExpr( GMPVariable::Unwrap( info[ 1 ].As< Napi::Object >() )->pMPVariable );
        rhsIsOK = true;
    }
    else if ( info[ 1 ].IsNumber() )
    {
        pRhs    = LinearExpr( info[ 1 ].As< Napi::Number >().DoubleValue() );
        rhsIsOK = true;
    }

    if ( lhsIsOK && rhsIsOK )
    {
        LinearRange result     = ( pLhs ) >= ( pRhs );
        auto        pResult    = new LinearRange( result );
        auto        asExternal = Napi::External< LinearRange >::New( info.Env(), pResult );
        return GLinearRange::constructor.New( { asExternal } );
    }

    ThrowJsError( Goperator_GEQ Error );
    return info.Env().Undefined();
}

Napi::Object FuncInit( Napi::Env env, Napi::Object exports )
{
    exports.Set( "operator_LEQ", Napi::Function::New( env, Goperator_LEQ ) );
    exports.Set( "operator_EQ", Napi::Function::New( env, Goperator_EQ ) );
    exports.Set( "operator_GEQ", Napi::Function::New( env, Goperator_GEQ ) );

    return exports;
}

}  // namespace operations_research

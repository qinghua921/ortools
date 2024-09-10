#pragma once


#include "commonheader.hpp"
#include "ortools/linear_solver/linear_solver.h"
#include "GMPVariable.hpp"

namespace operations_research
{
class GLinearExpr : public Napi::ObjectWrap< GLinearExpr >
{
public:
    static Napi::FunctionReference constructor;
    LinearExpr*                    pLinearExpr = nullptr;
    GLinearExpr( const Napi::CallbackInfo& info );
    ~GLinearExpr();
    static Napi::Object Init( Napi::Env env, Napi::Object exports );

    Napi::Value operator_plus_equals( const Napi::CallbackInfo& info );
    Napi::Value operator_minus_equals( const Napi::CallbackInfo& info );
    Napi::Value operator_times_equals( const Napi::CallbackInfo& info );
    Napi::Value operator_divide_equals( const Napi::CallbackInfo& info );
    Napi::Value operator_negate( const Napi::CallbackInfo& info );

    static bool ToLinearExpr( const Napi::Value& value, LinearExpr& expr );
};
};  // namespace operations_research

Napi::FunctionReference operations_research::GLinearExpr::constructor;

inline operations_research::GLinearExpr::GLinearExpr( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GLinearExpr >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< LinearExpr > >();
        pLinearExpr   = dynamic_cast< LinearExpr* >( external.Data() );
        if ( pLinearExpr != nullptr ) return;
    }

    //     LinearExpr();
    if ( info.Length() == 0 )
    {
        pLinearExpr = new LinearExpr();
        return;
    }

    //     LinearExpr( const MPVariable* var );  // NOLINT
    if ( info.Length() == 1 && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        auto var    = GMPVariable::Unwrap( info[ 0 ].As< Napi::Object >() );
        pLinearExpr = new LinearExpr( var->pMPVariable );
        return;
    }

    //     LinearExpr( double constant );  // NOLINT
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        double constant = info[ 0 ].As< Napi::Number >().DoubleValue();
        pLinearExpr     = new LinearExpr( constant );
        return;
    }

    ThrowJsError( operations_research::GLinearExpr::GLinearExpr : Invalid argument );
}

inline operations_research::GLinearExpr::~GLinearExpr()
{
    delete pLinearExpr;
}

inline Napi::Object operations_research::GLinearExpr::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "LinearExpr",
        {
            InstanceMethod( "operator_plus_equals", &GLinearExpr::operator_plus_equals ),
            InstanceMethod( "operator_minus_equals", &GLinearExpr::operator_minus_equals ),
            InstanceMethod( "operator_times_equals", &GLinearExpr::operator_times_equals ),
            InstanceMethod( "operator_divide_equals", &GLinearExpr::operator_divide_equals ),
            InstanceMethod( "operator_negate", &GLinearExpr::operator_negate ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "LinearExpr" ), func );
    return exports;
}

inline Napi::Value operations_research::GLinearExpr::operator_plus_equals( const Napi::CallbackInfo& info )
{
    //     LinearExpr& operator+=( const LinearExpr& rhs );
    if ( info.Length() == 1 && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( constructor.Value() ) )
    {
        auto rhs = GLinearExpr::Unwrap( info[ 0 ].As< Napi::Object >() );
        *pLinearExpr += *rhs->pLinearExpr;
        return info.This();
    }

    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        double rhs = info[ 0 ].As< Napi::Number >().DoubleValue();
        *pLinearExpr += rhs;
        return info.This();
    }

    if ( info.Length() == 1 && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        auto var = GMPVariable::Unwrap( info[ 0 ].As< Napi::Object >() );
        *pLinearExpr += var->pMPVariable;
        return info.This();
    }

    ThrowJsError( operations_research::GLinearExpr::operator_plus_equals : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GLinearExpr::operator_minus_equals( const Napi::CallbackInfo& info )
{
    //     LinearExpr& operator-=( const LinearExpr& rhs );
    if ( info.Length() == 1 && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( constructor.Value() ) )
    {
        auto rhs = GLinearExpr::Unwrap( info[ 0 ].As< Napi::Object >() );
        *pLinearExpr -= *rhs->pLinearExpr;
        return info.This();
    }

    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        double rhs = info[ 0 ].As< Napi::Number >().DoubleValue();
        *pLinearExpr -= rhs;
        return info.This();
    }

    if ( info.Length() == 1 && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        auto var = GMPVariable::Unwrap( info[ 0 ].As< Napi::Object >() );
        *pLinearExpr -= var->pMPVariable;
        return info.This();
    }

    ThrowJsError( operations_research::GLinearExpr::operator_minus_equals : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GLinearExpr::operator_times_equals( const Napi::CallbackInfo& info )
{
    //     LinearExpr& operator*=( double rhs );
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        double rhs = info[ 0 ].As< Napi::Number >().DoubleValue();
        *pLinearExpr *= rhs;
        return info.This();
    }

    ThrowJsError( operations_research::GLinearExpr::operator_times_equals : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GLinearExpr::operator_divide_equals( const Napi::CallbackInfo& info )
{
    //     LinearExpr& operator/=( double rhs );
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        double rhs = info[ 0 ].As< Napi::Number >().DoubleValue();
        *pLinearExpr /= rhs;
        return info.This();
    }

    ThrowJsError( operations_research::GLinearExpr::operator_divide_equals : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GLinearExpr::operator_negate( const Napi::CallbackInfo& info )
{
    //     LinearExpr  operaxtor-() const;
    if ( info.Length() == 0 )
    {
        LinearExpr* pResult  = new LinearExpr( -( *pLinearExpr ) );
        auto        external = Napi::External< LinearExpr >::New( info.Env(), pResult );
        return GLinearExpr::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GLinearExpr::operator_negate : Invalid argument );
    return info.Env().Undefined();
}

bool operations_research::GLinearExpr::ToLinearExpr( const Napi::Value& value, LinearExpr& expr )
{
    if ( value.IsObject() && value.As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
        expr = *GLinearExpr::Unwrap( value.As< Napi::Object >() )->pLinearExpr;
    else if ( value.IsNumber() )
        expr = value.As< Napi::Number >().DoubleValue();
    else if ( value.IsObject() && value.As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
        expr = GMPVariable::Unwrap( value.As< Napi::Object >() )->pMPVariable;
    else
        return false;

    return true;
}
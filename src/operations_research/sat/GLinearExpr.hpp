#pragma once

#include <napi.h>
#include "../../commonheader.hpp"
#include "ortools/sat/cp_model.h"
#include "GBoolVar.hpp"
#include "GIntVar.hpp"

namespace operations_research
{
namespace sat
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

        static bool ToLinearExpr( const Napi::Value& value, LinearExpr& expr );
    };
};  // namespace sat
};  // namespace operations_research

Napi::FunctionReference operations_research::sat::GLinearExpr::constructor;

inline operations_research::sat::GLinearExpr::GLinearExpr( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GLinearExpr >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< LinearExpr > >();
        pLinearExpr   = dynamic_cast< LinearExpr* >( external.Data() );
        if ( pLinearExpr != nullptr ) return;
    }

    ThrowJsError( operations_research::sat::GLinearExpr::GLinearExpr : Invalid argument );
}

inline operations_research::sat::GLinearExpr::~GLinearExpr()
{
    delete pLinearExpr;
}

inline Napi::Object operations_research::sat::GLinearExpr::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "LinearExpr",
        {
            InstanceMethod( "operator_plus_equals", &GLinearExpr::operator_plus_equals ),
            InstanceMethod( "operator_minus_equals", &GLinearExpr::operator_minus_equals ),
            InstanceMethod( "operator_times_equals", &GLinearExpr::operator_times_equals ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "LinearExpr" ), func );
    return exports;
}

inline Napi::Value operations_research::sat::GLinearExpr::operator_plus_equals( const Napi::CallbackInfo& info )
{
    //       LinearExpr& operator+=( const LinearExpr& other );
    LinearExpr other;
    if ( info.Length() == 1 && ToLinearExpr( info[ 0 ], other ) )
    {
        *pLinearExpr += other;
        return this->Value();
    }

    ThrowJsError( operations_research::sat::GLinearExpr::operator_plus_equals : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GLinearExpr::operator_minus_equals( const Napi::CallbackInfo& info )
{
    //       LinearExpr& operator-=( const LinearExpr& other );
    LinearExpr other;
    if ( info.Length() == 1 && ToLinearExpr( info[ 0 ], other ) )
    {
        *pLinearExpr -= other;
        return this->Value();
    }

    ThrowJsError( operations_research::sat::GLinearExpr::operator_minus_equals : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GLinearExpr::operator_times_equals( const Napi::CallbackInfo& info )
{
    //       LinearExpr& operator*=( int64_t factor );
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        int64_t other = info[ 0 ].As< Napi::Number >().Int64Value();
        *pLinearExpr *= other;
        return this->Value();
    }

    ThrowJsError( operations_research::sat::GLinearExpr::operator_times_equals : Invalid argument );
    return info.Env().Undefined();
}

bool operations_research::sat::GLinearExpr::ToLinearExpr( const Napi::Value& value, LinearExpr& expr )
{
    if ( value.IsObject() && value.As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
        expr = *GLinearExpr::Unwrap( value.As< Napi::Object >() )->pLinearExpr;
    else if ( value.IsNumber() )
        expr = value.As< Napi::Number >().DoubleValue();
    else if ( value.IsObject() && value.As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
        expr = *GBoolVar::Unwrap( value.As< Napi::Object >() )->pBoolVar;
    else if ( value.IsObject() && value.As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
        expr = *GIntVar::Unwrap( value.As< Napi::Object >() )->pIntVar;
    else
        return false;

    return true;
}
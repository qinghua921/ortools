#pragma once

#include "commonheader.hpp"
#include "ortools/linear_solver/linear_solver.h"
#include "GMPVariable.hpp"

namespace operations_research
{
WrapOrToolsClass(
    MPObjective,
    WrapOrToolsMethod( SetMinimization );
    WrapOrToolsMethod( SetCoefficient );
    WrapOrToolsMethod( Value );
    WrapOrToolsMethod( BestBound );
    WrapOrToolsMethod( SetMaximization );
    WrapOrToolsMethod( MinimizeLinearExpr ); );
};  // namespace operations_research

inline operations_research::GMPObjective::GMPObjective( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMPObjective >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< MPObjective > >();
        shared_ptr    = std::shared_ptr< MPObjective >( external.Data() );
        return;
    }

    ThrowJsError( operations_research::GMPObjective::GMPObjective : Invalid argument );
}

inline void operations_research::GMPObjective::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "MPObjective",
        {
            InstanceMethod( "SetMinimization", &GMPObjective::SetMinimization ),
            InstanceMethod( "SetCoefficient", &GMPObjective::SetCoefficient ),
            InstanceMethod( "Value", &GMPObjective::Value ),
            InstanceMethod( "BestBound", &GMPObjective::BestBound ),
            InstanceMethod( "SetMaximization", &GMPObjective::SetMaximization ),
            InstanceMethod( "MinimizeLinearExpr", &GMPObjective::MinimizeLinearExpr ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "MPObjective" ), func );
}

inline Napi::Value operations_research::GMPObjective::MinimizeLinearExpr( const Napi::CallbackInfo& info )
{
    //     void MinimizeLinearExpr( const LinearExpr& linear_expr )
    if ( info.Length() == 1 && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        auto linear_expr = GLinearExpr::Unwrap( info[ 0 ].As< Napi::Object >() );
        shared_ptr->MinimizeLinearExpr( *linear_expr->pLinearExpr );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPObjective::MinimizeLinearExpr : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GMPObjective::SetMaximization( const Napi::CallbackInfo& info )
{
    //     void SetMaximization()
    if ( info.Length() == 0 )
    {
        shared_ptr->SetMaximization();
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPObjective::SetMaximization : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GMPObjective::BestBound( const Napi::CallbackInfo& info )
{
    //     double BestBound() const;
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), shared_ptr->BestBound() );
    }

    ThrowJsError( operations_research::GMPObjective::BestBound : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GMPObjective::Value( const Napi::CallbackInfo& info )
{
    //     double Value() const;
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), shared_ptr->Value() );
    }

    ThrowJsError( operations_research::GMPObjective::Value : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GMPObjective::SetMinimization( const Napi::CallbackInfo& info )
{
    //     void SetMinimization()
    if ( info.Length() == 0 )
    {
        shared_ptr->SetMinimization();
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPObjective::SetMinimization : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GMPObjective::SetCoefficient( const Napi::CallbackInfo& info )
{
    //     void SetCoefficient( const MPVariable* const var, double coeff );
    if ( info.Length() == 2
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() )
         && info[ 1 ].IsNumber() )
    {
        auto   var   = GMPVariable::Unwrap( info[ 0 ].As< Napi::Object >() );
        double coeff = info[ 1 ].As< Napi::Number >().DoubleValue();
        shared_ptr->SetCoefficient( var->pMPVariable, coeff );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPObjective::SetCoefficient : Invalid argument );
    return info.Env().Undefined();
}

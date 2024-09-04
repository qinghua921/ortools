#pragma once

#include <napi.h>
#include "../commonheader.hpp"
#include "ortools/linear_solver/linear_solver.h"
#include "GMPVariable.hpp"

namespace operations_research
{
class GMPObjective : public Napi::ObjectWrap< GMPObjective >
{
public:
    static Napi::FunctionReference constructor;
    MPObjective*                   pMPObjective = nullptr;
    GMPObjective( const Napi::CallbackInfo& info );
    ~GMPObjective();
    static Napi::Object Init( Napi::Env env, Napi::Object exports );

    Napi::Value SetMinimization( const Napi::CallbackInfo& info );
    Napi::Value SetCoefficient( const Napi::CallbackInfo& info );
    Napi::Value Value( const Napi::CallbackInfo& info );
};
};  // namespace operations_research

Napi::FunctionReference operations_research::GMPObjective::constructor;

inline operations_research::GMPObjective::GMPObjective( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMPObjective >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< MPObjective > >();
        pMPObjective  = dynamic_cast< MPObjective* >( external.Data() );
        if ( pMPObjective != nullptr ) return;
    }

    ThrowJsError( operations_research::GMPObjective::GMPObjective : Invalid argument );
}

inline operations_research::GMPObjective::~GMPObjective()
{
    delete pMPObjective;
}

inline Napi::Object operations_research::GMPObjective::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "MPObjective",
        {
            InstanceMethod( "SetMinimization", &GMPObjective::SetMinimization ),
            InstanceMethod( "SetCoefficient", &GMPObjective::SetCoefficient ),
            InstanceMethod( "Value", &GMPObjective::Value ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "MPObjective" ), func );
    return exports;
}

inline Napi::Value operations_research::GMPObjective::Value( const Napi::CallbackInfo& info )
{
    //     double Value() const;
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), pMPObjective->Value() );
    }

    ThrowJsError( operations_research::GMPObjective::Value : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GMPObjective::SetMinimization( const Napi::CallbackInfo& info )
{
    //     void SetMinimization()
    if ( info.Length() == 0 )
    {
        pMPObjective->SetMinimization();
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
        pMPObjective->SetCoefficient( var->pMPVariable, coeff );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPObjective::SetCoefficient : Invalid argument );
    return info.Env().Undefined();
}

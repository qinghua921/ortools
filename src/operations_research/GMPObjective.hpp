#pragma once

#include <napi.h>
#include "GMPVariable.hpp"
#include "../commonheader.hpp"
#include "ortools/linear_solver/linear_solver.h"
namespace operations_research
{

class GMPObjective : public Napi::ObjectWrap< GMPObjective >
{
public:
    static Napi::FunctionReference constructor;
    MPObjective*                   pMPObjective;

public:
    GMPObjective( const Napi::CallbackInfo& info );
    ~GMPObjective();

public:
    static Napi::Object Init( Napi::Env env, Napi::Object exports );
    Napi::Value         SetMaximization( const Napi::CallbackInfo& info );
    Napi::Value         Value( const Napi::CallbackInfo& info );
    Napi::Value         SetCoefficient( const Napi::CallbackInfo& info );
    Napi::Value         SetMinimization( const Napi::CallbackInfo& info );
};

Napi::FunctionReference GMPObjective::constructor;

Napi::Object GMPObjective::Init( Napi::Env env, Napi::Object exports )
{
    Napi::Function func = DefineClass(
        env,
        "MPObjective",
        {
            InstanceMethod( "SetCoefficient", &GMPObjective::SetCoefficient ),    //
            InstanceMethod( "SetMinimization", &GMPObjective::SetMinimization ),  //
            InstanceMethod( "SetMaximization", &GMPObjective::SetMaximization ),  //
            InstanceMethod( "Value", &GMPObjective::Value )                       //
        } );

    constructor = Napi::Persistent( func );
    exports.Set( "MPObjective", func );
    return exports;
}

GMPObjective::GMPObjective( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMPObjective >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto pMPObjective = info[ 0 ].As< Napi::External< MPObjective > >().Data();
        if ( typeid( *pMPObjective ) == typeid( MPObjective ) )
        {
            this->pMPObjective = pMPObjective;
            return;
        }
    }

    ThrowJsError( GMPObjective::GMPObjective Error );
};

GMPObjective::~GMPObjective()
{
#ifdef DEBUG
    LOG( INFO ) << "GMPObjective::~GMPObjective";
#endif
}

Napi::Value GMPObjective::SetMaximization( const Napi::CallbackInfo& info )
{
    this->pMPObjective->SetMaximization();
    return info.Env().Undefined();
};

Napi::Value GMPObjective::Value( const Napi::CallbackInfo& info )
{
    return Napi::Number::New( info.Env(), this->pMPObjective->Value() );
};

Napi::Value GMPObjective::SetCoefficient( const Napi::CallbackInfo& info )
{
    if ( info.Length() < 2 || !info[ 0 ].IsObject() || !info[ 1 ].IsNumber() )
    {
        ThrowJsError( GMPObjective::SetCoefficient Error );
        return info.Env().Undefined();
    }

    GMPVariable* wrapper = GMPVariable::Unwrap( info[ 0 ].As< Napi::Object >() );
    if ( typeid( *wrapper ) != typeid( GMPVariable ) )
    {
        ThrowJsError( GMPObjective::SetCoefficient Error );
        return info.Env().Undefined();
    }

    auto row   = wrapper->pMPVariable;
    auto value = info[ 1 ].As< Napi::Number >();
    this->pMPObjective->SetCoefficient( row, value );
    return info.Env().Undefined();
};

Napi::Value GMPObjective::SetMinimization( const Napi::CallbackInfo& info )
{
    this->pMPObjective->SetMinimization();
    return info.Env().Undefined();
}

};  // namespace operations_research
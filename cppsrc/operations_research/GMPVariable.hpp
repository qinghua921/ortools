#pragma once

#include <napi.h>
#include "../commonheader.hpp"

#include "ortools/linear_solver/linear_solver.h"
namespace operations_research
{

class GMPVariable : public Napi::ObjectWrap< GMPVariable >
{
public:
    static Napi::FunctionReference constructor;
    MPVariable*                    pMPVariable;

public:
    GMPVariable( const Napi::CallbackInfo& info );
    ~GMPVariable();

public:
    static Napi::Object Init( Napi::Env env, Napi::Object exports );
    Napi::Value         name( const Napi::CallbackInfo& info );
    Napi::Value         solution_value( const Napi::CallbackInfo& info );
};

Napi::FunctionReference GMPVariable::constructor;

Napi::Object GMPVariable::Init( Napi::Env env, Napi::Object exports )
{
    Napi::Function func = DefineClass(
        env,
        "MPVariable",
        {
            InstanceMethod( "name", &GMPVariable::name ),                     //
            InstanceMethod( "solution_value", &GMPVariable::solution_value )  //
        } );

    constructor = Napi::Persistent( func );
    exports.Set( "MPVariable", func );
    return exports;
}

Napi::Value GMPVariable::solution_value( const Napi::CallbackInfo& info )
{
    return Napi::Number::New( info.Env(), this->pMPVariable->solution_value() );
}

Napi::Value GMPVariable::name( const Napi::CallbackInfo& info )
{
    return Napi::String::New( info.Env(), this->pMPVariable->name() );
}

GMPVariable::GMPVariable( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMPVariable >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto pMPVariable = info[ 0 ].As< Napi::External< MPVariable > >().Data();
        if ( typeid( *pMPVariable ) == typeid( MPVariable ) )
        {
            this->pMPVariable = pMPVariable;
            return;
        }
    }

    PaoJsError( GMPVariable::GMPVariable “Ï≥£ );
};

GMPVariable::~GMPVariable()
{
#ifdef KAIFA
    LOG( INFO ) << "GMPVariable::~GMPVariable";
#endif
};

}  // namespace operations_research

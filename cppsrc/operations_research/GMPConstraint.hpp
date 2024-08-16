#pragma once

#include <napi.h>

#include "ortools/linear_solver/linear_solver.h"
namespace operations_research
{

class GMPConstraint : public Napi::ObjectWrap< GMPConstraint >
{
public:
    static Napi::FunctionReference constructor;
    MPConstraint*                  pMPConstraint;

public:
    GMPConstraint( const Napi::CallbackInfo& info );
    ~GMPConstraint();

public:
    static Napi::Object Init( Napi::Env env, Napi::Object exports );
    Napi::Value         SetCoefficient( const Napi::CallbackInfo& info );
};

Napi::FunctionReference GMPConstraint::constructor;

Napi::Object GMPConstraint::Init( Napi::Env env, Napi::Object exports )
{
    Napi::Function func = DefineClass(
        env,
        "MPConstraint",
        {
            InstanceMethod( "SetCoefficient", &GMPConstraint::SetCoefficient )  //
        } );

    constructor = Napi::Persistent( func );
    exports.Set( "MPConstraint", func );
    return exports;
};

GMPConstraint::GMPConstraint( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMPConstraint >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto pMPConstraint = info[ 0 ].As< Napi::External< MPConstraint > >().Data();
        if ( typeid( *pMPConstraint ) == typeid( MPConstraint ) )
        {
            this->pMPConstraint = pMPConstraint;
            return;
        }
    }

    PaoJsError( GMPConstraint::GMPConstraint 异常 );
}

GMPConstraint::~GMPConstraint()
{
#ifdef KAIFA
    LOG( INFO ) << "GMPConstraint::~GMPConstraint";
#endif
}

Napi::Value GMPConstraint::SetCoefficient( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 2 && info[ 0 ].IsObject() && info[ 1 ].IsNumber() )
    {
        GMPVariable* wrapper = GMPVariable::Unwrap( info[ 0 ].As< Napi::Object >() );
        if ( typeid( *wrapper ) == typeid( GMPVariable ) )
        {
            auto row   = wrapper->pMPVariable;
            auto value = info[ 1 ].As< Napi::Number >();
            this->pMPConstraint->SetCoefficient( row, value );
            return info.Env().Undefined();
        }
    }

    PaoJsError( GMPConstraint::SetCoefficient 异常 );
    return info.Env().Undefined();
}

};  // namespace operations_research
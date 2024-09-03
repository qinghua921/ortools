#pragma once

#include <napi.h>
#include "../commonheader.hpp"
#include "ortools/linear_solver/linear_solver.h"
#include "GMPVariable.hpp"

namespace operations_research
{
class GMPConstraint : public Napi::ObjectWrap< GMPConstraint >
{
public:
    static Napi::FunctionReference constructor;
    MPConstraint*                  pMPConstraint = nullptr;
    GMPConstraint( const Napi::CallbackInfo& info );
    ~GMPConstraint();
    static Napi::Object Init( Napi::Env env, Napi::Object exports );

    Napi::Value SetCoefficient( const Napi::CallbackInfo& info );
};
};  // namespace operations_research

Napi::FunctionReference operations_research::GMPConstraint::constructor;

inline operations_research::GMPConstraint::GMPConstraint( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMPConstraint >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< MPConstraint > >();
        pMPConstraint = dynamic_cast< MPConstraint* >( external.Data() );
        if ( pMPConstraint != nullptr ) return;
    }

    ThrowJsError( operations_research::GMPConstraint::GMPConstraint : Invalid argument );
}

inline operations_research::GMPConstraint::~GMPConstraint()
{
    delete pMPConstraint;
}

inline Napi::Object operations_research::GMPConstraint::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "MPConstraint",
        {
            InstanceMethod( "SetCoefficient", &GMPConstraint::SetCoefficient ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "MPConstraint" ), func );
    return exports;
}

inline Napi::Value operations_research::GMPConstraint::SetCoefficient( const Napi::CallbackInfo& info )
{
    //     void SetCoefficient( const MPVariable* const var, double coeff );
    if ( info.Length() == 2 && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() )
         && info[ 1 ].IsNumber() )
    {
        auto   var   = GMPVariable::Unwrap( info[ 0 ].As< Napi::Object >() );
        double coeff = info[ 1 ].As< Napi::Number >().DoubleValue();
        pMPConstraint->SetCoefficient( var->pMPVariable, coeff );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPConstraint::SetCoefficient : Invalid argument );
    return info.Env().Undefined();
}

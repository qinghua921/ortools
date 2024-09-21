#pragma once

#include "napi.h"
#include "ortools/linear_solver/linear_solver.h"
#include "MPVariable.hpp"

namespace operations_research
{

class GMPConstraint : public Napi::ObjectWrap< GMPConstraint >
{
public:
    static inline Napi::FunctionReference constructor;
    MPConstraint*                         pMPConstraint = nullptr;

    GMPConstraint( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GMPConstraint >( info )
    {
        Napi::Env env = info.Env();

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external = info[ 0 ].As< Napi::External< MPConstraint > >();
            pMPConstraint = dynamic_cast< MPConstraint* >( external.Data() );
            if ( pMPConstraint ) return;
        }

        Napi::TypeError::New( env, "operations_research::GMPConstraint::GMPConstraint : Invalid arguments" ).ThrowAsJavaScriptException();
    };

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
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
    };

    // void SetCoefficient( const MPVariable* var, double coeff );
    Napi::Value SetCoefficient( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 2 && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() )
             && info[ 1 ].IsNumber() )
        {
            auto   var   = GMPVariable::Unwrap( info[ 0 ].As< Napi::Object >() );
            double coeff = info[ 1 ].As< Napi::Number >().DoubleValue();
            pMPConstraint->SetCoefficient( var->pMPVariable, coeff );
            return env.Null();
        }

        Napi::TypeError::New( env, "operations_research::GMPConstraint::SetCoefficient : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };
};

};  // namespace operations_research
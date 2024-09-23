#pragma once

#include "napi.h"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{

class GMPObjective : public Napi::ObjectWrap< GMPObjective >
{
public:
    static inline Napi::FunctionReference constructor;
    MPObjective*                          pMPObjective = nullptr;

    GMPObjective( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GMPObjective >( info )
    {
        Napi::Env env = info.Env();

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external = info[ 0 ].As< Napi::External< MPObjective > >();
            pMPObjective  = dynamic_cast< MPObjective* >( external.Data() );
            if ( pMPObjective ) return;
        }

        Napi::TypeError::New( env, "operations_research::GMPObjective::GMPObjective : Invalid arguments" ).ThrowAsJavaScriptException();
    };

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "MPObjective",
            {
                InstanceMethod( "Clear", &GMPObjective::Clear ),
                InstanceMethod( "SetCoefficient", &GMPObjective::SetCoefficient ),
                InstanceMethod( "SetMinimization", &GMPObjective::SetMinimization ),
                InstanceMethod( "SetMaximization", &GMPObjective::SetMaximization ),
                InstanceMethod( "Value", &GMPObjective::Value ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPObjective" ), func );
        return exports;
    };

    // double Value() const;
    Napi::Value Value( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            return Napi::Number::New( env, pMPObjective->Value() );
        }

        Napi::TypeError::New( env, "operations_research::GMPObjective::Value : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // void SetMaximization();
    Napi::Value SetMaximization( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            pMPObjective->SetMaximization();
            return env.Null();
        }

        Napi::TypeError::New( env, "operations_research::GMPObjective::SetMaximization : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // void SetMinimization();
    Napi::Value SetMinimization( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            pMPObjective->SetMinimization();
            return env.Null();
        }

        Napi::TypeError::New( env, "operations_research::GMPObjective::SetMinimization : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
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
            pMPObjective->SetCoefficient( var->pMPVariable, coeff );
            return env.Null();
        }

        Napi::TypeError::New( env, "operations_research::GMPObjective::SetCoefficient : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // void Clear();
    Napi::Value Clear( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            pMPObjective->Clear();
            return env.Null();
        }

        Napi::TypeError::New( env, "operations_research::GMPObjective::Clear : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };
};

};  // namespace operations_research
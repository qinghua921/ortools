#pragma once

#include "napi.h"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{

class GMPVariable : public Napi::ObjectWrap< GMPVariable >
{
public:
    static inline Napi::FunctionReference constructor;
    MPVariable*                           pMPVariable = nullptr;

    GMPVariable( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GMPVariable >( info )
    {
        Napi::Env env = info.Env();

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external = info[ 0 ].As< Napi::External< MPVariable > >();
            pMPVariable   = dynamic_cast< MPVariable* >( external.Data() );
            if ( pMPVariable ) return;
        }

        Napi::TypeError::New( env, "operations_research::GMPVariable::GMPVariable : Invalid arguments" ).ThrowAsJavaScriptException();
    };

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "MPVariable",
            {
                InstanceMethod( "solution_value", &GMPVariable::solution_value ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPVariable" ), func );
        return exports;
    };

    // double solution_value() const;
    Napi::Value solution_value( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            return Napi::Number::New( env, pMPVariable->solution_value() );
        }

        Napi::TypeError::New( env, "operations_research::GMPVariable::solution_value : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }
};

};  // namespace operations_research
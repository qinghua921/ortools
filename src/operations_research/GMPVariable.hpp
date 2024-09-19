#pragma once

#include "napi.h"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{

class GMPVariable : public Napi::ObjectWrap< GMPVariable >
{
public:
    static inline Napi::FunctionReference constructor;
    MPVariable*                           pMPVariable;
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
            {} );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPVariable" ), func );
        return exports;
    };
};

};  // namespace operations_research
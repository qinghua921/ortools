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
            {} );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPObjective" ), func );
        return exports;
    };
};

};  // namespace operations_research
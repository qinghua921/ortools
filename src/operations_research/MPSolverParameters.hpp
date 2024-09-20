#pragma once

#include "napi.h"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{

class GMPSolverParameters : public Napi::ObjectWrap< GMPSolverParameters >
{
public:
    static inline Napi::FunctionReference constructor;
    MPSolverParameters*                   pMPSolverParameters = nullptr;

    GMPSolverParameters( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GMPSolverParameters >( info )
    {
        Napi::Env env = info.Env();

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external       = info[ 0 ].As< Napi::External< MPSolverParameters > >();
            pMPSolverParameters = dynamic_cast< MPSolverParameters* >( external.Data() );
            if ( pMPSolverParameters ) return;
        }

        Napi::TypeError::New( env, "operations_research::GMPSolverParameters::GMPSolverParameters : Invalid arguments" ).ThrowAsJavaScriptException();
    };

    // ~GMPSolverParameters()
    // TODO  delete pMPSolverParameters or not????;

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "MPSolverParameters",
            {} );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPSolverParameters" ), func );
        return exports;
    };
};

};  // namespace operations_research
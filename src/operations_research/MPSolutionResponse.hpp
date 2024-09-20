#pragma once

#include "napi.h"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{

class GMPSolutionResponse : public Napi::ObjectWrap< GMPSolutionResponse >
{
public:
    static inline Napi::FunctionReference constructor;
    MPSolutionResponse*                   pMPSolutionResponse = nullptr;

    GMPSolutionResponse( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GMPSolutionResponse >( info )
    {
        Napi::Env env = info.Env();

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external       = info[ 0 ].As< Napi::External< MPSolutionResponse > >();
            pMPSolutionResponse = dynamic_cast< MPSolutionResponse* >( external.Data() );
            if ( pMPSolutionResponse ) return;
        }

        Napi::TypeError::New( env, "operations_research::GMPSolutionResponse::GMPSolutionResponse : Invalid arguments" ).ThrowAsJavaScriptException();
    };

    // ~GMPSolutionResponse()
    // TODO  delete pMPSolutionResponse or not????;

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "MPSolutionResponse",
            {} );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPSolutionResponse" ), func );
        return exports;
    };
};

};  // namespace operations_research
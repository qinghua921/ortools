#pragma once

#include "napi.h"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{

class GMPModelRequest : public Napi::ObjectWrap< GMPModelRequest >
{
public:
    static inline Napi::FunctionReference constructor;
    MPModelRequest*                       pMPModelRequest = nullptr;

    GMPModelRequest( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GMPModelRequest >( info )
    {
        Napi::Env env = info.Env();

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external   = info[ 0 ].As< Napi::External< MPModelRequest > >();
            pMPModelRequest = dynamic_cast< MPModelRequest* >( external.Data() );
            if ( pMPModelRequest ) return;
        }

        Napi::TypeError::New( env, "operations_research::GMPModelRequest::GMPModelRequest : Invalid arguments" ).ThrowAsJavaScriptException();
    };

    // ~GMPModelRequest()
    // TODO  delete pMPModelRequest or not????;

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "MPModelRequest",
            {} );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPModelRequest" ), func );
        return exports;
    };
};

};  // namespace operations_research
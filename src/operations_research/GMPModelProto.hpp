#pragma once

#include "napi.h"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{

class GMPModelProto : public Napi::ObjectWrap< GMPModelProto >
{
public:
    static inline Napi::FunctionReference constructor;
    MPModelProto*                         pMPModelProto;
    GMPModelProto( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GMPModelProto >( info )
    {
        Napi::Env env = info.Env();

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external = info[ 0 ].As< Napi::External< MPModelProto > >();
            pMPModelProto = dynamic_cast< MPModelProto* >( external.Data() );
            if ( pMPModelProto ) return;
        }

        Napi::TypeError::New( env, "operations_research::GMPModelProto::GMPModelProto : Invalid arguments" ).ThrowAsJavaScriptException();
    };
    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "MPModelProto",
            {} );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPModelProto" ), func );
        return exports;
    };
};

};  // namespace operations_research
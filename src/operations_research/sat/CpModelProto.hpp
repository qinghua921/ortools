#pragma once

#include "napi.h"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
    class GCpModelProto : public Napi::ObjectWrap< GCpModelProto >
    {
    public:
        static inline Napi::FunctionReference constructor;
        CpModelProto*                         pCpModelProto = nullptr;

        GCpModelProto( const Napi::CallbackInfo& info )
            : Napi::ObjectWrap< GCpModelProto >( info )
        {
            Napi::Env env = info.Env();

            if ( info.Length() == 1 && info[ 0 ].IsExternal() )
            {
                auto external = info[ 0 ].As< Napi::External< CpModelProto > >();
                pCpModelProto = dynamic_cast< CpModelProto* >( external.Data() );
                if ( pCpModelProto ) return;
            }

            Napi::TypeError::New( env, "operations_research::GCpModelProto::GCpModelProto : Invalid arguments" ).ThrowAsJavaScriptException();
        };

        ~GCpModelProto()
        {
            if ( pCpModelProto ) delete pCpModelProto;
        };

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "CpModelProto",
                {} );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "CpModelProto" ), func );
            return exports;
        };
    };
}  // namespace sat

};  // namespace operations_research
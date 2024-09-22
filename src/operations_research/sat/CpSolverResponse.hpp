#pragma once

#include "napi.h"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{

    class GCpSolverResponse : public Napi::ObjectWrap< GCpSolverResponse >
    {
    public:
        static inline Napi::FunctionReference constructor;
        CpSolverResponse*                     pCpSolverResponse = nullptr;

        GCpSolverResponse( const Napi::CallbackInfo& info )
            : Napi::ObjectWrap< GCpSolverResponse >( info )
        {
            Napi::Env env = info.Env();

            if ( info.Length() == 1 && info[ 0 ].IsExternal() )
            {
                auto external     = info[ 0 ].As< Napi::External< CpSolverResponse > >();
                pCpSolverResponse = dynamic_cast< CpSolverResponse* >( external.Data() );
                if ( pCpSolverResponse ) return;
            }

            Napi::TypeError::New( env, "operations_research::GCpSolverResponse::GCpSolverResponse : Invalid arguments" ).ThrowAsJavaScriptException();
        };

        // TODO delete pCpSolverResponse or not ?
        // ~GCpSolverResponse()
        // {
        //     if ( pCpSolverResponse ) delete pCpSolverResponse;
        // };

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "CpSolverResponse",
                {} );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "CpSolverResponse" ), func );
            return exports;
        };
    };
}  // namespace sat

};  // namespace operations_research
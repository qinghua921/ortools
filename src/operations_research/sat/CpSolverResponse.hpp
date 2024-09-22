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

        ~GCpSolverResponse()
        {
            if ( pCpSolverResponse ) delete pCpSolverResponse;
        };

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "CpSolverResponse",
                {
                    InstanceMethod( "status", &GCpSolverResponse::status )
                } );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "CpSolverResponse" ), func );
            return exports;
        };

        // ::operations_research::sat::CpSolverStatus status() const;
        Napi::Value status( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            if ( info.Length() == 0 )
            {
                return Napi::Number::New( env, pCpSolverResponse->status() );
            }

            Napi::TypeError::New( env, "operations_research::sat::GCpSolverResponse::status : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        }
    };
}  // namespace sat

};  // namespace operations_research
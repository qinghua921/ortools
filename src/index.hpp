#pragma once

#include <napi.h>
#include "ortools/linear_solver/linear_solver.h"

// ThrowAsJavaScriptException
#define ThrowJsError( errinfo ) \
    Napi::Error::New( info.Env(), ( char* )u8#errinfo ).ThrowAsJavaScriptException()

namespace operations_research
{
class GMPSolver : public Napi::ObjectWrap< GMPSolver >
{
public:
    static Napi::FunctionReference constructor;
    MPSolver*                      pMPSolver = nullptr;

    GMPSolver( const Napi::CallbackInfo& info );
    ~GMPSolver();

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );

        Napi::Function func = DefineClass(
            env, "MPSolver",
            {
                StaticMethod( "CreateSolver", &GMPSolver::CreateSolver ),
            } );

        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPSolver" ), func );

        return exports;
    };

    static Napi::Value CreateSolver( const Napi::CallbackInfo& info );
};

Napi::FunctionReference GMPSolver::constructor;

namespace sat
{

};  // namespace sat
};  // namespace operations_research

Napi::Object Init( Napi::Env env, Napi::Object exports )
{
    auto operations_research_exports = Napi::Object::New( env );
    operations_research::GMPSolver::Init( env, operations_research_exports );

    exports.Set( "operations_research", operations_research_exports );

    return exports;
}

NODE_API_MODULE( ortools_binding, Init );

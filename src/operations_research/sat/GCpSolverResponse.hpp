#pragma once

#include <napi.h>
#include "../../commonheader.hpp"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
    class GCpSolverResponse : public Napi::ObjectWrap< GCpSolverResponse >
    {
    public:
        static Napi::FunctionReference constructor;
        CpSolverResponse*                          pCpSolverResponse = nullptr;
        GCpSolverResponse( const Napi::CallbackInfo& info );
        ~GCpSolverResponse();
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
    };
};  // namespace sat
};  // namespace operations_research

Napi::FunctionReference operations_research::sat::GCpSolverResponse::constructor;

inline operations_research::sat::GCpSolverResponse::GCpSolverResponse( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GCpSolverResponse >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< CpSolverResponse > >();
        pCpSolverResponse         = dynamic_cast< CpSolverResponse* >( external.Data() );
        if ( pCpSolverResponse != nullptr ) return;
    }

    ThrowJsError( operations_research::GCpSolverResponse::GCpSolverResponse : Invalid argument );
}

inline operations_research::sat::GCpSolverResponse::~GCpSolverResponse()
{
    delete pCpSolverResponse;
}

inline Napi::Object operations_research::sat::GCpSolverResponse::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "CpSolverResponse",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "CpSolverResponse" ), func );
    return exports;
}

#pragma once

#include <napi.h>
#include "commonheader.hpp"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{
class GMPSolutionResponse : public Napi::ObjectWrap< GMPSolutionResponse >
{
public:
    static Napi::FunctionReference constructor;
    MPSolutionResponse*            pMPSolutionResponse = nullptr;
    GMPSolutionResponse( const Napi::CallbackInfo& info );
    ~GMPSolutionResponse();
    static Napi::Object Init( Napi::Env env, Napi::Object exports );
};
};  // namespace operations_research

Napi::FunctionReference operations_research::GMPSolutionResponse::constructor;

inline operations_research::GMPSolutionResponse::GMPSolutionResponse( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMPSolutionResponse >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external       = info[ 0 ].As< Napi::External< MPSolutionResponse > >();
        pMPSolutionResponse = dynamic_cast< MPSolutionResponse* >( external.Data() );
        if ( pMPSolutionResponse != nullptr ) return;
    }

    ThrowJsError( operations_research::GMPSolutionResponse::GMPSolutionResponse : Invalid argument );
}

inline operations_research::GMPSolutionResponse::~GMPSolutionResponse()
{
    delete pMPSolutionResponse;
}

inline Napi::Object operations_research::GMPSolutionResponse::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "MPSolutionResponse",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "MPSolutionResponse" ), func );
    return exports;
}

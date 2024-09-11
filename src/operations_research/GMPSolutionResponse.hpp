#pragma once

#include "commonheader.hpp"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{
class GMPSolutionResponse : public Napi::ObjectWrap< GMPSolutionResponse >
{
    CommonProperties( MPSolutionResponse );
};
};  // namespace operations_research

inline operations_research::GMPSolutionResponse::GMPSolutionResponse( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMPSolutionResponse >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external        = info[ 0 ].As< Napi::External< MPSolutionResponse > >();
        spMPSolutionResponse = std::shared_ptr< MPSolutionResponse >( external.Data() );
        return;
    }

    ThrowJsError( operations_research::GMPSolutionResponse::GMPSolutionResponse : Invalid argument );
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

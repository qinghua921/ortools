#pragma once

#include "commonheader.hpp"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{
class GMPModelRequest : public Napi::ObjectWrap< GMPModelRequest >
{
    CommonProperties( MPModelRequest );
};
};  // namespace operations_research

inline operations_research::GMPModelRequest::GMPModelRequest( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMPModelRequest >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external    = info[ 0 ].As< Napi::External< MPModelRequest > >();
        spMPModelRequest = std::shared_ptr< MPModelRequest >( external.Data() );
        return;
    }

    ThrowJsError( operations_research::GMPModelRequest::GMPModelRequest : Invalid argument );
}

inline Napi::Object operations_research::GMPModelRequest::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "MPModelRequest",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "MPModelRequest" ), func );
    return exports;
}

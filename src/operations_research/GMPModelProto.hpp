#pragma once

#include "commonheader.hpp"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{
class GMPModelProto : public Napi::ObjectWrap< GMPModelProto >
{
    CommonProperties( MPModelProto );
};
};  // namespace operations_research

inline operations_research::GMPModelProto::GMPModelProto( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMPModelProto >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external  = info[ 0 ].As< Napi::External< MPModelProto > >();
        spMPModelProto = std::shared_ptr< MPModelProto >( external.Data() );
        return;
    }

    ThrowJsError( operations_research::GMPModelProto::GMPModelProto : Invalid argument );
}

inline Napi::Object operations_research::GMPModelProto::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "MPModelProto",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "MPModelProto" ), func );
    return exports;
}

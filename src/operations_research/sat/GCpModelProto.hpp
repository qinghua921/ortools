#pragma once

#include "commonheader.hpp"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
    WrapOrToolsClass( CpModelProto );
};  // namespace sat
};  // namespace operations_research

inline operations_research::sat::GCpModelProto::GCpModelProto( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GCpModelProto >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< CpModelProto > >();
        shared_ptr    = std::shared_ptr< CpModelProto >( external.Data() );
        return;
    }

    ThrowJsError( operations_research::GCpModelProto::GCpModelProto : Invalid argument );
}

inline void operations_research::sat::GCpModelProto::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "CpModelProto",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "CpModelProto" ), func );
}

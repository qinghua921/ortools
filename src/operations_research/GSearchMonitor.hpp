#pragma once

#include "commonheader.hpp"
#include "ortools/constraint_solver/constraint_solver.h"

namespace operations_research
{
class GSearchMonitor : public Napi::ObjectWrap< GSearchMonitor >
{
    CommonProperties( SearchMonitor )
};
}  // namespace operations_research

inline operations_research::GSearchMonitor::GSearchMonitor( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GSearchMonitor >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< SearchMonitor > >();
        spSearchMonitor        = std::shared_ptr< SearchMonitor >( external.Data() );
        return;
    }

    ThrowJsError( operations_research::GSearchMonitor::GSearchMonitor : Invalid argument );
}

inline Napi::Object operations_research::GSearchMonitor::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "SearchMonitor",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "SearchMonitor" ), func );
    return exports;
}
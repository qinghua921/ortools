#pragma once

#include "commonheader.hpp"
#include "ortools/constraint_solver/constraint_solver.h"

namespace operations_research
{
class GIntervalVar : public Napi::ObjectWrap< GIntervalVar >
{
    CommonProperties( IntervalVar )
};
}  // namespace operations_research

inline operations_research::GIntervalVar::GIntervalVar( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GIntervalVar >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< IntervalVar > >();
        spIntervalVar = std::shared_ptr< IntervalVar >( external.Data() );
        return;
    }

    ThrowJsError( operations_research::GIntervalVar::GIntervalVar : Invalid argument );
}

inline Napi::Object operations_research::GIntervalVar::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "IntervalVar",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "IntervalVar" ), func );
    return exports;
}
#pragma once

#include "commonheader.hpp"
#include "ortools/constraint_solver/constraint_solver.h"

namespace operations_research
{
class GSequenceVar : public Napi::ObjectWrap< GSequenceVar >
{
    CommonProperties( SequenceVar )
};
}  // namespace operations_research

inline operations_research::GSequenceVar::GSequenceVar( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GSequenceVar >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< SequenceVar > >();
        spSequenceVar = std::shared_ptr< SequenceVar >( external.Data() );
        return;
    }

    ThrowJsError( operations_research::GSequenceVar::GSequenceVar : Invalid argument );
}

inline Napi::Object operations_research::GSequenceVar::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "SequenceVar",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "SequenceVar" ), func );
    return exports;
}
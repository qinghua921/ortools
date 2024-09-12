#pragma once

#include "commonheader.hpp"
#include "ortools/constraint_solver/constraint_solver.h"

namespace operations_research
{
class GDecisionBuilder : public Napi::ObjectWrap< GDecisionBuilder >
{
    CommonProperties( DecisionBuilder )
};
}  // namespace operations_research

inline operations_research::GDecisionBuilder::GDecisionBuilder( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GDecisionBuilder >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external     = info[ 0 ].As< Napi::External< DecisionBuilder > >();
        spDecisionBuilder = std::shared_ptr< DecisionBuilder >( external.Data() );
        return;
    }

    ThrowJsError( operations_research::GDecisionBuilder::GDecisionBuilder : Invalid argument );
}

inline Napi::Object operations_research::GDecisionBuilder::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "DecisionBuilder",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "DecisionBuilder" ), func );
    return exports;
}
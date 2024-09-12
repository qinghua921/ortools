#pragma once

#include "commonheader.hpp"
#include "ortools/constraint_solver/constraint_solver.h"

namespace operations_research
{
class GConstraint : public Napi::ObjectWrap< GConstraint >
{
    CommonProperties( Constraint )
};
}  // namespace operations_research

inline operations_research::GConstraint::GConstraint( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GConstraint >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< Constraint > >();
        spConstraint  = std::shared_ptr< Constraint >( external.Data() );
        return;
    }

    ThrowJsError( op::GConstraint::GConstraint : Invalid argument );
}

inline Napi::Object operations_research::GConstraint::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "Constraint",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "Constraint" ), func );
    return exports;
}
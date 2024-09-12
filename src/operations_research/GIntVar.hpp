#pragma once

#include "commonheader.hpp"
#include "ortools/constraint_solver/constraint_solver.h"

namespace operations_research
{
class GIntVar : public Napi::ObjectWrap< GIntVar >
{
    CommonProperties( IntVar )

    Napi::Value Value( const Napi::CallbackInfo& info );
};
}  // namespace operations_research

inline operations_research::GIntVar::GIntVar( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GIntVar >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< IntVar > >();
        spIntVar      = std::shared_ptr< IntVar >( external.Data() );
        return;
    }

    ThrowJsError( operations_research::GIntVar::GIntVar : Invalid argument );
}

inline Napi::Object operations_research::GIntVar::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "IntVar",
        {
            InstanceMethod( "Value", &GIntVar::Value ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "IntVar" ), func );
    return exports;
}

inline Napi::Value operations_research::GIntVar::Value( const Napi::CallbackInfo& info )
{
    //      virtual int64_t Value() const = 0;
    return Napi::Number::New( info.Env(), spIntVar->Value() );
}
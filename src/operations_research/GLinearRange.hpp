#pragma once

#include "commonheader.hpp"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{
class GLinearRange : public Napi::ObjectWrap< GLinearRange >
{
public:
    CommonProperties( LinearRange );
};
};  // namespace operations_research

inline operations_research::GLinearRange::GLinearRange( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GLinearRange >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< LinearRange > >();
        spLinearRange = std::shared_ptr< LinearRange >( external.Data() );
        return;
    }

    ThrowJsError( operations_research::GLinearRange::GLinearRange : Invalid argument );
}

inline Napi::Object operations_research::GLinearRange::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "LinearRange",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "LinearRange" ), func );
    return exports;
}

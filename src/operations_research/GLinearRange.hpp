#pragma once

#include <napi.h>
#include "commonheader.hpp"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{
class GLinearRange : public Napi::ObjectWrap< GLinearRange >
{
public:
    static Napi::FunctionReference constructor;
    LinearRange*                   pLinearRange = nullptr;
    GLinearRange( const Napi::CallbackInfo& info );
    ~GLinearRange();
    static Napi::Object Init( Napi::Env env, Napi::Object exports );
};
};  // namespace operations_research

Napi::FunctionReference operations_research::GLinearRange::constructor;

inline operations_research::GLinearRange::GLinearRange( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GLinearRange >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< LinearRange > >();
        pLinearRange  = dynamic_cast< LinearRange* >( external.Data() );
        if ( pLinearRange != nullptr ) return;
    }

    ThrowJsError( operations_research::GLinearRange::GLinearRange : Invalid argument );
}

inline operations_research::GLinearRange::~GLinearRange()
{
    delete pLinearRange;
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

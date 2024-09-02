#pragma once

#include <napi.h>
#include "../commonheader.hpp"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{
class GMPObjective : public Napi::ObjectWrap< GMPObjective >
{
public:
    static Napi::FunctionReference constructor;
    MPObjective*                   pMPObjective = nullptr;
    GMPObjective( const Napi::CallbackInfo& info );
    ~GMPObjective();
    static Napi::Object Init( Napi::Env env, Napi::Object exports );
};
};  // namespace operations_research

Napi::FunctionReference operations_research::GMPObjective::constructor;

inline operations_research::GMPObjective::GMPObjective( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMPObjective >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< MPObjective > >();
        pMPObjective  = dynamic_cast< MPObjective* >( external.Data() );
        if ( pMPObjective != nullptr ) return;
    }

    ThrowJsError( operations_research::GMPObjective::GMPObjective : Invalid argument );
}

inline operations_research::GMPObjective::~GMPObjective()
{
    delete pMPObjective;
}

inline Napi::Object operations_research::GMPObjective::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "MPObjective",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "MPObjective" ), func );
    return exports;
}

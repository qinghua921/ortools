#pragma once


#include "commonheader.hpp"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{
class GMPCallback : public Napi::ObjectWrap< GMPCallback >
{
public:
    static inline Napi::FunctionReference constructor;
    MPCallback*                          pMPCallback = nullptr;
    GMPCallback( const Napi::CallbackInfo& info );
    ~GMPCallback();
    static Napi::Object Init( Napi::Env env, Napi::Object exports );
};
};  // namespace operations_research



inline operations_research::GMPCallback::GMPCallback( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMPCallback >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< MPCallback > >();
        pMPCallback         = dynamic_cast< MPCallback* >( external.Data() );
        if ( pMPCallback != nullptr ) return;
    }

    ThrowJsError( operations_research::GMPCallback::GMPCallback : Invalid argument );
}

inline operations_research::GMPCallback::~GMPCallback()
{
    delete pMPCallback;
}

inline Napi::Object operations_research::GMPCallback::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "MPCallback",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "MPCallback" ), func );
    return exports;
}

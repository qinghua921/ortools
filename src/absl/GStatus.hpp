#pragma once


#include "commonheader.hpp"
#include "absl/status/status.h"

namespace absl
{
class GStatus : public Napi::ObjectWrap< GStatus >
{
public:
    static inline Napi::FunctionReference constructor;
    Status*                        pStatus = nullptr;
    GStatus( const Napi::CallbackInfo& info );
    ~GStatus();
    static Napi::Object Init( Napi::Env env, Napi::Object exports );
};
};  // namespace absl



inline absl::GStatus::GStatus( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GStatus >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< Status > >();
        pStatus       = dynamic_cast< Status* >( external.Data() );
        if ( pStatus != nullptr ) return;
    }

    ThrowJsError( absl::GStatus::GStatus : Invalid argument );
}

inline absl::GStatus::~GStatus()
{
    delete pStatus;
}

inline Napi::Object absl::GStatus::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "Status",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "Status" ), func );
    return exports;
}

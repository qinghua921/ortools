#pragma once

#include <napi.h>
#include "../commonheader.hpp"

namespace absl
{
class GDuration : public Napi::ObjectWrap< GDuration >
{
public:
    static Napi::FunctionReference constructor;
    Duration*                      pDuration = nullptr;
    GDuration( const Napi::CallbackInfo& info );
    ~GDuration();
    static Napi::Object Init( Napi::Env env, Napi::Object exports );
};
};  // namespace absl

Napi::FunctionReference absl::GDuration::constructor;

inline absl::GDuration::GDuration( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GDuration >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< Duration > >();
        pDuration     = dynamic_cast< Duration* >( external.Data() );
        if ( pDuration != nullptr ) return;
    }

    ThrowJsError( absl::GDuration::GDuration : Invalid argument );
}

inline absl::GDuration::~GDuration()
{
    delete pDuration;
}

inline Napi::Object absl::GDuration::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "Duration",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "Duration" ), func );
    return exports;
}

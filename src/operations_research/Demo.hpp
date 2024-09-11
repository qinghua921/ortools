#pragma once

#include "commonheader.hpp"

namespace operations_research
{
class GDemo : public Napi::ObjectWrap< GDemo >
{
public:
    static Napi::FunctionReference constructor;
    std::shared_ptr< Demo >        pDemo;
    GDemo( const Napi::CallbackInfo& info );
    static Napi::Object Init( Napi::Env env, Napi::Object exports );
};
};  // namespace operations_research

Napi::FunctionReference operations_research::GDemo::constructor;

inline operations_research::GDemo::GDemo( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GDemo >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< std::shared_ptr< Demo > > >();
        pDemo         = *external.Data();
        return;
    }

    ThrowJsError( operations_research::GDemo::GDemo : Invalid argument );
}

inline Napi::Object operations_research::GDemo::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "Demo",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "Demo" ), func );
    return exports;
}

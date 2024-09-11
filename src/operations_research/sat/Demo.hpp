#pragma once

#include "commonheader.hpp"

namespace operations_research
{
namespace sat
{
    class GDemo : public Napi::ObjectWrap< GDemo >
    {
    public:
        static inline Napi::FunctionReference constructor;
        std::shared_ptr< Demo >               pDemo;
        GDemo( const Napi::CallbackInfo& info );
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
    };
};  // namespace sat
};  // namespace operations_research

inline operations_research::sat::GDemo::GDemo( const Napi::CallbackInfo& info )
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

inline Napi::Object operations_research::sat::GDemo::Init( Napi::Env env, Napi::Object exports )
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

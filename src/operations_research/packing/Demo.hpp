#pragma once

#include <napi.h>
#include "commonheader.hpp"

namespace operations_research
{
namespace packing
{
    class GDemo : public Napi::ObjectWrap< GDemo >
    {
    public:
        static Napi::FunctionReference constructor;
        Demo*                          pDemo = nullptr;
        GDemo( const Napi::CallbackInfo& info );
        ~GDemo();
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
    };
};  // namespace packing
};  // namespace operations_research

Napi::FunctionReference operations_research::packing::GDemo::constructor;

inline operations_research::packing::GDemo::GDemo( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GDemo >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< Demo > >();
        pDemo         = dynamic_cast< Demo* >( external.Data() );
        if ( pDemo != nullptr ) return;
    }

    ThrowJsError( operations_research::GDemo::GDemo : Invalid argument );
}

inline operations_research::packing::GDemo::~GDemo()
{
    delete pDemo;
}

inline Napi::Object operations_research::packing::GDemo::Init( Napi::Env env, Napi::Object exports )
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

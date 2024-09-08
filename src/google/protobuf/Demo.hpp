#pragma once

#include <napi.h>
#include "../commonheader.hpp"

namespace google
{
namespace protobuf
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
};  // namespace protobuf
};  // namespace google

Napi::FunctionReference google::protobuf::GDemo::constructor;

inline google::protobuf::GDemo::GDemo( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GDemo >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< Demo > >();
        pDemo         = dynamic_cast< Demo* >( external.Data() );
        if ( pDemo != nullptr ) return;
    }

    ThrowJsError( google::protobuf::GDemo::GDemo : Invalid argument );
}

inline google::protobuf::GDemo::~GDemo()
{
    delete pDemo;
}

inline Napi::Object google::protobuf::GDemo::Init( Napi::Env env, Napi::Object exports )
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

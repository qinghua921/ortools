#pragma once

#include <napi.h>
#include "../commonheader.hpp"
// #include <ortools/init/init.h>

namespace operations_research
{
class GOrToolsVersion : public Napi::ObjectWrap< GOrToolsVersion >
{
public:
    static Napi::FunctionReference constructor;
    static Napi::Object            Init( Napi::Env env, Napi::Object exports );

public:
    GOrToolsVersion( const Napi::CallbackInfo& info );
    ~GOrToolsVersion();

public:
    static Napi::Value VersionString( const Napi::CallbackInfo& info );
};

Napi::FunctionReference GOrToolsVersion::constructor;

Napi::Object GOrToolsVersion::Init( Napi::Env env, Napi::Object exports )
{
    Napi::Function func = DefineClass(
        env,
        "OrToolsVersion",
        {
            StaticMethod( "VersionString", &GOrToolsVersion::VersionString )  //
        } );

    constructor = Napi::Persistent( func );
    exports.Set( "OrToolsVersion", func );
    return exports;
}

GOrToolsVersion::GOrToolsVersion( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GOrToolsVersion >( info )
{
}

GOrToolsVersion::~GOrToolsVersion()
{
}

Napi::Value GOrToolsVersion::VersionString( const Napi::CallbackInfo& info )
{
    return Napi::String::New( info.Env(), "1111" );
}

}  // namespace operations_research
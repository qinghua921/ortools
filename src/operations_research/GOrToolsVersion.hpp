#pragma once

#include <napi.h>
#include "../commonheader.hpp"
#include <ortools/init/init.h>

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
    static Napi::Value MajorNumber( const Napi::CallbackInfo& info );
    static Napi::Value MinorNumber( const Napi::CallbackInfo& info );
    static Napi::Value PatchNumber( const Napi::CallbackInfo& info );
};

Napi::FunctionReference GOrToolsVersion::constructor;

Napi::Object GOrToolsVersion::Init( Napi::Env env, Napi::Object exports )
{
    Napi::Function func = DefineClass(
        env,
        "OrToolsVersion",
        {
            StaticMethod( "VersionString", &GOrToolsVersion::VersionString ),  //
            StaticMethod( "MajorNumber", &GOrToolsVersion::MajorNumber ),      //
            StaticMethod( "MinorNumber", &GOrToolsVersion::MinorNumber ),      //
            StaticMethod( "PatchNumber", &GOrToolsVersion::PatchNumber ),      //
        } );

    constructor = Napi::Persistent( func );
    exports.Set( "OrToolsVersion", func );
    return exports;
}

GOrToolsVersion::GOrToolsVersion( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GOrToolsVersion >( info )
{
    return;
}

GOrToolsVersion::~GOrToolsVersion()
{
}

Napi::Value GOrToolsVersion::VersionString( const Napi::CallbackInfo& info )
{
    return Napi::String::New( info.Env(), OrToolsVersion::VersionString() );
}

Napi::Value GOrToolsVersion::MajorNumber( const Napi::CallbackInfo& info )
{
    return Napi::Number::New( info.Env(), OrToolsVersion::MajorNumber() );
}

Napi::Value GOrToolsVersion::MinorNumber( const Napi::CallbackInfo& info )
{
    return Napi::Number::New( info.Env(), OrToolsVersion::MinorNumber() );
}

Napi::Value GOrToolsVersion::PatchNumber( const Napi::CallbackInfo& info )
{
    return Napi::Number::New( info.Env(), OrToolsVersion::PatchNumber() );
}

}  // namespace operations_research
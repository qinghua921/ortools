#pragma once

#include "napi.h"
#include "ortools/init/init.h"

namespace operations_research
{

class GOrToolsVersion : public Napi::ObjectWrap< GOrToolsVersion >
{
public:
    static inline Napi::FunctionReference constructor;
    OrToolsVersion*                       pOrToolsVersion = nullptr;

    GOrToolsVersion( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GOrToolsVersion >( info )
    {
        Napi::Env env = info.Env();

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external   = info[ 0 ].As< Napi::External< OrToolsVersion > >();
            pOrToolsVersion = dynamic_cast< OrToolsVersion* >( external.Data() );
            if ( pOrToolsVersion ) return;
        }

        Napi::TypeError::New( env, "operations_research::GOrToolsVersion::GOrToolsVersion : Invalid arguments" ).ThrowAsJavaScriptException();
    };

    ~GOrToolsVersion()
    {
        if ( pOrToolsVersion ) delete pOrToolsVersion;
    };

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "OrToolsVersion",
            {
                StaticMethod( "VersionString", &GOrToolsVersion::VersionString ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "OrToolsVersion" ), func );
        return exports;
    };

    // static std::string VersionString()
    static Napi::Value VersionString( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            return Napi::String::New( env, OrToolsVersion::VersionString() );
        }

        Napi::TypeError::New( env, "operations_research::GOrToolsVersion::VersionString : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Undefined();
    };
};

};  // namespace operations_research
#pragma once

#include "napi.h"

namespace operations_research
{

class GDemo : public Napi::ObjectWrap< GDemo >
{
public:
    static inline Napi::FunctionReference constructor;
    Demo*                                 pDemo = nullptr;

    GDemo( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GDemo >( info )
    {
        Napi::Env env = info.Env();

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external = info[ 0 ].As< Napi::External< Demo > >();
            pDemo         = dynamic_cast< Demo* >( external.Data() );
            if ( pDemo ) return;
        }

        Napi::TypeError::New( env, "operations_research::GDemo::GDemo : Invalid arguments" ).ThrowAsJavaScriptException();
    };

    // ~GDemo()
    // TODO  delete pDemo or not????;

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "Demo",
            {} );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "Demo" ), func );
        return exports;
    };
};

};  // namespace operations_research
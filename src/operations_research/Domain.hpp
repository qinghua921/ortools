#pragma once

#include "napi.h"
#include "ortools/util/sorted_interval_list.h"

namespace operations_research
{

class GDomain : public Napi::ObjectWrap< GDomain >
{
public:
    static inline Napi::FunctionReference constructor;
    Domain*                               pDomain = nullptr;

    GDomain( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GDomain >( info )
    {
        Napi::Env env = info.Env();

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external = info[ 0 ].As< Napi::External< Domain > >();
            pDomain       = dynamic_cast< Domain* >( external.Data() );
            if ( pDomain ) return;
        }

        // Domain() {}
        if ( info.Length() == 0 )
        {
            pDomain = new Domain();
            return;
        }

        // explicit Domain( int64_t value );
        if ( info.Length() == 1 && info[ 0 ].IsNumber() )
        {
            int64_t value = info[ 0 ].As< Napi::Number >().Int64Value();
            pDomain       = new Domain( value );
            return;
        }

        //  Domain( int64_t left, int64_t right );
        if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() )
        {
            int64_t left  = info[ 0 ].As< Napi::Number >().Int64Value();
            int64_t right = info[ 1 ].As< Napi::Number >().Int64Value();
            pDomain       = new Domain( left, right );
            return;
        }

        Napi::TypeError::New( env, "operations_research::GDomain::GDomain : Invalid arguments" ).ThrowAsJavaScriptException();
    };

    ~GDomain()
    {
        if ( pDomain ) delete pDomain;
    };

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "Domain",
            {} );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "Domain" ), func );
        return exports;
    };
};

};  // namespace operations_research
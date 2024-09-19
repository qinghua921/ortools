#pragma once

#include "napi.h"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{

class GLinearRange : public Napi::ObjectWrap< GLinearRange >
{
public:
    static inline Napi::FunctionReference constructor;
    LinearRange*                          pLinearRange = nullptr;

    GLinearRange( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GLinearRange >( info )
    {
        Napi::Env env = info.Env();

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external = info[ 0 ].As< Napi::External< LinearRange > >();
            pLinearRange  = dynamic_cast< LinearRange* >( external.Data() );
            if ( pLinearRange ) return;
        }

        Napi::TypeError::New( env, "operations_research::GLinearRange::GLinearRange : Invalid arguments" ).ThrowAsJavaScriptException();
    };

    // ~GLinearRange()
    // TODO

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "LinearRange",
            {} );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "LinearRange" ), func );
        return exports;
    };
};

};  // namespace operations_research
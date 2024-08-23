#pragma once

#include <napi.h>
#include "ortools/linear_solver/linear_solver.h"
#include "../commonheader.hpp"

namespace operations_research
{
class GLinearRange : public Napi::ObjectWrap< GLinearRange >
{
public:
    static Napi::FunctionReference constructor;
    LinearRange*                   pLinearRange = nullptr;

    GLinearRange( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GLinearRange >( info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external = info[ 0 ].As< Napi::External< LinearRange > >();
            pLinearRange  = dynamic_cast< LinearRange* >( external.Data() );
            if ( pLinearRange ) return;
        }

        ThrowJsError( GLinearRange::GLinearRange Error : Invalid arguments );
    };

    ~GLinearRange()
    {
        if ( pLinearRange )
        {
            delete pLinearRange;
            pLinearRange = nullptr;
        }
    }

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "LinearRange",
            {} );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( "LinearRange", func );
        return exports;
    };
};

Napi::FunctionReference GLinearRange::constructor;

};  // namespace operations_research
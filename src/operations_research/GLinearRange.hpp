#pragma once

#include <napi.h>
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{
class GLinearRange : public Napi::ObjectWrap< GLinearRange >
{
public:
    static Napi::FunctionReference constructor;
    LinearRange*                   pLinearRange;

    GLinearRange( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GLinearRange >( info )
    {
    }

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
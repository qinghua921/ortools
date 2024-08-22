#pragma once

#include <napi.h>
#include "../commonheader.hpp"

namespace operations_research
{

class GClosedInterval : public Napi::ObjectWrap< GClosedInterval >
{
public:
    static Napi::FunctionReference constructor;
    ClosedInterval*                pClosedInterval;

public:
    GClosedInterval( const Napi::CallbackInfo& info );
    ~GClosedInterval();

public:
    static Napi::Object Init( Napi::Env env, Napi::Object exports );
};

Napi::FunctionReference GClosedInterval::constructor;

Napi::Object GClosedInterval::Init( Napi::Env env, Napi::Object exports )
{
    Napi::Function func = DefineClass(
        env,
        "ClosedInterval",
        {
            // InstanceMethod( "Contains", &GDomain::Contains ),  //
        } );

    constructor = Napi::Persistent( func );
    exports.Set( "ClosedInterval", func );
    return exports;
}

GClosedInterval::GClosedInterval( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GClosedInterval >( info )
{
    this->pClosedInterval=nullptr;
}

GClosedInterval::~GClosedInterval()
{
#ifdef DEBUG
    LOG( INFO ) << "GClosedInterval::~GClosedInterval";
#endif
}

}  // namespace operations_research
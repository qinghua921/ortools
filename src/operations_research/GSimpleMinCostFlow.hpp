#pragma once

#include <napi.h>
#include "../commonheader.hpp"
#include "ortools/graph/min_cost_flow.h"

namespace operations_research
{
class GSimpleMinCostFlow : public Napi::ObjectWrap< GSimpleMinCostFlow >
{
public:
    static Napi::FunctionReference constructor;
    SimpleMinCostFlow*             pSimpleMinCostFlow = nullptr;
    GSimpleMinCostFlow( const Napi::CallbackInfo& info );
    ~GSimpleMinCostFlow();
    static Napi::Object Init( Napi::Env env, Napi::Object exports );
};
};  // namespace operations_research

Napi::FunctionReference operations_research::GSimpleMinCostFlow::constructor;

inline operations_research::GSimpleMinCostFlow::GSimpleMinCostFlow( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GSimpleMinCostFlow >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external      = info[ 0 ].As< Napi::External< SimpleMinCostFlow > >();
        pSimpleMinCostFlow = dynamic_cast< SimpleMinCostFlow* >( external.Data() );
        if ( pSimpleMinCostFlow != nullptr ) return;
    }

    if ( info.Length() == 0 )
    {
        pSimpleMinCostFlow = new SimpleMinCostFlow();
        return;
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::GSimpleMinCostFlow : Invalid argument );
}

inline operations_research::GSimpleMinCostFlow::~GSimpleMinCostFlow()
{
    delete pSimpleMinCostFlow;
}

inline Napi::Object operations_research::GSimpleMinCostFlow::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "SimpleMinCostFlow",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "SimpleMinCostFlow" ), func );
    return exports;
}

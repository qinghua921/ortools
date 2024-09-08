#pragma once

#include <napi.h>
#include "../../commonheader.hpp"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
    class GIntervalVar : public Napi::ObjectWrap< GIntervalVar >
    {
    public:
        static Napi::FunctionReference constructor;
        IntervalVar*                   pIntervalVar = nullptr;
        GIntervalVar( const Napi::CallbackInfo& info );
        ~GIntervalVar();
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
    };
};  // namespace sat
};  // namespace operations_research

Napi::FunctionReference operations_research::sat::GIntervalVar::constructor;

inline operations_research::sat::GIntervalVar::GIntervalVar( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GIntervalVar >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< IntervalVar > >();
        pIntervalVar  = dynamic_cast< IntervalVar* >( external.Data() );
        if ( pIntervalVar != nullptr ) return;
    }

    ThrowJsError( operations_research::GIntervalVar::GIntervalVar : Invalid argument );
}

inline operations_research::sat::GIntervalVar::~GIntervalVar()
{
    delete pIntervalVar;
}

inline Napi::Object operations_research::sat::GIntervalVar::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "IntervalVar",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "IntervalVar" ), func );
    return exports;
}

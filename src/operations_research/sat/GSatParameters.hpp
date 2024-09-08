#pragma once

#include <napi.h>
#include "../../commonheader.hpp"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
    class GSatParameters : public Napi::ObjectWrap< GSatParameters >
    {
    public:
        static Napi::FunctionReference constructor;
        SatParameters*                 pSatParameters = nullptr;
        GSatParameters( const Napi::CallbackInfo& info );
        ~GSatParameters();
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
    };
};  // namespace sat
};  // namespace operations_research

Napi::FunctionReference operations_research::sat::GSatParameters::constructor;

inline operations_research::sat::GSatParameters::GSatParameters( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GSatParameters >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external  = info[ 0 ].As< Napi::External< SatParameters > >();
        pSatParameters = dynamic_cast< SatParameters* >( external.Data() );
        if ( pSatParameters != nullptr ) return;
    }

    ThrowJsError( operations_research::GSatParameters::GSatParameters : Invalid argument );
}

inline operations_research::sat::GSatParameters::~GSatParameters()
{
    delete pSatParameters;
}

inline Napi::Object operations_research::sat::GSatParameters::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "SatParameters",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "SatParameters" ), func );
    return exports;
}

#pragma once


#include "commonheader.hpp"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
    class GDecisionStrategyProto : public Napi::ObjectWrap< GDecisionStrategyProto >
    {
    public:
        static Napi::FunctionReference constructor;
        DecisionStrategyProto*                          pDecisionStrategyProto = nullptr;
        GDecisionStrategyProto( const Napi::CallbackInfo& info );
        ~GDecisionStrategyProto();
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
    };
};  // namespace sat
};  // namespace operations_research

Napi::FunctionReference operations_research::sat::GDecisionStrategyProto::constructor;

inline operations_research::sat::GDecisionStrategyProto::GDecisionStrategyProto( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GDecisionStrategyProto >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< DecisionStrategyProto > >();
        pDecisionStrategyProto         = dynamic_cast< DecisionStrategyProto* >( external.Data() );
        if ( pDecisionStrategyProto != nullptr ) return;
    }

    ThrowJsError( operations_research::GDecisionStrategyProto::GDecisionStrategyProto : Invalid argument );
}

inline operations_research::sat::GDecisionStrategyProto::~GDecisionStrategyProto()
{
    delete pDecisionStrategyProto;
}

inline Napi::Object operations_research::sat::GDecisionStrategyProto::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "DecisionStrategyProto",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "DecisionStrategyProto" ), func );
    return exports;
}

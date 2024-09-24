#pragma once

#include "napi.h"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
    class GIntervalVar : public Napi::ObjectWrap< GIntervalVar >
    {
    public:
        static inline Napi::FunctionReference constructor;
        IntervalVar*                          pIntervalVar = nullptr;

        GIntervalVar( const Napi::CallbackInfo& info )
            : Napi::ObjectWrap< GIntervalVar >( info )
        {
            Napi::Env env = info.Env();

            if ( info.Length() == 1 && info[ 0 ].IsExternal() )
            {
                auto external = info[ 0 ].As< Napi::External< IntervalVar > >();
                pIntervalVar  = dynamic_cast< IntervalVar* >( external.Data() );
                if ( pIntervalVar ) return;
            }

            Napi::TypeError::New( env, "operations_research::GIntervalVar::GIntervalVar : Invalid arguments" ).ThrowAsJavaScriptException();
        };

        ~GIntervalVar()
        {
            if ( pIntervalVar ) delete pIntervalVar;
        };

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "IntervalVar",
                {} );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "IntervalVar" ), func );
            return exports;
        };
    };
}  // namespace sat

};  // namespace operations_research
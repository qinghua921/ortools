#pragma once

#include "napi.h"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{

    class GConstraint : public Napi::ObjectWrap< GConstraint >
    {
    public:
        static inline Napi::FunctionReference constructor;
        Constraint*                           pConstraint = nullptr;

        GConstraint( const Napi::CallbackInfo& info )
            : Napi::ObjectWrap< GConstraint >( info )
        {
            Napi::Env env = info.Env();

            if ( info.Length() == 1 && info[ 0 ].IsExternal() )
            {
                auto external = info[ 0 ].As< Napi::External< Constraint > >();
                pConstraint   = dynamic_cast< Constraint* >( external.Data() );
                if ( pConstraint ) return;
            }

            Napi::TypeError::New( env, "operations_research::GConstraint::GConstraint : Invalid arguments" ).ThrowAsJavaScriptException();
        };

        // TODO delete pConstraint or not ?
        // ~GConstraint()
        // {
        //     if ( pConstraint ) delete pConstraint;
        // };

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "Constraint",
                {} );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "Constraint" ), func );
            return exports;
        };
    };
}  // namespace sat

};  // namespace operations_research
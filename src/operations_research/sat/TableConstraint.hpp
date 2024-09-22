#pragma once

#include "napi.h"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{

    class GTableConstraint : public Napi::ObjectWrap< GTableConstraint >
    {
    public:
        static inline Napi::FunctionReference constructor;
        TableConstraint*                      pTableConstraint = nullptr;

        GTableConstraint( const Napi::CallbackInfo& info )
            : Napi::ObjectWrap< GTableConstraint >( info )
        {
            Napi::Env env = info.Env();

            if ( info.Length() == 1 && info[ 0 ].IsExternal() )
            {
                auto external    = info[ 0 ].As< Napi::External< TableConstraint > >();
                pTableConstraint = dynamic_cast< TableConstraint* >( external.Data() );
                if ( pTableConstraint ) return;
            }

            Napi::TypeError::New( env, "operations_research::GTableConstraint::GTableConstraint : Invalid arguments" ).ThrowAsJavaScriptException();
        };

        // TODO delete pTableConstraint or not ?
        // ~GTableConstraint()
        // {
        //     if ( pTableConstraint ) delete pTableConstraint;
        // };

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "TableConstraint",
                {} );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "TableConstraint" ), func );
            return exports;
        };
    };
}  // namespace sat

};  // namespace operations_research
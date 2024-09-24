#pragma once

#include "napi.h"

namespace operations_research
{
namespace sat
{
    class GNoOverlap2DConstraint : public Napi::ObjectWrap< GNoOverlap2DConstraint >
    {
    public:
        static inline Napi::FunctionReference constructor;
        NoOverlap2DConstraint*                pNoOverlap2DConstraint = nullptr;

        GNoOverlap2DConstraint( const Napi::CallbackInfo& info )
            : Napi::ObjectWrap< GNoOverlap2DConstraint >( info )
        {
            Napi::Env env = info.Env();

            if ( info.Length() == 1 && info[ 0 ].IsExternal() )
            {
                auto external          = info[ 0 ].As< Napi::External< NoOverlap2DConstraint > >();
                pNoOverlap2DConstraint = dynamic_cast< NoOverlap2DConstraint* >( external.Data() );
                if ( pNoOverlap2DConstraint ) return;
            }

            Napi::TypeError::New( env, "operations_research::GNoOverlap2DConstraint::GNoOverlap2DConstraint : Invalid arguments" ).ThrowAsJavaScriptException();
        };

        ~GNoOverlap2DConstraint()
        {
            if ( pNoOverlap2DConstraint ) delete pNoOverlap2DConstraint;
        };

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "NoOverlap2DConstraint",
                {} );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "NoOverlap2DConstraint" ), func );
            return exports;
        };
    };
}  // namespace sat

};  // namespace operations_research
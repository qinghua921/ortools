#pragma once

#include "napi.h"

namespace operations_research
{
namespace sat
{

    class GLinearExpr : public Napi::ObjectWrap< GLinearExpr >
    {
    public:
        static inline Napi::FunctionReference constructor;
        LinearExpr*                           pLinearExpr = nullptr;

        GLinearExpr( const Napi::CallbackInfo& info )
            : Napi::ObjectWrap< GLinearExpr >( info )
        {
            Napi::Env env = info.Env();

            if ( info.Length() == 1 && info[ 0 ].IsExternal() )
            {
                auto external = info[ 0 ].As< Napi::External< LinearExpr > >();
                pLinearExpr   = dynamic_cast< LinearExpr* >( external.Data() );
                if ( pLinearExpr ) return;
            }

            Napi::TypeError::New( env, "operations_research::GLinearExpr::GLinearExpr : Invalid arguments" ).ThrowAsJavaScriptException();
        };

        ~GLinearExpr()
        {
            if ( pLinearExpr ) delete pLinearExpr;
        };

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "LinearExpr",
                {} );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "LinearExpr" ), func );
            return exports;
        };
    };
}  // namespace sat

};  // namespace operations_research
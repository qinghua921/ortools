#pragma once

#include "napi.h"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{

    class GIntVar : public Napi::ObjectWrap< GIntVar >
    {
    public:
        static inline Napi::FunctionReference constructor;
        IntVar*                               pIntVar = nullptr;

        GIntVar( const Napi::CallbackInfo& info )
            : Napi::ObjectWrap< GIntVar >( info )
        {
            Napi::Env env = info.Env();

            if ( info.Length() == 1 && info[ 0 ].IsExternal() )
            {
                auto external = info[ 0 ].As< Napi::External< IntVar > >();
                pIntVar       = dynamic_cast< IntVar* >( external.Data() );
                if ( pIntVar ) return;
            }

            // IntVar() = default;
            if ( info.Length() == 0 )
            {
                pIntVar = new IntVar();
                return;
            }

            // explicit IntVar( const BoolVar& var );
            if ( info.Length() == 1 && info[ 0 ].IsObject()
                 && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
            {
                auto gBoolVar = GBoolVar::Unwrap( info[ 0 ].As< Napi::Object >() );
                pIntVar       = new IntVar( *gBoolVar->pBoolVar );
                return;
            }

            Napi::TypeError::New( env, "operations_research::GIntVar::GIntVar : Invalid arguments" ).ThrowAsJavaScriptException();
        };

        ~GIntVar()
        {
            if ( pIntVar ) delete pIntVar;
        };

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "IntVar",
                {
                    InstanceMethod( "WithName", &GIntVar::WithName ),
                } );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "IntVar" ), func );
            return exports;
        };

        // IntVar WithName( absl::string_view name );
        Napi::Value WithName( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            if ( info.Length() == 1 && info[ 0 ].IsString() )
            {
                std::string name = info[ 0 ].As< Napi::String >().Utf8Value();
                pIntVar->WithName( name );
                return this->Value();
            }

            Napi::TypeError::New( env, "operations_research::sat::GIntVar::WithName : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        };
    };
}  // namespace sat

};  // namespace operations_research
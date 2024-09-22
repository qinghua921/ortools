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

        ~GTableConstraint()
        {
            if ( pTableConstraint ) delete pTableConstraint;
        };

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "TableConstraint",
                {
                    InstanceMethod( "AddTuple", &GTableConstraint::AddTuple ),
                } );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "TableConstraint" ), func );
            return exports;
        };

        // void AddTuple( absl::Span< const int64_t > tuple );
        Napi::Value AddTuple( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            if ( info.Length() == 1 && info[ 0 ].IsArray() )
            {
                Napi::Array            arr = info[ 0 ].As< Napi::Array >();
                std::vector< int64_t > tuple;
                for ( int i = 0; i < arr.Length(); i++ )
                {
                    tuple.push_back( arr.Get( i ).As< Napi::Number >().Int64Value() );
                }
                pTableConstraint->AddTuple( tuple );
                return env.Undefined();
            }

            Napi::TypeError::New( env, "operations_research::GTableConstraint::AddTuple : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Undefined();
        };
    };
}  // namespace sat

};  // namespace operations_research
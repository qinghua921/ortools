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

        ~GConstraint()
        {
            if ( pConstraint ) delete pConstraint;
        };

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "Constraint",
                {
                    InstanceMethod( "OnlyEnforceIf", &GConstraint::OnlyEnforceIf ),
                } );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "Constraint" ), func );
            return exports;
        };

                Napi::Value OnlyEnforceIf( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            // Constraint OnlyEnforceIf( absl::Span< const BoolVar > literals );
            if ( info.Length() == 1 && info[ 0 ].IsArray() )
            {
                Napi::Array            literals = info[ 0 ].As< Napi::Array >();
                std::vector< BoolVar > bool_vars;
                for ( int i = 0; i < literals.Length(); i++ )
                {
                    Napi::Value value = literals[ i ];
                    if ( value.IsObject() && value.As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
                    {
                        GBoolVar* gboolvar = GBoolVar::Unwrap( value.As< Napi::Object >() );
                        bool_vars.push_back( *gboolvar->pBoolVar );
                        continue;
                    }

                    Napi::TypeError::New( env, "operations_research::GConstraint::OnlyEnforceIf : Invalid arguments" ).ThrowAsJavaScriptException();
                    return env.Null();
                }
                auto result = pConstraint->OnlyEnforceIf( bool_vars );
                return GConstraint::constructor.New( { Napi::External< Constraint >::New( env, new Constraint( result ) ) } );
            }

            // Constraint OnlyEnforceIf( BoolVar literal );
            if ( info.Length() == 1 && info[ 0 ].IsObject() && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
            {
                GBoolVar* gboolvar = GBoolVar::Unwrap( info[ 0 ].As< Napi::Object >() );
                auto      result   = pConstraint->OnlyEnforceIf( *gboolvar->pBoolVar );
                return GConstraint::constructor.New( { Napi::External< Constraint >::New( env, new Constraint( result ) ) } );
            }

            Napi::TypeError::New( env, "operations_research::GConstraint::OnlyEnforceIf : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        };
    };
}  // namespace sat

};  // namespace operations_research
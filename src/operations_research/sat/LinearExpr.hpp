#pragma once

#include "napi.h"
#include "ortools/sat/cp_model.h"

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

            // LinearExpr() = default;
            if ( info.Length() == 0 )
            {
                pLinearExpr = new LinearExpr();
                return;
            }

            // LinearExpr( BoolVar var );
            if ( info.Length() == 1 && info[ 0 ].IsObject()
                 && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
            {
                auto var    = GBoolVar::Unwrap( info[ 0 ].As< Napi::Object >() );
                pLinearExpr = new LinearExpr( *var->pBoolVar );
                return;
            }

            // LinearExpr( IntVar var );
            if ( info.Length() == 1 && info[ 0 ].IsObject()
                 && info[ 0 ].As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
            {
                auto var    = GIntVar::Unwrap( info[ 0 ].As< Napi::Object >() );
                pLinearExpr = new LinearExpr( *var->pIntVar );
                return;
            }

            //  LinearExpr( int64_t constant );
            if ( info.Length() == 1 && info[ 0 ].IsNumber() )
            {
                int64_t constant = info[ 0 ].As< Napi::Number >().Int64Value();
                pLinearExpr      = new LinearExpr( constant );
                return;
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
                {
                    InstanceMethod( "operator_plus_equals", &GLinearExpr::operator_plus_equals ),
                    StaticMethod( "Sum", &GLinearExpr::Sum ),
                } );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "LinearExpr" ), func );
            return exports;
        };

        // static LinearExpr Sum( absl::Span< const IntVar > vars );
        static Napi::Value Sum( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            std::vector< IntVar > vars;
            if ( info.Length() == 1 && info[ 0 ].IsArray() )
            {
                Napi::Array arr = info[ 0 ].As< Napi::Array >();
                for ( int i = 0; i < arr.Length(); i++ )
                {
                    if ( arr.Get( i ).IsObject() && arr.Get( i ).As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
                    {
                        auto var = GIntVar::Unwrap( arr.Get( i ).As< Napi::Object >() );
                        vars.push_back( *var->pIntVar );
                    }
                    else
                    {
                        Napi::TypeError::New( env, "operations_research::sat::GLinearExpr::Sum : Invalid arguments" ).ThrowAsJavaScriptException();
                        return env.Null();
                    }
                }

                LinearExpr expr = LinearExpr::Sum( vars );
                return GLinearExpr::constructor.New( { Napi::External< LinearExpr >::New( env, new LinearExpr( expr ) ) } );
            }

            Napi::TypeError::New( env, "operations_research::sat::GLinearExpr::Sum : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        }

        // LinearExpr& operator+=( const LinearExpr& other );
        Napi::Value operator_plus_equals( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            LinearExpr other;
            if ( info.Length() == 1 && ToLinearExpr( info[ 0 ], other ) )
            {
                *pLinearExpr += other;
                return this->Value();
            }

            Napi::TypeError::New( env, "operations_research::sat::GLinearExpr::operator_plus_equals : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        }

        static bool ToLinearExpr( const Napi::Value& value, LinearExpr& expr )
        {
            if ( value.IsObject() && value.As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
                expr = *GLinearExpr::Unwrap( value.As< Napi::Object >() )->pLinearExpr;
            else if ( value.IsNumber() )
                expr = value.As< Napi::Number >().DoubleValue();
            else if ( value.IsObject() && value.As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
                expr = *GBoolVar::Unwrap( value.As< Napi::Object >() )->pBoolVar;
            else if ( value.IsObject() && value.As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
                expr = *GIntVar::Unwrap( value.As< Napi::Object >() )->pIntVar;
            else
                return false;

            return true;
        }
    };
}  // namespace sat

};  // namespace operations_research
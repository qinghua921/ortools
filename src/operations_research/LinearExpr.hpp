#pragma once

#include "napi.h"
#include "ortools/linear_solver/linear_solver.h"
#include "MPVariable.hpp"

namespace operations_research
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

        // LinearExpr();
        if ( info.Length() == 0 )
        {
            pLinearExpr = new LinearExpr();
            return;
        }

        // LinearExpr( double constant );  // NOLINT
        if ( info.Length() == 1 && info[ 0 ].IsNumber() )
        {
            double constant = info[ 0 ].As< Napi::Number >().DoubleValue();
            pLinearExpr     = new LinearExpr( constant );
            return;
        }

        // LinearExpr( const MPVariable* var );  // NOLINT
        if ( info.Length() == 1 && info[ 0 ].IsObject() && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
        {
            MPVariable* var = GMPVariable::Unwrap( info[ 0 ].As< Napi::Object >() )->pMPVariable;
            pLinearExpr     = new LinearExpr( var );
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
                InstanceMethod( "operator_times_equals", &GLinearExpr::operator_times_equals ),
                StaticMethod( "NotVar", &GLinearExpr::NotVar ),
                InstanceMethod( "operator_minus_equals", &GLinearExpr::operator_minus_equals ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "LinearExpr" ), func );
        return exports;
    };
    
    // LinearExpr& operator-=( const LinearExpr& rhs );
    Napi::Value operator_minus_equals( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        LinearExpr rhs;
        if ( info.Length() == 1 && ToLinearExpr( info[ 0 ], rhs ) )
        {
            *pLinearExpr -= rhs;
            return this->Value();
        }

        Napi::TypeError::New( env, "LinearExpr::operator-= : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // static LinearExpr NotVar( LinearExpr var );
    static Napi::Value NotVar( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
        {
            LinearExpr* pLinearExpr = GLinearExpr::Unwrap( info[ 0 ].As< Napi::Object >() )->pLinearExpr;
            LinearExpr  result      = LinearExpr::NotVar( *pLinearExpr );
            return GLinearExpr::constructor.New( { Napi::External< LinearExpr >::New( env, new LinearExpr( result ) ) } );
        }

        Napi::TypeError::New( env, "LinearExpr::NotVar : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // LinearExpr& operator*=( double rhs );
    Napi::Value operator_times_equals( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsNumber() )
        {
            double rhs = info[ 0 ].As< Napi::Number >().DoubleValue();
            *pLinearExpr *= rhs;
            return this->Value();
        }

        Napi::TypeError::New( env, "LinearExpr::operator*= : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // LinearExpr& operator+=( const LinearExpr& rhs );
    Napi::Value operator_plus_equals( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        LinearExpr rhs;
        if ( info.Length() == 1 && ToLinearExpr( info[ 0 ], rhs ) )
        {
            *pLinearExpr += rhs;
            return this->Value();
        }

        Napi::TypeError::New( env, "LinearExpr::operator+= : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    static bool ToLinearExpr( const Napi::Value& value, LinearExpr& expr )
    {
        if ( value.IsObject() && value.As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
            expr = *GLinearExpr::Unwrap( value.As< Napi::Object >() )->pLinearExpr;
        else if ( value.IsNumber() )
            expr = value.As< Napi::Number >().DoubleValue();
        else if ( value.IsObject() && value.As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
            expr = GMPVariable::Unwrap( value.As< Napi::Object >() )->pMPVariable;
        else
            return false;

        return true;
    }
};

};  // namespace operations_research
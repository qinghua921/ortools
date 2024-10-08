#pragma once

#include "napi.h"
#include "LinearExpr.hpp"
#include "SatParameters.hpp"

namespace operations_research
{
namespace sat
{
    // inline LinearExpr operator*( LinearExpr expr, int64_t factor )
    Napi::Value Goperator_times( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        LinearExpr expr;
        if ( info.Length() == 2 && GLinearExpr::ToLinearExpr( info[ 0 ], expr ) && info[ 1 ].IsNumber() )
        {
            int64_t factor = info[ 1 ].As< Napi::Number >().Int64Value();
            auto    result = expr * factor;
            return GLinearExpr::constructor.New( { Napi::External< LinearExpr >::New( env, new LinearExpr( result ) ) } );
        }

        Napi::TypeError::New( env, "operations_research::sat::operator_times : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }

    // CpSolverResponse Solve( const CpModelProto& model_proto );
    Napi::Value GSolve( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GCpModelProto::constructor.Value() ) )
        {
            auto model_proto       = GCpModelProto::Unwrap( info[ 0 ].As< Napi::Object >() );
            auto response          = Solve( *model_proto->pCpModelProto );
            auto external_response = Napi::External< CpSolverResponse >::New( env, new CpSolverResponse( response ) );
            return GCpSolverResponse::constructor.New( { external_response } );
        }

        Napi::TypeError::New( env, "operations_research::Solve : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }

    // BoolVar Not( BoolVar x );
    Napi::Value GNot( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
        {
            auto x      = GBoolVar::Unwrap( info[ 0 ].As< Napi::Object >() );
            auto result = Not( *x->pBoolVar );
            return GBoolVar::constructor.New( { Napi::External< BoolVar >::New( env, new BoolVar( result ) ) } );
        }

        Napi::TypeError::New( env, "operations_research::Not : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }

    // CpSolverResponse SolveWithParameters( const CpModelProto&  model_proto,
    //                                        const SatParameters& params );
    Napi::Value GSolveWithParameters( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );
        if ( info.Length() == 2
             && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GCpModelProto::constructor.Value() )
             && info[ 1 ].IsObject()
             && info[ 1 ].As< Napi::Object >().InstanceOf( GSatParameters::constructor.Value() ) )
        {
            auto model_proto       = GCpModelProto::Unwrap( info[ 0 ].As< Napi::Object >() );
            auto params            = GSatParameters::Unwrap( info[ 1 ].As< Napi::Object >() );
            auto response          = SolveWithParameters( *model_proto->pCpModelProto, *params->pSatParameters );
            auto external_response = Napi::External< CpSolverResponse >::New( env, new CpSolverResponse( response ) );
            return GCpSolverResponse::constructor.New( { external_response } );
        }

        Napi::TypeError::New( env, "operations_research::SolveWithParameters : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }

    static Napi::Object FuncInit( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );

        exports.Set( "SolveWithParameters", Napi::Function::New( env, GSolveWithParameters ) );
        exports.Set( "Not", Napi::Function::New( env, GNot ) );
        exports.Set( "Solve", Napi::Function::New( env, GSolve ) );
        exports.Set( "operator_times", Napi::Function::New( env, Goperator_times ) );

        return exports;
    };

};  // namespace sat
};  // namespace operations_research
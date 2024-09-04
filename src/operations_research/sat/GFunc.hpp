#pragma once

#include <napi.h>
#include "GLinearExpr.hpp"
#include "GCpModelProto.hpp"
#include "GCpSolverResponse.hpp"
#include "../../commonheader.hpp"

namespace operations_research
{
namespace sat
{

    static Napi::Object GFuncInit( Napi::Env env, Napi::Object exports );

    Napi::Value GCpSolverResponseStats( const Napi::CallbackInfo& info );
    Napi::Value GSolutionIntegerValue( const Napi::CallbackInfo& info );
    Napi::Value GSolve( const Napi::CallbackInfo& info );
    Napi::Value Goperator_negate( const Napi::CallbackInfo& info );
    Napi::Value Goperator_plus( const Napi::CallbackInfo& info );
    Napi::Value Goperator_minus( const Napi::CallbackInfo& info );
    Napi::Value Goperator_times( const Napi::CallbackInfo& info );

};  // namespace sat
};  // namespace operations_research

inline Napi::Object operations_research::sat::GFuncInit( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );

    exports.Set( Napi::String::New( env, "Solve" ), Napi::Function::New( env, GSolve ) );
    exports.Set( Napi::String::New( env, "operator_negate" ), Napi::Function::New( env, Goperator_negate ) );
    exports.Set( Napi::String::New( env, "operator_plus" ), Napi::Function::New( env, Goperator_plus ) );
    exports.Set( Napi::String::New( env, "operator_minus" ), Napi::Function::New( env, Goperator_minus ) );
    exports.Set( Napi::String::New( env, "operator_times" ), Napi::Function::New( env, Goperator_times ) );
    exports.Set( Napi::String::New( env, "SolutionIntegerValue" ), Napi::Function::New( env, GSolutionIntegerValue ) );
    exports.Set( Napi::String::New( env, "CpSolverResponseStats" ), Napi::Function::New( env, GCpSolverResponseStats ) );
    return exports;
}

Napi::Value operations_research::sat::GCpSolverResponseStats( const Napi::CallbackInfo& info )
{
    //    std::string CpSolverResponseStats( const CpSolverResponse& response,
    //     bool                    has_objective = true );
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GCpSolverResponse::constructor.Value() ) )
    {
        auto solver_response = GCpSolverResponse::Unwrap( info[ 0 ].As< Napi::Object >() );
        return Napi::String::New( info.Env(), CpSolverResponseStats( *solver_response->pCpSolverResponse ) );
    }

    if ( info.Length() == 2
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GCpSolverResponse::constructor.Value() )
         && info[ 1 ].IsBoolean() )
    {
        auto solver_response = GCpSolverResponse::Unwrap( info[ 0 ].As< Napi::Object >() );
        bool has_objective   = info[ 1 ].As< Napi::Boolean >().Value();
        return Napi::String::New( info.Env(), CpSolverResponseStats( *solver_response->pCpSolverResponse, has_objective ) );
    }

    ThrowJsError( operations_research::sat::CpSolverResponseStats : Invalid arguments );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::GSolutionIntegerValue( const Napi::CallbackInfo& info )
{
    // int64_t SolutionIntegerValue( const CpSolverResponse& r, const LinearExpr& expr );
    LinearExpr expr;
    if ( info.Length() == 2
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GCpSolverResponse::constructor.Value() )
         && GLinearExpr::ToLinearExpr( info[ 1 ], expr ) )
    {
        auto solver_response = GCpSolverResponse::Unwrap( info[ 0 ].As< Napi::Object >() );
        return Napi::Number::New( info.Env(), SolutionIntegerValue( *solver_response->pCpSolverResponse, expr ) );
    }

    ThrowJsError( operations_research::sat::SolutionIntegerValue : Invalid arguments );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::GSolve( const Napi::CallbackInfo& info )
{
    // CpSolverResponse Solve( const CpModelProto& model_proto );
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GCpModelProto::constructor.Value() ) )
    {
        auto model_proto      = GCpModelProto::Unwrap( info[ 0 ].As< Napi::Object >() );
        auto cpSolverResponse = Solve( *model_proto->pCpModelProto );
        auto exterior         = Napi::External< CpSolverResponse >::New( info.Env(), new CpSolverResponse( cpSolverResponse ) );
        return GCpSolverResponse::constructor.New( { exterior } );
    }

    ThrowJsError( operations_research::sat::GSolve : Invalid arguments );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::Goperator_negate( const Napi::CallbackInfo& info )
{
    // inline LinearExpr operator-( LinearExpr expr )
    LinearExpr expr;
    if ( info.Length() == 1 && GLinearExpr::ToLinearExpr( info[ 0 ], expr ) )
    {
        auto result   = -expr;
        auto exterior = Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) );
        return GLinearExpr::constructor.New( { exterior } );
    }

    ThrowJsError( operations_research::sat::Goperator_negate : Invalid arguments );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::Goperator_plus( const Napi::CallbackInfo& info )
{
    // inline LinearExpr operator+( const LinearExpr& lhs, const LinearExpr& rhs )
    LinearExpr lhs;
    LinearExpr rhs;
    if ( info.Length() == 2
         && GLinearExpr::ToLinearExpr( info[ 0 ], lhs )
         && GLinearExpr::ToLinearExpr( info[ 1 ], rhs ) )
    {
        auto result   = lhs + rhs;
        auto exterior = Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) );
        return GLinearExpr::constructor.New( { exterior } );
    }

    ThrowJsError( operations_research::sat::Goperator_plus : Invalid arguments );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::Goperator_minus( const Napi::CallbackInfo& info )
{
    // inline LinearExpr operator-( const LinearExpr& lhs, const LinearExpr& rhs )
    LinearExpr lhs;
    LinearExpr rhs;
    if ( info.Length() == 2
         && GLinearExpr::ToLinearExpr( info[ 0 ], lhs )
         && GLinearExpr::ToLinearExpr( info[ 1 ], rhs ) )
    {
        auto result   = lhs - rhs;
        auto exterior = Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) );
        return GLinearExpr::constructor.New( { exterior } );
    }

    ThrowJsError( operations_research::sat::Goperator_minus : Invalid arguments );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::Goperator_times( const Napi::CallbackInfo& info )
{
    // inline LinearExpr operator*( LinearExpr expr, int64_t factor )
    LinearExpr expr;
    if ( info.Length() == 2 && GLinearExpr::ToLinearExpr( info[ 0 ], expr ) && info[ 1 ].IsNumber() )
    {
        int64_t factor   = info[ 1 ].As< Napi::Number >().Int64Value();
        auto    result   = expr * factor;
        auto    exterior = Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) );
        return GLinearExpr::constructor.New( { exterior } );
    }

    // inline LinearExpr operator*( int64_t factor, LinearExpr expr )
    if ( info.Length() == 2 && GLinearExpr::ToLinearExpr( info[ 1 ], expr ) && info[ 0 ].IsNumber() )
    {
        int64_t factor   = info[ 0 ].As< Napi::Number >().Int64Value();
        auto    result   = expr * factor;
        auto    exterior = Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) );
        return GLinearExpr::constructor.New( { exterior } );
    }

    ThrowJsError( operations_research::sat::Goperator_times : Invalid arguments );
    return info.Env().Undefined();
};

// inline DoubleLinearExpr operator-( DoubleLinearExpr expr )
// inline DoubleLinearExpr operator+( const DoubleLinearExpr& lhs, const DoubleLinearExpr& rhs )
// inline DoubleLinearExpr operator+( DoubleLinearExpr&&      lhs, const DoubleLinearExpr& rhs )
// inline DoubleLinearExpr operator+( const DoubleLinearExpr& lhs, DoubleLinearExpr&&      rhs )
// inline DoubleLinearExpr operator+( DoubleLinearExpr&& lhs, DoubleLinearExpr&& rhs )
// inline DoubleLinearExpr operator+( DoubleLinearExpr expr, double rhs )
// inline DoubleLinearExpr operator+( double lhs, DoubleLinearExpr expr )
// inline DoubleLinearExpr operator-( const DoubleLinearExpr& lhs, const DoubleLinearExpr& rhs )
// inline DoubleLinearExpr operator-( DoubleLinearExpr&&      lhs, const DoubleLinearExpr& rhs )
// inline DoubleLinearExpr operator-( const DoubleLinearExpr& lhs, DoubleLinearExpr&&      rhs )
// inline DoubleLinearExpr operator-( DoubleLinearExpr&& lhs, DoubleLinearExpr&& rhs )
// inline DoubleLinearExpr operator-( DoubleLinearExpr epxr, double rhs )
// inline DoubleLinearExpr operator-( double lhs, DoubleLinearExpr expr )
// inline DoubleLinearExpr operator*( DoubleLinearExpr expr, double factor )
// inline DoubleLinearExpr operator*( double factor, DoubleLinearExpr expr )

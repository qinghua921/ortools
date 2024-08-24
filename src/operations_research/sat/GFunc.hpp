#pragma once

#include <napi.h>
#include "../../commonheader.hpp"
#include "GDoubleLinearExpr.hpp"
#include "GCpModelProto.hpp"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
    Napi::Value Goperator_neg( const Napi::CallbackInfo& info )
    {
        // inline LinearExpr operator-( LinearExpr expr )
        if ( info.Length() == 1
             && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
        {
            auto expr   = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
            auto result = -*expr->pLinearExpr;
            auto ext    = Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) );
            return GLinearExpr::constructor.New( { ext } );
        }

        // inline DoubleLinearExpr operator-( DoubleLinearExpr expr )
        if ( info.Length() == 1
             && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GDoubleLinearExpr::constructor.Value() ) )
        {
            auto expr   = Napi::ObjectWrap< GDoubleLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
            auto result = -*expr->pDoubleLinearExpr;
            auto ext    = Napi::External< DoubleLinearExpr >::New( info.Env(), new DoubleLinearExpr( result ) );
            return GDoubleLinearExpr::constructor.New( { ext } );
        }

        ThrowJsError( sat::Goperator_neg : Invalid argument );
        return info.Env().Undefined();
    }

    // TODO: check if this is correct
    Napi::Value Goperator_plus( const Napi::CallbackInfo& info )
    {
        // inline LinearExpr operator+( LinearExpr&& lhs, LinearExpr&& rhs )
        // inline LinearExpr operator+( LinearExpr&& lhs, const LinearExpr& rhs )
        // inline LinearExpr operator+( const LinearExpr& lhs, LinearExpr&& rhs )
        // inline LinearExpr operator+( const LinearExpr& lhs, const LinearExpr& rhs )
        if ( info.Length() == 2
             && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() )
             && info[ 1 ].IsObject()
             && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
        {
            auto lhs    = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
            auto rhs    = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() );
            auto result = *lhs->pLinearExpr + *rhs->pLinearExpr;
            auto ext    = Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) );
            return GLinearExpr::constructor.New( { ext } );
        }

        // inline DoubleLinearExpr operator+( const DoubleLinearExpr& lhs, DoubleLinearExpr&&      rhs )
        // inline DoubleLinearExpr operator+( DoubleLinearExpr&& lhs, DoubleLinearExpr&& rhs )
        // inline DoubleLinearExpr operator+( DoubleLinearExpr&&      lhs, const DoubleLinearExpr& rhs )
        // inline DoubleLinearExpr operator+( const DoubleLinearExpr& lhs, const DoubleLinearExpr& rhs )
        if ( info.Length() == 2
             && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GDoubleLinearExpr::constructor.Value() )
             && info[ 1 ].IsObject()
             && info[ 1 ].As< Napi::Object >().InstanceOf( GDoubleLinearExpr::constructor.Value() ) )
        {
            auto lhs    = Napi::ObjectWrap< GDoubleLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
            auto rhs    = Napi::ObjectWrap< GDoubleLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() );
            auto result = *lhs->pDoubleLinearExpr + *rhs->pDoubleLinearExpr;
            auto ext    = Napi::External< DoubleLinearExpr >::New( info.Env(), new DoubleLinearExpr( result ) );
            return GDoubleLinearExpr::constructor.New( { ext } );
        }

        // inline DoubleLinearExpr operator+( DoubleLinearExpr expr, double rhs )
        if ( info.Length() == 2
             && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GDoubleLinearExpr::constructor.Value() )
             && info[ 1 ].IsNumber() )
        {
            auto expr   = Napi::ObjectWrap< GDoubleLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
            auto factor = info[ 1 ].As< Napi::Number >().DoubleValue();
            auto result = *expr->pDoubleLinearExpr + factor;
            auto ext    = Napi::External< DoubleLinearExpr >::New( info.Env(), new DoubleLinearExpr( result ) );
            return GDoubleLinearExpr::constructor.New( { ext } );
        }

        // inline DoubleLinearExpr operator+( double lhs, DoubleLinearExpr expr )
        if ( info.Length() == 2
             && info[ 1 ].IsObject()
             && info[ 1 ].As< Napi::Object >().InstanceOf( GDoubleLinearExpr::constructor.Value() )
             && info[ 0 ].IsNumber() )
        {
            auto expr   = Napi::ObjectWrap< GDoubleLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() );
            auto factor = info[ 0 ].As< Napi::Number >().DoubleValue();
            auto result = *expr->pDoubleLinearExpr + factor;
            auto ext    = Napi::External< DoubleLinearExpr >::New( info.Env(), new DoubleLinearExpr( result ) );
            return GDoubleLinearExpr::constructor.New( { ext } );
        }

        ThrowJsError( sat::Goperator_plus : Invalid argument );
        return info.Env().Undefined();
    }

    Napi::Value Goperator_minus( const Napi::CallbackInfo& info )
    {
        // inline LinearExpr operator-( LinearExpr&& lhs, LinearExpr&& rhs )
        // inline LinearExpr operator-( const LinearExpr& lhs, LinearExpr&& rhs )
        // inline LinearExpr operator-( LinearExpr&& lhs, const LinearExpr& rhs )
        // inline LinearExpr operator-( const LinearExpr& lhs, const LinearExpr& rhs )
        if ( info.Length() == 2
             && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() )
             && info[ 1 ].IsObject()
             && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
        {
            auto lhs    = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
            auto rhs    = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() );
            auto result = *lhs->pLinearExpr - *rhs->pLinearExpr;
            auto ext    = Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) );
            return GLinearExpr::constructor.New( { ext } );
        }

        // inline DoubleLinearExpr operator-( DoubleLinearExpr&&      lhs, const DoubleLinearExpr& rhs )
        // inline DoubleLinearExpr operator-( const DoubleLinearExpr& lhs, DoubleLinearExpr&&      rhs )
        // inline DoubleLinearExpr operator-( DoubleLinearExpr&& lhs, DoubleLinearExpr&& rhs )
        // inline DoubleLinearExpr operator-( const DoubleLinearExpr& lhs, const DoubleLinearExpr& rhs )
        if ( info.Length() == 2
             && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GDoubleLinearExpr::constructor.Value() )
             && info[ 1 ].IsObject()
             && info[ 1 ].As< Napi::Object >().InstanceOf( GDoubleLinearExpr::constructor.Value() ) )
        {
            auto lhs    = Napi::ObjectWrap< GDoubleLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
            auto rhs    = Napi::ObjectWrap< GDoubleLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() );
            auto result = *lhs->pDoubleLinearExpr - *rhs->pDoubleLinearExpr;
            auto ext    = Napi::External< DoubleLinearExpr >::New( info.Env(), new DoubleLinearExpr( result ) );
            return GDoubleLinearExpr::constructor.New( { ext } );
        }

        // inline DoubleLinearExpr operator-( DoubleLinearExpr epxr, double rhs )
        if ( info.Length() == 2
             && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GDoubleLinearExpr::constructor.Value() )
             && info[ 1 ].IsNumber() )
        {
            auto expr   = Napi::ObjectWrap< GDoubleLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
            auto factor = info[ 1 ].As< Napi::Number >().DoubleValue();
            auto result = *expr->pDoubleLinearExpr - factor;
            auto ext    = Napi::External< DoubleLinearExpr >::New( info.Env(), new DoubleLinearExpr( result ) );
            return GDoubleLinearExpr::constructor.New( { ext } );
        }

        // inline DoubleLinearExpr operator-( double lhs, DoubleLinearExpr expr )
        if ( info.Length() == 2
             && info[ 1 ].IsObject()
             && info[ 1 ].As< Napi::Object >().InstanceOf( GDoubleLinearExpr::constructor.Value() )
             && info[ 0 ].IsNumber() )
        {
            auto expr   = Napi::ObjectWrap< GDoubleLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() );
            auto factor = info[ 0 ].As< Napi::Number >().DoubleValue();
            auto result = factor - *expr->pDoubleLinearExpr;
            auto ext    = Napi::External< DoubleLinearExpr >::New( info.Env(), new DoubleLinearExpr( result ) );
            return GDoubleLinearExpr::constructor.New( { ext } );
        }

        ThrowJsError( sat::Goperator_minus : Invalid argument );
        return info.Env().Undefined();
    };

    Napi::Value Goperator_times( const Napi::CallbackInfo& info )
    {
        // inline LinearExpr operator*( LinearExpr expr, int64_t factor )
        if ( info.Length() == 2
             && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() )
             && info[ 1 ].IsNumber() )
        {
            auto expr   = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
            auto factor = info[ 1 ].As< Napi::Number >().Int64Value();
            auto result = *expr->pLinearExpr * factor;
            auto ext    = Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) );
            return GLinearExpr::constructor.New( { ext } );
        }

        // inline LinearExpr operator*( BoolVar expr, int64_t factor )
        if ( info.Length() == 2
             && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() )
             && info[ 1 ].IsNumber() )
        {
            auto expr   = Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 0 ].As< Napi::Object >() );
            auto factor = info[ 1 ].As< Napi::Number >().Int64Value();
            auto result = *expr->pBoolVar * factor;
            auto ext    = Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) );
            return GLinearExpr::constructor.New( { ext } );
        }

        // inline LinearExpr operator*( int64_t factor, LinearExpr expr )
        if ( info.Length() == 2
             && info[ 1 ].IsObject()
             && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() )
             && info[ 0 ].IsNumber() )
        {
            auto expr   = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() );
            auto factor = info[ 0 ].As< Napi::Number >().Int64Value();
            auto result = *expr->pLinearExpr * factor;
            auto ext    = Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) );
            return GLinearExpr::constructor.New( { ext } );
        }

        // inline DoubleLinearExpr operator*( DoubleLinearExpr expr, double factor )
        if ( info.Length() == 2
             && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GDoubleLinearExpr::constructor.Value() )
             && info[ 1 ].IsNumber() )
        {
            auto expr   = Napi::ObjectWrap< GDoubleLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
            auto factor = info[ 1 ].As< Napi::Number >().DoubleValue();
            auto result = *expr->pDoubleLinearExpr * factor;
            auto ext    = Napi::External< DoubleLinearExpr >::New( info.Env(), new DoubleLinearExpr( result ) );
            return GDoubleLinearExpr::constructor.New( { ext } );
        }

        // inline DoubleLinearExpr operator*( double factor, DoubleLinearExpr expr )
        if ( info.Length() == 2
             && info[ 1 ].IsObject()
             && info[ 1 ].As< Napi::Object >().InstanceOf( GDoubleLinearExpr::constructor.Value() )
             && info[ 0 ].IsNumber() )
        {
            auto expr   = Napi::ObjectWrap< GDoubleLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() );
            auto factor = info[ 0 ].As< Napi::Number >().DoubleValue();
            auto result = *expr->pDoubleLinearExpr * factor;
            auto ext    = Napi::External< DoubleLinearExpr >::New( info.Env(), new DoubleLinearExpr( result ) );
            return GDoubleLinearExpr::constructor.New( { ext } );
        }

        ThrowJsError( sat::Goperator_times : Invalid argument );
        return info.Env().Undefined();
    }

    // CpSolverResponse Solve( const CpModelProto& model_proto );
    Napi::Value GSolve( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1
             && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GCpModelProto::constructor.Value() ) )
        {
            auto model_proto      = Napi::ObjectWrap< GCpModelProto >::Unwrap( info[ 0 ].As< Napi::Object >() );
            auto cpSolverResponse = Solve( *model_proto->pCpModelProto );
            auto ext              = Napi::External< CpSolverResponse >::New( info.Env(), new CpSolverResponse( cpSolverResponse ) );
            return GCpSolverResponse::constructor.New( { ext } );
        }

        ThrowJsError( sat::Solve : Not implemented );
        return info.Env().Undefined();
    }

    Napi::Object GFuncInit( Napi::Env env, Napi::Object exports )
    {
        exports.Set( "operator_neg", Napi::Function::New( env, Goperator_neg ) );
        exports.Set( "operator_plus", Napi::Function::New( env, Goperator_plus ) );
        exports.Set( "operator_minus", Napi::Function::New( env, Goperator_minus ) );
        exports.Set( "operator_times", Napi::Function::New( env, Goperator_times ) );
        exports.Set( "Solve", Napi::Function::New( env, GSolve ) );
        return exports;
    }

}  // namespace sat
}  // namespace operations_research

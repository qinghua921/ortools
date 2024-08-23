#pragma once

#include <napi.h>
#include "ortools/linear_solver/linear_solver.h"
#include "../commonheader.hpp"
#include "GLinearExpr.hpp"

namespace operations_research
{
class GLinearRange : public Napi::ObjectWrap< GLinearRange >
{
public:
    static Napi::FunctionReference constructor;
    LinearRange*                   pLinearRange = nullptr;

    GLinearRange( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GLinearRange >( info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external = info[ 0 ].As< Napi::External< LinearRange > >();
            pLinearRange  = dynamic_cast< LinearRange* >( external.Data() );
            if ( pLinearRange ) return;
        }

        //     LinearRange() : lower_bound_( 0 ), upper_bound_( 0 ) {}
        if ( info.Length() == 0 )
        {
            pLinearRange = new LinearRange();
            return;
        }

        //     LinearRange( double lower_bound, const LinearExpr& linear_expr, double upper_bound );
        if ( info.Length() == 3
             && info[ 0 ].IsNumber()
             && info[ 1 ].IsObject()
             && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() )
             && info[ 2 ].IsNumber() )
        {
            double lower_bound = info[ 0 ].As< Napi::Number >().DoubleValue();
            auto   linear_expr = GLinearExpr::Unwrap( info[ 1 ].As< Napi::Object >() );
            double upper_bound = info[ 2 ].As< Napi::Number >().DoubleValue();
            pLinearRange       = new LinearRange( lower_bound, *linear_expr->pLinearExpr, upper_bound );
            return;
        }

        ThrowJsError( GLinearRange::GLinearRange Error : Invalid arguments );
    };

    ~GLinearRange()
    {
        if ( pLinearRange )
        {
            delete pLinearRange;
            pLinearRange = nullptr;
        }
    }

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "LinearRange",
            {
                InstanceMethod( "lower_bound", &GLinearRange::lower_bound ),
                InstanceMethod( "linear_expr", &GLinearRange::linear_expr ),
                InstanceMethod( "upper_bound", &GLinearRange::upper_bound ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( "LinearRange", func );
        return exports;
    };

    //     double lower_bound() const
    Napi::Value lower_bound( const Napi::CallbackInfo& info )
    {
        return Napi::Number::New( info.Env(), pLinearRange->lower_bound() );
    };

    //     const LinearExpr& linear_expr() const
    Napi::Value linear_expr( const Napi::CallbackInfo& info )
    {
        auto linear_expr = new LinearExpr( pLinearRange->linear_expr() );
        auto external    = Napi::External< LinearExpr >::New( info.Env(), linear_expr );
        return GLinearExpr::constructor.New( { external } );
    };

    //     double upper_bound() const
    Napi::Value upper_bound( const Napi::CallbackInfo& info )
    {
        return Napi::Number::New( info.Env(), pLinearRange->upper_bound() );
    };
};

Napi::FunctionReference GLinearRange::constructor;

};  // namespace operations_research

// class LinearRange
// {
// };

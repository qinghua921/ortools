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
    LinearRange* pLinearRange = nullptr;

    static Napi::FunctionReference constructor;
    static Napi::Object            Init( Napi::Env env, Napi::Object exports )
    {
        Napi::Function func = DefineClass(
            env,
            "LinearRange",
            {} );

        constructor = Napi::Persistent( func );
        exports.Set( "LinearRange", func );
        return exports;
    };

    /**
     * LinearRange() : lower_bound_(0), upper_bound_(0) {}
     *
     * LinearRange(double lower_bound, const LinearExpr& linear_expr,double upper_bound);
     */
    GLinearRange( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GLinearRange >( info )
    {
        if ( info.Length() == 0 )
        {
            pLinearRange = new LinearRange();
            return;
        }

        if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsObject() && info[ 2 ].IsNumber() )
        {
            double       lower_bound  = info[ 0 ].As< Napi::Number >().DoubleValue();
            GLinearExpr* pGLinearExpr = GLinearExpr::Unwrap( info[ 1 ].As< Napi::Object >() );
            double       upper_bound  = info[ 2 ].As< Napi::Number >().DoubleValue();

            if ( typeid( *pGLinearExpr ) == typeid( GLinearExpr ) )
            {
                pLinearRange = new LinearRange( lower_bound, *pGLinearExpr->pLinearExpr, upper_bound );
                return;
            }
        }

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto pLinearRange = info[ 0 ].As< Napi::External< LinearRange > >().Data();
            if ( typeid( *pLinearRange ) == typeid( LinearRange ) )
            {
                this->pLinearRange = pLinearRange;
                return;
            }
        }

        ThrowJsError( GLinearRange::GLinearRange _set_error_mode );
    }

    ~GLinearRange()
    {
        if ( pLinearRange )
        {
            delete pLinearRange;
            pLinearRange = nullptr;
        }
    }

    //   double lower_bound() const { return lower_bound_; }
    //   const LinearExpr& linear_expr() const { return linear_expr_; }
    //   double upper_bound() const { return upper_bound_; }
};

Napi::FunctionReference GLinearRange::constructor;

}  // namespace operations_research
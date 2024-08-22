#pragma once

#include <napi.h>
#include "ortools/linear_solver/linear_solver.h"
#include "../commonheader.hpp"
#include "GMPVariable.hpp"

namespace operations_research
{

class GLinearExpr : public Napi::ObjectWrap< GLinearExpr >
{
public:
    static Napi::FunctionReference constructor;
    LinearExpr*                    pLinearExpr = nullptr;

    GLinearExpr( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GLinearExpr >( info )
    {
        //     LinearExpr();
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
        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto              external = info[ 0 ].As< Napi::External< const MPVariable > >();
            const MPVariable* var      = dynamic_cast< const MPVariable* >( external.Data() );
            if ( var )
            {
                pLinearExpr = new LinearExpr( var );
                return;
            }
        }

        ThrowJsError( GLinearExpr::GLinearExpr : Invalid number of arguments.);
    };

    ~GLinearExpr()
    {
        if ( pLinearExpr )
        {
            delete pLinearExpr;
            pLinearExpr = nullptr;
        }
    }

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "LinearExpr",
            {
                InstanceMethod( "operator_plus", &GLinearExpr::operator_plus ),
                InstanceMethod( "operator_minus", &GLinearExpr::operator_minus ),
                InstanceMethod( "operator_times", &GLinearExpr::operator_times ),
                InstanceMethod( "operator_divide", &GLinearExpr::operator_divide ),
                InstanceMethod( "operator_negate", &GLinearExpr::operator_negate ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( "LinearExpr", func );
        return exports;
    };

    //     LinearExpr& operator+=( const LinearExpr& rhs );
    Napi::Value operator_plus( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsObject() )
        {
            if ( info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
            {
                auto rhs = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
                pLinearExpr->operator+=( *rhs->pLinearExpr );
                return this->Value();
            }

            if ( info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
            {
                auto rhs = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 0 ].As< Napi::Object >() );
                pLinearExpr->operator+=( rhs->pMPVariable );
                return this->Value();
            }
        }

        ThrowJsError( GLinearExpr::operator_plus : Invalid number of arguments or argument is not a LinearExpr object.);
        return info.Env().Undefined();
    };

    //     LinearExpr& operator-=( const LinearExpr& rhs );
    Napi::Value operator_minus( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsObject() )
        {
            if ( info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
            {
                auto rhs = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
                pLinearExpr->operator-=( *rhs->pLinearExpr );
                return this->Value();
            }

            if ( info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
            {
                auto rhs = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 0 ].As< Napi::Object >() );
                pLinearExpr->operator-=( rhs->pMPVariable );
                return this->Value();
            }
        }

        ThrowJsError( GLinearExpr::operator_minus : Invalid number of arguments or argument is not a LinearExpr object.);
        return info.Env().Undefined();
    };

    //     LinearExpr& operator*=( double rhs );
    Napi::Value operator_times( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsNumber() )
        {
            double rhs = info[ 0 ].As< Napi::Number >().DoubleValue();
            pLinearExpr->operator*=( rhs );
            return this->Value();
        }

        ThrowJsError( GLinearExpr::operator_times : Invalid number of arguments or argument is not a number.);
        return info.Env().Undefined();
    }

    //     LinearExpr& operator/=( double rhs );
    Napi::Value operator_divide( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsNumber() )
        {
            double rhs = info[ 0 ].As< Napi::Number >().DoubleValue();
            pLinearExpr->operator/=( rhs );
            return this->Value();
        }

        ThrowJsError( GLinearExpr::operator_divide : Invalid number of arguments or argument is not a number.);
        return info.Env().Undefined();
    };

    //     LinearExpr  operator-() const;
    Napi::Value operator_negate( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 0 )
        {
            *this->pLinearExpr = -( *pLinearExpr );
            return this->Value();
        }

        ThrowJsError( GLinearExpr::operator_negate : Invalid number of arguments.);
        return info.Env().Undefined();
    };
};

Napi::FunctionReference GLinearExpr::constructor;

};  // namespace operations_research

// class LinearExpr
// {
// public:

//     /**
//      * Returns 1-var.
//      *
//      * NOTE(user): if var is binary variable, this corresponds to the logical
//      * negation of var.
//      * Passing by value is intentional, see the discussion on binary ops.
//      */
//     static LinearExpr NotVar( LinearExpr var );

//     double offset() const
//     {
//         return offset_;
//     }
//     const absl::flat_hash_map< const MPVariable*, double >& terms() const
//     {
//         return terms_;
//     }

//     /**
//      * Evaluates the value of this expression at the solution found.
//      *
//      * It must be called only after calling MPSolver::Solve.
//      */
//     double SolutionValue() const;

//     /**
//      * A human readable representation of this. Variables will be printed in order
//      * of lowest index first.
//      */
//     std::string ToString() const;

// };

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
    LinearExpr* pLinearExpr;

    static Napi::FunctionReference constructor;
    static Napi::Object            Init( Napi::Env env, Napi::Object exports )
    {
        Napi::Function func = DefineClass(
            env,
            "LinearExpr",
            {
                InstanceMethod( "operator_plus", &GLinearExpr::operator_plus ),
            } );

        constructor = Napi::Persistent( func );
        exports.Set( "LinearExpr", func );
        return exports;
    };

    // LinearExpr();
    // LinearExpr( double constant );  // NOLINT
    // LinearExpr( const MPVariable* var );  // NOLINT
    GLinearExpr( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GLinearExpr >( info )
    {
        if ( info.Length() == 0 )
        {
            this->pLinearExpr = new LinearExpr();
            return;
        }

        if ( info.Length() == 1 && info[ 0 ].IsNumber() )
        {
            this->pLinearExpr = new LinearExpr( info[ 0 ].As< Napi::Number >().DoubleValue() );
            return;
        }

        if ( info.Length() == 1 && info[ 0 ].IsObject() )
        {
            GMPVariable* pMPVariable = GMPVariable ::Unwrap( info[ 0 ].As< Napi::Object >() );
            if ( typeid( *pMPVariable ) == typeid( GMPVariable ) )
            {
                this->pLinearExpr = new LinearExpr( pMPVariable->pMPVariable );
                return;
            }
        }

        ThrowJsError( GLinearExpr::GLinearExpr Error );
    }

    ~GLinearExpr()
    {
        if ( this->pLinearExpr )
        {
            delete this->pLinearExpr;
            this->pLinearExpr = nullptr;
        }
    }

    // LinearExpr& operator+=( const LinearExpr& rhs );
    Napi::Value operator_plus( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsObject() )
        {
            GLinearExpr* pGLinearExpr = GLinearExpr::Unwrap( info[ 0 ].As< Napi::Object >() );
            if ( typeid( *pGLinearExpr ) == typeid( GLinearExpr ) )
            {
                *( this->pLinearExpr ) += ( *pGLinearExpr->pLinearExpr );
                return this->Value();
            }

            GMPVariable* pGMPVariable = GMPVariable ::Unwrap( info[ 0 ].As< Napi::Object >() );
            if ( typeid( *pGMPVariable ) == typeid( GMPVariable ) )
            {
                *( this->pLinearExpr ) += ( pGMPVariable->pMPVariable );
                return this->Value();
            }
        }

        ThrowJsError( GLinearExpr::operator_plus Error );
        return info.Env().Undefined();
    }

    // /**
    //  * Returns 1-var.
    //  *
    //  * NOTE(user): if var is binary variable, this corresponds to the logical
    //  * negation of var.
    //  * Passing by value is intentional, see the discussion on binary ops.
    //  */
    // static LinearExpr NotVar( LinearExpr var );

    // LinearExpr& operator-=( const LinearExpr& rhs );
    // LinearExpr& operator*=( double rhs );
    // LinearExpr& operator/=( double rhs );
    // LinearExpr  operator-() const;

    // double offset() const
    // {
    //     return offset_;
    // }
    // const absl::flat_hash_map< const MPVariable*, double >& terms() const
    // {
    //     return terms_;
    // }

    // /**
    //  * Evaluates the value of this expression at the solution found.
    //  *
    //  * It must be called only after calling MPSolver::Solve.
    //  */
    // double SolutionValue() const;

    // /**
    //  * A human readable representation of this. Variables will be printed in order
    //  * of lowest index first.
    //  */
    // std::string ToString() const;
};

Napi::FunctionReference GLinearExpr::constructor;

}  // namespace operations_research
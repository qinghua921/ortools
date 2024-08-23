#pragma once

#include <napi.h>
#include "ortools/sat/cp_model.h"
#include "../../commonheader.hpp"

namespace operations_research
{
namespace sat
{
    class GDoubleLinearExpr : public Napi::ObjectWrap< GDoubleLinearExpr >
    {
    public:
        static Napi::FunctionReference constructor;
        DoubleLinearExpr*              pDoubleLinearExpr = nullptr;

        GDoubleLinearExpr( const Napi::CallbackInfo& info )
            : Napi::ObjectWrap< GDoubleLinearExpr >( info )
        {
            //     DoubleLinearExpr();
            if ( info.Length() == 0 )
            {
                pDoubleLinearExpr = new DoubleLinearExpr();
                return;
            }

            ThrowJsError( GDoubleLinearExpr::GDoubleLinearExpr : Invalid number of arguments );
        };

        ~GDoubleLinearExpr()
        {
            if ( pDoubleLinearExpr != nullptr )
            {
                delete pDoubleLinearExpr;
                pDoubleLinearExpr = nullptr;
            }
        }

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "DoubleLinearExpr",
                {} );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( "DoubleLinearExpr", func );
            return exports;
        };

        // class DoubleLinearExpr
        // {
        // public:

        //     /// Constructs a linear expression from a Boolean variable.
        //     /// It deals with logical negation correctly.
        //     explicit DoubleLinearExpr( BoolVar var );

        //     /// Constructs a linear expression from an integer variable.
        //     explicit DoubleLinearExpr( IntVar var );

        //     /// Constructs a constant linear expression.
        //     explicit DoubleLinearExpr( double constant );

        //     /// Adds a constant value to the linear expression.
        //     DoubleLinearExpr& operator+=( double value );

        //     /// Adds a single integer variable to the linear expression.
        //     DoubleLinearExpr& operator+=( IntVar var );
        //     DoubleLinearExpr& operator+=( BoolVar var );

        //     /// Adds another linear expression to the linear expression.
        //     DoubleLinearExpr& operator+=( const DoubleLinearExpr& expr );

        //     /// Adds a term (var * coeff) to the linear expression.
        //     DoubleLinearExpr& AddTerm( IntVar var, double coeff );
        //     DoubleLinearExpr& AddTerm( BoolVar var, double coeff );

        //     /// Adds a linear expression to the double linear expression.
        //     DoubleLinearExpr& AddExpression( const LinearExpr& exprs, double coeff = 1.0 );

        //     /// Adds a constant value to the linear expression.
        //     DoubleLinearExpr& operator-=( double value );

        //     /// Adds a single integer variable to the linear expression.
        //     DoubleLinearExpr& operator-=( IntVar var );

        //     /// Adds another linear expression to the linear expression.
        //     DoubleLinearExpr& operator-=( const DoubleLinearExpr& expr );

        //     /// Multiply the linear expression by a constant.
        //     DoubleLinearExpr& operator*=( double coeff );

        //     /// Constructs the sum of a list of variables.
        //     static DoubleLinearExpr Sum( absl::Span< const IntVar > vars );

        //     /// Constructs the sum of a list of Boolean variables.
        //     static DoubleLinearExpr Sum( absl::Span< const BoolVar > vars );

        //     /// Constructs the scalar product of variables and coefficients.
        //     static DoubleLinearExpr WeightedSum( absl::Span< const IntVar > vars,
        //                                          absl::Span< const double > coeffs );

        //     /// Constructs the scalar product of Boolean variables and coefficients.
        //     static DoubleLinearExpr WeightedSum( absl::Span< const BoolVar > vars,
        //                                          absl::Span< const double >  coeffs );

        //     /// Returns the vector of variable indices.
        //     const std::vector< int >& variables() const
        //     {
        //         return variables_;
        //     }

        //     /// Returns the vector of coefficients.
        //     const std::vector< double >& coefficients() const
        //     {
        //         return coefficients_;
        //     }

        //     // Returns true if the expression has no variable.
        //     const bool IsConstant() const
        //     {
        //         return variables_.empty();
        //     }

        //     /// Returns the constant term.
        //     double constant() const
        //     {
        //         return constant_;
        //     }

        //     /// Debug string. See the documentation for LinearExpr::DebugString().
        //     std::string DebugString( const CpModelProto* proto = nullptr ) const;

        // };
    };

    Napi::FunctionReference GDoubleLinearExpr::constructor;

}  // namespace sat
}  // namespace operations_research
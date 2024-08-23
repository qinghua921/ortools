#pragma once

#include <napi.h>
#include "ortools/sat/cp_model.h"
#include "../../commonheader.hpp"
#include "GBoolVar.hpp"
#include "GIntVar.hpp"
#include "GBoolVar.hpp"

namespace operations_research
{
namespace sat
{
    class GLinearExpr : public Napi::ObjectWrap< GLinearExpr >
    {
    public:
        static Napi::FunctionReference constructor;
        LinearExpr*                    pLinearExpr = nullptr;

        GLinearExpr( const Napi::CallbackInfo& info )
            : Napi::ObjectWrap< GLinearExpr >( info )
        {
            if ( info.Length() == 0 )
            {
                pLinearExpr = new LinearExpr();
                return;
            }

            //     LinearExpr( BoolVar var );
            if ( info.Length() == 1
                 && info[ 0 ].IsObject()
                 && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
            {
                GBoolVar* pVar = Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 0 ].As< Napi::Object >() );
                pLinearExpr    = new LinearExpr( *pVar->pBoolVar );
                return;
            }

            //     LinearExpr( IntVar var );
            if ( info.Length() == 1
                 && info[ 0 ].IsObject()
                 && info[ 0 ].As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
            {
                GIntVar* pVar = Napi::ObjectWrap< GIntVar >::Unwrap( info[ 0 ].As< Napi::Object >() );
                pLinearExpr   = new LinearExpr( *pVar->pIntVar );
                return;
            }

            //     LinearExpr( int64_t constant );
            if ( info.Length() == 1 && info[ 0 ].IsNumber() )
            {
                int64_t constant = info[ 0 ].As< Napi::Number >().Int64Value();
                pLinearExpr      = new LinearExpr( constant );
                return;
            }

            if ( info.Length() == 1 && info[ 0 ].IsExternal() )
            {
                auto external = info[ 0 ].As< Napi::External< LinearExpr > >();
                pLinearExpr   = dynamic_cast< LinearExpr* >( external.Data() );
                if ( pLinearExpr != nullptr ) return;
            }

            ThrowJsError( GLinearExpr::GLinearExpr : Invalid number of arguments );
        };

        ~GLinearExpr()
        {
            if ( pLinearExpr != nullptr )
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
                } );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( "LinearExpr", func );
            return exports;
        };

        //     /// Constructs the sum of a list of variables.
        //     static LinearExpr Sum( absl::Span< const IntVar > vars );

        //     /// Constructs the sum of a list of Boolean variables.
        //     static LinearExpr Sum( absl::Span< const BoolVar > vars );

        //     /// Constructs the scalar product of variables and coefficients.
        //     static LinearExpr WeightedSum( absl::Span< const IntVar >  vars,
        //                                    absl::Span< const int64_t > coeffs );

        //     /// Constructs the scalar product of Boolean variables and coefficients.
        //     static LinearExpr WeightedSum( absl::Span< const BoolVar > vars,
        //                                    absl::Span< const int64_t > coeffs );

        //     /// Constructs var * coefficient.
        //     static LinearExpr Term( IntVar var, int64_t coefficient );

        //     /// Constructs bool * coefficient.
        //     static LinearExpr Term( BoolVar var, int64_t coefficient );

        //     /// Constructs a linear expr from its proto representation.
        //     static LinearExpr FromProto( const LinearExpressionProto& proto );

        //     LinearExpr& operator+=( const LinearExpr& other );
        Napi::Value operator_plus( const Napi::CallbackInfo& info )
        {
            if ( info.Length() == 1
                 && info[ 0 ].IsObject()
                 && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
            {
                GLinearExpr* pOther = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
                *pLinearExpr += *pOther->pLinearExpr;
                return this->Value();
            }

            if ( info.Length() == 1
                 && info[ 0 ].IsObject()
                 && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
            {
                GBoolVar* pVar = Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 0 ].As< Napi::Object >() );
                *pLinearExpr += *pVar->pBoolVar;
                return this->Value();
            }

            ThrowJsError( GLinearExpr::operator_plus : Invalid number of arguments );
            return info.Env().Undefined();
        }

        //     LinearExpr& operator-=( const LinearExpr& other );
        Napi::Value operator_minus( const Napi::CallbackInfo& info )
        {
            if ( info.Length() == 1
                 && info[ 0 ].IsObject()
                 && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
            {
                GLinearExpr* pOther = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
                *pLinearExpr -= *pOther->pLinearExpr;
                return this->Value();
            }

            if ( info.Length() == 1
                 && info[ 0 ].IsObject()
                 && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
            {
                GBoolVar* pVar = Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 0 ].As< Napi::Object >() );
                *pLinearExpr -= *pVar->pBoolVar;
                return this->Value();
            }

            ThrowJsError( GLinearExpr::operator_minus : Invalid number of arguments );
            return info.Env().Undefined();
        }

        //     LinearExpr& operator*=( int64_t factor );
        Napi::Value operator_times( const Napi::CallbackInfo& info )
        {
            if ( info.Length() == 1 && info[ 0 ].IsNumber() )
            {
                int64_t factor = info[ 0 ].As< Napi::Number >().Int64Value();
                *pLinearExpr *= factor;
                return this->Value();
            }

            ThrowJsError( GLinearExpr::operator_times : Invalid number of arguments );
            return info.Env().Undefined();
        }

        //     /// Returns the vector of variable indices.
        //     const std::vector< int >& variables() const
        //     {
        //         return variables_;
        //     }

        //     /// Returns the vector of coefficients.
        //     const std::vector< int64_t >& coefficients() const
        //     {
        //         return coefficients_;
        //     }

        //     /// Returns true if the expression has no variables.
        //     const bool IsConstant() const
        //     {
        //         return variables_.empty();
        //     }

        //     /// Returns the constant term.
        //     int64_t constant() const
        //     {
        //         return constant_;
        //     }

        //     /**
        //      * Debug string. If the CpModelBuilder is passed, the string will include
        //      * variable names and domains. Otherwise, you will get a shorter string with
        //      * only variable indices.
        //      */
        //     std::string DebugString( const CpModelProto* proto = nullptr ) const;

        // };
    };

    Napi::FunctionReference GLinearExpr::constructor;
}  // namespace sat
}  // namespace operations_research
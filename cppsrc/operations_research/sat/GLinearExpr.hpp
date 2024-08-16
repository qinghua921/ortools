#pragma once

#include <napi.h>
#include "GIntVar.hpp"
#include "GLinearExpr.hpp"
#include "GBoolVar.hpp"
#include "GCpModelProto.hpp"
#include <typeinfo>
#include <ortools/sat/cp_model.h>
#include "../../commonheader.hpp"

namespace operations_research
{
namespace sat
{
    class GLinearExpr : public Napi::ObjectWrap< GLinearExpr >
    {
    public:
        static Napi::FunctionReference constructor;
        static bool                    UnwrapValue( const Napi::Value& value, LinearExpr& linearExpr );
        LinearExpr                     vLinearExpr;

    public:
        GLinearExpr( const Napi::CallbackInfo& info );
        ~GLinearExpr();

    public:
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
        static Napi::Value  WeightedSum( const Napi::CallbackInfo& info );
        static Napi::Value  LinearExprPlus( const Napi::CallbackInfo& info );
        static Napi::Value  NumberLinearExprMult( const Napi::CallbackInfo& info );
        static Napi::Value  Term( const Napi::CallbackInfo& info );
        Napi::Value         IsConstant( const Napi::CallbackInfo& info );
        Napi::Value         DebugString( const Napi::CallbackInfo& info );
        Napi::Value         Plus( const Napi::CallbackInfo& info );
        Napi::Value         Minus( const Napi::CallbackInfo& info );
        Napi::Value         Multi( const Napi::CallbackInfo& info );
    };

    Napi::FunctionReference GLinearExpr::constructor;

    Napi::Object GLinearExpr::Init( Napi::Env env, Napi::Object exports )
    {
        Napi::Function func = DefineClass(
            env,
            "LinearExpr",
            {
                StaticMethod( "WeightedSum", &GLinearExpr::WeightedSum ),                    //
                StaticMethod( "LinearExprPlus", &GLinearExpr::LinearExprPlus ),              //
                StaticMethod( "NumberLinearExprMult", &GLinearExpr::NumberLinearExprMult ),  //
                StaticMethod( "Term", &GLinearExpr::Term ),                                  //

                InstanceMethod( "IsConstant", &GLinearExpr::IsConstant ),    //
                InstanceMethod( "DebugString", &GLinearExpr::DebugString ),  //
                InstanceMethod( "Plus", &GLinearExpr::Plus ),                //
                InstanceMethod( "Minus", &GLinearExpr::Minus ),              //
                InstanceMethod( "Multi", &GLinearExpr::Multi ),              //
            } );

        constructor = Napi::Persistent( func );
        exports.Set( "LinearExpr", func );
        return exports;
    }

    Napi::Value GLinearExpr::IsConstant( const Napi::CallbackInfo& info )
    {
        auto ret = this->vLinearExpr.IsConstant();
        return Napi::Boolean::New( info.Env(), ret );
    }

    inline Napi::Value GLinearExpr::DebugString( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsObject() )
        {
            GCpModelProto* pGCpModelProto = GCpModelProto::Unwrap( info[ 0 ].As< Napi::Object >() );
            if ( typeid( *pGCpModelProto ) == typeid( GCpModelProto ) )
            {
                auto vstring = this->vLinearExpr.DebugString( pGCpModelProto->pCpModelProto );
                return Napi::String::New( info.Env(), vstring );
            }
        }

        ThrowJsError( GLinearExpr::DebugString Error );
        return info.Env().Undefined();
    }

    Napi::Value GLinearExpr::Plus( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && ( info[ 0 ].IsObject() || info[ 0 ].IsNumber() ) )
        {
            LinearExpr other;
            auto       okOther = GLinearExpr::UnwrapValue( info[ 0 ], other );
            if ( okOther )
            {
                auto ret           = this->vLinearExpr + other;
                auto asExternalVar = Napi::External< LinearExpr >::New( info.Env(), &ret );
                return GLinearExpr::constructor.New( { asExternalVar } );
            }
        }

        ThrowJsError( GLinearExpr::Plus ERROR );
        return info.Env().Undefined();
    }

    Napi::Value GLinearExpr::Minus( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && ( info[ 0 ].IsObject() || info[ 0 ].IsNumber() ) )
        {
            LinearExpr other;
            auto       okOther = GLinearExpr::UnwrapValue( info[ 0 ], other );
            if ( okOther )
            {
                auto ret           = this->vLinearExpr - other;
                auto asExternalVar = Napi::External< LinearExpr >::New( info.Env(), &ret );
                return GLinearExpr::constructor.New( { asExternalVar } );
            }
        }

        ThrowJsError( GLinearExpr::Minus ERROR );
        return info.Env().Undefined();
    }

    Napi::Value GLinearExpr::Multi( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsNumber() )
        {
            auto ret           = this->vLinearExpr * info[ 0 ].As< Napi::Number >();
            auto asExternalVar = Napi::External< LinearExpr >::New( info.Env(), &ret );
            return GLinearExpr::constructor.New( { asExternalVar } );
        }

        ThrowJsError( GLinearExpr::Multi ERROR );
        return info.Env().Undefined();
    }

    Napi::Value GLinearExpr::WeightedSum( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 2 && info[ 0 ].IsArray() && info[ 1 ].IsArray() )
        {
            auto                   coeffs = info[ 1 ].As< Napi::Array >();
            std::vector< int64_t > coeffs_;
            for ( size_t i = 0; i < coeffs.Length(); i++ )
            {
                auto ls = coeffs.Get( i ).As< Napi::Number >();
                coeffs_.push_back( ls.Int64Value() );
            }

            auto var = info[ 0 ].As< Napi::Array >();

            // IntVar
            std::vector< IntVar > intVars;
            for ( size_t i = 0; i < var.Length(); i++ )
            {
                auto ls = GIntVar::Unwrap( var.Get( i ).As< Napi::Object >() );
                if ( typeid( *ls ) == typeid( GIntVar ) ) intVars.push_back( ls->vIntVar );
            }
            if ( var.Length() == intVars.size() )
            {
                auto linearExpr    = LinearExpr::WeightedSum( absl::Span< const IntVar >( intVars ), absl::Span< const int64_t >( coeffs_ ) );
                auto asExternalVar = Napi::External< LinearExpr >::New( info.Env(), &linearExpr );
                return GLinearExpr::constructor.New( { asExternalVar } );
            }

            // BoolVar
            std::vector< BoolVar > boolVars;
            for ( size_t i = 0; i < var.Length(); i++ )
            {
                auto ls = GBoolVar::Unwrap( var.Get( i ).As< Napi::Object >() );
                if ( typeid( *ls ) == typeid( GBoolVar ) ) boolVars.push_back( ls->vBoolVar );
            }
            if ( var.Length() == boolVars.size() )
            {
                auto linearExpr    = LinearExpr::WeightedSum( absl::Span< const BoolVar >( boolVars ), absl::Span< const int64_t >( coeffs_ ) );
                auto asExternalVar = Napi::External< LinearExpr >::New( info.Env(), &linearExpr );
                return GLinearExpr::constructor.New( { asExternalVar } );
            }
        }

        ThrowJsError( GLinearExpr::WeightedSum Error );
        return info.Env().Undefined();
    }

    Napi::Value GLinearExpr::NumberLinearExprMult( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsObject() )
        {
            LinearExpr right;
            auto       rightok = GLinearExpr::UnwrapValue( info[ 1 ], right );

            if ( rightok )
            {
                auto ret           = info[ 0 ].As< Napi::Number >() * right;
                auto asExternalVar = Napi::External< LinearExpr >::New( info.Env(), &ret );
                return GLinearExpr::constructor.New( { asExternalVar } );
            }
        }

        ThrowJsError( GLinearExpr::NumberLinearExprMult ERROR );
        return info.Env().Undefined();
    }

    Napi::Value GLinearExpr::Term( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 2 && info[ 0 ].IsObject() && info[ 1 ].IsNumber() )
        {
            auto pGIntVar = GIntVar::Unwrap( info[ 0 ].As< Napi::Object >() );
            if ( typeid( *pGIntVar ) == typeid( GIntVar ) )
            {
                auto ret           = LinearExpr::Term( pGIntVar->vIntVar, info[ 1 ].As< Napi::Number >() );
                auto asExternalVar = Napi::External< LinearExpr >::New( info.Env(), &ret );
                return GLinearExpr::constructor.New( { asExternalVar } );
            }

            auto pGBoolVar = GBoolVar::Unwrap( info[ 0 ].As< Napi::Object >() );
            if ( typeid( *pGBoolVar ) == typeid( GBoolVar ) )
            {
                auto ret           = LinearExpr::Term( pGBoolVar->vBoolVar, info[ 1 ].As< Napi::Number >() );
                auto asExternalVar = Napi::External< LinearExpr >::New( info.Env(), &ret );
                return GLinearExpr::constructor.New( { asExternalVar } );
            }
        }

        ThrowJsError( GLinearExpr::Term ERROR );
        return info.Env().Undefined();
    }

    Napi::Value GLinearExpr::LinearExprPlus( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 2
             && ( info[ 0 ].IsNumber() || info[ 0 ].IsObject() )
             && ( info[ 1 ].IsNumber() || info[ 1 ].IsObject() ) )
        {
            LinearExpr left;
            auto       leftok = GLinearExpr::UnwrapValue( info[ 0 ], left );
            LinearExpr right;
            auto       rightok = GLinearExpr::UnwrapValue( info[ 1 ], right );

            if ( leftok && rightok )
            {
                auto ret           = left + right;
                auto asExternalVar = Napi::External< LinearExpr >::New( info.Env(), &ret );
                return GLinearExpr::constructor.New( { asExternalVar } );
            }
        }

        ThrowJsError( GLinearExpr::LinearExprPlus ERROR );
        return info.Env().Undefined();
    }

    /**
     * 接受 Napi::Number, GLinearExpr, GIntVar, GBoolVar
     */
    bool GLinearExpr::UnwrapValue( const Napi::Value& value, LinearExpr& linearExpr )
    {
        if ( value.IsNumber() )
        {
            linearExpr = value.As< Napi::Number >().Int64Value();
            return true;
        }

        auto pGLinearExpr = GLinearExpr::Unwrap( value.As< Napi::Object >() );

        if ( typeid( *pGLinearExpr ) == typeid( GLinearExpr ) )
        {
            linearExpr = pGLinearExpr->vLinearExpr;
            return true;
        }

        auto pGIntVar = GIntVar::Unwrap( value.As< Napi::Object >() );

        if ( typeid( *pGIntVar ) == typeid( GIntVar ) )
        {
            linearExpr = pGIntVar->vIntVar;
            return true;
        }

        auto pGBoolVar = GBoolVar::Unwrap( value.As< Napi::Object >() );

        if ( typeid( *pGBoolVar ) == typeid( GBoolVar ) )
        {
            linearExpr = pGBoolVar->vBoolVar;
            return true;
        }

        return false;
    }

    GLinearExpr::GLinearExpr( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GLinearExpr >( info )
    {
        if ( info.Length() == 0 )
        {
            this->vLinearExpr = LinearExpr();
            return;
        }

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto pLinearExpr = info[ 0 ].As< Napi::External< LinearExpr > >().Data();
            if ( typeid( *pLinearExpr ) == typeid( LinearExpr ) )
            {
                this->vLinearExpr = *pLinearExpr;
                return;
            }
        }

        if ( info.Length() == 1 && info[ 0 ].IsNumber() )
        {
            this->vLinearExpr = LinearExpr( info[ 0 ].As< Napi::Number >() );
            return;
        }

        if ( info.Length() == 1 && info[ 0 ].IsBoolean() )
        {
            this->vLinearExpr = LinearExpr( info[ 0 ].As< Napi::Boolean >() );
            return;
        }

        if ( info.Length() == 1 && info[ 0 ].IsObject() )
        {
            auto pGIntVar = GIntVar::Unwrap( info[ 0 ].As< Napi::Object >() );
            if ( typeid( *pGIntVar ) == typeid( GIntVar ) )
            {
                this->vLinearExpr = LinearExpr( pGIntVar->vIntVar );
                return;
            }
        }

        ThrowJsError( GLinearExpr::GLinearExpr Error );
    }

    GLinearExpr::~GLinearExpr()
    {
#ifdef DEBUG
        LOG( INFO ) << "GLinearExpr::~GLinearExpr";
#endif
    }
}  // namespace sat
}  // namespace operations_research

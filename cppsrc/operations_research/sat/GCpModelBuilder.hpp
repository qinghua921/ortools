#pragma once

#include <napi.h>
#include "../GDomain.hpp"
#include "GIntVar.hpp"
#include "GLinearExpr.hpp"
#include "GConstraint.hpp"
#include "GCpModelProto.hpp"
#include "GIntervalVar.hpp"
#include "GBoolVar.hpp"
#include "GTableConstraint.hpp"
#include <ortools/sat/cp_model.h>

namespace operations_research
{
namespace sat
{
    class GCpModelBuilder : public Napi::ObjectWrap< GCpModelBuilder >
    {
    public:
        static Napi::FunctionReference constructor;
        CpModelBuilder*                pCpModelBuilder;

    public:
        GCpModelBuilder( const Napi::CallbackInfo& info );
        ~GCpModelBuilder();

    public:
        static Napi::Object Init( Napi::Env env, Napi::Object exports );

        Napi::Value Build( const Napi::CallbackInfo& info );

        Napi::Value Maximize( const Napi::CallbackInfo& info );
        Napi::Value Minimize( const Napi::CallbackInfo& info );

        Napi::Value NewIntVar( const Napi::CallbackInfo& info );
        Napi::Value NewBoolVar( const Napi::CallbackInfo& info );
        Napi::Value NewIntervalVar( const Napi::CallbackInfo& info );
        Napi::Value NewOptionalIntervalVar( const Napi::CallbackInfo& info );
        Napi::Value NewFixedSizeIntervalVar( const Napi::CallbackInfo& info );
        Napi::Value NewOptionalFixedSizeIntervalVar( const Napi::CallbackInfo& info );

        Napi::Value AddEquality( const Napi::CallbackInfo& info );
        Napi::Value AddLessOrEqual( const Napi::CallbackInfo& info );
        Napi::Value AddLessThan( const Napi::CallbackInfo& info );
        Napi::Value AddMaxEquality( const Napi::CallbackInfo& info );
        Napi::Value AddMinEquality( const Napi::CallbackInfo& info );
        Napi::Value AddNoOverlap( const Napi::CallbackInfo& info );
        Napi::Value AddLinearConstraint( const Napi::CallbackInfo& info );
        Napi::Value AddImplication( const Napi::CallbackInfo& info );
        Napi::Value AddAllowedAssignments( const Napi::CallbackInfo& info );
        Napi::Value AddModuloEquality( const Napi::CallbackInfo& info );
        Napi::Value AddDivisionEquality( const Napi::CallbackInfo& info );
    };

    Napi::FunctionReference GCpModelBuilder::constructor;

    Napi::Object GCpModelBuilder::Init( Napi::Env env, Napi::Object exports )
    {
        Napi::Function func = DefineClass(
            env,
            "CpModelBuilder",
            {
                InstanceMethod( "Build", &GCpModelBuilder::Build ),  //

                InstanceMethod( "Maximize", &GCpModelBuilder::Maximize ),  //
                InstanceMethod( "Minimize", &GCpModelBuilder::Minimize ),  //

                InstanceMethod( "NewIntVar", &GCpModelBuilder::NewIntVar ),                                              //
                InstanceMethod( "NewBoolVar", &GCpModelBuilder::NewBoolVar ),                                            //
                InstanceMethod( "NewIntervalVar", &GCpModelBuilder::NewIntervalVar ),                                    //
                InstanceMethod( "NewOptionalIntervalVar", &GCpModelBuilder::NewOptionalIntervalVar ),                    //
                InstanceMethod( "NewFixedSizeIntervalVar", &GCpModelBuilder::NewFixedSizeIntervalVar ),                  //
                InstanceMethod( "NewOptionalFixedSizeIntervalVar", &GCpModelBuilder::NewOptionalFixedSizeIntervalVar ),  //

                InstanceMethod( "AddEquality", &GCpModelBuilder::AddEquality ),                      //
                InstanceMethod( "AddLessOrEqual", &GCpModelBuilder::AddLessOrEqual ),                //
                InstanceMethod( "AddLessThan", &GCpModelBuilder::AddLessThan ),                      //
                InstanceMethod( "AddMaxEquality", &GCpModelBuilder::AddMaxEquality ),                //
                InstanceMethod( "AddMinEquality", &GCpModelBuilder::AddMinEquality ),                //
                InstanceMethod( "AddNoOverlap", &GCpModelBuilder::AddNoOverlap ),                    //
                InstanceMethod( "AddLinearConstraint", &GCpModelBuilder::AddLinearConstraint ),      //
                InstanceMethod( "AddImplication", &GCpModelBuilder::AddImplication ),                //
                InstanceMethod( "AddAllowedAssignments", &GCpModelBuilder::AddAllowedAssignments ),  //
                InstanceMethod( "AddModuloEquality", &GCpModelBuilder::AddModuloEquality ),          //
                InstanceMethod( "AddDivisionEquality", &GCpModelBuilder::AddDivisionEquality ),      //

            } );

        constructor = Napi::Persistent( func );
        exports.Set( "CpModelBuilder", func );
        return exports;
    }

    Napi::Value GCpModelBuilder::Minimize( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsObject() )
        {
            LinearExpr linearExpr;
            auto       linearExprOk = GLinearExpr::UnwrapValue( info[ 0 ], linearExpr );
            if ( linearExprOk )
            {
                this->pCpModelBuilder->Minimize( linearExpr );
                return info.Env().Undefined();
            }
        }

        ThrowJsError( GCpModelBuilder::Maximize 异常 );
        return info.Env().Undefined();
    }
    // FIXME 考虑 内存泄漏
    // TODO  jest 不结束
    Napi::Value GCpModelBuilder::AddMaxEquality( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 2 && info[ 0 ].IsObject() && info[ 1 ].IsArray() )
        {
            LinearExpr target;
            auto       targetOk = GLinearExpr::UnwrapValue( info[ 0 ], target );

            auto                      vArray = info[ 1 ].As< Napi::Array >();
            std::vector< LinearExpr > exprs;

            for ( size_t i = 0; i < vArray.Length(); i++ )
            {
                LinearExpr ls;
                auto       lsOk = GLinearExpr::UnwrapValue( vArray.Get( i ), ls );
                if ( lsOk ) exprs.push_back( ls );
            }

            if ( exprs.size() == vArray.Length() )
            {
                auto ret           = this->pCpModelBuilder->AddMaxEquality( target, exprs );
                auto asExternalVar = Napi::External< Constraint >::New( info.Env(), &ret );
                return GConstraint::constructor.New( { asExternalVar } );
            }
        }

        ThrowJsError( GCpModelBuilder::AddMaxEquality 参数异常 );
        return info.Env().Undefined();
    }

    Napi::Value GCpModelBuilder::AddMinEquality( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 2 && info[ 0 ].IsObject() && info[ 1 ].IsArray() )
        {
            LinearExpr target;
            auto       targetOk = GLinearExpr::UnwrapValue( info[ 0 ], target );

            auto                      vArray = info[ 1 ].As< Napi::Array >();
            std::vector< LinearExpr > exprs;

            for ( size_t i = 0; i < vArray.Length(); i++ )
            {
                LinearExpr ls;
                auto       lsOk = GLinearExpr::UnwrapValue( vArray.Get( i ), ls );
                if ( lsOk ) exprs.push_back( ls );
            }

            if ( exprs.size() == vArray.Length() )
            {
                auto ret           = this->pCpModelBuilder->AddMinEquality( target, exprs );
                auto asExternalVar = Napi::External< Constraint >::New( info.Env(), &ret );
                return GConstraint::constructor.New( { asExternalVar } );
            }
        }

        ThrowJsError( GCpModelBuilder::AddMinEquality 参数异常 );
        return info.Env().Undefined();
    }

    Napi::Value GCpModelBuilder::AddNoOverlap( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsArray() )
        {
            auto var = info[ 0 ].As< Napi::Array >();

            std::vector< IntervalVar > intervalVars;
            for ( size_t i = 0; i < var.Length(); i++ )
            {
                auto ls = GIntervalVar::Unwrap( var.Get( i ).As< Napi::Object >() );
                if ( typeid( *ls ) == typeid( GIntervalVar ) ) intervalVars.push_back( ls->vIntervalVar );
            }
            if ( var.Length() == intervalVars.size() )
            {
                auto ret           = this->pCpModelBuilder->AddNoOverlap( intervalVars );
                auto asExternalVar = Napi::External< Constraint >::New( info.Env(), &ret );
                return GConstraint::constructor.New( { asExternalVar } );
            }
        }

        ThrowJsError( GCpModelBuilder::AddNoOverlap 异常 );
        return info.Env().Undefined();
    }

    Napi::Value GCpModelBuilder::AddLinearConstraint( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 2 && info[ 0 ].IsObject() && info[ 1 ].IsObject() )
        {
            LinearExpr vLinearExpr;
            auto       vLinearExprOk = GLinearExpr::UnwrapValue( info[ 0 ], vLinearExpr );

            auto pGDomain = GDomain::Unwrap( info[ 1 ].As< Napi::Object >() );
            if ( typeid( *pGDomain ) == typeid( GDomain ) && vLinearExprOk )
            {
                auto domain        = pGDomain->vDomain;
                auto vConstraint   = this->pCpModelBuilder->AddLinearConstraint( vLinearExpr, domain );
                auto asExternalVar = Napi::External< Constraint >::New( info.Env(), &vConstraint );
                return GConstraint::constructor.New( { asExternalVar } );
            }
        }

        ThrowJsError( GCpModelBuilder::AddLinearConstraint 异常 );
        return info.Env().Undefined();
    }

    Napi::Value GCpModelBuilder::AddImplication( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 2 && info[ 0 ].IsObject() && info[ 1 ].IsObject() )
        {
            auto aGBoolVar = GBoolVar::Unwrap( info[ 0 ].As< Napi::Object >() );
            auto bGBoolVar = GBoolVar::Unwrap( info[ 1 ].As< Napi::Object >() );

            if ( typeid( *aGBoolVar ) == typeid( GBoolVar ) && typeid( *bGBoolVar ) == typeid( GBoolVar ) )
            {
                auto vConstraint = this->pCpModelBuilder->AddImplication( aGBoolVar->vBoolVar, bGBoolVar->vBoolVar );
                auto vExternal   = Napi::External< Constraint >::New( info.Env(), &vConstraint );
                return GConstraint::constructor.New( { vExternal } );
            }
        }

        ThrowJsError( GCpModelBuilder::AddImplication 异常 );
        return info.Env().Undefined();
    }

    inline Napi::Value GCpModelBuilder::AddAllowedAssignments( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsArray() )
        {
            auto var = info[ 0 ].As< Napi::Array >();

            std::vector< IntVar > intVars;
            for ( size_t i = 0; i < var.Length(); i++ )
            {
                auto ls = GIntVar::Unwrap( var.Get( i ).As< Napi::Object >() );
                if ( typeid( *ls ) == typeid( GIntVar ) ) intVars.push_back( ls->vIntVar );
            }
            if ( var.Length() == intVars.size() )
            {
                auto ret           = this->pCpModelBuilder->AddAllowedAssignments( intVars );
                auto asExternalVar = Napi::External< TableConstraint >::New( info.Env(), &ret );
                return GTableConstraint::constructor.New( { asExternalVar } );
            }
        }

        ThrowJsError( GCpModelBuilder::AddAllowedAssignments ERROR );
        return info.Env().Undefined();
    }

    Napi::Value GCpModelBuilder::AddModuloEquality( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 3
             && ( info[ 0 ].IsObject() || info[ 0 ].IsNumber() )
             && ( info[ 1 ].IsObject() || info[ 1 ].IsNumber() )
             && ( info[ 2 ].IsObject() || info[ 2 ].IsNumber() ) )
        {
            LinearExpr target;
            auto       okTarget = GLinearExpr::UnwrapValue( info[ 0 ], target );
            LinearExpr var;
            auto       okVar = GLinearExpr::UnwrapValue( info[ 1 ], var );
            LinearExpr mod;
            auto       okMod = GLinearExpr::UnwrapValue( info[ 2 ], mod );
            if ( okTarget && okVar && okMod )
            {
                auto vConstraint = this->pCpModelBuilder->AddModuloEquality( target, var, mod );
                auto vExternal   = Napi::External< Constraint >::New( info.Env(), &vConstraint );
                return GConstraint::constructor.New( { vExternal } );
            }
        }

        ThrowJsError( GCpModelBuilder::AddModuloEquality ERROR );
        return info.Env().Undefined();
    }

    Napi::Value GCpModelBuilder::AddDivisionEquality( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 3
             && ( info[ 0 ].IsObject() || info[ 0 ].IsNumber() )
             && ( info[ 1 ].IsObject() || info[ 1 ].IsNumber() )
             && ( info[ 2 ].IsObject() || info[ 2 ].IsNumber() ) )
        {
            LinearExpr target;
            auto       okTarget = GLinearExpr::UnwrapValue( info[ 0 ], target );
            LinearExpr numerator;
            auto       okNumerator = GLinearExpr::UnwrapValue( info[ 1 ], numerator );
            LinearExpr denominator;
            auto       okDenominator = GLinearExpr::UnwrapValue( info[ 2 ], denominator );
            if ( okTarget && okNumerator && okDenominator )
            {
                auto vConstraint = this->pCpModelBuilder->AddDivisionEquality( target, numerator, denominator );
                auto vExternal   = Napi::External< Constraint >::New( info.Env(), &vConstraint );
                return GConstraint::constructor.New( { vExternal } );
            }
        }

        ThrowJsError( GCpModelBuilder::AddDivisionEquality ERROR );
        return info.Env().Undefined();
    }

    Napi::Value GCpModelBuilder::NewIntervalVar( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 3
             && ( info[ 0 ].IsObject() || info[ 0 ].IsNumber() )
             && ( info[ 1 ].IsObject() || info[ 1 ].IsNumber() )
             && ( info[ 2 ].IsObject() || info[ 2 ].IsNumber() ) )
        {
            LinearExpr start;
            auto       okStart = GLinearExpr::UnwrapValue( info[ 0 ], start );
            LinearExpr size;
            auto       okSize = GLinearExpr::UnwrapValue( info[ 1 ], size );
            LinearExpr end;
            auto       okEnd = GLinearExpr::UnwrapValue( info[ 2 ], end );
            if ( okStart && okSize && okEnd )
            {
                auto vIntervalVar = this->pCpModelBuilder->NewIntervalVar( start, size, end );
                auto vExternal    = Napi::External< IntervalVar >::New( info.Env(), &vIntervalVar );
                return GIntervalVar::constructor.New( { vExternal } );
            }
        }

        ThrowJsError( GCpModelBuilder::NewIntervalVar 异常 );
        return info.Env().Undefined();
    }

    Napi::Value GCpModelBuilder::NewOptionalIntervalVar( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 4
             && ( info[ 0 ].IsObject() || info[ 0 ].IsNumber() )
             && ( info[ 1 ].IsObject() || info[ 1 ].IsNumber() )
             && ( info[ 2 ].IsObject() || info[ 2 ].IsNumber() )
             && info[ 3 ].IsObject() )
        {
            LinearExpr start;
            auto       okStart = GLinearExpr::UnwrapValue( info[ 0 ], start );
            LinearExpr size;
            auto       okSize = GLinearExpr::UnwrapValue( info[ 1 ], size );
            LinearExpr end;
            auto       okEnd     = GLinearExpr::UnwrapValue( info[ 2 ], end );
            auto       pGBoolVar = GBoolVar::Unwrap( info[ 3 ].As< Napi::Object >() );

            if ( okStart && okSize && okEnd && typeid( *pGBoolVar ) == typeid( GBoolVar ) )
            {
                auto vIntervalVar = this->pCpModelBuilder->NewOptionalIntervalVar( start, size, end, pGBoolVar->vBoolVar );
                auto vExternal    = Napi::External< IntervalVar >::New( info.Env(), &vIntervalVar );
                return GIntervalVar::constructor.New( { vExternal } );
            }
        }

        ThrowJsError( GCpModelBuilder::NewOptionalIntervalVar ERROR );
        return info.Env().Undefined();
    }

    Napi::Value GCpModelBuilder::NewFixedSizeIntervalVar( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 2 && ( info[ 0 ].IsObject() || info[ 0 ].IsNumber() ) && info[ 1 ].IsNumber() )
        {
            LinearExpr start;
            auto       okStart = GLinearExpr::UnwrapValue( info[ 0 ], start );
            if ( okStart )
            {
                auto vIntervalVar = this->pCpModelBuilder->NewFixedSizeIntervalVar( start, info[ 1 ].As< Napi::Number >() );
                auto vExternal    = Napi::External< IntervalVar >::New( info.Env(), &vIntervalVar );
                return GIntervalVar::constructor.New( { vExternal } );
            }
        }

        ThrowJsError( GCpModelBuilder::NewFixedSizeIntervalVar ERROR );
        return info.Env().Undefined();
    }

    Napi::Value GCpModelBuilder::NewOptionalFixedSizeIntervalVar( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 3 && info[ 0 ].IsObject() && info[ 1 ].IsNumber() && info[ 2 ].IsObject() )
        {
            LinearExpr start;
            auto       startOk = GLinearExpr::UnwrapValue( info[ 0 ], start );

            auto pGBoolVar = GBoolVar::Unwrap( info[ 2 ].As< Napi::Object >() );
            if ( startOk && typeid( *pGBoolVar ) == typeid( GBoolVar ) )
            {
                auto vIntervalVar = this->pCpModelBuilder->NewOptionalFixedSizeIntervalVar( start, info[ 1 ].As< Napi::Number >(), pGBoolVar->vBoolVar );
                auto vExternal    = Napi::External< IntervalVar >::New( info.Env(), &vIntervalVar );
                return GIntervalVar::constructor.New( { vExternal } );
            }
        }

        ThrowJsError( GCpModelBuilder::NewOptionalFixedSizeIntervalVar ERROR );
        return info.Env().Undefined();
    }

    Napi::Value GCpModelBuilder::AddEquality( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 2 )
        {
            LinearExpr left;
            auto       leftOk = GLinearExpr::UnwrapValue( info[ 0 ], left );
            LinearExpr right;
            auto       rightOk = GLinearExpr::UnwrapValue( info[ 1 ], right );
            if ( leftOk && rightOk )
            {
                auto vConstraint   = this->pCpModelBuilder->AddEquality( left, right );
                auto asExternalVar = Napi::External< Constraint >::New( info.Env(), &vConstraint );
                return GConstraint::constructor.New( { asExternalVar } );
            }
        }

        ThrowJsError( GCpModelBuilder::AddEquality 异常 );
        return info.Env().Undefined();
    }

    Napi::Value GCpModelBuilder::Build( const Napi::CallbackInfo& info )
    {
        auto pCpModelProto = this->pCpModelBuilder->MutableProto();
        auto external      = Napi::External< CpModelProto >::New( info.Env(), pCpModelProto );
        return GCpModelProto::constructor.New( { external } );
    }

    Napi::Value GCpModelBuilder::Maximize( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsObject() )
        {
            LinearExpr linearExpr;
            auto       linearExprOk = GLinearExpr::UnwrapValue( info[ 0 ], linearExpr );
            if ( linearExprOk )
            {
                this->pCpModelBuilder->Maximize( linearExpr );
                return info.Env().Undefined();
            }
        }

        ThrowJsError( GCpModelBuilder::Maximize 异常 );
        return info.Env().Undefined();
    }

    GCpModelBuilder::~GCpModelBuilder()
    {
#ifdef DEBUG
        LOG( INFO ) << "GCpModelBuilder::~GCpModelBuilder";
#endif
        if ( this->pCpModelBuilder )
        {
            delete this->pCpModelBuilder;
            this->pCpModelBuilder = nullptr;
        }
    }

    GCpModelBuilder::GCpModelBuilder( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GCpModelBuilder >( info )
    {
        this->pCpModelBuilder = new CpModelBuilder();
    }

    Napi::Value GCpModelBuilder::NewIntVar( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsObject() )
        {
            auto pGDomain = GDomain::Unwrap( info[ 0 ].As< Napi::Object >() );
            if ( typeid( *pGDomain ) == typeid( GDomain ) )
            {
                auto domain        = pGDomain->vDomain;
                auto intVar        = this->pCpModelBuilder->NewIntVar( domain );
                auto asExternalVar = Napi::External< IntVar >::New( info.Env(), &intVar );
                return GIntVar::constructor.New( { asExternalVar } );
            }
        }

        ThrowJsError( GCpModelBuilder::NewIntVar 异常 );
        return info.Env().Undefined();
    }

    Napi::Value GCpModelBuilder::NewBoolVar( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 0 )
        {
            auto vBoolVar      = this->pCpModelBuilder->NewBoolVar();
            auto asExternalVar = Napi::External< BoolVar >::New( info.Env(), &vBoolVar );
            return GBoolVar::constructor.New( { asExternalVar } );
        }

        ThrowJsError( GCpModelBuilder::NewBoolVar 异常 );
        return info.Env().Undefined();
    }

    Napi::Value GCpModelBuilder::AddLessOrEqual( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 2 && info[ 0 ].IsObject() && ( info[ 1 ].IsObject() || info[ 1 ].IsNumber() ) )
        {
            LinearExpr left;
            auto       leftOk = GLinearExpr::UnwrapValue( info[ 0 ], left );
            LinearExpr right;
            auto       rightOk = GLinearExpr::UnwrapValue( info[ 1 ], right );

            if ( leftOk && rightOk )
            {
                auto constraint    = this->pCpModelBuilder->AddLessOrEqual( left, right );
                auto asExternalVar = Napi::External< Constraint >::New( info.Env(), &constraint );
                return GConstraint::constructor.New( { asExternalVar } );
            }
        }

        ThrowJsError( GCpModelBuilder::AddLessOrEqual 异常 );
        return info.Env().Undefined();
    }

    Napi::Value GCpModelBuilder::AddLessThan( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 2 && info[ 0 ].IsObject() && ( info[ 1 ].IsObject() || info[ 1 ].IsNumber() ) )
        {
            LinearExpr left;
            auto       leftOk = GLinearExpr::UnwrapValue( info[ 0 ], left );
            LinearExpr right;
            auto       rightOk = GLinearExpr::UnwrapValue( info[ 1 ], right );

            if ( leftOk && rightOk )
            {
                auto constraint    = this->pCpModelBuilder->AddLessThan( left, right );
                auto asExternalVar = Napi::External< sat::Constraint >::New( info.Env(), &constraint );
                return GConstraint::constructor.New( { asExternalVar } );
            }
        }

        ThrowJsError( GCpModelBuilder::AddLessThan 异常 );
        return info.Env().Undefined();
    };

}  // namespace sat
}  // namespace operations_research
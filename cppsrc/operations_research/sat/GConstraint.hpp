#pragma once

#include <napi.h>
#include <Windows.h>
#include <ortools/sat/cp_model.h>

namespace operations_research
{
namespace sat
{
    class GConstraint : public Napi::ObjectWrap< GConstraint >
    {
    public:
        static Napi::FunctionReference constructor;
        Constraint*                    pConstraint = nullptr;

    public:
        GConstraint( const Napi::CallbackInfo& info );
        ~GConstraint();

    public:
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
        Napi::Value         WithName( const Napi::CallbackInfo& info );
        Napi::Value         Name( const Napi::CallbackInfo& info );
        Napi::Value         OnlyEnforceIf( const Napi::CallbackInfo& info );
    };

    Napi::FunctionReference GConstraint::constructor;

    Napi::Object GConstraint::Init( Napi::Env env, Napi::Object exports )
    {
        Napi::Function func = DefineClass(
            env,
            "Constraint",
            {
                InstanceMethod( "Name", &GConstraint::Name ),                    //
                InstanceMethod( "WithName", &GConstraint::WithName ),            //
                InstanceMethod( "OnlyEnforceIf", &GConstraint::OnlyEnforceIf ),  //
            } );

        constructor = Napi::Persistent( func );
        exports.Set( "Constraint", func );
        return exports;
    }

    Napi::Value GConstraint::Name( const Napi::CallbackInfo& info )
    {
        return Napi::String::New( info.Env(), this->pConstraint->Name() );
    }

    Napi::Value GConstraint::OnlyEnforceIf( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsObject() )
        {
            auto pGBoolVar = GBoolVar::Unwrap( info[ 0 ].As< Napi::Object >() );
            if ( typeid( *pGBoolVar ) == typeid( GBoolVar ) )
            {
                auto vConstraint = this->pConstraint->OnlyEnforceIf( pGBoolVar->vBoolVar );
                auto asExternal  = Napi::External< Constraint >::New( info.Env(), &vConstraint );
                return GConstraint::constructor.New( { asExternal } );
            }
        }

        if ( info.Length() == 1 && info[ 0 ].IsArray() )
        {
            auto                   nArray = info[ 0 ].As< Napi::Array >();
            std::vector< BoolVar > vBoolVar;

            for ( size_t i = 0; i < nArray.Length(); i++ )
            {
                auto ls = GBoolVar::Unwrap( nArray.Get( i ).As< Napi::Object >() );
                if ( typeid( *ls ) == typeid( GBoolVar ) ) vBoolVar.push_back( ls->vBoolVar );
            }

            if ( nArray.Length() == vBoolVar.size() )
            {
                auto vConstraint = this->pConstraint->OnlyEnforceIf( vBoolVar );
                auto asExternal  = Napi::External< Constraint >::New( info.Env(), &vConstraint );
                return GConstraint::constructor.New( { asExternal } );
            }
        }

        PaoJsError( GConstraint::OnlyEnforceIf 异常 );
        return info.Env().Undefined();
    }

    Napi::Value GConstraint::WithName( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            auto name        = info[ 0 ].As< Napi::String >();
            auto vConstraint = this->pConstraint->WithName( name );
            auto asExternal  = Napi::External< Constraint >::New( info.Env(), &vConstraint );
            return GConstraint::constructor.New( { asExternal } );
        }

        PaoJsError( GConstraint::WithName 异常 );
        return info.Env().Undefined();
    }

    GConstraint::~GConstraint()
    {
#ifdef KAIFA
        LOG( INFO ) << "GConstraint::~GConstraint";
#endif
        if ( this->pConstraint )
        {
            delete[]( ( byte* )this->pConstraint );
            this->pConstraint = nullptr;
        }
    }

    GConstraint::GConstraint( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GConstraint >( info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto pConstraint = info[ 0 ].As< Napi::External< Constraint > >().Data();
            if ( typeid( *pConstraint ) == typeid( Constraint ) )
            {
                // 注意: 黑科技
                auto neicun = new byte[ sizeof( Constraint ) ];
                memcpy( neicun, pConstraint, sizeof( Constraint ) );
                this->pConstraint = ( Constraint* )neicun;
                return;
            }
        }

        PaoJsError( GConstraint::GConstraint 异常 );
    }
}  // namespace sat

}  // namespace operations_research

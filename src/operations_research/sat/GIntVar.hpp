#pragma once

#include <napi.h>
#include <ortools/sat/cp_model.h>
#include "../../commonheader.hpp"

namespace operations_research
{
namespace sat
{

    class GIntVar : public Napi::ObjectWrap< GIntVar >
    {
    public:
        static Napi::FunctionReference constructor;
        IntVar                         vIntVar;

    public:
        GIntVar( const Napi::CallbackInfo& info );
        ~GIntVar();

    public:
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
        Napi::Value         WithName( const Napi::CallbackInfo& info );
        Napi::Value         DebugString( const Napi::CallbackInfo& info );
        Napi::Value         index( const Napi::CallbackInfo& info );
        Napi::Value         Domain( const Napi::CallbackInfo& info );
    };

    Napi::FunctionReference GIntVar::constructor;

    Napi::Object GIntVar::Init( Napi::Env env, Napi::Object exports )
    {
        Napi::Function func = DefineClass(
            env,
            "IntVar",
            {
                InstanceMethod( "WithName", &GIntVar::WithName ),        //
                InstanceMethod( "DebugString", &GIntVar::DebugString ),  //
                InstanceMethod( "index", &GIntVar::index ),              //
                InstanceMethod( "Domain", &GIntVar::Domain ),            //
            } );

        constructor = Napi::Persistent( func );
        exports.Set( "IntVar", func );
        return exports;
    }

    Napi::Value GIntVar::WithName( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            auto name     = info[ 0 ].As< Napi::String >();
            auto intVar_  = this->vIntVar.WithName( name );
            auto external = Napi::External< IntVar >::New( info.Env(), &intVar_ );
            return GIntVar::constructor.New( { external } );
        }

        ThrowJsError( GIntVar::WithName ERROR );
        return info.Env().Undefined();
    }

    Napi::Value GIntVar::DebugString( const Napi::CallbackInfo& info )
    {
        return Napi::String::New( info.Env(), this->vIntVar.DebugString() );
    }

    Napi::Value GIntVar::index( const Napi::CallbackInfo& info )
    {
        return Napi::Number::New( info.Env(), this->vIntVar.index() );
    }

    Napi::Value GIntVar::Domain( const Napi::CallbackInfo& info )
    {
        auto vDomain  = this->vIntVar.Domain();
        auto external = Napi::External< operations_research::Domain >::New( info.Env(), &vDomain );
        return GDomain::constructor.New( { external } );
    }

    GIntVar::~GIntVar()
    {
#ifdef DEBUG
        LOG( INFO ) << "GIntVar::~GIntVar";
#endif
    }

    GIntVar::GIntVar( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GIntVar >( info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto pIntVar = info[ 0 ].As< Napi::External< IntVar > >().Data();
            if ( typeid( *pIntVar ) == typeid( IntVar ) )
            {
                this->vIntVar = *pIntVar;
                return;
            }
        }

        ThrowJsError( GIntVar::GIntVar ERROR );
    }
}  // namespace sat
}  // namespace operations_research

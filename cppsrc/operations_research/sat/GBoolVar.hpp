#pragma once

#include <napi.h>
#include <ortools/sat/cp_model.h>

namespace operations_research
{
namespace sat
{
    class GBoolVar : public Napi::ObjectWrap< GBoolVar >
    {
    public:
        static Napi::FunctionReference constructor;
        BoolVar                        vBoolVar;

    public:
        GBoolVar( const Napi::CallbackInfo& info );
        ~GBoolVar();

    public:
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
        Napi::Value         DebugString( const Napi::CallbackInfo& info );
        Napi::Value         WithName( const Napi::CallbackInfo& info );
        Napi::Value         index( const Napi::CallbackInfo& info );
        Napi::Value         Not( const Napi::CallbackInfo& info );
    };

    Napi::Object GBoolVar::Init( Napi::Env env, Napi::Object exports )
    {
        Napi::Function func = DefineClass(
            env,
            "BoolVar",
            {
                InstanceMethod( "DebugString", &GBoolVar::DebugString ),  //
                InstanceMethod( "WithName", &GBoolVar::WithName ),        //
                InstanceMethod( "index", &GBoolVar::index ),              //
                InstanceMethod( "Not", &GBoolVar::Not ),                  //
            } );

        constructor = Napi::Persistent( func );
        exports.Set( "BoolVar", func );
        return exports;
    }

    Napi::Value GBoolVar::DebugString( const Napi::CallbackInfo& info )
    {
        return Napi::String::New( info.Env(), this->vBoolVar.DebugString() );
    }

    Napi::Value GBoolVar::WithName( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            auto name     = info[ 0 ].As< Napi::String >();
            auto vBoolVar = this->vBoolVar.WithName( name );
            auto external = Napi::External< BoolVar >::New( info.Env(), &vBoolVar );
            return GBoolVar::constructor.New( { external } );
        }

        PaoJsError( GBoolVar::WithName ERROR );
        return info.Env().Undefined();
    }

    Napi::Value GBoolVar::index( const Napi::CallbackInfo& info )
    {
        return Napi::Number::New( info.Env(), this->vBoolVar.index() );
    }

    Napi::Value GBoolVar::Not( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 0 )
        {
            auto vBoolVar = this->vBoolVar.Not();
            auto external = Napi::External< BoolVar >::New( info.Env(), &vBoolVar );
            return GBoolVar::constructor.New( { external } );
        }

        PaoJsError( GBoolVar::Not ERROR );
        return info.Env().Undefined();
    }

    GBoolVar::GBoolVar( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GBoolVar >( info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto pBoolVar = info[ 0 ].As< Napi::External< BoolVar > >().Data();
            if ( typeid( *pBoolVar ) == typeid( BoolVar ) )
            {
                this->vBoolVar = *pBoolVar;
                return;
            }
        }

        PaoJsError( GBoolVar::GBoolVar ERROR );
    }

    GBoolVar::~GBoolVar()
    {
#ifdef KAIFA
        LOG( INFO ) << "GBoolVar::~GBoolVar";
#endif
    }

    Napi::FunctionReference GBoolVar::constructor;

}  // namespace sat
}  // namespace operations_research
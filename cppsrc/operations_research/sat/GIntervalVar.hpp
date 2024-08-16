#pragma once

#include <napi.h>
#include <ortools/sat/cp_model.h>
#include "../../commonheader.hpp"

namespace operations_research
{
namespace sat
{

    class GIntervalVar : public Napi::ObjectWrap< GIntervalVar >
    {
    public:
        static Napi::FunctionReference constructor;
        IntervalVar                    vIntervalVar;

    public:
        GIntervalVar( const Napi::CallbackInfo& info );
        ~GIntervalVar();

    public:
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
        Napi::Value         WithName( const Napi::CallbackInfo& info );
        Napi::Value         index( const Napi::CallbackInfo& info );
    };

    Napi::Object GIntervalVar::Init( Napi::Env env, Napi::Object exports )
    {
        Napi::Function func = DefineClass(
            env,
            "IntervalVar",
            {
                InstanceMethod( "WithName", &GIntervalVar::WithName ),  //
                InstanceMethod( "index", &GIntervalVar::index ),        //
            } );

        constructor = Napi::Persistent( func );
        exports.Set( "IntervalVar", func );
        return exports;
    }

    Napi::Value GIntervalVar::WithName( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            auto name         = info[ 0 ].As< Napi::String >();
            auto vIntervalVar = this->vIntervalVar.WithName( name );
            auto external     = Napi::External< IntervalVar >::New( info.Env(), &vIntervalVar );
            return GIntervalVar::constructor.New( { external } );
        }

        ThrowJsError( GIntervalVar::WithName ERROR );
        return info.Env().Undefined();
    }

    Napi::Value GIntervalVar::index( const Napi::CallbackInfo& info )
    {
        return Napi::Number::New( info.Env(), this->vIntervalVar.index() );
    }

    GIntervalVar::GIntervalVar( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GIntervalVar >( info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto pIntervalVar = info[ 0 ].As< Napi::External< IntervalVar > >().Data();
            if ( typeid( *pIntervalVar ) == typeid( IntervalVar ) )
            {
                this->vIntervalVar = *pIntervalVar;
                return;
            }
        }

        ThrowJsError( GIntervalVar::GIntervalVar 异常 );
    }

    GIntervalVar::~GIntervalVar()
    {
#ifdef DEBUG
        LOG( INFO ) << "GIntervalVar::~GIntervalVar";
#endif
    }

    Napi::FunctionReference GIntervalVar::constructor;
}  // namespace sat
}  // namespace operations_research
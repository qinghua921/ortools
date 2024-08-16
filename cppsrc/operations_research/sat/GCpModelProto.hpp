#pragma once

#include <napi.h>
#include <ortools/sat/cp_model.h>
#include "../../commonheader.hpp"

namespace operations_research
{
namespace sat
{

    class GCpModelProto : public Napi::ObjectWrap< GCpModelProto >
    {
    public:
        static Napi::FunctionReference constructor;
        CpModelProto*                  pCpModelProto;

    public:
        GCpModelProto( const Napi::CallbackInfo& info );
        ~GCpModelProto();

    public:
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
        Napi::Value         DebugString( const Napi::CallbackInfo& info );
    };

    Napi::FunctionReference GCpModelProto::constructor;

    Napi::Object GCpModelProto::Init( Napi::Env env, Napi::Object exports )
    {
        Napi::Function func = DefineClass(
            env,
            "CpModelProto",
            {
                InstanceMethod( "DebugString", &GCpModelProto::DebugString ),  //
            } );

        constructor = Napi::Persistent( func );
        exports.Set( "CpModelProto", func );
        return exports;
    }

    Napi::Value GCpModelProto::DebugString( const Napi::CallbackInfo& info )
    {
        return Napi::String::New( info.Env(), this->pCpModelProto->DebugString() );
    }

    GCpModelProto::GCpModelProto( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GCpModelProto >( info ), pCpModelProto( nullptr )
    {
        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto pCpModelProto = info[ 0 ].As< Napi::External< CpModelProto > >().Data();
            if ( typeid( *pCpModelProto ) == typeid( CpModelProto ) )
            {
                this->pCpModelProto = pCpModelProto;
                return;
            }
        }

        PaoJsError( GCpModelProto::GCpModelProto 异常 );
    }

    GCpModelProto::~GCpModelProto()
    {
#ifdef KAIFA
        LOG( INFO ) << "GCpModelProto::~GCpModelProto";
#endif
    }

}  // namespace sat
}  // namespace operations_research
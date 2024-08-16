#pragma once

#include <napi.h>
#include "../../commonheader.hpp"
#include <ortools/sat/cp_model.h>
namespace operations_research
{
namespace sat
{
    class GCpSolverResponse : public Napi::ObjectWrap< GCpSolverResponse >
    {
    public:
        static Napi::FunctionReference constructor;
        CpSolverResponse*              pCpSolverResponse;
        bool                           deleteit;

    public:
        GCpSolverResponse( const Napi::CallbackInfo& info );
        ~GCpSolverResponse();

    public:
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
        Napi::Value         status( const Napi::CallbackInfo& info );
        Napi::Value         objective_value( const Napi::CallbackInfo& info );
    };

    Napi::FunctionReference GCpSolverResponse::constructor;

    Napi::Object GCpSolverResponse::Init( Napi::Env env, Napi::Object exports )
    {
        Napi::Function func = DefineClass(
            env,
            "CpSolverResponse",
            {
                InstanceMethod( "status", &GCpSolverResponse::status ),                    //
                InstanceMethod( "objective_value", &GCpSolverResponse::objective_value ),  //
            } );

        constructor = Napi::Persistent( func );
        exports.Set( "CpSolverResponse", func );
        return exports;
    }

    Napi::Value GCpSolverResponse::objective_value( const Napi::CallbackInfo& info )
    {
        auto ret = this->pCpSolverResponse->objective_value();
        return Napi::Number::New( info.Env(), ret );
    }

    Napi::Value GCpSolverResponse::status( const Napi::CallbackInfo& info )
    {
        auto ret = this->pCpSolverResponse->status();
        return Napi::Number::New( info.Env(), ret );
    }

    GCpSolverResponse::GCpSolverResponse( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GCpSolverResponse >( info )
    {
        if ( info.Length() == 2 && info[ 0 ].IsExternal() && info[ 1 ].IsBoolean() )
        {
            auto pCpSolverResponse = info[ 0 ].As< Napi::External< CpSolverResponse > >().Data();
            if ( typeid( *pCpSolverResponse ) == typeid( CpSolverResponse ) )
            {
                this->pCpSolverResponse = pCpSolverResponse;
                this->deleteit          = info[ 1 ].As< Napi::Boolean >();
                return;
            }
        }

        PaoJsError( GCpSolverResponse::GCpSolverResponse ERROR );
    }

    GCpSolverResponse::~GCpSolverResponse()
    {
#ifdef KAIFA
        LOG( INFO ) << "GCpSolverResponse::~GCpSolverResponse";
#endif
        if ( this->pCpSolverResponse && this->deleteit )
        {
            delete this->pCpSolverResponse;
            this->pCpSolverResponse = nullptr;
        }
    }
}  // namespace sat
}  // namespace operations_research
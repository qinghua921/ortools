#pragma once

#include <napi.h>
#include <ortools/sat/cp_model.h>
#include "../../commonheader.hpp"

namespace operations_research
{
namespace sat
{

    class GSatParameters : public Napi::ObjectWrap< GSatParameters >
    {
    public:
        static Napi::FunctionReference constructor;
        SatParameters                  vSatParameters;

    public:
        GSatParameters( const Napi::CallbackInfo& info );
        ~GSatParameters();

    public:
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
        Napi::Value         set_enumerate_all_solutions( const Napi::CallbackInfo& info );
    };

    GSatParameters::GSatParameters( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GSatParameters >( info )
    {
        if ( info.Length() == 0 )
        {
            return;
        }

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto pSatParameters = info[ 0 ].As< Napi::External< SatParameters > >().Data();
            if ( typeid( *pSatParameters ) == typeid( SatParameters ) )
            {
                this->vSatParameters = *pSatParameters;
                return;
            }
        }

        PaoJsError( GSatParameters::GSatParameters ERROR );
    }

    GSatParameters::~GSatParameters()
    {
    }

    Napi::Object GSatParameters::Init( Napi::Env env, Napi::Object exports )
    {
        Napi::Function func = DefineClass(
            env,
            "SatParameters",
            {
                InstanceMethod( "set_enumerate_all_solutions", &GSatParameters::set_enumerate_all_solutions ),  //
            } );

        constructor = Napi::Persistent( func );
        exports.Set( "SatParameters", func );
        return exports;
    }

    Napi::Value GSatParameters::set_enumerate_all_solutions( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsBoolean() )
        {
            this->vSatParameters.set_enumerate_all_solutions( info[ 0 ].As< Napi::Boolean >() );
            return info.Env().Undefined();
        }

        PaoJsError( GSatParameters::set_enumerate_all_solutions ERROR );
        return info.Env().Undefined();
    }

    Napi::FunctionReference GSatParameters::constructor;

}  // namespace sat
}  // namespace operations_research
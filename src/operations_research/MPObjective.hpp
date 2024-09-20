#pragma once

#include "napi.h"
#include "ortools/linear_solver/linear_solver.h"
#include "MPVariable.hpp"

namespace operations_research
{

class GMPObjective : public Napi::ObjectWrap< GMPObjective >
{
public:
    static inline Napi::FunctionReference constructor;
    MPObjective*                          pMPObjective = nullptr;

    GMPObjective( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GMPObjective >( info )
    {
        Napi::Env env = info.Env();

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external = info[ 0 ].As< Napi::External< MPObjective > >();
            pMPObjective  = dynamic_cast< MPObjective* >( external.Data() );
            if ( pMPObjective ) return;
        }

        Napi::TypeError::New( env, "operations_research::GMPObjective::GMPObjective : Invalid arguments" ).ThrowAsJavaScriptException();
    };

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "MPObjective",
            {
                InstanceMethod( "Clear", &GMPObjective::Clear ),
                InstanceMethod( "SetCoefficient", &GMPObjective::SetCoefficient ),
                InstanceMethod( "GetCoefficient", &GMPObjective::GetCoefficient ),
                InstanceMethod( "terms", &GMPObjective::terms ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPObjective" ), func );
        return exports;
    };

    //     const absl::flat_hash_map< const MPVariable*, double >& terms() const
    Napi::Value terms( const Napi::CallbackInfo& info )
    {
        auto              env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            auto         terms = pMPObjective->terms();
            Napi::Object ret   = Napi::Object::New( env );
            for ( auto it = terms.begin(); it != terms.end(); ++it )
            {
                auto var   = it->first;
                auto coeff = it->second;
                // FIXME: is it safe to cast const MPVariable* to MPVariable*?
                auto gvar = GMPVariable::constructor.New( { Napi::External< MPVariable >::New( env, ( MPVariable* )var ) } );
                ret.Set( gvar, Napi::Number::New( env, coeff ) );
            }
            return ret;
        }

        Napi::TypeError::New( env, "operations_research::GMPObjective::terms : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Undefined();
    }

    //     double GetCoefficient( const MPVariable* var ) const;
    Napi::Value GetCoefficient( const Napi::CallbackInfo& info )
    {
        auto              env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
        {
            auto   var   = GMPVariable::Unwrap( info[ 0 ].As< Napi::Object >() );
            double coeff = pMPObjective->GetCoefficient( var->pMPVariable );
            return Napi::Number::New( env, coeff );
        }

        Napi::TypeError::New( env, "operations_research::GMPObjective::GetCoefficient : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Undefined();
    }

    //     void SetCoefficient( const MPVariable* var, double coeff );
    Napi::Value SetCoefficient( const Napi::CallbackInfo& info )
    {
        auto              env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 2 && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() )
             && info[ 1 ].IsNumber() )
        {
            auto   var   = GMPVariable::Unwrap( info[ 0 ].As< Napi::Object >() );
            double coeff = info[ 1 ].As< Napi::Number >().DoubleValue();
            pMPObjective->SetCoefficient( var->pMPVariable, coeff );
            return env.Undefined();
        }

        Napi::TypeError::New( env, "operations_research::GMPObjective::SetCoefficient : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Undefined();
    }

    //     void Clear();
    Napi::Value Clear( const Napi::CallbackInfo& info )
    {
        auto              env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            pMPObjective->Clear();
            return env.Undefined();
        }

        Napi::TypeError::New( env, "operations_research::GMPObjective::Clear : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Undefined();
    }
};

};  // namespace operations_research
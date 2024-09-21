#pragma once

#include "napi.h"
#include "ortools/linear_solver/linear_solver.h"
#include "MPVariable.hpp"
#include "MPConstraint.hpp"
#include "LinearRange.hpp"
#include "MPObjective.hpp"

namespace operations_research
{

class GMPSolver : public Napi::ObjectWrap< GMPSolver >
{
public:
    static inline Napi::FunctionReference constructor;
    MPSolver*                             pMPSolver = nullptr;

    GMPSolver( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GMPSolver >( info )
    {
        Napi::Env env = info.Env();

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external = info[ 0 ].As< Napi::External< MPSolver > >();
            pMPSolver     = dynamic_cast< MPSolver* >( external.Data() );
            if ( pMPSolver ) return;
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::GMPSolver : Invalid arguments" ).ThrowAsJavaScriptException();
    };

    ~GMPSolver()
    {
        if ( pMPSolver ) delete pMPSolver;
    }

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "MPSolver",
            {
                StaticMethod( "CreateSolver", &GMPSolver::CreateSolver ),
                InstanceMethod( "MakeBoolVar", &GMPSolver::MakeBoolVar ),
                InstanceMethod( "MakeRowConstraint", &GMPSolver::MakeRowConstraint ),
                InstanceMethod( "MutableObjective", &GMPSolver::MutableObjective ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPSolver" ), func );
        return exports;
    };

    // MPObjective* MutableObjective();
    Napi::Value MutableObjective( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            MPObjective* pMPObjective = pMPSolver->MutableObjective();
            auto         external     = Napi::External< MPObjective >::New( env, pMPObjective );
            return GMPObjective::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MutableObjective : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    Napi::Value MakeRowConstraint( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        // MPConstraint* MakeRowConstraint( double lb, double ub );
        if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() )
        {
            double        lb            = info[ 0 ].As< Napi::Number >().DoubleValue();
            double        ub            = info[ 1 ].As< Napi::Number >().DoubleValue();
            MPConstraint* pMPConstraint = pMPSolver->MakeRowConstraint( lb, ub );
            auto          external      = Napi::External< MPConstraint >::New( env, pMPConstraint );
            return GMPConstraint::constructor.New( { external } );
        }

        // MPConstraint* MakeRowConstraint();
        if ( info.Length() == 0 )
        {
            MPConstraint* pMPConstraint = pMPSolver->MakeRowConstraint();
            auto          external      = Napi::External< MPConstraint >::New( env, pMPConstraint );
            return GMPConstraint::constructor.New( { external } );
        }

        //     MPConstraint* MakeRowConstraint( double lb, double ub,
        //                                      const std::string& name );
        if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber()
             && info[ 2 ].IsString() )
        {
            double        lb            = info[ 0 ].As< Napi::Number >().DoubleValue();
            double        ub            = info[ 1 ].As< Napi::Number >().DoubleValue();
            std::string   name          = info[ 2 ].As< Napi::String >().Utf8Value();
            MPConstraint* pMPConstraint = pMPSolver->MakeRowConstraint( lb, ub, name );
            auto          external      = Napi::External< MPConstraint >::New( env, pMPConstraint );
            return GMPConstraint::constructor.New( { external } );
        }

        // MPConstraint* MakeRowConstraint( const std::string& name );
        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string   name          = info[ 0 ].As< Napi::String >().Utf8Value();
            MPConstraint* pMPConstraint = pMPSolver->MakeRowConstraint( name );
            auto          external      = Napi::External< MPConstraint >::New( env, pMPConstraint );
            return GMPConstraint::constructor.New( { external } );
        }

        // MPConstraint* MakeRowConstraint( const LinearRange& range );
        if ( info.Length() == 1 && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearRange::constructor.Value() ) )
        {
            auto          linearRange   = GLinearRange::Unwrap( info[ 0 ].As< Napi::Object >() );
            LinearRange*  pLinearRange  = linearRange->pLinearRange;
            MPConstraint* pMPConstraint = pMPSolver->MakeRowConstraint( *pLinearRange );
            auto          external      = Napi::External< MPConstraint >::New( env, pMPConstraint );
            return GMPConstraint::constructor.New( { external } );
        }
        //     MPConstraint* MakeRowConstraint( const LinearRange& range,
        //                                      const std::string& name );
        if ( info.Length() == 2 && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearRange::constructor.Value() )
             && info[ 1 ].IsString() )
        {
            auto          linearRange   = GLinearRange::Unwrap( info[ 0 ].As< Napi::Object >() );
            LinearRange*  pLinearRange  = linearRange->pLinearRange;
            std::string   name          = info[ 1 ].As< Napi::String >().Utf8Value();
            MPConstraint* pMPConstraint = pMPSolver->MakeRowConstraint( *pLinearRange, name );
            auto          external      = Napi::External< MPConstraint >::New( env, pMPConstraint );
            return GMPConstraint::constructor.New( { external } );
        }
        
        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeRowConstraint : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // MPVariable* MakeBoolVar( const std::string& name );
    Napi::Value MakeBoolVar( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string name        = info[ 0 ].As< Napi::String >().Utf8Value();
            MPVariable* pMPVariable = pMPSolver->MakeBoolVar( name );
            auto        external    = Napi::External< MPVariable >::New( env, pMPVariable );
            return GMPVariable::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeBoolVar : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // static MPSolver* CreateSolver( const std::string& solver_id );
    static Napi::Value CreateSolver( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string solver_id = info[ 0 ].As< Napi::String >().Utf8Value();
            MPSolver*   pMPSolver = MPSolver::CreateSolver( solver_id );
            auto        external  = Napi::External< MPSolver >::New( env, pMPSolver );
            return GMPSolver::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::CreateSolver : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };
};

};  // namespace operations_research
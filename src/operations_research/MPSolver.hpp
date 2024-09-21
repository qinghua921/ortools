#pragma once

#include "napi.h"
#include "ortools/linear_solver/linear_solver.h"
#include "MPVariable.hpp"
#include "MPConstraint.hpp"
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
    };

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );

        auto enum_ResultStatus = Napi::Object::New( env );
        enum_ResultStatus.Set( "OPTIMAL", static_cast< int >( MPSolver::ResultStatus::OPTIMAL ) );
        enum_ResultStatus.Set( "FEASIBLE", static_cast< int >( MPSolver::ResultStatus::FEASIBLE ) );
        enum_ResultStatus.Set( "INFEASIBLE", static_cast< int >( MPSolver::ResultStatus::INFEASIBLE ) );
        enum_ResultStatus.Set( "UNBOUNDED", static_cast< int >( MPSolver::ResultStatus::UNBOUNDED ) );
        enum_ResultStatus.Set( "ABNORMAL", static_cast< int >( MPSolver::ResultStatus::ABNORMAL ) );
        enum_ResultStatus.Set( "MODEL_INVALID", static_cast< int >( MPSolver::ResultStatus::MODEL_INVALID ) );
        enum_ResultStatus.Set( "NOT_SOLVED", static_cast< int >( MPSolver::ResultStatus::NOT_SOLVED ) );

        Napi::Function func = DefineClass(
            env, "MPSolver",
            {
                StaticValue( "ResultStatus", enum_ResultStatus ),

                StaticMethod( "CreateSolver", &GMPSolver::CreateSolver ),
                InstanceMethod( "MakeBoolVar", &GMPSolver::MakeBoolVar ),
                InstanceMethod( "MakeRowConstraint", &GMPSolver::MakeRowConstraint ),
                InstanceMethod( "MutableObjective", &GMPSolver::MutableObjective ),
                InstanceMethod( "Solve", &GMPSolver::Solve ),

            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPSolver" ), func );
        return exports;
    };

    // ResultStatus Solve();
    Napi::Value Solve( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            MPSolver::ResultStatus status = pMPSolver->Solve();
            return Napi::Number::New( env, static_cast< int >( status ) );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::Solve : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }

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
    }

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
        if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
        {
            double        lb            = info[ 0 ].As< Napi::Number >().DoubleValue();
            double        ub            = info[ 1 ].As< Napi::Number >().DoubleValue();
            std::string   name          = info[ 2 ].As< Napi::String >().Utf8Value();
            MPConstraint* pMPConstraint = pMPSolver->MakeRowConstraint( lb, ub, name );
            auto          external      = Napi::External< MPConstraint >::New( env, pMPConstraint );
            return GMPConstraint::constructor.New( { external } );
        }

        //     MPConstraint* MakeRowConstraint( const std::string& name );
        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string   name          = info[ 0 ].As< Napi::String >().Utf8Value();
            MPConstraint* pMPConstraint = pMPSolver->MakeRowConstraint( name );
            auto          external      = Napi::External< MPConstraint >::New( env, pMPConstraint );
            return GMPConstraint::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeRowConstraint : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }

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
    }

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
    }
};

};  // namespace operations_research
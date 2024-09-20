#pragma once

#include "napi.h"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{

class GMPVariable : public Napi::ObjectWrap< GMPVariable >
{
public:
    static inline Napi::FunctionReference constructor;
    MPVariable*                           pMPVariable = nullptr;

    GMPVariable( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GMPVariable >( info )
    {
        Napi::Env env = info.Env();

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external = info[ 0 ].As< Napi::External< MPVariable > >();
            pMPVariable   = dynamic_cast< MPVariable* >( external.Data() );
            if ( pMPVariable ) return;
        }

        Napi::TypeError::New( env, "operations_research::GMPVariable::GMPVariable : Invalid arguments" ).ThrowAsJavaScriptException();
    };

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "MPVariable",
            {
                InstanceMethod( "name", &GMPVariable::Name ),
                InstanceMethod( "SetInteger", &GMPVariable::SetInteger ),
                InstanceMethod( "integer", &GMPVariable::integer ),
                InstanceMethod( "solution_value", &GMPVariable::solution_value ),
                InstanceMethod( "index", &GMPVariable::index ),
                InstanceMethod( "lb", &GMPVariable::lb ),
                InstanceMethod( "ub", &GMPVariable::ub ),
                InstanceMethod( "SetLB", &GMPVariable::SetLB ),
                InstanceMethod( "SetUB", &GMPVariable::SetUB ),
                InstanceMethod( "SetBounds", &GMPVariable::SetBounds ),
                InstanceMethod( "unrounded_solution_value", &GMPVariable::unrounded_solution_value ),
                InstanceMethod( "branching_priority", &GMPVariable::branching_priority ),
                InstanceMethod( "SetBranchingPriority", &GMPVariable::SetBranchingPriority ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPVariable" ), func );
        return exports;
    };

    //     void SetBranchingPriority( int priority );
    Napi::Value SetBranchingPriority( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsNumber() )
        {
            int priority = info[ 0 ].As< Napi::Number >().Int32Value();
            pMPVariable->SetBranchingPriority( priority );
            return env.Undefined();
        }

        Napi::TypeError::New( env, "operations_research::GMPVariable::SetBranchingPriority : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }

    //     int branching_priority() const
    Napi::Value branching_priority( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            return Napi::Number::New( env, pMPVariable->branching_priority() );
        }

        Napi::TypeError::New( env, "operations_research::GMPVariable::branching_priority : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }

    //     double reduced_cost() const;
    Napi::Value reduced_cost( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            return Napi::Number::New( env, pMPVariable->reduced_cost() );
        }

        Napi::TypeError::New( env, "operations_research::GMPVariable::reduced_cost : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }

    //     double unrounded_solution_value() const;
    Napi::Value unrounded_solution_value( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            return Napi::Number::New( env, pMPVariable->unrounded_solution_value() );
        }

        Napi::TypeError::New( env, "operations_research::GMPVariable::unrounded_solution_value : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }
    //     void SetBounds( double lb, double ub );
    Napi::Value SetBounds( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() )
        {
            double lb = info[ 0 ].As< Napi::Number >().DoubleValue();
            double ub = info[ 1 ].As< Napi::Number >().DoubleValue();
            pMPVariable->SetBounds( lb, ub );
            return env.Undefined();
        }

        Napi::TypeError::New( env, "operations_research::GMPVariable::SetBounds : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }
    //     void SetUB( double ub )
    Napi::Value SetUB( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsNumber() )
        {
            double ub = info[ 0 ].As< Napi::Number >().DoubleValue();
            pMPVariable->SetUB( ub );
            return env.Undefined();
        }

        Napi::TypeError::New( env, "operations_research::GMPVariable::SetUB : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }
    //     void SetLB( double lb )
    Napi::Value SetLB( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsNumber() )
        {
            double lb = info[ 0 ].As< Napi::Number >().DoubleValue();
            pMPVariable->SetLB( lb );
            return env.Undefined();
        }

        Napi::TypeError::New( env, "operations_research::GMPVariable::SetLB : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }
    //     double ub() const
    Napi::Value ub( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            return Napi::Number::New( env, pMPVariable->ub() );
        }

        Napi::TypeError::New( env, "operations_research::GMPVariable::ub : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }
    //     double lb() const
    Napi::Value lb( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            return Napi::Number::New( env, pMPVariable->lb() );
        }

        Napi::TypeError::New( env, "operations_research::GMPVariable::lb : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }

    //     int index() const
    Napi::Value index( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            return Napi::Number::New( env, pMPVariable->index() );
        }

        Napi::TypeError::New( env, "operations_research::GMPVariable::index : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }

    //     double solution_value() const;
    Napi::Value solution_value( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            return Napi::Number::New( env, pMPVariable->solution_value() );
        }

        Napi::TypeError::New( env, "operations_research::GMPVariable::solution_value : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }

    //     bool integer() const
    Napi::Value integer( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            return Napi::Boolean::New( env, pMPVariable->integer() );
        }

        Napi::TypeError::New( env, "operations_research::GMPVariable::Integer : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }

    //     void SetInteger( bool integer );
    Napi::Value SetInteger( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsBoolean() )
        {
            bool integer = info[ 0 ].As< Napi::Boolean >().Value();
            pMPVariable->SetInteger( integer );
            return env.Undefined();
        }

        Napi::TypeError::New( env, "operations_research::GMPVariable::SetInteger : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }

    //     const std::string& name() const
    Napi::Value Name( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            return Napi::String::New( env, pMPVariable->name() );
        }

        Napi::TypeError::New( env, "operations_research::GMPVariable::Name : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }
};

};  // namespace operations_research
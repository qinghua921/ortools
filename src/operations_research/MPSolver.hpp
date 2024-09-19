#pragma once

#include "napi.h"
#include "ortools/linear_solver/linear_solver.h"
#include "MPVariable.hpp"
#include "MPConstraint.hpp"
#include "LinearRange.hpp"

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

        // MPSolver( const std::string& name, OptimizationProblemType problem_type );
        if ( info.Length() == 2 && info[ 0 ].IsString() && info[ 1 ].IsNumber() )
        {
            std::string name         = info[ 0 ].As< Napi::String >().Utf8Value();
            int         problem_type = info[ 1 ].As< Napi::Number >().Int32Value();
            pMPSolver                = new MPSolver( name, static_cast< MPSolver::OptimizationProblemType >( problem_type ) );
            return;
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
        Napi::Function    func = DefineClass(
            env, "MPSolver",
            {
                StaticMethod( "CreateSolver", &GMPSolver::CreateSolver ),
                StaticMethod( "SupportsProblemType", &GMPSolver::SupportsProblemType ),
                StaticMethod( "ParseSolverType", &GMPSolver::ParseSolverType ),
                StaticMethod( "ParseSolverTypeOrDie", &GMPSolver::ParseSolverTypeOrDie ),
                InstanceMethod( "IsMIP", &GMPSolver::IsMIP ),
                InstanceMethod( "Name", &GMPSolver::Name ),
                InstanceMethod( "ProblemType", &GMPSolver::ProblemType ),
                InstanceMethod( "Clear", &GMPSolver::Clear ),
                InstanceMethod( "NumVariables", &GMPSolver::NumVariables ),
                InstanceMethod( "variables", &GMPSolver::variables ),
                InstanceMethod( "variable", &GMPSolver::variable ),
                InstanceMethod( "LookupVariableOrNull", &GMPSolver::LookupVariableOrNull ),
                InstanceMethod( "MakeVar", &GMPSolver::MakeVar ),
                InstanceMethod( "MakeNumVar", &GMPSolver::MakeNumVar ),
                InstanceMethod( "MakeIntVar", &GMPSolver::MakeIntVar ),
                InstanceMethod( "MakeBoolVar", &GMPSolver::MakeBoolVar ),
                InstanceMethod( "MakeVarArray", &GMPSolver::MakeVarArray ),
                InstanceMethod( "MakeNumVarArray", &GMPSolver::MakeNumVarArray ),
                InstanceMethod( "MakeIntVarArray", &GMPSolver::MakeIntVarArray ),
                InstanceMethod( "MakeBoolVarArray", &GMPSolver::MakeBoolVarArray ),
                InstanceMethod( "NumConstraints", &GMPSolver::NumConstraints ),
                InstanceMethod( "constraints", &GMPSolver::constraints ),
                InstanceMethod( "constraint", &GMPSolver::constraint ),
                InstanceMethod( "LookupConstraintOrNull", &GMPSolver::LookupConstraintOrNull ),
                InstanceMethod( "MakeRowConstraint", &GMPSolver::MakeRowConstraint ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPSolver" ), func );
        return exports;
    };

    Napi::Value MakeRowConstraint( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        //     MPConstraint* MakeRowConstraint( double lb, double ub );
        if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() )
        {
            double lb  = info[ 0 ].As< Napi::Number >().DoubleValue();
            double ub  = info[ 1 ].As< Napi::Number >().DoubleValue();
            auto   row = pMPSolver->MakeRowConstraint( lb, ub );
            if ( row )
            {
                auto external = Napi::External< MPConstraint >::New( env, row );
                return GMPConstraint::constructor.New( { external } );
            }
            return env.Null();
        }

        //     MPConstraint* MakeRowConstraint();
        if ( info.Length() == 0 )
        {
            auto row = pMPSolver->MakeRowConstraint();
            if ( row )
            {
                auto external = Napi::External< MPConstraint >::New( env, row );
                return GMPConstraint::constructor.New( { external } );
            }
            return env.Null();
        }

        //     MPConstraint* MakeRowConstraint( double lb, double ub,
        //                                      const std::string& name );
        if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
        {
            double      lb   = info[ 0 ].As< Napi::Number >().DoubleValue();
            double      ub   = info[ 1 ].As< Napi::Number >().DoubleValue();
            std::string name = info[ 2 ].As< Napi::String >().Utf8Value();
            auto        row  = pMPSolver->MakeRowConstraint( lb, ub, name );
            if ( row )
            {
                auto external = Napi::External< MPConstraint >::New( env, row );
                return GMPConstraint::constructor.New( { external } );
            }
            return env.Null();
        }

        //     MPConstraint* MakeRowConstraint( const std::string& name );
        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string name = info[ 0 ].As< Napi::String >().Utf8Value();
            auto        row  = pMPSolver->MakeRowConstraint( name );
            if ( row )
            {
                auto external = Napi::External< MPConstraint >::New( env, row );
                return GMPConstraint::constructor.New( { external } );
            }
            return env.Null();
        }

        //     MPConstraint* MakeRowConstraint( const LinearRange& range );
        if ( info.Length() == 1 && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearRange::constructor.Value() ) )
        {
            auto range = GLinearRange::Unwrap( info[ 0 ].As< Napi::Object >() );
            auto row   = pMPSolver->MakeRowConstraint( *range->pLinearRange );
            if ( row )
            {
                auto external = Napi::External< MPConstraint >::New( env, row );
                return GMPConstraint::constructor.New( { external } );
            }
            return env.Null();
        }

        //     MPConstraint* MakeRowConstraint( const LinearRange& range,
        //                                      const std::string& name );
        if ( info.Length() == 2 && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearRange::constructor.Value() )
             && info[ 1 ].IsString() )
        {
            auto        range = GLinearRange::Unwrap( info[ 0 ].As< Napi::Object >() );
            std::string name  = info[ 1 ].As< Napi::String >().Utf8Value();
            auto        row   = pMPSolver->MakeRowConstraint( *range->pLinearRange, name );
            if ( row )
            {
                auto external = Napi::External< MPConstraint >::New( env, row );
                return GMPConstraint::constructor.New( { external } );
            }
            return env.Null();
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeRowConstraint : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     MPConstraint* LookupConstraintOrNull(
    //         const std::string& constraint_name ) const;
    Napi::Value LookupConstraintOrNull( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string constraint_name = info[ 0 ].As< Napi::String >().Utf8Value();
            auto        constraint      = pMPSolver->LookupConstraintOrNull( constraint_name );
            if ( constraint )
            {
                auto external = Napi::External< MPConstraint >::New( env, constraint );
                return GMPConstraint::constructor.New( { external } );
            }
            return env.Null();
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::LookupConstraintOrNull : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     MPConstraint* constraint( int index ) const
    Napi::Value constraint( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsNumber() )
        {
            int  index      = info[ 0 ].As< Napi::Number >().Int32Value();
            auto constraint = pMPSolver->constraint( index );
            if ( constraint )
            {
                auto external = Napi::External< MPConstraint >::New( env, constraint );
                return GMPConstraint::constructor.New( { external } );
            }
            return env.Null();
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::constraint : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     const std::vector< MPConstraint* >& constraints() const
    Napi::Value constraints( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            auto        constraints = pMPSolver->constraints();
            Napi::Array result      = Napi::Array::New( env, constraints.size() );
            for ( int i = 0; i < constraints.size(); i++ )
            {
                auto external = Napi::External< MPConstraint >::New( env, constraints[ i ] );
                result.Set( i, GMPConstraint::constructor.New( { external } ) );
            }
            return result;
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::constraints : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     int NumConstraints() const
    Napi::Value NumConstraints( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            return Napi::Number::New( env, pMPSolver->NumConstraints() );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::NumConstraints : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     void MakeBoolVarArray( int nb, const std::string& name,
    //                            std::vector< MPVariable* >* vars );
    Napi::Value MakeBoolVarArray( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsString() )
        {
            int                        nb          = info[ 0 ].As< Napi::Number >().Int32Value();
            std::string                name_prefix = info[ 1 ].As< Napi::String >().Utf8Value();
            std::vector< MPVariable* > vars;
            pMPSolver->MakeBoolVarArray( nb, name_prefix, &vars );
            Napi::Array result = Napi::Array::New( env, vars.size() );
            for ( int i = 0; i < vars.size(); i++ )
            {
                auto external = Napi::External< MPVariable >::New( env, vars[ i ] );
                result.Set( i, GMPVariable::constructor.New( { external } ) );
            }
            return result;
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeBoolVarArray : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     void MakeIntVarArray( int nb, double lb, double ub, const std::string& name,
    //                           std::vector< MPVariable* >* vars );
    Napi::Value MakeIntVarArray( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 4 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsNumber() && info[ 3 ].IsString() )
        {
            int                        nb          = info[ 0 ].As< Napi::Number >().Int32Value();
            double                     lb          = info[ 1 ].As< Napi::Number >().DoubleValue();
            double                     ub          = info[ 2 ].As< Napi::Number >().DoubleValue();
            std::string                name_prefix = info[ 3 ].As< Napi::String >().Utf8Value();
            std::vector< MPVariable* > vars;
            pMPSolver->MakeIntVarArray( nb, lb, ub, name_prefix, &vars );
            Napi::Array result = Napi::Array::New( env, vars.size() );
            for ( int i = 0; i < vars.size(); i++ )
            {
                auto external = Napi::External< MPVariable >::New( env, vars[ i ] );
                result.Set( i, GMPVariable::constructor.New( { external } ) );
            }
            return result;
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeIntVarArray : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     void MakeNumVarArray( int nb, double lb, double ub, const std::string& name,
    //                           std::vector< MPVariable* >* vars );
    Napi::Value MakeNumVarArray( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 4 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsNumber() && info[ 3 ].IsString() )
        {
            int                        nb          = info[ 0 ].As< Napi::Number >().Int32Value();
            double                     lb          = info[ 1 ].As< Napi::Number >().DoubleValue();
            double                     ub          = info[ 2 ].As< Napi::Number >().DoubleValue();
            std::string                name_prefix = info[ 3 ].As< Napi::String >().Utf8Value();
            std::vector< MPVariable* > vars;
            pMPSolver->MakeNumVarArray( nb, lb, ub, name_prefix, &vars );
            Napi::Array result = Napi::Array::New( env, vars.size() );
            for ( int i = 0; i < vars.size(); i++ )
            {
                auto external = Napi::External< MPVariable >::New( env, vars[ i ] );
                result.Set( i, GMPVariable::constructor.New( { external } ) );
            }
            return result;
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeNumVarArray : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     void MakeVarArray( int nb, double lb, double ub, bool integer,
    //                        const std::string&          name_prefix,
    //                        std::vector< MPVariable* >* vars );
    Napi::Value MakeVarArray( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 5 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsNumber() && info[ 3 ].IsBoolean() && info[ 4 ].IsString() )
        {
            int                        nb          = info[ 0 ].As< Napi::Number >().Int32Value();
            double                     lb          = info[ 1 ].As< Napi::Number >().DoubleValue();
            double                     ub          = info[ 2 ].As< Napi::Number >().DoubleValue();
            bool                       integer     = info[ 3 ].As< Napi::Boolean >().Value();
            std::string                name_prefix = info[ 4 ].As< Napi::String >().Utf8Value();
            std::vector< MPVariable* > vars;
            pMPSolver->MakeVarArray( nb, lb, ub, integer, name_prefix, &vars );
            Napi::Array result = Napi::Array::New( env, vars.size() );
            for ( int i = 0; i < vars.size(); i++ )
            {
                auto external = Napi::External< MPVariable >::New( env, vars[ i ] );
                result.Set( i, GMPVariable::constructor.New( { external } ) );
            }
            return result;
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeVarArray : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     MPVariable* MakeBoolVar( const std::string& name );
    Napi::Value MakeBoolVar( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string name     = info[ 0 ].As< Napi::String >().Utf8Value();
            auto        pVar     = pMPSolver->MakeBoolVar( name );
            auto        external = Napi::External< MPVariable >::New( env, pVar );
            return GMPVariable::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeBoolVar : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     MPVariable* MakeIntVar( double lb, double ub, const std::string& name );
    Napi::Value MakeIntVar( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
        {
            double      lb       = info[ 0 ].As< Napi::Number >().DoubleValue();
            double      ub       = info[ 1 ].As< Napi::Number >().DoubleValue();
            std::string name     = info[ 2 ].As< Napi::String >().Utf8Value();
            auto        pVar     = pMPSolver->MakeIntVar( lb, ub, name );
            auto        external = Napi::External< MPVariable >::New( env, pVar );
            return GMPVariable::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeIntVar : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     MPVariable* MakeNumVar( double lb, double ub, const std::string& name );
    Napi::Value MakeNumVar( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
        {
            double      lb       = info[ 0 ].As< Napi::Number >().DoubleValue();
            double      ub       = info[ 1 ].As< Napi::Number >().DoubleValue();
            std::string name     = info[ 2 ].As< Napi::String >().Utf8Value();
            auto        pVar     = pMPSolver->MakeNumVar( lb, ub, name );
            auto        external = Napi::External< MPVariable >::New( env, pVar );
            return GMPVariable::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeNumVar : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     MPVariable* MakeVar( double lb, double ub, bool integer,
    //                          const std::string& name );
    Napi::Value MakeVar( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 4 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsBoolean() && info[ 3 ].IsString() )
        {
            double      lb       = info[ 0 ].As< Napi::Number >().DoubleValue();
            double      ub       = info[ 1 ].As< Napi::Number >().DoubleValue();
            bool        integer  = info[ 2 ].As< Napi::Boolean >().Value();
            std::string name     = info[ 3 ].As< Napi::String >().Utf8Value();
            auto        pVar     = pMPSolver->MakeVar( lb, ub, integer, name );
            auto        external = Napi::External< MPVariable >::New( env, pVar );
            return GMPVariable::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeVar : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     MPVariable* LookupVariableOrNull( const std::string& var_name ) const;
    Napi::Value LookupVariableOrNull( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string var_name = info[ 0 ].As< Napi::String >().Utf8Value();
            auto        pVar     = pMPSolver->LookupVariableOrNull( var_name );
            if ( pVar )
            {
                auto external = Napi::External< MPVariable >::New( env, pVar );
                return GMPVariable::constructor.New( { external } );
            }
            return env.Null();
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::LookupVariableOrNull : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     MPVariable* variable( int index ) const
    Napi::Value variable( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsNumber() )
        {
            int  index = info[ 0 ].As< Napi::Number >().Int32Value();
            auto pVar  = pMPSolver->variable( index );
            if ( pVar )
            {
                auto external = Napi::External< MPVariable >::New( env, pVar );
                return GMPVariable::constructor.New( { external } );
            }
            return env.Null();
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::variable : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     const std::vector< MPVariable* >& variables() const
    Napi::Value variables( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            auto variables = pMPSolver->variables();
            auto ret       = Napi::Array::New( env, variables.size() );
            for ( int i = 0; i < variables.size(); i++ )
            {
                auto external = Napi::External< MPVariable >::New( env, variables[ i ] );
                ret.Set( i, GMPVariable::constructor.New( { external } ) );
            }
            return ret;
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::variables : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     int NumVariables() const
    Napi::Value NumVariables( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            return Napi::Number::New( env, pMPSolver->NumVariables() );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::NumVariables : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     void Clear();
    Napi::Value Clear( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            pMPSolver->Clear();
            return env.Undefined();
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::Clear : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     virtual OptimizationProblemType ProblemType() const
    Napi::Value ProblemType( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            return Napi::Number::New( env, static_cast< int >( pMPSolver->ProblemType() ) );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::ProblemType : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     const std::string& Name() const
    Napi::Value Name( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            return Napi::String::New( env, pMPSolver->Name() );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::Name : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     bool IsMIP() const;
    Napi::Value IsMIP( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            return Napi::Boolean::New( env, pMPSolver->IsMIP() );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::IsMIP : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     static OptimizationProblemType ParseSolverTypeOrDie(
    //         const std::string& solver_id );
    static Napi::Value ParseSolverTypeOrDie( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string solver_id = info[ 0 ].As< Napi::String >().Utf8Value();
            auto        type      = MPSolver::ParseSolverTypeOrDie( solver_id );
            return Napi::Number::New( env, static_cast< int >( type ) );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::ParseSolverTypeOrDie : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     static bool ParseSolverType( absl::string_view        solver_id,
    //                                  OptimizationProblemType* type );
    static Napi::Value ParseSolverType( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string                       solver_id = info[ 0 ].As< Napi::String >().Utf8Value();
            MPSolver::OptimizationProblemType type;
            auto                              result = MPSolver::ParseSolverType( solver_id, &type );
            auto                              ret    = Napi::Object::New( env );
            ret.Set( "return", Napi::Boolean::New( env, result ) );
            ret.Set( "type", Napi::Number::New( env, static_cast< int >( type ) ) );
            return ret;
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::ParseSolverType : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     static bool SupportsProblemType( OptimizationProblemType problem_type );
    static Napi::Value SupportsProblemType( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsNumber() )
        {
            int problem_type = info[ 0 ].As< Napi::Number >().Int32Value();
            return Napi::Boolean::New( env, MPSolver::SupportsProblemType( static_cast< MPSolver::OptimizationProblemType >( problem_type ) ) );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::SupportsProblemType : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     static MPSolver* CreateSolver( const std::string& solver_id );
    static Napi::Value CreateSolver( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string solver_id = info[ 0 ].As< Napi::String >().Utf8Value();
            MPSolver*   pSolver   = MPSolver::CreateSolver( solver_id );
            auto        external  = Napi::External< MPSolver >::New( env, pSolver );
            return GMPSolver::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::CreateSolver : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };
};

};  // namespace operations_research
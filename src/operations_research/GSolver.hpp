#pragma once

#include "commonheader.hpp"
#include "ortools/constraint_solver/constraint_solver.h"
#include "GIntVar.hpp"
#include "GConstraint.hpp"

namespace operations_research
{
class GSolver : public Napi::ObjectWrap< GSolver >
{
    CommonProperties( Solver );

    Napi::Value MakeIntVar( const Napi::CallbackInfo& info );
    Napi::Value MakeAllDifferent( const Napi::CallbackInfo& info );
    Napi::Value AddConstraint( const Napi::CallbackInfo& info );
};
};  // namespace operations_research

inline operations_research::GSolver::GSolver( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< operations_research::GSolver >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< Solver > >();
        spSolver      = std::shared_ptr< Solver >( external.Data() );
        return;
    }

    //      explicit Solver(const std::string& name);
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string name = info[ 0 ].As< Napi::String >().Utf8Value();
        spSolver         = std::make_shared< Solver >( name );
        return;
    }

    ThrowJsError( operations_research::GSolver::GSolver : Invalid argument );
}

inline Napi::Object operations_research::GSolver::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "Solver",
        {
            InstanceMethod( "MakeIntVar", &GSolver::MakeIntVar ),
            InstanceMethod( "MakeAllDifferent", &GSolver::MakeAllDifferent ),
            InstanceMethod( "AddConstraint", &GSolver::AddConstraint ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "Solver" ), func );
    return exports;
}

inline Napi::Value operations_research::GSolver::AddConstraint( const Napi::CallbackInfo& info )
{
    //      void AddConstraint(Constraint* const c);
    if ( info.Length() == 1 && info[ 0 ].IsObject() && info[ 0 ].As< Napi::Object >().InstanceOf( GConstraint::constructor.Value() ) )
    {
        auto gc = GConstraint::Unwrap( info[ 0 ].As< Napi::Object >() );
        spSolver->AddConstraint( gc->spConstraint.get() );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GSolver::AddConstraint : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSolver::MakeAllDifferent( const Napi::CallbackInfo& info )
{
    //      Constraint* MakeAllDifferent(const std::vector<IntVar*>& vars);
    if ( info.Length() == 1 && info[ 0 ].IsArray() )
    {
        std::vector< IntVar* > vars;
        Napi::Array            arr = info[ 0 ].As< Napi::Array >();

        for ( int i = 0; i < arr.Length(); i++ )
        {
            if ( arr.Get( i ).As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
            {
                auto gi = GIntVar::Unwrap( arr.Get( i ).As< Napi::Object >() );
                vars.push_back( gi->spIntVar.get() );
                continue;
            }

            ThrowJsError( operations_research::GSolver::MakeAllDifferent : Invalid argument );
            return info.Env().Undefined();
        }

        auto external = Napi::External< Constraint >::New( info.Env(), spSolver->MakeAllDifferent( vars ) );
        return GConstraint::constructor.New( { external } );
    }

    //      Constraint* MakeAllDifferent(const std::vector<IntVar*>& vars,
    //                                   bool stronger_propagation);
    if ( info.Length() == 2 && info[ 0 ].IsArray() && info[ 1 ].IsBoolean() )
    {
        std::vector< IntVar* > vars;
        Napi::Array            arr = info[ 0 ].As< Napi::Array >();

        for ( int i = 0; i < arr.Length(); i++ )
        {
            if ( arr.Get( i ).As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
            {
                auto gi = GIntVar::Unwrap( arr.Get( i ).As< Napi::Object >() );
                vars.push_back( gi->spIntVar.get() );
                continue;
            }

            LOG( INFO ) << info[ i ].Type();

            ThrowJsError( operations_research::GSolver::MakeAllDifferent : Invalid argument );
            return info.Env().Undefined();
        }

        bool stronger_propagation = info[ 1 ].As< Napi::Boolean >().Value();
        auto external             = Napi::External< Constraint >::New( info.Env(), spSolver->MakeAllDifferent( vars, stronger_propagation ) );
        return GConstraint::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GSolver::MakeAllDifferent : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSolver::MakeIntVar( const Napi::CallbackInfo& info )
{
    //      /// MakeIntVar will create the best range based int var for the bounds given.
    //      IntVar* MakeIntVar(int64_t min, int64_t max, const std::string& name);
    if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
    {
        int64_t     min      = info[ 0 ].As< Napi::Number >().Int64Value();
        int64_t     max      = info[ 1 ].As< Napi::Number >().Int64Value();
        std::string name     = info[ 2 ].As< Napi::String >().Utf8Value();
        auto        external = Napi::External< IntVar >::New( info.Env(), spSolver->MakeIntVar( min, max, name ) );
        return GIntVar::constructor.New( { external } );
    }

    //      /// MakeIntVar will create a variable with the given sparse domain.
    //      IntVar* MakeIntVar(const std::vector<int64_t>& values,
    //                         const std::string& name);
    //      /// MakeIntVar will create a variable with the given sparse domain.
    //      IntVar* MakeIntVar(const std::vector<int>& values, const std::string& name);
    if ( info.Length() == 2 && info[ 0 ].IsArray() && info[ 1 ].IsString() )
    {
        std::vector< int64_t > values;
        std::string            name = info[ 1 ].As< Napi::String >().Utf8Value();
        Napi::Array            arr  = info[ 0 ].As< Napi::Array >();

        for ( int i = 0; i < arr.Length(); i++ )
        {
            values.push_back( arr.Get( i ).As< Napi::Number >().Int64Value() );
        }

        auto external = Napi::External< IntVar >::New( info.Env(), spSolver->MakeIntVar( values, name ) );
        return GIntVar::constructor.New( { external } );
    }

    //      /// MakeIntVar will create the best range based int var for the bounds given.
    //      IntVar* MakeIntVar(int64_t min, int64_t max);
    if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() )
    {
        int64_t min      = info[ 0 ].As< Napi::Number >().Int64Value();
        int64_t max      = info[ 1 ].As< Napi::Number >().Int64Value();
        auto    external = Napi::External< IntVar >::New( info.Env(), spSolver->MakeIntVar( min, max ) );
        return GIntVar::constructor.New( { external } );
    }

    //      /// MakeIntVar will create a variable with the given sparse domain.
    //      IntVar* MakeIntVar(const std::vector<int64_t>& values);
    //      /// MakeIntVar will create a variable with the given sparse domain.
    //      IntVar* MakeIntVar(const std::vector<int>& values);
    if ( info.Length() == 1 && info[ 0 ].IsArray() )
    {
        std::vector< int64_t > values;
        Napi::Array            arr = info[ 0 ].As< Napi::Array >();

        for ( int i = 0; i < arr.Length(); i++ )
        {
            values.push_back( arr.Get( i ).As< Napi::Number >().Int64Value() );
        }

        auto external = Napi::External< IntVar >::New( info.Env(), spSolver->MakeIntVar( values ) );
        return GIntVar::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GSolver::MakeIntVar : Invalid argument );
    return info.Env().Undefined();
}
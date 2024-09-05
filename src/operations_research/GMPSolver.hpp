#pragma once

#include <napi.h>
#include "../commonheader.hpp"
#include "ortools/linear_solver/linear_solver.h"
#include "GMPVariable.hpp"
#include "GMPConstraint.hpp"
#include "GLinearRange.hpp"

namespace operations_research
{
class GMPSolver : public Napi::ObjectWrap< GMPSolver >
{
public:
    static Napi::FunctionReference constructor;
    MPSolver*                      pMPSolver = nullptr;
    GMPSolver( const Napi::CallbackInfo& info );
    ~GMPSolver();
    static Napi::Object Init( Napi::Env env, Napi::Object exports );

    Napi::Value        MakeIntVar( const Napi::CallbackInfo& info );
    Napi::Value        Solve( const Napi::CallbackInfo& info );
    Napi::Value        MutableObjective( const Napi::CallbackInfo& info );
    Napi::Value        MakeRowConstraint( const Napi::CallbackInfo& info );
    Napi::Value        MakeBoolVar( const Napi::CallbackInfo& info );
    static Napi::Value CreateSolver( const Napi::CallbackInfo& info );
    Napi::Value        MakeNumVar( const Napi::CallbackInfo& info );
    Napi::Value        NumVariables( const Napi::CallbackInfo& info );
    Napi::Value        NumConstraints( const Napi::CallbackInfo& info );
};
};  // namespace operations_research

Napi::FunctionReference operations_research::GMPSolver::constructor;

inline operations_research::GMPSolver::GMPSolver( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMPSolver >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< MPSolver > >();
        pMPSolver     = dynamic_cast< MPSolver* >( external.Data() );
        if ( pMPSolver != nullptr ) return;
    }

    ThrowJsError( operations_research::GMPSolver::GMPSolver : Invalid argument );
}

inline operations_research::GMPSolver::~GMPSolver()
{
    delete pMPSolver;
}

inline Napi::Object operations_research::GMPSolver::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );

    Napi::Object ResultStatus = Napi::Object::New( env );
    ResultStatus.Set( Napi::String::New( env, "OPTIMAL" ), Napi::Number::New( env, static_cast< int >( MPSolver::OPTIMAL ) ) );
    ResultStatus.Set( Napi::String::New( env, "FEASIBLE" ), Napi::Number::New( env, static_cast< int >( MPSolver::FEASIBLE ) ) );
    ResultStatus.Set( Napi::String::New( env, "INFEASIBLE" ), Napi::Number::New( env, static_cast< int >( MPSolver::INFEASIBLE ) ) );
    ResultStatus.Set( Napi::String::New( env, "UNBOUNDED" ), Napi::Number::New( env, static_cast< int >( MPSolver::UNBOUNDED ) ) );
    ResultStatus.Set( Napi::String::New( env, "ABNORMAL" ), Napi::Number::New( env, static_cast< int >( MPSolver::ABNORMAL ) ) );
    ResultStatus.Set( Napi::String::New( env, "MODEL_INVALID" ), Napi::Number::New( env, static_cast< int >( MPSolver::MODEL_INVALID ) ) );
    ResultStatus.Set( Napi::String::New( env, "NOT_SOLVED" ), Napi::Number::New( env, static_cast< int >( MPSolver::NOT_SOLVED ) ) );

    Napi::Function func = DefineClass(
        env, "MPSolver",
        {
            InstanceMethod( "MakeIntVar", &GMPSolver::MakeIntVar ),
            InstanceMethod( "Solve", &GMPSolver::Solve ),
            InstanceMethod( "MutableObjective", &GMPSolver::MutableObjective ),
            InstanceMethod( "MakeRowConstraint", &GMPSolver::MakeRowConstraint ),
            InstanceMethod( "MakeBoolVar", &GMPSolver::MakeBoolVar ),
            StaticMethod( "CreateSolver", &GMPSolver::CreateSolver ),
            StaticValue( "ResultStatus", ResultStatus ),
            InstanceMethod( "MakeNumVar", &GMPSolver::MakeNumVar ),
            InstanceMethod( "NumVariables", &GMPSolver::NumVariables ),
            InstanceMethod( "NumConstraints", &GMPSolver::NumConstraints ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "MPSolver" ), func );
    return exports;
}

inline Napi::Value operations_research::GMPSolver::NumConstraints( const Napi::CallbackInfo& info )
{
    //     int NumConstraints() const
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), pMPSolver->NumConstraints() );
    }

    ThrowJsError( operations_research::GMPSolver::NumConstraints : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GMPSolver::NumVariables( const Napi::CallbackInfo& info )
{
    //     int NumVariables() const
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), pMPSolver->NumVariables() );
    }

    ThrowJsError( operations_research::GMPSolver::NumVariables : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GMPSolver::MakeNumVar( const Napi::CallbackInfo& info )
{
    //     MPVariable* MakeNumVar( double lb, double ub, const std::string& name );
    if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
    {
        double      lb   = info[ 0 ].As< Napi::Number >().DoubleValue();
        double      ub   = info[ 1 ].As< Napi::Number >().DoubleValue();
        std::string name = info[ 2 ].As< Napi::String >().Utf8Value();
        MPVariable* pVar = pMPSolver->MakeNumVar( lb, ub, name );
        if ( pVar != nullptr )
        {
            auto external = Napi::External< MPVariable >::New( info.Env(), pVar );
            return GMPVariable::constructor.New( { external } );
        }
    }

    ThrowJsError( operations_research::GMPSolver::MakeNumVar : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GMPSolver::MakeIntVar( const Napi::CallbackInfo& info )
{
    //     MPVariable* MakeIntVar( double lb, double ub, const std::string& name );
    if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
    {
        double      lb   = info[ 0 ].As< Napi::Number >().DoubleValue();
        double      ub   = info[ 1 ].As< Napi::Number >().DoubleValue();
        std::string name = info[ 2 ].As< Napi::String >().Utf8Value();
        MPVariable* pVar = pMPSolver->MakeIntVar( lb, ub, name );
        if ( pVar != nullptr )
        {
            auto external = Napi::External< MPVariable >::New( info.Env(), pVar );
            return GMPVariable::constructor.New( { external } );
        }

        ThrowJsError( operations_research::GMPSolver::MakeIntVar : Failed to create variable );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPSolver::MakeIntVar : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GMPSolver::Solve( const Napi::CallbackInfo& info )
{
    //     ResultStatus Solve();
    if ( info.Length() == 0 )
    {
        auto status = pMPSolver->Solve();
        return Napi::Number::New( info.Env(), status );
    }

    ThrowJsError( operations_research::GMPSolver::Solve : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GMPSolver::MutableObjective( const Napi::CallbackInfo& info )
{
    //     MPObjective* MutableObjective()
    if ( info.Length() == 0 )
    {
        MPObjective* pObjective = pMPSolver->MutableObjective();
        if ( pObjective != nullptr )
        {
            auto external = Napi::External< MPObjective >::New( info.Env(), pObjective );
            return GMPObjective::constructor.New( { external } );
        }
        ThrowJsError( operations_research::GMPSolver::MutableObjective : Failed to create objective );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPSolver::MutableObjective : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GMPSolver::MakeRowConstraint( const Napi::CallbackInfo& info )
{
    //     MPConstraint* MakeRowConstraint( double lb, double ub );
    if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() )
    {
        double        lb          = info[ 0 ].As< Napi::Number >().DoubleValue();
        double        ub          = info[ 1 ].As< Napi::Number >().DoubleValue();
        MPConstraint* pConstraint = pMPSolver->MakeRowConstraint( lb, ub );
        if ( pConstraint != nullptr )
        {
            auto external = Napi::External< MPConstraint >::New( info.Env(), pConstraint );
            return GMPConstraint::constructor.New( { external } );
        }
        ThrowJsError( operations_research::GMPSolver::MakeRowConstraint : Failed to create constraint );
        return info.Env().Undefined();
    }

    //     MPConstraint* MakeRowConstraint();
    if ( info.Length() == 0 )
    {
        MPConstraint* pConstraint = pMPSolver->MakeRowConstraint();
        if ( pConstraint != nullptr )
        {
            auto external = Napi::External< MPConstraint >::New( info.Env(), pConstraint );
            return GMPConstraint::constructor.New( { external } );
        }
        ThrowJsError( operations_research::GMPSolver::MakeRowConstraint : Failed to create constraint );
        return info.Env().Undefined();
    }

    //     MPConstraint* MakeRowConstraint( double lb, double ub,
    //                                      const std::string& name );
    if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
    {
        double        lb          = info[ 0 ].As< Napi::Number >().DoubleValue();
        double        ub          = info[ 1 ].As< Napi::Number >().DoubleValue();
        std::string   name        = info[ 2 ].As< Napi::String >().Utf8Value();
        MPConstraint* pConstraint = pMPSolver->MakeRowConstraint( lb, ub, name );
        if ( pConstraint != nullptr )
        {
            auto external = Napi::External< MPConstraint >::New( info.Env(), pConstraint );
            return GMPConstraint::constructor.New( { external } );
        }
        ThrowJsError( operations_research::GMPSolver::MakeRowConstraint : Failed to create constraint );
        return info.Env().Undefined();
    }

    //     MPConstraint* MakeRowConstraint( const std::string& name );
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string   name        = info[ 0 ].As< Napi::String >().Utf8Value();
        MPConstraint* pConstraint = pMPSolver->MakeRowConstraint( name );
        if ( pConstraint != nullptr )
        {
            auto external = Napi::External< MPConstraint >::New( info.Env(), pConstraint );
            return GMPConstraint::constructor.New( { external } );
        }
        ThrowJsError( operations_research::GMPSolver::MakeRowConstraint : Failed to create constraint );
        return info.Env().Undefined();
    }

    //     MPConstraint* MakeRowConstraint( const LinearRange& range );
    if ( info.Length() == 1 && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearRange::constructor.Value() ) )
    {
        auto          range       = GLinearRange::Unwrap( info[ 0 ].As< Napi::Object >() );
        MPConstraint* pConstraint = pMPSolver->MakeRowConstraint( *range->pLinearRange );
        if ( pConstraint != nullptr )
        {
            auto external = Napi::External< MPConstraint >::New( info.Env(), pConstraint );
            return GMPConstraint::constructor.New( { external } );
        }
        ThrowJsError( operations_research::GMPSolver::MakeRowConstraint : Failed to create constraint );
        return info.Env().Undefined();
    }

    //     MPConstraint* MakeRowConstraint( const LinearRange& range,
    //                                      const std::string& name );
    if ( info.Length() == 2 && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearRange::constructor.Value() ) && info[ 1 ].IsString() )
    {
        auto          range       = GLinearRange::Unwrap( info[ 0 ].As< Napi::Object >() );
        std::string   name        = info[ 1 ].As< Napi::String >().Utf8Value();
        MPConstraint* pConstraint = pMPSolver->MakeRowConstraint( *range->pLinearRange, name );
        if ( pConstraint != nullptr )
        {
            auto external = Napi::External< MPConstraint >::New( info.Env(), pConstraint );
            return GMPConstraint::constructor.New( { external } );
        }
        ThrowJsError( operations_research::GMPSolver::MakeRowConstraint : Failed to create constraint );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPSolver::MakeRowConstraint : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GMPSolver::MakeBoolVar( const Napi::CallbackInfo& info )
{
    //     MPVariable* MakeBoolVar( const std::string& name );
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string name = info[ 0 ].As< Napi::String >().Utf8Value();
        MPVariable* pVar = pMPSolver->MakeBoolVar( name );
        if ( pVar != nullptr )
        {
            auto external = Napi::External< MPVariable >::New( info.Env(), pVar );
            return GMPVariable::constructor.New( { external } );
        }

        ThrowJsError( operations_research::GMPSolver::MakeBoolVar : Failed to create variable );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPSolver::MakeBoolVar : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GMPSolver::CreateSolver( const Napi::CallbackInfo& info )
{
    //     static MPSolver* CreateSolver( const std::string& solver_id );
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string solver_id = info[ 0 ].As< Napi::String >().Utf8Value();
        MPSolver*   pMPSolver = MPSolver::CreateSolver( solver_id );
        if ( pMPSolver != nullptr )
        {
            auto external = Napi::External< MPSolver >::New( info.Env(), pMPSolver );
            return GMPSolver::constructor.New( { external } );
        }

        ThrowJsError( operations_research::GMPSolver::CreateSolver : Failed to create solver );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPSolver::CreateSolver : Invalid argument );
    return info.Env().Undefined();
}

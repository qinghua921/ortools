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

    Napi::Value        MakeRowConstraint( const Napi::CallbackInfo& info );
    Napi::Value        MakeBoolVar( const Napi::CallbackInfo& info );
    static Napi::Value CreateSolver( const Napi::CallbackInfo& info );
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
    Napi::Function    func = DefineClass(
        env, "MPSolver",
        {
            InstanceMethod( "MakeRowConstraint", &GMPSolver::MakeRowConstraint ),
            InstanceMethod( "MakeBoolVar", &GMPSolver::MakeBoolVar ),
            StaticMethod( "CreateSolver", &GMPSolver::CreateSolver ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "MPSolver" ), func );
    return exports;
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
    if ( info.Length() == 1 && info[ 0 ].IsObject() && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearRange::constructor.Value() ) )
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
    if ( info.Length() == 2 && info[ 0 ].IsObject() && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearRange::constructor.Value() ) && info[ 1 ].IsString() )
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

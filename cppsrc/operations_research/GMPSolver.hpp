#pragma once

#include <napi.h>
#include "GMPVariable.hpp"
#include "GMPConstraint.hpp"
#include "GMPObjective.hpp"
#include "GMPSolverWorker.hpp"
#include "../commonheader.hpp"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{

class GMPSolver : public Napi::ObjectWrap< GMPSolver >
{
public:
    static Napi::FunctionReference constructor;
    MPSolver*                      pMPSolver;

public:
    GMPSolver( const Napi::CallbackInfo& info );
    ~GMPSolver();

public:
    static Napi::Object Init( Napi::Env env, Napi::Object exports );
    static Napi::Value  CreateSolver( const Napi::CallbackInfo& info );
    Napi::Value         MutableObjective( const Napi::CallbackInfo& info );
    Napi::Value         MakeRowConstraint( const Napi::CallbackInfo& info );
    Napi::Value         Solve( const Napi::CallbackInfo& info );
    Napi::Value         Name( const Napi::CallbackInfo& info );
    Napi::Value         NumVariables( const Napi::CallbackInfo& info );
    Napi::Value         NumConstraints( const Napi::CallbackInfo& info );
    Napi::Value         wall_time( const Napi::CallbackInfo& info );
    Napi::Value         iterations( const Napi::CallbackInfo& info );
    Napi::Value         nodes( const Napi::CallbackInfo& info );
    Napi::Value         infinity( const Napi::CallbackInfo& info );
    Napi::Value         MakeNumVar( const Napi::CallbackInfo& info );
    Napi::Value         MakeIntVar( const Napi::CallbackInfo& info );
};

Napi::FunctionReference GMPSolver::constructor;

Napi::Object GMPSolver::Init( Napi::Env env, Napi::Object exports )
{
    Napi::Function func = DefineClass(
        env,
        "MPSolver",
        {
            StaticMethod( "CreateSolver", &GMPSolver::CreateSolver ),              //
            InstanceMethod( "infinity", &GMPSolver::infinity ),                    //
            InstanceMethod( "MakeNumVar", &GMPSolver::MakeNumVar ),                //
            InstanceMethod( "MakeIntVar", &GMPSolver::MakeIntVar ),                //
            InstanceMethod( "MutableObjective", &GMPSolver::MutableObjective ),    //
            InstanceMethod( "Solve", &GMPSolver::Solve ),                          //
            InstanceMethod( "Name", &GMPSolver::Name ),                            //
            InstanceMethod( "NumVariables", &GMPSolver::NumVariables ),            //
            InstanceMethod( "MakeRowConstraint", &GMPSolver::MakeRowConstraint ),  //
            InstanceMethod( "NumConstraints", &GMPSolver::NumConstraints ),        //
            InstanceMethod( "wall_time", &GMPSolver::wall_time ),                  //
            InstanceMethod( "iterations", &GMPSolver::iterations ),                //
            InstanceMethod( "nodes", &GMPSolver::nodes ),                          //
        } );

    constructor = Napi::Persistent( func );
    exports.Set( "MPSolver", func );
    return exports;
};

GMPSolver::GMPSolver( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMPSolver >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        auto solver_id  = info[ 0 ].As< Napi::String >();
        this->pMPSolver = MPSolver::CreateSolver( solver_id );
        if ( this->pMPSolver ) return;
    }

    ThrowJsError( GMPSolver::GMPSolver Error );
};

GMPSolver::~GMPSolver()
{
#ifdef DEBUG
    LOG( INFO ) << "GMPSolver::~GMPSolver";
#endif
    if ( this->pMPSolver )
    {
        delete this->pMPSolver;
        this->pMPSolver = nullptr;
    }
}

Napi::Value GMPSolver::CreateSolver( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        return constructor.New( { info[ 0 ].As< Napi::String >() } );
    }

    ThrowJsError( GMPSolver::CreateSolver Error );
    return info.Env().Undefined();
};

Napi::Value GMPSolver::MutableObjective( const Napi::CallbackInfo& info )
{
    auto objective     = this->pMPSolver->MutableObjective();
    auto asExternalVar = Napi::External< MPObjective >::New( info.Env(), objective );
    return GMPObjective::constructor.New( { asExternalVar } );
}

Napi::Value GMPSolver::MakeRowConstraint( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() )
    {
        auto lb            = info[ 0 ].As< Napi::Number >();
        auto ub            = info[ 1 ].As< Napi::Number >();
        auto constraint    = this->pMPSolver->MakeRowConstraint( lb, ub );
        auto asExternalVar = Napi::External< MPConstraint >::New( info.Env(), constraint );
        return GMPConstraint::constructor.New( { asExternalVar } );
    }

    ThrowJsError( GMPSolver::MakeRowConstraint Error );
    return info.Env().Undefined();
}

Napi::Value GMPSolver::Solve( const Napi::CallbackInfo& info )
{
    GMPSolverWorker* worker = new GMPSolverWorker( info.Env(), this->pMPSolver );
    worker->Queue();
    return worker->Promise();
}

Napi::Value GMPSolver::Name( const Napi::CallbackInfo& info )
{
    return Napi::String::New( info.Env(), this->pMPSolver->Name() );
}

Napi::Value GMPSolver::NumVariables( const Napi::CallbackInfo& info )
{
    return Napi::Number::New( info.Env(), this->pMPSolver->NumVariables() );
};

Napi::Value GMPSolver::NumConstraints( const Napi::CallbackInfo& info )
{
    return Napi::Number::New( info.Env(), this->pMPSolver->NumConstraints() );
};

Napi::Value GMPSolver::wall_time( const Napi::CallbackInfo& info )
{
    return Napi::Number::New( info.Env(), this->pMPSolver->wall_time() );
}

Napi::Value GMPSolver::iterations( const Napi::CallbackInfo& info )
{
    return Napi::Number::New( info.Env(), this->pMPSolver->iterations() );
}

Napi::Value GMPSolver::nodes( const Napi::CallbackInfo& info )
{
    return Napi::Number::New( info.Env(), this->pMPSolver->nodes() );
}

Napi::Value GMPSolver::infinity( const Napi::CallbackInfo& info )
{
    return Napi::Number::New( info.Env(), this->pMPSolver->infinity() );
}

Napi::Value GMPSolver::MakeNumVar( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
    {
        auto lb            = info[ 0 ].As< Napi::Number >().DoubleValue();
        auto ub            = info[ 1 ].As< Napi::Number >().DoubleValue();
        auto name          = info[ 2 ].As< Napi::String >();
        auto numVar        = this->pMPSolver->MakeNumVar( lb, ub, name );
        auto asExternalVar = Napi::External< MPVariable >::New( info.Env(), numVar );
        return GMPVariable::constructor.New( { asExternalVar } );
    }

    ThrowJsError( GMPSolver::MakeNumVar Error );
    return info.Env().Undefined();
}

Napi::Value GMPSolver::MakeIntVar( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
    {
        auto lb            = info[ 0 ].As< Napi::Number >().DoubleValue();
        auto ub            = info[ 1 ].As< Napi::Number >().DoubleValue();
        auto name          = info[ 2 ].As< Napi::String >();
        auto numVar        = this->pMPSolver->MakeIntVar( lb, ub, name );
        auto asExternalVar = Napi::External< MPVariable >::New( info.Env(), numVar );
        return GMPVariable::constructor.New( { asExternalVar } );
    }

    ThrowJsError( ParamterError );
    return info.Env().Undefined();
};

}  // namespace operations_research

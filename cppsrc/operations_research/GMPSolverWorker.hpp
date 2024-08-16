#pragma once

#include <napi.h>

#include "ortools/linear_solver/linear_solver.h"
namespace operations_research
{

class GMPSolverWorker : public Napi::AsyncWorker
{
public:
    Napi::Env               env;
    MPSolver*               pMPSolver;
    MPSolver::ResultStatus  status;
    Napi::Promise::Deferred deferred;

public:
    GMPSolverWorker( Napi::Env env, MPSolver* pMPSolver );
    ~GMPSolverWorker();

public:
    void          Execute() override;
    void          OnOK() override;
    void          OnError( const Napi::Error& e ) override;
    Napi::Promise Promise();
};

GMPSolverWorker::GMPSolverWorker( Napi::Env env, MPSolver* pMPSolver )
    : Napi::AsyncWorker( env ),
      env( env ),
      deferred( Napi::Promise::Deferred::New( env ) ),
      pMPSolver( pMPSolver ){};

GMPSolverWorker::~GMPSolverWorker()
{
#ifdef DEBUG
    LOG( INFO ) << "GMPSolverWorker::~GMPSolverWorker";
#endif
};

void GMPSolverWorker::Execute()
{
    this->status = this->pMPSolver->Solve();
};

void GMPSolverWorker::OnOK()
{
    this->deferred.Resolve( Napi::Number::New( this->env, this->status ) );
};

void GMPSolverWorker::OnError( const Napi::Error& e )
{
    this->deferred.Reject( e.Value() );
};

Napi::Promise GMPSolverWorker::Promise()
{
    return this->deferred.Promise();
}

};  // namespace operations_research
#pragma once

#include <napi.h>
#include <ortools/sat/cp_model.h>

namespace operations_research
{
namespace sat
{
    class FuncSolveWorker : public Napi::AsyncWorker
    {
    public:
        Napi::Env               env;
        Napi::Promise::Deferred deferred;
        GCpModelProto*          pGCpModelProto;
        CpSolverResponse        vCpSolverResponse;

    public:
        FuncSolveWorker( Napi::Env env, GCpModelProto* pGCpModelProto );
        ~FuncSolveWorker();

    public:
        void          Execute() override;
        void          OnOK() override;
        void          OnError( const Napi::Error& e ) override;
        Napi::Promise Promise();
    };

    FuncSolveWorker::FuncSolveWorker( Napi::Env env, GCpModelProto* pGCpModelProto )
        : Napi::AsyncWorker( env ),
          env( env ),
          deferred( Napi::Promise::Deferred::New( env ) ),
          pGCpModelProto( pGCpModelProto ){};

    FuncSolveWorker::~FuncSolveWorker()
    {
#ifdef KAIFA
        LOG( INFO ) << "FuncSolveWorker::~FuncSolveWorker";
#endif
    };

    void FuncSolveWorker::Execute()
    {
        this->vCpSolverResponse = Solve( *pGCpModelProto->pCpModelProto );
    };

    void FuncSolveWorker::OnOK()
    {
        auto vExternal = Napi::External< CpSolverResponse >::New( this->env, new CpSolverResponse( this->vCpSolverResponse ) );
        auto ret       = GCpSolverResponse::constructor.New( { vExternal, Napi::Boolean::New( env, true ) } );
        this->deferred.Resolve( ret );
    };

    void FuncSolveWorker::OnError( const Napi::Error& e )
    {
        this->deferred.Reject( e.Value() );
    };

    Napi::Promise FuncSolveWorker::Promise()
    {
        return this->deferred.Promise();
    }
}  // namespace sat
};  // namespace operations_research
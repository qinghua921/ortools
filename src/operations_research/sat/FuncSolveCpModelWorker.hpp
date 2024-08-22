#pragma once

#include <napi.h>
#include <ortools/sat/cp_model.h>

namespace operations_research
{
namespace sat
{
    class FuncSolveCpModelWorker : public Napi::AsyncWorker
    {
    public:
        Napi::Env               env;
        Napi::Promise::Deferred deferred;
        GCpModelProto*          pGCpModelProto;
        GModel*                 pGModel;
        CpSolverResponse        vCpSolverResponse;

    public:
        FuncSolveCpModelWorker( Napi::Env env, GCpModelProto* pGCpModelProto, GModel* pGModel );
        ~FuncSolveCpModelWorker();

    public:
        void          Execute() override;
        void          OnOK() override;
        void          OnError( const Napi::Error& e ) override;
        Napi::Promise Promise();
    };

    FuncSolveCpModelWorker::FuncSolveCpModelWorker( Napi::Env env, GCpModelProto* pGCpModelProto, GModel* pGModel )
        : Napi::AsyncWorker( env ),
          env( env ),
          deferred( Napi::Promise::Deferred::New( env ) ),
          pGCpModelProto( pGCpModelProto ),
          pGModel( pGModel ){};

    FuncSolveCpModelWorker::~FuncSolveCpModelWorker()
    {
#ifdef DEBUG
        LOG( INFO ) << "FuncSolveCpModelWorker::~FuncSolveCpModelWorker";
#endif
    };

    void FuncSolveCpModelWorker::Execute()
    {
        this->vCpSolverResponse = SolveCpModel( *pGCpModelProto->pCpModelProto, pGModel->pModel );
    };

    void FuncSolveCpModelWorker::OnOK()
    {
        auto vExternal = Napi::External< CpSolverResponse >::New( this->env, new CpSolverResponse( this->vCpSolverResponse ) );
        auto ret       = GCpSolverResponse::constructor.New( { vExternal, Napi::Boolean::New( env, true ) } );
        this->deferred.Resolve( ret );
    };

    void FuncSolveCpModelWorker::OnError( const Napi::Error& e )
    {
        this->deferred.Reject( e.Value() );
    };

    Napi::Promise FuncSolveCpModelWorker::Promise()
    {
        return this->deferred.Promise();
    }

}  // namespace sat
};  // namespace operations_research
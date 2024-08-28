#include "index.hpp"

operations_research::GMPSolver::GMPSolver( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< operations_research::GMPSolver >( info )
{
    //     MPSolver( const std::string& name, OptimizationProblemType problem_type );
    if ( info.Length() == 2 && info[ 0 ].IsString() && info[ 1 ].IsNumber() )
    {
        std::string name                     = info[ 0 ].As< Napi::String >();
        using OptimizationProblemType        = MPSolver::OptimizationProblemType;
        OptimizationProblemType problem_type = static_cast< OptimizationProblemType >( info[ 1 ].As< Napi::Number >().Int32Value() );
        pMPSolver                            = new MPSolver( name, problem_type );
        return;
    }

    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< MPSolver > >();
        pMPSolver     = dynamic_cast< MPSolver* >( external.Data() );
        if ( pMPSolver!= nullptr ) return;
    }

    ThrowJsError( GMPSolver::GMPSolver : Invalid arguments );
}

operations_research::GMPSolver::~GMPSolver()
{
    delete pMPSolver;
}

Napi::Value operations_research::GMPSolver::CreateSolver( const Napi::CallbackInfo& info )
{
    // static MPSolver* CreateSolver( const std::string& solver_id );
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string solver_id = info[ 0 ].As< Napi::String >();
        MPSolver*   pSolver   = MPSolver::CreateSolver( solver_id );
        auto        external  = Napi::External< MPSolver >::New( info.Env(), pSolver );
        return GMPSolver::constructor.New( { external } );
    }

    ThrowJsError( GMPSolver::CreateSolver : Invalid arguments );
    return info.Env().Undefined();
}

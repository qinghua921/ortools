#pragma once

#include "napi.h"
#include "../commonheader.hpp"
#include "ortools/linear_solver/linear_solver.h"

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
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "MPSolver" ), func );
    return exports;
}

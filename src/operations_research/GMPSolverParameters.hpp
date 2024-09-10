#pragma once


#include "commonheader.hpp"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{
class GMPSolverParameters : public Napi::ObjectWrap< GMPSolverParameters >
{
public:
    static Napi::FunctionReference constructor;
    MPSolverParameters*            pMPSolverParameters = nullptr;
    GMPSolverParameters( const Napi::CallbackInfo& info );
    ~GMPSolverParameters();
    static Napi::Object Init( Napi::Env env, Napi::Object exports );
};
};  // namespace operations_research

Napi::FunctionReference operations_research::GMPSolverParameters::constructor;

inline operations_research::GMPSolverParameters::GMPSolverParameters( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMPSolverParameters >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external       = info[ 0 ].As< Napi::External< MPSolverParameters > >();
        pMPSolverParameters = dynamic_cast< MPSolverParameters* >( external.Data() );
        if ( pMPSolverParameters != nullptr ) return;
    }

    ThrowJsError( operations_research::GMPSolverParameters::GMPSolverParameters : Invalid argument );
}

inline operations_research::GMPSolverParameters::~GMPSolverParameters()
{
    delete pMPSolverParameters;
}

inline Napi::Object operations_research::GMPSolverParameters::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "MPSolverParameters",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "MPSolverParameters" ), func );
    return exports;
}

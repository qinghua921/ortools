#pragma once

#include <napi.h>
#include "../commonheader.hpp"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{
class GMPConstraint : public Napi::ObjectWrap< GMPConstraint >
{
public:
    static Napi::FunctionReference constructor;
    MPConstraint*                  pMPConstraint = nullptr;
    GMPConstraint( const Napi::CallbackInfo& info );
    ~GMPConstraint();
    static Napi::Object Init( Napi::Env env, Napi::Object exports );
};
};  // namespace operations_research

Napi::FunctionReference operations_research::GMPConstraint::constructor;

inline operations_research::GMPConstraint::GMPConstraint( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMPConstraint >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< MPConstraint > >();
        pMPConstraint = dynamic_cast< MPConstraint* >( external.Data() );
        if ( pMPConstraint != nullptr ) return;
    }

    ThrowJsError( operations_research::GMPConstraint::GMPConstraint : Invalid argument );
}

inline operations_research::GMPConstraint::~GMPConstraint()
{
    delete pMPConstraint;
}

inline Napi::Object operations_research::GMPConstraint::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "MPConstraint",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "MPConstraint" ), func );
    return exports;
}

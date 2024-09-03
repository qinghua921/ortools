#pragma once

#include <napi.h>
#include "../../commonheader.hpp"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
    class GConstraint : public Napi::ObjectWrap< GConstraint >
    {
    public:
        static Napi::FunctionReference constructor;
        Constraint*                    pConstraint = nullptr;
        GConstraint( const Napi::CallbackInfo& info );
        ~GConstraint();
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
    };
};  // namespace sat
};  // namespace operations_research

Napi::FunctionReference operations_research::sat::GConstraint::constructor;

inline operations_research::sat::GConstraint::GConstraint( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GConstraint >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< Constraint > >();
        pConstraint   = dynamic_cast< Constraint* >( external.Data() );
        if ( pConstraint != nullptr ) return;
    }

    ThrowJsError( operations_research::GConstraint::GConstraint : Invalid argument );
}

inline operations_research::sat::GConstraint::~GConstraint()
{
    delete pConstraint;
}

inline Napi::Object operations_research::sat::GConstraint::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "Constraint",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "Constraint" ), func );
    return exports;
}

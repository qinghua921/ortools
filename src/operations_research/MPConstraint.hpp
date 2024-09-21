#pragma once

#include "napi.h"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{

class GMPConstraint : public Napi::ObjectWrap< GMPConstraint >
{
public:
    static inline Napi::FunctionReference constructor;
    MPConstraint*                         pMPConstraint = nullptr;

    GMPConstraint( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GMPConstraint >( info )
    {
        Napi::Env env = info.Env();

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external = info[ 0 ].As< Napi::External< MPConstraint > >();
            pMPConstraint = dynamic_cast< MPConstraint* >( external.Data() );
            if ( pMPConstraint ) return;
        }

        Napi::TypeError::New( env, "operations_research::GMPConstraint::GMPConstraint : Invalid arguments" ).ThrowAsJavaScriptException();
    };

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "MPConstraint",
            {} );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPConstraint" ), func );
        return exports;
    };
};

};  // namespace operations_research
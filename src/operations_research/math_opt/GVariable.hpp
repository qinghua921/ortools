#pragma once

#include <napi.h>
#include "../../commonheader.hpp"
#include "ortools/math_opt/cpp/math_opt.h"

namespace operations_research
{
namespace math_opt
{
    class GVariable : public Napi::ObjectWrap< GVariable >
    {
    public:
        static Napi::FunctionReference constructor;
        Variable*                      pVariable = nullptr;
        GVariable( const Napi::CallbackInfo& info );
        ~GVariable();
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
    };
};  // namespace math_opt
};  // namespace operations_research

Napi::FunctionReference operations_research::math_opt::GVariable::constructor;

inline operations_research::math_opt::GVariable::GVariable( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GVariable >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< Variable > >();
        pVariable     = dynamic_cast< Variable* >( external.Data() );
        if ( pVariable != nullptr ) return;
    }

    ThrowJsError( operations_research::GVariable::GVariable : Invalid argument );
}

inline operations_research::math_opt::GVariable::~GVariable()
{
    delete pVariable;
}

inline Napi::Object operations_research::math_opt::GVariable::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "Variable",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "Variable" ), func );
    return exports;
}

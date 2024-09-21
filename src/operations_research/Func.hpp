#pragma once

#include "napi.h"
namespace operations_research
{

static Napi::Object FuncInit( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );

    // exports.Set( "operator_less_equals", Napi::Function::New( env, operator_less_equals ) );
    // exports.Set( "operator_equals", Napi::Function::New( env, operator_equals ) );

    return exports;
};

};  // namespace operations_research
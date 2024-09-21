#pragma once

#include "napi.h"

namespace operations_research
{

static Napi::Object FuncInit( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );

    // exports.Set( "operator_le", Napi::Function::New( env, operator_le ) );

    return exports;
};

};  // namespace operations_research
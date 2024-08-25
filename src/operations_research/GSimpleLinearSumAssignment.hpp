#pragma once

#include <napi.h>
#include "ortools/graph/assignment.h"

namespace operations_research
{

class GSimpleLinearSumAssignment : public Napi::ObjectWrap< GSimpleLinearSumAssignment >
{
public:
    static Napi::FunctionReference constructor;
    SimpleLinearSumAssignment*     pSimpleLinearSumAssignment = nullptr;
    GSimpleLinearSumAssignment( const Napi::CallbackInfo& info );
    ~GSimpleLinearSumAssignment();
    static Napi::Object            Init( Napi::Env env, Napi::Object exports );
};
}  // namespace operations_research

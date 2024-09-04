#pragma once

#include <napi.h>
#include "../../commonheader.hpp"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
    static Napi::Object GEnumInit( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );

        // export enum CpSolverStatus
        auto cpSolverStatus = Napi::Object::New( env );
        cpSolverStatus.Set( "UNKNOWN", Napi::Number::New( env, CpSolverStatus::UNKNOWN ) );
        cpSolverStatus.Set( "MODEL_INVALID", Napi::Number::New( env, CpSolverStatus::MODEL_INVALID ) );
        cpSolverStatus.Set( "FEASIBLE", Napi::Number::New( env, CpSolverStatus::FEASIBLE ) );
        cpSolverStatus.Set( "INFEASIBLE", Napi::Number::New( env, CpSolverStatus::INFEASIBLE ) );
        cpSolverStatus.Set( "OPTIMAL", Napi::Number::New( env, CpSolverStatus::OPTIMAL ) );
        exports.Set( "CpSolverStatus", cpSolverStatus );

        return exports;
    };

}  // namespace sat
}  // namespace operations_research

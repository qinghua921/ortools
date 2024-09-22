#pragma once

#include "napi.h"

namespace operations_research
{
namespace sat
{
    static Napi::Object EnumInit( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );

        auto enumCpSolverStatus = Napi::Object::New( env );
        enumCpSolverStatus.Set( "UNKNOWN", static_cast< int >( CpSolverStatus::UNKNOWN ) );
        enumCpSolverStatus.Set( "MODEL_INVALID", static_cast< int >( CpSolverStatus::MODEL_INVALID ) );
        enumCpSolverStatus.Set( "FEASIBLE", static_cast< int >( CpSolverStatus::FEASIBLE ) );
        enumCpSolverStatus.Set( "INFEASIBLE", static_cast< int >( CpSolverStatus::INFEASIBLE ) );
        enumCpSolverStatus.Set( "OPTIMAL", static_cast< int >( CpSolverStatus::OPTIMAL ) );
        exports.Set( "CpSolverStatus", enumCpSolverStatus );

        return exports;
    };

}  // namespace sat

};  // namespace operations_research
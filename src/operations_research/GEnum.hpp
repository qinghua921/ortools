#pragma once

#include "napi.h"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{
static Napi::Object GEnumInit( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );

    auto enumMPSolverResponseStatus = Napi::Object::New( env );
    enumMPSolverResponseStatus.Set( "MPSOLVER_OPTIMAL", static_cast< int >( MPSolverResponseStatus::MPSOLVER_OPTIMAL ) );
    enumMPSolverResponseStatus.Set( "MPSOLVER_FEASIBLE", static_cast< int >( MPSolverResponseStatus::MPSOLVER_FEASIBLE ) );
    enumMPSolverResponseStatus.Set( "MPSOLVER_INFEASIBLE", static_cast< int >( MPSolverResponseStatus::MPSOLVER_INFEASIBLE ) );
    enumMPSolverResponseStatus.Set( "MPSOLVER_UNBOUNDED", static_cast< int >( MPSolverResponseStatus::MPSOLVER_UNBOUNDED ) );
    enumMPSolverResponseStatus.Set( "MPSOLVER_ABNORMAL", static_cast< int >( MPSolverResponseStatus::MPSOLVER_ABNORMAL ) );
    enumMPSolverResponseStatus.Set( "MPSOLVER_NOT_SOLVED", static_cast< int >( MPSolverResponseStatus::MPSOLVER_NOT_SOLVED ) );
    enumMPSolverResponseStatus.Set( "MPSOLVER_MODEL_IS_VALID", static_cast< int >( MPSolverResponseStatus::MPSOLVER_MODEL_IS_VALID ) );
    enumMPSolverResponseStatus.Set( "MPSOLVER_CANCELLED_BY_USER", static_cast< int >( MPSolverResponseStatus::MPSOLVER_CANCELLED_BY_USER ) );
    enumMPSolverResponseStatus.Set( "MPSOLVER_UNKNOWN_STATUS", static_cast< int >( MPSolverResponseStatus::MPSOLVER_UNKNOWN_STATUS ) );
    enumMPSolverResponseStatus.Set( "MPSOLVER_MODEL_INVALID", static_cast< int >( MPSolverResponseStatus::MPSOLVER_MODEL_INVALID ) );
    enumMPSolverResponseStatus.Set( "MPSOLVER_MODEL_INVALID_SOLUTION_HINT", static_cast< int >( MPSolverResponseStatus::MPSOLVER_MODEL_INVALID_SOLUTION_HINT ) );
    enumMPSolverResponseStatus.Set( "MPSOLVER_MODEL_INVALID_SOLVER_PARAMETERS", static_cast< int >( MPSolverResponseStatus::MPSOLVER_MODEL_INVALID_SOLVER_PARAMETERS ) );
    enumMPSolverResponseStatus.Set( "MPSOLVER_SOLVER_TYPE_UNAVAILABLE", static_cast< int >( MPSolverResponseStatus::MPSOLVER_SOLVER_TYPE_UNAVAILABLE ) );
    enumMPSolverResponseStatus.Set( "MPSOLVER_INCOMPATIBLE_OPTIONS", static_cast< int >( MPSolverResponseStatus::MPSOLVER_INCOMPATIBLE_OPTIONS ) );
    exports.Set( "MPSolverResponseStatus", enumMPSolverResponseStatus );

    return exports;
};
};  // namespace operations_research
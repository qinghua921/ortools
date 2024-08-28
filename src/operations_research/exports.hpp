#pragma once

#include "./sat/exports.hpp"
#include <napi.h>

#include "GFunc.hpp"
#include "GLinearExpr.hpp"
#include "GLinearRange.hpp"
#include "GMPConstraint.hpp"
#include "GMPObjective.hpp"
#include "GMPSolver.hpp"
#include "GMPSolverParameters.hpp"
#include "GMPVariable.hpp"
#include "GSimpleLinearSumAssignment.hpp"
#include "GSimpleMinCostFlow.hpp"

namespace operations_research
{
void Init( Napi::Env env, Napi::Object exports_ )
{
    auto exports = Napi::Object::New( env );

    GFuncInit( env, exports );
    GLinearExpr::Init( env, exports );
    GLinearRange::Init( env, exports );
    GMPConstraint::Init( env, exports );
    GMPObjective::Init( env, exports );
    GMPSolver::Init( env, exports );
    GMPSolverParameters::Init( env, exports );
    GMPVariable::Init( env, exports );
    GSimpleLinearSumAssignment::Init( env, exports );
    GSimpleMinCostFlow::Init( env, exports );

    sat::Init( env, exports );

    exports_.Set( "operations_research", exports );
}
}  // namespace operations_research

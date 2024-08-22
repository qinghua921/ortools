#pragma once

#include "./sat/exports.hpp"
#include <napi.h>
#include "GFunc.hpp"
#include "GLinearExpr.hpp"
#include "GLinearRange.hpp"
#include "GMPConstraint.hpp"
#include "GMPSolver.hpp"
#include "GMPVariable.hpp"

namespace operations_research
{
void Init( Napi::Env env, Napi::Object exports_ )
{
    auto exports = Napi::Object::New( env );

    FuncInit( env, exports );
    GLinearExpr::Init( env, exports );
    GLinearRange::Init( env, exports );
    GMPConstraint::Init( env, exports );
    GMPSolver::Init( env, exports );
    GMPVariable::Init( env, exports );

    sat::Init( env, exports );

    exports_.Set( "operations_research", exports );
}
}  // namespace operations_research

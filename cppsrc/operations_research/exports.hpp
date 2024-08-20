#include <napi.h>

#include "GDomain.hpp"
#include "sat/exports.hpp"
#include "GMPSolver.hpp"
#include "GMPVariable.hpp"
#include "GMPConstraint.hpp"
#include "GMPObjective.hpp"
#include "GClosedInterval.hpp"
#include "GOrToolsVersion.hpp"
#include "GLinearExpr.hpp"
#include "Func.hpp"
#include "GLinearRange.hpp"

namespace operations_research
{
void Init( Napi::Env env, Napi::Object exports_ )
{
    auto exports = Napi::Object::New( env );

    GOrToolsVersion::Init( env, exports );
    GDomain::Init( env, exports );
    GLinearExpr::Init( env, exports );
    GMPConstraint::Init( env, exports );
    GMPObjective::Init( env, exports );
    GLinearRange::Init( env, exports );
    GMPSolver::Init( env, exports );
    GMPVariable::Init( env, exports );
    GClosedInterval::Init( env, exports );

    FuncInit( env, exports );

    sat::Init( env, exports );

    exports_.Set( "operations_research", exports );
}
}  // namespace operations_research

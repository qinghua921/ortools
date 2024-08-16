#include <napi.h>

#include "GDomain.hpp"
#include "sat/exports.hpp"
#include "GMPSolver.hpp"
#include "GMPVariable.hpp"
#include "GMPConstraint.hpp"
#include "GMPObjective.hpp"
#include "GClosedInterval.hpp"

namespace operations_research
{
void Init( Napi::Env env, Napi::Object exports_ )
{
    auto exports = Napi::Object::New( env );
    sat::Init( env, exports );

    // GDomain::Init( env, exports );
    // GMPConstraint::Init( env, exports );
    // GMPObjective::Init( env, exports );
    // GMPSolver::Init( env, exports );
    // GMPVariable::Init( env, exports );
    // GClosedInterval::Init( env, exports );

    exports_.Set( "operations_research", exports );
}
}  // namespace operations_research

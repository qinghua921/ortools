#include <napi.h>
#include "absl/flags/flag.h"
#include "absl/log/flags.h"
#include "ortools/base/init_google.h"
#include "ortools/base/logging.h"
#include "ortools/init/init.h"

#include "operations_research/MPSolver.hpp"
#include "operations_research/MPVariable.hpp"
#include "operations_research/LinearExpr.hpp"
#include "operations_research/MPConstraint.hpp"
#include "operations_research/LinearRange.hpp"

Napi::Object Init( Napi::Env env, Napi::Object exports )
{
    google::InitGoogleLogging( "ortools_binding" );
    absl::SetFlag( &FLAGS_stderrthreshold, 3 );

    Napi::HandleScope scope( env );

    auto operations_research = Napi::Object::New( env );
    operations_research::GMPSolver::Init( env, operations_research );
    operations_research::GMPVariable::Init( env, operations_research );
    operations_research::GLinearExpr::Init( env, operations_research );
    operations_research::GMPConstraint::Init( env, operations_research );
    operations_research::GLinearRange::Init( env, operations_research );
    exports.Set( "operations_research", operations_research );

    return exports;
}

NODE_API_MODULE( ortools_binding, Init );

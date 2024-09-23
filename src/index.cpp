#include <napi.h>
#include "absl/flags/flag.h"
#include "absl/log/flags.h"
#include "ortools/base/init_google.h"
#include "ortools/base/logging.h"
#include "ortools/init/init.h"

/*** operations_research *************************************************************************/

#include "operations_research/Domain.hpp"
#include "operations_research/Func.hpp"
#include "operations_research/LinearExpr.hpp"
#include "operations_research/LinearRange.hpp"
#include "operations_research/MPConstraint.hpp"
#include "operations_research/MPObjective.hpp"
#include "operations_research/MPSolver.hpp"
#include "operations_research/MPVariable.hpp"
#include "operations_research/OrToolsVersion.hpp"
#include "operations_research/SimpleLinearSumAssignment.hpp"
#include "operations_research/SimpleMinCostFlow.hpp"

/*** operations_research::packing *************************************************************************/

#include "operations_research/packing/BinPacking2dParser.hpp"
#include "operations_research/packing/MultipleDimensionsBinPackingProblem.hpp"

/*** operations_research::sat *************************************************************************/

#include "operations_research/sat/BoolVar.hpp"
#include "operations_research/sat/Constraint.hpp"
#include "operations_research/sat/CpModelBuilder.hpp"
#include "operations_research/sat/CpModelProto.hpp"
#include "operations_research/sat/CpSolverResponse.hpp"
#include "operations_research/sat/Enum.hpp"
#include "operations_research/sat/Func.hpp"
#include "operations_research/sat/IntervalVar.hpp"
#include "operations_research/sat/IntVar.hpp"
#include "operations_research/sat/LinearExpr.hpp"
#include "operations_research/sat/NoOverlap2DConstraint.hpp"
#include "operations_research/sat/SatParameters.hpp"
#include "operations_research/sat/TableConstraint.hpp"

Napi::Object Init( Napi::Env env, Napi::Object exports )
{
    google::InitGoogleLogging( "ortools_binding" );
    absl::SetFlag( &FLAGS_stderrthreshold, 0 );

    Napi::HandleScope scope( env );

    auto operations_research = Napi::Object::New( env );
    {
        auto packing = Napi::Object::New( env );
        operations_research::packing::GBinPacking2dParser::Init( env, packing );
        operations_research::packing::GMultipleDimensionsBinPackingProblem::Init( env, packing );
        operations_research.Set( "packing", packing );
    }
    {
        auto sat = Napi::Object::New( env );
        operations_research::sat::GBoolVar::Init( env, sat );
        operations_research::sat::GCpModelBuilder::Init( env, sat );
        operations_research::sat::GCpModelProto::Init( env, sat );
        operations_research::sat::GConstraint::Init( env, sat );
        operations_research::sat::GCpSolverResponse::Init( env, sat );
        operations_research::sat::EnumInit( env, sat );
        operations_research::sat::FuncInit( env, sat );
        operations_research::sat::GIntervalVar::Init( env, sat );
        operations_research::sat::GIntVar::Init( env, sat );
        operations_research::sat::GLinearExpr::Init( env, sat );
        operations_research::sat::GNoOverlap2DConstraint::Init( env, sat );
        operations_research::sat::GSatParameters::Init( env, sat );
        operations_research::sat::GTableConstraint::Init( env, sat );
        operations_research.Set( "sat", sat );
    }
    operations_research::GDomain::Init( env, operations_research );
    operations_research::FuncInit( env, operations_research );
    operations_research::GLinearExpr::Init( env, operations_research );
    operations_research::GLinearRange::Init( env, operations_research );
    operations_research::GMPConstraint::Init( env, operations_research );
    operations_research::GMPObjective::Init( env, operations_research );
    operations_research::GMPSolver::Init( env, operations_research );
    operations_research::GMPVariable::Init( env, operations_research );
    operations_research::GOrToolsVersion::Init( env, operations_research );
    operations_research::GSimpleLinearSumAssignment::Init( env, operations_research );
    operations_research::GSimpleMinCostFlow::Init( env, operations_research );
    exports.Set( "operations_research", operations_research );

    return exports;
}

NODE_API_MODULE( ortools_binding, Init );

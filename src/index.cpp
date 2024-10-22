#include <absl/flags/flag.h>
#include <absl/log/flags.h>
#include <napi.h>
#include <ortools/base/init_google.h>
#include <ortools/base/logging.h>
#include <ortools/init/init.h>

#include "or.hpp"
#include "or_sat.hpp"

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    google::InitGoogleLogging("ortools_binding");
    absl::SetFlag(&FLAGS_stderrthreshold, 0);

    Napi::HandleScope scope(env);

    auto operations_research = Napi::Object::New(env);
    // {
    //     auto packing = Napi::Object::New( env );
    //     operations_research::packing::GBinPacking2dParser::Init( env, packing );
    //     operations_research::packing::GMultipleDimensionsBinPackingItem::Init( env, packing );
    //     operations_research::packing::GMultipleDimensionsBinPackingProblem::Init( env, packing );
    //     operations_research::packing::GMultipleDimensionsBinPackingShape::Init( env, packing );
    //     operations_research.Set( "packing", packing );
    // }
    // {
    //     auto sat = Napi::Object::New( env );
    //     operations_research::sat::GBoolVar::Init( env, sat );
    //     operations_research::sat::GCpModelBuilder::Init( env, sat );
    //     operations_research::sat::GCpModelProto::Init( env, sat );
    //     operations_research::sat::GConstraint::Init( env, sat );
    //     operations_research::sat::GCpSolverResponse::Init( env, sat );
    //     operations_research::sat::EnumInit( env, sat );
    //     operations_research::sat::FuncInit( env, sat );
    //     operations_research::sat::GIntervalVar::Init( env, sat );
    //     operations_research::sat::GIntVar::Init( env, sat );
    //     operations_research::sat::GLinearExpr::Init( env, sat );
    //     operations_research::sat::GNoOverlap2DConstraint::Init( env, sat );
    //     operations_research::sat::GSatParameters::Init( env, sat );
    //     operations_research::sat::GTableConstraint::Init( env, sat );
    //     operations_research.Set( "sat", sat );
    // }
    operations_research::GMPSolver::Init(env, operations_research);
    operations_research::GMPVariable::Init(env, operations_research);
    operations_research::GMPCallback::Init(env, operations_research);
    operations_research::GMPModelRequest::Init(env, operations_research);
    operations_research::GMPSolutionResponse::Init(env, operations_research);
    operations_research::GLinearRange::Init(env, operations_research);
    operations_research::GMPConstraint::Init(env, operations_research);
    operations_research::GMPObjective::Init(env, operations_research);
    operations_research::GMPSolverParameters::Init(env, operations_research);
    operations_research::GMPCallbackContext::Init(env, operations_research);
    operations_research::GLinearExpr::Init(env, operations_research);
    operations_research::FuncInit(env, operations_research);
    exports.Set("operations_research", operations_research);

    return exports;
}

NODE_API_MODULE(ortools_binding, Init);

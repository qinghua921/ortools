#include <napi.h>

/***********************************************************************************
 * ./operations_research
 ***********************************************************************************/

#include "./operations_research/GEnum.hpp"
#include "./operations_research/GFunc.hpp"
#include "./operations_research/GLinearExpr.hpp"
#include "./operations_research/GLinearRange.hpp"
#include "./operations_research/GMPCallback.hpp"
#include "./operations_research/GMPConstraint.hpp"
#include "./operations_research/GMPModelProto.hpp"
#include "./operations_research/GMPModelRequest.hpp"
#include "./operations_research/GMPObjective.hpp"
#include "./operations_research/GMPSolutionResponse.hpp"
#include "./operations_research/GMPSolver.hpp"
#include "./operations_research/GMPSolverParameters.hpp"
#include "./operations_research/GMPVariable.hpp"
#include "./operations_research/GSimpleLinearSumAssignment.hpp"
#include "./operations_research/GSimpleMinCostFlow.hpp"
#include "./operations_research/GDomain.hpp"

/***********************************************************************************
 * ./operations_research/sat
 ***********************************************************************************/

#include "./operations_research/sat/GCpModelBuilder.hpp"
#include "./operations_research/sat/GBoolVar.hpp"
#include "./operations_research/sat/GConstraint.hpp"
#include "./operations_research/sat/GIntVar.hpp"
#include "./operations_research/sat/GLinearExpr.hpp"
#include "./operations_research/sat/GTableConstraint.hpp"
#include "./operations_research/sat/GFunc.hpp"
#include "./operations_research/sat/GEnum.hpp"
#include "./operations_research/sat/GCpModelProto.hpp"
#include "./operations_research/sat/GCpSolverResponse.hpp"
#include "./operations_research/sat/GIntervalVar.hpp"
#include "./operations_research/sat/GNoOverlap2DConstraint.hpp"
#include "./operations_research/sat/GSatParameters.hpp"

/***********************************************************************************
 * ./operations_research/math_opt
 ***********************************************************************************/
// TODO  math_opt
// #include "./operations_research/math_opt/GModel.hpp"
// #include "./operations_research/math_opt/GLinearConstraint.hpp"
// #include "./operations_research/math_opt/GVariable.hpp"

/***********************************************************************************
 * ./operations_research/packing
 ***********************************************************************************/

#include "./operations_research/packing/GBinPacking2dParser.hpp"
#include "./operations_research/packing/GMultipleDimensionsBinPackingProblem.hpp"
#include "./operations_research/packing/GMultipleDimensionsBinPackingShape.hpp"
#include "./operations_research/packing/GMultipleDimensionsBinPackingItem.hpp"

/***********************************************************************************
 * ./google/protobuf
 ***********************************************************************************/

#include "./google/protobuf/GRepeatedField.hpp"
#include "./google/protobuf/GRepeatedPtrField.hpp"

Napi::Object Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );

    // ./operations_research

    auto operations_research_exports = Napi::Object::New( env );

    operations_research::GFuncInit( env, operations_research_exports );
    operations_research::GLinearExpr::Init( env, operations_research_exports );
    operations_research::GLinearRange::Init( env, operations_research_exports );
    operations_research::GMPCallback::Init( env, operations_research_exports );
    operations_research::GMPConstraint::Init( env, operations_research_exports );
    operations_research::GMPModelProto::Init( env, operations_research_exports );
    operations_research::GMPModelRequest::Init( env, operations_research_exports );
    operations_research::GMPObjective::Init( env, operations_research_exports );
    operations_research::GMPSolutionResponse::Init( env, operations_research_exports );
    operations_research::GMPSolver::Init( env, operations_research_exports );
    operations_research::GMPSolverParameters::Init( env, operations_research_exports );
    operations_research::GMPVariable::Init( env, operations_research_exports );
    operations_research::GSimpleLinearSumAssignment::Init( env, operations_research_exports );
    operations_research::GSimpleMinCostFlow::Init( env, operations_research_exports );
    operations_research::GDomain::Init( env, operations_research_exports );

    // ./operations_research/sat

    auto operations_research_sat_exports = Napi::Object::New( env );

    operations_research::sat::GEnumInit( env, operations_research_sat_exports );
    operations_research::sat::GFuncInit( env, operations_research_sat_exports );
    operations_research::sat::GCpModelBuilder::Init( env, operations_research_sat_exports );
    operations_research::sat::GBoolVar::Init( env, operations_research_sat_exports );
    operations_research::sat::GConstraint::Init( env, operations_research_sat_exports );
    operations_research::sat::GIntVar::Init( env, operations_research_sat_exports );
    operations_research::sat::GLinearExpr::Init( env, operations_research_sat_exports );
    operations_research::sat::GTableConstraint::Init( env, operations_research_sat_exports );
    operations_research::sat::GCpModelProto::Init( env, operations_research_sat_exports );
    operations_research::sat::GCpSolverResponse::Init( env, operations_research_sat_exports );
    operations_research::sat::GIntervalVar::Init( env, operations_research_sat_exports );
    operations_research::sat::GNoOverlap2DConstraint::Init( env, operations_research_sat_exports );
    operations_research::sat::GSatParameters::Init( env, operations_research_sat_exports );

    operations_research_exports.Set( "sat", operations_research_sat_exports );

    // ./operations_research/math_opt

    auto operations_research_math_opt_exports = Napi::Object::New( env );
    // TODO  math_opt
    // operations_research::math_opt::GModel::Init( env, operations_research_math_opt_exports );
    // operations_research::math_opt::GLinearConstraint::Init( env, operations_research_math_opt_exports );
    // operations_research::math_opt::GVariable::Init( env, operations_research_math_opt_exports );

    operations_research_exports.Set( "math_opt", operations_research_math_opt_exports );

    // ./operations_research/packing

    auto operations_research_packing_exports = Napi::Object::New( env );

    operations_research::packing::GBinPacking2dParser::Init( env, operations_research_packing_exports );
    operations_research::packing::GMultipleDimensionsBinPackingProblem::Init( env, operations_research_packing_exports );
    operations_research::packing::GMultipleDimensionsBinPackingShape::Init( env, operations_research_packing_exports );
    operations_research::packing::GMultipleDimensionsBinPackingItem::Init( env, operations_research_packing_exports );

    operations_research_exports.Set( "packing", operations_research_packing_exports );

    exports.Set( "operations_research", operations_research_exports );

    // ./google

    auto google_exports = Napi::Object::New( env );

    // ./google/protobuf

    auto google_protobuf_exports = Napi::Object::New( env );

    google_exports.Set( "protobuf", google_protobuf_exports );

    google::protobuf::GRepeatedField< int64_t >::Init( env, google_protobuf_exports );
    google::protobuf::GRepeatedPtrField< operations_research::packing::GMultipleDimensionsBinPackingItem >::Init( env, google_protobuf_exports );

    exports.Set( "google", google_exports );

    return exports;
}

NODE_API_MODULE( ortools_binding, Init );

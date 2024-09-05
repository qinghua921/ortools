#include <napi.h>

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

// #include "./operations_research/math_opt/GModel.hpp"

Napi::Object Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );

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

    operations_research_exports.Set( "sat", operations_research_sat_exports );

    auto operations_research_math_opt_exports = Napi::Object::New( env );
    // operations_research::math_opt::GModel::Init( env, operations_research_math_opt_exports );

    operations_research_exports.Set( "math_opt", operations_research_math_opt_exports );

    exports.Set( "operations_research", operations_research_exports );

    return exports;
}

NODE_API_MODULE( ortools_binding, Init );

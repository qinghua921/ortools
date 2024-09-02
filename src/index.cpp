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

    auto operations_research_sat_exports = Napi::Object::New( env );
    operations_research_exports.Set( "sat", operations_research_sat_exports );

    exports.Set( "operations_research", operations_research_exports );

    return exports;
}

NODE_API_MODULE( ortools_binding, Init );

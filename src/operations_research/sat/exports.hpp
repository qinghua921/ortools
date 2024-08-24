#include <napi.h>

#include "GBoolVar.hpp"
#include "GConstraint.hpp"
#include "GCpModelBuilder.hpp"
#include "GCpModelProto.hpp"
#include "GCpSolverResponse.hpp"
#include "GDoubleLinearExpr.hpp"
#include "GFunc.hpp"
#include "GIntVar.hpp"
#include "GLinearExpr.hpp"
#include "GTableConstraint.hpp"

namespace operations_research
{
namespace sat
{
    void Init( Napi::Env env, Napi::Object exports )
    {
        auto satExports = Napi::Object::New( env );

        GBoolVar::Init( env, satExports );
        GConstraint::Init( env, satExports );
        GCpModelBuilder::Init( env, satExports );
        GCpModelProto::Init( env, satExports );
        GCpSolverResponse::Init( env, satExports );
        GDoubleLinearExpr::Init( env, satExports );
        GFuncInit( env, satExports );
        GIntVar::Init( env, satExports );
        GLinearExpr::Init( env, satExports );
        GTableConstraint::Init( env, satExports );

        exports.Set( "sat", satExports );
    }
}  // namespace sat
}  // namespace operations_research

#include <napi.h>

// #include "GCpModelBuilder.hpp"
// #include "GConstraint.hpp"
// #include "GIntVar.hpp"
// #include "GLinearExpr.hpp"
// #include "GCpModelProto.hpp"
// #include "GCpSolverResponse.hpp"
// #include "Func.hpp"
// #include "GIntervalVar.hpp"
// #include "GBoolVar.hpp"
// #include "GModel.hpp"
// #include "GSatParameters.hpp"

namespace operations_research
{
namespace sat
{
    void Init( Napi::Env env, Napi::Object exports )
    {
        auto satExports = Napi::Object::New( env );

        // GCpModelBuilder::Init( env, satExports );
        // GConstraint::Init( env, satExports );
        // GIntVar::Init( env, satExports );
        // GLinearExpr::Init( env, satExports );
        // GCpModelProto::Init( env, satExports );
        // GCpSolverResponse::Init( env, satExports );
        // GIntervalVar::Init( env, satExports );
        // GBoolVar::Init( env, satExports );
        // GModel::Init( env, satExports );
        // GSatParameters::Init( env, satExports );

        // FuncInit( env, satExports );

        exports.Set( "sat", satExports );
    }

}  // namespace sat
}  // namespace operations_research

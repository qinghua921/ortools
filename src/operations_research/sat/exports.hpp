#include <napi.h>

#include "GCpModelBuilder.hpp"
#include "GBoolVar.hpp"
#include "GIntVar.hpp"
#include "GConstraint.hpp"
#include "GLinearExpr.hpp"
#include "GTableConstraint.hpp"
#include "GFunc.hpp"

namespace operations_research
{
namespace sat
{
    void Init( Napi::Env env, Napi::Object exports )
    {
        auto satExports = Napi::Object::New( env );

        GCpModelBuilder::Init( env, satExports );
        GBoolVar::Init( env, satExports );
        GIntVar::Init( env, satExports );
        GConstraint::Init( env, satExports );
        GLinearExpr::Init( env, satExports );
        GTableConstraint::Init( env, satExports );

        FuncInit( env, satExports );

        exports.Set( "sat", satExports );
    }
}  // namespace sat
}  // namespace operations_research

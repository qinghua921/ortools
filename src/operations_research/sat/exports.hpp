#include <napi.h>

namespace operations_research
{
namespace sat
{
    void Init( Napi::Env env, Napi::Object exports )
    {
        auto satExports = Napi::Object::New( env );

        // GCpModelBuilder::Init( env, satExports );

        exports.Set( "sat", satExports );
    }
}  // namespace sat
}  // namespace operations_research

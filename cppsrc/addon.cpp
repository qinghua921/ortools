#include <napi.h>

#include "ortools/base/init_google.h"
#include "operations_research/exports.hpp"


Napi::Object Init( Napi::Env env, Napi::Object exports )
{
    // FIXME 确认使用
    google::InitGoogleLogging( "OrtoolsBinding" );
    absl::SetFlag( &FLAGS_stderrthreshold, 0 );

    operations_research::Init( env, exports );

    return exports;
}

NODE_API_MODULE( ortools_binding, Init );
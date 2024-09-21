﻿#include <napi.h>
#include "absl/flags/flag.h"
#include "absl/log/flags.h"
#include "ortools/base/init_google.h"
#include "ortools/base/logging.h"
#include "ortools/init/init.h"

Napi::Object Init( Napi::Env env, Napi::Object exports )
{
    google::InitGoogleLogging( "ortools_binding" );
    absl::SetFlag( &FLAGS_stderrthreshold, 3 );

    Napi::HandleScope scope( env );

    auto operations_research = Napi::Object::New( env );
    exports.Set( "operations_research", operations_research );

    return exports;
}

NODE_API_MODULE( ortools_binding, Init );

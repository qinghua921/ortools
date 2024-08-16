#pragma once

// ThrowAsJavaScriptException
#define PaoJsError( xinxi ) \
    Napi::Error::New( info.Env(), ( char* )u8#xinxi ).ThrowAsJavaScriptException()

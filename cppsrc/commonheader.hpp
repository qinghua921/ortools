#pragma once

// ThrowAsJavaScriptException
#define ThrowJsError( xinxi ) \
    Napi::Error::New( info.Env(), ( char* )u8#xinxi ).ThrowAsJavaScriptException()

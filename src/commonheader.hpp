#pragma once

#include <napi.h>

// ThrowAsJavaScriptException
#define ThrowJsError( errinfo ) \
    Napi::Error::New( info.Env(), ( char* )u8#errinfo ).ThrowAsJavaScriptException()

#define CommonProperties( OrToolsClassName )                    \
public:                                                         \
    static inline Napi::FunctionReference constructor;          \
    std::shared_ptr< OrToolsClassName >   sp##OrToolsClassName; \
    G##OrToolsClassName( const Napi::CallbackInfo& info );      \
    static Napi::Object Init( Napi::Env env, Napi::Object exports );

class Demo
{
};
#pragma once

#include <napi.h>

// ThrowAsJavaScriptException
#define ThrowJsError( errinfo ) \
    Napi::Error::New( info.Env(), ( char* )u8#errinfo ).ThrowAsJavaScriptException()

class Demo
{
};

#define WrapOrToolsMethod( METHOD_NAME ) \
    Napi::Value METHOD_NAME( const Napi::CallbackInfo& info );

#define WrapOrToolsClass( CLASS_NAME, ... )                                             \
    class G##CLASS_NAME : public Napi::ObjectWrap< G##CLASS_NAME >                      \
    {                                                                                   \
    public:                                                                             \
        static inline Napi::FunctionReference constructor;                              \
        std::shared_ptr< CLASS_NAME >         shared_ptr;                               \
        G##CLASS_NAME( const Napi::CallbackInfo& info );                                \
        static void        Init( Napi::Env env, Napi::Object exports );                 \
        static Napi::Value FromExternal( CLASS_NAME* ptr )                              \
        {                                                                               \
            Napi::Env         env = constructor.Env();                                  \
            Napi::HandleScope scope( env );                                             \
            auto              external = Napi::External< CLASS_NAME >::New( env, ptr ); \
            return G##CLASS_NAME::constructor.New( { external } );                      \
        };                                                                              \
        /* Define methods */                                                            \
        __VA_ARGS__                                                                     \
    };

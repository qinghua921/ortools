#pragma once


#include "commonheader.hpp"

namespace operations_research
{
namespace math_opt
{
    class GDemo : public Napi::ObjectWrap< GDemo >
    {
    public:
        static Napi::FunctionReference constructor;
        Demo*                          pDemo = nullptr;
        GDemo( const Napi::CallbackInfo& info );
        ~GDemo();
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
    };
};  // namespace math_opt
};  // namespace operations_research

Napi::FunctionReference operations_research::math_opt::GDemo::constructor;

inline operations_research::math_opt::GDemo::GDemo( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GDemo >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< Demo > >();
        pDemo         = dynamic_cast< Demo* >( external.Data() );
        if ( pDemo != nullptr ) return;
    }

    ThrowJsError( operations_research::GDemo::GDemo : Invalid argument );
}

inline operations_research::math_opt::GDemo::~GDemo()
{
    delete pDemo;
}

inline Napi::Object operations_research::math_opt::GDemo::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "Demo",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "Demo" ), func );
    return exports;
}

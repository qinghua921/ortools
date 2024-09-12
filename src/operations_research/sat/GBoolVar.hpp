#pragma once

#include "commonheader.hpp"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
    class GBoolVar : public Napi::ObjectWrap< GBoolVar >
    {
    public:
        CommonProperties( BoolVar );

        Napi::Value WithName( const Napi::CallbackInfo& info );
    };
};  // namespace sat
};  // namespace operations_research

inline operations_research::sat::GBoolVar::GBoolVar( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GBoolVar >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< BoolVar > >();
        spBoolVar     = std::shared_ptr< BoolVar >( external.Data() );
        return;
    }

    ThrowJsError( operations_research::GBoolVar::GBoolVar : Invalid argument );
}

inline Napi::Object operations_research::sat::GBoolVar::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "BoolVar",
        {
            InstanceMethod( "WithName", &GBoolVar::WithName ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "BoolVar" ), func );
    return exports;
}

inline Napi::Value operations_research::sat::GBoolVar::WithName( const Napi::CallbackInfo& info )
{
    //     BoolVar WithName( const std::string& name );
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string name     = info[ 0 ].As< Napi::String >().Utf8Value();
        auto        newVar   = spBoolVar->WithName( name );
        auto        external = Napi::External< BoolVar >::New( info.Env(), new BoolVar( newVar ) );
        return GBoolVar::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GBoolVar::WithName : Invalid argument );
    return info.Env().Undefined();
}

#pragma once

#include "commonheader.hpp"
#include "ortools/sat/cp_model.h"
#include "GBoolVar.hpp"

namespace operations_research
{
namespace sat
{
    class GIntVar : public Napi::ObjectWrap< GIntVar >
    {
    public:
        CommonProperties( IntVar );

        Napi::Value WithName( const Napi::CallbackInfo& info );
        Napi::Value index( const Napi::CallbackInfo& info );
    };
};  // namespace sat
};  // namespace operations_research

inline operations_research::sat::GIntVar::GIntVar( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GIntVar >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< IntVar > >();
        spIntVar      = std::shared_ptr< IntVar >( external.Data() );
        return;
    }

    //     IntVar() = default;
    if ( info.Length() == 0 )
    {
        spIntVar = std::make_shared< IntVar >();
        return;
    }

    //     explicit IntVar( const BoolVar& var );
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        auto gboolvar = GBoolVar::Unwrap( info[ 0 ].As< Napi::Object >() );
        spIntVar      = std::make_shared< IntVar >( *gboolvar->spBoolVar );
        return;
    }

    ThrowJsError( operations_research::GIntVar::GIntVar : Invalid argument );
}

inline Napi::Object operations_research::sat::GIntVar::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "IntVar",
        {
            InstanceMethod( "WithName", &GIntVar::WithName ),
            InstanceMethod( "index", &GIntVar::index ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "IntVar" ), func );
    return exports;
}

inline Napi::Value operations_research::sat::GIntVar::index( const Napi::CallbackInfo& info )
{
    //     int index() const
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), spIntVar->index() );
    }

    ThrowJsError( operations_research::GIntVar::index : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GIntVar::WithName( const Napi::CallbackInfo& info )
{
    //     IntVar WithName( const std::string& name );
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string name = info[ 0 ].As< Napi::String >().Utf8Value();
        spIntVar->WithName( name );
        return this->Value();
    }

    ThrowJsError( operations_research::GIntVar::WithName : Invalid argument );
    return info.Env().Undefined();
}

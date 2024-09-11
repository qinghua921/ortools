#pragma once

#include "commonheader.hpp"
#include "GConstraint.hpp"

namespace operations_research
{
namespace sat
{
    WrapOrToolsClass(
        TableConstraint,
        WrapOrToolsMethod( AddTuple ); );
};  // namespace sat
};  // namespace operations_research

inline operations_research::sat::GTableConstraint::GTableConstraint( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GTableConstraint >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< TableConstraint > >();
        shared_ptr    = std::shared_ptr< TableConstraint >( external.Data() );
        return;
    }

    ThrowJsError( operations_research::GTableConstraint::GTableConstraint : Invalid argument );
}

inline void operations_research::sat::GTableConstraint::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "TableConstraint",
        {
            InstanceMethod( "AddTuple", &GTableConstraint::AddTuple ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "TableConstraint" ), func );
}

inline Napi::Value operations_research::sat::GTableConstraint::AddTuple( const Napi::CallbackInfo& info )
{
    //     void AddTuple( absl::Span< const int64_t > tuple );
    if ( info.Length() == 1 && info[ 0 ].IsArray() )
    {
        auto                   jsTuple = info[ 0 ].As< Napi::Array >();
        std::vector< int64_t > tuple( jsTuple.Length() );
        for ( int i = 0; i < jsTuple.Length(); i++ )
        {
            if ( jsTuple.Get( i ).IsNumber() )
            {
                tuple[ i ] = jsTuple.Get( i ).As< Napi::Number >().Int64Value();
                continue;
            }

            ThrowJsError( operations_research::GTableConstraint::AddTuple : Invalid argument );
            return info.Env().Undefined();
        }

        shared_ptr->AddTuple( tuple );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GTableConstraint::AddTuple : Invalid argument );
    return info.Env().Undefined();
}

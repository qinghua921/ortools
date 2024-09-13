#pragma once

#include "commonheader.hpp"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
class GDomain : public Napi::ObjectWrap< GDomain >
{
    CommonProperties( Domain );

    static Napi::Value FromFlatIntervals( const Napi::CallbackInfo& info );
};
};  // namespace operations_research

inline operations_research::GDomain::GDomain( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GDomain >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< Domain > >();
        spDomain      = std::shared_ptr< Domain >( external.Data() );
        return;
    }

    //      Domain() {}
    if ( info.Length() == 0 )
    {
        spDomain = std::make_shared< Domain >();
        return;
    }

    //      Domain(int64_t left, int64_t right);
    if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() )
    {
        int64_t left  = info[ 0 ].As< Napi::Number >().Int64Value();
        int64_t right = info[ 1 ].As< Napi::Number >().Int64Value();
        spDomain      = std::make_shared< Domain >( left, right );
        return;
    }

    ThrowJsError( operations_research::GDomain::GDomain : Invalid argument );
}

inline Napi::Object operations_research::GDomain::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "Domain",
        {
            StaticMethod( "FromFlatIntervals", &GDomain::FromFlatIntervals ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "Domain" ), func );
    return exports;
}

inline Napi::Value operations_research::GDomain::FromFlatIntervals( const Napi::CallbackInfo& info )
{
    // static Domain FromFlatIntervals(const std::vector<int64_t>& flat_intervals);
    if ( info.Length() == 1 && info[ 0 ].IsArray() )
    {
        std::vector< int64_t > flat_intervals;
        Napi::Array            arr = info[ 0 ].As< Napi::Array >();
        for ( uint32_t i = 0; i < arr.Length(); i++ )
        {
            if ( arr.Get( i ).IsNumber() )
            {
                flat_intervals.push_back( arr.Get( i ).As< Napi::Number >().Int64Value() );
                continue;
            }

            ThrowJsError( operations_research::GDomain::FromFlatIntervals : Invalid argument );
            return info.Env().Undefined();
        }
        auto domain   = Domain::FromFlatIntervals( flat_intervals );
        auto external = Napi::External< Domain >::New( info.Env(), new Domain( domain ) );
        return GDomain::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GDomain::FromFlatIntervals : Invalid argument );
    return info.Env().Undefined();
}

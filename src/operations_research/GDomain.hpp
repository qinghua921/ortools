#pragma once

#include <napi.h>
#include "../commonheader.hpp"
#include <ortools/util/sorted_interval_list.h>

namespace operations_research
{

class GDomain : public Napi::ObjectWrap< GDomain >
{
public:
    static Napi::FunctionReference constructor;
    Domain                         vDomain;

public:
    GDomain( const Napi::CallbackInfo& info );
    ~GDomain();

public:
    static Napi::Object Init( Napi::Env env, Napi::Object exports );
    static Napi::Value  FromValues( const Napi::CallbackInfo& info );
    Napi::Value         Contains( const Napi::CallbackInfo& info );
    Napi::Value         FlattenedIntervals( const Napi::CallbackInfo& info );
};

Napi::FunctionReference GDomain::constructor;

Napi::Object GDomain::Init( Napi::Env env, Napi::Object exports )
{
    Napi::Function func = DefineClass(
        env,
        "Domain",
        {
            StaticMethod( "FromValues", &GDomain::FromValues ),                    //
            InstanceMethod( "Contains", &GDomain::Contains ),                      //
            InstanceMethod( "FlattenedIntervals", &GDomain::FlattenedIntervals ),  //
        } );

    constructor = Napi::Persistent( func );
    exports.Set( "Domain", func );
    return exports;
}

Napi::Value GDomain::FromValues( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 1 && info[ 0 ].IsArray() )
    {
        auto                   values = info[ 0 ].As< Napi::Array >();
        std::vector< int64_t > values_;
        for ( size_t i = 0; i < values.Length(); i++ )
        {
            if ( values.Get( i ).IsNumber() ) values_.push_back( values.Get( i ).As< Napi::Number >() );
        }
        if ( values.Length() == values_.size() )
        {
            auto ret           = Domain::FromValues( values_ );
            auto asExternalVar = Napi::External< Domain >::New( info.Env(), &ret );
            return GDomain::constructor.New( { asExternalVar } );
        }
    }

    ThrowJsError( GDomain::FromValues Error );
    return info.Env().Undefined();
}

Napi::Value GDomain::Contains( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        auto shuzi = info[ 0 ].As< Napi::Number >();
        auto ret   = this->vDomain.Contains( shuzi );
        return Napi::Boolean::New( info.Env(), ret );
    }

    ThrowJsError( GDomain::Contains Error );
    return info.Env().Undefined();
}

Napi::Value GDomain::FlattenedIntervals( const Napi::CallbackInfo& info )
{
    auto shuju_list = this->vDomain.FlattenedIntervals();
    auto ret        = Napi::Array::New( info.Env(), shuju_list.size() );

    for ( int i = 0; i < shuju_list.size(); ++i )
    {
        ret.Set( i, Napi::Number::New( info.Env(), shuju_list[ i ] ) );
    }

    return ret;
};

GDomain::~GDomain()
{
#ifdef DEBUG
    LOG( INFO ) << "GDomain::~GDomain";
#endif
}

GDomain::GDomain( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GDomain >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto pDomain = info[ 0 ].As< Napi::External< Domain > >().Data();
        if ( typeid( *pDomain ) == typeid( Domain ) )
        {
            this->vDomain = *pDomain;
            return;
        }
    }

    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        auto value    = info[ 0 ].As< Napi::Number >();
        this->vDomain = Domain( value );
        return;
    }

    if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() )
    {
        auto left     = info[ 0 ].As< Napi::Number >();
        auto right    = info[ 1 ].As< Napi::Number >();
        this->vDomain = Domain( left, right );
        return;
    }

    ThrowJsError( GDomain::GDomain Error );
}

}  // namespace operations_research

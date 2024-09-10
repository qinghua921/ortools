#pragma once


#include "commonheader.hpp"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
class GDomain : public Napi::ObjectWrap< GDomain >
{
public:
    static Napi::FunctionReference constructor;
    Domain*                        pDomain = nullptr;
    GDomain( const Napi::CallbackInfo& info );
    ~GDomain();
    static Napi::Object Init( Napi::Env env, Napi::Object exports );
};
};  // namespace operations_research

Napi::FunctionReference operations_research::GDomain::constructor;

inline operations_research::GDomain::GDomain( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GDomain >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< Domain > >();
        pDomain       = dynamic_cast< Domain* >( external.Data() );
        if ( pDomain != nullptr ) return;
    }

    //      Domain() {}
    if ( info.Length() == 0 )
    {
        pDomain = new Domain();
        return;
    }

    //      Domain(int64_t left, int64_t right);
    if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() )
    {
        int64_t left  = info[ 0 ].As< Napi::Number >().Int64Value();
        int64_t right = info[ 1 ].As< Napi::Number >().Int64Value();
        pDomain       = new Domain( left, right );
        return;
    }

    ThrowJsError( operations_research::GDomain::GDomain : Invalid argument );
}

inline operations_research::GDomain::~GDomain()
{
    delete pDomain;
}

inline Napi::Object operations_research::GDomain::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "Domain",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "Domain" ), func );
    return exports;
}

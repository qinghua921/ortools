#pragma once


#include "commonheader.hpp"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
    class GCpModelProto : public Napi::ObjectWrap< GCpModelProto >
    {
    public:
        static inline Napi::FunctionReference constructor;
        CpModelProto*                  pCpModelProto = nullptr;
        GCpModelProto( const Napi::CallbackInfo& info );
        ~GCpModelProto();
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
    };
};  // namespace sat
};  // namespace operations_research



inline operations_research::sat::GCpModelProto::GCpModelProto( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GCpModelProto >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< CpModelProto > >();
        pCpModelProto = dynamic_cast< CpModelProto* >( external.Data() );
        if ( pCpModelProto != nullptr ) return;
    }

    ThrowJsError( operations_research::GCpModelProto::GCpModelProto : Invalid argument );
}

inline operations_research::sat::GCpModelProto::~GCpModelProto()
{
    delete pCpModelProto;
}

inline Napi::Object operations_research::sat::GCpModelProto::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "CpModelProto",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "CpModelProto" ), func );
    return exports;
}

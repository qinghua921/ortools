#pragma once


#include "commonheader.hpp"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{
class GMPModelProto : public Napi::ObjectWrap< GMPModelProto >
{
public:
    static Napi::FunctionReference constructor;
    MPModelProto*                          pMPModelProto = nullptr;
    GMPModelProto( const Napi::CallbackInfo& info );
    ~GMPModelProto();
    static Napi::Object Init( Napi::Env env, Napi::Object exports );
};
};  // namespace operations_research

Napi::FunctionReference operations_research::GMPModelProto::constructor;

inline operations_research::GMPModelProto::GMPModelProto( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMPModelProto >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< MPModelProto > >();
        pMPModelProto         = dynamic_cast< MPModelProto* >( external.Data() );
        if ( pMPModelProto != nullptr ) return;
    }

    ThrowJsError( operations_research::GMPModelProto::GMPModelProto : Invalid argument );
}

inline operations_research::GMPModelProto::~GMPModelProto()
{
    delete pMPModelProto;
}

inline Napi::Object operations_research::GMPModelProto::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "MPModelProto",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "MPModelProto" ), func );
    return exports;
}

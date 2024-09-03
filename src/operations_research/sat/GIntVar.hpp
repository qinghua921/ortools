#pragma once

#include <napi.h>
#include "../../commonheader.hpp"
#include "ortools/sat/cp_model.h"
#include "GBoolVar.hpp"

namespace operations_research
{
namespace sat
{
    class GIntVar : public Napi::ObjectWrap< GIntVar >
    {
    public:
        static Napi::FunctionReference constructor;
        IntVar*                        pIntVar = nullptr;
        GIntVar( const Napi::CallbackInfo& info );
        ~GIntVar();
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
    };
};  // namespace sat
};  // namespace operations_research

Napi::FunctionReference operations_research::sat::GIntVar::constructor;

inline operations_research::sat::GIntVar::GIntVar( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GIntVar >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< IntVar > >();
        pIntVar       = dynamic_cast< IntVar* >( external.Data() );
        if ( pIntVar != nullptr ) return;
    }

    //     IntVar() = default;
    if ( info.Length() == 0 )
    {
        pIntVar = new IntVar();
        return;
    }

    //     explicit IntVar( const BoolVar& var );
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        auto gboolvar = GBoolVar::Unwrap( info[ 0 ].As< Napi::Object >() );
        pIntVar       = new IntVar( *gboolvar->pBoolVar );
        return;
    }

    ThrowJsError( operations_research::GIntVar::GIntVar : Invalid argument );
}

inline operations_research::sat::GIntVar::~GIntVar()
{
    delete pIntVar;
}

inline Napi::Object operations_research::sat::GIntVar::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "IntVar",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "IntVar" ), func );
    return exports;
}

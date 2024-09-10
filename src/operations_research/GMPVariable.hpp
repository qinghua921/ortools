#pragma once


#include "commonheader.hpp"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{
class GMPVariable : public Napi::ObjectWrap< GMPVariable >
{
public:
    static Napi::FunctionReference constructor;
    MPVariable*                    pMPVariable = nullptr;
    GMPVariable( const Napi::CallbackInfo& info );
    ~GMPVariable();
    static Napi::Object Init( Napi::Env env, Napi::Object exports );

    Napi::Value solution_value( const Napi::CallbackInfo& info ) ;
};
};  // namespace operations_research

Napi::FunctionReference operations_research::GMPVariable::constructor;

inline operations_research::GMPVariable::GMPVariable( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMPVariable >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< MPVariable > >();
        pMPVariable   = dynamic_cast< MPVariable* >( external.Data() );
        if ( pMPVariable != nullptr ) return;
    }

    ThrowJsError( operations_research::GMPVariable::GMPVariable : Invalid argument );
}

inline operations_research::GMPVariable::~GMPVariable()
{
    delete pMPVariable;
}

inline Napi::Object operations_research::GMPVariable::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "MPVariable",
        {
            InstanceMethod( "solution_value", &GMPVariable::solution_value ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "MPVariable" ), func );
    return exports;
}

inline Napi::Value operations_research::GMPVariable::solution_value( const Napi::CallbackInfo& info )
{
    //     double solution_value() const;
    if(info.Length() == 0)
    {
        return Napi::Number::New( info.Env(), pMPVariable->solution_value() );
    }

    ThrowJsError( operations_research::GMPVariable::solution_value : Invalid argument );
    return info.Env().Undefined();
}

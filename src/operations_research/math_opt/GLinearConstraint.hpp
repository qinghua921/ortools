#pragma once


#include "commonheader.hpp"
#include "ortools/math_opt/cpp/math_opt.h"

namespace operations_research
{
namespace math_opt
{
    class GLinearConstraint : public Napi::ObjectWrap< GLinearConstraint >
    {
    public:
        static Napi::FunctionReference constructor;
        LinearConstraint*              pLinearConstraint = nullptr;
        GLinearConstraint( const Napi::CallbackInfo& info );
        ~GLinearConstraint();
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
    };
};  // namespace math_opt
};  // namespace operations_research

Napi::FunctionReference operations_research::math_opt::GLinearConstraint::constructor;

inline operations_research::math_opt::GLinearConstraint::GLinearConstraint( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GLinearConstraint >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external     = info[ 0 ].As< Napi::External< LinearConstraint > >();
        pLinearConstraint = dynamic_cast< LinearConstraint* >( external.Data() );
        if ( pLinearConstraint != nullptr ) return;
    }

    ThrowJsError( operations_research::GLinearConstraint::GLinearConstraint : Invalid argument );
}

inline operations_research::math_opt::GLinearConstraint::~GLinearConstraint()
{
    delete pLinearConstraint;
}

inline Napi::Object operations_research::math_opt::GLinearConstraint::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "LinearConstraint",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "LinearConstraint" ), func );
    return exports;
}

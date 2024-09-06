#pragma once

#include <napi.h>
#include "../../commonheader.hpp"
#include "ortools/math_opt/cpp/math_opt.h"

namespace operations_research
{
namespace math_opt
{
    class GModel : public Napi::ObjectWrap< GModel >
    {
    public:
        static Napi::FunctionReference constructor;
        Model*                         pModel = nullptr;
        GModel( const Napi::CallbackInfo& info );
        ~GModel();
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
    };
};  // namespace math_opt
};  // namespace operations_research

Napi::FunctionReference operations_research::math_opt::GModel::constructor;

inline operations_research::math_opt::GModel::GModel( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GModel >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< Model > >();
        pModel        = dynamic_cast< Model* >( external.Data() );
        if ( pModel != nullptr ) return;
    }

    ThrowJsError( operations_research::GModel::GModel : Invalid argument );
}

inline operations_research::math_opt::GModel::~GModel()
{
    delete pModel;
}

inline Napi::Object operations_research::math_opt::GModel::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "Model",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "Model" ), func );
    return exports;
}

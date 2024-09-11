#pragma once

#include "commonheader.hpp"
#include "ortools/sat/model.h"

namespace operations_research
{
namespace sat
{
    class GModel : public Napi::ObjectWrap< GModel >
    {
    public:
        static inline Napi::FunctionReference constructor;
        std::shared_ptr< Model >              spModel;
        GModel( const Napi::CallbackInfo& info );
        static Napi::Object Init( Napi::Env env, Napi::Object exports );

        Napi::Value Add( const Napi::CallbackInfo& info );
    };
};  // namespace sat
};  // namespace operations_research

inline operations_research::sat::GModel::GModel( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GModel >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< Model > >();
        spModel       = std::shared_ptr< Model >( external.Data() );
        return;
    }

    //     Model() {}
    if ( info.Length() == 0 )
    {
        spModel = std::make_shared< Model >();
        return;
    }

    ThrowJsError( operations_research::GModel::GModel : Invalid argument );
}

inline Napi::Object operations_research::sat::GModel::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "Model",
        {
            InstanceMethod( "Add", &GModel::Add ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "Model" ), func );
    return exports;
}

inline Napi::Value operations_research::sat::GModel::Add( const Napi::CallbackInfo& info )
{
    // template < typename T >
    // T Add( std::function< T( Model* ) > f )
    if ( info.Length() == 1 && info[ 0 ].IsFunction() )
    {
        auto env  = info.Env();
        auto jsin = info[ 0 ].As< Napi::Function >();

        auto ret = this->spModel->Add< Napi::Value >( [ env, jsin ]( Model* model ) -> Napi::Value {
            auto asExternalVar = Napi::External< Model >::New( env, model );
            auto vGModel       = GModel::constructor.New( { asExternalVar } );
            return jsin.Call( { vGModel } );
        } );

        return ret;
    }

    ThrowJsError( operations_research::GModel::Add : Invalid argument );
    return info.Env().Undefined();
}
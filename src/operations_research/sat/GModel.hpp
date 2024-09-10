#pragma once

#include <napi.h>
#include "../../commonheader.hpp"
#include "ortools/sat/model.h"

namespace operations_research
{
namespace sat
{
    class GModel : public Napi::ObjectWrap< GModel >
    {
    public:
        static Napi::FunctionReference constructor;
        Model*                         pModel = nullptr;
        GModel( const Napi::CallbackInfo& info );
        ~GModel();
        static Napi::Object Init( Napi::Env env, Napi::Object exports );

        Napi::Value Add( const Napi::CallbackInfo& info );
    };
};  // namespace sat
};  // namespace operations_research

Napi::FunctionReference operations_research::sat::GModel::constructor;

inline operations_research::sat::GModel::GModel( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GModel >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< Model > >();
        pModel        = dynamic_cast< Model* >( external.Data() );
        if ( pModel != nullptr ) return;
    }

    //     Model() {}
    if ( info.Length() == 0 )
    {
        pModel = new Model();
        return;
    }

    ThrowJsError( operations_research::GModel::GModel : Invalid argument );
}

inline operations_research::sat::GModel::~GModel()
{
    delete pModel;
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
        auto f = info[ 0 ].As< Napi::Function >();
        return f.Call( { this->Value() } );
        // TODO: return the result need to be wrapped in a Napi::Value
        // auto result = pModel->Add(
        //     [ &f, this ]( Model* model_ ) -> Napi::Value {
        //         return f.Call( { this->Value() } );
        //     } );

        // return result;
    }

    ThrowJsError( operations_research::GModel::Add : Invalid argument );
    return info.Env().Undefined();
}
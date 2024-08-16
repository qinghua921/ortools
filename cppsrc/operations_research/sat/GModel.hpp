#pragma once

#include <napi.h>
#include <ortools/sat/cp_model.h>
#include "../../commonheader.hpp"

namespace operations_research
{
namespace sat
{

    class GModel : public Napi::ObjectWrap< GModel >
    {
    public:
        static Napi::FunctionReference constructor;
        Model*                         pModel;
        bool                           deleteit;

    public:
        GModel( const Napi::CallbackInfo& info );
        ~GModel();

    public:
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
        Napi::Value         Add( const Napi::CallbackInfo& info );
        Napi::Value         Name( const Napi::CallbackInfo& info );
        // Napi::Value         index( const Napi::CallbackInfo& info );
    };

    Napi::Object GModel::Init( Napi::Env env, Napi::Object exports )
    {
        Napi::Function func = DefineClass(
            env,
            "Model",
            {
                InstanceMethod( "Add", &GModel::Add ),    //
                InstanceMethod( "Name", &GModel::Name ),  //
                // InstanceMethod( "index", &GIntVar::WithName ),        //
            } );

        constructor = Napi::Persistent( func );
        exports.Set( "Model", func );
        return exports;
    }

    Napi::Value GModel::Add( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsFunction() )
        {
            auto env  = info.Env();
            auto jsin = info[ 0 ].As< Napi::Function >();

            auto ret = this->pModel->Add< Napi::Value >( [ env, jsin ]( Model* model ) -> Napi::Value {
                auto asExternalVar = Napi::External< Model >::New( env, model );
                auto vGModel       = GModel::constructor.New( { asExternalVar } );
                return jsin.Call( { vGModel } );
            } );

            return ret;
        }

        PaoJsError( GModel::Add ERROR );
        return info.Env().Undefined();
    }

    Napi::Value GModel::Name( const Napi::CallbackInfo& info )
    {
        return Napi::String::New( info.Env(), this->pModel->Name() );
    }

    GModel::GModel( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GModel >( info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto pModel = info[ 0 ].As< Napi::External< Model > >().Data();
            if ( typeid( *pModel ) == typeid( Model ) )
            {
                this->pModel   = pModel;
                this->deleteit = false;
                return;
            }
        }

        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            this->pModel   = new Model( info[ 0 ].As< Napi::String >() );
            this->deleteit = true;
            return;
        }

        PaoJsError( GModel::GModel ERROR );
    }

    GModel::~GModel()
    {
#ifdef KAIFA
        LOG( INFO ) << "GModel::~GModel";
#endif  // DEBUG
        if ( this->pModel && this->deleteit )
        {
            delete this->pModel;
            this->pModel = nullptr;
        }
    }

    Napi::FunctionReference GModel::constructor;

}  // namespace sat
}  // namespace operations_research
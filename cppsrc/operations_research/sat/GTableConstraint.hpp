#pragma once

#include <napi.h>
#include <ortools/sat/cp_model.h>
#include "../../commonheader.hpp"

namespace operations_research
{
namespace sat
{

    class GTableConstraint : public Napi::ObjectWrap< GTableConstraint >
    {
    public:
        static Napi::FunctionReference constructor;
        TableConstraint*               pTableConstraint;

    public:
        GTableConstraint( const Napi::CallbackInfo& info );
        ~GTableConstraint();

    public:
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
        Napi::Value         AddTuple( const Napi::CallbackInfo& info );
    };

    Napi::FunctionReference GTableConstraint::constructor;

    GTableConstraint::GTableConstraint( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GTableConstraint >( info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto pTableConstraint = info[ 0 ].As< Napi::External< TableConstraint > >().Data();
            if ( typeid( *pTableConstraint ) == typeid( TableConstraint ) )
            {
                // 注意: 黑科技
                auto neicun = new byte[ sizeof( TableConstraint ) ];
                memcpy( neicun, pTableConstraint, sizeof( TableConstraint ) );
                this->pTableConstraint = ( TableConstraint* )neicun;
                return;
            }
        }

        PaoJsError( GTableConstraint::GTableConstraint ERROR );
    }

    GTableConstraint::~GTableConstraint()
    {
#ifdef KAIFA
        LOG( INFO ) << "GTableConstraint::~GTableConstraint";
#endif
        if ( this->pTableConstraint )
        {
            delete[]( ( byte* )this->pTableConstraint );
            this->pTableConstraint = nullptr;
        }
    }

    Napi::Object GTableConstraint::Init( Napi::Env env, Napi::Object exports )
    {
        Napi::Function func = DefineClass(
            env,
            "TableConstraint",
            {
                InstanceMethod( "AddTuple", &GTableConstraint::AddTuple ),  //
            } );

        constructor = Napi::Persistent( func );
        exports.Set( "TableConstraint", func );
        return exports;
    }

    Napi::Value GTableConstraint::AddTuple( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsArray() )
        {
            auto var = info[ 0 ].As< Napi::Array >();

            std::vector< int64_t > intVars;
            for ( size_t i = 0; i < var.Length(); i++ )
            {
                if ( var.Get( i ).IsNumber() ) intVars.push_back( var.Get( i ).As< Napi::Number >().Int64Value() );
            }
            if ( var.Length() == intVars.size() )
            {
                this->pTableConstraint->AddTuple( absl::Span< const int64_t >( intVars ) );
                return info.Env().Undefined();
            }
        }

        PaoJsError( GTableConstraint::AddTuple ERROR );
        return info.Env().Undefined();
    }

}  // namespace sat
}  // namespace operations_research
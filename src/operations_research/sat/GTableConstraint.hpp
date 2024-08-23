#pragma once

#include <napi.h>
#include "ortools/sat/cp_model.h"
#include "../../commonheader.hpp"

namespace operations_research
{
namespace sat
{
    class GTableConstraint : public Napi::ObjectWrap< GTableConstraint >
    {
    public:
        static Napi::FunctionReference constructor;
        TableConstraint*               pTableConstraint = nullptr;

        GTableConstraint( const Napi::CallbackInfo& info )
            : Napi::ObjectWrap< GTableConstraint >( info )
        {
            if ( info.Length() == 1 && info[ 0 ].IsExternal() )
            {
                auto external    = info[ 0 ].As< Napi::External< TableConstraint > >();
                pTableConstraint = dynamic_cast< TableConstraint* >( external.Data() );
                if ( pTableConstraint != nullptr ) return;
            }

            ThrowJsError( GTableConstraint::constructor : Invalid arguments );
        }

        ~GTableConstraint()
        {
            if ( pTableConstraint != nullptr )
            {
                delete pTableConstraint;
                pTableConstraint = nullptr;
            }
        }

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "TableConstraint",
                {} );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( "TableConstraint", func );
            return exports;
        };

        //     void AddTuple( absl::Span< const int64_t > tuple );
        Napi::Value AddTuple( const Napi::CallbackInfo& info )
        {
            if ( info.Length() == 1 && info[ 0 ].IsArray() )
            {
                Napi::Array            jsTuple = info[ 0 ].As< Napi::Array >();
                std::vector< int64_t > tuple( jsTuple.Length() );
                for ( int i = 0; i < jsTuple.Length(); i++ )
                {
                    tuple[ i ] = jsTuple.Get( i ).As< Napi::Number >().Int64Value();
                }

                pTableConstraint->AddTuple( tuple );
                return info.Env().Undefined();
            }

            ThrowJsError( GTableConstraint::AddTuple : Invalid arguments );
            return info.Env().Undefined();
        }
    };

    Napi::FunctionReference GTableConstraint::constructor;

}  // namespace sat
}  // namespace operations_research
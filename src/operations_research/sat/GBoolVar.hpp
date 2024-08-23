#pragma once

#include <napi.h>
#include "../../commonheader.hpp"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
    class GBoolVar : public Napi::ObjectWrap< GBoolVar >
    {
    public:
        static Napi::FunctionReference constructor;
        BoolVar*                       pBoolVar = nullptr;

        GBoolVar( const Napi::CallbackInfo& info )
            : Napi::ObjectWrap< GBoolVar >( info )
        {
            //         BoolVar() = default;
            if ( info.Length() == 0 )
            {
                pBoolVar = new BoolVar();
                return;
            }

            if ( info.Length() == 1 && info[ 0 ].IsExternal() )
            {
                auto external = info[ 0 ].As< Napi::External< BoolVar > >();
                pBoolVar      = dynamic_cast< BoolVar* >( external.Data() );
                if ( pBoolVar ) return;
            }

            ThrowJsError( GBoolVar::GBoolVar : Invalid number of arguments.);
        };

        ~GBoolVar()
        {
            if ( pBoolVar )
            {
                delete pBoolVar;
                pBoolVar = nullptr;
            }
        };

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "BoolVar",
                {
                    InstanceMethod( "WithName", &GBoolVar::WithName ),
                } );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( "BoolVar", func );
            return exports;
        };

        //         BoolVar WithName( const std::string& name );
        Napi::Value WithName( const Napi::CallbackInfo& info )
        {
            if ( info.Length() == 1 && info[ 0 ].IsString() )
            {
                std::string name = info[ 0 ].As< Napi::String >().Utf8Value();
                *pBoolVar        = pBoolVar->WithName( name );
                return this->Value();
            }

            ThrowJsError( GBoolVar::WithName : Invalid number of arguments or argument type.);
            return info.Env().Undefined();
        };

        //         /// Returns the name of the variable.
        //         std::string Name() const;

        //         /// Returns the logical negation of the current Boolean variable.
        //         BoolVar Not() const
        //         {
        //             return BoolVar( NegatedRef( index_ ), builder_ );
        //         }

        //         bool operator==( const BoolVar& other ) const
        //         {
        //             return other.builder_ == builder_ && other.index_ == index_;
        //         }

        //         bool operator!=( const BoolVar& other ) const
        //         {
        //             return other.builder_ != builder_ || other.index_ != index_;
        //         }

        //         std::string DebugString() const;

        //         /**
        //          * Returns the index of the variable in the model.
        //          *
        //          * Warning: If the variable is the negation of another variable v, its index
        //          * is -v.index() - 1. So this can be negative.
        //          */
        //         int index() const
        //         {
        //             return index_;
        //         }

        //     };
    };

    Napi::FunctionReference GBoolVar::constructor;
};  // namespace sat
};  // namespace operations_research
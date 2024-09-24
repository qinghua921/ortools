#pragma once

#include "napi.h"
#include "ortools/packing/multiple_dimensions_bin_packing.pb.h"
#include "MultipleDimensionsBinPackingShape.hpp"
#include "MultipleDimensionsBinPackingItem.hpp"

namespace operations_research
{
namespace packing
{
    class GMultipleDimensionsBinPackingProblem : public Napi::ObjectWrap< GMultipleDimensionsBinPackingProblem >
    {
    public:
        static inline Napi::FunctionReference constructor;
        MultipleDimensionsBinPackingProblem*  pMultipleDimensionsBinPackingProblem = nullptr;

        GMultipleDimensionsBinPackingProblem( const Napi::CallbackInfo& info )
            : Napi::ObjectWrap< GMultipleDimensionsBinPackingProblem >( info )
        {
            Napi::Env env = info.Env();

            if ( info.Length() == 1 && info[ 0 ].IsExternal() )
            {
                auto external                        = info[ 0 ].As< Napi::External< MultipleDimensionsBinPackingProblem > >();
                pMultipleDimensionsBinPackingProblem = dynamic_cast< MultipleDimensionsBinPackingProblem* >( external.Data() );
                if ( pMultipleDimensionsBinPackingProblem ) return;
            }

            //        inline MultipleDimensionsBinPackingProblem()
            //            : MultipleDimensionsBinPackingProblem( nullptr ) {}
            if ( info.Length() == 0 )
            {
                pMultipleDimensionsBinPackingProblem = new MultipleDimensionsBinPackingProblem();
                return;
            }

            Napi::TypeError::New( env, "operations_research::GMultipleDimensionsBinPackingProblem::GMultipleDimensionsBinPackingProblem : Invalid arguments" ).ThrowAsJavaScriptException();
        };

        ~GMultipleDimensionsBinPackingProblem()
        {
            if ( pMultipleDimensionsBinPackingProblem ) delete pMultipleDimensionsBinPackingProblem;
        };

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "MultipleDimensionsBinPackingProblem",
                {
                    InstanceMethod( "items_size", &GMultipleDimensionsBinPackingProblem::items_size ),
                    InstanceMethod( "box_shape", &GMultipleDimensionsBinPackingProblem::box_shape ),
                    InstanceMethod( "items", &GMultipleDimensionsBinPackingProblem::items ),
                    InstanceMethod( "has_box_shape", &GMultipleDimensionsBinPackingProblem::has_box_shape ),
                    InstanceMethod( "clear_box_shape", &GMultipleDimensionsBinPackingProblem::clear_box_shape ),
                } );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "MultipleDimensionsBinPackingProblem" ), func );
            return exports;
        };

        // void clear_box_shape();
        Napi::Value clear_box_shape( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            if ( info.Length() == 0 )
            {
                pMultipleDimensionsBinPackingProblem->clear_box_shape();
                return env.Null();
            }

            Napi::TypeError::New( env, "operations_research::GMultipleDimensionsBinPackingProblem::clear_box_shape : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        };

        // bool has_box_shape() const;
        Napi::Value has_box_shape( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            if ( info.Length() == 0 )
            {
                return Napi::Boolean::New( env, pMultipleDimensionsBinPackingProblem->has_box_shape() );
            }

            Napi::TypeError::New( env, "operations_research::GMultipleDimensionsBinPackingProblem::has_box_shape : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        };

        // const RepeatedPtrField<MultipleDimensionsBinPackingItem >& items() const;
        Napi::Value items( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            if ( info.Length() == 0 )
            {
                Napi::Array items = Napi::Array::New( env, pMultipleDimensionsBinPackingProblem->items_size() );
                for ( int i = 0; i < pMultipleDimensionsBinPackingProblem->items_size(); i++ )
                {
                    auto external = Napi::External< MultipleDimensionsBinPackingItem >::New(
                        env, new MultipleDimensionsBinPackingItem( pMultipleDimensionsBinPackingProblem->items( i ) ) );
                    items.Set( i, GMultipleDimensionsBinPackingItem::constructor.New( { external } ) );
                }
                return items;
            }

            Napi::TypeError::New( env, "operations_research::GMultipleDimensionsBinPackingProblem::items : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        };

        //  const MultipleDimensionsBinPackingShape& box_shape() const;
        Napi::Value box_shape( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            if ( info.Length() == 0 )
            {
                auto external = Napi::External< MultipleDimensionsBinPackingShape >::New(
                    env, new MultipleDimensionsBinPackingShape( pMultipleDimensionsBinPackingProblem->box_shape() ) );
                return GMultipleDimensionsBinPackingShape::constructor.New( { external } );
            }

            Napi::TypeError::New( env, "operations_research::GMultipleDimensionsBinPackingProblem::box_shape : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        };

        // int items_size() const;
        Napi::Value items_size( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            if ( info.Length() == 0 )
            {
                return Napi::Number::New( env, pMultipleDimensionsBinPackingProblem->items_size() );
            }

            Napi::TypeError::New( env, "operations_research::GMultipleDimensionsBinPackingProblem::items_size : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        };
    };
};  // namespace packing
};  // namespace operations_research
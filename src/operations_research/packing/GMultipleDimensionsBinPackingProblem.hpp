#pragma once

#include <napi.h>
#include "commonheader.hpp"
#include "ortools/packing/binpacking_2d_parser.h"
#include "GMultipleDimensionsBinPackingShape.hpp"
#include "GMultipleDimensionsBinPackingItem.hpp"
#include "google/protobuf/GRepeatedPtrField.hpp"

namespace operations_research
{
namespace packing
{
    class GMultipleDimensionsBinPackingProblem : public Napi::ObjectWrap< GMultipleDimensionsBinPackingProblem >
    {
    public:
        static Napi::FunctionReference       constructor;
        MultipleDimensionsBinPackingProblem* pMultipleDimensionsBinPackingProblem = nullptr;
        GMultipleDimensionsBinPackingProblem( const Napi::CallbackInfo& info );
        ~GMultipleDimensionsBinPackingProblem();
        static Napi::Object Init( Napi::Env env, Napi::Object exports );

        Napi::Value items_size( const Napi::CallbackInfo& info );
        Napi::Value box_shape( const Napi::CallbackInfo& info );
        Napi::Value items( const Napi::CallbackInfo& info );
    };
};  // namespace packing
};  // namespace operations_research

Napi::FunctionReference operations_research::packing::GMultipleDimensionsBinPackingProblem::constructor;

inline operations_research::packing::GMultipleDimensionsBinPackingProblem::GMultipleDimensionsBinPackingProblem( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMultipleDimensionsBinPackingProblem >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external                        = info[ 0 ].As< Napi::External< MultipleDimensionsBinPackingProblem > >();
        pMultipleDimensionsBinPackingProblem = dynamic_cast< MultipleDimensionsBinPackingProblem* >( external.Data() );
        if ( pMultipleDimensionsBinPackingProblem != nullptr ) return;
    }

    ThrowJsError( operations_research::GMultipleDimensionsBinPackingProblem::GMultipleDimensionsBinPackingProblem : Invalid argument );
}

inline operations_research::packing::GMultipleDimensionsBinPackingProblem::~GMultipleDimensionsBinPackingProblem()
{
    delete pMultipleDimensionsBinPackingProblem;
}

inline Napi::Object operations_research::packing::GMultipleDimensionsBinPackingProblem::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "MultipleDimensionsBinPackingProblem",
        {
            InstanceMethod( "items_size", &GMultipleDimensionsBinPackingProblem::items_size ),
            InstanceMethod( "box_shape", &GMultipleDimensionsBinPackingProblem::box_shape ),
            InstanceMethod( "items", &GMultipleDimensionsBinPackingProblem::items ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "MultipleDimensionsBinPackingProblem" ), func );
    return exports;
}

inline Napi::Value operations_research::packing::GMultipleDimensionsBinPackingProblem::items( const Napi::CallbackInfo& info )
{
    //     const ::operations_research::packing::MultipleDimensionsBinPackingItem& items( int index ) const;
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        int  index    = info[ 0 ].As< Napi::Number >().Int32Value();
        auto item     = pMultipleDimensionsBinPackingProblem->items( index );
        auto external = Napi::External< MultipleDimensionsBinPackingItem >::New( info.Env(), new MultipleDimensionsBinPackingItem( item ) );
        return GMultipleDimensionsBinPackingItem::constructor.New( { external } );
    }

    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::packing::MultipleDimensionsBinPackingItem >&
    //     items() const;
    if ( info.Length() == 0 )
    {
        auto items   = pMultipleDimensionsBinPackingProblem->items();
        auto g_items = new google::protobuf::RepeatedPtrField< GMultipleDimensionsBinPackingItem >();
        for ( int i = 0; i < items.size(); i++ )
        {
            auto item     = items.Get( i );
            auto external = Napi::External< MultipleDimensionsBinPackingItem >::New( info.Env(), new MultipleDimensionsBinPackingItem( item ) );
            auto g_item   = GMultipleDimensionsBinPackingItem::constructor.New( { external } );
            g_items->AddAllocated( GMultipleDimensionsBinPackingItem::Unwrap( g_item ) );
        }

        auto external = Napi::External< google::protobuf::RepeatedPtrField< GMultipleDimensionsBinPackingItem > >::New( info.Env(), g_items );
        return google::protobuf::GRepeatedPtrField< GMultipleDimensionsBinPackingItem >::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GMultipleDimensionsBinPackingProblem::items : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::packing::GMultipleDimensionsBinPackingProblem::box_shape( const Napi::CallbackInfo& info )
{
    //     const ::operations_research::packing::MultipleDimensionsBinPackingShape&              box_shape() const;
    if ( info.Length() == 0 )
    {
        auto box_shape = pMultipleDimensionsBinPackingProblem->box_shape();
        auto external  = Napi::External< MultipleDimensionsBinPackingShape >::New( info.Env(), new MultipleDimensionsBinPackingShape( box_shape ) );
        return GMultipleDimensionsBinPackingShape::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GMultipleDimensionsBinPackingProblem::box_shape : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::packing::GMultipleDimensionsBinPackingProblem::items_size( const Napi::CallbackInfo& info )
{
    //     int items_size() const;
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), pMultipleDimensionsBinPackingProblem->items_size() );
    }

    ThrowJsError( operations_research::GMultipleDimensionsBinPackingProblem::items_size : Invalid argument );
    return info.Env().Undefined();
}
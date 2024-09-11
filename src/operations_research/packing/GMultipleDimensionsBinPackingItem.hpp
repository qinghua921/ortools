#pragma once


#include "commonheader.hpp"
#include "ortools/packing/binpacking_2d_parser.h"
#include "GMultipleDimensionsBinPackingShape.hpp"

namespace operations_research
{
namespace packing
{
    class GMultipleDimensionsBinPackingItem : public Napi::ObjectWrap< GMultipleDimensionsBinPackingItem >
    {
    public:
        static inline Napi::FunctionReference    constructor;
        MultipleDimensionsBinPackingItem* pMultipleDimensionsBinPackingItem = nullptr;
        GMultipleDimensionsBinPackingItem( const Napi::CallbackInfo& info );
        ~GMultipleDimensionsBinPackingItem();
        static Napi::Object Init( Napi::Env env, Napi::Object exports );

        Napi::Value shapes( const Napi::CallbackInfo& info );
        Napi::Value shapes_size( const Napi::CallbackInfo& info );
    };
};  // namespace packing
};  // namespace operations_research



inline operations_research::packing::GMultipleDimensionsBinPackingItem::GMultipleDimensionsBinPackingItem( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMultipleDimensionsBinPackingItem >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external                     = info[ 0 ].As< Napi::External< MultipleDimensionsBinPackingItem > >();
        pMultipleDimensionsBinPackingItem = dynamic_cast< MultipleDimensionsBinPackingItem* >( external.Data() );
        if ( pMultipleDimensionsBinPackingItem != nullptr ) return;
    }

    ThrowJsError( operations_research::GMultipleDimensionsBinPackingItem::GMultipleDimensionsBinPackingItem : Invalid argument );
}

inline operations_research::packing::GMultipleDimensionsBinPackingItem::~GMultipleDimensionsBinPackingItem()
{
    delete pMultipleDimensionsBinPackingItem;
}

inline Napi::Object operations_research::packing::GMultipleDimensionsBinPackingItem::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "MultipleDimensionsBinPackingItem",
        {
            InstanceMethod( "shapes", &GMultipleDimensionsBinPackingItem::shapes ),
            InstanceMethod( "shapes_size", &GMultipleDimensionsBinPackingItem::shapes_size ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "MultipleDimensionsBinPackingItem" ), func );
    return exports;
}

inline Napi::Value operations_research::packing::GMultipleDimensionsBinPackingItem::shapes( const Napi::CallbackInfo& info )
{
    //     const ::operations_research::packing::MultipleDimensionsBinPackingShape& shapes( int index ) const;
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        int  index    = info[ 0 ].As< Napi::Number >().Int32Value();
        auto shapes   = pMultipleDimensionsBinPackingItem->shapes( index );
        auto external = Napi::External< MultipleDimensionsBinPackingShape >::New( info.Env(), new MultipleDimensionsBinPackingShape( shapes ) );
        return GMultipleDimensionsBinPackingShape::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GMultipleDimensionsBinPackingItem::shapes : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::packing::GMultipleDimensionsBinPackingItem::shapes_size( const Napi::CallbackInfo& info )
{
    //     int shapes_size() const;
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), pMultipleDimensionsBinPackingItem->shapes_size() );
    }

    ThrowJsError( operations_research::GMultipleDimensionsBinPackingItem::shapes_size : Invalid argument );
    return info.Env().Undefined();
}

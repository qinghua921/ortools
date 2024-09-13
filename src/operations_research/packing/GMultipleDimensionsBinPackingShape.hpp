#pragma once

#include "commonheader.hpp"
#include "ortools/packing/binpacking_2d_parser.h"
#include "google/protobuf/GRepeatedField.hpp"

namespace operations_research
{
namespace packing
{
    class GMultipleDimensionsBinPackingShape : public Napi::ObjectWrap< GMultipleDimensionsBinPackingShape >
    {
        CommonProperties( MultipleDimensionsBinPackingShape );

        Napi::Value dimensions( const Napi::CallbackInfo& info );
        Napi::Value dimensions_size( const Napi::CallbackInfo& info );
    };
};  // namespace packing
};  // namespace operations_research

inline operations_research::packing::GMultipleDimensionsBinPackingShape::GMultipleDimensionsBinPackingShape( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMultipleDimensionsBinPackingShape >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external                       = info[ 0 ].As< Napi::External< MultipleDimensionsBinPackingShape > >();
        spMultipleDimensionsBinPackingShape = std::shared_ptr< MultipleDimensionsBinPackingShape >( external.Data() );
        return;
    }

    ThrowJsError( operations_research::GMultipleDimensionsBinPackingShape::GMultipleDimensionsBinPackingShape : Invalid argument );
}

inline Napi::Object operations_research::packing::GMultipleDimensionsBinPackingShape::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "MultipleDimensionsBinPackingShape",
        {
            InstanceMethod( "dimensions", &GMultipleDimensionsBinPackingShape::dimensions ),
            InstanceMethod( "dimensions_size", &GMultipleDimensionsBinPackingShape::dimensions_size ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "MultipleDimensionsBinPackingShape" ), func );
    return exports;
}

inline Napi::Value operations_research::packing::GMultipleDimensionsBinPackingShape::dimensions_size( const Napi::CallbackInfo& info )
{
    //     int dimensions_size() const;
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), spMultipleDimensionsBinPackingShape->dimensions_size() );
    }

    ThrowJsError( operations_research::GMultipleDimensionsBinPackingShape::dimensions_size : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::packing::GMultipleDimensionsBinPackingShape::dimensions( const Napi::CallbackInfo& info )
{
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
    //     dimensions() const;
    if ( info.Length() == 0 )
    {
        auto dimensions = spMultipleDimensionsBinPackingShape->dimensions();
        auto external   = Napi::External< google::protobuf::RepeatedField< int64_t > >::New( info.Env(), new google::protobuf::RepeatedField< int64_t >( dimensions ) );
        return google::protobuf::GRepeatedField< int64_t >::constructor.New( { external } );
    }

    //     int64_t dimensions( int index ) const;
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        auto index = info[ 0 ].As< Napi::Number >().Int64Value();
        return Napi::Number::New( info.Env(), spMultipleDimensionsBinPackingShape->dimensions( index ) );
    }

    ThrowJsError( operations_research::GMultipleDimensionsBinPackingShape::dimensions : Invalid argument );
    return info.Env().Undefined();
}
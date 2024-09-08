#pragma once

#include <napi.h>
#include "../../commonheader.hpp"
#include "ortools/packing/binpacking_2d_parser.h"

namespace operations_research
{
namespace packing
{
    class GMultipleDimensionsBinPackingShape : public Napi::ObjectWrap< GMultipleDimensionsBinPackingShape >
    {
    public:
        static Napi::FunctionReference     constructor;
        MultipleDimensionsBinPackingShape* pMultipleDimensionsBinPackingShape = nullptr;
        GMultipleDimensionsBinPackingShape( const Napi::CallbackInfo& info );
        ~GMultipleDimensionsBinPackingShape();
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
    };
};  // namespace packing
};  // namespace operations_research

Napi::FunctionReference operations_research::packing::GMultipleDimensionsBinPackingShape::constructor;

inline operations_research::packing::GMultipleDimensionsBinPackingShape::GMultipleDimensionsBinPackingShape( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMultipleDimensionsBinPackingShape >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external                      = info[ 0 ].As< Napi::External< MultipleDimensionsBinPackingShape > >();
        pMultipleDimensionsBinPackingShape = dynamic_cast< MultipleDimensionsBinPackingShape* >( external.Data() );
        if ( pMultipleDimensionsBinPackingShape != nullptr ) return;
    }

    ThrowJsError( operations_research::GMultipleDimensionsBinPackingShape::GMultipleDimensionsBinPackingShape : Invalid argument );
}

inline operations_research::packing::GMultipleDimensionsBinPackingShape::~GMultipleDimensionsBinPackingShape()
{
    delete pMultipleDimensionsBinPackingShape;
}

inline Napi::Object operations_research::packing::GMultipleDimensionsBinPackingShape::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "MultipleDimensionsBinPackingShape",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "MultipleDimensionsBinPackingShape" ), func );
    return exports;
}

#pragma once

#include "napi.h"
#include "ortools/packing/multiple_dimensions_bin_packing.pb.h"

namespace operations_research
{
namespace packing
{
    class GMultipleDimensionsBinPackingShape : public Napi::ObjectWrap< GMultipleDimensionsBinPackingShape >
    {
    public:
        static inline Napi::FunctionReference constructor;
        MultipleDimensionsBinPackingShape*    pMultipleDimensionsBinPackingShape = nullptr;

        GMultipleDimensionsBinPackingShape( const Napi::CallbackInfo& info )
            : Napi::ObjectWrap< GMultipleDimensionsBinPackingShape >( info )
        {
            Napi::Env env = info.Env();

            if ( info.Length() == 1 && info[ 0 ].IsExternal() )
            {
                auto external                      = info[ 0 ].As< Napi::External< MultipleDimensionsBinPackingShape > >();
                pMultipleDimensionsBinPackingShape = dynamic_cast< MultipleDimensionsBinPackingShape* >( external.Data() );
                if ( pMultipleDimensionsBinPackingShape ) return;
            }

            Napi::TypeError::New( env, "operations_research::GMultipleDimensionsBinPackingShape::GMultipleDimensionsBinPackingShape : Invalid arguments" ).ThrowAsJavaScriptException();
        };

        ~GMultipleDimensionsBinPackingShape()
        {
            if ( pMultipleDimensionsBinPackingShape ) delete pMultipleDimensionsBinPackingShape;
        };

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "MultipleDimensionsBinPackingShape",
                {} );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "MultipleDimensionsBinPackingShape" ), func );
            return exports;
        };
    };
}  // namespace packing

};  // namespace operations_research
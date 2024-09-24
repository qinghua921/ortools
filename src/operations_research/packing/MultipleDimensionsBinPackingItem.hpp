#pragma once

#include "napi.h"
#include "ortools/packing/multiple_dimensions_bin_packing.pb.h"

namespace operations_research
{
namespace packing
{
    class GMultipleDimensionsBinPackingItem : public Napi::ObjectWrap< GMultipleDimensionsBinPackingItem >
    {
    public:
        static inline Napi::FunctionReference constructor;
        MultipleDimensionsBinPackingItem*     pMultipleDimensionsBinPackingItem = nullptr;

        GMultipleDimensionsBinPackingItem( const Napi::CallbackInfo& info )
            : Napi::ObjectWrap< GMultipleDimensionsBinPackingItem >( info )
        {
            Napi::Env env = info.Env();

            if ( info.Length() == 1 && info[ 0 ].IsExternal() )
            {
                auto external                     = info[ 0 ].As< Napi::External< MultipleDimensionsBinPackingItem > >();
                pMultipleDimensionsBinPackingItem = dynamic_cast< MultipleDimensionsBinPackingItem* >( external.Data() );
                if ( pMultipleDimensionsBinPackingItem ) return;
            }

            Napi::TypeError::New( env, "operations_research::GMultipleDimensionsBinPackingItem::GMultipleDimensionsBinPackingItem : Invalid arguments" ).ThrowAsJavaScriptException();
        };

        ~GMultipleDimensionsBinPackingItem()
        {
            if ( pMultipleDimensionsBinPackingItem ) delete pMultipleDimensionsBinPackingItem;
        };

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "MultipleDimensionsBinPackingItem",
                {} );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "MultipleDimensionsBinPackingItem" ), func );
            return exports;
        };
    };
}  // namespace packing

};  // namespace operations_research
#pragma once

#include "napi.h"
#include "ortools/packing/multiple_dimensions_bin_packing.pb.h"

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
                {} );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "MultipleDimensionsBinPackingProblem" ), func );
            return exports;
        };
    };
}  // namespace packing

};  // namespace operations_research
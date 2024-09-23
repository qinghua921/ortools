#pragma once

#include "napi.h"
#include "ortools/packing/binpacking_2d_parser.h"

namespace operations_research
{
namespace packing
{
    class GBinPacking2dParser : public Napi::ObjectWrap< GBinPacking2dParser >
    {
    public:
        static inline Napi::FunctionReference constructor;
        BinPacking2dParser*                   pBinPacking2dParser = nullptr;

        GBinPacking2dParser( const Napi::CallbackInfo& info )
            : Napi::ObjectWrap< GBinPacking2dParser >( info )
        {
            Napi::Env env = info.Env();

            if ( info.Length() == 1 && info[ 0 ].IsExternal() )
            {
                auto external       = info[ 0 ].As< Napi::External< BinPacking2dParser > >();
                pBinPacking2dParser = dynamic_cast< BinPacking2dParser* >( external.Data() );
                if ( pBinPacking2dParser ) return;
            }

            // BinPacking2dParser();
            if ( info.Length() == 0 )
            {
                pBinPacking2dParser = new BinPacking2dParser();
                return;
            }

            Napi::TypeError::New( env, "operations_research::GBinPacking2dParser::GBinPacking2dParser : Invalid arguments" ).ThrowAsJavaScriptException();
        };

        ~GBinPacking2dParser()
        {
            if ( pBinPacking2dParser ) delete pBinPacking2dParser;
        };

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "BinPacking2dParser",
                {
                    InstanceMethod( "Load2BPFile", &GBinPacking2dParser::Load2BPFile )
                } );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "BinPacking2dParser" ), func );
            return exports;
        };

        // MultipleDimensionsBinPackingProblem problem() const
        Napi::Value problem( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            if ( info.Length() == 0 )
            {
                return Napi::External< MultipleDimensionsBinPackingProblem >::New( env, pBinPacking2dParser->problem() );
            }

            Napi::TypeError::New( env, "operations_research::GBinPacking2dParser::problem : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        };

        // bool Load2BPFile( absl::string_view file_name, int instance );
        Napi::Value Load2BPFile( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            if ( info.Length() == 2 && info[ 0 ].IsString() && info[ 1 ].IsNumber() )
            {
                std::string file_name = info[ 0 ].As< Napi::String >().Utf8Value();
                int         instance  = info[ 1 ].As< Napi::Number >().Int32Value();
                bool        result    = pBinPacking2dParser->Load2BPFile( file_name, instance );
                return Napi::Boolean::New( env, result );
            }

            Napi::TypeError::New( env, "operations_research::GBinPacking2dParser::Load2BPFile : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        };
    };
}  // namespace packing

};  // namespace operations_research
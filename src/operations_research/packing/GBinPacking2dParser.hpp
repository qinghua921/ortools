#pragma once

#include "commonheader.hpp"
#include "ortools/packing/binpacking_2d_parser.h"
#include "GMultipleDimensionsBinPackingProblem.hpp"

namespace operations_research
{
namespace packing
{
    class GBinPacking2dParser : public Napi::ObjectWrap< GBinPacking2dParser >
    {
    public:
        static inline Napi::FunctionReference constructor;
        BinPacking2dParser*                   pBinPacking2dParser = nullptr;
        GBinPacking2dParser( const Napi::CallbackInfo& info );
        ~GBinPacking2dParser();
        static Napi::Object Init( Napi::Env env, Napi::Object exports );

        Napi::Value Load2BPFile( const Napi::CallbackInfo& info );
        Napi::Value problem( const Napi::CallbackInfo& info );
    };
};  // namespace packing
};  // namespace operations_research

inline operations_research::packing::GBinPacking2dParser::GBinPacking2dParser( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GBinPacking2dParser >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external       = info[ 0 ].As< Napi::External< BinPacking2dParser > >();
        pBinPacking2dParser = dynamic_cast< BinPacking2dParser* >( external.Data() );
        if ( pBinPacking2dParser != nullptr ) return;
    }

    //  BinPacking2dParser();
    if ( info.Length() == 0 )
    {
        pBinPacking2dParser = new BinPacking2dParser();
        return;
    }

    ThrowJsError( operations_research::GBinPacking2dParser::GBinPacking2dParser : Invalid argument );
}

inline operations_research::packing::GBinPacking2dParser::~GBinPacking2dParser()
{
    delete pBinPacking2dParser;
}

inline Napi::Object operations_research::packing::GBinPacking2dParser::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "BinPacking2dParser",
        {
            InstanceMethod( "Load2BPFile", &GBinPacking2dParser::Load2BPFile ),
            InstanceMethod( "problem", &GBinPacking2dParser::problem ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "BinPacking2dParser" ), func );
    return exports;
}

inline Napi::Value operations_research::packing::GBinPacking2dParser::problem( const Napi::CallbackInfo& info )
{
    //  MultipleDimensionsBinPackingProblem problem() const { return problem_; }
    if ( info.Length() == 0 )
    {
        auto problem  = pBinPacking2dParser->problem();
        auto external = Napi::External< MultipleDimensionsBinPackingProblem >::New( info.Env(), new MultipleDimensionsBinPackingProblem( problem ) );
        return GMultipleDimensionsBinPackingProblem::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GBinPacking2dParser::problem : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::packing::GBinPacking2dParser::Load2BPFile( const Napi::CallbackInfo& info )
{
    //  bool Load2BPFile(const std::string& file_name, int instance);
    if ( info.Length() == 2 && info[ 0 ].IsString() && info[ 1 ].IsNumber() )
    {
        std::string file_name = info[ 0 ].As< Napi::String >().Utf8Value();
        int         instance  = info[ 1 ].As< Napi::Number >().Int32Value();
        bool        result    = pBinPacking2dParser->Load2BPFile( file_name, instance );
        return Napi::Boolean::New( info.Env(), result );
    }

    ThrowJsError( operations_research::GBinPacking2dParser::Load2BPFile : Invalid argument );
    return info.Env().Undefined();
}

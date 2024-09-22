#pragma once

#include "napi.h"
#include "ortools/graph/assignment.h"

namespace operations_research
{

class GSimpleLinearSumAssignment : public Napi::ObjectWrap< GSimpleLinearSumAssignment >
{
public:
    static inline Napi::FunctionReference constructor;
    SimpleLinearSumAssignment*            pSimpleLinearSumAssignment = nullptr;

    GSimpleLinearSumAssignment( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GSimpleLinearSumAssignment >( info )
    {
        Napi::Env env = info.Env();

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external              = info[ 0 ].As< Napi::External< SimpleLinearSumAssignment > >();
            pSimpleLinearSumAssignment = dynamic_cast< SimpleLinearSumAssignment* >( external.Data() );
            if ( pSimpleLinearSumAssignment ) return;
        }

        Napi::TypeError::New( env, "operations_research::GSimpleLinearSumAssignment::GSimpleLinearSumAssignment : Invalid arguments" ).ThrowAsJavaScriptException();
    };

    // TODO delete pSimpleLinearSumAssignment or not ?
    // ~GSimpleLinearSumAssignment()
    // {
    //     if ( pSimpleLinearSumAssignment ) delete pSimpleLinearSumAssignment;
    // };

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "SimpleLinearSumAssignment",
            {} );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "SimpleLinearSumAssignment" ), func );
        return exports;
    };
};

};  // namespace operations_research
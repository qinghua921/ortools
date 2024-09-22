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

        // SimpleLinearSumAssignment();
        if ( info.Length() == 0 )
        {
            pSimpleLinearSumAssignment = new SimpleLinearSumAssignment();
            return;
        }

        Napi::TypeError::New( env, "operations_research::GSimpleLinearSumAssignment::GSimpleLinearSumAssignment : Invalid arguments" ).ThrowAsJavaScriptException();
    };

    ~GSimpleLinearSumAssignment()
    {
        if ( pSimpleLinearSumAssignment ) delete pSimpleLinearSumAssignment;
    };

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );

        auto enumStatus = Napi::Object::New( env );
        enumStatus.Set( "OPTIMAL", static_cast< int >( SimpleLinearSumAssignment::Status::OPTIMAL ) );
        enumStatus.Set( "INFEASIBLE", static_cast< int >( SimpleLinearSumAssignment::Status::INFEASIBLE ) );
        enumStatus.Set( "POSSIBLE_OVERFLOW", static_cast< int >( SimpleLinearSumAssignment::Status::POSSIBLE_OVERFLOW ) );

        Napi::Function func = DefineClass(
            env, "SimpleLinearSumAssignment",
            {
                StaticValue( "Status", enumStatus ),
                InstanceMethod( "AddArcWithCost", &GSimpleLinearSumAssignment::AddArcWithCost ),
                InstanceMethod( "Solve", &GSimpleLinearSumAssignment::Solve ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "SimpleLinearSumAssignment" ), func );
        return exports;
    };

    //    Status Solve();
    Napi::Value Solve( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            SimpleLinearSumAssignment::Status status = pSimpleLinearSumAssignment->Solve();
            return Napi::Number::New( env, static_cast< int >( status ) );
        }

        Napi::TypeError::New( env, "operations_research::GSimpleLinearSumAssignment::Solve : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //    ArcIndex AddArcWithCost( NodeIndex left_node, NodeIndex right_node,
    //                             CostValue cost );
    Napi::Value AddArcWithCost( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsNumber() )
        {
            NodeIndex left_node  = info[ 0 ].As< Napi::Number >().Int32Value();
            NodeIndex right_node = info[ 1 ].As< Napi::Number >().Int32Value();
            CostValue cost       = info[ 2 ].As< Napi::Number >().Int32Value();

            ArcIndex arc_index = pSimpleLinearSumAssignment->AddArcWithCost( left_node, right_node, cost );
            return Napi::Number::New( env, arc_index );
        }

        Napi::TypeError::New( env, "operations_research::GSimpleLinearSumAssignment::AddArcWithCost : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };
};

};  // namespace operations_research
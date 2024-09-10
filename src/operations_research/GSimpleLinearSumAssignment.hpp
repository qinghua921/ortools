#pragma once

#include <napi.h>
#include "commonheader.hpp"
#include "ortools/graph/assignment.h"

namespace operations_research
{
class GSimpleLinearSumAssignment : public Napi::ObjectWrap< GSimpleLinearSumAssignment >
{
public:
    static Napi::FunctionReference constructor;
    SimpleLinearSumAssignment*     pSimpleLinearSumAssignment = nullptr;
    GSimpleLinearSumAssignment( const Napi::CallbackInfo& info );
    ~GSimpleLinearSumAssignment();
    static Napi::Object Init( Napi::Env env, Napi::Object exports );

    Napi::Value Solve( const Napi::CallbackInfo& info );
    Napi::Value AddArcWithCost( const Napi::CallbackInfo& info );
};
};  // namespace operations_research

Napi::FunctionReference operations_research::GSimpleLinearSumAssignment::constructor;

inline operations_research::GSimpleLinearSumAssignment::GSimpleLinearSumAssignment( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GSimpleLinearSumAssignment >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external              = info[ 0 ].As< Napi::External< SimpleLinearSumAssignment > >();
        pSimpleLinearSumAssignment = dynamic_cast< SimpleLinearSumAssignment* >( external.Data() );
        if ( pSimpleLinearSumAssignment != nullptr ) return;
    }

    //     SimpleLinearSumAssignment();
    if ( info.Length() == 0 )
    {
        pSimpleLinearSumAssignment = new SimpleLinearSumAssignment();
        return;
    }

    ThrowJsError( operations_research::GSimpleLinearSumAssignment::GSimpleLinearSumAssignment : Invalid argument );
}

inline operations_research::GSimpleLinearSumAssignment::~GSimpleLinearSumAssignment()
{
    delete pSimpleLinearSumAssignment;
}

inline Napi::Object operations_research::GSimpleLinearSumAssignment::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );

    // export enum Status
    Napi::Object status_obj = Napi::Object::New( env );
    status_obj.Set( Napi::String::New( env, "OPTIMAL" ), Napi::Number::New( env, SimpleLinearSumAssignment::OPTIMAL ) );
    status_obj.Set( Napi::String::New( env, "INFEASIBLE" ), Napi::Number::New( env, SimpleLinearSumAssignment::INFEASIBLE ) );
    status_obj.Set( Napi::String::New( env, "POSSIBLE_OVERFLOW" ), Napi::Number::New( env, SimpleLinearSumAssignment::POSSIBLE_OVERFLOW ) );

    Napi::Function    func = DefineClass(
        env, "SimpleLinearSumAssignment",
        {
            InstanceMethod( "Solve", &GSimpleLinearSumAssignment::Solve ),
            InstanceMethod( "AddArcWithCost", &GSimpleLinearSumAssignment::AddArcWithCost ),
            StaticValue( "Status", status_obj ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "SimpleLinearSumAssignment" ), func );
    return exports;
}

inline Napi::Value operations_research::GSimpleLinearSumAssignment::Solve( const Napi::CallbackInfo& info )
{
    //     Status Solve();
    if ( info.Length() == 0 )
    {
        auto status = pSimpleLinearSumAssignment->Solve();
        return Napi::Number::New( info.Env(), status );
    }

    ThrowJsError( operations_research::GSimpleLinearSumAssignment::Solve : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSimpleLinearSumAssignment::AddArcWithCost( const Napi::CallbackInfo& info )
{
    //     ArcIndex AddArcWithCost( NodeIndex left_node, NodeIndex right_node,
    //                              CostValue cost );
    if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsNumber() )
    {
        NodeIndex left_node  = info[ 0 ].As< Napi::Number >().Int32Value();
        NodeIndex right_node = info[ 1 ].As< Napi::Number >().Int32Value();
        CostValue cost       = info[ 2 ].As< Napi::Number >().Int64Value();
        ArcIndex  arc_index  = pSimpleLinearSumAssignment->AddArcWithCost( left_node, right_node, cost );
        return Napi::Number::New( info.Env(), arc_index );
    }

    ThrowJsError( operations_research::GSimpleLinearSumAssignment::AddArcWithCost : Invalid argument );
    return info.Env().Undefined();
}

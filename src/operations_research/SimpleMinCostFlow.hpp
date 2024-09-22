#pragma once

#include "napi.h"
#include "ortools/graph/min_cost_flow.h"

namespace operations_research
{

class GSimpleMinCostFlow : public Napi::ObjectWrap< GSimpleMinCostFlow >
{
public:
    static inline Napi::FunctionReference constructor;
    SimpleMinCostFlow*                    pSimpleMinCostFlow = nullptr;

    GSimpleMinCostFlow( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GSimpleMinCostFlow >( info )
    {
        Napi::Env env = info.Env();

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external      = info[ 0 ].As< Napi::External< SimpleMinCostFlow > >();
            pSimpleMinCostFlow = dynamic_cast< SimpleMinCostFlow* >( external.Data() );
            if ( pSimpleMinCostFlow ) return;
        }

        //     explicit SimpleMinCostFlow( NodeIndex reserve_num_nodes = 0,
        //                                 ArcIndex  reserve_num_arcs  = 0 );
        if ( info.Length() == 0 || ( info.Length() == 1 && info[ 0 ].IsNumber() )
             || ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() ) )
        {
            int reserve_num_nodes = 0;
            int reserve_num_arcs  = 0;
            if ( info.Length() == 1 )
            {
                reserve_num_nodes = info[ 0 ].As< Napi::Number >().Int32Value();
            }
            else if ( info.Length() == 2 )
            {
                reserve_num_nodes = info[ 0 ].As< Napi::Number >().Int32Value();
                reserve_num_arcs  = info[ 1 ].As< Napi::Number >().Int32Value();
            }
            pSimpleMinCostFlow = new SimpleMinCostFlow( reserve_num_nodes, reserve_num_arcs );
            return;
        }

        Napi::TypeError::New( env, "operations_research::GSimpleMinCostFlow::GSimpleMinCostFlow : Invalid arguments" ).ThrowAsJavaScriptException();
    };

    ~GSimpleMinCostFlow()
    {
        if ( pSimpleMinCostFlow ) delete pSimpleMinCostFlow;
    };

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );

        auto enumStatus = Napi::Object::New( env );
        enumStatus.Set( "NOT_SOLVED", static_cast< int >( MinCostFlow::Status::NOT_SOLVED ) );
        enumStatus.Set( "OPTIMAL", static_cast< int >( MinCostFlow::Status::OPTIMAL ) );
        enumStatus.Set( "FEASIBLE", static_cast< int >( MinCostFlow::Status::FEASIBLE ) );
        enumStatus.Set( "INFEASIBLE", static_cast< int >( MinCostFlow::Status::INFEASIBLE ) );
        enumStatus.Set( "UNBALANCED", static_cast< int >( MinCostFlow::Status::UNBALANCED ) );
        enumStatus.Set( "BAD_RESULT", static_cast< int >( MinCostFlow::Status::BAD_RESULT ) );
        enumStatus.Set( "BAD_COST_RANGE", static_cast< int >( MinCostFlow::Status::BAD_COST_RANGE ) );

        Napi::Function func = DefineClass(
            env, "SimpleMinCostFlow",
            {
                StaticValue( "Status", enumStatus ),
                InstanceMethod( "AddArcWithCapacityAndUnitCost", &GSimpleMinCostFlow::AddArcWithCapacityAndUnitCost ),
                InstanceMethod( "SetNodeSupply", &GSimpleMinCostFlow::SetNodeSupply ),
                InstanceMethod( "Solve", &GSimpleMinCostFlow::Solve ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "SimpleMinCostFlow" ), func );
        return exports;
    };

    //  Status Solve()
    Napi::Value Solve( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            MinCostFlow::Status status = pSimpleMinCostFlow->Solve();
            return Napi::Number::New( env, status );
        }

        Napi::TypeError::New( env, "operations_research::GSimpleMinCostFlow::Solve : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //  void SetNodeSupply( NodeIndex node, FlowQuantity supply );
    Napi::Value SetNodeSupply( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() )
        {
            NodeIndex    node   = info[ 0 ].As< Napi::Number >().Int32Value();
            FlowQuantity supply = info[ 1 ].As< Napi::Number >().Int32Value();
            pSimpleMinCostFlow->SetNodeSupply( node, supply );
            return env.Undefined();
        }

        Napi::TypeError::New( env, "operations_research::GSimpleMinCostFlow::SetNodeSupply : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //     ArcIndex AddArcWithCapacityAndUnitCost( NodeIndex tail, NodeIndex head,
    //                                             FlowQuantity capacity,
    //                                             CostValue    unit_cost );
    Napi::Value AddArcWithCapacityAndUnitCost( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 4 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsNumber() && info[ 3 ].IsNumber() )
        {
            NodeIndex    tail      = info[ 0 ].As< Napi::Number >().Int32Value();
            NodeIndex    head      = info[ 1 ].As< Napi::Number >().Int32Value();
            FlowQuantity capacity  = info[ 2 ].As< Napi::Number >().Int32Value();
            CostValue    unit_cost = info[ 3 ].As< Napi::Number >().Int32Value();
            ArcIndex     arc_index = pSimpleMinCostFlow->AddArcWithCapacityAndUnitCost( tail, head, capacity, unit_cost );
            return Napi::Number::New( env, arc_index );
        }

        Napi::TypeError::New( env, "operations_research::GSimpleMinCostFlow::AddArcWithCapacityAndUnitCost : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };
};

};  // namespace operations_research
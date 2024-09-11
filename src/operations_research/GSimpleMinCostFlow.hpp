#pragma once

#include "commonheader.hpp"
#include "ortools/graph/min_cost_flow.h"

namespace operations_research
{
WrapOrToolsClass(
    SimpleMinCostFlow,
    WrapOrToolsMethod( NumNodes );
    WrapOrToolsMethod( NumArcs );
    WrapOrToolsMethod( Tail );
    WrapOrToolsMethod( Head );
    WrapOrToolsMethod( Capacity );
    WrapOrToolsMethod( Supply );
    WrapOrToolsMethod( UnitCost );
    WrapOrToolsMethod( OptimalCost );
    WrapOrToolsMethod( Solve );
    WrapOrToolsMethod( SetNodeSupply );
    WrapOrToolsMethod( AddArcWithCapacityAndUnitCost );
    WrapOrToolsMethod( Flow ); );
};  // namespace operations_research

inline operations_research::GSimpleMinCostFlow::GSimpleMinCostFlow( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GSimpleMinCostFlow >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< SimpleMinCostFlow > >();
        shared_ptr    = std::shared_ptr< SimpleMinCostFlow >( external.Data() );
        return;
    }

    if ( info.Length() == 0 )
    {
        shared_ptr = std::make_shared< SimpleMinCostFlow >();
        return;
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::GSimpleMinCostFlow : Invalid argument );
}

inline void operations_research::GSimpleMinCostFlow::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );

    //  export enum Status
    Napi::Object status_obj = Napi::Object::New( env );
    status_obj.Set( Napi::String::New( env, "NOT_SOLVED" ), Napi::Number::New( env, SimpleMinCostFlow::NOT_SOLVED ) );
    status_obj.Set( Napi::String::New( env, "OPTIMAL" ), Napi::Number::New( env, SimpleMinCostFlow::OPTIMAL ) );
    status_obj.Set( Napi::String::New( env, "FEASIBLE" ), Napi::Number::New( env, SimpleMinCostFlow::FEASIBLE ) );
    status_obj.Set( Napi::String::New( env, "INFEASIBLE" ), Napi::Number::New( env, SimpleMinCostFlow::INFEASIBLE ) );
    status_obj.Set( Napi::String::New( env, "UNBALANCED" ), Napi::Number::New( env, SimpleMinCostFlow::UNBALANCED ) );
    status_obj.Set( Napi::String::New( env, "BAD_RESULT" ), Napi::Number::New( env, SimpleMinCostFlow::BAD_RESULT ) );
    status_obj.Set( Napi::String::New( env, "BAD_COST_RANGE" ), Napi::Number::New( env, SimpleMinCostFlow::BAD_COST_RANGE ) );

    Napi::Function func = DefineClass(
        env, "SimpleMinCostFlow",
        {
            StaticValue( "Status", status_obj ),

            InstanceMethod( "NumNodes", &GSimpleMinCostFlow::NumNodes ),
            InstanceMethod( "NumArcs", &GSimpleMinCostFlow::NumArcs ),
            InstanceMethod( "Tail", &GSimpleMinCostFlow::Tail ),
            InstanceMethod( "Head", &GSimpleMinCostFlow::Head ),
            InstanceMethod( "Capacity", &GSimpleMinCostFlow::Capacity ),
            InstanceMethod( "Supply", &GSimpleMinCostFlow::Supply ),
            InstanceMethod( "UnitCost", &GSimpleMinCostFlow::UnitCost ),
            InstanceMethod( "OptimalCost", &GSimpleMinCostFlow::OptimalCost ),
            InstanceMethod( "Solve", &GSimpleMinCostFlow::Solve ),
            InstanceMethod( "SetNodeSupply", &GSimpleMinCostFlow::SetNodeSupply ),
            InstanceMethod( "AddArcWithCapacityAndUnitCost", &GSimpleMinCostFlow::AddArcWithCapacityAndUnitCost ),
            InstanceMethod( "Flow", &GSimpleMinCostFlow::Flow ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "SimpleMinCostFlow" ), func );
}

inline Napi::Value operations_research::GSimpleMinCostFlow::Flow( const Napi::CallbackInfo& info )
{
    //     FlowQuantity Flow( ArcIndex arc ) const;
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        auto arc  = info[ 0 ].As< Napi::Number >().Int64Value();
        auto flow = shared_ptr->Flow( arc );
        return Napi::Number::New( info.Env(), flow );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::Flow : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSimpleMinCostFlow::NumNodes( const Napi::CallbackInfo& info )
{
    //     NodeIndex    NumNodes() const;
    if ( info.Length() == 0 )
    {
        auto num_nodes = shared_ptr->NumNodes();
        return Napi::Number::New( info.Env(), num_nodes );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::NumNodes : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSimpleMinCostFlow::NumArcs( const Napi::CallbackInfo& info )
{
    //     ArcIndex     NumArcs() const;
    if ( info.Length() == 0 )
    {
        auto num_arcs = shared_ptr->NumArcs();
        return Napi::Number::New( info.Env(), num_arcs );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::NumArcs : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSimpleMinCostFlow::Tail( const Napi::CallbackInfo& info )
{
    //     NodeIndex    Tail( ArcIndex arc ) const;
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        auto arc  = info[ 0 ].As< Napi::Number >().Int64Value();
        auto tail = shared_ptr->Tail( arc );
        return Napi::Number::New( info.Env(), tail );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::Tail : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSimpleMinCostFlow::Head( const Napi::CallbackInfo& info )
{
    //     NodeIndex    Head( ArcIndex arc ) const;
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        auto arc  = info[ 0 ].As< Napi::Number >().Int64Value();
        auto head = shared_ptr->Head( arc );
        return Napi::Number::New( info.Env(), head );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::Head : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSimpleMinCostFlow::Capacity( const Napi::CallbackInfo& info )
{
    //     FlowQuantity Capacity( ArcIndex arc ) const;
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        auto arc      = info[ 0 ].As< Napi::Number >().Int64Value();
        auto capacity = shared_ptr->Capacity( arc );
        return Napi::Number::New( info.Env(), capacity );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::Capacity : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSimpleMinCostFlow::Supply( const Napi::CallbackInfo& info )
{
    //     FlowQuantity Supply( NodeIndex node ) const;
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        auto node   = info[ 0 ].As< Napi::Number >().Int32Value();
        auto supply = shared_ptr->Supply( node );
        return Napi::Number::New( info.Env(), supply );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::Supply : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSimpleMinCostFlow::UnitCost( const Napi::CallbackInfo& info )
{
    //     CostValue    UnitCost( ArcIndex arc ) const;
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        auto arc       = info[ 0 ].As< Napi::Number >().Int64Value();
        auto unit_cost = shared_ptr->UnitCost( arc );
        return Napi::Number::New( info.Env(), unit_cost );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::UnitCost : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSimpleMinCostFlow::OptimalCost( const Napi::CallbackInfo& info )
{
    //     CostValue OptimalCost() const;
    if ( info.Length() == 0 )
    {
        auto optimal_cost = shared_ptr->OptimalCost();
        return Napi::Number::New( info.Env(), optimal_cost );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::OptimalCost : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSimpleMinCostFlow::Solve( const Napi::CallbackInfo& info )
{
    //     Status Solve()
    if ( info.Length() == 0 )
    {
        auto status = shared_ptr->Solve();
        return Napi::Number::New( info.Env(), status );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::Solve : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSimpleMinCostFlow::SetNodeSupply( const Napi::CallbackInfo& info )
{
    //     void SetNodeSupply( NodeIndex node, FlowQuantity supply );
    if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() )
    {
        NodeIndex    node   = info[ 0 ].As< Napi::Number >().Int32Value();
        FlowQuantity supply = info[ 1 ].As< Napi::Number >().Int64Value();
        shared_ptr->SetNodeSupply( node, supply );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::SetNodeSupply : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSimpleMinCostFlow::AddArcWithCapacityAndUnitCost( const Napi::CallbackInfo& info )
{
    //     ArcIndex AddArcWithCapacityAndUnitCost( NodeIndex tail, NodeIndex head,
    //                                             FlowQuantity capacity,
    //                                             CostValue    unit_cost );
    if ( info.Length() == 4 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsNumber() && info[ 3 ].IsNumber() )
    {
        NodeIndex    tail      = info[ 0 ].As< Napi::Number >().Int32Value();
        NodeIndex    head      = info[ 1 ].As< Napi::Number >().Int32Value();
        FlowQuantity capacity  = info[ 2 ].As< Napi::Number >().Int64Value();
        CostValue    unit_cost = info[ 3 ].As< Napi::Number >().Int64Value();
        ArcIndex     arc_index = shared_ptr->AddArcWithCapacityAndUnitCost( tail, head, capacity, unit_cost );
        return Napi::Number::New( info.Env(), arc_index );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::AddArcWithCapacityAndUnitCost : Invalid argument );
    return info.Env().Undefined();
}

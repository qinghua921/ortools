#pragma once

#include <napi.h>
#include "ortools/graph/min_cost_flow.h"
#include "../commonheader.hpp"

namespace operations_research
{

class GSimpleMinCostFlow : public Napi::ObjectWrap< GSimpleMinCostFlow >
{
public:
    static Napi::FunctionReference constructor;
    SimpleMinCostFlow*             pSimpleMinCostFlow = nullptr;

    GSimpleMinCostFlow( const Napi::CallbackInfo& info );
    ~GSimpleMinCostFlow();

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "SimpleMinCostFlow",
            {
                InstanceMethod( "AddArcWithCapacityAndUnitCost", &GSimpleMinCostFlow::AddArcWithCapacityAndUnitCost ),
                InstanceMethod( "SetNodeSupply", &GSimpleMinCostFlow::SetNodeSupply ),
                InstanceMethod( "Solve", &GSimpleMinCostFlow::Solve ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( "SimpleMinCostFlow", func );
        return exports;
    };

    Napi::Value AddArcWithCapacityAndUnitCost( Napi::CallbackInfo const& info );  //     ArcIndex AddArcWithCapacityAndUnitCost( NodeIndex tail, NodeIndex head, FlowQuantity capacity, CostValue    unit_cost );
    Napi::Value SetNodeSupply( Napi::CallbackInfo const& info );                  //     void SetNodeSupply( NodeIndex node, FlowQuantity supply );
    Napi::Value Solve( Napi::CallbackInfo const& info );                          //     Status Solve()

    //     // By default, the constructor takes no size. New node indices are created
    //     // lazily by AddArcWithCapacityAndUnitCost() or SetNodeSupply() such that the
    //     // set of valid nodes will always be [0, NumNodes()).
    //     //
    //     // You may pre-reserve the internal data structures with a given expected
    //     // number of nodes and arcs, to potentially gain performance.
    //     explicit SimpleMinCostFlow( NodeIndex reserve_num_nodes = 0,
    //                                 ArcIndex  reserve_num_arcs  = 0 );

    //     // Same as Solve(), but does not have the restriction that the supply
    //     // must match the demand or that the graph has enough capacity to serve
    //     // all the demand or use all the supply. This will compute a maximum-flow
    //     // with minimum cost. The value of the maximum-flow will be given by
    //     // MaximumFlow().
    //     Status SolveMaxFlowWithMinCost()
    //     {
    //         return SolveWithPossibleAdjustment( SupplyAdjustment::ADJUST );
    //     }

    //     // Returns the cost of the minimum-cost flow found by the algorithm when
    //     // the returned Status is OPTIMAL.
    //     CostValue OptimalCost() const;

    //     // Returns the total flow of the minimum-cost flow found by the algorithm
    //     // when the returned Status is OPTIMAL.
    //     FlowQuantity MaximumFlow() const;

    //     // Returns the flow on arc, this only make sense for a successful Solve().
    //     //
    //     // Note: It is possible that there is more than one optimal solution. The
    //     // algorithm is deterministic so it will always return the same solution for
    //     // a given problem. However, there is no guarantee of this from one code
    //     // version to the next (but the code does not change often).
    //     FlowQuantity Flow( ArcIndex arc ) const;

    //     // Accessors for the user given data. The implementation will crash if "arc"
    //     // is not in [0, NumArcs()) or "node" is not in [0, NumNodes()).
    //     NodeIndex    NumNodes() const;
    //     ArcIndex     NumArcs() const;
    //     NodeIndex    Tail( ArcIndex arc ) const;
    //     NodeIndex    Head( ArcIndex arc ) const;
    //     FlowQuantity Capacity( ArcIndex arc ) const;
    //     FlowQuantity Supply( NodeIndex node ) const;
    //     CostValue    UnitCost( ArcIndex arc ) const;

    // };
};

GSimpleMinCostFlow::GSimpleMinCostFlow( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GSimpleMinCostFlow >( info )
{
    if ( info.Length() == 0 )
    {
        pSimpleMinCostFlow = new SimpleMinCostFlow();
        return;
    }

    ThrowJsError( GSimpleMinCostFlow::GSimpleMinCostFlow : Invalid arguments );
}

GSimpleMinCostFlow::~GSimpleMinCostFlow()
{
    if ( pSimpleMinCostFlow )
    {
        delete pSimpleMinCostFlow;
        pSimpleMinCostFlow = nullptr;
    }
}

Napi::Value GSimpleMinCostFlow::AddArcWithCapacityAndUnitCost( Napi::CallbackInfo const& info )
{
    if ( info.Length() == 4 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsNumber() && info[ 3 ].IsNumber() )
    {
        NodeIndex    tail      = info[ 0 ].As< Napi::Number >().Int64Value();
        NodeIndex    head      = info[ 1 ].As< Napi::Number >().Int64Value();
        FlowQuantity capacity  = info[ 2 ].As< Napi::Number >().Int64Value();
        CostValue    unit_cost = info[ 3 ].As< Napi::Number >().Int64Value();
        ArcIndex     arc       = pSimpleMinCostFlow->AddArcWithCapacityAndUnitCost( tail, head, capacity, unit_cost );
        return Napi::Number::New( info.Env(), arc );
    }

    ThrowJsError( GSimpleMinCostFlow::AddArcWithCapacityAndUnitCost : Invalid arguments );
    return info.Env().Undefined();
}

Napi::Value GSimpleMinCostFlow::SetNodeSupply( Napi::CallbackInfo const& info )
{
    if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() )
    {
        NodeIndex    node   = info[ 0 ].As< Napi::Number >().Int64Value();
        FlowQuantity supply = info[ 1 ].As< Napi::Number >().Int64Value();
        pSimpleMinCostFlow->SetNodeSupply( node, supply );
        return info.Env().Undefined();
    }

    ThrowJsError( GSimpleMinCostFlow::SetNodeSupply : Invalid arguments );
    return info.Env().Undefined();
}

Napi::Value GSimpleMinCostFlow::Solve( Napi::CallbackInfo const& info )
{
    if ( info.Length() == 0 )
    {
        SimpleMinCostFlow::Status status = pSimpleMinCostFlow->Solve();
        return Napi::Number::New( info.Env(), status );
    }

    ThrowJsError( GSimpleMinCostFlow::Solve : Invalid arguments );
    return info.Env().Undefined();
}

Napi::FunctionReference GSimpleMinCostFlow::constructor;

};  // namespace operations_research
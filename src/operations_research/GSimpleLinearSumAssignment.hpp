#pragma once

#include <napi.h>
#include "ortools/graph/assignment.h"
#include "../commonheader.hpp"

namespace operations_research
{

class GSimpleLinearSumAssignment : public Napi::ObjectWrap< GSimpleLinearSumAssignment >
{
public:
    static Napi::FunctionReference constructor;
    SimpleLinearSumAssignment*     pSimpleLinearSumAssignment = nullptr;
    GSimpleLinearSumAssignment( const Napi::CallbackInfo& info );
    ~GSimpleLinearSumAssignment();
    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "SimpleLinearSumAssignment",
            {
                InstanceMethod( "AddArcWithCost", &GSimpleLinearSumAssignment::AddArcWithCost ),
                InstanceMethod( "Solve", &GSimpleLinearSumAssignment::Solve ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( "SimpleLinearSumAssignment", func );
        return exports;
    };

    Napi::Value AddArcWithCost( const Napi::CallbackInfo& info );  //     ArcIndex AddArcWithCost( NodeIndex left_node, NodeIndex right_node, CostValue cost );
    Napi::Value Solve( const Napi::CallbackInfo& info );           //     Status Solve();

    //     // Returns the current number of left nodes which is the same as the
    //     // number of right nodes. This is one greater than the largest node
    //     // index seen so far in AddArcWithCost().
    //     NodeIndex NumNodes() const;

    //     // Returns the current number of arcs in the graph.
    //     ArcIndex NumArcs() const;

    //     // Returns user-provided data.
    //     // The implementation will crash if "arc" is not in [0, NumArcs()).
    //     NodeIndex LeftNode( ArcIndex arc ) const;
    //     NodeIndex RightNode( ArcIndex arc ) const;
    //     CostValue Cost( ArcIndex arc ) const;

    //     // Returns the cost of an assignment with minimal cost.
    //     // This is 0 if the last Solve() didn't return OPTIMAL.
    //     CostValue OptimalCost() const
    //     {
    //         return optimal_cost_;
    //     }

    //     // Returns the right node assigned to the given left node in the
    //     // last solution computed by Solve(). This works only if Solve()
    //     // returned OPTIMAL.
    //     //
    //     // Note: It is possible that there is more than one optimal
    //     // solution. The algorithm is deterministic so it will always return
    //     // the same solution for a given problem. There is no such guarantee
    //     // from one code version to the next, but the code does not change
    //     // often.
    //     NodeIndex RightMate( NodeIndex left_node ) const
    //     {
    //         return arc_head_[ assignment_arcs_[ left_node ] ];
    //     }

    //     // Returns the cost of the arc used for "left_node"'s assignment.
    //     // This works only if Solve() returned OPTIMAL.
    //     CostValue AssignmentCost( NodeIndex left_node ) const
    //     {
    //         return arc_cost_[ assignment_arcs_[ left_node ] ];
    //     }

    // };
};

Napi::FunctionReference GSimpleLinearSumAssignment::constructor;

GSimpleLinearSumAssignment::GSimpleLinearSumAssignment( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GSimpleLinearSumAssignment >( info )
{
    //     SimpleLinearSumAssignment();
    if ( info.Length() == 0 )
    {
        pSimpleLinearSumAssignment = new SimpleLinearSumAssignment();
        return;
    }

    ThrowJsError( GSimpleLinearSumAssignment::GSimpleLinearSumAssignment : Invalid number of arguments );
}

GSimpleLinearSumAssignment::~GSimpleLinearSumAssignment()
{
    if ( pSimpleLinearSumAssignment != nullptr )
    {
        delete pSimpleLinearSumAssignment;
        pSimpleLinearSumAssignment = nullptr;
    }
}

Napi::Value GSimpleLinearSumAssignment::AddArcWithCost( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 3 )
    {
        if ( info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsNumber() )
        {
            NodeIndex left_node  = info[ 0 ].As< Napi::Number >().Int64Value();
            NodeIndex right_node = info[ 1 ].As< Napi::Number >().Int64Value();
            CostValue cost       = info[ 2 ].As< Napi::Number >().Int64Value();
            ArcIndex  arc        = pSimpleLinearSumAssignment->AddArcWithCost( left_node, right_node, cost );
            return Napi::Number::New( info.Env(), arc );
        }
    }

    ThrowJsError( GSimpleLinearSumAssignment::AddArcWithCost : Invalid number of arguments or invalid argument type );
    return info.Env().Undefined();
}

Napi::Value GSimpleLinearSumAssignment::Solve( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 0 )
    {
        auto status = pSimpleLinearSumAssignment->Solve();
        return Napi::Number::New( info.Env(), status );
    }

    ThrowJsError( GSimpleLinearSumAssignment::Solve : Invalid number of arguments );
    return info.Env().Undefined();
}

}  // namespace operations_research

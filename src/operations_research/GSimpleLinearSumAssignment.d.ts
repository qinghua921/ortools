export namespace SimpleLinearSumAssignment
{
    export enum Status
    {
        OPTIMAL,            // The algorithm found a minimum-cost perfect matching.
        INFEASIBLE,         // The given problem admits no perfect matching.
        POSSIBLE_OVERFLOW,  // Some cost magnitude is too large.
    }
}

export class SimpleLinearSumAssignment
{
    // public:
    //     // The constructor takes no size.
    //     // New node indices will be created lazily by AddArcWithCost().
    //     SimpleLinearSumAssignment();
    constructor();

    //     // Adds an arc from a left node to a right node with a given cost.
    //     // * Node indices must be non-negative (>= 0). For a perfect
    //     //   matching to exist on n nodes, the values taken by "left_node"
    //     //   must cover [0, n), same for "right_node".
    //     // * The arc cost can be any integer, negative, positive or zero.
    //     // * After the method finishes, NumArcs() == the returned ArcIndex + 1.
    //     ArcIndex AddArcWithCost( NodeIndex left_node, NodeIndex right_node,
    //                              CostValue cost );
    AddArcWithCost(left_node: number, right_node: number, cost: number): number;

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

    //     // Solves the problem (finds the perfect matching that minimizes the
    //     // cost) and returns the solver status.
    //     Status Solve();
    Solve(): SimpleLinearSumAssignment.Status;

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
}

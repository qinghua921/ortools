// A simple and efficient min-cost flow interface. This is as fast as
// GenericMinCostFlow<ReverseArcStaticGraph>, which is the fastest, but is uses
// more memory in order to hide the somewhat involved construction of the
// static graph.
//
// TODO(user): If the need arises, extend this interface to support warm start
// and incrementality between solves. Note that this is already supported by the
// GenericMinCostFlow<> interface.
export class SimpleMinCostFlow  
{
    constructor();

    //     // By default, the constructor takes no size. New node indices are created
    //     // lazily by AddArcWithCapacityAndUnitCost() or SetNodeSupply() such that the
    //     // set of valid nodes will always be [0, NumNodes()).
    //     //
    //     // You may pre-reserve the internal data structures with a given expected
    //     // number of nodes and arcs, to potentially gain performance.
    //     explicit SimpleMinCostFlow( NodeIndex reserve_num_nodes = 0,
    //                                 ArcIndex  reserve_num_arcs  = 0 );

    //     // Adds a directed arc from tail to head to the underlying graph with
    //     // a given capacity and cost per unit of flow.
    //     // * Node indices and the capacity must be non-negative (>= 0).
    //     // * The unit cost can take any integer value (even negative).
    //     // * Self-looping and duplicate arcs are supported.
    //     // * After the method finishes, NumArcs() == the returned ArcIndex + 1.
    //     ArcIndex AddArcWithCapacityAndUnitCost( NodeIndex tail, NodeIndex head,
    //                                             FlowQuantity capacity,
    //                                             CostValue    unit_cost );

    //     // Sets the supply of the given node. The node index must be non-negative (>=
    //     // 0). Nodes implicitly created will have a default supply set to 0. A demand
    //     // is modeled as a negative supply.
    //     void SetNodeSupply( NodeIndex node, FlowQuantity supply );

    //     // Solves the problem, and returns the problem status. This function
    //     // requires that the sum of all node supply minus node demand is zero and
    //     // that the graph has enough capacity to send all supplies and serve all
    //     // demands. Otherwise, it will return INFEASIBLE.
    //     Status Solve()
    //     {
    //         return SolveWithPossibleAdjustment( SupplyAdjustment::DONT_ADJUST );
    //     }

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

}

export namespace SimpleMinCostFlow
{
    export enum Status
    {
        NOT_SOLVED,
        OPTIMAL,
        FEASIBLE,
        INFEASIBLE,
        UNBALANCED,
        BAD_RESULT,

        // This is returned when an integer overflow occurred during the algorithm
        // execution.
        //
        // Some details on how to deal with this:
        // - The sum of all incoming/outgoing capacity at each node should not
        //   overflow. TODO(user): this is not always properly checked and probably
        //   deserve a different return status.
        // - Since we scale cost, each arc unit cost times (num_nodes + 1) should
        //   not overflow. We detect that at the beginning of the Solve().
        // - This is however not sufficient as the node potential depends on the
        //   minimum cost of sending 1 unit of flow through the residual graph. If
        //   the maximum arc unit cost is smaller than kint64max / (2 * n ^ 2) then
        //   one shouldn't run into any overflow. But in pratice this bound is quite
        //   loose. So it is possible to try with higher cost, and the algorithm
        //   will detect if an overflow actually happen and return BAD_COST_RANGE,
        //   so we can retry with smaller cost.
        //
        // And two remarks:
        // - Note that the complexity of the algorithm depends on the maximum cost,
        //   so it is usually a good idea to use unit cost that are as small as
        //   possible.
        // - Even if there is no overflow, note that the total cost can easily not
        //   fit on an int64_t since it is the product of the unit cost times the
        //   actual amount of flow sent. This is easy to detect since the final
        //   optimal cost will be set to kint64max. It is also relatively easy to
        //   deal with since we will still have the proper flow on each arc. It is
        //   thus possible to recompute the total cost in double or using
        //   absl::int128 if the need arise.
        BAD_COST_RANGE
    };
}

/**
 * A simple and efficient min-cost flow interface. This is as fast as
 * GenericMinCostFlow<ReverseArcStaticGraph>, which is the fastest, but is uses
 * more memory in order to hide the somewhat involved construction of the
 * static graph.
 *
 * TODO(user): If the need arises, extend this interface to support warm start
 * and incrementality between solves. Note that this is already supported by the
 * GenericMinCostFlow<> interface.
 */
export class SimpleMinCostFlow // : public MinCostFlowBase
{
    // public:
    //     // By default, the constructor takes no size. New node indices are created
    //     // lazily by AddArcWithCapacityAndUnitCost() or SetNodeSupply() such that the
    //     // set of valid nodes will always be [0, NumNodes()).
    //     //
    //     // You may pre-reserve the internal data structures with a given expected
    //     // number of nodes and arcs, to potentially gain performance.
    //     explicit SimpleMinCostFlow( NodeIndex reserve_num_nodes = 0,
    //                                 ArcIndex  reserve_num_arcs  = 0 );
    /**
     * By default, the constructor takes no size. New node indices are created
     * lazily by AddArcWithCapacityAndUnitCost() or SetNodeSupply() such that the
     * set of valid nodes will always be [0, NumNodes()).
     *
     * You may pre-reserve the internal data structures with a given expected
     * number of nodes and arcs, to potentially gain performance.
     *
     * C++ explicit SimpleMinCostFlow( NodeIndex reserve_num_nodes = 0,
     *                                ArcIndex  reserve_num_arcs  = 0 );
     */
    constructor(reserve_num_nodes: number = 0, reserve_num_arcs: number = 0);


    //     // Adds a directed arc from tail to head to the underlying graph with
    //     // a given capacity and cost per unit of flow.
    //     // * Node indices and the capacity must be non-negative (>= 0).
    //     // * The unit cost can take any integer value (even negative).
    //     // * Self-looping and duplicate arcs are supported.
    //     // * After the method finishes, NumArcs() == the returned ArcIndex + 1.
    //     ArcIndex AddArcWithCapacityAndUnitCost( NodeIndex tail, NodeIndex head,
    //                                             FlowQuantity capacity,
    //                                             CostValue    unit_cost );
    /**
     * Adds a directed arc from tail to head to the underlying graph with
     * a given capacity and cost per unit of flow.
     * * Node indices and the capacity must be non-negative (>= 0).
     * * The unit cost can take any integer value (even negative).
     * * Self-looping and duplicate arcs are supported.
     * * After the method finishes, NumArcs() == the returned ArcIndex + 1.
     *
     * C++ ArcIndex AddArcWithCapacityAndUnitCost( NodeIndex tail, NodeIndex head,
     *                                            FlowQuantity capacity,
     *                                            CostValue    unit_cost );
     */
    AddArcWithCapacityAndUnitCost(tail: number, head: number, capacity: number, unit_cost: number): number;


    //     // Sets the supply of the given node. The node index must be non-negative (>=
    //     // 0). Nodes implicitly created will have a default supply set to 0. A demand
    //     // is modeled as a negative supply.
    //     void SetNodeSupply( NodeIndex node, FlowQuantity supply );
    /**
     * Sets the supply of the given node. The node index must be non-negative (>=
     * 0). Nodes implicitly created will have a default supply set to 0. A demand
     * is modeled as a negative supply.
     *
     * C++ void SetNodeSupply( NodeIndex node, FlowQuantity supply );
     */
    SetNodeSupply(node: number, supply: number): void;

    //     // Solves the problem, and returns the problem status. This function
    //     // requires that the sum of all node supply minus node demand is zero and
    //     // that the graph has enough capacity to send all supplies and serve all
    //     // demands. Otherwise, it will return INFEASIBLE.
    //     Status Solve()
    //     {
    //         return SolveWithPossibleAdjustment( SupplyAdjustment::DONT_ADJUST );
    //     }
    /**
     * Solves the problem, and returns the problem status. This function
     * requires that the sum of all node supply minus node demand is zero and
     * that the graph has enough capacity to send all supplies and serve all
     * demands. Otherwise, it will return INFEASIBLE.
     *
     * C++ Status Solve()
     */
    Solve(): number;

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

    //     // Advanced usage. The default is true.
    //     //
    //     // Without cost scaling, the algorithm will return a 1-optimal solution to the
    //     // given problem. The solution will be an optimal solution to a perturbed
    //     // problem where some of the arc unit costs are changed by at most 1.
    //     //
    //     // If the cost are initially integer and we scale them by (num_nodes + 1),
    //     // then we can show that such 1-optimal solution is actually optimal. This
    //     // is what happen by default or when SetPriceScaling(true) is called.
    //     //
    //     // However, if your cost were originally double, you don't really care to
    //     // solve optimally a problem where the weights are approximated in the first
    //     // place. It is better to multiply your double by a scaling_factor (prefer a
    //     // power of 2) so that the maximum rounded arc unit cost is under kint64max /
    //     // (num_nodes + 1) to prevent any overflow. You can then solve without any
    //     // cost scaling. The final result will be the optimal to a problem were the
    //     // unit cost of some arc as been changed by at most 1 / scaling_factor.
    //     void SetPriceScaling( bool value )
    //     {
    //         scale_prices_ = value;
    //     }

};

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
        BAD_COST_RANGE
    };
}
export class SimpleMinCostFlow  
{
    //  public:
    //    explicit SimpleMinCostFlow(NodeIndex reserve_num_nodes = 0, ArcIndex reserve_num_arcs = 0);


    AddArcWithCapacityAndUnitCost(tail: number, head: number, capacity: number, unit_cost: number): number;
    SetNodeSupply(node: number, supply: number): void;

    Solve(): SimpleMinCostFlow.Status;

    //    // Same as Solve(), but does not have the restriction that the supply
    //    // must match the demand or that the graph has enough capacity to serve
    //    // all the demand or use all the supply. This will compute a maximum-flow
    //    // with minimum cost. The value of the maximum-flow will be given by
    //    // MaximumFlow().
    //    Status SolveMaxFlowWithMinCost()
    //    {
    //        return SolveWithPossibleAdjustment(SupplyAdjustment::ADJUST);
    //    }

    OptimalCost(): number;

    //    // Returns the total flow of the minimum-cost flow found by the algorithm
    //    // when the returned Status is OPTIMAL.
    //    FlowQuantity MaximumFlow() const;

    Flow(arc: number): number;

    //    NodeIndex NumNodes() const;
    NumArcs(): number;
    Tail(arc: number): number;
    Head(arc: number): number;
    //    FlowQuantity Capacity(ArcIndex arc) const;
    //    FlowQuantity Supply(NodeIndex node) const;
    UnitCost(arc: number): number;

    //    // Advanced usage. The default is true.
    //    //
    //    // Without cost scaling, the algorithm will return a 1-optimal solution to the
    //    // given problem. The solution will be an optimal solution to a perturbed
    //    // problem where some of the arc unit costs are changed by at most 1.
    //    //
    //    // If the cost are initially integer and we scale them by (num_nodes + 1),
    //    // then we can show that such 1-optimal solution is actually optimal. This
    //    // is what happen by default or when SetPriceScaling(true) is called.
    //    //
    //    // However, if your cost were originally double, you don't really care to
    //    // solve optimally a problem where the weights are approximated in the first
    //    // place. It is better to multiply your double by a scaling_factor (prefer a
    //    // power of 2) so that the maximum rounded arc unit cost is under kint64max /
    //    // (num_nodes + 1) to prevent any overflow. You can then solve without any
    //    // cost scaling. The final result will be the optimal to a problem were the
    //    // unit cost of some arc as been changed by at most 1 / scaling_factor.
    //    void SetPriceScaling(bool value)
    //    {
    //        scale_prices_ = value;
    //    }
};

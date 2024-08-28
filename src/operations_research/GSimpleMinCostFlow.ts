import { ortools } from "../addon";

// A simple and efficient min-cost flow interface. This is as fast as
// GenericMinCostFlow<ReverseArcStaticGraph>, which is the fastest, but is uses
// more memory in order to hide the somewhat involved construction of the
// static graph.
//
// TODO(user): If the need arises, extend this interface to support warm start
// and incrementality between solves. Note that this is already supported by the
// GenericMinCostFlow<> interface.
export interface GSimpleMinCostFlow
{

    // Adds a directed arc from tail to head to the underlying graph with
    // a given capacity and cost per unit of flow.
    // * Node indices and the capacity must be non-negative (>= 0).
    // * The unit cost can take any integer value (even negative).
    // * Self-looping and duplicate arcs are supported.
    // * After the method finishes, NumArcs() == the returned ArcIndex + 1.
    AddArcWithCapacityAndUnitCost(tail: number, head: number, capacity: number, unit_cost: number): number;

    // Sets the supply of the given node. The node index must be non-negative (>=
    // 0). Nodes implicitly created will have a default supply set to 0. A demand
    // is modeled as a negative supply.
    SetNodeSupply(node: number, supply: number): void;

    // Solves the problem, and returns the problem status. This function
    // requires that the sum of all node supply minus node demand is zero and
    // that the graph has enough capacity to send all supplies and serve all
    // demands. Otherwise, it will return INFEASIBLE.
    Solve(): GStatus;

}

export const GSimpleMinCostFlow:
    {
        new(): GSimpleMinCostFlow;
    } = ortools.operations_research.SimpleMinCostFlow;

export enum GStatus
{
    NOT_SOLVED,
    OPTIMAL,
    FEASIBLE,
    INFEASIBLE,
    UNBALANCED,
    BAD_RESULT,
    BAD_COST_RANGE
};
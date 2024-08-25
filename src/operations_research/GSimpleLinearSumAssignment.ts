import { ortools } from "../addon";

export enum Status
{
    OPTIMAL,            // The algorithm found a minimum-cost perfect matching.
    INFEASIBLE,         // The given problem admits no perfect matching.
    POSSIBLE_OVERFLOW,  // Some cost magnitude is too large.
};

export interface SimpleLinearSumAssignment
{
    // Adds an arc from a left node to a right node with a given cost.
    // * Node indices must be non-negative (>= 0). For a perfect
    //   matching to exist on n nodes, the values taken by "left_node"
    //   must cover [0, n), same for "right_node".
    // * The arc cost can be any integer, negative, positive or zero.
    // * After the method finishes, NumArcs() == the returned ArcIndex + 1.
    AddArcWithCost(left_node: number, right_node: number, cost: number): number;

    // Solves the problem (finds the perfect matching that minimizes the
    // cost) and returns the solver status.
    Solve(): Status;
}

export const SimpleLinearSumAssignment:
    {
        // The constructor takes no size.
        // New node indices will be created lazily by AddArcWithCost().
        new(): SimpleLinearSumAssignment;
    } = ortools.operations_research.SimpleLinearSumAssignment;
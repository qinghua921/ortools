export namespace SimpleLinearSumAssignment
{
    export enum Status
    {
        OPTIMAL,           // The algorithm found a minimum-cost perfect matching.
        INFEASIBLE,        // The given problem admits no perfect matching.
        POSSIBLE_OVERFLOW, // Some cost magnitude is too large.
    };
}

export class SimpleLinearSumAssignment
{
    //  public:
    constructor();


    AddArcWithCost(left_node: number, right_node: number, cost: number): number;

    //    // Returns the current number of left nodes which is the same as the
    //    // number of right nodes. This is one greater than the largest node
    //    // index seen so far in AddArcWithCost().
    //    NodeIndex NumNodes() const;

    //    // Returns the current number of arcs in the graph.
    //    ArcIndex NumArcs() const;

    //    // Returns user-provided data.
    //    // The implementation will crash if "arc" is not in [0, NumArcs()).
    //    NodeIndex LeftNode(ArcIndex arc) const;
    //    NodeIndex RightNode(ArcIndex arc) const;
    //    CostValue Cost(ArcIndex arc) const;


    Solve(): SimpleLinearSumAssignment.Status;
    OptimalCost(): number;
    RightMate(left_node: number): number;
    AssignmentCost(left_node: number): number;

};

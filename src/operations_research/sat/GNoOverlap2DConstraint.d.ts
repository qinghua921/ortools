import { IntervalVar } from "./GIntervalVar";

/**
 * Specialized no_overlap2D constraint.
 *
 * This constraint allows adding rectangles to the no_overlap2D
 * constraint incrementally.
 */
export class NoOverlap2DConstraint
{
    // public:
    //  /// Adds a rectangle (parallel to the axis) to the constraint.
    //  void AddRectangle(IntervalVar x_coordinate, IntervalVar y_coordinate);
    AddRectangle(x_coordinate: IntervalVar, y_coordinate: IntervalVar): void;

};
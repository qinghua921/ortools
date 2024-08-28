import { ortools } from "../../addon";

/**
 * A constraint.
 *
 * This class enables you to modify the constraint that was previously added to
 * the model.
 *
 * The constraint must be built using the different \c CpModelBuilder::AddXXX
 * methods.
 */
export interface GConstraint { }

export const GConstraint: {} = ortools.operations_research.sat.Constraint;
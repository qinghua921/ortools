import { ortools } from "../../addon";
import { BoolVar } from "./GBoolVar";
import { Constraint } from "./GConstraint";
import { DoubleLinearExpr } from "./GDoubleLinearExpr";
import { IntVar } from "./GIntVar";
import { LinearExpr } from "./GLinearExpr";
import { TableConstraint } from "./GTableConstraint";

/**
 * Wrapper class around the cp_model proto.
 *
 * This class provides two types of methods:
 *  - NewXXX to create integer, boolean, or interval variables.
 *  - AddXXX to create new constraints and add them to the model.
 */
export interface CpModelBuilder
{
    // Sets the name of the model.
    SetName(name: string): void;

    //     /// Creates an integer variable with the given domain.
    //     IntVar NewIntVar( const Domain& domain );

    // Creates a Boolean variable.
    NewBoolVar(): BoolVar;

    // At most one literal is true. Sum literals <= 1.
    AddAtMostOne(literals: BoolVar[]): Constraint;

    // Adds left == right.
    AddEquality(left: LinearExpr | IntVar | BoolVar | number, right: LinearExpr | IntVar | BoolVar | number): Constraint;

    /**
     * Adds an allowed assignments constraint.
     *
     * An AllowedAssignments constraint is a constraint on an array of variables
     * that forces, when all variables are fixed to a single value, that the
     * corresponding list of values is equal to one of the tuples added to the
     * constraint.
     *
     * It returns a table constraint that allows adding tuples incrementally after
     * construction.
     */
    AddAllowedAssignments(vars: IntVar[]): TableConstraint;

    // Adds a linear maximization objective.
    Maximize(expr: LinearExpr): void;

    // Adds a linear floating point maximization objective.
    // Note that the coefficients will be internally scaled to integer.
    Maximize(expr: DoubleLinearExpr): void;
}

export const CpModelBuilder:
    {
        new(): CpModelBuilder
    } = ortools.operations_research.sat.CpModelBuilder;
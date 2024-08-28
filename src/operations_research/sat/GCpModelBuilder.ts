import { ortools } from "../../addon";
import { GBoolVar } from "./GBoolVar";
import { GConstraint } from "./GConstraint";
import { GCpModelProto } from "./GCpModelProto";
import { GDoubleLinearExpr } from "./GDoubleLinearExpr";
import { GIntVar } from "./GIntVar";
import { GLinearExpr } from "./GLinearExpr";
import { GTableConstraint } from "./GTableConstraint";

/**
 * Wrapper class around the cp_model proto.
 *
 * This class provides two types of methods:
 *  - NewXXX to create integer, boolean, or interval variables.
 *  - AddXXX to create new constraints and add them to the model.
 */
export interface GCpModelBuilder
{
    // Sets the name of the model.
    SetName(name: string): void;

    //     /// Creates an integer variable with the given domain.
    //     IntVar NewIntVar( const Domain& domain );

    // Creates a Boolean variable.
    NewBoolVar(): GBoolVar;

    // At most one literal is true. Sum literals <= 1.
    AddAtMostOne(literals: GBoolVar[]): GConstraint;

    // Adds left == right.
    AddEquality(left: GLinearExpr | GIntVar | GBoolVar | number, right: GLinearExpr | GIntVar | GBoolVar | number): GConstraint;

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
    AddAllowedAssignments(vars: GIntVar[]): GTableConstraint;

    // Adds a linear maximization objective.
    Maximize(expr: GLinearExpr): void;

    // Adds a linear floating point maximization objective.
    // Note that the coefficients will be internally scaled to integer.
    Maximize(expr: GDoubleLinearExpr): void;

    //     const CpModelProto& Build() const
    Build(): GCpModelProto;
}

export const GCpModelBuilder:
    {
        new(): GCpModelBuilder
    } = ortools.operations_research.sat.CpModelBuilder;
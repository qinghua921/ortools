import { CanAsLinearExpr, ortools } from "../../nodeaddon"
import { Domain } from "../Domain"
import { BoolVar } from "./BoolVar"
import { Constraint } from "./Constraint"
import { CpModelProto } from "./CpModelProto"
import { IntVar } from "./IntVar"
import { IntervalVar } from "./IntervalVar"
import { LinearExpr } from "./LinearExpr"
import { TableConstraint } from "./TableConstraint"


/**
 * Wrapper class around the cp_model proto.
 *
 * This class provides two types of methods:
 *  - NewXXX to create integer, boolean, or interval variables.
 *  - AddXXX to create new constraints and add them to the model.
 */
export interface CpModelBuilder
{
    /** 
     * Creates an interval variable from 3 affine expressions.
     */
    NewIntervalVar(start: CanAsLinearExpr, size: CanAsLinearExpr, end: CanAsLinearExpr): IntervalVar

    /**  
     * Creates an optional interval variable from 3 affine expressions and a Boolean variable.
     */
    NewOptionalIntervalVar(start: CanAsLinearExpr, size: CanAsLinearExpr, end: CanAsLinearExpr, presence: BoolVar): IntervalVar

    /**
     * Creates an optional interval variable with a fixed size.
     */
    NewOptionalFixedSizeIntervalVar(start: CanAsLinearExpr, size: number, presence: BoolVar): IntervalVar

    /**  
     * 创建整型变量 
     */
    NewIntVar(domain: Domain): IntVar

    /**
     * Creates an interval variable with a fixed size.
     */
    NewFixedSizeIntervalVar(start: CanAsLinearExpr, size: number): IntervalVar

    /** 
     * 创建 Bool 变量 
     */
    NewBoolVar(): BoolVar

    /**  
     * Adds left == right. 
     */
    AddEquality(left: CanAsLinearExpr, right: CanAsLinearExpr): Constraint

    /**  
     * 约束 left <= right. 
     */
    AddLessOrEqual(left: CanAsLinearExpr, right: CanAsLinearExpr): Constraint

    /**  
     * 约束 left < right. 
     */
    AddLessThan(left: CanAsLinearExpr, right: CanAsLinearExpr): Constraint

    /**  
     * Adds target == max(vars). 
     */
    AddMaxEquality(target: LinearExpr | IntVar, vars: IntVar[] | LinearExpr[]): Constraint

    /**  
     * Adds target == min(vars). 
     */
    AddMinEquality(target: LinearExpr | IntVar, vars: IntVar[] | LinearExpr[]): Constraint

    /**  
     * Adds expr in domain. 
     */
    AddLinearConstraint(target: LinearExpr | IntVar, domain: Domain): Constraint

    /**
     * Adds a no-overlap constraint that ensures that all present intervals do
     * not overlap in time.
     */
    AddNoOverlap(vars: IntervalVar[]): Constraint

    /**  
     * Adds a => b. 
     */
    AddImplication(a: BoolVar, b: BoolVar): Constraint

    /** Adds target = var % mod. */
    AddModuloEquality(target: CanAsLinearExpr, ver: CanAsLinearExpr, mod: CanAsLinearExpr): Constraint

    /** Adds target = numerator / denominator (integer division rounded towards 0). */
    AddDivisionEquality(target: CanAsLinearExpr, numerator: CanAsLinearExpr, denominator: CanAsLinearExpr): Constraint

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
    AddAllowedAssignments(vars: IntVar[]): TableConstraint

    /**  
     * 创建线性最大目标 
     */
    Maximize(linearExpr: LinearExpr | IntVar): void

    /**  
     * 创建线性最小目标 
     */
    Minimize(linearExpr: LinearExpr | IntVar): void


    Build(): CpModelProto
}

export const CpModelBuilder:
    {
        new(): CpModelBuilder
    } = ortools.operations_research.sat.CpModelBuilder

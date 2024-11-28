import { LinearExpr } from "./LinearExpr";
import { BoolVar } from "./BoolVar";
import { CpModelProto } from "./CpModelProto";
import { CpSolverResponse } from "./CpSolverResponse";

export function operator_times(expr: LinearExpr, factor: number): LinearExpr;
export function operator_times(expr: BoolVar, factor: number): LinearExpr;
export function Solve(model_proto: CpModelProto): CpSolverResponse;
export function SolutionBooleanValue(r: CpSolverResponse, x: BoolVar): boolean;

export enum CpSolverStatus 
{
    UNKNOWN = 0,
    MODEL_INVALID = 1,
    FEASIBLE = 2,
    INFEASIBLE = 3,
    OPTIMAL = 4,
};
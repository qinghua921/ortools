import { LinearExpr } from "./LinearExpr";
import { BoolVar } from "./BoolVar";
import { CpModelProto } from "./CpModelProto";
import { CpSolverResponse } from "./CpSolverResponse";
import { SatParameters } from "./SatParameters";

export function operator_times(expr: LinearExpr, factor: number): LinearExpr;
export function operator_times(expr: BoolVar, factor: number): LinearExpr;
export function operator_times(factor: number, expr: BoolVar): LinearExpr;
export function Solve(model_proto: CpModelProto): CpSolverResponse;
export function SolutionBooleanValue(r: CpSolverResponse, x: BoolVar): boolean;
export function CpSolverResponseStats(response: CpSolverResponse, has_objective: boolean = true): string;
export function SolveWithParameters(model_proto: CpModelProto, params: SatParameters): CpSolverResponse;

export enum CpSolverStatus 
{
    UNKNOWN = 0,
    MODEL_INVALID = 1,
    FEASIBLE = 2,
    INFEASIBLE = 3,
    OPTIMAL = 4,
};
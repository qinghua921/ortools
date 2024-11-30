import { CanAsLinearExpr, LinearExpr } from "./LinearExpr";


export function operator_ge(lhs: CanAsLinearExpr, rhs: CanAsLinearExpr): LinearExpr;
export function operator_le(lhs: CanAsLinearExpr, rhs: CanAsLinearExpr): LinearExpr;
export function operator_eq(lhs: CanAsLinearExpr, rhs: CanAsLinearExpr): LinearExpr;
export function operator_times(lhs: CanAsLinearExpr, rhs: number): LinearExpr;
export function operator_times(lhs: number, rhs: CanAsLinearExpr): LinearExpr;

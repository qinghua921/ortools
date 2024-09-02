import { LinearExpr } from "./GLinearExpr";
import { LinearRange } from "./GLinearRange";
import { MPVariable } from "./GMPVariable";

// LinearRange operator<=( const LinearExpr& lhs, const LinearExpr& rhs );
export function operator_less_equals(lhs: LinearExpr | number | MPVariable, rhs: LinearExpr | number | MPVariable): LinearRange;
// LinearRange operator==( const LinearExpr& lhs, const LinearExpr& rhs );
export function operator_equals(lhs: LinearExpr | number | MPVariable, rhs: LinearExpr | number | MPVariable): LinearRange;
// LinearRange operator>=( const LinearExpr& lhs, const LinearExpr& rhs );
export function operator_greater_equals(lhs: LinearExpr | number | MPVariable, rhs: LinearExpr | number | MPVariable): LinearRange;

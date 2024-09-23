import { CanAsLinearExpr, LinearExpr } from "./LinearExpr";

//LinearRange operator<=( const LinearExpr& lhs, const LinearExpr& rhs );
export function operator_le(lhs: LinearExpr, rhs: LinearExpr): LinearRange;

//LinearRange operator==( const LinearExpr& lhs, const LinearExpr& rhs );
export function operator_eq(lhs: LinearExpr, rhs: LinearExpr): LinearRange;

//LinearRange operator>=( const LinearExpr& lhs, const LinearExpr& rhs );
export function operator_ge(lhs: LinearExpr, rhs: LinearExpr): LinearRange;


// NOTE(user): in the ops below, the non-"const LinearExpr&" are intentional.
// We need to create a new LinearExpr for the result, so we lose nothing by
// passing one argument by value, mutating it, and then returning it. In
// particular, this allows (with move semantics and RVO) an optimized
// evaluation of expressions such as
// a + b + c + d
// (see http://en.cppreference.com/w/cpp/language/operators).
//LinearExpr operator+( LinearExpr lhs, const LinearExpr& rhs );
//LinearExpr operator-( LinearExpr lhs, const LinearExpr& rhs );

//LinearExpr operator*( LinearExpr lhs, double rhs );
export function operator_times(lhs: CanAsLinearExpr, rhs: number): LinearExpr;

//LinearExpr operator*( double lhs, LinearExpr rhs );
export function operator_times(lhs: number, rhs: CanAsLinearExpr): LinearExpr;

//LinearExpr operator/( LinearExpr lhs, double rhs );

import { LinearExpr } from "./GLinearExpr";
import { LinearRange } from "./GLinearRange";
import { MPVariable } from "./GMPVariable";

// LinearRange operator<=( const LinearExpr& lhs, const LinearExpr& rhs );
export function operator_less_equals(lhs: CanAsLinearExpr, rhs: CanAsLinearExpr): LinearRange;
// LinearRange operator==( const LinearExpr& lhs, const LinearExpr& rhs );
export function operator_equals(lhs: CanAsLinearExpr, rhs: CanAsLinearExpr): LinearRange;
// LinearRange operator>=( const LinearExpr& lhs, const LinearExpr& rhs );
export function operator_greater_equals(lhs: CanAsLinearExpr, rhs: CanAsLinearExpr): LinearRange;


// NOTE(user): in the ops below, the non-"const LinearExpr&" are intentional.
// We need to create a new LinearExpr for the result, so we lose nothing by
// passing one argument by value, mutating it, and then returning it. In
// particular, this allows (with move semantics and RVO) an optimized
// evaluation of expressions such as
// a + b + c + d
// (see http://en.cppreference.com/w/cpp/language/operators).
// LinearExpr operator+(LinearExpr lhs, const LinearExpr& rhs);
export function operator_plus(lhs: CanAsLinearExpr, rhs: CanAsLinearExpr): LinearExpr;
// LinearExpr operator-(LinearExpr lhs, const LinearExpr& rhs);
export function operator_minus(lhs: CanAsLinearExpr, rhs: CanAsLinearExpr): LinearExpr;
// LinearExpr operator*(LinearExpr lhs, double rhs);
// LinearExpr operator*(double lhs, LinearExpr rhs);
export function operator_times(lhs: CanAsLinearExpr, rhs: number): LinearExpr;
export function operator_times(lhs: number, rhs: CanAsLinearExpr): LinearExpr;
// LinearExpr operator/(LinearExpr lhs, double rhs);
export function operator_divide(lhs: LinearExpr, rhs: number): LinearExpr;


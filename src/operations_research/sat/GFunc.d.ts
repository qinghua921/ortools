import { CpModelProto } from './GCpModelProto';
import { CpSolverResponse } from './GCpSolverResponse';
import { CanAsLinearExpr, LinearExpr } from './GLinearExpr';

// inline LinearExpr operator-( LinearExpr expr )
export function operator_negate(expr: CanAsLinearExpr): LinearExpr;

// inline LinearExpr operator+( LinearExpr&& lhs, const LinearExpr& rhs )
// inline LinearExpr operator+( const LinearExpr& lhs, LinearExpr&& rhs )
// inline LinearExpr operator+( LinearExpr&& lhs, LinearExpr&& rhs )
// inline LinearExpr operator+( const LinearExpr& lhs, const LinearExpr& rhs )
export function operator_plus(lhs: CanAsLinearExpr, rhs: CanAsLinearExpr): LinearExpr;

// inline LinearExpr operator-( const LinearExpr& lhs, const LinearExpr& rhs )
// inline LinearExpr operator-( LinearExpr&& lhs, const LinearExpr& rhs )
// inline LinearExpr operator-( const LinearExpr& lhs, LinearExpr&& rhs )
// inline LinearExpr operator-( LinearExpr&& lhs, LinearExpr&& rhs )
export function operator_minus(lhs: CanAsLinearExpr, rhs: CanAsLinearExpr): LinearExpr;

// inline LinearExpr operator*( LinearExpr expr, int64_t factor )
export function operator_times(expr: CanAsLinearExpr, factor: number): LinearExpr;

// inline LinearExpr operator*( int64_t factor, LinearExpr expr )
export function operator_times(factor: number, expr: CanAsLinearExpr): LinearExpr;

/// Solves the given CpModelProto and returns an instance of CpSolverResponse.
// CpSolverResponse Solve( const CpModelProto& model_proto );
export function Solve(model_proto: CpModelProto): CpSolverResponse;

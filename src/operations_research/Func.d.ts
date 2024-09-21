
//LinearRange operator<=( const LinearExpr& lhs, const LinearExpr& rhs );
export function operator_le(lhs: LinearExpr, rhs: LinearExpr): LinearRange;

//LinearRange operator==( const LinearExpr& lhs, const LinearExpr& rhs );
export function operator_eq(lhs: LinearExpr, rhs: LinearExpr): LinearRange;

//LinearRange operator>=( const LinearExpr& lhs, const LinearExpr& rhs );
export function operator_ge(lhs: LinearExpr, rhs: LinearExpr): LinearRange;

declare namespace operations_research
{
    //LinearRange operator<=( const LinearExpr& lhs, const LinearExpr& rhs );
    declare function operator_le(lhs: CanAsLinearExpr, rhs: CanAsLinearExpr): LinearRange;
    //LinearRange operator==( const LinearExpr& lhs, const LinearExpr& rhs );
    declare function operator_eq(lhs: CanAsLinearExpr, rhs: CanAsLinearExpr): LinearRange;
    //LinearRange operator>=( const LinearExpr& lhs, const LinearExpr& rhs );
    declare function operator_ge(lhs: CanAsLinearExpr, rhs: CanAsLinearExpr): LinearRange;
}
declare namespace operations_research
{

    //LinearRange operator <= ( const LinearExpr& lhs, const LinearExpr& rhs );
    declare function operator_less_equals(lhs: CanAsLinearExpr, rhs: CanAsLinearExpr): LinearRange;
    //LinearRange operator == ( const LinearExpr& lhs, const LinearExpr& rhs );
    declare function operator_equals(lhs: CanAsLinearExpr, rhs: CanAsLinearExpr): LinearRange;
    //LinearRange operator >= ( const LinearExpr& lhs, const LinearExpr& rhs );

}
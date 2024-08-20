import { ortools } from "../nodeaddon"
import { LinearExpr } from "./LinearExpr"
import { LinearRange } from "./LinearRange"


// LinearRange operator<=( const LinearExpr& lhs, const LinearExpr& rhs );
export const operator_LEQ: (lhs: LinearExpr | number, rhs: LinearExpr | number) => LinearRange
    = ortools.operations_research.operator_LEQ

// LinearRange operator==( const LinearExpr& lhs, const LinearExpr& rhs );
export const operator_EQ: (lhs: LinearExpr | number, rhs: LinearExpr | number) => LinearRange
    = ortools.operations_research.operator_EQ

// LinearRange operator>=( const LinearExpr& lhs, const LinearExpr& rhs );
export const operator_GEQ: (lhs: LinearExpr | number, rhs: LinearExpr | number) => LinearRange
    = ortools.operations_research.operator_GEQ

import { ortools } from "../nodeaddon"
import { LinearExpr } from "./LinearExpr"
import { LinearRange } from "./LinearRange"
import { MPVariable } from "./MPVariable"


// LinearRange operator<=( const LinearExpr& lhs, const LinearExpr& rhs );
const operator_LEQ_: (lhs: LinearExpr, rhs: LinearExpr) => LinearRange
    = ortools.operations_research.operator_LEQ

export function operator_LEQ(lhs: LinearExpr | number | MPVariable, rhs: LinearExpr | number | MPVariable)
{
    return operator_LEQ_(new LinearExpr(lhs), new LinearExpr(rhs))
}

// LinearRange operator==( const LinearExpr& lhs, const LinearExpr& rhs );
export const operator_EQ: (lhs: LinearExpr | number | MPVariable, rhs: LinearExpr | number | MPVariable) => LinearRange
    = ortools.operations_research.operator_EQ

// LinearRange operator>=( const LinearExpr& lhs, const LinearExpr& rhs );
export const operator_GEQ: (lhs: LinearExpr | number | MPVariable, rhs: LinearExpr | number | MPVariable) => LinearRange
    = ortools.operations_research.operator_GEQ

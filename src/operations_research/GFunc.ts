import { ortools } from "../addon"
import { LinearExpr } from "./GLinearExpr"
import { LinearRange } from "./GLinearRange"
import { MPVariable } from "./GMPVariable"


// LinearRange operator<=( const LinearExpr& lhs, const LinearExpr& rhs );
export const operator_LEQ: (lhs: LinearExpr | number | MPVariable, rhs: LinearExpr | number | MPVariable) => LinearRange
    = ortools.operations_research.operator_LEQ


// LinearRange operator==( const LinearExpr& lhs, const LinearExpr& rhs ); 
export const operator_EQ: (lhs: LinearExpr | number | MPVariable, rhs: LinearExpr | number | MPVariable) => LinearRange
    = ortools.operations_research.operator_EQ


// LinearRange operator>=( const LinearExpr& lhs, const LinearExpr& rhs );
export const operator_GEQ: (lhs: LinearExpr | number | MPVariable, rhs: LinearExpr | number | MPVariable) => LinearRange
    = ortools.operations_research.operator_GEQ

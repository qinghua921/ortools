import { ortools } from "../addon"
import { GLinearExpr } from "./GLinearExpr"
import { GLinearRange } from "./GLinearRange"
import { GMPVariable } from "./GMPVariable"


// LinearRange operator<=( const LinearExpr& lhs, const LinearExpr& rhs );
export const Goperator_LEQ: (lhs: GLinearExpr | number | GMPVariable, rhs: GLinearExpr | number | GMPVariable) => GLinearRange
    = ortools.operations_research.operator_LEQ


// LinearRange operator==( const LinearExpr& lhs, const LinearExpr& rhs ); 
export const Goperator_EQ: (lhs: GLinearExpr | number | GMPVariable, rhs: GLinearExpr | number | GMPVariable) => GLinearRange
    = ortools.operations_research.operator_EQ


// LinearRange operator>=( const LinearExpr& lhs, const LinearExpr& rhs );
export const Goperator_GEQ: (lhs: GLinearExpr | number | GMPVariable, rhs: GLinearExpr | number | GMPVariable) => GLinearRange
    = ortools.operations_research.operator_GEQ

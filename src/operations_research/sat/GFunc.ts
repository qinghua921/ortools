import { ortools } from "../../addon";
import { BoolVar } from "./GBoolVar";
import { DoubleLinearExpr } from "./GDoubleLinearExpr";
import { LinearExpr } from "./GLinearExpr";


export const operator_neg:
    // inline LinearExpr operator-( LinearExpr expr )
    ((expr: LinearExpr) => LinearExpr)
    // inline DoubleLinearExpr operator-( DoubleLinearExpr expr )
    & ((expr: DoubleLinearExpr) => DoubleLinearExpr)
    = ortools.operations_research.sat.operator_neg

export const operator_plus:
    // inline LinearExpr operator+( const LinearExpr& lhs, const LinearExpr& rhs )
    ((lhs: LinearExpr, rhs: LinearExpr) => LinearExpr)
    // inline DoubleLinearExpr operator+( const DoubleLinearExpr& lhs, const DoubleLinearExpr& rhs )
    & ((lhs: DoubleLinearExpr, rhs: DoubleLinearExpr) => DoubleLinearExpr)
    // inline DoubleLinearExpr operator+( DoubleLinearExpr expr, double rhs )
    & ((expr: DoubleLinearExpr, rhs: number) => DoubleLinearExpr)
    // inline DoubleLinearExpr operator+( double lhs, DoubleLinearExpr expr )
    & ((lhs: number, expr: DoubleLinearExpr) => DoubleLinearExpr)
    = ortools.operations_research.sat.operator_plus

export const operator_minus:
    // inline LinearExpr operator-( const LinearExpr& lhs, const LinearExpr& rhs )
    ((lhs: LinearExpr, rhs: LinearExpr) => LinearExpr)
    // inline DoubleLinearExpr operator-( const DoubleLinearExpr& lhs, const DoubleLinearExpr& rhs )
    & ((lhs: DoubleLinearExpr, rhs: DoubleLinearExpr) => DoubleLinearExpr)
    // inline DoubleLinearExpr operator-( DoubleLinearExpr epxr, double rhs )
    & ((expr: DoubleLinearExpr, rhs: number) => DoubleLinearExpr)
    // inline DoubleLinearExpr operator-( double lhs, DoubleLinearExpr expr )
    & ((lhs: number, expr: DoubleLinearExpr) => DoubleLinearExpr)
    = ortools.operations_research.sat.operator_minus



export const operator_times:
    // inline LinearExpr operator*( LinearExpr expr, int64_t factor )
    ((expr: LinearExpr | BoolVar, factor: number) => LinearExpr)
    // inline LinearExpr operator*( int64_t factor, LinearExpr expr )
    & ((factor: number, expr: LinearExpr) => LinearExpr)
    // inline DoubleLinearExpr operator*( DoubleLinearExpr expr, double factor )
    & ((expr: DoubleLinearExpr, factor: number) => DoubleLinearExpr)
    // inline DoubleLinearExpr operator*( double factor, DoubleLinearExpr expr )
    & ((factor: number, expr: DoubleLinearExpr) => DoubleLinearExpr)
    = ortools.operations_research.sat.operator_times

// Solves the given CpModelProto and returns an instance of CpSolverResponse.
export const Solve: (model_proto: CpModelProto) => CpSolverResponse
    = ortools.operations_research.sat.Solve
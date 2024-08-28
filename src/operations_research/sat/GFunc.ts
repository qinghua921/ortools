import { ortools } from "../../addon";
import { GBoolVar } from "./GBoolVar";
import { GCpModelProto } from "./GCpModelProto";
import { GCpSolverResponse } from "./GCpSolverResponse";
import { GDoubleLinearExpr } from "./GDoubleLinearExpr";
import { GLinearExpr } from "./GLinearExpr";


export const Goperator_neg:
    // inline LinearExpr operator-( LinearExpr expr )
    ((expr: GLinearExpr) => GLinearExpr)
    // inline DoubleLinearExpr operator-( DoubleLinearExpr expr )
    & ((expr: GDoubleLinearExpr) => GDoubleLinearExpr)
    = ortools.operations_research.sat.operator_neg

export const Goperator_plus:
    // inline LinearExpr operator+( const LinearExpr& lhs, const LinearExpr& rhs )
    ((lhs: GLinearExpr, rhs: GLinearExpr) => GLinearExpr)
    // inline DoubleLinearExpr operator+( const DoubleLinearExpr& lhs, const DoubleLinearExpr& rhs )
    & ((lhs: GDoubleLinearExpr, rhs: GDoubleLinearExpr) => GDoubleLinearExpr)
    // inline DoubleLinearExpr operator+( DoubleLinearExpr expr, double rhs )
    & ((expr: GDoubleLinearExpr, rhs: number) => GDoubleLinearExpr)
    // inline DoubleLinearExpr operator+( double lhs, DoubleLinearExpr expr )
    & ((lhs: number, expr: GDoubleLinearExpr) => GDoubleLinearExpr)
    = ortools.operations_research.sat.operator_plus

export const Goperator_minus:
    // inline LinearExpr operator-( const LinearExpr& lhs, const LinearExpr& rhs )
    ((lhs: GLinearExpr, rhs: GLinearExpr) => GLinearExpr)
    // inline DoubleLinearExpr operator-( const DoubleLinearExpr& lhs, const DoubleLinearExpr& rhs )
    & ((lhs: GDoubleLinearExpr, rhs: GDoubleLinearExpr) => GDoubleLinearExpr)
    // inline DoubleLinearExpr operator-( DoubleLinearExpr epxr, double rhs )
    & ((expr: GDoubleLinearExpr, rhs: number) => GDoubleLinearExpr)
    // inline DoubleLinearExpr operator-( double lhs, DoubleLinearExpr expr )
    & ((lhs: number, expr: GDoubleLinearExpr) => GDoubleLinearExpr)
    = ortools.operations_research.sat.operator_minus



export const Goperator_times:
    // inline LinearExpr operator*( LinearExpr expr, int64_t factor )
    ((expr: GLinearExpr | GBoolVar, factor: number) => GLinearExpr)
    // inline LinearExpr operator*( int64_t factor, LinearExpr expr )
    & ((factor: number, expr: GLinearExpr) => GLinearExpr)
    // inline DoubleLinearExpr operator*( DoubleLinearExpr expr, double factor )
    & ((expr: GDoubleLinearExpr, factor: number) => GDoubleLinearExpr)
    // inline DoubleLinearExpr operator*( double factor, DoubleLinearExpr expr )
    & ((factor: number, expr: GDoubleLinearExpr) => GDoubleLinearExpr)
    = ortools.operations_research.sat.operator_times

// Solves the given CpModelProto and returns an instance of CpSolverResponse.
export const Solve: (model_proto: GCpModelProto) => GCpSolverResponse
    = ortools.operations_research.sat.Solve
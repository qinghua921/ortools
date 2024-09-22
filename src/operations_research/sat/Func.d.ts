import { CpSolverResponse } from "./CpSolverResponse";
import { CanAsLinearExpr, LinearExpr } from "./LinearExpr";

/// Solves the given CpModelProto and returns an instance of CpSolverResponse.
//CpSolverResponse Solve( const CpModelProto& model_proto );
/**
 * Solves the given CpModelProto and returns an instance of CpSolverResponse.
 * 
 * C++ CpSolverResponse Solve( const CpModelProto& model_proto );
 */
export function GSolve(model_proto: CpModelProto): CpSolverResponse;

//inline LinearExpr operator-( LinearExpr expr )
//{
//    return expr *= -1;
//}

//inline LinearExpr operator+( const LinearExpr& lhs, const LinearExpr& rhs )
//{
//    LinearExpr temp( lhs );
//    temp += rhs;
//    return temp;
//}
//inline LinearExpr operator+( LinearExpr&& lhs, const LinearExpr& rhs )
//{
//    lhs += rhs;
//    return std::move( lhs );
//}
//inline LinearExpr operator+( const LinearExpr& lhs, LinearExpr&& rhs )
//{
//    rhs += lhs;
//    return std::move( rhs );
//}
//inline LinearExpr operator+( LinearExpr&& lhs, LinearExpr&& rhs )
//{
//    if ( lhs.variables().size() < rhs.variables().size() )
//    {
//        rhs += std::move( lhs );
//        return std::move( rhs );
//    }
//    else
//    {
//        lhs += std::move( rhs );
//        return std::move( lhs );
//    }
//}

//inline LinearExpr operator-( const LinearExpr& lhs, const LinearExpr& rhs )
//{
//    LinearExpr temp( lhs );
//    temp -= rhs;
//    return temp;
//}
//inline LinearExpr operator-( LinearExpr&& lhs, const LinearExpr& rhs )
//{
//    lhs -= rhs;
//    return std::move( lhs );
//}
//inline LinearExpr operator-( const LinearExpr& lhs, LinearExpr&& rhs )
//{
//    rhs *= -1;
//    rhs += lhs;
//    return std::move( rhs );
//}
//inline LinearExpr operator-( LinearExpr&& lhs, LinearExpr&& rhs )
//{
//    lhs -= std::move( rhs );
//    return std::move( lhs );
//}

//inline LinearExpr operator*( LinearExpr expr, int64_t factor )
export function Goperator_times(expr: CanAsLinearExpr, factor: number): LinearExpr;

//inline LinearExpr operator*( int64_t factor, LinearExpr expr )
//{
//    expr *= factor;
//    return expr;
//}

//// For DoubleLinearExpr.

//inline DoubleLinearExpr operator-( DoubleLinearExpr expr )
//{
//    expr *= -1;
//    return expr;
//}

//inline DoubleLinearExpr operator+( const DoubleLinearExpr& lhs,
//                                   const DoubleLinearExpr& rhs )
//{
//    DoubleLinearExpr temp( lhs );
//    temp += rhs;
//    return temp;
//}
//inline DoubleLinearExpr operator+( DoubleLinearExpr&&      lhs,
//                                   const DoubleLinearExpr& rhs )
//{
//    lhs += rhs;
//    return std::move( lhs );
//}
//inline DoubleLinearExpr operator+( const DoubleLinearExpr& lhs,
//                                   DoubleLinearExpr&&      rhs )
//{
//    rhs += lhs;
//    return std::move( rhs );
//}
//inline DoubleLinearExpr operator+( DoubleLinearExpr&& lhs,
//                                   DoubleLinearExpr&& rhs )
//{
//    if ( lhs.variables().size() < rhs.variables().size() )
//    {
//        rhs += std::move( lhs );
//        return std::move( rhs );
//    }
//    else
//    {
//        lhs += std::move( rhs );
//        return std::move( lhs );
//    }
//}

//inline DoubleLinearExpr operator+( DoubleLinearExpr expr, double rhs )
//{
//    expr += rhs;
//    return expr;
//}
//inline DoubleLinearExpr operator+( double lhs, DoubleLinearExpr expr )
//{
//    expr += lhs;
//    return expr;
//}

//inline DoubleLinearExpr operator-( const DoubleLinearExpr& lhs,
//                                   const DoubleLinearExpr& rhs )
//{
//    DoubleLinearExpr temp( lhs );
//    temp -= rhs;
//    return temp;
//}
//inline DoubleLinearExpr operator-( DoubleLinearExpr&&      lhs,
//                                   const DoubleLinearExpr& rhs )
//{
//    lhs -= rhs;
//    return std::move( lhs );
//}
//inline DoubleLinearExpr operator-( const DoubleLinearExpr& lhs,
//                                   DoubleLinearExpr&&      rhs )
//{
//    rhs *= -1;
//    rhs += lhs;
//    return std::move( rhs );
//}
//inline DoubleLinearExpr operator-( DoubleLinearExpr&& lhs,
//                                   DoubleLinearExpr&& rhs )
//{
//    lhs -= std::move( rhs );
//    return std::move( lhs );
//}

//inline DoubleLinearExpr operator-( DoubleLinearExpr epxr, double rhs )
//{
//    epxr -= rhs;
//    return epxr;
//}
//inline DoubleLinearExpr operator-( double lhs, DoubleLinearExpr expr )
//{
//    expr *= -1;
//    expr += lhs;
//    return expr;
//}

//inline DoubleLinearExpr operator*( DoubleLinearExpr expr, double factor )
//{
//    expr *= factor;
//    return expr;
//}

//inline DoubleLinearExpr operator*( double factor, DoubleLinearExpr expr )
//{
//    expr *= factor;
//    return expr;
//}

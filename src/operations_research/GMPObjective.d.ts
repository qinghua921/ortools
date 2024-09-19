export namespace operations_research
{
    export class MPObjective
    {
        // public:
        // #ifndef SWIG
        //     MPObjective( const MPObjective& )            = delete;
        //     MPObjective& operator=( const MPObjective& ) = delete;
        // #endif
        //     void                                                    Clear();
        //     void                                                    SetCoefficient( const MPVariable* var, double coeff );
        //     double                                                  GetCoefficient( const MPVariable* var ) const;
        //     const absl::flat_hash_map< const MPVariable*, double >& terms() const;
        //     void                                                    SetOffset( double value );
        //     double                                                  offset() const;
        //     void                                                    OptimizeLinearExpr( const LinearExpr& linear_expr, bool is_maximization );
        //     void                                                    MaximizeLinearExpr( const LinearExpr& linear_expr );
        //     void                                                    MinimizeLinearExpr( const LinearExpr& linear_expr );
        //     void                                                    AddLinearExpr( const LinearExpr& linear_expr );
        //     void                                                    SetOptimizationDirection( bool maximize );
        //     void                                                    SetMinimization();
        //     void                                                    SetMaximization();
        //     bool                                                    maximization() const;
        //     bool                                                    minimization() const;
        //     double                                                  Value() const;
        //     double                                                  BestBound() const;

        // private:
        //     friend class MPSolver;
        //     friend class MPSolverInterface;
        //     friend class CBCInterface;
        //     friend class CLPInterface;
        //     friend class GLPKInterface;
        //     friend class SCIPInterface;
        //     friend class SLMInterface;
        //     friend class GurobiInterface;
        //     friend class CplexInterface;
        //     friend class XpressInterface;
        //     friend class GLOPInterface;
        //     friend class BopInterface;
        //     friend class SatInterface;
        //     friend class PdlpInterface;
        //     friend class HighsInterface;
        //     friend class KnapsackInterface;
        //     explicit MPObjective( MPSolverInterface* const interface_in )
        //         : interface_( interface_in ), coefficients_( 1 ), offset_( 0.0 );
        //     MPSolverInterface* const                         interface_;
        //     absl::flat_hash_map< const MPVariable*, double > coefficients_;
        //     double                                           offset_;
    };

}
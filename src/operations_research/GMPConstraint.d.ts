export namespace operations_research
{
    export class MPConstraint
    {
        // public:
        // #ifndef SWIG
        //     MPConstraint( const MPConstraint& )            = delete;
        //     MPConstraint& operator=( const MPConstraint& ) = delete;
        // #endif
        //     const std::string&                                      name() const;
        //     void                                                    Clear();
        //     void                                                    SetCoefficient( const MPVariable* var, double coeff );
        //     double                                                  GetCoefficient( const MPVariable* var ) const;
        //     const absl::flat_hash_map< const MPVariable*, double >& terms() const;
        //     double                                                  lb() const;
        //     double                                                  ub() const;
        //     void                                                    SetLB( double lb );
        //     void                                                    SetUB( double ub );
        //     void                                                    SetBounds( double lb, double ub );
        //     bool                                                    is_lazy() const;
        //     void                                                    set_is_lazy( bool laziness );
        //     const MPVariable*                                       indicator_variable() const;
        //     bool                                                    indicator_value() const;
        //     int                                                     index() const;
        //     double                                                  dual_value() const;
        //     MPSolver::BasisStatus                                   basis_status() const;

        // protected:
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
        //     MPConstraint( int index, double lb, double ub, const std::string& name, MPSolverInterface* const interface_in )
        //         : coefficients_( 1 ), index_( index ), lb_( lb ), ub_( ub ), name_( name.empty() ? absl::StrFormat( "auto_c_%09d", index ) : name ), is_lazy_( false ), indicator_variable_( nullptr ), dual_value_( 0.0 ), interface_( interface_in );
        //     void set_dual_value( double dual_value );

        // private:
        //     bool                                             ContainsNewVariables();
        //     absl::flat_hash_map< const MPVariable*, double > coefficients_;
        //     const int                                        index_;
        //     double                                           lb_;
        //     double                                           ub_;
        //     const std::string                                name_;
        //     bool                                             is_lazy_;
        //     const MPVariable*                                indicator_variable_;
        //     bool                                             indicator_value_;
        //     double                                           dual_value_;
        //     MPSolverInterface* const                         interface_;
    };

}
declare namespace operations_research
{
    /**
     * The class for variables of a Mathematical Programming (MP) model.
     */
    declare class MPVariable
    {
        // public:
        //     /// Returns the name of the variable.
        //     const std::string& name() const
        //     {
        //         return name_;
        //     }

        //     /// Sets the integrality requirement of the variable.
        //     void SetInteger( bool integer );

        //     /// Returns the integrality requirement of the variable.
        //     bool integer() const
        //     {
        //         return integer_;
        //     }

        //     /**
        //      * Returns the value of the variable in the current solution.
        //      *
        //      * If the variable is integer, then the value will always be an integer (the
        //      * underlying solver handles floating-point values only, but this function
        //      * automatically rounds it to the nearest integer; see: man 3 round).
        //      */
        //     double solution_value() const;

        //     /// Returns the index of the variable in the MPSolver::variables_.
        //     int index() const
        //     {
        //         return index_;
        //     }

        //     /// Returns the lower bound.
        //     double lb() const
        //     {
        //         return lb_;
        //     }

        //     /// Returns the upper bound.
        //     double ub() const
        //     {
        //         return ub_;
        //     }

        //     /// Sets the lower bound.
        //     void SetLB( double lb )
        //     {
        //         SetBounds( lb, ub_ );
        //     }

        //     /// Sets the upper bound.
        //     void SetUB( double ub )
        //     {
        //         SetBounds( lb_, ub );
        //     }

        //     /// Sets both the lower and upper bounds.
        //     void SetBounds( double lb, double ub );

        //     /**
        //      * Advanced usage: unrounded solution value.
        //      *
        //      * The returned value won't be rounded to the nearest integer even if the
        //      * variable is integer.
        //      */
        //     double unrounded_solution_value() const;

        //     /**
        //      * Advanced usage: returns the reduced cost of the variable in the current
        //      * solution (only available for continuous problems).
        //      */
        //     double reduced_cost() const;

        //     /**
        //      * Advanced usage: returns the basis status of the variable in the current
        //      * solution (only available for continuous problems).
        //      *
        //      * @see MPSolver::BasisStatus.
        //      */
        //     MPSolver::BasisStatus basis_status() const;

        //     /**
        //      * Advanced usage: Certain MIP solvers (e.g. Gurobi or SCIP) allow you to set
        //      * a per-variable priority for determining which variable to branch on.
        //      *
        //      * A value of 0 is treated as default, and is equivalent to not setting the
        //      * branching priority. The solver looks first to branch on fractional
        //      * variables in higher priority levels. As of 2019-05, only Gurobi and SCIP
        //      * support setting branching priority; all other solvers will simply ignore
        //      * this annotation.
        //      */
        //     int branching_priority() const
        //     {
        //         return branching_priority_;
        //     }
        //     void SetBranchingPriority( int priority );

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
        //     friend class MPVariableSolutionValueTest;
        //     friend class BopInterface;
        //     friend class SatInterface;
        //     friend class PdlpInterface;
        //     friend class HighsInterface;
        //     friend class KnapsackInterface;

        //     // Constructor. A variable points to a single MPSolverInterface that
        //     // is specified in the constructor. A variable cannot belong to
        //     // several models.
        //     MPVariable( int index, double lb, double ub, bool integer,
        //                 const std::string& name, MPSolverInterface* const interface_in )
        //         : index_( index ),
        //           lb_( lb ),
        //           ub_( ub ),
        //           integer_( integer ),
        //           name_( name.empty() ? absl::StrFormat( "auto_v_%09d", index ) : name ),
        //           solution_value_( 0.0 ),
        //           reduced_cost_( 0.0 ),
        //           interface_( interface_in ) {}

        //     void set_solution_value( double value )
        //     {
        //         solution_value_ = value;
        //     }
        //     void set_reduced_cost( double reduced_cost )
        //     {
        //         reduced_cost_ = reduced_cost;
        //     }

        // private:
        //     const int                index_;
        //     double                   lb_;
        //     double                   ub_;
        //     bool                     integer_;
        //     const std::string        name_;
        //     double                   solution_value_;
        //     double                   reduced_cost_;
        //     int                      branching_priority_ = 0;
        //     MPSolverInterface* const interface_;
    };

}
declare namespace operations_research
{
    /**
     * The class for variables of a Mathematical Programming (MP) model.
     */
    declare class MPVariable
    {
        /**
         * Returns the name of the variable.
         * 
         * C++ const std::string& name() const
         */
        name(): string;

        /**
         * Sets the integrality requirement of the variable.
         * 
         * C++ void SetInteger( bool integer )
         */
        SetInteger(integer: boolean): void;

        /**
         * Returns the integrality requirement of the variable.
         * 
         * C++ bool integer() const
         */
        integer(): boolean;

        /**
         * Returns the value of the variable in the current solution.
         * 
         * If the variable is integer, then the value will always be an integer (the
         * underlying solver handles floating-point values only, but this function
         * automatically rounds it to the nearest integer; see: man 3 round).
         * 
         * C++ double solution_value() const
         */
        solution_value(): number;

        /**
         * Returns the index of the variable in the MPSolver::variables_.
         * 
         * C++ int index() const
         */
        index(): number;

        /**
         * Returns the lower bound.
         * 
         * C++ double lb() const
         */
        lb(): number;

        /**
         * Returns the upper bound.
         * 
         * C++ double ub() const
         */
        ub(): number;

        /**
         * Sets the lower bound.
         * 
         * C++ void SetLB( double lb )
         */
        SetLB(lb: number): void;

        /**
         * Sets the upper bound.
         * 
         * C++ void SetUB( double ub )
         */
        SetUB(ub: number): void;

        /**
         * Sets both the lower and upper bounds.
         * 
         * C++ void SetBounds( double lb, double ub )
         */
        SetBounds(lb: number, ub: number): void;

        /**
         * Advanced usage: unrounded solution value.
         * 
         * The returned value won't be rounded to the nearest integer even if the
         * variable is integer.
         * 
         * C++ double unrounded_solution_value() const
         */
        unrounded_solution_value(): number;

        /**
         * Advanced usage: returns the reduced cost of the variable in the current
         * solution (only available for continuous problems).
         * 
         * C++ double reduced_cost() const
         */
        reduced_cost(): number;

        /**
         * Advanced usage: returns the basis status of the variable in the current
         * solution (only available for continuous problems).
         * 
         * C++ MPSolver::BasisStatus basis_status() const
         */
        basis_status(): MPSolver.BasisStatus;

        /**
         * Advanced usage: Certain MIP solvers (e.g. Gurobi or SCIP) allow you to set
         * a per-variable priority for determining which variable to branch on.
         * 
         * A value of 0 is treated as default, and is equivalent to not setting the
         * branching priority. The solver looks first to branch on fractional
         * variables in higher priority levels. As of 2019-05, only Gurobi and SCIP
         * support setting branching priority; all other solvers will simply ignore
         * this annotation.
         * 
         * C++ int branching_priority() const
         */
        branching_priority(): number;

        /**
         * Advanced usage: Sets the branching priority of the variable.
         *  
         * C++ void SetBranchingPriority( int priority )
         */
        SetBranchingPriority(priority: number): void;
    };
}
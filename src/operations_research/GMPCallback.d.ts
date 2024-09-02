// Extend this class with model specific logic, and register through
// MPSolver::SetCallback, passing a pointer to this object.
//
// See go/mpsolver-callbacks for additional documentation.
export class MPCallback
{
    // public:
    //     // If you intend to call call MPCallbackContext::AddCut(), you must set
    //     // might_add_cuts below to be true.  Likewise for
    //     // MPCallbackContext::AddLazyConstraint() and might_add_lazy_constraints.
    //     MPCallback( bool might_add_cuts, bool might_add_lazy_constraints )
    //         : might_add_cuts_( might_add_cuts ),
    //           might_add_lazy_constraints_( might_add_lazy_constraints ) {}
    //     virtual ~MPCallback() {}

    //     // Threading behavior may be solver dependent:
    //     //   * Gurobi: RunCallback always runs on the same thread that you called
    //     //     MPSolver::Solve() on, even when Gurobi uses multiple threads.
    //     virtual void RunCallback( MPCallbackContext* callback_context ) = 0;

    //     bool might_add_cuts() const
    //     {
    //         return might_add_cuts_;
    //     }
    //     bool might_add_lazy_constraints() const
    //     {
    //         return might_add_lazy_constraints_;
    //     }

    // private:
    //     bool might_add_cuts_;
    //     bool might_add_lazy_constraints_;
}

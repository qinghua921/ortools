
/// A search monitor is a simple set of callbacks to monitor all search events
export class SearchMonitor 
{
    // public:
    //     static constexpr int kNoProgress = -1;

    //     explicit SearchMonitor( Solver* const s )
    //         : solver_( s ) {}
    //     ~SearchMonitor() override {}
    //     /// Beginning of the search.
    //     virtual void EnterSearch();

    //     /// Restart the search.
    //     virtual void RestartSearch();

    //     /// End of the search.
    //     virtual void ExitSearch();

    //     /// Before calling DecisionBuilder::Next.
    //     virtual void BeginNextDecision( DecisionBuilder* const b );

    //     /// After calling DecisionBuilder::Next, along with the returned decision.
    //     virtual void EndNextDecision( DecisionBuilder* const b, Decision* const d );

    //     /// Before applying the decision.
    //     virtual void ApplyDecision( Decision* const d );

    //     /// Before refuting the decision.
    //     virtual void RefuteDecision( Decision* const d );

    //     /// Just after refuting or applying the decision, apply is true after Apply.
    //     /// This is called only if the Apply() or Refute() methods have not failed.
    //     virtual void AfterDecision( Decision* const d, bool apply );

    //     /// Just when the failure occurs.
    //     virtual void BeginFail();

    //     /// After completing the backtrack.
    //     virtual void EndFail();

    //     /// Before the initial propagation.
    //     virtual void BeginInitialPropagation();

    //     /// After the initial propagation.
    //     virtual void EndInitialPropagation();

    //     /// This method is called when a solution is found. It asserts whether the
    //     /// solution is valid. A value of false indicates that the solution
    //     /// should be discarded.
    //     virtual bool AcceptSolution();

    //     /// This method is called when a valid solution is found. If the
    //     /// return value is true, then search will resume after. If the result
    //     /// is false, then search will stop there.
    //     virtual bool AtSolution();

    //     /// When the search tree is finished.
    //     virtual void NoMoreSolutions();

    //     /// When a local optimum is reached. If 'true' is returned, the last solution
    //     /// is discarded and the search proceeds with the next one.
    //     virtual bool LocalOptimum();

    //     ///
    //     virtual bool AcceptDelta( Assignment* delta, Assignment* deltadelta );

    //     /// After accepting a neighbor during local search.
    //     virtual void AcceptNeighbor();

    //     /// After accepting an unchecked neighbor during local search.
    //     virtual void AcceptUncheckedNeighbor();

    //     /// Returns true if the limit of solutions has been reached including
    //     /// unchecked solutions.
    //     virtual bool IsUncheckedSolutionLimitReached()
    //     {
    //         return false;
    //     }

    //     /// Periodic call to check limits in long running methods.
    //     virtual void PeriodicCheck();

    //     /// Returns a percentage representing the propress of the search before
    //     /// reaching limits.
    //     virtual int ProgressPercent()
    //     {
    //         return kNoProgress;
    //     }

    //     /// Accepts the given model visitor.
    //     virtual void Accept( ModelVisitor* const visitor ) const;

    //     /// Registers itself on the solver such that it gets notified of the search
    //     /// and propagation events. Override to incrementally install listeners for
    //     /// specific events.
    //     virtual void Install();

    //     Solver* solver() const
    //     {
    //         return solver_;
    //     }

    // protected:
    //     void ListenToEvent( Solver::MonitorEvent event );

    // private:
    //     Solver* const solver_;
    //     DISALLOW_COPY_AND_ASSIGN( SearchMonitor );
};

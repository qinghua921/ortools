
/// Interval variables are often used in scheduling. The main characteristics
/// of an IntervalVar are the start position, duration, and end
/// date. All these characteristics can be queried and set, and demons can
/// be posted on their modifications.
///
/// An important aspect is optionality: an IntervalVar can be performed or not.
/// If unperformed, then it simply does not exist, and its characteristics
/// cannot be accessed any more. An interval var is automatically marked
/// as unperformed when it is not consistent anymore (start greater
/// than end, duration < 0...)
export class IntervalVar 
{
    // public:
    //     /// The smallest acceptable value to be returned by StartMin()
    //     static const int64_t kMinValidValue;
    //     /// The largest acceptable value to be returned by EndMax()
    //     static const int64_t kMaxValidValue;
    //     IntervalVar( Solver* const solver, const std::string& name )
    //         : PropagationBaseObject( solver )
    //     {
    //         set_name( name );
    //     }
    //     ~IntervalVar() override {}

    //     /// These methods query, set, and watch the start position of the
    //     /// interval var.
    //     virtual int64_t StartMin() const                        = 0;
    //     virtual int64_t StartMax() const                        = 0;
    //     virtual void    SetStartMin( int64_t m )                = 0;
    //     virtual void    SetStartMax( int64_t m )                = 0;
    //     virtual void    SetStartRange( int64_t mi, int64_t ma ) = 0;
    //     virtual int64_t OldStartMin() const                     = 0;
    //     virtual int64_t OldStartMax() const                     = 0;
    //     virtual void    WhenStartRange( Demon* const d )        = 0;
    //     void            WhenStartRange( Solver::Closure closure )
    //     {
    //         WhenStartRange( solver()->MakeClosureDemon( std::move( closure ) ) );
    //     }
    // #if !defined( SWIG )
    //     void WhenStartRange( Solver::Action action )
    //     {
    //         WhenStartRange( solver()->MakeActionDemon( std::move( action ) ) );
    //     }
    // #endif  // SWIG
    //     virtual void WhenStartBound( Demon* const d ) = 0;
    //     void         WhenStartBound( Solver::Closure closure )
    //     {
    //         WhenStartBound( solver()->MakeClosureDemon( std::move( closure ) ) );
    //     }
    // #if !defined( SWIG )
    //     void WhenStartBound( Solver::Action action )
    //     {
    //         WhenStartBound( solver()->MakeActionDemon( std::move( action ) ) );
    //     }
    // #endif  // SWIG

    //     /// These methods query, set, and watch the duration of the interval var.
    //     virtual int64_t DurationMin() const                        = 0;
    //     virtual int64_t DurationMax() const                        = 0;
    //     virtual void    SetDurationMin( int64_t m )                = 0;
    //     virtual void    SetDurationMax( int64_t m )                = 0;
    //     virtual void    SetDurationRange( int64_t mi, int64_t ma ) = 0;
    //     virtual int64_t OldDurationMin() const                     = 0;
    //     virtual int64_t OldDurationMax() const                     = 0;
    //     virtual void    WhenDurationRange( Demon* const d )        = 0;
    //     void            WhenDurationRange( Solver::Closure closure )
    //     {
    //         WhenDurationRange( solver()->MakeClosureDemon( std::move( closure ) ) );
    //     }
    // #if !defined( SWIG )
    //     void WhenDurationRange( Solver::Action action )
    //     {
    //         WhenDurationRange( solver()->MakeActionDemon( std::move( action ) ) );
    //     }
    // #endif  // SWIG
    //     virtual void WhenDurationBound( Demon* const d ) = 0;
    //     void         WhenDurationBound( Solver::Closure closure )
    //     {
    //         WhenDurationBound( solver()->MakeClosureDemon( std::move( closure ) ) );
    //     }
    // #if !defined( SWIG )
    //     void WhenDurationBound( Solver::Action action )
    //     {
    //         WhenDurationBound( solver()->MakeActionDemon( std::move( action ) ) );
    //     }
    // #endif  // SWIG

    //     /// These methods query, set, and watch the end position of the interval var.
    //     virtual int64_t EndMin() const                        = 0;
    //     virtual int64_t EndMax() const                        = 0;
    //     virtual void    SetEndMin( int64_t m )                = 0;
    //     virtual void    SetEndMax( int64_t m )                = 0;
    //     virtual void    SetEndRange( int64_t mi, int64_t ma ) = 0;
    //     virtual int64_t OldEndMin() const                     = 0;
    //     virtual int64_t OldEndMax() const                     = 0;
    //     virtual void    WhenEndRange( Demon* const d )        = 0;
    //     void            WhenEndRange( Solver::Closure closure )
    //     {
    //         WhenEndRange( solver()->MakeClosureDemon( std::move( closure ) ) );
    //     }
    // #if !defined( SWIG )
    //     void WhenEndRange( Solver::Action action )
    //     {
    //         WhenEndRange( solver()->MakeActionDemon( std::move( action ) ) );
    //     }
    // #endif  // SWIG
    //     virtual void WhenEndBound( Demon* const d ) = 0;
    //     void         WhenEndBound( Solver::Closure closure )
    //     {
    //         WhenEndBound( solver()->MakeClosureDemon( std::move( closure ) ) );
    //     }
    // #if !defined( SWIG )
    //     void WhenEndBound( Solver::Action action )
    //     {
    //         WhenEndBound( solver()->MakeActionDemon( std::move( action ) ) );
    //     }
    // #endif  // SWIG

    //     /// These methods query, set, and watch the performed status of the
    //     /// interval var.
    //     virtual bool MustBePerformed() const = 0;
    //     virtual bool MayBePerformed() const  = 0;
    //     bool         CannotBePerformed() const
    //     {
    //         return !MayBePerformed();
    //     }
    //     bool IsPerformedBound() const
    //     {
    //         return MustBePerformed() || !MayBePerformed();
    //     }
    //     virtual void SetPerformed( bool val )             = 0;
    //     virtual bool WasPerformedBound() const            = 0;
    //     virtual void WhenPerformedBound( Demon* const d ) = 0;
    //     void         WhenPerformedBound( Solver::Closure closure )
    //     {
    //         WhenPerformedBound( solver()->MakeClosureDemon( std::move( closure ) ) );
    //     }
    // #if !defined( SWIG )
    //     void WhenPerformedBound( Solver::Action action )
    //     {
    //         WhenPerformedBound( solver()->MakeActionDemon( std::move( action ) ) );
    //     }
    // #endif  // SWIG

    //     /// Attaches a demon awakened when anything about this interval changes.
    //     void WhenAnything( Demon* const d );
    //     /// Attaches a closure awakened when anything about this interval changes.
    //     void WhenAnything( Solver::Closure closure )
    //     {
    //         WhenAnything( solver()->MakeClosureDemon( std::move( closure ) ) );
    //     }
    // #if !defined( SWIG )
    //     /// Attaches an action awakened when anything about this interval changes.
    //     void WhenAnything( Solver::Action action )
    //     {
    //         WhenAnything( solver()->MakeActionDemon( std::move( action ) ) );
    //     }
    // #endif  // SWIG

    //     /// These methods create expressions encapsulating the start, end
    //     /// and duration of the interval var. Please note that these must not
    //     /// be used if the interval var is unperformed.
    //     virtual IntExpr* StartExpr()     = 0;
    //     virtual IntExpr* DurationExpr()  = 0;
    //     virtual IntExpr* EndExpr()       = 0;
    //     virtual IntExpr* PerformedExpr() = 0;
    //     /// These methods create expressions encapsulating the start, end
    //     /// and duration of the interval var. If the interval var is
    //     /// unperformed, they will return the unperformed_value.
    //     virtual IntExpr* SafeStartExpr( int64_t unperformed_value )    = 0;
    //     virtual IntExpr* SafeDurationExpr( int64_t unperformed_value ) = 0;
    //     virtual IntExpr* SafeEndExpr( int64_t unperformed_value )      = 0;

    //     /// Accepts the given visitor.
    //     virtual void Accept( ModelVisitor* const visitor ) const = 0;

    // private:
    //     DISALLOW_COPY_AND_ASSIGN( IntervalVar );
};

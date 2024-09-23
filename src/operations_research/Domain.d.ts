
/**
 * We call \e domain any subset of Int64 = [kint64min, kint64max].
 *
 * This class can be used to represent such set efficiently as a sorted and
 * non-adjacent list of intervals. This is efficient as long as the size of such
 * list stays reasonable.
 *
 * In the comments below, the domain of *this will always be written 'D'.
 * Note that all the functions are safe with respect to integer overflow.
 */
export class Domain
{
    // public:
    //     /// By default, Domain will be empty.
    //     Domain() {}
    /**
     * By default, Domain will be empty.
     * 
     * C++ Domain() {}
     */
    constructor();

    //     /// Constructor for the common case of a singleton domain.
    //     explicit Domain( int64_t value );
    /**
     * Constructor for the common case of a singleton domain.
     * 
     * C++ explicit Domain( int64_t value );
     */
    constructor(value: number);



    //     /**
    //      * Constructor for the common case of a single interval [left, right].
    //      * If left > right, this will result in the empty domain.
    //      */
    //     Domain( int64_t left, int64_t right );
    /**
     * Constructor for the common case of a single interval [left, right].
     * If left > right, this will result in the empty domain.
     * 
     * C++ Domain( int64_t left, int64_t right );
     */
    constructor(left: number, right: number);



    //     /**
    //      * Returns the full domain Int64.
    //      */
    //     static Domain AllValues();
    /**
     * Returns the full domain Int64.
     * 
     * C++ static Domain AllValues();
     */
    static AllValues(): Domain;


    //     /**
    //      * Creates a domain from the union of an unsorted list of integer values.
    //      * Input values may be repeated, with no consequence on the output
    //      */
    //     static Domain FromValues( std::vector< int64_t > values );
    /**
     * Creates a domain from the union of an unsorted list of integer values.
     * Input values may be repeated, with no consequence on the output
     * 
     * C++ static Domain FromValues( std::vector< int64_t > values );
     */
    static FromValues(values: number[]): Domain;



    //     /**
    //      * Creates a domain from the union of an unsorted list of intervals.
    //      */
    //     static Domain FromIntervals( absl::Span< const ClosedInterval > intervals );

    //     /**
    //      * Same as FromIntervals() for a flattened representation (start, end,
    //      * start, end, ...).
    //      */
    //     static Domain FromFlatSpanOfIntervals(
    //         absl::Span< const int64_t > flat_intervals );

    //     /**
    //      * This method is available in Python, Java and .NET. It allows
    //      * building a Domain object from a list of intervals (long[][] in Java and
    //      * .NET, [[0, 2], [5, 5], [8, 10]] in python).
    //      */
    //     static Domain FromVectorIntervals(
    //         const std::vector< std::vector< int64_t > >& intervals );

    //     /**
    //      * This method is available in Python, Java and .NET. It allows
    //      * building a Domain object from a flattened list of intervals
    //      * (long[] in Java and .NET, [0, 2, 5, 5, 8, 10] in python).
    //      */
    //     static Domain FromFlatIntervals( const std::vector< int64_t >& flat_intervals );

    //     /**
    //      * This method returns the flattened list of interval bounds of the domain.
    //      *
    //      * Thus the domain {0, 1, 2, 5, 8, 9, 10} will return [0, 2, 5, 5,
    //      * 8, 10] (as a C++ std::vector<int64_t>, as a java or C# long[], as
    //      * a python list of integers).
    //      */
    //     std::vector< int64_t > FlattenedIntervals() const;

    // #if !defined( SWIG )
    //     /**
    //      * Allows to iterate over all values of a domain in order with
    //      * for (const int64_t v : domain.Values()) { ... }
    //      *
    //      * Note that this shouldn't be used in another context !!
    //      * We don't implement full fledged iterator APIs.
    //      */
    //     class DomainIterator
    //     {
    //     public:
    //         explicit DomainIterator(
    //             const absl::InlinedVector< ClosedInterval, 1 >& intervals )
    //             : value_( intervals.empty() ? int64_t{ 0 } : intervals.front().start ),
    //               it_( intervals.begin() ),
    //               end_( intervals.end() ) {}

    //         int64_t operator*() const
    //         {
    //             return value_;
    //         }

    //         void operator++()
    //         {
    //             if ( value_ == it_->end )
    //             {
    //                 ++it_;
    //                 if ( it_ != end_ ) value_ = it_->start;
    //             }
    //             else
    //             {
    //                 ++value_;
    //             }
    //         }

    //         bool operator!=(
    //             absl::InlinedVector< ClosedInterval, 1 >::const_iterator end ) const
    //         {
    //             return it_ != end;
    //         }

    //     private:
    //         int64_t                                                  value_;
    //         absl::InlinedVector< ClosedInterval, 1 >::const_iterator it_;
    //         absl::InlinedVector< ClosedInterval, 1 >::const_iterator end_;
    //     };
    //     struct DomainIteratorBeginEnd
    //     {
    //         DomainIterator begin() const
    //         {
    //             return DomainIterator( intervals );
    //         }
    //         absl::InlinedVector< ClosedInterval, 1 >::const_iterator end() const
    //         {
    //             return intervals.end();
    //         }
    //         const absl::InlinedVector< ClosedInterval, 1 >& intervals;
    //     };
    //     struct DomainIteratorBeginEndWithOwnership
    //     {
    //         DomainIterator begin() const
    //         {
    //             return DomainIterator( intervals );
    //         }
    //         absl::InlinedVector< ClosedInterval, 1 >::const_iterator end() const
    //         {
    //             return intervals.end();
    //         }
    //         absl::InlinedVector< ClosedInterval, 1 > intervals;
    //     };
    //     DomainIteratorBeginEnd Values() const&
    //     {
    //         return { this->intervals_ };
    //     }
    //     DomainIteratorBeginEndWithOwnership Values() const&&
    //     {
    //         return { std::move( this->intervals_ ) };
    //     }
    // #endif  // !defined(SWIG)

    //     /**
    //      * Returns true if this is the empty set.
    //      */
    //     bool IsEmpty() const;

    //     /**
    //      * Returns the number of elements in the domain. It is capped at kint64max
    //      */
    //     int64_t Size() const;

    //     /**
    //      * Returns true if the domain has just two values. This often mean a non-fixed
    //      * Boolean variable.
    //      */
    //     bool HasTwoValues() const
    //     {
    //         if ( intervals_.size() == 1 )
    //         {
    //             return intervals_[ 0 ].end == intervals_[ 0 ].start + 1;
    //         }
    //         else if ( intervals_.size() == 2 )
    //         {
    //             return intervals_[ 0 ].end == intervals_[ 0 ].start && intervals_[ 1 ].end == intervals_[ 1 ].start;
    //         }
    //         return false;
    //     }

    //     /**
    //      * Returns the min value of the domain.
    //      * The domain must not be empty.
    //      */
    //     int64_t Min() const;

    //     /**
    //      * Returns the max value of the domain.
    //      * The domain must not be empty.
    //      */
    //     int64_t Max() const;

    //     /**
    //      * Returns the value closest to zero. If there is a tie, pick positive one.
    //      */
    //     int64_t SmallestValue() const;

    //     /**
    //      * Returns the value closest to the given point.
    //      * If there is a tie, pick larger one.
    //      */
    //     int64_t ClosestValue( int64_t wanted ) const;

    //     /**
    //      * Returns the closest value in the domain that is <= (resp. >=) to the input.
    //      * Do not change the input if there is no such value.
    //      */
    //     int64_t ValueAtOrBefore( int64_t input ) const;
    //     int64_t ValueAtOrAfter( int64_t input ) const;

    //     /**
    //      * If the domain contains zero, this return the simple interval around it.
    //      * Otherwise, this returns an empty domain.
    //      */
    //     Domain PartAroundZero() const;

    //     /**
    //      * Returns true iff the domain is reduced to a single value.
    //      * The domain must not be empty.
    //      */
    //     bool IsFixed() const;

    //     /**
    //      * Returns the value of a fixed domain. IsFixed() must be true.
    //      * This is the same as Min() or Max() but allows for a more readable code and
    //      * also crash in debug mode if called on a non fixed domain.
    //      */
    //     int64_t FixedValue() const;

    //     /**
    //      * Returns true iff value is in Domain.
    //      */
    //     bool Contains( int64_t value ) const;

    //     /**
    //      * Returns the distance from the value to the domain.
    //      */
    //     int64_t Distance( int64_t value ) const;

    //     /**
    //      * Returns true iff D is included in the given domain.
    //      */
    //     bool IsIncludedIn( const Domain& domain ) const;

    //     /**
    //      * Returns the set Int64 ∖ D.
    //      */
    //     Domain Complement() const;

    //     /**
    //      * Returns {x ∈ Int64, ∃ e ∈ D, x = -e}.
    //      *
    //      * Note in particular that if the negation of Int64 is not Int64 but
    //      * Int64 \ {kint64min} !!
    //      */
    //     Domain Negation() const;

    //     /**
    //      * Returns the intersection of D and domain.
    //      */
    //     Domain IntersectionWith( const Domain& domain ) const;

    //     /**
    //      * Returns the union of D and domain.
    //      */
    //     Domain UnionWith( const Domain& domain ) const;

    //     /**
    //      * Returns {x ∈ Int64, ∃ a ∈ D, ∃ b ∈ domain, x = a + b}.
    //      */
    //     Domain AdditionWith( const Domain& domain ) const;

    //     /**
    //      * Returns {x ∈ Int64, ∃ e ∈ D, x = e * coeff}.
    //      *
    //      * Note that because the resulting domain will only contains multiple of
    //      * coeff, the size of intervals.size() can become really large. If it is
    //      * larger than a fixed constant, exact will be set to false and the result
    //      * will be set to ContinuousMultiplicationBy(coeff).
    //      *
    //      * Note that if you multiply by a negative coeff, kint64min will be dropped
    //      * from the result even if it was here due to how this is implemented.
    //      */
    //     Domain MultiplicationBy( int64_t coeff, bool* exact = nullptr ) const;

    //     /**
    //      * If NumIntervals() is too large, this return a superset of the domain.
    //      */
    //     Domain RelaxIfTooComplex() const;

    //     /**
    //      * Returns a superset of MultiplicationBy() to avoid the explosion in the
    //      * representation size. This behaves as if we replace the set D of
    //      * non-adjacent integer intervals by the set of floating-point elements in the
    //      * same intervals.
    //      *
    //      * For instance, [1, 100] * 2 will be transformed in [2, 200] and not in
    //      * [2][4][6]...[200] like in MultiplicationBy(). Note that this would be
    //      * similar to a InverseDivisionBy(), but not quite the same because if we
    //      * look for {x ∈ Int64, ∃ e ∈ D, x / coeff = e}, then we will get [2, 201] in
    //      * the case above.
    //      */
    //     Domain ContinuousMultiplicationBy( int64_t coeff ) const;

    //     /**
    //      * Returns a superset of MultiplicationBy() to avoid the explosion in the
    //      * representation size. This behaves as if we replace the set D of
    //      * non-adjacent integer intervals by the set of floating-point elements in the
    //      * same intervals.
    //      *
    //      * For instance, [1, 100] * 2 will be transformed in [2, 200] and not in
    //      * [2][4][6]...[200] like in MultiplicationBy(). Note that this would be
    //      * similar to a InverseDivisionBy(), but not quite the same because if we
    //      * look for {x ∈ Int64, ∃ e ∈ D, x / coeff = e}, then we will get [2, 201] in
    //      * the case above.
    //      */
    //     Domain ContinuousMultiplicationBy( const Domain& domain ) const;

    //     /**
    //      * Returns {x ∈ Int64, ∃ e ∈ D, x = e / coeff}.
    //      *
    //      * For instance Domain(1, 7).DivisionBy(2) == Domain(0, 3).
    //      */
    //     Domain DivisionBy( int64_t coeff ) const;

    //     /**
    //      * Returns {x ∈ Int64, ∃ e ∈ D, x * coeff = e}.
    //      *
    //      * For instance Domain(1, 7).InverseMultiplicationBy(2) == Domain(1, 3).
    //      */
    //     Domain InverseMultiplicationBy( int64_t coeff ) const;

    //     /**
    //      * Returns a superset of {x ∈ Int64, ∃ e ∈ D, ∃ m ∈ modulo, x = e % m }.
    //      *
    //      * We check that modulo is strictly positive.
    //      * The sign of the modulo depends on the sign of e.
    //      * We compute the exact min/max if the modulo is fixed, otherwise we will
    //      * just return a superset.
    //      */
    //     Domain PositiveModuloBySuperset( const Domain& modulo ) const;

    //     /**
    //      * Returns a superset of {x ∈ Int64, ∃ e ∈ D, ∃ d ∈ divisor, x = e / d }.
    //      *
    //      * We check that divisor is strictly positive.
    //      * For now we just intersect with the min/max possible value.
    //      */
    //     Domain PositiveDivisionBySuperset( const Domain& divisor ) const;

    //     /**
    //      * Returns a superset of {x ∈ Int64, ∃ y ∈ D, x = y * y }.
    //      */
    //     Domain SquareSuperset() const;

    //     /**
    //      * Advanced usage. Given some \e implied information on this domain that is
    //      * assumed to be always true (i.e. only values in the intersection with
    //      * implied domain matter), this function will simplify the current domain
    //      * without changing the set of "possible values".
    //      *
    //      * More precisely, this will:
    //      *  - Take the intersection with implied_domain.
    //      *  - Minimize the number of intervals. For example, if the
    //      *    domain is [1,2][4] and implied is [1][4], then the domain can be
    //      *    relaxed to [1, 4] to simplify its complexity without changing the set
    //      *    of admissible value assuming only implied values can be seen.
    //      *  - Restrict as much as possible the bounds of the remaining intervals.
    //      *    For example, if the input is [1,2] and implied is [0,4], then the domain
    //      * will not be changed.
    //      *
    //      * Note that \b domain.SimplifyUsingImpliedDomain(domain) will just return
    //      * [domain.Min(), domain.Max()]. This is meant to be applied to the right-hand
    //      * side of a constraint to make its propagation more efficient.
    //      */
    //     Domain SimplifyUsingImpliedDomain( const Domain& implied_domain ) const;

    //     /**
    //      * Returns a compact string of a vector of intervals like "[1,4][6][10,20]".
    //      */
    //     std::string ToString() const;

    //     /**
    //      * Lexicographic order on the intervals() representation.
    //      */
    //     bool operator<( const Domain& other ) const;

    //     bool operator==( const Domain& other ) const
    //     {
    //         return intervals_ == other.intervals_;
    //     }

    //     bool operator!=( const Domain& other ) const
    //     {
    //         return intervals_ != other.intervals_;
    //     }

    //     template < typename H >
    //     friend H AbslHashValue( H h, const Domain& domain )
    //     {
    //         return H::combine( std::move( h ), domain.intervals_ );
    //     }

    //     /**
    //      * Basic read-only std::vector<> wrapping to view a Domain as a sorted list of
    //      * non-adjacent intervals. Note that we don't expose size() which might be
    //      * confused with the number of values in the domain.
    //      */
    //     int NumIntervals() const
    //     {
    //         return intervals_.size();
    //     }
    //     ClosedInterval front() const
    //     {
    //         return intervals_.front();
    //     }
    //     ClosedInterval back() const
    //     {
    //         return intervals_.back();
    //     }
    //     ClosedInterval operator[]( int i ) const
    //     {
    //         return intervals_[ i ];
    //     }
    //     absl::InlinedVector< ClosedInterval, 1 >::const_iterator begin() const
    //     {
    //         return intervals_.begin();
    //     }
    //     absl::InlinedVector< ClosedInterval, 1 >::const_iterator end() const
    //     {
    //         return intervals_.end();
    //     }

};


// Duration
//
// The `absl::Duration` class represents a signed, fixed-length amount of time.
// A `Duration` is generated using a unit-specific factory function, or is
// the result of subtracting one `absl::Time` from another. Durations behave
// like unit-safe integers and they support all the natural integer-like
// arithmetic operations. Arithmetic overflows and saturates at +/- infinity.
// `Duration` should be passed by value rather than const reference.
//
// Factory functions `Nanoseconds()`, `Microseconds()`, `Milliseconds()`,
// `Seconds()`, `Minutes()`, `Hours()` and `InfiniteDuration()` allow for
// creation of constexpr `Duration` values
//
// Examples:
//
//   constexpr absl::Duration ten_ns = absl::Nanoseconds(10);
//   constexpr absl::Duration min = absl::Minutes(1);
//   constexpr absl::Duration hour = absl::Hours(1);
//   absl::Duration dur = 60 * min;  // dur == hour
//   absl::Duration half_sec = absl::Milliseconds(500);
//   absl::Duration quarter_sec = 0.25 * absl::Seconds(1);
//
// `Duration` values can be easily converted to an integral number of units
// using the division operator.
//
// Example:
//
//   constexpr absl::Duration dur = absl::Milliseconds(1500);
//   int64_t ns = dur / absl::Nanoseconds(1);   // ns == 1500000000
//   int64_t ms = dur / absl::Milliseconds(1);  // ms == 1500
//   int64_t sec = dur / absl::Seconds(1);    // sec == 1 (subseconds truncated)
//   int64_t min = dur / absl::Minutes(1);    // min == 0
//
// See the `IDivDuration()` and `FDivDuration()` functions below for details on
// how to access the fractional parts of the quotient.
//
// Alternatively, conversions can be performed using helpers such as
// `ToInt64Microseconds()` and `ToDoubleSeconds()`.
export class Duration
{
    // public:
    //     // Value semantics.
    //     constexpr Duration()
    //         : rep_hi_( 0 ), rep_lo_( 0 ) {}  // zero-length duration

    //     // Copyable.
    // #if !defined( __clang__ ) && defined( _MSC_VER ) && _MSC_VER < 1930
    //     // Explicitly defining the constexpr copy constructor avoids an MSVC bug.
    //     constexpr Duration( const Duration& d )
    //         : rep_hi_( d.rep_hi_ ), rep_lo_( d.rep_lo_ ) {}
    // #else
    //     constexpr Duration( const Duration& d ) = default;
    // #endif
    //     Duration& operator=( const Duration& d ) = default;

    //     // Compound assignment operators.
    //     Duration& operator+=( Duration d );
    //     Duration& operator-=( Duration d );
    //     Duration& operator*=( int64_t r );
    //     Duration& operator*=( double r );
    //     Duration& operator/=( int64_t r );
    //     Duration& operator/=( double r );
    //     Duration& operator%=( Duration rhs );

    //     // Overloads that forward to either the int64_t or double overloads above.
    //     // Integer operands must be representable as int64_t.
    //     template < typename T, time_internal::EnableIfIntegral< T > = 0 >
    //     Duration& operator*=( T r )
    //     {
    //         int64_t x = r;
    //         return *this *= x;
    //     }

    //     template < typename T, time_internal::EnableIfIntegral< T > = 0 >
    //     Duration& operator/=( T r )
    //     {
    //         int64_t x = r;
    //         return *this /= x;
    //     }

    //     template < typename T, time_internal::EnableIfFloat< T > = 0 >
    //     Duration& operator*=( T r )
    //     {
    //         double x = r;
    //         return *this *= x;
    //     }

    //     template < typename T, time_internal::EnableIfFloat< T > = 0 >
    //     Duration& operator/=( T r )
    //     {
    //         double x = r;
    //         return *this /= x;
    //     }

    //     template < typename H >
    //     friend H AbslHashValue( H h, Duration d )
    //     {
    //         return H::combine( std::move( h ), d.rep_hi_, d.rep_lo_ );
    //     }

}

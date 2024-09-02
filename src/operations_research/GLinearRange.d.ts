
/**
 * An expression of the form:
 *
 * \code lower_bound <= sum_{i in S} a_i*x_i <= upper_bound. \endcode
 * The sum is represented as a LinearExpr with offset 0.
 *
 * Must be added to model with
 * \code
   MPSolver::AddRowConstraint(const LinearRange& range,
                              const std::string& name);
   \endcode
 */
export class LinearRange
{
    //    public:
    //    LinearRange()
    //        : lower_bound_( 0 ), upper_bound_( 0 ) {}
    //    /**
    //     * The bounds of the linear range are updated so that they include the offset
    //     * from "linear_expr", i.e., we form the range:
    //     * \code
    //       lower_bound - offset <= linear_expr - offset <= upper_bound - offset.
    //       \endcode
    //     */
    //    LinearRange( double lower_bound, const LinearExpr& linear_expr,
    //                 double upper_bound );

    //    double lower_bound() const
    //    {
    //        return lower_bound_;
    //    }
    //    const LinearExpr& linear_expr() const
    //    {
    //        return linear_expr_;
    //    }
    //    double upper_bound() const
    //    {
    //        return upper_bound_;
    //    }

}   
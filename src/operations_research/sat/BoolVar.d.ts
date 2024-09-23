/**
 * A Boolean variable.
 *
 * This class refer to an IntegerVariableProto with domain [0, 1] or to its
 * logical negation (Not). This is called a Boolean Literal in other context.
 *
 * This can only be constructed via \c CpModelBuilder.NewBoolVar().
 */
export class BoolVar
{
    //public:
    //    /// A default constructed BoolVar can be used to mean not defined yet.
    //    /// However, it shouldn't be passed to any of the functions in this file.
    //    /// Doing so will crash in debug mode and will result in an invalid model in
    //    /// opt mode.
    //    BoolVar() = default;
    /**
     * A default constructed BoolVar can be used to mean not defined yet.
     * However, it shouldn't be passed to any of the functions in this file.
     * Doing so will crash in debug mode and will result in an invalid model in
     * opt mode.
     * 
     * C++ BoolVar() = default;
     */
    constructor();

    //    /// Sets the name of the variable.
    //    /// Note that this will always set the "positive" version of this Boolean.
    //    BoolVar WithName( absl::string_view name );
    /**
     * Sets the name of the variable.
     * Note that this will always set the "positive" version of this Boolean.
     * 
     * C++ BoolVar WithName( absl::string_view name )
     */
    WithName(name: string): BoolVar;

    //    /// Returns the name of the variable.
    //    std::string Name() const;
    /**
     * Returns the name of the variable.
     * 
     * C++ std::string Name() const
     */
    Name(): string;


    //    /// Returns the logical negation of the current Boolean variable.
    //    BoolVar Not() const
    /**
     * Returns the logical negation of the current Boolean variable.
     * 
     * C++ BoolVar Not() const
     */
    Not(): BoolVar;



    //    bool operator==( const BoolVar& other ) const
    /**
     * C++ bool operator==( const BoolVar& other ) const
     */
    operator_eq(other: BoolVar): boolean;

    //    bool operator!=( const BoolVar& other ) const
    //    {
    //        return other.builder_ != builder_ || other.index_ != index_;
    //    }

    /**
     * C++ BoolVar operator~() const
     */

    //    std::string DebugString() const;

    //    /**
    //     * Returns the index of the variable in the model.
    //     *
    //     * Warning: If the variable is the negation of another variable v, its index
    //     * is -v.index() - 1. So this can be negative.
    //     */
    //    int index() const
    //    {
    //        return index_;
    //    }

};

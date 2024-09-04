import { BoolVar } from "./GBoolVar";

/**
 * An integer variable.
 *
 * This class wraps an IntegerVariableProto.
 * This can only be constructed via \c CpModelBuilder.NewIntVar().
 */
export class IntVar
{
    // public:
    //     /// A default constructed IntVar can be used to mean not defined yet.
    //     /// However, it shouldn't be passed to any of the functions in this file.
    //     /// Doing so will crash in debug mode and will result in an invalid model in
    //     /// opt mode.
    //     IntVar() = default;
    constructor();

    //     /// Cast BoolVar -> IntVar.
    //     /// The IntVar will take the value 1 (when the bool is true) and 0 otherwise.
    //     ///
    //     /// Warning: If you construct an IntVar from a negated BoolVar, this might
    //     /// create a new variable in the model. Otherwise this just point to the same
    //     /// underlying variable.
    //     explicit IntVar( const BoolVar& var );
    constructor(var_: BoolVar);

    //     /// Cast IntVar -> BoolVar.
    //     ///
    //     /// Warning: The domain of the var must be within {0,1}. If not, we crash
    //     /// in debug mode, and in opt mode you will get an invalid model if you use
    //     /// this BoolVar anywhere since it will not have a valid domain.
    //     BoolVar ToBoolVar() const;

    //     /// Sets the name of the variable.
    //     IntVar WithName( const std::string& name );
    WithName(name: string): IntVar;

    //     /// Returns the name of the variable (or the empty string if not set).
    //     std::string Name() const;

    //     bool operator==( const IntVar& other ) const
    //     {
    //         return other.builder_ == builder_ && other.index_ == index_;
    //     }

    //     bool operator!=( const IntVar& other ) const
    //     {
    //         return other.builder_ != builder_ || other.index_ != index_;
    //     }

    //     // Returns the domain of the variable.
    //     // Note that we keep the fully qualified return type as compilation fails with
    //     // gcc otherwise.
    //     ::operations_research::Domain Domain() const;

    //     std::string DebugString() const;

    //     /// Returns the index of the variable in the model. This will be non-negative.
    //     int index() const
    //     {
    //         return index_;
    //     }

}

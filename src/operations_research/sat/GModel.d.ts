/**
 * Class that owns everything related to a particular optimization model.
 *
 * This class is actually a fully generic wrapper that can hold any type of
 * constraints, watchers, solvers and provide a mechanism to wire them together.
 */
export class Model
{
    // public:
    //     Model() {}
    constructor();


    //     /**
    //      * When there is more than one model in an application, it makes sense to
    //      * name them for debugging or logging.
    //      */
    //     explicit Model( std::string name )
    //         : name_( name ) {}

    //     /**
    //      * This makes it possible  to have a nicer API on the client side, and it
    //      * allows both of these forms:
    //      *   - ConstraintCreationFunction(constraint_args, &model);
    //      *   - model.Add(ConstraintCreationFunction(constraint_args));
    //      *
    //      * The second form is a bit nicer for the client and it also allows to store
    //      * constraints and add them later. However, the function creating the
    //      * constraint is slighly more involved.
    //      *
    //      * \code
    //      std::function<void(Model*)> ConstraintCreationFunction(constraint_args) {
    //        return [=] (Model* model) {
    //           ... the same code ...
    //        };
    //      }
    //      \endcode
    //      *
    //      * We also have a templated return value for the functions that need it like
    //      * \code
    //      const BooleanVariable b = model.Add(NewBooleanVariable());
    //      const IntegerVariable i = model.Add(NewWeightedSum(weights, variables));
    //      \endcode
    //      */
    //     template < typename T >
    //     T Add( std::function< T( Model* ) > f )
    Add<T>(func: (model: Model) => T): T

    //     /// Similar to Add() but this is const.
    //     template < typename T >
    //     T Get( std::function< T( const Model& ) > f ) const
    //     {
    //         return f( *this );
    //     }

    //     /**
    //      * Returns an object of type T that is unique to this model (like a "local"
    //      * singleton). This returns an already created instance or create a new one if
    //      * needed using the T(Model* model) constructor if it exist or T() otherwise.
    //      *
    //      * This works a bit like in a dependency injection framework and allows to
    //      * really easily wire all the classes that make up a solver together. For
    //      * instance a constraint can depends on the LiteralTrail, or the IntegerTrail
    //      * or both, it can depend on a Watcher class to register itself in order to
    //      * be called when needed and so on.
    //      *
    //      * IMPORTANT: the Model* constructor functions shouldn't form a cycle between
    //      * each other, otherwise this will crash the program.
    //      */
    //     template < typename T >
    //     T* GetOrCreate()
    //     {
    //         const size_t type_id = gtl::FastTypeId< T >();
    //         auto         find    = singletons_.find( type_id );
    //         if ( find != singletons_.end() )
    //         {
    //             return static_cast< T* >( find->second );
    //         }

    //         // New element.
    //         // TODO(user): directly store std::unique_ptr<> in singletons_?
    //         T* new_t               = MyNew< T >( 0 );
    //         singletons_[ type_id ] = new_t;
    //         TakeOwnership( new_t );
    //         return new_t;
    //     }

    //     /**
    //      * Likes GetOrCreate() but do not create the object if it is non-existing.
    //      *
    //      * This returns a const version of the object.
    //      */
    //     template < typename T >
    //     const T* Get() const
    //     {
    //         const auto& it = singletons_.find( gtl::FastTypeId< T >() );
    //         return it != singletons_.end() ? static_cast< const T* >( it->second )
    //                                        : nullptr;
    //     }

    //     /**
    //      * Same as Get(), but returns a mutable version of the object.
    //      */
    //     template < typename T >
    //     T* Mutable() const
    //     {
    //         const auto& it = singletons_.find( gtl::FastTypeId< T >() );
    //         return it != singletons_.end() ? static_cast< T* >( it->second ) : nullptr;
    //     }

    //     /**
    //      * Gives ownership of a pointer to this model.
    //      *
    //      * It will be destroyed when the model is.
    //      */
    //     template < typename T >
    //     T* TakeOwnership( T* t )
    //     {
    //         cleanup_list_.emplace_back( new Delete< T >( t ) );
    //         return t;
    //     }

    //     /**
    //      * This returns a non-singleton object owned by the model and created with the
    //      * T(Model* model) constructor if it exist or the T() constructor otherwise.
    //      * It is just a shortcut to new + TakeOwnership().
    //      */
    //     template < typename T >
    //     T* Create()
    //     {
    //         T* new_t = MyNew< T >( 0 );
    //         TakeOwnership( new_t );
    //         return new_t;
    //     }

    //     /**
    //      * Register a non-owned class that will be "singleton" in the model.
    //      *
    //      * It is an error to call this on an already registered class.
    //      */
    //     template < typename T >
    //     void Register( T* non_owned_class )
    //     {
    //         const size_t type_id = gtl::FastTypeId< T >();
    //         CHECK( !singletons_.contains( type_id ) );
    //         singletons_[ type_id ] = non_owned_class;
    //     }

    //     const std::string& Name() const
    //     {
    //         return name_;
    //     }

};

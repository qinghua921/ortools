export class Model
{
    //   public:
    constructor();
    constructor( name : string );



    //     // This type is neither copyable nor movable.
    //     Model(const Model &)            = delete;
    //     Model &operator=(const Model &) = delete;

    //     template <typename T>
    //     T Add(std::function<T(Model *)> f)
    //     {
    //         return f(this);
    //     }

    //     /// Similar to Add() but this is const.
    //     template <typename T>
    //     T Get(std::function<T(const Model &)> f) const
    //     {
    //         return f(*this);
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
    //     template <typename T>
    //     T *GetOrCreate()
    //     {
    //         const size_t type_id = gtl::FastTypeId<T>();
    //         auto find            = singletons_.find(type_id);
    //         if (find != singletons_.end())
    //         {
    //             return static_cast<T *>(find->second);
    //         }

    //         // New element.
    //         // TODO(user): directly store std::unique_ptr<> in singletons_?
    //         T *new_t             = MyNew<T>(0);
    //         singletons_[type_id] = new_t;
    //         TakeOwnership(new_t);
    //         return new_t;
    //     }

    //     /**
    //      * Likes GetOrCreate() but do not create the object if it is non-existing.
    //      *
    //      * This returns a const version of the object.
    //      */
    //     template <typename T>
    //     const T *Get() const
    //     {
    //         const auto &it = singletons_.find(gtl::FastTypeId<T>());
    //         return it != singletons_.end() ? static_cast<const T *>(it->second)
    //                                        : nullptr;
    //     }

    //     /**
    //      * Same as Get(), but returns a mutable version of the object.
    //      */
    //     template <typename T>
    //     T *Mutable() const
    //     {
    //         const auto &it = singletons_.find(gtl::FastTypeId<T>());
    //         return it != singletons_.end() ? static_cast<T *>(it->second) : nullptr;
    //     }

    //     /**
    //      * Gives ownership of a pointer to this model.
    //      *
    //      * It will be destroyed when the model is.
    //      */
    //     template <typename T>
    //     T *TakeOwnership(T *t)
    //     {
    //         cleanup_list_.emplace_back(new Delete<T>(t));
    //         return t;
    //     }

    //     /**
    //      * This returns a non-singleton object owned by the model and created with the
    //      * T(Model* model) constructor if it exist or the T() constructor otherwise.
    //      * It is just a shortcut to new + TakeOwnership().
    //      */
    //     template <typename T>
    //     T *Create()
    //     {
    //         T *new_t = MyNew<T>(0);
    //         TakeOwnership(new_t);
    //         return new_t;
    //     }

    //     /**
    //      * Register a non-owned class that will be "singleton" in the model.
    //      *
    //      * It is an error to call this on an already registered class.
    //      */
    //     template <typename T>
    //     void Register(T *non_owned_class)
    //     {
    //         const size_t type_id = gtl::FastTypeId<T>();
    //         CHECK(!singletons_.contains(type_id));
    //         singletons_[type_id] = non_owned_class;
    //     }

    //     const std::string &Name() const
    //     {
    //         return name_;
    //     }

    //   private:
    //     // We want to call the constructor T(model*) if it exists or just T() if
    //     // it doesn't. For this we use some template "magic":
    //     // - The first MyNew() will only be defined if the type in decltype() exist.
    //     // - The second MyNew() will always be defined, but because of the ellipsis
    //     //   it has lower priority that the first one.
    //     template <typename T>
    //     decltype(T(static_cast<Model *>(nullptr))) *MyNew(int)
    //     {
    //         return new T(this);
    //     }
    //     template <typename T>
    //     T *MyNew(...)
    //     {
    //         return new T();
    //     }

    //     const std::string name_;

    //     // Map of FastTypeId<T> to a "singleton" of type T.
    //     absl::flat_hash_map</*typeid*/ size_t, void *> singletons_;

    //     struct DeleteInterface
    //     {
    //         virtual ~DeleteInterface() = default;
    //     };
    //     template <typename T>
    //     class Delete : public DeleteInterface
    //     {
    //       public:
    //         explicit Delete(T *t)
    //             : to_delete_(t)
    //         {
    //         }
    //         ~Delete() override = default;

    //       private:
    //         std::unique_ptr<T> to_delete_;
    //     };

    //     // The list of items to delete.
    //     //
    //     // TODO(user): I don't think we need the two layers of unique_ptr, but we
    //     // don't care too much about efficiency here and this was easier to get
    //     // working.
    //     std::vector<std::unique_ptr<DeleteInterface>> cleanup_list_;
};

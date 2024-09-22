
export class CpModelProto // final : public ::google::protobuf::Message
{
    //    public:
    //        inline CpModelProto()
    //            : CpModelProto( nullptr ) {}
    //        ~CpModelProto() override;
    //        template < typename = void >
    //        explicit PROTOBUF_CONSTEXPR CpModelProto(
    //            ::google::protobuf::internal::ConstantInitialized );

    //        inline CpModelProto( const CpModelProto& from )
    //            : CpModelProto( nullptr, from ) {}
    //        inline CpModelProto( CpModelProto&& from ) noexcept
    //            : CpModelProto( nullptr, std::move( from ) ) {}
    //        inline CpModelProto& operator=( const CpModelProto& from )
    //        {
    //            CopyFrom( from );
    //            return *this;
    //        }
    //        inline CpModelProto& operator=( CpModelProto&& from ) noexcept
    //        {
    //            if ( this == &from ) return *this;
    //            if ( GetArena() == from.GetArena()
    //#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
    //                 && GetArena() != nullptr
    //#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    //            )
    //            {
    //                InternalSwap( &from );
    //            }
    //            else
    //            {
    //                CopyFrom( from );
    //            }
    //            return *this;
    //        }

    //        inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
    //            ABSL_ATTRIBUTE_LIFETIME_BOUND
    //        {
    //            return _internal_metadata_.unknown_fields< ::google::protobuf::UnknownFieldSet >( ::google::protobuf::UnknownFieldSet::default_instance );
    //        }
    //        inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
    //            ABSL_ATTRIBUTE_LIFETIME_BOUND
    //        {
    //            return _internal_metadata_.mutable_unknown_fields< ::google::protobuf::UnknownFieldSet >();
    //        }

    //        static const ::google::protobuf::Descriptor* descriptor()
    //        {
    //            return GetDescriptor();
    //        }
    //        static const ::google::protobuf::Descriptor* GetDescriptor()
    //        {
    //            return default_instance().GetMetadata().descriptor;
    //        }
    //        static const ::google::protobuf::Reflection* GetReflection()
    //        {
    //            return default_instance().GetMetadata().reflection;
    //        }
    //        static const CpModelProto& default_instance()
    //        {
    //            return *internal_default_instance();
    //        }
    //        static inline const CpModelProto* internal_default_instance()
    //        {
    //            return reinterpret_cast< const CpModelProto* >(
    //                &_CpModelProto_default_instance_ );
    //        }
    //        static constexpr int kIndexInFileMessages = 26;
    //        friend void          swap( CpModelProto& a, CpModelProto& b )
    //        {
    //            a.Swap( &b );
    //        }
    //        inline void Swap( CpModelProto* other )
    //        {
    //            if ( other == this ) return;
    //#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    //            if ( GetArena() != nullptr && GetArena() == other->GetArena() )
    //            {
    //#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    //            if ( GetArena() == other->GetArena() )
    //            {
    //#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
    //                InternalSwap( other );
    //            }
    //            else
    //            {
    //                ::google::protobuf::internal::GenericSwap( this, other );
    //            }
    //        }
    //        void UnsafeArenaSwap( CpModelProto* other )
    //        {
    //            if ( other == this ) return;
    //            ABSL_DCHECK( GetArena() == other->GetArena() );
    //            InternalSwap( other );
    //        }

    //        // implements Message ----------------------------------------------

    //        CpModelProto* New( ::google::protobuf::Arena* arena = nullptr ) const final
    //        {
    //            return ::google::protobuf::Message::DefaultConstruct< CpModelProto >( arena );
    //        }
    //        using ::google::protobuf::Message::CopyFrom;
    //        void CopyFrom( const CpModelProto& from );
    //        using ::google::protobuf::Message::MergeFrom;
    //        void MergeFrom( const CpModelProto& from )
    //        {
    //            CpModelProto::MergeImpl( *this, from );
    //        }

    //    private:
    //        static void MergeImpl(
    //            ::google::protobuf::MessageLite&       to_msg,
    //            const ::google::protobuf::MessageLite& from_msg );

    //    public:
    //        ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
    //        bool                              IsInitialized() const final;

    //        ::size_t    ByteSizeLong() const final;
    //        const char* _InternalParse( const char* ptr, ::google::protobuf::internal::ParseContext* ctx ) final;
    //        ::uint8_t*  _InternalSerialize(
    //             ::uint8_t*                                   target,
    //             ::google::protobuf::io::EpsCopyOutputStream* stream ) const final;
    //        int GetCachedSize() const
    //        {
    //            return _impl_._cached_size_.Get();
    //        }

    //    private:
    //        void SharedCtor( ::google::protobuf::Arena* arena );
    //        void SharedDtor();
    //        void InternalSwap( CpModelProto* other );

    //    private:
    //        friend class ::google::protobuf::internal::AnyMetadata;
    //        static ::absl::string_view FullMessageName()
    //        {
    //            return "operations_research.sat.CpModelProto";
    //        }

    //    protected:
    //        explicit CpModelProto( ::google::protobuf::Arena* arena );
    //        CpModelProto( ::google::protobuf::Arena* arena, const CpModelProto& from );
    //        CpModelProto( ::google::protobuf::Arena* arena, CpModelProto&& from ) noexcept
    //            : CpModelProto( arena )
    //        {
    //            *this = ::std::move( from );
    //        }
    //        const ::google::protobuf::MessageLite::ClassData* GetClassData()
    //            const final;

    //    public:
    //        ::google::protobuf::Metadata GetMetadata() const final;
    //        // nested types ----------------------------------------------------

    //        // accessors -------------------------------------------------------
    //        enum : int
    //        {
    //            kVariablesFieldNumber              = 2,
    //            kConstraintsFieldNumber            = 3,
    //            kSearchStrategyFieldNumber         = 5,
    //            kAssumptionsFieldNumber            = 7,
    //            kNameFieldNumber                   = 1,
    //            kObjectiveFieldNumber              = 4,
    //            kSolutionHintFieldNumber           = 6,
    //            kSymmetryFieldNumber               = 8,
    //            kFloatingPointObjectiveFieldNumber = 9,
    //        };
    //        // repeated .operations_research.sat.IntegerVariableProto variables = 2;
    //        int variables_size() const;

    //    private:
    //        int _internal_variables_size() const;

    //    public:
    //        void                                                                                      clear_variables();
    //        ::operations_research::sat::IntegerVariableProto*                                         mutable_variables( int index );
    //        ::google::protobuf::RepeatedPtrField< ::operations_research::sat::IntegerVariableProto >* mutable_variables();

    //    private:
    //        const ::google::protobuf::RepeatedPtrField< ::operations_research::sat::IntegerVariableProto >& _internal_variables() const;
    //        ::google::protobuf::RepeatedPtrField< ::operations_research::sat::IntegerVariableProto >*       _internal_mutable_variables();

    //    public:
    //        const ::operations_research::sat::IntegerVariableProto&                                         variables( int index ) const;
    //        ::operations_research::sat::IntegerVariableProto*                                               add_variables();
    //        const ::google::protobuf::RepeatedPtrField< ::operations_research::sat::IntegerVariableProto >& variables() const;
    //        // repeated .operations_research.sat.ConstraintProto constraints = 3;
    //        int constraints_size() const;

    //    private:
    //        int _internal_constraints_size() const;

    //    public:
    //        void                                                                                 clear_constraints();
    //        ::operations_research::sat::ConstraintProto*                                         mutable_constraints( int index );
    //        ::google::protobuf::RepeatedPtrField< ::operations_research::sat::ConstraintProto >* mutable_constraints();

    //    private:
    //        const ::google::protobuf::RepeatedPtrField< ::operations_research::sat::ConstraintProto >& _internal_constraints() const;
    //        ::google::protobuf::RepeatedPtrField< ::operations_research::sat::ConstraintProto >*       _internal_mutable_constraints();

    //    public:
    //        const ::operations_research::sat::ConstraintProto&                                         constraints( int index ) const;
    //        ::operations_research::sat::ConstraintProto*                                               add_constraints();
    //        const ::google::protobuf::RepeatedPtrField< ::operations_research::sat::ConstraintProto >& constraints() const;
    //        // repeated .operations_research.sat.DecisionStrategyProto search_strategy = 5;
    //        int search_strategy_size() const;

    //    private:
    //        int _internal_search_strategy_size() const;

    //    public:
    //        void                                                                                       clear_search_strategy();
    //        ::operations_research::sat::DecisionStrategyProto*                                         mutable_search_strategy( int index );
    //        ::google::protobuf::RepeatedPtrField< ::operations_research::sat::DecisionStrategyProto >* mutable_search_strategy();

    //    private:
    //        const ::google::protobuf::RepeatedPtrField< ::operations_research::sat::DecisionStrategyProto >& _internal_search_strategy() const;
    //        ::google::protobuf::RepeatedPtrField< ::operations_research::sat::DecisionStrategyProto >*       _internal_mutable_search_strategy();

    //    public:
    //        const ::operations_research::sat::DecisionStrategyProto&                                         search_strategy( int index ) const;
    //        ::operations_research::sat::DecisionStrategyProto*                                               add_search_strategy();
    //        const ::google::protobuf::RepeatedPtrField< ::operations_research::sat::DecisionStrategyProto >& search_strategy() const;
    //        // repeated int32 assumptions = 7;
    //        int assumptions_size() const;

    //    private:
    //        int _internal_assumptions_size() const;

    //    public:
    //        void                                                  clear_assumptions();
    //        ::int32_t                                             assumptions( int index ) const;
    //        void                                                  set_assumptions( int index, ::int32_t value );
    //        void                                                  add_assumptions( ::int32_t value );
    //        const ::google::protobuf::RepeatedField< ::int32_t >& assumptions() const;
    //        ::google::protobuf::RepeatedField< ::int32_t >*       mutable_assumptions();

    //    private:
    //        const ::google::protobuf::RepeatedField< ::int32_t >& _internal_assumptions() const;
    //        ::google::protobuf::RepeatedField< ::int32_t >*       _internal_mutable_assumptions();

    //    public:
    //        // string name = 1;
    //        void               clear_name();
    //        const std::string& name() const;
    //        template < typename Arg_ = const std::string&, typename... Args_ >
    //        void               set_name( Arg_&& arg, Args_... args );
    //        std::string*       mutable_name();
    //        PROTOBUF_NODISCARD std::string* release_name();
    //        void                            set_allocated_name( std::string* value );

    //    private:
    //        const std::string&                 _internal_name() const;
    //        inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(
    //            const std::string& value );
    //        std::string* _internal_mutable_name();

    //    public:
    //        // .operations_research.sat.CpObjectiveProto objective = 4;
    //        bool                                                             has_objective() const;
    //        void                                                             clear_objective();
    //        const ::operations_research::sat::CpObjectiveProto&              objective() const;
    //        PROTOBUF_NODISCARD ::operations_research::sat::CpObjectiveProto* release_objective();
    //        ::operations_research::sat::CpObjectiveProto*                    mutable_objective();
    //        void                                                             set_allocated_objective( ::operations_research::sat::CpObjectiveProto* value );
    //        void                                                             unsafe_arena_set_allocated_objective( ::operations_research::sat::CpObjectiveProto* value );
    //        ::operations_research::sat::CpObjectiveProto*                    unsafe_arena_release_objective();

    //    private:
    //        const ::operations_research::sat::CpObjectiveProto& _internal_objective() const;
    //        ::operations_research::sat::CpObjectiveProto*       _internal_mutable_objective();

    //    public:
    //        // .operations_research.sat.PartialVariableAssignment solution_hint = 6;
    //        bool                                                                      has_solution_hint() const;
    //        void                                                                      clear_solution_hint();
    //        const ::operations_research::sat::PartialVariableAssignment&              solution_hint() const;
    //        PROTOBUF_NODISCARD ::operations_research::sat::PartialVariableAssignment* release_solution_hint();
    //        ::operations_research::sat::PartialVariableAssignment*                    mutable_solution_hint();
    //        void                                                                      set_allocated_solution_hint( ::operations_research::sat::PartialVariableAssignment* value );
    //        void                                                                      unsafe_arena_set_allocated_solution_hint( ::operations_research::sat::PartialVariableAssignment* value );
    //        ::operations_research::sat::PartialVariableAssignment*                    unsafe_arena_release_solution_hint();

    //    private:
    //        const ::operations_research::sat::PartialVariableAssignment& _internal_solution_hint() const;
    //        ::operations_research::sat::PartialVariableAssignment*       _internal_mutable_solution_hint();

    //    public:
    //        // .operations_research.sat.SymmetryProto symmetry = 8;
    //        bool                                                          has_symmetry() const;
    //        void                                                          clear_symmetry();
    //        const ::operations_research::sat::SymmetryProto&              symmetry() const;
    //        PROTOBUF_NODISCARD ::operations_research::sat::SymmetryProto* release_symmetry();
    //        ::operations_research::sat::SymmetryProto*                    mutable_symmetry();
    //        void                                                          set_allocated_symmetry( ::operations_research::sat::SymmetryProto* value );
    //        void                                                          unsafe_arena_set_allocated_symmetry( ::operations_research::sat::SymmetryProto* value );
    //        ::operations_research::sat::SymmetryProto*                    unsafe_arena_release_symmetry();

    //    private:
    //        const ::operations_research::sat::SymmetryProto& _internal_symmetry() const;
    //        ::operations_research::sat::SymmetryProto*       _internal_mutable_symmetry();

    //    public:
    //        // .operations_research.sat.FloatObjectiveProto floating_point_objective = 9;
    //        bool                                                                has_floating_point_objective() const;
    //        void                                                                clear_floating_point_objective();
    //        const ::operations_research::sat::FloatObjectiveProto&              floating_point_objective() const;
    //        PROTOBUF_NODISCARD ::operations_research::sat::FloatObjectiveProto* release_floating_point_objective();
    //        ::operations_research::sat::FloatObjectiveProto*                    mutable_floating_point_objective();
    //        void                                                                set_allocated_floating_point_objective( ::operations_research::sat::FloatObjectiveProto* value );
    //        void                                                                unsafe_arena_set_allocated_floating_point_objective( ::operations_research::sat::FloatObjectiveProto* value );
    //        ::operations_research::sat::FloatObjectiveProto*                    unsafe_arena_release_floating_point_objective();

    //    private:
    //        const ::operations_research::sat::FloatObjectiveProto& _internal_floating_point_objective() const;
    //        ::operations_research::sat::FloatObjectiveProto*       _internal_mutable_floating_point_objective();

    //    public:
    //        // @@protoc_insertion_point(class_scope:operations_research.sat.CpModelProto)
    //    private:
    //        class _Internal;
    //        friend class ::google::protobuf::internal::TcParser;
    //        static const ::google::protobuf::internal::TcParseTable<
    //            4, 9, 7,
    //            57, 2 >
    //            _table_;
    //        friend class ::google::protobuf::MessageLite;
    //        friend class ::google::protobuf::Arena;
    //        template < typename T >
    //        friend class ::google::protobuf::Arena::InternalHelper;
    //        using InternalArenaConstructable_ = void;
    //        using DestructorSkippable_        = void;
    //        struct Impl_
    //        {
    //            inline explicit constexpr Impl_(
    //                ::google::protobuf::internal::ConstantInitialized ) noexcept;
    //            inline explicit Impl_( ::google::protobuf::internal::InternalVisibility visibility,
    //                                   ::google::protobuf::Arena*                       arena );
    //            inline explicit Impl_( ::google::protobuf::internal::InternalVisibility visibility,
    //                                   ::google::protobuf::Arena* arena, const Impl_& from );
    //            ::google::protobuf::internal::HasBits< 1 >                                                _has_bits_;
    //            mutable ::google::protobuf::internal::CachedSize                                          _cached_size_;
    //            ::google::protobuf::RepeatedPtrField< ::operations_research::sat::IntegerVariableProto >  variables_;
    //            ::google::protobuf::RepeatedPtrField< ::operations_research::sat::ConstraintProto >       constraints_;
    //            ::google::protobuf::RepeatedPtrField< ::operations_research::sat::DecisionStrategyProto > search_strategy_;
    //            ::google::protobuf::RepeatedField< ::int32_t >                                            assumptions_;
    //            mutable ::google::protobuf::internal::CachedSize                                          _assumptions_cached_byte_size_;
    //            ::google::protobuf::internal::ArenaStringPtr                                              name_;
    //            ::operations_research::sat::CpObjectiveProto*                                             objective_;
    //            ::operations_research::sat::PartialVariableAssignment*                                    solution_hint_;
    //            ::operations_research::sat::SymmetryProto*                                                symmetry_;
    //            ::operations_research::sat::FloatObjectiveProto*                                          floating_point_objective_;
    //            PROTOBUF_TSAN_DECLARE_MEMBER
    //        };
    //        union
    //        {
    //            Impl_ _impl_;
    //        };
    //        friend struct ::TableStruct_ortools_2fsat_2fcp_5fmodel_2eproto;
};

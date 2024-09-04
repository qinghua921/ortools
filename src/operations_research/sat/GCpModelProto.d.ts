
export class CpModelProto  
{
    // public:
    //     inline CpModelProto()
    //         : CpModelProto( nullptr ) {}
    //     ~CpModelProto() override;
    //     explicit PROTOBUF_CONSTEXPR CpModelProto( ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized );

    //     CpModelProto( const CpModelProto& from );
    //     CpModelProto( CpModelProto&& from ) noexcept
    //         : CpModelProto()
    //     {
    //         *this = ::std::move( from );
    //     }

    //     inline CpModelProto& operator=( const CpModelProto& from )
    //     {
    //         CopyFrom( from );
    //         return *this;
    //     }
    //     inline CpModelProto& operator=( CpModelProto&& from ) noexcept
    //     {
    //         if ( this == &from ) return *this;
    //         if ( GetOwningArena() == from.GetOwningArena()
    // #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
    //              && GetOwningArena() != nullptr
    // #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    //         )
    //         {
    //             InternalSwap( &from );
    //         }
    //         else
    //         {
    //             CopyFrom( from );
    //         }
    //         return *this;
    //     }

    //     static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor()
    //     {
    //         return GetDescriptor();
    //     }
    //     static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor()
    //     {
    //         return default_instance().GetMetadata().descriptor;
    //     }
    //     static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection()
    //     {
    //         return default_instance().GetMetadata().reflection;
    //     }
    //     static const CpModelProto& default_instance()
    //     {
    //         return *internal_default_instance();
    //     }
    //     static inline const CpModelProto* internal_default_instance()
    //     {
    //         return reinterpret_cast< const CpModelProto* >(
    //             &_CpModelProto_default_instance_ );
    //     }
    //     static constexpr int kIndexInFileMessages =
    //         27;

    //     friend void swap( CpModelProto& a, CpModelProto& b )
    //     {
    //         a.Swap( &b );
    //     }
    //     inline void Swap( CpModelProto* other )
    //     {
    //         if ( other == this ) return;
    // #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    //         if ( GetOwningArena() != nullptr && GetOwningArena() == other->GetOwningArena() )
    //         {
    // #else   // PROTOBUF_FORCE_COPY_IN_SWAP
    //         if ( GetOwningArena() == other->GetOwningArena() )
    //         {
    // #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
    //             InternalSwap( other );
    //         }
    //         else
    //         {
    //             ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap( this, other );
    //         }
    //     }
    //     void UnsafeArenaSwap( CpModelProto* other )
    //     {
    //         if ( other == this ) return;
    //         GOOGLE_DCHECK( GetOwningArena() == other->GetOwningArena() );
    //         InternalSwap( other );
    //     }

    //     // implements Message ----------------------------------------------

    //     CpModelProto* New( ::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr ) const final
    //     {
    //         return CreateMaybeMessage< CpModelProto >( arena );
    //     }
    //     using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
    //     void CopyFrom( const CpModelProto& from );
    //     using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
    //     void MergeFrom( const CpModelProto& from )
    //     {
    //         CpModelProto::MergeImpl( *this, from );
    //     }

    // private:
    //     static void MergeImpl( ::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg );

    // public:
    //     PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
    //     bool                                  IsInitialized() const final;

    //     size_t      ByteSizeLong() const final;
    //     const char* _InternalParse( const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx ) final;
    //     uint8_t*    _InternalSerialize(
    //            uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream ) const final;
    //     int GetCachedSize() const final
    //     {
    //         return _impl_._cached_size_.Get();
    //     }

    // private:
    //     void SharedCtor( ::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned );
    //     void SharedDtor();
    //     void SetCachedSize( int size ) const final;
    //     void InternalSwap( CpModelProto* other );

    // private:
    //     friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
    //     static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName()
    //     {
    //         return "operations_research.sat.CpModelProto";
    //     }

    // protected:
    //     explicit CpModelProto( ::PROTOBUF_NAMESPACE_ID::Arena* arena,
    //                            bool                            is_message_owned = false );

    // public:
    //     static const ClassData                             _class_data_;
    //     const ::PROTOBUF_NAMESPACE_ID::Message::ClassData* GetClassData() const final;

    //     ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

    //     // nested types ----------------------------------------------------

    //     // accessors -------------------------------------------------------

    //     enum : int
    //     {
    //         kVariablesFieldNumber              = 2,
    //         kConstraintsFieldNumber            = 3,
    //         kSearchStrategyFieldNumber         = 5,
    //         kAssumptionsFieldNumber            = 7,
    //         kNameFieldNumber                   = 1,
    //         kObjectiveFieldNumber              = 4,
    //         kSolutionHintFieldNumber           = 6,
    //         kSymmetryFieldNumber               = 8,
    //         kFloatingPointObjectiveFieldNumber = 9,
    //     };
    //     // repeated .operations_research.sat.IntegerVariableProto variables = 2;
    //     int variables_size() const;

    // private:
    //     int _internal_variables_size() const;

    // public:
    //     void                                              clear_variables();
    //     ::operations_research::sat::IntegerVariableProto* mutable_variables( int index );
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::IntegerVariableProto >*
    //     mutable_variables();

    // private:
    //     const ::operations_research::sat::IntegerVariableProto& _internal_variables( int index ) const;
    //     ::operations_research::sat::IntegerVariableProto*       _internal_add_variables();

    // public:
    //     const ::operations_research::sat::IntegerVariableProto& variables( int index ) const;
    //     ::operations_research::sat::IntegerVariableProto*       add_variables();
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::IntegerVariableProto >&
    //     variables() const;

    //     // repeated .operations_research.sat.ConstraintProto constraints = 3;
    //     int constraints_size() const;

    // private:
    //     int _internal_constraints_size() const;

    // public:
    //     void                                         clear_constraints();
    //     ::operations_research::sat::ConstraintProto* mutable_constraints( int index );
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::ConstraintProto >*
    //     mutable_constraints();

    // private:
    //     const ::operations_research::sat::ConstraintProto& _internal_constraints( int index ) const;
    //     ::operations_research::sat::ConstraintProto*       _internal_add_constraints();

    // public:
    //     const ::operations_research::sat::ConstraintProto& constraints( int index ) const;
    //     ::operations_research::sat::ConstraintProto*       add_constraints();
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::ConstraintProto >&
    //     constraints() const;

    //     // repeated .operations_research.sat.DecisionStrategyProto search_strategy = 5;
    //     int search_strategy_size() const;

    // private:
    //     int _internal_search_strategy_size() const;

    // public:
    //     void                                               clear_search_strategy();
    //     ::operations_research::sat::DecisionStrategyProto* mutable_search_strategy( int index );
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::DecisionStrategyProto >*
    //     mutable_search_strategy();

    // private:
    //     const ::operations_research::sat::DecisionStrategyProto& _internal_search_strategy( int index ) const;
    //     ::operations_research::sat::DecisionStrategyProto*       _internal_add_search_strategy();

    // public:
    //     const ::operations_research::sat::DecisionStrategyProto& search_strategy( int index ) const;
    //     ::operations_research::sat::DecisionStrategyProto*       add_search_strategy();
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::DecisionStrategyProto >&
    //     search_strategy() const;

    //     // repeated int32 assumptions = 7;
    //     int assumptions_size() const;

    // private:
    //     int _internal_assumptions_size() const;

    // public:
    //     void clear_assumptions();

    // private:
    //     int32_t _internal_assumptions( int index ) const;
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
    //          _internal_assumptions() const;
    //     void _internal_add_assumptions( int32_t value );
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
    //     _internal_mutable_assumptions();

    // public:
    //     int32_t assumptions( int index ) const;
    //     void    set_assumptions( int index, int32_t value );
    //     void    add_assumptions( int32_t value );
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
    //     assumptions() const;
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
    //     mutable_assumptions();

    //     // string name = 1;
    //     void               clear_name();
    //     const std::string& name() const;
    //     template < typename ArgT0 = const std::string&, typename... ArgT >
    //     void               set_name( ArgT0&& arg0, ArgT... args );
    //     std::string*       mutable_name();
    //     PROTOBUF_NODISCARD std::string* release_name();
    //     void                            set_allocated_name( std::string* name );

    // private:
    //     const std::string&                 _internal_name() const;
    //     inline PROTOBUF_ALWAYS_INLINE void _internal_set_name( const std::string& value );
    //     std::string*                       _internal_mutable_name();

    // public:
    //     // .operations_research.sat.CpObjectiveProto objective = 4;
    //     bool has_objective() const;

    // private:
    //     bool _internal_has_objective() const;

    // public:
    //     void                                                             clear_objective();
    //     const ::operations_research::sat::CpObjectiveProto&              objective() const;
    //     PROTOBUF_NODISCARD ::operations_research::sat::CpObjectiveProto* release_objective();
    //     ::operations_research::sat::CpObjectiveProto*                    mutable_objective();
    //     void                                                             set_allocated_objective( ::operations_research::sat::CpObjectiveProto* objective );

    // private:
    //     const ::operations_research::sat::CpObjectiveProto& _internal_objective() const;
    //     ::operations_research::sat::CpObjectiveProto*       _internal_mutable_objective();

    // public:
    //     void unsafe_arena_set_allocated_objective(
    //         ::operations_research::sat::CpObjectiveProto* objective );
    //     ::operations_research::sat::CpObjectiveProto* unsafe_arena_release_objective();

    //     // .operations_research.sat.PartialVariableAssignment solution_hint = 6;
    //     bool has_solution_hint() const;

    // private:
    //     bool _internal_has_solution_hint() const;

    // public:
    //     void                                                                      clear_solution_hint();
    //     const ::operations_research::sat::PartialVariableAssignment&              solution_hint() const;
    //     PROTOBUF_NODISCARD ::operations_research::sat::PartialVariableAssignment* release_solution_hint();
    //     ::operations_research::sat::PartialVariableAssignment*                    mutable_solution_hint();
    //     void                                                                      set_allocated_solution_hint( ::operations_research::sat::PartialVariableAssignment* solution_hint );

    // private:
    //     const ::operations_research::sat::PartialVariableAssignment& _internal_solution_hint() const;
    //     ::operations_research::sat::PartialVariableAssignment*       _internal_mutable_solution_hint();

    // public:
    //     void unsafe_arena_set_allocated_solution_hint(
    //         ::operations_research::sat::PartialVariableAssignment* solution_hint );
    //     ::operations_research::sat::PartialVariableAssignment* unsafe_arena_release_solution_hint();

    //     // .operations_research.sat.SymmetryProto symmetry = 8;
    //     bool has_symmetry() const;

    // private:
    //     bool _internal_has_symmetry() const;

    // public:
    //     void                                                          clear_symmetry();
    //     const ::operations_research::sat::SymmetryProto&              symmetry() const;
    //     PROTOBUF_NODISCARD ::operations_research::sat::SymmetryProto* release_symmetry();
    //     ::operations_research::sat::SymmetryProto*                    mutable_symmetry();
    //     void                                                          set_allocated_symmetry( ::operations_research::sat::SymmetryProto* symmetry );

    // private:
    //     const ::operations_research::sat::SymmetryProto& _internal_symmetry() const;
    //     ::operations_research::sat::SymmetryProto*       _internal_mutable_symmetry();

    // public:
    //     void unsafe_arena_set_allocated_symmetry(
    //         ::operations_research::sat::SymmetryProto* symmetry );
    //     ::operations_research::sat::SymmetryProto* unsafe_arena_release_symmetry();

    //     // .operations_research.sat.FloatObjectiveProto floating_point_objective = 9;
    //     bool has_floating_point_objective() const;

    // private:
    //     bool _internal_has_floating_point_objective() const;

    // public:
    //     void                                                                clear_floating_point_objective();
    //     const ::operations_research::sat::FloatObjectiveProto&              floating_point_objective() const;
    //     PROTOBUF_NODISCARD ::operations_research::sat::FloatObjectiveProto* release_floating_point_objective();
    //     ::operations_research::sat::FloatObjectiveProto*                    mutable_floating_point_objective();
    //     void                                                                set_allocated_floating_point_objective( ::operations_research::sat::FloatObjectiveProto* floating_point_objective );

    // private:
    //     const ::operations_research::sat::FloatObjectiveProto& _internal_floating_point_objective() const;
    //     ::operations_research::sat::FloatObjectiveProto*       _internal_mutable_floating_point_objective();

    // public:
    //     void unsafe_arena_set_allocated_floating_point_objective(
    //         ::operations_research::sat::FloatObjectiveProto* floating_point_objective );
    //     ::operations_research::sat::FloatObjectiveProto* unsafe_arena_release_floating_point_objective();

    //     // @@protoc_insertion_point(class_scope:operations_research.sat.CpModelProto)
    // private:
    //     class _Internal;

    //     template < typename T >
    //     friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
    //     typedef void InternalArenaConstructable_;
    //     typedef void DestructorSkippable_;
    //     struct Impl_
    //     {
    //         ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::IntegerVariableProto >  variables_;
    //         ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::ConstraintProto >       constraints_;
    //         ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::DecisionStrategyProto > search_strategy_;
    //         ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >                                              assumptions_;
    //         mutable std::atomic< int >                                                                     _assumptions_cached_byte_size_;
    //         ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr                                              name_;
    //         ::operations_research::sat::CpObjectiveProto*                                                  objective_;
    //         ::operations_research::sat::PartialVariableAssignment*                                         solution_hint_;
    //         ::operations_research::sat::SymmetryProto*                                                     symmetry_;
    //         ::operations_research::sat::FloatObjectiveProto*                                               floating_point_objective_;
    //         mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize                                          _cached_size_;
    //     };
    //     union
    //     {
    //         Impl_ _impl_;
    //     };
    //     friend struct ::TableStruct_ortools_2fsat_2fcp_5fmodel_2eproto;
}


export class MPModelProto 
{
    // public:
    //     inline MPModelProto()
    //         : MPModelProto( nullptr ) {}
    //     ~MPModelProto() override;
    //     explicit PROTOBUF_CONSTEXPR MPModelProto( ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized );

    //     MPModelProto( const MPModelProto& from );
    //     MPModelProto( MPModelProto&& from ) noexcept
    //         : MPModelProto()
    //     {
    //         *this = ::std::move( from );
    //     }

    //     inline MPModelProto& operator=( const MPModelProto& from )
    //     {
    //         CopyFrom( from );
    //         return *this;
    //     }
    //     inline MPModelProto& operator=( MPModelProto&& from ) noexcept
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

    //     inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const
    //     {
    //         return _internal_metadata_.unknown_fields< ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet >( ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance );
    //     }
    //     inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields()
    //     {
    //         return _internal_metadata_.mutable_unknown_fields< ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet >();
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
    //     static const MPModelProto& default_instance()
    //     {
    //         return *internal_default_instance();
    //     }
    //     static inline const MPModelProto* internal_default_instance()
    //     {
    //         return reinterpret_cast< const MPModelProto* >(
    //             &_MPModelProto_default_instance_ );
    //     }
    //     static constexpr int kIndexInFileMessages =
    //         12;

    //     friend void swap( MPModelProto& a, MPModelProto& b )
    //     {
    //         a.Swap( &b );
    //     }
    //     inline void Swap( MPModelProto* other )
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
    //     void UnsafeArenaSwap( MPModelProto* other )
    //     {
    //         if ( other == this ) return;
    //         GOOGLE_DCHECK( GetOwningArena() == other->GetOwningArena() );
    //         InternalSwap( other );
    //     }

    //     // implements Message ----------------------------------------------

    //     MPModelProto* New( ::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr ) const final
    //     {
    //         return CreateMaybeMessage< MPModelProto >( arena );
    //     }
    //     using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
    //     void CopyFrom( const MPModelProto& from );
    //     using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
    //     void MergeFrom( const MPModelProto& from )
    //     {
    //         MPModelProto::MergeImpl( *this, from );
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
    //     void InternalSwap( MPModelProto* other );

    // private:
    //     friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
    //     static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName()
    //     {
    //         return "operations_research.MPModelProto";
    //     }

    // protected:
    //     explicit MPModelProto( ::PROTOBUF_NAMESPACE_ID::Arena* arena,
    //                            bool                            is_message_owned = false );

    // public:
    //     static const ClassData                             _class_data_;
    //     const ::PROTOBUF_NAMESPACE_ID::Message::ClassData* GetClassData() const final;

    //     ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

    //     // nested types ----------------------------------------------------

    //     typedef MPModelProto_Annotation Annotation;

    //     // accessors -------------------------------------------------------

    //     enum : int
    //     {
    //         kVariableFieldNumber           = 3,
    //         kConstraintFieldNumber         = 4,
    //         kGeneralConstraintFieldNumber  = 7,
    //         kAnnotationFieldNumber         = 9,
    //         kNameFieldNumber               = 5,
    //         kSolutionHintFieldNumber       = 6,
    //         kQuadraticObjectiveFieldNumber = 8,
    //         kObjectiveOffsetFieldNumber    = 2,
    //         kMaximizeFieldNumber           = 1,
    //     };
    //     // repeated .operations_research.MPVariableProto variable = 3;
    //     int variable_size() const;

    // private:
    //     int _internal_variable_size() const;

    // public:
    //     void                                    clear_variable();
    //     ::operations_research::MPVariableProto* mutable_variable( int index );
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPVariableProto >*
    //     mutable_variable();

    // private:
    //     const ::operations_research::MPVariableProto& _internal_variable( int index ) const;
    //     ::operations_research::MPVariableProto*       _internal_add_variable();

    // public:
    //     const ::operations_research::MPVariableProto& variable( int index ) const;
    //     ::operations_research::MPVariableProto*       add_variable();
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPVariableProto >&
    //     variable() const;

    //     // repeated .operations_research.MPConstraintProto constraint = 4;
    //     int constraint_size() const;

    // private:
    //     int _internal_constraint_size() const;

    // public:
    //     void                                      clear_constraint();
    //     ::operations_research::MPConstraintProto* mutable_constraint( int index );
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPConstraintProto >*
    //     mutable_constraint();

    // private:
    //     const ::operations_research::MPConstraintProto& _internal_constraint( int index ) const;
    //     ::operations_research::MPConstraintProto*       _internal_add_constraint();

    // public:
    //     const ::operations_research::MPConstraintProto& constraint( int index ) const;
    //     ::operations_research::MPConstraintProto*       add_constraint();
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPConstraintProto >&
    //     constraint() const;

    //     // repeated .operations_research.MPGeneralConstraintProto general_constraint = 7;
    //     int general_constraint_size() const;

    // private:
    //     int _internal_general_constraint_size() const;

    // public:
    //     void                                             clear_general_constraint();
    //     ::operations_research::MPGeneralConstraintProto* mutable_general_constraint( int index );
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPGeneralConstraintProto >*
    //     mutable_general_constraint();

    // private:
    //     const ::operations_research::MPGeneralConstraintProto& _internal_general_constraint( int index ) const;
    //     ::operations_research::MPGeneralConstraintProto*       _internal_add_general_constraint();

    // public:
    //     const ::operations_research::MPGeneralConstraintProto& general_constraint( int index ) const;
    //     ::operations_research::MPGeneralConstraintProto*       add_general_constraint();
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPGeneralConstraintProto >&
    //     general_constraint() const;

    //     // repeated .operations_research.MPModelProto.Annotation annotation = 9;
    //     int annotation_size() const;

    // private:
    //     int _internal_annotation_size() const;

    // public:
    //     void                                            clear_annotation();
    //     ::operations_research::MPModelProto_Annotation* mutable_annotation( int index );
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPModelProto_Annotation >*
    //     mutable_annotation();

    // private:
    //     const ::operations_research::MPModelProto_Annotation& _internal_annotation( int index ) const;
    //     ::operations_research::MPModelProto_Annotation*       _internal_add_annotation();

    // public:
    //     const ::operations_research::MPModelProto_Annotation& annotation( int index ) const;
    //     ::operations_research::MPModelProto_Annotation*       add_annotation();
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPModelProto_Annotation >&
    //     annotation() const;

    //     // optional string name = 5 [default = ""];
    //     bool has_name() const;

    // private:
    //     bool _internal_has_name() const;

    // public:
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
    //     // optional .operations_research.PartialVariableAssignment solution_hint = 6;
    //     bool has_solution_hint() const;

    // private:
    //     bool _internal_has_solution_hint() const;

    // public:
    //     void                                                                 clear_solution_hint();
    //     const ::operations_research::PartialVariableAssignment&              solution_hint() const;
    //     PROTOBUF_NODISCARD ::operations_research::PartialVariableAssignment* release_solution_hint();
    //     ::operations_research::PartialVariableAssignment*                    mutable_solution_hint();
    //     void                                                                 set_allocated_solution_hint( ::operations_research::PartialVariableAssignment* solution_hint );

    // private:
    //     const ::operations_research::PartialVariableAssignment& _internal_solution_hint() const;
    //     ::operations_research::PartialVariableAssignment*       _internal_mutable_solution_hint();

    // public:
    //     void unsafe_arena_set_allocated_solution_hint(
    //         ::operations_research::PartialVariableAssignment* solution_hint );
    //     ::operations_research::PartialVariableAssignment* unsafe_arena_release_solution_hint();

    //     // optional .operations_research.MPQuadraticObjective quadratic_objective = 8;
    //     bool has_quadratic_objective() const;

    // private:
    //     bool _internal_has_quadratic_objective() const;

    // public:
    //     void                                                            clear_quadratic_objective();
    //     const ::operations_research::MPQuadraticObjective&              quadratic_objective() const;
    //     PROTOBUF_NODISCARD ::operations_research::MPQuadraticObjective* release_quadratic_objective();
    //     ::operations_research::MPQuadraticObjective*                    mutable_quadratic_objective();
    //     void                                                            set_allocated_quadratic_objective( ::operations_research::MPQuadraticObjective* quadratic_objective );

    // private:
    //     const ::operations_research::MPQuadraticObjective& _internal_quadratic_objective() const;
    //     ::operations_research::MPQuadraticObjective*       _internal_mutable_quadratic_objective();

    // public:
    //     void unsafe_arena_set_allocated_quadratic_objective(
    //         ::operations_research::MPQuadraticObjective* quadratic_objective );
    //     ::operations_research::MPQuadraticObjective* unsafe_arena_release_quadratic_objective();

    //     // optional double objective_offset = 2 [default = 0];
    //     bool has_objective_offset() const;

    // private:
    //     bool _internal_has_objective_offset() const;

    // public:
    //     void   clear_objective_offset();
    //     double objective_offset() const;
    //     void   set_objective_offset( double value );

    // private:
    //     double _internal_objective_offset() const;
    //     void   _internal_set_objective_offset( double value );

    // public:
    //     // optional bool maximize = 1 [default = false];
    //     bool has_maximize() const;

    // private:
    //     bool _internal_has_maximize() const;

    // public:
    //     void clear_maximize();
    //     bool maximize() const;
    //     void set_maximize( bool value );

    // private:
    //     bool _internal_maximize() const;
    //     void _internal_set_maximize( bool value );

    // public:
    //     // @@protoc_insertion_point(class_scope:operations_research.MPModelProto)
    // private:
    //     class _Internal;

    //     template < typename T >
    //     friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
    //     typedef void InternalArenaConstructable_;
    //     typedef void DestructorSkippable_;
    //     struct Impl_
    //     {
    //         ::PROTOBUF_NAMESPACE_ID::internal::HasBits< 1 >                                              _has_bits_;
    //         mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize                                        _cached_size_;
    //         ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPVariableProto >          variable_;
    //         ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPConstraintProto >        constraint_;
    //         ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPGeneralConstraintProto > general_constraint_;
    //         ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPModelProto_Annotation >  annotation_;
    //         ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr                                            name_;
    //         ::operations_research::PartialVariableAssignment*                                            solution_hint_;
    //         ::operations_research::MPQuadraticObjective*                                                 quadratic_objective_;
    //         double                                                                                       objective_offset_;
    //         bool                                                                                         maximize_;
    //     };
    //     union
    //     {
    //         Impl_ _impl_;
    //     };
    //     friend struct ::TableStruct_ortools_2flinear_5fsolver_2flinear_5fsolver_2eproto;
}

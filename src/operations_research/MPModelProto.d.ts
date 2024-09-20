declare namespace operations_research
{
    declare class MPModelProto //final : public ::google::protobuf::Message
    {
        // public:
        //     inline MPModelProto()
        //         : MPModelProto( nullptr ) {}
        //     ~MPModelProto() override;
        //     template < typename = void >
        //     explicit PROTOBUF_CONSTEXPR MPModelProto(
        //         ::google::protobuf::internal::ConstantInitialized );

        //     inline MPModelProto( const MPModelProto& from )
        //         : MPModelProto( nullptr, from ) {}
        //     inline MPModelProto( MPModelProto&& from ) noexcept
        //         : MPModelProto( nullptr, std::move( from ) ) {}
        //     inline MPModelProto& operator=( const MPModelProto& from )
        //     {
        //         CopyFrom( from );
        //         return *this;
        //     }
        //     inline MPModelProto& operator=( MPModelProto&& from ) noexcept
        //     {
        //         if ( this == &from ) return *this;
        //         if ( GetArena() == from.GetArena()
        // #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        //              && GetArena() != nullptr
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

        //     inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
        //         ABSL_ATTRIBUTE_LIFETIME_BOUND
        //     {
        //         return _internal_metadata_.unknown_fields< ::google::protobuf::UnknownFieldSet >( ::google::protobuf::UnknownFieldSet::default_instance );
        //     }
        //     inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
        //         ABSL_ATTRIBUTE_LIFETIME_BOUND
        //     {
        //         return _internal_metadata_.mutable_unknown_fields< ::google::protobuf::UnknownFieldSet >();
        //     }

        //     static const ::google::protobuf::Descriptor* descriptor()
        //     {
        //         return GetDescriptor();
        //     }
        //     static const ::google::protobuf::Descriptor* GetDescriptor()
        //     {
        //         return default_instance().GetMetadata().descriptor;
        //     }
        //     static const ::google::protobuf::Reflection* GetReflection()
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
        //     static constexpr int kIndexInFileMessages = 12;
        //     friend void          swap( MPModelProto& a, MPModelProto& b )
        //     {
        //         a.Swap( &b );
        //     }
        //     inline void Swap( MPModelProto* other )
        //     {
        //         if ( other == this ) return;
        // #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
        //         if ( GetArena() != nullptr && GetArena() == other->GetArena() )
        //         {
        // #else   // PROTOBUF_FORCE_COPY_IN_SWAP
        //         if ( GetArena() == other->GetArena() )
        //         {
        // #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
        //             InternalSwap( other );
        //         }
        //         else
        //         {
        //             ::google::protobuf::internal::GenericSwap( this, other );
        //         }
        //     }
        //     void UnsafeArenaSwap( MPModelProto* other )
        //     {
        //         if ( other == this ) return;
        //         ABSL_DCHECK( GetArena() == other->GetArena() );
        //         InternalSwap( other );
        //     }

        //     // implements Message ----------------------------------------------

        //     MPModelProto* New( ::google::protobuf::Arena* arena = nullptr ) const final
        //     {
        //         return ::google::protobuf::Message::DefaultConstruct< MPModelProto >( arena );
        //     }
        //     using ::google::protobuf::Message::CopyFrom;
        //     void CopyFrom( const MPModelProto& from );
        //     using ::google::protobuf::Message::MergeFrom;
        //     void MergeFrom( const MPModelProto& from )
        //     {
        //         MPModelProto::MergeImpl( *this, from );
        //     }

        // private:
        //     static void MergeImpl(
        //         ::google::protobuf::MessageLite&       to_msg,
        //         const ::google::protobuf::MessageLite& from_msg );

        // public:
        //     ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
        //     bool                              IsInitialized() const final;

        //     ::size_t    ByteSizeLong() const final;
        //     const char* _InternalParse( const char* ptr, ::google::protobuf::internal::ParseContext* ctx ) final;
        //     ::uint8_t*  _InternalSerialize(
        //          ::uint8_t*                                   target,
        //          ::google::protobuf::io::EpsCopyOutputStream* stream ) const final;
        //     int GetCachedSize() const
        //     {
        //         return _impl_._cached_size_.Get();
        //     }

        // private:
        //     void SharedCtor( ::google::protobuf::Arena* arena );
        //     void SharedDtor();
        //     void InternalSwap( MPModelProto* other );

        // private:
        //     friend class ::google::protobuf::internal::AnyMetadata;
        //     static ::absl::string_view FullMessageName()
        //     {
        //         return "operations_research.MPModelProto";
        //     }

        // protected:
        //     explicit MPModelProto( ::google::protobuf::Arena* arena );
        //     MPModelProto( ::google::protobuf::Arena* arena, const MPModelProto& from );
        //     MPModelProto( ::google::protobuf::Arena* arena, MPModelProto&& from ) noexcept
        //         : MPModelProto( arena )
        //     {
        //         *this = ::std::move( from );
        //     }
        //     const ::google::protobuf::MessageLite::ClassData* GetClassData()
        //         const final;

        // public:
        //     ::google::protobuf::Metadata GetMetadata() const final;
        //     // nested types ----------------------------------------------------
        //     using Annotation = MPModelProto_Annotation;

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
        //     void                                                                            clear_variable();
        //     ::operations_research::MPVariableProto*                                         mutable_variable( int index );
        //     ::google::protobuf::RepeatedPtrField< ::operations_research::MPVariableProto >* mutable_variable();

        // private:
        //     const ::google::protobuf::RepeatedPtrField< ::operations_research::MPVariableProto >& _internal_variable() const;
        //     ::google::protobuf::RepeatedPtrField< ::operations_research::MPVariableProto >*       _internal_mutable_variable();

        // public:
        //     const ::operations_research::MPVariableProto&                                         variable( int index ) const;
        //     ::operations_research::MPVariableProto*                                               add_variable();
        //     const ::google::protobuf::RepeatedPtrField< ::operations_research::MPVariableProto >& variable() const;
        //     // repeated .operations_research.MPConstraintProto constraint = 4;
        //     int constraint_size() const;

        // private:
        //     int _internal_constraint_size() const;

        // public:
        //     void                                                                              clear_constraint();
        //     ::operations_research::MPConstraintProto*                                         mutable_constraint( int index );
        //     ::google::protobuf::RepeatedPtrField< ::operations_research::MPConstraintProto >* mutable_constraint();

        // private:
        //     const ::google::protobuf::RepeatedPtrField< ::operations_research::MPConstraintProto >& _internal_constraint() const;
        //     ::google::protobuf::RepeatedPtrField< ::operations_research::MPConstraintProto >*       _internal_mutable_constraint();

        // public:
        //     const ::operations_research::MPConstraintProto&                                         constraint( int index ) const;
        //     ::operations_research::MPConstraintProto*                                               add_constraint();
        //     const ::google::protobuf::RepeatedPtrField< ::operations_research::MPConstraintProto >& constraint() const;
        //     // repeated .operations_research.MPGeneralConstraintProto general_constraint = 7;
        //     int general_constraint_size() const;

        // private:
        //     int _internal_general_constraint_size() const;

        // public:
        //     void                                                                                     clear_general_constraint();
        //     ::operations_research::MPGeneralConstraintProto*                                         mutable_general_constraint( int index );
        //     ::google::protobuf::RepeatedPtrField< ::operations_research::MPGeneralConstraintProto >* mutable_general_constraint();

        // private:
        //     const ::google::protobuf::RepeatedPtrField< ::operations_research::MPGeneralConstraintProto >& _internal_general_constraint() const;
        //     ::google::protobuf::RepeatedPtrField< ::operations_research::MPGeneralConstraintProto >*       _internal_mutable_general_constraint();

        // public:
        //     const ::operations_research::MPGeneralConstraintProto&                                         general_constraint( int index ) const;
        //     ::operations_research::MPGeneralConstraintProto*                                               add_general_constraint();
        //     const ::google::protobuf::RepeatedPtrField< ::operations_research::MPGeneralConstraintProto >& general_constraint() const;
        //     // repeated .operations_research.MPModelProto.Annotation annotation = 9;
        //     int annotation_size() const;

        // private:
        //     int _internal_annotation_size() const;

        // public:
        //     void                                                                                    clear_annotation();
        //     ::operations_research::MPModelProto_Annotation*                                         mutable_annotation( int index );
        //     ::google::protobuf::RepeatedPtrField< ::operations_research::MPModelProto_Annotation >* mutable_annotation();

        // private:
        //     const ::google::protobuf::RepeatedPtrField< ::operations_research::MPModelProto_Annotation >& _internal_annotation() const;
        //     ::google::protobuf::RepeatedPtrField< ::operations_research::MPModelProto_Annotation >*       _internal_mutable_annotation();

        // public:
        //     const ::operations_research::MPModelProto_Annotation&                                         annotation( int index ) const;
        //     ::operations_research::MPModelProto_Annotation*                                               add_annotation();
        //     const ::google::protobuf::RepeatedPtrField< ::operations_research::MPModelProto_Annotation >& annotation() const;
        //     // optional string name = 5 [default = ""];
        //     bool               has_name() const;
        //     void               clear_name();
        //     const std::string& name() const;
        //     template < typename Arg_ = const std::string&, typename... Args_ >
        //     void               set_name( Arg_&& arg, Args_... args );
        //     std::string*       mutable_name();
        //     PROTOBUF_NODISCARD std::string* release_name();
        //     void                            set_allocated_name( std::string* value );

        // private:
        //     const std::string&                 _internal_name() const;
        //     inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(
        //         const std::string& value );
        //     std::string* _internal_mutable_name();

        // public:
        //     // optional .operations_research.PartialVariableAssignment solution_hint = 6;
        //     bool                                                                 has_solution_hint() const;
        //     void                                                                 clear_solution_hint();
        //     const ::operations_research::PartialVariableAssignment&              solution_hint() const;
        //     PROTOBUF_NODISCARD ::operations_research::PartialVariableAssignment* release_solution_hint();
        //     ::operations_research::PartialVariableAssignment*                    mutable_solution_hint();
        //     void                                                                 set_allocated_solution_hint( ::operations_research::PartialVariableAssignment* value );
        //     void                                                                 unsafe_arena_set_allocated_solution_hint( ::operations_research::PartialVariableAssignment* value );
        //     ::operations_research::PartialVariableAssignment*                    unsafe_arena_release_solution_hint();

        // private:
        //     const ::operations_research::PartialVariableAssignment& _internal_solution_hint() const;
        //     ::operations_research::PartialVariableAssignment*       _internal_mutable_solution_hint();

        // public:
        //     // optional .operations_research.MPQuadraticObjective quadratic_objective = 8;
        //     bool                                                            has_quadratic_objective() const;
        //     void                                                            clear_quadratic_objective();
        //     const ::operations_research::MPQuadraticObjective&              quadratic_objective() const;
        //     PROTOBUF_NODISCARD ::operations_research::MPQuadraticObjective* release_quadratic_objective();
        //     ::operations_research::MPQuadraticObjective*                    mutable_quadratic_objective();
        //     void                                                            set_allocated_quadratic_objective( ::operations_research::MPQuadraticObjective* value );
        //     void                                                            unsafe_arena_set_allocated_quadratic_objective( ::operations_research::MPQuadraticObjective* value );
        //     ::operations_research::MPQuadraticObjective*                    unsafe_arena_release_quadratic_objective();

        // private:
        //     const ::operations_research::MPQuadraticObjective& _internal_quadratic_objective() const;
        //     ::operations_research::MPQuadraticObjective*       _internal_mutable_quadratic_objective();

        // public:
        //     // optional double objective_offset = 2 [default = 0];
        //     bool   has_objective_offset() const;
        //     void   clear_objective_offset();
        //     double objective_offset() const;
        //     void   set_objective_offset( double value );

        // private:
        //     double _internal_objective_offset() const;
        //     void   _internal_set_objective_offset( double value );

        // public:
        //     // optional bool maximize = 1 [default = false];
        //     bool has_maximize() const;
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
        //     friend class ::google::protobuf::internal::TcParser;
        //     static const ::google::protobuf::internal::TcParseTable<
        //         4, 9, 6,
        //         53, 2 >
        //         _table_;
        //     friend class ::google::protobuf::MessageLite;
        //     friend class ::google::protobuf::Arena;
        //     template < typename T >
        //     friend class ::google::protobuf::Arena::InternalHelper;
        //     using InternalArenaConstructable_ = void;
        //     using DestructorSkippable_        = void;
        //     struct Impl_
        //     {
        //         inline explicit constexpr Impl_(
        //             ::google::protobuf::internal::ConstantInitialized ) noexcept;
        //         inline explicit Impl_( ::google::protobuf::internal::InternalVisibility visibility,
        //                                ::google::protobuf::Arena*                       arena );
        //         inline explicit Impl_( ::google::protobuf::internal::InternalVisibility visibility,
        //                                ::google::protobuf::Arena* arena, const Impl_& from );
        //         ::google::protobuf::internal::HasBits< 1 >                                              _has_bits_;
        //         mutable ::google::protobuf::internal::CachedSize                                        _cached_size_;
        //         ::google::protobuf::RepeatedPtrField< ::operations_research::MPVariableProto >          variable_;
        //         ::google::protobuf::RepeatedPtrField< ::operations_research::MPConstraintProto >        constraint_;
        //         ::google::protobuf::RepeatedPtrField< ::operations_research::MPGeneralConstraintProto > general_constraint_;
        //         ::google::protobuf::RepeatedPtrField< ::operations_research::MPModelProto_Annotation >  annotation_;
        //         ::google::protobuf::internal::ArenaStringPtr                                            name_;
        //         ::operations_research::PartialVariableAssignment*                                       solution_hint_;
        //         ::operations_research::MPQuadraticObjective*                                            quadratic_objective_;
        //         double                                                                                  objective_offset_;
        //         bool                                                                                    maximize_;
        //         PROTOBUF_TSAN_DECLARE_MEMBER
        //     };
        //     union
        //     {
        //         Impl_ _impl_;
        //     };
        //     friend struct ::TableStruct_ortools_2flinear_5fsolver_2flinear_5fsolver_2eproto;
    }
}
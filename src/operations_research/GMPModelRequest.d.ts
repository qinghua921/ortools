export namespace MPModelRequest
{
    export enum SolverType  
    {
        CLP_LINEAR_PROGRAMMING = 0,
        GLOP_LINEAR_PROGRAMMING = 2,
        GLPK_LINEAR_PROGRAMMING = 1,
        GUROBI_LINEAR_PROGRAMMING = 6,
        XPRESS_LINEAR_PROGRAMMING = 101,
        CPLEX_LINEAR_PROGRAMMING = 10,
        HIGHS_LINEAR_PROGRAMMING = 15,
        SCIP_MIXED_INTEGER_PROGRAMMING = 3,
        GLPK_MIXED_INTEGER_PROGRAMMING = 4,
        CBC_MIXED_INTEGER_PROGRAMMING = 5,
        GUROBI_MIXED_INTEGER_PROGRAMMING = 7,
        XPRESS_MIXED_INTEGER_PROGRAMMING = 102,
        CPLEX_MIXED_INTEGER_PROGRAMMING = 11,
        HIGHS_MIXED_INTEGER_PROGRAMMING = 16,
        BOP_INTEGER_PROGRAMMING = 12,
        SAT_INTEGER_PROGRAMMING = 14,
        PDLP_LINEAR_PROGRAMMING = 8,
        KNAPSACK_MIXED_INTEGER_PROGRAMMING = 13
    }
}

export class MPModelRequest 
{
    // public:
    //     inline MPModelRequest()
    //         : MPModelRequest( nullptr ) {}
    //     ~MPModelRequest() override;
    //     explicit PROTOBUF_CONSTEXPR MPModelRequest( ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized );

    //     MPModelRequest( const MPModelRequest& from );
    //     MPModelRequest( MPModelRequest&& from ) noexcept
    //         : MPModelRequest()
    //     {
    //         *this = ::std::move( from );
    //     }

    //     inline MPModelRequest& operator=( const MPModelRequest& from )
    //     {
    //         CopyFrom( from );
    //         return *this;
    //     }
    //     inline MPModelRequest& operator=( MPModelRequest&& from ) noexcept
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
    //     static const MPModelRequest& default_instance()
    //     {
    //         return *internal_default_instance();
    //     }
    //     static inline const MPModelRequest* internal_default_instance()
    //     {
    //         return reinterpret_cast< const MPModelRequest* >(
    //             &_MPModelRequest_default_instance_ );
    //     }
    //     static constexpr int kIndexInFileMessages =
    //         18;

    //     friend void swap( MPModelRequest& a, MPModelRequest& b )
    //     {
    //         a.Swap( &b );
    //     }
    //     inline void Swap( MPModelRequest* other )
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
    //     void UnsafeArenaSwap( MPModelRequest* other )
    //     {
    //         if ( other == this ) return;
    //         GOOGLE_DCHECK( GetOwningArena() == other->GetOwningArena() );
    //         InternalSwap( other );
    //     }

    //     // implements Message ----------------------------------------------

    //     MPModelRequest* New( ::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr ) const final
    //     {
    //         return CreateMaybeMessage< MPModelRequest >( arena );
    //     }
    //     using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
    //     void CopyFrom( const MPModelRequest& from );
    //     using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
    //     void MergeFrom( const MPModelRequest& from )
    //     {
    //         MPModelRequest::MergeImpl( *this, from );
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
    //     void InternalSwap( MPModelRequest* other );

    // private:
    //     friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
    //     static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName()
    //     {
    //         return "operations_research.MPModelRequest";
    //     }

    // protected:
    //     explicit MPModelRequest( ::PROTOBUF_NAMESPACE_ID::Arena* arena,
    //                              bool                            is_message_owned = false );

    // public:
    //     static const ClassData                             _class_data_;
    //     const ::PROTOBUF_NAMESPACE_ID::Message::ClassData* GetClassData() const final;

    //     ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

    //     // nested types ----------------------------------------------------

    //     typedef MPModelRequest_SolverType SolverType;
    //     static constexpr SolverType       CLP_LINEAR_PROGRAMMING =
    //         MPModelRequest_SolverType_CLP_LINEAR_PROGRAMMING;
    //     static constexpr SolverType GLOP_LINEAR_PROGRAMMING =
    //         MPModelRequest_SolverType_GLOP_LINEAR_PROGRAMMING;
    //     static constexpr SolverType GLPK_LINEAR_PROGRAMMING =
    //         MPModelRequest_SolverType_GLPK_LINEAR_PROGRAMMING;
    //     static constexpr SolverType GUROBI_LINEAR_PROGRAMMING =
    //         MPModelRequest_SolverType_GUROBI_LINEAR_PROGRAMMING;
    //     static constexpr SolverType XPRESS_LINEAR_PROGRAMMING =
    //         MPModelRequest_SolverType_XPRESS_LINEAR_PROGRAMMING;
    //     static constexpr SolverType CPLEX_LINEAR_PROGRAMMING =
    //         MPModelRequest_SolverType_CPLEX_LINEAR_PROGRAMMING;
    //     static constexpr SolverType HIGHS_LINEAR_PROGRAMMING =
    //         MPModelRequest_SolverType_HIGHS_LINEAR_PROGRAMMING;
    //     static constexpr SolverType SCIP_MIXED_INTEGER_PROGRAMMING =
    //         MPModelRequest_SolverType_SCIP_MIXED_INTEGER_PROGRAMMING;
    //     static constexpr SolverType GLPK_MIXED_INTEGER_PROGRAMMING =
    //         MPModelRequest_SolverType_GLPK_MIXED_INTEGER_PROGRAMMING;
    //     static constexpr SolverType CBC_MIXED_INTEGER_PROGRAMMING =
    //         MPModelRequest_SolverType_CBC_MIXED_INTEGER_PROGRAMMING;
    //     static constexpr SolverType GUROBI_MIXED_INTEGER_PROGRAMMING =
    //         MPModelRequest_SolverType_GUROBI_MIXED_INTEGER_PROGRAMMING;
    //     static constexpr SolverType XPRESS_MIXED_INTEGER_PROGRAMMING =
    //         MPModelRequest_SolverType_XPRESS_MIXED_INTEGER_PROGRAMMING;
    //     static constexpr SolverType CPLEX_MIXED_INTEGER_PROGRAMMING =
    //         MPModelRequest_SolverType_CPLEX_MIXED_INTEGER_PROGRAMMING;
    //     static constexpr SolverType HIGHS_MIXED_INTEGER_PROGRAMMING =
    //         MPModelRequest_SolverType_HIGHS_MIXED_INTEGER_PROGRAMMING;
    //     static constexpr SolverType BOP_INTEGER_PROGRAMMING =
    //         MPModelRequest_SolverType_BOP_INTEGER_PROGRAMMING;
    //     static constexpr SolverType SAT_INTEGER_PROGRAMMING =
    //         MPModelRequest_SolverType_SAT_INTEGER_PROGRAMMING;
    //     static constexpr SolverType PDLP_LINEAR_PROGRAMMING =
    //         MPModelRequest_SolverType_PDLP_LINEAR_PROGRAMMING;
    //     static constexpr SolverType KNAPSACK_MIXED_INTEGER_PROGRAMMING =
    //         MPModelRequest_SolverType_KNAPSACK_MIXED_INTEGER_PROGRAMMING;
    //     static inline bool SolverType_IsValid( int value )
    //     {
    //         return MPModelRequest_SolverType_IsValid( value );
    //     }
    //     static constexpr SolverType SolverType_MIN =
    //         MPModelRequest_SolverType_SolverType_MIN;
    //     static constexpr SolverType SolverType_MAX =
    //         MPModelRequest_SolverType_SolverType_MAX;
    //     static constexpr int SolverType_ARRAYSIZE =
    //         MPModelRequest_SolverType_SolverType_ARRAYSIZE;
    //     static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
    //     SolverType_descriptor()
    //     {
    //         return MPModelRequest_SolverType_descriptor();
    //     }
    //     template < typename T >
    //     static inline const std::string& SolverType_Name( T enum_t_value )
    //     {
    //         static_assert( ::std::is_same< T, SolverType >::value || ::std::is_integral< T >::value,
    //                        "Incorrect type passed to function SolverType_Name." );
    //         return MPModelRequest_SolverType_Name( enum_t_value );
    //     }
    //     static inline bool SolverType_Parse( ::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
    //                                          SolverType*                               value )
    //     {
    //         return MPModelRequest_SolverType_Parse( name, value );
    //     }

    //     // accessors -------------------------------------------------------

    //     enum : int
    //     {
    //         kSolverSpecificParametersFieldNumber              = 5,
    //         kModelFieldNumber                                 = 1,
    //         kModelDeltaFieldNumber                            = 8,
    //         kSolverTimeLimitSecondsFieldNumber                = 3,
    //         kEnableInternalSolverOutputFieldNumber            = 4,
    //         kIgnoreSolverSpecificParametersFailureFieldNumber = 9,
    //         kPopulateAdditionalSolutionsUpToFieldNumber       = 11,
    //         kSolverTypeFieldNumber                            = 2,
    //     };
    //     // optional string solver_specific_parameters = 5;
    //     bool has_solver_specific_parameters() const;

    // private:
    //     bool _internal_has_solver_specific_parameters() const;

    // public:
    //     void               clear_solver_specific_parameters();
    //     const std::string& solver_specific_parameters() const;
    //     template < typename ArgT0 = const std::string&, typename... ArgT >
    //     void               set_solver_specific_parameters( ArgT0&& arg0, ArgT... args );
    //     std::string*       mutable_solver_specific_parameters();
    //     PROTOBUF_NODISCARD std::string* release_solver_specific_parameters();
    //     void                            set_allocated_solver_specific_parameters( std::string* solver_specific_parameters );

    // private:
    //     const std::string&                 _internal_solver_specific_parameters() const;
    //     inline PROTOBUF_ALWAYS_INLINE void _internal_set_solver_specific_parameters( const std::string& value );
    //     std::string*                       _internal_mutable_solver_specific_parameters();

    // public:
    //     // optional .operations_research.MPModelProto model = 1;
    //     bool has_model() const;

    // private:
    //     bool _internal_has_model() const;

    // public:
    //     void                                                    clear_model();
    //     const ::operations_research::MPModelProto&              model() const;
    //     PROTOBUF_NODISCARD ::operations_research::MPModelProto* release_model();
    //     ::operations_research::MPModelProto*                    mutable_model();
    //     void                                                    set_allocated_model( ::operations_research::MPModelProto* model );

    // private:
    //     const ::operations_research::MPModelProto& _internal_model() const;
    //     ::operations_research::MPModelProto*       _internal_mutable_model();

    // public:
    //     void unsafe_arena_set_allocated_model(
    //         ::operations_research::MPModelProto* model );
    //     ::operations_research::MPModelProto* unsafe_arena_release_model();

    //     // optional .operations_research.MPModelDeltaProto model_delta = 8;
    //     bool has_model_delta() const;

    // private:
    //     bool _internal_has_model_delta() const;

    // public:
    //     void                                                         clear_model_delta();
    //     const ::operations_research::MPModelDeltaProto&              model_delta() const;
    //     PROTOBUF_NODISCARD ::operations_research::MPModelDeltaProto* release_model_delta();
    //     ::operations_research::MPModelDeltaProto*                    mutable_model_delta();
    //     void                                                         set_allocated_model_delta( ::operations_research::MPModelDeltaProto* model_delta );

    // private:
    //     const ::operations_research::MPModelDeltaProto& _internal_model_delta() const;
    //     ::operations_research::MPModelDeltaProto*       _internal_mutable_model_delta();

    // public:
    //     void unsafe_arena_set_allocated_model_delta(
    //         ::operations_research::MPModelDeltaProto* model_delta );
    //     ::operations_research::MPModelDeltaProto* unsafe_arena_release_model_delta();

    //     // optional double solver_time_limit_seconds = 3;
    //     bool has_solver_time_limit_seconds() const;

    // private:
    //     bool _internal_has_solver_time_limit_seconds() const;

    // public:
    //     void   clear_solver_time_limit_seconds();
    //     double solver_time_limit_seconds() const;
    //     void   set_solver_time_limit_seconds( double value );

    // private:
    //     double _internal_solver_time_limit_seconds() const;
    //     void   _internal_set_solver_time_limit_seconds( double value );

    // public:
    //     // optional bool enable_internal_solver_output = 4 [default = false];
    //     bool has_enable_internal_solver_output() const;

    // private:
    //     bool _internal_has_enable_internal_solver_output() const;

    // public:
    //     void clear_enable_internal_solver_output();
    //     bool enable_internal_solver_output() const;
    //     void set_enable_internal_solver_output( bool value );

    // private:
    //     bool _internal_enable_internal_solver_output() const;
    //     void _internal_set_enable_internal_solver_output( bool value );

    // public:
    //     // optional bool ignore_solver_specific_parameters_failure = 9 [default = false];
    //     bool has_ignore_solver_specific_parameters_failure() const;

    // private:
    //     bool _internal_has_ignore_solver_specific_parameters_failure() const;

    // public:
    //     void clear_ignore_solver_specific_parameters_failure();
    //     bool ignore_solver_specific_parameters_failure() const;
    //     void set_ignore_solver_specific_parameters_failure( bool value );

    // private:
    //     bool _internal_ignore_solver_specific_parameters_failure() const;
    //     void _internal_set_ignore_solver_specific_parameters_failure( bool value );

    // public:
    //     // optional int32 populate_additional_solutions_up_to = 11 [default = 0];
    //     bool has_populate_additional_solutions_up_to() const;

    // private:
    //     bool _internal_has_populate_additional_solutions_up_to() const;

    // public:
    //     void    clear_populate_additional_solutions_up_to();
    //     int32_t populate_additional_solutions_up_to() const;
    //     void    set_populate_additional_solutions_up_to( int32_t value );

    // private:
    //     int32_t _internal_populate_additional_solutions_up_to() const;
    //     void    _internal_set_populate_additional_solutions_up_to( int32_t value );

    // public:
    //     // optional .operations_research.MPModelRequest.SolverType solver_type = 2 [default = GLOP_LINEAR_PROGRAMMING];
    //     bool has_solver_type() const;

    // private:
    //     bool _internal_has_solver_type() const;

    // public:
    //     void                                             clear_solver_type();
    //     ::operations_research::MPModelRequest_SolverType solver_type() const;
    //     void                                             set_solver_type( ::operations_research::MPModelRequest_SolverType value );

    // private:
    //     ::operations_research::MPModelRequest_SolverType _internal_solver_type() const;
    //     void                                             _internal_set_solver_type( ::operations_research::MPModelRequest_SolverType value );

    // public:
    //     // @@protoc_insertion_point(class_scope:operations_research.MPModelRequest)
    // private:
    //     class _Internal;

    //     template < typename T >
    //     friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
    //     typedef void InternalArenaConstructable_;
    //     typedef void DestructorSkippable_;
    //     struct Impl_
    //     {
    //         ::PROTOBUF_NAMESPACE_ID::internal::HasBits< 1 >       _has_bits_;
    //         mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    //         ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr     solver_specific_parameters_;
    //         ::operations_research::MPModelProto*                  model_;
    //         ::operations_research::MPModelDeltaProto*             model_delta_;
    //         double                                                solver_time_limit_seconds_;
    //         bool                                                  enable_internal_solver_output_;
    //         bool                                                  ignore_solver_specific_parameters_failure_;
    //         int32_t                                               populate_additional_solutions_up_to_;
    //         int                                                   solver_type_;
    //     };
    //     union
    //     {
    //         Impl_ _impl_;
    //     };
    //     friend struct ::TableStruct_ortools_2flinear_5fsolver_2flinear_5fsolver_2eproto;
}

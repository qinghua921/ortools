declare namespace operations_research
{
    declare class MPModelRequest // final : public ::google::protobuf::Message
    {
        // public:
        //     inline MPModelRequest()
        //         : MPModelRequest( nullptr ) {}
        //     ~MPModelRequest() override;
        //     template < typename = void >
        //     explicit PROTOBUF_CONSTEXPR MPModelRequest(
        //         ::google::protobuf::internal::ConstantInitialized );

        //     inline MPModelRequest( const MPModelRequest& from )
        //         : MPModelRequest( nullptr, from ) {}
        //     inline MPModelRequest( MPModelRequest&& from ) noexcept
        //         : MPModelRequest( nullptr, std::move( from ) ) {}
        //     inline MPModelRequest& operator=( const MPModelRequest& from )
        //     {
        //         CopyFrom( from );
        //         return *this;
        //     }
        //     inline MPModelRequest& operator=( MPModelRequest&& from ) noexcept
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
        //     static const MPModelRequest& default_instance()
        //     {
        //         return *internal_default_instance();
        //     }
        //     static inline const MPModelRequest* internal_default_instance()
        //     {
        //         return reinterpret_cast< const MPModelRequest* >(
        //             &_MPModelRequest_default_instance_ );
        //     }
        //     static constexpr int kIndexInFileMessages = 18;
        //     friend void          swap( MPModelRequest& a, MPModelRequest& b )
        //     {
        //         a.Swap( &b );
        //     }
        //     inline void Swap( MPModelRequest* other )
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
        //     void UnsafeArenaSwap( MPModelRequest* other )
        //     {
        //         if ( other == this ) return;
        //         ABSL_DCHECK( GetArena() == other->GetArena() );
        //         InternalSwap( other );
        //     }

        //     // implements Message ----------------------------------------------

        //     MPModelRequest* New( ::google::protobuf::Arena* arena = nullptr ) const final
        //     {
        //         return ::google::protobuf::Message::DefaultConstruct< MPModelRequest >( arena );
        //     }
        //     using ::google::protobuf::Message::CopyFrom;
        //     void CopyFrom( const MPModelRequest& from );
        //     using ::google::protobuf::Message::MergeFrom;
        //     void MergeFrom( const MPModelRequest& from )
        //     {
        //         MPModelRequest::MergeImpl( *this, from );
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
        //     void InternalSwap( MPModelRequest* other );

        // private:
        //     friend class ::google::protobuf::internal::AnyMetadata;
        //     static ::absl::string_view FullMessageName()
        //     {
        //         return "operations_research.MPModelRequest";
        //     }

        // protected:
        //     explicit MPModelRequest( ::google::protobuf::Arena* arena );
        //     MPModelRequest( ::google::protobuf::Arena* arena, const MPModelRequest& from );
        //     MPModelRequest( ::google::protobuf::Arena* arena, MPModelRequest&& from ) noexcept
        //         : MPModelRequest( arena )
        //     {
        //         *this = ::std::move( from );
        //     }
        //     const ::google::protobuf::MessageLite::ClassData* GetClassData()
        //         const final;

        // public:
        //     ::google::protobuf::Metadata GetMetadata() const final;
        //     // nested types ----------------------------------------------------
        //     using SolverType                                               = MPModelRequest_SolverType;
        //     static constexpr SolverType CLP_LINEAR_PROGRAMMING             = MPModelRequest_SolverType_CLP_LINEAR_PROGRAMMING;
        //     static constexpr SolverType GLOP_LINEAR_PROGRAMMING            = MPModelRequest_SolverType_GLOP_LINEAR_PROGRAMMING;
        //     static constexpr SolverType GLPK_LINEAR_PROGRAMMING            = MPModelRequest_SolverType_GLPK_LINEAR_PROGRAMMING;
        //     static constexpr SolverType GUROBI_LINEAR_PROGRAMMING          = MPModelRequest_SolverType_GUROBI_LINEAR_PROGRAMMING;
        //     static constexpr SolverType XPRESS_LINEAR_PROGRAMMING          = MPModelRequest_SolverType_XPRESS_LINEAR_PROGRAMMING;
        //     static constexpr SolverType CPLEX_LINEAR_PROGRAMMING           = MPModelRequest_SolverType_CPLEX_LINEAR_PROGRAMMING;
        //     static constexpr SolverType HIGHS_LINEAR_PROGRAMMING           = MPModelRequest_SolverType_HIGHS_LINEAR_PROGRAMMING;
        //     static constexpr SolverType SCIP_MIXED_INTEGER_PROGRAMMING     = MPModelRequest_SolverType_SCIP_MIXED_INTEGER_PROGRAMMING;
        //     static constexpr SolverType GLPK_MIXED_INTEGER_PROGRAMMING     = MPModelRequest_SolverType_GLPK_MIXED_INTEGER_PROGRAMMING;
        //     static constexpr SolverType CBC_MIXED_INTEGER_PROGRAMMING      = MPModelRequest_SolverType_CBC_MIXED_INTEGER_PROGRAMMING;
        //     static constexpr SolverType GUROBI_MIXED_INTEGER_PROGRAMMING   = MPModelRequest_SolverType_GUROBI_MIXED_INTEGER_PROGRAMMING;
        //     static constexpr SolverType XPRESS_MIXED_INTEGER_PROGRAMMING   = MPModelRequest_SolverType_XPRESS_MIXED_INTEGER_PROGRAMMING;
        //     static constexpr SolverType CPLEX_MIXED_INTEGER_PROGRAMMING    = MPModelRequest_SolverType_CPLEX_MIXED_INTEGER_PROGRAMMING;
        //     static constexpr SolverType HIGHS_MIXED_INTEGER_PROGRAMMING    = MPModelRequest_SolverType_HIGHS_MIXED_INTEGER_PROGRAMMING;
        //     static constexpr SolverType BOP_INTEGER_PROGRAMMING            = MPModelRequest_SolverType_BOP_INTEGER_PROGRAMMING;
        //     static constexpr SolverType SAT_INTEGER_PROGRAMMING            = MPModelRequest_SolverType_SAT_INTEGER_PROGRAMMING;
        //     static constexpr SolverType PDLP_LINEAR_PROGRAMMING            = MPModelRequest_SolverType_PDLP_LINEAR_PROGRAMMING;
        //     static constexpr SolverType KNAPSACK_MIXED_INTEGER_PROGRAMMING = MPModelRequest_SolverType_KNAPSACK_MIXED_INTEGER_PROGRAMMING;
        //     static inline bool          SolverType_IsValid( int value )
        //     {
        //         return MPModelRequest_SolverType_IsValid( value );
        //     }
        //     static constexpr SolverType                             SolverType_MIN       = MPModelRequest_SolverType_SolverType_MIN;
        //     static constexpr SolverType                             SolverType_MAX       = MPModelRequest_SolverType_SolverType_MAX;
        //     static constexpr int                                    SolverType_ARRAYSIZE = MPModelRequest_SolverType_SolverType_ARRAYSIZE;
        //     static inline const ::google::protobuf::EnumDescriptor* SolverType_descriptor()
        //     {
        //         return MPModelRequest_SolverType_descriptor();
        //     }
        //     template < typename T >
        //     static inline const std::string& SolverType_Name( T value )
        //     {
        //         return MPModelRequest_SolverType_Name( value );
        //     }
        //     static inline bool SolverType_Parse( absl::string_view name, SolverType* value )
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
        //     bool               has_solver_specific_parameters() const;
        //     void               clear_solver_specific_parameters();
        //     const std::string& solver_specific_parameters() const;
        //     template < typename Arg_ = const std::string&, typename... Args_ >
        //     void               set_solver_specific_parameters( Arg_&& arg, Args_... args );
        //     std::string*       mutable_solver_specific_parameters();
        //     PROTOBUF_NODISCARD std::string* release_solver_specific_parameters();
        //     void                            set_allocated_solver_specific_parameters( std::string* value );

        // private:
        //     const std::string&                 _internal_solver_specific_parameters() const;
        //     inline PROTOBUF_ALWAYS_INLINE void _internal_set_solver_specific_parameters(
        //         const std::string& value );
        //     std::string* _internal_mutable_solver_specific_parameters();

        // public:
        //     // optional .operations_research.MPModelProto model = 1;
        //     bool                                                    has_model() const;
        //     void                                                    clear_model();
        //     const ::operations_research::MPModelProto&              model() const;
        //     PROTOBUF_NODISCARD ::operations_research::MPModelProto* release_model();
        //     ::operations_research::MPModelProto*                    mutable_model();
        //     void                                                    set_allocated_model( ::operations_research::MPModelProto* value );
        //     void                                                    unsafe_arena_set_allocated_model( ::operations_research::MPModelProto* value );
        //     ::operations_research::MPModelProto*                    unsafe_arena_release_model();

        // private:
        //     const ::operations_research::MPModelProto& _internal_model() const;
        //     ::operations_research::MPModelProto*       _internal_mutable_model();

        // public:
        //     // optional .operations_research.MPModelDeltaProto model_delta = 8;
        //     bool                                                         has_model_delta() const;
        //     void                                                         clear_model_delta();
        //     const ::operations_research::MPModelDeltaProto&              model_delta() const;
        //     PROTOBUF_NODISCARD ::operations_research::MPModelDeltaProto* release_model_delta();
        //     ::operations_research::MPModelDeltaProto*                    mutable_model_delta();
        //     void                                                         set_allocated_model_delta( ::operations_research::MPModelDeltaProto* value );
        //     void                                                         unsafe_arena_set_allocated_model_delta( ::operations_research::MPModelDeltaProto* value );
        //     ::operations_research::MPModelDeltaProto*                    unsafe_arena_release_model_delta();

        // private:
        //     const ::operations_research::MPModelDeltaProto& _internal_model_delta() const;
        //     ::operations_research::MPModelDeltaProto*       _internal_mutable_model_delta();

        // public:
        //     // optional double solver_time_limit_seconds = 3;
        //     bool   has_solver_time_limit_seconds() const;
        //     void   clear_solver_time_limit_seconds();
        //     double solver_time_limit_seconds() const;
        //     void   set_solver_time_limit_seconds( double value );

        // private:
        //     double _internal_solver_time_limit_seconds() const;
        //     void   _internal_set_solver_time_limit_seconds( double value );

        // public:
        //     // optional bool enable_internal_solver_output = 4 [default = false];
        //     bool has_enable_internal_solver_output() const;
        //     void clear_enable_internal_solver_output();
        //     bool enable_internal_solver_output() const;
        //     void set_enable_internal_solver_output( bool value );

        // private:
        //     bool _internal_enable_internal_solver_output() const;
        //     void _internal_set_enable_internal_solver_output( bool value );

        // public:
        //     // optional bool ignore_solver_specific_parameters_failure = 9 [default = false];
        //     bool has_ignore_solver_specific_parameters_failure() const;
        //     void clear_ignore_solver_specific_parameters_failure();
        //     bool ignore_solver_specific_parameters_failure() const;
        //     void set_ignore_solver_specific_parameters_failure( bool value );

        // private:
        //     bool _internal_ignore_solver_specific_parameters_failure() const;
        //     void _internal_set_ignore_solver_specific_parameters_failure( bool value );

        // public:
        //     // optional int32 populate_additional_solutions_up_to = 11 [default = 0];
        //     bool      has_populate_additional_solutions_up_to() const;
        //     void      clear_populate_additional_solutions_up_to();
        //     ::int32_t populate_additional_solutions_up_to() const;
        //     void      set_populate_additional_solutions_up_to( ::int32_t value );

        // private:
        //     ::int32_t _internal_populate_additional_solutions_up_to() const;
        //     void      _internal_set_populate_additional_solutions_up_to( ::int32_t value );

        // public:
        //     // optional .operations_research.MPModelRequest.SolverType solver_type = 2 [default = GLOP_LINEAR_PROGRAMMING];
        //     bool                                             has_solver_type() const;
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
        //     friend class ::google::protobuf::internal::TcParser;
        //     static const ::google::protobuf::internal::TcParseTable<
        //         4, 8, 3,
        //         77, 2 >
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
        //         ::google::protobuf::internal::HasBits< 1 >       _has_bits_;
        //         mutable ::google::protobuf::internal::CachedSize _cached_size_;
        //         ::google::protobuf::internal::ArenaStringPtr     solver_specific_parameters_;
        //         ::operations_research::MPModelProto*             model_;
        //         ::operations_research::MPModelDeltaProto*        model_delta_;
        //         double                                           solver_time_limit_seconds_;
        //         bool                                             enable_internal_solver_output_;
        //         bool                                             ignore_solver_specific_parameters_failure_;
        //         ::int32_t                                        populate_additional_solutions_up_to_;
        //         int                                              solver_type_;
        //         PROTOBUF_TSAN_DECLARE_MEMBER
        //     };
        //     union
        //     {
        //         Impl_ _impl_;
        //     };
        //     friend struct ::TableStruct_ortools_2flinear_5fsolver_2flinear_5fsolver_2eproto;
    };
}
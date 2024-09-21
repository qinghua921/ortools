declare namespace operations_research
{
    declare class MPSolutionResponse // final : public ::google::protobuf::Message
    {
        // public:
        //     inline MPSolutionResponse()
        //         : MPSolutionResponse( nullptr ) {}
        //     ~MPSolutionResponse() override;
        //     template < typename = void >
        //     explicit PROTOBUF_CONSTEXPR MPSolutionResponse(
        //         ::google::protobuf::internal::ConstantInitialized );

        //     inline MPSolutionResponse( const MPSolutionResponse& from )
        //         : MPSolutionResponse( nullptr, from ) {}
        //     inline MPSolutionResponse( MPSolutionResponse&& from ) noexcept
        //         : MPSolutionResponse( nullptr, std::move( from ) ) {}
        //     inline MPSolutionResponse& operator=( const MPSolutionResponse& from )
        //     {
        //         CopyFrom( from );
        //         return *this;
        //     }
        //     inline MPSolutionResponse& operator=( MPSolutionResponse&& from ) noexcept
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
        //     static const MPSolutionResponse& default_instance()
        //     {
        //         return *internal_default_instance();
        //     }
        //     static inline const MPSolutionResponse* internal_default_instance()
        //     {
        //         return reinterpret_cast< const MPSolutionResponse* >(
        //             &_MPSolutionResponse_default_instance_ );
        //     }
        //     static constexpr int kIndexInFileMessages = 21;
        //     friend void          swap( MPSolutionResponse& a, MPSolutionResponse& b )
        //     {
        //         a.Swap( &b );
        //     }
        //     inline void Swap( MPSolutionResponse* other )
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
        //     void UnsafeArenaSwap( MPSolutionResponse* other )
        //     {
        //         if ( other == this ) return;
        //         ABSL_DCHECK( GetArena() == other->GetArena() );
        //         InternalSwap( other );
        //     }

        //     // implements Message ----------------------------------------------

        //     MPSolutionResponse* New( ::google::protobuf::Arena* arena = nullptr ) const final
        //     {
        //         return ::google::protobuf::Message::DefaultConstruct< MPSolutionResponse >( arena );
        //     }
        //     using ::google::protobuf::Message::CopyFrom;
        //     void CopyFrom( const MPSolutionResponse& from );
        //     using ::google::protobuf::Message::MergeFrom;
        //     void MergeFrom( const MPSolutionResponse& from )
        //     {
        //         MPSolutionResponse::MergeImpl( *this, from );
        //     }


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


        // public:
        //     ::google::protobuf::Metadata GetMetadata() const final;
        //     // nested types ----------------------------------------------------

        //     // accessors -------------------------------------------------------
        //     enum : int
        //     {
        //         kVariableValueFieldNumber       = 3,
        //         kDualValueFieldNumber           = 4,
        //         kReducedCostFieldNumber         = 6,
        //         kAdditionalSolutionsFieldNumber = 8,
        //         kStatusStrFieldNumber           = 7,
        //         kSolverSpecificInfoFieldNumber  = 11,
        //         kSolveInfoFieldNumber           = 10,
        //         kObjectiveValueFieldNumber      = 2,
        //         kBestObjectiveBoundFieldNumber  = 5,
        //         kStatusFieldNumber              = 1,
        //     };
        //     // repeated double variable_value = 3 [packed = true];
        //     int variable_value_size() const;


        // public:
        //     void                                               clear_variable_value();
        //     double                                             variable_value( int index ) const;
        //     void                                               set_variable_value( int index, double value );
        //     void                                               add_variable_value( double value );
        //     const ::google::protobuf::RepeatedField< double >& variable_value() const;
        //     ::google::protobuf::RepeatedField< double >*       mutable_variable_value();


        // public:
        //     // repeated double dual_value = 4 [packed = true];
        //     int dual_value_size() const;

        // public:
        //     void                                               clear_dual_value();
        //     double                                             dual_value( int index ) const;
        //     void                                               set_dual_value( int index, double value );
        //     void                                               add_dual_value( double value );
        //     const ::google::protobuf::RepeatedField< double >& dual_value() const;
        //     ::google::protobuf::RepeatedField< double >*       mutable_dual_value();

        // public:
        //     // repeated double reduced_cost = 6 [packed = true];
        //     int reduced_cost_size() const;

        // public:
        //     void                                               clear_reduced_cost();
        //     double                                             reduced_cost( int index ) const;
        //     void                                               set_reduced_cost( int index, double value );
        //     void                                               add_reduced_cost( double value );
        //     const ::google::protobuf::RepeatedField< double >& reduced_cost() const;
        //     ::google::protobuf::RepeatedField< double >*       mutable_reduced_cost();

        // public:
        //     // repeated .operations_research.MPSolution additional_solutions = 8;
        //     int additional_solutions_size() const;

        // public:
        //     void                                                                       clear_additional_solutions();
        //     ::operations_research::MPSolution*                                         mutable_additional_solutions( int index );
        //     ::google::protobuf::RepeatedPtrField< ::operations_research::MPSolution >* mutable_additional_solutions();


        // public:
        //     const ::operations_research::MPSolution&                                         additional_solutions( int index ) const;
        //     ::operations_research::MPSolution*                                               add_additional_solutions();
        //     const ::google::protobuf::RepeatedPtrField< ::operations_research::MPSolution >& additional_solutions() const;
        //     // optional string status_str = 7;
        //     bool               has_status_str() const;
        //     void               clear_status_str();
        //     const std::string& status_str() const;
        //     template < typename Arg_ = const std::string&, typename... Args_ >
        //     void               set_status_str( Arg_&& arg, Args_... args );
        //     std::string*       mutable_status_str();
        //     PROTOBUF_NODISCARD std::string* release_status_str();
        //     void                            set_allocated_status_str( std::string* value );

        // public:
        //     // optional bytes solver_specific_info = 11;
        //     bool               has_solver_specific_info() const;
        //     void               clear_solver_specific_info();
        //     const std::string& solver_specific_info() const;
        //     template < typename Arg_ = const std::string&, typename... Args_ >
        //     void               set_solver_specific_info( Arg_&& arg, Args_... args );
        //     std::string*       mutable_solver_specific_info();
        //     PROTOBUF_NODISCARD std::string* release_solver_specific_info();
        //     void                            set_allocated_solver_specific_info( std::string* value );

        // public:
        //     // optional .operations_research.MPSolveInfo solve_info = 10;
        //     bool                                                   has_solve_info() const;
        //     void                                                   clear_solve_info();
        //     const ::operations_research::MPSolveInfo&              solve_info() const;
        //     PROTOBUF_NODISCARD ::operations_research::MPSolveInfo* release_solve_info();
        //     ::operations_research::MPSolveInfo*                    mutable_solve_info();
        //     void                                                   set_allocated_solve_info( ::operations_research::MPSolveInfo* value );
        //     void                                                   unsafe_arena_set_allocated_solve_info( ::operations_research::MPSolveInfo* value );
        //     ::operations_research::MPSolveInfo*                    unsafe_arena_release_solve_info();


        // public:
        //     // optional double objective_value = 2;
        //     bool   has_objective_value() const;
        //     void   clear_objective_value();
        //     double objective_value() const;
        //     void   set_objective_value( double value );


        // public:
        //     // optional double best_objective_bound = 5;
        //     bool   has_best_objective_bound() const;
        //     void   clear_best_objective_bound();
        //     double best_objective_bound() const;
        //     void   set_best_objective_bound( double value );


        // public:
        //     // optional .operations_research.MPSolverResponseStatus status = 1 [default = MPSOLVER_UNKNOWN_STATUS];
        //     bool                                          has_status() const;
        //     void                                          clear_status();
        //     ::operations_research::MPSolverResponseStatus status() const;
        //     void                                          set_status( ::operations_research::MPSolverResponseStatus value );


        // public:
        //     // @@protoc_insertion_point(class_scope:operations_research.MPSolutionResponse)
    };
}
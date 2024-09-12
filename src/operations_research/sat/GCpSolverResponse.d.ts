import { CpSolverStatus } from "./GEnum";

export class CpSolverResponse 
{
    // public:
    //     inline CpSolverResponse()
    //         : CpSolverResponse( nullptr ) {}
    //     ~CpSolverResponse() override;
    //     explicit PROTOBUF_CONSTEXPR CpSolverResponse( ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized );

    //     CpSolverResponse( const CpSolverResponse& from );
    //     CpSolverResponse( CpSolverResponse&& from ) noexcept
    //         : CpSolverResponse()
    //     {
    //         *this = ::std::move( from );
    //     }

    //     inline CpSolverResponse& operator=( const CpSolverResponse& from )
    //     {
    //         CopyFrom( from );
    //         return *this;
    //     }
    //     inline CpSolverResponse& operator=( CpSolverResponse&& from ) noexcept
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
    //     static const CpSolverResponse& default_instance()
    //     {
    //         return *internal_default_instance();
    //     }
    //     static inline const CpSolverResponse* internal_default_instance()
    //     {
    //         return reinterpret_cast< const CpSolverResponse* >(
    //             &_CpSolverResponse_default_instance_ );
    //     }
    //     static constexpr int kIndexInFileMessages =
    //         29;

    //     friend void swap( CpSolverResponse& a, CpSolverResponse& b )
    //     {
    //         a.Swap( &b );
    //     }
    //     inline void Swap( CpSolverResponse* other )
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
    //     void UnsafeArenaSwap( CpSolverResponse* other )
    //     {
    //         if ( other == this ) return;
    //         GOOGLE_DCHECK( GetOwningArena() == other->GetOwningArena() );
    //         InternalSwap( other );
    //     }


    //     CpSolverResponse* New( ::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr ) const final
    //     {
    //         return CreateMaybeMessage< CpSolverResponse >( arena );
    //     }
    //     using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
    //     void CopyFrom( const CpSolverResponse& from );
    //     using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
    //     void MergeFrom( const CpSolverResponse& from )
    //     {
    //         CpSolverResponse::MergeImpl( *this, from );
    //     }


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


    // public:
    //     static const ClassData                             _class_data_;
    //     const ::PROTOBUF_NAMESPACE_ID::Message::ClassData* GetClassData() const final;

    //     ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;



    //     enum : int
    //     {
    //         kSolutionFieldNumber                              = 2,
    //         kTightenedVariablesFieldNumber                    = 21,
    //         kSufficientAssumptionsForInfeasibilityFieldNumber = 23,
    //         kAdditionalSolutionsFieldNumber                   = 27,
    //         kSolutionInfoFieldNumber                          = 20,
    //         kSolveLogFieldNumber                              = 26,
    //         kIntegerObjectiveFieldNumber                      = 28,
    //         kObjectiveValueFieldNumber                        = 3,
    //         kBestObjectiveBoundFieldNumber                    = 4,
    //         kNumBooleansFieldNumber                           = 10,
    //         kNumConflictsFieldNumber                          = 11,
    //         kNumBranchesFieldNumber                           = 12,
    //         kNumBinaryPropagationsFieldNumber                 = 13,
    //         kNumIntegerPropagationsFieldNumber                = 14,
    //         kWallTimeFieldNumber                              = 15,
    //         kUserTimeFieldNumber                              = 16,
    //         kDeterministicTimeFieldNumber                     = 17,
    //         kGapIntegralFieldNumber                           = 22,
    //         kNumRestartsFieldNumber                           = 24,
    //         kNumLpIterationsFieldNumber                       = 25,
    //         kInnerObjectiveLowerBoundFieldNumber              = 29,
    //         kNumIntegersFieldNumber                           = 30,
    //         kStatusFieldNumber                                = 1,
    //     };
    //     int solution_size() const;


    // public:
    //     void clear_solution();


    // public:
    //     int64_t solution( int index ) const;
    //     void    set_solution( int index, int64_t value );
    //     void    add_solution( int64_t value );
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
    //     solution() const;
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
    //     mutable_solution();

    //     int tightened_variables_size() const;


    // public:
    //     void                                              clear_tightened_variables();
    //     ::operations_research::sat::IntegerVariableProto* mutable_tightened_variables( int index );
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::IntegerVariableProto >*
    //     mutable_tightened_variables();


    // public:
    //     const ::operations_research::sat::IntegerVariableProto& tightened_variables( int index ) const;
    //     ::operations_research::sat::IntegerVariableProto*       add_tightened_variables();
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::IntegerVariableProto >&
    //     tightened_variables() const;

    //     int sufficient_assumptions_for_infeasibility_size() const;


    // public:
    //     void clear_sufficient_assumptions_for_infeasibility();

    //     int32_t sufficient_assumptions_for_infeasibility( int index ) const;
    sufficient_assumptions_for_infeasibility(index: number): number;

    //     void    set_sufficient_assumptions_for_infeasibility( int index, int32_t value );
    //     void    add_sufficient_assumptions_for_infeasibility( int32_t value );
    
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
    //     sufficient_assumptions_for_infeasibility() const;
    sufficient_assumptions_for_infeasibility(): number[];

    //     ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
    //     mutable_sufficient_assumptions_for_infeasibility();

    //     int additional_solutions_size() const;


    // public:
    //     void                                          clear_additional_solutions();
    //     ::operations_research::sat::CpSolverSolution* mutable_additional_solutions( int index );
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::CpSolverSolution >*
    //     mutable_additional_solutions();


    // public:
    //     const ::operations_research::sat::CpSolverSolution& additional_solutions( int index ) const;
    //     ::operations_research::sat::CpSolverSolution*       add_additional_solutions();
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::CpSolverSolution >&
    //     additional_solutions() const;

    //     void               clear_solution_info();
    //     const std::string& solution_info() const;
    //     template < typename ArgT0 = const std::string&, typename... ArgT >
    //     void               set_solution_info( ArgT0&& arg0, ArgT... args );
    //     std::string*       mutable_solution_info();
    //     PROTOBUF_NODISCARD std::string* release_solution_info();
    //     void                            set_allocated_solution_info( std::string* solution_info );

    // public:
    //     void               clear_solve_log();
    //     const std::string& solve_log() const;
    //     template < typename ArgT0 = const std::string&, typename... ArgT >
    //     void               set_solve_log( ArgT0&& arg0, ArgT... args );
    //     std::string*       mutable_solve_log();
    //     PROTOBUF_NODISCARD std::string* release_solve_log();
    //     void                            set_allocated_solve_log( std::string* solve_log );

    // public:
    //     bool has_integer_objective() const;

    // public:
    //     void                                                             clear_integer_objective();
    //     const ::operations_research::sat::CpObjectiveProto&              integer_objective() const;
    //     PROTOBUF_NODISCARD ::operations_research::sat::CpObjectiveProto* release_integer_objective();
    //     ::operations_research::sat::CpObjectiveProto*                    mutable_integer_objective();
    //     void                                                             set_allocated_integer_objective( ::operations_research::sat::CpObjectiveProto* integer_objective );

    // public:
    //     void unsafe_arena_set_allocated_integer_objective(
    //         ::operations_research::sat::CpObjectiveProto* integer_objective );
    //     ::operations_research::sat::CpObjectiveProto* unsafe_arena_release_integer_objective();

    //     void   clear_objective_value();
    //     double objective_value() const;
    objective_value(): double;
    //     void   set_objective_value( double value );

    // private:
    //     double _internal_objective_value() const;
    //     void   _internal_set_objective_value( double value );

    // public:
    //     void   clear_best_objective_bound();
    //     double best_objective_bound() const;
    //     void   set_best_objective_bound( double value );

    // private:
    //     double _internal_best_objective_bound() const;
    //     void   _internal_set_best_objective_bound( double value );

    // public:
    //     void    clear_num_booleans();
    //     int64_t num_booleans() const;
    //     void    set_num_booleans( int64_t value );

    // private:
    //     int64_t _internal_num_booleans() const;
    //     void    _internal_set_num_booleans( int64_t value );

    // public:
    //     void    clear_num_conflicts();
    //     int64_t num_conflicts() const;
    //     void    set_num_conflicts( int64_t value );

    // public:
    //     void    clear_num_branches();
    //     int64_t num_branches() const;
    //     void    set_num_branches( int64_t value );

    // private:
    //     int64_t _internal_num_branches() const;
    //     void    _internal_set_num_branches( int64_t value );

    // public:
    //     void    clear_num_binary_propagations();
    //     int64_t num_binary_propagations() const;
    //     void    set_num_binary_propagations( int64_t value );

    // private:
    //     int64_t _internal_num_binary_propagations() const;
    //     void    _internal_set_num_binary_propagations( int64_t value );

    // public:
    //     void    clear_num_integer_propagations();
    //     int64_t num_integer_propagations() const;
    //     void    set_num_integer_propagations( int64_t value );

    // private:
    //     int64_t _internal_num_integer_propagations() const;
    //     void    _internal_set_num_integer_propagations( int64_t value );

    // public:
    //     void   clear_wall_time();
    //     double wall_time() const;
    //     void   set_wall_time( double value );

    // private:
    //     double _internal_wall_time() const;
    //     void   _internal_set_wall_time( double value );

    // public:
    //     void   clear_user_time();
    //     double user_time() const;
    //     void   set_user_time( double value );

    // private:
    //     double _internal_user_time() const;
    //     void   _internal_set_user_time( double value );

    // public:
    //     void   clear_deterministic_time();
    //     double deterministic_time() const;
    //     void   set_deterministic_time( double value );

    // private:
    //     double _internal_deterministic_time() const;
    //     void   _internal_set_deterministic_time( double value );

    // public:
    //     void   clear_gap_integral();
    //     double gap_integral() const;
    //     void   set_gap_integral( double value );

    // private:
    //     double _internal_gap_integral() const;
    //     void   _internal_set_gap_integral( double value );

    // public:
    //     void    clear_num_restarts();
    //     int64_t num_restarts() const;
    //     void    set_num_restarts( int64_t value );

    // private:
    //     int64_t _internal_num_restarts() const;
    //     void    _internal_set_num_restarts( int64_t value );

    // public:
    //     void    clear_num_lp_iterations();
    //     int64_t num_lp_iterations() const;
    //     void    set_num_lp_iterations( int64_t value );

    // private:
    //     int64_t _internal_num_lp_iterations() const;
    //     void    _internal_set_num_lp_iterations( int64_t value );

    // public:
    //     void    clear_inner_objective_lower_bound();
    //     int64_t inner_objective_lower_bound() const;
    //     void    set_inner_objective_lower_bound( int64_t value );

    // private:
    //     int64_t _internal_inner_objective_lower_bound() const;
    //     void    _internal_set_inner_objective_lower_bound( int64_t value );

    // public:
    //     void    clear_num_integers();
    //     int64_t num_integers() const;
    //     void    set_num_integers( int64_t value );


    // public:
    //     void                                       clear_status();

    //     ::operations_research::sat::CpSolverStatus status() const;
    status(): CpSolverStatus;

    //     void                                       set_status( ::operations_research::sat::CpSolverStatus value );
}

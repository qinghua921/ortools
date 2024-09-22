
export class CpSolverResponse // final : public ::google::protobuf::Message
{
    //    public:
    //        inline CpSolverResponse()
    //            : CpSolverResponse( nullptr ) {}
    //        ~CpSolverResponse() override;
    //        template < typename = void >
    //        explicit PROTOBUF_CONSTEXPR CpSolverResponse(
    //            ::google::protobuf::internal::ConstantInitialized );

    //        inline CpSolverResponse( const CpSolverResponse& from )
    //            : CpSolverResponse( nullptr, from ) {}
    //        inline CpSolverResponse( CpSolverResponse&& from ) noexcept
    //            : CpSolverResponse( nullptr, std::move( from ) ) {}
    //        inline CpSolverResponse& operator=( const CpSolverResponse& from )
    //        {
    //            CopyFrom( from );
    //            return *this;
    //        }
    //        inline CpSolverResponse& operator=( CpSolverResponse&& from ) noexcept
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
    //        static const CpSolverResponse& default_instance()
    //        {
    //            return *internal_default_instance();
    //        }
    //        static inline const CpSolverResponse* internal_default_instance()
    //        {
    //            return reinterpret_cast< const CpSolverResponse* >(
    //                &_CpSolverResponse_default_instance_ );
    //        }
    //        static constexpr int kIndexInFileMessages = 28;
    //        friend void          swap( CpSolverResponse& a, CpSolverResponse& b )
    //        {
    //            a.Swap( &b );
    //        }
    //        inline void Swap( CpSolverResponse* other )
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
    //        void UnsafeArenaSwap( CpSolverResponse* other )
    //        {
    //            if ( other == this ) return;
    //            ABSL_DCHECK( GetArena() == other->GetArena() );
    //            InternalSwap( other );
    //        }

    //        // implements Message ----------------------------------------------

    //        CpSolverResponse* New( ::google::protobuf::Arena* arena = nullptr ) const final
    //        {
    //            return ::google::protobuf::Message::DefaultConstruct< CpSolverResponse >( arena );
    //        }
    //        using ::google::protobuf::Message::CopyFrom;
    //        void CopyFrom( const CpSolverResponse& from );
    //        using ::google::protobuf::Message::MergeFrom;
    //        void MergeFrom( const CpSolverResponse& from )
    //        {
    //            CpSolverResponse::MergeImpl( *this, from );
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
    //        void InternalSwap( CpSolverResponse* other );

    //    private:
    //        friend class ::google::protobuf::internal::AnyMetadata;
    //        static ::absl::string_view FullMessageName()
    //        {
    //            return "operations_research.sat.CpSolverResponse";
    //        }

    //    protected:
    //        explicit CpSolverResponse( ::google::protobuf::Arena* arena );
    //        CpSolverResponse( ::google::protobuf::Arena* arena, const CpSolverResponse& from );
    //        CpSolverResponse( ::google::protobuf::Arena* arena, CpSolverResponse&& from ) noexcept
    //            : CpSolverResponse( arena )
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
    //            kSolutionFieldNumber                              = 2,
    //            kTightenedVariablesFieldNumber                    = 21,
    //            kSufficientAssumptionsForInfeasibilityFieldNumber = 23,
    //            kAdditionalSolutionsFieldNumber                   = 27,
    //            kSolutionInfoFieldNumber                          = 20,
    //            kSolveLogFieldNumber                              = 26,
    //            kIntegerObjectiveFieldNumber                      = 28,
    //            kObjectiveValueFieldNumber                        = 3,
    //            kBestObjectiveBoundFieldNumber                    = 4,
    //            kNumBooleansFieldNumber                           = 10,
    //            kNumConflictsFieldNumber                          = 11,
    //            kNumBranchesFieldNumber                           = 12,
    //            kNumBinaryPropagationsFieldNumber                 = 13,
    //            kNumIntegerPropagationsFieldNumber                = 14,
    //            kWallTimeFieldNumber                              = 15,
    //            kUserTimeFieldNumber                              = 16,
    //            kDeterministicTimeFieldNumber                     = 17,
    //            kGapIntegralFieldNumber                           = 22,
    //            kNumRestartsFieldNumber                           = 24,
    //            kNumLpIterationsFieldNumber                       = 25,
    //            kInnerObjectiveLowerBoundFieldNumber              = 29,
    //            kNumIntegersFieldNumber                           = 30,
    //            kStatusFieldNumber                                = 1,
    //        };
    //        // repeated int64 solution = 2;
    //        int solution_size() const;

    //    private:
    //        int _internal_solution_size() const;

    //    public:
    //        void                                                  clear_solution();
    //        ::int64_t                                             solution( int index ) const;
    //        void                                                  set_solution( int index, ::int64_t value );
    //        void                                                  add_solution( ::int64_t value );
    //        const ::google::protobuf::RepeatedField< ::int64_t >& solution() const;
    //        ::google::protobuf::RepeatedField< ::int64_t >*       mutable_solution();

    //    private:
    //        const ::google::protobuf::RepeatedField< ::int64_t >& _internal_solution() const;
    //        ::google::protobuf::RepeatedField< ::int64_t >*       _internal_mutable_solution();

    //    public:
    //        // repeated .operations_research.sat.IntegerVariableProto tightened_variables = 21;
    //        int tightened_variables_size() const;

    //    private:
    //        int _internal_tightened_variables_size() const;

    //    public:
    //        void                                                                                      clear_tightened_variables();
    //        ::operations_research::sat::IntegerVariableProto*                                         mutable_tightened_variables( int index );
    //        ::google::protobuf::RepeatedPtrField< ::operations_research::sat::IntegerVariableProto >* mutable_tightened_variables();

    //    private:
    //        const ::google::protobuf::RepeatedPtrField< ::operations_research::sat::IntegerVariableProto >& _internal_tightened_variables() const;
    //        ::google::protobuf::RepeatedPtrField< ::operations_research::sat::IntegerVariableProto >*       _internal_mutable_tightened_variables();

    //    public:
    //        const ::operations_research::sat::IntegerVariableProto&                                         tightened_variables( int index ) const;
    //        ::operations_research::sat::IntegerVariableProto*                                               add_tightened_variables();
    //        const ::google::protobuf::RepeatedPtrField< ::operations_research::sat::IntegerVariableProto >& tightened_variables() const;
    //        // repeated int32 sufficient_assumptions_for_infeasibility = 23;
    //        int sufficient_assumptions_for_infeasibility_size() const;

    //    private:
    //        int _internal_sufficient_assumptions_for_infeasibility_size() const;

    //    public:
    //        void                                                  clear_sufficient_assumptions_for_infeasibility();
    //        ::int32_t                                             sufficient_assumptions_for_infeasibility( int index ) const;
    //        void                                                  set_sufficient_assumptions_for_infeasibility( int index, ::int32_t value );
    //        void                                                  add_sufficient_assumptions_for_infeasibility( ::int32_t value );
    //        const ::google::protobuf::RepeatedField< ::int32_t >& sufficient_assumptions_for_infeasibility() const;
    //        ::google::protobuf::RepeatedField< ::int32_t >*       mutable_sufficient_assumptions_for_infeasibility();

    //    private:
    //        const ::google::protobuf::RepeatedField< ::int32_t >& _internal_sufficient_assumptions_for_infeasibility() const;
    //        ::google::protobuf::RepeatedField< ::int32_t >*       _internal_mutable_sufficient_assumptions_for_infeasibility();

    //    public:
    //        // repeated .operations_research.sat.CpSolverSolution additional_solutions = 27;
    //        int additional_solutions_size() const;

    //    private:
    //        int _internal_additional_solutions_size() const;

    //    public:
    //        void                                                                                  clear_additional_solutions();
    //        ::operations_research::sat::CpSolverSolution*                                         mutable_additional_solutions( int index );
    //        ::google::protobuf::RepeatedPtrField< ::operations_research::sat::CpSolverSolution >* mutable_additional_solutions();

    //    private:
    //        const ::google::protobuf::RepeatedPtrField< ::operations_research::sat::CpSolverSolution >& _internal_additional_solutions() const;
    //        ::google::protobuf::RepeatedPtrField< ::operations_research::sat::CpSolverSolution >*       _internal_mutable_additional_solutions();

    //    public:
    //        const ::operations_research::sat::CpSolverSolution&                                         additional_solutions( int index ) const;
    //        ::operations_research::sat::CpSolverSolution*                                               add_additional_solutions();
    //        const ::google::protobuf::RepeatedPtrField< ::operations_research::sat::CpSolverSolution >& additional_solutions() const;
    //        // string solution_info = 20;
    //        void               clear_solution_info();
    //        const std::string& solution_info() const;
    //        template < typename Arg_ = const std::string&, typename... Args_ >
    //        void               set_solution_info( Arg_&& arg, Args_... args );
    //        std::string*       mutable_solution_info();
    //        PROTOBUF_NODISCARD std::string* release_solution_info();
    //        void                            set_allocated_solution_info( std::string* value );

    //    private:
    //        const std::string&                 _internal_solution_info() const;
    //        inline PROTOBUF_ALWAYS_INLINE void _internal_set_solution_info(
    //            const std::string& value );
    //        std::string* _internal_mutable_solution_info();

    //    public:
    //        // string solve_log = 26;
    //        void               clear_solve_log();
    //        const std::string& solve_log() const;
    //        template < typename Arg_ = const std::string&, typename... Args_ >
    //        void               set_solve_log( Arg_&& arg, Args_... args );
    //        std::string*       mutable_solve_log();
    //        PROTOBUF_NODISCARD std::string* release_solve_log();
    //        void                            set_allocated_solve_log( std::string* value );

    //    private:
    //        const std::string&                 _internal_solve_log() const;
    //        inline PROTOBUF_ALWAYS_INLINE void _internal_set_solve_log(
    //            const std::string& value );
    //        std::string* _internal_mutable_solve_log();

    //    public:
    //        // .operations_research.sat.CpObjectiveProto integer_objective = 28;
    //        bool                                                             has_integer_objective() const;
    //        void                                                             clear_integer_objective();
    //        const ::operations_research::sat::CpObjectiveProto&              integer_objective() const;
    //        PROTOBUF_NODISCARD ::operations_research::sat::CpObjectiveProto* release_integer_objective();
    //        ::operations_research::sat::CpObjectiveProto*                    mutable_integer_objective();
    //        void                                                             set_allocated_integer_objective( ::operations_research::sat::CpObjectiveProto* value );
    //        void                                                             unsafe_arena_set_allocated_integer_objective( ::operations_research::sat::CpObjectiveProto* value );
    //        ::operations_research::sat::CpObjectiveProto*                    unsafe_arena_release_integer_objective();

    //    private:
    //        const ::operations_research::sat::CpObjectiveProto& _internal_integer_objective() const;
    //        ::operations_research::sat::CpObjectiveProto*       _internal_mutable_integer_objective();

    //    public:
    //        // double objective_value = 3;
    //        void   clear_objective_value();
    //        double objective_value() const;
    //        void   set_objective_value( double value );

    //    private:
    //        double _internal_objective_value() const;
    //        void   _internal_set_objective_value( double value );

    //    public:
    //        // double best_objective_bound = 4;
    //        void   clear_best_objective_bound();
    //        double best_objective_bound() const;
    //        void   set_best_objective_bound( double value );

    //    private:
    //        double _internal_best_objective_bound() const;
    //        void   _internal_set_best_objective_bound( double value );

    //    public:
    //        // int64 num_booleans = 10;
    //        void      clear_num_booleans();
    //        ::int64_t num_booleans() const;
    //        void      set_num_booleans( ::int64_t value );

    //    private:
    //        ::int64_t _internal_num_booleans() const;
    //        void      _internal_set_num_booleans( ::int64_t value );

    //    public:
    //        // int64 num_conflicts = 11;
    //        void      clear_num_conflicts();
    //        ::int64_t num_conflicts() const;
    //        void      set_num_conflicts( ::int64_t value );

    //    private:
    //        ::int64_t _internal_num_conflicts() const;
    //        void      _internal_set_num_conflicts( ::int64_t value );

    //    public:
    //        // int64 num_branches = 12;
    //        void      clear_num_branches();
    //        ::int64_t num_branches() const;
    //        void      set_num_branches( ::int64_t value );

    //    private:
    //        ::int64_t _internal_num_branches() const;
    //        void      _internal_set_num_branches( ::int64_t value );

    //    public:
    //        // int64 num_binary_propagations = 13;
    //        void      clear_num_binary_propagations();
    //        ::int64_t num_binary_propagations() const;
    //        void      set_num_binary_propagations( ::int64_t value );

    //    private:
    //        ::int64_t _internal_num_binary_propagations() const;
    //        void      _internal_set_num_binary_propagations( ::int64_t value );

    //    public:
    //        // int64 num_integer_propagations = 14;
    //        void      clear_num_integer_propagations();
    //        ::int64_t num_integer_propagations() const;
    //        void      set_num_integer_propagations( ::int64_t value );

    //    private:
    //        ::int64_t _internal_num_integer_propagations() const;
    //        void      _internal_set_num_integer_propagations( ::int64_t value );

    //    public:
    //        // double wall_time = 15;
    //        void   clear_wall_time();
    //        double wall_time() const;
    //        void   set_wall_time( double value );

    //    private:
    //        double _internal_wall_time() const;
    //        void   _internal_set_wall_time( double value );

    //    public:
    //        // double user_time = 16;
    //        void   clear_user_time();
    //        double user_time() const;
    //        void   set_user_time( double value );

    //    private:
    //        double _internal_user_time() const;
    //        void   _internal_set_user_time( double value );

    //    public:
    //        // double deterministic_time = 17;
    //        void   clear_deterministic_time();
    //        double deterministic_time() const;
    //        void   set_deterministic_time( double value );

    //    private:
    //        double _internal_deterministic_time() const;
    //        void   _internal_set_deterministic_time( double value );

    //    public:
    //        // double gap_integral = 22;
    //        void   clear_gap_integral();
    //        double gap_integral() const;
    //        void   set_gap_integral( double value );

    //    private:
    //        double _internal_gap_integral() const;
    //        void   _internal_set_gap_integral( double value );

    //    public:
    //        // int64 num_restarts = 24;
    //        void      clear_num_restarts();
    //        ::int64_t num_restarts() const;
    //        void      set_num_restarts( ::int64_t value );

    //    private:
    //        ::int64_t _internal_num_restarts() const;
    //        void      _internal_set_num_restarts( ::int64_t value );

    //    public:
    //        // int64 num_lp_iterations = 25;
    //        void      clear_num_lp_iterations();
    //        ::int64_t num_lp_iterations() const;
    //        void      set_num_lp_iterations( ::int64_t value );

    //    private:
    //        ::int64_t _internal_num_lp_iterations() const;
    //        void      _internal_set_num_lp_iterations( ::int64_t value );

    //    public:
    //        // int64 inner_objective_lower_bound = 29;
    //        void      clear_inner_objective_lower_bound();
    //        ::int64_t inner_objective_lower_bound() const;
    //        void      set_inner_objective_lower_bound( ::int64_t value );

    //    private:
    //        ::int64_t _internal_inner_objective_lower_bound() const;
    //        void      _internal_set_inner_objective_lower_bound( ::int64_t value );

    //    public:
    //        // int64 num_integers = 30;
    //        void      clear_num_integers();
    //        ::int64_t num_integers() const;
    //        void      set_num_integers( ::int64_t value );

    //    private:
    //        ::int64_t _internal_num_integers() const;
    //        void      _internal_set_num_integers( ::int64_t value );

    //    public:
    //        // .operations_research.sat.CpSolverStatus status = 1;
    //        void                                       clear_status();
    //        ::operations_research::sat::CpSolverStatus status() const;
    //        void                                       set_status( ::operations_research::sat::CpSolverStatus value );

    //    private:
    //        ::operations_research::sat::CpSolverStatus _internal_status() const;
    //        void                                       _internal_set_status( ::operations_research::sat::CpSolverStatus value );

    //    public:
    //        // @@protoc_insertion_point(class_scope:operations_research.sat.CpSolverResponse)
    //    private:
    //        class _Internal;
    //        friend class ::google::protobuf::internal::TcParser;
    //        static const ::google::protobuf::internal::TcParseTable<
    //            5, 23, 3,
    //            87, 2 >
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
    //            ::google::protobuf::internal::HasBits< 1 >                                               _has_bits_;
    //            mutable ::google::protobuf::internal::CachedSize                                         _cached_size_;
    //            ::google::protobuf::RepeatedField< ::int64_t >                                           solution_;
    //            mutable ::google::protobuf::internal::CachedSize                                         _solution_cached_byte_size_;
    //            ::google::protobuf::RepeatedPtrField< ::operations_research::sat::IntegerVariableProto > tightened_variables_;
    //            ::google::protobuf::RepeatedField< ::int32_t >                                           sufficient_assumptions_for_infeasibility_;
    //            mutable ::google::protobuf::internal::CachedSize                                         _sufficient_assumptions_for_infeasibility_cached_byte_size_;
    //            ::google::protobuf::RepeatedPtrField< ::operations_research::sat::CpSolverSolution >     additional_solutions_;
    //            ::google::protobuf::internal::ArenaStringPtr                                             solution_info_;
    //            ::google::protobuf::internal::ArenaStringPtr                                             solve_log_;
    //            ::operations_research::sat::CpObjectiveProto*                                            integer_objective_;
    //            double                                                                                   objective_value_;
    //            double                                                                                   best_objective_bound_;
    //            ::int64_t                                                                                num_booleans_;
    //            ::int64_t                                                                                num_conflicts_;
    //            ::int64_t                                                                                num_branches_;
    //            ::int64_t                                                                                num_binary_propagations_;
    //            ::int64_t                                                                                num_integer_propagations_;
    //            double                                                                                   wall_time_;
    //            double                                                                                   user_time_;
    //            double                                                                                   deterministic_time_;
    //            double                                                                                   gap_integral_;
    //            ::int64_t                                                                                num_restarts_;
    //            ::int64_t                                                                                num_lp_iterations_;
    //            ::int64_t                                                                                inner_objective_lower_bound_;
    //            ::int64_t                                                                                num_integers_;
    //            int                                                                                      status_;
    //            PROTOBUF_TSAN_DECLARE_MEMBER
    //        };
    //        union
    //        {
    //            Impl_ _impl_;
    //        };
    //        friend struct ::TableStruct_ortools_2fsat_2fcp_5fmodel_2eproto;
};

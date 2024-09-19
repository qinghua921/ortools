export namespace operations_research
{

    export class MPSolutionResponse //final : public ::google::protobuf::Message
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
        //     void InternalSwap( MPSolutionResponse* other );

        // private:
        //     friend class ::google::protobuf::internal::AnyMetadata;
        //     static ::absl::string_view FullMessageName()
        //     {
        //         return "operations_research.MPSolutionResponse";
        //     }

        // protected:
        //     explicit MPSolutionResponse( ::google::protobuf::Arena* arena );
        //     MPSolutionResponse( ::google::protobuf::Arena* arena, const MPSolutionResponse& from );
        //     MPSolutionResponse( ::google::protobuf::Arena* arena, MPSolutionResponse&& from ) noexcept
        //         : MPSolutionResponse( arena )
        //     {
        //         *this = ::std::move( from );
        //     }
        //     const ::google::protobuf::MessageLite::ClassData* GetClassData()
        //         const final;

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

        // private:
        //     int _internal_variable_value_size() const;

        // public:
        //     void                                               clear_variable_value();
        //     double                                             variable_value( int index ) const;
        //     void                                               set_variable_value( int index, double value );
        //     void                                               add_variable_value( double value );
        //     const ::google::protobuf::RepeatedField< double >& variable_value() const;
        //     ::google::protobuf::RepeatedField< double >*       mutable_variable_value();

        // private:
        //     const ::google::protobuf::RepeatedField< double >& _internal_variable_value() const;
        //     ::google::protobuf::RepeatedField< double >*       _internal_mutable_variable_value();

        // public:
        //     // repeated double dual_value = 4 [packed = true];
        //     int dual_value_size() const;

        // private:
        //     int _internal_dual_value_size() const;

        // public:
        //     void                                               clear_dual_value();
        //     double                                             dual_value( int index ) const;
        //     void                                               set_dual_value( int index, double value );
        //     void                                               add_dual_value( double value );
        //     const ::google::protobuf::RepeatedField< double >& dual_value() const;
        //     ::google::protobuf::RepeatedField< double >*       mutable_dual_value();

        // private:
        //     const ::google::protobuf::RepeatedField< double >& _internal_dual_value() const;
        //     ::google::protobuf::RepeatedField< double >*       _internal_mutable_dual_value();

        // public:
        //     // repeated double reduced_cost = 6 [packed = true];
        //     int reduced_cost_size() const;

        // private:
        //     int _internal_reduced_cost_size() const;

        // public:
        //     void                                               clear_reduced_cost();
        //     double                                             reduced_cost( int index ) const;
        //     void                                               set_reduced_cost( int index, double value );
        //     void                                               add_reduced_cost( double value );
        //     const ::google::protobuf::RepeatedField< double >& reduced_cost() const;
        //     ::google::protobuf::RepeatedField< double >*       mutable_reduced_cost();

        // private:
        //     const ::google::protobuf::RepeatedField< double >& _internal_reduced_cost() const;
        //     ::google::protobuf::RepeatedField< double >*       _internal_mutable_reduced_cost();

        // public:
        //     // repeated .operations_research.MPSolution additional_solutions = 8;
        //     int additional_solutions_size() const;

        // private:
        //     int _internal_additional_solutions_size() const;

        // public:
        //     void                                                                       clear_additional_solutions();
        //     ::operations_research::MPSolution*                                         mutable_additional_solutions( int index );
        //     ::google::protobuf::RepeatedPtrField< ::operations_research::MPSolution >* mutable_additional_solutions();

        // private:
        //     const ::google::protobuf::RepeatedPtrField< ::operations_research::MPSolution >& _internal_additional_solutions() const;
        //     ::google::protobuf::RepeatedPtrField< ::operations_research::MPSolution >*       _internal_mutable_additional_solutions();

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

        // private:
        //     const std::string&                 _internal_status_str() const;
        //     inline PROTOBUF_ALWAYS_INLINE void _internal_set_status_str(
        //         const std::string& value );
        //     std::string* _internal_mutable_status_str();

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

        // private:
        //     const std::string&                 _internal_solver_specific_info() const;
        //     inline PROTOBUF_ALWAYS_INLINE void _internal_set_solver_specific_info(
        //         const std::string& value );
        //     std::string* _internal_mutable_solver_specific_info();

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

        // private:
        //     const ::operations_research::MPSolveInfo& _internal_solve_info() const;
        //     ::operations_research::MPSolveInfo*       _internal_mutable_solve_info();

        // public:
        //     // optional double objective_value = 2;
        //     bool   has_objective_value() const;
        //     void   clear_objective_value();
        //     double objective_value() const;
        //     void   set_objective_value( double value );

        // private:
        //     double _internal_objective_value() const;
        //     void   _internal_set_objective_value( double value );

        // public:
        //     // optional double best_objective_bound = 5;
        //     bool   has_best_objective_bound() const;
        //     void   clear_best_objective_bound();
        //     double best_objective_bound() const;
        //     void   set_best_objective_bound( double value );

        // private:
        //     double _internal_best_objective_bound() const;
        //     void   _internal_set_best_objective_bound( double value );

        // public:
        //     // optional .operations_research.MPSolverResponseStatus status = 1 [default = MPSOLVER_UNKNOWN_STATUS];
        //     bool                                          has_status() const;
        //     void                                          clear_status();
        //     ::operations_research::MPSolverResponseStatus status() const;
        //     void                                          set_status( ::operations_research::MPSolverResponseStatus value );

        // private:
        //     ::operations_research::MPSolverResponseStatus _internal_status() const;
        //     void                                          _internal_set_status( ::operations_research::MPSolverResponseStatus value );

        // public:
        //     // @@protoc_insertion_point(class_scope:operations_research.MPSolutionResponse)
        // private:
        //     class _Internal;
        //     friend class ::google::protobuf::internal::TcParser;
        //     static const ::google::protobuf::internal::TcParseTable<
        //         4, 10, 3,
        //         65, 2 >
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
        //         ::google::protobuf::internal::HasBits< 1 >                                _has_bits_;
        //         mutable ::google::protobuf::internal::CachedSize                          _cached_size_;
        //         ::google::protobuf::RepeatedField< double >                               variable_value_;
        //         ::google::protobuf::RepeatedField< double >                               dual_value_;
        //         ::google::protobuf::RepeatedField< double >                               reduced_cost_;
        //         ::google::protobuf::RepeatedPtrField< ::operations_research::MPSolution > additional_solutions_;
        //         ::google::protobuf::internal::ArenaStringPtr                              status_str_;
        //         ::google::protobuf::internal::ArenaStringPtr                              solver_specific_info_;
        //         ::operations_research::MPSolveInfo*                                       solve_info_;
        //         double                                                                    objective_value_;
        //         double                                                                    best_objective_bound_;
        //         int                                                                       status_;
        //         PROTOBUF_TSAN_DECLARE_MEMBER
        //     };
        //     union
        //     {
        //         Impl_ _impl_;
        //     };
        //     friend struct ::TableStruct_ortools_2flinear_5fsolver_2flinear_5fsolver_2eproto;
    };

}
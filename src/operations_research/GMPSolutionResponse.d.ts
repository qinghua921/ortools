export class MPSolutionResponse 
{
    // public:
    //     inline MPSolutionResponse()
    //         : MPSolutionResponse( nullptr ) {}
    //     ~MPSolutionResponse() override;
    //     explicit PROTOBUF_CONSTEXPR MPSolutionResponse( ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized );

    //     MPSolutionResponse( const MPSolutionResponse& from );
    //     MPSolutionResponse( MPSolutionResponse&& from ) noexcept
    //         : MPSolutionResponse()
    //     {
    //         *this = ::std::move( from );
    //     }

    //     inline MPSolutionResponse& operator=( const MPSolutionResponse& from )
    //     {
    //         CopyFrom( from );
    //         return *this;
    //     }
    //     inline MPSolutionResponse& operator=( MPSolutionResponse&& from ) noexcept
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
    //     static const MPSolutionResponse& default_instance()
    //     {
    //         return *internal_default_instance();
    //     }
    //     static inline const MPSolutionResponse* internal_default_instance()
    //     {
    //         return reinterpret_cast< const MPSolutionResponse* >(
    //             &_MPSolutionResponse_default_instance_ );
    //     }
    //     static constexpr int kIndexInFileMessages =
    //         21;

    //     friend void swap( MPSolutionResponse& a, MPSolutionResponse& b )
    //     {
    //         a.Swap( &b );
    //     }
    //     inline void Swap( MPSolutionResponse* other )
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
    //     void UnsafeArenaSwap( MPSolutionResponse* other )
    //     {
    //         if ( other == this ) return;
    //         GOOGLE_DCHECK( GetOwningArena() == other->GetOwningArena() );
    //         InternalSwap( other );
    //     }

    //     // implements Message ----------------------------------------------

    //     MPSolutionResponse* New( ::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr ) const final
    //     {
    //         return CreateMaybeMessage< MPSolutionResponse >( arena );
    //     }
    //     using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
    //     void CopyFrom( const MPSolutionResponse& from );
    //     using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
    //     void MergeFrom( const MPSolutionResponse& from )
    //     {
    //         MPSolutionResponse::MergeImpl( *this, from );
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
    //     void InternalSwap( MPSolutionResponse* other );

    // private:
    //     friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
    //     static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName()
    //     {
    //         return "operations_research.MPSolutionResponse";
    //     }

    // protected:
    //     explicit MPSolutionResponse( ::PROTOBUF_NAMESPACE_ID::Arena* arena,
    //                                  bool                            is_message_owned = false );

    // public:
    //     static const ClassData                             _class_data_;
    //     const ::PROTOBUF_NAMESPACE_ID::Message::ClassData* GetClassData() const final;

    //     ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

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
    //     void clear_variable_value();

    // private:
    //     double _internal_variable_value( int index ) const;
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    //          _internal_variable_value() const;
    //     void _internal_add_variable_value( double value );
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    //     _internal_mutable_variable_value();

    // public:
    //     double variable_value( int index ) const;
    //     void   set_variable_value( int index, double value );
    //     void   add_variable_value( double value );
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    //     variable_value() const;
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    //     mutable_variable_value();

    //     // repeated double dual_value = 4 [packed = true];
    //     int dual_value_size() const;

    // private:
    //     int _internal_dual_value_size() const;

    // public:
    //     void clear_dual_value();

    // private:
    //     double _internal_dual_value( int index ) const;
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    //          _internal_dual_value() const;
    //     void _internal_add_dual_value( double value );
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    //     _internal_mutable_dual_value();

    // public:
    //     double dual_value( int index ) const;
    //     void   set_dual_value( int index, double value );
    //     void   add_dual_value( double value );
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    //     dual_value() const;
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    //     mutable_dual_value();

    //     // repeated double reduced_cost = 6 [packed = true];
    //     int reduced_cost_size() const;

    // private:
    //     int _internal_reduced_cost_size() const;

    // public:
    //     void clear_reduced_cost();

    // private:
    //     double _internal_reduced_cost( int index ) const;
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    //          _internal_reduced_cost() const;
    //     void _internal_add_reduced_cost( double value );
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    //     _internal_mutable_reduced_cost();

    // public:
    //     double reduced_cost( int index ) const;
    //     void   set_reduced_cost( int index, double value );
    //     void   add_reduced_cost( double value );
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    //     reduced_cost() const;
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    //     mutable_reduced_cost();

    //     // repeated .operations_research.MPSolution additional_solutions = 8;
    //     int additional_solutions_size() const;

    // private:
    //     int _internal_additional_solutions_size() const;

    // public:
    //     void                               clear_additional_solutions();
    //     ::operations_research::MPSolution* mutable_additional_solutions( int index );
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPSolution >*
    //     mutable_additional_solutions();

    // private:
    //     const ::operations_research::MPSolution& _internal_additional_solutions( int index ) const;
    //     ::operations_research::MPSolution*       _internal_add_additional_solutions();

    // public:
    //     const ::operations_research::MPSolution& additional_solutions( int index ) const;
    //     ::operations_research::MPSolution*       add_additional_solutions();
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPSolution >&
    //     additional_solutions() const;

    //     // optional string status_str = 7;
    //     bool has_status_str() const;

    // private:
    //     bool _internal_has_status_str() const;

    // public:
    //     void               clear_status_str();
    //     const std::string& status_str() const;
    //     template < typename ArgT0 = const std::string&, typename... ArgT >
    //     void               set_status_str( ArgT0&& arg0, ArgT... args );
    //     std::string*       mutable_status_str();
    //     PROTOBUF_NODISCARD std::string* release_status_str();
    //     void                            set_allocated_status_str( std::string* status_str );

    // private:
    //     const std::string&                 _internal_status_str() const;
    //     inline PROTOBUF_ALWAYS_INLINE void _internal_set_status_str( const std::string& value );
    //     std::string*                       _internal_mutable_status_str();

    // public:
    //     // optional bytes solver_specific_info = 11;
    //     bool has_solver_specific_info() const;

    // private:
    //     bool _internal_has_solver_specific_info() const;

    // public:
    //     void               clear_solver_specific_info();
    //     const std::string& solver_specific_info() const;
    //     template < typename ArgT0 = const std::string&, typename... ArgT >
    //     void               set_solver_specific_info( ArgT0&& arg0, ArgT... args );
    //     std::string*       mutable_solver_specific_info();
    //     PROTOBUF_NODISCARD std::string* release_solver_specific_info();
    //     void                            set_allocated_solver_specific_info( std::string* solver_specific_info );

    // private:
    //     const std::string&                 _internal_solver_specific_info() const;
    //     inline PROTOBUF_ALWAYS_INLINE void _internal_set_solver_specific_info( const std::string& value );
    //     std::string*                       _internal_mutable_solver_specific_info();

    // public:
    //     // optional .operations_research.MPSolveInfo solve_info = 10;
    //     bool has_solve_info() const;

    // private:
    //     bool _internal_has_solve_info() const;

    // public:
    //     void                                                   clear_solve_info();
    //     const ::operations_research::MPSolveInfo&              solve_info() const;
    //     PROTOBUF_NODISCARD ::operations_research::MPSolveInfo* release_solve_info();
    //     ::operations_research::MPSolveInfo*                    mutable_solve_info();
    //     void                                                   set_allocated_solve_info( ::operations_research::MPSolveInfo* solve_info );

    // private:
    //     const ::operations_research::MPSolveInfo& _internal_solve_info() const;
    //     ::operations_research::MPSolveInfo*       _internal_mutable_solve_info();

    // public:
    //     void unsafe_arena_set_allocated_solve_info(
    //         ::operations_research::MPSolveInfo* solve_info );
    //     ::operations_research::MPSolveInfo* unsafe_arena_release_solve_info();

    //     // optional double objective_value = 2;
    //     bool has_objective_value() const;

    // private:
    //     bool _internal_has_objective_value() const;

    // public:
    //     void   clear_objective_value();
    //     double objective_value() const;
    //     void   set_objective_value( double value );

    // private:
    //     double _internal_objective_value() const;
    //     void   _internal_set_objective_value( double value );

    // public:
    //     // optional double best_objective_bound = 5;
    //     bool has_best_objective_bound() const;

    // private:
    //     bool _internal_has_best_objective_bound() const;

    // public:
    //     void   clear_best_objective_bound();
    //     double best_objective_bound() const;
    //     void   set_best_objective_bound( double value );

    // private:
    //     double _internal_best_objective_bound() const;
    //     void   _internal_set_best_objective_bound( double value );

    // public:
    //     // optional .operations_research.MPSolverResponseStatus status = 1 [default = MPSOLVER_UNKNOWN_STATUS];
    //     bool has_status() const;

    // private:
    //     bool _internal_has_status() const;

    // public:
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

    //     template < typename T >
    //     friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
    //     typedef void InternalArenaConstructable_;
    //     typedef void DestructorSkippable_;
    //     struct Impl_
    //     {
    //         ::PROTOBUF_NAMESPACE_ID::internal::HasBits< 1 >                                _has_bits_;
    //         mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize                          _cached_size_;
    //         ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >                               variable_value_;
    //         ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >                               dual_value_;
    //         ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >                               reduced_cost_;
    //         ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPSolution > additional_solutions_;
    //         ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr                              status_str_;
    //         ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr                              solver_specific_info_;
    //         ::operations_research::MPSolveInfo*                                            solve_info_;
    //         double                                                                         objective_value_;
    //         double                                                                         best_objective_bound_;
    //         int                                                                            status_;
    //     };
    //     union
    //     {
    //         Impl_ _impl_;
    //     };
    //     friend struct ::TableStruct_ortools_2flinear_5fsolver_2flinear_5fsolver_2eproto;
    // };
    // // ===================================================================

    // // ===================================================================

    // #ifdef __GNUC__
    // #pragma GCC diagnostic push
    // #pragma GCC diagnostic ignored "-Wstrict-aliasing"
    // #endif  // __GNUC__
    // // MPVariableProto

    // // optional double lower_bound = 1 [default = -inf];
    // inline bool MPVariableProto::_internal_has_lower_bound() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000010u ) != 0;
    //     return value;
    // }
    // inline bool MPVariableProto::has_lower_bound() const
    // {
    //     return _internal_has_lower_bound();
    // }
    // inline void MPVariableProto::clear_lower_bound()
    // {
    //     _impl_.lower_bound_ = -std::numeric_limits< double >::infinity();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000010u;
    // }
    // inline double MPVariableProto::_internal_lower_bound() const
    // {
    //     return _impl_.lower_bound_;
    // }
    // inline double MPVariableProto::lower_bound() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPVariableProto.lower_bound)
    //     return _internal_lower_bound();
    // }
    // inline void MPVariableProto::_internal_set_lower_bound( double value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000010u;
    //     _impl_.lower_bound_ = value;
    // }
    // inline void MPVariableProto::set_lower_bound( double value )
    // {
    //     _internal_set_lower_bound( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPVariableProto.lower_bound)
    // }

    // // optional double upper_bound = 2 [default = inf];
    // inline bool MPVariableProto::_internal_has_upper_bound() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000020u ) != 0;
    //     return value;
    // }
    // inline bool MPVariableProto::has_upper_bound() const
    // {
    //     return _internal_has_upper_bound();
    // }
    // inline void MPVariableProto::clear_upper_bound()
    // {
    //     _impl_.upper_bound_ = std::numeric_limits< double >::infinity();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000020u;
    // }
    // inline double MPVariableProto::_internal_upper_bound() const
    // {
    //     return _impl_.upper_bound_;
    // }
    // inline double MPVariableProto::upper_bound() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPVariableProto.upper_bound)
    //     return _internal_upper_bound();
    // }
    // inline void MPVariableProto::_internal_set_upper_bound( double value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000020u;
    //     _impl_.upper_bound_ = value;
    // }
    // inline void MPVariableProto::set_upper_bound( double value )
    // {
    //     _internal_set_upper_bound( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPVariableProto.upper_bound)
    // }

    // // optional double objective_coefficient = 3 [default = 0];
    // inline bool MPVariableProto::_internal_has_objective_coefficient() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000002u ) != 0;
    //     return value;
    // }
    // inline bool MPVariableProto::has_objective_coefficient() const
    // {
    //     return _internal_has_objective_coefficient();
    // }
    // inline void MPVariableProto::clear_objective_coefficient()
    // {
    //     _impl_.objective_coefficient_ = 0;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    // }
    // inline double MPVariableProto::_internal_objective_coefficient() const
    // {
    //     return _impl_.objective_coefficient_;
    // }
    // inline double MPVariableProto::objective_coefficient() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPVariableProto.objective_coefficient)
    //     return _internal_objective_coefficient();
    // }
    // inline void MPVariableProto::_internal_set_objective_coefficient( double value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000002u;
    //     _impl_.objective_coefficient_ = value;
    // }
    // inline void MPVariableProto::set_objective_coefficient( double value )
    // {
    //     _internal_set_objective_coefficient( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPVariableProto.objective_coefficient)
    // }

    // // optional bool is_integer = 4 [default = false];
    // inline bool MPVariableProto::_internal_has_is_integer() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000004u ) != 0;
    //     return value;
    // }
    // inline bool MPVariableProto::has_is_integer() const
    // {
    //     return _internal_has_is_integer();
    // }
    // inline void MPVariableProto::clear_is_integer()
    // {
    //     _impl_.is_integer_ = false;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    // }
    // inline bool MPVariableProto::_internal_is_integer() const
    // {
    //     return _impl_.is_integer_;
    // }
    // inline bool MPVariableProto::is_integer() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPVariableProto.is_integer)
    //     return _internal_is_integer();
    // }
    // inline void MPVariableProto::_internal_set_is_integer( bool value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000004u;
    //     _impl_.is_integer_ = value;
    // }
    // inline void MPVariableProto::set_is_integer( bool value )
    // {
    //     _internal_set_is_integer( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPVariableProto.is_integer)
    // }

    // // optional string name = 5 [default = ""];
    // inline bool MPVariableProto::_internal_has_name() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000001u ) != 0;
    //     return value;
    // }
    // inline bool MPVariableProto::has_name() const
    // {
    //     return _internal_has_name();
    // }
    // inline void MPVariableProto::clear_name()
    // {
    //     _impl_.name_.ClearToEmpty();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    // }
    // inline const std::string& MPVariableProto::name() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPVariableProto.name)
    //     return _internal_name();
    // }
    // template < typename ArgT0, typename... ArgT >
    // inline PROTOBUF_ALWAYS_INLINE void MPVariableProto::set_name( ArgT0&& arg0, ArgT... args )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     _impl_.name_.Set( static_cast< ArgT0&& >( arg0 ), args..., GetArenaForAllocation() );
    //     // @@protoc_insertion_point(field_set:operations_research.MPVariableProto.name)
    // }
    // inline std::string* MPVariableProto::mutable_name()
    // {
    //     std::string* _s = _internal_mutable_name();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPVariableProto.name)
    //     return _s;
    // }
    // inline const std::string& MPVariableProto::_internal_name() const
    // {
    //     return _impl_.name_.Get();
    // }
    // inline void MPVariableProto::_internal_set_name( const std::string& value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     _impl_.name_.Set( value, GetArenaForAllocation() );
    // }
    // inline std::string* MPVariableProto::_internal_mutable_name()
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     return _impl_.name_.Mutable( GetArenaForAllocation() );
    // }
    // inline std::string* MPVariableProto::release_name()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPVariableProto.name)
    //     if ( !_internal_has_name() )
    //     {
    //         return nullptr;
    //     }
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    //     auto* p = _impl_.name_.Release();
    // #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     if ( _impl_.name_.IsDefault() )
    //     {
    //         _impl_.name_.Set( "", GetArenaForAllocation() );
    //     }
    // #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     return p;
    // }
    // inline void MPVariableProto::set_allocated_name( std::string* name )
    // {
    //     if ( name != nullptr )
    //     {
    //         _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    //     }
    //     _impl_.name_.SetAllocated( name, GetArenaForAllocation() );
    // #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     if ( _impl_.name_.IsDefault() )
    //     {
    //         _impl_.name_.Set( "", GetArenaForAllocation() );
    //     }
    // #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //         // @@protoc_insertion_point(field_set_allocated:operations_research.MPVariableProto.name)
    // }

    // // optional int32 branching_priority = 6 [default = 0];
    // inline bool MPVariableProto::_internal_has_branching_priority() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000008u ) != 0;
    //     return value;
    // }
    // inline bool MPVariableProto::has_branching_priority() const
    // {
    //     return _internal_has_branching_priority();
    // }
    // inline void MPVariableProto::clear_branching_priority()
    // {
    //     _impl_.branching_priority_ = 0;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000008u;
    // }
    // inline int32_t MPVariableProto::_internal_branching_priority() const
    // {
    //     return _impl_.branching_priority_;
    // }
    // inline int32_t MPVariableProto::branching_priority() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPVariableProto.branching_priority)
    //     return _internal_branching_priority();
    // }
    // inline void MPVariableProto::_internal_set_branching_priority( int32_t value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000008u;
    //     _impl_.branching_priority_ = value;
    // }
    // inline void MPVariableProto::set_branching_priority( int32_t value )
    // {
    //     _internal_set_branching_priority( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPVariableProto.branching_priority)
    // }

    // // -------------------------------------------------------------------

    // // MPConstraintProto

    // // repeated int32 var_index = 6 [packed = true];
    // inline int MPConstraintProto::_internal_var_index_size() const
    // {
    //     return _impl_.var_index_.size();
    // }
    // inline int MPConstraintProto::var_index_size() const
    // {
    //     return _internal_var_index_size();
    // }
    // inline void MPConstraintProto::clear_var_index()
    // {
    //     _impl_.var_index_.Clear();
    // }
    // inline int32_t MPConstraintProto::_internal_var_index( int index ) const
    // {
    //     return _impl_.var_index_.Get( index );
    // }
    // inline int32_t MPConstraintProto::var_index( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPConstraintProto.var_index)
    //     return _internal_var_index( index );
    // }
    // inline void MPConstraintProto::set_var_index( int index, int32_t value )
    // {
    //     _impl_.var_index_.Set( index, value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPConstraintProto.var_index)
    // }
    // inline void MPConstraintProto::_internal_add_var_index( int32_t value )
    // {
    //     _impl_.var_index_.Add( value );
    // }
    // inline void MPConstraintProto::add_var_index( int32_t value )
    // {
    //     _internal_add_var_index( value );
    //     // @@protoc_insertion_point(field_add:operations_research.MPConstraintProto.var_index)
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
    // MPConstraintProto::_internal_var_index() const
    // {
    //     return _impl_.var_index_;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
    // MPConstraintProto::var_index() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.MPConstraintProto.var_index)
    //     return _internal_var_index();
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
    // MPConstraintProto::_internal_mutable_var_index()
    // {
    //     return &_impl_.var_index_;
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
    // MPConstraintProto::mutable_var_index()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.MPConstraintProto.var_index)
    //     return _internal_mutable_var_index();
    // }

    // // repeated double coefficient = 7 [packed = true];
    // inline int MPConstraintProto::_internal_coefficient_size() const
    // {
    //     return _impl_.coefficient_.size();
    // }
    // inline int MPConstraintProto::coefficient_size() const
    // {
    //     return _internal_coefficient_size();
    // }
    // inline void MPConstraintProto::clear_coefficient()
    // {
    //     _impl_.coefficient_.Clear();
    // }
    // inline double MPConstraintProto::_internal_coefficient( int index ) const
    // {
    //     return _impl_.coefficient_.Get( index );
    // }
    // inline double MPConstraintProto::coefficient( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPConstraintProto.coefficient)
    //     return _internal_coefficient( index );
    // }
    // inline void MPConstraintProto::set_coefficient( int index, double value )
    // {
    //     _impl_.coefficient_.Set( index, value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPConstraintProto.coefficient)
    // }
    // inline void MPConstraintProto::_internal_add_coefficient( double value )
    // {
    //     _impl_.coefficient_.Add( value );
    // }
    // inline void MPConstraintProto::add_coefficient( double value )
    // {
    //     _internal_add_coefficient( value );
    //     // @@protoc_insertion_point(field_add:operations_research.MPConstraintProto.coefficient)
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    // MPConstraintProto::_internal_coefficient() const
    // {
    //     return _impl_.coefficient_;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    // MPConstraintProto::coefficient() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.MPConstraintProto.coefficient)
    //     return _internal_coefficient();
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    // MPConstraintProto::_internal_mutable_coefficient()
    // {
    //     return &_impl_.coefficient_;
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    // MPConstraintProto::mutable_coefficient()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.MPConstraintProto.coefficient)
    //     return _internal_mutable_coefficient();
    // }

    // // optional double lower_bound = 2 [default = -inf];
    // inline bool MPConstraintProto::_internal_has_lower_bound() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000004u ) != 0;
    //     return value;
    // }
    // inline bool MPConstraintProto::has_lower_bound() const
    // {
    //     return _internal_has_lower_bound();
    // }
    // inline void MPConstraintProto::clear_lower_bound()
    // {
    //     _impl_.lower_bound_ = -std::numeric_limits< double >::infinity();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    // }
    // inline double MPConstraintProto::_internal_lower_bound() const
    // {
    //     return _impl_.lower_bound_;
    // }
    // inline double MPConstraintProto::lower_bound() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPConstraintProto.lower_bound)
    //     return _internal_lower_bound();
    // }
    // inline void MPConstraintProto::_internal_set_lower_bound( double value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000004u;
    //     _impl_.lower_bound_ = value;
    // }
    // inline void MPConstraintProto::set_lower_bound( double value )
    // {
    //     _internal_set_lower_bound( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPConstraintProto.lower_bound)
    // }

    // // optional double upper_bound = 3 [default = inf];
    // inline bool MPConstraintProto::_internal_has_upper_bound() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000008u ) != 0;
    //     return value;
    // }
    // inline bool MPConstraintProto::has_upper_bound() const
    // {
    //     return _internal_has_upper_bound();
    // }
    // inline void MPConstraintProto::clear_upper_bound()
    // {
    //     _impl_.upper_bound_ = std::numeric_limits< double >::infinity();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000008u;
    // }
    // inline double MPConstraintProto::_internal_upper_bound() const
    // {
    //     return _impl_.upper_bound_;
    // }
    // inline double MPConstraintProto::upper_bound() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPConstraintProto.upper_bound)
    //     return _internal_upper_bound();
    // }
    // inline void MPConstraintProto::_internal_set_upper_bound( double value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000008u;
    //     _impl_.upper_bound_ = value;
    // }
    // inline void MPConstraintProto::set_upper_bound( double value )
    // {
    //     _internal_set_upper_bound( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPConstraintProto.upper_bound)
    // }

    // // optional string name = 4 [default = ""];
    // inline bool MPConstraintProto::_internal_has_name() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000001u ) != 0;
    //     return value;
    // }
    // inline bool MPConstraintProto::has_name() const
    // {
    //     return _internal_has_name();
    // }
    // inline void MPConstraintProto::clear_name()
    // {
    //     _impl_.name_.ClearToEmpty();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    // }
    // inline const std::string& MPConstraintProto::name() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPConstraintProto.name)
    //     return _internal_name();
    // }
    // template < typename ArgT0, typename... ArgT >
    // inline PROTOBUF_ALWAYS_INLINE void MPConstraintProto::set_name( ArgT0&& arg0, ArgT... args )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     _impl_.name_.Set( static_cast< ArgT0&& >( arg0 ), args..., GetArenaForAllocation() );
    //     // @@protoc_insertion_point(field_set:operations_research.MPConstraintProto.name)
    // }
    // inline std::string* MPConstraintProto::mutable_name()
    // {
    //     std::string* _s = _internal_mutable_name();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPConstraintProto.name)
    //     return _s;
    // }
    // inline const std::string& MPConstraintProto::_internal_name() const
    // {
    //     return _impl_.name_.Get();
    // }
    // inline void MPConstraintProto::_internal_set_name( const std::string& value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     _impl_.name_.Set( value, GetArenaForAllocation() );
    // }
    // inline std::string* MPConstraintProto::_internal_mutable_name()
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     return _impl_.name_.Mutable( GetArenaForAllocation() );
    // }
    // inline std::string* MPConstraintProto::release_name()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPConstraintProto.name)
    //     if ( !_internal_has_name() )
    //     {
    //         return nullptr;
    //     }
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    //     auto* p = _impl_.name_.Release();
    // #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     if ( _impl_.name_.IsDefault() )
    //     {
    //         _impl_.name_.Set( "", GetArenaForAllocation() );
    //     }
    // #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     return p;
    // }
    // inline void MPConstraintProto::set_allocated_name( std::string* name )
    // {
    //     if ( name != nullptr )
    //     {
    //         _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    //     }
    //     _impl_.name_.SetAllocated( name, GetArenaForAllocation() );
    // #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     if ( _impl_.name_.IsDefault() )
    //     {
    //         _impl_.name_.Set( "", GetArenaForAllocation() );
    //     }
    // #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //         // @@protoc_insertion_point(field_set_allocated:operations_research.MPConstraintProto.name)
    // }

    // // optional bool is_lazy = 5 [default = false];
    // inline bool MPConstraintProto::_internal_has_is_lazy() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000002u ) != 0;
    //     return value;
    // }
    // inline bool MPConstraintProto::has_is_lazy() const
    // {
    //     return _internal_has_is_lazy();
    // }
    // inline void MPConstraintProto::clear_is_lazy()
    // {
    //     _impl_.is_lazy_ = false;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    // }
    // inline bool MPConstraintProto::_internal_is_lazy() const
    // {
    //     return _impl_.is_lazy_;
    // }
    // inline bool MPConstraintProto::is_lazy() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPConstraintProto.is_lazy)
    //     return _internal_is_lazy();
    // }
    // inline void MPConstraintProto::_internal_set_is_lazy( bool value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000002u;
    //     _impl_.is_lazy_ = value;
    // }
    // inline void MPConstraintProto::set_is_lazy( bool value )
    // {
    //     _internal_set_is_lazy( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPConstraintProto.is_lazy)
    // }

    // // -------------------------------------------------------------------

    // // MPGeneralConstraintProto

    // // optional string name = 1 [default = ""];
    // inline bool MPGeneralConstraintProto::_internal_has_name() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000001u ) != 0;
    //     return value;
    // }
    // inline bool MPGeneralConstraintProto::has_name() const
    // {
    //     return _internal_has_name();
    // }
    // inline void MPGeneralConstraintProto::clear_name()
    // {
    //     _impl_.name_.ClearToEmpty();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    // }
    // inline const std::string& MPGeneralConstraintProto::name() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPGeneralConstraintProto.name)
    //     return _internal_name();
    // }
    // template < typename ArgT0, typename... ArgT >
    // inline PROTOBUF_ALWAYS_INLINE void MPGeneralConstraintProto::set_name( ArgT0&& arg0, ArgT... args )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     _impl_.name_.Set( static_cast< ArgT0&& >( arg0 ), args..., GetArenaForAllocation() );
    //     // @@protoc_insertion_point(field_set:operations_research.MPGeneralConstraintProto.name)
    // }
    // inline std::string* MPGeneralConstraintProto::mutable_name()
    // {
    //     std::string* _s = _internal_mutable_name();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPGeneralConstraintProto.name)
    //     return _s;
    // }
    // inline const std::string& MPGeneralConstraintProto::_internal_name() const
    // {
    //     return _impl_.name_.Get();
    // }
    // inline void MPGeneralConstraintProto::_internal_set_name( const std::string& value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     _impl_.name_.Set( value, GetArenaForAllocation() );
    // }
    // inline std::string* MPGeneralConstraintProto::_internal_mutable_name()
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     return _impl_.name_.Mutable( GetArenaForAllocation() );
    // }
    // inline std::string* MPGeneralConstraintProto::release_name()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPGeneralConstraintProto.name)
    //     if ( !_internal_has_name() )
    //     {
    //         return nullptr;
    //     }
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    //     auto* p = _impl_.name_.Release();
    // #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     if ( _impl_.name_.IsDefault() )
    //     {
    //         _impl_.name_.Set( "", GetArenaForAllocation() );
    //     }
    // #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     return p;
    // }
    // inline void MPGeneralConstraintProto::set_allocated_name( std::string* name )
    // {
    //     if ( name != nullptr )
    //     {
    //         _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    //     }
    //     _impl_.name_.SetAllocated( name, GetArenaForAllocation() );
    // #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     if ( _impl_.name_.IsDefault() )
    //     {
    //         _impl_.name_.Set( "", GetArenaForAllocation() );
    //     }
    // #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //         // @@protoc_insertion_point(field_set_allocated:operations_research.MPGeneralConstraintProto.name)
    // }

    // // .operations_research.MPIndicatorConstraint indicator_constraint = 2;
    // inline bool MPGeneralConstraintProto::_internal_has_indicator_constraint() const
    // {
    //     return general_constraint_case() == kIndicatorConstraint;
    // }
    // inline bool MPGeneralConstraintProto::has_indicator_constraint() const
    // {
    //     return _internal_has_indicator_constraint();
    // }
    // inline void MPGeneralConstraintProto::set_has_indicator_constraint()
    // {
    //     _impl_._oneof_case_[ 0 ] = kIndicatorConstraint;
    // }
    // inline void MPGeneralConstraintProto::clear_indicator_constraint()
    // {
    //     if ( _internal_has_indicator_constraint() )
    //     {
    //         if ( GetArenaForAllocation() == nullptr )
    //         {
    //             delete _impl_.general_constraint_.indicator_constraint_;
    //         }
    //         clear_has_general_constraint();
    //     }
    // }
    // inline ::operations_research::MPIndicatorConstraint* MPGeneralConstraintProto::release_indicator_constraint()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPGeneralConstraintProto.indicator_constraint)
    //     if ( _internal_has_indicator_constraint() )
    //     {
    //         clear_has_general_constraint();
    //         ::operations_research::MPIndicatorConstraint* temp = _impl_.general_constraint_.indicator_constraint_;
    //         if ( GetArenaForAllocation() != nullptr )
    //         {
    //             temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //         }
    //         _impl_.general_constraint_.indicator_constraint_ = nullptr;
    //         return temp;
    //     }
    //     else
    //     {
    //         return nullptr;
    //     }
    // }
    // inline const ::operations_research::MPIndicatorConstraint& MPGeneralConstraintProto::_internal_indicator_constraint() const
    // {
    //     return _internal_has_indicator_constraint()
    //                ? *_impl_.general_constraint_.indicator_constraint_
    //                : reinterpret_cast< ::operations_research::MPIndicatorConstraint& >( ::operations_research::_MPIndicatorConstraint_default_instance_ );
    // }
    // inline const ::operations_research::MPIndicatorConstraint& MPGeneralConstraintProto::indicator_constraint() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPGeneralConstraintProto.indicator_constraint)
    //     return _internal_indicator_constraint();
    // }
    // inline ::operations_research::MPIndicatorConstraint* MPGeneralConstraintProto::unsafe_arena_release_indicator_constraint()
    // {
    //     // @@protoc_insertion_point(field_unsafe_arena_release:operations_research.MPGeneralConstraintProto.indicator_constraint)
    //     if ( _internal_has_indicator_constraint() )
    //     {
    //         clear_has_general_constraint();
    //         ::operations_research::MPIndicatorConstraint* temp = _impl_.general_constraint_.indicator_constraint_;
    //         _impl_.general_constraint_.indicator_constraint_   = nullptr;
    //         return temp;
    //     }
    //     else
    //     {
    //         return nullptr;
    //     }
    // }
    // inline void MPGeneralConstraintProto::unsafe_arena_set_allocated_indicator_constraint( ::operations_research::MPIndicatorConstraint* indicator_constraint )
    // {
    //     clear_general_constraint();
    //     if ( indicator_constraint )
    //     {
    //         set_has_indicator_constraint();
    //         _impl_.general_constraint_.indicator_constraint_ = indicator_constraint;
    //     }
    //     // @@protoc_insertion_point(field_unsafe_arena_set_allocated:operations_research.MPGeneralConstraintProto.indicator_constraint)
    // }
    // inline ::operations_research::MPIndicatorConstraint* MPGeneralConstraintProto::_internal_mutable_indicator_constraint()
    // {
    //     if ( !_internal_has_indicator_constraint() )
    //     {
    //         clear_general_constraint();
    //         set_has_indicator_constraint();
    //         _impl_.general_constraint_.indicator_constraint_ = CreateMaybeMessage< ::operations_research::MPIndicatorConstraint >( GetArenaForAllocation() );
    //     }
    //     return _impl_.general_constraint_.indicator_constraint_;
    // }
    // inline ::operations_research::MPIndicatorConstraint* MPGeneralConstraintProto::mutable_indicator_constraint()
    // {
    //     ::operations_research::MPIndicatorConstraint* _msg = _internal_mutable_indicator_constraint();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPGeneralConstraintProto.indicator_constraint)
    //     return _msg;
    // }

    // // .operations_research.MPSosConstraint sos_constraint = 3;
    // inline bool MPGeneralConstraintProto::_internal_has_sos_constraint() const
    // {
    //     return general_constraint_case() == kSosConstraint;
    // }
    // inline bool MPGeneralConstraintProto::has_sos_constraint() const
    // {
    //     return _internal_has_sos_constraint();
    // }
    // inline void MPGeneralConstraintProto::set_has_sos_constraint()
    // {
    //     _impl_._oneof_case_[ 0 ] = kSosConstraint;
    // }
    // inline void MPGeneralConstraintProto::clear_sos_constraint()
    // {
    //     if ( _internal_has_sos_constraint() )
    //     {
    //         if ( GetArenaForAllocation() == nullptr )
    //         {
    //             delete _impl_.general_constraint_.sos_constraint_;
    //         }
    //         clear_has_general_constraint();
    //     }
    // }
    // inline ::operations_research::MPSosConstraint* MPGeneralConstraintProto::release_sos_constraint()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPGeneralConstraintProto.sos_constraint)
    //     if ( _internal_has_sos_constraint() )
    //     {
    //         clear_has_general_constraint();
    //         ::operations_research::MPSosConstraint* temp = _impl_.general_constraint_.sos_constraint_;
    //         if ( GetArenaForAllocation() != nullptr )
    //         {
    //             temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //         }
    //         _impl_.general_constraint_.sos_constraint_ = nullptr;
    //         return temp;
    //     }
    //     else
    //     {
    //         return nullptr;
    //     }
    // }
    // inline const ::operations_research::MPSosConstraint& MPGeneralConstraintProto::_internal_sos_constraint() const
    // {
    //     return _internal_has_sos_constraint()
    //                ? *_impl_.general_constraint_.sos_constraint_
    //                : reinterpret_cast< ::operations_research::MPSosConstraint& >( ::operations_research::_MPSosConstraint_default_instance_ );
    // }
    // inline const ::operations_research::MPSosConstraint& MPGeneralConstraintProto::sos_constraint() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPGeneralConstraintProto.sos_constraint)
    //     return _internal_sos_constraint();
    // }
    // inline ::operations_research::MPSosConstraint* MPGeneralConstraintProto::unsafe_arena_release_sos_constraint()
    // {
    //     // @@protoc_insertion_point(field_unsafe_arena_release:operations_research.MPGeneralConstraintProto.sos_constraint)
    //     if ( _internal_has_sos_constraint() )
    //     {
    //         clear_has_general_constraint();
    //         ::operations_research::MPSosConstraint* temp = _impl_.general_constraint_.sos_constraint_;
    //         _impl_.general_constraint_.sos_constraint_   = nullptr;
    //         return temp;
    //     }
    //     else
    //     {
    //         return nullptr;
    //     }
    // }
    // inline void MPGeneralConstraintProto::unsafe_arena_set_allocated_sos_constraint( ::operations_research::MPSosConstraint* sos_constraint )
    // {
    //     clear_general_constraint();
    //     if ( sos_constraint )
    //     {
    //         set_has_sos_constraint();
    //         _impl_.general_constraint_.sos_constraint_ = sos_constraint;
    //     }
    //     // @@protoc_insertion_point(field_unsafe_arena_set_allocated:operations_research.MPGeneralConstraintProto.sos_constraint)
    // }
    // inline ::operations_research::MPSosConstraint* MPGeneralConstraintProto::_internal_mutable_sos_constraint()
    // {
    //     if ( !_internal_has_sos_constraint() )
    //     {
    //         clear_general_constraint();
    //         set_has_sos_constraint();
    //         _impl_.general_constraint_.sos_constraint_ = CreateMaybeMessage< ::operations_research::MPSosConstraint >( GetArenaForAllocation() );
    //     }
    //     return _impl_.general_constraint_.sos_constraint_;
    // }
    // inline ::operations_research::MPSosConstraint* MPGeneralConstraintProto::mutable_sos_constraint()
    // {
    //     ::operations_research::MPSosConstraint* _msg = _internal_mutable_sos_constraint();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPGeneralConstraintProto.sos_constraint)
    //     return _msg;
    // }

    // // .operations_research.MPQuadraticConstraint quadratic_constraint = 4;
    // inline bool MPGeneralConstraintProto::_internal_has_quadratic_constraint() const
    // {
    //     return general_constraint_case() == kQuadraticConstraint;
    // }
    // inline bool MPGeneralConstraintProto::has_quadratic_constraint() const
    // {
    //     return _internal_has_quadratic_constraint();
    // }
    // inline void MPGeneralConstraintProto::set_has_quadratic_constraint()
    // {
    //     _impl_._oneof_case_[ 0 ] = kQuadraticConstraint;
    // }
    // inline void MPGeneralConstraintProto::clear_quadratic_constraint()
    // {
    //     if ( _internal_has_quadratic_constraint() )
    //     {
    //         if ( GetArenaForAllocation() == nullptr )
    //         {
    //             delete _impl_.general_constraint_.quadratic_constraint_;
    //         }
    //         clear_has_general_constraint();
    //     }
    // }
    // inline ::operations_research::MPQuadraticConstraint* MPGeneralConstraintProto::release_quadratic_constraint()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPGeneralConstraintProto.quadratic_constraint)
    //     if ( _internal_has_quadratic_constraint() )
    //     {
    //         clear_has_general_constraint();
    //         ::operations_research::MPQuadraticConstraint* temp = _impl_.general_constraint_.quadratic_constraint_;
    //         if ( GetArenaForAllocation() != nullptr )
    //         {
    //             temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //         }
    //         _impl_.general_constraint_.quadratic_constraint_ = nullptr;
    //         return temp;
    //     }
    //     else
    //     {
    //         return nullptr;
    //     }
    // }
    // inline const ::operations_research::MPQuadraticConstraint& MPGeneralConstraintProto::_internal_quadratic_constraint() const
    // {
    //     return _internal_has_quadratic_constraint()
    //                ? *_impl_.general_constraint_.quadratic_constraint_
    //                : reinterpret_cast< ::operations_research::MPQuadraticConstraint& >( ::operations_research::_MPQuadraticConstraint_default_instance_ );
    // }
    // inline const ::operations_research::MPQuadraticConstraint& MPGeneralConstraintProto::quadratic_constraint() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPGeneralConstraintProto.quadratic_constraint)
    //     return _internal_quadratic_constraint();
    // }
    // inline ::operations_research::MPQuadraticConstraint* MPGeneralConstraintProto::unsafe_arena_release_quadratic_constraint()
    // {
    //     // @@protoc_insertion_point(field_unsafe_arena_release:operations_research.MPGeneralConstraintProto.quadratic_constraint)
    //     if ( _internal_has_quadratic_constraint() )
    //     {
    //         clear_has_general_constraint();
    //         ::operations_research::MPQuadraticConstraint* temp = _impl_.general_constraint_.quadratic_constraint_;
    //         _impl_.general_constraint_.quadratic_constraint_   = nullptr;
    //         return temp;
    //     }
    //     else
    //     {
    //         return nullptr;
    //     }
    // }
    // inline void MPGeneralConstraintProto::unsafe_arena_set_allocated_quadratic_constraint( ::operations_research::MPQuadraticConstraint* quadratic_constraint )
    // {
    //     clear_general_constraint();
    //     if ( quadratic_constraint )
    //     {
    //         set_has_quadratic_constraint();
    //         _impl_.general_constraint_.quadratic_constraint_ = quadratic_constraint;
    //     }
    //     // @@protoc_insertion_point(field_unsafe_arena_set_allocated:operations_research.MPGeneralConstraintProto.quadratic_constraint)
    // }
    // inline ::operations_research::MPQuadraticConstraint* MPGeneralConstraintProto::_internal_mutable_quadratic_constraint()
    // {
    //     if ( !_internal_has_quadratic_constraint() )
    //     {
    //         clear_general_constraint();
    //         set_has_quadratic_constraint();
    //         _impl_.general_constraint_.quadratic_constraint_ = CreateMaybeMessage< ::operations_research::MPQuadraticConstraint >( GetArenaForAllocation() );
    //     }
    //     return _impl_.general_constraint_.quadratic_constraint_;
    // }
    // inline ::operations_research::MPQuadraticConstraint* MPGeneralConstraintProto::mutable_quadratic_constraint()
    // {
    //     ::operations_research::MPQuadraticConstraint* _msg = _internal_mutable_quadratic_constraint();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPGeneralConstraintProto.quadratic_constraint)
    //     return _msg;
    // }

    // // .operations_research.MPAbsConstraint abs_constraint = 5;
    // inline bool MPGeneralConstraintProto::_internal_has_abs_constraint() const
    // {
    //     return general_constraint_case() == kAbsConstraint;
    // }
    // inline bool MPGeneralConstraintProto::has_abs_constraint() const
    // {
    //     return _internal_has_abs_constraint();
    // }
    // inline void MPGeneralConstraintProto::set_has_abs_constraint()
    // {
    //     _impl_._oneof_case_[ 0 ] = kAbsConstraint;
    // }
    // inline void MPGeneralConstraintProto::clear_abs_constraint()
    // {
    //     if ( _internal_has_abs_constraint() )
    //     {
    //         if ( GetArenaForAllocation() == nullptr )
    //         {
    //             delete _impl_.general_constraint_.abs_constraint_;
    //         }
    //         clear_has_general_constraint();
    //     }
    // }
    // inline ::operations_research::MPAbsConstraint* MPGeneralConstraintProto::release_abs_constraint()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPGeneralConstraintProto.abs_constraint)
    //     if ( _internal_has_abs_constraint() )
    //     {
    //         clear_has_general_constraint();
    //         ::operations_research::MPAbsConstraint* temp = _impl_.general_constraint_.abs_constraint_;
    //         if ( GetArenaForAllocation() != nullptr )
    //         {
    //             temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //         }
    //         _impl_.general_constraint_.abs_constraint_ = nullptr;
    //         return temp;
    //     }
    //     else
    //     {
    //         return nullptr;
    //     }
    // }
    // inline const ::operations_research::MPAbsConstraint& MPGeneralConstraintProto::_internal_abs_constraint() const
    // {
    //     return _internal_has_abs_constraint()
    //                ? *_impl_.general_constraint_.abs_constraint_
    //                : reinterpret_cast< ::operations_research::MPAbsConstraint& >( ::operations_research::_MPAbsConstraint_default_instance_ );
    // }
    // inline const ::operations_research::MPAbsConstraint& MPGeneralConstraintProto::abs_constraint() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPGeneralConstraintProto.abs_constraint)
    //     return _internal_abs_constraint();
    // }
    // inline ::operations_research::MPAbsConstraint* MPGeneralConstraintProto::unsafe_arena_release_abs_constraint()
    // {
    //     // @@protoc_insertion_point(field_unsafe_arena_release:operations_research.MPGeneralConstraintProto.abs_constraint)
    //     if ( _internal_has_abs_constraint() )
    //     {
    //         clear_has_general_constraint();
    //         ::operations_research::MPAbsConstraint* temp = _impl_.general_constraint_.abs_constraint_;
    //         _impl_.general_constraint_.abs_constraint_   = nullptr;
    //         return temp;
    //     }
    //     else
    //     {
    //         return nullptr;
    //     }
    // }
    // inline void MPGeneralConstraintProto::unsafe_arena_set_allocated_abs_constraint( ::operations_research::MPAbsConstraint* abs_constraint )
    // {
    //     clear_general_constraint();
    //     if ( abs_constraint )
    //     {
    //         set_has_abs_constraint();
    //         _impl_.general_constraint_.abs_constraint_ = abs_constraint;
    //     }
    //     // @@protoc_insertion_point(field_unsafe_arena_set_allocated:operations_research.MPGeneralConstraintProto.abs_constraint)
    // }
    // inline ::operations_research::MPAbsConstraint* MPGeneralConstraintProto::_internal_mutable_abs_constraint()
    // {
    //     if ( !_internal_has_abs_constraint() )
    //     {
    //         clear_general_constraint();
    //         set_has_abs_constraint();
    //         _impl_.general_constraint_.abs_constraint_ = CreateMaybeMessage< ::operations_research::MPAbsConstraint >( GetArenaForAllocation() );
    //     }
    //     return _impl_.general_constraint_.abs_constraint_;
    // }
    // inline ::operations_research::MPAbsConstraint* MPGeneralConstraintProto::mutable_abs_constraint()
    // {
    //     ::operations_research::MPAbsConstraint* _msg = _internal_mutable_abs_constraint();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPGeneralConstraintProto.abs_constraint)
    //     return _msg;
    // }

    // // .operations_research.MPArrayConstraint and_constraint = 6;
    // inline bool MPGeneralConstraintProto::_internal_has_and_constraint() const
    // {
    //     return general_constraint_case() == kAndConstraint;
    // }
    // inline bool MPGeneralConstraintProto::has_and_constraint() const
    // {
    //     return _internal_has_and_constraint();
    // }
    // inline void MPGeneralConstraintProto::set_has_and_constraint()
    // {
    //     _impl_._oneof_case_[ 0 ] = kAndConstraint;
    // }
    // inline void MPGeneralConstraintProto::clear_and_constraint()
    // {
    //     if ( _internal_has_and_constraint() )
    //     {
    //         if ( GetArenaForAllocation() == nullptr )
    //         {
    //             delete _impl_.general_constraint_.and_constraint_;
    //         }
    //         clear_has_general_constraint();
    //     }
    // }
    // inline ::operations_research::MPArrayConstraint* MPGeneralConstraintProto::release_and_constraint()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPGeneralConstraintProto.and_constraint)
    //     if ( _internal_has_and_constraint() )
    //     {
    //         clear_has_general_constraint();
    //         ::operations_research::MPArrayConstraint* temp = _impl_.general_constraint_.and_constraint_;
    //         if ( GetArenaForAllocation() != nullptr )
    //         {
    //             temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //         }
    //         _impl_.general_constraint_.and_constraint_ = nullptr;
    //         return temp;
    //     }
    //     else
    //     {
    //         return nullptr;
    //     }
    // }
    // inline const ::operations_research::MPArrayConstraint& MPGeneralConstraintProto::_internal_and_constraint() const
    // {
    //     return _internal_has_and_constraint()
    //                ? *_impl_.general_constraint_.and_constraint_
    //                : reinterpret_cast< ::operations_research::MPArrayConstraint& >( ::operations_research::_MPArrayConstraint_default_instance_ );
    // }
    // inline const ::operations_research::MPArrayConstraint& MPGeneralConstraintProto::and_constraint() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPGeneralConstraintProto.and_constraint)
    //     return _internal_and_constraint();
    // }
    // inline ::operations_research::MPArrayConstraint* MPGeneralConstraintProto::unsafe_arena_release_and_constraint()
    // {
    //     // @@protoc_insertion_point(field_unsafe_arena_release:operations_research.MPGeneralConstraintProto.and_constraint)
    //     if ( _internal_has_and_constraint() )
    //     {
    //         clear_has_general_constraint();
    //         ::operations_research::MPArrayConstraint* temp = _impl_.general_constraint_.and_constraint_;
    //         _impl_.general_constraint_.and_constraint_     = nullptr;
    //         return temp;
    //     }
    //     else
    //     {
    //         return nullptr;
    //     }
    // }
    // inline void MPGeneralConstraintProto::unsafe_arena_set_allocated_and_constraint( ::operations_research::MPArrayConstraint* and_constraint )
    // {
    //     clear_general_constraint();
    //     if ( and_constraint )
    //     {
    //         set_has_and_constraint();
    //         _impl_.general_constraint_.and_constraint_ = and_constraint;
    //     }
    //     // @@protoc_insertion_point(field_unsafe_arena_set_allocated:operations_research.MPGeneralConstraintProto.and_constraint)
    // }
    // inline ::operations_research::MPArrayConstraint* MPGeneralConstraintProto::_internal_mutable_and_constraint()
    // {
    //     if ( !_internal_has_and_constraint() )
    //     {
    //         clear_general_constraint();
    //         set_has_and_constraint();
    //         _impl_.general_constraint_.and_constraint_ = CreateMaybeMessage< ::operations_research::MPArrayConstraint >( GetArenaForAllocation() );
    //     }
    //     return _impl_.general_constraint_.and_constraint_;
    // }
    // inline ::operations_research::MPArrayConstraint* MPGeneralConstraintProto::mutable_and_constraint()
    // {
    //     ::operations_research::MPArrayConstraint* _msg = _internal_mutable_and_constraint();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPGeneralConstraintProto.and_constraint)
    //     return _msg;
    // }

    // // .operations_research.MPArrayConstraint or_constraint = 7;
    // inline bool MPGeneralConstraintProto::_internal_has_or_constraint() const
    // {
    //     return general_constraint_case() == kOrConstraint;
    // }
    // inline bool MPGeneralConstraintProto::has_or_constraint() const
    // {
    //     return _internal_has_or_constraint();
    // }
    // inline void MPGeneralConstraintProto::set_has_or_constraint()
    // {
    //     _impl_._oneof_case_[ 0 ] = kOrConstraint;
    // }
    // inline void MPGeneralConstraintProto::clear_or_constraint()
    // {
    //     if ( _internal_has_or_constraint() )
    //     {
    //         if ( GetArenaForAllocation() == nullptr )
    //         {
    //             delete _impl_.general_constraint_.or_constraint_;
    //         }
    //         clear_has_general_constraint();
    //     }
    // }
    // inline ::operations_research::MPArrayConstraint* MPGeneralConstraintProto::release_or_constraint()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPGeneralConstraintProto.or_constraint)
    //     if ( _internal_has_or_constraint() )
    //     {
    //         clear_has_general_constraint();
    //         ::operations_research::MPArrayConstraint* temp = _impl_.general_constraint_.or_constraint_;
    //         if ( GetArenaForAllocation() != nullptr )
    //         {
    //             temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //         }
    //         _impl_.general_constraint_.or_constraint_ = nullptr;
    //         return temp;
    //     }
    //     else
    //     {
    //         return nullptr;
    //     }
    // }
    // inline const ::operations_research::MPArrayConstraint& MPGeneralConstraintProto::_internal_or_constraint() const
    // {
    //     return _internal_has_or_constraint()
    //                ? *_impl_.general_constraint_.or_constraint_
    //                : reinterpret_cast< ::operations_research::MPArrayConstraint& >( ::operations_research::_MPArrayConstraint_default_instance_ );
    // }
    // inline const ::operations_research::MPArrayConstraint& MPGeneralConstraintProto::or_constraint() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPGeneralConstraintProto.or_constraint)
    //     return _internal_or_constraint();
    // }
    // inline ::operations_research::MPArrayConstraint* MPGeneralConstraintProto::unsafe_arena_release_or_constraint()
    // {
    //     // @@protoc_insertion_point(field_unsafe_arena_release:operations_research.MPGeneralConstraintProto.or_constraint)
    //     if ( _internal_has_or_constraint() )
    //     {
    //         clear_has_general_constraint();
    //         ::operations_research::MPArrayConstraint* temp = _impl_.general_constraint_.or_constraint_;
    //         _impl_.general_constraint_.or_constraint_      = nullptr;
    //         return temp;
    //     }
    //     else
    //     {
    //         return nullptr;
    //     }
    // }
    // inline void MPGeneralConstraintProto::unsafe_arena_set_allocated_or_constraint( ::operations_research::MPArrayConstraint* or_constraint )
    // {
    //     clear_general_constraint();
    //     if ( or_constraint )
    //     {
    //         set_has_or_constraint();
    //         _impl_.general_constraint_.or_constraint_ = or_constraint;
    //     }
    //     // @@protoc_insertion_point(field_unsafe_arena_set_allocated:operations_research.MPGeneralConstraintProto.or_constraint)
    // }
    // inline ::operations_research::MPArrayConstraint* MPGeneralConstraintProto::_internal_mutable_or_constraint()
    // {
    //     if ( !_internal_has_or_constraint() )
    //     {
    //         clear_general_constraint();
    //         set_has_or_constraint();
    //         _impl_.general_constraint_.or_constraint_ = CreateMaybeMessage< ::operations_research::MPArrayConstraint >( GetArenaForAllocation() );
    //     }
    //     return _impl_.general_constraint_.or_constraint_;
    // }
    // inline ::operations_research::MPArrayConstraint* MPGeneralConstraintProto::mutable_or_constraint()
    // {
    //     ::operations_research::MPArrayConstraint* _msg = _internal_mutable_or_constraint();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPGeneralConstraintProto.or_constraint)
    //     return _msg;
    // }

    // // .operations_research.MPArrayWithConstantConstraint min_constraint = 8;
    // inline bool MPGeneralConstraintProto::_internal_has_min_constraint() const
    // {
    //     return general_constraint_case() == kMinConstraint;
    // }
    // inline bool MPGeneralConstraintProto::has_min_constraint() const
    // {
    //     return _internal_has_min_constraint();
    // }
    // inline void MPGeneralConstraintProto::set_has_min_constraint()
    // {
    //     _impl_._oneof_case_[ 0 ] = kMinConstraint;
    // }
    // inline void MPGeneralConstraintProto::clear_min_constraint()
    // {
    //     if ( _internal_has_min_constraint() )
    //     {
    //         if ( GetArenaForAllocation() == nullptr )
    //         {
    //             delete _impl_.general_constraint_.min_constraint_;
    //         }
    //         clear_has_general_constraint();
    //     }
    // }
    // inline ::operations_research::MPArrayWithConstantConstraint* MPGeneralConstraintProto::release_min_constraint()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPGeneralConstraintProto.min_constraint)
    //     if ( _internal_has_min_constraint() )
    //     {
    //         clear_has_general_constraint();
    //         ::operations_research::MPArrayWithConstantConstraint* temp = _impl_.general_constraint_.min_constraint_;
    //         if ( GetArenaForAllocation() != nullptr )
    //         {
    //             temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //         }
    //         _impl_.general_constraint_.min_constraint_ = nullptr;
    //         return temp;
    //     }
    //     else
    //     {
    //         return nullptr;
    //     }
    // }
    // inline const ::operations_research::MPArrayWithConstantConstraint& MPGeneralConstraintProto::_internal_min_constraint() const
    // {
    //     return _internal_has_min_constraint()
    //                ? *_impl_.general_constraint_.min_constraint_
    //                : reinterpret_cast< ::operations_research::MPArrayWithConstantConstraint& >( ::operations_research::_MPArrayWithConstantConstraint_default_instance_ );
    // }
    // inline const ::operations_research::MPArrayWithConstantConstraint& MPGeneralConstraintProto::min_constraint() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPGeneralConstraintProto.min_constraint)
    //     return _internal_min_constraint();
    // }
    // inline ::operations_research::MPArrayWithConstantConstraint* MPGeneralConstraintProto::unsafe_arena_release_min_constraint()
    // {
    //     // @@protoc_insertion_point(field_unsafe_arena_release:operations_research.MPGeneralConstraintProto.min_constraint)
    //     if ( _internal_has_min_constraint() )
    //     {
    //         clear_has_general_constraint();
    //         ::operations_research::MPArrayWithConstantConstraint* temp = _impl_.general_constraint_.min_constraint_;
    //         _impl_.general_constraint_.min_constraint_                 = nullptr;
    //         return temp;
    //     }
    //     else
    //     {
    //         return nullptr;
    //     }
    // }
    // inline void MPGeneralConstraintProto::unsafe_arena_set_allocated_min_constraint( ::operations_research::MPArrayWithConstantConstraint* min_constraint )
    // {
    //     clear_general_constraint();
    //     if ( min_constraint )
    //     {
    //         set_has_min_constraint();
    //         _impl_.general_constraint_.min_constraint_ = min_constraint;
    //     }
    //     // @@protoc_insertion_point(field_unsafe_arena_set_allocated:operations_research.MPGeneralConstraintProto.min_constraint)
    // }
    // inline ::operations_research::MPArrayWithConstantConstraint* MPGeneralConstraintProto::_internal_mutable_min_constraint()
    // {
    //     if ( !_internal_has_min_constraint() )
    //     {
    //         clear_general_constraint();
    //         set_has_min_constraint();
    //         _impl_.general_constraint_.min_constraint_ = CreateMaybeMessage< ::operations_research::MPArrayWithConstantConstraint >( GetArenaForAllocation() );
    //     }
    //     return _impl_.general_constraint_.min_constraint_;
    // }
    // inline ::operations_research::MPArrayWithConstantConstraint* MPGeneralConstraintProto::mutable_min_constraint()
    // {
    //     ::operations_research::MPArrayWithConstantConstraint* _msg = _internal_mutable_min_constraint();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPGeneralConstraintProto.min_constraint)
    //     return _msg;
    // }

    // // .operations_research.MPArrayWithConstantConstraint max_constraint = 9;
    // inline bool MPGeneralConstraintProto::_internal_has_max_constraint() const
    // {
    //     return general_constraint_case() == kMaxConstraint;
    // }
    // inline bool MPGeneralConstraintProto::has_max_constraint() const
    // {
    //     return _internal_has_max_constraint();
    // }
    // inline void MPGeneralConstraintProto::set_has_max_constraint()
    // {
    //     _impl_._oneof_case_[ 0 ] = kMaxConstraint;
    // }
    // inline void MPGeneralConstraintProto::clear_max_constraint()
    // {
    //     if ( _internal_has_max_constraint() )
    //     {
    //         if ( GetArenaForAllocation() == nullptr )
    //         {
    //             delete _impl_.general_constraint_.max_constraint_;
    //         }
    //         clear_has_general_constraint();
    //     }
    // }
    // inline ::operations_research::MPArrayWithConstantConstraint* MPGeneralConstraintProto::release_max_constraint()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPGeneralConstraintProto.max_constraint)
    //     if ( _internal_has_max_constraint() )
    //     {
    //         clear_has_general_constraint();
    //         ::operations_research::MPArrayWithConstantConstraint* temp = _impl_.general_constraint_.max_constraint_;
    //         if ( GetArenaForAllocation() != nullptr )
    //         {
    //             temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //         }
    //         _impl_.general_constraint_.max_constraint_ = nullptr;
    //         return temp;
    //     }
    //     else
    //     {
    //         return nullptr;
    //     }
    // }
    // inline const ::operations_research::MPArrayWithConstantConstraint& MPGeneralConstraintProto::_internal_max_constraint() const
    // {
    //     return _internal_has_max_constraint()
    //                ? *_impl_.general_constraint_.max_constraint_
    //                : reinterpret_cast< ::operations_research::MPArrayWithConstantConstraint& >( ::operations_research::_MPArrayWithConstantConstraint_default_instance_ );
    // }
    // inline const ::operations_research::MPArrayWithConstantConstraint& MPGeneralConstraintProto::max_constraint() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPGeneralConstraintProto.max_constraint)
    //     return _internal_max_constraint();
    // }
    // inline ::operations_research::MPArrayWithConstantConstraint* MPGeneralConstraintProto::unsafe_arena_release_max_constraint()
    // {
    //     // @@protoc_insertion_point(field_unsafe_arena_release:operations_research.MPGeneralConstraintProto.max_constraint)
    //     if ( _internal_has_max_constraint() )
    //     {
    //         clear_has_general_constraint();
    //         ::operations_research::MPArrayWithConstantConstraint* temp = _impl_.general_constraint_.max_constraint_;
    //         _impl_.general_constraint_.max_constraint_                 = nullptr;
    //         return temp;
    //     }
    //     else
    //     {
    //         return nullptr;
    //     }
    // }
    // inline void MPGeneralConstraintProto::unsafe_arena_set_allocated_max_constraint( ::operations_research::MPArrayWithConstantConstraint* max_constraint )
    // {
    //     clear_general_constraint();
    //     if ( max_constraint )
    //     {
    //         set_has_max_constraint();
    //         _impl_.general_constraint_.max_constraint_ = max_constraint;
    //     }
    //     // @@protoc_insertion_point(field_unsafe_arena_set_allocated:operations_research.MPGeneralConstraintProto.max_constraint)
    // }
    // inline ::operations_research::MPArrayWithConstantConstraint* MPGeneralConstraintProto::_internal_mutable_max_constraint()
    // {
    //     if ( !_internal_has_max_constraint() )
    //     {
    //         clear_general_constraint();
    //         set_has_max_constraint();
    //         _impl_.general_constraint_.max_constraint_ = CreateMaybeMessage< ::operations_research::MPArrayWithConstantConstraint >( GetArenaForAllocation() );
    //     }
    //     return _impl_.general_constraint_.max_constraint_;
    // }
    // inline ::operations_research::MPArrayWithConstantConstraint* MPGeneralConstraintProto::mutable_max_constraint()
    // {
    //     ::operations_research::MPArrayWithConstantConstraint* _msg = _internal_mutable_max_constraint();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPGeneralConstraintProto.max_constraint)
    //     return _msg;
    // }

    // inline bool MPGeneralConstraintProto::has_general_constraint() const
    // {
    //     return general_constraint_case() != GENERAL_CONSTRAINT_NOT_SET;
    // }
    // inline void MPGeneralConstraintProto::clear_has_general_constraint()
    // {
    //     _impl_._oneof_case_[ 0 ] = GENERAL_CONSTRAINT_NOT_SET;
    // }
    // inline MPGeneralConstraintProto::GeneralConstraintCase MPGeneralConstraintProto::general_constraint_case() const
    // {
    //     return MPGeneralConstraintProto::GeneralConstraintCase( _impl_._oneof_case_[ 0 ] );
    // }
    // // -------------------------------------------------------------------

    // // MPIndicatorConstraint

    // // optional int32 var_index = 1;
    // inline bool MPIndicatorConstraint::_internal_has_var_index() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000002u ) != 0;
    //     return value;
    // }
    // inline bool MPIndicatorConstraint::has_var_index() const
    // {
    //     return _internal_has_var_index();
    // }
    // inline void MPIndicatorConstraint::clear_var_index()
    // {
    //     _impl_.var_index_ = 0;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    // }
    // inline int32_t MPIndicatorConstraint::_internal_var_index() const
    // {
    //     return _impl_.var_index_;
    // }
    // inline int32_t MPIndicatorConstraint::var_index() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPIndicatorConstraint.var_index)
    //     return _internal_var_index();
    // }
    // inline void MPIndicatorConstraint::_internal_set_var_index( int32_t value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000002u;
    //     _impl_.var_index_ = value;
    // }
    // inline void MPIndicatorConstraint::set_var_index( int32_t value )
    // {
    //     _internal_set_var_index( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPIndicatorConstraint.var_index)
    // }

    // // optional int32 var_value = 2;
    // inline bool MPIndicatorConstraint::_internal_has_var_value() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000004u ) != 0;
    //     return value;
    // }
    // inline bool MPIndicatorConstraint::has_var_value() const
    // {
    //     return _internal_has_var_value();
    // }
    // inline void MPIndicatorConstraint::clear_var_value()
    // {
    //     _impl_.var_value_ = 0;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    // }
    // inline int32_t MPIndicatorConstraint::_internal_var_value() const
    // {
    //     return _impl_.var_value_;
    // }
    // inline int32_t MPIndicatorConstraint::var_value() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPIndicatorConstraint.var_value)
    //     return _internal_var_value();
    // }
    // inline void MPIndicatorConstraint::_internal_set_var_value( int32_t value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000004u;
    //     _impl_.var_value_ = value;
    // }
    // inline void MPIndicatorConstraint::set_var_value( int32_t value )
    // {
    //     _internal_set_var_value( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPIndicatorConstraint.var_value)
    // }

    // // optional .operations_research.MPConstraintProto constraint = 3;
    // inline bool MPIndicatorConstraint::_internal_has_constraint() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000001u ) != 0;
    //     PROTOBUF_ASSUME( !value || _impl_.constraint_ != nullptr );
    //     return value;
    // }
    // inline bool MPIndicatorConstraint::has_constraint() const
    // {
    //     return _internal_has_constraint();
    // }
    // inline void MPIndicatorConstraint::clear_constraint()
    // {
    //     if ( _impl_.constraint_ != nullptr ) _impl_.constraint_->Clear();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    // }
    // inline const ::operations_research::MPConstraintProto& MPIndicatorConstraint::_internal_constraint() const
    // {
    //     const ::operations_research::MPConstraintProto* p = _impl_.constraint_;
    //     return p != nullptr ? *p : reinterpret_cast< const ::operations_research::MPConstraintProto& >( ::operations_research::_MPConstraintProto_default_instance_ );
    // }
    // inline const ::operations_research::MPConstraintProto& MPIndicatorConstraint::constraint() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPIndicatorConstraint.constraint)
    //     return _internal_constraint();
    // }
    // inline void MPIndicatorConstraint::unsafe_arena_set_allocated_constraint(
    //     ::operations_research::MPConstraintProto* constraint )
    // {
    //     if ( GetArenaForAllocation() == nullptr )
    //     {
    //         delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite* >( _impl_.constraint_ );
    //     }
    //     _impl_.constraint_ = constraint;
    //     if ( constraint )
    //     {
    //         _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    //     }
    //     // @@protoc_insertion_point(field_unsafe_arena_set_allocated:operations_research.MPIndicatorConstraint.constraint)
    // }
    // inline ::operations_research::MPConstraintProto* MPIndicatorConstraint::release_constraint()
    // {
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    //     ::operations_research::MPConstraintProto* temp = _impl_.constraint_;
    //     _impl_.constraint_                             = nullptr;
    // #ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
    //     auto* old = reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite* >( temp );
    //     temp      = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //     if ( GetArenaForAllocation() == nullptr )
    //     {
    //         delete old;
    //     }
    // #else   // PROTOBUF_FORCE_COPY_IN_RELEASE
    //     if ( GetArenaForAllocation() != nullptr )
    //     {
    //         temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //     }
    // #endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
    //     return temp;
    // }
    // inline ::operations_research::MPConstraintProto* MPIndicatorConstraint::unsafe_arena_release_constraint()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPIndicatorConstraint.constraint)
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    //     ::operations_research::MPConstraintProto* temp = _impl_.constraint_;
    //     _impl_.constraint_                             = nullptr;
    //     return temp;
    // }
    // inline ::operations_research::MPConstraintProto* MPIndicatorConstraint::_internal_mutable_constraint()
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     if ( _impl_.constraint_ == nullptr )
    //     {
    //         auto* p            = CreateMaybeMessage< ::operations_research::MPConstraintProto >( GetArenaForAllocation() );
    //         _impl_.constraint_ = p;
    //     }
    //     return _impl_.constraint_;
    // }
    // inline ::operations_research::MPConstraintProto* MPIndicatorConstraint::mutable_constraint()
    // {
    //     ::operations_research::MPConstraintProto* _msg = _internal_mutable_constraint();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPIndicatorConstraint.constraint)
    //     return _msg;
    // }
    // inline void MPIndicatorConstraint::set_allocated_constraint( ::operations_research::MPConstraintProto* constraint )
    // {
    //     ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
    //     if ( message_arena == nullptr )
    //     {
    //         delete _impl_.constraint_;
    //     }
    //     if ( constraint )
    //     {
    //         ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
    //             ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena( constraint );
    //         if ( message_arena != submessage_arena )
    //         {
    //             constraint = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
    //                 message_arena, constraint, submessage_arena );
    //         }
    //         _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    //     }
    //     _impl_.constraint_ = constraint;
    //     // @@protoc_insertion_point(field_set_allocated:operations_research.MPIndicatorConstraint.constraint)
    // }

    // // -------------------------------------------------------------------

    // // MPSosConstraint

    // // optional .operations_research.MPSosConstraint.Type type = 1 [default = SOS1_DEFAULT];
    // inline bool MPSosConstraint::_internal_has_type() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000001u ) != 0;
    //     return value;
    // }
    // inline bool MPSosConstraint::has_type() const
    // {
    //     return _internal_has_type();
    // }
    // inline void MPSosConstraint::clear_type()
    // {
    //     _impl_.type_ = 0;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    // }
    // inline ::operations_research::MPSosConstraint_Type MPSosConstraint::_internal_type() const
    // {
    //     return static_cast< ::operations_research::MPSosConstraint_Type >( _impl_.type_ );
    // }
    // inline ::operations_research::MPSosConstraint_Type MPSosConstraint::type() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPSosConstraint.type)
    //     return _internal_type();
    // }
    // inline void MPSosConstraint::_internal_set_type( ::operations_research::MPSosConstraint_Type value )
    // {
    //     assert( ::operations_research::MPSosConstraint_Type_IsValid( value ) );
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     _impl_.type_ = value;
    // }
    // inline void MPSosConstraint::set_type( ::operations_research::MPSosConstraint_Type value )
    // {
    //     _internal_set_type( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPSosConstraint.type)
    // }

    // // repeated int32 var_index = 2;
    // inline int MPSosConstraint::_internal_var_index_size() const
    // {
    //     return _impl_.var_index_.size();
    // }
    // inline int MPSosConstraint::var_index_size() const
    // {
    //     return _internal_var_index_size();
    // }
    // inline void MPSosConstraint::clear_var_index()
    // {
    //     _impl_.var_index_.Clear();
    // }
    // inline int32_t MPSosConstraint::_internal_var_index( int index ) const
    // {
    //     return _impl_.var_index_.Get( index );
    // }
    // inline int32_t MPSosConstraint::var_index( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPSosConstraint.var_index)
    //     return _internal_var_index( index );
    // }
    // inline void MPSosConstraint::set_var_index( int index, int32_t value )
    // {
    //     _impl_.var_index_.Set( index, value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPSosConstraint.var_index)
    // }
    // inline void MPSosConstraint::_internal_add_var_index( int32_t value )
    // {
    //     _impl_.var_index_.Add( value );
    // }
    // inline void MPSosConstraint::add_var_index( int32_t value )
    // {
    //     _internal_add_var_index( value );
    //     // @@protoc_insertion_point(field_add:operations_research.MPSosConstraint.var_index)
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
    // MPSosConstraint::_internal_var_index() const
    // {
    //     return _impl_.var_index_;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
    // MPSosConstraint::var_index() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.MPSosConstraint.var_index)
    //     return _internal_var_index();
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
    // MPSosConstraint::_internal_mutable_var_index()
    // {
    //     return &_impl_.var_index_;
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
    // MPSosConstraint::mutable_var_index()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.MPSosConstraint.var_index)
    //     return _internal_mutable_var_index();
    // }

    // // repeated double weight = 3;
    // inline int MPSosConstraint::_internal_weight_size() const
    // {
    //     return _impl_.weight_.size();
    // }
    // inline int MPSosConstraint::weight_size() const
    // {
    //     return _internal_weight_size();
    // }
    // inline void MPSosConstraint::clear_weight()
    // {
    //     _impl_.weight_.Clear();
    // }
    // inline double MPSosConstraint::_internal_weight( int index ) const
    // {
    //     return _impl_.weight_.Get( index );
    // }
    // inline double MPSosConstraint::weight( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPSosConstraint.weight)
    //     return _internal_weight( index );
    // }
    // inline void MPSosConstraint::set_weight( int index, double value )
    // {
    //     _impl_.weight_.Set( index, value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPSosConstraint.weight)
    // }
    // inline void MPSosConstraint::_internal_add_weight( double value )
    // {
    //     _impl_.weight_.Add( value );
    // }
    // inline void MPSosConstraint::add_weight( double value )
    // {
    //     _internal_add_weight( value );
    //     // @@protoc_insertion_point(field_add:operations_research.MPSosConstraint.weight)
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    // MPSosConstraint::_internal_weight() const
    // {
    //     return _impl_.weight_;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    // MPSosConstraint::weight() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.MPSosConstraint.weight)
    //     return _internal_weight();
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    // MPSosConstraint::_internal_mutable_weight()
    // {
    //     return &_impl_.weight_;
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    // MPSosConstraint::mutable_weight()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.MPSosConstraint.weight)
    //     return _internal_mutable_weight();
    // }

    // // -------------------------------------------------------------------

    // // MPQuadraticConstraint

    // // repeated int32 var_index = 1;
    // inline int MPQuadraticConstraint::_internal_var_index_size() const
    // {
    //     return _impl_.var_index_.size();
    // }
    // inline int MPQuadraticConstraint::var_index_size() const
    // {
    //     return _internal_var_index_size();
    // }
    // inline void MPQuadraticConstraint::clear_var_index()
    // {
    //     _impl_.var_index_.Clear();
    // }
    // inline int32_t MPQuadraticConstraint::_internal_var_index( int index ) const
    // {
    //     return _impl_.var_index_.Get( index );
    // }
    // inline int32_t MPQuadraticConstraint::var_index( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPQuadraticConstraint.var_index)
    //     return _internal_var_index( index );
    // }
    // inline void MPQuadraticConstraint::set_var_index( int index, int32_t value )
    // {
    //     _impl_.var_index_.Set( index, value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPQuadraticConstraint.var_index)
    // }
    // inline void MPQuadraticConstraint::_internal_add_var_index( int32_t value )
    // {
    //     _impl_.var_index_.Add( value );
    // }
    // inline void MPQuadraticConstraint::add_var_index( int32_t value )
    // {
    //     _internal_add_var_index( value );
    //     // @@protoc_insertion_point(field_add:operations_research.MPQuadraticConstraint.var_index)
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
    // MPQuadraticConstraint::_internal_var_index() const
    // {
    //     return _impl_.var_index_;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
    // MPQuadraticConstraint::var_index() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.MPQuadraticConstraint.var_index)
    //     return _internal_var_index();
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
    // MPQuadraticConstraint::_internal_mutable_var_index()
    // {
    //     return &_impl_.var_index_;
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
    // MPQuadraticConstraint::mutable_var_index()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.MPQuadraticConstraint.var_index)
    //     return _internal_mutable_var_index();
    // }

    // // repeated double coefficient = 2;
    // inline int MPQuadraticConstraint::_internal_coefficient_size() const
    // {
    //     return _impl_.coefficient_.size();
    // }
    // inline int MPQuadraticConstraint::coefficient_size() const
    // {
    //     return _internal_coefficient_size();
    // }
    // inline void MPQuadraticConstraint::clear_coefficient()
    // {
    //     _impl_.coefficient_.Clear();
    // }
    // inline double MPQuadraticConstraint::_internal_coefficient( int index ) const
    // {
    //     return _impl_.coefficient_.Get( index );
    // }
    // inline double MPQuadraticConstraint::coefficient( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPQuadraticConstraint.coefficient)
    //     return _internal_coefficient( index );
    // }
    // inline void MPQuadraticConstraint::set_coefficient( int index, double value )
    // {
    //     _impl_.coefficient_.Set( index, value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPQuadraticConstraint.coefficient)
    // }
    // inline void MPQuadraticConstraint::_internal_add_coefficient( double value )
    // {
    //     _impl_.coefficient_.Add( value );
    // }
    // inline void MPQuadraticConstraint::add_coefficient( double value )
    // {
    //     _internal_add_coefficient( value );
    //     // @@protoc_insertion_point(field_add:operations_research.MPQuadraticConstraint.coefficient)
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    // MPQuadraticConstraint::_internal_coefficient() const
    // {
    //     return _impl_.coefficient_;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    // MPQuadraticConstraint::coefficient() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.MPQuadraticConstraint.coefficient)
    //     return _internal_coefficient();
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    // MPQuadraticConstraint::_internal_mutable_coefficient()
    // {
    //     return &_impl_.coefficient_;
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    // MPQuadraticConstraint::mutable_coefficient()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.MPQuadraticConstraint.coefficient)
    //     return _internal_mutable_coefficient();
    // }

    // // repeated int32 qvar1_index = 3;
    // inline int MPQuadraticConstraint::_internal_qvar1_index_size() const
    // {
    //     return _impl_.qvar1_index_.size();
    // }
    // inline int MPQuadraticConstraint::qvar1_index_size() const
    // {
    //     return _internal_qvar1_index_size();
    // }
    // inline void MPQuadraticConstraint::clear_qvar1_index()
    // {
    //     _impl_.qvar1_index_.Clear();
    // }
    // inline int32_t MPQuadraticConstraint::_internal_qvar1_index( int index ) const
    // {
    //     return _impl_.qvar1_index_.Get( index );
    // }
    // inline int32_t MPQuadraticConstraint::qvar1_index( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPQuadraticConstraint.qvar1_index)
    //     return _internal_qvar1_index( index );
    // }
    // inline void MPQuadraticConstraint::set_qvar1_index( int index, int32_t value )
    // {
    //     _impl_.qvar1_index_.Set( index, value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPQuadraticConstraint.qvar1_index)
    // }
    // inline void MPQuadraticConstraint::_internal_add_qvar1_index( int32_t value )
    // {
    //     _impl_.qvar1_index_.Add( value );
    // }
    // inline void MPQuadraticConstraint::add_qvar1_index( int32_t value )
    // {
    //     _internal_add_qvar1_index( value );
    //     // @@protoc_insertion_point(field_add:operations_research.MPQuadraticConstraint.qvar1_index)
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
    // MPQuadraticConstraint::_internal_qvar1_index() const
    // {
    //     return _impl_.qvar1_index_;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
    // MPQuadraticConstraint::qvar1_index() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.MPQuadraticConstraint.qvar1_index)
    //     return _internal_qvar1_index();
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
    // MPQuadraticConstraint::_internal_mutable_qvar1_index()
    // {
    //     return &_impl_.qvar1_index_;
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
    // MPQuadraticConstraint::mutable_qvar1_index()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.MPQuadraticConstraint.qvar1_index)
    //     return _internal_mutable_qvar1_index();
    // }

    // // repeated int32 qvar2_index = 4;
    // inline int MPQuadraticConstraint::_internal_qvar2_index_size() const
    // {
    //     return _impl_.qvar2_index_.size();
    // }
    // inline int MPQuadraticConstraint::qvar2_index_size() const
    // {
    //     return _internal_qvar2_index_size();
    // }
    // inline void MPQuadraticConstraint::clear_qvar2_index()
    // {
    //     _impl_.qvar2_index_.Clear();
    // }
    // inline int32_t MPQuadraticConstraint::_internal_qvar2_index( int index ) const
    // {
    //     return _impl_.qvar2_index_.Get( index );
    // }
    // inline int32_t MPQuadraticConstraint::qvar2_index( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPQuadraticConstraint.qvar2_index)
    //     return _internal_qvar2_index( index );
    // }
    // inline void MPQuadraticConstraint::set_qvar2_index( int index, int32_t value )
    // {
    //     _impl_.qvar2_index_.Set( index, value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPQuadraticConstraint.qvar2_index)
    // }
    // inline void MPQuadraticConstraint::_internal_add_qvar2_index( int32_t value )
    // {
    //     _impl_.qvar2_index_.Add( value );
    // }
    // inline void MPQuadraticConstraint::add_qvar2_index( int32_t value )
    // {
    //     _internal_add_qvar2_index( value );
    //     // @@protoc_insertion_point(field_add:operations_research.MPQuadraticConstraint.qvar2_index)
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
    // MPQuadraticConstraint::_internal_qvar2_index() const
    // {
    //     return _impl_.qvar2_index_;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
    // MPQuadraticConstraint::qvar2_index() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.MPQuadraticConstraint.qvar2_index)
    //     return _internal_qvar2_index();
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
    // MPQuadraticConstraint::_internal_mutable_qvar2_index()
    // {
    //     return &_impl_.qvar2_index_;
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
    // MPQuadraticConstraint::mutable_qvar2_index()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.MPQuadraticConstraint.qvar2_index)
    //     return _internal_mutable_qvar2_index();
    // }

    // // repeated double qcoefficient = 5;
    // inline int MPQuadraticConstraint::_internal_qcoefficient_size() const
    // {
    //     return _impl_.qcoefficient_.size();
    // }
    // inline int MPQuadraticConstraint::qcoefficient_size() const
    // {
    //     return _internal_qcoefficient_size();
    // }
    // inline void MPQuadraticConstraint::clear_qcoefficient()
    // {
    //     _impl_.qcoefficient_.Clear();
    // }
    // inline double MPQuadraticConstraint::_internal_qcoefficient( int index ) const
    // {
    //     return _impl_.qcoefficient_.Get( index );
    // }
    // inline double MPQuadraticConstraint::qcoefficient( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPQuadraticConstraint.qcoefficient)
    //     return _internal_qcoefficient( index );
    // }
    // inline void MPQuadraticConstraint::set_qcoefficient( int index, double value )
    // {
    //     _impl_.qcoefficient_.Set( index, value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPQuadraticConstraint.qcoefficient)
    // }
    // inline void MPQuadraticConstraint::_internal_add_qcoefficient( double value )
    // {
    //     _impl_.qcoefficient_.Add( value );
    // }
    // inline void MPQuadraticConstraint::add_qcoefficient( double value )
    // {
    //     _internal_add_qcoefficient( value );
    //     // @@protoc_insertion_point(field_add:operations_research.MPQuadraticConstraint.qcoefficient)
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    // MPQuadraticConstraint::_internal_qcoefficient() const
    // {
    //     return _impl_.qcoefficient_;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    // MPQuadraticConstraint::qcoefficient() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.MPQuadraticConstraint.qcoefficient)
    //     return _internal_qcoefficient();
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    // MPQuadraticConstraint::_internal_mutable_qcoefficient()
    // {
    //     return &_impl_.qcoefficient_;
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    // MPQuadraticConstraint::mutable_qcoefficient()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.MPQuadraticConstraint.qcoefficient)
    //     return _internal_mutable_qcoefficient();
    // }

    // // optional double lower_bound = 6 [default = -inf];
    // inline bool MPQuadraticConstraint::_internal_has_lower_bound() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000001u ) != 0;
    //     return value;
    // }
    // inline bool MPQuadraticConstraint::has_lower_bound() const
    // {
    //     return _internal_has_lower_bound();
    // }
    // inline void MPQuadraticConstraint::clear_lower_bound()
    // {
    //     _impl_.lower_bound_ = -std::numeric_limits< double >::infinity();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    // }
    // inline double MPQuadraticConstraint::_internal_lower_bound() const
    // {
    //     return _impl_.lower_bound_;
    // }
    // inline double MPQuadraticConstraint::lower_bound() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPQuadraticConstraint.lower_bound)
    //     return _internal_lower_bound();
    // }
    // inline void MPQuadraticConstraint::_internal_set_lower_bound( double value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     _impl_.lower_bound_ = value;
    // }
    // inline void MPQuadraticConstraint::set_lower_bound( double value )
    // {
    //     _internal_set_lower_bound( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPQuadraticConstraint.lower_bound)
    // }

    // // optional double upper_bound = 7 [default = inf];
    // inline bool MPQuadraticConstraint::_internal_has_upper_bound() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000002u ) != 0;
    //     return value;
    // }
    // inline bool MPQuadraticConstraint::has_upper_bound() const
    // {
    //     return _internal_has_upper_bound();
    // }
    // inline void MPQuadraticConstraint::clear_upper_bound()
    // {
    //     _impl_.upper_bound_ = std::numeric_limits< double >::infinity();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    // }
    // inline double MPQuadraticConstraint::_internal_upper_bound() const
    // {
    //     return _impl_.upper_bound_;
    // }
    // inline double MPQuadraticConstraint::upper_bound() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPQuadraticConstraint.upper_bound)
    //     return _internal_upper_bound();
    // }
    // inline void MPQuadraticConstraint::_internal_set_upper_bound( double value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000002u;
    //     _impl_.upper_bound_ = value;
    // }
    // inline void MPQuadraticConstraint::set_upper_bound( double value )
    // {
    //     _internal_set_upper_bound( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPQuadraticConstraint.upper_bound)
    // }

    // // -------------------------------------------------------------------

    // // MPAbsConstraint

    // // optional int32 var_index = 1;
    // inline bool MPAbsConstraint::_internal_has_var_index() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000001u ) != 0;
    //     return value;
    // }
    // inline bool MPAbsConstraint::has_var_index() const
    // {
    //     return _internal_has_var_index();
    // }
    // inline void MPAbsConstraint::clear_var_index()
    // {
    //     _impl_.var_index_ = 0;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    // }
    // inline int32_t MPAbsConstraint::_internal_var_index() const
    // {
    //     return _impl_.var_index_;
    // }
    // inline int32_t MPAbsConstraint::var_index() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPAbsConstraint.var_index)
    //     return _internal_var_index();
    // }
    // inline void MPAbsConstraint::_internal_set_var_index( int32_t value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     _impl_.var_index_ = value;
    // }
    // inline void MPAbsConstraint::set_var_index( int32_t value )
    // {
    //     _internal_set_var_index( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPAbsConstraint.var_index)
    // }

    // // optional int32 resultant_var_index = 2;
    // inline bool MPAbsConstraint::_internal_has_resultant_var_index() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000002u ) != 0;
    //     return value;
    // }
    // inline bool MPAbsConstraint::has_resultant_var_index() const
    // {
    //     return _internal_has_resultant_var_index();
    // }
    // inline void MPAbsConstraint::clear_resultant_var_index()
    // {
    //     _impl_.resultant_var_index_ = 0;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    // }
    // inline int32_t MPAbsConstraint::_internal_resultant_var_index() const
    // {
    //     return _impl_.resultant_var_index_;
    // }
    // inline int32_t MPAbsConstraint::resultant_var_index() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPAbsConstraint.resultant_var_index)
    //     return _internal_resultant_var_index();
    // }
    // inline void MPAbsConstraint::_internal_set_resultant_var_index( int32_t value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000002u;
    //     _impl_.resultant_var_index_ = value;
    // }
    // inline void MPAbsConstraint::set_resultant_var_index( int32_t value )
    // {
    //     _internal_set_resultant_var_index( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPAbsConstraint.resultant_var_index)
    // }

    // // -------------------------------------------------------------------

    // // MPArrayConstraint

    // // repeated int32 var_index = 1;
    // inline int MPArrayConstraint::_internal_var_index_size() const
    // {
    //     return _impl_.var_index_.size();
    // }
    // inline int MPArrayConstraint::var_index_size() const
    // {
    //     return _internal_var_index_size();
    // }
    // inline void MPArrayConstraint::clear_var_index()
    // {
    //     _impl_.var_index_.Clear();
    // }
    // inline int32_t MPArrayConstraint::_internal_var_index( int index ) const
    // {
    //     return _impl_.var_index_.Get( index );
    // }
    // inline int32_t MPArrayConstraint::var_index( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPArrayConstraint.var_index)
    //     return _internal_var_index( index );
    // }
    // inline void MPArrayConstraint::set_var_index( int index, int32_t value )
    // {
    //     _impl_.var_index_.Set( index, value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPArrayConstraint.var_index)
    // }
    // inline void MPArrayConstraint::_internal_add_var_index( int32_t value )
    // {
    //     _impl_.var_index_.Add( value );
    // }
    // inline void MPArrayConstraint::add_var_index( int32_t value )
    // {
    //     _internal_add_var_index( value );
    //     // @@protoc_insertion_point(field_add:operations_research.MPArrayConstraint.var_index)
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
    // MPArrayConstraint::_internal_var_index() const
    // {
    //     return _impl_.var_index_;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
    // MPArrayConstraint::var_index() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.MPArrayConstraint.var_index)
    //     return _internal_var_index();
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
    // MPArrayConstraint::_internal_mutable_var_index()
    // {
    //     return &_impl_.var_index_;
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
    // MPArrayConstraint::mutable_var_index()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.MPArrayConstraint.var_index)
    //     return _internal_mutable_var_index();
    // }

    // // optional int32 resultant_var_index = 2;
    // inline bool MPArrayConstraint::_internal_has_resultant_var_index() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000001u ) != 0;
    //     return value;
    // }
    // inline bool MPArrayConstraint::has_resultant_var_index() const
    // {
    //     return _internal_has_resultant_var_index();
    // }
    // inline void MPArrayConstraint::clear_resultant_var_index()
    // {
    //     _impl_.resultant_var_index_ = 0;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    // }
    // inline int32_t MPArrayConstraint::_internal_resultant_var_index() const
    // {
    //     return _impl_.resultant_var_index_;
    // }
    // inline int32_t MPArrayConstraint::resultant_var_index() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPArrayConstraint.resultant_var_index)
    //     return _internal_resultant_var_index();
    // }
    // inline void MPArrayConstraint::_internal_set_resultant_var_index( int32_t value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     _impl_.resultant_var_index_ = value;
    // }
    // inline void MPArrayConstraint::set_resultant_var_index( int32_t value )
    // {
    //     _internal_set_resultant_var_index( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPArrayConstraint.resultant_var_index)
    // }

    // // -------------------------------------------------------------------

    // // MPArrayWithConstantConstraint

    // // repeated int32 var_index = 1;
    // inline int MPArrayWithConstantConstraint::_internal_var_index_size() const
    // {
    //     return _impl_.var_index_.size();
    // }
    // inline int MPArrayWithConstantConstraint::var_index_size() const
    // {
    //     return _internal_var_index_size();
    // }
    // inline void MPArrayWithConstantConstraint::clear_var_index()
    // {
    //     _impl_.var_index_.Clear();
    // }
    // inline int32_t MPArrayWithConstantConstraint::_internal_var_index( int index ) const
    // {
    //     return _impl_.var_index_.Get( index );
    // }
    // inline int32_t MPArrayWithConstantConstraint::var_index( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPArrayWithConstantConstraint.var_index)
    //     return _internal_var_index( index );
    // }
    // inline void MPArrayWithConstantConstraint::set_var_index( int index, int32_t value )
    // {
    //     _impl_.var_index_.Set( index, value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPArrayWithConstantConstraint.var_index)
    // }
    // inline void MPArrayWithConstantConstraint::_internal_add_var_index( int32_t value )
    // {
    //     _impl_.var_index_.Add( value );
    // }
    // inline void MPArrayWithConstantConstraint::add_var_index( int32_t value )
    // {
    //     _internal_add_var_index( value );
    //     // @@protoc_insertion_point(field_add:operations_research.MPArrayWithConstantConstraint.var_index)
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
    // MPArrayWithConstantConstraint::_internal_var_index() const
    // {
    //     return _impl_.var_index_;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
    // MPArrayWithConstantConstraint::var_index() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.MPArrayWithConstantConstraint.var_index)
    //     return _internal_var_index();
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
    // MPArrayWithConstantConstraint::_internal_mutable_var_index()
    // {
    //     return &_impl_.var_index_;
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
    // MPArrayWithConstantConstraint::mutable_var_index()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.MPArrayWithConstantConstraint.var_index)
    //     return _internal_mutable_var_index();
    // }

    // // optional double constant = 2;
    // inline bool MPArrayWithConstantConstraint::_internal_has_constant() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000001u ) != 0;
    //     return value;
    // }
    // inline bool MPArrayWithConstantConstraint::has_constant() const
    // {
    //     return _internal_has_constant();
    // }
    // inline void MPArrayWithConstantConstraint::clear_constant()
    // {
    //     _impl_.constant_ = 0;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    // }
    // inline double MPArrayWithConstantConstraint::_internal_constant() const
    // {
    //     return _impl_.constant_;
    // }
    // inline double MPArrayWithConstantConstraint::constant() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPArrayWithConstantConstraint.constant)
    //     return _internal_constant();
    // }
    // inline void MPArrayWithConstantConstraint::_internal_set_constant( double value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     _impl_.constant_ = value;
    // }
    // inline void MPArrayWithConstantConstraint::set_constant( double value )
    // {
    //     _internal_set_constant( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPArrayWithConstantConstraint.constant)
    // }

    // // optional int32 resultant_var_index = 3;
    // inline bool MPArrayWithConstantConstraint::_internal_has_resultant_var_index() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000002u ) != 0;
    //     return value;
    // }
    // inline bool MPArrayWithConstantConstraint::has_resultant_var_index() const
    // {
    //     return _internal_has_resultant_var_index();
    // }
    // inline void MPArrayWithConstantConstraint::clear_resultant_var_index()
    // {
    //     _impl_.resultant_var_index_ = 0;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    // }
    // inline int32_t MPArrayWithConstantConstraint::_internal_resultant_var_index() const
    // {
    //     return _impl_.resultant_var_index_;
    // }
    // inline int32_t MPArrayWithConstantConstraint::resultant_var_index() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPArrayWithConstantConstraint.resultant_var_index)
    //     return _internal_resultant_var_index();
    // }
    // inline void MPArrayWithConstantConstraint::_internal_set_resultant_var_index( int32_t value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000002u;
    //     _impl_.resultant_var_index_ = value;
    // }
    // inline void MPArrayWithConstantConstraint::set_resultant_var_index( int32_t value )
    // {
    //     _internal_set_resultant_var_index( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPArrayWithConstantConstraint.resultant_var_index)
    // }

    // // -------------------------------------------------------------------

    // // MPQuadraticObjective

    // // repeated int32 qvar1_index = 1;
    // inline int MPQuadraticObjective::_internal_qvar1_index_size() const
    // {
    //     return _impl_.qvar1_index_.size();
    // }
    // inline int MPQuadraticObjective::qvar1_index_size() const
    // {
    //     return _internal_qvar1_index_size();
    // }
    // inline void MPQuadraticObjective::clear_qvar1_index()
    // {
    //     _impl_.qvar1_index_.Clear();
    // }
    // inline int32_t MPQuadraticObjective::_internal_qvar1_index( int index ) const
    // {
    //     return _impl_.qvar1_index_.Get( index );
    // }
    // inline int32_t MPQuadraticObjective::qvar1_index( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPQuadraticObjective.qvar1_index)
    //     return _internal_qvar1_index( index );
    // }
    // inline void MPQuadraticObjective::set_qvar1_index( int index, int32_t value )
    // {
    //     _impl_.qvar1_index_.Set( index, value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPQuadraticObjective.qvar1_index)
    // }
    // inline void MPQuadraticObjective::_internal_add_qvar1_index( int32_t value )
    // {
    //     _impl_.qvar1_index_.Add( value );
    // }
    // inline void MPQuadraticObjective::add_qvar1_index( int32_t value )
    // {
    //     _internal_add_qvar1_index( value );
    //     // @@protoc_insertion_point(field_add:operations_research.MPQuadraticObjective.qvar1_index)
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
    // MPQuadraticObjective::_internal_qvar1_index() const
    // {
    //     return _impl_.qvar1_index_;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
    // MPQuadraticObjective::qvar1_index() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.MPQuadraticObjective.qvar1_index)
    //     return _internal_qvar1_index();
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
    // MPQuadraticObjective::_internal_mutable_qvar1_index()
    // {
    //     return &_impl_.qvar1_index_;
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
    // MPQuadraticObjective::mutable_qvar1_index()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.MPQuadraticObjective.qvar1_index)
    //     return _internal_mutable_qvar1_index();
    // }

    // // repeated int32 qvar2_index = 2;
    // inline int MPQuadraticObjective::_internal_qvar2_index_size() const
    // {
    //     return _impl_.qvar2_index_.size();
    // }
    // inline int MPQuadraticObjective::qvar2_index_size() const
    // {
    //     return _internal_qvar2_index_size();
    // }
    // inline void MPQuadraticObjective::clear_qvar2_index()
    // {
    //     _impl_.qvar2_index_.Clear();
    // }
    // inline int32_t MPQuadraticObjective::_internal_qvar2_index( int index ) const
    // {
    //     return _impl_.qvar2_index_.Get( index );
    // }
    // inline int32_t MPQuadraticObjective::qvar2_index( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPQuadraticObjective.qvar2_index)
    //     return _internal_qvar2_index( index );
    // }
    // inline void MPQuadraticObjective::set_qvar2_index( int index, int32_t value )
    // {
    //     _impl_.qvar2_index_.Set( index, value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPQuadraticObjective.qvar2_index)
    // }
    // inline void MPQuadraticObjective::_internal_add_qvar2_index( int32_t value )
    // {
    //     _impl_.qvar2_index_.Add( value );
    // }
    // inline void MPQuadraticObjective::add_qvar2_index( int32_t value )
    // {
    //     _internal_add_qvar2_index( value );
    //     // @@protoc_insertion_point(field_add:operations_research.MPQuadraticObjective.qvar2_index)
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
    // MPQuadraticObjective::_internal_qvar2_index() const
    // {
    //     return _impl_.qvar2_index_;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
    // MPQuadraticObjective::qvar2_index() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.MPQuadraticObjective.qvar2_index)
    //     return _internal_qvar2_index();
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
    // MPQuadraticObjective::_internal_mutable_qvar2_index()
    // {
    //     return &_impl_.qvar2_index_;
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
    // MPQuadraticObjective::mutable_qvar2_index()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.MPQuadraticObjective.qvar2_index)
    //     return _internal_mutable_qvar2_index();
    // }

    // // repeated double coefficient = 3;
    // inline int MPQuadraticObjective::_internal_coefficient_size() const
    // {
    //     return _impl_.coefficient_.size();
    // }
    // inline int MPQuadraticObjective::coefficient_size() const
    // {
    //     return _internal_coefficient_size();
    // }
    // inline void MPQuadraticObjective::clear_coefficient()
    // {
    //     _impl_.coefficient_.Clear();
    // }
    // inline double MPQuadraticObjective::_internal_coefficient( int index ) const
    // {
    //     return _impl_.coefficient_.Get( index );
    // }
    // inline double MPQuadraticObjective::coefficient( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPQuadraticObjective.coefficient)
    //     return _internal_coefficient( index );
    // }
    // inline void MPQuadraticObjective::set_coefficient( int index, double value )
    // {
    //     _impl_.coefficient_.Set( index, value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPQuadraticObjective.coefficient)
    // }
    // inline void MPQuadraticObjective::_internal_add_coefficient( double value )
    // {
    //     _impl_.coefficient_.Add( value );
    // }
    // inline void MPQuadraticObjective::add_coefficient( double value )
    // {
    //     _internal_add_coefficient( value );
    //     // @@protoc_insertion_point(field_add:operations_research.MPQuadraticObjective.coefficient)
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    // MPQuadraticObjective::_internal_coefficient() const
    // {
    //     return _impl_.coefficient_;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    // MPQuadraticObjective::coefficient() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.MPQuadraticObjective.coefficient)
    //     return _internal_coefficient();
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    // MPQuadraticObjective::_internal_mutable_coefficient()
    // {
    //     return &_impl_.coefficient_;
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    // MPQuadraticObjective::mutable_coefficient()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.MPQuadraticObjective.coefficient)
    //     return _internal_mutable_coefficient();
    // }

    // // -------------------------------------------------------------------

    // // PartialVariableAssignment

    // // repeated int32 var_index = 1 [packed = true];
    // inline int PartialVariableAssignment::_internal_var_index_size() const
    // {
    //     return _impl_.var_index_.size();
    // }
    // inline int PartialVariableAssignment::var_index_size() const
    // {
    //     return _internal_var_index_size();
    // }
    // inline void PartialVariableAssignment::clear_var_index()
    // {
    //     _impl_.var_index_.Clear();
    // }
    // inline int32_t PartialVariableAssignment::_internal_var_index( int index ) const
    // {
    //     return _impl_.var_index_.Get( index );
    // }
    // inline int32_t PartialVariableAssignment::var_index( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.PartialVariableAssignment.var_index)
    //     return _internal_var_index( index );
    // }
    // inline void PartialVariableAssignment::set_var_index( int index, int32_t value )
    // {
    //     _impl_.var_index_.Set( index, value );
    //     // @@protoc_insertion_point(field_set:operations_research.PartialVariableAssignment.var_index)
    // }
    // inline void PartialVariableAssignment::_internal_add_var_index( int32_t value )
    // {
    //     _impl_.var_index_.Add( value );
    // }
    // inline void PartialVariableAssignment::add_var_index( int32_t value )
    // {
    //     _internal_add_var_index( value );
    //     // @@protoc_insertion_point(field_add:operations_research.PartialVariableAssignment.var_index)
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
    // PartialVariableAssignment::_internal_var_index() const
    // {
    //     return _impl_.var_index_;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
    // PartialVariableAssignment::var_index() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.PartialVariableAssignment.var_index)
    //     return _internal_var_index();
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
    // PartialVariableAssignment::_internal_mutable_var_index()
    // {
    //     return &_impl_.var_index_;
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
    // PartialVariableAssignment::mutable_var_index()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.PartialVariableAssignment.var_index)
    //     return _internal_mutable_var_index();
    // }

    // // repeated double var_value = 2 [packed = true];
    // inline int PartialVariableAssignment::_internal_var_value_size() const
    // {
    //     return _impl_.var_value_.size();
    // }
    // inline int PartialVariableAssignment::var_value_size() const
    // {
    //     return _internal_var_value_size();
    // }
    // inline void PartialVariableAssignment::clear_var_value()
    // {
    //     _impl_.var_value_.Clear();
    // }
    // inline double PartialVariableAssignment::_internal_var_value( int index ) const
    // {
    //     return _impl_.var_value_.Get( index );
    // }
    // inline double PartialVariableAssignment::var_value( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.PartialVariableAssignment.var_value)
    //     return _internal_var_value( index );
    // }
    // inline void PartialVariableAssignment::set_var_value( int index, double value )
    // {
    //     _impl_.var_value_.Set( index, value );
    //     // @@protoc_insertion_point(field_set:operations_research.PartialVariableAssignment.var_value)
    // }
    // inline void PartialVariableAssignment::_internal_add_var_value( double value )
    // {
    //     _impl_.var_value_.Add( value );
    // }
    // inline void PartialVariableAssignment::add_var_value( double value )
    // {
    //     _internal_add_var_value( value );
    //     // @@protoc_insertion_point(field_add:operations_research.PartialVariableAssignment.var_value)
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    // PartialVariableAssignment::_internal_var_value() const
    // {
    //     return _impl_.var_value_;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    // PartialVariableAssignment::var_value() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.PartialVariableAssignment.var_value)
    //     return _internal_var_value();
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    // PartialVariableAssignment::_internal_mutable_var_value()
    // {
    //     return &_impl_.var_value_;
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    // PartialVariableAssignment::mutable_var_value()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.PartialVariableAssignment.var_value)
    //     return _internal_mutable_var_value();
    // }

    // // -------------------------------------------------------------------

    // // MPModelProto_Annotation

    // // optional .operations_research.MPModelProto.Annotation.TargetType target_type = 1;
    // inline bool MPModelProto_Annotation::_internal_has_target_type() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000008u ) != 0;
    //     return value;
    // }
    // inline bool MPModelProto_Annotation::has_target_type() const
    // {
    //     return _internal_has_target_type();
    // }
    // inline void MPModelProto_Annotation::clear_target_type()
    // {
    //     _impl_.target_type_ = 0;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000008u;
    // }
    // inline ::operations_research::MPModelProto_Annotation_TargetType MPModelProto_Annotation::_internal_target_type() const
    // {
    //     return static_cast< ::operations_research::MPModelProto_Annotation_TargetType >( _impl_.target_type_ );
    // }
    // inline ::operations_research::MPModelProto_Annotation_TargetType MPModelProto_Annotation::target_type() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPModelProto.Annotation.target_type)
    //     return _internal_target_type();
    // }
    // inline void MPModelProto_Annotation::_internal_set_target_type( ::operations_research::MPModelProto_Annotation_TargetType value )
    // {
    //     assert( ::operations_research::MPModelProto_Annotation_TargetType_IsValid( value ) );
    //     _impl_._has_bits_[ 0 ] |= 0x00000008u;
    //     _impl_.target_type_ = value;
    // }
    // inline void MPModelProto_Annotation::set_target_type( ::operations_research::MPModelProto_Annotation_TargetType value )
    // {
    //     _internal_set_target_type( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPModelProto.Annotation.target_type)
    // }

    // // optional int32 target_index = 2;
    // inline bool MPModelProto_Annotation::_internal_has_target_index() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000010u ) != 0;
    //     return value;
    // }
    // inline bool MPModelProto_Annotation::has_target_index() const
    // {
    //     return _internal_has_target_index();
    // }
    // inline void MPModelProto_Annotation::clear_target_index()
    // {
    //     _impl_.target_index_ = 0;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000010u;
    // }
    // inline int32_t MPModelProto_Annotation::_internal_target_index() const
    // {
    //     return _impl_.target_index_;
    // }
    // inline int32_t MPModelProto_Annotation::target_index() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPModelProto.Annotation.target_index)
    //     return _internal_target_index();
    // }
    // inline void MPModelProto_Annotation::_internal_set_target_index( int32_t value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000010u;
    //     _impl_.target_index_ = value;
    // }
    // inline void MPModelProto_Annotation::set_target_index( int32_t value )
    // {
    //     _internal_set_target_index( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPModelProto.Annotation.target_index)
    // }

    // // optional string target_name = 3;
    // inline bool MPModelProto_Annotation::_internal_has_target_name() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000001u ) != 0;
    //     return value;
    // }
    // inline bool MPModelProto_Annotation::has_target_name() const
    // {
    //     return _internal_has_target_name();
    // }
    // inline void MPModelProto_Annotation::clear_target_name()
    // {
    //     _impl_.target_name_.ClearToEmpty();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    // }
    // inline const std::string& MPModelProto_Annotation::target_name() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPModelProto.Annotation.target_name)
    //     return _internal_target_name();
    // }
    // template < typename ArgT0, typename... ArgT >
    // inline PROTOBUF_ALWAYS_INLINE void MPModelProto_Annotation::set_target_name( ArgT0&& arg0, ArgT... args )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     _impl_.target_name_.Set( static_cast< ArgT0&& >( arg0 ), args..., GetArenaForAllocation() );
    //     // @@protoc_insertion_point(field_set:operations_research.MPModelProto.Annotation.target_name)
    // }
    // inline std::string* MPModelProto_Annotation::mutable_target_name()
    // {
    //     std::string* _s = _internal_mutable_target_name();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPModelProto.Annotation.target_name)
    //     return _s;
    // }
    // inline const std::string& MPModelProto_Annotation::_internal_target_name() const
    // {
    //     return _impl_.target_name_.Get();
    // }
    // inline void MPModelProto_Annotation::_internal_set_target_name( const std::string& value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     _impl_.target_name_.Set( value, GetArenaForAllocation() );
    // }
    // inline std::string* MPModelProto_Annotation::_internal_mutable_target_name()
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     return _impl_.target_name_.Mutable( GetArenaForAllocation() );
    // }
    // inline std::string* MPModelProto_Annotation::release_target_name()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPModelProto.Annotation.target_name)
    //     if ( !_internal_has_target_name() )
    //     {
    //         return nullptr;
    //     }
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    //     auto* p = _impl_.target_name_.Release();
    // #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     if ( _impl_.target_name_.IsDefault() )
    //     {
    //         _impl_.target_name_.Set( "", GetArenaForAllocation() );
    //     }
    // #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     return p;
    // }
    // inline void MPModelProto_Annotation::set_allocated_target_name( std::string* target_name )
    // {
    //     if ( target_name != nullptr )
    //     {
    //         _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    //     }
    //     _impl_.target_name_.SetAllocated( target_name, GetArenaForAllocation() );
    // #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     if ( _impl_.target_name_.IsDefault() )
    //     {
    //         _impl_.target_name_.Set( "", GetArenaForAllocation() );
    //     }
    // #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //         // @@protoc_insertion_point(field_set_allocated:operations_research.MPModelProto.Annotation.target_name)
    // }

    // // optional string payload_key = 4;
    // inline bool MPModelProto_Annotation::_internal_has_payload_key() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000002u ) != 0;
    //     return value;
    // }
    // inline bool MPModelProto_Annotation::has_payload_key() const
    // {
    //     return _internal_has_payload_key();
    // }
    // inline void MPModelProto_Annotation::clear_payload_key()
    // {
    //     _impl_.payload_key_.ClearToEmpty();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    // }
    // inline const std::string& MPModelProto_Annotation::payload_key() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPModelProto.Annotation.payload_key)
    //     return _internal_payload_key();
    // }
    // template < typename ArgT0, typename... ArgT >
    // inline PROTOBUF_ALWAYS_INLINE void MPModelProto_Annotation::set_payload_key( ArgT0&& arg0, ArgT... args )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000002u;
    //     _impl_.payload_key_.Set( static_cast< ArgT0&& >( arg0 ), args..., GetArenaForAllocation() );
    //     // @@protoc_insertion_point(field_set:operations_research.MPModelProto.Annotation.payload_key)
    // }
    // inline std::string* MPModelProto_Annotation::mutable_payload_key()
    // {
    //     std::string* _s = _internal_mutable_payload_key();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPModelProto.Annotation.payload_key)
    //     return _s;
    // }
    // inline const std::string& MPModelProto_Annotation::_internal_payload_key() const
    // {
    //     return _impl_.payload_key_.Get();
    // }
    // inline void MPModelProto_Annotation::_internal_set_payload_key( const std::string& value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000002u;
    //     _impl_.payload_key_.Set( value, GetArenaForAllocation() );
    // }
    // inline std::string* MPModelProto_Annotation::_internal_mutable_payload_key()
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000002u;
    //     return _impl_.payload_key_.Mutable( GetArenaForAllocation() );
    // }
    // inline std::string* MPModelProto_Annotation::release_payload_key()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPModelProto.Annotation.payload_key)
    //     if ( !_internal_has_payload_key() )
    //     {
    //         return nullptr;
    //     }
    //     _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    //     auto* p = _impl_.payload_key_.Release();
    // #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     if ( _impl_.payload_key_.IsDefault() )
    //     {
    //         _impl_.payload_key_.Set( "", GetArenaForAllocation() );
    //     }
    // #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     return p;
    // }
    // inline void MPModelProto_Annotation::set_allocated_payload_key( std::string* payload_key )
    // {
    //     if ( payload_key != nullptr )
    //     {
    //         _impl_._has_bits_[ 0 ] |= 0x00000002u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    //     }
    //     _impl_.payload_key_.SetAllocated( payload_key, GetArenaForAllocation() );
    // #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     if ( _impl_.payload_key_.IsDefault() )
    //     {
    //         _impl_.payload_key_.Set( "", GetArenaForAllocation() );
    //     }
    // #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //         // @@protoc_insertion_point(field_set_allocated:operations_research.MPModelProto.Annotation.payload_key)
    // }

    // // optional string payload_value = 5;
    // inline bool MPModelProto_Annotation::_internal_has_payload_value() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000004u ) != 0;
    //     return value;
    // }
    // inline bool MPModelProto_Annotation::has_payload_value() const
    // {
    //     return _internal_has_payload_value();
    // }
    // inline void MPModelProto_Annotation::clear_payload_value()
    // {
    //     _impl_.payload_value_.ClearToEmpty();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    // }
    // inline const std::string& MPModelProto_Annotation::payload_value() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPModelProto.Annotation.payload_value)
    //     return _internal_payload_value();
    // }
    // template < typename ArgT0, typename... ArgT >
    // inline PROTOBUF_ALWAYS_INLINE void MPModelProto_Annotation::set_payload_value( ArgT0&& arg0, ArgT... args )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000004u;
    //     _impl_.payload_value_.Set( static_cast< ArgT0&& >( arg0 ), args..., GetArenaForAllocation() );
    //     // @@protoc_insertion_point(field_set:operations_research.MPModelProto.Annotation.payload_value)
    // }
    // inline std::string* MPModelProto_Annotation::mutable_payload_value()
    // {
    //     std::string* _s = _internal_mutable_payload_value();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPModelProto.Annotation.payload_value)
    //     return _s;
    // }
    // inline const std::string& MPModelProto_Annotation::_internal_payload_value() const
    // {
    //     return _impl_.payload_value_.Get();
    // }
    // inline void MPModelProto_Annotation::_internal_set_payload_value( const std::string& value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000004u;
    //     _impl_.payload_value_.Set( value, GetArenaForAllocation() );
    // }
    // inline std::string* MPModelProto_Annotation::_internal_mutable_payload_value()
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000004u;
    //     return _impl_.payload_value_.Mutable( GetArenaForAllocation() );
    // }
    // inline std::string* MPModelProto_Annotation::release_payload_value()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPModelProto.Annotation.payload_value)
    //     if ( !_internal_has_payload_value() )
    //     {
    //         return nullptr;
    //     }
    //     _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    //     auto* p = _impl_.payload_value_.Release();
    // #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     if ( _impl_.payload_value_.IsDefault() )
    //     {
    //         _impl_.payload_value_.Set( "", GetArenaForAllocation() );
    //     }
    // #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     return p;
    // }
    // inline void MPModelProto_Annotation::set_allocated_payload_value( std::string* payload_value )
    // {
    //     if ( payload_value != nullptr )
    //     {
    //         _impl_._has_bits_[ 0 ] |= 0x00000004u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    //     }
    //     _impl_.payload_value_.SetAllocated( payload_value, GetArenaForAllocation() );
    // #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     if ( _impl_.payload_value_.IsDefault() )
    //     {
    //         _impl_.payload_value_.Set( "", GetArenaForAllocation() );
    //     }
    // #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //         // @@protoc_insertion_point(field_set_allocated:operations_research.MPModelProto.Annotation.payload_value)
    // }

    // // -------------------------------------------------------------------

    // // MPModelProto

    // // repeated .operations_research.MPVariableProto variable = 3;
    // inline int MPModelProto::_internal_variable_size() const
    // {
    //     return _impl_.variable_.size();
    // }
    // inline int MPModelProto::variable_size() const
    // {
    //     return _internal_variable_size();
    // }
    // inline void MPModelProto::clear_variable()
    // {
    //     _impl_.variable_.Clear();
    // }
    // inline ::operations_research::MPVariableProto* MPModelProto::mutable_variable( int index )
    // {
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPModelProto.variable)
    //     return _impl_.variable_.Mutable( index );
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPVariableProto >*
    // MPModelProto::mutable_variable()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.MPModelProto.variable)
    //     return &_impl_.variable_;
    // }
    // inline const ::operations_research::MPVariableProto& MPModelProto::_internal_variable( int index ) const
    // {
    //     return _impl_.variable_.Get( index );
    // }
    // inline const ::operations_research::MPVariableProto& MPModelProto::variable( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPModelProto.variable)
    //     return _internal_variable( index );
    // }
    // inline ::operations_research::MPVariableProto* MPModelProto::_internal_add_variable()
    // {
    //     return _impl_.variable_.Add();
    // }
    // inline ::operations_research::MPVariableProto* MPModelProto::add_variable()
    // {
    //     ::operations_research::MPVariableProto* _add = _internal_add_variable();
    //     // @@protoc_insertion_point(field_add:operations_research.MPModelProto.variable)
    //     return _add;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPVariableProto >&
    // MPModelProto::variable() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.MPModelProto.variable)
    //     return _impl_.variable_;
    // }

    // // repeated .operations_research.MPConstraintProto constraint = 4;
    // inline int MPModelProto::_internal_constraint_size() const
    // {
    //     return _impl_.constraint_.size();
    // }
    // inline int MPModelProto::constraint_size() const
    // {
    //     return _internal_constraint_size();
    // }
    // inline void MPModelProto::clear_constraint()
    // {
    //     _impl_.constraint_.Clear();
    // }
    // inline ::operations_research::MPConstraintProto* MPModelProto::mutable_constraint( int index )
    // {
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPModelProto.constraint)
    //     return _impl_.constraint_.Mutable( index );
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPConstraintProto >*
    // MPModelProto::mutable_constraint()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.MPModelProto.constraint)
    //     return &_impl_.constraint_;
    // }
    // inline const ::operations_research::MPConstraintProto& MPModelProto::_internal_constraint( int index ) const
    // {
    //     return _impl_.constraint_.Get( index );
    // }
    // inline const ::operations_research::MPConstraintProto& MPModelProto::constraint( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPModelProto.constraint)
    //     return _internal_constraint( index );
    // }
    // inline ::operations_research::MPConstraintProto* MPModelProto::_internal_add_constraint()
    // {
    //     return _impl_.constraint_.Add();
    // }
    // inline ::operations_research::MPConstraintProto* MPModelProto::add_constraint()
    // {
    //     ::operations_research::MPConstraintProto* _add = _internal_add_constraint();
    //     // @@protoc_insertion_point(field_add:operations_research.MPModelProto.constraint)
    //     return _add;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPConstraintProto >&
    // MPModelProto::constraint() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.MPModelProto.constraint)
    //     return _impl_.constraint_;
    // }

    // // repeated .operations_research.MPGeneralConstraintProto general_constraint = 7;
    // inline int MPModelProto::_internal_general_constraint_size() const
    // {
    //     return _impl_.general_constraint_.size();
    // }
    // inline int MPModelProto::general_constraint_size() const
    // {
    //     return _internal_general_constraint_size();
    // }
    // inline void MPModelProto::clear_general_constraint()
    // {
    //     _impl_.general_constraint_.Clear();
    // }
    // inline ::operations_research::MPGeneralConstraintProto* MPModelProto::mutable_general_constraint( int index )
    // {
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPModelProto.general_constraint)
    //     return _impl_.general_constraint_.Mutable( index );
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPGeneralConstraintProto >*
    // MPModelProto::mutable_general_constraint()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.MPModelProto.general_constraint)
    //     return &_impl_.general_constraint_;
    // }
    // inline const ::operations_research::MPGeneralConstraintProto& MPModelProto::_internal_general_constraint( int index ) const
    // {
    //     return _impl_.general_constraint_.Get( index );
    // }
    // inline const ::operations_research::MPGeneralConstraintProto& MPModelProto::general_constraint( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPModelProto.general_constraint)
    //     return _internal_general_constraint( index );
    // }
    // inline ::operations_research::MPGeneralConstraintProto* MPModelProto::_internal_add_general_constraint()
    // {
    //     return _impl_.general_constraint_.Add();
    // }
    // inline ::operations_research::MPGeneralConstraintProto* MPModelProto::add_general_constraint()
    // {
    //     ::operations_research::MPGeneralConstraintProto* _add = _internal_add_general_constraint();
    //     // @@protoc_insertion_point(field_add:operations_research.MPModelProto.general_constraint)
    //     return _add;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPGeneralConstraintProto >&
    // MPModelProto::general_constraint() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.MPModelProto.general_constraint)
    //     return _impl_.general_constraint_;
    // }

    // // optional bool maximize = 1 [default = false];
    // inline bool MPModelProto::_internal_has_maximize() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000010u ) != 0;
    //     return value;
    // }
    // inline bool MPModelProto::has_maximize() const
    // {
    //     return _internal_has_maximize();
    // }
    // inline void MPModelProto::clear_maximize()
    // {
    //     _impl_.maximize_ = false;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000010u;
    // }
    // inline bool MPModelProto::_internal_maximize() const
    // {
    //     return _impl_.maximize_;
    // }
    // inline bool MPModelProto::maximize() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPModelProto.maximize)
    //     return _internal_maximize();
    // }
    // inline void MPModelProto::_internal_set_maximize( bool value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000010u;
    //     _impl_.maximize_ = value;
    // }
    // inline void MPModelProto::set_maximize( bool value )
    // {
    //     _internal_set_maximize( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPModelProto.maximize)
    // }

    // // optional double objective_offset = 2 [default = 0];
    // inline bool MPModelProto::_internal_has_objective_offset() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000008u ) != 0;
    //     return value;
    // }
    // inline bool MPModelProto::has_objective_offset() const
    // {
    //     return _internal_has_objective_offset();
    // }
    // inline void MPModelProto::clear_objective_offset()
    // {
    //     _impl_.objective_offset_ = 0;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000008u;
    // }
    // inline double MPModelProto::_internal_objective_offset() const
    // {
    //     return _impl_.objective_offset_;
    // }
    // inline double MPModelProto::objective_offset() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPModelProto.objective_offset)
    //     return _internal_objective_offset();
    // }
    // inline void MPModelProto::_internal_set_objective_offset( double value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000008u;
    //     _impl_.objective_offset_ = value;
    // }
    // inline void MPModelProto::set_objective_offset( double value )
    // {
    //     _internal_set_objective_offset( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPModelProto.objective_offset)
    // }

    // // optional .operations_research.MPQuadraticObjective quadratic_objective = 8;
    // inline bool MPModelProto::_internal_has_quadratic_objective() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000004u ) != 0;
    //     PROTOBUF_ASSUME( !value || _impl_.quadratic_objective_ != nullptr );
    //     return value;
    // }
    // inline bool MPModelProto::has_quadratic_objective() const
    // {
    //     return _internal_has_quadratic_objective();
    // }
    // inline void MPModelProto::clear_quadratic_objective()
    // {
    //     if ( _impl_.quadratic_objective_ != nullptr ) _impl_.quadratic_objective_->Clear();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    // }
    // inline const ::operations_research::MPQuadraticObjective& MPModelProto::_internal_quadratic_objective() const
    // {
    //     const ::operations_research::MPQuadraticObjective* p = _impl_.quadratic_objective_;
    //     return p != nullptr ? *p : reinterpret_cast< const ::operations_research::MPQuadraticObjective& >( ::operations_research::_MPQuadraticObjective_default_instance_ );
    // }
    // inline const ::operations_research::MPQuadraticObjective& MPModelProto::quadratic_objective() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPModelProto.quadratic_objective)
    //     return _internal_quadratic_objective();
    // }
    // inline void MPModelProto::unsafe_arena_set_allocated_quadratic_objective(
    //     ::operations_research::MPQuadraticObjective* quadratic_objective )
    // {
    //     if ( GetArenaForAllocation() == nullptr )
    //     {
    //         delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite* >( _impl_.quadratic_objective_ );
    //     }
    //     _impl_.quadratic_objective_ = quadratic_objective;
    //     if ( quadratic_objective )
    //     {
    //         _impl_._has_bits_[ 0 ] |= 0x00000004u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    //     }
    //     // @@protoc_insertion_point(field_unsafe_arena_set_allocated:operations_research.MPModelProto.quadratic_objective)
    // }
    // inline ::operations_research::MPQuadraticObjective* MPModelProto::release_quadratic_objective()
    // {
    //     _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    //     ::operations_research::MPQuadraticObjective* temp = _impl_.quadratic_objective_;
    //     _impl_.quadratic_objective_                       = nullptr;
    // #ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
    //     auto* old = reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite* >( temp );
    //     temp      = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //     if ( GetArenaForAllocation() == nullptr )
    //     {
    //         delete old;
    //     }
    // #else   // PROTOBUF_FORCE_COPY_IN_RELEASE
    //     if ( GetArenaForAllocation() != nullptr )
    //     {
    //         temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //     }
    // #endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
    //     return temp;
    // }
    // inline ::operations_research::MPQuadraticObjective* MPModelProto::unsafe_arena_release_quadratic_objective()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPModelProto.quadratic_objective)
    //     _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    //     ::operations_research::MPQuadraticObjective* temp = _impl_.quadratic_objective_;
    //     _impl_.quadratic_objective_                       = nullptr;
    //     return temp;
    // }
    // inline ::operations_research::MPQuadraticObjective* MPModelProto::_internal_mutable_quadratic_objective()
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000004u;
    //     if ( _impl_.quadratic_objective_ == nullptr )
    //     {
    //         auto* p                     = CreateMaybeMessage< ::operations_research::MPQuadraticObjective >( GetArenaForAllocation() );
    //         _impl_.quadratic_objective_ = p;
    //     }
    //     return _impl_.quadratic_objective_;
    // }
    // inline ::operations_research::MPQuadraticObjective* MPModelProto::mutable_quadratic_objective()
    // {
    //     ::operations_research::MPQuadraticObjective* _msg = _internal_mutable_quadratic_objective();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPModelProto.quadratic_objective)
    //     return _msg;
    // }
    // inline void MPModelProto::set_allocated_quadratic_objective( ::operations_research::MPQuadraticObjective* quadratic_objective )
    // {
    //     ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
    //     if ( message_arena == nullptr )
    //     {
    //         delete _impl_.quadratic_objective_;
    //     }
    //     if ( quadratic_objective )
    //     {
    //         ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
    //             ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena( quadratic_objective );
    //         if ( message_arena != submessage_arena )
    //         {
    //             quadratic_objective = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
    //                 message_arena, quadratic_objective, submessage_arena );
    //         }
    //         _impl_._has_bits_[ 0 ] |= 0x00000004u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    //     }
    //     _impl_.quadratic_objective_ = quadratic_objective;
    //     // @@protoc_insertion_point(field_set_allocated:operations_research.MPModelProto.quadratic_objective)
    // }

    // // optional string name = 5 [default = ""];
    // inline bool MPModelProto::_internal_has_name() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000001u ) != 0;
    //     return value;
    // }
    // inline bool MPModelProto::has_name() const
    // {
    //     return _internal_has_name();
    // }
    // inline void MPModelProto::clear_name()
    // {
    //     _impl_.name_.ClearToEmpty();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    // }
    // inline const std::string& MPModelProto::name() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPModelProto.name)
    //     return _internal_name();
    // }
    // template < typename ArgT0, typename... ArgT >
    // inline PROTOBUF_ALWAYS_INLINE void MPModelProto::set_name( ArgT0&& arg0, ArgT... args )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     _impl_.name_.Set( static_cast< ArgT0&& >( arg0 ), args..., GetArenaForAllocation() );
    //     // @@protoc_insertion_point(field_set:operations_research.MPModelProto.name)
    // }
    // inline std::string* MPModelProto::mutable_name()
    // {
    //     std::string* _s = _internal_mutable_name();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPModelProto.name)
    //     return _s;
    // }
    // inline const std::string& MPModelProto::_internal_name() const
    // {
    //     return _impl_.name_.Get();
    // }
    // inline void MPModelProto::_internal_set_name( const std::string& value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     _impl_.name_.Set( value, GetArenaForAllocation() );
    // }
    // inline std::string* MPModelProto::_internal_mutable_name()
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     return _impl_.name_.Mutable( GetArenaForAllocation() );
    // }
    // inline std::string* MPModelProto::release_name()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPModelProto.name)
    //     if ( !_internal_has_name() )
    //     {
    //         return nullptr;
    //     }
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    //     auto* p = _impl_.name_.Release();
    // #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     if ( _impl_.name_.IsDefault() )
    //     {
    //         _impl_.name_.Set( "", GetArenaForAllocation() );
    //     }
    // #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     return p;
    // }
    // inline void MPModelProto::set_allocated_name( std::string* name )
    // {
    //     if ( name != nullptr )
    //     {
    //         _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    //     }
    //     _impl_.name_.SetAllocated( name, GetArenaForAllocation() );
    // #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     if ( _impl_.name_.IsDefault() )
    //     {
    //         _impl_.name_.Set( "", GetArenaForAllocation() );
    //     }
    // #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //         // @@protoc_insertion_point(field_set_allocated:operations_research.MPModelProto.name)
    // }

    // // optional .operations_research.PartialVariableAssignment solution_hint = 6;
    // inline bool MPModelProto::_internal_has_solution_hint() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000002u ) != 0;
    //     PROTOBUF_ASSUME( !value || _impl_.solution_hint_ != nullptr );
    //     return value;
    // }
    // inline bool MPModelProto::has_solution_hint() const
    // {
    //     return _internal_has_solution_hint();
    // }
    // inline void MPModelProto::clear_solution_hint()
    // {
    //     if ( _impl_.solution_hint_ != nullptr ) _impl_.solution_hint_->Clear();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    // }
    // inline const ::operations_research::PartialVariableAssignment& MPModelProto::_internal_solution_hint() const
    // {
    //     const ::operations_research::PartialVariableAssignment* p = _impl_.solution_hint_;
    //     return p != nullptr ? *p : reinterpret_cast< const ::operations_research::PartialVariableAssignment& >( ::operations_research::_PartialVariableAssignment_default_instance_ );
    // }
    // inline const ::operations_research::PartialVariableAssignment& MPModelProto::solution_hint() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPModelProto.solution_hint)
    //     return _internal_solution_hint();
    // }
    // inline void MPModelProto::unsafe_arena_set_allocated_solution_hint(
    //     ::operations_research::PartialVariableAssignment* solution_hint )
    // {
    //     if ( GetArenaForAllocation() == nullptr )
    //     {
    //         delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite* >( _impl_.solution_hint_ );
    //     }
    //     _impl_.solution_hint_ = solution_hint;
    //     if ( solution_hint )
    //     {
    //         _impl_._has_bits_[ 0 ] |= 0x00000002u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    //     }
    //     // @@protoc_insertion_point(field_unsafe_arena_set_allocated:operations_research.MPModelProto.solution_hint)
    // }
    // inline ::operations_research::PartialVariableAssignment* MPModelProto::release_solution_hint()
    // {
    //     _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    //     ::operations_research::PartialVariableAssignment* temp = _impl_.solution_hint_;
    //     _impl_.solution_hint_                                  = nullptr;
    // #ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
    //     auto* old = reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite* >( temp );
    //     temp      = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //     if ( GetArenaForAllocation() == nullptr )
    //     {
    //         delete old;
    //     }
    // #else   // PROTOBUF_FORCE_COPY_IN_RELEASE
    //     if ( GetArenaForAllocation() != nullptr )
    //     {
    //         temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //     }
    // #endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
    //     return temp;
    // }
    // inline ::operations_research::PartialVariableAssignment* MPModelProto::unsafe_arena_release_solution_hint()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPModelProto.solution_hint)
    //     _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    //     ::operations_research::PartialVariableAssignment* temp = _impl_.solution_hint_;
    //     _impl_.solution_hint_                                  = nullptr;
    //     return temp;
    // }
    // inline ::operations_research::PartialVariableAssignment* MPModelProto::_internal_mutable_solution_hint()
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000002u;
    //     if ( _impl_.solution_hint_ == nullptr )
    //     {
    //         auto* p               = CreateMaybeMessage< ::operations_research::PartialVariableAssignment >( GetArenaForAllocation() );
    //         _impl_.solution_hint_ = p;
    //     }
    //     return _impl_.solution_hint_;
    // }
    // inline ::operations_research::PartialVariableAssignment* MPModelProto::mutable_solution_hint()
    // {
    //     ::operations_research::PartialVariableAssignment* _msg = _internal_mutable_solution_hint();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPModelProto.solution_hint)
    //     return _msg;
    // }
    // inline void MPModelProto::set_allocated_solution_hint( ::operations_research::PartialVariableAssignment* solution_hint )
    // {
    //     ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
    //     if ( message_arena == nullptr )
    //     {
    //         delete _impl_.solution_hint_;
    //     }
    //     if ( solution_hint )
    //     {
    //         ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
    //             ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena( solution_hint );
    //         if ( message_arena != submessage_arena )
    //         {
    //             solution_hint = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
    //                 message_arena, solution_hint, submessage_arena );
    //         }
    //         _impl_._has_bits_[ 0 ] |= 0x00000002u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    //     }
    //     _impl_.solution_hint_ = solution_hint;
    //     // @@protoc_insertion_point(field_set_allocated:operations_research.MPModelProto.solution_hint)
    // }

    // // repeated .operations_research.MPModelProto.Annotation annotation = 9;
    // inline int MPModelProto::_internal_annotation_size() const
    // {
    //     return _impl_.annotation_.size();
    // }
    // inline int MPModelProto::annotation_size() const
    // {
    //     return _internal_annotation_size();
    // }
    // inline void MPModelProto::clear_annotation()
    // {
    //     _impl_.annotation_.Clear();
    // }
    // inline ::operations_research::MPModelProto_Annotation* MPModelProto::mutable_annotation( int index )
    // {
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPModelProto.annotation)
    //     return _impl_.annotation_.Mutable( index );
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPModelProto_Annotation >*
    // MPModelProto::mutable_annotation()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.MPModelProto.annotation)
    //     return &_impl_.annotation_;
    // }
    // inline const ::operations_research::MPModelProto_Annotation& MPModelProto::_internal_annotation( int index ) const
    // {
    //     return _impl_.annotation_.Get( index );
    // }
    // inline const ::operations_research::MPModelProto_Annotation& MPModelProto::annotation( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPModelProto.annotation)
    //     return _internal_annotation( index );
    // }
    // inline ::operations_research::MPModelProto_Annotation* MPModelProto::_internal_add_annotation()
    // {
    //     return _impl_.annotation_.Add();
    // }
    // inline ::operations_research::MPModelProto_Annotation* MPModelProto::add_annotation()
    // {
    //     ::operations_research::MPModelProto_Annotation* _add = _internal_add_annotation();
    //     // @@protoc_insertion_point(field_add:operations_research.MPModelProto.annotation)
    //     return _add;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPModelProto_Annotation >&
    // MPModelProto::annotation() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.MPModelProto.annotation)
    //     return _impl_.annotation_;
    // }

    // // -------------------------------------------------------------------

    // // OptionalDouble

    // // optional double value = 1;
    // inline bool OptionalDouble::_internal_has_value() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000001u ) != 0;
    //     return value;
    // }
    // inline bool OptionalDouble::has_value() const
    // {
    //     return _internal_has_value();
    // }
    // inline void OptionalDouble::clear_value()
    // {
    //     _impl_.value_ = 0;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    // }
    // inline double OptionalDouble::_internal_value() const
    // {
    //     return _impl_.value_;
    // }
    // inline double OptionalDouble::value() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.OptionalDouble.value)
    //     return _internal_value();
    // }
    // inline void OptionalDouble::_internal_set_value( double value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     _impl_.value_ = value;
    // }
    // inline void OptionalDouble::set_value( double value )
    // {
    //     _internal_set_value( value );
    //     // @@protoc_insertion_point(field_set:operations_research.OptionalDouble.value)
    // }

    // // -------------------------------------------------------------------

    // // MPSolverCommonParameters

    // // optional .operations_research.OptionalDouble relative_mip_gap = 1;
    // inline bool MPSolverCommonParameters::_internal_has_relative_mip_gap() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000001u ) != 0;
    //     PROTOBUF_ASSUME( !value || _impl_.relative_mip_gap_ != nullptr );
    //     return value;
    // }
    // inline bool MPSolverCommonParameters::has_relative_mip_gap() const
    // {
    //     return _internal_has_relative_mip_gap();
    // }
    // inline void MPSolverCommonParameters::clear_relative_mip_gap()
    // {
    //     if ( _impl_.relative_mip_gap_ != nullptr ) _impl_.relative_mip_gap_->Clear();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    // }
    // inline const ::operations_research::OptionalDouble& MPSolverCommonParameters::_internal_relative_mip_gap() const
    // {
    //     const ::operations_research::OptionalDouble* p = _impl_.relative_mip_gap_;
    //     return p != nullptr ? *p : reinterpret_cast< const ::operations_research::OptionalDouble& >( ::operations_research::_OptionalDouble_default_instance_ );
    // }
    // inline const ::operations_research::OptionalDouble& MPSolverCommonParameters::relative_mip_gap() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPSolverCommonParameters.relative_mip_gap)
    //     return _internal_relative_mip_gap();
    // }
    // inline void MPSolverCommonParameters::unsafe_arena_set_allocated_relative_mip_gap(
    //     ::operations_research::OptionalDouble* relative_mip_gap )
    // {
    //     if ( GetArenaForAllocation() == nullptr )
    //     {
    //         delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite* >( _impl_.relative_mip_gap_ );
    //     }
    //     _impl_.relative_mip_gap_ = relative_mip_gap;
    //     if ( relative_mip_gap )
    //     {
    //         _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    //     }
    //     // @@protoc_insertion_point(field_unsafe_arena_set_allocated:operations_research.MPSolverCommonParameters.relative_mip_gap)
    // }
    // inline ::operations_research::OptionalDouble* MPSolverCommonParameters::release_relative_mip_gap()
    // {
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    //     ::operations_research::OptionalDouble* temp = _impl_.relative_mip_gap_;
    //     _impl_.relative_mip_gap_                    = nullptr;
    // #ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
    //     auto* old = reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite* >( temp );
    //     temp      = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //     if ( GetArenaForAllocation() == nullptr )
    //     {
    //         delete old;
    //     }
    // #else   // PROTOBUF_FORCE_COPY_IN_RELEASE
    //     if ( GetArenaForAllocation() != nullptr )
    //     {
    //         temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //     }
    // #endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
    //     return temp;
    // }
    // inline ::operations_research::OptionalDouble* MPSolverCommonParameters::unsafe_arena_release_relative_mip_gap()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPSolverCommonParameters.relative_mip_gap)
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    //     ::operations_research::OptionalDouble* temp = _impl_.relative_mip_gap_;
    //     _impl_.relative_mip_gap_                    = nullptr;
    //     return temp;
    // }
    // inline ::operations_research::OptionalDouble* MPSolverCommonParameters::_internal_mutable_relative_mip_gap()
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     if ( _impl_.relative_mip_gap_ == nullptr )
    //     {
    //         auto* p                  = CreateMaybeMessage< ::operations_research::OptionalDouble >( GetArenaForAllocation() );
    //         _impl_.relative_mip_gap_ = p;
    //     }
    //     return _impl_.relative_mip_gap_;
    // }
    // inline ::operations_research::OptionalDouble* MPSolverCommonParameters::mutable_relative_mip_gap()
    // {
    //     ::operations_research::OptionalDouble* _msg = _internal_mutable_relative_mip_gap();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPSolverCommonParameters.relative_mip_gap)
    //     return _msg;
    // }
    // inline void MPSolverCommonParameters::set_allocated_relative_mip_gap( ::operations_research::OptionalDouble* relative_mip_gap )
    // {
    //     ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
    //     if ( message_arena == nullptr )
    //     {
    //         delete _impl_.relative_mip_gap_;
    //     }
    //     if ( relative_mip_gap )
    //     {
    //         ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
    //             ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena( relative_mip_gap );
    //         if ( message_arena != submessage_arena )
    //         {
    //             relative_mip_gap = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
    //                 message_arena, relative_mip_gap, submessage_arena );
    //         }
    //         _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    //     }
    //     _impl_.relative_mip_gap_ = relative_mip_gap;
    //     // @@protoc_insertion_point(field_set_allocated:operations_research.MPSolverCommonParameters.relative_mip_gap)
    // }

    // // optional .operations_research.OptionalDouble primal_tolerance = 2;
    // inline bool MPSolverCommonParameters::_internal_has_primal_tolerance() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000002u ) != 0;
    //     PROTOBUF_ASSUME( !value || _impl_.primal_tolerance_ != nullptr );
    //     return value;
    // }
    // inline bool MPSolverCommonParameters::has_primal_tolerance() const
    // {
    //     return _internal_has_primal_tolerance();
    // }
    // inline void MPSolverCommonParameters::clear_primal_tolerance()
    // {
    //     if ( _impl_.primal_tolerance_ != nullptr ) _impl_.primal_tolerance_->Clear();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    // }
    // inline const ::operations_research::OptionalDouble& MPSolverCommonParameters::_internal_primal_tolerance() const
    // {
    //     const ::operations_research::OptionalDouble* p = _impl_.primal_tolerance_;
    //     return p != nullptr ? *p : reinterpret_cast< const ::operations_research::OptionalDouble& >( ::operations_research::_OptionalDouble_default_instance_ );
    // }
    // inline const ::operations_research::OptionalDouble& MPSolverCommonParameters::primal_tolerance() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPSolverCommonParameters.primal_tolerance)
    //     return _internal_primal_tolerance();
    // }
    // inline void MPSolverCommonParameters::unsafe_arena_set_allocated_primal_tolerance(
    //     ::operations_research::OptionalDouble* primal_tolerance )
    // {
    //     if ( GetArenaForAllocation() == nullptr )
    //     {
    //         delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite* >( _impl_.primal_tolerance_ );
    //     }
    //     _impl_.primal_tolerance_ = primal_tolerance;
    //     if ( primal_tolerance )
    //     {
    //         _impl_._has_bits_[ 0 ] |= 0x00000002u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    //     }
    //     // @@protoc_insertion_point(field_unsafe_arena_set_allocated:operations_research.MPSolverCommonParameters.primal_tolerance)
    // }
    // inline ::operations_research::OptionalDouble* MPSolverCommonParameters::release_primal_tolerance()
    // {
    //     _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    //     ::operations_research::OptionalDouble* temp = _impl_.primal_tolerance_;
    //     _impl_.primal_tolerance_                    = nullptr;
    // #ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
    //     auto* old = reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite* >( temp );
    //     temp      = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //     if ( GetArenaForAllocation() == nullptr )
    //     {
    //         delete old;
    //     }
    // #else   // PROTOBUF_FORCE_COPY_IN_RELEASE
    //     if ( GetArenaForAllocation() != nullptr )
    //     {
    //         temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //     }
    // #endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
    //     return temp;
    // }
    // inline ::operations_research::OptionalDouble* MPSolverCommonParameters::unsafe_arena_release_primal_tolerance()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPSolverCommonParameters.primal_tolerance)
    //     _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    //     ::operations_research::OptionalDouble* temp = _impl_.primal_tolerance_;
    //     _impl_.primal_tolerance_                    = nullptr;
    //     return temp;
    // }
    // inline ::operations_research::OptionalDouble* MPSolverCommonParameters::_internal_mutable_primal_tolerance()
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000002u;
    //     if ( _impl_.primal_tolerance_ == nullptr )
    //     {
    //         auto* p                  = CreateMaybeMessage< ::operations_research::OptionalDouble >( GetArenaForAllocation() );
    //         _impl_.primal_tolerance_ = p;
    //     }
    //     return _impl_.primal_tolerance_;
    // }
    // inline ::operations_research::OptionalDouble* MPSolverCommonParameters::mutable_primal_tolerance()
    // {
    //     ::operations_research::OptionalDouble* _msg = _internal_mutable_primal_tolerance();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPSolverCommonParameters.primal_tolerance)
    //     return _msg;
    // }
    // inline void MPSolverCommonParameters::set_allocated_primal_tolerance( ::operations_research::OptionalDouble* primal_tolerance )
    // {
    //     ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
    //     if ( message_arena == nullptr )
    //     {
    //         delete _impl_.primal_tolerance_;
    //     }
    //     if ( primal_tolerance )
    //     {
    //         ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
    //             ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena( primal_tolerance );
    //         if ( message_arena != submessage_arena )
    //         {
    //             primal_tolerance = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
    //                 message_arena, primal_tolerance, submessage_arena );
    //         }
    //         _impl_._has_bits_[ 0 ] |= 0x00000002u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    //     }
    //     _impl_.primal_tolerance_ = primal_tolerance;
    //     // @@protoc_insertion_point(field_set_allocated:operations_research.MPSolverCommonParameters.primal_tolerance)
    // }

    // // optional .operations_research.OptionalDouble dual_tolerance = 3;
    // inline bool MPSolverCommonParameters::_internal_has_dual_tolerance() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000004u ) != 0;
    //     PROTOBUF_ASSUME( !value || _impl_.dual_tolerance_ != nullptr );
    //     return value;
    // }
    // inline bool MPSolverCommonParameters::has_dual_tolerance() const
    // {
    //     return _internal_has_dual_tolerance();
    // }
    // inline void MPSolverCommonParameters::clear_dual_tolerance()
    // {
    //     if ( _impl_.dual_tolerance_ != nullptr ) _impl_.dual_tolerance_->Clear();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    // }
    // inline const ::operations_research::OptionalDouble& MPSolverCommonParameters::_internal_dual_tolerance() const
    // {
    //     const ::operations_research::OptionalDouble* p = _impl_.dual_tolerance_;
    //     return p != nullptr ? *p : reinterpret_cast< const ::operations_research::OptionalDouble& >( ::operations_research::_OptionalDouble_default_instance_ );
    // }
    // inline const ::operations_research::OptionalDouble& MPSolverCommonParameters::dual_tolerance() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPSolverCommonParameters.dual_tolerance)
    //     return _internal_dual_tolerance();
    // }
    // inline void MPSolverCommonParameters::unsafe_arena_set_allocated_dual_tolerance(
    //     ::operations_research::OptionalDouble* dual_tolerance )
    // {
    //     if ( GetArenaForAllocation() == nullptr )
    //     {
    //         delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite* >( _impl_.dual_tolerance_ );
    //     }
    //     _impl_.dual_tolerance_ = dual_tolerance;
    //     if ( dual_tolerance )
    //     {
    //         _impl_._has_bits_[ 0 ] |= 0x00000004u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    //     }
    //     // @@protoc_insertion_point(field_unsafe_arena_set_allocated:operations_research.MPSolverCommonParameters.dual_tolerance)
    // }
    // inline ::operations_research::OptionalDouble* MPSolverCommonParameters::release_dual_tolerance()
    // {
    //     _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    //     ::operations_research::OptionalDouble* temp = _impl_.dual_tolerance_;
    //     _impl_.dual_tolerance_                      = nullptr;
    // #ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
    //     auto* old = reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite* >( temp );
    //     temp      = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //     if ( GetArenaForAllocation() == nullptr )
    //     {
    //         delete old;
    //     }
    // #else   // PROTOBUF_FORCE_COPY_IN_RELEASE
    //     if ( GetArenaForAllocation() != nullptr )
    //     {
    //         temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //     }
    // #endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
    //     return temp;
    // }
    // inline ::operations_research::OptionalDouble* MPSolverCommonParameters::unsafe_arena_release_dual_tolerance()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPSolverCommonParameters.dual_tolerance)
    //     _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    //     ::operations_research::OptionalDouble* temp = _impl_.dual_tolerance_;
    //     _impl_.dual_tolerance_                      = nullptr;
    //     return temp;
    // }
    // inline ::operations_research::OptionalDouble* MPSolverCommonParameters::_internal_mutable_dual_tolerance()
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000004u;
    //     if ( _impl_.dual_tolerance_ == nullptr )
    //     {
    //         auto* p                = CreateMaybeMessage< ::operations_research::OptionalDouble >( GetArenaForAllocation() );
    //         _impl_.dual_tolerance_ = p;
    //     }
    //     return _impl_.dual_tolerance_;
    // }
    // inline ::operations_research::OptionalDouble* MPSolverCommonParameters::mutable_dual_tolerance()
    // {
    //     ::operations_research::OptionalDouble* _msg = _internal_mutable_dual_tolerance();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPSolverCommonParameters.dual_tolerance)
    //     return _msg;
    // }
    // inline void MPSolverCommonParameters::set_allocated_dual_tolerance( ::operations_research::OptionalDouble* dual_tolerance )
    // {
    //     ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
    //     if ( message_arena == nullptr )
    //     {
    //         delete _impl_.dual_tolerance_;
    //     }
    //     if ( dual_tolerance )
    //     {
    //         ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
    //             ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena( dual_tolerance );
    //         if ( message_arena != submessage_arena )
    //         {
    //             dual_tolerance = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
    //                 message_arena, dual_tolerance, submessage_arena );
    //         }
    //         _impl_._has_bits_[ 0 ] |= 0x00000004u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    //     }
    //     _impl_.dual_tolerance_ = dual_tolerance;
    //     // @@protoc_insertion_point(field_set_allocated:operations_research.MPSolverCommonParameters.dual_tolerance)
    // }

    // // optional .operations_research.MPSolverCommonParameters.LPAlgorithmValues lp_algorithm = 4 [default = LP_ALGO_UNSPECIFIED];
    // inline bool MPSolverCommonParameters::_internal_has_lp_algorithm() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000008u ) != 0;
    //     return value;
    // }
    // inline bool MPSolverCommonParameters::has_lp_algorithm() const
    // {
    //     return _internal_has_lp_algorithm();
    // }
    // inline void MPSolverCommonParameters::clear_lp_algorithm()
    // {
    //     _impl_.lp_algorithm_ = 0;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000008u;
    // }
    // inline ::operations_research::MPSolverCommonParameters_LPAlgorithmValues MPSolverCommonParameters::_internal_lp_algorithm() const
    // {
    //     return static_cast< ::operations_research::MPSolverCommonParameters_LPAlgorithmValues >( _impl_.lp_algorithm_ );
    // }
    // inline ::operations_research::MPSolverCommonParameters_LPAlgorithmValues MPSolverCommonParameters::lp_algorithm() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPSolverCommonParameters.lp_algorithm)
    //     return _internal_lp_algorithm();
    // }
    // inline void MPSolverCommonParameters::_internal_set_lp_algorithm( ::operations_research::MPSolverCommonParameters_LPAlgorithmValues value )
    // {
    //     assert( ::operations_research::MPSolverCommonParameters_LPAlgorithmValues_IsValid( value ) );
    //     _impl_._has_bits_[ 0 ] |= 0x00000008u;
    //     _impl_.lp_algorithm_ = value;
    // }
    // inline void MPSolverCommonParameters::set_lp_algorithm( ::operations_research::MPSolverCommonParameters_LPAlgorithmValues value )
    // {
    //     _internal_set_lp_algorithm( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPSolverCommonParameters.lp_algorithm)
    // }

    // // optional .operations_research.OptionalBoolean presolve = 5 [default = BOOL_UNSPECIFIED];
    // inline bool MPSolverCommonParameters::_internal_has_presolve() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000010u ) != 0;
    //     return value;
    // }
    // inline bool MPSolverCommonParameters::has_presolve() const
    // {
    //     return _internal_has_presolve();
    // }
    // inline void MPSolverCommonParameters::clear_presolve()
    // {
    //     _impl_.presolve_ = 0;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000010u;
    // }
    // inline ::operations_research::OptionalBoolean MPSolverCommonParameters::_internal_presolve() const
    // {
    //     return static_cast< ::operations_research::OptionalBoolean >( _impl_.presolve_ );
    // }
    // inline ::operations_research::OptionalBoolean MPSolverCommonParameters::presolve() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPSolverCommonParameters.presolve)
    //     return _internal_presolve();
    // }
    // inline void MPSolverCommonParameters::_internal_set_presolve( ::operations_research::OptionalBoolean value )
    // {
    //     assert( ::operations_research::OptionalBoolean_IsValid( value ) );
    //     _impl_._has_bits_[ 0 ] |= 0x00000010u;
    //     _impl_.presolve_ = value;
    // }
    // inline void MPSolverCommonParameters::set_presolve( ::operations_research::OptionalBoolean value )
    // {
    //     _internal_set_presolve( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPSolverCommonParameters.presolve)
    // }

    // // optional .operations_research.OptionalBoolean scaling = 7 [default = BOOL_UNSPECIFIED];
    // inline bool MPSolverCommonParameters::_internal_has_scaling() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000020u ) != 0;
    //     return value;
    // }
    // inline bool MPSolverCommonParameters::has_scaling() const
    // {
    //     return _internal_has_scaling();
    // }
    // inline void MPSolverCommonParameters::clear_scaling()
    // {
    //     _impl_.scaling_ = 0;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000020u;
    // }
    // inline ::operations_research::OptionalBoolean MPSolverCommonParameters::_internal_scaling() const
    // {
    //     return static_cast< ::operations_research::OptionalBoolean >( _impl_.scaling_ );
    // }
    // inline ::operations_research::OptionalBoolean MPSolverCommonParameters::scaling() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPSolverCommonParameters.scaling)
    //     return _internal_scaling();
    // }
    // inline void MPSolverCommonParameters::_internal_set_scaling( ::operations_research::OptionalBoolean value )
    // {
    //     assert( ::operations_research::OptionalBoolean_IsValid( value ) );
    //     _impl_._has_bits_[ 0 ] |= 0x00000020u;
    //     _impl_.scaling_ = value;
    // }
    // inline void MPSolverCommonParameters::set_scaling( ::operations_research::OptionalBoolean value )
    // {
    //     _internal_set_scaling( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPSolverCommonParameters.scaling)
    // }

    // // -------------------------------------------------------------------

    // // -------------------------------------------------------------------

    // // -------------------------------------------------------------------

    // // MPModelDeltaProto

    // // optional string baseline_model_file_path = 1;
    // inline bool MPModelDeltaProto::_internal_has_baseline_model_file_path() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000001u ) != 0;
    //     return value;
    // }
    // inline bool MPModelDeltaProto::has_baseline_model_file_path() const
    // {
    //     return _internal_has_baseline_model_file_path();
    // }
    // inline void MPModelDeltaProto::clear_baseline_model_file_path()
    // {
    //     _impl_.baseline_model_file_path_.ClearToEmpty();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    // }
    // inline const std::string& MPModelDeltaProto::baseline_model_file_path() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPModelDeltaProto.baseline_model_file_path)
    //     return _internal_baseline_model_file_path();
    // }
    // template < typename ArgT0, typename... ArgT >
    // inline PROTOBUF_ALWAYS_INLINE void MPModelDeltaProto::set_baseline_model_file_path( ArgT0&& arg0, ArgT... args )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     _impl_.baseline_model_file_path_.Set( static_cast< ArgT0&& >( arg0 ), args..., GetArenaForAllocation() );
    //     // @@protoc_insertion_point(field_set:operations_research.MPModelDeltaProto.baseline_model_file_path)
    // }
    // inline std::string* MPModelDeltaProto::mutable_baseline_model_file_path()
    // {
    //     std::string* _s = _internal_mutable_baseline_model_file_path();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPModelDeltaProto.baseline_model_file_path)
    //     return _s;
    // }
    // inline const std::string& MPModelDeltaProto::_internal_baseline_model_file_path() const
    // {
    //     return _impl_.baseline_model_file_path_.Get();
    // }
    // inline void MPModelDeltaProto::_internal_set_baseline_model_file_path( const std::string& value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     _impl_.baseline_model_file_path_.Set( value, GetArenaForAllocation() );
    // }
    // inline std::string* MPModelDeltaProto::_internal_mutable_baseline_model_file_path()
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     return _impl_.baseline_model_file_path_.Mutable( GetArenaForAllocation() );
    // }
    // inline std::string* MPModelDeltaProto::release_baseline_model_file_path()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPModelDeltaProto.baseline_model_file_path)
    //     if ( !_internal_has_baseline_model_file_path() )
    //     {
    //         return nullptr;
    //     }
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    //     auto* p = _impl_.baseline_model_file_path_.Release();
    // #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     if ( _impl_.baseline_model_file_path_.IsDefault() )
    //     {
    //         _impl_.baseline_model_file_path_.Set( "", GetArenaForAllocation() );
    //     }
    // #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     return p;
    // }
    // inline void MPModelDeltaProto::set_allocated_baseline_model_file_path( std::string* baseline_model_file_path )
    // {
    //     if ( baseline_model_file_path != nullptr )
    //     {
    //         _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    //     }
    //     _impl_.baseline_model_file_path_.SetAllocated( baseline_model_file_path, GetArenaForAllocation() );
    // #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     if ( _impl_.baseline_model_file_path_.IsDefault() )
    //     {
    //         _impl_.baseline_model_file_path_.Set( "", GetArenaForAllocation() );
    //     }
    // #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //         // @@protoc_insertion_point(field_set_allocated:operations_research.MPModelDeltaProto.baseline_model_file_path)
    // }

    // // map<int32, .operations_research.MPVariableProto> variable_overrides = 2;
    // inline int MPModelDeltaProto::_internal_variable_overrides_size() const
    // {
    //     return _impl_.variable_overrides_.size();
    // }
    // inline int MPModelDeltaProto::variable_overrides_size() const
    // {
    //     return _internal_variable_overrides_size();
    // }
    // inline void MPModelDeltaProto::clear_variable_overrides()
    // {
    //     _impl_.variable_overrides_.Clear();
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::Map< int32_t, ::operations_research::MPVariableProto >&
    // MPModelDeltaProto::_internal_variable_overrides() const
    // {
    //     return _impl_.variable_overrides_.GetMap();
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::Map< int32_t, ::operations_research::MPVariableProto >&
    // MPModelDeltaProto::variable_overrides() const
    // {
    //     // @@protoc_insertion_point(field_map:operations_research.MPModelDeltaProto.variable_overrides)
    //     return _internal_variable_overrides();
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::Map< int32_t, ::operations_research::MPVariableProto >*
    // MPModelDeltaProto::_internal_mutable_variable_overrides()
    // {
    //     return _impl_.variable_overrides_.MutableMap();
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::Map< int32_t, ::operations_research::MPVariableProto >*
    // MPModelDeltaProto::mutable_variable_overrides()
    // {
    //     // @@protoc_insertion_point(field_mutable_map:operations_research.MPModelDeltaProto.variable_overrides)
    //     return _internal_mutable_variable_overrides();
    // }

    // // map<int32, .operations_research.MPConstraintProto> constraint_overrides = 3;
    // inline int MPModelDeltaProto::_internal_constraint_overrides_size() const
    // {
    //     return _impl_.constraint_overrides_.size();
    // }
    // inline int MPModelDeltaProto::constraint_overrides_size() const
    // {
    //     return _internal_constraint_overrides_size();
    // }
    // inline void MPModelDeltaProto::clear_constraint_overrides()
    // {
    //     _impl_.constraint_overrides_.Clear();
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::Map< int32_t, ::operations_research::MPConstraintProto >&
    // MPModelDeltaProto::_internal_constraint_overrides() const
    // {
    //     return _impl_.constraint_overrides_.GetMap();
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::Map< int32_t, ::operations_research::MPConstraintProto >&
    // MPModelDeltaProto::constraint_overrides() const
    // {
    //     // @@protoc_insertion_point(field_map:operations_research.MPModelDeltaProto.constraint_overrides)
    //     return _internal_constraint_overrides();
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::Map< int32_t, ::operations_research::MPConstraintProto >*
    // MPModelDeltaProto::_internal_mutable_constraint_overrides()
    // {
    //     return _impl_.constraint_overrides_.MutableMap();
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::Map< int32_t, ::operations_research::MPConstraintProto >*
    // MPModelDeltaProto::mutable_constraint_overrides()
    // {
    //     // @@protoc_insertion_point(field_mutable_map:operations_research.MPModelDeltaProto.constraint_overrides)
    //     return _internal_mutable_constraint_overrides();
    // }

    // // -------------------------------------------------------------------

    // // MPModelRequest

    // // optional .operations_research.MPModelProto model = 1;
    // inline bool MPModelRequest::_internal_has_model() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000002u ) != 0;
    //     PROTOBUF_ASSUME( !value || _impl_.model_ != nullptr );
    //     return value;
    // }
    // inline bool MPModelRequest::has_model() const
    // {
    //     return _internal_has_model();
    // }
    // inline void MPModelRequest::clear_model()
    // {
    //     if ( _impl_.model_ != nullptr ) _impl_.model_->Clear();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    // }
    // inline const ::operations_research::MPModelProto& MPModelRequest::_internal_model() const
    // {
    //     const ::operations_research::MPModelProto* p = _impl_.model_;
    //     return p != nullptr ? *p : reinterpret_cast< const ::operations_research::MPModelProto& >( ::operations_research::_MPModelProto_default_instance_ );
    // }
    // inline const ::operations_research::MPModelProto& MPModelRequest::model() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPModelRequest.model)
    //     return _internal_model();
    // }
    // inline void MPModelRequest::unsafe_arena_set_allocated_model(
    //     ::operations_research::MPModelProto* model )
    // {
    //     if ( GetArenaForAllocation() == nullptr )
    //     {
    //         delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite* >( _impl_.model_ );
    //     }
    //     _impl_.model_ = model;
    //     if ( model )
    //     {
    //         _impl_._has_bits_[ 0 ] |= 0x00000002u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    //     }
    //     // @@protoc_insertion_point(field_unsafe_arena_set_allocated:operations_research.MPModelRequest.model)
    // }
    // inline ::operations_research::MPModelProto* MPModelRequest::release_model()
    // {
    //     _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    //     ::operations_research::MPModelProto* temp = _impl_.model_;
    //     _impl_.model_                             = nullptr;
    // #ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
    //     auto* old = reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite* >( temp );
    //     temp      = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //     if ( GetArenaForAllocation() == nullptr )
    //     {
    //         delete old;
    //     }
    // #else   // PROTOBUF_FORCE_COPY_IN_RELEASE
    //     if ( GetArenaForAllocation() != nullptr )
    //     {
    //         temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //     }
    // #endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
    //     return temp;
    // }
    // inline ::operations_research::MPModelProto* MPModelRequest::unsafe_arena_release_model()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPModelRequest.model)
    //     _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    //     ::operations_research::MPModelProto* temp = _impl_.model_;
    //     _impl_.model_                             = nullptr;
    //     return temp;
    // }
    // inline ::operations_research::MPModelProto* MPModelRequest::_internal_mutable_model()
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000002u;
    //     if ( _impl_.model_ == nullptr )
    //     {
    //         auto* p       = CreateMaybeMessage< ::operations_research::MPModelProto >( GetArenaForAllocation() );
    //         _impl_.model_ = p;
    //     }
    //     return _impl_.model_;
    // }
    // inline ::operations_research::MPModelProto* MPModelRequest::mutable_model()
    // {
    //     ::operations_research::MPModelProto* _msg = _internal_mutable_model();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPModelRequest.model)
    //     return _msg;
    // }
    // inline void MPModelRequest::set_allocated_model( ::operations_research::MPModelProto* model )
    // {
    //     ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
    //     if ( message_arena == nullptr )
    //     {
    //         delete _impl_.model_;
    //     }
    //     if ( model )
    //     {
    //         ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
    //             ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena( model );
    //         if ( message_arena != submessage_arena )
    //         {
    //             model = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
    //                 message_arena, model, submessage_arena );
    //         }
    //         _impl_._has_bits_[ 0 ] |= 0x00000002u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    //     }
    //     _impl_.model_ = model;
    //     // @@protoc_insertion_point(field_set_allocated:operations_research.MPModelRequest.model)
    // }

    // // optional .operations_research.MPModelRequest.SolverType solver_type = 2 [default = GLOP_LINEAR_PROGRAMMING];
    // inline bool MPModelRequest::_internal_has_solver_type() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000080u ) != 0;
    //     return value;
    // }
    // inline bool MPModelRequest::has_solver_type() const
    // {
    //     return _internal_has_solver_type();
    // }
    // inline void MPModelRequest::clear_solver_type()
    // {
    //     _impl_.solver_type_ = 2;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000080u;
    // }
    // inline ::operations_research::MPModelRequest_SolverType MPModelRequest::_internal_solver_type() const
    // {
    //     return static_cast< ::operations_research::MPModelRequest_SolverType >( _impl_.solver_type_ );
    // }
    // inline ::operations_research::MPModelRequest_SolverType MPModelRequest::solver_type() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPModelRequest.solver_type)
    //     return _internal_solver_type();
    // }
    // inline void MPModelRequest::_internal_set_solver_type( ::operations_research::MPModelRequest_SolverType value )
    // {
    //     assert( ::operations_research::MPModelRequest_SolverType_IsValid( value ) );
    //     _impl_._has_bits_[ 0 ] |= 0x00000080u;
    //     _impl_.solver_type_ = value;
    // }
    // inline void MPModelRequest::set_solver_type( ::operations_research::MPModelRequest_SolverType value )
    // {
    //     _internal_set_solver_type( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPModelRequest.solver_type)
    // }

    // // optional double solver_time_limit_seconds = 3;
    // inline bool MPModelRequest::_internal_has_solver_time_limit_seconds() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000008u ) != 0;
    //     return value;
    // }
    // inline bool MPModelRequest::has_solver_time_limit_seconds() const
    // {
    //     return _internal_has_solver_time_limit_seconds();
    // }
    // inline void MPModelRequest::clear_solver_time_limit_seconds()
    // {
    //     _impl_.solver_time_limit_seconds_ = 0;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000008u;
    // }
    // inline double MPModelRequest::_internal_solver_time_limit_seconds() const
    // {
    //     return _impl_.solver_time_limit_seconds_;
    // }
    // inline double MPModelRequest::solver_time_limit_seconds() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPModelRequest.solver_time_limit_seconds)
    //     return _internal_solver_time_limit_seconds();
    // }
    // inline void MPModelRequest::_internal_set_solver_time_limit_seconds( double value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000008u;
    //     _impl_.solver_time_limit_seconds_ = value;
    // }
    // inline void MPModelRequest::set_solver_time_limit_seconds( double value )
    // {
    //     _internal_set_solver_time_limit_seconds( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPModelRequest.solver_time_limit_seconds)
    // }

    // // optional bool enable_internal_solver_output = 4 [default = false];
    // inline bool MPModelRequest::_internal_has_enable_internal_solver_output() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000010u ) != 0;
    //     return value;
    // }
    // inline bool MPModelRequest::has_enable_internal_solver_output() const
    // {
    //     return _internal_has_enable_internal_solver_output();
    // }
    // inline void MPModelRequest::clear_enable_internal_solver_output()
    // {
    //     _impl_.enable_internal_solver_output_ = false;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000010u;
    // }
    // inline bool MPModelRequest::_internal_enable_internal_solver_output() const
    // {
    //     return _impl_.enable_internal_solver_output_;
    // }
    // inline bool MPModelRequest::enable_internal_solver_output() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPModelRequest.enable_internal_solver_output)
    //     return _internal_enable_internal_solver_output();
    // }
    // inline void MPModelRequest::_internal_set_enable_internal_solver_output( bool value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000010u;
    //     _impl_.enable_internal_solver_output_ = value;
    // }
    // inline void MPModelRequest::set_enable_internal_solver_output( bool value )
    // {
    //     _internal_set_enable_internal_solver_output( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPModelRequest.enable_internal_solver_output)
    // }

    // // optional string solver_specific_parameters = 5;
    // inline bool MPModelRequest::_internal_has_solver_specific_parameters() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000001u ) != 0;
    //     return value;
    // }
    // inline bool MPModelRequest::has_solver_specific_parameters() const
    // {
    //     return _internal_has_solver_specific_parameters();
    // }
    // inline void MPModelRequest::clear_solver_specific_parameters()
    // {
    //     _impl_.solver_specific_parameters_.ClearToEmpty();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    // }
    // inline const std::string& MPModelRequest::solver_specific_parameters() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPModelRequest.solver_specific_parameters)
    //     return _internal_solver_specific_parameters();
    // }
    // template < typename ArgT0, typename... ArgT >
    // inline PROTOBUF_ALWAYS_INLINE void MPModelRequest::set_solver_specific_parameters( ArgT0&& arg0, ArgT... args )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     _impl_.solver_specific_parameters_.Set( static_cast< ArgT0&& >( arg0 ), args..., GetArenaForAllocation() );
    //     // @@protoc_insertion_point(field_set:operations_research.MPModelRequest.solver_specific_parameters)
    // }
    // inline std::string* MPModelRequest::mutable_solver_specific_parameters()
    // {
    //     std::string* _s = _internal_mutable_solver_specific_parameters();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPModelRequest.solver_specific_parameters)
    //     return _s;
    // }
    // inline const std::string& MPModelRequest::_internal_solver_specific_parameters() const
    // {
    //     return _impl_.solver_specific_parameters_.Get();
    // }
    // inline void MPModelRequest::_internal_set_solver_specific_parameters( const std::string& value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     _impl_.solver_specific_parameters_.Set( value, GetArenaForAllocation() );
    // }
    // inline std::string* MPModelRequest::_internal_mutable_solver_specific_parameters()
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     return _impl_.solver_specific_parameters_.Mutable( GetArenaForAllocation() );
    // }
    // inline std::string* MPModelRequest::release_solver_specific_parameters()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPModelRequest.solver_specific_parameters)
    //     if ( !_internal_has_solver_specific_parameters() )
    //     {
    //         return nullptr;
    //     }
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    //     auto* p = _impl_.solver_specific_parameters_.Release();
    // #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     if ( _impl_.solver_specific_parameters_.IsDefault() )
    //     {
    //         _impl_.solver_specific_parameters_.Set( "", GetArenaForAllocation() );
    //     }
    // #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     return p;
    // }
    // inline void MPModelRequest::set_allocated_solver_specific_parameters( std::string* solver_specific_parameters )
    // {
    //     if ( solver_specific_parameters != nullptr )
    //     {
    //         _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    //     }
    //     _impl_.solver_specific_parameters_.SetAllocated( solver_specific_parameters, GetArenaForAllocation() );
    // #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     if ( _impl_.solver_specific_parameters_.IsDefault() )
    //     {
    //         _impl_.solver_specific_parameters_.Set( "", GetArenaForAllocation() );
    //     }
    // #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //         // @@protoc_insertion_point(field_set_allocated:operations_research.MPModelRequest.solver_specific_parameters)
    // }

    // // optional bool ignore_solver_specific_parameters_failure = 9 [default = false];
    // inline bool MPModelRequest::_internal_has_ignore_solver_specific_parameters_failure() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000020u ) != 0;
    //     return value;
    // }
    // inline bool MPModelRequest::has_ignore_solver_specific_parameters_failure() const
    // {
    //     return _internal_has_ignore_solver_specific_parameters_failure();
    // }
    // inline void MPModelRequest::clear_ignore_solver_specific_parameters_failure()
    // {
    //     _impl_.ignore_solver_specific_parameters_failure_ = false;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000020u;
    // }
    // inline bool MPModelRequest::_internal_ignore_solver_specific_parameters_failure() const
    // {
    //     return _impl_.ignore_solver_specific_parameters_failure_;
    // }
    // inline bool MPModelRequest::ignore_solver_specific_parameters_failure() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPModelRequest.ignore_solver_specific_parameters_failure)
    //     return _internal_ignore_solver_specific_parameters_failure();
    // }
    // inline void MPModelRequest::_internal_set_ignore_solver_specific_parameters_failure( bool value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000020u;
    //     _impl_.ignore_solver_specific_parameters_failure_ = value;
    // }
    // inline void MPModelRequest::set_ignore_solver_specific_parameters_failure( bool value )
    // {
    //     _internal_set_ignore_solver_specific_parameters_failure( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPModelRequest.ignore_solver_specific_parameters_failure)
    // }

    // // optional .operations_research.MPModelDeltaProto model_delta = 8;
    // inline bool MPModelRequest::_internal_has_model_delta() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000004u ) != 0;
    //     PROTOBUF_ASSUME( !value || _impl_.model_delta_ != nullptr );
    //     return value;
    // }
    // inline bool MPModelRequest::has_model_delta() const
    // {
    //     return _internal_has_model_delta();
    // }
    // inline void MPModelRequest::clear_model_delta()
    // {
    //     if ( _impl_.model_delta_ != nullptr ) _impl_.model_delta_->Clear();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    // }
    // inline const ::operations_research::MPModelDeltaProto& MPModelRequest::_internal_model_delta() const
    // {
    //     const ::operations_research::MPModelDeltaProto* p = _impl_.model_delta_;
    //     return p != nullptr ? *p : reinterpret_cast< const ::operations_research::MPModelDeltaProto& >( ::operations_research::_MPModelDeltaProto_default_instance_ );
    // }
    // inline const ::operations_research::MPModelDeltaProto& MPModelRequest::model_delta() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPModelRequest.model_delta)
    //     return _internal_model_delta();
    // }
    // inline void MPModelRequest::unsafe_arena_set_allocated_model_delta(
    //     ::operations_research::MPModelDeltaProto* model_delta )
    // {
    //     if ( GetArenaForAllocation() == nullptr )
    //     {
    //         delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite* >( _impl_.model_delta_ );
    //     }
    //     _impl_.model_delta_ = model_delta;
    //     if ( model_delta )
    //     {
    //         _impl_._has_bits_[ 0 ] |= 0x00000004u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    //     }
    //     // @@protoc_insertion_point(field_unsafe_arena_set_allocated:operations_research.MPModelRequest.model_delta)
    // }
    // inline ::operations_research::MPModelDeltaProto* MPModelRequest::release_model_delta()
    // {
    //     _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    //     ::operations_research::MPModelDeltaProto* temp = _impl_.model_delta_;
    //     _impl_.model_delta_                            = nullptr;
    // #ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
    //     auto* old = reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite* >( temp );
    //     temp      = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //     if ( GetArenaForAllocation() == nullptr )
    //     {
    //         delete old;
    //     }
    // #else   // PROTOBUF_FORCE_COPY_IN_RELEASE
    //     if ( GetArenaForAllocation() != nullptr )
    //     {
    //         temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //     }
    // #endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
    //     return temp;
    // }
    // inline ::operations_research::MPModelDeltaProto* MPModelRequest::unsafe_arena_release_model_delta()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPModelRequest.model_delta)
    //     _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    //     ::operations_research::MPModelDeltaProto* temp = _impl_.model_delta_;
    //     _impl_.model_delta_                            = nullptr;
    //     return temp;
    // }
    // inline ::operations_research::MPModelDeltaProto* MPModelRequest::_internal_mutable_model_delta()
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000004u;
    //     if ( _impl_.model_delta_ == nullptr )
    //     {
    //         auto* p             = CreateMaybeMessage< ::operations_research::MPModelDeltaProto >( GetArenaForAllocation() );
    //         _impl_.model_delta_ = p;
    //     }
    //     return _impl_.model_delta_;
    // }
    // inline ::operations_research::MPModelDeltaProto* MPModelRequest::mutable_model_delta()
    // {
    //     ::operations_research::MPModelDeltaProto* _msg = _internal_mutable_model_delta();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPModelRequest.model_delta)
    //     return _msg;
    // }
    // inline void MPModelRequest::set_allocated_model_delta( ::operations_research::MPModelDeltaProto* model_delta )
    // {
    //     ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
    //     if ( message_arena == nullptr )
    //     {
    //         delete _impl_.model_delta_;
    //     }
    //     if ( model_delta )
    //     {
    //         ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
    //             ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena( model_delta );
    //         if ( message_arena != submessage_arena )
    //         {
    //             model_delta = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
    //                 message_arena, model_delta, submessage_arena );
    //         }
    //         _impl_._has_bits_[ 0 ] |= 0x00000004u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    //     }
    //     _impl_.model_delta_ = model_delta;
    //     // @@protoc_insertion_point(field_set_allocated:operations_research.MPModelRequest.model_delta)
    // }

    // // optional int32 populate_additional_solutions_up_to = 11 [default = 0];
    // inline bool MPModelRequest::_internal_has_populate_additional_solutions_up_to() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000040u ) != 0;
    //     return value;
    // }
    // inline bool MPModelRequest::has_populate_additional_solutions_up_to() const
    // {
    //     return _internal_has_populate_additional_solutions_up_to();
    // }
    // inline void MPModelRequest::clear_populate_additional_solutions_up_to()
    // {
    //     _impl_.populate_additional_solutions_up_to_ = 0;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000040u;
    // }
    // inline int32_t MPModelRequest::_internal_populate_additional_solutions_up_to() const
    // {
    //     return _impl_.populate_additional_solutions_up_to_;
    // }
    // inline int32_t MPModelRequest::populate_additional_solutions_up_to() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPModelRequest.populate_additional_solutions_up_to)
    //     return _internal_populate_additional_solutions_up_to();
    // }
    // inline void MPModelRequest::_internal_set_populate_additional_solutions_up_to( int32_t value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000040u;
    //     _impl_.populate_additional_solutions_up_to_ = value;
    // }
    // inline void MPModelRequest::set_populate_additional_solutions_up_to( int32_t value )
    // {
    //     _internal_set_populate_additional_solutions_up_to( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPModelRequest.populate_additional_solutions_up_to)
    // }

    // // -------------------------------------------------------------------

    // // MPSolution

    // // optional double objective_value = 1;
    // inline bool MPSolution::_internal_has_objective_value() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000001u ) != 0;
    //     return value;
    // }
    // inline bool MPSolution::has_objective_value() const
    // {
    //     return _internal_has_objective_value();
    // }
    // inline void MPSolution::clear_objective_value()
    // {
    //     _impl_.objective_value_ = 0;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    // }
    // inline double MPSolution::_internal_objective_value() const
    // {
    //     return _impl_.objective_value_;
    // }
    // inline double MPSolution::objective_value() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPSolution.objective_value)
    //     return _internal_objective_value();
    // }
    // inline void MPSolution::_internal_set_objective_value( double value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     _impl_.objective_value_ = value;
    // }
    // inline void MPSolution::set_objective_value( double value )
    // {
    //     _internal_set_objective_value( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPSolution.objective_value)
    // }

    // // repeated double variable_value = 2 [packed = true];
    // inline int MPSolution::_internal_variable_value_size() const
    // {
    //     return _impl_.variable_value_.size();
    // }
    // inline int MPSolution::variable_value_size() const
    // {
    //     return _internal_variable_value_size();
    // }
    // inline void MPSolution::clear_variable_value()
    // {
    //     _impl_.variable_value_.Clear();
    // }
    // inline double MPSolution::_internal_variable_value( int index ) const
    // {
    //     return _impl_.variable_value_.Get( index );
    // }
    // inline double MPSolution::variable_value( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPSolution.variable_value)
    //     return _internal_variable_value( index );
    // }
    // inline void MPSolution::set_variable_value( int index, double value )
    // {
    //     _impl_.variable_value_.Set( index, value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPSolution.variable_value)
    // }
    // inline void MPSolution::_internal_add_variable_value( double value )
    // {
    //     _impl_.variable_value_.Add( value );
    // }
    // inline void MPSolution::add_variable_value( double value )
    // {
    //     _internal_add_variable_value( value );
    //     // @@protoc_insertion_point(field_add:operations_research.MPSolution.variable_value)
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    // MPSolution::_internal_variable_value() const
    // {
    //     return _impl_.variable_value_;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    // MPSolution::variable_value() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.MPSolution.variable_value)
    //     return _internal_variable_value();
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    // MPSolution::_internal_mutable_variable_value()
    // {
    //     return &_impl_.variable_value_;
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    // MPSolution::mutable_variable_value()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.MPSolution.variable_value)
    //     return _internal_mutable_variable_value();
    // }

    // // -------------------------------------------------------------------

    // // MPSolveInfo

    // // optional double solve_wall_time_seconds = 1;
    // inline bool MPSolveInfo::_internal_has_solve_wall_time_seconds() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000001u ) != 0;
    //     return value;
    // }
    // inline bool MPSolveInfo::has_solve_wall_time_seconds() const
    // {
    //     return _internal_has_solve_wall_time_seconds();
    // }
    // inline void MPSolveInfo::clear_solve_wall_time_seconds()
    // {
    //     _impl_.solve_wall_time_seconds_ = 0;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    // }
    // inline double MPSolveInfo::_internal_solve_wall_time_seconds() const
    // {
    //     return _impl_.solve_wall_time_seconds_;
    // }
    // inline double MPSolveInfo::solve_wall_time_seconds() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPSolveInfo.solve_wall_time_seconds)
    //     return _internal_solve_wall_time_seconds();
    // }
    // inline void MPSolveInfo::_internal_set_solve_wall_time_seconds( double value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     _impl_.solve_wall_time_seconds_ = value;
    // }
    // inline void MPSolveInfo::set_solve_wall_time_seconds( double value )
    // {
    //     _internal_set_solve_wall_time_seconds( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPSolveInfo.solve_wall_time_seconds)
    // }

    // // optional double solve_user_time_seconds = 2;
    // inline bool MPSolveInfo::_internal_has_solve_user_time_seconds() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000002u ) != 0;
    //     return value;
    // }
    // inline bool MPSolveInfo::has_solve_user_time_seconds() const
    // {
    //     return _internal_has_solve_user_time_seconds();
    // }
    // inline void MPSolveInfo::clear_solve_user_time_seconds()
    // {
    //     _impl_.solve_user_time_seconds_ = 0;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    // }
    // inline double MPSolveInfo::_internal_solve_user_time_seconds() const
    // {
    //     return _impl_.solve_user_time_seconds_;
    // }
    // inline double MPSolveInfo::solve_user_time_seconds() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPSolveInfo.solve_user_time_seconds)
    //     return _internal_solve_user_time_seconds();
    // }
    // inline void MPSolveInfo::_internal_set_solve_user_time_seconds( double value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000002u;
    //     _impl_.solve_user_time_seconds_ = value;
    // }
    // inline void MPSolveInfo::set_solve_user_time_seconds( double value )
    // {
    //     _internal_set_solve_user_time_seconds( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPSolveInfo.solve_user_time_seconds)
    // }

    // // -------------------------------------------------------------------

    // // MPSolutionResponse

    // // optional .operations_research.MPSolverResponseStatus status = 1 [default = MPSOLVER_UNKNOWN_STATUS];
    // inline bool MPSolutionResponse::_internal_has_status() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000020u ) != 0;
    //     return value;
    // }
    // inline bool MPSolutionResponse::has_status() const
    // {
    //     return _internal_has_status();
    // }
    // inline void MPSolutionResponse::clear_status()
    // {
    //     _impl_.status_ = 99;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000020u;
    // }
    // inline ::operations_research::MPSolverResponseStatus MPSolutionResponse::_internal_status() const
    // {
    //     return static_cast< ::operations_research::MPSolverResponseStatus >( _impl_.status_ );
    // }
    // inline ::operations_research::MPSolverResponseStatus MPSolutionResponse::status() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPSolutionResponse.status)
    //     return _internal_status();
    // }
    // inline void MPSolutionResponse::_internal_set_status( ::operations_research::MPSolverResponseStatus value )
    // {
    //     assert( ::operations_research::MPSolverResponseStatus_IsValid( value ) );
    //     _impl_._has_bits_[ 0 ] |= 0x00000020u;
    //     _impl_.status_ = value;
    // }
    // inline void MPSolutionResponse::set_status( ::operations_research::MPSolverResponseStatus value )
    // {
    //     _internal_set_status( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPSolutionResponse.status)
    // }

    // // optional string status_str = 7;
    // inline bool MPSolutionResponse::_internal_has_status_str() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000001u ) != 0;
    //     return value;
    // }
    // inline bool MPSolutionResponse::has_status_str() const
    // {
    //     return _internal_has_status_str();
    // }
    // inline void MPSolutionResponse::clear_status_str()
    // {
    //     _impl_.status_str_.ClearToEmpty();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    // }
    // inline const std::string& MPSolutionResponse::status_str() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPSolutionResponse.status_str)
    //     return _internal_status_str();
    // }
    // template < typename ArgT0, typename... ArgT >
    // inline PROTOBUF_ALWAYS_INLINE void MPSolutionResponse::set_status_str( ArgT0&& arg0, ArgT... args )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     _impl_.status_str_.Set( static_cast< ArgT0&& >( arg0 ), args..., GetArenaForAllocation() );
    //     // @@protoc_insertion_point(field_set:operations_research.MPSolutionResponse.status_str)
    // }
    // inline std::string* MPSolutionResponse::mutable_status_str()
    // {
    //     std::string* _s = _internal_mutable_status_str();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPSolutionResponse.status_str)
    //     return _s;
    // }
    // inline const std::string& MPSolutionResponse::_internal_status_str() const
    // {
    //     return _impl_.status_str_.Get();
    // }
    // inline void MPSolutionResponse::_internal_set_status_str( const std::string& value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     _impl_.status_str_.Set( value, GetArenaForAllocation() );
    // }
    // inline std::string* MPSolutionResponse::_internal_mutable_status_str()
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     return _impl_.status_str_.Mutable( GetArenaForAllocation() );
    // }
    // inline std::string* MPSolutionResponse::release_status_str()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPSolutionResponse.status_str)
    //     if ( !_internal_has_status_str() )
    //     {
    //         return nullptr;
    //     }
    //     _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    //     auto* p = _impl_.status_str_.Release();
    // #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     if ( _impl_.status_str_.IsDefault() )
    //     {
    //         _impl_.status_str_.Set( "", GetArenaForAllocation() );
    //     }
    // #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     return p;
    // }
    // inline void MPSolutionResponse::set_allocated_status_str( std::string* status_str )
    // {
    //     if ( status_str != nullptr )
    //     {
    //         _impl_._has_bits_[ 0 ] |= 0x00000001u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000001u;
    //     }
    //     _impl_.status_str_.SetAllocated( status_str, GetArenaForAllocation() );
    // #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     if ( _impl_.status_str_.IsDefault() )
    //     {
    //         _impl_.status_str_.Set( "", GetArenaForAllocation() );
    //     }
    // #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //         // @@protoc_insertion_point(field_set_allocated:operations_research.MPSolutionResponse.status_str)
    // }

    // // optional double objective_value = 2;
    // inline bool MPSolutionResponse::_internal_has_objective_value() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000008u ) != 0;
    //     return value;
    // }
    // inline bool MPSolutionResponse::has_objective_value() const
    // {
    //     return _internal_has_objective_value();
    // }
    // inline void MPSolutionResponse::clear_objective_value()
    // {
    //     _impl_.objective_value_ = 0;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000008u;
    // }
    // inline double MPSolutionResponse::_internal_objective_value() const
    // {
    //     return _impl_.objective_value_;
    // }
    // inline double MPSolutionResponse::objective_value() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPSolutionResponse.objective_value)
    //     return _internal_objective_value();
    // }
    // inline void MPSolutionResponse::_internal_set_objective_value( double value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000008u;
    //     _impl_.objective_value_ = value;
    // }
    // inline void MPSolutionResponse::set_objective_value( double value )
    // {
    //     _internal_set_objective_value( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPSolutionResponse.objective_value)
    // }

    // // optional double best_objective_bound = 5;
    // inline bool MPSolutionResponse::_internal_has_best_objective_bound() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000010u ) != 0;
    //     return value;
    // }
    // inline bool MPSolutionResponse::has_best_objective_bound() const
    // {
    //     return _internal_has_best_objective_bound();
    // }
    // inline void MPSolutionResponse::clear_best_objective_bound()
    // {
    //     _impl_.best_objective_bound_ = 0;
    //     _impl_._has_bits_[ 0 ] &= ~0x00000010u;
    // }
    // inline double MPSolutionResponse::_internal_best_objective_bound() const
    // {
    //     return _impl_.best_objective_bound_;
    // }
    // inline double MPSolutionResponse::best_objective_bound() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPSolutionResponse.best_objective_bound)
    //     return _internal_best_objective_bound();
    // }
    // inline void MPSolutionResponse::_internal_set_best_objective_bound( double value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000010u;
    //     _impl_.best_objective_bound_ = value;
    // }
    // inline void MPSolutionResponse::set_best_objective_bound( double value )
    // {
    //     _internal_set_best_objective_bound( value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPSolutionResponse.best_objective_bound)
    // }

    // // repeated double variable_value = 3 [packed = true];
    // inline int MPSolutionResponse::_internal_variable_value_size() const
    // {
    //     return _impl_.variable_value_.size();
    // }
    // inline int MPSolutionResponse::variable_value_size() const
    // {
    //     return _internal_variable_value_size();
    // }
    // inline void MPSolutionResponse::clear_variable_value()
    // {
    //     _impl_.variable_value_.Clear();
    // }
    // inline double MPSolutionResponse::_internal_variable_value( int index ) const
    // {
    //     return _impl_.variable_value_.Get( index );
    // }
    // inline double MPSolutionResponse::variable_value( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPSolutionResponse.variable_value)
    //     return _internal_variable_value( index );
    // }
    // inline void MPSolutionResponse::set_variable_value( int index, double value )
    // {
    //     _impl_.variable_value_.Set( index, value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPSolutionResponse.variable_value)
    // }
    // inline void MPSolutionResponse::_internal_add_variable_value( double value )
    // {
    //     _impl_.variable_value_.Add( value );
    // }
    // inline void MPSolutionResponse::add_variable_value( double value )
    // {
    //     _internal_add_variable_value( value );
    //     // @@protoc_insertion_point(field_add:operations_research.MPSolutionResponse.variable_value)
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    // MPSolutionResponse::_internal_variable_value() const
    // {
    //     return _impl_.variable_value_;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    // MPSolutionResponse::variable_value() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.MPSolutionResponse.variable_value)
    //     return _internal_variable_value();
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    // MPSolutionResponse::_internal_mutable_variable_value()
    // {
    //     return &_impl_.variable_value_;
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    // MPSolutionResponse::mutable_variable_value()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.MPSolutionResponse.variable_value)
    //     return _internal_mutable_variable_value();
    // }

    // // optional .operations_research.MPSolveInfo solve_info = 10;
    // inline bool MPSolutionResponse::_internal_has_solve_info() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000004u ) != 0;
    //     PROTOBUF_ASSUME( !value || _impl_.solve_info_ != nullptr );
    //     return value;
    // }
    // inline bool MPSolutionResponse::has_solve_info() const
    // {
    //     return _internal_has_solve_info();
    // }
    // inline void MPSolutionResponse::clear_solve_info()
    // {
    //     if ( _impl_.solve_info_ != nullptr ) _impl_.solve_info_->Clear();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    // }
    // inline const ::operations_research::MPSolveInfo& MPSolutionResponse::_internal_solve_info() const
    // {
    //     const ::operations_research::MPSolveInfo* p = _impl_.solve_info_;
    //     return p != nullptr ? *p : reinterpret_cast< const ::operations_research::MPSolveInfo& >( ::operations_research::_MPSolveInfo_default_instance_ );
    // }
    // inline const ::operations_research::MPSolveInfo& MPSolutionResponse::solve_info() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPSolutionResponse.solve_info)
    //     return _internal_solve_info();
    // }
    // inline void MPSolutionResponse::unsafe_arena_set_allocated_solve_info(
    //     ::operations_research::MPSolveInfo* solve_info )
    // {
    //     if ( GetArenaForAllocation() == nullptr )
    //     {
    //         delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite* >( _impl_.solve_info_ );
    //     }
    //     _impl_.solve_info_ = solve_info;
    //     if ( solve_info )
    //     {
    //         _impl_._has_bits_[ 0 ] |= 0x00000004u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    //     }
    //     // @@protoc_insertion_point(field_unsafe_arena_set_allocated:operations_research.MPSolutionResponse.solve_info)
    // }
    // inline ::operations_research::MPSolveInfo* MPSolutionResponse::release_solve_info()
    // {
    //     _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    //     ::operations_research::MPSolveInfo* temp = _impl_.solve_info_;
    //     _impl_.solve_info_                       = nullptr;
    // #ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
    //     auto* old = reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite* >( temp );
    //     temp      = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //     if ( GetArenaForAllocation() == nullptr )
    //     {
    //         delete old;
    //     }
    // #else   // PROTOBUF_FORCE_COPY_IN_RELEASE
    //     if ( GetArenaForAllocation() != nullptr )
    //     {
    //         temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull( temp );
    //     }
    // #endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
    //     return temp;
    // }
    // inline ::operations_research::MPSolveInfo* MPSolutionResponse::unsafe_arena_release_solve_info()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPSolutionResponse.solve_info)
    //     _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    //     ::operations_research::MPSolveInfo* temp = _impl_.solve_info_;
    //     _impl_.solve_info_                       = nullptr;
    //     return temp;
    // }
    // inline ::operations_research::MPSolveInfo* MPSolutionResponse::_internal_mutable_solve_info()
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000004u;
    //     if ( _impl_.solve_info_ == nullptr )
    //     {
    //         auto* p            = CreateMaybeMessage< ::operations_research::MPSolveInfo >( GetArenaForAllocation() );
    //         _impl_.solve_info_ = p;
    //     }
    //     return _impl_.solve_info_;
    // }
    // inline ::operations_research::MPSolveInfo* MPSolutionResponse::mutable_solve_info()
    // {
    //     ::operations_research::MPSolveInfo* _msg = _internal_mutable_solve_info();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPSolutionResponse.solve_info)
    //     return _msg;
    // }
    // inline void MPSolutionResponse::set_allocated_solve_info( ::operations_research::MPSolveInfo* solve_info )
    // {
    //     ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
    //     if ( message_arena == nullptr )
    //     {
    //         delete _impl_.solve_info_;
    //     }
    //     if ( solve_info )
    //     {
    //         ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
    //             ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena( solve_info );
    //         if ( message_arena != submessage_arena )
    //         {
    //             solve_info = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
    //                 message_arena, solve_info, submessage_arena );
    //         }
    //         _impl_._has_bits_[ 0 ] |= 0x00000004u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000004u;
    //     }
    //     _impl_.solve_info_ = solve_info;
    //     // @@protoc_insertion_point(field_set_allocated:operations_research.MPSolutionResponse.solve_info)
    // }

    // // optional bytes solver_specific_info = 11;
    // inline bool MPSolutionResponse::_internal_has_solver_specific_info() const
    // {
    //     bool value = ( _impl_._has_bits_[ 0 ] & 0x00000002u ) != 0;
    //     return value;
    // }
    // inline bool MPSolutionResponse::has_solver_specific_info() const
    // {
    //     return _internal_has_solver_specific_info();
    // }
    // inline void MPSolutionResponse::clear_solver_specific_info()
    // {
    //     _impl_.solver_specific_info_.ClearToEmpty();
    //     _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    // }
    // inline const std::string& MPSolutionResponse::solver_specific_info() const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPSolutionResponse.solver_specific_info)
    //     return _internal_solver_specific_info();
    // }
    // template < typename ArgT0, typename... ArgT >
    // inline PROTOBUF_ALWAYS_INLINE void MPSolutionResponse::set_solver_specific_info( ArgT0&& arg0, ArgT... args )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000002u;
    //     _impl_.solver_specific_info_.SetBytes( static_cast< ArgT0&& >( arg0 ), args..., GetArenaForAllocation() );
    //     // @@protoc_insertion_point(field_set:operations_research.MPSolutionResponse.solver_specific_info)
    // }
    // inline std::string* MPSolutionResponse::mutable_solver_specific_info()
    // {
    //     std::string* _s = _internal_mutable_solver_specific_info();
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPSolutionResponse.solver_specific_info)
    //     return _s;
    // }
    // inline const std::string& MPSolutionResponse::_internal_solver_specific_info() const
    // {
    //     return _impl_.solver_specific_info_.Get();
    // }
    // inline void MPSolutionResponse::_internal_set_solver_specific_info( const std::string& value )
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000002u;
    //     _impl_.solver_specific_info_.Set( value, GetArenaForAllocation() );
    // }
    // inline std::string* MPSolutionResponse::_internal_mutable_solver_specific_info()
    // {
    //     _impl_._has_bits_[ 0 ] |= 0x00000002u;
    //     return _impl_.solver_specific_info_.Mutable( GetArenaForAllocation() );
    // }
    // inline std::string* MPSolutionResponse::release_solver_specific_info()
    // {
    //     // @@protoc_insertion_point(field_release:operations_research.MPSolutionResponse.solver_specific_info)
    //     if ( !_internal_has_solver_specific_info() )
    //     {
    //         return nullptr;
    //     }
    //     _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    //     auto* p = _impl_.solver_specific_info_.Release();
    // #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     if ( _impl_.solver_specific_info_.IsDefault() )
    //     {
    //         _impl_.solver_specific_info_.Set( "", GetArenaForAllocation() );
    //     }
    // #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     return p;
    // }
    // inline void MPSolutionResponse::set_allocated_solver_specific_info( std::string* solver_specific_info )
    // {
    //     if ( solver_specific_info != nullptr )
    //     {
    //         _impl_._has_bits_[ 0 ] |= 0x00000002u;
    //     }
    //     else
    //     {
    //         _impl_._has_bits_[ 0 ] &= ~0x00000002u;
    //     }
    //     _impl_.solver_specific_info_.SetAllocated( solver_specific_info, GetArenaForAllocation() );
    // #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //     if ( _impl_.solver_specific_info_.IsDefault() )
    //     {
    //         _impl_.solver_specific_info_.Set( "", GetArenaForAllocation() );
    //     }
    // #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    //         // @@protoc_insertion_point(field_set_allocated:operations_research.MPSolutionResponse.solver_specific_info)
    // }

    // // repeated double dual_value = 4 [packed = true];
    // inline int MPSolutionResponse::_internal_dual_value_size() const
    // {
    //     return _impl_.dual_value_.size();
    // }
    // inline int MPSolutionResponse::dual_value_size() const
    // {
    //     return _internal_dual_value_size();
    // }
    // inline void MPSolutionResponse::clear_dual_value()
    // {
    //     _impl_.dual_value_.Clear();
    // }
    // inline double MPSolutionResponse::_internal_dual_value( int index ) const
    // {
    //     return _impl_.dual_value_.Get( index );
    // }
    // inline double MPSolutionResponse::dual_value( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPSolutionResponse.dual_value)
    //     return _internal_dual_value( index );
    // }
    // inline void MPSolutionResponse::set_dual_value( int index, double value )
    // {
    //     _impl_.dual_value_.Set( index, value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPSolutionResponse.dual_value)
    // }
    // inline void MPSolutionResponse::_internal_add_dual_value( double value )
    // {
    //     _impl_.dual_value_.Add( value );
    // }
    // inline void MPSolutionResponse::add_dual_value( double value )
    // {
    //     _internal_add_dual_value( value );
    //     // @@protoc_insertion_point(field_add:operations_research.MPSolutionResponse.dual_value)
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    // MPSolutionResponse::_internal_dual_value() const
    // {
    //     return _impl_.dual_value_;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    // MPSolutionResponse::dual_value() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.MPSolutionResponse.dual_value)
    //     return _internal_dual_value();
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    // MPSolutionResponse::_internal_mutable_dual_value()
    // {
    //     return &_impl_.dual_value_;
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    // MPSolutionResponse::mutable_dual_value()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.MPSolutionResponse.dual_value)
    //     return _internal_mutable_dual_value();
    // }

    // // repeated double reduced_cost = 6 [packed = true];
    // inline int MPSolutionResponse::_internal_reduced_cost_size() const
    // {
    //     return _impl_.reduced_cost_.size();
    // }
    // inline int MPSolutionResponse::reduced_cost_size() const
    // {
    //     return _internal_reduced_cost_size();
    // }
    // inline void MPSolutionResponse::clear_reduced_cost()
    // {
    //     _impl_.reduced_cost_.Clear();
    // }
    // inline double MPSolutionResponse::_internal_reduced_cost( int index ) const
    // {
    //     return _impl_.reduced_cost_.Get( index );
    // }
    // inline double MPSolutionResponse::reduced_cost( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPSolutionResponse.reduced_cost)
    //     return _internal_reduced_cost( index );
    // }
    // inline void MPSolutionResponse::set_reduced_cost( int index, double value )
    // {
    //     _impl_.reduced_cost_.Set( index, value );
    //     // @@protoc_insertion_point(field_set:operations_research.MPSolutionResponse.reduced_cost)
    // }
    // inline void MPSolutionResponse::_internal_add_reduced_cost( double value )
    // {
    //     _impl_.reduced_cost_.Add( value );
    // }
    // inline void MPSolutionResponse::add_reduced_cost( double value )
    // {
    //     _internal_add_reduced_cost( value );
    //     // @@protoc_insertion_point(field_add:operations_research.MPSolutionResponse.reduced_cost)
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    // MPSolutionResponse::_internal_reduced_cost() const
    // {
    //     return _impl_.reduced_cost_;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
    // MPSolutionResponse::reduced_cost() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.MPSolutionResponse.reduced_cost)
    //     return _internal_reduced_cost();
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    // MPSolutionResponse::_internal_mutable_reduced_cost()
    // {
    //     return &_impl_.reduced_cost_;
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
    // MPSolutionResponse::mutable_reduced_cost()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.MPSolutionResponse.reduced_cost)
    //     return _internal_mutable_reduced_cost();
    // }

    // // repeated .operations_research.MPSolution additional_solutions = 8;
    // inline int MPSolutionResponse::_internal_additional_solutions_size() const
    // {
    //     return _impl_.additional_solutions_.size();
    // }
    // inline int MPSolutionResponse::additional_solutions_size() const
    // {
    //     return _internal_additional_solutions_size();
    // }
    // inline void MPSolutionResponse::clear_additional_solutions()
    // {
    //     _impl_.additional_solutions_.Clear();
    // }
    // inline ::operations_research::MPSolution* MPSolutionResponse::mutable_additional_solutions( int index )
    // {
    //     // @@protoc_insertion_point(field_mutable:operations_research.MPSolutionResponse.additional_solutions)
    //     return _impl_.additional_solutions_.Mutable( index );
    // }
    // inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPSolution >*
    // MPSolutionResponse::mutable_additional_solutions()
    // {
    //     // @@protoc_insertion_point(field_mutable_list:operations_research.MPSolutionResponse.additional_solutions)
    //     return &_impl_.additional_solutions_;
    // }
    // inline const ::operations_research::MPSolution& MPSolutionResponse::_internal_additional_solutions( int index ) const
    // {
    //     return _impl_.additional_solutions_.Get( index );
    // }
    // inline const ::operations_research::MPSolution& MPSolutionResponse::additional_solutions( int index ) const
    // {
    //     // @@protoc_insertion_point(field_get:operations_research.MPSolutionResponse.additional_solutions)
    //     return _internal_additional_solutions( index );
    // }
    // inline ::operations_research::MPSolution* MPSolutionResponse::_internal_add_additional_solutions()
    // {
    //     return _impl_.additional_solutions_.Add();
    // }
    // inline ::operations_research::MPSolution* MPSolutionResponse::add_additional_solutions()
    // {
    //     ::operations_research::MPSolution* _add = _internal_add_additional_solutions();
    //     // @@protoc_insertion_point(field_add:operations_research.MPSolutionResponse.additional_solutions)
    //     return _add;
    // }
    // inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::MPSolution >&
    // MPSolutionResponse::additional_solutions() const
    // {
    //     // @@protoc_insertion_point(field_list:operations_research.MPSolutionResponse.additional_solutions)
    //     return _impl_.additional_solutions_;
    // }

    // #ifdef __GNUC__
    // #pragma GCC diagnostic pop
    // #endif  // __GNUC__
    // // -------------------------------------------------------------------

    // // -------------------------------------------------------------------

    // // -------------------------------------------------------------------

    // // -------------------------------------------------------------------

    // // -------------------------------------------------------------------

    // // -------------------------------------------------------------------

    // // -------------------------------------------------------------------

    // // -------------------------------------------------------------------

    // // -------------------------------------------------------------------

    // // -------------------------------------------------------------------

    // // -------------------------------------------------------------------

    // // -------------------------------------------------------------------

    // // -------------------------------------------------------------------

    // // -------------------------------------------------------------------

    // // -------------------------------------------------------------------

    // // -------------------------------------------------------------------

    // // -------------------------------------------------------------------

    // // -------------------------------------------------------------------

    // // -------------------------------------------------------------------

    // // -------------------------------------------------------------------

    // // -------------------------------------------------------------------

    // // @@protoc_insertion_point(namespace_scope)

}  // namespace operations_research

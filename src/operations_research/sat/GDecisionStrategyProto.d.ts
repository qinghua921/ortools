export class DecisionStrategyProto 
{
// public:
//     inline DecisionStrategyProto()
//         : DecisionStrategyProto( nullptr ) {}
//     ~DecisionStrategyProto() override;
//     explicit PROTOBUF_CONSTEXPR DecisionStrategyProto( ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized );

//     DecisionStrategyProto( const DecisionStrategyProto& from );
//     DecisionStrategyProto( DecisionStrategyProto&& from ) noexcept
//         : DecisionStrategyProto()
//     {
//         *this = ::std::move( from );
//     }

//     inline DecisionStrategyProto& operator=( const DecisionStrategyProto& from )
//     {
//         CopyFrom( from );
//         return *this;
//     }
//     inline DecisionStrategyProto& operator=( DecisionStrategyProto&& from ) noexcept
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
//     static const DecisionStrategyProto& default_instance()
//     {
//         return *internal_default_instance();
//     }
//     static inline const DecisionStrategyProto* internal_default_instance()
//     {
//         return reinterpret_cast< const DecisionStrategyProto* >(
//             &_DecisionStrategyProto_default_instance_ );
//     }
//     static constexpr int kIndexInFileMessages =
//         22;

//     friend void swap( DecisionStrategyProto& a, DecisionStrategyProto& b )
//     {
//         a.Swap( &b );
//     }
//     inline void Swap( DecisionStrategyProto* other )
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
//     void UnsafeArenaSwap( DecisionStrategyProto* other )
//     {
//         if ( other == this ) return;
//         GOOGLE_DCHECK( GetOwningArena() == other->GetOwningArena() );
//         InternalSwap( other );
//     }

//     // implements Message ----------------------------------------------

//     DecisionStrategyProto* New( ::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr ) const final
//     {
//         return CreateMaybeMessage< DecisionStrategyProto >( arena );
//     }
//     using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
//     void CopyFrom( const DecisionStrategyProto& from );
//     using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
//     void MergeFrom( const DecisionStrategyProto& from )
//     {
//         DecisionStrategyProto::MergeImpl( *this, from );
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
//     void InternalSwap( DecisionStrategyProto* other );

// private:
//     friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
//     static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName()
//     {
//         return "operations_research.sat.DecisionStrategyProto";
//     }

// protected:
//     explicit DecisionStrategyProto( ::PROTOBUF_NAMESPACE_ID::Arena* arena,
//                                     bool                            is_message_owned = false );

// public:
//     static const ClassData                             _class_data_;
//     const ::PROTOBUF_NAMESPACE_ID::Message::ClassData* GetClassData() const final;

//     ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

//     // nested types ----------------------------------------------------

//     typedef DecisionStrategyProto_AffineTransformation AffineTransformation;

//     typedef DecisionStrategyProto_VariableSelectionStrategy VariableSelectionStrategy;
//     static constexpr VariableSelectionStrategy              CHOOSE_FIRST =
//         DecisionStrategyProto_VariableSelectionStrategy_CHOOSE_FIRST;
//     static constexpr VariableSelectionStrategy CHOOSE_LOWEST_MIN =
//         DecisionStrategyProto_VariableSelectionStrategy_CHOOSE_LOWEST_MIN;
//     static constexpr VariableSelectionStrategy CHOOSE_HIGHEST_MAX =
//         DecisionStrategyProto_VariableSelectionStrategy_CHOOSE_HIGHEST_MAX;
//     static constexpr VariableSelectionStrategy CHOOSE_MIN_DOMAIN_SIZE =
//         DecisionStrategyProto_VariableSelectionStrategy_CHOOSE_MIN_DOMAIN_SIZE;
//     static constexpr VariableSelectionStrategy CHOOSE_MAX_DOMAIN_SIZE =
//         DecisionStrategyProto_VariableSelectionStrategy_CHOOSE_MAX_DOMAIN_SIZE;
//     static inline bool VariableSelectionStrategy_IsValid( int value )
//     {
//         return DecisionStrategyProto_VariableSelectionStrategy_IsValid( value );
//     }
//     static constexpr VariableSelectionStrategy VariableSelectionStrategy_MIN =
//         DecisionStrategyProto_VariableSelectionStrategy_VariableSelectionStrategy_MIN;
//     static constexpr VariableSelectionStrategy VariableSelectionStrategy_MAX =
//         DecisionStrategyProto_VariableSelectionStrategy_VariableSelectionStrategy_MAX;
//     static constexpr int VariableSelectionStrategy_ARRAYSIZE =
//         DecisionStrategyProto_VariableSelectionStrategy_VariableSelectionStrategy_ARRAYSIZE;
//     static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
//     VariableSelectionStrategy_descriptor()
//     {
//         return DecisionStrategyProto_VariableSelectionStrategy_descriptor();
//     }
//     template < typename T >
//     static inline const std::string& VariableSelectionStrategy_Name( T enum_t_value )
//     {
//         static_assert( ::std::is_same< T, VariableSelectionStrategy >::value || ::std::is_integral< T >::value,
//                        "Incorrect type passed to function VariableSelectionStrategy_Name." );
//         return DecisionStrategyProto_VariableSelectionStrategy_Name( enum_t_value );
//     }
//     static inline bool VariableSelectionStrategy_Parse( ::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
//                                                         VariableSelectionStrategy*                value )
//     {
//         return DecisionStrategyProto_VariableSelectionStrategy_Parse( name, value );
//     }

//     typedef DecisionStrategyProto_DomainReductionStrategy DomainReductionStrategy;
//     static constexpr DomainReductionStrategy              SELECT_MIN_VALUE =
//         DecisionStrategyProto_DomainReductionStrategy_SELECT_MIN_VALUE;
//     static constexpr DomainReductionStrategy SELECT_MAX_VALUE =
//         DecisionStrategyProto_DomainReductionStrategy_SELECT_MAX_VALUE;
//     static constexpr DomainReductionStrategy SELECT_LOWER_HALF =
//         DecisionStrategyProto_DomainReductionStrategy_SELECT_LOWER_HALF;
//     static constexpr DomainReductionStrategy SELECT_UPPER_HALF =
//         DecisionStrategyProto_DomainReductionStrategy_SELECT_UPPER_HALF;
//     static constexpr DomainReductionStrategy SELECT_MEDIAN_VALUE =
//         DecisionStrategyProto_DomainReductionStrategy_SELECT_MEDIAN_VALUE;
//     static inline bool DomainReductionStrategy_IsValid( int value )
//     {
//         return DecisionStrategyProto_DomainReductionStrategy_IsValid( value );
//     }
//     static constexpr DomainReductionStrategy DomainReductionStrategy_MIN =
//         DecisionStrategyProto_DomainReductionStrategy_DomainReductionStrategy_MIN;
//     static constexpr DomainReductionStrategy DomainReductionStrategy_MAX =
//         DecisionStrategyProto_DomainReductionStrategy_DomainReductionStrategy_MAX;
//     static constexpr int DomainReductionStrategy_ARRAYSIZE =
//         DecisionStrategyProto_DomainReductionStrategy_DomainReductionStrategy_ARRAYSIZE;
//     static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
//     DomainReductionStrategy_descriptor()
//     {
//         return DecisionStrategyProto_DomainReductionStrategy_descriptor();
//     }
//     template < typename T >
//     static inline const std::string& DomainReductionStrategy_Name( T enum_t_value )
//     {
//         static_assert( ::std::is_same< T, DomainReductionStrategy >::value || ::std::is_integral< T >::value,
//                        "Incorrect type passed to function DomainReductionStrategy_Name." );
//         return DecisionStrategyProto_DomainReductionStrategy_Name( enum_t_value );
//     }
//     static inline bool DomainReductionStrategy_Parse( ::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
//                                                       DomainReductionStrategy*                  value )
//     {
//         return DecisionStrategyProto_DomainReductionStrategy_Parse( name, value );
//     }

//     // accessors -------------------------------------------------------

//     enum : int
//     {
//         kVariablesFieldNumber                 = 1,
//         kTransformationsFieldNumber           = 4,
//         kVariableSelectionStrategyFieldNumber = 2,
//         kDomainReductionStrategyFieldNumber   = 3,
//     };
//     // repeated int32 variables = 1;
//     int variables_size() const;

// private:
//     int _internal_variables_size() const;

// public:
//     void clear_variables();

// private:
//     int32_t _internal_variables( int index ) const;
//     const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
//          _internal_variables() const;
//     void _internal_add_variables( int32_t value );
//     ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
//     _internal_mutable_variables();

// public:
//     int32_t variables( int index ) const;
//     void    set_variables( int index, int32_t value );
//     void    add_variables( int32_t value );
//     const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
//     variables() const;
//     ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
//     mutable_variables();

//     // repeated .operations_research.sat.DecisionStrategyProto.AffineTransformation transformations = 4;
//     int transformations_size() const;

// private:
//     int _internal_transformations_size() const;

// public:
//     void                                                                    clear_transformations();
//     ::operations_research::sat::DecisionStrategyProto_AffineTransformation* mutable_transformations( int index );
//     ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::DecisionStrategyProto_AffineTransformation >*
//     mutable_transformations();

// private:
//     const ::operations_research::sat::DecisionStrategyProto_AffineTransformation& _internal_transformations( int index ) const;
//     ::operations_research::sat::DecisionStrategyProto_AffineTransformation*       _internal_add_transformations();

// public:
//     const ::operations_research::sat::DecisionStrategyProto_AffineTransformation& transformations( int index ) const;
//     ::operations_research::sat::DecisionStrategyProto_AffineTransformation*       add_transformations();
//     const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::DecisionStrategyProto_AffineTransformation >&
//     transformations() const;

//     // .operations_research.sat.DecisionStrategyProto.VariableSelectionStrategy variable_selection_strategy = 2;
//     void                                                                        clear_variable_selection_strategy();
//     ::operations_research::sat::DecisionStrategyProto_VariableSelectionStrategy variable_selection_strategy() const;
//     void                                                                        set_variable_selection_strategy( ::operations_research::sat::DecisionStrategyProto_VariableSelectionStrategy value );

// private:
//     ::operations_research::sat::DecisionStrategyProto_VariableSelectionStrategy _internal_variable_selection_strategy() const;
//     void                                                                        _internal_set_variable_selection_strategy( ::operations_research::sat::DecisionStrategyProto_VariableSelectionStrategy value );

// public:
//     // .operations_research.sat.DecisionStrategyProto.DomainReductionStrategy domain_reduction_strategy = 3;
//     void                                                                      clear_domain_reduction_strategy();
//     ::operations_research::sat::DecisionStrategyProto_DomainReductionStrategy domain_reduction_strategy() const;
//     void                                                                      set_domain_reduction_strategy( ::operations_research::sat::DecisionStrategyProto_DomainReductionStrategy value );

// private:
//     ::operations_research::sat::DecisionStrategyProto_DomainReductionStrategy _internal_domain_reduction_strategy() const;
//     void                                                                      _internal_set_domain_reduction_strategy( ::operations_research::sat::DecisionStrategyProto_DomainReductionStrategy value );

// public:
//     // @@protoc_insertion_point(class_scope:operations_research.sat.DecisionStrategyProto)
// private:
//     class _Internal;

//     template < typename T >
//     friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
//     typedef void InternalArenaConstructable_;
//     typedef void DestructorSkippable_;
//     struct Impl_
//     {
//         ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >                                                                   variables_;
//         mutable std::atomic< int >                                                                                          _variables_cached_byte_size_;
//         ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::DecisionStrategyProto_AffineTransformation > transformations_;
//         int                                                                                                                 variable_selection_strategy_;
//         int                                                                                                                 domain_reduction_strategy_;
//         mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize                                                               _cached_size_;
//     };
//     union
//     {
//         Impl_ _impl_;
//     };
//     friend struct ::TableStruct_ortools_2fsat_2fcp_5fmodel_2eproto;
};

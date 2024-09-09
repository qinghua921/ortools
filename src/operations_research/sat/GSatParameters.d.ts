export namespace SatParameters
{
    export enum SearchBranching
    {
        AUTOMATIC_SEARCH = 0,
        FIXED_SEARCH = 1,
        PORTFOLIO_SEARCH = 2,
        LP_SEARCH = 3,
        PSEUDO_COST_SEARCH = 4,
        PORTFOLIO_WITH_QUICK_RESTART_SEARCH = 5,
        HINT_SEARCH = 6,
        PARTIAL_FIXED_SEARCH = 7
    };
}

export class SatParameters 
{
    // public:
    //     inline SatParameters()
    //         : SatParameters( nullptr ) {}
    constructor();

    //     explicit PROTOBUF_CONSTEXPR SatParameters( ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized );

    //     SatParameters( const SatParameters& from );
    //     SatParameters( SatParameters&& from ) noexcept
    //         : SatParameters()
    //     {
    //         *this = ::std::move( from );
    //     }

    //     inline SatParameters& operator=( const SatParameters& from )
    //     {
    //         CopyFrom( from );
    //         return *this;
    //     }
    //     inline SatParameters& operator=( SatParameters&& from ) noexcept
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
    //     static const SatParameters& default_instance()
    //     {
    //         return *internal_default_instance();
    //     }
    //     static inline const SatParameters* internal_default_instance()
    //     {
    //         return reinterpret_cast< const SatParameters* >(
    //             &_SatParameters_default_instance_ );
    //     }
    //     static constexpr int kIndexInFileMessages =
    //         0;

    //     friend void swap( SatParameters& a, SatParameters& b )
    //     {
    //         a.Swap( &b );
    //     }
    //     inline void Swap( SatParameters* other )
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
    //     void UnsafeArenaSwap( SatParameters* other )
    //     {
    //         if ( other == this ) return;
    //         GOOGLE_DCHECK( GetOwningArena() == other->GetOwningArena() );
    //         InternalSwap( other );
    //     }

    //     // implements Message ----------------------------------------------

    //     SatParameters* New( ::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr ) const final
    //     {
    //         return CreateMaybeMessage< SatParameters >( arena );
    //     }
    //     using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
    //     void CopyFrom( const SatParameters& from );
    //     using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
    //     void MergeFrom( const SatParameters& from )
    //     {
    //         SatParameters::MergeImpl( *this, from );
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

    // private:
    //     void SharedCtor( ::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned );
    //     void SharedDtor();
    //     void SetCachedSize( int size ) const final;
    //     void InternalSwap( SatParameters* other );

    // private:
    //     friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
    //     static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName()
    //     {
    //         return "operations_research.sat.SatParameters";
    //     }

    // protected:
    //     explicit SatParameters( ::PROTOBUF_NAMESPACE_ID::Arena* arena,
    //                             bool                            is_message_owned = false );

    // public:
    //     static const ClassData                             _class_data_;
    //     const ::PROTOBUF_NAMESPACE_ID::Message::ClassData* GetClassData() const final;

    //     ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

    //     // nested types ----------------------------------------------------

    //     typedef SatParameters_VariableOrder VariableOrder;
    //     static constexpr VariableOrder      IN_ORDER =
    //         SatParameters_VariableOrder_IN_ORDER;
    //     static constexpr VariableOrder IN_REVERSE_ORDER =
    //         SatParameters_VariableOrder_IN_REVERSE_ORDER;
    //     static constexpr VariableOrder IN_RANDOM_ORDER =
    //         SatParameters_VariableOrder_IN_RANDOM_ORDER;
    //     static inline bool VariableOrder_IsValid( int value )
    //     {
    //         return SatParameters_VariableOrder_IsValid( value );
    //     }
    //     static constexpr VariableOrder VariableOrder_MIN =
    //         SatParameters_VariableOrder_VariableOrder_MIN;
    //     static constexpr VariableOrder VariableOrder_MAX =
    //         SatParameters_VariableOrder_VariableOrder_MAX;
    //     static constexpr int VariableOrder_ARRAYSIZE =
    //         SatParameters_VariableOrder_VariableOrder_ARRAYSIZE;
    //     static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
    //     VariableOrder_descriptor()
    //     {
    //         return SatParameters_VariableOrder_descriptor();
    //     }
    //     template < typename T >
    //     static inline const std::string& VariableOrder_Name( T enum_t_value )
    //     {
    //         static_assert( ::std::is_same< T, VariableOrder >::value || ::std::is_integral< T >::value,
    //                        "Incorrect type passed to function VariableOrder_Name." );
    //         return SatParameters_VariableOrder_Name( enum_t_value );
    //     }
    //     static inline bool VariableOrder_Parse( ::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
    //                                             VariableOrder*                            value )
    //     {
    //         return SatParameters_VariableOrder_Parse( name, value );
    //     }

    //     typedef SatParameters_Polarity Polarity;
    //     static constexpr Polarity      POLARITY_TRUE =
    //         SatParameters_Polarity_POLARITY_TRUE;
    //     static constexpr Polarity POLARITY_FALSE =
    //         SatParameters_Polarity_POLARITY_FALSE;
    //     static constexpr Polarity POLARITY_RANDOM =
    //         SatParameters_Polarity_POLARITY_RANDOM;
    //     static constexpr Polarity POLARITY_WEIGHTED_SIGN =
    //         SatParameters_Polarity_POLARITY_WEIGHTED_SIGN;
    //     static constexpr Polarity POLARITY_REVERSE_WEIGHTED_SIGN =
    //         SatParameters_Polarity_POLARITY_REVERSE_WEIGHTED_SIGN;
    //     static inline bool Polarity_IsValid( int value )
    //     {
    //         return SatParameters_Polarity_IsValid( value );
    //     }
    //     static constexpr Polarity Polarity_MIN =
    //         SatParameters_Polarity_Polarity_MIN;
    //     static constexpr Polarity Polarity_MAX =
    //         SatParameters_Polarity_Polarity_MAX;
    //     static constexpr int Polarity_ARRAYSIZE =
    //         SatParameters_Polarity_Polarity_ARRAYSIZE;
    //     static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
    //     Polarity_descriptor()
    //     {
    //         return SatParameters_Polarity_descriptor();
    //     }
    //     template < typename T >
    //     static inline const std::string& Polarity_Name( T enum_t_value )
    //     {
    //         static_assert( ::std::is_same< T, Polarity >::value || ::std::is_integral< T >::value,
    //                        "Incorrect type passed to function Polarity_Name." );
    //         return SatParameters_Polarity_Name( enum_t_value );
    //     }
    //     static inline bool Polarity_Parse( ::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
    //                                        Polarity*                                 value )
    //     {
    //         return SatParameters_Polarity_Parse( name, value );
    //     }

    //     typedef SatParameters_ConflictMinimizationAlgorithm ConflictMinimizationAlgorithm;
    //     static constexpr ConflictMinimizationAlgorithm      NONE =
    //         SatParameters_ConflictMinimizationAlgorithm_NONE;
    //     static constexpr ConflictMinimizationAlgorithm SIMPLE =
    //         SatParameters_ConflictMinimizationAlgorithm_SIMPLE;
    //     static constexpr ConflictMinimizationAlgorithm RECURSIVE =
    //         SatParameters_ConflictMinimizationAlgorithm_RECURSIVE;
    //     static constexpr ConflictMinimizationAlgorithm EXPERIMENTAL =
    //         SatParameters_ConflictMinimizationAlgorithm_EXPERIMENTAL;
    //     static inline bool ConflictMinimizationAlgorithm_IsValid( int value )
    //     {
    //         return SatParameters_ConflictMinimizationAlgorithm_IsValid( value );
    //     }
    //     static constexpr ConflictMinimizationAlgorithm ConflictMinimizationAlgorithm_MIN =
    //         SatParameters_ConflictMinimizationAlgorithm_ConflictMinimizationAlgorithm_MIN;
    //     static constexpr ConflictMinimizationAlgorithm ConflictMinimizationAlgorithm_MAX =
    //         SatParameters_ConflictMinimizationAlgorithm_ConflictMinimizationAlgorithm_MAX;
    //     static constexpr int ConflictMinimizationAlgorithm_ARRAYSIZE =
    //         SatParameters_ConflictMinimizationAlgorithm_ConflictMinimizationAlgorithm_ARRAYSIZE;
    //     static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
    //     ConflictMinimizationAlgorithm_descriptor()
    //     {
    //         return SatParameters_ConflictMinimizationAlgorithm_descriptor();
    //     }
    //     template < typename T >
    //     static inline const std::string& ConflictMinimizationAlgorithm_Name( T enum_t_value )
    //     {
    //         static_assert( ::std::is_same< T, ConflictMinimizationAlgorithm >::value || ::std::is_integral< T >::value,
    //                        "Incorrect type passed to function ConflictMinimizationAlgorithm_Name." );
    //         return SatParameters_ConflictMinimizationAlgorithm_Name( enum_t_value );
    //     }
    //     static inline bool ConflictMinimizationAlgorithm_Parse( ::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
    //                                                             ConflictMinimizationAlgorithm*            value )
    //     {
    //         return SatParameters_ConflictMinimizationAlgorithm_Parse( name, value );
    //     }

    //     typedef SatParameters_BinaryMinizationAlgorithm BinaryMinizationAlgorithm;
    //     static constexpr BinaryMinizationAlgorithm      NO_BINARY_MINIMIZATION =
    //         SatParameters_BinaryMinizationAlgorithm_NO_BINARY_MINIMIZATION;
    //     static constexpr BinaryMinizationAlgorithm BINARY_MINIMIZATION_FIRST =
    //         SatParameters_BinaryMinizationAlgorithm_BINARY_MINIMIZATION_FIRST;
    //     static constexpr BinaryMinizationAlgorithm BINARY_MINIMIZATION_FIRST_WITH_TRANSITIVE_REDUCTION =
    //         SatParameters_BinaryMinizationAlgorithm_BINARY_MINIMIZATION_FIRST_WITH_TRANSITIVE_REDUCTION;
    //     static constexpr BinaryMinizationAlgorithm BINARY_MINIMIZATION_WITH_REACHABILITY =
    //         SatParameters_BinaryMinizationAlgorithm_BINARY_MINIMIZATION_WITH_REACHABILITY;
    //     static constexpr BinaryMinizationAlgorithm EXPERIMENTAL_BINARY_MINIMIZATION =
    //         SatParameters_BinaryMinizationAlgorithm_EXPERIMENTAL_BINARY_MINIMIZATION;
    //     static inline bool BinaryMinizationAlgorithm_IsValid( int value )
    //     {
    //         return SatParameters_BinaryMinizationAlgorithm_IsValid( value );
    //     }
    //     static constexpr BinaryMinizationAlgorithm BinaryMinizationAlgorithm_MIN =
    //         SatParameters_BinaryMinizationAlgorithm_BinaryMinizationAlgorithm_MIN;
    //     static constexpr BinaryMinizationAlgorithm BinaryMinizationAlgorithm_MAX =
    //         SatParameters_BinaryMinizationAlgorithm_BinaryMinizationAlgorithm_MAX;
    //     static constexpr int BinaryMinizationAlgorithm_ARRAYSIZE =
    //         SatParameters_BinaryMinizationAlgorithm_BinaryMinizationAlgorithm_ARRAYSIZE;
    //     static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
    //     BinaryMinizationAlgorithm_descriptor()
    //     {
    //         return SatParameters_BinaryMinizationAlgorithm_descriptor();
    //     }
    //     template < typename T >
    //     static inline const std::string& BinaryMinizationAlgorithm_Name( T enum_t_value )
    //     {
    //         static_assert( ::std::is_same< T, BinaryMinizationAlgorithm >::value || ::std::is_integral< T >::value,
    //                        "Incorrect type passed to function BinaryMinizationAlgorithm_Name." );
    //         return SatParameters_BinaryMinizationAlgorithm_Name( enum_t_value );
    //     }
    //     static inline bool BinaryMinizationAlgorithm_Parse( ::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
    //                                                         BinaryMinizationAlgorithm*                value )
    //     {
    //         return SatParameters_BinaryMinizationAlgorithm_Parse( name, value );
    //     }

    //     typedef SatParameters_ClauseProtection ClauseProtection;
    //     static constexpr ClauseProtection      PROTECTION_NONE =
    //         SatParameters_ClauseProtection_PROTECTION_NONE;
    //     static constexpr ClauseProtection PROTECTION_ALWAYS =
    //         SatParameters_ClauseProtection_PROTECTION_ALWAYS;
    //     static constexpr ClauseProtection PROTECTION_LBD =
    //         SatParameters_ClauseProtection_PROTECTION_LBD;
    //     static inline bool ClauseProtection_IsValid( int value )
    //     {
    //         return SatParameters_ClauseProtection_IsValid( value );
    //     }
    //     static constexpr ClauseProtection ClauseProtection_MIN =
    //         SatParameters_ClauseProtection_ClauseProtection_MIN;
    //     static constexpr ClauseProtection ClauseProtection_MAX =
    //         SatParameters_ClauseProtection_ClauseProtection_MAX;
    //     static constexpr int ClauseProtection_ARRAYSIZE =
    //         SatParameters_ClauseProtection_ClauseProtection_ARRAYSIZE;
    //     static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
    //     ClauseProtection_descriptor()
    //     {
    //         return SatParameters_ClauseProtection_descriptor();
    //     }
    //     template < typename T >
    //     static inline const std::string& ClauseProtection_Name( T enum_t_value )
    //     {
    //         static_assert( ::std::is_same< T, ClauseProtection >::value || ::std::is_integral< T >::value,
    //                        "Incorrect type passed to function ClauseProtection_Name." );
    //         return SatParameters_ClauseProtection_Name( enum_t_value );
    //     }
    //     static inline bool ClauseProtection_Parse( ::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
    //                                                ClauseProtection*                         value )
    //     {
    //         return SatParameters_ClauseProtection_Parse( name, value );
    //     }

    //     typedef SatParameters_ClauseOrdering ClauseOrdering;
    //     static constexpr ClauseOrdering      CLAUSE_ACTIVITY =
    //         SatParameters_ClauseOrdering_CLAUSE_ACTIVITY;
    //     static constexpr ClauseOrdering CLAUSE_LBD =
    //         SatParameters_ClauseOrdering_CLAUSE_LBD;
    //     static inline bool ClauseOrdering_IsValid( int value )
    //     {
    //         return SatParameters_ClauseOrdering_IsValid( value );
    //     }
    //     static constexpr ClauseOrdering ClauseOrdering_MIN =
    //         SatParameters_ClauseOrdering_ClauseOrdering_MIN;
    //     static constexpr ClauseOrdering ClauseOrdering_MAX =
    //         SatParameters_ClauseOrdering_ClauseOrdering_MAX;
    //     static constexpr int ClauseOrdering_ARRAYSIZE =
    //         SatParameters_ClauseOrdering_ClauseOrdering_ARRAYSIZE;
    //     static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
    //     ClauseOrdering_descriptor()
    //     {
    //         return SatParameters_ClauseOrdering_descriptor();
    //     }
    //     template < typename T >
    //     static inline const std::string& ClauseOrdering_Name( T enum_t_value )
    //     {
    //         static_assert( ::std::is_same< T, ClauseOrdering >::value || ::std::is_integral< T >::value,
    //                        "Incorrect type passed to function ClauseOrdering_Name." );
    //         return SatParameters_ClauseOrdering_Name( enum_t_value );
    //     }
    //     static inline bool ClauseOrdering_Parse( ::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
    //                                              ClauseOrdering*                           value )
    //     {
    //         return SatParameters_ClauseOrdering_Parse( name, value );
    //     }

    //     typedef SatParameters_RestartAlgorithm RestartAlgorithm;
    //     static constexpr RestartAlgorithm      NO_RESTART =
    //         SatParameters_RestartAlgorithm_NO_RESTART;
    //     static constexpr RestartAlgorithm LUBY_RESTART =
    //         SatParameters_RestartAlgorithm_LUBY_RESTART;
    //     static constexpr RestartAlgorithm DL_MOVING_AVERAGE_RESTART =
    //         SatParameters_RestartAlgorithm_DL_MOVING_AVERAGE_RESTART;
    //     static constexpr RestartAlgorithm LBD_MOVING_AVERAGE_RESTART =
    //         SatParameters_RestartAlgorithm_LBD_MOVING_AVERAGE_RESTART;
    //     static constexpr RestartAlgorithm FIXED_RESTART =
    //         SatParameters_RestartAlgorithm_FIXED_RESTART;
    //     static inline bool RestartAlgorithm_IsValid( int value )
    //     {
    //         return SatParameters_RestartAlgorithm_IsValid( value );
    //     }
    //     static constexpr RestartAlgorithm RestartAlgorithm_MIN =
    //         SatParameters_RestartAlgorithm_RestartAlgorithm_MIN;
    //     static constexpr RestartAlgorithm RestartAlgorithm_MAX =
    //         SatParameters_RestartAlgorithm_RestartAlgorithm_MAX;
    //     static constexpr int RestartAlgorithm_ARRAYSIZE =
    //         SatParameters_RestartAlgorithm_RestartAlgorithm_ARRAYSIZE;
    //     static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
    //     RestartAlgorithm_descriptor()
    //     {
    //         return SatParameters_RestartAlgorithm_descriptor();
    //     }
    //     template < typename T >
    //     static inline const std::string& RestartAlgorithm_Name( T enum_t_value )
    //     {
    //         static_assert( ::std::is_same< T, RestartAlgorithm >::value || ::std::is_integral< T >::value,
    //                        "Incorrect type passed to function RestartAlgorithm_Name." );
    //         return SatParameters_RestartAlgorithm_Name( enum_t_value );
    //     }
    //     static inline bool RestartAlgorithm_Parse( ::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
    //                                                RestartAlgorithm*                         value )
    //     {
    //         return SatParameters_RestartAlgorithm_Parse( name, value );
    //     }

    //     typedef SatParameters_MaxSatAssumptionOrder MaxSatAssumptionOrder;
    //     static constexpr MaxSatAssumptionOrder      DEFAULT_ASSUMPTION_ORDER =
    //         SatParameters_MaxSatAssumptionOrder_DEFAULT_ASSUMPTION_ORDER;
    //     static constexpr MaxSatAssumptionOrder ORDER_ASSUMPTION_BY_DEPTH =
    //         SatParameters_MaxSatAssumptionOrder_ORDER_ASSUMPTION_BY_DEPTH;
    //     static constexpr MaxSatAssumptionOrder ORDER_ASSUMPTION_BY_WEIGHT =
    //         SatParameters_MaxSatAssumptionOrder_ORDER_ASSUMPTION_BY_WEIGHT;
    //     static inline bool MaxSatAssumptionOrder_IsValid( int value )
    //     {
    //         return SatParameters_MaxSatAssumptionOrder_IsValid( value );
    //     }
    //     static constexpr MaxSatAssumptionOrder MaxSatAssumptionOrder_MIN =
    //         SatParameters_MaxSatAssumptionOrder_MaxSatAssumptionOrder_MIN;
    //     static constexpr MaxSatAssumptionOrder MaxSatAssumptionOrder_MAX =
    //         SatParameters_MaxSatAssumptionOrder_MaxSatAssumptionOrder_MAX;
    //     static constexpr int MaxSatAssumptionOrder_ARRAYSIZE =
    //         SatParameters_MaxSatAssumptionOrder_MaxSatAssumptionOrder_ARRAYSIZE;
    //     static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
    //     MaxSatAssumptionOrder_descriptor()
    //     {
    //         return SatParameters_MaxSatAssumptionOrder_descriptor();
    //     }
    //     template < typename T >
    //     static inline const std::string& MaxSatAssumptionOrder_Name( T enum_t_value )
    //     {
    //         static_assert( ::std::is_same< T, MaxSatAssumptionOrder >::value || ::std::is_integral< T >::value,
    //                        "Incorrect type passed to function MaxSatAssumptionOrder_Name." );
    //         return SatParameters_MaxSatAssumptionOrder_Name( enum_t_value );
    //     }
    //     static inline bool MaxSatAssumptionOrder_Parse( ::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
    //                                                     MaxSatAssumptionOrder*                    value )
    //     {
    //         return SatParameters_MaxSatAssumptionOrder_Parse( name, value );
    //     }

    //     typedef SatParameters_MaxSatStratificationAlgorithm MaxSatStratificationAlgorithm;
    //     static constexpr MaxSatStratificationAlgorithm      STRATIFICATION_NONE =
    //         SatParameters_MaxSatStratificationAlgorithm_STRATIFICATION_NONE;
    //     static constexpr MaxSatStratificationAlgorithm STRATIFICATION_DESCENT =
    //         SatParameters_MaxSatStratificationAlgorithm_STRATIFICATION_DESCENT;
    //     static constexpr MaxSatStratificationAlgorithm STRATIFICATION_ASCENT =
    //         SatParameters_MaxSatStratificationAlgorithm_STRATIFICATION_ASCENT;
    //     static inline bool MaxSatStratificationAlgorithm_IsValid( int value )
    //     {
    //         return SatParameters_MaxSatStratificationAlgorithm_IsValid( value );
    //     }
    //     static constexpr MaxSatStratificationAlgorithm MaxSatStratificationAlgorithm_MIN =
    //         SatParameters_MaxSatStratificationAlgorithm_MaxSatStratificationAlgorithm_MIN;
    //     static constexpr MaxSatStratificationAlgorithm MaxSatStratificationAlgorithm_MAX =
    //         SatParameters_MaxSatStratificationAlgorithm_MaxSatStratificationAlgorithm_MAX;
    //     static constexpr int MaxSatStratificationAlgorithm_ARRAYSIZE =
    //         SatParameters_MaxSatStratificationAlgorithm_MaxSatStratificationAlgorithm_ARRAYSIZE;
    //     static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
    //     MaxSatStratificationAlgorithm_descriptor()
    //     {
    //         return SatParameters_MaxSatStratificationAlgorithm_descriptor();
    //     }
    //     template < typename T >
    //     static inline const std::string& MaxSatStratificationAlgorithm_Name( T enum_t_value )
    //     {
    //         static_assert( ::std::is_same< T, MaxSatStratificationAlgorithm >::value || ::std::is_integral< T >::value,
    //                        "Incorrect type passed to function MaxSatStratificationAlgorithm_Name." );
    //         return SatParameters_MaxSatStratificationAlgorithm_Name( enum_t_value );
    //     }
    //     static inline bool MaxSatStratificationAlgorithm_Parse( ::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
    //                                                             MaxSatStratificationAlgorithm*            value )
    //     {
    //         return SatParameters_MaxSatStratificationAlgorithm_Parse( name, value );
    //     }

    //     typedef SatParameters_SearchBranching SearchBranching;
    //     static constexpr SearchBranching      AUTOMATIC_SEARCH =
    //         SatParameters_SearchBranching_AUTOMATIC_SEARCH;
    //     static constexpr SearchBranching FIXED_SEARCH =
    //         SatParameters_SearchBranching_FIXED_SEARCH;
    //     static constexpr SearchBranching PORTFOLIO_SEARCH =
    //         SatParameters_SearchBranching_PORTFOLIO_SEARCH;
    //     static constexpr SearchBranching LP_SEARCH =
    //         SatParameters_SearchBranching_LP_SEARCH;
    //     static constexpr SearchBranching PSEUDO_COST_SEARCH =
    //         SatParameters_SearchBranching_PSEUDO_COST_SEARCH;
    //     static constexpr SearchBranching PORTFOLIO_WITH_QUICK_RESTART_SEARCH =
    //         SatParameters_SearchBranching_PORTFOLIO_WITH_QUICK_RESTART_SEARCH;
    //     static constexpr SearchBranching HINT_SEARCH =
    //         SatParameters_SearchBranching_HINT_SEARCH;
    //     static constexpr SearchBranching PARTIAL_FIXED_SEARCH =
    //         SatParameters_SearchBranching_PARTIAL_FIXED_SEARCH;
    //     static inline bool SearchBranching_IsValid( int value )
    //     {
    //         return SatParameters_SearchBranching_IsValid( value );
    //     }
    //     static constexpr SearchBranching SearchBranching_MIN =
    //         SatParameters_SearchBranching_SearchBranching_MIN;
    //     static constexpr SearchBranching SearchBranching_MAX =
    //         SatParameters_SearchBranching_SearchBranching_MAX;
    //     static constexpr int SearchBranching_ARRAYSIZE =
    //         SatParameters_SearchBranching_SearchBranching_ARRAYSIZE;
    //     static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
    //     SearchBranching_descriptor()
    //     {
    //         return SatParameters_SearchBranching_descriptor();
    //     }
    //     template < typename T >
    //     static inline const std::string& SearchBranching_Name( T enum_t_value )
    //     {
    //         static_assert( ::std::is_same< T, SearchBranching >::value || ::std::is_integral< T >::value,
    //                        "Incorrect type passed to function SearchBranching_Name." );
    //         return SatParameters_SearchBranching_Name( enum_t_value );
    //     }
    //     static inline bool SearchBranching_Parse( ::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
    //                                               SearchBranching*                          value )
    //     {
    //         return SatParameters_SearchBranching_Parse( name, value );
    //     }

    //     typedef SatParameters_FPRoundingMethod FPRoundingMethod;
    //     static constexpr FPRoundingMethod      NEAREST_INTEGER =
    //         SatParameters_FPRoundingMethod_NEAREST_INTEGER;
    //     static constexpr FPRoundingMethod LOCK_BASED =
    //         SatParameters_FPRoundingMethod_LOCK_BASED;
    //     static constexpr FPRoundingMethod ACTIVE_LOCK_BASED =
    //         SatParameters_FPRoundingMethod_ACTIVE_LOCK_BASED;
    //     static constexpr FPRoundingMethod PROPAGATION_ASSISTED =
    //         SatParameters_FPRoundingMethod_PROPAGATION_ASSISTED;
    //     static inline bool FPRoundingMethod_IsValid( int value )
    //     {
    //         return SatParameters_FPRoundingMethod_IsValid( value );
    //     }
    //     static constexpr FPRoundingMethod FPRoundingMethod_MIN =
    //         SatParameters_FPRoundingMethod_FPRoundingMethod_MIN;
    //     static constexpr FPRoundingMethod FPRoundingMethod_MAX =
    //         SatParameters_FPRoundingMethod_FPRoundingMethod_MAX;
    //     static constexpr int FPRoundingMethod_ARRAYSIZE =
    //         SatParameters_FPRoundingMethod_FPRoundingMethod_ARRAYSIZE;
    //     static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
    //     FPRoundingMethod_descriptor()
    //     {
    //         return SatParameters_FPRoundingMethod_descriptor();
    //     }
    //     template < typename T >
    //     static inline const std::string& FPRoundingMethod_Name( T enum_t_value )
    //     {
    //         static_assert( ::std::is_same< T, FPRoundingMethod >::value || ::std::is_integral< T >::value,
    //                        "Incorrect type passed to function FPRoundingMethod_Name." );
    //         return SatParameters_FPRoundingMethod_Name( enum_t_value );
    //     }
    //     static inline bool FPRoundingMethod_Parse( ::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
    //                                                FPRoundingMethod*                         value )
    //     {
    //         return SatParameters_FPRoundingMethod_Parse( name, value );
    //     }

    //     // accessors -------------------------------------------------------

    //     enum : int
    //     {
    //         kRestartAlgorithmsFieldNumber                              = 61,
    //         kSubsolversFieldNumber                                     = 207,
    //         kIgnoreSubsolversFieldNumber                               = 209,
    //         kSubsolverParamsFieldNumber                                = 210,
    //         kExtraSubsolversFieldNumber                                = 219,
    //         kDefaultRestartAlgorithmsFieldNumber                       = 70,
    //         kNameFieldNumber                                           = 171,
    //         kLogPrefixFieldNumber                                      = 185,
    //         kPreferredVariableOrderFieldNumber                         = 1,
    //         kClauseCleanupTargetFieldNumber                            = 13,
    //         kRandomBranchesRatioFieldNumber                            = 32,
    //         kRandomPolarityRatioFieldNumber                            = 45,
    //         kMaxSatAssumptionOrderFieldNumber                          = 51,
    //         kClauseCleanupProtectionFieldNumber                        = 58,
    //         kClauseCleanupOrderingFieldNumber                          = 60,
    //         kNumConflictsBeforeStrategyChangesFieldNumber              = 68,
    //         kStrategyChangeIncreaseRatioFieldNumber                    = 69,
    //         kInitialVariablesActivityFieldNumber                       = 76,
    //         kSearchBranchingFieldNumber                                = 82,
    //         kUseErwaHeuristicFieldNumber                               = 75,
    //         kAlsoBumpVariablesInConflictReasonsFieldNumber             = 77,
    //         kUseBlockingRestartFieldNumber                             = 64,
    //         kPermuteVariableRandomlyFieldNumber                        = 178,
    //         kSearchRandomizationToleranceFieldNumber                   = 104,
    //         kNumSearchWorkersFieldNumber                               = 100,
    //         kUseLnsOnlyFieldNumber                                     = 101,
    //         kDiversifyLnsParamsFieldNumber                             = 137,
    //         kRandomizeSearchFieldNumber                                = 103,
    //         kUseOptionalVariablesFieldNumber                           = 108,
    //         kUsePbResolutionFieldNumber                                = 43,
    //         kMinimizeReductionDuringPbResolutionFieldNumber            = 48,
    //         kUseSatInprocessingFieldNumber                             = 163,
    //         kDetectTableWithCostFieldNumber                            = 216,
    //         kOptimizeWithLbTreeSearchFieldNumber                       = 188,
    //         kOptimizeWithMaxHsFieldNumber                              = 85,
    //         kEnumerateAllSolutionsFieldNumber                          = 87,
    //         kKeepAllFeasibleSolutionsInPresolveFieldNumber             = 173,
    //         kInterleaveBatchSizeFieldNumber                            = 134,
    //         kInterleaveSearchFieldNumber                               = 136,
    //         kDebugPostsolveWithFullSolverFieldNumber                   = 162,
    //         kDebugCrashOnBadHintFieldNumber                            = 195,
    //         kMaxSatReverseAssumptionOrderFieldNumber                   = 52,
    //         kProbingPeriodAtRootFieldNumber                            = 142,
    //         kFillTightenedDomainsInResponseFieldNumber                 = 132,
    //         kFillAdditionalSolutionsInResponseFieldNumber              = 194,
    //         kStopAfterFirstSolutionFieldNumber                         = 98,
    //         kStopAfterPresolveFieldNumber                              = 149,
    //         kPermutePresolveConstraintOrderFieldNumber                 = 179,
    //         kUseAbslRandomFieldNumber                                  = 180,
    //         kLogSearchProgressFieldNumber                              = 41,
    //         kLogToResponseFieldNumber                                  = 187,
    //         kUseStrongPropagationInDisjunctiveFieldNumber              = 230,
    //         kUseOverloadCheckerInCumulativeFieldNumber                 = 78,
    //         kUseTimetableEdgeFindingInCumulativeFieldNumber            = 79,
    //         kUseHardPrecedencesInCumulativeFieldNumber                 = 215,
    //         kDebugMaxNumPresolveOperationsFieldNumber                  = 151,
    //         kRelativeGapLimitFieldNumber                               = 160,
    //         kExploitRelaxationSolutionFieldNumber                      = 161,
    //         kUseProbingSearchFieldNumber                               = 176,
    //         kUseObjectiveLbSearchFieldNumber                           = 228,
    //         kOptimizeWithCoreFieldNumber                               = 83,
    //         kUseBranchingInLpFieldNumber                               = 139,
    //         kUseCombinedNoOverlapFieldNumber                           = 133,
    //         kPolishLpSolutionFieldNumber                               = 175,
    //         kNewLinearPropagationFieldNumber                           = 224,
    //         kAddObjectiveCutFieldNumber                                = 197,
    //         kRepairHintFieldNumber                                     = 167,
    //         kFixVariablesToTheirHintedValueFieldNumber                 = 192,
    //         kExploitBestSolutionFieldNumber                            = 130,
    //         kExploitAllPrecedencesFieldNumber                          = 220,
    //         kUseTimetablingInNoOverlap2DFieldNumber                    = 200,
    //         kUseEnergeticReasoningInNoOverlap2DFieldNumber             = 213,
    //         kOnlyAddCutsAtLevelZeroFieldNumber                         = 92,
    //         kExpandAlldiffConstraintsFieldNumber                       = 170,
    //         kDisableConstraintExpansionFieldNumber                     = 181,
    //         kEncodeComplexLinearConstraintWithIntegerFieldNumber       = 223,
    //         kPresolveExtractIntegerEnforcementFieldNumber              = 174,
    //         kNumWorkersFieldNumber                                     = 206,
    //         kMipScaleLargeDomainFieldNumber                            = 225,
    //         kOnlySolveIpFieldNumber                                    = 222,
    //         kInitialPolarityFieldNumber                                = 2,
    //         kMinimizationAlgorithmFieldNumber                          = 4,
    //         kVariableActivityDecayFieldNumber                          = 15,
    //         kMaxVariableActivityValueFieldNumber                       = 16,
    //         kClauseActivityDecayFieldNumber                            = 17,
    //         kClauseCleanupPeriodFieldNumber                            = 11,
    //         kGlucoseDecayIncrementPeriodFieldNumber                    = 24,
    //         kMaxClauseActivityValueFieldNumber                         = 18,
    //         kGlucoseMaxDecayFieldNumber                                = 22,
    //         kGlucoseDecayIncrementFieldNumber                          = 23,
    //         kRestartPeriodFieldNumber                                  = 30,
    //         kRandomSeedFieldNumber                                     = 31,
    //         kMaxTimeInSecondsFieldNumber                               = 36,
    //         kMaxNumberOfConflictsFieldNumber                           = 37,
    //         kMaxMemoryInMbFieldNumber                                  = 40,
    //         kBinaryMinimizationAlgorithmFieldNumber                    = 34,
    //         kPbCleanupIncrementFieldNumber                             = 46,
    //         kPbCleanupRatioFieldNumber                                 = 47,
    //         kMaxSatStratificationFieldNumber                           = 53,
    //         kPresolveBveThresholdFieldNumber                           = 54,
    //         kPresolveProbingDeterministicTimeLimitFieldNumber          = 57,
    //         kPresolveBveClauseWeightFieldNumber                        = 55,
    //         kClauseCleanupLbdBoundFieldNumber                          = 59,
    //         kRestartDlAverageRatioFieldNumber                          = 63,
    //         kRestartRunningWindowSizeFieldNumber                       = 62,
    //         kUseOptimizationHintsFieldNumber                           = 35,
    //         kMinimizeCoreFieldNumber                                   = 50,
    //         kFindMultipleCoresFieldNumber                              = 84,
    //         kCoverOptimizationFieldNumber                              = 89,
    //         kBlockingRestartMultiplierFieldNumber                      = 66,
    //         kMaxDeterministicTimeFieldNumber                           = 67,
    //         kBlockingRestartWindowSizeFieldNumber                      = 65,
    //         kPresolveBvaThresholdFieldNumber                           = 73,
    //         kRestartLbdAverageRatioFieldNumber                         = 71,
    //         kCountAssumptionLevelsInLbdFieldNumber                     = 49,
    //         kPresolveBlockedClauseFieldNumber                          = 88,
    //         kPresolveUseBvaFieldNumber                                 = 72,
    //         kCpModelPresolveFieldNumber                                = 86,
    //         kLinearizationLevelFieldNumber                             = 90,
    //         kMaxNumCutsFieldNumber                                     = 91,
    //         kMinimizeWithPropagationRestartPeriodFieldNumber           = 96,
    //         kMinimizeWithPropagationNumDecisionsFieldNumber            = 97,
    //         kBinarySearchNumConflictsFieldNumber                       = 99,
    //         kBooleanEncodingLevelFieldNumber                           = 107,
    //         kCpModelProbingLevelFieldNumber                            = 110,
    //         kMinOrthogonalityForLpConstraintsFieldNumber               = 115,
    //         kAddLpConstraintsLazilyFieldNumber                         = 112,
    //         kExploitIntegerLpSolutionFieldNumber                       = 94,
    //         kExploitAllLpSolutionFieldNumber                           = 116,
    //         kExploitObjectiveFieldNumber                               = 131,
    //         kUsePhaseSavingFieldNumber                                 = 44,
    //         kSubsumptionDuringConflictAnalysisFieldNumber              = 56,
    //         kLogSubsolverStatisticsFieldNumber                         = 189,
    //         kLogToStdoutFieldNumber                                    = 186,
    //         kMaxIntegerRoundingScalingFieldNumber                      = 119,
    //         kMaxConsecutiveInactiveCountFieldNumber                    = 121,
    //         kUsePrecedencesInDisjunctiveConstraintFieldNumber          = 74,
    //         kUseDisjunctiveConstraintInCumulativeFieldNumber           = 80,
    //         kUseDualSchedulingHeuristicsFieldNumber                    = 214,
    //         kAddCgCutsFieldNumber                                      = 117,
    //         kNewConstraintsBatchSizeFieldNumber                        = 122,
    //         kPseudoCostReliabilityThresholdFieldNumber                 = 123,
    //         kMipMaxBoundFieldNumber                                    = 124,
    //         kMipVarScalingFieldNumber                                  = 125,
    //         kMipWantedPrecisionFieldNumber                             = 126,
    //         kMipCheckPrecisionFieldNumber                              = 128,
    //         kMipMaxActivityExponentFieldNumber                         = 127,
    //         kUseShavingInProbingSearchFieldNumber                      = 204,
    //         kInstantiateAllVariablesFieldNumber                        = 106,
    //         kAutoDetectGreaterThanAtLeastOneOfFieldNumber              = 95,
    //         kUseRinsLnsFieldNumber                                     = 129,
    //         kMaxPresolveIterationsFieldNumber                          = 138,
    //         kUseFeasibilityPumpFieldNumber                             = 164,
    //         kUseExactLpReasonFieldNumber                               = 109,
    //         kCatchSigintSignalFieldNumber                              = 135,
    //         kUseImpliedBoundsFieldNumber                               = 144,
    //         kMergeNoOverlapWorkLimitFieldNumber                        = 145,
    //         kMergeAtMostOneWorkLimitFieldNumber                        = 146,
    //         kPresolveSubstitutionLevelFieldNumber                      = 147,
    //         kMaxAllDiffCutSizeFieldNumber                              = 148,
    //         kHintConflictLimitFieldNumber                              = 153,
    //         kAddMirCutsFieldNumber                                     = 120,
    //         kAddZeroHalfCutsFieldNumber                                = 169,
    //         kAddCliqueCutsFieldNumber                                  = 172,
    //         kAddLinMaxCutsFieldNumber                                  = 152,
    //         kCutMaxActiveCountValueFieldNumber                         = 155,
    //         kMaxCutRoundsAtLevelZeroFieldNumber                        = 154,
    //         kCutCleanupTargetFieldNumber                               = 157,
    //         kCutActiveCountDecayFieldNumber                            = 156,
    //         kAbsoluteGapLimitFieldNumber                               = 159,
    //         kFpRoundingFieldNumber                                     = 165,
    //         kFindBigLinearOverlapFieldNumber                           = 234,
    //         kShareObjectiveBoundsFieldNumber                           = 113,
    //         kShareLevelZeroBoundsFieldNumber                           = 114,
    //         kShareBinaryClausesFieldNumber                             = 203,
    //         kPolarityRephaseIncrementFieldNumber                       = 168,
    //         kCpModelUseSatPresolveFieldNumber                          = 93,
    //         kExpandReservoirConstraintsFieldNumber                     = 182,
    //         kIgnoreNamesFieldNumber                                    = 202,
    //         kInferAllDiffsFieldNumber                                  = 233,
    //         kConvertIntervalsFieldNumber                               = 177,
    //         kMipAutomaticallyScaleVariablesFieldNumber                 = 166,
    //         kMipComputeTrueObjectiveBoundFieldNumber                   = 198,
    //         kSymmetryLevelFieldNumber                                  = 183,
    //         kClauseCleanupRatioFieldNumber                             = 190,
    //         kMaxDomainSizeWhenEncodingEqNeqConstraintsFieldNumber      = 191,
    //         kSolutionPoolSizeFieldNumber                               = 193,
    //         kMipMaxValidMagnitudeFieldNumber                           = 199,
    //         kPresolveInclusionWorkLimitFieldNumber                     = 201,
    //         kCutLevelFieldNumber                                       = 196,
    //         kMinNumLnsWorkersFieldNumber                               = 211,
    //         kShavingSearchDeterministicTimeFieldNumber                 = 205,
    //         kLogFrequencyInSecondsFieldNumber                          = 212,
    //         kModelReductionLogFrequencyInSecondsFieldNumber            = 218,
    //         kPropagationLoopDetectionFactorFieldNumber                 = 221,
    //         kTableCompressionLevelFieldNumber                          = 217,
    //         kRootLpIterationsFieldNumber                               = 227,
    //         kProbingDeterministicTimeLimitFieldNumber                  = 226,
    //         kMaxSizeToCreatePrecedenceLiteralsInDisjunctiveFieldNumber = 229,
    //         kObjectiveLnsMinSizeFieldNumber                            = 231,
    //         kMipDropToleranceFieldNumber                               = 232,
    //     };
    //     // repeated .operations_research.sat.SatParameters.RestartAlgorithm restart_algorithms = 61;
    //     int restart_algorithms_size() const;

    // private:
    //     int _internal_restart_algorithms_size() const;

    // public:
    //     void clear_restart_algorithms();

    // private:
    //     ::operations_research::sat::SatParameters_RestartAlgorithm _internal_restart_algorithms( int index ) const;
    //     void                                                       _internal_add_restart_algorithms( ::operations_research::sat::SatParameters_RestartAlgorithm value );
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedField< int >*             _internal_mutable_restart_algorithms();

    // public:
    //     ::operations_research::sat::SatParameters_RestartAlgorithm restart_algorithms( int index ) const;
    //     void                                                       set_restart_algorithms( int index, ::operations_research::sat::SatParameters_RestartAlgorithm value );
    //     void                                                       add_restart_algorithms( ::operations_research::sat::SatParameters_RestartAlgorithm value );
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int >&       restart_algorithms() const;
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedField< int >*             mutable_restart_algorithms();

    //     // repeated string subsolvers = 207;
    //     int subsolvers_size() const;

    // private:
    //     int _internal_subsolvers_size() const;

    // public:
    //     void                                                            clear_subsolvers();
    //     const std::string&                                              subsolvers( int index ) const;
    //     std::string*                                                    mutable_subsolvers( int index );
    //     void                                                            set_subsolvers( int index, const std::string& value );
    //     void                                                            set_subsolvers( int index, std::string&& value );
    //     void                                                            set_subsolvers( int index, const char* value );
    //     void                                                            set_subsolvers( int index, const char* value, size_t size );
    //     std::string*                                                    add_subsolvers();
    //     void                                                            add_subsolvers( const std::string& value );
    //     void                                                            add_subsolvers( std::string&& value );
    //     void                                                            add_subsolvers( const char* value );
    //     void                                                            add_subsolvers( const char* value, size_t size );
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< std::string >& subsolvers() const;
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< std::string >*       mutable_subsolvers();

    // private:
    //     const std::string& _internal_subsolvers( int index ) const;
    //     std::string*       _internal_add_subsolvers();

    // public:
    //     // repeated string ignore_subsolvers = 209;
    //     int ignore_subsolvers_size() const;

    // private:
    //     int _internal_ignore_subsolvers_size() const;

    // public:
    //     void                                                            clear_ignore_subsolvers();
    //     const std::string&                                              ignore_subsolvers( int index ) const;
    //     std::string*                                                    mutable_ignore_subsolvers( int index );
    //     void                                                            set_ignore_subsolvers( int index, const std::string& value );
    //     void                                                            set_ignore_subsolvers( int index, std::string&& value );
    //     void                                                            set_ignore_subsolvers( int index, const char* value );
    //     void                                                            set_ignore_subsolvers( int index, const char* value, size_t size );
    //     std::string*                                                    add_ignore_subsolvers();
    //     void                                                            add_ignore_subsolvers( const std::string& value );
    //     void                                                            add_ignore_subsolvers( std::string&& value );
    //     void                                                            add_ignore_subsolvers( const char* value );
    //     void                                                            add_ignore_subsolvers( const char* value, size_t size );
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< std::string >& ignore_subsolvers() const;
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< std::string >*       mutable_ignore_subsolvers();

    // private:
    //     const std::string& _internal_ignore_subsolvers( int index ) const;
    //     std::string*       _internal_add_ignore_subsolvers();

    // public:
    //     // repeated .operations_research.sat.SatParameters subsolver_params = 210;
    //     int subsolver_params_size() const;

    // private:
    //     int _internal_subsolver_params_size() const;

    // public:
    //     void                                       clear_subsolver_params();
    //     ::operations_research::sat::SatParameters* mutable_subsolver_params( int index );
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::SatParameters >*
    //     mutable_subsolver_params();

    // private:
    //     const ::operations_research::sat::SatParameters& _internal_subsolver_params( int index ) const;
    //     ::operations_research::sat::SatParameters*       _internal_add_subsolver_params();

    // public:
    //     const ::operations_research::sat::SatParameters& subsolver_params( int index ) const;
    //     ::operations_research::sat::SatParameters*       add_subsolver_params();
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::SatParameters >&
    //     subsolver_params() const;

    //     // repeated string extra_subsolvers = 219;
    //     int extra_subsolvers_size() const;

    // private:
    //     int _internal_extra_subsolvers_size() const;

    // public:
    //     void                                                            clear_extra_subsolvers();
    //     const std::string&                                              extra_subsolvers( int index ) const;
    //     std::string*                                                    mutable_extra_subsolvers( int index );
    //     void                                                            set_extra_subsolvers( int index, const std::string& value );
    //     void                                                            set_extra_subsolvers( int index, std::string&& value );
    //     void                                                            set_extra_subsolvers( int index, const char* value );
    //     void                                                            set_extra_subsolvers( int index, const char* value, size_t size );
    //     std::string*                                                    add_extra_subsolvers();
    //     void                                                            add_extra_subsolvers( const std::string& value );
    //     void                                                            add_extra_subsolvers( std::string&& value );
    //     void                                                            add_extra_subsolvers( const char* value );
    //     void                                                            add_extra_subsolvers( const char* value, size_t size );
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< std::string >& extra_subsolvers() const;
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< std::string >*       mutable_extra_subsolvers();

    // private:
    //     const std::string& _internal_extra_subsolvers( int index ) const;
    //     std::string*       _internal_add_extra_subsolvers();

    // public:
    //     // optional string default_restart_algorithms = 70 [default = "LUBY_RESTART,LBD_MOVING_AVERAGE_RESTART,DL_MOVING_AVERAGE_RESTART"];
    //     bool has_default_restart_algorithms() const;

    // private:
    //     bool _internal_has_default_restart_algorithms() const;

    // public:
    //     void               clear_default_restart_algorithms();
    //     const std::string& default_restart_algorithms() const;
    //     template < typename ArgT0 = const std::string&, typename... ArgT >
    //     void               set_default_restart_algorithms( ArgT0&& arg0, ArgT... args );
    //     std::string*       mutable_default_restart_algorithms();
    //     PROTOBUF_NODISCARD std::string* release_default_restart_algorithms();
    //     void                            set_allocated_default_restart_algorithms( std::string* default_restart_algorithms );

    // private:
    //     const std::string&                 _internal_default_restart_algorithms() const;
    //     inline PROTOBUF_ALWAYS_INLINE void _internal_set_default_restart_algorithms( const std::string& value );
    //     std::string*                       _internal_mutable_default_restart_algorithms();

    // public:
    //     // optional string name = 171 [default = ""];
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
    //     // optional string log_prefix = 185 [default = ""];
    //     bool has_log_prefix() const;

    // private:
    //     bool _internal_has_log_prefix() const;

    // public:
    //     void               clear_log_prefix();
    //     const std::string& log_prefix() const;
    //     template < typename ArgT0 = const std::string&, typename... ArgT >
    //     void               set_log_prefix( ArgT0&& arg0, ArgT... args );
    //     std::string*       mutable_log_prefix();
    //     PROTOBUF_NODISCARD std::string* release_log_prefix();
    //     void                            set_allocated_log_prefix( std::string* log_prefix );

    // private:
    //     const std::string&                 _internal_log_prefix() const;
    //     inline PROTOBUF_ALWAYS_INLINE void _internal_set_log_prefix( const std::string& value );
    //     std::string*                       _internal_mutable_log_prefix();

    // public:
    //     // optional .operations_research.sat.SatParameters.VariableOrder preferred_variable_order = 1 [default = IN_ORDER];
    //     bool has_preferred_variable_order() const;

    // private:
    //     bool _internal_has_preferred_variable_order() const;

    // public:
    //     void                                                    clear_preferred_variable_order();
    //     ::operations_research::sat::SatParameters_VariableOrder preferred_variable_order() const;
    //     void                                                    set_preferred_variable_order( ::operations_research::sat::SatParameters_VariableOrder value );

    // private:
    //     ::operations_research::sat::SatParameters_VariableOrder _internal_preferred_variable_order() const;
    //     void                                                    _internal_set_preferred_variable_order( ::operations_research::sat::SatParameters_VariableOrder value );

    // public:
    //     // optional int32 clause_cleanup_target = 13 [default = 0];
    //     bool has_clause_cleanup_target() const;

    // private:
    //     bool _internal_has_clause_cleanup_target() const;

    // public:
    //     void    clear_clause_cleanup_target();
    //     int32_t clause_cleanup_target() const;
    //     void    set_clause_cleanup_target( int32_t value );

    // private:
    //     int32_t _internal_clause_cleanup_target() const;
    //     void    _internal_set_clause_cleanup_target( int32_t value );

    // public:
    //     // optional double random_branches_ratio = 32 [default = 0];
    //     bool has_random_branches_ratio() const;

    // private:
    //     bool _internal_has_random_branches_ratio() const;

    // public:
    //     void   clear_random_branches_ratio();
    //     double random_branches_ratio() const;
    //     void   set_random_branches_ratio( double value );

    // private:
    //     double _internal_random_branches_ratio() const;
    //     void   _internal_set_random_branches_ratio( double value );

    // public:
    //     // optional double random_polarity_ratio = 45 [default = 0];
    //     bool has_random_polarity_ratio() const;

    // private:
    //     bool _internal_has_random_polarity_ratio() const;

    // public:
    //     void   clear_random_polarity_ratio();
    //     double random_polarity_ratio() const;
    //     void   set_random_polarity_ratio( double value );

    // private:
    //     double _internal_random_polarity_ratio() const;
    //     void   _internal_set_random_polarity_ratio( double value );

    // public:
    //     // optional .operations_research.sat.SatParameters.MaxSatAssumptionOrder max_sat_assumption_order = 51 [default = DEFAULT_ASSUMPTION_ORDER];
    //     bool has_max_sat_assumption_order() const;

    // private:
    //     bool _internal_has_max_sat_assumption_order() const;

    // public:
    //     void                                                            clear_max_sat_assumption_order();
    //     ::operations_research::sat::SatParameters_MaxSatAssumptionOrder max_sat_assumption_order() const;
    //     void                                                            set_max_sat_assumption_order( ::operations_research::sat::SatParameters_MaxSatAssumptionOrder value );

    // private:
    //     ::operations_research::sat::SatParameters_MaxSatAssumptionOrder _internal_max_sat_assumption_order() const;
    //     void                                                            _internal_set_max_sat_assumption_order( ::operations_research::sat::SatParameters_MaxSatAssumptionOrder value );

    // public:
    //     // optional .operations_research.sat.SatParameters.ClauseProtection clause_cleanup_protection = 58 [default = PROTECTION_NONE];
    //     bool has_clause_cleanup_protection() const;

    // private:
    //     bool _internal_has_clause_cleanup_protection() const;

    // public:
    //     void                                                       clear_clause_cleanup_protection();
    //     ::operations_research::sat::SatParameters_ClauseProtection clause_cleanup_protection() const;
    //     void                                                       set_clause_cleanup_protection( ::operations_research::sat::SatParameters_ClauseProtection value );

    // private:
    //     ::operations_research::sat::SatParameters_ClauseProtection _internal_clause_cleanup_protection() const;
    //     void                                                       _internal_set_clause_cleanup_protection( ::operations_research::sat::SatParameters_ClauseProtection value );

    // public:
    //     // optional .operations_research.sat.SatParameters.ClauseOrdering clause_cleanup_ordering = 60 [default = CLAUSE_ACTIVITY];
    //     bool has_clause_cleanup_ordering() const;

    // private:
    //     bool _internal_has_clause_cleanup_ordering() const;

    // public:
    //     void                                                     clear_clause_cleanup_ordering();
    //     ::operations_research::sat::SatParameters_ClauseOrdering clause_cleanup_ordering() const;
    //     void                                                     set_clause_cleanup_ordering( ::operations_research::sat::SatParameters_ClauseOrdering value );

    // private:
    //     ::operations_research::sat::SatParameters_ClauseOrdering _internal_clause_cleanup_ordering() const;
    //     void                                                     _internal_set_clause_cleanup_ordering( ::operations_research::sat::SatParameters_ClauseOrdering value );

    // public:
    //     // optional int32 num_conflicts_before_strategy_changes = 68 [default = 0];
    //     bool has_num_conflicts_before_strategy_changes() const;

    // private:
    //     bool _internal_has_num_conflicts_before_strategy_changes() const;

    // public:
    //     void    clear_num_conflicts_before_strategy_changes();
    //     int32_t num_conflicts_before_strategy_changes() const;
    //     void    set_num_conflicts_before_strategy_changes( int32_t value );

    // private:
    //     int32_t _internal_num_conflicts_before_strategy_changes() const;
    //     void    _internal_set_num_conflicts_before_strategy_changes( int32_t value );

    // public:
    //     // optional double strategy_change_increase_ratio = 69 [default = 0];
    //     bool has_strategy_change_increase_ratio() const;

    // private:
    //     bool _internal_has_strategy_change_increase_ratio() const;

    // public:
    //     void   clear_strategy_change_increase_ratio();
    //     double strategy_change_increase_ratio() const;
    //     void   set_strategy_change_increase_ratio( double value );

    // private:
    //     double _internal_strategy_change_increase_ratio() const;
    //     void   _internal_set_strategy_change_increase_ratio( double value );

    // public:
    //     // optional double initial_variables_activity = 76 [default = 0];
    //     bool has_initial_variables_activity() const;

    // private:
    //     bool _internal_has_initial_variables_activity() const;

    // public:
    //     void   clear_initial_variables_activity();
    //     double initial_variables_activity() const;
    //     void   set_initial_variables_activity( double value );

    // private:
    //     double _internal_initial_variables_activity() const;
    //     void   _internal_set_initial_variables_activity( double value );

    // public:
    //     // optional .operations_research.sat.SatParameters.SearchBranching search_branching = 82 [default = AUTOMATIC_SEARCH];
    //     bool has_search_branching() const;

    // private:
    //     bool _internal_has_search_branching() const;

    // public:
    //     void                                                      clear_search_branching();
    //     ::operations_research::sat::SatParameters_SearchBranching search_branching() const;
    //     void                                                      set_search_branching( ::operations_research::sat::SatParameters_SearchBranching value );


    // public:
    //     // optional bool use_erwa_heuristic = 75 [default = false];
    //     bool has_use_erwa_heuristic() const;

    // private:
    //     bool _internal_has_use_erwa_heuristic() const;

    // public:
    //     void clear_use_erwa_heuristic();
    //     bool use_erwa_heuristic() const;
    //     void set_use_erwa_heuristic( bool value );

    // private:
    //     bool _internal_use_erwa_heuristic() const;
    //     void _internal_set_use_erwa_heuristic( bool value );

    // public:
    //     // optional bool also_bump_variables_in_conflict_reasons = 77 [default = false];
    //     bool has_also_bump_variables_in_conflict_reasons() const;

    // private:
    //     bool _internal_has_also_bump_variables_in_conflict_reasons() const;

    // public:
    //     void clear_also_bump_variables_in_conflict_reasons();
    //     bool also_bump_variables_in_conflict_reasons() const;
    //     void set_also_bump_variables_in_conflict_reasons( bool value );

    // private:
    //     bool _internal_also_bump_variables_in_conflict_reasons() const;
    //     void _internal_set_also_bump_variables_in_conflict_reasons( bool value );

    // public:
    //     // optional bool use_blocking_restart = 64 [default = false];
    //     bool has_use_blocking_restart() const;

    // private:
    //     bool _internal_has_use_blocking_restart() const;

    // public:
    //     void clear_use_blocking_restart();
    //     bool use_blocking_restart() const;
    //     void set_use_blocking_restart( bool value );

    // private:
    //     bool _internal_use_blocking_restart() const;
    //     void _internal_set_use_blocking_restart( bool value );

    // public:
    //     // optional bool permute_variable_randomly = 178 [default = false];
    //     bool has_permute_variable_randomly() const;

    // private:
    //     bool _internal_has_permute_variable_randomly() const;

    // public:
    //     void clear_permute_variable_randomly();
    //     bool permute_variable_randomly() const;
    //     void set_permute_variable_randomly( bool value );

    // private:
    //     bool _internal_permute_variable_randomly() const;
    //     void _internal_set_permute_variable_randomly( bool value );

    // public:
    //     // optional int64 search_randomization_tolerance = 104 [default = 0];
    //     bool has_search_randomization_tolerance() const;

    // private:
    //     bool _internal_has_search_randomization_tolerance() const;

    // public:
    //     void    clear_search_randomization_tolerance();
    //     int64_t search_randomization_tolerance() const;
    //     void    set_search_randomization_tolerance( int64_t value );

    // private:
    //     int64_t _internal_search_randomization_tolerance() const;
    //     void    _internal_set_search_randomization_tolerance( int64_t value );

    // public:
    //     // optional int32 num_search_workers = 100 [default = 0];
    //     bool has_num_search_workers() const;

    // private:
    //     bool _internal_has_num_search_workers() const;

    // public:
    //     void    clear_num_search_workers();
    //     int32_t num_search_workers() const;
    //     void    set_num_search_workers( int32_t value );

    // private:
    //     int32_t _internal_num_search_workers() const;
    //     void    _internal_set_num_search_workers( int32_t value );

    // public:
    //     // optional bool use_lns_only = 101 [default = false];
    //     bool has_use_lns_only() const;

    // private:
    //     bool _internal_has_use_lns_only() const;

    // public:
    //     void clear_use_lns_only();
    //     bool use_lns_only() const;
    //     void set_use_lns_only( bool value );

    // private:
    //     bool _internal_use_lns_only() const;
    //     void _internal_set_use_lns_only( bool value );

    // public:
    //     // optional bool diversify_lns_params = 137 [default = false];
    //     bool has_diversify_lns_params() const;

    // private:
    //     bool _internal_has_diversify_lns_params() const;

    // public:
    //     void clear_diversify_lns_params();
    //     bool diversify_lns_params() const;
    //     void set_diversify_lns_params( bool value );

    // private:
    //     bool _internal_diversify_lns_params() const;
    //     void _internal_set_diversify_lns_params( bool value );

    // public:
    //     // optional bool randomize_search = 103 [default = false];
    //     bool has_randomize_search() const;

    // private:
    //     bool _internal_has_randomize_search() const;

    // public:
    //     void clear_randomize_search();
    //     bool randomize_search() const;
    //     void set_randomize_search( bool value );

    // private:
    //     bool _internal_randomize_search() const;
    //     void _internal_set_randomize_search( bool value );

    // public:
    //     // optional bool use_optional_variables = 108 [default = false];
    //     bool has_use_optional_variables() const;

    // private:
    //     bool _internal_has_use_optional_variables() const;

    // public:
    //     void clear_use_optional_variables();
    //     bool use_optional_variables() const;
    //     void set_use_optional_variables( bool value );

    // private:
    //     bool _internal_use_optional_variables() const;
    //     void _internal_set_use_optional_variables( bool value );

    // public:
    //     // optional bool use_pb_resolution = 43 [default = false];
    //     bool has_use_pb_resolution() const;

    // private:
    //     bool _internal_has_use_pb_resolution() const;

    // public:
    //     void clear_use_pb_resolution();
    //     bool use_pb_resolution() const;
    //     void set_use_pb_resolution( bool value );

    // private:
    //     bool _internal_use_pb_resolution() const;
    //     void _internal_set_use_pb_resolution( bool value );

    // public:
    //     // optional bool minimize_reduction_during_pb_resolution = 48 [default = false];
    //     bool has_minimize_reduction_during_pb_resolution() const;

    // private:
    //     bool _internal_has_minimize_reduction_during_pb_resolution() const;

    // public:
    //     void clear_minimize_reduction_during_pb_resolution();
    //     bool minimize_reduction_during_pb_resolution() const;
    //     void set_minimize_reduction_during_pb_resolution( bool value );

    // private:
    //     bool _internal_minimize_reduction_during_pb_resolution() const;
    //     void _internal_set_minimize_reduction_during_pb_resolution( bool value );

    // public:
    //     // optional bool use_sat_inprocessing = 163 [default = false];
    //     bool has_use_sat_inprocessing() const;

    // private:
    //     bool _internal_has_use_sat_inprocessing() const;

    // public:
    //     void clear_use_sat_inprocessing();
    //     bool use_sat_inprocessing() const;
    //     void set_use_sat_inprocessing( bool value );

    // private:
    //     bool _internal_use_sat_inprocessing() const;
    //     void _internal_set_use_sat_inprocessing( bool value );

    // public:
    //     // optional bool detect_table_with_cost = 216 [default = false];
    //     bool has_detect_table_with_cost() const;

    // private:
    //     bool _internal_has_detect_table_with_cost() const;

    // public:
    //     void clear_detect_table_with_cost();
    //     bool detect_table_with_cost() const;
    //     void set_detect_table_with_cost( bool value );

    // private:
    //     bool _internal_detect_table_with_cost() const;
    //     void _internal_set_detect_table_with_cost( bool value );

    // public:
    //     // optional bool optimize_with_lb_tree_search = 188 [default = false];
    //     bool has_optimize_with_lb_tree_search() const;

    // private:
    //     bool _internal_has_optimize_with_lb_tree_search() const;

    // public:
    //     void clear_optimize_with_lb_tree_search();
    //     bool optimize_with_lb_tree_search() const;
    //     void set_optimize_with_lb_tree_search( bool value );

    // private:
    //     bool _internal_optimize_with_lb_tree_search() const;
    //     void _internal_set_optimize_with_lb_tree_search( bool value );

    // public:
    //     // optional bool optimize_with_max_hs = 85 [default = false];
    //     bool has_optimize_with_max_hs() const;

    // private:
    //     bool _internal_has_optimize_with_max_hs() const;

    // public:
    //     void clear_optimize_with_max_hs();
    //     bool optimize_with_max_hs() const;
    //     void set_optimize_with_max_hs( bool value );

    // private:
    //     bool _internal_optimize_with_max_hs() const;
    //     void _internal_set_optimize_with_max_hs( bool value );

    // public:
    //     // optional bool enumerate_all_solutions = 87 [default = false];
    //     bool has_enumerate_all_solutions() const;

    // private:
    //     bool _internal_has_enumerate_all_solutions() const;

    // public:
    //     void clear_enumerate_all_solutions();
    //     bool enumerate_all_solutions() const;
    //     void set_enumerate_all_solutions( bool value );

    // private:
    //     bool _internal_enumerate_all_solutions() const;
    //     void _internal_set_enumerate_all_solutions( bool value );

    // public:
    //     // optional bool keep_all_feasible_solutions_in_presolve = 173 [default = false];
    //     bool has_keep_all_feasible_solutions_in_presolve() const;

    // private:
    //     bool _internal_has_keep_all_feasible_solutions_in_presolve() const;

    // public:
    //     void clear_keep_all_feasible_solutions_in_presolve();
    //     bool keep_all_feasible_solutions_in_presolve() const;
    //     void set_keep_all_feasible_solutions_in_presolve( bool value );

    // private:
    //     bool _internal_keep_all_feasible_solutions_in_presolve() const;
    //     void _internal_set_keep_all_feasible_solutions_in_presolve( bool value );

    // public:
    //     // optional int32 interleave_batch_size = 134 [default = 0];
    //     bool has_interleave_batch_size() const;

    // private:
    //     bool _internal_has_interleave_batch_size() const;

    // public:
    //     void    clear_interleave_batch_size();
    //     int32_t interleave_batch_size() const;
    //     void    set_interleave_batch_size( int32_t value );

    // private:
    //     int32_t _internal_interleave_batch_size() const;
    //     void    _internal_set_interleave_batch_size( int32_t value );

    // public:
    //     // optional bool interleave_search = 136 [default = false];
    //     bool has_interleave_search() const;

    // private:
    //     bool _internal_has_interleave_search() const;

    // public:
    //     void clear_interleave_search();
    //     bool interleave_search() const;
    //     void set_interleave_search( bool value );

    // private:
    //     bool _internal_interleave_search() const;
    //     void _internal_set_interleave_search( bool value );

    // public:
    //     // optional bool debug_postsolve_with_full_solver = 162 [default = false];
    //     bool has_debug_postsolve_with_full_solver() const;

    // private:
    //     bool _internal_has_debug_postsolve_with_full_solver() const;

    // public:
    //     void clear_debug_postsolve_with_full_solver();
    //     bool debug_postsolve_with_full_solver() const;
    //     void set_debug_postsolve_with_full_solver( bool value );

    // private:
    //     bool _internal_debug_postsolve_with_full_solver() const;
    //     void _internal_set_debug_postsolve_with_full_solver( bool value );

    // public:
    //     // optional bool debug_crash_on_bad_hint = 195 [default = false];
    //     bool has_debug_crash_on_bad_hint() const;

    // private:
    //     bool _internal_has_debug_crash_on_bad_hint() const;

    // public:
    //     void clear_debug_crash_on_bad_hint();
    //     bool debug_crash_on_bad_hint() const;
    //     void set_debug_crash_on_bad_hint( bool value );

    // private:
    //     bool _internal_debug_crash_on_bad_hint() const;
    //     void _internal_set_debug_crash_on_bad_hint( bool value );

    // public:
    //     // optional bool max_sat_reverse_assumption_order = 52 [default = false];
    //     bool has_max_sat_reverse_assumption_order() const;

    // private:
    //     bool _internal_has_max_sat_reverse_assumption_order() const;

    // public:
    //     void clear_max_sat_reverse_assumption_order();
    //     bool max_sat_reverse_assumption_order() const;
    //     void set_max_sat_reverse_assumption_order( bool value );

    // private:
    //     bool _internal_max_sat_reverse_assumption_order() const;
    //     void _internal_set_max_sat_reverse_assumption_order( bool value );

    // public:
    //     // optional int64 probing_period_at_root = 142 [default = 0];
    //     bool has_probing_period_at_root() const;

    // private:
    //     bool _internal_has_probing_period_at_root() const;

    // public:
    //     void    clear_probing_period_at_root();
    //     int64_t probing_period_at_root() const;
    //     void    set_probing_period_at_root( int64_t value );

    // private:
    //     int64_t _internal_probing_period_at_root() const;
    //     void    _internal_set_probing_period_at_root( int64_t value );

    // public:
    //     // optional bool fill_tightened_domains_in_response = 132 [default = false];
    //     bool has_fill_tightened_domains_in_response() const;

    // private:
    //     bool _internal_has_fill_tightened_domains_in_response() const;

    // public:
    //     void clear_fill_tightened_domains_in_response();
    //     bool fill_tightened_domains_in_response() const;
    //     void set_fill_tightened_domains_in_response( bool value );

    // private:
    //     bool _internal_fill_tightened_domains_in_response() const;
    //     void _internal_set_fill_tightened_domains_in_response( bool value );

    // public:
    //     // optional bool fill_additional_solutions_in_response = 194 [default = false];
    //     bool has_fill_additional_solutions_in_response() const;

    // private:
    //     bool _internal_has_fill_additional_solutions_in_response() const;

    // public:
    //     void clear_fill_additional_solutions_in_response();
    //     bool fill_additional_solutions_in_response() const;
    //     void set_fill_additional_solutions_in_response( bool value );

    // private:
    //     bool _internal_fill_additional_solutions_in_response() const;
    //     void _internal_set_fill_additional_solutions_in_response( bool value );

    // public:
    //     // optional bool stop_after_first_solution = 98 [default = false];
    //     bool has_stop_after_first_solution() const;

    // private:
    //     bool _internal_has_stop_after_first_solution() const;

    // public:
    //     void clear_stop_after_first_solution();
    //     bool stop_after_first_solution() const;
    //     void set_stop_after_first_solution( bool value );

    // private:
    //     bool _internal_stop_after_first_solution() const;
    //     void _internal_set_stop_after_first_solution( bool value );

    // public:
    //     // optional bool stop_after_presolve = 149 [default = false];
    //     bool has_stop_after_presolve() const;

    // private:
    //     bool _internal_has_stop_after_presolve() const;

    // public:
    //     void clear_stop_after_presolve();
    //     bool stop_after_presolve() const;
    //     void set_stop_after_presolve( bool value );

    // private:
    //     bool _internal_stop_after_presolve() const;
    //     void _internal_set_stop_after_presolve( bool value );

    // public:
    //     // optional bool permute_presolve_constraint_order = 179 [default = false];
    //     bool has_permute_presolve_constraint_order() const;

    // private:
    //     bool _internal_has_permute_presolve_constraint_order() const;

    // public:
    //     void clear_permute_presolve_constraint_order();
    //     bool permute_presolve_constraint_order() const;
    //     void set_permute_presolve_constraint_order( bool value );

    // private:
    //     bool _internal_permute_presolve_constraint_order() const;
    //     void _internal_set_permute_presolve_constraint_order( bool value );

    // public:
    //     // optional bool use_absl_random = 180 [default = false];
    //     bool has_use_absl_random() const;

    // private:
    //     bool _internal_has_use_absl_random() const;

    // public:
    //     void clear_use_absl_random();
    //     bool use_absl_random() const;
    //     void set_use_absl_random( bool value );

    // private:
    //     bool _internal_use_absl_random() const;
    //     void _internal_set_use_absl_random( bool value );

    // public:
    //     // optional bool log_search_progress = 41 [default = false];
    //     bool has_log_search_progress() const;

    // private:
    //     bool _internal_has_log_search_progress() const;

    // public:
    //     void clear_log_search_progress();
    //     bool log_search_progress() const;
    //     void set_log_search_progress( bool value );
    set_log_search_progress(value: boolean): void;


    // public:
    //     // optional bool log_to_response = 187 [default = false];
    //     bool has_log_to_response() const;

    // private:
    //     bool _internal_has_log_to_response() const;

    // public:
    //     void clear_log_to_response();
    //     bool log_to_response() const;
    //     void set_log_to_response( bool value );

    // private:
    //     bool _internal_log_to_response() const;
    //     void _internal_set_log_to_response( bool value );

    // public:
    //     // optional bool use_strong_propagation_in_disjunctive = 230 [default = false];
    //     bool has_use_strong_propagation_in_disjunctive() const;

    // private:
    //     bool _internal_has_use_strong_propagation_in_disjunctive() const;

    // public:
    //     void clear_use_strong_propagation_in_disjunctive();
    //     bool use_strong_propagation_in_disjunctive() const;
    //     void set_use_strong_propagation_in_disjunctive( bool value );

    // private:
    //     bool _internal_use_strong_propagation_in_disjunctive() const;
    //     void _internal_set_use_strong_propagation_in_disjunctive( bool value );

    // public:
    //     // optional bool use_overload_checker_in_cumulative = 78 [default = false];
    //     bool has_use_overload_checker_in_cumulative() const;

    // private:
    //     bool _internal_has_use_overload_checker_in_cumulative() const;

    // public:
    //     void clear_use_overload_checker_in_cumulative();
    //     bool use_overload_checker_in_cumulative() const;
    //     void set_use_overload_checker_in_cumulative( bool value );

    // private:
    //     bool _internal_use_overload_checker_in_cumulative() const;
    //     void _internal_set_use_overload_checker_in_cumulative( bool value );

    // public:
    //     // optional bool use_timetable_edge_finding_in_cumulative = 79 [default = false];
    //     bool has_use_timetable_edge_finding_in_cumulative() const;

    // private:
    //     bool _internal_has_use_timetable_edge_finding_in_cumulative() const;

    // public:
    //     void clear_use_timetable_edge_finding_in_cumulative();
    //     bool use_timetable_edge_finding_in_cumulative() const;
    //     void set_use_timetable_edge_finding_in_cumulative( bool value );

    // private:
    //     bool _internal_use_timetable_edge_finding_in_cumulative() const;
    //     void _internal_set_use_timetable_edge_finding_in_cumulative( bool value );

    // public:
    //     // optional bool use_hard_precedences_in_cumulative = 215 [default = false];
    //     bool has_use_hard_precedences_in_cumulative() const;

    // private:
    //     bool _internal_has_use_hard_precedences_in_cumulative() const;

    // public:
    //     void clear_use_hard_precedences_in_cumulative();
    //     bool use_hard_precedences_in_cumulative() const;
    //     void set_use_hard_precedences_in_cumulative( bool value );

    // private:
    //     bool _internal_use_hard_precedences_in_cumulative() const;
    //     void _internal_set_use_hard_precedences_in_cumulative( bool value );

    // public:
    //     // optional int32 debug_max_num_presolve_operations = 151 [default = 0];
    //     bool has_debug_max_num_presolve_operations() const;

    // private:
    //     bool _internal_has_debug_max_num_presolve_operations() const;

    // public:
    //     void    clear_debug_max_num_presolve_operations();
    //     int32_t debug_max_num_presolve_operations() const;
    //     void    set_debug_max_num_presolve_operations( int32_t value );

    // private:
    //     int32_t _internal_debug_max_num_presolve_operations() const;
    //     void    _internal_set_debug_max_num_presolve_operations( int32_t value );

    // public:
    //     // optional double relative_gap_limit = 160 [default = 0];
    //     bool has_relative_gap_limit() const;

    // private:
    //     bool _internal_has_relative_gap_limit() const;

    // public:
    //     void   clear_relative_gap_limit();
    //     double relative_gap_limit() const;
    //     void   set_relative_gap_limit( double value );

    // private:
    //     double _internal_relative_gap_limit() const;
    //     void   _internal_set_relative_gap_limit( double value );

    // public:
    //     // optional bool exploit_relaxation_solution = 161 [default = false];
    //     bool has_exploit_relaxation_solution() const;

    // private:
    //     bool _internal_has_exploit_relaxation_solution() const;

    // public:
    //     void clear_exploit_relaxation_solution();
    //     bool exploit_relaxation_solution() const;
    //     void set_exploit_relaxation_solution( bool value );

    // private:
    //     bool _internal_exploit_relaxation_solution() const;
    //     void _internal_set_exploit_relaxation_solution( bool value );

    // public:
    //     // optional bool use_probing_search = 176 [default = false];
    //     bool has_use_probing_search() const;

    // private:
    //     bool _internal_has_use_probing_search() const;

    // public:
    //     void clear_use_probing_search();
    //     bool use_probing_search() const;
    //     void set_use_probing_search( bool value );

    // private:
    //     bool _internal_use_probing_search() const;
    //     void _internal_set_use_probing_search( bool value );

    // public:
    //     // optional bool use_objective_lb_search = 228 [default = false];
    //     bool has_use_objective_lb_search() const;

    // private:
    //     bool _internal_has_use_objective_lb_search() const;

    // public:
    //     void clear_use_objective_lb_search();
    //     bool use_objective_lb_search() const;
    //     void set_use_objective_lb_search( bool value );

    // private:
    //     bool _internal_use_objective_lb_search() const;
    //     void _internal_set_use_objective_lb_search( bool value );

    // public:
    //     // optional bool optimize_with_core = 83 [default = false];
    //     bool has_optimize_with_core() const;

    // private:
    //     bool _internal_has_optimize_with_core() const;

    // public:
    //     void clear_optimize_with_core();
    //     bool optimize_with_core() const;
    //     void set_optimize_with_core( bool value );

    // private:
    //     bool _internal_optimize_with_core() const;
    //     void _internal_set_optimize_with_core( bool value );

    // public:
    //     // optional bool use_branching_in_lp = 139 [default = false];
    //     bool has_use_branching_in_lp() const;

    // private:
    //     bool _internal_has_use_branching_in_lp() const;

    // public:
    //     void clear_use_branching_in_lp();
    //     bool use_branching_in_lp() const;
    //     void set_use_branching_in_lp( bool value );

    // private:
    //     bool _internal_use_branching_in_lp() const;
    //     void _internal_set_use_branching_in_lp( bool value );

    // public:
    //     // optional bool use_combined_no_overlap = 133 [default = false];
    //     bool has_use_combined_no_overlap() const;

    // private:
    //     bool _internal_has_use_combined_no_overlap() const;

    // public:
    //     void clear_use_combined_no_overlap();
    //     bool use_combined_no_overlap() const;
    //     void set_use_combined_no_overlap( bool value );

    // private:
    //     bool _internal_use_combined_no_overlap() const;
    //     void _internal_set_use_combined_no_overlap( bool value );

    // public:
    //     // optional bool polish_lp_solution = 175 [default = false];
    //     bool has_polish_lp_solution() const;

    // private:
    //     bool _internal_has_polish_lp_solution() const;

    // public:
    //     void clear_polish_lp_solution();
    //     bool polish_lp_solution() const;
    //     void set_polish_lp_solution( bool value );

    // private:
    //     bool _internal_polish_lp_solution() const;
    //     void _internal_set_polish_lp_solution( bool value );

    // public:
    //     // optional bool new_linear_propagation = 224 [default = false];
    //     bool has_new_linear_propagation() const;

    // private:
    //     bool _internal_has_new_linear_propagation() const;

    // public:
    //     void clear_new_linear_propagation();
    //     bool new_linear_propagation() const;
    //     void set_new_linear_propagation( bool value );

    // private:
    //     bool _internal_new_linear_propagation() const;
    //     void _internal_set_new_linear_propagation( bool value );

    // public:
    //     // optional bool add_objective_cut = 197 [default = false];
    //     bool has_add_objective_cut() const;

    // private:
    //     bool _internal_has_add_objective_cut() const;

    // public:
    //     void clear_add_objective_cut();
    //     bool add_objective_cut() const;
    //     void set_add_objective_cut( bool value );

    // private:
    //     bool _internal_add_objective_cut() const;
    //     void _internal_set_add_objective_cut( bool value );

    // public:
    //     // optional bool repair_hint = 167 [default = false];
    //     bool has_repair_hint() const;

    // private:
    //     bool _internal_has_repair_hint() const;

    // public:
    //     void clear_repair_hint();
    //     bool repair_hint() const;
    //     void set_repair_hint( bool value );

    // private:
    //     bool _internal_repair_hint() const;
    //     void _internal_set_repair_hint( bool value );

    // public:
    //     // optional bool fix_variables_to_their_hinted_value = 192 [default = false];
    //     bool has_fix_variables_to_their_hinted_value() const;

    // private:
    //     bool _internal_has_fix_variables_to_their_hinted_value() const;

    // public:
    //     void clear_fix_variables_to_their_hinted_value();
    //     bool fix_variables_to_their_hinted_value() const;
    //     void set_fix_variables_to_their_hinted_value( bool value );

    // private:
    //     bool _internal_fix_variables_to_their_hinted_value() const;
    //     void _internal_set_fix_variables_to_their_hinted_value( bool value );

    // public:
    //     // optional bool exploit_best_solution = 130 [default = false];
    //     bool has_exploit_best_solution() const;

    // private:
    //     bool _internal_has_exploit_best_solution() const;

    // public:
    //     void clear_exploit_best_solution();
    //     bool exploit_best_solution() const;
    //     void set_exploit_best_solution( bool value );

    // private:
    //     bool _internal_exploit_best_solution() const;
    //     void _internal_set_exploit_best_solution( bool value );

    // public:
    //     // optional bool exploit_all_precedences = 220 [default = false];
    //     bool has_exploit_all_precedences() const;

    // private:
    //     bool _internal_has_exploit_all_precedences() const;

    // public:
    //     void clear_exploit_all_precedences();
    //     bool exploit_all_precedences() const;
    //     void set_exploit_all_precedences( bool value );

    // private:
    //     bool _internal_exploit_all_precedences() const;
    //     void _internal_set_exploit_all_precedences( bool value );

    // public:
    //     // optional bool use_timetabling_in_no_overlap_2d = 200 [default = false];
    //     bool has_use_timetabling_in_no_overlap_2d() const;

    // private:
    //     bool _internal_has_use_timetabling_in_no_overlap_2d() const;

    // public:
    //     void clear_use_timetabling_in_no_overlap_2d();
    //     bool use_timetabling_in_no_overlap_2d() const;
    //     void set_use_timetabling_in_no_overlap_2d( bool value );
    set_use_timetabling_in_no_overlap_2d(value: boolean): void;


    // public:
    //     // optional bool use_energetic_reasoning_in_no_overlap_2d = 213 [default = false];
    //     bool has_use_energetic_reasoning_in_no_overlap_2d() const;

    // private:
    //     bool _internal_has_use_energetic_reasoning_in_no_overlap_2d() const;

    // public:
    //     void clear_use_energetic_reasoning_in_no_overlap_2d();
    //     bool use_energetic_reasoning_in_no_overlap_2d() const;
    //     void set_use_energetic_reasoning_in_no_overlap_2d( bool value );


    // public:
    //     // optional bool only_add_cuts_at_level_zero = 92 [default = false];
    //     bool has_only_add_cuts_at_level_zero() const;

    // private:
    //     bool _internal_has_only_add_cuts_at_level_zero() const;

    // public:
    //     void clear_only_add_cuts_at_level_zero();
    //     bool only_add_cuts_at_level_zero() const;
    //     void set_only_add_cuts_at_level_zero( bool value );

    // private:
    //     bool _internal_only_add_cuts_at_level_zero() const;
    //     void _internal_set_only_add_cuts_at_level_zero( bool value );

    // public:
    //     // optional bool expand_alldiff_constraints = 170 [default = false];
    //     bool has_expand_alldiff_constraints() const;

    // private:
    //     bool _internal_has_expand_alldiff_constraints() const;

    // public:
    //     void clear_expand_alldiff_constraints();
    //     bool expand_alldiff_constraints() const;
    //     void set_expand_alldiff_constraints( bool value );

    // private:
    //     bool _internal_expand_alldiff_constraints() const;
    //     void _internal_set_expand_alldiff_constraints( bool value );

    // public:
    //     // optional bool disable_constraint_expansion = 181 [default = false];
    //     bool has_disable_constraint_expansion() const;

    // private:
    //     bool _internal_has_disable_constraint_expansion() const;

    // public:
    //     void clear_disable_constraint_expansion();
    //     bool disable_constraint_expansion() const;
    //     void set_disable_constraint_expansion( bool value );

    // private:
    //     bool _internal_disable_constraint_expansion() const;
    //     void _internal_set_disable_constraint_expansion( bool value );

    // public:
    //     // optional bool encode_complex_linear_constraint_with_integer = 223 [default = false];
    //     bool has_encode_complex_linear_constraint_with_integer() const;

    // private:
    //     bool _internal_has_encode_complex_linear_constraint_with_integer() const;

    // public:
    //     void clear_encode_complex_linear_constraint_with_integer();
    //     bool encode_complex_linear_constraint_with_integer() const;
    //     void set_encode_complex_linear_constraint_with_integer( bool value );

    // private:
    //     bool _internal_encode_complex_linear_constraint_with_integer() const;
    //     void _internal_set_encode_complex_linear_constraint_with_integer( bool value );

    // public:
    //     // optional bool presolve_extract_integer_enforcement = 174 [default = false];
    //     bool has_presolve_extract_integer_enforcement() const;

    // private:
    //     bool _internal_has_presolve_extract_integer_enforcement() const;

    // public:
    //     void clear_presolve_extract_integer_enforcement();
    //     bool presolve_extract_integer_enforcement() const;
    //     void set_presolve_extract_integer_enforcement( bool value );

    // private:
    //     bool _internal_presolve_extract_integer_enforcement() const;
    //     void _internal_set_presolve_extract_integer_enforcement( bool value );

    // public:
    //     // optional int32 num_workers = 206 [default = 0];
    //     bool has_num_workers() const;

    // private:
    //     bool _internal_has_num_workers() const;

    // public:
    //     void    clear_num_workers();
    //     int32_t num_workers() const;
    //     void    set_num_workers( int32_t value );

    // private:
    //     int32_t _internal_num_workers() const;
    //     void    _internal_set_num_workers( int32_t value );

    // public:
    //     // optional bool mip_scale_large_domain = 225 [default = false];
    //     bool has_mip_scale_large_domain() const;

    // private:
    //     bool _internal_has_mip_scale_large_domain() const;

    // public:
    //     void clear_mip_scale_large_domain();
    //     bool mip_scale_large_domain() const;
    //     void set_mip_scale_large_domain( bool value );

    // private:
    //     bool _internal_mip_scale_large_domain() const;
    //     void _internal_set_mip_scale_large_domain( bool value );

    // public:
    //     // optional bool only_solve_ip = 222 [default = false];
    //     bool has_only_solve_ip() const;

    // private:
    //     bool _internal_has_only_solve_ip() const;

    // public:
    //     void clear_only_solve_ip();
    //     bool only_solve_ip() const;
    //     void set_only_solve_ip( bool value );

    // private:
    //     bool _internal_only_solve_ip() const;
    //     void _internal_set_only_solve_ip( bool value );

    // public:
    //     // optional .operations_research.sat.SatParameters.Polarity initial_polarity = 2 [default = POLARITY_FALSE];
    //     bool has_initial_polarity() const;

    // private:
    //     bool _internal_has_initial_polarity() const;

    // public:
    //     void                                               clear_initial_polarity();
    //     ::operations_research::sat::SatParameters_Polarity initial_polarity() const;
    //     void                                               set_initial_polarity( ::operations_research::sat::SatParameters_Polarity value );

    // private:
    //     ::operations_research::sat::SatParameters_Polarity _internal_initial_polarity() const;
    //     void                                               _internal_set_initial_polarity( ::operations_research::sat::SatParameters_Polarity value );

    // public:
    //     // optional .operations_research.sat.SatParameters.ConflictMinimizationAlgorithm minimization_algorithm = 4 [default = RECURSIVE];
    //     bool has_minimization_algorithm() const;

    // private:
    //     bool _internal_has_minimization_algorithm() const;

    // public:
    //     void                                                                    clear_minimization_algorithm();
    //     ::operations_research::sat::SatParameters_ConflictMinimizationAlgorithm minimization_algorithm() const;
    //     void                                                                    set_minimization_algorithm( ::operations_research::sat::SatParameters_ConflictMinimizationAlgorithm value );

    // private:
    //     ::operations_research::sat::SatParameters_ConflictMinimizationAlgorithm _internal_minimization_algorithm() const;
    //     void                                                                    _internal_set_minimization_algorithm( ::operations_research::sat::SatParameters_ConflictMinimizationAlgorithm value );

    // public:
    //     // optional double variable_activity_decay = 15 [default = 0.8];
    //     bool has_variable_activity_decay() const;

    // private:
    //     bool _internal_has_variable_activity_decay() const;

    // public:
    //     void   clear_variable_activity_decay();
    //     double variable_activity_decay() const;
    //     void   set_variable_activity_decay( double value );

    // private:
    //     double _internal_variable_activity_decay() const;
    //     void   _internal_set_variable_activity_decay( double value );

    // public:
    //     // optional double max_variable_activity_value = 16 [default = 1e+100];
    //     bool has_max_variable_activity_value() const;

    // private:
    //     bool _internal_has_max_variable_activity_value() const;

    // public:
    //     void   clear_max_variable_activity_value();
    //     double max_variable_activity_value() const;
    //     void   set_max_variable_activity_value( double value );

    // private:
    //     double _internal_max_variable_activity_value() const;
    //     void   _internal_set_max_variable_activity_value( double value );

    // public:
    //     // optional double clause_activity_decay = 17 [default = 0.999];
    //     bool has_clause_activity_decay() const;

    // private:
    //     bool _internal_has_clause_activity_decay() const;

    // public:
    //     void   clear_clause_activity_decay();
    //     double clause_activity_decay() const;
    //     void   set_clause_activity_decay( double value );

    // private:
    //     double _internal_clause_activity_decay() const;
    //     void   _internal_set_clause_activity_decay( double value );

    // public:
    //     // optional int32 clause_cleanup_period = 11 [default = 10000];
    //     bool has_clause_cleanup_period() const;

    // private:
    //     bool _internal_has_clause_cleanup_period() const;

    // public:
    //     void    clear_clause_cleanup_period();
    //     int32_t clause_cleanup_period() const;
    //     void    set_clause_cleanup_period( int32_t value );

    // private:
    //     int32_t _internal_clause_cleanup_period() const;
    //     void    _internal_set_clause_cleanup_period( int32_t value );

    // public:
    //     // optional int32 glucose_decay_increment_period = 24 [default = 5000];
    //     bool has_glucose_decay_increment_period() const;

    // private:
    //     bool _internal_has_glucose_decay_increment_period() const;

    // public:
    //     void    clear_glucose_decay_increment_period();
    //     int32_t glucose_decay_increment_period() const;
    //     void    set_glucose_decay_increment_period( int32_t value );

    // private:
    //     int32_t _internal_glucose_decay_increment_period() const;
    //     void    _internal_set_glucose_decay_increment_period( int32_t value );

    // public:
    //     // optional double max_clause_activity_value = 18 [default = 1e+020];
    //     bool has_max_clause_activity_value() const;

    // private:
    //     bool _internal_has_max_clause_activity_value() const;

    // public:
    //     void   clear_max_clause_activity_value();
    //     double max_clause_activity_value() const;
    //     void   set_max_clause_activity_value( double value );

    // private:
    //     double _internal_max_clause_activity_value() const;
    //     void   _internal_set_max_clause_activity_value( double value );

    // public:
    //     // optional double glucose_max_decay = 22 [default = 0.95];
    //     bool has_glucose_max_decay() const;

    // private:
    //     bool _internal_has_glucose_max_decay() const;

    // public:
    //     void   clear_glucose_max_decay();
    //     double glucose_max_decay() const;
    //     void   set_glucose_max_decay( double value );

    // private:
    //     double _internal_glucose_max_decay() const;
    //     void   _internal_set_glucose_max_decay( double value );

    // public:
    //     // optional double glucose_decay_increment = 23 [default = 0.01];
    //     bool has_glucose_decay_increment() const;

    // private:
    //     bool _internal_has_glucose_decay_increment() const;

    // public:
    //     void   clear_glucose_decay_increment();
    //     double glucose_decay_increment() const;
    //     void   set_glucose_decay_increment( double value );

    // private:
    //     double _internal_glucose_decay_increment() const;
    //     void   _internal_set_glucose_decay_increment( double value );

    // public:
    //     // optional int32 restart_period = 30 [default = 50];
    //     bool has_restart_period() const;

    // private:
    //     bool _internal_has_restart_period() const;

    // public:
    //     void    clear_restart_period();
    //     int32_t restart_period() const;
    //     void    set_restart_period( int32_t value );

    // private:
    //     int32_t _internal_restart_period() const;
    //     void    _internal_set_restart_period( int32_t value );

    // public:
    //     // optional int32 random_seed = 31 [default = 1];
    //     bool has_random_seed() const;

    // private:
    //     bool _internal_has_random_seed() const;

    // public:
    //     void    clear_random_seed();
    //     int32_t random_seed() const;
    //     void    set_random_seed( int32_t value );

    // private:
    //     int32_t _internal_random_seed() const;
    //     void    _internal_set_random_seed( int32_t value );

    // public:
    //     // optional double max_time_in_seconds = 36 [default = inf];
    //     bool has_max_time_in_seconds() const;

    // private:
    //     bool _internal_has_max_time_in_seconds() const;

    // public:
    //     void   clear_max_time_in_seconds();
    //     double max_time_in_seconds() const;
    //     void   set_max_time_in_seconds( double value );

    // private:
    //     double _internal_max_time_in_seconds() const;
    //     void   _internal_set_max_time_in_seconds( double value );

    // public:
    //     // optional int64 max_number_of_conflicts = 37 [default = 9223372036854775807];
    //     bool has_max_number_of_conflicts() const;

    // private:
    //     bool _internal_has_max_number_of_conflicts() const;

    // public:
    //     void    clear_max_number_of_conflicts();
    //     int64_t max_number_of_conflicts() const;
    //     void    set_max_number_of_conflicts( int64_t value );

    // private:
    //     int64_t _internal_max_number_of_conflicts() const;
    //     void    _internal_set_max_number_of_conflicts( int64_t value );

    // public:
    //     // optional int64 max_memory_in_mb = 40 [default = 10000];
    //     bool has_max_memory_in_mb() const;

    // private:
    //     bool _internal_has_max_memory_in_mb() const;

    // public:
    //     void    clear_max_memory_in_mb();
    //     int64_t max_memory_in_mb() const;
    //     void    set_max_memory_in_mb( int64_t value );

    // private:
    //     int64_t _internal_max_memory_in_mb() const;
    //     void    _internal_set_max_memory_in_mb( int64_t value );

    // public:
    //     // optional .operations_research.sat.SatParameters.BinaryMinizationAlgorithm binary_minimization_algorithm = 34 [default = BINARY_MINIMIZATION_FIRST];
    //     bool has_binary_minimization_algorithm() const;

    // private:
    //     bool _internal_has_binary_minimization_algorithm() const;

    // public:
    //     void                                                                clear_binary_minimization_algorithm();
    //     ::operations_research::sat::SatParameters_BinaryMinizationAlgorithm binary_minimization_algorithm() const;
    //     void                                                                set_binary_minimization_algorithm( ::operations_research::sat::SatParameters_BinaryMinizationAlgorithm value );

    // private:
    //     ::operations_research::sat::SatParameters_BinaryMinizationAlgorithm _internal_binary_minimization_algorithm() const;
    //     void                                                                _internal_set_binary_minimization_algorithm( ::operations_research::sat::SatParameters_BinaryMinizationAlgorithm value );

    // public:
    //     // optional int32 pb_cleanup_increment = 46 [default = 200];
    //     bool has_pb_cleanup_increment() const;

    // private:
    //     bool _internal_has_pb_cleanup_increment() const;

    // public:
    //     void    clear_pb_cleanup_increment();
    //     int32_t pb_cleanup_increment() const;
    //     void    set_pb_cleanup_increment( int32_t value );

    // private:
    //     int32_t _internal_pb_cleanup_increment() const;
    //     void    _internal_set_pb_cleanup_increment( int32_t value );

    // public:
    //     // optional double pb_cleanup_ratio = 47 [default = 0.5];
    //     bool has_pb_cleanup_ratio() const;

    // private:
    //     bool _internal_has_pb_cleanup_ratio() const;

    // public:
    //     void   clear_pb_cleanup_ratio();
    //     double pb_cleanup_ratio() const;
    //     void   set_pb_cleanup_ratio( double value );

    // private:
    //     double _internal_pb_cleanup_ratio() const;
    //     void   _internal_set_pb_cleanup_ratio( double value );

    // public:
    //     // optional .operations_research.sat.SatParameters.MaxSatStratificationAlgorithm max_sat_stratification = 53 [default = STRATIFICATION_DESCENT];
    //     bool has_max_sat_stratification() const;

    // private:
    //     bool _internal_has_max_sat_stratification() const;

    // public:
    //     void                                                                    clear_max_sat_stratification();
    //     ::operations_research::sat::SatParameters_MaxSatStratificationAlgorithm max_sat_stratification() const;
    //     void                                                                    set_max_sat_stratification( ::operations_research::sat::SatParameters_MaxSatStratificationAlgorithm value );

    // private:
    //     ::operations_research::sat::SatParameters_MaxSatStratificationAlgorithm _internal_max_sat_stratification() const;
    //     void                                                                    _internal_set_max_sat_stratification( ::operations_research::sat::SatParameters_MaxSatStratificationAlgorithm value );

    // public:
    //     // optional int32 presolve_bve_threshold = 54 [default = 500];
    //     bool has_presolve_bve_threshold() const;

    // private:
    //     bool _internal_has_presolve_bve_threshold() const;

    // public:
    //     void    clear_presolve_bve_threshold();
    //     int32_t presolve_bve_threshold() const;
    //     void    set_presolve_bve_threshold( int32_t value );

    // private:
    //     int32_t _internal_presolve_bve_threshold() const;
    //     void    _internal_set_presolve_bve_threshold( int32_t value );

    // public:
    //     // optional double presolve_probing_deterministic_time_limit = 57 [default = 30];
    //     bool has_presolve_probing_deterministic_time_limit() const;

    // private:
    //     bool _internal_has_presolve_probing_deterministic_time_limit() const;

    // public:
    //     void   clear_presolve_probing_deterministic_time_limit();
    //     double presolve_probing_deterministic_time_limit() const;
    //     void   set_presolve_probing_deterministic_time_limit( double value );

    // private:
    //     double _internal_presolve_probing_deterministic_time_limit() const;
    //     void   _internal_set_presolve_probing_deterministic_time_limit( double value );

    // public:
    //     // optional int32 presolve_bve_clause_weight = 55 [default = 3];
    //     bool has_presolve_bve_clause_weight() const;

    // private:
    //     bool _internal_has_presolve_bve_clause_weight() const;

    // public:
    //     void    clear_presolve_bve_clause_weight();
    //     int32_t presolve_bve_clause_weight() const;
    //     void    set_presolve_bve_clause_weight( int32_t value );

    // private:
    //     int32_t _internal_presolve_bve_clause_weight() const;
    //     void    _internal_set_presolve_bve_clause_weight( int32_t value );

    // public:
    //     // optional int32 clause_cleanup_lbd_bound = 59 [default = 5];
    //     bool has_clause_cleanup_lbd_bound() const;

    // private:
    //     bool _internal_has_clause_cleanup_lbd_bound() const;

    // public:
    //     void    clear_clause_cleanup_lbd_bound();
    //     int32_t clause_cleanup_lbd_bound() const;
    //     void    set_clause_cleanup_lbd_bound( int32_t value );

    // private:
    //     int32_t _internal_clause_cleanup_lbd_bound() const;
    //     void    _internal_set_clause_cleanup_lbd_bound( int32_t value );

    // public:
    //     // optional double restart_dl_average_ratio = 63 [default = 1];
    //     bool has_restart_dl_average_ratio() const;

    // private:
    //     bool _internal_has_restart_dl_average_ratio() const;

    // public:
    //     void   clear_restart_dl_average_ratio();
    //     double restart_dl_average_ratio() const;
    //     void   set_restart_dl_average_ratio( double value );

    // private:
    //     double _internal_restart_dl_average_ratio() const;
    //     void   _internal_set_restart_dl_average_ratio( double value );

    // public:
    //     // optional int32 restart_running_window_size = 62 [default = 50];
    //     bool has_restart_running_window_size() const;

    // private:
    //     bool _internal_has_restart_running_window_size() const;

    // public:
    //     void    clear_restart_running_window_size();
    //     int32_t restart_running_window_size() const;
    //     void    set_restart_running_window_size( int32_t value );

    // private:
    //     int32_t _internal_restart_running_window_size() const;
    //     void    _internal_set_restart_running_window_size( int32_t value );

    // public:
    //     // optional bool use_optimization_hints = 35 [default = true];
    //     bool has_use_optimization_hints() const;

    // private:
    //     bool _internal_has_use_optimization_hints() const;

    // public:
    //     void clear_use_optimization_hints();
    //     bool use_optimization_hints() const;
    //     void set_use_optimization_hints( bool value );

    // private:
    //     bool _internal_use_optimization_hints() const;
    //     void _internal_set_use_optimization_hints( bool value );

    // public:
    //     // optional bool minimize_core = 50 [default = true];
    //     bool has_minimize_core() const;

    // private:
    //     bool _internal_has_minimize_core() const;

    // public:
    //     void clear_minimize_core();
    //     bool minimize_core() const;
    //     void set_minimize_core( bool value );

    // private:
    //     bool _internal_minimize_core() const;
    //     void _internal_set_minimize_core( bool value );

    // public:
    //     // optional bool find_multiple_cores = 84 [default = true];
    //     bool has_find_multiple_cores() const;

    // private:
    //     bool _internal_has_find_multiple_cores() const;

    // public:
    //     void clear_find_multiple_cores();
    //     bool find_multiple_cores() const;
    //     void set_find_multiple_cores( bool value );

    // private:
    //     bool _internal_find_multiple_cores() const;
    //     void _internal_set_find_multiple_cores( bool value );

    // public:
    //     // optional bool cover_optimization = 89 [default = true];
    //     bool has_cover_optimization() const;

    // private:
    //     bool _internal_has_cover_optimization() const;

    // public:
    //     void clear_cover_optimization();
    //     bool cover_optimization() const;
    //     void set_cover_optimization( bool value );

    // private:
    //     bool _internal_cover_optimization() const;
    //     void _internal_set_cover_optimization( bool value );

    // public:
    //     // optional double blocking_restart_multiplier = 66 [default = 1.4];
    //     bool has_blocking_restart_multiplier() const;

    // private:
    //     bool _internal_has_blocking_restart_multiplier() const;

    // public:
    //     void   clear_blocking_restart_multiplier();
    //     double blocking_restart_multiplier() const;
    //     void   set_blocking_restart_multiplier( double value );

    // private:
    //     double _internal_blocking_restart_multiplier() const;
    //     void   _internal_set_blocking_restart_multiplier( double value );

    // public:
    //     // optional double max_deterministic_time = 67 [default = inf];
    //     bool has_max_deterministic_time() const;

    // private:
    //     bool _internal_has_max_deterministic_time() const;

    // public:
    //     void   clear_max_deterministic_time();
    //     double max_deterministic_time() const;
    //     void   set_max_deterministic_time( double value );

    // private:
    //     double _internal_max_deterministic_time() const;
    //     void   _internal_set_max_deterministic_time( double value );

    // public:
    //     // optional int32 blocking_restart_window_size = 65 [default = 5000];
    //     bool has_blocking_restart_window_size() const;

    // private:
    //     bool _internal_has_blocking_restart_window_size() const;

    // public:
    //     void    clear_blocking_restart_window_size();
    //     int32_t blocking_restart_window_size() const;
    //     void    set_blocking_restart_window_size( int32_t value );

    // private:
    //     int32_t _internal_blocking_restart_window_size() const;
    //     void    _internal_set_blocking_restart_window_size( int32_t value );

    // public:
    //     // optional int32 presolve_bva_threshold = 73 [default = 1];
    //     bool has_presolve_bva_threshold() const;

    // private:
    //     bool _internal_has_presolve_bva_threshold() const;

    // public:
    //     void    clear_presolve_bva_threshold();
    //     int32_t presolve_bva_threshold() const;
    //     void    set_presolve_bva_threshold( int32_t value );

    // private:
    //     int32_t _internal_presolve_bva_threshold() const;
    //     void    _internal_set_presolve_bva_threshold( int32_t value );

    // public:
    //     // optional double restart_lbd_average_ratio = 71 [default = 1];
    //     bool has_restart_lbd_average_ratio() const;

    // private:
    //     bool _internal_has_restart_lbd_average_ratio() const;

    // public:
    //     void   clear_restart_lbd_average_ratio();
    //     double restart_lbd_average_ratio() const;
    //     void   set_restart_lbd_average_ratio( double value );

    // private:
    //     double _internal_restart_lbd_average_ratio() const;
    //     void   _internal_set_restart_lbd_average_ratio( double value );

    // public:
    //     // optional bool count_assumption_levels_in_lbd = 49 [default = true];
    //     bool has_count_assumption_levels_in_lbd() const;

    // private:
    //     bool _internal_has_count_assumption_levels_in_lbd() const;

    // public:
    //     void clear_count_assumption_levels_in_lbd();
    //     bool count_assumption_levels_in_lbd() const;
    //     void set_count_assumption_levels_in_lbd( bool value );

    // private:
    //     bool _internal_count_assumption_levels_in_lbd() const;
    //     void _internal_set_count_assumption_levels_in_lbd( bool value );

    // public:
    //     // optional bool presolve_blocked_clause = 88 [default = true];
    //     bool has_presolve_blocked_clause() const;

    // private:
    //     bool _internal_has_presolve_blocked_clause() const;

    // public:
    //     void clear_presolve_blocked_clause();
    //     bool presolve_blocked_clause() const;
    //     void set_presolve_blocked_clause( bool value );

    // private:
    //     bool _internal_presolve_blocked_clause() const;
    //     void _internal_set_presolve_blocked_clause( bool value );

    // public:
    //     // optional bool presolve_use_bva = 72 [default = true];
    //     bool has_presolve_use_bva() const;

    // private:
    //     bool _internal_has_presolve_use_bva() const;

    // public:
    //     void clear_presolve_use_bva();
    //     bool presolve_use_bva() const;
    //     void set_presolve_use_bva( bool value );

    // private:
    //     bool _internal_presolve_use_bva() const;
    //     void _internal_set_presolve_use_bva( bool value );

    // public:
    //     // optional bool cp_model_presolve = 86 [default = true];
    //     bool has_cp_model_presolve() const;

    // private:
    //     bool _internal_has_cp_model_presolve() const;

    // public:
    //     void clear_cp_model_presolve();
    //     bool cp_model_presolve() const;
    //     void set_cp_model_presolve( bool value );

    // private:
    //     bool _internal_cp_model_presolve() const;
    //     void _internal_set_cp_model_presolve( bool value );

    // public:
    //     // optional int32 linearization_level = 90 [default = 1];
    //     bool has_linearization_level() const;

    // private:
    //     bool _internal_has_linearization_level() const;

    // public:
    //     void    clear_linearization_level();
    //     int32_t linearization_level() const;
    //     void    set_linearization_level( int32_t value );

    // private:
    //     int32_t _internal_linearization_level() const;
    //     void    _internal_set_linearization_level( int32_t value );

    // public:
    //     // optional int32 max_num_cuts = 91 [default = 10000];
    //     bool has_max_num_cuts() const;

    // private:
    //     bool _internal_has_max_num_cuts() const;

    // public:
    //     void    clear_max_num_cuts();
    //     int32_t max_num_cuts() const;
    //     void    set_max_num_cuts( int32_t value );

    // private:
    //     int32_t _internal_max_num_cuts() const;
    //     void    _internal_set_max_num_cuts( int32_t value );

    // public:
    //     // optional int32 minimize_with_propagation_restart_period = 96 [default = 10];
    //     bool has_minimize_with_propagation_restart_period() const;

    // private:
    //     bool _internal_has_minimize_with_propagation_restart_period() const;

    // public:
    //     void    clear_minimize_with_propagation_restart_period();
    //     int32_t minimize_with_propagation_restart_period() const;
    //     void    set_minimize_with_propagation_restart_period( int32_t value );

    // private:
    //     int32_t _internal_minimize_with_propagation_restart_period() const;
    //     void    _internal_set_minimize_with_propagation_restart_period( int32_t value );

    // public:
    //     // optional int32 minimize_with_propagation_num_decisions = 97 [default = 1000];
    //     bool has_minimize_with_propagation_num_decisions() const;

    // private:
    //     bool _internal_has_minimize_with_propagation_num_decisions() const;

    // public:
    //     void    clear_minimize_with_propagation_num_decisions();
    //     int32_t minimize_with_propagation_num_decisions() const;
    //     void    set_minimize_with_propagation_num_decisions( int32_t value );

    // private:
    //     int32_t _internal_minimize_with_propagation_num_decisions() const;
    //     void    _internal_set_minimize_with_propagation_num_decisions( int32_t value );

    // public:
    //     // optional int32 binary_search_num_conflicts = 99 [default = -1];
    //     bool has_binary_search_num_conflicts() const;

    // private:
    //     bool _internal_has_binary_search_num_conflicts() const;

    // public:
    //     void    clear_binary_search_num_conflicts();
    //     int32_t binary_search_num_conflicts() const;
    //     void    set_binary_search_num_conflicts( int32_t value );

    // private:
    //     int32_t _internal_binary_search_num_conflicts() const;
    //     void    _internal_set_binary_search_num_conflicts( int32_t value );

    // public:
    //     // optional int32 boolean_encoding_level = 107 [default = 1];
    //     bool has_boolean_encoding_level() const;

    // private:
    //     bool _internal_has_boolean_encoding_level() const;

    // public:
    //     void    clear_boolean_encoding_level();
    //     int32_t boolean_encoding_level() const;
    //     void    set_boolean_encoding_level( int32_t value );

    // private:
    //     int32_t _internal_boolean_encoding_level() const;
    //     void    _internal_set_boolean_encoding_level( int32_t value );

    // public:
    //     // optional int32 cp_model_probing_level = 110 [default = 2];
    //     bool has_cp_model_probing_level() const;

    // private:
    //     bool _internal_has_cp_model_probing_level() const;

    // public:
    //     void    clear_cp_model_probing_level();
    //     int32_t cp_model_probing_level() const;
    //     void    set_cp_model_probing_level( int32_t value );

    // private:
    //     int32_t _internal_cp_model_probing_level() const;
    //     void    _internal_set_cp_model_probing_level( int32_t value );

    // public:
    //     // optional double min_orthogonality_for_lp_constraints = 115 [default = 0.05];
    //     bool has_min_orthogonality_for_lp_constraints() const;

    // private:
    //     bool _internal_has_min_orthogonality_for_lp_constraints() const;

    // public:
    //     void   clear_min_orthogonality_for_lp_constraints();
    //     double min_orthogonality_for_lp_constraints() const;
    //     void   set_min_orthogonality_for_lp_constraints( double value );

    // private:
    //     double _internal_min_orthogonality_for_lp_constraints() const;
    //     void   _internal_set_min_orthogonality_for_lp_constraints( double value );

    // public:
    //     // optional bool add_lp_constraints_lazily = 112 [default = true];
    //     bool has_add_lp_constraints_lazily() const;

    // private:
    //     bool _internal_has_add_lp_constraints_lazily() const;

    // public:
    //     void clear_add_lp_constraints_lazily();
    //     bool add_lp_constraints_lazily() const;
    //     void set_add_lp_constraints_lazily( bool value );

    // private:
    //     bool _internal_add_lp_constraints_lazily() const;
    //     void _internal_set_add_lp_constraints_lazily( bool value );

    // public:
    //     // optional bool exploit_integer_lp_solution = 94 [default = true];
    //     bool has_exploit_integer_lp_solution() const;

    // private:
    //     bool _internal_has_exploit_integer_lp_solution() const;

    // public:
    //     void clear_exploit_integer_lp_solution();
    //     bool exploit_integer_lp_solution() const;
    //     void set_exploit_integer_lp_solution( bool value );

    // private:
    //     bool _internal_exploit_integer_lp_solution() const;
    //     void _internal_set_exploit_integer_lp_solution( bool value );

    // public:
    //     // optional bool exploit_all_lp_solution = 116 [default = true];
    //     bool has_exploit_all_lp_solution() const;

    // private:
    //     bool _internal_has_exploit_all_lp_solution() const;

    // public:
    //     void clear_exploit_all_lp_solution();
    //     bool exploit_all_lp_solution() const;
    //     void set_exploit_all_lp_solution( bool value );

    // private:
    //     bool _internal_exploit_all_lp_solution() const;
    //     void _internal_set_exploit_all_lp_solution( bool value );

    // public:
    //     // optional bool exploit_objective = 131 [default = true];
    //     bool has_exploit_objective() const;

    // private:
    //     bool _internal_has_exploit_objective() const;

    // public:
    //     void clear_exploit_objective();
    //     bool exploit_objective() const;
    //     void set_exploit_objective( bool value );

    // private:
    //     bool _internal_exploit_objective() const;
    //     void _internal_set_exploit_objective( bool value );

    // public:
    //     // optional bool use_phase_saving = 44 [default = true];
    //     bool has_use_phase_saving() const;

    // private:
    //     bool _internal_has_use_phase_saving() const;

    // public:
    //     void clear_use_phase_saving();
    //     bool use_phase_saving() const;
    //     void set_use_phase_saving( bool value );

    // private:
    //     bool _internal_use_phase_saving() const;
    //     void _internal_set_use_phase_saving( bool value );

    // public:
    //     // optional bool subsumption_during_conflict_analysis = 56 [default = true];
    //     bool has_subsumption_during_conflict_analysis() const;

    // private:
    //     bool _internal_has_subsumption_during_conflict_analysis() const;

    // public:
    //     void clear_subsumption_during_conflict_analysis();
    //     bool subsumption_during_conflict_analysis() const;
    //     void set_subsumption_during_conflict_analysis( bool value );

    // private:
    //     bool _internal_subsumption_during_conflict_analysis() const;
    //     void _internal_set_subsumption_during_conflict_analysis( bool value );

    // public:
    //     // optional bool log_subsolver_statistics = 189 [default = true];
    //     bool has_log_subsolver_statistics() const;

    // private:
    //     bool _internal_has_log_subsolver_statistics() const;

    // public:
    //     void clear_log_subsolver_statistics();
    //     bool log_subsolver_statistics() const;
    //     void set_log_subsolver_statistics( bool value );

    // private:
    //     bool _internal_log_subsolver_statistics() const;
    //     void _internal_set_log_subsolver_statistics( bool value );

    // public:
    //     // optional bool log_to_stdout = 186 [default = true];
    //     bool has_log_to_stdout() const;

    // private:
    //     bool _internal_has_log_to_stdout() const;

    // public:
    //     void clear_log_to_stdout();
    //     bool log_to_stdout() const;
    //     void set_log_to_stdout( bool value );

    // private:
    //     bool _internal_log_to_stdout() const;
    //     void _internal_set_log_to_stdout( bool value );

    // public:
    //     // optional int32 max_integer_rounding_scaling = 119 [default = 600];
    //     bool has_max_integer_rounding_scaling() const;

    // private:
    //     bool _internal_has_max_integer_rounding_scaling() const;

    // public:
    //     void    clear_max_integer_rounding_scaling();
    //     int32_t max_integer_rounding_scaling() const;
    //     void    set_max_integer_rounding_scaling( int32_t value );

    // private:
    //     int32_t _internal_max_integer_rounding_scaling() const;
    //     void    _internal_set_max_integer_rounding_scaling( int32_t value );

    // public:
    //     // optional int32 max_consecutive_inactive_count = 121 [default = 100];
    //     bool has_max_consecutive_inactive_count() const;

    // private:
    //     bool _internal_has_max_consecutive_inactive_count() const;

    // public:
    //     void    clear_max_consecutive_inactive_count();
    //     int32_t max_consecutive_inactive_count() const;
    //     void    set_max_consecutive_inactive_count( int32_t value );

    // private:
    //     int32_t _internal_max_consecutive_inactive_count() const;
    //     void    _internal_set_max_consecutive_inactive_count( int32_t value );

    // public:
    //     // optional bool use_precedences_in_disjunctive_constraint = 74 [default = true];
    //     bool has_use_precedences_in_disjunctive_constraint() const;

    // private:
    //     bool _internal_has_use_precedences_in_disjunctive_constraint() const;

    // public:
    //     void clear_use_precedences_in_disjunctive_constraint();
    //     bool use_precedences_in_disjunctive_constraint() const;
    //     void set_use_precedences_in_disjunctive_constraint( bool value );

    // private:
    //     bool _internal_use_precedences_in_disjunctive_constraint() const;
    //     void _internal_set_use_precedences_in_disjunctive_constraint( bool value );

    // public:
    //     // optional bool use_disjunctive_constraint_in_cumulative = 80 [default = true];
    //     bool has_use_disjunctive_constraint_in_cumulative() const;

    // private:
    //     bool _internal_has_use_disjunctive_constraint_in_cumulative() const;

    // public:
    //     void clear_use_disjunctive_constraint_in_cumulative();
    //     bool use_disjunctive_constraint_in_cumulative() const;
    //     void set_use_disjunctive_constraint_in_cumulative( bool value );

    // private:
    //     bool _internal_use_disjunctive_constraint_in_cumulative() const;
    //     void _internal_set_use_disjunctive_constraint_in_cumulative( bool value );

    // public:
    //     // optional bool use_dual_scheduling_heuristics = 214 [default = true];
    //     bool has_use_dual_scheduling_heuristics() const;

    // private:
    //     bool _internal_has_use_dual_scheduling_heuristics() const;

    // public:
    //     void clear_use_dual_scheduling_heuristics();
    //     bool use_dual_scheduling_heuristics() const;
    //     void set_use_dual_scheduling_heuristics( bool value );

    // private:
    //     bool _internal_use_dual_scheduling_heuristics() const;
    //     void _internal_set_use_dual_scheduling_heuristics( bool value );

    // public:
    //     // optional bool add_cg_cuts = 117 [default = true];
    //     bool has_add_cg_cuts() const;

    // private:
    //     bool _internal_has_add_cg_cuts() const;

    // public:
    //     void clear_add_cg_cuts();
    //     bool add_cg_cuts() const;
    //     void set_add_cg_cuts( bool value );

    // private:
    //     bool _internal_add_cg_cuts() const;
    //     void _internal_set_add_cg_cuts( bool value );

    // public:
    //     // optional int32 new_constraints_batch_size = 122 [default = 50];
    //     bool has_new_constraints_batch_size() const;

    // private:
    //     bool _internal_has_new_constraints_batch_size() const;

    // public:
    //     void    clear_new_constraints_batch_size();
    //     int32_t new_constraints_batch_size() const;
    //     void    set_new_constraints_batch_size( int32_t value );

    // private:
    //     int32_t _internal_new_constraints_batch_size() const;
    //     void    _internal_set_new_constraints_batch_size( int32_t value );

    // public:
    //     // optional int64 pseudo_cost_reliability_threshold = 123 [default = 100];
    //     bool has_pseudo_cost_reliability_threshold() const;

    // private:
    //     bool _internal_has_pseudo_cost_reliability_threshold() const;

    // public:
    //     void    clear_pseudo_cost_reliability_threshold();
    //     int64_t pseudo_cost_reliability_threshold() const;
    //     void    set_pseudo_cost_reliability_threshold( int64_t value );

    // private:
    //     int64_t _internal_pseudo_cost_reliability_threshold() const;
    //     void    _internal_set_pseudo_cost_reliability_threshold( int64_t value );

    // public:
    //     // optional double mip_max_bound = 124 [default = 10000000];
    //     bool has_mip_max_bound() const;

    // private:
    //     bool _internal_has_mip_max_bound() const;

    // public:
    //     void   clear_mip_max_bound();
    //     double mip_max_bound() const;
    //     void   set_mip_max_bound( double value );

    // private:
    //     double _internal_mip_max_bound() const;
    //     void   _internal_set_mip_max_bound( double value );

    // public:
    //     // optional double mip_var_scaling = 125 [default = 1];
    //     bool has_mip_var_scaling() const;

    // private:
    //     bool _internal_has_mip_var_scaling() const;

    // public:
    //     void   clear_mip_var_scaling();
    //     double mip_var_scaling() const;
    //     void   set_mip_var_scaling( double value );

    // private:
    //     double _internal_mip_var_scaling() const;
    //     void   _internal_set_mip_var_scaling( double value );

    // public:
    //     // optional double mip_wanted_precision = 126 [default = 1e-006];
    //     bool has_mip_wanted_precision() const;

    // private:
    //     bool _internal_has_mip_wanted_precision() const;

    // public:
    //     void   clear_mip_wanted_precision();
    //     double mip_wanted_precision() const;
    //     void   set_mip_wanted_precision( double value );

    // private:
    //     double _internal_mip_wanted_precision() const;
    //     void   _internal_set_mip_wanted_precision( double value );

    // public:
    //     // optional double mip_check_precision = 128 [default = 0.0001];
    //     bool has_mip_check_precision() const;

    // private:
    //     bool _internal_has_mip_check_precision() const;

    // public:
    //     void   clear_mip_check_precision();
    //     double mip_check_precision() const;
    //     void   set_mip_check_precision( double value );

    // private:
    //     double _internal_mip_check_precision() const;
    //     void   _internal_set_mip_check_precision( double value );

    // public:
    //     // optional int32 mip_max_activity_exponent = 127 [default = 53];
    //     bool has_mip_max_activity_exponent() const;

    // private:
    //     bool _internal_has_mip_max_activity_exponent() const;

    // public:
    //     void    clear_mip_max_activity_exponent();
    //     int32_t mip_max_activity_exponent() const;
    //     void    set_mip_max_activity_exponent( int32_t value );

    // private:
    //     int32_t _internal_mip_max_activity_exponent() const;
    //     void    _internal_set_mip_max_activity_exponent( int32_t value );

    // public:
    //     // optional bool use_shaving_in_probing_search = 204 [default = true];
    //     bool has_use_shaving_in_probing_search() const;

    // private:
    //     bool _internal_has_use_shaving_in_probing_search() const;

    // public:
    //     void clear_use_shaving_in_probing_search();
    //     bool use_shaving_in_probing_search() const;
    //     void set_use_shaving_in_probing_search( bool value );

    // private:
    //     bool _internal_use_shaving_in_probing_search() const;
    //     void _internal_set_use_shaving_in_probing_search( bool value );

    // public:
    //     // optional bool instantiate_all_variables = 106 [default = true];
    //     bool has_instantiate_all_variables() const;

    // private:
    //     bool _internal_has_instantiate_all_variables() const;

    // public:
    //     void clear_instantiate_all_variables();
    //     bool instantiate_all_variables() const;
    //     void set_instantiate_all_variables( bool value );

    // private:
    //     bool _internal_instantiate_all_variables() const;
    //     void _internal_set_instantiate_all_variables( bool value );

    // public:
    //     // optional bool auto_detect_greater_than_at_least_one_of = 95 [default = true];
    //     bool has_auto_detect_greater_than_at_least_one_of() const;

    // private:
    //     bool _internal_has_auto_detect_greater_than_at_least_one_of() const;

    // public:
    //     void clear_auto_detect_greater_than_at_least_one_of();
    //     bool auto_detect_greater_than_at_least_one_of() const;
    //     void set_auto_detect_greater_than_at_least_one_of( bool value );

    // private:
    //     bool _internal_auto_detect_greater_than_at_least_one_of() const;
    //     void _internal_set_auto_detect_greater_than_at_least_one_of( bool value );

    // public:
    //     // optional bool use_rins_lns = 129 [default = true];
    //     bool has_use_rins_lns() const;

    // private:
    //     bool _internal_has_use_rins_lns() const;

    // public:
    //     void clear_use_rins_lns();
    //     bool use_rins_lns() const;
    //     void set_use_rins_lns( bool value );

    // private:
    //     bool _internal_use_rins_lns() const;
    //     void _internal_set_use_rins_lns( bool value );

    // public:
    //     // optional int32 max_presolve_iterations = 138 [default = 3];
    //     bool has_max_presolve_iterations() const;

    // private:
    //     bool _internal_has_max_presolve_iterations() const;

    // public:
    //     void    clear_max_presolve_iterations();
    //     int32_t max_presolve_iterations() const;
    //     void    set_max_presolve_iterations( int32_t value );

    // private:
    //     int32_t _internal_max_presolve_iterations() const;
    //     void    _internal_set_max_presolve_iterations( int32_t value );

    // public:
    //     // optional bool use_feasibility_pump = 164 [default = true];
    //     bool has_use_feasibility_pump() const;

    // private:
    //     bool _internal_has_use_feasibility_pump() const;

    // public:
    //     void clear_use_feasibility_pump();
    //     bool use_feasibility_pump() const;
    //     void set_use_feasibility_pump( bool value );

    // private:
    //     bool _internal_use_feasibility_pump() const;
    //     void _internal_set_use_feasibility_pump( bool value );

    // public:
    //     // optional bool use_exact_lp_reason = 109 [default = true];
    //     bool has_use_exact_lp_reason() const;

    // private:
    //     bool _internal_has_use_exact_lp_reason() const;

    // public:
    //     void clear_use_exact_lp_reason();
    //     bool use_exact_lp_reason() const;
    //     void set_use_exact_lp_reason( bool value );

    // private:
    //     bool _internal_use_exact_lp_reason() const;
    //     void _internal_set_use_exact_lp_reason( bool value );

    // public:
    //     // optional bool catch_sigint_signal = 135 [default = true];
    //     bool has_catch_sigint_signal() const;

    // private:
    //     bool _internal_has_catch_sigint_signal() const;

    // public:
    //     void clear_catch_sigint_signal();
    //     bool catch_sigint_signal() const;
    //     void set_catch_sigint_signal( bool value );

    // private:
    //     bool _internal_catch_sigint_signal() const;
    //     void _internal_set_catch_sigint_signal( bool value );

    // public:
    //     // optional bool use_implied_bounds = 144 [default = true];
    //     bool has_use_implied_bounds() const;

    // private:
    //     bool _internal_has_use_implied_bounds() const;

    // public:
    //     void clear_use_implied_bounds();
    //     bool use_implied_bounds() const;
    //     void set_use_implied_bounds( bool value );

    // private:
    //     bool _internal_use_implied_bounds() const;
    //     void _internal_set_use_implied_bounds( bool value );

    // public:
    //     // optional double merge_no_overlap_work_limit = 145 [default = 1000000000000];
    //     bool has_merge_no_overlap_work_limit() const;

    // private:
    //     bool _internal_has_merge_no_overlap_work_limit() const;

    // public:
    //     void   clear_merge_no_overlap_work_limit();
    //     double merge_no_overlap_work_limit() const;
    //     void   set_merge_no_overlap_work_limit( double value );

    // private:
    //     double _internal_merge_no_overlap_work_limit() const;
    //     void   _internal_set_merge_no_overlap_work_limit( double value );

    // public:
    //     // optional double merge_at_most_one_work_limit = 146 [default = 100000000];
    //     bool has_merge_at_most_one_work_limit() const;

    // private:
    //     bool _internal_has_merge_at_most_one_work_limit() const;

    // public:
    //     void   clear_merge_at_most_one_work_limit();
    //     double merge_at_most_one_work_limit() const;
    //     void   set_merge_at_most_one_work_limit( double value );

    // private:
    //     double _internal_merge_at_most_one_work_limit() const;
    //     void   _internal_set_merge_at_most_one_work_limit( double value );

    // public:
    //     // optional int32 presolve_substitution_level = 147 [default = 1];
    //     bool has_presolve_substitution_level() const;

    // private:
    //     bool _internal_has_presolve_substitution_level() const;

    // public:
    //     void    clear_presolve_substitution_level();
    //     int32_t presolve_substitution_level() const;
    //     void    set_presolve_substitution_level( int32_t value );

    // private:
    //     int32_t _internal_presolve_substitution_level() const;
    //     void    _internal_set_presolve_substitution_level( int32_t value );

    // public:
    //     // optional int32 max_all_diff_cut_size = 148 [default = 64];
    //     bool has_max_all_diff_cut_size() const;

    // private:
    //     bool _internal_has_max_all_diff_cut_size() const;

    // public:
    //     void    clear_max_all_diff_cut_size();
    //     int32_t max_all_diff_cut_size() const;
    //     void    set_max_all_diff_cut_size( int32_t value );

    // private:
    //     int32_t _internal_max_all_diff_cut_size() const;
    //     void    _internal_set_max_all_diff_cut_size( int32_t value );

    // public:
    //     // optional int32 hint_conflict_limit = 153 [default = 10];
    //     bool has_hint_conflict_limit() const;

    // private:
    //     bool _internal_has_hint_conflict_limit() const;

    // public:
    //     void    clear_hint_conflict_limit();
    //     int32_t hint_conflict_limit() const;
    //     void    set_hint_conflict_limit( int32_t value );

    // private:
    //     int32_t _internal_hint_conflict_limit() const;
    //     void    _internal_set_hint_conflict_limit( int32_t value );

    // public:
    //     // optional bool add_mir_cuts = 120 [default = true];
    //     bool has_add_mir_cuts() const;

    // private:
    //     bool _internal_has_add_mir_cuts() const;

    // public:
    //     void clear_add_mir_cuts();
    //     bool add_mir_cuts() const;
    //     void set_add_mir_cuts( bool value );

    // private:
    //     bool _internal_add_mir_cuts() const;
    //     void _internal_set_add_mir_cuts( bool value );

    // public:
    //     // optional bool add_zero_half_cuts = 169 [default = true];
    //     bool has_add_zero_half_cuts() const;

    // private:
    //     bool _internal_has_add_zero_half_cuts() const;

    // public:
    //     void clear_add_zero_half_cuts();
    //     bool add_zero_half_cuts() const;
    //     void set_add_zero_half_cuts( bool value );

    // private:
    //     bool _internal_add_zero_half_cuts() const;
    //     void _internal_set_add_zero_half_cuts( bool value );

    // public:
    //     // optional bool add_clique_cuts = 172 [default = true];
    //     bool has_add_clique_cuts() const;

    // private:
    //     bool _internal_has_add_clique_cuts() const;

    // public:
    //     void clear_add_clique_cuts();
    //     bool add_clique_cuts() const;
    //     void set_add_clique_cuts( bool value );

    // private:
    //     bool _internal_add_clique_cuts() const;
    //     void _internal_set_add_clique_cuts( bool value );

    // public:
    //     // optional bool add_lin_max_cuts = 152 [default = true];
    //     bool has_add_lin_max_cuts() const;

    // private:
    //     bool _internal_has_add_lin_max_cuts() const;

    // public:
    //     void clear_add_lin_max_cuts();
    //     bool add_lin_max_cuts() const;
    //     void set_add_lin_max_cuts( bool value );

    // private:
    //     bool _internal_add_lin_max_cuts() const;
    //     void _internal_set_add_lin_max_cuts( bool value );

    // public:
    //     // optional double cut_max_active_count_value = 155 [default = 10000000000];
    //     bool has_cut_max_active_count_value() const;

    // private:
    //     bool _internal_has_cut_max_active_count_value() const;

    // public:
    //     void   clear_cut_max_active_count_value();
    //     double cut_max_active_count_value() const;
    //     void   set_cut_max_active_count_value( double value );

    // private:
    //     double _internal_cut_max_active_count_value() const;
    //     void   _internal_set_cut_max_active_count_value( double value );

    // public:
    //     // optional int32 max_cut_rounds_at_level_zero = 154 [default = 1];
    //     bool has_max_cut_rounds_at_level_zero() const;

    // private:
    //     bool _internal_has_max_cut_rounds_at_level_zero() const;

    // public:
    //     void    clear_max_cut_rounds_at_level_zero();
    //     int32_t max_cut_rounds_at_level_zero() const;
    //     void    set_max_cut_rounds_at_level_zero( int32_t value );

    // private:
    //     int32_t _internal_max_cut_rounds_at_level_zero() const;
    //     void    _internal_set_max_cut_rounds_at_level_zero( int32_t value );

    // public:
    //     // optional int32 cut_cleanup_target = 157 [default = 1000];
    //     bool has_cut_cleanup_target() const;

    // private:
    //     bool _internal_has_cut_cleanup_target() const;

    // public:
    //     void    clear_cut_cleanup_target();
    //     int32_t cut_cleanup_target() const;
    //     void    set_cut_cleanup_target( int32_t value );

    // private:
    //     int32_t _internal_cut_cleanup_target() const;
    //     void    _internal_set_cut_cleanup_target( int32_t value );

    // public:
    //     // optional double cut_active_count_decay = 156 [default = 0.8];
    //     bool has_cut_active_count_decay() const;

    // private:
    //     bool _internal_has_cut_active_count_decay() const;

    // public:
    //     void   clear_cut_active_count_decay();
    //     double cut_active_count_decay() const;
    //     void   set_cut_active_count_decay( double value );

    // private:
    //     double _internal_cut_active_count_decay() const;
    //     void   _internal_set_cut_active_count_decay( double value );

    // public:
    //     // optional double absolute_gap_limit = 159 [default = 0.0001];
    //     bool has_absolute_gap_limit() const;

    // private:
    //     bool _internal_has_absolute_gap_limit() const;

    // public:
    //     void   clear_absolute_gap_limit();
    //     double absolute_gap_limit() const;
    //     void   set_absolute_gap_limit( double value );

    // private:
    //     double _internal_absolute_gap_limit() const;
    //     void   _internal_set_absolute_gap_limit( double value );

    // public:
    //     // optional .operations_research.sat.SatParameters.FPRoundingMethod fp_rounding = 165 [default = PROPAGATION_ASSISTED];
    //     bool has_fp_rounding() const;

    // private:
    //     bool _internal_has_fp_rounding() const;

    // public:
    //     void                                                       clear_fp_rounding();
    //     ::operations_research::sat::SatParameters_FPRoundingMethod fp_rounding() const;
    //     void                                                       set_fp_rounding( ::operations_research::sat::SatParameters_FPRoundingMethod value );

    // private:
    //     ::operations_research::sat::SatParameters_FPRoundingMethod _internal_fp_rounding() const;
    //     void                                                       _internal_set_fp_rounding( ::operations_research::sat::SatParameters_FPRoundingMethod value );

    // public:
    //     // optional bool find_big_linear_overlap = 234 [default = true];
    //     bool has_find_big_linear_overlap() const;

    // private:
    //     bool _internal_has_find_big_linear_overlap() const;

    // public:
    //     void clear_find_big_linear_overlap();
    //     bool find_big_linear_overlap() const;
    //     void set_find_big_linear_overlap( bool value );

    // private:
    //     bool _internal_find_big_linear_overlap() const;
    //     void _internal_set_find_big_linear_overlap( bool value );

    // public:
    //     // optional bool share_objective_bounds = 113 [default = true];
    //     bool has_share_objective_bounds() const;

    // private:
    //     bool _internal_has_share_objective_bounds() const;

    // public:
    //     void clear_share_objective_bounds();
    //     bool share_objective_bounds() const;
    //     void set_share_objective_bounds( bool value );

    // private:
    //     bool _internal_share_objective_bounds() const;
    //     void _internal_set_share_objective_bounds( bool value );

    // public:
    //     // optional bool share_level_zero_bounds = 114 [default = true];
    //     bool has_share_level_zero_bounds() const;

    // private:
    //     bool _internal_has_share_level_zero_bounds() const;

    // public:
    //     void clear_share_level_zero_bounds();
    //     bool share_level_zero_bounds() const;
    //     void set_share_level_zero_bounds( bool value );

    // private:
    //     bool _internal_share_level_zero_bounds() const;
    //     void _internal_set_share_level_zero_bounds( bool value );

    // public:
    //     // optional bool share_binary_clauses = 203 [default = true];
    //     bool has_share_binary_clauses() const;

    // private:
    //     bool _internal_has_share_binary_clauses() const;

    // public:
    //     void clear_share_binary_clauses();
    //     bool share_binary_clauses() const;
    //     void set_share_binary_clauses( bool value );

    // private:
    //     bool _internal_share_binary_clauses() const;
    //     void _internal_set_share_binary_clauses( bool value );

    // public:
    //     // optional int32 polarity_rephase_increment = 168 [default = 1000];
    //     bool has_polarity_rephase_increment() const;

    // private:
    //     bool _internal_has_polarity_rephase_increment() const;

    // public:
    //     void    clear_polarity_rephase_increment();
    //     int32_t polarity_rephase_increment() const;
    //     void    set_polarity_rephase_increment( int32_t value );

    // private:
    //     int32_t _internal_polarity_rephase_increment() const;
    //     void    _internal_set_polarity_rephase_increment( int32_t value );

    // public:
    //     // optional bool cp_model_use_sat_presolve = 93 [default = true];
    //     bool has_cp_model_use_sat_presolve() const;

    // private:
    //     bool _internal_has_cp_model_use_sat_presolve() const;

    // public:
    //     void clear_cp_model_use_sat_presolve();
    //     bool cp_model_use_sat_presolve() const;
    //     void set_cp_model_use_sat_presolve( bool value );

    // private:
    //     bool _internal_cp_model_use_sat_presolve() const;
    //     void _internal_set_cp_model_use_sat_presolve( bool value );

    // public:
    //     // optional bool expand_reservoir_constraints = 182 [default = true];
    //     bool has_expand_reservoir_constraints() const;

    // private:
    //     bool _internal_has_expand_reservoir_constraints() const;

    // public:
    //     void clear_expand_reservoir_constraints();
    //     bool expand_reservoir_constraints() const;
    //     void set_expand_reservoir_constraints( bool value );

    // private:
    //     bool _internal_expand_reservoir_constraints() const;
    //     void _internal_set_expand_reservoir_constraints( bool value );

    // public:
    //     // optional bool ignore_names = 202 [default = true];
    //     bool has_ignore_names() const;

    // private:
    //     bool _internal_has_ignore_names() const;

    // public:
    //     void clear_ignore_names();
    //     bool ignore_names() const;
    //     void set_ignore_names( bool value );

    // private:
    //     bool _internal_ignore_names() const;
    //     void _internal_set_ignore_names( bool value );

    // public:
    //     // optional bool infer_all_diffs = 233 [default = true];
    //     bool has_infer_all_diffs() const;

    // private:
    //     bool _internal_has_infer_all_diffs() const;

    // public:
    //     void clear_infer_all_diffs();
    //     bool infer_all_diffs() const;
    //     void set_infer_all_diffs( bool value );

    // private:
    //     bool _internal_infer_all_diffs() const;
    //     void _internal_set_infer_all_diffs( bool value );

    // public:
    //     // optional bool convert_intervals = 177 [default = true];
    //     bool has_convert_intervals() const;

    // private:
    //     bool _internal_has_convert_intervals() const;

    // public:
    //     void clear_convert_intervals();
    //     bool convert_intervals() const;
    //     void set_convert_intervals( bool value );

    // private:
    //     bool _internal_convert_intervals() const;
    //     void _internal_set_convert_intervals( bool value );

    // public:
    //     // optional bool mip_automatically_scale_variables = 166 [default = true];
    //     bool has_mip_automatically_scale_variables() const;

    // private:
    //     bool _internal_has_mip_automatically_scale_variables() const;

    // public:
    //     void clear_mip_automatically_scale_variables();
    //     bool mip_automatically_scale_variables() const;
    //     void set_mip_automatically_scale_variables( bool value );

    // private:
    //     bool _internal_mip_automatically_scale_variables() const;
    //     void _internal_set_mip_automatically_scale_variables( bool value );

    // public:
    //     // optional bool mip_compute_true_objective_bound = 198 [default = true];
    //     bool has_mip_compute_true_objective_bound() const;

    // private:
    //     bool _internal_has_mip_compute_true_objective_bound() const;

    // public:
    //     void clear_mip_compute_true_objective_bound();
    //     bool mip_compute_true_objective_bound() const;
    //     void set_mip_compute_true_objective_bound( bool value );

    // private:
    //     bool _internal_mip_compute_true_objective_bound() const;
    //     void _internal_set_mip_compute_true_objective_bound( bool value );

    // public:
    //     // optional int32 symmetry_level = 183 [default = 2];
    //     bool has_symmetry_level() const;

    // private:
    //     bool _internal_has_symmetry_level() const;

    // public:
    //     void    clear_symmetry_level();
    //     int32_t symmetry_level() const;
    //     void    set_symmetry_level( int32_t value );

    // private:
    //     int32_t _internal_symmetry_level() const;
    //     void    _internal_set_symmetry_level( int32_t value );

    // public:
    //     // optional double clause_cleanup_ratio = 190 [default = 0.5];
    //     bool has_clause_cleanup_ratio() const;

    // private:
    //     bool _internal_has_clause_cleanup_ratio() const;

    // public:
    //     void   clear_clause_cleanup_ratio();
    //     double clause_cleanup_ratio() const;
    //     void   set_clause_cleanup_ratio( double value );

    // private:
    //     double _internal_clause_cleanup_ratio() const;
    //     void   _internal_set_clause_cleanup_ratio( double value );

    // public:
    //     // optional int32 max_domain_size_when_encoding_eq_neq_constraints = 191 [default = 16];
    //     bool has_max_domain_size_when_encoding_eq_neq_constraints() const;

    // private:
    //     bool _internal_has_max_domain_size_when_encoding_eq_neq_constraints() const;

    // public:
    //     void    clear_max_domain_size_when_encoding_eq_neq_constraints();
    //     int32_t max_domain_size_when_encoding_eq_neq_constraints() const;
    //     void    set_max_domain_size_when_encoding_eq_neq_constraints( int32_t value );

    // private:
    //     int32_t _internal_max_domain_size_when_encoding_eq_neq_constraints() const;
    //     void    _internal_set_max_domain_size_when_encoding_eq_neq_constraints( int32_t value );

    // public:
    //     // optional int32 solution_pool_size = 193 [default = 3];
    //     bool has_solution_pool_size() const;

    // private:
    //     bool _internal_has_solution_pool_size() const;

    // public:
    //     void    clear_solution_pool_size();
    //     int32_t solution_pool_size() const;
    //     void    set_solution_pool_size( int32_t value );

    // private:
    //     int32_t _internal_solution_pool_size() const;
    //     void    _internal_set_solution_pool_size( int32_t value );

    // public:
    //     // optional double mip_max_valid_magnitude = 199 [default = 1e+030];
    //     bool has_mip_max_valid_magnitude() const;

    // private:
    //     bool _internal_has_mip_max_valid_magnitude() const;

    // public:
    //     void   clear_mip_max_valid_magnitude();
    //     double mip_max_valid_magnitude() const;
    //     void   set_mip_max_valid_magnitude( double value );

    // private:
    //     double _internal_mip_max_valid_magnitude() const;
    //     void   _internal_set_mip_max_valid_magnitude( double value );

    // public:
    //     // optional int64 presolve_inclusion_work_limit = 201 [default = 100000000];
    //     bool has_presolve_inclusion_work_limit() const;

    // private:
    //     bool _internal_has_presolve_inclusion_work_limit() const;

    // public:
    //     void    clear_presolve_inclusion_work_limit();
    //     int64_t presolve_inclusion_work_limit() const;
    //     void    set_presolve_inclusion_work_limit( int64_t value );

    // private:
    //     int64_t _internal_presolve_inclusion_work_limit() const;
    //     void    _internal_set_presolve_inclusion_work_limit( int64_t value );

    // public:
    //     // optional int32 cut_level = 196 [default = 1];
    //     bool has_cut_level() const;

    // private:
    //     bool _internal_has_cut_level() const;

    // public:
    //     void    clear_cut_level();
    //     int32_t cut_level() const;
    //     void    set_cut_level( int32_t value );

    // private:
    //     int32_t _internal_cut_level() const;
    //     void    _internal_set_cut_level( int32_t value );

    // public:
    //     // optional int32 min_num_lns_workers = 211 [default = 2];
    //     bool has_min_num_lns_workers() const;

    // private:
    //     bool _internal_has_min_num_lns_workers() const;

    // public:
    //     void    clear_min_num_lns_workers();
    //     int32_t min_num_lns_workers() const;
    //     void    set_min_num_lns_workers( int32_t value );

    // private:
    //     int32_t _internal_min_num_lns_workers() const;
    //     void    _internal_set_min_num_lns_workers( int32_t value );

    // public:
    //     // optional double shaving_search_deterministic_time = 205 [default = 0.001];
    //     bool has_shaving_search_deterministic_time() const;

    // private:
    //     bool _internal_has_shaving_search_deterministic_time() const;

    // public:
    //     void   clear_shaving_search_deterministic_time();
    //     double shaving_search_deterministic_time() const;
    //     void   set_shaving_search_deterministic_time( double value );

    // private:
    //     double _internal_shaving_search_deterministic_time() const;
    //     void   _internal_set_shaving_search_deterministic_time( double value );

    // public:
    //     // optional double log_frequency_in_seconds = 212 [default = -1];
    //     bool has_log_frequency_in_seconds() const;

    // private:
    //     bool _internal_has_log_frequency_in_seconds() const;

    // public:
    //     void   clear_log_frequency_in_seconds();
    //     double log_frequency_in_seconds() const;
    //     void   set_log_frequency_in_seconds( double value );

    // private:
    //     double _internal_log_frequency_in_seconds() const;
    //     void   _internal_set_log_frequency_in_seconds( double value );

    // public:
    //     // optional double model_reduction_log_frequency_in_seconds = 218 [default = 5];
    //     bool has_model_reduction_log_frequency_in_seconds() const;

    // private:
    //     bool _internal_has_model_reduction_log_frequency_in_seconds() const;

    // public:
    //     void   clear_model_reduction_log_frequency_in_seconds();
    //     double model_reduction_log_frequency_in_seconds() const;
    //     void   set_model_reduction_log_frequency_in_seconds( double value );

    // private:
    //     double _internal_model_reduction_log_frequency_in_seconds() const;
    //     void   _internal_set_model_reduction_log_frequency_in_seconds( double value );

    // public:
    //     // optional double propagation_loop_detection_factor = 221 [default = 10];
    //     bool has_propagation_loop_detection_factor() const;

    // private:
    //     bool _internal_has_propagation_loop_detection_factor() const;

    // public:
    //     void   clear_propagation_loop_detection_factor();
    //     double propagation_loop_detection_factor() const;
    //     void   set_propagation_loop_detection_factor( double value );

    // private:
    //     double _internal_propagation_loop_detection_factor() const;
    //     void   _internal_set_propagation_loop_detection_factor( double value );

    // public:
    //     // optional int32 table_compression_level = 217 [default = 2];
    //     bool has_table_compression_level() const;

    // private:
    //     bool _internal_has_table_compression_level() const;

    // public:
    //     void    clear_table_compression_level();
    //     int32_t table_compression_level() const;
    //     void    set_table_compression_level( int32_t value );

    // private:
    //     int32_t _internal_table_compression_level() const;
    //     void    _internal_set_table_compression_level( int32_t value );

    // public:
    //     // optional int32 root_lp_iterations = 227 [default = 2000];
    //     bool has_root_lp_iterations() const;

    // private:
    //     bool _internal_has_root_lp_iterations() const;

    // public:
    //     void    clear_root_lp_iterations();
    //     int32_t root_lp_iterations() const;
    //     void    set_root_lp_iterations( int32_t value );

    // private:
    //     int32_t _internal_root_lp_iterations() const;
    //     void    _internal_set_root_lp_iterations( int32_t value );

    // public:
    //     // optional double probing_deterministic_time_limit = 226 [default = 1];
    //     bool has_probing_deterministic_time_limit() const;

    // private:
    //     bool _internal_has_probing_deterministic_time_limit() const;

    // public:
    //     void   clear_probing_deterministic_time_limit();
    //     double probing_deterministic_time_limit() const;
    //     void   set_probing_deterministic_time_limit( double value );

    // private:
    //     double _internal_probing_deterministic_time_limit() const;
    //     void   _internal_set_probing_deterministic_time_limit( double value );

    // public:
    //     // optional int32 max_size_to_create_precedence_literals_in_disjunctive = 229 [default = 60];
    //     bool has_max_size_to_create_precedence_literals_in_disjunctive() const;

    // private:
    //     bool _internal_has_max_size_to_create_precedence_literals_in_disjunctive() const;

    // public:
    //     void    clear_max_size_to_create_precedence_literals_in_disjunctive();
    //     int32_t max_size_to_create_precedence_literals_in_disjunctive() const;
    //     void    set_max_size_to_create_precedence_literals_in_disjunctive( int32_t value );

    // private:
    //     int32_t _internal_max_size_to_create_precedence_literals_in_disjunctive() const;
    //     void    _internal_set_max_size_to_create_precedence_literals_in_disjunctive( int32_t value );

    // public:
    //     // optional int32 objective_lns_min_size = 231 [default = 2147483647];
    //     bool has_objective_lns_min_size() const;

    // private:
    //     bool _internal_has_objective_lns_min_size() const;

    // public:
    //     void    clear_objective_lns_min_size();
    //     int32_t objective_lns_min_size() const;
    //     void    set_objective_lns_min_size( int32_t value );

    // private:
    //     int32_t _internal_objective_lns_min_size() const;
    //     void    _internal_set_objective_lns_min_size( int32_t value );

    // public:
    //     // optional double mip_drop_tolerance = 232 [default = 1e-016];
    //     bool has_mip_drop_tolerance() const;

    // private:
    //     bool _internal_has_mip_drop_tolerance() const;

    // public:
    //     void   clear_mip_drop_tolerance();
    //     double mip_drop_tolerance() const;
    //     void   set_mip_drop_tolerance( double value );

    // private:
    //     double _internal_mip_drop_tolerance() const;
    //     void   _internal_set_mip_drop_tolerance( double value );

    // public:
    //     // @@protoc_insertion_point(class_scope:operations_research.sat.SatParameters)
    // private:
    //     class _Internal;

    //     template < typename T >
    //     friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
    //     typedef void InternalArenaConstructable_;
    //     typedef void DestructorSkippable_;
    //     struct Impl_
    //     {
    //         ::PROTOBUF_NAMESPACE_ID::internal::HasBits< 7 >                                        _has_bits_;
    //         mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize                                  _cached_size_;
    //         ::PROTOBUF_NAMESPACE_ID::RepeatedField< int >                                          restart_algorithms_;
    //         ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< std::string >                               subsolvers_;
    //         ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< std::string >                               ignore_subsolvers_;
    //         ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::sat::SatParameters > subsolver_params_;
    //         ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< std::string >                               extra_subsolvers_;
    //         static const ::PROTOBUF_NAMESPACE_ID::internal::LazyString                             _i_give_permission_to_break_this_code_default_default_restart_algorithms_;
    //         ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr                                      default_restart_algorithms_;
    //         ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr                                      name_;
    //         ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr                                      log_prefix_;
    //         int                                                                                    preferred_variable_order_;
    //         int32_t                                                                                clause_cleanup_target_;
    //         double                                                                                 random_branches_ratio_;
    //         double                                                                                 random_polarity_ratio_;
    //         int                                                                                    max_sat_assumption_order_;
    //         int                                                                                    clause_cleanup_protection_;
    //         int                                                                                    clause_cleanup_ordering_;
    //         int32_t                                                                                num_conflicts_before_strategy_changes_;
    //         double                                                                                 strategy_change_increase_ratio_;
    //         double                                                                                 initial_variables_activity_;
    //         int                                                                                    search_branching_;
    //         bool                                                                                   use_erwa_heuristic_;
    //         bool                                                                                   also_bump_variables_in_conflict_reasons_;
    //         bool                                                                                   use_blocking_restart_;
    //         bool                                                                                   permute_variable_randomly_;
    //         int64_t                                                                                search_randomization_tolerance_;
    //         int32_t                                                                                num_search_workers_;
    //         bool                                                                                   use_lns_only_;
    //         bool                                                                                   diversify_lns_params_;
    //         bool                                                                                   randomize_search_;
    //         bool                                                                                   use_optional_variables_;
    //         bool                                                                                   use_pb_resolution_;
    //         bool                                                                                   minimize_reduction_during_pb_resolution_;
    //         bool                                                                                   use_sat_inprocessing_;
    //         bool                                                                                   detect_table_with_cost_;
    //         bool                                                                                   optimize_with_lb_tree_search_;
    //         bool                                                                                   optimize_with_max_hs_;
    //         bool                                                                                   enumerate_all_solutions_;
    //         bool                                                                                   keep_all_feasible_solutions_in_presolve_;
    //         int32_t                                                                                interleave_batch_size_;
    //         bool                                                                                   interleave_search_;
    //         bool                                                                                   debug_postsolve_with_full_solver_;
    //         bool                                                                                   debug_crash_on_bad_hint_;
    //         bool                                                                                   max_sat_reverse_assumption_order_;
    //         int64_t                                                                                probing_period_at_root_;
    //         bool                                                                                   fill_tightened_domains_in_response_;
    //         bool                                                                                   fill_additional_solutions_in_response_;
    //         bool                                                                                   stop_after_first_solution_;
    //         bool                                                                                   stop_after_presolve_;
    //         bool                                                                                   permute_presolve_constraint_order_;
    //         bool                                                                                   use_absl_random_;
    //         bool                                                                                   log_search_progress_;
    //         bool                                                                                   log_to_response_;
    //         bool                                                                                   use_strong_propagation_in_disjunctive_;
    //         bool                                                                                   use_overload_checker_in_cumulative_;
    //         bool                                                                                   use_timetable_edge_finding_in_cumulative_;
    //         bool                                                                                   use_hard_precedences_in_cumulative_;
    //         int32_t                                                                                debug_max_num_presolve_operations_;
    //         double                                                                                 relative_gap_limit_;
    //         bool                                                                                   exploit_relaxation_solution_;
    //         bool                                                                                   use_probing_search_;
    //         bool                                                                                   use_objective_lb_search_;
    //         bool                                                                                   optimize_with_core_;
    //         bool                                                                                   use_branching_in_lp_;
    //         bool                                                                                   use_combined_no_overlap_;
    //         bool                                                                                   polish_lp_solution_;
    //         bool                                                                                   new_linear_propagation_;
    //         bool                                                                                   add_objective_cut_;
    //         bool                                                                                   repair_hint_;
    //         bool                                                                                   fix_variables_to_their_hinted_value_;
    //         bool                                                                                   exploit_best_solution_;
    //         bool                                                                                   exploit_all_precedences_;
    //         bool                                                                                   use_timetabling_in_no_overlap_2d_;
    //         bool                                                                                   use_energetic_reasoning_in_no_overlap_2d_;
    //         bool                                                                                   only_add_cuts_at_level_zero_;
    //         bool                                                                                   expand_alldiff_constraints_;
    //         bool                                                                                   disable_constraint_expansion_;
    //         bool                                                                                   encode_complex_linear_constraint_with_integer_;
    //         bool                                                                                   presolve_extract_integer_enforcement_;
    //         int32_t                                                                                num_workers_;
    //         bool                                                                                   mip_scale_large_domain_;
    //         bool                                                                                   only_solve_ip_;
    //         int                                                                                    initial_polarity_;
    //         int                                                                                    minimization_algorithm_;
    //         double                                                                                 variable_activity_decay_;
    //         double                                                                                 max_variable_activity_value_;
    //         double                                                                                 clause_activity_decay_;
    //         int32_t                                                                                clause_cleanup_period_;
    //         int32_t                                                                                glucose_decay_increment_period_;
    //         double                                                                                 max_clause_activity_value_;
    //         double                                                                                 glucose_max_decay_;
    //         double                                                                                 glucose_decay_increment_;
    //         int32_t                                                                                restart_period_;
    //         int32_t                                                                                random_seed_;
    //         double                                                                                 max_time_in_seconds_;
    //         int64_t                                                                                max_number_of_conflicts_;
    //         int64_t                                                                                max_memory_in_mb_;
    //         int                                                                                    binary_minimization_algorithm_;
    //         int32_t                                                                                pb_cleanup_increment_;
    //         double                                                                                 pb_cleanup_ratio_;
    //         int                                                                                    max_sat_stratification_;
    //         int32_t                                                                                presolve_bve_threshold_;
    //         double                                                                                 presolve_probing_deterministic_time_limit_;
    //         int32_t                                                                                presolve_bve_clause_weight_;
    //         int32_t                                                                                clause_cleanup_lbd_bound_;
    //         double                                                                                 restart_dl_average_ratio_;
    //         int32_t                                                                                restart_running_window_size_;
    //         bool                                                                                   use_optimization_hints_;
    //         bool                                                                                   minimize_core_;
    //         bool                                                                                   find_multiple_cores_;
    //         bool                                                                                   cover_optimization_;
    //         double                                                                                 blocking_restart_multiplier_;
    //         double                                                                                 max_deterministic_time_;
    //         int32_t                                                                                blocking_restart_window_size_;
    //         int32_t                                                                                presolve_bva_threshold_;
    //         double                                                                                 restart_lbd_average_ratio_;
    //         bool                                                                                   count_assumption_levels_in_lbd_;
    //         bool                                                                                   presolve_blocked_clause_;
    //         bool                                                                                   presolve_use_bva_;
    //         bool                                                                                   cp_model_presolve_;
    //         int32_t                                                                                linearization_level_;
    //         int32_t                                                                                max_num_cuts_;
    //         int32_t                                                                                minimize_with_propagation_restart_period_;
    //         int32_t                                                                                minimize_with_propagation_num_decisions_;
    //         int32_t                                                                                binary_search_num_conflicts_;
    //         int32_t                                                                                boolean_encoding_level_;
    //         int32_t                                                                                cp_model_probing_level_;
    //         double                                                                                 min_orthogonality_for_lp_constraints_;
    //         bool                                                                                   add_lp_constraints_lazily_;
    //         bool                                                                                   exploit_integer_lp_solution_;
    //         bool                                                                                   exploit_all_lp_solution_;
    //         bool                                                                                   exploit_objective_;
    //         bool                                                                                   use_phase_saving_;
    //         bool                                                                                   subsumption_during_conflict_analysis_;
    //         bool                                                                                   log_subsolver_statistics_;
    //         bool                                                                                   log_to_stdout_;
    //         int32_t                                                                                max_integer_rounding_scaling_;
    //         int32_t                                                                                max_consecutive_inactive_count_;
    //         bool                                                                                   use_precedences_in_disjunctive_constraint_;
    //         bool                                                                                   use_disjunctive_constraint_in_cumulative_;
    //         bool                                                                                   use_dual_scheduling_heuristics_;
    //         bool                                                                                   add_cg_cuts_;
    //         int32_t                                                                                new_constraints_batch_size_;
    //         int64_t                                                                                pseudo_cost_reliability_threshold_;
    //         double                                                                                 mip_max_bound_;
    //         double                                                                                 mip_var_scaling_;
    //         double                                                                                 mip_wanted_precision_;
    //         double                                                                                 mip_check_precision_;
    //         int32_t                                                                                mip_max_activity_exponent_;
    //         bool                                                                                   use_shaving_in_probing_search_;
    //         bool                                                                                   instantiate_all_variables_;
    //         bool                                                                                   auto_detect_greater_than_at_least_one_of_;
    //         bool                                                                                   use_rins_lns_;
    //         int32_t                                                                                max_presolve_iterations_;
    //         bool                                                                                   use_feasibility_pump_;
    //         bool                                                                                   use_exact_lp_reason_;
    //         bool                                                                                   catch_sigint_signal_;
    //         bool                                                                                   use_implied_bounds_;
    //         double                                                                                 merge_no_overlap_work_limit_;
    //         double                                                                                 merge_at_most_one_work_limit_;
    //         int32_t                                                                                presolve_substitution_level_;
    //         int32_t                                                                                max_all_diff_cut_size_;
    //         int32_t                                                                                hint_conflict_limit_;
    //         bool                                                                                   add_mir_cuts_;
    //         bool                                                                                   add_zero_half_cuts_;
    //         bool                                                                                   add_clique_cuts_;
    //         bool                                                                                   add_lin_max_cuts_;
    //         double                                                                                 cut_max_active_count_value_;
    //         int32_t                                                                                max_cut_rounds_at_level_zero_;
    //         int32_t                                                                                cut_cleanup_target_;
    //         double                                                                                 cut_active_count_decay_;
    //         double                                                                                 absolute_gap_limit_;
    //         int                                                                                    fp_rounding_;
    //         bool                                                                                   find_big_linear_overlap_;
    //         bool                                                                                   share_objective_bounds_;
    //         bool                                                                                   share_level_zero_bounds_;
    //         bool                                                                                   share_binary_clauses_;
    //         int32_t                                                                                polarity_rephase_increment_;
    //         bool                                                                                   cp_model_use_sat_presolve_;
    //         bool                                                                                   expand_reservoir_constraints_;
    //         bool                                                                                   ignore_names_;
    //         bool                                                                                   infer_all_diffs_;
    //         bool                                                                                   convert_intervals_;
    //         bool                                                                                   mip_automatically_scale_variables_;
    //         bool                                                                                   mip_compute_true_objective_bound_;
    //         int32_t                                                                                symmetry_level_;
    //         double                                                                                 clause_cleanup_ratio_;
    //         int32_t                                                                                max_domain_size_when_encoding_eq_neq_constraints_;
    //         int32_t                                                                                solution_pool_size_;
    //         double                                                                                 mip_max_valid_magnitude_;
    //         int64_t                                                                                presolve_inclusion_work_limit_;
    //         int32_t                                                                                cut_level_;
    //         int32_t                                                                                min_num_lns_workers_;
    //         double                                                                                 shaving_search_deterministic_time_;
    //         double                                                                                 log_frequency_in_seconds_;
    //         double                                                                                 model_reduction_log_frequency_in_seconds_;
    //         double                                                                                 propagation_loop_detection_factor_;
    //         int32_t                                                                                table_compression_level_;
    //         int32_t                                                                                root_lp_iterations_;
    //         double                                                                                 probing_deterministic_time_limit_;
    //         int32_t                                                                                max_size_to_create_precedence_literals_in_disjunctive_;
    //         int32_t                                                                                objective_lns_min_size_;
    //         double                                                                                 mip_drop_tolerance_;
    //     };
    //     union
    //     {
    //         Impl_ _impl_;
    //     };
    //     friend struct ::TableStruct_ortools_2fsat_2fsat_5fparameters_2eproto;
};

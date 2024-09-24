
export class SatParameters // final : public ::google::protobuf::Message
{
    //    public:
    //        inline SatParameters()
    //            : SatParameters( nullptr ) {}
    /**
     * C++ inline SatParameters()
     *         : SatParameters( nullptr ) {}
     */
    constructor();

    //        ~SatParameters() override;
    //        template < typename = void >
    //        explicit PROTOBUF_CONSTEXPR SatParameters(
    //            ::google::protobuf::internal::ConstantInitialized );

    //        inline SatParameters( const SatParameters& from )
    //            : SatParameters( nullptr, from ) {}
    //        inline SatParameters( SatParameters&& from ) noexcept
    //            : SatParameters( nullptr, std::move( from ) ) {}
    //        inline SatParameters& operator=( const SatParameters& from )
    //        {
    //            CopyFrom( from );
    //            return *this;
    //        }
    //        inline SatParameters& operator=( SatParameters&& from ) noexcept
    //        {
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
    //        static const SatParameters& default_instance()
    //        {
    //            return *internal_default_instance();
    //        }
    //        static inline const SatParameters* internal_default_instance()
    //        {
    //            return reinterpret_cast< const SatParameters* >(
    //                &_SatParameters_default_instance_ );
    //        }
    //        static constexpr int kIndexInFileMessages = 0;
    //        friend void          swap( SatParameters& a, SatParameters& b )
    //        {
    //            a.Swap( &b );
    //        }
    //        inline void Swap( SatParameters* other )
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
    //        void UnsafeArenaSwap( SatParameters* other )
    //        {
    //            if ( other == this ) return;
    //            ABSL_DCHECK( GetArena() == other->GetArena() );
    //            InternalSwap( other );
    //        }

    //        // implements Message ----------------------------------------------

    //        SatParameters* New( ::google::protobuf::Arena* arena = nullptr ) const final
    //        {
    //            return ::google::protobuf::Message::DefaultConstruct< SatParameters >( arena );
    //        }
    //        using ::google::protobuf::Message::CopyFrom;
    //        void CopyFrom( const SatParameters& from );
    //        using ::google::protobuf::Message::MergeFrom;
    //        void MergeFrom( const SatParameters& from )
    //        {
    //            SatParameters::MergeImpl( *this, from );
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
    //        void InternalSwap( SatParameters* other );

    //    private:
    //        friend class ::google::protobuf::internal::AnyMetadata;
    //        static ::absl::string_view FullMessageName()
    //        {
    //            return "operations_research.sat.SatParameters";
    //        }

    //    protected:
    //        explicit SatParameters( ::google::protobuf::Arena* arena );
    //        SatParameters( ::google::protobuf::Arena* arena, const SatParameters& from );
    //        SatParameters( ::google::protobuf::Arena* arena, SatParameters&& from ) noexcept
    //            : SatParameters( arena )
    //        {
    //            *this = ::std::move( from );
    //        }
    //        const ::google::protobuf::MessageLite::ClassData* GetClassData()
    //            const final;

    //    public:
    //        ::google::protobuf::Metadata GetMetadata() const final;
    //        // nested types ----------------------------------------------------
    //        using VariableOrder                             = SatParameters_VariableOrder;
    //        static constexpr VariableOrder IN_ORDER         = SatParameters_VariableOrder_IN_ORDER;
    //        static constexpr VariableOrder IN_REVERSE_ORDER = SatParameters_VariableOrder_IN_REVERSE_ORDER;
    //        static constexpr VariableOrder IN_RANDOM_ORDER  = SatParameters_VariableOrder_IN_RANDOM_ORDER;
    //        static inline bool             VariableOrder_IsValid( int value )
    //        {
    //            return SatParameters_VariableOrder_IsValid( value );
    //        }
    //        static constexpr VariableOrder                          VariableOrder_MIN       = SatParameters_VariableOrder_VariableOrder_MIN;
    //        static constexpr VariableOrder                          VariableOrder_MAX       = SatParameters_VariableOrder_VariableOrder_MAX;
    //        static constexpr int                                    VariableOrder_ARRAYSIZE = SatParameters_VariableOrder_VariableOrder_ARRAYSIZE;
    //        static inline const ::google::protobuf::EnumDescriptor* VariableOrder_descriptor()
    //        {
    //            return SatParameters_VariableOrder_descriptor();
    //        }
    //        template < typename T >
    //        static inline const std::string& VariableOrder_Name( T value )
    //        {
    //            return SatParameters_VariableOrder_Name( value );
    //        }
    //        static inline bool VariableOrder_Parse( absl::string_view name, VariableOrder* value )
    //        {
    //            return SatParameters_VariableOrder_Parse( name, value );
    //        }
    //        using Polarity                            = SatParameters_Polarity;
    //        static constexpr Polarity POLARITY_TRUE   = SatParameters_Polarity_POLARITY_TRUE;
    //        static constexpr Polarity POLARITY_FALSE  = SatParameters_Polarity_POLARITY_FALSE;
    //        static constexpr Polarity POLARITY_RANDOM = SatParameters_Polarity_POLARITY_RANDOM;
    //        static inline bool        Polarity_IsValid( int value )
    //        {
    //            return SatParameters_Polarity_IsValid( value );
    //        }
    //        static constexpr Polarity                               Polarity_MIN       = SatParameters_Polarity_Polarity_MIN;
    //        static constexpr Polarity                               Polarity_MAX       = SatParameters_Polarity_Polarity_MAX;
    //        static constexpr int                                    Polarity_ARRAYSIZE = SatParameters_Polarity_Polarity_ARRAYSIZE;
    //        static inline const ::google::protobuf::EnumDescriptor* Polarity_descriptor()
    //        {
    //            return SatParameters_Polarity_descriptor();
    //        }
    //        template < typename T >
    //        static inline const std::string& Polarity_Name( T value )
    //        {
    //            return SatParameters_Polarity_Name( value );
    //        }
    //        static inline bool Polarity_Parse( absl::string_view name, Polarity* value )
    //        {
    //            return SatParameters_Polarity_Parse( name, value );
    //        }
    //        using ConflictMinimizationAlgorithm                         = SatParameters_ConflictMinimizationAlgorithm;
    //        static constexpr ConflictMinimizationAlgorithm NONE         = SatParameters_ConflictMinimizationAlgorithm_NONE;
    //        static constexpr ConflictMinimizationAlgorithm SIMPLE       = SatParameters_ConflictMinimizationAlgorithm_SIMPLE;
    //        static constexpr ConflictMinimizationAlgorithm RECURSIVE    = SatParameters_ConflictMinimizationAlgorithm_RECURSIVE;
    //        static constexpr ConflictMinimizationAlgorithm EXPERIMENTAL = SatParameters_ConflictMinimizationAlgorithm_EXPERIMENTAL;
    //        static inline bool                             ConflictMinimizationAlgorithm_IsValid( int value )
    //        {
    //            return SatParameters_ConflictMinimizationAlgorithm_IsValid( value );
    //        }
    //        static constexpr ConflictMinimizationAlgorithm          ConflictMinimizationAlgorithm_MIN       = SatParameters_ConflictMinimizationAlgorithm_ConflictMinimizationAlgorithm_MIN;
    //        static constexpr ConflictMinimizationAlgorithm          ConflictMinimizationAlgorithm_MAX       = SatParameters_ConflictMinimizationAlgorithm_ConflictMinimizationAlgorithm_MAX;
    //        static constexpr int                                    ConflictMinimizationAlgorithm_ARRAYSIZE = SatParameters_ConflictMinimizationAlgorithm_ConflictMinimizationAlgorithm_ARRAYSIZE;
    //        static inline const ::google::protobuf::EnumDescriptor* ConflictMinimizationAlgorithm_descriptor()
    //        {
    //            return SatParameters_ConflictMinimizationAlgorithm_descriptor();
    //        }
    //        template < typename T >
    //        static inline const std::string& ConflictMinimizationAlgorithm_Name( T value )
    //        {
    //            return SatParameters_ConflictMinimizationAlgorithm_Name( value );
    //        }
    //        static inline bool ConflictMinimizationAlgorithm_Parse( absl::string_view name, ConflictMinimizationAlgorithm* value )
    //        {
    //            return SatParameters_ConflictMinimizationAlgorithm_Parse( name, value );
    //        }
    //        using BinaryMinizationAlgorithm                                                                = SatParameters_BinaryMinizationAlgorithm;
    //        static constexpr BinaryMinizationAlgorithm NO_BINARY_MINIMIZATION                              = SatParameters_BinaryMinizationAlgorithm_NO_BINARY_MINIMIZATION;
    //        static constexpr BinaryMinizationAlgorithm BINARY_MINIMIZATION_FIRST                           = SatParameters_BinaryMinizationAlgorithm_BINARY_MINIMIZATION_FIRST;
    //        static constexpr BinaryMinizationAlgorithm BINARY_MINIMIZATION_FIRST_WITH_TRANSITIVE_REDUCTION = SatParameters_BinaryMinizationAlgorithm_BINARY_MINIMIZATION_FIRST_WITH_TRANSITIVE_REDUCTION;
    //        static constexpr BinaryMinizationAlgorithm BINARY_MINIMIZATION_WITH_REACHABILITY               = SatParameters_BinaryMinizationAlgorithm_BINARY_MINIMIZATION_WITH_REACHABILITY;
    //        static constexpr BinaryMinizationAlgorithm EXPERIMENTAL_BINARY_MINIMIZATION                    = SatParameters_BinaryMinizationAlgorithm_EXPERIMENTAL_BINARY_MINIMIZATION;
    //        static inline bool                         BinaryMinizationAlgorithm_IsValid( int value )
    //        {
    //            return SatParameters_BinaryMinizationAlgorithm_IsValid( value );
    //        }
    //        static constexpr BinaryMinizationAlgorithm              BinaryMinizationAlgorithm_MIN       = SatParameters_BinaryMinizationAlgorithm_BinaryMinizationAlgorithm_MIN;
    //        static constexpr BinaryMinizationAlgorithm              BinaryMinizationAlgorithm_MAX       = SatParameters_BinaryMinizationAlgorithm_BinaryMinizationAlgorithm_MAX;
    //        static constexpr int                                    BinaryMinizationAlgorithm_ARRAYSIZE = SatParameters_BinaryMinizationAlgorithm_BinaryMinizationAlgorithm_ARRAYSIZE;
    //        static inline const ::google::protobuf::EnumDescriptor* BinaryMinizationAlgorithm_descriptor()
    //        {
    //            return SatParameters_BinaryMinizationAlgorithm_descriptor();
    //        }
    //        template < typename T >
    //        static inline const std::string& BinaryMinizationAlgorithm_Name( T value )
    //        {
    //            return SatParameters_BinaryMinizationAlgorithm_Name( value );
    //        }
    //        static inline bool BinaryMinizationAlgorithm_Parse( absl::string_view name, BinaryMinizationAlgorithm* value )
    //        {
    //            return SatParameters_BinaryMinizationAlgorithm_Parse( name, value );
    //        }
    //        using ClauseProtection                              = SatParameters_ClauseProtection;
    //        static constexpr ClauseProtection PROTECTION_NONE   = SatParameters_ClauseProtection_PROTECTION_NONE;
    //        static constexpr ClauseProtection PROTECTION_ALWAYS = SatParameters_ClauseProtection_PROTECTION_ALWAYS;
    //        static constexpr ClauseProtection PROTECTION_LBD    = SatParameters_ClauseProtection_PROTECTION_LBD;
    //        static inline bool                ClauseProtection_IsValid( int value )
    //        {
    //            return SatParameters_ClauseProtection_IsValid( value );
    //        }
    //        static constexpr ClauseProtection                       ClauseProtection_MIN       = SatParameters_ClauseProtection_ClauseProtection_MIN;
    //        static constexpr ClauseProtection                       ClauseProtection_MAX       = SatParameters_ClauseProtection_ClauseProtection_MAX;
    //        static constexpr int                                    ClauseProtection_ARRAYSIZE = SatParameters_ClauseProtection_ClauseProtection_ARRAYSIZE;
    //        static inline const ::google::protobuf::EnumDescriptor* ClauseProtection_descriptor()
    //        {
    //            return SatParameters_ClauseProtection_descriptor();
    //        }
    //        template < typename T >
    //        static inline const std::string& ClauseProtection_Name( T value )
    //        {
    //            return SatParameters_ClauseProtection_Name( value );
    //        }
    //        static inline bool ClauseProtection_Parse( absl::string_view name, ClauseProtection* value )
    //        {
    //            return SatParameters_ClauseProtection_Parse( name, value );
    //        }
    //        using ClauseOrdering                            = SatParameters_ClauseOrdering;
    //        static constexpr ClauseOrdering CLAUSE_ACTIVITY = SatParameters_ClauseOrdering_CLAUSE_ACTIVITY;
    //        static constexpr ClauseOrdering CLAUSE_LBD      = SatParameters_ClauseOrdering_CLAUSE_LBD;
    //        static inline bool              ClauseOrdering_IsValid( int value )
    //        {
    //            return SatParameters_ClauseOrdering_IsValid( value );
    //        }
    //        static constexpr ClauseOrdering                         ClauseOrdering_MIN       = SatParameters_ClauseOrdering_ClauseOrdering_MIN;
    //        static constexpr ClauseOrdering                         ClauseOrdering_MAX       = SatParameters_ClauseOrdering_ClauseOrdering_MAX;
    //        static constexpr int                                    ClauseOrdering_ARRAYSIZE = SatParameters_ClauseOrdering_ClauseOrdering_ARRAYSIZE;
    //        static inline const ::google::protobuf::EnumDescriptor* ClauseOrdering_descriptor()
    //        {
    //            return SatParameters_ClauseOrdering_descriptor();
    //        }
    //        template < typename T >
    //        static inline const std::string& ClauseOrdering_Name( T value )
    //        {
    //            return SatParameters_ClauseOrdering_Name( value );
    //        }
    //        static inline bool ClauseOrdering_Parse( absl::string_view name, ClauseOrdering* value )
    //        {
    //            return SatParameters_ClauseOrdering_Parse( name, value );
    //        }
    //        using RestartAlgorithm                                       = SatParameters_RestartAlgorithm;
    //        static constexpr RestartAlgorithm NO_RESTART                 = SatParameters_RestartAlgorithm_NO_RESTART;
    //        static constexpr RestartAlgorithm LUBY_RESTART               = SatParameters_RestartAlgorithm_LUBY_RESTART;
    //        static constexpr RestartAlgorithm DL_MOVING_AVERAGE_RESTART  = SatParameters_RestartAlgorithm_DL_MOVING_AVERAGE_RESTART;
    //        static constexpr RestartAlgorithm LBD_MOVING_AVERAGE_RESTART = SatParameters_RestartAlgorithm_LBD_MOVING_AVERAGE_RESTART;
    //        static constexpr RestartAlgorithm FIXED_RESTART              = SatParameters_RestartAlgorithm_FIXED_RESTART;
    //        static inline bool                RestartAlgorithm_IsValid( int value )
    //        {
    //            return SatParameters_RestartAlgorithm_IsValid( value );
    //        }
    //        static constexpr RestartAlgorithm                       RestartAlgorithm_MIN       = SatParameters_RestartAlgorithm_RestartAlgorithm_MIN;
    //        static constexpr RestartAlgorithm                       RestartAlgorithm_MAX       = SatParameters_RestartAlgorithm_RestartAlgorithm_MAX;
    //        static constexpr int                                    RestartAlgorithm_ARRAYSIZE = SatParameters_RestartAlgorithm_RestartAlgorithm_ARRAYSIZE;
    //        static inline const ::google::protobuf::EnumDescriptor* RestartAlgorithm_descriptor()
    //        {
    //            return SatParameters_RestartAlgorithm_descriptor();
    //        }
    //        template < typename T >
    //        static inline const std::string& RestartAlgorithm_Name( T value )
    //        {
    //            return SatParameters_RestartAlgorithm_Name( value );
    //        }
    //        static inline bool RestartAlgorithm_Parse( absl::string_view name, RestartAlgorithm* value )
    //        {
    //            return SatParameters_RestartAlgorithm_Parse( name, value );
    //        }
    //        using MaxSatAssumptionOrder                                       = SatParameters_MaxSatAssumptionOrder;
    //        static constexpr MaxSatAssumptionOrder DEFAULT_ASSUMPTION_ORDER   = SatParameters_MaxSatAssumptionOrder_DEFAULT_ASSUMPTION_ORDER;
    //        static constexpr MaxSatAssumptionOrder ORDER_ASSUMPTION_BY_DEPTH  = SatParameters_MaxSatAssumptionOrder_ORDER_ASSUMPTION_BY_DEPTH;
    //        static constexpr MaxSatAssumptionOrder ORDER_ASSUMPTION_BY_WEIGHT = SatParameters_MaxSatAssumptionOrder_ORDER_ASSUMPTION_BY_WEIGHT;
    //        static inline bool                     MaxSatAssumptionOrder_IsValid( int value )
    //        {
    //            return SatParameters_MaxSatAssumptionOrder_IsValid( value );
    //        }
    //        static constexpr MaxSatAssumptionOrder                  MaxSatAssumptionOrder_MIN       = SatParameters_MaxSatAssumptionOrder_MaxSatAssumptionOrder_MIN;
    //        static constexpr MaxSatAssumptionOrder                  MaxSatAssumptionOrder_MAX       = SatParameters_MaxSatAssumptionOrder_MaxSatAssumptionOrder_MAX;
    //        static constexpr int                                    MaxSatAssumptionOrder_ARRAYSIZE = SatParameters_MaxSatAssumptionOrder_MaxSatAssumptionOrder_ARRAYSIZE;
    //        static inline const ::google::protobuf::EnumDescriptor* MaxSatAssumptionOrder_descriptor()
    //        {
    //            return SatParameters_MaxSatAssumptionOrder_descriptor();
    //        }
    //        template < typename T >
    //        static inline const std::string& MaxSatAssumptionOrder_Name( T value )
    //        {
    //            return SatParameters_MaxSatAssumptionOrder_Name( value );
    //        }
    //        static inline bool MaxSatAssumptionOrder_Parse( absl::string_view name, MaxSatAssumptionOrder* value )
    //        {
    //            return SatParameters_MaxSatAssumptionOrder_Parse( name, value );
    //        }
    //        using MaxSatStratificationAlgorithm                                   = SatParameters_MaxSatStratificationAlgorithm;
    //        static constexpr MaxSatStratificationAlgorithm STRATIFICATION_NONE    = SatParameters_MaxSatStratificationAlgorithm_STRATIFICATION_NONE;
    //        static constexpr MaxSatStratificationAlgorithm STRATIFICATION_DESCENT = SatParameters_MaxSatStratificationAlgorithm_STRATIFICATION_DESCENT;
    //        static constexpr MaxSatStratificationAlgorithm STRATIFICATION_ASCENT  = SatParameters_MaxSatStratificationAlgorithm_STRATIFICATION_ASCENT;
    //        static inline bool                             MaxSatStratificationAlgorithm_IsValid( int value )
    //        {
    //            return SatParameters_MaxSatStratificationAlgorithm_IsValid( value );
    //        }
    //        static constexpr MaxSatStratificationAlgorithm          MaxSatStratificationAlgorithm_MIN       = SatParameters_MaxSatStratificationAlgorithm_MaxSatStratificationAlgorithm_MIN;
    //        static constexpr MaxSatStratificationAlgorithm          MaxSatStratificationAlgorithm_MAX       = SatParameters_MaxSatStratificationAlgorithm_MaxSatStratificationAlgorithm_MAX;
    //        static constexpr int                                    MaxSatStratificationAlgorithm_ARRAYSIZE = SatParameters_MaxSatStratificationAlgorithm_MaxSatStratificationAlgorithm_ARRAYSIZE;
    //        static inline const ::google::protobuf::EnumDescriptor* MaxSatStratificationAlgorithm_descriptor()
    //        {
    //            return SatParameters_MaxSatStratificationAlgorithm_descriptor();
    //        }
    //        template < typename T >
    //        static inline const std::string& MaxSatStratificationAlgorithm_Name( T value )
    //        {
    //            return SatParameters_MaxSatStratificationAlgorithm_Name( value );
    //        }
    //        static inline bool MaxSatStratificationAlgorithm_Parse( absl::string_view name, MaxSatStratificationAlgorithm* value )
    //        {
    //            return SatParameters_MaxSatStratificationAlgorithm_Parse( name, value );
    //        }
    //        using SearchBranching                                                = SatParameters_SearchBranching;
    //        static constexpr SearchBranching AUTOMATIC_SEARCH                    = SatParameters_SearchBranching_AUTOMATIC_SEARCH;
    //        static constexpr SearchBranching FIXED_SEARCH                        = SatParameters_SearchBranching_FIXED_SEARCH;
    //        static constexpr SearchBranching PORTFOLIO_SEARCH                    = SatParameters_SearchBranching_PORTFOLIO_SEARCH;
    //        static constexpr SearchBranching LP_SEARCH                           = SatParameters_SearchBranching_LP_SEARCH;
    //        static constexpr SearchBranching PSEUDO_COST_SEARCH                  = SatParameters_SearchBranching_PSEUDO_COST_SEARCH;
    //        static constexpr SearchBranching PORTFOLIO_WITH_QUICK_RESTART_SEARCH = SatParameters_SearchBranching_PORTFOLIO_WITH_QUICK_RESTART_SEARCH;
    //        static constexpr SearchBranching HINT_SEARCH                         = SatParameters_SearchBranching_HINT_SEARCH;
    //        static constexpr SearchBranching PARTIAL_FIXED_SEARCH                = SatParameters_SearchBranching_PARTIAL_FIXED_SEARCH;
    //        static constexpr SearchBranching RANDOMIZED_SEARCH                   = SatParameters_SearchBranching_RANDOMIZED_SEARCH;
    //        static inline bool               SearchBranching_IsValid( int value )
    //        {
    //            return SatParameters_SearchBranching_IsValid( value );
    //        }
    //        static constexpr SearchBranching                        SearchBranching_MIN       = SatParameters_SearchBranching_SearchBranching_MIN;
    //        static constexpr SearchBranching                        SearchBranching_MAX       = SatParameters_SearchBranching_SearchBranching_MAX;
    //        static constexpr int                                    SearchBranching_ARRAYSIZE = SatParameters_SearchBranching_SearchBranching_ARRAYSIZE;
    //        static inline const ::google::protobuf::EnumDescriptor* SearchBranching_descriptor()
    //        {
    //            return SatParameters_SearchBranching_descriptor();
    //        }
    //        template < typename T >
    //        static inline const std::string& SearchBranching_Name( T value )
    //        {
    //            return SatParameters_SearchBranching_Name( value );
    //        }
    //        static inline bool SearchBranching_Parse( absl::string_view name, SearchBranching* value )
    //        {
    //            return SatParameters_SearchBranching_Parse( name, value );
    //        }
    //        using SharedTreeSplitStrategy                                          = SatParameters_SharedTreeSplitStrategy;
    //        static constexpr SharedTreeSplitStrategy SPLIT_STRATEGY_AUTO           = SatParameters_SharedTreeSplitStrategy_SPLIT_STRATEGY_AUTO;
    //        static constexpr SharedTreeSplitStrategy SPLIT_STRATEGY_DISCREPANCY    = SatParameters_SharedTreeSplitStrategy_SPLIT_STRATEGY_DISCREPANCY;
    //        static constexpr SharedTreeSplitStrategy SPLIT_STRATEGY_OBJECTIVE_LB   = SatParameters_SharedTreeSplitStrategy_SPLIT_STRATEGY_OBJECTIVE_LB;
    //        static constexpr SharedTreeSplitStrategy SPLIT_STRATEGY_BALANCED_TREE  = SatParameters_SharedTreeSplitStrategy_SPLIT_STRATEGY_BALANCED_TREE;
    //        static constexpr SharedTreeSplitStrategy SPLIT_STRATEGY_FIRST_PROPOSAL = SatParameters_SharedTreeSplitStrategy_SPLIT_STRATEGY_FIRST_PROPOSAL;
    //        static inline bool                       SharedTreeSplitStrategy_IsValid( int value )
    //        {
    //            return SatParameters_SharedTreeSplitStrategy_IsValid( value );
    //        }
    //        static constexpr SharedTreeSplitStrategy                SharedTreeSplitStrategy_MIN       = SatParameters_SharedTreeSplitStrategy_SharedTreeSplitStrategy_MIN;
    //        static constexpr SharedTreeSplitStrategy                SharedTreeSplitStrategy_MAX       = SatParameters_SharedTreeSplitStrategy_SharedTreeSplitStrategy_MAX;
    //        static constexpr int                                    SharedTreeSplitStrategy_ARRAYSIZE = SatParameters_SharedTreeSplitStrategy_SharedTreeSplitStrategy_ARRAYSIZE;
    //        static inline const ::google::protobuf::EnumDescriptor* SharedTreeSplitStrategy_descriptor()
    //        {
    //            return SatParameters_SharedTreeSplitStrategy_descriptor();
    //        }
    //        template < typename T >
    //        static inline const std::string& SharedTreeSplitStrategy_Name( T value )
    //        {
    //            return SatParameters_SharedTreeSplitStrategy_Name( value );
    //        }
    //        static inline bool SharedTreeSplitStrategy_Parse( absl::string_view name, SharedTreeSplitStrategy* value )
    //        {
    //            return SatParameters_SharedTreeSplitStrategy_Parse( name, value );
    //        }
    //        using FPRoundingMethod                                 = SatParameters_FPRoundingMethod;
    //        static constexpr FPRoundingMethod NEAREST_INTEGER      = SatParameters_FPRoundingMethod_NEAREST_INTEGER;
    //        static constexpr FPRoundingMethod LOCK_BASED           = SatParameters_FPRoundingMethod_LOCK_BASED;
    //        static constexpr FPRoundingMethod ACTIVE_LOCK_BASED    = SatParameters_FPRoundingMethod_ACTIVE_LOCK_BASED;
    //        static constexpr FPRoundingMethod PROPAGATION_ASSISTED = SatParameters_FPRoundingMethod_PROPAGATION_ASSISTED;
    //        static inline bool                FPRoundingMethod_IsValid( int value )
    //        {
    //            return SatParameters_FPRoundingMethod_IsValid( value );
    //        }
    //        static constexpr FPRoundingMethod                       FPRoundingMethod_MIN       = SatParameters_FPRoundingMethod_FPRoundingMethod_MIN;
    //        static constexpr FPRoundingMethod                       FPRoundingMethod_MAX       = SatParameters_FPRoundingMethod_FPRoundingMethod_MAX;
    //        static constexpr int                                    FPRoundingMethod_ARRAYSIZE = SatParameters_FPRoundingMethod_FPRoundingMethod_ARRAYSIZE;
    //        static inline const ::google::protobuf::EnumDescriptor* FPRoundingMethod_descriptor()
    //        {
    //            return SatParameters_FPRoundingMethod_descriptor();
    //        }
    //        template < typename T >
    //        static inline const std::string& FPRoundingMethod_Name( T value )
    //        {
    //            return SatParameters_FPRoundingMethod_Name( value );
    //        }
    //        static inline bool FPRoundingMethod_Parse( absl::string_view name, FPRoundingMethod* value )
    //        {
    //            return SatParameters_FPRoundingMethod_Parse( name, value );
    //        }

    //        // accessors -------------------------------------------------------
    //        enum : int
    //        {
    //            kRestartAlgorithmsFieldNumber                              = 61,
    //            kSubsolversFieldNumber                                     = 207,
    //            kIgnoreSubsolversFieldNumber                               = 209,
    //            kSubsolverParamsFieldNumber                                = 210,
    //            kExtraSubsolversFieldNumber                                = 219,
    //            kFilterSubsolversFieldNumber                               = 293,
    //            kDefaultRestartAlgorithmsFieldNumber                       = 70,
    //            kNameFieldNumber                                           = 171,
    //            kLogPrefixFieldNumber                                      = 185,
    //            kPreferredVariableOrderFieldNumber                         = 1,
    //            kClauseCleanupTargetFieldNumber                            = 13,
    //            kRandomBranchesRatioFieldNumber                            = 32,
    //            kRandomPolarityRatioFieldNumber                            = 45,
    //            kMaxSatAssumptionOrderFieldNumber                          = 51,
    //            kClauseCleanupProtectionFieldNumber                        = 58,
    //            kClauseCleanupOrderingFieldNumber                          = 60,
    //            kNumConflictsBeforeStrategyChangesFieldNumber              = 68,
    //            kStrategyChangeIncreaseRatioFieldNumber                    = 69,
    //            kInitialVariablesActivityFieldNumber                       = 76,
    //            kSearchBranchingFieldNumber                                = 82,
    //            kUseErwaHeuristicFieldNumber                               = 75,
    //            kAlsoBumpVariablesInConflictReasonsFieldNumber             = 77,
    //            kUseBlockingRestartFieldNumber                             = 64,
    //            kPermuteVariableRandomlyFieldNumber                        = 178,
    //            kSearchRandomVariablePoolSizeFieldNumber                   = 104,
    //            kNumSearchWorkersFieldNumber                               = 100,
    //            kLogToResponseFieldNumber                                  = 187,
    //            kUsePbResolutionFieldNumber                                = 43,
    //            kMinimizeReductionDuringPbResolutionFieldNumber            = 48,
    //            kDetectTableWithCostFieldNumber                            = 216,
    //            kInterleaveBatchSizeFieldNumber                            = 134,
    //            kFillTightenedDomainsInResponseFieldNumber                 = 132,
    //            kFillAdditionalSolutionsInResponseFieldNumber              = 194,
    //            kStopAfterFirstSolutionFieldNumber                         = 98,
    //            kStopAfterPresolveFieldNumber                              = 149,
    //            kPermutePresolveConstraintOrderFieldNumber                 = 179,
    //            kUseAbslRandomFieldNumber                                  = 180,
    //            kLogSearchProgressFieldNumber                              = 41,
    //            kLogSubsolverStatisticsFieldNumber                         = 189,
    //            kPolishLpSolutionFieldNumber                               = 175,
    //            kOnlyAddCutsAtLevelZeroFieldNumber                         = 92,
    //            kAddObjectiveCutFieldNumber                                = 197,
    //            kExploitBestSolutionFieldNumber                            = 130,
    //            kDebugMaxNumPresolveOperationsFieldNumber                  = 151,
    //            kRandomizeSearchFieldNumber                                = 103,
    //            kPushAllTasksTowardStartFieldNumber                        = 262,
    //            kUseOptionalVariablesFieldNumber                           = 108,
    //            kUseCombinedNoOverlapFieldNumber                           = 133,
    //            kDebugPostsolveWithFullSolverFieldNumber                   = 162,
    //            kDebugCrashOnBadHintFieldNumber                            = 195,
    //            kMaxSatReverseAssumptionOrderFieldNumber                   = 52,
    //            kUseStrongPropagationInDisjunctiveFieldNumber              = 230,
    //            kOptimizeWithCoreFieldNumber                               = 83,
    //            kOptimizeWithLbTreeSearchFieldNumber                       = 188,
    //            kSaveLpBasisInLbTreeSearchFieldNumber                      = 284,
    //            kOptimizeWithMaxHsFieldNumber                              = 85,
    //            kRelativeGapLimitFieldNumber                               = 160,
    //            kUseTimetableEdgeFindingInCumulativeFieldNumber            = 79,
    //            kUseHardPrecedencesInCumulativeFieldNumber                 = 215,
    //            kExploitAllPrecedencesFieldNumber                          = 220,
    //            kUseTimetablingInNoOverlap2DFieldNumber                    = 200,
    //            kUseLsOnlyFieldNumber                                      = 240,
    //            kUseSharedTreeSearchFieldNumber                            = 236,
    //            kEnumerateAllSolutionsFieldNumber                          = 87,
    //            kKeepAllFeasibleSolutionsInPresolveFieldNumber             = 173,
    //            kStopAfterRootPropagationFieldNumber                       = 252,
    //            kUseLnsOnlyFieldNumber                                     = 101,
    //            kUseLbRelaxLnsFieldNumber                                  = 255,
    //            kDiversifyLnsParamsFieldNumber                             = 137,
    //            kEncodeComplexLinearConstraintWithIntegerFieldNumber       = 223,
    //            kPresolveExtractIntegerEnforcementFieldNumber              = 174,
    //            kInterleaveSearchFieldNumber                               = 136,
    //            kShareGlueClausesFieldNumber                               = 285,
    //            kNumWorkersFieldNumber                                     = 206,
    //            kUseEnergeticReasoningInNoOverlap2DFieldNumber             = 213,
    //            kUseAreaEnergeticReasoningInNoOverlap2DFieldNumber         = 271,
    //            kRepairHintFieldNumber                                     = 167,
    //            kFixVariablesToTheirHintedValueFieldNumber                 = 192,
    //            kExploitRelaxationSolutionFieldNumber                      = 161,
    //            kDetectLinearizedProductFieldNumber                        = 277,
    //            kMipScaleLargeDomainFieldNumber                            = 225,
    //            kOnlySolveIpFieldNumber                                    = 222,
    //            kUseDynamicPrecedenceInDisjunctiveFieldNumber              = 263,
    //            kUseDynamicPrecedenceInCumulativeFieldNumber               = 268,
    //            kUseOverloadCheckerInCumulativeFieldNumber                 = 78,
    //            kUseConservativeScaleOverloadCheckerFieldNumber            = 286,
    //            kExpandAlldiffConstraintsFieldNumber                       = 170,
    //            kExpandReservoirUsingCircuitFieldNumber                    = 288,
    //            kEncodeCumulativeAsReservoirFieldNumber                    = 287,
    //            kDisableConstraintExpansionFieldNumber                     = 181,
    //            kSharedTreeNumWorkersFieldNumber                           = 235,
    //            kUseProbingSearchFieldNumber                               = 176,
    //            kUseObjectiveLbSearchFieldNumber                           = 228,
    //            kUseObjectiveShavingSearchFieldNumber                      = 253,
    //            kUseVariablesShavingSearchFieldNumber                      = 289,
    //            kSharedTreeSplitStrategyFieldNumber                        = 239,
    //            kNumViolationLsFieldNumber                                 = 244,
    //            kMipTreatHighMagnitudeBoundsAsInfinityFieldNumber          = 278,
    //            kMaxLinMaxSizeForExpansionFieldNumber                      = 280,
    //            kMaxNumDeterministicBatchesFieldNumber                     = 291,
    //            kNumFullSubsolversFieldNumber                              = 294,
    //            kSharedTreeWorkerMinRestartsPerSubtreeFieldNumber          = 282,
    //            kInitialPolarityFieldNumber                                = 2,
    //            kMinimizationAlgorithmFieldNumber                          = 4,
    //            kVariableActivityDecayFieldNumber                          = 15,
    //            kMaxVariableActivityValueFieldNumber                       = 16,
    //            kClauseActivityDecayFieldNumber                            = 17,
    //            kClauseCleanupPeriodFieldNumber                            = 11,
    //            kGlucoseDecayIncrementPeriodFieldNumber                    = 24,
    //            kMaxClauseActivityValueFieldNumber                         = 18,
    //            kGlucoseMaxDecayFieldNumber                                = 22,
    //            kGlucoseDecayIncrementFieldNumber                          = 23,
    //            kRestartPeriodFieldNumber                                  = 30,
    //            kRandomSeedFieldNumber                                     = 31,
    //            kMaxTimeInSecondsFieldNumber                               = 36,
    //            kMaxNumberOfConflictsFieldNumber                           = 37,
    //            kMaxMemoryInMbFieldNumber                                  = 40,
    //            kBinaryMinimizationAlgorithmFieldNumber                    = 34,
    //            kPbCleanupIncrementFieldNumber                             = 46,
    //            kPbCleanupRatioFieldNumber                                 = 47,
    //            kCoreMinimizationLevelFieldNumber                          = 50,
    //            kMaxSatStratificationFieldNumber                           = 53,
    //            kPresolveBveThresholdFieldNumber                           = 54,
    //            kPresolveBveClauseWeightFieldNumber                        = 55,
    //            kPresolveProbingDeterministicTimeLimitFieldNumber          = 57,
    //            kClauseCleanupLbdBoundFieldNumber                          = 59,
    //            kRestartRunningWindowSizeFieldNumber                       = 62,
    //            kRestartDlAverageRatioFieldNumber                          = 63,
    //            kBlockingRestartMultiplierFieldNumber                      = 66,
    //            kMaxDeterministicTimeFieldNumber                           = 67,
    //            kBlockingRestartWindowSizeFieldNumber                      = 65,
    //            kUseOptimizationHintsFieldNumber                           = 35,
    //            kFindMultipleCoresFieldNumber                              = 84,
    //            kCoverOptimizationFieldNumber                              = 89,
    //            kUsePrecedencesInDisjunctiveConstraintFieldNumber          = 74,
    //            kRestartLbdAverageRatioFieldNumber                         = 71,
    //            kPresolveBvaThresholdFieldNumber                           = 73,
    //            kUsePhaseSavingFieldNumber                                 = 44,
    //            kSubsumptionDuringConflictAnalysisFieldNumber              = 56,
    //            kLogToStdoutFieldNumber                                    = 186,
    //            kCountAssumptionLevelsInLbdFieldNumber                     = 49,
    //            kPresolveBlockedClauseFieldNumber                          = 88,
    //            kPresolveUseBvaFieldNumber                                 = 72,
    //            kCpModelPresolveFieldNumber                                = 86,
    //            kCpModelUseSatPresolveFieldNumber                          = 93,
    //            kLinearizationLevelFieldNumber                             = 90,
    //            kMaxNumCutsFieldNumber                                     = 91,
    //            kBinarySearchNumConflictsFieldNumber                       = 99,
    //            kBooleanEncodingLevelFieldNumber                           = 107,
    //            kCpModelProbingLevelFieldNumber                            = 110,
    //            kMinOrthogonalityForLpConstraintsFieldNumber               = 115,
    //            kMaxIntegerRoundingScalingFieldNumber                      = 119,
    //            kMaxConsecutiveInactiveCountFieldNumber                    = 121,
    //            kPseudoCostReliabilityThresholdFieldNumber                 = 123,
    //            kMipMaxBoundFieldNumber                                    = 124,
    //            kMipVarScalingFieldNumber                                  = 125,
    //            kNewConstraintsBatchSizeFieldNumber                        = 122,
    //            kExploitIntegerLpSolutionFieldNumber                       = 94,
    //            kExploitAllLpSolutionFieldNumber                           = 116,
    //            kExploitObjectiveFieldNumber                               = 131,
    //            kMipAutomaticallyScaleVariablesFieldNumber                 = 166,
    //            kMipWantedPrecisionFieldNumber                             = 126,
    //            kMipCheckPrecisionFieldNumber                              = 128,
    //            kMipMaxActivityExponentFieldNumber                         = 127,
    //            kMaxPresolveIterationsFieldNumber                          = 138,
    //            kUseExactLpReasonFieldNumber                               = 109,
    //            kCatchSigintSignalFieldNumber                              = 135,
    //            kUseImpliedBoundsFieldNumber                               = 144,
    //            kConvertIntervalsFieldNumber                               = 177,
    //            kPresolveSubstitutionLevelFieldNumber                      = 147,
    //            kMergeNoOverlapWorkLimitFieldNumber                        = 145,
    //            kMergeAtMostOneWorkLimitFieldNumber                        = 146,
    //            kMaxAllDiffCutSizeFieldNumber                              = 148,
    //            kUseSatInprocessingFieldNumber                             = 163,
    //            kShareObjectiveBoundsFieldNumber                           = 113,
    //            kShareLevelZeroBoundsFieldNumber                           = 114,
    //            kShareBinaryClausesFieldNumber                             = 203,
    //            kHintConflictLimitFieldNumber                              = 153,
    //            kMaxCutRoundsAtLevelZeroFieldNumber                        = 154,
    //            kCutMaxActiveCountValueFieldNumber                         = 155,
    //            kCutActiveCountDecayFieldNumber                            = 156,
    //            kCutCleanupTargetFieldNumber                               = 157,
    //            kNewLinearPropagationFieldNumber                           = 224,
    //            kAddCgCutsFieldNumber                                      = 117,
    //            kAddMirCutsFieldNumber                                     = 120,
    //            kAddZeroHalfCutsFieldNumber                                = 169,
    //            kAbsoluteGapLimitFieldNumber                               = 159,
    //            kFpRoundingFieldNumber                                     = 165,
    //            kAutoDetectGreaterThanAtLeastOneOfFieldNumber              = 95,
    //            kUseLnsFieldNumber                                         = 283,
    //            kUseRinsLnsFieldNumber                                     = 129,
    //            kUseFeasibilityPumpFieldNumber                             = 164,
    //            kPolarityRephaseIncrementFieldNumber                       = 168,
    //            kAddCliqueCutsFieldNumber                                  = 172,
    //            kAddRltCutsFieldNumber                                     = 279,
    //            kAddLinMaxCutsFieldNumber                                  = 152,
    //            kAddLpConstraintsLazilyFieldNumber                         = 112,
    //            kSymmetryLevelFieldNumber                                  = 183,
    //            kMaxDomainSizeWhenEncodingEqNeqConstraintsFieldNumber      = 191,
    //            kClauseCleanupRatioFieldNumber                             = 190,
    //            kUseDisjunctiveConstraintInCumulativeFieldNumber           = 80,
    //            kUseDualSchedulingHeuristicsFieldNumber                    = 214,
    //            kUseExtendedProbingFieldNumber                             = 269,
    //            kUseShavingInProbingSearchFieldNumber                      = 204,
    //            kSolutionPoolSizeFieldNumber                               = 193,
    //            kCutLevelFieldNumber                                       = 196,
    //            kMipComputeTrueObjectiveBoundFieldNumber                   = 198,
    //            kMipMaxValidMagnitudeFieldNumber                           = 199,
    //            kPresolveInclusionWorkLimitFieldNumber                     = 201,
    //            kShavingSearchDeterministicTimeFieldNumber                 = 205,
    //            kExpandReservoirConstraintsFieldNumber                     = 182,
    //            kIgnoreNamesFieldNumber                                    = 202,
    //            kInferAllDiffsFieldNumber                                  = 233,
    //            kFindBigLinearOverlapFieldNumber                           = 234,
    //            kTableCompressionLevelFieldNumber                          = 217,
    //            kPropagationLoopDetectionFactorFieldNumber                 = 221,
    //            kProbingDeterministicTimeLimitFieldNumber                  = 226,
    //            kRootLpIterationsFieldNumber                               = 227,
    //            kMaxSizeToCreatePrecedenceLiteralsInDisjunctiveFieldNumber = 229,
    //            kUseFeasibilityJumpFieldNumber                             = 265,
    //            kFeasibilityJumpEnableRestartsFieldNumber                  = 250,
    //            kSharedTreeWorkerEnableTrailSharingFieldNumber             = 295,
    //            kInstantiateAllVariablesFieldNumber                        = 106,
    //            kSharedTreeMaxNodesPerWorkerFieldNumber                    = 238,
    //            kMipDropToleranceFieldNumber                               = 232,
    //            kSharedTreeWorkerObjectiveSplitProbabilityFieldNumber      = 237,
    //            kFeasibilityJumpDecayFieldNumber                           = 242,
    //            kFeasibilityJumpVarRandomizationProbabilityFieldNumber     = 247,
    //            kFeasibilityJumpVarPerburbationRangeRatioFieldNumber       = 248,
    //            kViolationLsPerturbationPeriodFieldNumber                  = 249,
    //            kLinearSplitSizeFieldNumber                                = 256,
    //            kFeasibilityJumpLinearizationLevelFieldNumber              = 257,
    //            kFeasibilityJumpRestartFactorFieldNumber                   = 258,
    //            kViolationLsCompoundMoveProbabilityFieldNumber             = 259,
    //            kMaxNumIntervalsForTimetableEdgeFindingFieldNumber         = 260,
    //            kMipPresolveLevelFieldNumber                               = 261,
    //            kLpPrimalToleranceFieldNumber                              = 266,
    //            kLpDualToleranceFieldNumber                                = 267,
    //            kFeasibilityJumpMaxExpandedConstraintSizeFieldNumber       = 264,
    //            kAtMostOneMaxExpansionSizeFieldNumber                      = 270,
    //            kInprocessingDtimeRatioFieldNumber                         = 273,
    //            kInprocessingProbingDtimeFieldNumber                       = 274,
    //            kProbingNumCombinationsLimitFieldNumber                    = 272,
    //            kMaxPairsPairwiseReasoningInNoOverlap2DFieldNumber         = 276,
    //            kInprocessingMinimizationDtimeFieldNumber                  = 275,
    //            kSharedTreeOpenLeavesPerWorkerFieldNumber                  = 281,
    //            kShavingSearchThresholdFieldNumber                         = 290,
    //            kFeasibilityJumpBatchDtimeFieldNumber                      = 292,
    //        };
    //        // repeated .operations_research.sat.SatParameters.RestartAlgorithm restart_algorithms = 61;
    //        int restart_algorithms_size() const;

    //    private:
    //        int _internal_restart_algorithms_size() const;

    //    public:
    //        void clear_restart_algorithms();

    //    public:
    //        ::operations_research::sat::SatParameters_RestartAlgorithm restart_algorithms( int index ) const;
    //        void                                                       set_restart_algorithms( int index, ::operations_research::sat::SatParameters_RestartAlgorithm value );
    //        void                                                       add_restart_algorithms( ::operations_research::sat::SatParameters_RestartAlgorithm value );
    //        const ::google::protobuf::RepeatedField< int >&            restart_algorithms() const;
    //        ::google::protobuf::RepeatedField< int >*                  mutable_restart_algorithms();

    //    private:
    //        const ::google::protobuf::RepeatedField< int >& _internal_restart_algorithms() const;
    //        ::google::protobuf::RepeatedField< int >*       _internal_mutable_restart_algorithms();

    //    public:
    //        // repeated string subsolvers = 207;
    //        int subsolvers_size() const;

    //    private:
    //        int _internal_subsolvers_size() const;

    //    public:
    //        void                                                       clear_subsolvers();
    //        const std::string&                                         subsolvers( int index ) const;
    //        std::string*                                               mutable_subsolvers( int index );
    //        void                                                       set_subsolvers( int index, const std::string& value );
    //        void                                                       set_subsolvers( int index, std::string&& value );
    //        void                                                       set_subsolvers( int index, const char* value );
    //        void                                                       set_subsolvers( int index, const char* value, std::size_t size );
    //        void                                                       set_subsolvers( int index, absl::string_view value );
    //        std::string*                                               add_subsolvers();
    //        void                                                       add_subsolvers( const std::string& value );
    //        void                                                       add_subsolvers( std::string&& value );
    //        void                                                       add_subsolvers( const char* value );
    //        void                                                       add_subsolvers( const char* value, std::size_t size );
    //        void                                                       add_subsolvers( absl::string_view value );
    //        const ::google::protobuf::RepeatedPtrField< std::string >& subsolvers() const;
    //        ::google::protobuf::RepeatedPtrField< std::string >*       mutable_subsolvers();

    //    private:
    //        const ::google::protobuf::RepeatedPtrField< std::string >& _internal_subsolvers() const;
    //        ::google::protobuf::RepeatedPtrField< std::string >*       _internal_mutable_subsolvers();

    //    public:
    //        // repeated string ignore_subsolvers = 209;
    //        int ignore_subsolvers_size() const;

    //    private:
    //        int _internal_ignore_subsolvers_size() const;

    //    public:
    //        void                                                       clear_ignore_subsolvers();
    //        const std::string&                                         ignore_subsolvers( int index ) const;
    //        std::string*                                               mutable_ignore_subsolvers( int index );
    //        void                                                       set_ignore_subsolvers( int index, const std::string& value );
    //        void                                                       set_ignore_subsolvers( int index, std::string&& value );
    //        void                                                       set_ignore_subsolvers( int index, const char* value );
    //        void                                                       set_ignore_subsolvers( int index, const char* value, std::size_t size );
    //        void                                                       set_ignore_subsolvers( int index, absl::string_view value );
    //        std::string*                                               add_ignore_subsolvers();
    //        void                                                       add_ignore_subsolvers( const std::string& value );
    //        void                                                       add_ignore_subsolvers( std::string&& value );
    //        void                                                       add_ignore_subsolvers( const char* value );
    //        void                                                       add_ignore_subsolvers( const char* value, std::size_t size );
    //        void                                                       add_ignore_subsolvers( absl::string_view value );
    //        const ::google::protobuf::RepeatedPtrField< std::string >& ignore_subsolvers() const;
    //        ::google::protobuf::RepeatedPtrField< std::string >*       mutable_ignore_subsolvers();

    //    private:
    //        const ::google::protobuf::RepeatedPtrField< std::string >& _internal_ignore_subsolvers() const;
    //        ::google::protobuf::RepeatedPtrField< std::string >*       _internal_mutable_ignore_subsolvers();

    //    public:
    //        // repeated .operations_research.sat.SatParameters subsolver_params = 210;
    //        int subsolver_params_size() const;

    //    private:
    //        int _internal_subsolver_params_size() const;

    //    public:
    //        void                                                                               clear_subsolver_params();
    //        ::operations_research::sat::SatParameters*                                         mutable_subsolver_params( int index );
    //        ::google::protobuf::RepeatedPtrField< ::operations_research::sat::SatParameters >* mutable_subsolver_params();

    //    private:
    //        const ::google::protobuf::RepeatedPtrField< ::operations_research::sat::SatParameters >& _internal_subsolver_params() const;
    //        ::google::protobuf::RepeatedPtrField< ::operations_research::sat::SatParameters >*       _internal_mutable_subsolver_params();

    //    public:
    //        const ::operations_research::sat::SatParameters&                                         subsolver_params( int index ) const;
    //        ::operations_research::sat::SatParameters*                                               add_subsolver_params();
    //        const ::google::protobuf::RepeatedPtrField< ::operations_research::sat::SatParameters >& subsolver_params() const;
    //        // repeated string extra_subsolvers = 219;
    //        int extra_subsolvers_size() const;

    //    private:
    //        int _internal_extra_subsolvers_size() const;

    //    public:
    //        void                                                       clear_extra_subsolvers();
    //        const std::string&                                         extra_subsolvers( int index ) const;
    //        std::string*                                               mutable_extra_subsolvers( int index );
    //        void                                                       set_extra_subsolvers( int index, const std::string& value );
    //        void                                                       set_extra_subsolvers( int index, std::string&& value );
    //        void                                                       set_extra_subsolvers( int index, const char* value );
    //        void                                                       set_extra_subsolvers( int index, const char* value, std::size_t size );
    //        void                                                       set_extra_subsolvers( int index, absl::string_view value );
    //        std::string*                                               add_extra_subsolvers();
    //        void                                                       add_extra_subsolvers( const std::string& value );
    //        void                                                       add_extra_subsolvers( std::string&& value );
    //        void                                                       add_extra_subsolvers( const char* value );
    //        void                                                       add_extra_subsolvers( const char* value, std::size_t size );
    //        void                                                       add_extra_subsolvers( absl::string_view value );
    //        const ::google::protobuf::RepeatedPtrField< std::string >& extra_subsolvers() const;
    //        ::google::protobuf::RepeatedPtrField< std::string >*       mutable_extra_subsolvers();

    //    private:
    //        const ::google::protobuf::RepeatedPtrField< std::string >& _internal_extra_subsolvers() const;
    //        ::google::protobuf::RepeatedPtrField< std::string >*       _internal_mutable_extra_subsolvers();

    //    public:
    //        // repeated string filter_subsolvers = 293;
    //        int filter_subsolvers_size() const;

    //    private:
    //        int _internal_filter_subsolvers_size() const;

    //    public:
    //        void                                                       clear_filter_subsolvers();
    //        const std::string&                                         filter_subsolvers( int index ) const;
    //        std::string*                                               mutable_filter_subsolvers( int index );
    //        void                                                       set_filter_subsolvers( int index, const std::string& value );
    //        void                                                       set_filter_subsolvers( int index, std::string&& value );
    //        void                                                       set_filter_subsolvers( int index, const char* value );
    //        void                                                       set_filter_subsolvers( int index, const char* value, std::size_t size );
    //        void                                                       set_filter_subsolvers( int index, absl::string_view value );
    //        std::string*                                               add_filter_subsolvers();
    //        void                                                       add_filter_subsolvers( const std::string& value );
    //        void                                                       add_filter_subsolvers( std::string&& value );
    //        void                                                       add_filter_subsolvers( const char* value );
    //        void                                                       add_filter_subsolvers( const char* value, std::size_t size );
    //        void                                                       add_filter_subsolvers( absl::string_view value );
    //        const ::google::protobuf::RepeatedPtrField< std::string >& filter_subsolvers() const;
    //        ::google::protobuf::RepeatedPtrField< std::string >*       mutable_filter_subsolvers();

    //    private:
    //        const ::google::protobuf::RepeatedPtrField< std::string >& _internal_filter_subsolvers() const;
    //        ::google::protobuf::RepeatedPtrField< std::string >*       _internal_mutable_filter_subsolvers();

    //    public:
    //        // optional string default_restart_algorithms = 70 [default = "LUBY_RESTART,LBD_MOVING_AVERAGE_RESTART,DL_MOVING_AVERAGE_RESTART"];
    //        bool               has_default_restart_algorithms() const;
    //        void               clear_default_restart_algorithms();
    //        const std::string& default_restart_algorithms() const;
    //        template < typename Arg_ = const std::string&, typename... Args_ >
    //        void               set_default_restart_algorithms( Arg_&& arg, Args_... args );
    //        std::string*       mutable_default_restart_algorithms();
    //        PROTOBUF_NODISCARD std::string* release_default_restart_algorithms();
    //        void                            set_allocated_default_restart_algorithms( std::string* value );

    //    private:
    //        const std::string&                 _internal_default_restart_algorithms() const;
    //        inline PROTOBUF_ALWAYS_INLINE void _internal_set_default_restart_algorithms(
    //            const std::string& value );
    //        std::string* _internal_mutable_default_restart_algorithms();

    //    public:
    //        // optional string name = 171 [default = ""];
    //        bool               has_name() const;
    //        void               clear_name();
    //        const std::string& name() const;
    //        template < typename Arg_ = const std::string&, typename... Args_ >
    //        void               set_name( Arg_&& arg, Args_... args );
    //        std::string*       mutable_name();
    //        PROTOBUF_NODISCARD std::string* release_name();
    //        void                            set_allocated_name( std::string* value );

    //    private:
    //        const std::string&                 _internal_name() const;
    //        inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(
    //            const std::string& value );
    //        std::string* _internal_mutable_name();

    //    public:
    //        // optional string log_prefix = 185 [default = ""];
    //        bool               has_log_prefix() const;
    //        void               clear_log_prefix();
    //        const std::string& log_prefix() const;
    //        template < typename Arg_ = const std::string&, typename... Args_ >
    //        void               set_log_prefix( Arg_&& arg, Args_... args );
    //        std::string*       mutable_log_prefix();
    //        PROTOBUF_NODISCARD std::string* release_log_prefix();
    //        void                            set_allocated_log_prefix( std::string* value );

    //    private:
    //        const std::string&                 _internal_log_prefix() const;
    //        inline PROTOBUF_ALWAYS_INLINE void _internal_set_log_prefix(
    //            const std::string& value );
    //        std::string* _internal_mutable_log_prefix();

    //    public:
    //        // optional .operations_research.sat.SatParameters.VariableOrder preferred_variable_order = 1 [default = IN_ORDER];
    //        bool                                                    has_preferred_variable_order() const;
    //        void                                                    clear_preferred_variable_order();
    //        ::operations_research::sat::SatParameters_VariableOrder preferred_variable_order() const;
    //        void                                                    set_preferred_variable_order( ::operations_research::sat::SatParameters_VariableOrder value );

    //    private:
    //        ::operations_research::sat::SatParameters_VariableOrder _internal_preferred_variable_order() const;
    //        void                                                    _internal_set_preferred_variable_order( ::operations_research::sat::SatParameters_VariableOrder value );

    //    public:
    //        // optional int32 clause_cleanup_target = 13 [default = 0];
    //        bool      has_clause_cleanup_target() const;
    //        void      clear_clause_cleanup_target();
    //        ::int32_t clause_cleanup_target() const;
    //        void      set_clause_cleanup_target( ::int32_t value );

    //    private:
    //        ::int32_t _internal_clause_cleanup_target() const;
    //        void      _internal_set_clause_cleanup_target( ::int32_t value );

    //    public:
    //        // optional double random_branches_ratio = 32 [default = 0];
    //        bool   has_random_branches_ratio() const;
    //        void   clear_random_branches_ratio();
    //        double random_branches_ratio() const;
    //        void   set_random_branches_ratio( double value );

    //    private:
    //        double _internal_random_branches_ratio() const;
    //        void   _internal_set_random_branches_ratio( double value );

    //    public:
    //        // optional double random_polarity_ratio = 45 [default = 0];
    //        bool   has_random_polarity_ratio() const;
    //        void   clear_random_polarity_ratio();
    //        double random_polarity_ratio() const;
    //        void   set_random_polarity_ratio( double value );

    //    private:
    //        double _internal_random_polarity_ratio() const;
    //        void   _internal_set_random_polarity_ratio( double value );

    //    public:
    //        // optional .operations_research.sat.SatParameters.MaxSatAssumptionOrder max_sat_assumption_order = 51 [default = DEFAULT_ASSUMPTION_ORDER];
    //        bool                                                            has_max_sat_assumption_order() const;
    //        void                                                            clear_max_sat_assumption_order();
    //        ::operations_research::sat::SatParameters_MaxSatAssumptionOrder max_sat_assumption_order() const;
    //        void                                                            set_max_sat_assumption_order( ::operations_research::sat::SatParameters_MaxSatAssumptionOrder value );

    //    private:
    //        ::operations_research::sat::SatParameters_MaxSatAssumptionOrder _internal_max_sat_assumption_order() const;
    //        void                                                            _internal_set_max_sat_assumption_order( ::operations_research::sat::SatParameters_MaxSatAssumptionOrder value );

    //    public:
    //        // optional .operations_research.sat.SatParameters.ClauseProtection clause_cleanup_protection = 58 [default = PROTECTION_NONE];
    //        bool                                                       has_clause_cleanup_protection() const;
    //        void                                                       clear_clause_cleanup_protection();
    //        ::operations_research::sat::SatParameters_ClauseProtection clause_cleanup_protection() const;
    //        void                                                       set_clause_cleanup_protection( ::operations_research::sat::SatParameters_ClauseProtection value );

    //    private:
    //        ::operations_research::sat::SatParameters_ClauseProtection _internal_clause_cleanup_protection() const;
    //        void                                                       _internal_set_clause_cleanup_protection( ::operations_research::sat::SatParameters_ClauseProtection value );

    //    public:
    //        // optional .operations_research.sat.SatParameters.ClauseOrdering clause_cleanup_ordering = 60 [default = CLAUSE_ACTIVITY];
    //        bool                                                     has_clause_cleanup_ordering() const;
    //        void                                                     clear_clause_cleanup_ordering();
    //        ::operations_research::sat::SatParameters_ClauseOrdering clause_cleanup_ordering() const;
    //        void                                                     set_clause_cleanup_ordering( ::operations_research::sat::SatParameters_ClauseOrdering value );

    //    private:
    //        ::operations_research::sat::SatParameters_ClauseOrdering _internal_clause_cleanup_ordering() const;
    //        void                                                     _internal_set_clause_cleanup_ordering( ::operations_research::sat::SatParameters_ClauseOrdering value );

    //    public:
    //        // optional int32 num_conflicts_before_strategy_changes = 68 [default = 0];
    //        bool      has_num_conflicts_before_strategy_changes() const;
    //        void      clear_num_conflicts_before_strategy_changes();
    //        ::int32_t num_conflicts_before_strategy_changes() const;
    //        void      set_num_conflicts_before_strategy_changes( ::int32_t value );

    //    private:
    //        ::int32_t _internal_num_conflicts_before_strategy_changes() const;
    //        void      _internal_set_num_conflicts_before_strategy_changes( ::int32_t value );

    //    public:
    //        // optional double strategy_change_increase_ratio = 69 [default = 0];
    //        bool   has_strategy_change_increase_ratio() const;
    //        void   clear_strategy_change_increase_ratio();
    //        double strategy_change_increase_ratio() const;
    //        void   set_strategy_change_increase_ratio( double value );

    //    private:
    //        double _internal_strategy_change_increase_ratio() const;
    //        void   _internal_set_strategy_change_increase_ratio( double value );

    //    public:
    //        // optional double initial_variables_activity = 76 [default = 0];
    //        bool   has_initial_variables_activity() const;
    //        void   clear_initial_variables_activity();
    //        double initial_variables_activity() const;
    //        void   set_initial_variables_activity( double value );

    //    private:
    //        double _internal_initial_variables_activity() const;
    //        void   _internal_set_initial_variables_activity( double value );

    //    public:
    //        // optional .operations_research.sat.SatParameters.SearchBranching search_branching = 82 [default = AUTOMATIC_SEARCH];
    //        bool                                                      has_search_branching() const;
    //        void                                                      clear_search_branching();
    //        ::operations_research::sat::SatParameters_SearchBranching search_branching() const;
    //        void                                                      set_search_branching( ::operations_research::sat::SatParameters_SearchBranching value );

    //    private:
    //        ::operations_research::sat::SatParameters_SearchBranching _internal_search_branching() const;
    //        void                                                      _internal_set_search_branching( ::operations_research::sat::SatParameters_SearchBranching value );

    //    public:
    //        // optional bool use_erwa_heuristic = 75 [default = false];
    //        bool has_use_erwa_heuristic() const;
    //        void clear_use_erwa_heuristic();
    //        bool use_erwa_heuristic() const;
    //        void set_use_erwa_heuristic( bool value );

    //    private:
    //        bool _internal_use_erwa_heuristic() const;
    //        void _internal_set_use_erwa_heuristic( bool value );

    //    public:
    //        // optional bool also_bump_variables_in_conflict_reasons = 77 [default = false];
    //        bool has_also_bump_variables_in_conflict_reasons() const;
    //        void clear_also_bump_variables_in_conflict_reasons();
    //        bool also_bump_variables_in_conflict_reasons() const;
    //        void set_also_bump_variables_in_conflict_reasons( bool value );

    //    private:
    //        bool _internal_also_bump_variables_in_conflict_reasons() const;
    //        void _internal_set_also_bump_variables_in_conflict_reasons( bool value );

    //    public:
    //        // optional bool use_blocking_restart = 64 [default = false];
    //        bool has_use_blocking_restart() const;
    //        void clear_use_blocking_restart();
    //        bool use_blocking_restart() const;
    //        void set_use_blocking_restart( bool value );

    //    private:
    //        bool _internal_use_blocking_restart() const;
    //        void _internal_set_use_blocking_restart( bool value );

    //    public:
    //        // optional bool permute_variable_randomly = 178 [default = false];
    //        bool has_permute_variable_randomly() const;
    //        void clear_permute_variable_randomly();
    //        bool permute_variable_randomly() const;
    //        void set_permute_variable_randomly( bool value );

    //    private:
    //        bool _internal_permute_variable_randomly() const;
    //        void _internal_set_permute_variable_randomly( bool value );

    //    public:
    //        // optional int64 search_random_variable_pool_size = 104 [default = 0];
    //        bool      has_search_random_variable_pool_size() const;
    //        void      clear_search_random_variable_pool_size();
    //        ::int64_t search_random_variable_pool_size() const;
    //        void      set_search_random_variable_pool_size( ::int64_t value );

    //    private:
    //        ::int64_t _internal_search_random_variable_pool_size() const;
    //        void      _internal_set_search_random_variable_pool_size( ::int64_t value );

    //    public:
    //        // optional int32 num_search_workers = 100 [default = 0];
    //        bool      has_num_search_workers() const;
    //        void      clear_num_search_workers();
    //        ::int32_t num_search_workers() const;
    //        void      set_num_search_workers( ::int32_t value );

    //    private:
    //        ::int32_t _internal_num_search_workers() const;
    //        void      _internal_set_num_search_workers( ::int32_t value );

    //    public:
    //        // optional bool log_to_response = 187 [default = false];
    //        bool has_log_to_response() const;
    //        void clear_log_to_response();
    //        bool log_to_response() const;
    //        void set_log_to_response( bool value );

    //    private:
    //        bool _internal_log_to_response() const;
    //        void _internal_set_log_to_response( bool value );

    //    public:
    //        // optional bool use_pb_resolution = 43 [default = false];
    //        bool has_use_pb_resolution() const;
    //        void clear_use_pb_resolution();
    //        bool use_pb_resolution() const;
    //        void set_use_pb_resolution( bool value );

    //    private:
    //        bool _internal_use_pb_resolution() const;
    //        void _internal_set_use_pb_resolution( bool value );

    //    public:
    //        // optional bool minimize_reduction_during_pb_resolution = 48 [default = false];
    //        bool has_minimize_reduction_during_pb_resolution() const;
    //        void clear_minimize_reduction_during_pb_resolution();
    //        bool minimize_reduction_during_pb_resolution() const;
    //        void set_minimize_reduction_during_pb_resolution( bool value );

    //    private:
    //        bool _internal_minimize_reduction_during_pb_resolution() const;
    //        void _internal_set_minimize_reduction_during_pb_resolution( bool value );

    //    public:
    //        // optional bool detect_table_with_cost = 216 [default = false];
    //        bool has_detect_table_with_cost() const;
    //        void clear_detect_table_with_cost();
    //        bool detect_table_with_cost() const;
    //        void set_detect_table_with_cost( bool value );

    //    private:
    //        bool _internal_detect_table_with_cost() const;
    //        void _internal_set_detect_table_with_cost( bool value );

    //    public:
    //        // optional int32 interleave_batch_size = 134 [default = 0];
    //        bool      has_interleave_batch_size() const;
    //        void      clear_interleave_batch_size();
    //        ::int32_t interleave_batch_size() const;
    //        void      set_interleave_batch_size( ::int32_t value );

    //    private:
    //        ::int32_t _internal_interleave_batch_size() const;
    //        void      _internal_set_interleave_batch_size( ::int32_t value );

    //    public:
    //        // optional bool fill_tightened_domains_in_response = 132 [default = false];
    //        bool has_fill_tightened_domains_in_response() const;
    //        void clear_fill_tightened_domains_in_response();
    //        bool fill_tightened_domains_in_response() const;
    //        void set_fill_tightened_domains_in_response( bool value );

    //    private:
    //        bool _internal_fill_tightened_domains_in_response() const;
    //        void _internal_set_fill_tightened_domains_in_response( bool value );

    //    public:
    //        // optional bool fill_additional_solutions_in_response = 194 [default = false];
    //        bool has_fill_additional_solutions_in_response() const;
    //        void clear_fill_additional_solutions_in_response();
    //        bool fill_additional_solutions_in_response() const;
    //        void set_fill_additional_solutions_in_response( bool value );

    //    private:
    //        bool _internal_fill_additional_solutions_in_response() const;
    //        void _internal_set_fill_additional_solutions_in_response( bool value );

    //    public:
    //        // optional bool stop_after_first_solution = 98 [default = false];
    //        bool has_stop_after_first_solution() const;
    //        void clear_stop_after_first_solution();
    //        bool stop_after_first_solution() const;
    //        void set_stop_after_first_solution( bool value );

    //    private:
    //        bool _internal_stop_after_first_solution() const;
    //        void _internal_set_stop_after_first_solution( bool value );

    //    public:
    //        // optional bool stop_after_presolve = 149 [default = false];
    //        bool has_stop_after_presolve() const;
    //        void clear_stop_after_presolve();
    //        bool stop_after_presolve() const;
    //        void set_stop_after_presolve( bool value );

    //    private:
    //        bool _internal_stop_after_presolve() const;
    //        void _internal_set_stop_after_presolve( bool value );

    //    public:
    //        // optional bool permute_presolve_constraint_order = 179 [default = false];
    //        bool has_permute_presolve_constraint_order() const;
    //        void clear_permute_presolve_constraint_order();
    //        bool permute_presolve_constraint_order() const;
    //        void set_permute_presolve_constraint_order( bool value );

    //    private:
    //        bool _internal_permute_presolve_constraint_order() const;
    //        void _internal_set_permute_presolve_constraint_order( bool value );

    //    public:
    //        // optional bool use_absl_random = 180 [default = false];
    //        bool has_use_absl_random() const;
    //        void clear_use_absl_random();
    //        bool use_absl_random() const;
    //        void set_use_absl_random( bool value );


    //    public:
    //        // optional bool log_search_progress = 41 [default = false];
    //        bool has_log_search_progress() const;
    //        void clear_log_search_progress();
    //        bool log_search_progress() const;

    /**
     * C++  void set_log_search_progress( bool value );
     */
    set_log_search_progress(value: boolean): void;


    //    public:
    //        // optional bool log_subsolver_statistics = 189 [default = false];
    //        bool has_log_subsolver_statistics() const;
    //        void clear_log_subsolver_statistics();
    //        bool log_subsolver_statistics() const;
    //        void set_log_subsolver_statistics( bool value );


    //    public:
    //        // optional bool polish_lp_solution = 175 [default = false];
    //        bool has_polish_lp_solution() const;
    //        void clear_polish_lp_solution();
    //        bool polish_lp_solution() const;
    //        void set_polish_lp_solution( bool value );


    //    public:
    //        // optional bool only_add_cuts_at_level_zero = 92 [default = false];
    //        bool has_only_add_cuts_at_level_zero() const;
    //        void clear_only_add_cuts_at_level_zero();
    //        bool only_add_cuts_at_level_zero() const;
    //        void set_only_add_cuts_at_level_zero( bool value );


    //    public:
    //        // optional bool add_objective_cut = 197 [default = false];
    //        bool has_add_objective_cut() const;
    //        void clear_add_objective_cut();
    //        bool add_objective_cut() const;
    //        void set_add_objective_cut( bool value );


    //    public:
    //        // optional bool exploit_best_solution = 130 [default = false];
    //        bool has_exploit_best_solution() const;
    //        void clear_exploit_best_solution();
    //        bool exploit_best_solution() const;
    //        void set_exploit_best_solution( bool value );


    //    public:
    //        // optional int32 debug_max_num_presolve_operations = 151 [default = 0];
    //        bool      has_debug_max_num_presolve_operations() const;
    //        void      clear_debug_max_num_presolve_operations();
    //        ::int32_t debug_max_num_presolve_operations() const;
    //        void      set_debug_max_num_presolve_operations( ::int32_t value );


    //    public:
    //        // optional bool randomize_search = 103 [default = false];
    //        bool has_randomize_search() const;
    //        void clear_randomize_search();
    //        bool randomize_search() const;
    //        void set_randomize_search( bool value );


    //    public:
    //        // optional bool push_all_tasks_toward_start = 262 [default = false];
    //        bool has_push_all_tasks_toward_start() const;
    //        void clear_push_all_tasks_toward_start();
    //        bool push_all_tasks_toward_start() const;
    //        void set_push_all_tasks_toward_start( bool value );

    //    private:
    //        bool _internal_push_all_tasks_toward_start() const;
    //        void _internal_set_push_all_tasks_toward_start( bool value );

    //    public:
    //        // optional bool use_optional_variables = 108 [default = false];
    //        bool has_use_optional_variables() const;
    //        void clear_use_optional_variables();
    //        bool use_optional_variables() const;
    //        void set_use_optional_variables( bool value );

    //    private:
    //        bool _internal_use_optional_variables() const;
    //        void _internal_set_use_optional_variables( bool value );

    //    public:
    //        // optional bool use_combined_no_overlap = 133 [default = false];
    //        bool has_use_combined_no_overlap() const;
    //        void clear_use_combined_no_overlap();
    //        bool use_combined_no_overlap() const;
    //        void set_use_combined_no_overlap( bool value );

    //    private:
    //        bool _internal_use_combined_no_overlap() const;
    //        void _internal_set_use_combined_no_overlap( bool value );

    //    public:
    //        // optional bool debug_postsolve_with_full_solver = 162 [default = false];
    //        bool has_debug_postsolve_with_full_solver() const;
    //        void clear_debug_postsolve_with_full_solver();
    //        bool debug_postsolve_with_full_solver() const;
    //        void set_debug_postsolve_with_full_solver( bool value );

    //    private:
    //        bool _internal_debug_postsolve_with_full_solver() const;
    //        void _internal_set_debug_postsolve_with_full_solver( bool value );

    //    public:
    //        // optional bool debug_crash_on_bad_hint = 195 [default = false];
    //        bool has_debug_crash_on_bad_hint() const;
    //        void clear_debug_crash_on_bad_hint();
    //        bool debug_crash_on_bad_hint() const;
    //        void set_debug_crash_on_bad_hint( bool value );

    //    private:
    //        bool _internal_debug_crash_on_bad_hint() const;
    //        void _internal_set_debug_crash_on_bad_hint( bool value );

    //    public:
    //        // optional bool max_sat_reverse_assumption_order = 52 [default = false];
    //        bool has_max_sat_reverse_assumption_order() const;
    //        void clear_max_sat_reverse_assumption_order();
    //        bool max_sat_reverse_assumption_order() const;
    //        void set_max_sat_reverse_assumption_order( bool value );

    //    private:
    //        bool _internal_max_sat_reverse_assumption_order() const;
    //        void _internal_set_max_sat_reverse_assumption_order( bool value );

    //    public:
    //        // optional bool use_strong_propagation_in_disjunctive = 230 [default = false];
    //        bool has_use_strong_propagation_in_disjunctive() const;
    //        void clear_use_strong_propagation_in_disjunctive();
    //        bool use_strong_propagation_in_disjunctive() const;
    //        void set_use_strong_propagation_in_disjunctive( bool value );

    //    private:
    //        bool _internal_use_strong_propagation_in_disjunctive() const;
    //        void _internal_set_use_strong_propagation_in_disjunctive( bool value );

    //    public:
    //        // optional bool optimize_with_core = 83 [default = false];
    //        bool has_optimize_with_core() const;
    //        void clear_optimize_with_core();
    //        bool optimize_with_core() const;
    //        void set_optimize_with_core( bool value );

    //    private:
    //        bool _internal_optimize_with_core() const;
    //        void _internal_set_optimize_with_core( bool value );

    //    public:
    //        // optional bool optimize_with_lb_tree_search = 188 [default = false];
    //        bool has_optimize_with_lb_tree_search() const;
    //        void clear_optimize_with_lb_tree_search();
    //        bool optimize_with_lb_tree_search() const;
    //        void set_optimize_with_lb_tree_search( bool value );

    //    private:
    //        bool _internal_optimize_with_lb_tree_search() const;
    //        void _internal_set_optimize_with_lb_tree_search( bool value );

    //    public:
    //        // optional bool save_lp_basis_in_lb_tree_search = 284 [default = false];
    //        bool has_save_lp_basis_in_lb_tree_search() const;
    //        void clear_save_lp_basis_in_lb_tree_search();
    //        bool save_lp_basis_in_lb_tree_search() const;
    //        void set_save_lp_basis_in_lb_tree_search( bool value );

    //    private:
    //        bool _internal_save_lp_basis_in_lb_tree_search() const;
    //        void _internal_set_save_lp_basis_in_lb_tree_search( bool value );

    //    public:
    //        // optional bool optimize_with_max_hs = 85 [default = false];
    //        bool has_optimize_with_max_hs() const;
    //        void clear_optimize_with_max_hs();
    //        bool optimize_with_max_hs() const;
    //        void set_optimize_with_max_hs( bool value );

    //    private:
    //        bool _internal_optimize_with_max_hs() const;
    //        void _internal_set_optimize_with_max_hs( bool value );

    //    public:
    //        // optional double relative_gap_limit = 160 [default = 0];
    //        bool   has_relative_gap_limit() const;
    //        void   clear_relative_gap_limit();
    //        double relative_gap_limit() const;
    //        void   set_relative_gap_limit( double value );

    //    private:
    //        double _internal_relative_gap_limit() const;
    //        void   _internal_set_relative_gap_limit( double value );

    //    public:
    //        // optional bool use_timetable_edge_finding_in_cumulative = 79 [default = false];
    //        bool has_use_timetable_edge_finding_in_cumulative() const;
    //        void clear_use_timetable_edge_finding_in_cumulative();
    //        bool use_timetable_edge_finding_in_cumulative() const;
    //        void set_use_timetable_edge_finding_in_cumulative( bool value );

    //    private:
    //        bool _internal_use_timetable_edge_finding_in_cumulative() const;
    //        void _internal_set_use_timetable_edge_finding_in_cumulative( bool value );

    //    public:
    //        // optional bool use_hard_precedences_in_cumulative = 215 [default = false];
    //        bool has_use_hard_precedences_in_cumulative() const;
    //        void clear_use_hard_precedences_in_cumulative();
    //        bool use_hard_precedences_in_cumulative() const;
    //        void set_use_hard_precedences_in_cumulative( bool value );

    //    private:
    //        bool _internal_use_hard_precedences_in_cumulative() const;
    //        void _internal_set_use_hard_precedences_in_cumulative( bool value );

    //    public:
    //        // optional bool exploit_all_precedences = 220 [default = false];
    //        bool has_exploit_all_precedences() const;
    //        void clear_exploit_all_precedences();
    //        bool exploit_all_precedences() const;
    //        void set_exploit_all_precedences( bool value );

    //    private:
    //        bool _internal_exploit_all_precedences() const;
    //        void _internal_set_exploit_all_precedences( bool value );

    //    public:
    //        // optional bool use_timetabling_in_no_overlap_2d = 200 [default = false];
    //        bool has_use_timetabling_in_no_overlap_2d() const;
    //        void clear_use_timetabling_in_no_overlap_2d();
    //        bool use_timetabling_in_no_overlap_2d() const;

    /**
     * C++  void set_use_timetabling_in_no_overlap_2d( bool value );
     */
    set_use_timetabling_in_no_overlap_2d(value: boolean): void;


    //    public:
    //        // optional bool use_ls_only = 240 [default = false];
    //        bool has_use_ls_only() const;
    //        void clear_use_ls_only();
    //        bool use_ls_only() const;
    //        void set_use_ls_only( bool value );

    //    private:
    //        bool _internal_use_ls_only() const;
    //        void _internal_set_use_ls_only( bool value );

    //    public:
    //        // optional bool use_shared_tree_search = 236 [default = false];
    //        bool has_use_shared_tree_search() const;
    //        void clear_use_shared_tree_search();
    //        bool use_shared_tree_search() const;
    //        void set_use_shared_tree_search( bool value );

    //    private:
    //        bool _internal_use_shared_tree_search() const;
    //        void _internal_set_use_shared_tree_search( bool value );

    //    public:
    //        // optional bool enumerate_all_solutions = 87 [default = false];
    //        bool has_enumerate_all_solutions() const;
    //        void clear_enumerate_all_solutions();
    //        bool enumerate_all_solutions() const;
    //        void set_enumerate_all_solutions( bool value );

    //    private:
    //        bool _internal_enumerate_all_solutions() const;
    //        void _internal_set_enumerate_all_solutions( bool value );

    //    public:
    //        // optional bool keep_all_feasible_solutions_in_presolve = 173 [default = false];
    //        bool has_keep_all_feasible_solutions_in_presolve() const;
    //        void clear_keep_all_feasible_solutions_in_presolve();
    //        bool keep_all_feasible_solutions_in_presolve() const;
    //        void set_keep_all_feasible_solutions_in_presolve( bool value );

    //    private:
    //        bool _internal_keep_all_feasible_solutions_in_presolve() const;
    //        void _internal_set_keep_all_feasible_solutions_in_presolve( bool value );

    //    public:
    //        // optional bool stop_after_root_propagation = 252 [default = false];
    //        bool has_stop_after_root_propagation() const;
    //        void clear_stop_after_root_propagation();
    //        bool stop_after_root_propagation() const;
    //        void set_stop_after_root_propagation( bool value );

    //    private:
    //        bool _internal_stop_after_root_propagation() const;
    //        void _internal_set_stop_after_root_propagation( bool value );

    //    public:
    //        // optional bool use_lns_only = 101 [default = false];
    //        bool has_use_lns_only() const;
    //        void clear_use_lns_only();
    //        bool use_lns_only() const;
    //        void set_use_lns_only( bool value );

    //    private:
    //        bool _internal_use_lns_only() const;
    //        void _internal_set_use_lns_only( bool value );

    //    public:
    //        // optional bool use_lb_relax_lns = 255 [default = false];
    //        bool has_use_lb_relax_lns() const;
    //        void clear_use_lb_relax_lns();
    //        bool use_lb_relax_lns() const;
    //        void set_use_lb_relax_lns( bool value );

    //    private:
    //        bool _internal_use_lb_relax_lns() const;
    //        void _internal_set_use_lb_relax_lns( bool value );

    //    public:
    //        // optional bool diversify_lns_params = 137 [default = false];
    //        bool has_diversify_lns_params() const;
    //        void clear_diversify_lns_params();
    //        bool diversify_lns_params() const;
    //        void set_diversify_lns_params( bool value );

    //    private:
    //        bool _internal_diversify_lns_params() const;
    //        void _internal_set_diversify_lns_params( bool value );

    //    public:
    //        // optional bool encode_complex_linear_constraint_with_integer = 223 [default = false];
    //        bool has_encode_complex_linear_constraint_with_integer() const;
    //        void clear_encode_complex_linear_constraint_with_integer();
    //        bool encode_complex_linear_constraint_with_integer() const;
    //        void set_encode_complex_linear_constraint_with_integer( bool value );

    //    private:
    //        bool _internal_encode_complex_linear_constraint_with_integer() const;
    //        void _internal_set_encode_complex_linear_constraint_with_integer( bool value );

    //    public:
    //        // optional bool presolve_extract_integer_enforcement = 174 [default = false];
    //        bool has_presolve_extract_integer_enforcement() const;
    //        void clear_presolve_extract_integer_enforcement();
    //        bool presolve_extract_integer_enforcement() const;
    //        void set_presolve_extract_integer_enforcement( bool value );

    //    private:
    //        bool _internal_presolve_extract_integer_enforcement() const;
    //        void _internal_set_presolve_extract_integer_enforcement( bool value );

    //    public:
    //        // optional bool interleave_search = 136 [default = false];
    //        bool has_interleave_search() const;
    //        void clear_interleave_search();
    //        bool interleave_search() const;
    //        void set_interleave_search( bool value );

    //    private:
    //        bool _internal_interleave_search() const;
    //        void _internal_set_interleave_search( bool value );

    //    public:
    //        // optional bool share_glue_clauses = 285 [default = false];
    //        bool has_share_glue_clauses() const;
    //        void clear_share_glue_clauses();
    //        bool share_glue_clauses() const;
    //        void set_share_glue_clauses( bool value );

    //    private:
    //        bool _internal_share_glue_clauses() const;
    //        void _internal_set_share_glue_clauses( bool value );

    //    public:
    //        // optional int32 num_workers = 206 [default = 0];
    //        bool      has_num_workers() const;
    //        void      clear_num_workers();
    //        ::int32_t num_workers() const;
    //        void      set_num_workers( ::int32_t value );

    //    private:
    //        ::int32_t _internal_num_workers() const;
    //        void      _internal_set_num_workers( ::int32_t value );

    //    public:
    //        // optional bool use_energetic_reasoning_in_no_overlap_2d = 213 [default = false];
    //        bool has_use_energetic_reasoning_in_no_overlap_2d() const;
    //        void clear_use_energetic_reasoning_in_no_overlap_2d();
    //        bool use_energetic_reasoning_in_no_overlap_2d() const;

    /**
     * C++  void set_use_energetic_reasoning_in_no_overlap_2d( bool value );
     */
    set_use_energetic_reasoning_in_no_overlap_2d(value: boolean): void;


    //    public:
    //        // optional bool use_area_energetic_reasoning_in_no_overlap_2d = 271 [default = false];
    //        bool has_use_area_energetic_reasoning_in_no_overlap_2d() const;
    //        void clear_use_area_energetic_reasoning_in_no_overlap_2d();
    //        bool use_area_energetic_reasoning_in_no_overlap_2d() const;
    //        void set_use_area_energetic_reasoning_in_no_overlap_2d( bool value );

    //    private:
    //        bool _internal_use_area_energetic_reasoning_in_no_overlap_2d() const;
    //        void _internal_set_use_area_energetic_reasoning_in_no_overlap_2d( bool value );

    //    public:
    //        // optional bool repair_hint = 167 [default = false];
    //        bool has_repair_hint() const;
    //        void clear_repair_hint();
    //        bool repair_hint() const;
    //        void set_repair_hint( bool value );

    //    private:
    //        bool _internal_repair_hint() const;
    //        void _internal_set_repair_hint( bool value );

    //    public:
    //        // optional bool fix_variables_to_their_hinted_value = 192 [default = false];
    //        bool has_fix_variables_to_their_hinted_value() const;
    //        void clear_fix_variables_to_their_hinted_value();
    //        bool fix_variables_to_their_hinted_value() const;
    //        void set_fix_variables_to_their_hinted_value( bool value );

    //    private:
    //        bool _internal_fix_variables_to_their_hinted_value() const;
    //        void _internal_set_fix_variables_to_their_hinted_value( bool value );

    //    public:
    //        // optional bool exploit_relaxation_solution = 161 [default = false];
    //        bool has_exploit_relaxation_solution() const;
    //        void clear_exploit_relaxation_solution();
    //        bool exploit_relaxation_solution() const;
    //        void set_exploit_relaxation_solution( bool value );

    //    private:
    //        bool _internal_exploit_relaxation_solution() const;
    //        void _internal_set_exploit_relaxation_solution( bool value );

    //    public:
    //        // optional bool detect_linearized_product = 277 [default = false];
    //        bool has_detect_linearized_product() const;
    //        void clear_detect_linearized_product();
    //        bool detect_linearized_product() const;
    //        void set_detect_linearized_product( bool value );

    //    private:
    //        bool _internal_detect_linearized_product() const;
    //        void _internal_set_detect_linearized_product( bool value );

    //    public:
    //        // optional bool mip_scale_large_domain = 225 [default = false];
    //        bool has_mip_scale_large_domain() const;
    //        void clear_mip_scale_large_domain();
    //        bool mip_scale_large_domain() const;
    //        void set_mip_scale_large_domain( bool value );

    //    private:
    //        bool _internal_mip_scale_large_domain() const;
    //        void _internal_set_mip_scale_large_domain( bool value );

    //    public:
    //        // optional bool only_solve_ip = 222 [default = false];
    //        bool has_only_solve_ip() const;
    //        void clear_only_solve_ip();
    //        bool only_solve_ip() const;
    //        void set_only_solve_ip( bool value );

    //    private:
    //        bool _internal_only_solve_ip() const;
    //        void _internal_set_only_solve_ip( bool value );

    //    public:
    //        // optional bool use_dynamic_precedence_in_disjunctive = 263 [default = false];
    //        bool has_use_dynamic_precedence_in_disjunctive() const;
    //        void clear_use_dynamic_precedence_in_disjunctive();
    //        bool use_dynamic_precedence_in_disjunctive() const;
    //        void set_use_dynamic_precedence_in_disjunctive( bool value );

    //    private:
    //        bool _internal_use_dynamic_precedence_in_disjunctive() const;
    //        void _internal_set_use_dynamic_precedence_in_disjunctive( bool value );

    //    public:
    //        // optional bool use_dynamic_precedence_in_cumulative = 268 [default = false];
    //        bool has_use_dynamic_precedence_in_cumulative() const;
    //        void clear_use_dynamic_precedence_in_cumulative();
    //        bool use_dynamic_precedence_in_cumulative() const;
    //        void set_use_dynamic_precedence_in_cumulative( bool value );

    //    private:
    //        bool _internal_use_dynamic_precedence_in_cumulative() const;
    //        void _internal_set_use_dynamic_precedence_in_cumulative( bool value );

    //    public:
    //        // optional bool use_overload_checker_in_cumulative = 78 [default = false];
    //        bool has_use_overload_checker_in_cumulative() const;
    //        void clear_use_overload_checker_in_cumulative();
    //        bool use_overload_checker_in_cumulative() const;
    //        void set_use_overload_checker_in_cumulative( bool value );

    //    private:
    //        bool _internal_use_overload_checker_in_cumulative() const;
    //        void _internal_set_use_overload_checker_in_cumulative( bool value );

    //    public:
    //        // optional bool use_conservative_scale_overload_checker = 286 [default = false];
    //        bool has_use_conservative_scale_overload_checker() const;
    //        void clear_use_conservative_scale_overload_checker();
    //        bool use_conservative_scale_overload_checker() const;
    //        void set_use_conservative_scale_overload_checker( bool value );

    //    private:
    //        bool _internal_use_conservative_scale_overload_checker() const;
    //        void _internal_set_use_conservative_scale_overload_checker( bool value );

    //    public:
    //        // optional bool expand_alldiff_constraints = 170 [default = false];
    //        bool has_expand_alldiff_constraints() const;
    //        void clear_expand_alldiff_constraints();
    //        bool expand_alldiff_constraints() const;
    //        void set_expand_alldiff_constraints( bool value );

    //    private:
    //        bool _internal_expand_alldiff_constraints() const;
    //        void _internal_set_expand_alldiff_constraints( bool value );

    //    public:
    //        // optional bool expand_reservoir_using_circuit = 288 [default = false];
    //        bool has_expand_reservoir_using_circuit() const;
    //        void clear_expand_reservoir_using_circuit();
    //        bool expand_reservoir_using_circuit() const;
    //        void set_expand_reservoir_using_circuit( bool value );

    //    private:
    //        bool _internal_expand_reservoir_using_circuit() const;
    //        void _internal_set_expand_reservoir_using_circuit( bool value );

    //    public:
    //        // optional bool encode_cumulative_as_reservoir = 287 [default = false];
    //        bool has_encode_cumulative_as_reservoir() const;
    //        void clear_encode_cumulative_as_reservoir();
    //        bool encode_cumulative_as_reservoir() const;
    //        void set_encode_cumulative_as_reservoir( bool value );

    //    private:
    //        bool _internal_encode_cumulative_as_reservoir() const;
    //        void _internal_set_encode_cumulative_as_reservoir( bool value );

    //    public:
    //        // optional bool disable_constraint_expansion = 181 [default = false];
    //        bool has_disable_constraint_expansion() const;
    //        void clear_disable_constraint_expansion();
    //        bool disable_constraint_expansion() const;
    //        void set_disable_constraint_expansion( bool value );

    //    private:
    //        bool _internal_disable_constraint_expansion() const;
    //        void _internal_set_disable_constraint_expansion( bool value );

    //    public:
    //        // optional int32 shared_tree_num_workers = 235 [default = 0];
    //        bool      has_shared_tree_num_workers() const;
    //        void      clear_shared_tree_num_workers();
    //        ::int32_t shared_tree_num_workers() const;
    //        void      set_shared_tree_num_workers( ::int32_t value );

    //    private:
    //        ::int32_t _internal_shared_tree_num_workers() const;
    //        void      _internal_set_shared_tree_num_workers( ::int32_t value );

    //    public:
    //        // optional bool use_probing_search = 176 [default = false];
    //        bool has_use_probing_search() const;
    //        void clear_use_probing_search();
    //        bool use_probing_search() const;
    //        void set_use_probing_search( bool value );

    //    private:
    //        bool _internal_use_probing_search() const;
    //        void _internal_set_use_probing_search( bool value );

    //    public:
    //        // optional bool use_objective_lb_search = 228 [default = false];
    //        bool has_use_objective_lb_search() const;
    //        void clear_use_objective_lb_search();
    //        bool use_objective_lb_search() const;
    //        void set_use_objective_lb_search( bool value );

    //    private:
    //        bool _internal_use_objective_lb_search() const;
    //        void _internal_set_use_objective_lb_search( bool value );

    //    public:
    //        // optional bool use_objective_shaving_search = 253 [default = false];
    //        bool has_use_objective_shaving_search() const;
    //        void clear_use_objective_shaving_search();
    //        bool use_objective_shaving_search() const;
    //        void set_use_objective_shaving_search( bool value );

    //    private:
    //        bool _internal_use_objective_shaving_search() const;
    //        void _internal_set_use_objective_shaving_search( bool value );

    //    public:
    //        // optional bool use_variables_shaving_search = 289 [default = false];
    //        bool has_use_variables_shaving_search() const;
    //        void clear_use_variables_shaving_search();
    //        bool use_variables_shaving_search() const;
    //        void set_use_variables_shaving_search( bool value );

    //    private:
    //        bool _internal_use_variables_shaving_search() const;
    //        void _internal_set_use_variables_shaving_search( bool value );

    //    public:
    //        // optional .operations_research.sat.SatParameters.SharedTreeSplitStrategy shared_tree_split_strategy = 239 [default = SPLIT_STRATEGY_AUTO];
    //        bool                                                              has_shared_tree_split_strategy() const;
    //        void                                                              clear_shared_tree_split_strategy();
    //        ::operations_research::sat::SatParameters_SharedTreeSplitStrategy shared_tree_split_strategy() const;
    //        void                                                              set_shared_tree_split_strategy( ::operations_research::sat::SatParameters_SharedTreeSplitStrategy value );

    //    private:
    //        ::operations_research::sat::SatParameters_SharedTreeSplitStrategy _internal_shared_tree_split_strategy() const;
    //        void                                                              _internal_set_shared_tree_split_strategy( ::operations_research::sat::SatParameters_SharedTreeSplitStrategy value );

    //    public:
    //        // optional int32 num_violation_ls = 244 [default = 0];
    //        bool      has_num_violation_ls() const;
    //        void      clear_num_violation_ls();
    //        ::int32_t num_violation_ls() const;
    //        void      set_num_violation_ls( ::int32_t value );

    //    private:
    //        ::int32_t _internal_num_violation_ls() const;
    //        void      _internal_set_num_violation_ls( ::int32_t value );

    //    public:
    //        // optional bool mip_treat_high_magnitude_bounds_as_infinity = 278 [default = false];
    //        bool has_mip_treat_high_magnitude_bounds_as_infinity() const;
    //        void clear_mip_treat_high_magnitude_bounds_as_infinity();
    //        bool mip_treat_high_magnitude_bounds_as_infinity() const;
    //        void set_mip_treat_high_magnitude_bounds_as_infinity( bool value );

    //    private:
    //        bool _internal_mip_treat_high_magnitude_bounds_as_infinity() const;
    //        void _internal_set_mip_treat_high_magnitude_bounds_as_infinity( bool value );

    //    public:
    //        // optional int32 max_lin_max_size_for_expansion = 280 [default = 0];
    //        bool      has_max_lin_max_size_for_expansion() const;
    //        void      clear_max_lin_max_size_for_expansion();
    //        ::int32_t max_lin_max_size_for_expansion() const;
    //        void      set_max_lin_max_size_for_expansion( ::int32_t value );

    //    private:
    //        ::int32_t _internal_max_lin_max_size_for_expansion() const;
    //        void      _internal_set_max_lin_max_size_for_expansion( ::int32_t value );

    //    public:
    //        // optional int32 max_num_deterministic_batches = 291 [default = 0];
    //        bool      has_max_num_deterministic_batches() const;
    //        void      clear_max_num_deterministic_batches();
    //        ::int32_t max_num_deterministic_batches() const;
    //        void      set_max_num_deterministic_batches( ::int32_t value );

    //    private:
    //        ::int32_t _internal_max_num_deterministic_batches() const;
    //        void      _internal_set_max_num_deterministic_batches( ::int32_t value );

    //    public:
    //        // optional int32 num_full_subsolvers = 294 [default = 0];
    //        bool      has_num_full_subsolvers() const;
    //        void      clear_num_full_subsolvers();
    //        ::int32_t num_full_subsolvers() const;
    //        void      set_num_full_subsolvers( ::int32_t value );

    //    private:
    //        ::int32_t _internal_num_full_subsolvers() const;
    //        void      _internal_set_num_full_subsolvers( ::int32_t value );

    //    public:
    //        // optional int32 shared_tree_worker_min_restarts_per_subtree = 282 [default = 1];
    //        bool      has_shared_tree_worker_min_restarts_per_subtree() const;
    //        void      clear_shared_tree_worker_min_restarts_per_subtree();
    //        ::int32_t shared_tree_worker_min_restarts_per_subtree() const;
    //        void      set_shared_tree_worker_min_restarts_per_subtree( ::int32_t value );

    //    private:
    //        ::int32_t _internal_shared_tree_worker_min_restarts_per_subtree() const;
    //        void      _internal_set_shared_tree_worker_min_restarts_per_subtree( ::int32_t value );

    //    public:
    //        // optional .operations_research.sat.SatParameters.Polarity initial_polarity = 2 [default = POLARITY_FALSE];
    //        bool                                               has_initial_polarity() const;
    //        void                                               clear_initial_polarity();
    //        ::operations_research::sat::SatParameters_Polarity initial_polarity() const;
    //        void                                               set_initial_polarity( ::operations_research::sat::SatParameters_Polarity value );

    //    private:
    //        ::operations_research::sat::SatParameters_Polarity _internal_initial_polarity() const;
    //        void                                               _internal_set_initial_polarity( ::operations_research::sat::SatParameters_Polarity value );

    //    public:
    //        // optional .operations_research.sat.SatParameters.ConflictMinimizationAlgorithm minimization_algorithm = 4 [default = RECURSIVE];
    //        bool                                                                    has_minimization_algorithm() const;
    //        void                                                                    clear_minimization_algorithm();
    //        ::operations_research::sat::SatParameters_ConflictMinimizationAlgorithm minimization_algorithm() const;
    //        void                                                                    set_minimization_algorithm( ::operations_research::sat::SatParameters_ConflictMinimizationAlgorithm value );

    //    private:
    //        ::operations_research::sat::SatParameters_ConflictMinimizationAlgorithm _internal_minimization_algorithm() const;
    //        void                                                                    _internal_set_minimization_algorithm( ::operations_research::sat::SatParameters_ConflictMinimizationAlgorithm value );

    //    public:
    //        // optional double variable_activity_decay = 15 [default = 0.8];
    //        bool   has_variable_activity_decay() const;
    //        void   clear_variable_activity_decay();
    //        double variable_activity_decay() const;
    //        void   set_variable_activity_decay( double value );

    //    private:
    //        double _internal_variable_activity_decay() const;
    //        void   _internal_set_variable_activity_decay( double value );

    //    public:
    //        // optional double max_variable_activity_value = 16 [default = 1e+100];
    //        bool   has_max_variable_activity_value() const;
    //        void   clear_max_variable_activity_value();
    //        double max_variable_activity_value() const;
    //        void   set_max_variable_activity_value( double value );

    //    private:
    //        double _internal_max_variable_activity_value() const;
    //        void   _internal_set_max_variable_activity_value( double value );

    //    public:
    //        // optional double clause_activity_decay = 17 [default = 0.999];
    //        bool   has_clause_activity_decay() const;
    //        void   clear_clause_activity_decay();
    //        double clause_activity_decay() const;
    //        void   set_clause_activity_decay( double value );

    //    private:
    //        double _internal_clause_activity_decay() const;
    //        void   _internal_set_clause_activity_decay( double value );

    //    public:
    //        // optional int32 clause_cleanup_period = 11 [default = 10000];
    //        bool      has_clause_cleanup_period() const;
    //        void      clear_clause_cleanup_period();
    //        ::int32_t clause_cleanup_period() const;
    //        void      set_clause_cleanup_period( ::int32_t value );

    //    private:
    //        ::int32_t _internal_clause_cleanup_period() const;
    //        void      _internal_set_clause_cleanup_period( ::int32_t value );

    //    public:
    //        // optional int32 glucose_decay_increment_period = 24 [default = 5000];
    //        bool      has_glucose_decay_increment_period() const;
    //        void      clear_glucose_decay_increment_period();
    //        ::int32_t glucose_decay_increment_period() const;
    //        void      set_glucose_decay_increment_period( ::int32_t value );

    //    private:
    //        ::int32_t _internal_glucose_decay_increment_period() const;
    //        void      _internal_set_glucose_decay_increment_period( ::int32_t value );

    //    public:
    //        // optional double max_clause_activity_value = 18 [default = 1e+20];
    //        bool   has_max_clause_activity_value() const;
    //        void   clear_max_clause_activity_value();
    //        double max_clause_activity_value() const;
    //        void   set_max_clause_activity_value( double value );

    //    private:
    //        double _internal_max_clause_activity_value() const;
    //        void   _internal_set_max_clause_activity_value( double value );

    //    public:
    //        // optional double glucose_max_decay = 22 [default = 0.95];
    //        bool   has_glucose_max_decay() const;
    //        void   clear_glucose_max_decay();
    //        double glucose_max_decay() const;
    //        void   set_glucose_max_decay( double value );

    //    private:
    //        double _internal_glucose_max_decay() const;
    //        void   _internal_set_glucose_max_decay( double value );

    //    public:
    //        // optional double glucose_decay_increment = 23 [default = 0.01];
    //        bool   has_glucose_decay_increment() const;
    //        void   clear_glucose_decay_increment();
    //        double glucose_decay_increment() const;
    //        void   set_glucose_decay_increment( double value );

    //    private:
    //        double _internal_glucose_decay_increment() const;
    //        void   _internal_set_glucose_decay_increment( double value );

    //    public:
    //        // optional int32 restart_period = 30 [default = 50];
    //        bool      has_restart_period() const;
    //        void      clear_restart_period();
    //        ::int32_t restart_period() const;
    //        void      set_restart_period( ::int32_t value );

    //    private:
    //        ::int32_t _internal_restart_period() const;
    //        void      _internal_set_restart_period( ::int32_t value );

    //    public:
    //        // optional int32 random_seed = 31 [default = 1];
    //        bool      has_random_seed() const;
    //        void      clear_random_seed();
    //        ::int32_t random_seed() const;
    //        void      set_random_seed( ::int32_t value );

    //    private:
    //        ::int32_t _internal_random_seed() const;
    //        void      _internal_set_random_seed( ::int32_t value );

    //    public:
    //        // optional double max_time_in_seconds = 36 [default = inf];
    //        bool   has_max_time_in_seconds() const;
    //        void   clear_max_time_in_seconds();
    //        double max_time_in_seconds() const;
    //        void   set_max_time_in_seconds( double value );

    //    private:
    //        double _internal_max_time_in_seconds() const;
    //        void   _internal_set_max_time_in_seconds( double value );

    //    public:
    //        // optional int64 max_number_of_conflicts = 37 [default = 9223372036854775807];
    //        bool      has_max_number_of_conflicts() const;
    //        void      clear_max_number_of_conflicts();
    //        ::int64_t max_number_of_conflicts() const;
    //        void      set_max_number_of_conflicts( ::int64_t value );

    //    private:
    //        ::int64_t _internal_max_number_of_conflicts() const;
    //        void      _internal_set_max_number_of_conflicts( ::int64_t value );

    //    public:
    //        // optional int64 max_memory_in_mb = 40 [default = 10000];
    //        bool      has_max_memory_in_mb() const;
    //        void      clear_max_memory_in_mb();
    //        ::int64_t max_memory_in_mb() const;
    //        void      set_max_memory_in_mb( ::int64_t value );

    //    private:
    //        ::int64_t _internal_max_memory_in_mb() const;
    //        void      _internal_set_max_memory_in_mb( ::int64_t value );

    //    public:
    //        // optional .operations_research.sat.SatParameters.BinaryMinizationAlgorithm binary_minimization_algorithm = 34 [default = BINARY_MINIMIZATION_FIRST];
    //        bool                                                                has_binary_minimization_algorithm() const;
    //        void                                                                clear_binary_minimization_algorithm();
    //        ::operations_research::sat::SatParameters_BinaryMinizationAlgorithm binary_minimization_algorithm() const;
    //        void                                                                set_binary_minimization_algorithm( ::operations_research::sat::SatParameters_BinaryMinizationAlgorithm value );

    //    private:
    //        ::operations_research::sat::SatParameters_BinaryMinizationAlgorithm _internal_binary_minimization_algorithm() const;
    //        void                                                                _internal_set_binary_minimization_algorithm( ::operations_research::sat::SatParameters_BinaryMinizationAlgorithm value );

    //    public:
    //        // optional int32 pb_cleanup_increment = 46 [default = 200];
    //        bool      has_pb_cleanup_increment() const;
    //        void      clear_pb_cleanup_increment();
    //        ::int32_t pb_cleanup_increment() const;
    //        void      set_pb_cleanup_increment( ::int32_t value );

    //    private:
    //        ::int32_t _internal_pb_cleanup_increment() const;
    //        void      _internal_set_pb_cleanup_increment( ::int32_t value );

    //    public:
    //        // optional double pb_cleanup_ratio = 47 [default = 0.5];
    //        bool   has_pb_cleanup_ratio() const;
    //        void   clear_pb_cleanup_ratio();
    //        double pb_cleanup_ratio() const;
    //        void   set_pb_cleanup_ratio( double value );

    //    private:
    //        double _internal_pb_cleanup_ratio() const;
    //        void   _internal_set_pb_cleanup_ratio( double value );

    //    public:
    //        // optional int32 core_minimization_level = 50 [default = 2];
    //        bool      has_core_minimization_level() const;
    //        void      clear_core_minimization_level();
    //        ::int32_t core_minimization_level() const;
    //        void      set_core_minimization_level( ::int32_t value );

    //    private:
    //        ::int32_t _internal_core_minimization_level() const;
    //        void      _internal_set_core_minimization_level( ::int32_t value );

    //    public:
    //        // optional .operations_research.sat.SatParameters.MaxSatStratificationAlgorithm max_sat_stratification = 53 [default = STRATIFICATION_DESCENT];
    //        bool                                                                    has_max_sat_stratification() const;
    //        void                                                                    clear_max_sat_stratification();
    //        ::operations_research::sat::SatParameters_MaxSatStratificationAlgorithm max_sat_stratification() const;
    //        void                                                                    set_max_sat_stratification( ::operations_research::sat::SatParameters_MaxSatStratificationAlgorithm value );

    //    private:
    //        ::operations_research::sat::SatParameters_MaxSatStratificationAlgorithm _internal_max_sat_stratification() const;
    //        void                                                                    _internal_set_max_sat_stratification( ::operations_research::sat::SatParameters_MaxSatStratificationAlgorithm value );

    //    public:
    //        // optional int32 presolve_bve_threshold = 54 [default = 500];
    //        bool      has_presolve_bve_threshold() const;
    //        void      clear_presolve_bve_threshold();
    //        ::int32_t presolve_bve_threshold() const;
    //        void      set_presolve_bve_threshold( ::int32_t value );

    //    private:
    //        ::int32_t _internal_presolve_bve_threshold() const;
    //        void      _internal_set_presolve_bve_threshold( ::int32_t value );

    //    public:
    //        // optional int32 presolve_bve_clause_weight = 55 [default = 3];
    //        bool      has_presolve_bve_clause_weight() const;
    //        void      clear_presolve_bve_clause_weight();
    //        ::int32_t presolve_bve_clause_weight() const;
    //        void      set_presolve_bve_clause_weight( ::int32_t value );

    //    private:
    //        ::int32_t _internal_presolve_bve_clause_weight() const;
    //        void      _internal_set_presolve_bve_clause_weight( ::int32_t value );

    //    public:
    //        // optional double presolve_probing_deterministic_time_limit = 57 [default = 30];
    //        bool   has_presolve_probing_deterministic_time_limit() const;
    //        void   clear_presolve_probing_deterministic_time_limit();
    //        double presolve_probing_deterministic_time_limit() const;
    //        void   set_presolve_probing_deterministic_time_limit( double value );

    //    private:
    //        double _internal_presolve_probing_deterministic_time_limit() const;
    //        void   _internal_set_presolve_probing_deterministic_time_limit( double value );

    //    public:
    //        // optional int32 clause_cleanup_lbd_bound = 59 [default = 5];
    //        bool      has_clause_cleanup_lbd_bound() const;
    //        void      clear_clause_cleanup_lbd_bound();
    //        ::int32_t clause_cleanup_lbd_bound() const;
    //        void      set_clause_cleanup_lbd_bound( ::int32_t value );

    //    private:
    //        ::int32_t _internal_clause_cleanup_lbd_bound() const;
    //        void      _internal_set_clause_cleanup_lbd_bound( ::int32_t value );

    //    public:
    //        // optional int32 restart_running_window_size = 62 [default = 50];
    //        bool      has_restart_running_window_size() const;
    //        void      clear_restart_running_window_size();
    //        ::int32_t restart_running_window_size() const;
    //        void      set_restart_running_window_size( ::int32_t value );

    //    private:
    //        ::int32_t _internal_restart_running_window_size() const;
    //        void      _internal_set_restart_running_window_size( ::int32_t value );

    //    public:
    //        // optional double restart_dl_average_ratio = 63 [default = 1];
    //        bool   has_restart_dl_average_ratio() const;
    //        void   clear_restart_dl_average_ratio();
    //        double restart_dl_average_ratio() const;
    //        void   set_restart_dl_average_ratio( double value );

    //    private:
    //        double _internal_restart_dl_average_ratio() const;
    //        void   _internal_set_restart_dl_average_ratio( double value );

    //    public:
    //        // optional double blocking_restart_multiplier = 66 [default = 1.4];
    //        bool   has_blocking_restart_multiplier() const;
    //        void   clear_blocking_restart_multiplier();
    //        double blocking_restart_multiplier() const;
    //        void   set_blocking_restart_multiplier( double value );

    //    private:
    //        double _internal_blocking_restart_multiplier() const;
    //        void   _internal_set_blocking_restart_multiplier( double value );

    //    public:
    //        // optional double max_deterministic_time = 67 [default = inf];
    //        bool   has_max_deterministic_time() const;
    //        void   clear_max_deterministic_time();
    //        double max_deterministic_time() const;
    //        void   set_max_deterministic_time( double value );

    //    private:
    //        double _internal_max_deterministic_time() const;
    //        void   _internal_set_max_deterministic_time( double value );

    //    public:
    //        // optional int32 blocking_restart_window_size = 65 [default = 5000];
    //        bool      has_blocking_restart_window_size() const;
    //        void      clear_blocking_restart_window_size();
    //        ::int32_t blocking_restart_window_size() const;
    //        void      set_blocking_restart_window_size( ::int32_t value );

    //    private:
    //        ::int32_t _internal_blocking_restart_window_size() const;
    //        void      _internal_set_blocking_restart_window_size( ::int32_t value );

    //    public:
    //        // optional bool use_optimization_hints = 35 [default = true];
    //        bool has_use_optimization_hints() const;
    //        void clear_use_optimization_hints();
    //        bool use_optimization_hints() const;
    //        void set_use_optimization_hints( bool value );

    //    private:
    //        bool _internal_use_optimization_hints() const;
    //        void _internal_set_use_optimization_hints( bool value );

    //    public:
    //        // optional bool find_multiple_cores = 84 [default = true];
    //        bool has_find_multiple_cores() const;
    //        void clear_find_multiple_cores();
    //        bool find_multiple_cores() const;
    //        void set_find_multiple_cores( bool value );

    //    private:
    //        bool _internal_find_multiple_cores() const;
    //        void _internal_set_find_multiple_cores( bool value );

    //    public:
    //        // optional bool cover_optimization = 89 [default = true];
    //        bool has_cover_optimization() const;
    //        void clear_cover_optimization();
    //        bool cover_optimization() const;
    //        void set_cover_optimization( bool value );

    //    private:
    //        bool _internal_cover_optimization() const;
    //        void _internal_set_cover_optimization( bool value );

    //    public:
    //        // optional bool use_precedences_in_disjunctive_constraint = 74 [default = true];
    //        bool has_use_precedences_in_disjunctive_constraint() const;
    //        void clear_use_precedences_in_disjunctive_constraint();
    //        bool use_precedences_in_disjunctive_constraint() const;
    //        void set_use_precedences_in_disjunctive_constraint( bool value );

    //    private:
    //        bool _internal_use_precedences_in_disjunctive_constraint() const;
    //        void _internal_set_use_precedences_in_disjunctive_constraint( bool value );

    //    public:
    //        // optional double restart_lbd_average_ratio = 71 [default = 1];
    //        bool   has_restart_lbd_average_ratio() const;
    //        void   clear_restart_lbd_average_ratio();
    //        double restart_lbd_average_ratio() const;
    //        void   set_restart_lbd_average_ratio( double value );

    //    private:
    //        double _internal_restart_lbd_average_ratio() const;
    //        void   _internal_set_restart_lbd_average_ratio( double value );

    //    public:
    //        // optional int32 presolve_bva_threshold = 73 [default = 1];
    //        bool      has_presolve_bva_threshold() const;
    //        void      clear_presolve_bva_threshold();
    //        ::int32_t presolve_bva_threshold() const;
    //        void      set_presolve_bva_threshold( ::int32_t value );

    //    private:
    //        ::int32_t _internal_presolve_bva_threshold() const;
    //        void      _internal_set_presolve_bva_threshold( ::int32_t value );

    //    public:
    //        // optional bool use_phase_saving = 44 [default = true];
    //        bool has_use_phase_saving() const;
    //        void clear_use_phase_saving();
    //        bool use_phase_saving() const;
    //        void set_use_phase_saving( bool value );

    //    private:
    //        bool _internal_use_phase_saving() const;
    //        void _internal_set_use_phase_saving( bool value );

    //    public:
    //        // optional bool subsumption_during_conflict_analysis = 56 [default = true];
    //        bool has_subsumption_during_conflict_analysis() const;
    //        void clear_subsumption_during_conflict_analysis();
    //        bool subsumption_during_conflict_analysis() const;
    //        void set_subsumption_during_conflict_analysis( bool value );

    //    private:
    //        bool _internal_subsumption_during_conflict_analysis() const;
    //        void _internal_set_subsumption_during_conflict_analysis( bool value );

    //    public:
    //        // optional bool log_to_stdout = 186 [default = true];
    //        bool has_log_to_stdout() const;
    //        void clear_log_to_stdout();
    //        bool log_to_stdout() const;
    //        void set_log_to_stdout( bool value );

    //    private:
    //        bool _internal_log_to_stdout() const;
    //        void _internal_set_log_to_stdout( bool value );

    //    public:
    //        // optional bool count_assumption_levels_in_lbd = 49 [default = true];
    //        bool has_count_assumption_levels_in_lbd() const;
    //        void clear_count_assumption_levels_in_lbd();
    //        bool count_assumption_levels_in_lbd() const;
    //        void set_count_assumption_levels_in_lbd( bool value );

    //    private:
    //        bool _internal_count_assumption_levels_in_lbd() const;
    //        void _internal_set_count_assumption_levels_in_lbd( bool value );

    //    public:
    //        // optional bool presolve_blocked_clause = 88 [default = true];
    //        bool has_presolve_blocked_clause() const;
    //        void clear_presolve_blocked_clause();
    //        bool presolve_blocked_clause() const;
    //        void set_presolve_blocked_clause( bool value );

    //    private:
    //        bool _internal_presolve_blocked_clause() const;
    //        void _internal_set_presolve_blocked_clause( bool value );

    //    public:
    //        // optional bool presolve_use_bva = 72 [default = true];
    //        bool has_presolve_use_bva() const;
    //        void clear_presolve_use_bva();
    //        bool presolve_use_bva() const;
    //        void set_presolve_use_bva( bool value );

    //    private:
    //        bool _internal_presolve_use_bva() const;
    //        void _internal_set_presolve_use_bva( bool value );

    //    public:
    //        // optional bool cp_model_presolve = 86 [default = true];
    //        bool has_cp_model_presolve() const;
    //        void clear_cp_model_presolve();
    //        bool cp_model_presolve() const;
    //        void set_cp_model_presolve( bool value );

    //    private:
    //        bool _internal_cp_model_presolve() const;
    //        void _internal_set_cp_model_presolve( bool value );

    //    public:
    //        // optional bool cp_model_use_sat_presolve = 93 [default = true];
    //        bool has_cp_model_use_sat_presolve() const;
    //        void clear_cp_model_use_sat_presolve();
    //        bool cp_model_use_sat_presolve() const;
    //        void set_cp_model_use_sat_presolve( bool value );

    //    private:
    //        bool _internal_cp_model_use_sat_presolve() const;
    //        void _internal_set_cp_model_use_sat_presolve( bool value );

    //    public:
    //        // optional int32 linearization_level = 90 [default = 1];
    //        bool      has_linearization_level() const;
    //        void      clear_linearization_level();
    //        ::int32_t linearization_level() const;
    //        void      set_linearization_level( ::int32_t value );

    //    private:
    //        ::int32_t _internal_linearization_level() const;
    //        void      _internal_set_linearization_level( ::int32_t value );

    //    public:
    //        // optional int32 max_num_cuts = 91 [default = 10000];
    //        bool      has_max_num_cuts() const;
    //        void      clear_max_num_cuts();
    //        ::int32_t max_num_cuts() const;
    //        void      set_max_num_cuts( ::int32_t value );

    //    private:
    //        ::int32_t _internal_max_num_cuts() const;
    //        void      _internal_set_max_num_cuts( ::int32_t value );

    //    public:
    //        // optional int32 binary_search_num_conflicts = 99 [default = -1];
    //        bool      has_binary_search_num_conflicts() const;
    //        void      clear_binary_search_num_conflicts();
    //        ::int32_t binary_search_num_conflicts() const;
    //        void      set_binary_search_num_conflicts( ::int32_t value );

    //    private:
    //        ::int32_t _internal_binary_search_num_conflicts() const;
    //        void      _internal_set_binary_search_num_conflicts( ::int32_t value );

    //    public:
    //        // optional int32 boolean_encoding_level = 107 [default = 1];
    //        bool      has_boolean_encoding_level() const;
    //        void      clear_boolean_encoding_level();
    //        ::int32_t boolean_encoding_level() const;
    //        void      set_boolean_encoding_level( ::int32_t value );

    //    private:
    //        ::int32_t _internal_boolean_encoding_level() const;
    //        void      _internal_set_boolean_encoding_level( ::int32_t value );

    //    public:
    //        // optional int32 cp_model_probing_level = 110 [default = 2];
    //        bool      has_cp_model_probing_level() const;
    //        void      clear_cp_model_probing_level();
    //        ::int32_t cp_model_probing_level() const;
    //        void      set_cp_model_probing_level( ::int32_t value );

    //    private:
    //        ::int32_t _internal_cp_model_probing_level() const;
    //        void      _internal_set_cp_model_probing_level( ::int32_t value );

    //    public:
    //        // optional double min_orthogonality_for_lp_constraints = 115 [default = 0.05];
    //        bool   has_min_orthogonality_for_lp_constraints() const;
    //        void   clear_min_orthogonality_for_lp_constraints();
    //        double min_orthogonality_for_lp_constraints() const;
    //        void   set_min_orthogonality_for_lp_constraints( double value );

    //    private:
    //        double _internal_min_orthogonality_for_lp_constraints() const;
    //        void   _internal_set_min_orthogonality_for_lp_constraints( double value );

    //    public:
    //        // optional int32 max_integer_rounding_scaling = 119 [default = 600];
    //        bool      has_max_integer_rounding_scaling() const;
    //        void      clear_max_integer_rounding_scaling();
    //        ::int32_t max_integer_rounding_scaling() const;
    //        void      set_max_integer_rounding_scaling( ::int32_t value );

    //    private:
    //        ::int32_t _internal_max_integer_rounding_scaling() const;
    //        void      _internal_set_max_integer_rounding_scaling( ::int32_t value );

    //    public:
    //        // optional int32 max_consecutive_inactive_count = 121 [default = 100];
    //        bool      has_max_consecutive_inactive_count() const;
    //        void      clear_max_consecutive_inactive_count();
    //        ::int32_t max_consecutive_inactive_count() const;
    //        void      set_max_consecutive_inactive_count( ::int32_t value );

    //    private:
    //        ::int32_t _internal_max_consecutive_inactive_count() const;
    //        void      _internal_set_max_consecutive_inactive_count( ::int32_t value );

    //    public:
    //        // optional int64 pseudo_cost_reliability_threshold = 123 [default = 100];
    //        bool      has_pseudo_cost_reliability_threshold() const;
    //        void      clear_pseudo_cost_reliability_threshold();
    //        ::int64_t pseudo_cost_reliability_threshold() const;
    //        void      set_pseudo_cost_reliability_threshold( ::int64_t value );

    //    private:
    //        ::int64_t _internal_pseudo_cost_reliability_threshold() const;
    //        void      _internal_set_pseudo_cost_reliability_threshold( ::int64_t value );

    //    public:
    //        // optional double mip_max_bound = 124 [default = 10000000];
    //        bool   has_mip_max_bound() const;
    //        void   clear_mip_max_bound();
    //        double mip_max_bound() const;
    //        void   set_mip_max_bound( double value );

    //    private:
    //        double _internal_mip_max_bound() const;
    //        void   _internal_set_mip_max_bound( double value );

    //    public:
    //        // optional double mip_var_scaling = 125 [default = 1];
    //        bool   has_mip_var_scaling() const;
    //        void   clear_mip_var_scaling();
    //        double mip_var_scaling() const;
    //        void   set_mip_var_scaling( double value );

    //    private:
    //        double _internal_mip_var_scaling() const;
    //        void   _internal_set_mip_var_scaling( double value );

    //    public:
    //        // optional int32 new_constraints_batch_size = 122 [default = 50];
    //        bool      has_new_constraints_batch_size() const;
    //        void      clear_new_constraints_batch_size();
    //        ::int32_t new_constraints_batch_size() const;
    //        void      set_new_constraints_batch_size( ::int32_t value );

    //    private:
    //        ::int32_t _internal_new_constraints_batch_size() const;
    //        void      _internal_set_new_constraints_batch_size( ::int32_t value );

    //    public:
    //        // optional bool exploit_integer_lp_solution = 94 [default = true];
    //        bool has_exploit_integer_lp_solution() const;
    //        void clear_exploit_integer_lp_solution();
    //        bool exploit_integer_lp_solution() const;
    //        void set_exploit_integer_lp_solution( bool value );

    //    private:
    //        bool _internal_exploit_integer_lp_solution() const;
    //        void _internal_set_exploit_integer_lp_solution( bool value );

    //    public:
    //        // optional bool exploit_all_lp_solution = 116 [default = true];
    //        bool has_exploit_all_lp_solution() const;
    //        void clear_exploit_all_lp_solution();
    //        bool exploit_all_lp_solution() const;
    //        void set_exploit_all_lp_solution( bool value );

    //    private:
    //        bool _internal_exploit_all_lp_solution() const;
    //        void _internal_set_exploit_all_lp_solution( bool value );

    //    public:
    //        // optional bool exploit_objective = 131 [default = true];
    //        bool has_exploit_objective() const;
    //        void clear_exploit_objective();
    //        bool exploit_objective() const;
    //        void set_exploit_objective( bool value );

    //    private:
    //        bool _internal_exploit_objective() const;
    //        void _internal_set_exploit_objective( bool value );

    //    public:
    //        // optional bool mip_automatically_scale_variables = 166 [default = true];
    //        bool has_mip_automatically_scale_variables() const;
    //        void clear_mip_automatically_scale_variables();
    //        bool mip_automatically_scale_variables() const;
    //        void set_mip_automatically_scale_variables( bool value );

    //    private:
    //        bool _internal_mip_automatically_scale_variables() const;
    //        void _internal_set_mip_automatically_scale_variables( bool value );

    //    public:
    //        // optional double mip_wanted_precision = 126 [default = 1e-06];
    //        bool   has_mip_wanted_precision() const;
    //        void   clear_mip_wanted_precision();
    //        double mip_wanted_precision() const;
    //        void   set_mip_wanted_precision( double value );

    //    private:
    //        double _internal_mip_wanted_precision() const;
    //        void   _internal_set_mip_wanted_precision( double value );

    //    public:
    //        // optional double mip_check_precision = 128 [default = 0.0001];
    //        bool   has_mip_check_precision() const;
    //        void   clear_mip_check_precision();
    //        double mip_check_precision() const;
    //        void   set_mip_check_precision( double value );

    //    private:
    //        double _internal_mip_check_precision() const;
    //        void   _internal_set_mip_check_precision( double value );

    //    public:
    //        // optional int32 mip_max_activity_exponent = 127 [default = 53];
    //        bool      has_mip_max_activity_exponent() const;
    //        void      clear_mip_max_activity_exponent();
    //        ::int32_t mip_max_activity_exponent() const;
    //        void      set_mip_max_activity_exponent( ::int32_t value );

    //    private:
    //        ::int32_t _internal_mip_max_activity_exponent() const;
    //        void      _internal_set_mip_max_activity_exponent( ::int32_t value );

    //    public:
    //        // optional int32 max_presolve_iterations = 138 [default = 3];
    //        bool      has_max_presolve_iterations() const;
    //        void      clear_max_presolve_iterations();
    //        ::int32_t max_presolve_iterations() const;
    //        void      set_max_presolve_iterations( ::int32_t value );

    //    private:
    //        ::int32_t _internal_max_presolve_iterations() const;
    //        void      _internal_set_max_presolve_iterations( ::int32_t value );

    //    public:
    //        // optional bool use_exact_lp_reason = 109 [default = true];
    //        bool has_use_exact_lp_reason() const;
    //        void clear_use_exact_lp_reason();
    //        bool use_exact_lp_reason() const;
    //        void set_use_exact_lp_reason( bool value );

    //    private:
    //        bool _internal_use_exact_lp_reason() const;
    //        void _internal_set_use_exact_lp_reason( bool value );

    //    public:
    //        // optional bool catch_sigint_signal = 135 [default = true];
    //        bool has_catch_sigint_signal() const;
    //        void clear_catch_sigint_signal();
    //        bool catch_sigint_signal() const;
    //        void set_catch_sigint_signal( bool value );

    //    private:
    //        bool _internal_catch_sigint_signal() const;
    //        void _internal_set_catch_sigint_signal( bool value );

    //    public:
    //        // optional bool use_implied_bounds = 144 [default = true];
    //        bool has_use_implied_bounds() const;
    //        void clear_use_implied_bounds();
    //        bool use_implied_bounds() const;
    //        void set_use_implied_bounds( bool value );

    //    private:
    //        bool _internal_use_implied_bounds() const;
    //        void _internal_set_use_implied_bounds( bool value );

    //    public:
    //        // optional bool convert_intervals = 177 [default = true];
    //        bool has_convert_intervals() const;
    //        void clear_convert_intervals();
    //        bool convert_intervals() const;
    //        void set_convert_intervals( bool value );

    //    private:
    //        bool _internal_convert_intervals() const;
    //        void _internal_set_convert_intervals( bool value );

    //    public:
    //        // optional int32 presolve_substitution_level = 147 [default = 1];
    //        bool      has_presolve_substitution_level() const;
    //        void      clear_presolve_substitution_level();
    //        ::int32_t presolve_substitution_level() const;
    //        void      set_presolve_substitution_level( ::int32_t value );

    //    private:
    //        ::int32_t _internal_presolve_substitution_level() const;
    //        void      _internal_set_presolve_substitution_level( ::int32_t value );

    //    public:
    //        // optional double merge_no_overlap_work_limit = 145 [default = 1000000000000];
    //        bool   has_merge_no_overlap_work_limit() const;
    //        void   clear_merge_no_overlap_work_limit();
    //        double merge_no_overlap_work_limit() const;
    //        void   set_merge_no_overlap_work_limit( double value );

    //    private:
    //        double _internal_merge_no_overlap_work_limit() const;
    //        void   _internal_set_merge_no_overlap_work_limit( double value );

    //    public:
    //        // optional double merge_at_most_one_work_limit = 146 [default = 100000000];
    //        bool   has_merge_at_most_one_work_limit() const;
    //        void   clear_merge_at_most_one_work_limit();
    //        double merge_at_most_one_work_limit() const;
    //        void   set_merge_at_most_one_work_limit( double value );

    //    private:
    //        double _internal_merge_at_most_one_work_limit() const;
    //        void   _internal_set_merge_at_most_one_work_limit( double value );

    //    public:
    //        // optional int32 max_all_diff_cut_size = 148 [default = 64];
    //        bool      has_max_all_diff_cut_size() const;
    //        void      clear_max_all_diff_cut_size();
    //        ::int32_t max_all_diff_cut_size() const;
    //        void      set_max_all_diff_cut_size( ::int32_t value );

    //    private:
    //        ::int32_t _internal_max_all_diff_cut_size() const;
    //        void      _internal_set_max_all_diff_cut_size( ::int32_t value );

    //    public:
    //        // optional bool use_sat_inprocessing = 163 [default = true];
    //        bool has_use_sat_inprocessing() const;
    //        void clear_use_sat_inprocessing();
    //        bool use_sat_inprocessing() const;
    //        void set_use_sat_inprocessing( bool value );

    //    private:
    //        bool _internal_use_sat_inprocessing() const;
    //        void _internal_set_use_sat_inprocessing( bool value );

    //    public:
    //        // optional bool share_objective_bounds = 113 [default = true];
    //        bool has_share_objective_bounds() const;
    //        void clear_share_objective_bounds();
    //        bool share_objective_bounds() const;
    //        void set_share_objective_bounds( bool value );

    //    private:
    //        bool _internal_share_objective_bounds() const;
    //        void _internal_set_share_objective_bounds( bool value );

    //    public:
    //        // optional bool share_level_zero_bounds = 114 [default = true];
    //        bool has_share_level_zero_bounds() const;
    //        void clear_share_level_zero_bounds();
    //        bool share_level_zero_bounds() const;
    //        void set_share_level_zero_bounds( bool value );

    //    private:
    //        bool _internal_share_level_zero_bounds() const;
    //        void _internal_set_share_level_zero_bounds( bool value );

    //    public:
    //        // optional bool share_binary_clauses = 203 [default = true];
    //        bool has_share_binary_clauses() const;
    //        void clear_share_binary_clauses();
    //        bool share_binary_clauses() const;
    //        void set_share_binary_clauses( bool value );

    //    private:
    //        bool _internal_share_binary_clauses() const;
    //        void _internal_set_share_binary_clauses( bool value );

    //    public:
    //        // optional int32 hint_conflict_limit = 153 [default = 10];
    //        bool      has_hint_conflict_limit() const;
    //        void      clear_hint_conflict_limit();
    //        ::int32_t hint_conflict_limit() const;
    //        void      set_hint_conflict_limit( ::int32_t value );

    //    private:
    //        ::int32_t _internal_hint_conflict_limit() const;
    //        void      _internal_set_hint_conflict_limit( ::int32_t value );

    //    public:
    //        // optional int32 max_cut_rounds_at_level_zero = 154 [default = 1];
    //        bool      has_max_cut_rounds_at_level_zero() const;
    //        void      clear_max_cut_rounds_at_level_zero();
    //        ::int32_t max_cut_rounds_at_level_zero() const;
    //        void      set_max_cut_rounds_at_level_zero( ::int32_t value );

    //    private:
    //        ::int32_t _internal_max_cut_rounds_at_level_zero() const;
    //        void      _internal_set_max_cut_rounds_at_level_zero( ::int32_t value );

    //    public:
    //        // optional double cut_max_active_count_value = 155 [default = 10000000000];
    //        bool   has_cut_max_active_count_value() const;
    //        void   clear_cut_max_active_count_value();
    //        double cut_max_active_count_value() const;
    //        void   set_cut_max_active_count_value( double value );

    //    private:
    //        double _internal_cut_max_active_count_value() const;
    //        void   _internal_set_cut_max_active_count_value( double value );

    //    public:
    //        // optional double cut_active_count_decay = 156 [default = 0.8];
    //        bool   has_cut_active_count_decay() const;
    //        void   clear_cut_active_count_decay();
    //        double cut_active_count_decay() const;
    //        void   set_cut_active_count_decay( double value );

    //    private:
    //        double _internal_cut_active_count_decay() const;
    //        void   _internal_set_cut_active_count_decay( double value );

    //    public:
    //        // optional int32 cut_cleanup_target = 157 [default = 1000];
    //        bool      has_cut_cleanup_target() const;
    //        void      clear_cut_cleanup_target();
    //        ::int32_t cut_cleanup_target() const;
    //        void      set_cut_cleanup_target( ::int32_t value );

    //    private:
    //        ::int32_t _internal_cut_cleanup_target() const;
    //        void      _internal_set_cut_cleanup_target( ::int32_t value );

    //    public:
    //        // optional bool new_linear_propagation = 224 [default = true];
    //        bool has_new_linear_propagation() const;
    //        void clear_new_linear_propagation();
    //        bool new_linear_propagation() const;
    //        void set_new_linear_propagation( bool value );

    //    private:
    //        bool _internal_new_linear_propagation() const;
    //        void _internal_set_new_linear_propagation( bool value );

    //    public:
    //        // optional bool add_cg_cuts = 117 [default = true];
    //        bool has_add_cg_cuts() const;
    //        void clear_add_cg_cuts();
    //        bool add_cg_cuts() const;
    //        void set_add_cg_cuts( bool value );

    //    private:
    //        bool _internal_add_cg_cuts() const;
    //        void _internal_set_add_cg_cuts( bool value );

    //    public:
    //        // optional bool add_mir_cuts = 120 [default = true];
    //        bool has_add_mir_cuts() const;
    //        void clear_add_mir_cuts();
    //        bool add_mir_cuts() const;
    //        void set_add_mir_cuts( bool value );

    //    private:
    //        bool _internal_add_mir_cuts() const;
    //        void _internal_set_add_mir_cuts( bool value );

    //    public:
    //        // optional bool add_zero_half_cuts = 169 [default = true];
    //        bool has_add_zero_half_cuts() const;
    //        void clear_add_zero_half_cuts();
    //        bool add_zero_half_cuts() const;
    //        void set_add_zero_half_cuts( bool value );

    //    private:
    //        bool _internal_add_zero_half_cuts() const;
    //        void _internal_set_add_zero_half_cuts( bool value );

    //    public:
    //        // optional double absolute_gap_limit = 159 [default = 0.0001];
    //        bool   has_absolute_gap_limit() const;
    //        void   clear_absolute_gap_limit();
    //        double absolute_gap_limit() const;
    //        void   set_absolute_gap_limit( double value );

    //    private:
    //        double _internal_absolute_gap_limit() const;
    //        void   _internal_set_absolute_gap_limit( double value );

    //    public:
    //        // optional .operations_research.sat.SatParameters.FPRoundingMethod fp_rounding = 165 [default = PROPAGATION_ASSISTED];
    //        bool                                                       has_fp_rounding() const;
    //        void                                                       clear_fp_rounding();
    //        ::operations_research::sat::SatParameters_FPRoundingMethod fp_rounding() const;
    //        void                                                       set_fp_rounding( ::operations_research::sat::SatParameters_FPRoundingMethod value );

    //    private:
    //        ::operations_research::sat::SatParameters_FPRoundingMethod _internal_fp_rounding() const;
    //        void                                                       _internal_set_fp_rounding( ::operations_research::sat::SatParameters_FPRoundingMethod value );

    //    public:
    //        // optional bool auto_detect_greater_than_at_least_one_of = 95 [default = true];
    //        bool has_auto_detect_greater_than_at_least_one_of() const;
    //        void clear_auto_detect_greater_than_at_least_one_of();
    //        bool auto_detect_greater_than_at_least_one_of() const;
    //        void set_auto_detect_greater_than_at_least_one_of( bool value );

    //    private:
    //        bool _internal_auto_detect_greater_than_at_least_one_of() const;
    //        void _internal_set_auto_detect_greater_than_at_least_one_of( bool value );

    //    public:
    //        // optional bool use_lns = 283 [default = true];
    //        bool has_use_lns() const;
    //        void clear_use_lns();
    //        bool use_lns() const;
    //        void set_use_lns( bool value );

    //    private:
    //        bool _internal_use_lns() const;
    //        void _internal_set_use_lns( bool value );

    //    public:
    //        // optional bool use_rins_lns = 129 [default = true];
    //        bool has_use_rins_lns() const;
    //        void clear_use_rins_lns();
    //        bool use_rins_lns() const;
    //        void set_use_rins_lns( bool value );

    //    private:
    //        bool _internal_use_rins_lns() const;
    //        void _internal_set_use_rins_lns( bool value );

    //    public:
    //        // optional bool use_feasibility_pump = 164 [default = true];
    //        bool has_use_feasibility_pump() const;
    //        void clear_use_feasibility_pump();
    //        bool use_feasibility_pump() const;
    //        void set_use_feasibility_pump( bool value );

    //    private:
    //        bool _internal_use_feasibility_pump() const;
    //        void _internal_set_use_feasibility_pump( bool value );

    //    public:
    //        // optional int32 polarity_rephase_increment = 168 [default = 1000];
    //        bool      has_polarity_rephase_increment() const;
    //        void      clear_polarity_rephase_increment();
    //        ::int32_t polarity_rephase_increment() const;
    //        void      set_polarity_rephase_increment( ::int32_t value );

    //    private:
    //        ::int32_t _internal_polarity_rephase_increment() const;
    //        void      _internal_set_polarity_rephase_increment( ::int32_t value );

    //    public:
    //        // optional bool add_clique_cuts = 172 [default = true];
    //        bool has_add_clique_cuts() const;
    //        void clear_add_clique_cuts();
    //        bool add_clique_cuts() const;
    //        void set_add_clique_cuts( bool value );

    //    private:
    //        bool _internal_add_clique_cuts() const;
    //        void _internal_set_add_clique_cuts( bool value );

    //    public:
    //        // optional bool add_rlt_cuts = 279 [default = true];
    //        bool has_add_rlt_cuts() const;
    //        void clear_add_rlt_cuts();
    //        bool add_rlt_cuts() const;
    //        void set_add_rlt_cuts( bool value );

    //    private:
    //        bool _internal_add_rlt_cuts() const;
    //        void _internal_set_add_rlt_cuts( bool value );

    //    public:
    //        // optional bool add_lin_max_cuts = 152 [default = true];
    //        bool has_add_lin_max_cuts() const;
    //        void clear_add_lin_max_cuts();
    //        bool add_lin_max_cuts() const;
    //        void set_add_lin_max_cuts( bool value );

    //    private:
    //        bool _internal_add_lin_max_cuts() const;
    //        void _internal_set_add_lin_max_cuts( bool value );

    //    public:
    //        // optional bool add_lp_constraints_lazily = 112 [default = true];
    //        bool has_add_lp_constraints_lazily() const;
    //        void clear_add_lp_constraints_lazily();
    //        bool add_lp_constraints_lazily() const;
    //        void set_add_lp_constraints_lazily( bool value );

    //    private:
    //        bool _internal_add_lp_constraints_lazily() const;
    //        void _internal_set_add_lp_constraints_lazily( bool value );

    //    public:
    //        // optional int32 symmetry_level = 183 [default = 2];
    //        bool      has_symmetry_level() const;
    //        void      clear_symmetry_level();
    //        ::int32_t symmetry_level() const;
    //        void      set_symmetry_level( ::int32_t value );

    //    private:
    //        ::int32_t _internal_symmetry_level() const;
    //        void      _internal_set_symmetry_level( ::int32_t value );

    //    public:
    //        // optional int32 max_domain_size_when_encoding_eq_neq_constraints = 191 [default = 16];
    //        bool      has_max_domain_size_when_encoding_eq_neq_constraints() const;
    //        void      clear_max_domain_size_when_encoding_eq_neq_constraints();
    //        ::int32_t max_domain_size_when_encoding_eq_neq_constraints() const;
    //        void      set_max_domain_size_when_encoding_eq_neq_constraints( ::int32_t value );

    //    private:
    //        ::int32_t _internal_max_domain_size_when_encoding_eq_neq_constraints() const;
    //        void      _internal_set_max_domain_size_when_encoding_eq_neq_constraints( ::int32_t value );

    //    public:
    //        // optional double clause_cleanup_ratio = 190 [default = 0.5];
    //        bool   has_clause_cleanup_ratio() const;
    //        void   clear_clause_cleanup_ratio();
    //        double clause_cleanup_ratio() const;
    //        void   set_clause_cleanup_ratio( double value );

    //    private:
    //        double _internal_clause_cleanup_ratio() const;
    //        void   _internal_set_clause_cleanup_ratio( double value );

    //    public:
    //        // optional bool use_disjunctive_constraint_in_cumulative = 80 [default = true];
    //        bool has_use_disjunctive_constraint_in_cumulative() const;
    //        void clear_use_disjunctive_constraint_in_cumulative();
    //        bool use_disjunctive_constraint_in_cumulative() const;
    //        void set_use_disjunctive_constraint_in_cumulative( bool value );

    //    private:
    //        bool _internal_use_disjunctive_constraint_in_cumulative() const;
    //        void _internal_set_use_disjunctive_constraint_in_cumulative( bool value );

    //    public:
    //        // optional bool use_dual_scheduling_heuristics = 214 [default = true];
    //        bool has_use_dual_scheduling_heuristics() const;
    //        void clear_use_dual_scheduling_heuristics();
    //        bool use_dual_scheduling_heuristics() const;
    //        void set_use_dual_scheduling_heuristics( bool value );

    //    private:
    //        bool _internal_use_dual_scheduling_heuristics() const;
    //        void _internal_set_use_dual_scheduling_heuristics( bool value );

    //    public:
    //        // optional bool use_extended_probing = 269 [default = true];
    //        bool has_use_extended_probing() const;
    //        void clear_use_extended_probing();
    //        bool use_extended_probing() const;
    //        void set_use_extended_probing( bool value );

    //    private:
    //        bool _internal_use_extended_probing() const;
    //        void _internal_set_use_extended_probing( bool value );

    //    public:
    //        // optional bool use_shaving_in_probing_search = 204 [default = true];
    //        bool has_use_shaving_in_probing_search() const;
    //        void clear_use_shaving_in_probing_search();
    //        bool use_shaving_in_probing_search() const;
    //        void set_use_shaving_in_probing_search( bool value );

    //    private:
    //        bool _internal_use_shaving_in_probing_search() const;
    //        void _internal_set_use_shaving_in_probing_search( bool value );

    //    public:
    //        // optional int32 solution_pool_size = 193 [default = 3];
    //        bool      has_solution_pool_size() const;
    //        void      clear_solution_pool_size();
    //        ::int32_t solution_pool_size() const;
    //        void      set_solution_pool_size( ::int32_t value );

    //    private:
    //        ::int32_t _internal_solution_pool_size() const;
    //        void      _internal_set_solution_pool_size( ::int32_t value );

    //    public:
    //        // optional int32 cut_level = 196 [default = 1];
    //        bool      has_cut_level() const;
    //        void      clear_cut_level();
    //        ::int32_t cut_level() const;
    //        void      set_cut_level( ::int32_t value );

    //    private:
    //        ::int32_t _internal_cut_level() const;
    //        void      _internal_set_cut_level( ::int32_t value );

    //    public:
    //        // optional bool mip_compute_true_objective_bound = 198 [default = true];
    //        bool has_mip_compute_true_objective_bound() const;
    //        void clear_mip_compute_true_objective_bound();
    //        bool mip_compute_true_objective_bound() const;
    //        void set_mip_compute_true_objective_bound( bool value );

    //    private:
    //        bool _internal_mip_compute_true_objective_bound() const;
    //        void _internal_set_mip_compute_true_objective_bound( bool value );

    //    public:
    //        // optional double mip_max_valid_magnitude = 199 [default = 1e+20];
    //        bool   has_mip_max_valid_magnitude() const;
    //        void   clear_mip_max_valid_magnitude();
    //        double mip_max_valid_magnitude() const;
    //        void   set_mip_max_valid_magnitude( double value );

    //    private:
    //        double _internal_mip_max_valid_magnitude() const;
    //        void   _internal_set_mip_max_valid_magnitude( double value );

    //    public:
    //        // optional int64 presolve_inclusion_work_limit = 201 [default = 100000000];
    //        bool      has_presolve_inclusion_work_limit() const;
    //        void      clear_presolve_inclusion_work_limit();
    //        ::int64_t presolve_inclusion_work_limit() const;
    //        void      set_presolve_inclusion_work_limit( ::int64_t value );

    //    private:
    //        ::int64_t _internal_presolve_inclusion_work_limit() const;
    //        void      _internal_set_presolve_inclusion_work_limit( ::int64_t value );

    //    public:
    //        // optional double shaving_search_deterministic_time = 205 [default = 0.001];
    //        bool   has_shaving_search_deterministic_time() const;
    //        void   clear_shaving_search_deterministic_time();
    //        double shaving_search_deterministic_time() const;
    //        void   set_shaving_search_deterministic_time( double value );

    //    private:
    //        double _internal_shaving_search_deterministic_time() const;
    //        void   _internal_set_shaving_search_deterministic_time( double value );

    //    public:
    //        // optional bool expand_reservoir_constraints = 182 [default = true];
    //        bool has_expand_reservoir_constraints() const;
    //        void clear_expand_reservoir_constraints();
    //        bool expand_reservoir_constraints() const;
    //        void set_expand_reservoir_constraints( bool value );

    //    private:
    //        bool _internal_expand_reservoir_constraints() const;
    //        void _internal_set_expand_reservoir_constraints( bool value );

    //    public:
    //        // optional bool ignore_names = 202 [default = true];
    //        bool has_ignore_names() const;
    //        void clear_ignore_names();
    //        bool ignore_names() const;
    //        void set_ignore_names( bool value );

    //    private:
    //        bool _internal_ignore_names() const;
    //        void _internal_set_ignore_names( bool value );

    //    public:
    //        // optional bool infer_all_diffs = 233 [default = true];
    //        bool has_infer_all_diffs() const;
    //        void clear_infer_all_diffs();
    //        bool infer_all_diffs() const;
    //        void set_infer_all_diffs( bool value );

    //    private:
    //        bool _internal_infer_all_diffs() const;
    //        void _internal_set_infer_all_diffs( bool value );

    //    public:
    //        // optional bool find_big_linear_overlap = 234 [default = true];
    //        bool has_find_big_linear_overlap() const;
    //        void clear_find_big_linear_overlap();
    //        bool find_big_linear_overlap() const;
    //        void set_find_big_linear_overlap( bool value );

    //    private:
    //        bool _internal_find_big_linear_overlap() const;
    //        void _internal_set_find_big_linear_overlap( bool value );

    //    public:
    //        // optional int32 table_compression_level = 217 [default = 2];
    //        bool      has_table_compression_level() const;
    //        void      clear_table_compression_level();
    //        ::int32_t table_compression_level() const;
    //        void      set_table_compression_level( ::int32_t value );

    //    private:
    //        ::int32_t _internal_table_compression_level() const;
    //        void      _internal_set_table_compression_level( ::int32_t value );

    //    public:
    //        // optional double propagation_loop_detection_factor = 221 [default = 10];
    //        bool   has_propagation_loop_detection_factor() const;
    //        void   clear_propagation_loop_detection_factor();
    //        double propagation_loop_detection_factor() const;
    //        void   set_propagation_loop_detection_factor( double value );

    //    private:
    //        double _internal_propagation_loop_detection_factor() const;
    //        void   _internal_set_propagation_loop_detection_factor( double value );

    //    public:
    //        // optional double probing_deterministic_time_limit = 226 [default = 1];
    //        bool   has_probing_deterministic_time_limit() const;
    //        void   clear_probing_deterministic_time_limit();
    //        double probing_deterministic_time_limit() const;
    //        void   set_probing_deterministic_time_limit( double value );

    //    private:
    //        double _internal_probing_deterministic_time_limit() const;
    //        void   _internal_set_probing_deterministic_time_limit( double value );

    //    public:
    //        // optional int32 root_lp_iterations = 227 [default = 2000];
    //        bool      has_root_lp_iterations() const;
    //        void      clear_root_lp_iterations();
    //        ::int32_t root_lp_iterations() const;
    //        void      set_root_lp_iterations( ::int32_t value );

    //    private:
    //        ::int32_t _internal_root_lp_iterations() const;
    //        void      _internal_set_root_lp_iterations( ::int32_t value );

    //    public:
    //        // optional int32 max_size_to_create_precedence_literals_in_disjunctive = 229 [default = 60];
    //        bool      has_max_size_to_create_precedence_literals_in_disjunctive() const;
    //        void      clear_max_size_to_create_precedence_literals_in_disjunctive();
    //        ::int32_t max_size_to_create_precedence_literals_in_disjunctive() const;
    //        void      set_max_size_to_create_precedence_literals_in_disjunctive( ::int32_t value );

    //    private:
    //        ::int32_t _internal_max_size_to_create_precedence_literals_in_disjunctive() const;
    //        void      _internal_set_max_size_to_create_precedence_literals_in_disjunctive( ::int32_t value );

    //    public:
    //        // optional bool use_feasibility_jump = 265 [default = true];
    //        bool has_use_feasibility_jump() const;
    //        void clear_use_feasibility_jump();
    //        bool use_feasibility_jump() const;
    //        void set_use_feasibility_jump( bool value );

    //    private:
    //        bool _internal_use_feasibility_jump() const;
    //        void _internal_set_use_feasibility_jump( bool value );

    //    public:
    //        // optional bool feasibility_jump_enable_restarts = 250 [default = true];
    //        bool has_feasibility_jump_enable_restarts() const;
    //        void clear_feasibility_jump_enable_restarts();
    //        bool feasibility_jump_enable_restarts() const;
    //        void set_feasibility_jump_enable_restarts( bool value );

    //    private:
    //        bool _internal_feasibility_jump_enable_restarts() const;
    //        void _internal_set_feasibility_jump_enable_restarts( bool value );

    //    public:
    //        // optional bool shared_tree_worker_enable_trail_sharing = 295 [default = true];
    //        bool has_shared_tree_worker_enable_trail_sharing() const;
    //        void clear_shared_tree_worker_enable_trail_sharing();
    //        bool shared_tree_worker_enable_trail_sharing() const;
    //        void set_shared_tree_worker_enable_trail_sharing( bool value );

    //    private:
    //        bool _internal_shared_tree_worker_enable_trail_sharing() const;
    //        void _internal_set_shared_tree_worker_enable_trail_sharing( bool value );

    //    public:
    //        // optional bool instantiate_all_variables = 106 [default = true];
    //        bool has_instantiate_all_variables() const;
    //        void clear_instantiate_all_variables();
    //        bool instantiate_all_variables() const;
    //        void set_instantiate_all_variables( bool value );

    //    private:
    //        bool _internal_instantiate_all_variables() const;
    //        void _internal_set_instantiate_all_variables( bool value );

    //    public:
    //        // optional int32 shared_tree_max_nodes_per_worker = 238 [default = 100000];
    //        bool      has_shared_tree_max_nodes_per_worker() const;
    //        void      clear_shared_tree_max_nodes_per_worker();
    //        ::int32_t shared_tree_max_nodes_per_worker() const;
    //        void      set_shared_tree_max_nodes_per_worker( ::int32_t value );

    //    private:
    //        ::int32_t _internal_shared_tree_max_nodes_per_worker() const;
    //        void      _internal_set_shared_tree_max_nodes_per_worker( ::int32_t value );

    //    public:
    //        // optional double mip_drop_tolerance = 232 [default = 1e-16];
    //        bool   has_mip_drop_tolerance() const;
    //        void   clear_mip_drop_tolerance();
    //        double mip_drop_tolerance() const;
    //        void   set_mip_drop_tolerance( double value );

    //    private:
    //        double _internal_mip_drop_tolerance() const;
    //        void   _internal_set_mip_drop_tolerance( double value );

    //    public:
    //        // optional double shared_tree_worker_objective_split_probability = 237 [default = 0.5];
    //        bool   has_shared_tree_worker_objective_split_probability() const;
    //        void   clear_shared_tree_worker_objective_split_probability();
    //        double shared_tree_worker_objective_split_probability() const;
    //        void   set_shared_tree_worker_objective_split_probability( double value );

    //    private:
    //        double _internal_shared_tree_worker_objective_split_probability() const;
    //        void   _internal_set_shared_tree_worker_objective_split_probability( double value );

    //    public:
    //        // optional double feasibility_jump_decay = 242 [default = 0.95];
    //        bool   has_feasibility_jump_decay() const;
    //        void   clear_feasibility_jump_decay();
    //        double feasibility_jump_decay() const;
    //        void   set_feasibility_jump_decay( double value );

    //    private:
    //        double _internal_feasibility_jump_decay() const;
    //        void   _internal_set_feasibility_jump_decay( double value );

    //    public:
    //        // optional double feasibility_jump_var_randomization_probability = 247 [default = 0.05];
    //        bool   has_feasibility_jump_var_randomization_probability() const;
    //        void   clear_feasibility_jump_var_randomization_probability();
    //        double feasibility_jump_var_randomization_probability() const;
    //        void   set_feasibility_jump_var_randomization_probability( double value );

    //    private:
    //        double _internal_feasibility_jump_var_randomization_probability() const;
    //        void   _internal_set_feasibility_jump_var_randomization_probability( double value );

    //    public:
    //        // optional double feasibility_jump_var_perburbation_range_ratio = 248 [default = 0.2];
    //        bool   has_feasibility_jump_var_perburbation_range_ratio() const;
    //        void   clear_feasibility_jump_var_perburbation_range_ratio();
    //        double feasibility_jump_var_perburbation_range_ratio() const;
    //        void   set_feasibility_jump_var_perburbation_range_ratio( double value );

    //    private:
    //        double _internal_feasibility_jump_var_perburbation_range_ratio() const;
    //        void   _internal_set_feasibility_jump_var_perburbation_range_ratio( double value );

    //    public:
    //        // optional int32 violation_ls_perturbation_period = 249 [default = 100];
    //        bool      has_violation_ls_perturbation_period() const;
    //        void      clear_violation_ls_perturbation_period();
    //        ::int32_t violation_ls_perturbation_period() const;
    //        void      set_violation_ls_perturbation_period( ::int32_t value );

    //    private:
    //        ::int32_t _internal_violation_ls_perturbation_period() const;
    //        void      _internal_set_violation_ls_perturbation_period( ::int32_t value );

    //    public:
    //        // optional int32 linear_split_size = 256 [default = 100];
    //        bool      has_linear_split_size() const;
    //        void      clear_linear_split_size();
    //        ::int32_t linear_split_size() const;
    //        void      set_linear_split_size( ::int32_t value );

    //    private:
    //        ::int32_t _internal_linear_split_size() const;
    //        void      _internal_set_linear_split_size( ::int32_t value );

    //    public:
    //        // optional int32 feasibility_jump_linearization_level = 257 [default = 2];
    //        bool      has_feasibility_jump_linearization_level() const;
    //        void      clear_feasibility_jump_linearization_level();
    //        ::int32_t feasibility_jump_linearization_level() const;
    //        void      set_feasibility_jump_linearization_level( ::int32_t value );

    //    private:
    //        ::int32_t _internal_feasibility_jump_linearization_level() const;
    //        void      _internal_set_feasibility_jump_linearization_level( ::int32_t value );

    //    public:
    //        // optional int32 feasibility_jump_restart_factor = 258 [default = 1];
    //        bool      has_feasibility_jump_restart_factor() const;
    //        void      clear_feasibility_jump_restart_factor();
    //        ::int32_t feasibility_jump_restart_factor() const;
    //        void      set_feasibility_jump_restart_factor( ::int32_t value );

    //    private:
    //        ::int32_t _internal_feasibility_jump_restart_factor() const;
    //        void      _internal_set_feasibility_jump_restart_factor( ::int32_t value );

    //    public:
    //        // optional double violation_ls_compound_move_probability = 259 [default = 0.5];
    //        bool   has_violation_ls_compound_move_probability() const;
    //        void   clear_violation_ls_compound_move_probability();
    //        double violation_ls_compound_move_probability() const;
    //        void   set_violation_ls_compound_move_probability( double value );

    //    private:
    //        double _internal_violation_ls_compound_move_probability() const;
    //        void   _internal_set_violation_ls_compound_move_probability( double value );

    //    public:
    //        // optional int32 max_num_intervals_for_timetable_edge_finding = 260 [default = 100];
    //        bool      has_max_num_intervals_for_timetable_edge_finding() const;
    //        void      clear_max_num_intervals_for_timetable_edge_finding();
    //        ::int32_t max_num_intervals_for_timetable_edge_finding() const;
    //        void      set_max_num_intervals_for_timetable_edge_finding( ::int32_t value );

    //    private:
    //        ::int32_t _internal_max_num_intervals_for_timetable_edge_finding() const;
    //        void      _internal_set_max_num_intervals_for_timetable_edge_finding( ::int32_t value );

    //    public:
    //        // optional int32 mip_presolve_level = 261 [default = 2];
    //        bool      has_mip_presolve_level() const;
    //        void      clear_mip_presolve_level();
    //        ::int32_t mip_presolve_level() const;
    //        void      set_mip_presolve_level( ::int32_t value );

    //    private:
    //        ::int32_t _internal_mip_presolve_level() const;
    //        void      _internal_set_mip_presolve_level( ::int32_t value );

    //    public:
    //        // optional double lp_primal_tolerance = 266 [default = 1e-07];
    //        bool   has_lp_primal_tolerance() const;
    //        void   clear_lp_primal_tolerance();
    //        double lp_primal_tolerance() const;
    //        void   set_lp_primal_tolerance( double value );


    //    public:
    //        // optional double lp_dual_tolerance = 267 [default = 1e-07];
    //        bool   has_lp_dual_tolerance() const;
    //        void   clear_lp_dual_tolerance();
    //        double lp_dual_tolerance() const;
    //        void   set_lp_dual_tolerance( double value );


    //    public:
    //        // optional int32 feasibility_jump_max_expanded_constraint_size = 264 [default = 500];
    //        bool      has_feasibility_jump_max_expanded_constraint_size() const;
    //        void      clear_feasibility_jump_max_expanded_constraint_size();
    //        ::int32_t feasibility_jump_max_expanded_constraint_size() const;
    //        void      set_feasibility_jump_max_expanded_constraint_size( ::int32_t value );


    //    public:
    //        // optional int32 at_most_one_max_expansion_size = 270 [default = 3];
    //        bool      has_at_most_one_max_expansion_size() const;
    //        void      clear_at_most_one_max_expansion_size();
    //        ::int32_t at_most_one_max_expansion_size() const;
    //        void      set_at_most_one_max_expansion_size( ::int32_t value );


    //    public:
    //        // optional double inprocessing_dtime_ratio = 273 [default = 0.2];
    //        bool   has_inprocessing_dtime_ratio() const;
    //        void   clear_inprocessing_dtime_ratio();
    //        double inprocessing_dtime_ratio() const;
    //        void   set_inprocessing_dtime_ratio( double value );


    //    public:
    //        // optional double inprocessing_probing_dtime = 274 [default = 1];
    //        bool   has_inprocessing_probing_dtime() const;
    //        void   clear_inprocessing_probing_dtime();
    //        double inprocessing_probing_dtime() const;
    //        void   set_inprocessing_probing_dtime( double value );


    //    public:
    //        // optional int32 probing_num_combinations_limit = 272 [default = 20000];
    //        bool      has_probing_num_combinations_limit() const;
    //        void      clear_probing_num_combinations_limit();
    //        ::int32_t probing_num_combinations_limit() const;
    //        void      set_probing_num_combinations_limit( ::int32_t value );


    //    public:
    //        // optional int32 max_pairs_pairwise_reasoning_in_no_overlap_2d = 276 [default = 1250];
    //        bool      has_max_pairs_pairwise_reasoning_in_no_overlap_2d() const;
    //        void      clear_max_pairs_pairwise_reasoning_in_no_overlap_2d();
    //        ::int32_t max_pairs_pairwise_reasoning_in_no_overlap_2d() const;
    //        void      set_max_pairs_pairwise_reasoning_in_no_overlap_2d( ::int32_t value );


    //    public:
    //        // optional double inprocessing_minimization_dtime = 275 [default = 1];
    //        bool   has_inprocessing_minimization_dtime() const;
    //        void   clear_inprocessing_minimization_dtime();
    //        double inprocessing_minimization_dtime() const;
    //        void   set_inprocessing_minimization_dtime( double value );


    //    public:
    //        // optional double shared_tree_open_leaves_per_worker = 281 [default = 2];
    //        bool   has_shared_tree_open_leaves_per_worker() const;
    //        void   clear_shared_tree_open_leaves_per_worker();
    //        double shared_tree_open_leaves_per_worker() const;
    //        void   set_shared_tree_open_leaves_per_worker( double value );


    //    public:
    //        // optional int64 shaving_search_threshold = 290 [default = 64];
    //        bool      has_shaving_search_threshold() const;
    //        void      clear_shaving_search_threshold();
    //        ::int64_t shaving_search_threshold() const;
    //        void      set_shaving_search_threshold( ::int64_t value );


    //    public:
    //        // optional double feasibility_jump_batch_dtime = 292 [default = 0.1];
    //        bool   has_feasibility_jump_batch_dtime() const;
    //        void   clear_feasibility_jump_batch_dtime();
    //        double feasibility_jump_batch_dtime() const;
    //        void   set_feasibility_jump_batch_dtime( double value );


    //    public:
    //        // @@protoc_insertion_point(class_scope:operations_research.sat.SatParameters)
};

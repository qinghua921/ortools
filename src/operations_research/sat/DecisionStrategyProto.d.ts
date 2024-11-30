export namespace DecisionStrategyProto
{
    export const CHOOSE_FIRST
    export const CHOOSE_LOWEST_MIN
    export const CHOOSE_HIGHEST_MAX
    export const CHOOSE_MIN_DOMAIN_SIZE
    export const CHOOSE_MAX_DOMAIN_SIZE

    export const SELECT_MIN_VALUE
    export const SELECT_MAX_VALUE
    export const SELECT_LOWER_HALF
    export const SELECT_UPPER_HALF
    export const SELECT_MEDIAN_VALUE
}

export class DecisionStrategyProto
{
    //  public:
    //   inline DecisionStrategyProto() : DecisionStrategyProto(nullptr) {}
    //   ~DecisionStrategyProto() override;
    //   template <typename = void>
    //   explicit PROTOBUF_CONSTEXPR DecisionStrategyProto(
    //       ::google::protobuf::internal::ConstantInitialized);

    //   inline DecisionStrategyProto(const DecisionStrategyProto& from) : DecisionStrategyProto(nullptr, from) {}
    //   inline DecisionStrategyProto(DecisionStrategyProto&& from) noexcept
    //       : DecisionStrategyProto(nullptr, std::move(from)) {}
    //   inline DecisionStrategyProto& operator=(const DecisionStrategyProto& from) {
    //     CopyFrom(from);
    //     return *this;
    //   }
    //   inline DecisionStrategyProto& operator=(DecisionStrategyProto&& from) noexcept {
    //     if (this == &from) return *this;
    //     if (GetArena() == from.GetArena()
    // #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
    //         && GetArena() != nullptr
    // #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    //     ) {
    //       InternalSwap(&from);
    //     } else {
    //       CopyFrom(from);
    //     }
    //     return *this;
    //   }

    //   inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
    //       ABSL_ATTRIBUTE_LIFETIME_BOUND {
    //     return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
    //   }
    //   inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
    //       ABSL_ATTRIBUTE_LIFETIME_BOUND {
    //     return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
    //   }

    //   static const ::google::protobuf::Descriptor* descriptor() {
    //     return GetDescriptor();
    //   }
    //   static const ::google::protobuf::Descriptor* GetDescriptor() {
    //     return default_instance().GetMetadata().descriptor;
    //   }
    //   static const ::google::protobuf::Reflection* GetReflection() {
    //     return default_instance().GetMetadata().reflection;
    //   }
    //   static const DecisionStrategyProto& default_instance() {
    //     return *internal_default_instance();
    //   }
    //   static inline const DecisionStrategyProto* internal_default_instance() {
    //     return reinterpret_cast<const DecisionStrategyProto*>(
    //         &_DecisionStrategyProto_default_instance_);
    //   }
    //   static constexpr int kIndexInFileMessages = 21;
    //   friend void swap(DecisionStrategyProto& a, DecisionStrategyProto& b) { a.Swap(&b); }
    //   inline void Swap(DecisionStrategyProto* other) {
    //     if (other == this) return;
    // #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    //     if (GetArena() != nullptr && GetArena() == other->GetArena()) {
    // #else   // PROTOBUF_FORCE_COPY_IN_SWAP
    //     if (GetArena() == other->GetArena()) {
    // #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
    //       InternalSwap(other);
    //     } else {
    //       ::google::protobuf::internal::GenericSwap(this, other);
    //     }
    //   }
    //   void UnsafeArenaSwap(DecisionStrategyProto* other) {
    //     if (other == this) return;
    //     ABSL_DCHECK(GetArena() == other->GetArena());
    //     InternalSwap(other);
    //   }

    //   // implements Message ----------------------------------------------

    //   DecisionStrategyProto* New(::google::protobuf::Arena* arena = nullptr) const final {
    //     return ::google::protobuf::Message::DefaultConstruct<DecisionStrategyProto>(arena);
    //   }
    //   using ::google::protobuf::Message::CopyFrom;
    //   void CopyFrom(const DecisionStrategyProto& from);
    //   using ::google::protobuf::Message::MergeFrom;
    //   void MergeFrom(const DecisionStrategyProto& from) { DecisionStrategyProto::MergeImpl(*this, from); }

    //   private:
    //   static void MergeImpl(
    //       ::google::protobuf::MessageLite& to_msg,
    //       const ::google::protobuf::MessageLite& from_msg);

    //   public:
    //   ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
    //   bool IsInitialized() const final;

    //   ::size_t ByteSizeLong() const final;
    //   const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
    //   ::uint8_t* _InternalSerialize(
    //       ::uint8_t* target,
    //       ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
    //   int GetCachedSize() const { return _impl_._cached_size_.Get(); }

    //   private:
    //   void SharedCtor(::google::protobuf::Arena* arena);
    //   void SharedDtor();
    //   void InternalSwap(DecisionStrategyProto* other);
    //  private:
    //   friend class ::google::protobuf::internal::AnyMetadata;
    //   static ::absl::string_view FullMessageName() { return "operations_research.sat.DecisionStrategyProto"; }

    //  protected:
    //   explicit DecisionStrategyProto(::google::protobuf::Arena* arena);
    //   DecisionStrategyProto(::google::protobuf::Arena* arena, const DecisionStrategyProto& from);
    //   DecisionStrategyProto(::google::protobuf::Arena* arena, DecisionStrategyProto&& from) noexcept
    //       : DecisionStrategyProto(arena) {
    //     *this = ::std::move(from);
    //   }
    //   const ::google::protobuf::MessageLite::ClassData* GetClassData()
    //       const final;

    //  public:
    //   ::google::protobuf::Metadata GetMetadata() const final;
    //   // nested types ----------------------------------------------------
    //   using VariableSelectionStrategy = DecisionStrategyProto_VariableSelectionStrategy;
    //   static constexpr VariableSelectionStrategy CHOOSE_FIRST = DecisionStrategyProto_VariableSelectionStrategy_CHOOSE_FIRST;
    //   static constexpr VariableSelectionStrategy CHOOSE_LOWEST_MIN = DecisionStrategyProto_VariableSelectionStrategy_CHOOSE_LOWEST_MIN;
    //   static constexpr VariableSelectionStrategy CHOOSE_HIGHEST_MAX = DecisionStrategyProto_VariableSelectionStrategy_CHOOSE_HIGHEST_MAX;
    //   static constexpr VariableSelectionStrategy CHOOSE_MIN_DOMAIN_SIZE = DecisionStrategyProto_VariableSelectionStrategy_CHOOSE_MIN_DOMAIN_SIZE;
    //   static constexpr VariableSelectionStrategy CHOOSE_MAX_DOMAIN_SIZE = DecisionStrategyProto_VariableSelectionStrategy_CHOOSE_MAX_DOMAIN_SIZE;
    //   static inline bool VariableSelectionStrategy_IsValid(int value) {
    //     return DecisionStrategyProto_VariableSelectionStrategy_IsValid(value);
    //   }
    //   static constexpr VariableSelectionStrategy VariableSelectionStrategy_MIN = DecisionStrategyProto_VariableSelectionStrategy_VariableSelectionStrategy_MIN;
    //   static constexpr VariableSelectionStrategy VariableSelectionStrategy_MAX = DecisionStrategyProto_VariableSelectionStrategy_VariableSelectionStrategy_MAX;
    //   static constexpr int VariableSelectionStrategy_ARRAYSIZE = DecisionStrategyProto_VariableSelectionStrategy_VariableSelectionStrategy_ARRAYSIZE;
    //   static inline const ::google::protobuf::EnumDescriptor* VariableSelectionStrategy_descriptor() {
    //     return DecisionStrategyProto_VariableSelectionStrategy_descriptor();
    //   }
    //   template <typename T>
    //   static inline const std::string& VariableSelectionStrategy_Name(T value) {
    //     return DecisionStrategyProto_VariableSelectionStrategy_Name(value);
    //   }
    //   static inline bool VariableSelectionStrategy_Parse(absl::string_view name, VariableSelectionStrategy* value) {
    //     return DecisionStrategyProto_VariableSelectionStrategy_Parse(name, value);
    //   }
    //   using DomainReductionStrategy = DecisionStrategyProto_DomainReductionStrategy;
    //   static constexpr DomainReductionStrategy SELECT_MIN_VALUE = DecisionStrategyProto_DomainReductionStrategy_SELECT_MIN_VALUE;
    //   static constexpr DomainReductionStrategy SELECT_MAX_VALUE = DecisionStrategyProto_DomainReductionStrategy_SELECT_MAX_VALUE;
    //   static constexpr DomainReductionStrategy SELECT_LOWER_HALF = DecisionStrategyProto_DomainReductionStrategy_SELECT_LOWER_HALF;
    //   static constexpr DomainReductionStrategy SELECT_UPPER_HALF = DecisionStrategyProto_DomainReductionStrategy_SELECT_UPPER_HALF;
    //   static constexpr DomainReductionStrategy SELECT_MEDIAN_VALUE = DecisionStrategyProto_DomainReductionStrategy_SELECT_MEDIAN_VALUE;
    //   static inline bool DomainReductionStrategy_IsValid(int value) {
    //     return DecisionStrategyProto_DomainReductionStrategy_IsValid(value);
    //   }
    //   static constexpr DomainReductionStrategy DomainReductionStrategy_MIN = DecisionStrategyProto_DomainReductionStrategy_DomainReductionStrategy_MIN;
    //   static constexpr DomainReductionStrategy DomainReductionStrategy_MAX = DecisionStrategyProto_DomainReductionStrategy_DomainReductionStrategy_MAX;
    //   static constexpr int DomainReductionStrategy_ARRAYSIZE = DecisionStrategyProto_DomainReductionStrategy_DomainReductionStrategy_ARRAYSIZE;
    //   static inline const ::google::protobuf::EnumDescriptor* DomainReductionStrategy_descriptor() {
    //     return DecisionStrategyProto_DomainReductionStrategy_descriptor();
    //   }
    //   template <typename T>
    //   static inline const std::string& DomainReductionStrategy_Name(T value) {
    //     return DecisionStrategyProto_DomainReductionStrategy_Name(value);
    //   }
    //   static inline bool DomainReductionStrategy_Parse(absl::string_view name, DomainReductionStrategy* value) {
    //     return DecisionStrategyProto_DomainReductionStrategy_Parse(name, value);
    //   }

    //   // accessors -------------------------------------------------------
    //   enum : int {
    //     kVariablesFieldNumber = 1,
    //     kExprsFieldNumber = 5,
    //     kVariableSelectionStrategyFieldNumber = 2,
    //     kDomainReductionStrategyFieldNumber = 3,
    //   };
    //   // repeated int32 variables = 1;
    //   int variables_size() const;
    //   private:
    //   int _internal_variables_size() const;

    //   public:
    //   void clear_variables() ;
    //   ::int32_t variables(int index) const;
    //   void set_variables(int index, ::int32_t value);
    //   void add_variables(::int32_t value);
    //   const ::google::protobuf::RepeatedField<::int32_t>& variables() const;
    //   ::google::protobuf::RepeatedField<::int32_t>* mutable_variables();

    //   private:
    //   const ::google::protobuf::RepeatedField<::int32_t>& _internal_variables() const;
    //   ::google::protobuf::RepeatedField<::int32_t>* _internal_mutable_variables();

    //   public:
    //   // repeated .operations_research.sat.LinearExpressionProto exprs = 5;
    //   int exprs_size() const;
    //   private:
    //   int _internal_exprs_size() const;

    //   public:
    //   void clear_exprs() ;
    //   ::operations_research::sat::LinearExpressionProto* mutable_exprs(int index);
    //   ::google::protobuf::RepeatedPtrField<::operations_research::sat::LinearExpressionProto>* mutable_exprs();

    //   private:
    //   const ::google::protobuf::RepeatedPtrField<::operations_research::sat::LinearExpressionProto>& _internal_exprs() const;
    //   ::google::protobuf::RepeatedPtrField<::operations_research::sat::LinearExpressionProto>* _internal_mutable_exprs();
    //   public:
    //   const ::operations_research::sat::LinearExpressionProto& exprs(int index) const;
    //   ::operations_research::sat::LinearExpressionProto* add_exprs();
    //   const ::google::protobuf::RepeatedPtrField<::operations_research::sat::LinearExpressionProto>& exprs() const;
    //   // .operations_research.sat.DecisionStrategyProto.VariableSelectionStrategy variable_selection_strategy = 2;
    //   void clear_variable_selection_strategy() ;
    //   ::operations_research::sat::DecisionStrategyProto_VariableSelectionStrategy variable_selection_strategy() const;
    //   void set_variable_selection_strategy(::operations_research::sat::DecisionStrategyProto_VariableSelectionStrategy value);

    //   private:
    //   ::operations_research::sat::DecisionStrategyProto_VariableSelectionStrategy _internal_variable_selection_strategy() const;
    //   void _internal_set_variable_selection_strategy(::operations_research::sat::DecisionStrategyProto_VariableSelectionStrategy value);

    //   public:
    //   // .operations_research.sat.DecisionStrategyProto.DomainReductionStrategy domain_reduction_strategy = 3;
    //   void clear_domain_reduction_strategy() ;
    //   ::operations_research::sat::DecisionStrategyProto_DomainReductionStrategy domain_reduction_strategy() const;
    //   void set_domain_reduction_strategy(::operations_research::sat::DecisionStrategyProto_DomainReductionStrategy value);

    //   private:
    //   ::operations_research::sat::DecisionStrategyProto_DomainReductionStrategy _internal_domain_reduction_strategy() const;
    //   void _internal_set_domain_reduction_strategy(::operations_research::sat::DecisionStrategyProto_DomainReductionStrategy value);

    //   public:
    //   // @@protoc_insertion_point(class_scope:operations_research.sat.DecisionStrategyProto)
    //  private:
    //   class _Internal;
    //   friend class ::google::protobuf::internal::TcParser;
    //   static const ::google::protobuf::internal::TcParseTable<
    //       3, 4, 1,
    //       0, 2>
    //       _table_;
    //   friend class ::google::protobuf::MessageLite;
    //   friend class ::google::protobuf::Arena;
    //   template <typename T>
    //   friend class ::google::protobuf::Arena::InternalHelper;
    //   using InternalArenaConstructable_ = void;
    //   using DestructorSkippable_ = void;
    //   struct Impl_ {
    //     inline explicit constexpr Impl_(
    //         ::google::protobuf::internal::ConstantInitialized) noexcept;
    //     inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
    //                           ::google::protobuf::Arena* arena);
    //     inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
    //                           ::google::protobuf::Arena* arena, const Impl_& from);
    //     ::google::protobuf::RepeatedField<::int32_t> variables_;
    //     mutable ::google::protobuf::internal::CachedSize _variables_cached_byte_size_;
    //     ::google::protobuf::RepeatedPtrField< ::operations_research::sat::LinearExpressionProto > exprs_;
    //     int variable_selection_strategy_;
    //     int domain_reduction_strategy_;
    //     mutable ::google::protobuf::internal::CachedSize _cached_size_;
    //     PROTOBUF_TSAN_DECLARE_MEMBER
    //   };
    //   union { Impl_ _impl_; };
    //   friend struct ::TableStruct_ortools_2fsat_2fcp_5fmodel_2eproto;
};

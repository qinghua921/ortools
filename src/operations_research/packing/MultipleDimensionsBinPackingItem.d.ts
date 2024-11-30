import { MultipleDimensionsBinPackingShape } from "./MultipleDimensionsBinPackingShape";

export class MultipleDimensionsBinPackingItem
{
    //  public:
    //   inline MultipleDimensionsBinPackingItem() : MultipleDimensionsBinPackingItem(nullptr) {}
    //   ~MultipleDimensionsBinPackingItem() override;
    //   template <typename = void>
    //   explicit PROTOBUF_CONSTEXPR MultipleDimensionsBinPackingItem(
    //       ::google::protobuf::internal::ConstantInitialized);

    //   inline MultipleDimensionsBinPackingItem(const MultipleDimensionsBinPackingItem& from) : MultipleDimensionsBinPackingItem(nullptr, from) {}
    //   inline MultipleDimensionsBinPackingItem(MultipleDimensionsBinPackingItem&& from) noexcept
    //       : MultipleDimensionsBinPackingItem(nullptr, std::move(from)) {}
    //   inline MultipleDimensionsBinPackingItem& operator=(const MultipleDimensionsBinPackingItem& from) {
    //     CopyFrom(from);
    //     return *this;
    //   }
    //   inline MultipleDimensionsBinPackingItem& operator=(MultipleDimensionsBinPackingItem&& from) noexcept {
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
    //   static const MultipleDimensionsBinPackingItem& default_instance() {
    //     return *internal_default_instance();
    //   }
    //   static inline const MultipleDimensionsBinPackingItem* internal_default_instance() {
    //     return reinterpret_cast<const MultipleDimensionsBinPackingItem*>(
    //         &_MultipleDimensionsBinPackingItem_default_instance_);
    //   }
    //   static constexpr int kIndexInFileMessages = 1;
    //   friend void swap(MultipleDimensionsBinPackingItem& a, MultipleDimensionsBinPackingItem& b) { a.Swap(&b); }
    //   inline void Swap(MultipleDimensionsBinPackingItem* other) {
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
    //   void UnsafeArenaSwap(MultipleDimensionsBinPackingItem* other) {
    //     if (other == this) return;
    //     ABSL_DCHECK(GetArena() == other->GetArena());
    //     InternalSwap(other);
    //   }

    //   // implements Message ----------------------------------------------

    //   MultipleDimensionsBinPackingItem* New(::google::protobuf::Arena* arena = nullptr) const final {
    //     return ::google::protobuf::Message::DefaultConstruct<MultipleDimensionsBinPackingItem>(arena);
    //   }
    //   using ::google::protobuf::Message::CopyFrom;
    //   void CopyFrom(const MultipleDimensionsBinPackingItem& from);
    //   using ::google::protobuf::Message::MergeFrom;
    //   void MergeFrom(const MultipleDimensionsBinPackingItem& from) { MultipleDimensionsBinPackingItem::MergeImpl(*this, from); }

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



    //  public:
    //   ::google::protobuf::Metadata GetMetadata() const final;
    //   // nested types ----------------------------------------------------

    //   // accessors -------------------------------------------------------
    //   enum : int {
    //     kShapesFieldNumber = 1,
    //     kValueFieldNumber = 2,
    //   };
    shapes_size(): number;
    //   private:
    //   int _internal_shapes_size() const;

    //   public:
    //   void clear_shapes() ;
    //   ::operations_research::packing::MultipleDimensionsBinPackingShape* mutable_shapes(int index);
    //   ::google::protobuf::RepeatedPtrField<::operations_research::packing::MultipleDimensionsBinPackingShape>* mutable_shapes();

    //   private:
    //   const ::google::protobuf::RepeatedPtrField<::operations_research::packing::MultipleDimensionsBinPackingShape>& _internal_shapes() const;
    //   ::google::protobuf::RepeatedPtrField<::operations_research::packing::MultipleDimensionsBinPackingShape>* _internal_mutable_shapes();
    //   public:
    shapes(index: number): MultipleDimensionsBinPackingShape;
    //   ::operations_research::packing::MultipleDimensionsBinPackingShape* add_shapes();
    shapes(): MultipleDimensionsBinPackingShape[];
    //   // int64 value = 2;
    //   void clear_value() ;
    //   ::int64_t value() const;
    //   void set_value(::int64_t value);

    //   private:
    //   ::int64_t _internal_value() const;
    //   void _internal_set_value(::int64_t value);

    //   public:
    //   // @@protoc_insertion_point(class_scope:operations_research.packing.MultipleDimensionsBinPackingItem)
    //  private:
    //   class _Internal;
    //   friend class ::google::protobuf::internal::TcParser;
    //   static const ::google::protobuf::internal::TcParseTable<
    //       1, 2, 1,
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
    //     ::google::protobuf::RepeatedPtrField< ::operations_research::packing::MultipleDimensionsBinPackingShape > shapes_;
    //     ::int64_t value_;
    //     mutable ::google::protobuf::internal::CachedSize _cached_size_;
    //     PROTOBUF_TSAN_DECLARE_MEMBER
    //   };
    //   union { Impl_ _impl_; };
    //   friend struct ::TableStruct_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto;
};

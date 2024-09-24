
export class MultipleDimensionsBinPackingShape // final : public ::google::protobuf::Message
{
    // public:
    //     inline MultipleDimensionsBinPackingShape()
    //         : MultipleDimensionsBinPackingShape( nullptr ) {}
    //     ~MultipleDimensionsBinPackingShape() override;
    //     template < typename = void >
    //     explicit PROTOBUF_CONSTEXPR MultipleDimensionsBinPackingShape(
    //         ::google::protobuf::internal::ConstantInitialized );

    //     inline MultipleDimensionsBinPackingShape( const MultipleDimensionsBinPackingShape& from )
    //         : MultipleDimensionsBinPackingShape( nullptr, from ) {}
    //     inline MultipleDimensionsBinPackingShape( MultipleDimensionsBinPackingShape&& from ) noexcept
    //         : MultipleDimensionsBinPackingShape( nullptr, std::move( from ) ) {}
    //     inline MultipleDimensionsBinPackingShape& operator=( const MultipleDimensionsBinPackingShape& from )
    //     {
    //         CopyFrom( from );
    //         return *this;
    //     }
    //     inline MultipleDimensionsBinPackingShape& operator=( MultipleDimensionsBinPackingShape&& from ) noexcept
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
    //     static const MultipleDimensionsBinPackingShape& default_instance()
    //     {
    //         return *internal_default_instance();
    //     }
    //     static inline const MultipleDimensionsBinPackingShape* internal_default_instance()
    //     {
    //         return reinterpret_cast< const MultipleDimensionsBinPackingShape* >(
    //             &_MultipleDimensionsBinPackingShape_default_instance_ );
    //     }
    //     static constexpr int kIndexInFileMessages = 0;
    //     friend void          swap( MultipleDimensionsBinPackingShape& a, MultipleDimensionsBinPackingShape& b )
    //     {
    //         a.Swap( &b );
    //     }
    //     inline void Swap( MultipleDimensionsBinPackingShape* other )
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
    //     void UnsafeArenaSwap( MultipleDimensionsBinPackingShape* other )
    //     {
    //         if ( other == this ) return;
    //         ABSL_DCHECK( GetArena() == other->GetArena() );
    //         InternalSwap( other );
    //     }

    //     // implements Message ----------------------------------------------

    //     MultipleDimensionsBinPackingShape* New( ::google::protobuf::Arena* arena = nullptr ) const final
    //     {
    //         return ::google::protobuf::Message::DefaultConstruct< MultipleDimensionsBinPackingShape >( arena );
    //     }
    //     using ::google::protobuf::Message::CopyFrom;
    //     void CopyFrom( const MultipleDimensionsBinPackingShape& from );
    //     using ::google::protobuf::Message::MergeFrom;
    //     void MergeFrom( const MultipleDimensionsBinPackingShape& from )
    //     {
    //         MultipleDimensionsBinPackingShape::MergeImpl( *this, from );
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
    //     void InternalSwap( MultipleDimensionsBinPackingShape* other );

    // private:
    //     friend class ::google::protobuf::internal::AnyMetadata;
    //     static ::absl::string_view FullMessageName()
    //     {
    //         return "operations_research.packing.MultipleDimensionsBinPackingShape";
    //     }

    // protected:
    //     explicit MultipleDimensionsBinPackingShape( ::google::protobuf::Arena* arena );
    //     MultipleDimensionsBinPackingShape( ::google::protobuf::Arena* arena, const MultipleDimensionsBinPackingShape& from );
    //     MultipleDimensionsBinPackingShape( ::google::protobuf::Arena* arena, MultipleDimensionsBinPackingShape&& from ) noexcept
    //         : MultipleDimensionsBinPackingShape( arena )
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
    //         kDimensionsFieldNumber = 1,
    //     };
    //     // repeated int64 dimensions = 1;
    //     int dimensions_size() const;

    // private:
    //     int _internal_dimensions_size() const;

    // public:
    //     void                                                  clear_dimensions();
    //     ::int64_t                                             dimensions( int index ) const;
    //     void                                                  set_dimensions( int index, ::int64_t value );
    //     void                                                  add_dimensions( ::int64_t value );

    /**
     * C++ const ::google::protobuf::RepeatedField< ::int64_t >& dimensions() const;
     */
    dimensions(): number[];

    //     ::google::protobuf::RepeatedField< ::int64_t >*       mutable_dimensions();

    // private:
    //     const ::google::protobuf::RepeatedField< ::int64_t >& _internal_dimensions() const;
    //     ::google::protobuf::RepeatedField< ::int64_t >*       _internal_mutable_dimensions();

    // public:
    //     // @@protoc_insertion_point(class_scope:operations_research.packing.MultipleDimensionsBinPackingShape)
    // private:
    //     class _Internal;
    //     friend class ::google::protobuf::internal::TcParser;
    //     static const ::google::protobuf::internal::TcParseTable<
    //         0, 1, 0,
    //         0, 2 >
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
    //         ::google::protobuf::RepeatedField< ::int64_t >   dimensions_;
    //         mutable ::google::protobuf::internal::CachedSize _dimensions_cached_byte_size_;
    //         mutable ::google::protobuf::internal::CachedSize _cached_size_;
    //         PROTOBUF_TSAN_DECLARE_MEMBER
    //     };
    //     union
    //     {
    //         Impl_ _impl_;
    //     };
    //     friend struct ::TableStruct_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto;
};

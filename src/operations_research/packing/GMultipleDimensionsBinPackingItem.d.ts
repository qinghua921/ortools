import { MultipleDimensionsBinPackingShape } from "./GMultipleDimensionsBinPackingShape";

export class MultipleDimensionsBinPackingItem 
{
    // public:
    //     inline MultipleDimensionsBinPackingItem()
    //         : MultipleDimensionsBinPackingItem( nullptr ) {}
    //     ~MultipleDimensionsBinPackingItem() override;
    //     explicit PROTOBUF_CONSTEXPR MultipleDimensionsBinPackingItem( ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized );

    //     MultipleDimensionsBinPackingItem( const MultipleDimensionsBinPackingItem& from );
    //     MultipleDimensionsBinPackingItem( MultipleDimensionsBinPackingItem&& from ) noexcept
    //         : MultipleDimensionsBinPackingItem()
    //     {
    //         *this = ::std::move( from );
    //     }

    //     inline MultipleDimensionsBinPackingItem& operator=( const MultipleDimensionsBinPackingItem& from )
    //     {
    //         CopyFrom( from );
    //         return *this;
    //     }
    //     inline MultipleDimensionsBinPackingItem& operator=( MultipleDimensionsBinPackingItem&& from ) noexcept
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
    //     static const MultipleDimensionsBinPackingItem& default_instance()
    //     {
    //         return *internal_default_instance();
    //     }
    //     static inline const MultipleDimensionsBinPackingItem* internal_default_instance()
    //     {
    //         return reinterpret_cast< const MultipleDimensionsBinPackingItem* >(
    //             &_MultipleDimensionsBinPackingItem_default_instance_ );
    //     }
    //     static constexpr int kIndexInFileMessages =
    //         1;

    //     friend void swap( MultipleDimensionsBinPackingItem& a, MultipleDimensionsBinPackingItem& b )
    //     {
    //         a.Swap( &b );
    //     }
    //     inline void Swap( MultipleDimensionsBinPackingItem* other )
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
    //     void UnsafeArenaSwap( MultipleDimensionsBinPackingItem* other )
    //     {
    //         if ( other == this ) return;
    //         GOOGLE_DCHECK( GetOwningArena() == other->GetOwningArena() );
    //         InternalSwap( other );
    //     }

    //     // implements Message ----------------------------------------------

    //     MultipleDimensionsBinPackingItem* New( ::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr ) const final
    //     {
    //         return CreateMaybeMessage< MultipleDimensionsBinPackingItem >( arena );
    //     }
    //     using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
    //     void CopyFrom( const MultipleDimensionsBinPackingItem& from );
    //     using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
    //     void MergeFrom( const MultipleDimensionsBinPackingItem& from )
    //     {
    //         MultipleDimensionsBinPackingItem::MergeImpl( *this, from );
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
    //     void InternalSwap( MultipleDimensionsBinPackingItem* other );

    // private:
    //     friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
    //     static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName()
    //     {
    //         return "operations_research.packing.MultipleDimensionsBinPackingItem";
    //     }

    // protected:
    //     explicit MultipleDimensionsBinPackingItem( ::PROTOBUF_NAMESPACE_ID::Arena* arena,
    //                                                bool                            is_message_owned = false );

    // public:
    //     static const ClassData                             _class_data_;
    //     const ::PROTOBUF_NAMESPACE_ID::Message::ClassData* GetClassData() const final;

    //     ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

    //     // nested types ----------------------------------------------------

    //     // accessors -------------------------------------------------------

    //     enum : int
    //     {
    //         kShapesFieldNumber = 1,
    //         kValueFieldNumber  = 2,
    //     };

    //     // repeated .operations_research.packing.MultipleDimensionsBinPackingShape shapes = 1;
    //     int shapes_size() const;
    shapes_size(): number;

    // private:
    //     int _internal_shapes_size() const;

    // public:
    //     void                                                               clear_shapes();
    //     ::operations_research::packing::MultipleDimensionsBinPackingShape* mutable_shapes( int index );
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::packing::MultipleDimensionsBinPackingShape >*
    //     mutable_shapes();


    //     const ::operations_research::packing::MultipleDimensionsBinPackingShape& shapes( int index ) const;
    shapes(index: number): MultipleDimensionsBinPackingShape;

    // public:
    //     ::operations_research::packing::MultipleDimensionsBinPackingShape*       add_shapes();
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::packing::MultipleDimensionsBinPackingShape >&
    //     shapes() const;

    //     // int64 value = 2;
    //     void    clear_value();
    //     int64_t value() const;
    //     void    set_value( int64_t value );

    // private:
    //     int64_t _internal_value() const;
    //     void    _internal_set_value( int64_t value );

    // public:
    //     // @@protoc_insertion_point(class_scope:operations_research.packing.MultipleDimensionsBinPackingItem)
    // private:
    //     class _Internal;

    //     template < typename T >
    //     friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
    //     typedef void InternalArenaConstructable_;
    //     typedef void DestructorSkippable_;
    //     struct Impl_
    //     {
    //         ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::packing::MultipleDimensionsBinPackingShape > shapes_;
    //         int64_t                                                                                                        value_;
    //         mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize                                                          _cached_size_;
    //     };
    //     union
    //     {
    //         Impl_ _impl_;
    //     };
    //     friend struct ::TableStruct_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto;
};

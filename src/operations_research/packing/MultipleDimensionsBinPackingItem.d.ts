
class MultipleDimensionsBinPackingItem // final : public ::google::protobuf::Message
{
    // public:
    //     inline MultipleDimensionsBinPackingItem()
    //         : MultipleDimensionsBinPackingItem( nullptr ) {}
    //     ~MultipleDimensionsBinPackingItem() override;
    //     template < typename = void >
    //     explicit PROTOBUF_CONSTEXPR MultipleDimensionsBinPackingItem(
    //         ::google::protobuf::internal::ConstantInitialized );

    //     inline MultipleDimensionsBinPackingItem( const MultipleDimensionsBinPackingItem& from )
    //         : MultipleDimensionsBinPackingItem( nullptr, from ) {}
    //     inline MultipleDimensionsBinPackingItem( MultipleDimensionsBinPackingItem&& from ) noexcept
    //         : MultipleDimensionsBinPackingItem( nullptr, std::move( from ) ) {}
    //     inline MultipleDimensionsBinPackingItem& operator=( const MultipleDimensionsBinPackingItem& from )
    //     {
    //         CopyFrom( from );
    //         return *this;
    //     }
    //     inline MultipleDimensionsBinPackingItem& operator=( MultipleDimensionsBinPackingItem&& from ) noexcept
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
    //     static const MultipleDimensionsBinPackingItem& default_instance()
    //     {
    //         return *internal_default_instance();
    //     }
    //     static inline const MultipleDimensionsBinPackingItem* internal_default_instance()
    //     {
    //         return reinterpret_cast< const MultipleDimensionsBinPackingItem* >(
    //             &_MultipleDimensionsBinPackingItem_default_instance_ );
    //     }
    //     static constexpr int kIndexInFileMessages = 1;
    //     friend void          swap( MultipleDimensionsBinPackingItem& a, MultipleDimensionsBinPackingItem& b )
    //     {
    //         a.Swap( &b );
    //     }
    //     inline void Swap( MultipleDimensionsBinPackingItem* other )
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
    //     void UnsafeArenaSwap( MultipleDimensionsBinPackingItem* other )
    //     {
    //         if ( other == this ) return;
    //         ABSL_DCHECK( GetArena() == other->GetArena() );
    //         InternalSwap( other );
    //     }

    //     // implements Message ----------------------------------------------

    //     MultipleDimensionsBinPackingItem* New( ::google::protobuf::Arena* arena = nullptr ) const final
    //     {
    //         return ::google::protobuf::Message::DefaultConstruct< MultipleDimensionsBinPackingItem >( arena );
    //     }
    //     using ::google::protobuf::Message::CopyFrom;
    //     void CopyFrom( const MultipleDimensionsBinPackingItem& from );
    //     using ::google::protobuf::Message::MergeFrom;
    //     void MergeFrom( const MultipleDimensionsBinPackingItem& from )
    //     {
    //         MultipleDimensionsBinPackingItem::MergeImpl( *this, from );
    //     }

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



    // public:
    //     ::google::protobuf::Metadata GetMetadata() const final;
    //     // nested types ----------------------------------------------------

    //     // accessors -------------------------------------------------------
    //     enum : int
    //     {
    //         kShapesFieldNumber = 1,
    //         kValueFieldNumber  = 2,
    //     };
    //     // repeated .operations_research.packing.MultipleDimensionsBinPackingShape shapes = 1;
    //     int shapes_size() const;


    // public:
    //     void                                                                                                       clear_shapes();
    //     ::operations_research::packing::MultipleDimensionsBinPackingShape*                                         mutable_shapes( int index );
    //     ::google::protobuf::RepeatedPtrField< ::operations_research::packing::MultipleDimensionsBinPackingShape >* mutable_shapes();


    // public:
    //     const ::operations_research::packing::MultipleDimensionsBinPackingShape&                                         shapes( int index ) const;
    //     ::operations_research::packing::MultipleDimensionsBinPackingShape*                                               add_shapes();
    //     const ::google::protobuf::RepeatedPtrField< ::operations_research::packing::MultipleDimensionsBinPackingShape >& shapes() const;
    //     // int64 value = 2;
    //     void      clear_value();
    //     ::int64_t value() const;
    //     void      set_value( ::int64_t value );


    // public:
    //     // @@protoc_insertion_point(class_scope:operations_research.packing.MultipleDimensionsBinPackingItem)
};

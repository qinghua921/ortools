export class MultipleDimensionsBinPackingShape 
{
    // public:
    //     inline MultipleDimensionsBinPackingShape()
    //         : MultipleDimensionsBinPackingShape( nullptr ) {}
    //     ~MultipleDimensionsBinPackingShape() override;
    //     explicit PROTOBUF_CONSTEXPR MultipleDimensionsBinPackingShape( ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized );

    //     MultipleDimensionsBinPackingShape( const MultipleDimensionsBinPackingShape& from );
    //     MultipleDimensionsBinPackingShape( MultipleDimensionsBinPackingShape&& from ) noexcept
    //         : MultipleDimensionsBinPackingShape()
    //     {
    //         *this = ::std::move( from );
    //     }

    //     inline MultipleDimensionsBinPackingShape& operator=( const MultipleDimensionsBinPackingShape& from )
    //     {
    //         CopyFrom( from );
    //         return *this;
    //     }
    //     inline MultipleDimensionsBinPackingShape& operator=( MultipleDimensionsBinPackingShape&& from ) noexcept
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
    //     static const MultipleDimensionsBinPackingShape& default_instance()
    //     {
    //         return *internal_default_instance();
    //     }
    //     static inline const MultipleDimensionsBinPackingShape* internal_default_instance()
    //     {
    //         return reinterpret_cast< const MultipleDimensionsBinPackingShape* >(
    //             &_MultipleDimensionsBinPackingShape_default_instance_ );
    //     }
    //     static constexpr int kIndexInFileMessages =
    //         0;

    //     friend void swap( MultipleDimensionsBinPackingShape& a, MultipleDimensionsBinPackingShape& b )
    //     {
    //         a.Swap( &b );
    //     }
    //     inline void Swap( MultipleDimensionsBinPackingShape* other )
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
    //     void UnsafeArenaSwap( MultipleDimensionsBinPackingShape* other )
    //     {
    //         if ( other == this ) return;
    //         GOOGLE_DCHECK( GetOwningArena() == other->GetOwningArena() );
    //         InternalSwap( other );
    //     }

    //     // implements Message ----------------------------------------------

    //     MultipleDimensionsBinPackingShape* New( ::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr ) const final
    //     {
    //         return CreateMaybeMessage< MultipleDimensionsBinPackingShape >( arena );
    //     }
    //     using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
    //     void CopyFrom( const MultipleDimensionsBinPackingShape& from );
    //     using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
    //     void MergeFrom( const MultipleDimensionsBinPackingShape& from )
    //     {
    //         MultipleDimensionsBinPackingShape::MergeImpl( *this, from );
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



    // protected:
    //     explicit MultipleDimensionsBinPackingShape( ::PROTOBUF_NAMESPACE_ID::Arena* arena,
    //                                                 bool                            is_message_owned = false );

    // public:
    //     static const ClassData                             _class_data_;
    //     const ::PROTOBUF_NAMESPACE_ID::Message::ClassData* GetClassData() const final;

    //     ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

    //     // nested types ----------------------------------------------------

    //     // accessors -------------------------------------------------------

    //     enum : int
    //     {
    //         kDimensionsFieldNumber = 1,
    //     };
    //     // repeated int64 dimensions = 1;
    //     int dimensions_size() const;


    // public:
    //     void clear_dimensions();


    // public:
    //     int64_t dimensions( int index ) const;
    //     void    set_dimensions( int index, int64_t value );
    //     void    add_dimensions( int64_t value );
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
    //     dimensions() const;
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
    //     mutable_dimensions();

}

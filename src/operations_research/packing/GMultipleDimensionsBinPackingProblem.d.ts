
export class MultipleDimensionsBinPackingProblem 
{
    // public:
    //     inline MultipleDimensionsBinPackingProblem()
    //         : MultipleDimensionsBinPackingProblem( nullptr ) {}
    //     ~MultipleDimensionsBinPackingProblem() override;
    //     explicit PROTOBUF_CONSTEXPR MultipleDimensionsBinPackingProblem( ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized );

    //     MultipleDimensionsBinPackingProblem( const MultipleDimensionsBinPackingProblem& from );
    //     MultipleDimensionsBinPackingProblem( MultipleDimensionsBinPackingProblem&& from ) noexcept
    //         : MultipleDimensionsBinPackingProblem()
    //     {
    //         *this = ::std::move( from );
    //     }

    //     inline MultipleDimensionsBinPackingProblem& operator=( const MultipleDimensionsBinPackingProblem& from )
    //     {
    //         CopyFrom( from );
    //         return *this;
    //     }
    //     inline MultipleDimensionsBinPackingProblem& operator=( MultipleDimensionsBinPackingProblem&& from ) noexcept
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
    //     static const MultipleDimensionsBinPackingProblem& default_instance()
    //     {
    //         return *internal_default_instance();
    //     }
    //     static inline const MultipleDimensionsBinPackingProblem* internal_default_instance()
    //     {
    //         return reinterpret_cast< const MultipleDimensionsBinPackingProblem* >(
    //             &_MultipleDimensionsBinPackingProblem_default_instance_ );
    //     }
    //     static constexpr int kIndexInFileMessages =
    //         2;

    //     friend void swap( MultipleDimensionsBinPackingProblem& a, MultipleDimensionsBinPackingProblem& b )
    //     {
    //         a.Swap( &b );
    //     }
    //     inline void Swap( MultipleDimensionsBinPackingProblem* other )
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
    //     void UnsafeArenaSwap( MultipleDimensionsBinPackingProblem* other )
    //     {
    //         if ( other == this ) return;
    //         GOOGLE_DCHECK( GetOwningArena() == other->GetOwningArena() );
    //         InternalSwap( other );
    //     }

    //     // implements Message ----------------------------------------------

    //     MultipleDimensionsBinPackingProblem* New( ::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr ) const final
    //     {
    //         return CreateMaybeMessage< MultipleDimensionsBinPackingProblem >( arena );
    //     }
    //     using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
    //     void CopyFrom( const MultipleDimensionsBinPackingProblem& from );
    //     using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
    //     void MergeFrom( const MultipleDimensionsBinPackingProblem& from )
    //     {
    //         MultipleDimensionsBinPackingProblem::MergeImpl( *this, from );
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
    //     void InternalSwap( MultipleDimensionsBinPackingProblem* other );

    // private:
    //     friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
    //     static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName()
    //     {
    //         return "operations_research.packing.MultipleDimensionsBinPackingProblem";
    //     }

    // protected:
    //     explicit MultipleDimensionsBinPackingProblem( ::PROTOBUF_NAMESPACE_ID::Arena* arena,
    //                                                   bool                            is_message_owned = false );

    // public:
    //     static const ClassData                             _class_data_;
    //     const ::PROTOBUF_NAMESPACE_ID::Message::ClassData* GetClassData() const final;

    //     ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

    //     // nested types ----------------------------------------------------

    //     // accessors -------------------------------------------------------

    //     enum : int
    //     {
    //         kItemsFieldNumber    = 2,
    //         kBoxShapeFieldNumber = 1,
    //     };

    //     // repeated .operations_research.packing.MultipleDimensionsBinPackingItem items = 2;
    //     int items_size() const;
    items_size(): number;


    // public:
    //     void                                                              clear_items();
    //     ::operations_research::packing::MultipleDimensionsBinPackingItem* mutable_items( int index );
    //     ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::packing::MultipleDimensionsBinPackingItem >*
    //     mutable_items();

    // private:
    //     const ::operations_research::packing::MultipleDimensionsBinPackingItem& _internal_items( int index ) const;
    //     ::operations_research::packing::MultipleDimensionsBinPackingItem*       _internal_add_items();

    // public:
    //     const ::operations_research::packing::MultipleDimensionsBinPackingItem& items( int index ) const;
    //     ::operations_research::packing::MultipleDimensionsBinPackingItem*       add_items();
    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::operations_research::packing::MultipleDimensionsBinPackingItem >&
    //     items() const;

    //     // .operations_research.packing.MultipleDimensionsBinPackingShape box_shape = 1;
    //     bool has_box_shape() const;

    // private:
    //     bool _internal_has_box_shape() const;

    // public:
    //     void                                                                                  clear_box_shape();
    //     const ::operations_research::packing::MultipleDimensionsBinPackingShape&              box_shape() const;
    
    //     PROTOBUF_NODISCARD ::operations_research::packing::MultipleDimensionsBinPackingShape* release_box_shape();
    //     ::operations_research::packing::MultipleDimensionsBinPackingShape*                    mutable_box_shape();
    //     void                                                                                  set_allocated_box_shape( ::operations_research::packing::MultipleDimensionsBinPackingShape* box_shape );

    // private:
    //     const ::operations_research::packing::MultipleDimensionsBinPackingShape& _internal_box_shape() const;
    //     ::operations_research::packing::MultipleDimensionsBinPackingShape*       _internal_mutable_box_shape();

    // public:
    //     void unsafe_arena_set_allocated_box_shape(
    //         ::operations_research::packing::MultipleDimensionsBinPackingShape* box_shape );
    //     ::operations_research::packing::MultipleDimensionsBinPackingShape* unsafe_arena_release_box_shape();

    //     // @@protoc_insertion_point(class_scope:operations_research.packing.MultipleDimensionsBinPackingProblem)
};

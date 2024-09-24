
export class MultipleDimensionsBinPackingProblem // final : public ::google::protobuf::Message
{
    //    public:

    /**
     * C++ inline MultipleDimensionsBinPackingProblem()
     *     : MultipleDimensionsBinPackingProblem( nullptr ) {}
     */
    constructor();

    //        template < typename = void >
    //        explicit PROTOBUF_CONSTEXPR MultipleDimensionsBinPackingProblem(
    //            ::google::protobuf::internal::ConstantInitialized );

    //        inline MultipleDimensionsBinPackingProblem( const MultipleDimensionsBinPackingProblem& from )
    //            : MultipleDimensionsBinPackingProblem( nullptr, from ) {}
    //        inline MultipleDimensionsBinPackingProblem( MultipleDimensionsBinPackingProblem&& from ) noexcept
    //            : MultipleDimensionsBinPackingProblem( nullptr, std::move( from ) ) {}
    //        inline MultipleDimensionsBinPackingProblem& operator=( const MultipleDimensionsBinPackingProblem& from )
    //        {
    //            CopyFrom( from );
    //            return *this;
    //        }
    //        inline MultipleDimensionsBinPackingProblem& operator=( MultipleDimensionsBinPackingProblem&& from ) noexcept
    //        {
    //            if ( this == &from ) return *this;
    //            if ( GetArena() == from.GetArena()
    //#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
    //                 && GetArena() != nullptr
    //#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    //            )
    //            {
    //                InternalSwap( &from );
    //            }
    //            else
    //            {
    //                CopyFrom( from );
    //            }
    //            return *this;
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
    //        static const MultipleDimensionsBinPackingProblem& default_instance()
    //        {
    //            return *internal_default_instance();
    //        }
    //        static inline const MultipleDimensionsBinPackingProblem* internal_default_instance()
    //        {
    //            return reinterpret_cast< const MultipleDimensionsBinPackingProblem* >(
    //                &_MultipleDimensionsBinPackingProblem_default_instance_ );
    //        }
    //        static constexpr int kIndexInFileMessages = 2;
    //        friend void          swap( MultipleDimensionsBinPackingProblem& a, MultipleDimensionsBinPackingProblem& b )
    //        {
    //            a.Swap( &b );
    //        }
    //        inline void Swap( MultipleDimensionsBinPackingProblem* other )
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
    //        void UnsafeArenaSwap( MultipleDimensionsBinPackingProblem* other )
    //        {
    //            if ( other == this ) return;
    //            ABSL_DCHECK( GetArena() == other->GetArena() );
    //            InternalSwap( other );
    //        }

    //        // implements Message ----------------------------------------------

    //        MultipleDimensionsBinPackingProblem* New( ::google::protobuf::Arena* arena = nullptr ) const final
    //        {
    //            return ::google::protobuf::Message::DefaultConstruct< MultipleDimensionsBinPackingProblem >( arena );
    //        }
    //        using ::google::protobuf::Message::CopyFrom;
    //        void CopyFrom( const MultipleDimensionsBinPackingProblem& from );
    //        using ::google::protobuf::Message::MergeFrom;
    //        void MergeFrom( const MultipleDimensionsBinPackingProblem& from )
    //        {
    //            MultipleDimensionsBinPackingProblem::MergeImpl( *this, from );
    //        }

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



    //    public:
    //        ::google::protobuf::Metadata GetMetadata() const final;
    //        // nested types ----------------------------------------------------

    //        // accessors -------------------------------------------------------
    //        enum : int
    //        {
    //            kItemsFieldNumber    = 2,
    //            kBoxShapeFieldNumber = 1,
    //        };

    //        // repeated .operations_research.packing.MultipleDimensionsBinPackingItem items = 2;
    //        int items_size() const;
    /**
     * repeated .operations_research.packing.MultipleDimensionsBinPackingItem items = 2;
     * 
     * C++ int items_size() const;
     */
    items_size(): number;


    //    public:
    //        void                                                                                                      clear_items();
    //        ::operations_research::packing::MultipleDimensionsBinPackingItem*                                         mutable_items( int index );
    //        ::google::protobuf::RepeatedPtrField< ::operations_research::packing::MultipleDimensionsBinPackingItem >* mutable_items();

    //    private:
    //        const ::google::protobuf::RepeatedPtrField< ::operations_research::packing::MultipleDimensionsBinPackingItem >& _internal_items() const;
    //        ::google::protobuf::RepeatedPtrField< ::operations_research::packing::MultipleDimensionsBinPackingItem >*       _internal_mutable_items();

    //    public:
    //        const ::operations_research::packing::MultipleDimensionsBinPackingItem&                                         items( int index ) const;
    //        ::operations_research::packing::MultipleDimensionsBinPackingItem*                                               add_items();
    //        const ::google::protobuf::RepeatedPtrField< ::operations_research::packing::MultipleDimensionsBinPackingItem >& items() const;

    //        // .operations_research.packing.MultipleDimensionsBinPackingShape box_shape = 1;
    //        bool                                                                                  has_box_shape() const;
    //        void                                                                                  clear_box_shape();

    /**
     * C++ const ::operations_research::packing::MultipleDimensionsBinPackingShape& box_shape() const;
     */
    box_shape(): readonly MultipleDimensionsBinPackingShape;

    //        PROTOBUF_NODISCARD ::operations_research::packing::MultipleDimensionsBinPackingShape* release_box_shape();
    //        ::operations_research::packing::MultipleDimensionsBinPackingShape*                    mutable_box_shape();
    //        void                                                                                  set_allocated_box_shape( ::operations_research::packing::MultipleDimensionsBinPackingShape* value );
    //        void                                                                                  unsafe_arena_set_allocated_box_shape( ::operations_research::packing::MultipleDimensionsBinPackingShape* value );
    //        ::operations_research::packing::MultipleDimensionsBinPackingShape*                    unsafe_arena_release_box_shape();


};

import { MultipleDimensionsBinPackingItem } from "../../operations_research/packing/GMultipleDimensionsBinPackingItem";
import { RepeatedField } from "./GRepeatedField";

export class RepeatedPtrField_MultipleDimensionsBinPackingItem extends RepeatedPtrField<MultipleDimensionsBinPackingItem> { }

// RepeatedPtrField is like RepeatedField, but used for repeated strings or
// Messages.
class RepeatedPtrField<Element> extends RepeatedField<Element>
{

    //     public:
    //         constexpr RepeatedPtrField();
    //         explicit RepeatedPtrField( Arena* arena );

    //         RepeatedPtrField( const RepeatedPtrField& other );

    //         template < typename Iter,
    //                    typename = typename std::enable_if< std::is_constructible<
    //                        Element, decltype( *std::declval< Iter >() ) >::value >::type >
    //         RepeatedPtrField( Iter begin, Iter end );

    //         ~RepeatedPtrField();

    //         RepeatedPtrField& operator=( const RepeatedPtrField& other );

    //         RepeatedPtrField( RepeatedPtrField&& other ) noexcept;
    //         RepeatedPtrField& operator=( RepeatedPtrField&& other ) noexcept;

    //         bool empty() const;
    //         int  size() const;
    size(): number;

    //         const Element& Get( int index ) const;
    Get(index: number): Element;
    //         Element*       Mutable( int index );

    //         // Unlike std::vector, adding an element to a RepeatedPtrField doesn't always
    //         // make a new element; it might re-use an element left over from when the
    //         // field was Clear()'d or reize()'d smaller.  For this reason, Add() is the
    //         // fastest API for adding a new element.
    //         Element* Add();

    //         // `Add(std::move(value));` is equivalent to `*Add() = std::move(value);`
    //         // It will either move-construct to the end of this field, or swap value
    //         // with the new-or-recycled element at the end of this field.  Note that
    //         // this operation is very slow if this RepeatedPtrField is not on the
    //         // same Arena, if any, as `value`.
    //         void Add( Element&& value );

    //         // Copying to the end of this RepeatedPtrField is slowest of all; it can't
    //         // reliably copy-construct to the last element of this RepeatedPtrField, for
    //         // example (unlike std::vector).
    //         // We currently block this API.  The right way to add to the end is to call
    //         // Add() and modify the element it points to.
    //         // If you must add an existing value, call `*Add() = value;`
    //         void Add( const Element& value ) = delete;

    //         // Append elements in the range [begin, end) after reserving
    //         // the appropriate number of elements.
    //         template < typename Iter >
    //         void Add( Iter begin, Iter end );

    //         const Element& operator[]( int index ) const
    //         {
    //             return Get( index );
    //         }
    //         Element& operator[]( int index )
    //         {
    //             return *Mutable( index );
    //         }

    //         const Element& at( int index ) const;
    //         Element&       at( int index );

    //         // Removes the last element in the array.
    //         // Ownership of the element is retained by the array.
    //         void RemoveLast();

    //         // Deletes elements with indices in the range [start .. start+num-1].
    //         // Caution: moves all elements with indices [start+num .. ].
    //         // Calling this routine inside a loop can cause quadratic behavior.
    //         void DeleteSubrange( int start, int num );

    //         PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear();
    //         void                                  MergeFrom( const RepeatedPtrField& other );
    //         PROTOBUF_ATTRIBUTE_REINITIALIZES void CopyFrom( const RepeatedPtrField& other );

    //         // Replaces the contents with RepeatedPtrField(begin, end).
    //         template < typename Iter >
    //         PROTOBUF_ATTRIBUTE_REINITIALIZES void Assign( Iter begin, Iter end );

    //         // Reserves space to expand the field to at least the given size.  This only
    //         // resizes the pointer array; it doesn't allocate any objects.  If the
    //         // array is grown, it will always be at least doubled in size.
    //         void Reserve( int new_size );

    //         int Capacity() const;

    //         // Gets the underlying array.  This pointer is possibly invalidated by
    //         // any add or remove operation.
    //         //
    //         // This API is deprecated. Instead of directly working with element array,
    //         // use APIs in repeated_field_util.h; e.g. sorting, etc.
    //         PROTOBUF_DEPRECATED_MSG( "Use APIs in repeated_field_util.h" )
    //         Element**             mutable_data();
    //         const Element* const* data() const;

    //         // Swaps entire contents with "other". If they are on separate arenas, then
    //         // copies data.
    //         void Swap( RepeatedPtrField* other );

    //         // Swaps entire contents with "other". Caller should guarantee that either
    //         // both fields are on the same arena or both are on the heap. Swapping between
    //         // different arenas with this function is disallowed and is caught via
    //         // GOOGLE_DCHECK.
    //         void UnsafeArenaSwap( RepeatedPtrField* other );

    //         // Swaps two elements.
    //         void SwapElements( int index1, int index2 );

    //         // STL-like iterator support
    //         typedef internal::RepeatedPtrIterator< Element >       iterator;
    //         typedef internal::RepeatedPtrIterator< const Element > const_iterator;
    //         typedef Element                                        value_type;
    //         typedef value_type&                                    reference;
    //         typedef const value_type&                              const_reference;
    //         typedef value_type*                                    pointer;
    //         typedef const value_type*                              const_pointer;
    //         typedef int                                            size_type;
    //         typedef ptrdiff_t                                      difference_type;

    //         iterator       begin();
    //         const_iterator begin() const;
    //         const_iterator cbegin() const;
    //         iterator       end();
    //         const_iterator end() const;
    //         const_iterator cend() const;

    //         // Reverse iterator support
    //         typedef std::reverse_iterator< const_iterator > const_reverse_iterator;
    //         typedef std::reverse_iterator< iterator >       reverse_iterator;
    //         reverse_iterator                                rbegin()
    //         {
    //             return reverse_iterator( end() );
    //         }
    //         const_reverse_iterator rbegin() const
    //         {
    //             return const_reverse_iterator( end() );
    //         }
    //         reverse_iterator rend()
    //         {
    //             return reverse_iterator( begin() );
    //         }
    //         const_reverse_iterator rend() const
    //         {
    //             return const_reverse_iterator( begin() );
    //         }

    //         // Custom STL-like iterator that iterates over and returns the underlying
    //         // pointers to Element rather than Element itself.
    //         typedef internal::RepeatedPtrOverPtrsIterator< Element*, void* >
    //             pointer_iterator;
    //         typedef internal::RepeatedPtrOverPtrsIterator< const Element* const,
    //                                                        const void* const >
    //                                const_pointer_iterator;
    //         pointer_iterator       pointer_begin();
    //         const_pointer_iterator pointer_begin() const;
    //         pointer_iterator       pointer_end();
    //         const_pointer_iterator pointer_end() const;

    //         // Returns (an estimate of) the number of bytes used by the repeated field,
    //         // excluding sizeof(*this).
    //         size_t SpaceUsedExcludingSelfLong() const;

    //         int SpaceUsedExcludingSelf() const
    //         {
    //             return internal::ToIntSize( SpaceUsedExcludingSelfLong() );
    //         }

    //         // Advanced memory management --------------------------------------
    //         // When hardcore memory management becomes necessary -- as it sometimes
    //         // does here at Google -- the following methods may be useful.

    //         // Adds an already-allocated object, passing ownership to the
    //         // RepeatedPtrField.
    //         //
    //         // Note that some special behavior occurs with respect to arenas:
    //         //
    //         //   (i) if this field holds submessages, the new submessage will be copied if
    //         //   the original is in an arena and this RepeatedPtrField is either in a
    //         //   different arena, or on the heap.
    //         //   (ii) if this field holds strings, the passed-in string *must* be
    //         //   heap-allocated, not arena-allocated. There is no way to dynamically check
    //         //   this at runtime, so User Beware.
    //         void AddAllocated( Element* value );

    //         // Removes and returns the last element, passing ownership to the caller.
    //         // Requires:  size() > 0
    //         //
    //         // If this RepeatedPtrField is on an arena, an object copy is required to pass
    //         // ownership back to the user (for compatible semantics). Use
    //         // UnsafeArenaReleaseLast() if this behavior is undesired.
    //         PROTOBUF_NODISCARD Element* ReleaseLast();

    //         // Adds an already-allocated object, skipping arena-ownership checks. The user
    //         // must guarantee that the given object is in the same arena as this
    //         // RepeatedPtrField.
    //         // It is also useful in legacy code that uses temporary ownership to avoid
    //         // copies. Example:
    //         //   RepeatedPtrField<T> temp_field;
    //         //   temp_field.UnsafeArenaAddAllocated(new T);
    //         //   ... // Do something with temp_field
    //         //   temp_field.UnsafeArenaExtractSubrange(0, temp_field.size(), nullptr);
    //         // If you put temp_field on the arena this fails, because the ownership
    //         // transfers to the arena at the "AddAllocated" call and is not released
    //         // anymore, causing a double delete. UnsafeArenaAddAllocated prevents this.
    //         void UnsafeArenaAddAllocated( Element* value );

    //         // Removes and returns the last element.  Unlike ReleaseLast, the returned
    //         // pointer is always to the original object.  This may be in an arena, in
    //         // which case it would have the arena's lifetime.
    //         // Requires: current_size_ > 0
    //         Element* UnsafeArenaReleaseLast();

    //         // Extracts elements with indices in the range "[start .. start+num-1]".
    //         // The caller assumes ownership of the extracted elements and is responsible
    //         // for deleting them when they are no longer needed.
    //         // If "elements" is non-nullptr, then pointers to the extracted elements
    //         // are stored in "elements[0 .. num-1]" for the convenience of the caller.
    //         // If "elements" is nullptr, then the caller must use some other mechanism
    //         // to perform any further operations (like deletion) on these elements.
    //         // Caution: implementation also moves elements with indices [start+num ..].
    //         // Calling this routine inside a loop can cause quadratic behavior.
    //         //
    //         // Memory copying behavior is identical to ReleaseLast(), described above: if
    //         // this RepeatedPtrField is on an arena, an object copy is performed for each
    //         // returned element, so that all returned element pointers are to
    //         // heap-allocated copies. If this copy is not desired, the user should call
    //         // UnsafeArenaExtractSubrange().
    //         void ExtractSubrange( int start, int num, Element** elements );

    //         // Identical to ExtractSubrange() described above, except that no object
    //         // copies are ever performed. Instead, the raw object pointers are returned.
    //         // Thus, if on an arena, the returned objects must not be freed, because they
    //         // will not be heap-allocated objects.
    //         void UnsafeArenaExtractSubrange( int start, int num, Element** elements );

    //         // When elements are removed by calls to RemoveLast() or Clear(), they
    //         // are not actually freed.  Instead, they are cleared and kept so that
    //         // they can be reused later.  This can save lots of CPU time when
    //         // repeatedly reusing a protocol message for similar purposes.
    //         //
    //         // Hardcore programs may choose to manipulate these cleared objects
    //         // to better optimize memory management using the following routines.

    //         // Gets the number of cleared objects that are currently being kept
    //         // around for reuse.
    //         int ClearedCount() const;
    // #ifndef PROTOBUF_FUTURE_BREAKING_CHANGES
    //         // Adds an element to the pool of cleared objects, passing ownership to
    //         // the RepeatedPtrField.  The element must be cleared prior to calling
    //         // this method.
    //         //
    //         // This method cannot be called when either the repeated field or |value| is
    //         // on an arena; both cases will trigger a GOOGLE_DCHECK-failure.
    //         void AddCleared( Element* value );
    //         // Removes and returns a single element from the cleared pool, passing
    //         // ownership to the caller.  The element is guaranteed to be cleared.
    //         // Requires:  ClearedCount() > 0
    //         //
    //         // This method cannot be called when the repeated field is on an arena; doing
    //         // so will trigger a GOOGLE_DCHECK-failure.
    //         PROTOBUF_NODISCARD Element* ReleaseCleared();
    // #endif  // !PROTOBUF_FUTURE_BREAKING_CHANGES

    //         // Removes the element referenced by position.
    //         //
    //         // Returns an iterator to the element immediately following the removed
    //         // element.
    //         //
    //         // Invalidates all iterators at or after the removed element, including end().
    //         iterator erase( const_iterator position );

    //         // Removes the elements in the range [first, last).
    //         //
    //         // Returns an iterator to the element immediately following the removed range.
    //         //
    //         // Invalidates all iterators at or after the removed range, including end().
    //         iterator erase( const_iterator first, const_iterator last );

    //         // Gets the arena on which this RepeatedPtrField stores its elements.
    //         inline Arena* GetArena() const;

    //         // For internal use only.
    //         //
    //         // This is public due to it being called by generated code.
    //         void InternalSwap( RepeatedPtrField* other )
    //         {
    //             internal::RepeatedPtrFieldBase::InternalSwap( other );
    //         }

};

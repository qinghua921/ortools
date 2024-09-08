// RepeatedField is used to represent repeated fields of a primitive type (in
// other words, everything except strings and nested Messages).  Most users will
// not ever use a RepeatedField directly; they will use the get-by-index,
// set-by-index, and add accessors that are generated for all repeated fields.

export class RepeatedField_Int64 extends RepeatedField<number> { };

class RepeatedField<Element>
{
    //   static_assert(
    //       alignof(Arena) >= alignof(Element),
    //       "We only support types that have an alignment smaller than Arena");

    //  public:
    //   constexpr RepeatedField();
    //   explicit RepeatedField(Arena* arena);

    //   RepeatedField(const RepeatedField& other);

    //   template <typename Iter,
    //             typename = typename std::enable_if<std::is_constructible<
    //                 Element, decltype(*std::declval<Iter>())>::value>::type>
    //   RepeatedField(Iter begin, Iter end);

    //   ~RepeatedField();

    //   RepeatedField& operator=(const RepeatedField& other);

    //   RepeatedField(RepeatedField&& other) noexcept;
    //   RepeatedField& operator=(RepeatedField&& other) noexcept;

    //   bool empty() const;
    //   int size() const;
    size(): number;

    //   const Element& Get(int index) const;
    //   Element* Mutable(int index);

    //   const Element& operator[](int index) const { return Get(index); }
    operator_get(index: number): Element;

    //   Element& operator[](int index) { return *Mutable(index); }

    //   const Element& at(int index) const;
    //   Element& at(int index);

    //   void Set(int index, const Element& value);
    //   void Add(const Element& value);
    //   // Appends a new element and returns a pointer to it.
    //   // The new element is uninitialized if |Element| is a POD type.
    //   Element* Add();
    //   // Appends elements in the range [begin, end) after reserving
    //   // the appropriate number of elements.
    //   template <typename Iter>
    //   void Add(Iter begin, Iter end);

    //   // Removes the last element in the array.
    //   void RemoveLast();

    //   // Extracts elements with indices in "[start .. start+num-1]".
    //   // Copies them into "elements[0 .. num-1]" if "elements" is not nullptr.
    //   // Caution: also moves elements with indices [start+num ..].
    //   // Calling this routine inside a loop can cause quadratic behavior.
    //   void ExtractSubrange(int start, int num, Element* elements);

    //   PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear();
    //   void MergeFrom(const RepeatedField& other);
    //   PROTOBUF_ATTRIBUTE_REINITIALIZES void CopyFrom(const RepeatedField& other);

    //   // Replaces the contents with RepeatedField(begin, end).
    //   template <typename Iter>
    //   PROTOBUF_ATTRIBUTE_REINITIALIZES void Assign(Iter begin, Iter end);

    //   // Reserves space to expand the field to at least the given size.  If the
    //   // array is grown, it will always be at least doubled in size.
    //   void Reserve(int new_size);

    //   // Resizes the RepeatedField to a new, smaller size.  This is O(1).
    //   void Truncate(int new_size);

    //   void AddAlreadyReserved(const Element& value);
    //   // Appends a new element and return a pointer to it.
    //   // The new element is uninitialized if |Element| is a POD type.
    //   // Should be called only if Capacity() > Size().
    //   Element* AddAlreadyReserved();
    //   Element* AddNAlreadyReserved(int elements);
    //   int Capacity() const;

    //   // Like STL resize.  Uses value to fill appended elements.
    //   // Like Truncate() if new_size <= size(), otherwise this is
    //   // O(new_size - size()).
    //   void Resize(int new_size, const Element& value);

    //   // Gets the underlying array.  This pointer is possibly invalidated by
    //   // any add or remove operation.
    //   Element* mutable_data();
    //   const Element* data() const;

    //   // Swaps entire contents with "other". If they are separate arenas then,
    //   // copies data between each other.
    //   void Swap(RepeatedField* other);

    //   // Swaps entire contents with "other". Should be called only if the caller can
    //   // guarantee that both repeated fields are on the same arena or are on the
    //   // heap. Swapping between different arenas is disallowed and caught by a
    //   // GOOGLE_DCHECK (see API docs for details).
    //   void UnsafeArenaSwap(RepeatedField* other);

    //   // Swaps two elements.
    //   void SwapElements(int index1, int index2);

    //   // STL-like iterator support
    //   typedef internal::RepeatedIterator<Element> iterator;
    //   typedef internal::RepeatedIterator<const Element> const_iterator;
    //   typedef Element value_type;
    //   typedef value_type& reference;
    //   typedef const value_type& const_reference;
    //   typedef value_type* pointer;
    //   typedef const value_type* const_pointer;
    //   typedef int size_type;
    //   typedef ptrdiff_t difference_type;

    //   iterator begin();
    //   const_iterator begin() const;
    //   const_iterator cbegin() const;
    //   iterator end();
    //   const_iterator end() const;
    //   const_iterator cend() const;

    //   // Reverse iterator support
    //   typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    //   typedef std::reverse_iterator<iterator> reverse_iterator;
    //   reverse_iterator rbegin() { return reverse_iterator(end()); }
    //   const_reverse_iterator rbegin() const {
    //     return const_reverse_iterator(end());
    //   }
    //   reverse_iterator rend() { return reverse_iterator(begin()); }
    //   const_reverse_iterator rend() const {
    //     return const_reverse_iterator(begin());
    //   }

    //   // Returns the number of bytes used by the repeated field, excluding
    //   // sizeof(*this)
    //   size_t SpaceUsedExcludingSelfLong() const;

    //   int SpaceUsedExcludingSelf() const {
    //     return internal::ToIntSize(SpaceUsedExcludingSelfLong());
    //   }

    //   // Removes the element referenced by position.
    //   //
    //   // Returns an iterator to the element immediately following the removed
    //   // element.
    //   //
    //   // Invalidates all iterators at or after the removed element, including end().
    //   iterator erase(const_iterator position);

    //   // Removes the elements in the range [first, last).
    //   //
    //   // Returns an iterator to the element immediately following the removed range.
    //   //
    //   // Invalidates all iterators at or after the removed range, including end().
    //   iterator erase(const_iterator first, const_iterator last);

    //   // Gets the Arena on which this RepeatedField stores its elements.
    //   inline Arena* GetArena() const {
    //     return GetOwningArena();
    //   }

    //   // For internal use only.
    //   //
    //   // This is public due to it being called by generated code.
    //   inline void InternalSwap(RepeatedField* other);

    //  private:
    //   template <typename T> friend class Arena::InternalHelper;

    //   // Gets the Arena on which this RepeatedField stores its elements.
    //   inline Arena* GetOwningArena() const {
    //     return (total_size_ == 0) ? static_cast<Arena*>(arena_or_elements_)
    //                               : rep()->arena;
    //   }

    //   static constexpr int kInitialSize = 0;
    //   // A note on the representation here (see also comment below for
    //   // RepeatedPtrFieldBase's struct Rep):
    //   //
    //   // We maintain the same sizeof(RepeatedField) as before we added arena support
    //   // so that we do not degrade performance by bloating memory usage. Directly
    //   // adding an arena_ element to RepeatedField is quite costly. By using
    //   // indirection in this way, we keep the same size when the RepeatedField is
    //   // empty (common case), and add only an 8-byte header to the elements array
    //   // when non-empty. We make sure to place the size fields directly in the
    //   // RepeatedField class to avoid costly cache misses due to the indirection.
    //   int current_size_;
    //   int total_size_;
    //   // Pad the Rep after arena allow for power-of-two byte sizes when
    //   // sizeof(Element) > sizeof(Arena*). eg for 16-byte objects.
    //   static PROTOBUF_CONSTEXPR const size_t kRepHeaderSize =
    //       sizeof(Arena*) < sizeof(Element) ? sizeof(Element) : sizeof(Arena*);
    //   struct Rep {
    //     Arena* arena;
    //     Element* elements() {
    //       return reinterpret_cast<Element*>(reinterpret_cast<char*>(this) +
    //                                         kRepHeaderSize);
    //     }
    //   };

    //   // If total_size_ == 0 this points to an Arena otherwise it points to the
    //   // elements member of a Rep struct. Using this invariant allows the storage of
    //   // the arena pointer without an extra allocation in the constructor.
    //   void* arena_or_elements_;

    //   // Returns a pointer to elements array.
    //   // pre-condition: the array must have been allocated.
    //   Element* elements() const {
    //     GOOGLE_DCHECK_GT(total_size_, 0);
    //     // Because of above pre-condition this cast is safe.
    //     return unsafe_elements();
    //   }

    //   // Returns a pointer to elements array if it exists; otherwise either null or
    //   // an invalid pointer is returned. This only happens for empty repeated
    //   // fields, where you can't dereference this pointer anyway (it's empty).
    //   Element* unsafe_elements() const {
    //     return static_cast<Element*>(arena_or_elements_);
    //   }

    //   // Returns a pointer to the Rep struct.
    //   // pre-condition: the Rep must have been allocated, ie elements() is safe.
    //   Rep* rep() const {
    //     return reinterpret_cast<Rep*>(reinterpret_cast<char*>(elements()) -
    //                                   kRepHeaderSize);
    //   }

    //   friend class Arena;
    //   typedef void InternalArenaConstructable_;

    //   // Moves the contents of |from| into |to|, possibly clobbering |from| in the
    //   // process.  For primitive types this is just a memcpy(), but it could be
    //   // specialized for non-primitive types to, say, swap each element instead.
    //   void MoveArray(Element* to, Element* from, int size);

    //   // Copies the elements of |from| into |to|.
    //   void CopyArray(Element* to, const Element* from, int size);

    //   // Internal helper to delete all elements and deallocate the storage.
    //   void InternalDeallocate(Rep* rep, int size, bool in_destructor) {
    //     if (rep != nullptr) {
    //       Element* e = &rep->elements()[0];
    //       if (!std::is_trivial<Element>::value) {
    //         Element* limit = &rep->elements()[size];
    //         for (; e < limit; e++) {
    //           e->~Element();
    //         }
    //       }
    //       const size_t bytes = size * sizeof(*e) + kRepHeaderSize;
    //       if (rep->arena == nullptr) {
    //         internal::SizedDelete(rep, bytes);
    //       } else if (!in_destructor) {
    //         // If we are in the destructor, we might be being destroyed as part of
    //         // the arena teardown. We can't try and return blocks to the arena then.
    //         rep->arena->ReturnArrayMemory(rep, bytes);
    //       }
    //     }
    //   }

    //   // This class is a performance wrapper around RepeatedField::Add(const T&)
    //   // function. In general unless a RepeatedField is a local stack variable LLVM
    //   // has a hard time optimizing Add. The machine code tends to be
    //   // loop:
    //   // mov %size, dword ptr [%repeated_field]       // load
    //   // cmp %size, dword ptr [%repeated_field + 4]
    //   // jae fallback
    //   // mov %buffer, qword ptr [%repeated_field + 8]
    //   // mov dword [%buffer + %size * 4], %value
    //   // inc %size                                    // increment
    //   // mov dword ptr [%repeated_field], %size       // store
    //   // jmp loop
    //   //
    //   // This puts a load/store in each iteration of the important loop variable
    //   // size. It's a pretty bad compile that happens even in simple cases, but
    //   // largely the presence of the fallback path disturbs the compilers mem-to-reg
    //   // analysis.
    //   //
    //   // This class takes ownership of a repeated field for the duration of its
    //   // lifetime. The repeated field should not be accessed during this time, ie.
    //   // only access through this class is allowed. This class should always be a
    //   // function local stack variable. Intended use
    //   //
    //   // void AddSequence(const int* begin, const int* end, RepeatedField<int>* out)
    //   // {
    //   //   RepeatedFieldAdder<int> adder(out);  // Take ownership of out
    //   //   for (auto it = begin; it != end; ++it) {
    //   //     adder.Add(*it);
    //   //   }
    //   // }
    //   //
    //   // Typically, due to the fact that adder is a local stack variable, the
    //   // compiler will be successful in mem-to-reg transformation and the machine
    //   // code will be loop: cmp %size, %capacity jae fallback mov dword ptr [%buffer
    //   // + %size * 4], %val inc %size jmp loop
    //   //
    //   // The first version executes at 7 cycles per iteration while the second
    //   // version executes at only 1 or 2 cycles.
    //   template <int = 0, bool = std::is_trivial<Element>::value>
    //   class FastAdderImpl {
    //    public:
    //     explicit FastAdderImpl(RepeatedField* rf) : repeated_field_(rf) {
    //       index_ = repeated_field_->current_size_;
    //       capacity_ = repeated_field_->total_size_;
    //       buffer_ = repeated_field_->unsafe_elements();
    //     }
    //     ~FastAdderImpl() { repeated_field_->current_size_ = index_; }

    //     void Add(Element val) {
    //       if (index_ == capacity_) {
    //         repeated_field_->current_size_ = index_;
    //         repeated_field_->Reserve(index_ + 1);
    //         capacity_ = repeated_field_->total_size_;
    //         buffer_ = repeated_field_->unsafe_elements();
    //       }
    //       buffer_[index_++] = val;
    //     }

    //    private:
    //     RepeatedField* repeated_field_;
    //     int index_;
    //     int capacity_;
    //     Element* buffer_;

    //     GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(FastAdderImpl);
    //   };

    //   // FastAdder is a wrapper for adding fields. The specialization above handles
    //   // POD types more efficiently than RepeatedField.
    //   template <int I>
    //   class FastAdderImpl<I, false> {
    //    public:
    //     explicit FastAdderImpl(RepeatedField* rf) : repeated_field_(rf) {}
    //     void Add(const Element& val) { repeated_field_->Add(val); }

    //    private:
    //     RepeatedField* repeated_field_;
    //     GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(FastAdderImpl);
    //   };

    //   using FastAdder = FastAdderImpl<>;

    //   friend class TestRepeatedFieldHelper;
    //   friend class ::google::protobuf::internal::ParseContext;
};

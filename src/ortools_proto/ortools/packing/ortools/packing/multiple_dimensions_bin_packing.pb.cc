// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ortools/packing/multiple_dimensions_bin_packing.proto

#include "ortools/packing/multiple_dimensions_bin_packing.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace operations_research {
namespace packing {
PROTOBUF_CONSTEXPR MultipleDimensionsBinPackingShape::MultipleDimensionsBinPackingShape(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.dimensions_)*/{}
  , /*decltype(_impl_._dimensions_cached_byte_size_)*/{0}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct MultipleDimensionsBinPackingShapeDefaultTypeInternal {
  PROTOBUF_CONSTEXPR MultipleDimensionsBinPackingShapeDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~MultipleDimensionsBinPackingShapeDefaultTypeInternal() {}
  union {
    MultipleDimensionsBinPackingShape _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 MultipleDimensionsBinPackingShapeDefaultTypeInternal _MultipleDimensionsBinPackingShape_default_instance_;
PROTOBUF_CONSTEXPR MultipleDimensionsBinPackingItem::MultipleDimensionsBinPackingItem(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.shapes_)*/{}
  , /*decltype(_impl_.value_)*/int64_t{0}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct MultipleDimensionsBinPackingItemDefaultTypeInternal {
  PROTOBUF_CONSTEXPR MultipleDimensionsBinPackingItemDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~MultipleDimensionsBinPackingItemDefaultTypeInternal() {}
  union {
    MultipleDimensionsBinPackingItem _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 MultipleDimensionsBinPackingItemDefaultTypeInternal _MultipleDimensionsBinPackingItem_default_instance_;
PROTOBUF_CONSTEXPR MultipleDimensionsBinPackingProblem::MultipleDimensionsBinPackingProblem(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.items_)*/{}
  , /*decltype(_impl_.box_shape_)*/nullptr
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct MultipleDimensionsBinPackingProblemDefaultTypeInternal {
  PROTOBUF_CONSTEXPR MultipleDimensionsBinPackingProblemDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~MultipleDimensionsBinPackingProblemDefaultTypeInternal() {}
  union {
    MultipleDimensionsBinPackingProblem _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 MultipleDimensionsBinPackingProblemDefaultTypeInternal _MultipleDimensionsBinPackingProblem_default_instance_;
}  // namespace packing
}  // namespace operations_research
static ::_pb::Metadata file_level_metadata_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto[3];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto = nullptr;

const uint32_t TableStruct_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::operations_research::packing::MultipleDimensionsBinPackingShape, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::operations_research::packing::MultipleDimensionsBinPackingShape, _impl_.dimensions_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::operations_research::packing::MultipleDimensionsBinPackingItem, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::operations_research::packing::MultipleDimensionsBinPackingItem, _impl_.shapes_),
  PROTOBUF_FIELD_OFFSET(::operations_research::packing::MultipleDimensionsBinPackingItem, _impl_.value_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::operations_research::packing::MultipleDimensionsBinPackingProblem, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::operations_research::packing::MultipleDimensionsBinPackingProblem, _impl_.box_shape_),
  PROTOBUF_FIELD_OFFSET(::operations_research::packing::MultipleDimensionsBinPackingProblem, _impl_.items_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::operations_research::packing::MultipleDimensionsBinPackingShape)},
  { 7, -1, -1, sizeof(::operations_research::packing::MultipleDimensionsBinPackingItem)},
  { 15, -1, -1, sizeof(::operations_research::packing::MultipleDimensionsBinPackingProblem)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::operations_research::packing::_MultipleDimensionsBinPackingShape_default_instance_._instance,
  &::operations_research::packing::_MultipleDimensionsBinPackingItem_default_instance_._instance,
  &::operations_research::packing::_MultipleDimensionsBinPackingProblem_default_instance_._instance,
};

const char descriptor_table_protodef_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n5ortools/packing/multiple_dimensions_bi"
  "n_packing.proto\022\033operations_research.pac"
  "king\"7\n!MultipleDimensionsBinPackingShap"
  "e\022\022\n\ndimensions\030\001 \003(\003\"\201\001\n MultipleDimens"
  "ionsBinPackingItem\022N\n\006shapes\030\001 \003(\0132>.ope"
  "rations_research.packing.MultipleDimensi"
  "onsBinPackingShape\022\r\n\005value\030\002 \001(\003\"\306\001\n#Mu"
  "ltipleDimensionsBinPackingProblem\022Q\n\tbox"
  "_shape\030\001 \001(\0132>.operations_research.packi"
  "ng.MultipleDimensionsBinPackingShape\022L\n\005"
  "items\030\002 \003(\0132=.operations_research.packin"
  "g.MultipleDimensionsBinPackingItemB\002P\001b\006"
  "proto3"
  ;
static ::_pbi::once_flag descriptor_table_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto = {
    false, false, 486, descriptor_table_protodef_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto,
    "ortools/packing/multiple_dimensions_bin_packing.proto",
    &descriptor_table_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto_once, nullptr, 0, 3,
    schemas, file_default_instances, TableStruct_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto::offsets,
    file_level_metadata_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto, file_level_enum_descriptors_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto,
    file_level_service_descriptors_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto_getter() {
  return &descriptor_table_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto(&descriptor_table_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto);
namespace operations_research {
namespace packing {

// ===================================================================

class MultipleDimensionsBinPackingShape::_Internal {
 public:
};

MultipleDimensionsBinPackingShape::MultipleDimensionsBinPackingShape(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:operations_research.packing.MultipleDimensionsBinPackingShape)
}
MultipleDimensionsBinPackingShape::MultipleDimensionsBinPackingShape(const MultipleDimensionsBinPackingShape& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  MultipleDimensionsBinPackingShape* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.dimensions_){from._impl_.dimensions_}
    , /*decltype(_impl_._dimensions_cached_byte_size_)*/{0}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:operations_research.packing.MultipleDimensionsBinPackingShape)
}

inline void MultipleDimensionsBinPackingShape::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.dimensions_){arena}
    , /*decltype(_impl_._dimensions_cached_byte_size_)*/{0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

MultipleDimensionsBinPackingShape::~MultipleDimensionsBinPackingShape() {
  // @@protoc_insertion_point(destructor:operations_research.packing.MultipleDimensionsBinPackingShape)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void MultipleDimensionsBinPackingShape::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.dimensions_.~RepeatedField();
}

void MultipleDimensionsBinPackingShape::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void MultipleDimensionsBinPackingShape::Clear() {
// @@protoc_insertion_point(message_clear_start:operations_research.packing.MultipleDimensionsBinPackingShape)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.dimensions_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* MultipleDimensionsBinPackingShape::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // repeated int64 dimensions = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedInt64Parser(_internal_mutable_dimensions(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<uint8_t>(tag) == 8) {
          _internal_add_dimensions(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* MultipleDimensionsBinPackingShape::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:operations_research.packing.MultipleDimensionsBinPackingShape)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated int64 dimensions = 1;
  {
    int byte_size = _impl_._dimensions_cached_byte_size_.load(std::memory_order_relaxed);
    if (byte_size > 0) {
      target = stream->WriteInt64Packed(
          1, _internal_dimensions(), byte_size, target);
    }
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:operations_research.packing.MultipleDimensionsBinPackingShape)
  return target;
}

size_t MultipleDimensionsBinPackingShape::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:operations_research.packing.MultipleDimensionsBinPackingShape)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated int64 dimensions = 1;
  {
    size_t data_size = ::_pbi::WireFormatLite::
      Int64Size(this->_impl_.dimensions_);
    if (data_size > 0) {
      total_size += 1 +
        ::_pbi::WireFormatLite::Int32Size(static_cast<int32_t>(data_size));
    }
    int cached_size = ::_pbi::ToCachedSize(data_size);
    _impl_._dimensions_cached_byte_size_.store(cached_size,
                                    std::memory_order_relaxed);
    total_size += data_size;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData MultipleDimensionsBinPackingShape::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    MultipleDimensionsBinPackingShape::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*MultipleDimensionsBinPackingShape::GetClassData() const { return &_class_data_; }


void MultipleDimensionsBinPackingShape::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<MultipleDimensionsBinPackingShape*>(&to_msg);
  auto& from = static_cast<const MultipleDimensionsBinPackingShape&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:operations_research.packing.MultipleDimensionsBinPackingShape)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.dimensions_.MergeFrom(from._impl_.dimensions_);
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void MultipleDimensionsBinPackingShape::CopyFrom(const MultipleDimensionsBinPackingShape& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:operations_research.packing.MultipleDimensionsBinPackingShape)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MultipleDimensionsBinPackingShape::IsInitialized() const {
  return true;
}

void MultipleDimensionsBinPackingShape::InternalSwap(MultipleDimensionsBinPackingShape* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.dimensions_.InternalSwap(&other->_impl_.dimensions_);
}

::PROTOBUF_NAMESPACE_ID::Metadata MultipleDimensionsBinPackingShape::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto_getter, &descriptor_table_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto_once,
      file_level_metadata_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto[0]);
}

// ===================================================================

class MultipleDimensionsBinPackingItem::_Internal {
 public:
};

MultipleDimensionsBinPackingItem::MultipleDimensionsBinPackingItem(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:operations_research.packing.MultipleDimensionsBinPackingItem)
}
MultipleDimensionsBinPackingItem::MultipleDimensionsBinPackingItem(const MultipleDimensionsBinPackingItem& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  MultipleDimensionsBinPackingItem* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.shapes_){from._impl_.shapes_}
    , decltype(_impl_.value_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _this->_impl_.value_ = from._impl_.value_;
  // @@protoc_insertion_point(copy_constructor:operations_research.packing.MultipleDimensionsBinPackingItem)
}

inline void MultipleDimensionsBinPackingItem::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.shapes_){arena}
    , decltype(_impl_.value_){int64_t{0}}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

MultipleDimensionsBinPackingItem::~MultipleDimensionsBinPackingItem() {
  // @@protoc_insertion_point(destructor:operations_research.packing.MultipleDimensionsBinPackingItem)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void MultipleDimensionsBinPackingItem::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.shapes_.~RepeatedPtrField();
}

void MultipleDimensionsBinPackingItem::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void MultipleDimensionsBinPackingItem::Clear() {
// @@protoc_insertion_point(message_clear_start:operations_research.packing.MultipleDimensionsBinPackingItem)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.shapes_.Clear();
  _impl_.value_ = int64_t{0};
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* MultipleDimensionsBinPackingItem::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // repeated .operations_research.packing.MultipleDimensionsBinPackingShape shapes = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_shapes(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else
          goto handle_unusual;
        continue;
      // int64 value = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _impl_.value_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* MultipleDimensionsBinPackingItem::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:operations_research.packing.MultipleDimensionsBinPackingItem)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .operations_research.packing.MultipleDimensionsBinPackingShape shapes = 1;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_shapes_size()); i < n; i++) {
    const auto& repfield = this->_internal_shapes(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(1, repfield, repfield.GetCachedSize(), target, stream);
  }

  // int64 value = 2;
  if (this->_internal_value() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt64ToArray(2, this->_internal_value(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:operations_research.packing.MultipleDimensionsBinPackingItem)
  return target;
}

size_t MultipleDimensionsBinPackingItem::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:operations_research.packing.MultipleDimensionsBinPackingItem)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .operations_research.packing.MultipleDimensionsBinPackingShape shapes = 1;
  total_size += 1UL * this->_internal_shapes_size();
  for (const auto& msg : this->_impl_.shapes_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // int64 value = 2;
  if (this->_internal_value() != 0) {
    total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(this->_internal_value());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData MultipleDimensionsBinPackingItem::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    MultipleDimensionsBinPackingItem::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*MultipleDimensionsBinPackingItem::GetClassData() const { return &_class_data_; }


void MultipleDimensionsBinPackingItem::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<MultipleDimensionsBinPackingItem*>(&to_msg);
  auto& from = static_cast<const MultipleDimensionsBinPackingItem&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:operations_research.packing.MultipleDimensionsBinPackingItem)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.shapes_.MergeFrom(from._impl_.shapes_);
  if (from._internal_value() != 0) {
    _this->_internal_set_value(from._internal_value());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void MultipleDimensionsBinPackingItem::CopyFrom(const MultipleDimensionsBinPackingItem& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:operations_research.packing.MultipleDimensionsBinPackingItem)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MultipleDimensionsBinPackingItem::IsInitialized() const {
  return true;
}

void MultipleDimensionsBinPackingItem::InternalSwap(MultipleDimensionsBinPackingItem* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.shapes_.InternalSwap(&other->_impl_.shapes_);
  swap(_impl_.value_, other->_impl_.value_);
}

::PROTOBUF_NAMESPACE_ID::Metadata MultipleDimensionsBinPackingItem::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto_getter, &descriptor_table_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto_once,
      file_level_metadata_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto[1]);
}

// ===================================================================

class MultipleDimensionsBinPackingProblem::_Internal {
 public:
  static const ::operations_research::packing::MultipleDimensionsBinPackingShape& box_shape(const MultipleDimensionsBinPackingProblem* msg);
};

const ::operations_research::packing::MultipleDimensionsBinPackingShape&
MultipleDimensionsBinPackingProblem::_Internal::box_shape(const MultipleDimensionsBinPackingProblem* msg) {
  return *msg->_impl_.box_shape_;
}
MultipleDimensionsBinPackingProblem::MultipleDimensionsBinPackingProblem(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:operations_research.packing.MultipleDimensionsBinPackingProblem)
}
MultipleDimensionsBinPackingProblem::MultipleDimensionsBinPackingProblem(const MultipleDimensionsBinPackingProblem& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  MultipleDimensionsBinPackingProblem* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.items_){from._impl_.items_}
    , decltype(_impl_.box_shape_){nullptr}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_box_shape()) {
    _this->_impl_.box_shape_ = new ::operations_research::packing::MultipleDimensionsBinPackingShape(*from._impl_.box_shape_);
  }
  // @@protoc_insertion_point(copy_constructor:operations_research.packing.MultipleDimensionsBinPackingProblem)
}

inline void MultipleDimensionsBinPackingProblem::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.items_){arena}
    , decltype(_impl_.box_shape_){nullptr}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

MultipleDimensionsBinPackingProblem::~MultipleDimensionsBinPackingProblem() {
  // @@protoc_insertion_point(destructor:operations_research.packing.MultipleDimensionsBinPackingProblem)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void MultipleDimensionsBinPackingProblem::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.items_.~RepeatedPtrField();
  if (this != internal_default_instance()) delete _impl_.box_shape_;
}

void MultipleDimensionsBinPackingProblem::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void MultipleDimensionsBinPackingProblem::Clear() {
// @@protoc_insertion_point(message_clear_start:operations_research.packing.MultipleDimensionsBinPackingProblem)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.items_.Clear();
  if (GetArenaForAllocation() == nullptr && _impl_.box_shape_ != nullptr) {
    delete _impl_.box_shape_;
  }
  _impl_.box_shape_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* MultipleDimensionsBinPackingProblem::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .operations_research.packing.MultipleDimensionsBinPackingShape box_shape = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_box_shape(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated .operations_research.packing.MultipleDimensionsBinPackingItem items = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_items(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* MultipleDimensionsBinPackingProblem::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:operations_research.packing.MultipleDimensionsBinPackingProblem)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .operations_research.packing.MultipleDimensionsBinPackingShape box_shape = 1;
  if (this->_internal_has_box_shape()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, _Internal::box_shape(this),
        _Internal::box_shape(this).GetCachedSize(), target, stream);
  }

  // repeated .operations_research.packing.MultipleDimensionsBinPackingItem items = 2;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_items_size()); i < n; i++) {
    const auto& repfield = this->_internal_items(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(2, repfield, repfield.GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:operations_research.packing.MultipleDimensionsBinPackingProblem)
  return target;
}

size_t MultipleDimensionsBinPackingProblem::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:operations_research.packing.MultipleDimensionsBinPackingProblem)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .operations_research.packing.MultipleDimensionsBinPackingItem items = 2;
  total_size += 1UL * this->_internal_items_size();
  for (const auto& msg : this->_impl_.items_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // .operations_research.packing.MultipleDimensionsBinPackingShape box_shape = 1;
  if (this->_internal_has_box_shape()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.box_shape_);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData MultipleDimensionsBinPackingProblem::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    MultipleDimensionsBinPackingProblem::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*MultipleDimensionsBinPackingProblem::GetClassData() const { return &_class_data_; }


void MultipleDimensionsBinPackingProblem::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<MultipleDimensionsBinPackingProblem*>(&to_msg);
  auto& from = static_cast<const MultipleDimensionsBinPackingProblem&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:operations_research.packing.MultipleDimensionsBinPackingProblem)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.items_.MergeFrom(from._impl_.items_);
  if (from._internal_has_box_shape()) {
    _this->_internal_mutable_box_shape()->::operations_research::packing::MultipleDimensionsBinPackingShape::MergeFrom(
        from._internal_box_shape());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void MultipleDimensionsBinPackingProblem::CopyFrom(const MultipleDimensionsBinPackingProblem& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:operations_research.packing.MultipleDimensionsBinPackingProblem)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MultipleDimensionsBinPackingProblem::IsInitialized() const {
  return true;
}

void MultipleDimensionsBinPackingProblem::InternalSwap(MultipleDimensionsBinPackingProblem* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.items_.InternalSwap(&other->_impl_.items_);
  swap(_impl_.box_shape_, other->_impl_.box_shape_);
}

::PROTOBUF_NAMESPACE_ID::Metadata MultipleDimensionsBinPackingProblem::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto_getter, &descriptor_table_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto_once,
      file_level_metadata_ortools_2fpacking_2fmultiple_5fdimensions_5fbin_5fpacking_2eproto[2]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace packing
}  // namespace operations_research
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::operations_research::packing::MultipleDimensionsBinPackingShape*
Arena::CreateMaybeMessage< ::operations_research::packing::MultipleDimensionsBinPackingShape >(Arena* arena) {
  return Arena::CreateMessageInternal< ::operations_research::packing::MultipleDimensionsBinPackingShape >(arena);
}
template<> PROTOBUF_NOINLINE ::operations_research::packing::MultipleDimensionsBinPackingItem*
Arena::CreateMaybeMessage< ::operations_research::packing::MultipleDimensionsBinPackingItem >(Arena* arena) {
  return Arena::CreateMessageInternal< ::operations_research::packing::MultipleDimensionsBinPackingItem >(arena);
}
template<> PROTOBUF_NOINLINE ::operations_research::packing::MultipleDimensionsBinPackingProblem*
Arena::CreateMaybeMessage< ::operations_research::packing::MultipleDimensionsBinPackingProblem >(Arena* arena) {
  return Arena::CreateMessageInternal< ::operations_research::packing::MultipleDimensionsBinPackingProblem >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>

// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ortools/sat/cp_model_service.proto

#include "ortools/sat/cp_model_service.pb.h"

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
namespace sat {
namespace v1 {
PROTOBUF_CONSTEXPR CpSolverRequest::CpSolverRequest(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.model_)*/nullptr
  , /*decltype(_impl_.parameters_)*/nullptr
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct CpSolverRequestDefaultTypeInternal {
  PROTOBUF_CONSTEXPR CpSolverRequestDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~CpSolverRequestDefaultTypeInternal() {}
  union {
    CpSolverRequest _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 CpSolverRequestDefaultTypeInternal _CpSolverRequest_default_instance_;
}  // namespace v1
}  // namespace sat
}  // namespace operations_research
static ::_pb::Metadata file_level_metadata_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto = nullptr;

const uint32_t TableStruct_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::operations_research::sat::v1::CpSolverRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::operations_research::sat::v1::CpSolverRequest, _impl_.model_),
  PROTOBUF_FIELD_OFFSET(::operations_research::sat::v1::CpSolverRequest, _impl_.parameters_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::operations_research::sat::v1::CpSolverRequest)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::operations_research::sat::v1::_CpSolverRequest_default_instance_._instance,
};

const char descriptor_table_protodef_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\"ortools/sat/cp_model_service.proto\022\032op"
  "erations_research.sat.v1\032\032ortools/sat/cp"
  "_model.proto\032 ortools/sat/sat_parameters"
  ".proto\"\211\001\n\017CpSolverRequest\0224\n\005model\030\001 \001("
  "\0132%.operations_research.sat.CpModelProto"
  "\022:\n\nparameters\030\003 \001(\0132&.operations_resear"
  "ch.sat.SatParametersJ\004\010\002\020\0032t\n\010CpSolver\022h"
  "\n\014SolveProblem\022+.operations_research.sat"
  ".v1.CpSolverRequest\032).operations_researc"
  "h.sat.CpSolverResponse\"\000BG\n\031com.google.o"
  "rtools.sat.v1B\023CpModelServiceProtoP\001\252\002\022G"
  "oogle.OrTools.Satb\006proto3"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto_deps[2] = {
  &::descriptor_table_ortools_2fsat_2fcp_5fmodel_2eproto,
  &::descriptor_table_ortools_2fsat_2fsat_5fparameters_2eproto,
};
static ::_pbi::once_flag descriptor_table_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto = {
    false, false, 465, descriptor_table_protodef_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto,
    "ortools/sat/cp_model_service.proto",
    &descriptor_table_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto_once, descriptor_table_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto_deps, 2, 1,
    schemas, file_default_instances, TableStruct_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto::offsets,
    file_level_metadata_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto, file_level_enum_descriptors_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto,
    file_level_service_descriptors_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto_getter() {
  return &descriptor_table_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto(&descriptor_table_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto);
namespace operations_research {
namespace sat {
namespace v1 {

// ===================================================================

class CpSolverRequest::_Internal {
 public:
  static const ::operations_research::sat::CpModelProto& model(const CpSolverRequest* msg);
  static const ::operations_research::sat::SatParameters& parameters(const CpSolverRequest* msg);
};

const ::operations_research::sat::CpModelProto&
CpSolverRequest::_Internal::model(const CpSolverRequest* msg) {
  return *msg->_impl_.model_;
}
const ::operations_research::sat::SatParameters&
CpSolverRequest::_Internal::parameters(const CpSolverRequest* msg) {
  return *msg->_impl_.parameters_;
}
void CpSolverRequest::clear_model() {
  if (GetArenaForAllocation() == nullptr && _impl_.model_ != nullptr) {
    delete _impl_.model_;
  }
  _impl_.model_ = nullptr;
}
void CpSolverRequest::clear_parameters() {
  if (GetArenaForAllocation() == nullptr && _impl_.parameters_ != nullptr) {
    delete _impl_.parameters_;
  }
  _impl_.parameters_ = nullptr;
}
CpSolverRequest::CpSolverRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:operations_research.sat.v1.CpSolverRequest)
}
CpSolverRequest::CpSolverRequest(const CpSolverRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  CpSolverRequest* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.model_){nullptr}
    , decltype(_impl_.parameters_){nullptr}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_model()) {
    _this->_impl_.model_ = new ::operations_research::sat::CpModelProto(*from._impl_.model_);
  }
  if (from._internal_has_parameters()) {
    _this->_impl_.parameters_ = new ::operations_research::sat::SatParameters(*from._impl_.parameters_);
  }
  // @@protoc_insertion_point(copy_constructor:operations_research.sat.v1.CpSolverRequest)
}

inline void CpSolverRequest::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.model_){nullptr}
    , decltype(_impl_.parameters_){nullptr}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

CpSolverRequest::~CpSolverRequest() {
  // @@protoc_insertion_point(destructor:operations_research.sat.v1.CpSolverRequest)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void CpSolverRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete _impl_.model_;
  if (this != internal_default_instance()) delete _impl_.parameters_;
}

void CpSolverRequest::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void CpSolverRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:operations_research.sat.v1.CpSolverRequest)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaForAllocation() == nullptr && _impl_.model_ != nullptr) {
    delete _impl_.model_;
  }
  _impl_.model_ = nullptr;
  if (GetArenaForAllocation() == nullptr && _impl_.parameters_ != nullptr) {
    delete _impl_.parameters_;
  }
  _impl_.parameters_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* CpSolverRequest::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .operations_research.sat.CpModelProto model = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_model(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .operations_research.sat.SatParameters parameters = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          ptr = ctx->ParseMessage(_internal_mutable_parameters(), ptr);
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

uint8_t* CpSolverRequest::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:operations_research.sat.v1.CpSolverRequest)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .operations_research.sat.CpModelProto model = 1;
  if (this->_internal_has_model()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, _Internal::model(this),
        _Internal::model(this).GetCachedSize(), target, stream);
  }

  // .operations_research.sat.SatParameters parameters = 3;
  if (this->_internal_has_parameters()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(3, _Internal::parameters(this),
        _Internal::parameters(this).GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:operations_research.sat.v1.CpSolverRequest)
  return target;
}

size_t CpSolverRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:operations_research.sat.v1.CpSolverRequest)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .operations_research.sat.CpModelProto model = 1;
  if (this->_internal_has_model()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.model_);
  }

  // .operations_research.sat.SatParameters parameters = 3;
  if (this->_internal_has_parameters()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.parameters_);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData CpSolverRequest::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    CpSolverRequest::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*CpSolverRequest::GetClassData() const { return &_class_data_; }


void CpSolverRequest::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<CpSolverRequest*>(&to_msg);
  auto& from = static_cast<const CpSolverRequest&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:operations_research.sat.v1.CpSolverRequest)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_model()) {
    _this->_internal_mutable_model()->::operations_research::sat::CpModelProto::MergeFrom(
        from._internal_model());
  }
  if (from._internal_has_parameters()) {
    _this->_internal_mutable_parameters()->::operations_research::sat::SatParameters::MergeFrom(
        from._internal_parameters());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void CpSolverRequest::CopyFrom(const CpSolverRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:operations_research.sat.v1.CpSolverRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CpSolverRequest::IsInitialized() const {
  return true;
}

void CpSolverRequest::InternalSwap(CpSolverRequest* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(CpSolverRequest, _impl_.parameters_)
      + sizeof(CpSolverRequest::_impl_.parameters_)
      - PROTOBUF_FIELD_OFFSET(CpSolverRequest, _impl_.model_)>(
          reinterpret_cast<char*>(&_impl_.model_),
          reinterpret_cast<char*>(&other->_impl_.model_));
}

::PROTOBUF_NAMESPACE_ID::Metadata CpSolverRequest::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto_getter, &descriptor_table_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto_once,
      file_level_metadata_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace v1
}  // namespace sat
}  // namespace operations_research
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::operations_research::sat::v1::CpSolverRequest*
Arena::CreateMaybeMessage< ::operations_research::sat::v1::CpSolverRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::operations_research::sat::v1::CpSolverRequest >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
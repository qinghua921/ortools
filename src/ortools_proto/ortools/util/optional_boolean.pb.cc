// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ortools/util/optional_boolean.proto

#include "ortools/util/optional_boolean.pb.h"

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
}  // namespace operations_research
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_ortools_2futil_2foptional_5fboolean_2eproto[1];
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_ortools_2futil_2foptional_5fboolean_2eproto = nullptr;
const uint32_t TableStruct_ortools_2futil_2foptional_5fboolean_2eproto::offsets[1] = {};
static constexpr ::_pbi::MigrationSchema* schemas = nullptr;
static constexpr ::_pb::Message* const* file_default_instances = nullptr;

const char descriptor_table_protodef_ortools_2futil_2foptional_5fboolean_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n#ortools/util/optional_boolean.proto\022\023o"
  "perations_research*F\n\017OptionalBoolean\022\024\n"
  "\020BOOL_UNSPECIFIED\020\000\022\016\n\nBOOL_FALSE\020\002\022\r\n\tB"
  "OOL_TRUE\020\003B1\n\027com.google.ortools.utilP\001\252"
  "\002\023Google.OrTools.Utilb\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_ortools_2futil_2foptional_5fboolean_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_ortools_2futil_2foptional_5fboolean_2eproto = {
    false, false, 189, descriptor_table_protodef_ortools_2futil_2foptional_5fboolean_2eproto,
    "ortools/util/optional_boolean.proto",
    &descriptor_table_ortools_2futil_2foptional_5fboolean_2eproto_once, nullptr, 0, 0,
    schemas, file_default_instances, TableStruct_ortools_2futil_2foptional_5fboolean_2eproto::offsets,
    nullptr, file_level_enum_descriptors_ortools_2futil_2foptional_5fboolean_2eproto,
    file_level_service_descriptors_ortools_2futil_2foptional_5fboolean_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_ortools_2futil_2foptional_5fboolean_2eproto_getter() {
  return &descriptor_table_ortools_2futil_2foptional_5fboolean_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_ortools_2futil_2foptional_5fboolean_2eproto(&descriptor_table_ortools_2futil_2foptional_5fboolean_2eproto);
namespace operations_research {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* OptionalBoolean_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_ortools_2futil_2foptional_5fboolean_2eproto);
  return file_level_enum_descriptors_ortools_2futil_2foptional_5fboolean_2eproto[0];
}
bool OptionalBoolean_IsValid(int value) {
  switch (value) {
    case 0:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace operations_research
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Enum.proto

#include "Enum.pb.h"

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
namespace Protocol {
}  // namespace Protocol
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_Enum_2eproto[5];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_Enum_2eproto = nullptr;
const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_Enum_2eproto::offsets[1] = {};
static constexpr ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema* schemas = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::Message* const* file_default_instances = nullptr;

const char descriptor_table_protodef_Enum_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\nEnum.proto\022\010Protocol*k\n\013EObjectType\022\024\n"
  "\020OBJECT_TYPE_NONE\020\000\022\025\n\021OBJECT_TYPE_ACTOR"
  "\020\001\022\032\n\026OBJECT_TYPE_PROJECTILE\020\002\022\023\n\017OBJECT"
  "_TYPE_ENV\020\003*8\n\nEActorType\022\010\n\004None\020\000\022\n\n\006P"
  "layer\020\001\022\013\n\007Monster\020\002\022\007\n\003Npc\020\003*P\n\010EBagTyp"
  "e\022\017\n\013BagTypeNone\020\000\022\r\n\tEquipment\020\001\022\007\n\003Etc"
  "\020\002\022\013\n\007Useable\020\003\022\016\n\nBagTypeMax\020\004*i\n\013EPlay"
  "erType\022\024\n\020PLAYER_TYPE_NONE\020\000\022\026\n\022PLAYER_T"
  "YPE_KNIGHT\020\001\022\024\n\020PLAYER_TYPE_MAGE\020\002\022\026\n\022PL"
  "AYER_TYPE_ARCHER\020\003*u\n\nEMoveState\022\023\n\017MOVE"
  "_STATE_NONE\020\000\022\023\n\017MOVE_STATE_IDLE\020\001\022\022\n\016MO"
  "VE_STATE_RUN\020\002\022\023\n\017MOVE_STATE_JUMP\020\003\022\024\n\020M"
  "OVE_STATE_SKILL\020\004b\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_Enum_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Enum_2eproto = {
  false, false, 505, descriptor_table_protodef_Enum_2eproto, "Enum.proto", 
  &descriptor_table_Enum_2eproto_once, nullptr, 0, 0,
  schemas, file_default_instances, TableStruct_Enum_2eproto::offsets,
  nullptr, file_level_enum_descriptors_Enum_2eproto, file_level_service_descriptors_Enum_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_Enum_2eproto_getter() {
  return &descriptor_table_Enum_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_Enum_2eproto(&descriptor_table_Enum_2eproto);
namespace Protocol {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* EObjectType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_Enum_2eproto);
  return file_level_enum_descriptors_Enum_2eproto[0];
}
bool EObjectType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* EActorType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_Enum_2eproto);
  return file_level_enum_descriptors_Enum_2eproto[1];
}
bool EActorType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* EBagType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_Enum_2eproto);
  return file_level_enum_descriptors_Enum_2eproto[2];
}
bool EBagType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* EPlayerType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_Enum_2eproto);
  return file_level_enum_descriptors_Enum_2eproto[3];
}
bool EPlayerType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* EMoveState_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_Enum_2eproto);
  return file_level_enum_descriptors_Enum_2eproto[4];
}
bool EMoveState_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>

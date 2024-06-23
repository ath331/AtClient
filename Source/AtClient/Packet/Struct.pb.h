// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Struct.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Struct_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Struct_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3017000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3017001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "Enum.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Struct_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Struct_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Struct_2eproto;
namespace Protocol {
class PlayerInfo;
struct PlayerInfoDefaultTypeInternal;
extern PlayerInfoDefaultTypeInternal _PlayerInfo_default_instance_;
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
template<> ::Protocol::PlayerInfo* Arena::CreateMaybeMessage<::Protocol::PlayerInfo>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Protocol {

// ===================================================================

class PlayerInfo final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Protocol.PlayerInfo) */ {
 public:
  inline PlayerInfo() : PlayerInfo(nullptr) {}
  ~PlayerInfo() override;
  explicit constexpr PlayerInfo(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  PlayerInfo(const PlayerInfo& from);
  PlayerInfo(PlayerInfo&& from) noexcept
    : PlayerInfo() {
    *this = ::std::move(from);
  }

  inline PlayerInfo& operator=(const PlayerInfo& from) {
    CopyFrom(from);
    return *this;
  }
  inline PlayerInfo& operator=(PlayerInfo&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const PlayerInfo& default_instance() {
    return *internal_default_instance();
  }
  static inline const PlayerInfo* internal_default_instance() {
    return reinterpret_cast<const PlayerInfo*>(
               &_PlayerInfo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(PlayerInfo& a, PlayerInfo& b) {
    a.Swap(&b);
  }
  inline void Swap(PlayerInfo* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PlayerInfo* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline PlayerInfo* New() const final {
    return new PlayerInfo();
  }

  PlayerInfo* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<PlayerInfo>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const PlayerInfo& from);
  void MergeFrom(const PlayerInfo& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PlayerInfo* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Protocol.PlayerInfo";
  }
  protected:
  explicit PlayerInfo(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 2,
    kIdFieldNumber = 1,
    kPlayerTypeFieldNumber = 3,
    kXFieldNumber = 4,
    kYFieldNumber = 5,
    kZFieldNumber = 6,
    kYawFieldNumber = 7,
    kMoveStateFieldNumber = 8,
  };
  // string name = 2;
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_FUTURE_MUST_USE_RESULT std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // uint64 id = 1;
  void clear_id();
  ::PROTOBUF_NAMESPACE_ID::uint64 id() const;
  void set_id(::PROTOBUF_NAMESPACE_ID::uint64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint64 _internal_id() const;
  void _internal_set_id(::PROTOBUF_NAMESPACE_ID::uint64 value);
  public:

  // .Protocol.PlayerType playerType = 3;
  void clear_playertype();
  ::Protocol::PlayerType playertype() const;
  void set_playertype(::Protocol::PlayerType value);
  private:
  ::Protocol::PlayerType _internal_playertype() const;
  void _internal_set_playertype(::Protocol::PlayerType value);
  public:

  // float x = 4;
  void clear_x();
  float x() const;
  void set_x(float value);
  private:
  float _internal_x() const;
  void _internal_set_x(float value);
  public:

  // float y = 5;
  void clear_y();
  float y() const;
  void set_y(float value);
  private:
  float _internal_y() const;
  void _internal_set_y(float value);
  public:

  // float z = 6;
  void clear_z();
  float z() const;
  void set_z(float value);
  private:
  float _internal_z() const;
  void _internal_set_z(float value);
  public:

  // float yaw = 7;
  void clear_yaw();
  float yaw() const;
  void set_yaw(float value);
  private:
  float _internal_yaw() const;
  void _internal_set_yaw(float value);
  public:

  // .Protocol.MoveState moveState = 8;
  void clear_movestate();
  ::Protocol::MoveState movestate() const;
  void set_movestate(::Protocol::MoveState value);
  private:
  ::Protocol::MoveState _internal_movestate() const;
  void _internal_set_movestate(::Protocol::MoveState value);
  public:

  // @@protoc_insertion_point(class_scope:Protocol.PlayerInfo)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::PROTOBUF_NAMESPACE_ID::uint64 id_;
  int playertype_;
  float x_;
  float y_;
  float z_;
  float yaw_;
  int movestate_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Struct_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PlayerInfo

// uint64 id = 1;
inline void PlayerInfo::clear_id() {
  id_ = uint64_t{0u};
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 PlayerInfo::_internal_id() const {
  return id_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 PlayerInfo::id() const {
  // @@protoc_insertion_point(field_get:Protocol.PlayerInfo.id)
  return _internal_id();
}
inline void PlayerInfo::_internal_set_id(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  
  id_ = value;
}
inline void PlayerInfo::set_id(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:Protocol.PlayerInfo.id)
}

// string name = 2;
inline void PlayerInfo::clear_name() {
  name_.ClearToEmpty();
}
inline const std::string& PlayerInfo::name() const {
  // @@protoc_insertion_point(field_get:Protocol.PlayerInfo.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void PlayerInfo::set_name(ArgT0&& arg0, ArgT... args) {
 
 name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Protocol.PlayerInfo.name)
}
inline std::string* PlayerInfo::mutable_name() {
  // @@protoc_insertion_point(field_mutable:Protocol.PlayerInfo.name)
  return _internal_mutable_name();
}
inline const std::string& PlayerInfo::_internal_name() const {
  return name_.Get();
}
inline void PlayerInfo::_internal_set_name(const std::string& value) {
  
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* PlayerInfo::_internal_mutable_name() {
  
  return name_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* PlayerInfo::release_name() {
  // @@protoc_insertion_point(field_release:Protocol.PlayerInfo.name)
  return name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void PlayerInfo::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:Protocol.PlayerInfo.name)
}

// .Protocol.PlayerType playerType = 3;
inline void PlayerInfo::clear_playertype() {
  playertype_ = 0;
}
inline ::Protocol::PlayerType PlayerInfo::_internal_playertype() const {
  return static_cast< ::Protocol::PlayerType >(playertype_);
}
inline ::Protocol::PlayerType PlayerInfo::playertype() const {
  // @@protoc_insertion_point(field_get:Protocol.PlayerInfo.playerType)
  return _internal_playertype();
}
inline void PlayerInfo::_internal_set_playertype(::Protocol::PlayerType value) {
  
  playertype_ = value;
}
inline void PlayerInfo::set_playertype(::Protocol::PlayerType value) {
  _internal_set_playertype(value);
  // @@protoc_insertion_point(field_set:Protocol.PlayerInfo.playerType)
}

// float x = 4;
inline void PlayerInfo::clear_x() {
  x_ = 0;
}
inline float PlayerInfo::_internal_x() const {
  return x_;
}
inline float PlayerInfo::x() const {
  // @@protoc_insertion_point(field_get:Protocol.PlayerInfo.x)
  return _internal_x();
}
inline void PlayerInfo::_internal_set_x(float value) {
  
  x_ = value;
}
inline void PlayerInfo::set_x(float value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:Protocol.PlayerInfo.x)
}

// float y = 5;
inline void PlayerInfo::clear_y() {
  y_ = 0;
}
inline float PlayerInfo::_internal_y() const {
  return y_;
}
inline float PlayerInfo::y() const {
  // @@protoc_insertion_point(field_get:Protocol.PlayerInfo.y)
  return _internal_y();
}
inline void PlayerInfo::_internal_set_y(float value) {
  
  y_ = value;
}
inline void PlayerInfo::set_y(float value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:Protocol.PlayerInfo.y)
}

// float z = 6;
inline void PlayerInfo::clear_z() {
  z_ = 0;
}
inline float PlayerInfo::_internal_z() const {
  return z_;
}
inline float PlayerInfo::z() const {
  // @@protoc_insertion_point(field_get:Protocol.PlayerInfo.z)
  return _internal_z();
}
inline void PlayerInfo::_internal_set_z(float value) {
  
  z_ = value;
}
inline void PlayerInfo::set_z(float value) {
  _internal_set_z(value);
  // @@protoc_insertion_point(field_set:Protocol.PlayerInfo.z)
}

// float yaw = 7;
inline void PlayerInfo::clear_yaw() {
  yaw_ = 0;
}
inline float PlayerInfo::_internal_yaw() const {
  return yaw_;
}
inline float PlayerInfo::yaw() const {
  // @@protoc_insertion_point(field_get:Protocol.PlayerInfo.yaw)
  return _internal_yaw();
}
inline void PlayerInfo::_internal_set_yaw(float value) {
  
  yaw_ = value;
}
inline void PlayerInfo::set_yaw(float value) {
  _internal_set_yaw(value);
  // @@protoc_insertion_point(field_set:Protocol.PlayerInfo.yaw)
}

// .Protocol.MoveState moveState = 8;
inline void PlayerInfo::clear_movestate() {
  movestate_ = 0;
}
inline ::Protocol::MoveState PlayerInfo::_internal_movestate() const {
  return static_cast< ::Protocol::MoveState >(movestate_);
}
inline ::Protocol::MoveState PlayerInfo::movestate() const {
  // @@protoc_insertion_point(field_get:Protocol.PlayerInfo.moveState)
  return _internal_movestate();
}
inline void PlayerInfo::_internal_set_movestate(::Protocol::MoveState value) {
  
  movestate_ = value;
}
inline void PlayerInfo::set_movestate(::Protocol::MoveState value) {
  _internal_set_movestate(value);
  // @@protoc_insertion_point(field_set:Protocol.PlayerInfo.moveState)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace Protocol

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Struct_2eproto

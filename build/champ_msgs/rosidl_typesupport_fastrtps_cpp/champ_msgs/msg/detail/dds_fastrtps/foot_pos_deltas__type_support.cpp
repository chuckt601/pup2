// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from champ_msgs:msg/FootPosDeltas.idl
// generated code does not contain a copyright notice
#include "champ_msgs/msg/detail/foot_pos_deltas__rosidl_typesupport_fastrtps_cpp.hpp"
#include "champ_msgs/msg/detail/foot_pos_deltas__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace champ_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const champ_msgs::msg::Transformation &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  champ_msgs::msg::Transformation &);
size_t get_serialized_size(
  const champ_msgs::msg::Transformation &,
  size_t current_alignment);
size_t
max_serialized_size_Transformation(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace champ_msgs


namespace champ_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_champ_msgs
cdr_serialize(
  const champ_msgs::msg::FootPosDeltas & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: foot_pos_deltas
  {
    for (size_t i = 0; i < 4; i++) {
      champ_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.foot_pos_deltas[i],
        cdr);
    }
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_champ_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  champ_msgs::msg::FootPosDeltas & ros_message)
{
  // Member: foot_pos_deltas
  {
    for (size_t i = 0; i < 4; i++) {
      champ_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr,
        ros_message.foot_pos_deltas[i]);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_champ_msgs
get_serialized_size(
  const champ_msgs::msg::FootPosDeltas & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: foot_pos_deltas
  {
    size_t array_size = 4;

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        champ_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.foot_pos_deltas[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_champ_msgs
max_serialized_size_FootPosDeltas(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: foot_pos_deltas
  {
    size_t array_size = 4;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        champ_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Transformation(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = champ_msgs::msg::FootPosDeltas;
    is_plain =
      (
      offsetof(DataType, foot_pos_deltas) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _FootPosDeltas__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const champ_msgs::msg::FootPosDeltas *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _FootPosDeltas__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<champ_msgs::msg::FootPosDeltas *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _FootPosDeltas__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const champ_msgs::msg::FootPosDeltas *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _FootPosDeltas__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_FootPosDeltas(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _FootPosDeltas__callbacks = {
  "champ_msgs::msg",
  "FootPosDeltas",
  _FootPosDeltas__cdr_serialize,
  _FootPosDeltas__cdr_deserialize,
  _FootPosDeltas__get_serialized_size,
  _FootPosDeltas__max_serialized_size
};

static rosidl_message_type_support_t _FootPosDeltas__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_FootPosDeltas__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace champ_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_champ_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<champ_msgs::msg::FootPosDeltas>()
{
  return &champ_msgs::msg::typesupport_fastrtps_cpp::_FootPosDeltas__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, champ_msgs, msg, FootPosDeltas)() {
  return &champ_msgs::msg::typesupport_fastrtps_cpp::_FootPosDeltas__handle;
}

#ifdef __cplusplus
}
#endif

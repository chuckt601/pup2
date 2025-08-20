// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from champ_msgs:msg/FootPosDeltas.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "champ_msgs/msg/detail/foot_pos_deltas__rosidl_typesupport_introspection_c.h"
#include "champ_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "champ_msgs/msg/detail/foot_pos_deltas__functions.h"
#include "champ_msgs/msg/detail/foot_pos_deltas__struct.h"


// Include directives for member types
// Member `foot_pos_deltas`
#include "champ_msgs/msg/transformation.h"
// Member `foot_pos_deltas`
#include "champ_msgs/msg/detail/transformation__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__FootPosDeltas_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  champ_msgs__msg__FootPosDeltas__init(message_memory);
}

void champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__FootPosDeltas_fini_function(void * message_memory)
{
  champ_msgs__msg__FootPosDeltas__fini(message_memory);
}

size_t champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__size_function__FootPosDeltas__foot_pos_deltas(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__get_const_function__FootPosDeltas__foot_pos_deltas(
  const void * untyped_member, size_t index)
{
  const champ_msgs__msg__Transformation * member =
    (const champ_msgs__msg__Transformation *)(untyped_member);
  return &member[index];
}

void * champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__get_function__FootPosDeltas__foot_pos_deltas(
  void * untyped_member, size_t index)
{
  champ_msgs__msg__Transformation * member =
    (champ_msgs__msg__Transformation *)(untyped_member);
  return &member[index];
}

void champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__fetch_function__FootPosDeltas__foot_pos_deltas(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const champ_msgs__msg__Transformation * item =
    ((const champ_msgs__msg__Transformation *)
    champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__get_const_function__FootPosDeltas__foot_pos_deltas(untyped_member, index));
  champ_msgs__msg__Transformation * value =
    (champ_msgs__msg__Transformation *)(untyped_value);
  *value = *item;
}

void champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__assign_function__FootPosDeltas__foot_pos_deltas(
  void * untyped_member, size_t index, const void * untyped_value)
{
  champ_msgs__msg__Transformation * item =
    ((champ_msgs__msg__Transformation *)
    champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__get_function__FootPosDeltas__foot_pos_deltas(untyped_member, index));
  const champ_msgs__msg__Transformation * value =
    (const champ_msgs__msg__Transformation *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__FootPosDeltas_message_member_array[1] = {
  {
    "foot_pos_deltas",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(champ_msgs__msg__FootPosDeltas, foot_pos_deltas),  // bytes offset in struct
    NULL,  // default value
    champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__size_function__FootPosDeltas__foot_pos_deltas,  // size() function pointer
    champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__get_const_function__FootPosDeltas__foot_pos_deltas,  // get_const(index) function pointer
    champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__get_function__FootPosDeltas__foot_pos_deltas,  // get(index) function pointer
    champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__fetch_function__FootPosDeltas__foot_pos_deltas,  // fetch(index, &value) function pointer
    champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__assign_function__FootPosDeltas__foot_pos_deltas,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__FootPosDeltas_message_members = {
  "champ_msgs__msg",  // message namespace
  "FootPosDeltas",  // message name
  1,  // number of fields
  sizeof(champ_msgs__msg__FootPosDeltas),
  champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__FootPosDeltas_message_member_array,  // message members
  champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__FootPosDeltas_init_function,  // function to initialize message memory (memory has to be allocated)
  champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__FootPosDeltas_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__FootPosDeltas_message_type_support_handle = {
  0,
  &champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__FootPosDeltas_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_champ_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, champ_msgs, msg, FootPosDeltas)() {
  champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__FootPosDeltas_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, champ_msgs, msg, Transformation)();
  if (!champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__FootPosDeltas_message_type_support_handle.typesupport_identifier) {
    champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__FootPosDeltas_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &champ_msgs__msg__FootPosDeltas__rosidl_typesupport_introspection_c__FootPosDeltas_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

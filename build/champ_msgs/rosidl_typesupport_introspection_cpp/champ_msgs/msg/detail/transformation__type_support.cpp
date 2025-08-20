// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from champ_msgs:msg/Transformation.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "champ_msgs/msg/detail/transformation__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace champ_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Transformation_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) champ_msgs::msg::Transformation(_init);
}

void Transformation_fini_function(void * message_memory)
{
  auto typed_message = static_cast<champ_msgs::msg::Transformation *>(message_memory);
  typed_message->~Transformation();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Transformation_message_member_array[2] = {
  {
    "translation",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Vector3>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(champ_msgs::msg::Transformation, translation),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "rotation",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Quaternion>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(champ_msgs::msg::Transformation, rotation),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Transformation_message_members = {
  "champ_msgs::msg",  // message namespace
  "Transformation",  // message name
  2,  // number of fields
  sizeof(champ_msgs::msg::Transformation),
  Transformation_message_member_array,  // message members
  Transformation_init_function,  // function to initialize message memory (memory has to be allocated)
  Transformation_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Transformation_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Transformation_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace champ_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<champ_msgs::msg::Transformation>()
{
  return &::champ_msgs::msg::rosidl_typesupport_introspection_cpp::Transformation_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, champ_msgs, msg, Transformation)() {
  return &::champ_msgs::msg::rosidl_typesupport_introspection_cpp::Transformation_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

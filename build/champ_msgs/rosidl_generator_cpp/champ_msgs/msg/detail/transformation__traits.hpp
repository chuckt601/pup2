// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from champ_msgs:msg/Transformation.idl
// generated code does not contain a copyright notice

#ifndef CHAMP_MSGS__MSG__DETAIL__TRANSFORMATION__TRAITS_HPP_
#define CHAMP_MSGS__MSG__DETAIL__TRANSFORMATION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "champ_msgs/msg/detail/transformation__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'translation'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"
// Member 'rotation'
#include "geometry_msgs/msg/detail/quaternion__traits.hpp"

namespace champ_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Transformation & msg,
  std::ostream & out)
{
  out << "{";
  // member: translation
  {
    out << "translation: ";
    to_flow_style_yaml(msg.translation, out);
    out << ", ";
  }

  // member: rotation
  {
    out << "rotation: ";
    to_flow_style_yaml(msg.rotation, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Transformation & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: translation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "translation:\n";
    to_block_style_yaml(msg.translation, out, indentation + 2);
  }

  // member: rotation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rotation:\n";
    to_block_style_yaml(msg.rotation, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Transformation & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace champ_msgs

namespace rosidl_generator_traits
{

[[deprecated("use champ_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const champ_msgs::msg::Transformation & msg,
  std::ostream & out, size_t indentation = 0)
{
  champ_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use champ_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const champ_msgs::msg::Transformation & msg)
{
  return champ_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<champ_msgs::msg::Transformation>()
{
  return "champ_msgs::msg::Transformation";
}

template<>
inline const char * name<champ_msgs::msg::Transformation>()
{
  return "champ_msgs/msg/Transformation";
}

template<>
struct has_fixed_size<champ_msgs::msg::Transformation>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Quaternion>::value && has_fixed_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct has_bounded_size<champ_msgs::msg::Transformation>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Quaternion>::value && has_bounded_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct is_message<champ_msgs::msg::Transformation>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CHAMP_MSGS__MSG__DETAIL__TRANSFORMATION__TRAITS_HPP_

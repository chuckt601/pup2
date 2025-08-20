// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from champ_msgs:msg/FootPosDeltas.idl
// generated code does not contain a copyright notice

#ifndef CHAMP_MSGS__MSG__DETAIL__FOOT_POS_DELTAS__TRAITS_HPP_
#define CHAMP_MSGS__MSG__DETAIL__FOOT_POS_DELTAS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "champ_msgs/msg/detail/foot_pos_deltas__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'foot_pos_deltas'
#include "champ_msgs/msg/detail/transformation__traits.hpp"

namespace champ_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const FootPosDeltas & msg,
  std::ostream & out)
{
  out << "{";
  // member: foot_pos_deltas
  {
    if (msg.foot_pos_deltas.size() == 0) {
      out << "foot_pos_deltas: []";
    } else {
      out << "foot_pos_deltas: [";
      size_t pending_items = msg.foot_pos_deltas.size();
      for (auto item : msg.foot_pos_deltas) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FootPosDeltas & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: foot_pos_deltas
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.foot_pos_deltas.size() == 0) {
      out << "foot_pos_deltas: []\n";
    } else {
      out << "foot_pos_deltas:\n";
      for (auto item : msg.foot_pos_deltas) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FootPosDeltas & msg, bool use_flow_style = false)
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
  const champ_msgs::msg::FootPosDeltas & msg,
  std::ostream & out, size_t indentation = 0)
{
  champ_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use champ_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const champ_msgs::msg::FootPosDeltas & msg)
{
  return champ_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<champ_msgs::msg::FootPosDeltas>()
{
  return "champ_msgs::msg::FootPosDeltas";
}

template<>
inline const char * name<champ_msgs::msg::FootPosDeltas>()
{
  return "champ_msgs/msg/FootPosDeltas";
}

template<>
struct has_fixed_size<champ_msgs::msg::FootPosDeltas>
  : std::integral_constant<bool, has_fixed_size<champ_msgs::msg::Transformation>::value> {};

template<>
struct has_bounded_size<champ_msgs::msg::FootPosDeltas>
  : std::integral_constant<bool, has_bounded_size<champ_msgs::msg::Transformation>::value> {};

template<>
struct is_message<champ_msgs::msg::FootPosDeltas>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CHAMP_MSGS__MSG__DETAIL__FOOT_POS_DELTAS__TRAITS_HPP_

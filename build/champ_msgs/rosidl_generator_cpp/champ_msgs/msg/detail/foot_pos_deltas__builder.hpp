// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from champ_msgs:msg/FootPosDeltas.idl
// generated code does not contain a copyright notice

#ifndef CHAMP_MSGS__MSG__DETAIL__FOOT_POS_DELTAS__BUILDER_HPP_
#define CHAMP_MSGS__MSG__DETAIL__FOOT_POS_DELTAS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "champ_msgs/msg/detail/foot_pos_deltas__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace champ_msgs
{

namespace msg
{

namespace builder
{

class Init_FootPosDeltas_foot_pos_deltas
{
public:
  Init_FootPosDeltas_foot_pos_deltas()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::champ_msgs::msg::FootPosDeltas foot_pos_deltas(::champ_msgs::msg::FootPosDeltas::_foot_pos_deltas_type arg)
  {
    msg_.foot_pos_deltas = std::move(arg);
    return std::move(msg_);
  }

private:
  ::champ_msgs::msg::FootPosDeltas msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::champ_msgs::msg::FootPosDeltas>()
{
  return champ_msgs::msg::builder::Init_FootPosDeltas_foot_pos_deltas();
}

}  // namespace champ_msgs

#endif  // CHAMP_MSGS__MSG__DETAIL__FOOT_POS_DELTAS__BUILDER_HPP_

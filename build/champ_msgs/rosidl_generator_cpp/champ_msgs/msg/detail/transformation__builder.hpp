// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from champ_msgs:msg/Transformation.idl
// generated code does not contain a copyright notice

#ifndef CHAMP_MSGS__MSG__DETAIL__TRANSFORMATION__BUILDER_HPP_
#define CHAMP_MSGS__MSG__DETAIL__TRANSFORMATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "champ_msgs/msg/detail/transformation__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace champ_msgs
{

namespace msg
{

namespace builder
{

class Init_Transformation_rotation
{
public:
  explicit Init_Transformation_rotation(::champ_msgs::msg::Transformation & msg)
  : msg_(msg)
  {}
  ::champ_msgs::msg::Transformation rotation(::champ_msgs::msg::Transformation::_rotation_type arg)
  {
    msg_.rotation = std::move(arg);
    return std::move(msg_);
  }

private:
  ::champ_msgs::msg::Transformation msg_;
};

class Init_Transformation_translation
{
public:
  Init_Transformation_translation()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Transformation_rotation translation(::champ_msgs::msg::Transformation::_translation_type arg)
  {
    msg_.translation = std::move(arg);
    return Init_Transformation_rotation(msg_);
  }

private:
  ::champ_msgs::msg::Transformation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::champ_msgs::msg::Transformation>()
{
  return champ_msgs::msg::builder::Init_Transformation_translation();
}

}  // namespace champ_msgs

#endif  // CHAMP_MSGS__MSG__DETAIL__TRANSFORMATION__BUILDER_HPP_

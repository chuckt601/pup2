// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from champ_msgs:msg/FootPosDeltas.idl
// generated code does not contain a copyright notice

#ifndef CHAMP_MSGS__MSG__DETAIL__FOOT_POS_DELTAS__STRUCT_HPP_
#define CHAMP_MSGS__MSG__DETAIL__FOOT_POS_DELTAS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'foot_pos_deltas'
#include "champ_msgs/msg/detail/transformation__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__champ_msgs__msg__FootPosDeltas __attribute__((deprecated))
#else
# define DEPRECATED__champ_msgs__msg__FootPosDeltas __declspec(deprecated)
#endif

namespace champ_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FootPosDeltas_
{
  using Type = FootPosDeltas_<ContainerAllocator>;

  explicit FootPosDeltas_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->foot_pos_deltas.fill(champ_msgs::msg::Transformation_<ContainerAllocator>{_init});
    }
  }

  explicit FootPosDeltas_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : foot_pos_deltas(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->foot_pos_deltas.fill(champ_msgs::msg::Transformation_<ContainerAllocator>{_alloc, _init});
    }
  }

  // field types and members
  using _foot_pos_deltas_type =
    std::array<champ_msgs::msg::Transformation_<ContainerAllocator>, 4>;
  _foot_pos_deltas_type foot_pos_deltas;

  // setters for named parameter idiom
  Type & set__foot_pos_deltas(
    const std::array<champ_msgs::msg::Transformation_<ContainerAllocator>, 4> & _arg)
  {
    this->foot_pos_deltas = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    champ_msgs::msg::FootPosDeltas_<ContainerAllocator> *;
  using ConstRawPtr =
    const champ_msgs::msg::FootPosDeltas_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<champ_msgs::msg::FootPosDeltas_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<champ_msgs::msg::FootPosDeltas_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      champ_msgs::msg::FootPosDeltas_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<champ_msgs::msg::FootPosDeltas_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      champ_msgs::msg::FootPosDeltas_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<champ_msgs::msg::FootPosDeltas_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<champ_msgs::msg::FootPosDeltas_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<champ_msgs::msg::FootPosDeltas_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__champ_msgs__msg__FootPosDeltas
    std::shared_ptr<champ_msgs::msg::FootPosDeltas_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__champ_msgs__msg__FootPosDeltas
    std::shared_ptr<champ_msgs::msg::FootPosDeltas_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FootPosDeltas_ & other) const
  {
    if (this->foot_pos_deltas != other.foot_pos_deltas) {
      return false;
    }
    return true;
  }
  bool operator!=(const FootPosDeltas_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FootPosDeltas_

// alias to use template instance with default allocator
using FootPosDeltas =
  champ_msgs::msg::FootPosDeltas_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace champ_msgs

#endif  // CHAMP_MSGS__MSG__DETAIL__FOOT_POS_DELTAS__STRUCT_HPP_

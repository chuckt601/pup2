// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from champ_msgs:msg/Transformation.idl
// generated code does not contain a copyright notice

#ifndef CHAMP_MSGS__MSG__DETAIL__TRANSFORMATION__STRUCT_HPP_
#define CHAMP_MSGS__MSG__DETAIL__TRANSFORMATION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'translation'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"
// Member 'rotation'
#include "geometry_msgs/msg/detail/quaternion__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__champ_msgs__msg__Transformation __attribute__((deprecated))
#else
# define DEPRECATED__champ_msgs__msg__Transformation __declspec(deprecated)
#endif

namespace champ_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Transformation_
{
  using Type = Transformation_<ContainerAllocator>;

  explicit Transformation_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : translation(_init),
    rotation(_init)
  {
    (void)_init;
  }

  explicit Transformation_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : translation(_alloc, _init),
    rotation(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _translation_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _translation_type translation;
  using _rotation_type =
    geometry_msgs::msg::Quaternion_<ContainerAllocator>;
  _rotation_type rotation;

  // setters for named parameter idiom
  Type & set__translation(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->translation = _arg;
    return *this;
  }
  Type & set__rotation(
    const geometry_msgs::msg::Quaternion_<ContainerAllocator> & _arg)
  {
    this->rotation = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    champ_msgs::msg::Transformation_<ContainerAllocator> *;
  using ConstRawPtr =
    const champ_msgs::msg::Transformation_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<champ_msgs::msg::Transformation_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<champ_msgs::msg::Transformation_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      champ_msgs::msg::Transformation_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<champ_msgs::msg::Transformation_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      champ_msgs::msg::Transformation_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<champ_msgs::msg::Transformation_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<champ_msgs::msg::Transformation_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<champ_msgs::msg::Transformation_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__champ_msgs__msg__Transformation
    std::shared_ptr<champ_msgs::msg::Transformation_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__champ_msgs__msg__Transformation
    std::shared_ptr<champ_msgs::msg::Transformation_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Transformation_ & other) const
  {
    if (this->translation != other.translation) {
      return false;
    }
    if (this->rotation != other.rotation) {
      return false;
    }
    return true;
  }
  bool operator!=(const Transformation_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Transformation_

// alias to use template instance with default allocator
using Transformation =
  champ_msgs::msg::Transformation_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace champ_msgs

#endif  // CHAMP_MSGS__MSG__DETAIL__TRANSFORMATION__STRUCT_HPP_

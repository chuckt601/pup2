// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from champ_msgs:msg/Transformation.idl
// generated code does not contain a copyright notice

#ifndef CHAMP_MSGS__MSG__DETAIL__TRANSFORMATION__STRUCT_H_
#define CHAMP_MSGS__MSG__DETAIL__TRANSFORMATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'translation'
#include "geometry_msgs/msg/detail/vector3__struct.h"
// Member 'rotation'
#include "geometry_msgs/msg/detail/quaternion__struct.h"

/// Struct defined in msg/Transformation in the package champ_msgs.
/**
  * Position as a vector (x, y, z)
 */
typedef struct champ_msgs__msg__Transformation
{
  geometry_msgs__msg__Vector3 translation;
  /// Orientation as a quaternion (x, y, z, w)
  geometry_msgs__msg__Quaternion rotation;
} champ_msgs__msg__Transformation;

// Struct for a sequence of champ_msgs__msg__Transformation.
typedef struct champ_msgs__msg__Transformation__Sequence
{
  champ_msgs__msg__Transformation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} champ_msgs__msg__Transformation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CHAMP_MSGS__MSG__DETAIL__TRANSFORMATION__STRUCT_H_

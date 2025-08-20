// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from champ_msgs:msg/FootPosDeltas.idl
// generated code does not contain a copyright notice

#ifndef CHAMP_MSGS__MSG__DETAIL__FOOT_POS_DELTAS__STRUCT_H_
#define CHAMP_MSGS__MSG__DETAIL__FOOT_POS_DELTAS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'foot_pos_deltas'
#include "champ_msgs/msg/detail/transformation__struct.h"

/// Struct defined in msg/FootPosDeltas in the package champ_msgs.
/**
  * geometry_msgs/Transform foot_pos_deltas
 */
typedef struct champ_msgs__msg__FootPosDeltas
{
  /// Array of 4 Transformation objects
  champ_msgs__msg__Transformation foot_pos_deltas[4];
} champ_msgs__msg__FootPosDeltas;

// Struct for a sequence of champ_msgs__msg__FootPosDeltas.
typedef struct champ_msgs__msg__FootPosDeltas__Sequence
{
  champ_msgs__msg__FootPosDeltas * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} champ_msgs__msg__FootPosDeltas__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CHAMP_MSGS__MSG__DETAIL__FOOT_POS_DELTAS__STRUCT_H_

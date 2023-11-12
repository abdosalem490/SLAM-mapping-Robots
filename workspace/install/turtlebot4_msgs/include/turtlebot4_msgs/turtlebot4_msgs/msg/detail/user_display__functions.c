// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from turtlebot4_msgs:msg/UserDisplay.idl
// generated code does not contain a copyright notice
#include "turtlebot4_msgs/msg/detail/user_display__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `ip`
// Member `battery`
// Member `entries`
#include "rosidl_runtime_c/string_functions.h"

bool
turtlebot4_msgs__msg__UserDisplay__init(turtlebot4_msgs__msg__UserDisplay * msg)
{
  if (!msg) {
    return false;
  }
  // ip
  if (!rosidl_runtime_c__String__init(&msg->ip)) {
    turtlebot4_msgs__msg__UserDisplay__fini(msg);
    return false;
  }
  // battery
  if (!rosidl_runtime_c__String__init(&msg->battery)) {
    turtlebot4_msgs__msg__UserDisplay__fini(msg);
    return false;
  }
  // entries
  for (size_t i = 0; i < 5; ++i) {
    if (!rosidl_runtime_c__String__init(&msg->entries[i])) {
      turtlebot4_msgs__msg__UserDisplay__fini(msg);
      return false;
    }
  }
  // selected_entry
  return true;
}

void
turtlebot4_msgs__msg__UserDisplay__fini(turtlebot4_msgs__msg__UserDisplay * msg)
{
  if (!msg) {
    return;
  }
  // ip
  rosidl_runtime_c__String__fini(&msg->ip);
  // battery
  rosidl_runtime_c__String__fini(&msg->battery);
  // entries
  for (size_t i = 0; i < 5; ++i) {
    rosidl_runtime_c__String__fini(&msg->entries[i]);
  }
  // selected_entry
}

bool
turtlebot4_msgs__msg__UserDisplay__are_equal(const turtlebot4_msgs__msg__UserDisplay * lhs, const turtlebot4_msgs__msg__UserDisplay * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // ip
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->ip), &(rhs->ip)))
  {
    return false;
  }
  // battery
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->battery), &(rhs->battery)))
  {
    return false;
  }
  // entries
  for (size_t i = 0; i < 5; ++i) {
    if (!rosidl_runtime_c__String__are_equal(
        &(lhs->entries[i]), &(rhs->entries[i])))
    {
      return false;
    }
  }
  // selected_entry
  if (lhs->selected_entry != rhs->selected_entry) {
    return false;
  }
  return true;
}

bool
turtlebot4_msgs__msg__UserDisplay__copy(
  const turtlebot4_msgs__msg__UserDisplay * input,
  turtlebot4_msgs__msg__UserDisplay * output)
{
  if (!input || !output) {
    return false;
  }
  // ip
  if (!rosidl_runtime_c__String__copy(
      &(input->ip), &(output->ip)))
  {
    return false;
  }
  // battery
  if (!rosidl_runtime_c__String__copy(
      &(input->battery), &(output->battery)))
  {
    return false;
  }
  // entries
  for (size_t i = 0; i < 5; ++i) {
    if (!rosidl_runtime_c__String__copy(
        &(input->entries[i]), &(output->entries[i])))
    {
      return false;
    }
  }
  // selected_entry
  output->selected_entry = input->selected_entry;
  return true;
}

turtlebot4_msgs__msg__UserDisplay *
turtlebot4_msgs__msg__UserDisplay__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtlebot4_msgs__msg__UserDisplay * msg = (turtlebot4_msgs__msg__UserDisplay *)allocator.allocate(sizeof(turtlebot4_msgs__msg__UserDisplay), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turtlebot4_msgs__msg__UserDisplay));
  bool success = turtlebot4_msgs__msg__UserDisplay__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turtlebot4_msgs__msg__UserDisplay__destroy(turtlebot4_msgs__msg__UserDisplay * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turtlebot4_msgs__msg__UserDisplay__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turtlebot4_msgs__msg__UserDisplay__Sequence__init(turtlebot4_msgs__msg__UserDisplay__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtlebot4_msgs__msg__UserDisplay * data = NULL;

  if (size) {
    data = (turtlebot4_msgs__msg__UserDisplay *)allocator.zero_allocate(size, sizeof(turtlebot4_msgs__msg__UserDisplay), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turtlebot4_msgs__msg__UserDisplay__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turtlebot4_msgs__msg__UserDisplay__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turtlebot4_msgs__msg__UserDisplay__Sequence__fini(turtlebot4_msgs__msg__UserDisplay__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turtlebot4_msgs__msg__UserDisplay__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turtlebot4_msgs__msg__UserDisplay__Sequence *
turtlebot4_msgs__msg__UserDisplay__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtlebot4_msgs__msg__UserDisplay__Sequence * array = (turtlebot4_msgs__msg__UserDisplay__Sequence *)allocator.allocate(sizeof(turtlebot4_msgs__msg__UserDisplay__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turtlebot4_msgs__msg__UserDisplay__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turtlebot4_msgs__msg__UserDisplay__Sequence__destroy(turtlebot4_msgs__msg__UserDisplay__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turtlebot4_msgs__msg__UserDisplay__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turtlebot4_msgs__msg__UserDisplay__Sequence__are_equal(const turtlebot4_msgs__msg__UserDisplay__Sequence * lhs, const turtlebot4_msgs__msg__UserDisplay__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turtlebot4_msgs__msg__UserDisplay__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turtlebot4_msgs__msg__UserDisplay__Sequence__copy(
  const turtlebot4_msgs__msg__UserDisplay__Sequence * input,
  turtlebot4_msgs__msg__UserDisplay__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turtlebot4_msgs__msg__UserDisplay);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turtlebot4_msgs__msg__UserDisplay * data =
      (turtlebot4_msgs__msg__UserDisplay *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turtlebot4_msgs__msg__UserDisplay__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turtlebot4_msgs__msg__UserDisplay__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turtlebot4_msgs__msg__UserDisplay__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from turtlebot4_msgs:msg/UserButton.idl
// generated code does not contain a copyright notice
#include "turtlebot4_msgs/msg/detail/user_button__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
turtlebot4_msgs__msg__UserButton__init(turtlebot4_msgs__msg__UserButton * msg)
{
  if (!msg) {
    return false;
  }
  // button
  return true;
}

void
turtlebot4_msgs__msg__UserButton__fini(turtlebot4_msgs__msg__UserButton * msg)
{
  if (!msg) {
    return;
  }
  // button
}

bool
turtlebot4_msgs__msg__UserButton__are_equal(const turtlebot4_msgs__msg__UserButton * lhs, const turtlebot4_msgs__msg__UserButton * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // button
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->button[i] != rhs->button[i]) {
      return false;
    }
  }
  return true;
}

bool
turtlebot4_msgs__msg__UserButton__copy(
  const turtlebot4_msgs__msg__UserButton * input,
  turtlebot4_msgs__msg__UserButton * output)
{
  if (!input || !output) {
    return false;
  }
  // button
  for (size_t i = 0; i < 4; ++i) {
    output->button[i] = input->button[i];
  }
  return true;
}

turtlebot4_msgs__msg__UserButton *
turtlebot4_msgs__msg__UserButton__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtlebot4_msgs__msg__UserButton * msg = (turtlebot4_msgs__msg__UserButton *)allocator.allocate(sizeof(turtlebot4_msgs__msg__UserButton), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turtlebot4_msgs__msg__UserButton));
  bool success = turtlebot4_msgs__msg__UserButton__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turtlebot4_msgs__msg__UserButton__destroy(turtlebot4_msgs__msg__UserButton * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turtlebot4_msgs__msg__UserButton__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turtlebot4_msgs__msg__UserButton__Sequence__init(turtlebot4_msgs__msg__UserButton__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtlebot4_msgs__msg__UserButton * data = NULL;

  if (size) {
    data = (turtlebot4_msgs__msg__UserButton *)allocator.zero_allocate(size, sizeof(turtlebot4_msgs__msg__UserButton), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turtlebot4_msgs__msg__UserButton__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turtlebot4_msgs__msg__UserButton__fini(&data[i - 1]);
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
turtlebot4_msgs__msg__UserButton__Sequence__fini(turtlebot4_msgs__msg__UserButton__Sequence * array)
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
      turtlebot4_msgs__msg__UserButton__fini(&array->data[i]);
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

turtlebot4_msgs__msg__UserButton__Sequence *
turtlebot4_msgs__msg__UserButton__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtlebot4_msgs__msg__UserButton__Sequence * array = (turtlebot4_msgs__msg__UserButton__Sequence *)allocator.allocate(sizeof(turtlebot4_msgs__msg__UserButton__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turtlebot4_msgs__msg__UserButton__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turtlebot4_msgs__msg__UserButton__Sequence__destroy(turtlebot4_msgs__msg__UserButton__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turtlebot4_msgs__msg__UserButton__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turtlebot4_msgs__msg__UserButton__Sequence__are_equal(const turtlebot4_msgs__msg__UserButton__Sequence * lhs, const turtlebot4_msgs__msg__UserButton__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turtlebot4_msgs__msg__UserButton__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turtlebot4_msgs__msg__UserButton__Sequence__copy(
  const turtlebot4_msgs__msg__UserButton__Sequence * input,
  turtlebot4_msgs__msg__UserButton__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turtlebot4_msgs__msg__UserButton);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turtlebot4_msgs__msg__UserButton * data =
      (turtlebot4_msgs__msg__UserButton *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turtlebot4_msgs__msg__UserButton__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turtlebot4_msgs__msg__UserButton__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turtlebot4_msgs__msg__UserButton__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

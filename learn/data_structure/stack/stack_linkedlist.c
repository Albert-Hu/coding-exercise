#include <stdlib.h>
#include "stack.h"

typedef struct stack_data stack_data;

struct stack_data {
  stack_data* previous; /**< the pointer to previous object. */
  int value; /**< the value of the data. */
};

struct stack {
  size_t capacity; /**< the capacity of the stack. */
  size_t amount; /**< amount of the data in the stack.  */
  stack_data* data; /**< the data array. */
};

/**
 * @brief Construct a new stack data object.
 *
 * @param value The value of the data.
 * @param previous A pointer to previous object.
 * @return stack_data* A pointer to a stack data object.
 */
static stack_data* stack_data_new(int value, stack_data* previous) {
  stack_data* data = (stack_data*) malloc(sizeof(stack_data));

  data->previous = previous;
  data->value = value;

  return data;
}

/**
 * @brief Delete the stack data object.
 *
 * @param data
 */
static void stack_data_delete(stack_data* data) {
  free(data);
}

/**
 * @brief Construct a new stack object.
 *
 * @param capacity The capacity of the stack.
 * @return stack* A pointer to a stack object.
 */
stack* stack_new(size_t capacity) {
  stack* s = (stack*) malloc(sizeof(stack));

  s->capacity = capacity;
  s->amount = 0;
  s->data = NULL;

  return s;
}

/**
 * @brief Check if the stack is empty.
 *
 * @param s The stack object.
 * @return true The stack is empty.
 * @return false The stack is not empty.
 */
bool stack_is_empty(stack* s) {
  return s->amount == 0;
}

/**
 * @brief Check if the stack is full.
 *
 * @param s The stack object.
 * @return true The stack is full.
 * @return false The stack is not full.
 */
bool stack_is_full(stack* s) {
  return s->amount == s->capacity;
}

/**
 * @brief Push the data onto the stack.
 *
 * @param s The stack object.
 * @param data The data which will be pushed onto the stack.
 */
void stack_push(stack* s, int data) {
  stack_data* new_data;

  if (!stack_is_full(s)) {
    new_data = stack_data_new(data, s->data);
    s->data = new_data;
    s->amount++;
  }
}

/**
 * @brief Remove the data on top of the stack.
 *
 * @param s The stack object.
 */
void stack_pop(stack* s) {
  stack_data* current = s->data;

  if (!stack_is_empty(s)) {
    s->data = current->previous;
    s->amount--;
    stack_data_delete(current);
  }
}

/**
 * @brief Get the data on top of the stack.
 *
 * @param s The stack object.
 * @return int The data on top of the stack, return 0 if the stack is empty.
 */
int stack_top(stack* s) {
  int data = 0;

  if (!stack_is_empty(s)) {
    data = s->data->value;
  }

  return data;
}

/**
 * @brief Delete the stack object.
 *
 * @param s The stack object.
 */
void stack_delete(stack* s) {
  stack_data* current;

  while (s->data) {
    current = s->data;
    s->data = current->previous;
    stack_data_delete(current);
  }

  free(s);
}

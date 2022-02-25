#include <stdlib.h>
#include "stack.h"

struct stack {
  size_t capacity; /**< the capacity of the stack. */
  size_t amount; /**< amount of the data in the stack.  */
  int data[0]; /**< the data array. */
};

/**
 * @brief Create a stack object.
 *
 * @param size The capacity of the stack.
 * @return stack* The stack object.
 */
stack* stack_new(size_t capacity) {
  stack* s = (stack*) malloc(sizeof(stack) + sizeof(int) * capacity);

  s->capacity = capacity;
  s->amount = 0;

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
  if (!stack_is_full(s)) {
    s->data[s->amount] = data;
    s->amount++;
  }
}

/**
 * @brief Remove the data on top of the stack.
 *
 * @param s The stack object.
 */
void stack_pop(stack* s) {
  if (!stack_is_empty(s)) {
    s->amount--;
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
    data = s->data[s->amount - 1];
  }

  return data;
}

/**
 * @brief Delete the stack object.
 *
 * @param s The stack object.
 */
void stack_delete(stack* s) {
  free(s);
}

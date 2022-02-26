#include <stdlib.h>
#include "stack.h"

struct stack {
  // add your variables here
};

/**
 * @brief Construct a new stack object.
 *
 * @param capacity The capacity of the stack.
 * @return stack* A pointer to a stack object.
 */
stack* stack_new(size_t capacity) {
  stack* s = NULL;

  // implement this function here

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
  bool result = false;

  // implement this function here

  return result;
}

/**
 * @brief Check if the stack is full.
 *
 * @param s The stack object.
 * @return true The stack is full.
 * @return false The stack is not full.
 */
bool stack_is_full(stack* s) {
  bool result = false;

  // implement this function here

  return result;
}

/**
 * @brief Push the data onto the stack.
 *
 * @param s The stack object.
 * @param data The data which will be pushed onto the stack.
 */
void stack_push(stack* s, int data) {
  // implement this function here
}

/**
 * @brief Remove the data on top of the stack.
 *
 * @param s The stack object.
 */
void stack_pop(stack* s) {
  // implement this function here
}

/**
 * @brief Get the data on top of the stack.
 *
 * @param s The stack object.
 * @return int The data on top of the stack, return 0 if the stack is empty.
 */
int stack_top(stack* s) {
  int data = 0;

  // implement this function here

  return data;
}

/**
 * @brief Delete the stack object.
 *
 * @param s The stack object.
 */
void stack_delete(stack* s) {
  // implement this function here
}

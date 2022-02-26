#include <stdlib.h>
#include "stack.h"

/**
 * @brief  The stack class.
 *
 */
class Stack {
public:
  /**
   * @brief Construct a new Stack object.
   *
   * @param capacity The capacity of the stack.
   */
  Stack(size_t capacity) : m_capacity(capacity) , m_amount(0) {
    m_data = (int*) malloc(sizeof(int) * capacity);
  };

  /**
   * @brief Check if the stack is empty.
   *
   * @return true The stack is empty.
   * @return false The stack is not empty.
   */
  bool isEmpty() {
    return m_amount == 0;
  }

  /**
   * @brief Check if the stack is full.
   *
   * @return true The stack is full.
   * @return false The stack is not full.
   */
  bool isFull() {
    return m_amount == m_capacity;
  }

  /**
   * @brief Push the data onto the stack.
   *
   * @param data The data which will be pushed onto the stack.
   */
  void push(int data) {
    if (!isFull()) {
      m_data[m_amount] = data;
      m_amount++;
    }
  }

  /**
   * @brief Remove the data on top of the stack.
   *
   */
  void pop() {
    if (!isEmpty()) {
      m_amount--;
    }
  }

  /**
   * @brief Get the data on top of the stack.
   *
   * @return int The data on top of the stack, return 0 if the stack is empty.
   */
  int top() {
    int data = 0;

    if (!isEmpty()) {
      data = m_data[m_amount - 1];
    }

    return data;
  }

  /**
   * @brief Destroy the Stack object.
   *
   */
  ~Stack() {
    free(m_data);
  };

private:
  size_t m_capacity; /**< the capacity of the stack. */
  size_t m_amount; /**< amount of the data in the stack.  */
  int* m_data; /**< the data array. */
};

struct stack {
  Stack* object; /**< A pointer to the Stack object. */

  /**
   * @brief Construct a new stack object.
   *
   * @param capacity The capacity of the stack.
   */
  stack(size_t capacity) {
    object = new Stack(capacity);
  };

  /**
   * @brief Destroy the stack object.
   *
   */
  ~stack() {
    delete object;
  };
};

/**
 * @brief Construct a new stack object.
 *
 * @param capacity The capacity of the stack.
 * @return stack* A pointer to a stack object.
 */
stack* stack_new(size_t capacity) {
  return new stack(capacity);
}

/**
 * @brief Check if the stack is empty.
 *
 * @param s The stack object.
 * @return true The stack is empty.
 * @return false The stack is not empty.
 */
bool stack_is_empty(stack* s) {
  return s->object->isEmpty();
}

/**
 * @brief Check if the stack is full.
 *
 * @param s The stack object.
 * @return true The stack is full.
 * @return false The stack is not full.
 */
bool stack_is_full(stack* s) {
  return s->object->isFull();
}

/**
 * @brief Push the data onto the stack.
 *
 * @param s The stack object.
 * @param data The data which will be pushed onto the stack.
 */
void stack_push(stack* s, int data) {
  s->object->push(data);
}

/**
 * @brief Remove the data on top of the stack.
 *
 * @param s The stack object.
 */
void stack_pop(stack* s) {
  s->object->pop();
}

/**
 * @brief Get the data on top of the stack.
 *
 * @param s The stack object.
 * @return int The data on top of the stack, return 0 if the stack is empty.
 */
int stack_top(stack* s) {
  return s->object->top();
}

/**
 * @brief Delete the stack object.
 *
 * @param s The stack object.
 */
void stack_delete(stack* s) {
  delete s;
}

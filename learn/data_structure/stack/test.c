#include <stdio.h>
#include "stack.h"

typedef bool(*unit_test_t)();

bool test1() {
  stack* s = stack_new(1);

  if (!stack_is_empty(s) || stack_is_full(s))
    return false;

  if (stack_top(s) != 0)
    return 0;

  stack_push(s, 123);
  if (stack_is_empty(s) || !stack_is_full(s))
    return false;

  if (stack_top(s) != 123)
    return false;

  stack_pop(s);
  if (!stack_is_empty(s) || stack_is_full(s))
    return false;

  stack_delete(s);

  return true;
}

bool test2() {
  int data;
  const size_t capacity = 1e5;
  stack* s = stack_new(capacity);

  for (data = 0; data < capacity; data++) {
    stack_push(s, data);
    if (stack_top(s) != data)
      return false;
  }

  if (stack_is_empty(s) || !stack_is_full(s))
    return false;

  data = stack_top(s);
  stack_push(s, data + data);
  if (stack_top(s) != data)
    return false;

  for (data = capacity - 1; data >= 0; data--) {
    if (stack_is_empty(s) || stack_top(s) != data) {
      return false;
    }
    stack_pop(s);
  }

  if (!stack_is_empty(s) || stack_is_full(s))
    return false;

  stack_delete(s);

  return true;
}

bool test3() {
  int data = 0, count;
  const size_t capacity = 1e5;
  stack* s = stack_new(capacity);

  while (!stack_is_full(s)) {
    stack_push(s, data);

    if (stack_top(s) != data)
      return false;

    if (stack_top(s) % 23 == 0) {
      for (count = 0; count < 11; count++)
        stack_pop(s);
    }

    data++;
  }

  count = 0;
  while (!stack_is_empty(s)) {
    count++;
    stack_pop(s);
    if (count == 131) {
      for (data = 53; data > 0; data--) {
        stack_push(s, data);
        if (stack_top(s) != data)
          return false;
      }
      count = 0;
    }
  }

  stack_delete(s);

  return true;
}

int main(int argc, char* argv[]) {
  int test_case = 0;
  int success = 0, fail = 0;
  unit_test_t tests[] = {
    test1,
    test2,
    test3,
    NULL
  };

  while (tests[test_case]) {
    bool passed = tests[test_case]();

    if (passed) success++;
    else fail++;

    printf("Test %d ... %s\n", test_case + 1, passed ? "Pass" : "Fail");

    test_case++;
  }

  printf("--------------------------------\n");
  printf("%d passed, %d fail.\n", success, fail);

  return 0;
}

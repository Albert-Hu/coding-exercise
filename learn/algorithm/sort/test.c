#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "sort.h"

typedef bool(*unit_test_t)();

bool verify(int* data, int* answer, size_t size) {
  size_t index;

  for (index = 0; index < size; index++) {
    if (data[index] != answer[index])
      return false;
  }

  return true;
}

bool test1() {
  int* data;
  int* answer;
  size_t index;
  bool result;
  const size_t number = 100;

  data = (int*) malloc(sizeof(int) * number);
  answer = (int*) malloc(sizeof(int) * number);

  for (index = 0; index < number; index++)
    data[index] = answer[index] = 0;

  sort(data, number);

  result = verify(data, answer, number);

  free(data);
  free(answer);

  return result;
}

bool test2() {
  int* data;
  int* answer;
  size_t index;
  bool result;
  const size_t number = 100;

  data = (int*) malloc(sizeof(int) * number);
  answer = (int*) malloc(sizeof(int) * number);

  for (index = 0; index < number; index++)
    data[index] = answer[index] = index;

  sort(data, number);

  result = verify(data, answer, number);

  free(data);
  free(answer);

  return result;
}

bool test3() {
  int* data;
  int* answer;
  size_t index;
  bool result;
  const size_t number = 100;

  data = (int*) malloc(sizeof(int) * number);
  answer = (int*) malloc(sizeof(int) * number);

  for (index = 0; index < number; index++) {
    data[index] = number - index;
    answer[index] = index + 1;
  }

  sort(data, number);

  result = verify(data, answer, number);

  free(data);
  free(answer);

  return result;
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

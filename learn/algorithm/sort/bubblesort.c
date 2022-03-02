#include "sort.h"

/**
 * @brief Swap the variable a and b.
 *
 * @param a The variable a.
 * @param b The variable b.
 */
static void swap(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

/**
 * @brief Sort an integer array.
 *
 * @param data The integer array.
 * @param number The number of elements in the array.
 */
void sort(int* data, size_t number) {
  size_t current, next;

  for (current = 0; current < number; current++) {
    for (next = current + 1; next < number; next++) {
      if (data[next] < data[current]) {
        swap(&data[next], &data[current]);
      }
    }
  }
}

#ifndef _SORT_H_
#define _SORT_H_

#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Sort an integer array.
 *
 * @param data The integer array.
 * @param number The number of elements in the array.
 */
void sort(int* data, size_t number);

#ifdef __cplusplus
}
#endif

#endif /* _SORT_H_ */

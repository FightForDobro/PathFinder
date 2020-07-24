#include "libmx.h"

/**
 * @brief Applies the function f  for each element of the array arr given size
 * @author Denys Ushakov
 * @version a-1.0
 * @date 7/5/2020
 */
void mx_foreach(int *arr, int size, void(*f)(int)) {
    for (int i = 0; i < size; i++)
        f(arr[i]);
}

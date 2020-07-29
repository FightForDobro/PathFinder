#include "libmx.h"


/**
 * @brief Swap strings
 * @author Denys Ushakov
 * @version a-1.0
 * @date 7/6/2020
 */
void str_swap(char **str1, char **str2) {
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

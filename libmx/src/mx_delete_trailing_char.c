#include "libmx.h"

/**
 * Fucntion delete all trailing char
 * @param string string
 * @param chr char to delete
 * @return modified string
 */
char *mx_delete_trailing(char *string, char chr) {
    // ToDo: free memory
    char *result = mx_strnew(mx_strlen(string));

    for (int i = 0; string[i]; i++) {
        if (string[i] == chr && string[i + 1] == chr)
            while (string[i + 1] == chr)
                i++;

        result[mx_strlen(result)] = string[i];
    }

    return result;
}

#include "libmx.h"

/**
 * Function return size of line in file
 * @param filename
 * @param delim
 * @return size of line or -1 if file F_DNE
 */
static int get_line_size(const char *filename, char delim){
    char buf[1];
    int fd = open(filename, O_RDONLY);

    if (fd == -1) return -1;

    int size = 0;
    while (read(fd, &buf, 1))
    {
        if (buf[0] == delim)
        {
            close(fd);
            return size;
        }
        size++;
    }
    close(fd);
    return size;
}

/**
 * Creates string size of line and writes data from file
 * @param delim
 * @param filename
 * @return new_string or NULL in case of errors
 */
char  *mx_m_read_line(char delim, const char *filename) {
    int line_size = get_line_size(filename, delim);

    if (line_size == -1)
        return NULL;

    char *result = mx_strnew(line_size);
    int fd = open(filename, O_RDONLY);

    read(fd, result, line_size);
    close(fd);

    return result;
}
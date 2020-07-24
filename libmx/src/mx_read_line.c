#include "libmx.h"

/**
 * • reaches a delim character. The delimiter must not be returned with lineptr
 * • reaches the End Of File (EOF)A line is a sequence of characters before a delimiter.The function:
 * • works correctly with any file descriptor fd
 * • works correctly with any positive integer buf_size.buf_size must be passed to the function read as a parameter nbytes
 * • can read all data from the given fd  until the EOF, one line per call
 * • may have undefined behavior while reading from a binary file
 * @param lineptr pointer to string
 * @param buf_size how many bytes to read
 * @param delim delimiter char
 * @param fd file descriptor
 * @return
 * • returns the number of bytes that are written into lineptr
 * • returns -1  if EOF is reached and there is nothing to write inlineptr
 * • returns -2  in case of errors or fd  is invalid
 */
int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (fd == -1 || buf_size <= 0) return -2;
    static char *rem = NULL;
    int index;
    char *buf = mx_strnew(buf_size);
    int r;
    *lineptr += mx_strlen(*lineptr);
    while ((r = read(fd, buf, buf_size))) {
        if (rem == NULL)
            index = mx_get_char_index(buf, delim);
        else
            index = mx_get_char_index(rem, delim);
        if (index != -1) {
            if (rem != NULL) {
                buf = mx_strjoin(rem, buf);
                mx_strdel(&rem);
            }
            rem = mx_strdup(&buf[index + 1]);
            buf[index] = '\0';
            *lineptr = mx_strjoin(*lineptr, buf);
            break;
        } else {
            if (rem != NULL) {
                *lineptr = mx_strjoin(*lineptr, rem);
                mx_strdel(&rem);
            }
            buf[index] = '\0';
            *lineptr = mx_strjoin(*lineptr, buf);
        }
    }
    if (r < 0) return -1;
    return mx_strlen(*lineptr);
}

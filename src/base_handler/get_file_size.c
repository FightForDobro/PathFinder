// ToDo: Add this func to lib;

#include "pathfinder.h"
#include "base_handler.h"
#include "error_handler.h"

/**
 * Function calculates file size;
 * @param fd file descriptor;
 * @return file size
 */
int get_file_size(char *file_name)
{
    char buf[1];
    int file_size = 0;
    int fd = open(file_name, O_RDONLY);

    while (read(fd, &buf, 1)) // ToDo: Add var for buf_size(nbytes)
        file_size++;

    return file_size;
}

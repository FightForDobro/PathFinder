#include "pathfinder.h"
#include "error_handler.h"
#include "base_handler.h"

int main(int argc, char **argv)
{
    t_error **tErrors = init_errors();

    if (argc < 2)
        raise(tErrors[USAGE]);

    init_base(argv[1], tErrors);


//    while (1) {
//        char *result = mx_strnew(100);
//        scanf("%s", result);
//
//        printf("%d", mx_check_str_int(result));
//    }
//    int fd = open("../assets/correct", O_RDONLY);
//    char *new_string = mx_m_read_line('\n', "../assets/correct", fd, 0);
//    int c = 4;
//    int s = 0;
//    int fd = open("../assets/invalid_max_int", O_RDONLY);
//    char *new_string;
//    while (c--) {
//        new_string = mx_m_read_line('\n', "../assets/invalid_max_int", fd, s++);
//    }

    return 0;
}

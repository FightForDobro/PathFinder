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

    return 0;
}

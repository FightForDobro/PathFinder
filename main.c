#include "pathfinder.h"
#include "error_handler.h"
#include "base_handler.h"

int main(int argc, char **argv)
{
    t_error **tErrors = init_errors();

    if (argc < 2)
        raise(tErrors[USAGE]);

    init_base(argv[1], tErrors);

    return 0;
}

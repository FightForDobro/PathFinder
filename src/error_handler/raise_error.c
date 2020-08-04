#include "pathfinder.h"
#include "error_handler.h"

void raise(t_error *error)
{
    write(2, error->error_msg, error->error_msg_len);
    exit(1);
}
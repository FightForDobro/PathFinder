#ifndef PATHFINDER_ERROR_HANDLER_H
#define PATHFINDER_ERROR_HANDLER_H

#define ERROR_COUNT 4

enum e_error
{
    USAGE,
    F_DNE,
    F_EMPTY,
    FL_EMPTY,
    NL_INV,
    NOI_INV,
    DUP_B,
    SUM_MMI
};

typedef struct s_error
{
    enum e_error error_id;
    char *error_msg;
    int error_msg_len;
}              t_error;

t_error **init_errors();
void raise(t_error *error);

#endif //PATHFINDER_ERROR_HANDLER_H

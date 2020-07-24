#include "pathfinder.h"
#include "error_handler.h"

/**
 * Initialize usage error
 * @return struct of usage error
 */
static t_error *init_usage()
{

    t_error *usage = malloc(sizeof(t_error));

    usage->error_id = USAGE;
    usage->error_msg = mx_strnew(sizeof(char) * 30);
    mx_strcat(usage->error_msg, "usage: ./pathfinder [filename]");
    usage->error_msg_len = mx_strlen(usage->error_msg);

    return usage;
}

/**
 * Initialize f_dne error
 * @return struct of f_dne error
 */
static t_error *init_f_dne(char *file_name)
{
    t_error *f_dne = malloc(sizeof(t_error));

    f_dne->error_id = F_DNE;
    f_dne->error_msg = mx_strnew(sizeof(char) * (28 + mx_strlen(file_name)));
    mx_strcat(f_dne->error_msg, "error: file "); // ToDo: Make func create string
    mx_strcat(f_dne->error_msg, file_name);
    mx_strcat(f_dne->error_msg, " does not exist");
    f_dne->error_msg_len = mx_strlen(f_dne->error_msg);

    return f_dne;
}

/**
 * Initialize f_empty error
 * @return struct of f_empty error
 */
static t_error *init_f_empty(char *file_name)
{
    t_error *f_empty = malloc(sizeof(t_error));

    f_empty->error_id = F_EMPTY;
    f_empty->error_msg = mx_strnew(sizeof(char) * (28 + mx_strlen(file_name))); // ToDo: Make func create string
    mx_strcat(f_empty->error_msg, "error: file ");
    mx_strcat(f_empty->error_msg, file_name);
    mx_strcat(f_empty->error_msg, " is empty");
    f_empty->error_msg_len = mx_strlen(f_empty->error_msg);

    return f_empty;
}

/**
 * Initialize all error structs
 * @return array of error structs
 */
t_error **init_errors(int argc, char **argv)
{
    t_error **tErros= malloc(sizeof(t_error) * ERROR_COUNT);

    tErros[0] = init_usage();

    if (argc < 2)
        raise(tErros[USAGE]);

    tErros[1] = init_f_dne(argv[1]);
    tErros[2] = init_f_empty(argv[1]);

    return tErros;
}

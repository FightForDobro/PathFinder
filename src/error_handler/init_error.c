#include "pathfinder.h"
#include "error_handler.h"

/**
 * Initialize usage error
 * @return struct of usage error
 */
static t_error *init_usage()
{

    t_error *usage = malloc(sizeof(t_error));
    char *parts[] = {"usage: ./pathfinder [filename]"};

    usage->error_id = USAGE;
    usage->error_msg = mx_makestring(parts, 1);
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
    char *parts[] = {"error: file ", file_name, " does not exist"};

    f_dne->error_id = F_DNE;
    f_dne->error_msg = mx_makestring(parts, 3);
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
    char *parts[] = {"error: file ", file_name, " is empty"};

    f_empty->error_id = F_EMPTY;
    f_empty->error_msg = mx_makestring(parts, 3);
    f_empty->error_msg_len = mx_strlen(f_empty->error_msg);

    return f_empty;
}

static t_error *init_first_line_empty()
{
    t_error *fl_empty = malloc(sizeof(t_error));
    char *parts[] = {"error: line 1 is not valid"};

    fl_empty->error_id = FL_EMPTY;
    fl_empty->error_msg = mx_makestring(parts, 1);
    fl_empty->error_msg_len = mx_strlen(fl_empty->error_msg);

    return fl_empty;
}

t_error *init_num_line_invalid(int line_num)
{
    t_error *nl_invalid = malloc(sizeof(t_error));
    char *line_num_s = mx_itoa(line_num);
    char *parts[] = {"error: line ", line_num_s, " is not valid"}; // ToDo: Free that memory

    nl_invalid->error_id = NL_INV;
    nl_invalid->error_msg = mx_makestring(parts, 3);
    nl_invalid->error_msg_len = mx_strlen(nl_invalid->error_msg);

    mx_strdel(&line_num_s);

    return nl_invalid;
}

static t_error *init_invalid_number_of_islands()
{
    t_error *noi_invalid = malloc(sizeof(t_error));
    char *parts[] = {"error: invalid number of islands"};

    noi_invalid->error_id = NOI_INV;
    noi_invalid->error_msg = mx_makestring(parts, 1);
    noi_invalid->error_msg_len = mx_strlen(noi_invalid->error_msg);

    return noi_invalid;
}

static t_error *init_duplicate_bridges()
{
    t_error *dup_bridges = malloc(sizeof(t_error));
    char *parts[] = {"error: duplicate bridges"};

    dup_bridges->error_id = DUP_B;
    dup_bridges->error_msg = mx_makestring(parts, 1);
    dup_bridges->error_msg_len = mx_strlen(dup_bridges->error_msg);

    return dup_bridges;
}

static t_error *init_sum_more_max_int()
{
    t_error *sum_mmi = malloc(sizeof(t_error));
    char *parts[] = {"error: sum of bridges lengths is too big"};

    sum_mmi->error_id = SUM_MMI;
    sum_mmi->error_msg = mx_makestring(parts, 1);
    sum_mmi->error_msg_len = mx_strlen(sum_mmi->error_msg);

    return sum_mmi;
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
    tErros[3] = init_first_line_empty();
    tErros[5] = init_invalid_number_of_islands();
    tErros[6] = init_duplicate_bridges();
    tErros[7] = init_sum_more_max_int();

    return tErros;
}

#include "pathfinder.h"
#include "base_handler.h"
#include "error_handler.h"

/**
 * Initialize file_part and error
 * @param filename Filename
 * @param tErros List of error structs
 * @return graph struct
 */
static t_graph *init_file_part(char *filename, t_error **tErros)
{
    t_graph *graph = malloc(sizeof(t_graph));

    graph->filename = filename;
    graph->fd = open(filename, O_RDONLY);

    graph->tErrors = tErros;

    if (graph->fd < 0)
        raise(graph->tErrors[F_DNE]);

    if ((graph->file_size = get_file_size(graph->filename)) == 0)
        raise(graph->tErrors[F_EMPTY]);

    return graph;
}

/**
 * Initialize graph part and check errors
 * @param graph Graph struct
 * @return graph struct
 */
static t_graph *init_graph_part(t_graph *graph)
{
    char *first_line = mx_m_read_line('\n', graph->filename, graph->fd, 0);

    if (!mx_is_number(first_line))
        raise(graph->tErrors[FL_EMPTY]);

    if ((graph->islands_count = mx_atoi(first_line)) <= 0)
        raise(graph->tErrors[FL_EMPTY]);

    char *file = mx_file_to_str(graph->filename);
    graph->line_count = mx_count_substr(file, "\n");
    mx_strdel(&file);
    graph->current_line = 1;
    return graph;
}

t_graph *init_base(char *filename, t_error **tErros)
{
    t_graph *graph = init_file_part(filename, tErros);
    graph = init_graph_part(graph);
    graph = validate_connections(graph);
    return graph;
}

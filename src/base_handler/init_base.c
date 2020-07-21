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

    return graph;
}

/**
 * Initialize graph part and check errors
 * @param graph Graph struct
 * @return graph struct
 */
static t_graph *init_graph_part(t_graph *graph)
{
    if (graph->fd < 0)
        raise(graph->tErrors[F_DNE]);

    if ((graph->file_size = get_file_size(graph->fd)) == 0)
        raise(graph->tErrors[F_EMPTY]);

    return graph;
}

t_graph *init_base(char *filename, t_error **tErros)
{
    t_graph *graph = init_file_part(filename, tErros);
    graph = init_graph_part(graph);

    return graph;
}

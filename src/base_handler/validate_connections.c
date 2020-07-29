#include "pathfinder.h"
#include "base_handler.h"
#include "error_handler.h"

static void validate_line(char *island_line)
{

    if (mx_count_words(island_line, ',') != 2)
        raise()

    char **islands = malloc(sizeof(char *) *);
}

void validate_connections(t_graph *graph)
{
    t_island **islands = malloc(sizeof(t_island) * graph->islands_count);

    int islands_count = 0;

    while (islands_count != graph->islands_count)
    {
        char *island_line = mx_m_read_line('\n', graph->filename, graph->fd, islands_count + 1);

    }
}


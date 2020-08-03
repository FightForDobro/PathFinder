#include "base_handler.h"
#include "error_handler.h"
#include "pathfinder.h"

void mx_reopen_file(t_graph **pGraph)
{
    t_graph *graph = *pGraph;
    graph->fd = open(graph->filename, O_RDONLY);
}
#ifndef PATHFINDER_BASE_HANDLER_H
#define PATHFINDER_BASE_HANDLER_H

#include "error_handler.h"

typedef struct s_island
{
    char *island_connect[2];
    long long bridge_length;
}              t_island;

typedef struct s_graph
{
    /* File parts */
    char *filename;
    int fd;
    int file_size;

    /* Graph parts */
    int islands_count;
    char **islands;
    t_island **islands_struct;

    long long distance_sum;

    /* Error parts */
    t_error **tErrors;

}              t_graph;

t_graph *init_base(char *filename, t_error **tErros);
t_graph *validate_connections(t_graph *graph);
void mx_reopen_file(t_graph **pGraph);

/* Utils */
int get_file_size(int fd);


#endif //PATHFINDER_BASE_HANDLER_H

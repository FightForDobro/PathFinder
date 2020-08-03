#include "pathfinder.h"
#include "base_handler.h"
#include "error_handler.h"

static void count_islands(t_graph *graph)
{
    int fd = open(graph->filename, O_RDONLY);
    char buf[1];
    int island_count = -1;

    while (read(fd, &buf, 1))
        if (buf[0] == '\n')
            island_count++;

    if (graph->islands_count != island_count)
        raise(graph->tErrors[NOI_INV]);
}

static bool compare_islands(t_island *island0, t_island *island1)
{
    return mx_strcmp(island0->island_connect[0], island1->island_connect[0]) == 0
           &&
           mx_strcmp(island0->island_connect[1], island1->island_connect[1]) == 0;
}

static void find_duplicate(t_graph *graph)
{
    for (int i = 0; i <= graph->islands_count; i++)
    {
        for (int j = i + 1; j <= graph->islands_count; j++)
        {
            if (compare_islands(graph->islands_struct[i], graph->islands_struct[j]))
                raise(graph->tErrors[DUP_B]);
        }
    }
}

static t_island *validate_line(char *island_line, t_graph *graph)
{
    if (mx_count_words(island_line, ',') != 2)
        raise(graph->tErrors[NL_INV]);

    char **line_parts = mx_strsplit(island_line, ','); // ToDo: Free that memory
    line_parts[2] = NULL;
    if (mx_count_words(line_parts[0], '-') != 2)
        raise(graph->tErrors[NL_INV]);

    char **island = mx_strsplit(line_parts[0], '-');
    island[2] = NULL;

    t_island *tIsland = malloc(sizeof(t_island));
    tIsland->island_connect[0] = mx_strnew(0);
    tIsland->island_connect[1] = mx_strnew(0);
    tIsland->island_connect[0] = mx_strjoin(tIsland->island_connect[0], island[0]);
    tIsland->island_connect[1] = mx_strjoin(tIsland->island_connect[1], island[1]);

    tIsland->bridge_length = mx_atoll(line_parts[1]);

    mx_del_strarr(&line_parts);
    mx_del_strarr(&island);

    return tIsland;
}

t_graph *validate_connections(t_graph *graph)
{
    t_island **islands = malloc(sizeof(t_island) * graph->islands_count);

    int islands_count = 0;

    while (islands_count != graph->islands_count)
    {
        char *island_line = mx_m_read_line('\n', graph->filename, graph->fd, islands_count + 1);
        islands[islands_count++] = validate_line(island_line, graph);
    }

    graph->islands_struct = islands;
    count_islands(graph);
    find_duplicate(graph);

    for (int i = 0; i <= islands_count; i++) {
        graph->distance_sum += graph->islands_struct[0]->bridge_length;
        if (graph->distance_sum > 2147483647)
            raise(graph->tErrors[SUM_MMI]);
    }

    return graph;
}


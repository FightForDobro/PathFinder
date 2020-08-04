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
    for (int i = 0; i < graph->islands_count; i++)
    {
        for (int j = i + 1; j < graph->islands_count; j++)
        {
            if (compare_islands(graph->islands_struct[i], graph->islands_struct[j]))
                raise(graph->tErrors[DUP_B]);
        }
    }
}

//static t_island *validate_line(char *island_line, t_graph *graph)
//{
//    graph->current_line += 1;
//    graph->tErrors[NL_INV] = init_num_line_invalid(graph->current_line);
//
//    if(!island_line || island_line == NULL || !*island_line)
//        raise(graph->tErrors[NL_INV]);
//
//    if (mx_count_words(island_line, ',') != 2)
//        raise(graph->tErrors[NL_INV]);
//
//    char **line_parts = mx_strsplit(island_line, ','); // ToDo: Free that memory
//
//    if (!mx_is_number(line_parts[1]))
//        raise(graph->tErrors[NL_INV]);
//
//    line_parts[2] = NULL;
//    if (mx_count_words(line_parts[0], '-') != 2 || mx_count_substr(line_parts[0], "-") != 1)
//        raise(graph->tErrors[NL_INV]);
//
//    char **island = mx_strsplit(line_parts[0], '-');
//
//    for (int i = 0; i < 2; i++)
//        if (!mx_isonlyalpha(island[i]))
//            raise(graph->tErrors[NL_INV]);
//
//    island[2] = NULL;
//
//    t_island *tIsland = malloc(sizeof(t_island));
//    tIsland->island_connect[0] = mx_strnew(0);
//    tIsland->island_connect[1] = mx_strnew(0);
//    tIsland->island_connect[0] = mx_strjoin(tIsland->island_connect[0], island[0]);
//    tIsland->island_connect[1] = mx_strjoin(tIsland->island_connect[1], island[1]);
//
//    tIsland->bridge_length = mx_atoll(line_parts[1]);
//
//    mx_del_strarr(&line_parts);
//    mx_del_strarr(&island);
//    //ToDo: Delete error
//    return tIsland;
//}

static t_island *validate_line(char *island_line, t_graph *graph)
{
    graph->current_line += 1;
    graph->tErrors[NL_INV] = init_num_line_invalid(graph->current_line);

    char **line_parts = mx_strsplit(island_line, ',');
    if (mx_char_arr_size(line_parts) != 2)
        raise(graph->tErrors[NL_INV]);

    if (!mx_is_number(line_parts[1]))
        raise(graph->tErrors[NL_INV]);

    char **island = mx_strsplit(line_parts[0], '-');
    if (mx_char_arr_size(island) != 2 || mx_count_substr(line_parts[0], "-") != 1)
        raise(graph->tErrors[NL_INV]);

    for (int i = 0; i < 2; i++)
        if (!mx_isonlyalpha(island[i]))
            raise(graph->tErrors[NL_INV]);

    t_island *tIsland = malloc(sizeof(t_island));
    tIsland->island_connect[0] = mx_strjoin("", island[0]);
    tIsland->island_connect[1] = mx_strjoin("", island[1]);
    tIsland->bridge_length = mx_atoll(line_parts[1]);

    mx_del_strarr(&line_parts);
    mx_del_strarr(&island);

    return tIsland;
}

t_graph *validate_connections(t_graph *graph)
{
    t_island **islands = malloc(sizeof(t_island) * graph->islands_count);
    int islands_count = 0;
    char *island_line = NULL;

    while (island_line || islands_count == 0)
    {
        island_line = mx_m_read_line('\n', graph->filename, graph->fd, islands_count + 1);
        islands[islands_count++] = validate_line(island_line, graph);
    }

    graph->islands_struct = islands;
    count_islands(graph);
    find_duplicate(graph);


    for (int i = 0; i < islands_count; i++) {
        graph->distance_sum += graph->islands_struct[i]->bridge_length;
        if (graph->distance_sum > 2147483647)
            raise(graph->tErrors[SUM_MMI]);
    }

    return graph;
}


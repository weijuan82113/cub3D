/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:46:27 by wchen             #+#    #+#             */
/*   Updated: 2023/10/22 23:14:50 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// t_graph	*graph_create(int vertex_count, char **map, int x)
// {
// 	t_graph	*graph;
// 	int		i;

// 	graph = malloc(sizeof(t_graph));
// 	if (!graph)
// 		exit(EXIT_FAILURE);
// 	graph->num_vertex = vertex_count;
// 	graph->adj_lsts = malloc(sizeof(t_node *) * vertex_count);
// 	if (!graph->adj_lsts)
// 		exit(EXIT_FAILURE);
// 	graph->visited = malloc(sizeof(int) * vertex_count);
// 	if (!graph->visited)
// 		exit(EXIT_FAILURE);
// 	i = 0;
// 	while (i < vertex_count)
// 	{
// 		graph->adj_lsts[i] = NULL;
// 		if (map[i / x][i % x] == '1')
// 			graph->visited[i] = 1;
// 		else
// 			graph->visited[i] = 0;
// 		i++;
// 	}
// 	return (graph);
// }

// bool bfs_check(t_g_board *g)
// {
// 	t_graph *graph;
// 	t_bfs	*bfs;

// 	graph = graph_create(g->m_info->h * g->m_info->w, char **map, int x)

// }

void fill_the_map_array(char *content, char *map, int w)
{
	int i;

	i = 0;
	while(i < w && content[i] && content[i] != '\n')
	{
		map[i] = content[i];
		i ++;
	}
	while (i < w)
	{
		map[i] = ' ';
		i ++;
	}
}

bool initial_map_array(t_g_board *g)
{
	t_node	*temp_node;
	int	i;

	g->m_info->map = malloc(sizeof(char*) * (*g->m_info->h + 1));
	if (!g->m_info->map)
		return (false);
	i = 0;
	temp_node = g->line_lst;
	while(temp_node)
	{
		g->m_info->map[i] = malloc(sizeof(char) * (*g->m_info->w + 1));
		if (!g->m_info->map[i])
			return (false);
		fill_the_map_array(temp_node->content, g->m_info->map[i], *g->m_info->w);
		temp_node = temp_node -> next;
		i ++;
	}
	g->m_info->map[i] = NULL;
	return (true);
}

void debug_print_map_array(char **map)
{
	int i;

	printf("debug_print_map_array\n");
	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i ++;
	}
}

bool map_check(t_g_board *g_board)
{
	if (wall_check(g_board->line_lst, *g_board->m_info->h))
		return (ft_error(WALL_ERR));
	if (!initial_map_array(g_board))
		return (ft_error(INITIAL_MAP_ERR));
	debug_print_map_array(g_board->m_info->map);
	// if (bfs_check(g_board))
	// 	return (ft_error(WALL_ERR));
	return (false);
}

bool create_map_array(t_g_board *g_board)
{
	if(*g_board->m_info->h < 3 || *g_board->m_info->w < 3)
		return (ft_error(MAP_SIZE_ERR));
	if(map_check(g_board))
		return(true);
	return (false);
}
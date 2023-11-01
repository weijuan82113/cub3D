/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_bfs_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:17:29 by wchen             #+#    #+#             */
/*   Updated: 2023/11/01 23:24:17 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_graph	*graph_malloc(int vertex_count)
{
	t_graph	*graph;

	graph = malloc(sizeof(t_graph));
	if (!graph)
		return (NULL);
	graph->num_vertex = vertex_count;
	graph->adj_lsts = malloc(sizeof(t_node *) * vertex_count);
	if (!graph->adj_lsts)
		return (NULL);
	graph->visited = malloc(sizeof(int) * vertex_count);
	if (!graph->visited)
		return (NULL);
	return (graph);
}

t_graph	*graph_create(int vertex_count, char **map, int x)
{
	t_graph	*graph;
	int		i;

	graph = graph_malloc(vertex_count);
	if (!graph)
		return (NULL);
	i = 0;
	while (i < vertex_count)
	{
		graph->adj_lsts[i] = NULL;
		if (map[i / x][i % x] == '1')
			graph->visited[i] = 1;
		else if (map[i / x][i % x] == ' ')
			graph->visited[i] = 2;
		else
			graph->visited[i] = 0;
		i++;
	}
	return (graph);
}

bool	wall_bfs_check(t_g_board *g)
{
	t_graph	*graph;

	// bool	bfs_result;
	// bfs_result = false;
	graph = graph_create(*g->m_info->h * *g->m_info->w, g->m_info->map,
			*g->m_info->w);
	if (!graph)
	{
		free_graph(graph);
		return (ft_error(GRAPH_INITIAL_ERR));
	}
	if (edge_initial(graph, g))
	{
		free_graph(graph);
		return (ft_error(EDGE_INITIAL_ERR));
	}
	if (bfs_check(graph, *g->p_position))
		return (true);
	return (false);
	//bebug code
	// print_vidited (graph->visited, *g->m_info->h * *g->m_info->w,
	// 		*g->m_info->w);
	// bfs_result = bfs_check(graph, *g->p_position);
	// print_vidited (graph->visited, *g->m_info->h * *g->m_info->w,
	// 		*g->m_info->w);
	// print_graph(graph);
	// free_graph(graph);
	// if(bfs_result)
	// 	return (ft_error(WALL_ERR));
	// return (false);
}

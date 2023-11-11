/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_bfs_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:17:29 by wchen             #+#    #+#             */
/*   Updated: 2023/11/11 21:52:43 by kitsuki          ###   ########.fr       */
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
	{
		free(graph);
		return (NULL);
	}
	graph->visited = malloc(sizeof(int) * vertex_count);
	if (!graph->visited)
	{
		free(graph->adj_lsts);
		free(graph);
		return (NULL);
	}
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

	errno = 0;
	graph = graph_create(*g->m_info->h * *g->m_info->w, g->m_info->map,
			*g->m_info->w);
	if (!graph)
		return (ft_error(GRAPH_INITIAL_ERR));
	if (edge_initial(graph, g))
	{
		free_graph(graph);
		return (ft_error(EDGE_INITIAL_ERR));
	}
	if (bfs_check(graph, *g->p_position, false))
	{
		free_graph(graph);
		return (true);
	}
	free_graph(graph);
	return (false);
}

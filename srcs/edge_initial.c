/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_initial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:21:09 by wchen             #+#    #+#             */
/*   Updated: 2023/11/12 21:11:03 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	edge_add(t_graph *graph, int src, int dest)
{
	t_node	*new_node;
	int		*content;

	content = malloc(sizeof(int));
	if (!content)
		return (true);
	*content = dest;
	new_node = ft_lstnew(content);
	if (!new_node)
	{
		free(content);
		return (true);
	}
	if (graph->adj_lsts[src] == NULL)
		graph->adj_lsts[src] = new_node;
	else
		ft_lstadd_back(&graph->adj_lsts[src], new_node);
	return (false);
}

static bool	cont_direction(char **map, int x, t_graph *graph, int src)
{
	int		dest;
	bool	stop_flag;

	stop_flag = false;
	dest = src - x + 1;
	if (map[dest / x][dest % x] != '1' && !stop_flag)
		stop_flag = edge_add(graph, src, dest);
	dest = src - x - 1;
	if (map[dest / x][dest % x] != '1' && !stop_flag)
		stop_flag = edge_add(graph, src, dest);
	dest = src + x + 1;
	if (map[dest / x][dest % x] != '1' && !stop_flag)
		stop_flag = edge_add(graph, src, dest);
	dest = src + x - 1;
	if (map[dest / x][dest % x] != '1' && !stop_flag)
		stop_flag = edge_add(graph, src, dest);
	return (stop_flag);
}

bool	edge_add_direction(t_graph *graph, int src, t_g_board *g)
{
	char	**map;
	int		dest;
	int		x;
	bool	stop_flag;

	map = g->m_info->map;
	x = g->m_info->w;
	stop_flag = false;
	dest = src - x;
	if (map[dest / x][dest % x] != '1' && !stop_flag)
		stop_flag = edge_add(graph, src, dest);
	dest = src + x;
	if (map[dest / x][dest % x] != '1' && !stop_flag)
		stop_flag = edge_add(graph, src, dest);
	dest = src - 1;
	if (map[dest / x][dest % x] != '1' && !stop_flag)
		stop_flag = edge_add(graph, src, dest);
	dest = src + 1;
	if (map[dest / x][dest % x] != '1' && !stop_flag)
		stop_flag = edge_add(graph, src, dest);
	if (!stop_flag)
		stop_flag = cont_direction(map, x, graph, src);
	if (!stop_flag)
		return (false);
	return (true);
}

bool	edge_initial(t_graph *graph, t_g_board *g)
{
	int		i;
	char	**map;
	bool	stop_flag;

	i = 0;
	map = g->m_info->map;
	while (i < g->m_info->w * g->m_info->h)
	{
		if (map[i / g->m_info->w][i % g->m_info->w] != ' ' && map[i
			/ g->m_info->w][i % g->m_info->w] != '1')
			stop_flag = edge_add_direction(graph, i, g);
		if (stop_flag == true)
			return (true);
		i++;
	}
	return (false);
}

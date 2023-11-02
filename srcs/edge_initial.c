/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_initial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:21:09 by wchen             #+#    #+#             */
/*   Updated: 2023/11/01 23:29:49 by wchen            ###   ########.fr       */
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
		return (true);
	if (graph->adj_lsts[src] == NULL)
		graph->adj_lsts[src] = new_node;
	else
		ft_lstadd_back(&graph->adj_lsts[src], new_node);
	return (false);
}

bool	edge_add_direction(t_graph *graph, int src, t_g_board *g)
{
	char	**map;
	int		dest;
	int		x;
	bool	stop_flag;

	map = g->m_info->map;
	x = *g->m_info->w;
	stop_flag = false;
	dest = src - x; //top
	if (map[dest / x][dest % x] != '1' && !stop_flag)
		stop_flag = edge_add(graph, src, dest);
	dest = src + x; //bottom
	if (map[dest / x][dest % x] != '1' && !stop_flag)
		stop_flag = edge_add(graph, src, dest);
	dest = src - 1; //left
	if (map[dest / x][dest % x] != '1' && !stop_flag)
		stop_flag = edge_add(graph, src, dest);
	dest = src + 1; //right
	if (map[dest / x][dest % x] != '1' && !stop_flag)
		stop_flag = edge_add(graph, src, dest);
	dest = src - x + 1; //top right
	if (map[dest / x][dest % x] != '1' && !stop_flag)
		stop_flag = edge_add(graph, src, dest);
	dest = src - x - 1; //top left
	if (map[dest / x][dest % x] != '1' && !stop_flag)
		stop_flag = edge_add(graph, src, dest);
	dest = src + x + 1; //bottom right
	if (map[dest / x][dest % x] != '1' && !stop_flag)
		stop_flag = edge_add(graph, src, dest);
	dest = src + x - 1; //bottom left
	if (map[dest / x][dest % x] != '1' && !stop_flag)
		stop_flag = edge_add(graph, src, dest);
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
	while (i < *g->m_info->w * *g->m_info->h)
	{
		if (map[i / *g->m_info->w][i % *g->m_info->w] != ' ' && map[i
			/ *g->m_info->w][i % *g->m_info->w] != '1')
			stop_flag = edge_add_direction(graph, i, g);
		if (stop_flag == true)
			return (true);
		i++;
	}
	return (false);
}

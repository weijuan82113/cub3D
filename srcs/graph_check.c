/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:28:10 by wchen             #+#    #+#             */
/*   Updated: 2024/03/07 23:07:56 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_connect_space(t_node *adj_lsts, int *visited)
{
	int	p;

	while (adj_lsts)
	{
		p = *(int *)adj_lsts->content;
		if (visited[p] == 2)
			return (true);
		adj_lsts = adj_lsts -> next;
	}
	return (false);
}

bool	graph_check(t_graph *graph)
{
	int		i;

	i = 0;
	errno = 0;
	while (i < graph->num_vertex)
	{
		if (graph->visited[i] == 0)
			if (is_connect_space(graph->adj_lsts[i], graph->visited))
				return (ft_error(WALL_ERR));
		i ++;
	}
	return (false);
}

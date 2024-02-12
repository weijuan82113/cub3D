/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:28:10 by wchen             #+#    #+#             */
/*   Updated: 2024/02/12 23:43:26 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static bool	is_connect_space(t_node *adj_lsts, int *visited)
{
	int p;

	while(adj_lsts)
	{
		p = *(int *)adj_lsts->content;
		if (visited[p] == 2)
			return true;
		adj_lsts = adj_lsts -> next;
	}
	return false;
}

bool	graph_check(t_graph *graph, bool result)
{
	int		i;

	i = 0;
	errno = 0;
	while (i < graph->num_vertex && !result)
	{
		if (graph->visited[i] == 0)
			result = is_connect_space(graph->adj_lsts[i], graph->visited);
		i ++;
	}
	if (result)
		ft_error(WALL_ERR);
	return (result);
}

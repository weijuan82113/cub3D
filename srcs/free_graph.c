/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:08:21 by wchen             #+#    #+#             */
/*   Updated: 2023/10/29 20:23:40 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void free_graph(t_graph *graph)
{
	int i;

	if (!graph)
		return;
	if (!graph->adj_lsts)
		return;
	i = 0;
	while (i < graph->num_vertex)
	{
		if (graph->adj_lsts[i])
			ft_lstclear(&graph->adj_lsts[i], free);
		i ++;
	}
	free(graph->adj_lsts);
	free(graph->visited);
	free(graph);
}
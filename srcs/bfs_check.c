/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:28:10 by wchen             #+#    #+#             */
/*   Updated: 2023/11/03 22:44:02 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	bfs_initial(t_bfs *bfs, t_graph *graph, int start)
{
	errno = 0;
	bfs->q = ft_create_queue();
	graph->visited[start] = 1;
	bfs->start_vertex = malloc(sizeof(int));
	if (!bfs->start_vertex)
		return (ft_error(MALLOC_ERR));
	*bfs->start_vertex = start;
	ft_enqueue(bfs->q, bfs->start_vertex);
	return (false);
}

bool	enqueue_not_visied_lst(t_bfs *bfs, t_graph *graph, int content)
{
	bfs->adj_vertex = malloc(sizeof(int));
	if (!bfs->adj_vertex)
		return (ft_error(MALLOC_ERR));
	*bfs->adj_vertex = content;
	graph->visited[*bfs->adj_vertex] = 1;
	ft_enqueue(bfs->q, bfs->adj_vertex);
	return (false);
}

bool	bfs_check(t_graph *graph, int start, bool result)
{
	t_bfs	bfs;

	errno = 0;
	if (bfs_initial(&bfs, graph, start))
		return (true);
	while (bfs.q->rear != NULL)
	{
		bfs.current_vertex = *(int *)bfs.q->front->content;
		bfs.temp = graph->adj_lsts[bfs.current_vertex];
		while (bfs.temp)
		{
			if (graph->visited[*(int *)bfs.temp->content] == 0)
			{
				if (enqueue_not_visied_lst(&bfs, graph,
						*(int *)bfs.temp->content))
					result = true;
			}
			else if (graph->visited[*(int *)bfs.temp->content] == 2)
				result = ft_error(WALL_ERR);
			bfs.temp = bfs.temp->next;
		}
		ft_dequeue(bfs.q);
	}
	free(bfs.q);
	return (result);
}

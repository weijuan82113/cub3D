/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:28:10 by wchen             #+#    #+#             */
/*   Updated: 2023/11/08 00:05:26 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	bfs_initial(t_queue **bfs, t_graph *graph, int start)
{
	int	*start_vertex;

	errno = 0;
	*bfs = ft_create_queue();
	if (!(*bfs))
		return (ft_error(MALLOC_ERR));
	graph->visited[start] = 1;
	start_vertex = malloc(sizeof(int));
	if (!start_vertex)
	{
		free(*bfs);
		*bfs = NULL;
		return (ft_error(MALLOC_ERR));
	}
	*start_vertex = start;
	ft_enqueue(*bfs, start_vertex);
	if (!(*bfs)->rear)
	{
		free(*bfs);
		*bfs = NULL;
		free(start_vertex);
		return (ft_error(MALLOC_ERR));
	}
	return (false);
}

static bool	enqueue_not_visied_lst(t_queue *bfs, t_graph *graph, int content)
{
	int	*adj_vertex;

	adj_vertex = malloc(sizeof(int));
	if (!adj_vertex)
		return (ft_error(MALLOC_ERR));
	*adj_vertex = content;
	graph->visited[*adj_vertex] = 1;
	ft_enqueue(bfs, adj_vertex);
	if (!bfs->rear)
	{
		free(adj_vertex);
		return (ft_error(MALLOC_ERR));
	}
	return (false);
}

bool	bfs_check(t_graph *graph, int start, bool result)
{
	t_queue	*bfs;
	t_node	*temp;

	errno = 0;
	if (bfs_initial(&bfs, graph, start))
		return (true);
	while (bfs->rear != NULL)
	{
		temp = graph->adj_lsts[*(int *)bfs->front->content];
		while (temp)
		{
			if (graph->visited[*(int *)temp->content] == 0)
			{
				if (enqueue_not_visied_lst(bfs, graph,
						*(int *)temp->content))
					result = true;
			}
			else if (graph->visited[*(int *)temp->content] == 2)
				result = ft_error(WALL_ERR);
			temp = temp->next;
		}
		ft_dequeue(bfs);
	}
	free(bfs);
	return (result);
}

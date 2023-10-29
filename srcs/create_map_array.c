/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:46:27 by wchen             #+#    #+#             */
/*   Updated: 2023/10/29 20:24:09 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_graph	*graph_create(int vertex_count, char **map, int x)
{
	t_graph	*graph;
	int		i;

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
	bool 	stop_flag;

	map = g->m_info->map;
	x = *g->m_info->w;
	stop_flag = false;
	dest = src - x;//top
	if (map[dest / x][dest % x] != '1' && !stop_flag)
		stop_flag = edge_add(graph, src, dest);
	dest = src + x;//bottom
	if (map[dest / x][dest % x] != '1' && !stop_flag)
		stop_flag = edge_add(graph, src, dest);
	dest = src - 1;//left
	if (map[dest / x][dest % x] != '1' && !stop_flag)
		stop_flag = edge_add(graph, src, dest);
	dest = src + 1;//right
	if (map[dest / x][dest % x] != '1' && !stop_flag)
		stop_flag = edge_add(graph, src, dest);
	dest = src - x + 1;//top right
	if (map[dest / x][dest % x] != '1' && !stop_flag)
		stop_flag = edge_add(graph, src, dest);
	dest = src - x - 1;//top left
	if (map[dest / x][dest % x] != '1' && !stop_flag)
		stop_flag = edge_add(graph, src, dest);
	dest = src + x + 1;//bottom right
	if (map[dest / x][dest % x] != '1' && !stop_flag)
		stop_flag = edge_add(graph, src, dest);
	dest = src + x - 1;//bottom left
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
		if (map[i / *g->m_info->w][i % *g->m_info->w] != ' ' && map[i / *g->m_info->w][i % *g->m_info->w] != '1')
			stop_flag = edge_add_direction(graph, i, g);
		if (stop_flag == true)
			return (true);
		i++;
	}
	return (false);
}

bool	bsq_check(t_graph *graph, int start)
{
	t_bfs	bfs;

	bfs.q = ft_create_queue();
	graph->visited[start] = 1;
	bfs.start_vertex = malloc(sizeof(int));
	*bfs.start_vertex = start;
	ft_enqueue(bfs.q, bfs.start_vertex);
	while (bfs.q->rear != NULL)
	{
		bfs.current_vertex = *(int *)bfs.q->front->content;
		bfs.temp = graph->adj_lsts[bfs.current_vertex];
		while (bfs.temp)
		{
			if (graph->visited[*(int *)bfs.temp->content] == 0)
			{
				bfs.adj_vertex = malloc(sizeof(int));
				*bfs.adj_vertex = *(int *)bfs.temp->content;
				graph->visited[*bfs.adj_vertex] = 1;
				ft_enqueue(bfs.q, bfs.adj_vertex);
			}
			else if (graph->visited[*(int *)bfs.temp->content] == 2)
				return (true);
			bfs.temp = bfs.temp->next;
		}
		ft_dequeue(bfs.q);
	}
	free(bfs.q);
	return (false);
}

//Print the graph
void	print_graph(t_graph *graph)
{
	int		v;
	t_node	*temp;

	for (v = 0; v < graph->num_vertex; v++)
	{
		temp = graph->adj_lsts[v];
		printf("\n Vertex %d\n: ", v);
		while (temp)
		{
			printf("%d -> ", *(int *)temp->content);
			temp = temp->next;
		}
		printf("\n");
	}
}

void print_vidited(int *visited,int size, int x)
{
	int i;

	i = 0;
	printf("-------started-------\n");fflush(stdout);
	while (i < size)
	{
		//printf("i : %d\n", i);
		printf("%d", visited[i]);fflush(stdout);
		if(i % x == x-1)
			printf("\n");fflush(stdout);
		i ++;
	}
	printf("-------finished-------\n");fflush(stdout);
}

bool wall_bfs_check(t_g_board *g)
{
	t_graph *graph;
	bool	bsq_result;

	bsq_result = false;
	graph = graph_create(*g->m_info->h * *g->m_info->w, g->m_info->map, *g->m_info->w);
	if (!graph)
		return (ft_error(GRAPH_INITIAL_ERR));
	if (edge_initial(graph, g))
		return (ft_error(EDGE_INITIAL_ERR));
	//print_graph(graph);
	bsq_result = bsq_check(graph, *g->p_position);
	//print_vidited (graph->visited, *g->m_info->h * *g->m_info->w, *g->m_info->w);
	if(bsq_result)
		return (ft_error(WALL_ERR));
	return (false);
	//bebug
	// if (bsq_check(graph, *g->p_position))
	// 	return (ft_error(WALL_ERR));
	// return (false);
}

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
	if (wall_bfs_check(g_board))
		return (true);
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
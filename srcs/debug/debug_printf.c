/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:04:18 by wchen             #+#    #+#             */
/*   Updated: 2023/11/12 21:14:30 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_print_imglst(t_img_node *img_lst)
{
	while (img_lst)
	{
		printf("Print Image\n");
		printf("obj:%s\n", img_lst->obj);
		printf("img_path:%s\n", img_lst->img_path);
		printf("p_img:%p\n", img_lst->p_img);
		printf("h:%d\n", img_lst->h);
		printf("w:%d\n", img_lst->w);
		img_lst = img_lst->next;
	}
}

void	debug_print_colorlst(t_color_node *color_lst)
{
	while (color_lst)
	{
		printf("Print Color\n");
		printf("obj:%s\n", color_lst->obj);
		printf("rgb_int:%d\n", color_lst->rgb_int);
		color_lst = color_lst->next;
	}
}

void	debug_print_linelst(t_g_board *g_board)
{
	t_node	*temp_line;

	temp_line = g_board->line_lst;
	printf("print line content:\n");
	while (temp_line)
	{
		printf("%s\n", (char *)temp_line->content);
		temp_line = temp_line->next;
	}
	printf("w:%d\n", g_board->m_info->w);
	printf("h:%d\n", g_board->m_info->h);
	printf("position:%d\n", g_board->p_position);
}

//Print the graph
void	print_graph(t_graph *graph)
{
	int		v;
	t_node	*temp;

	v = 0;
	while (v < graph->num_vertex)
	{
		temp = graph->adj_lsts[v];
		printf("\n Vertex %d\n: ", v);
		while (temp)
		{
			printf("%d -> ", *(int *)temp->content);
			temp = temp->next;
		}
		printf("\n");
		v++;
	}
}

//Print the visited place(bfs algorithm visited point)
void	print_vidited(int *visited, int size, int x)
{
	int	i;

	i = 0;
	printf("-------started-------\n");
	fflush(stdout);
	while (i < size)
	{
		printf("%d", visited[i]);
		fflush(stdout);
		if (i % x == x - 1)
			printf("\n");
		fflush(stdout);
		i++;
	}
	printf("-------finished-------\n");
	fflush(stdout);
}

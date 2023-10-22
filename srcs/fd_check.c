/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:42:47 by wchen             #+#    #+#             */
/*   Updated: 2023/10/22 23:14:38 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void debug_print_imglst(t_g_board *g_board)
{
	t_img	*temp_img;

	temp_img = g_board->img_lst;
	while (temp_img)
	{
		printf("obj:%s\n", temp_img->obj);
		printf("img_path:%s\n", temp_img->img_path);
		temp_img = temp_img->next;
	}
}

void debug_print_linelst(t_g_board *g_board)
{
	t_node	*temp_line;

	temp_line = g_board->line_lst;
	printf("print line content:\n");
	while (temp_line)
	{
		printf("%s\n", (char *)temp_line->content);
		temp_line = temp_line->next;
	}
}

void game_board_initial(t_g_board *g_board)
{
	g_board->t_count = 0;
	g_board->line_lst = NULL;
	g_board->img_lst = NULL;
	g_board->m_info = (t_map_info *)malloc(sizeof(t_map_info));
	g_board->m_info->h = (int *)malloc(sizeof(int));
	if (!g_board->m_info->h)
		printf("malloc is failure\n");
	*g_board->m_info->h = 0;
	g_board->m_info->w = (int *)malloc(sizeof(int));
	if (!g_board->m_info->w)
		printf("malloc is failure\n");
	*g_board->m_info->w = 0;
}

bool fd_check(int fd)
{
	char		*line;
	int			index;
	t_g_board	*g_board;

	line = NULL;
	index = 0;
	g_board = malloc(sizeof(*g_board));
	if (!g_board)
		return (true);
	game_board_initial(g_board);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (line_check(line, g_board))
			return (true);
		printf("%s",line);
		index ++;
	}
	debug_print_imglst(g_board);
	debug_print_linelst(g_board);
	if (create_map_array(g_board))
		return (true);
	return (false);
}


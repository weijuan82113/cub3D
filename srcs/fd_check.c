/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:42:47 by wchen             #+#    #+#             */
/*   Updated: 2023/10/28 17:45:47 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void debug_print_imglst(t_img_node *img_lst)
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

void debug_print_colorlst(t_color_node *color_lst)
{
	while (color_lst)
	{
		printf("Print Color\n");
		printf("obj:%s\n", color_lst->obj);
		printf("color:%s\n", color_lst->rbg);
		color_lst = color_lst->next;
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
	printf("x:%d\n", *g_board->x);
	printf("y:%d\n", *g_board->y);
	printf("w:%d\n", *g_board->m_info->w);
	printf("h:%d\n", *g_board->m_info->h);
	printf("position:%d\n", *g_board->p_position);
}

bool fd_check(t_mlx *mlx, int fd)
{
	char		*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (line_check(line, mlx))
			return (true);
		printf("%s",line);
	}
	*mlx->g->p_position = *mlx->g->y * *mlx->g->m_info->w + *mlx->g->x;
	debug_print_linelst(mlx->g);
	debug_print_imglst(mlx->g->img_lst);
	debug_print_colorlst(mlx->g->color_lst);
	if (create_map_array(mlx->g))
		return (true);
	return (false);
}


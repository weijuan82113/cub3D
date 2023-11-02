/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:42:47 by wchen             #+#    #+#             */
/*   Updated: 2023/11/02 22:09:48 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	fd_check(t_mlx *mlx, int fd)
{
	char	*line;
	int		x;
	int		y;

	x = -1;
	y = -1;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line_check(line, mlx, &x, &y))
			return (true);
		free(line);
	}
	if (x == -1 || y == -1)
		return (ft_error(PLAYER_POSITON_ERR));
	*mlx->g->p_position = y * *mlx->g->m_info->w + x;
	// debug_print_linelst(mlx->g);
	// debug_print_imglst(mlx->g->img_lst);
	// debug_print_colorlst(mlx->g->color_lst);
	if (create_map_array(mlx->g))
		return (true);
	return (false);
}

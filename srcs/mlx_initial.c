/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initial.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:37:32 by wchen             #+#    #+#             */
/*   Updated: 2023/10/29 21:37:12 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool game_board_initial(t_g_board *g_board)
{
	g_board->t_count = 0;
	g_board->line_lst = NULL;
	g_board->img_lst = NULL;

	g_board->line_lst = NULL;
	g_board->img_lst = NULL;
	g_board->color_lst = NULL;
	if (!(g_board->m_info = malloc(sizeof(t_map_info))))
		return (ft_error(MALLOC_ERR));
	if (!(g_board->m_info->h = (int *)malloc(sizeof(int))))
		return (ft_error(MALLOC_ERR));
	*g_board->m_info->h = 0;
	if (!(g_board->m_info->w = (int *)malloc(sizeof(int))))
		return (ft_error(MALLOC_ERR));
	*g_board->m_info->w = 0;
	if (!(g_board->p_position = (int *)malloc(sizeof(int))))
		return (ft_error(MALLOC_ERR));
	*g_board->p_position = 0;
	return (false);
}

t_mlx *mlx_initial()
{
	t_mlx		*mlx;

	if (!(mlx = malloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->p_mlx = mlx_init()))
		return (NULL);
	if (!(mlx->p_win = mlx_new_window(mlx->p_mlx, win_x, win_y,"Cub3D")))
		return (NULL);
	if (!(mlx->g = malloc(sizeof(t_g_board))))
		return (NULL);
	if (game_board_initial(mlx->g))
		return (NULL);
	return (mlx);
}
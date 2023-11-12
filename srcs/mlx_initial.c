/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initial.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:37:32 by wchen             #+#    #+#             */
/*   Updated: 2023/11/12 21:54:18 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	g_init(t_g_board *g_board)
{
	g_board->line_lst = NULL;
	g_board->img_lst = NULL;
	g_board->color_lst = NULL;
	g_board->p_position = 0;
	g_board->t_count = 0;
	g_board->identifier = NULL;
}

static void	map_info_init(t_map_info *m_info)
{
	m_info->map = NULL;
	m_info->h = 0;
	m_info->w = 0;
}

static bool	game_board_initial(t_g_board *g_board)
{
	g_init(g_board);
	g_board->m_info = malloc(sizeof(t_map_info));
	if (!g_board->m_info)
		return (ft_error(MALLOC_ERR));
	map_info_init(g_board->m_info);
	g_board->identifier = ft_split(IDENTIFIER, '/');
	if (!g_board->identifier)
		return (ft_error(MALLOC_ERR));
	return (false);
}

bool	mlx_initial(t_mlx **dst)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	*dst = mlx;
	if (!mlx)
		return (true);
	mlx->p_mlx = mlx_init();
	if (!mlx->p_mlx)
		return (ft_error(MLX_INIT_ERR));
	mlx->p_win = mlx_new_window(mlx->p_mlx, WIN_X, WIN_Y, "Cub3D");
	if (!mlx->p_win)
		return (ft_error(MLX_INIT_ERR));
	mlx->g = malloc(sizeof(t_g_board));
	if (!mlx->g)
		return (ft_error(MALLOC_ERR));
	if (game_board_initial(mlx->g))
		return (true);
	return (false);
}

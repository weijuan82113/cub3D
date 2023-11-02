/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initial.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:37:32 by wchen             #+#    #+#             */
/*   Updated: 2023/11/02 21:20:35 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	g_init(t_g_board *g_board)
{
	g_board->t_count = 0;
	g_board->line_lst = NULL;
	g_board->img_lst = NULL;
	g_board->line_lst = NULL;
	g_board->img_lst = NULL;
	g_board->color_lst = NULL;
}

bool	game_board_initial(t_g_board *g_board)
{
	g_init(g_board);
	g_board->m_info = malloc(sizeof(t_map_info));
	if (!g_board->m_info)
		return (ft_error(MALLOC_ERR));
	g_board->m_info->h = (int *)malloc(sizeof(int));
	if (!g_board->m_info->h)
		return (ft_error(MALLOC_ERR));
	*g_board->m_info->h = 0;
	g_board->m_info->w = (int *)malloc(sizeof(int));
	if (!g_board->m_info->w)
		return (ft_error(MALLOC_ERR));
	*g_board->m_info->w = 0;
	g_board->p_position = (int *)malloc(sizeof(int));
	if (!g_board->p_position)
		return (ft_error(MALLOC_ERR));
	*g_board->p_position = 0;
	return (false);
}

t_mlx	*mlx_initial(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->p_mlx = mlx_init();
	if (!mlx->p_mlx)
		return (NULL);
	mlx->p_win = mlx_new_window(mlx->p_mlx, WIN_X, WIN_Y, "Cub3D");
	if (!mlx->p_win)
		return (NULL);
	mlx->g = malloc(sizeof(t_g_board));
	if (!mlx->g)
		return (NULL);
	if (game_board_initial(mlx->g))
		return (NULL);
	return (mlx);
}

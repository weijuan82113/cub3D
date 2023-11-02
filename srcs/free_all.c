/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:06:52 by wchen             #+#    #+#             */
/*   Updated: 2023/11/02 22:22:42 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_map(t_map_info **m_info, void (*del)(void *))
{
	t_map_info	*p_m_info;
	int			i;

	if (!m_info)
		return ;
	p_m_info = *m_info;
	if (!p_m_info)
		return ;
	i = 0;
	while (i < *p_m_info->h && p_m_info->map)
	{
		del(p_m_info->map[i]);
		i ++;
	}
	del(p_m_info->map);
	del(p_m_info->h);
	del(p_m_info->w);
	del(p_m_info);
	p_m_info = NULL;
}

static void	free_g_board(t_g_board **g)
{
	t_g_board	*p_g;

	p_g = *g;
	if (!p_g)
		return ;
	ft_lstclear(&p_g->line_lst, free);
	ft_imglstclear(&p_g->img_lst, free);
	ft_colorlstclear(&p_g->color_lst, free);
	free_map(&p_g->m_info, free);
	if (p_g->p_position)
		free(p_g->p_position);
	free(p_g);
	p_g = NULL;
}

void	free_all(t_mlx *mlx)
{
	mlx_clear_window(mlx->p_mlx, mlx->p_win);
	mlx_destroy_window(mlx->p_mlx, mlx->p_win);
	mlx_destroy_display(mlx->p_mlx);
	if (mlx->p_mlx)
	{
		free(mlx->p_mlx);
		mlx->p_mlx = NULL;
	}
	if (mlx->g)
		free_g_board(&mlx->g);
	free(mlx);
	mlx = NULL;
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

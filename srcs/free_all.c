/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:06:52 by wchen             #+#    #+#             */
/*   Updated: 2023/11/07 23:14:04 by kitsuki          ###   ########.fr       */
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
	while (p_m_info->h && i < *p_m_info->h && p_m_info->map)
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
	if (p_g->identifier)
		free_split(p_g->identifier);
	free(p_g);
	*g = NULL;
}

void	free_all(t_mlx *mlx)
{
	if (!mlx)
		return ;
	if (mlx->p_mlx)
	{
		if (mlx->p_win)
		{
			if (mlx->g)
				free_g_board(&mlx->g);
			mlx_clear_window(mlx->p_mlx, mlx->p_win);
			mlx_destroy_window(mlx->p_mlx, mlx->p_win);
		}
		mlx_destroy_display(mlx->p_mlx);
	}
	free(mlx);
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

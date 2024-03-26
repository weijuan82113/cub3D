/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:06:52 by wchen             #+#    #+#             */
/*   Updated: 2024/02/12 17:56:42 by kitsuki          ###   ########.fr       */
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
	while (i < p_m_info->h && p_m_info->map)
	{
		del(p_m_info->map[i]);
		i ++;
	}
	del(p_m_info->map);
	del(p_m_info);
	p_m_info = NULL;
}

static void	free_identifer(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (i < IDENTIFIER_NUM)
	{
		if (split[i])
			free(split[i]);
		i ++;
	}
	free(split);
}

static void	free_g_board(t_mlx *mlx)
{
	t_g_board	*p_g;

	p_g = mlx->g;
	if (!p_g)
		return ;
	ft_lstclear(&p_g->line_lst, free);
	ft_imglstclear(&p_g->img_lst, mlx->p_mlx);
	ft_colorlstclear(&p_g->color_lst, free);
	free_map(&p_g->m_info, free);
	if (p_g->identifier)
		free_identifer(p_g->identifier);
	free(p_g);
	mlx->g = NULL;
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
				free_g_board(mlx);
			mlx_clear_window(mlx->p_mlx, mlx->p_win);
			mlx_destroy_window(mlx->p_mlx, mlx->p_win);
		}
		mlx_destroy_display(mlx->p_mlx);
		free(mlx->p_mlx);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_notify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:25:55 by kitsuki           #+#    #+#             */
/*   Updated: 2023/11/06 23:02:23 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_draw_util.h"

static void	fix_collision(char **map, t_player *p, double mx, double my)
{
	int	x;
	int	y;

	x = (int)p->x;
	y = (int)p->y;
	if (map[(y + BLOCK / 3) / BLOCK][(x + BLOCK / 3) / BLOCK] == '1'
		|| map[(y - BLOCK / 3) / BLOCK][(x + BLOCK / 3) / BLOCK] == '1'
		|| map[(y + BLOCK / 3) / BLOCK][(x - BLOCK / 3) / BLOCK] == '1'
		|| map[(y - BLOCK / 3) / BLOCK][(x - BLOCK / 3) / BLOCK] == '1')
	{
		p->x = mx;
		p->y = my;
	}
}

int	key_notify(int button, t_mlx *mlx)
{
	double	mx;
	double	my;

	mx = mlx->player.x;
	my = mlx->player.y;
	if (button == ESC)
		clear(mlx);
	else if (button == KEY_A || button == KEY_LEFT)
		mlx->player.degree -= MOVE_DEGREE;
	else if (button == KEY_D || button == KEY_RIGHT)
		mlx->player.degree += MOVE_DEGREE;
	else if (button == KEY_W || button == KEY_UP)
	{
		mlx->player.x += BLOCK / 10 * sin(mlx->player.degree * M_PI / 180);
		mlx->player.y -= BLOCK / 10 * cos(mlx->player.degree * M_PI / 180);
	}
	else if (button == KEY_S || button == KEY_DOWN)
	{
		mlx->player.x -= BLOCK / 10 * sin(mlx->player.degree * M_PI / 180);
		mlx->player.y += BLOCK / 10 * cos(mlx->player.degree * M_PI / 180);
	}
	fix_collision(mlx->g->m_info->map, &mlx->player, mx, my);
	mlx->player.degree = set_degree(mlx->player.degree);
	repaint(mlx);
	return (0);
}

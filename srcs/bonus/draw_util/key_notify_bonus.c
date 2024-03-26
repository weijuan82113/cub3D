/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_notify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:25:55 by kitsuki           #+#    #+#             */
/*   Updated: 2023/11/12 20:46:41 by kitsuki          ###   ########.fr       */
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

static void	change_degree(int button, t_player *player)
{
	if (button == KEY_LEFT)
		player->degree -= MOVE_DEGREE;
	else if (button == KEY_RIGHT)
		player->degree += MOVE_DEGREE;
}

static void	move_position(int button, t_player *player)
{
	if (button == KEY_W || button == KEY_UP)
	{
		player->x += BLOCK / MOVE_PER_BLOCK * sin(player->degree * M_PI / 180);
		player->y -= BLOCK / MOVE_PER_BLOCK * cos(player->degree * M_PI / 180);
	}
	else if (button == KEY_S || button == KEY_DOWN)
	{
		player->x -= BLOCK / MOVE_PER_BLOCK * sin(player->degree * M_PI / 180);
		player->y += BLOCK / MOVE_PER_BLOCK * cos(player->degree * M_PI / 180);
	}
	else if (button == KEY_A)
	{
		player->x -= BLOCK / MOVE_PER_BLOCK * cos(player->degree * M_PI / 180);
		player->y -= BLOCK / MOVE_PER_BLOCK * sin(player->degree * M_PI / 180);
	}
	else if (button == KEY_D)
	{
		player->x += BLOCK / MOVE_PER_BLOCK * cos(player->degree * M_PI / 180);
		player->y += BLOCK / MOVE_PER_BLOCK * sin(player->degree * M_PI / 180);
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
	change_degree(button, &mlx->player);
	move_position(button, &mlx->player);
	fix_collision(mlx->g->m_info->map, &mlx->player, mx, my);
	mlx->player.degree = get_fixed_degree(mlx->player.degree);
	repaint(mlx);
	return (0);
}

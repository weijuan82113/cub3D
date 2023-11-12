/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:30:43 by kitsuki           #+#    #+#             */
/*   Updated: 2023/11/12 20:46:41 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_draw_util.h"

double	get_fixed_degree(double degree)
{
	while (degree < 0)
		degree += 360;
	while (degree >= 360)
		degree -= 360;
	return (degree);
}

static int	get_direction(t_g_board *g)
{
	int	p;
	int	w;

	p = *g->p_position;
	w = *g->m_info->w;
	if (g->m_info->map[p / w][p % w] == 'N')
		return (0);
	else if (g->m_info->map[p / w][p % w] == 'E')
		return (90);
	else if (g->m_info->map[p / w][p % w] == 'S')
		return (180);
	return (270);
}

void	draw(t_mlx *m)
{
	m->player.x = (*(m->g->p_position) % *(m->g->m_info->w) + 0.5) * BLOCK;
	m->player.y = (*(m->g->p_position) / *(m->g->m_info->w) + 0.5) * BLOCK;
	m->player.degree = get_direction(m->g);
	m->image = mlx_new_image(m->p_mlx, WIN_X, WIN_Y);
	m->path = mlx_get_data_addr(m->image, &m->bpp, &m->length, &m->endian);
	mlx_hook(m->p_win, CLIENT_MESSAGE, 1L << 17, clear, m);
	mlx_hook(m->p_win, KEYPRESS, KEYPRESSMASK, key_notify, m);
	mlx_do_key_autorepeaton(m->p_mlx);
	mlx_expose_hook(m->p_win, repaint, m);
	mlx_loop(m->p_mlx);
}

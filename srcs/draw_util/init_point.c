/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:23:09 by kitsuki           #+#    #+#             */
/*   Updated: 2023/11/05 12:23:26 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_draw_util.h"

t_point	init_point(t_player player, double degree)
{
	t_point	p;

	p.dx = player.x / BLOCK;
	p.dy = player.y / BLOCK;
	p.mx = (int)player.x % BLOCK;
	p.my = (int)player.y % BLOCK;
	if (0 <= degree && degree < 180)
		p.mx = BLOCK - p.mx;
	if (90 <= degree && degree < 270)
		p.my = BLOCK - p.my;
	return (p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _draw_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:56:13 by kitsuki           #+#    #+#             */
/*   Updated: 2024/03/19 23:40:49 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DRAW_UTIL_H
# define _DRAW_UTIL_H

# include "cub3d.h"
# include <math.h>

# define CLIENT_MESSAGE 33
# define KEYPRESSMASK 1L
# define KEYPRESS 2
# define BLOCK 200
# define RANGE 24.0
# define MOVE_PER_BLOCK 6
# define MOVE_DEGREE 9.0

typedef struct s_imgline {
	int			x;
	t_img_node	*data;
}				t_imgline;

typedef struct s_point
{
	int		dx;
	int		dy;
	double	mx;
	double	my;
}			t_point;

t_point		init_point(t_player player, double degree);
t_imgline	init_imageline(int x, t_img_node *data);
t_imgline	get_image_color(t_mlx *mlx, bool flag, t_point p, double degree);
t_imgline	get_imageline(t_mlx *mlx, double degree);
double		get_distance(t_mlx *mlx, double degree);
void		set_image(t_mlx *mlx, t_imgline img, int x, double tall);
void		set_background(t_mlx *mlx, int x);
int			clear(t_mlx *mlx);
int			repaint(t_mlx *mlx);
int			key_notify(int button, t_mlx *mlx);
double		get_fixed_degree(double degree);

#endif

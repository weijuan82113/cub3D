/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repaint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:50:09 by kitsuki           #+#    #+#             */
/*   Updated: 2023/11/06 23:14:28 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_draw_util.h"

static void	reset_image(t_mlx *mlx)
{
	int	i;
	int	j;

	if (mlx == NULL)
		return ;
	i = -1;
	j = -1;
	while (++ i < WIN_Y)
		while (++ j < WIN_X)
			*(unsigned int *)(mlx->path
					+ (i * mlx->length + j * mlx->bpp / 8)) = 0;
}

static double	get_tall(t_mlx *mlx, double degree)
{
	double	tall;

	tall = get_distance(mlx, set_degree(mlx->player.degree + degree));
	if (tall != 0 && cos(degree * M_PI / 180) != 0)
		tall = WIN_X / 2 / fabs(tan(RANGE * M_PI / 180))
			/ (fabs(cos(degree * M_PI / 180)) * tall);
	return (tall);
}

int	repaint(t_mlx *mlx)
{
	int			i;
	double		tall;
	t_imgline	imgline;

	reset_image(mlx);
	i = 0;
	while (i < WIN_X)
	{
		set_background(mlx, i);
		tall = get_tall(mlx, (double)(i - (WIN_X / 2)) / (WIN_X / 2) * RANGE);
		if (tall <= 0)
			continue ;
		imgline = get_imageline(mlx, set_degree(mlx->player.degree
					+ (double)(i - (WIN_X / 2)) / (WIN_X / 2) * RANGE));
		set_image(mlx, imgline, i, tall);
		i++;
	}
	mlx_put_image_to_window(mlx->p_mlx, mlx->p_win, mlx->image, 0, 0);
	return (0);
}

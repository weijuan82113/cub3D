/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imageline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:53:29 by kitsuki           #+#    #+#             */
/*   Updated: 2024/03/19 23:40:32 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_draw_util.h"

static const char	*g_array[] = {"NO", "SO", "EA", "WE"};

t_imgline	init_imageline(int x, t_img_node *data)
{
	t_imgline	img;

	img.x = x;
	img.data = data;
	return (img);
}

static bool	get_point_and_isx(t_point *p, bool *isx, t_mlx *mlx, double degree)
{
	*isx = true;
	while ((0 <= p->dy && p->dy < mlx->g->m_info->h)
		&& (0 <= p->dx && p->dx < mlx->g->m_info->w))
	{
		if (mlx->g->m_info->map[p->dy][p->dx] == '1')
			return (true);
		*isx = fabs(tan(degree * M_PI / 180)) * p->my > p->mx;
		if (*isx && tan(degree * M_PI / 180) != 0)
		{
			p->my -= p->mx / fabs(tan(degree * M_PI / 180));
			p->mx = BLOCK;
			p->dx += (0 <= degree && degree < 180) * 2 - 1;
		}
		else
		{
			p->mx -= fabs(tan(degree * M_PI / 180)) * p->my;
			p->my = BLOCK;
			p->dy += (90 <= degree && degree < 270) * 2 - 1;
		}
	}
	return (false);
}

double	get_distance(t_mlx *mlx, double degree)
{
	t_point	p;
	bool	flag;
	double	x;
	double	y;

	p = init_point(mlx->player, degree);
	if (!get_point_and_isx(&p, &flag, mlx, degree))
		return (0);
	if (0 <= degree && degree < 180)
		x = BLOCK - p.mx;
	else
		x = p.mx;
	x = mlx->player.x - p.dx * BLOCK - x;
	if (90 <= degree && degree < 270)
		y = BLOCK - p.my;
	else
		y = p.my;
	y = mlx->player.y - p.dy * BLOCK - y;
	return (sqrt(pow(x, 2) + pow(y, 2)));
}

t_imgline	get_image_color(t_mlx *mlx, bool flag, t_point p, double degree)
{
	t_img_node	*image;
	int			index;
	int			x;

	if (mlx == NULL)
		return (init_imageline(0, NULL));
	if (flag)
		x = p.my;
	else
		x = p.mx;
	if ((flag && 90 <= degree && degree < 270)
		|| (!flag && 0 <= degree && degree < 180))
		x = BLOCK - x;
	index = flag * 2 + !((flag && 180 <= degree && degree < 360)
			|| (!flag && 90 <= degree && degree < 270));
	image = mlx->g->img_lst;
	while (image != NULL)
	{
		if (ft_strncmp(image->obj, g_array[index], 3) == 0)
			return (init_imageline(x, image));
		image = image->next;
	}
	return (init_imageline(0, NULL));
}

t_imgline	get_imageline(t_mlx *mlx, double degree)
{
	t_point	p;
	bool	flag;

	p = init_point(mlx->player, degree);
	if (get_point_and_isx(&p, &flag, mlx, degree))
		return (get_image_color(mlx, flag, p, degree));
	return (get_image_color(NULL, false, p, 0));
}

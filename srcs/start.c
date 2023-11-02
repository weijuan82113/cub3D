/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:41:07 by kitsuki           #+#    #+#             */
/*   Updated: 2023/11/02 23:18:29 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

#define CLIENT_MESSAGE 33
#define KeyPressMask (1L<<0)
#define KeyPress 2
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000
#define BLOCK_SIZE 190
#define INITIAL_DEGREE 180
#define EYE_LINE 140
#define VIEW_RANGE 45

typedef struct cols {
	int x;
	t_img_node *data;
} col;

int x = 4.5 * BLOCK_SIZE;
double dx = 0;
int y = 4.5 * BLOCK_SIZE;
double dy = 0;
double degree = INITIAL_DEGREE;

static int32_t clear(t_mlx *mlx) {
	mlx_loop_end(mlx->p_mlx);
	mlx_destroy_image(mlx->p_mlx, mlx->image);
	mlx_destroy_window(mlx->p_mlx, mlx->p_win);
	mlx_destroy_display(mlx->p_mlx);
	exit(0);
	return 0;
}

static double setDegree(double degree) {
	while (degree < 0)
		degree += 360;
	while (degree >= 360)
		degree -= 360;
	return degree;
}

static col getImageColor(t_mlx *mlx, char *dir, int xx) {
	t_img_node	*image;
	col			c;

	c.x = 0;
	c.data = NULL;
	image = mlx->g->img_lst;
	while (image != NULL)
	{
		if (ft_strncmp(image->obj, dir, 3) == 0)
		{
			c.data = image;
			c.x = xx;
			break ;
		}
		image = image->next;
	}
	return (c);
}

static col getColor(t_mlx *mlx, double degree) {
	int		i;
	int		j;
	double	amarix;
	double	amariy;
	bool	flag;
	col		c;

	i = mlx->player.x / BLOCK_SIZE;
	j = y / BLOCK_SIZE;
	amarix = (int)mlx->player.x % BLOCK_SIZE;
	amariy = y % BLOCK_SIZE;
	flag = true;
	degree = setDegree(degree);
	if (0 <= degree && degree <= 180)
		amarix = BLOCK_SIZE - amarix;
	if (90 <= degree && degree <= 270)
		amariy = BLOCK_SIZE - amariy;
	while ((0 <= j && j < *mlx->g->m_info->h) && (0 <= i && i < *mlx->g->m_info->w))
	{
		if (mlx->g->m_info->map[j][i] == '1')
		{
			if (flag)
				return getImageColor(mlx, "EA", (int)(90 <= degree && degree <= 270 ? BLOCK_SIZE - amariy : amariy));
			else
				return getImageColor(mlx, "NO", (int)(0 <= degree && degree <= 180 ? BLOCK_SIZE - amarix : amarix));
		}
		if (fabs(tan(degree * M_PI / 180)) * amariy > amarix)
		{
			amariy -= amarix / fabs(tan(degree * M_PI / 180));
			flag = true;
			amarix = BLOCK_SIZE;
			i += (0 <= degree && degree <= 180) ? 1 : -1;
		}
		else
		{
			amarix -= fabs(tan(degree * M_PI / 180)) * amariy;
			flag = false;
			amariy = BLOCK_SIZE;
			j += (90 <= degree && degree <= 270) ? 1 : -1;
		}
	}
	c.x = 0;
	c.data = NULL;
	return (c);
}

static double getDistance(t_mlx *mlx, double degree) {
	int		i;
	int		j;
	double	amarix;
	double	amariy;

	i = x / BLOCK_SIZE;
	j = y / BLOCK_SIZE;
	amarix = x % BLOCK_SIZE;
	amariy = y % BLOCK_SIZE;
	degree = setDegree(degree);
	if (0 <= degree && degree <= 180)
		amarix = BLOCK_SIZE - amarix;
	if (90 <= degree && degree <= 270)
		amariy = BLOCK_SIZE - amariy;
	while ((0 <= j && j < *mlx->g->m_info->h) && (0 <= i && i < *mlx->g->m_info->w))
	{
		if (mlx->g->m_info->map[j][i] == '1')
			break;
		if (fabs(tan(degree * M_PI / 180)) * amariy > amarix)
		{
			amariy -= amarix / fabs(tan(degree * M_PI / 180));
			amarix = BLOCK_SIZE;
			i += (0 <= degree && degree <= 180) ? 1 : -1;
		}
		else
		{
			amarix -= fabs(tan(degree * M_PI / 180)) * amariy;
			amariy = BLOCK_SIZE;
			j += (90 <= degree && degree <= 270) ? 1 : -1;
		}
	}
	return sqrt(pow(x - i * BLOCK_SIZE - ((0 <= degree && degree <= 180) ? BLOCK_SIZE - amarix : amarix), 2) + pow(y - j * BLOCK_SIZE - ((90 <= degree && degree <= 270) ? BLOCK_SIZE - amariy : amariy), 2));
}

static int repaint(t_mlx *mlx) {
	int		i;
	int		j;
	double	display;
	double	tall;
	col		color;

	i = 0;
	j = 0;
	display = WINDOW_HEIGHT / 2 * (double)45 / VIEW_RANGE;
	while (i < WINDOW_WIDTH)
		while (j < WINDOW_HEIGHT)
			*(unsigned int *)(mlx->path + (j ++ * mlx->length + i ++ * mlx->bpp / 8)) = 0;
	i = -1;
	while (++ i < WINDOW_WIDTH)
	{
		tall = getDistance(mlx, degree + (double)(i - (WINDOW_HEIGHT / 2)) / (WINDOW_HEIGHT / 2) * VIEW_RANGE);
		if (tall != 0)
			tall = display / fabs(cos((double)(i - (WINDOW_HEIGHT / 2)) / (WINDOW_HEIGHT / 2) * VIEW_RANGE * M_PI / 180)) / tall;
		else
			tall = display;
		color = getColor(mlx, degree + (double)(i - (WINDOW_HEIGHT / 2)) / (WINDOW_HEIGHT / 2) * VIEW_RANGE);
		int tmp = EYE_LINE * tall > WINDOW_HEIGHT / 2 ? EYE_LINE * tall - WINDOW_HEIGHT / 2 : 0;
		j = -1;
		while (++ j < WINDOW_HEIGHT) {
			if (j < WINDOW_HEIGHT / 2)
				*(unsigned int *)(mlx->path + (j * mlx->length + i * mlx->bpp / 8)) = 0xff00ff;
			else
				*(unsigned int *)(mlx->path + (j * mlx->length + i * mlx->bpp / 8)) = 0x00ff00;
		}
		j = -EYE_LINE * tall <= - WINDOW_HEIGHT / 2 ? - WINDOW_HEIGHT / 2 + 1 : -EYE_LINE * tall;
		while (j < (BLOCK_SIZE - EYE_LINE) * tall && j <= WINDOW_HEIGHT / 2) {
			if (color.data != NULL)
				*(unsigned int *)(mlx->path + (((WINDOW_HEIGHT / 2) - j ++) * mlx->length + i * mlx->bpp / 8)) = *(unsigned int *)(color.data->path + (int)(color.data->h - tmp * color.data->h / (BLOCK_SIZE * tall)) * color.data->length + color.x * color.data->w / BLOCK_SIZE * color.data->bpp / 8);
			tmp ++;
		}
	}
	i = 495;
	while (i < 505)
		j = 495;
		while (j < 505)
			*(unsigned int *)(mlx->path + (j ++ * mlx->length + i * mlx->bpp / 8)) = 0;
	mlx_put_image_to_window(mlx->p_mlx, mlx->p_win, mlx->image, 0, 0);
	return (0);
}

static int	key_notify(int button, t_mlx *mlx)
{
	int mx = x;
	int my = y;

	if (button == ESC)
		clear(mlx);
	else if (button == KEY_A || button == KEY_LEFT)
		degree -= 3;
	else if (button == KEY_D || button == KEY_RIGHT)
		degree += 3;
	else if (button == KEY_W || button == KEY_UP)
	{
		dx += BLOCK_SIZE / 10 * sin(setDegree(degree) * M_PI / 180);
		dy -= BLOCK_SIZE / 10 * cos(setDegree(degree) * M_PI / 180);
	}
	else if (button == KEY_S || button == KEY_DOWN)
	{
		dx -= BLOCK_SIZE / 10 * sin(setDegree(degree) * M_PI / 180);
		dy += BLOCK_SIZE / 10 * cos(setDegree(degree) * M_PI / 180);
	}
	x += (int)dx;
	dx -= (int)dx;
	y += (int)dy;
	dy -= (int)dy;
	if (mlx->g->m_info->map[(y + BLOCK_SIZE / 3) / BLOCK_SIZE][(x + BLOCK_SIZE / 3) / BLOCK_SIZE] == '1'
	|| mlx->g->m_info->map[(y - BLOCK_SIZE / 3) / BLOCK_SIZE][(x + BLOCK_SIZE / 3) / BLOCK_SIZE] == '1'
	|| mlx->g->m_info->map[(y + BLOCK_SIZE / 3) / BLOCK_SIZE][(x - BLOCK_SIZE / 3) / BLOCK_SIZE] == '1'
	|| mlx->g->m_info->map[(y - BLOCK_SIZE / 3) / BLOCK_SIZE][(x - BLOCK_SIZE / 3) / BLOCK_SIZE] == '1')
	{
		x = mx;
		y = my;
	}
	repaint(mlx);
	return (0);
}

void	draw(t_mlx *mlx)
{
	mlx->player.x = (*(mlx->g->p_position) % *(mlx->g->m_info->w) + 0.5) * BLOCK_SIZE;
	mlx->player.y = (*(mlx->g->p_position) / *(mlx->g->m_info->w) + 0.5) * BLOCK_SIZE;
	mlx->image = mlx_new_image(mlx->p_mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx->path = mlx_get_data_addr(mlx->image, &mlx->bpp, &mlx->length, &mlx->endian);
	mlx_hook(mlx->p_win, CLIENT_MESSAGE, 1L << 17, clear, mlx);
	mlx_hook(mlx->p_win, KeyPress, KeyPressMask, key_notify, mlx);
	mlx_do_key_autorepeaton(mlx->p_mlx);
	mlx_expose_hook(mlx->p_win, repaint, mlx);
	mlx_loop(mlx->p_mlx);
}

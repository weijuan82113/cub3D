/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:16:39 by wchen             #+#    #+#             */
/*   Updated: 2023/09/30 23:09:17 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <math.h>

# define CLIENT_MESSAGE	33

typedef struct s_window {
	void *win;
	void *mlx;
} t_window;

static int32_t clear(t_window *tmp) {
	mlx_loop_end(tmp->mlx);
	mlx_destroy_window(tmp->mlx, tmp->win);
	mlx_destroy_display(tmp->mlx);
	exit(0);
	return 0;
}
const int width = 9;
const int height = 14;
int map[height][width] = {
{1, 1, 1, 0, 1, 0, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 1, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 1, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 1, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 1, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 1, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 1, 1}};
const int block = 190;
int x = 7 * block;
int y = 4 * block;
double initial_deg = 180;
// tan -> x / y

static double setDegree(double degree) {
	while (degree < 0)
		degree += 360;
	while (degree >= 360)
		degree -= 360;
	return degree;
}
static int getColor(double degree) {
	degree = setDegree(degree);
	//printf("deg: %f, tan: %f\n", degree, tan(degree * M_PI / 180));
	int i = x / block;
	double amarix = x % block;
	if (0 <= degree && degree <= 180)
		amarix = block - amarix;
	double amariy = y % block;
	if (90 <= degree && degree <= 270)
		amariy = block - amariy;
	bool flag = true;
	for (int j = y / block; (0 <= j && j < height) && (0 <= i && i < width);) {
		if (map[j][i] == 1) {
			if (flag)
				return 0x00FF00;
			else
				return 0x0000FF;
		}
		if (fabs(tan(degree * M_PI / 180)) * amariy > amarix) {
			amariy -= amarix / fabs(tan(degree * M_PI / 180));
			flag = true;
			//printf("fitx: %f\n", amarix / tan(degree * M_PI / 180));
			amarix = block;
			i += (0 <= degree && degree <= 180) ? 1 : -1;
		}
		else {
			amarix -= fabs(tan(degree * M_PI / 180)) * amariy;
			flag = false;
			//printf("fity: %f\n", tan(degree * M_PI / 180) * amariy);
			amariy = block;
			j += (90 <= degree && degree <= 270) ? 1 : -1;
		}
		//printf("%f, %f\n", amarix, amariy);
	}
	return 0x000000;
}

static double getDistance(double degree) {
	degree = setDegree(degree);
	int i = x / block;
	double amarix = x % block;
	if (0 <= degree && degree <= 180)
		amarix = block - amarix;
	double amariy = y % block;
	if (90 <= degree && degree <= 270)
		amariy = block - amariy;
	int j = y / block;
	while ((0 <= j && j < height) && (0 <= i && i < width)) {
		if (map[j][i] == 1)
			break;
		if (fabs(tan(degree * M_PI / 180)) * amariy > amarix) {
			amariy -= amarix / fabs(tan(degree * M_PI / 180));
			amarix = block;
			i += (0 <= degree && degree <= 180) ? 1 : -1;
		}
		else {
			amarix -= fabs(tan(degree * M_PI / 180)) * amariy;
			amariy = block;
			j += (90 <= degree && degree <= 270) ? 1 : -1;
		}
	}
	return sqrt(pow(x - i * block - ((0 <= degree && degree <= 180) ? block - amarix : amarix), 2) + pow(y - j * block - ((90 <= degree && degree <= 270) ? block - amariy : amariy), 2));
}

int takasa = 140;
int view_degree = 45;
static int repaint(t_window *tmp) {
	double display = 1000 / 2 * (double)45 / view_degree;
	for (int i = 0; i < 1000; i++) {
		double tall = getDistance(initial_deg + (double)(i - 500) / 500 * view_degree);
		if (tall != 0)
			tall = display / tall;
		else
			tall = display;
		int color = getColor(initial_deg + (double)(i - 500) / 500 * view_degree);
		for (int j = -takasa * tall; j < (200 - takasa) * tall; j++) {
			mlx_pixel_put(tmp->mlx, tmp->win, i, 500 - j, color);
		}
	}
	for (int i = 495; i < 505; i++) {
		for (int j = 495; j < 505; j++) {
			mlx_pixel_put(tmp->mlx, tmp->win, i, j, 0);
		}
	}
	return 0;
}

void test(void)
{
	t_window mlx_ptr;
	//void *mlx_wind;
	mlx_ptr.mlx = mlx_init();
	printf("test01");
	mlx_ptr.win = mlx_new_window(mlx_ptr.mlx, 1000, 1000, "abc");
	mlx_hook(mlx_ptr.win, CLIENT_MESSAGE, 1L << 17, clear, &mlx_ptr);
	mlx_expose_hook(mlx_ptr.win, repaint, &mlx_ptr);
	mlx_loop(mlx_ptr.mlx);
}
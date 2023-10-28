/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:16:39 by wchen             #+#    #+#             */
/*   Updated: 2023/10/15 01:26:18 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <math.h>

# define CLIENT_MESSAGE	33
# define ESCAPE			65307
# define W				119
# define A				97
# define S				115
# define D				100
# define LEFT			65361
# define UP				65362
# define RIGHT			65363
# define DOWN			65364

typedef struct s_window {
	void *win;
	void *mlx;
	void *image;
	int bpp;
	int length;
	int endian;
	void *path;
} t_window;

static int32_t clear(t_window *tmp) {
	mlx_loop_end(tmp->mlx);
	mlx_destroy_image(tmp->mlx, tmp->image);
	mlx_destroy_window(tmp->mlx, tmp->win);
	mlx_destroy_display(tmp->mlx);
	exit(0);
	return 0;
}

const int window_w = 1000;
const int window_h = 1000;

const int width = 9;
const int height = 14;
int map[height][width] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 1, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 1, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 1, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 1, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 1, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 1, 0, 0, 0, 1},
{1, 0, 1, 0, 0, 1, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 1, 0, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1}};
const int block = 190;
int x = 4.5 * block;
double dx = 0;
int y = 4.5 * block;
double dy = 0;
double initial_deg = 180;
// tan -> x / y

int ew_color[10] = {0x00FF00,0x00EF00,0x00DF00,0x00CF00,
0x00BF00,0x00AF00,0x009F00,0x008F00,
0x007F00,0x006F00};
int ns_color[10] = {0x0000FF,0x0000EF,0x0000DF,0x0000CF,
0x0000BF,0x0000AF,0x00009F,0x00008F,
0x00007F,0x00006F};

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
				return ew_color[(int)(90 <= degree && degree <= 270 ? block - amariy : amariy) / (block / 10)];
			else
				return ns_color[(int)(0 <= degree && degree <= 180 ? block - amarix : amarix) / (block / 10)];
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
	for (int i = 0; i < window_w; i++) {
		for (int j = 0; j < window_h; j++) {
			*(unsigned int *)(tmp->path + (j * tmp->length + i * tmp->bpp / 8)) = 0;
		}
	}
	double display = window_h / 2 * (double)45 / view_degree;
	for (int i = 0; i < window_w; i++) {
		double tall = getDistance(initial_deg + (double)(i - (window_h / 2)) / (window_h / 2) * view_degree);
		if (tall != 0)
			tall = display / fabs(cos((double)(i - (window_h / 2)) / (window_h / 2) * view_degree * M_PI / 180)) / tall;
		else
			tall = display;
		int color = getColor(initial_deg + (double)(i - (window_h / 2)) / (window_h / 2) * view_degree);
		for (int j = -takasa * tall <= - window_h / 2 ? - window_h / 2 + 1 : -takasa * tall; j < (200 - takasa) * tall && j <= window_h / 2; j++) {
			*(unsigned int *)(tmp->path + (((window_h / 2) - j) * tmp->length + i * tmp->bpp / 8)) = color;
		}
	}
	for (int i = 495; i < 505; i++) {
		for (int j = 495; j < 505; j++) {
			*(unsigned int *)(tmp->path + (j * tmp->length + i * tmp->bpp / 8)) = 0;
		}
	}
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->image, 0, 0);
	return 0;
}

#define KeyPress		2
#define KeyPressMask			(1L<<0)

static int	key_notify(int button, t_window *param)
{
	int mx = x;
	int my = y;

	if (button == ESCAPE)
		clear(param);
	else if (button == A || button == LEFT)
		initial_deg -= 3;
	else if (button == D || button == RIGHT)
		initial_deg += 3;
	else if (button == W || button == UP) {
		dx += block / 10 * sin(setDegree(initial_deg) * M_PI / 180);
		dy -= block / 10 * cos(setDegree(initial_deg) * M_PI / 180);
	} else if (button == S || button == DOWN) {
		dx -= block / 10 * sin(setDegree(initial_deg) * M_PI / 180);
		dy += block / 10 * cos(setDegree(initial_deg) * M_PI / 180);
	}
	x += (int)dx;
	dx -= (int)dx;
	y += (int)dy;
	dy -= (int)dy;
	//printf("before x: %d + %d, y: %d + %d\n", x / block, x % block, y / block, y % block);
	if (map[(y + block / 3) / block][(x + block / 3) / block] == 1
	|| map[(y - block / 3) / block][(x + block / 3) / block] == 1
	|| map[(y + block / 3) / block][(x - block / 3) / block] == 1
	|| map[(y - block / 3) / block][(x - block / 3) / block] == 1) {
		x = mx;
		y = my;
	}
	//printf("after x: %d + %d, y: %d + %d\n", x / block, x % block, y / block, y % block);
	repaint(param);
	return (0);
}

void test(void)
{
	t_window mlx_ptr;
	//void *mlx_wind;
	mlx_ptr.mlx = mlx_init();
	mlx_ptr.win = mlx_new_window(mlx_ptr.mlx, window_w, window_h, "abc");
	mlx_ptr.image = mlx_new_image(mlx_ptr.mlx, window_w, window_h);
	mlx_ptr.path = mlx_get_data_addr(mlx_ptr.image, &mlx_ptr.bpp, &mlx_ptr.length, &mlx_ptr.endian);
	mlx_hook(mlx_ptr.win, CLIENT_MESSAGE, 1L << 17, clear, &mlx_ptr);
	mlx_hook(mlx_ptr.win, KeyPress, KeyPressMask, key_notify, &mlx_ptr);
	mlx_do_key_autorepeaton(mlx_ptr.mlx);
	//mlx_key_hook(mlx_ptr.win, key_notify, &mlx_ptr);
	mlx_expose_hook(mlx_ptr.win, repaint, &mlx_ptr);
	mlx_loop(mlx_ptr.mlx);
}
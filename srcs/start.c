/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:41:07 by kitsuki           #+#    #+#             */
/*   Updated: 2023/10/29 23:34:33 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

#define CLIENT_MESSAGE 33
#define KeyPressMask (1L<<0)
#define KeyPress 2
# define ESCAPE			65307
# define W				119
# define A				97
# define S				115
# define D				100

static int32_t clear(t_mlx *mlx) {
	mlx_loop_end(mlx->p_mlx);
	mlx_destroy_image(mlx->p_mlx, mlx->image);
	mlx_destroy_window(mlx->p_mlx, mlx->p_win);
	mlx_destroy_display(mlx->p_mlx);
	exit(0);
	return 0;
}

const int window_w = 1000;
const int window_h = 1000;

int width = 9;
int height = 14;
char **map;
// int map[height][width] = {
// {1, 1, 1, 1, 1, 1, 1, 1, 1},
// {1, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 0, 0, 0, 0, 1, 0, 0, 1},
// {1, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 0, 0, 1, 0, 0, 0, 0, 1},
// {1, 0, 0, 0, 0, 0, 1, 0, 1},
// {1, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 0, 1, 0, 0, 0, 0, 0, 1},
// {1, 0, 0, 1, 0, 0, 0, 0, 1},
// {1, 0, 0, 0, 1, 0, 0, 0, 1},
// {1, 0, 1, 0, 0, 1, 0, 0, 1},
// {1, 0, 0, 0, 0, 0, 1, 0, 1},
// {1, 1, 1, 1, 1, 1, 1, 1, 1}};
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

typedef struct cols {
	int x;
	t_img_node *data;
} col;

static col getImageColor(t_mlx *mlx, char *dir, int xx) {
	t_img_node	*image;
	col c;

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
		//return * + ((image->h / 2) * image->length + x * image->w / block * mlx->bpp / 8));
		image = image->next;
	}
	return (c);
}

static col getColor(t_mlx *mlx, double degree) {
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
		if (map[j][i] == '1') {
			if (flag)
				return getImageColor(mlx, "EA", (int)(90 <= degree && degree <= 270 ? block - amariy : amariy));
			else
				return getImageColor(mlx, "NO", (int)(0 <= degree && degree <= 180 ? block - amarix : amarix));
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
	col c;
	c.x = 0;
	c.data = NULL;
	return c;
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
		if (map[j][i] == '1')
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
static int repaint(t_mlx *mlx) {
	for (int i = 0; i < window_w; i++) {
		for (int j = 0; j < window_h; j++) {
			*(unsigned int *)(mlx->path + (j * mlx->length + i * mlx->bpp / 8)) = 0;
		}
	}
	double display = window_h / 2 * (double)45 / view_degree;
	for (int i = 0; i < window_w; i++) {
		double tall = getDistance(initial_deg + (double)(i - (window_h / 2)) / (window_h / 2) * view_degree);
		if (tall != 0)
			tall = display / fabs(cos((double)(i - (window_h / 2)) / (window_h / 2) * view_degree * M_PI / 180)) / tall;
		else
			tall = display;
		col color = getColor(mlx, initial_deg + (double)(i - (window_h / 2)) / (window_h / 2) * view_degree);
		int tmp = takasa * tall > window_h / 2 ? takasa * tall - window_h / 2 : 0;
		for (int j = 0; j < window_h; j++) {
			if (j < window_h / 2)
				*(unsigned int *)(mlx->path + (j * mlx->length + i * mlx->bpp / 8)) = 0xff00ff;
			else
				*(unsigned int *)(mlx->path + (j * mlx->length + i * mlx->bpp / 8)) = 0x00ff00;
		}
		for (int j = -takasa * tall <= - window_h / 2 ? - window_h / 2 + 1 : -takasa * tall; j < (block - takasa) * tall && j <= window_h / 2; j++) {
			if (color.data != NULL) {
				*(unsigned int *)(mlx->path + (((window_h / 2) - j) * mlx->length + i * mlx->bpp / 8)) = *(unsigned int *)(color.data->path + (int)(color.data->h - tmp * color.data->h / (block * tall)) * color.data->length + color.x * color.data->w / block * color.data->bpp / 8);
				//printf("%d, %d;", (int)((tall * takasa - j) * color.data->h / tall), color.x);
			}
			tmp ++;
		}
	}
	for (int i = 495; i < 505; i++) {
		for (int j = 495; j < 505; j++) {
			*(unsigned int *)(mlx->path + (j * mlx->length + i * mlx->bpp / 8)) = 0;
		}
	}
	mlx_put_image_to_window(mlx->p_mlx, mlx->p_win, mlx->image, 0, 0);
	//printf("%d, %d", x, y);
	return 0;
}

static int	key_notify(int button, t_mlx *mlx)
{
	int mx = x;
	int my = y;

	if (button == ESCAPE)
		clear(mlx);
	else if (button == A || button == KEY_LEFT)
		initial_deg -= 3;
	else if (button == D || button == KEY_RIGHT)
		initial_deg += 3;
	else if (button == W || button == KEY_UP) {
		dx += block / 10 * sin(setDegree(initial_deg) * M_PI / 180);
		dy -= block / 10 * cos(setDegree(initial_deg) * M_PI / 180);
	} else if (button == S || button == KEY_DOWN) {
		dx -= block / 10 * sin(setDegree(initial_deg) * M_PI / 180);
		dy += block / 10 * cos(setDegree(initial_deg) * M_PI / 180);
	}
	x += (int)dx;
	dx -= (int)dx;
	y += (int)dy;
	dy -= (int)dy;
	//printf("before x: %d + %d, y: %d + %d\n", x / block, x % block, y / block, y % block);
	if (map[(y + block / 3) / block][(x + block / 3) / block] == '1'
	|| map[(y - block / 3) / block][(x + block / 3) / block] == '1'
	|| map[(y + block / 3) / block][(x - block / 3) / block] == '1'
	|| map[(y - block / 3) / block][(x - block / 3) / block] == '1') {
		x = mx;
		y = my;
	}
	//printf("after x: %d + %d, y: %d + %d\n", x / block, x % block, y / block, y % block);
	repaint(mlx);
	return (0);
}

void	draw(t_mlx *mlx)
{
	width = *mlx->g->m_info->w;
	height = *mlx->g->m_info->h;
	map = mlx->g->m_info->map;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			//printf("%c", map[i][j]);
		}
		//printf("\n");
	}
	x = (*(mlx->g->p_position) % *(mlx->g->m_info->w) + 0.5) * block;
	y = (*(mlx->g->p_position) / *(mlx->g->m_info->w) + 0.5) * block;
	mlx->image = mlx_new_image(mlx->p_mlx, window_w, window_h);
	mlx->path = mlx_get_data_addr(mlx->image, &mlx->bpp, &mlx->length, &mlx->endian);
	mlx_hook(mlx->p_win, CLIENT_MESSAGE, 1L << 17, clear, mlx);
	mlx_hook(mlx->p_win, KeyPress, KeyPressMask, key_notify, mlx);
	mlx_do_key_autorepeaton(mlx->p_mlx);
	mlx_expose_hook(mlx->p_win, repaint, mlx);
	mlx_loop(mlx->p_mlx);
}
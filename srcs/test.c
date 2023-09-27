/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:16:39 by wchen             #+#    #+#             */
/*   Updated: 2023/09/27 23:25:56 by kitsuki          ###   ########.fr       */
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
// tan -> x / y
static int getColor(double degree) {
	printf("deg: %f, tan: %f\n", degree, tan(degree * M_PI / 180));
	int map[3][5] = {{1, 1, 0, 1, 1},{1, 0, 0, 0, 1},{0, 0, 0, 0, 1}};
	int x = 190;
	int y = 149;
	int i = x / 50;
	double amarix = x % 50;
	double amariy = y % 50;
	bool flag = true;
	for (int j = y / 50; j >= 0 && (0 <= i && i <= 4);) {
		if (map[j][i] == 1) {
			if (flag)
				return 0x00FF00;
			else
				return 0x0000FF;
		}
		if (tan(degree * M_PI / 180) * amariy > amarix) {
			amariy -= amarix / tan(degree * M_PI / 180);
			flag = true;
			printf("fitx: %f\n", amarix / tan(degree * M_PI / 180));
			amarix = 50;
			i--;
		}
		else {
			amarix -= tan(degree * M_PI / 180) * amariy;
			flag = false;
			printf("fity: %f\n", tan(degree * M_PI / 180) * amariy);
			amariy = 50;
			j--;
		}
		printf("%f, %f\n", amarix, amariy);
	}
	return 0x000000;
}

static double getDistance(double degree) {
	int map[3][5] = {{1, 1, 0, 1, 1},{1, 0, 0, 0, 1},{0, 0, 0, 0, 1}};
	int x = 190;
	int y = 149;
	int i = x / 50;
	double amarix = x % 50;
	double amariy = y % 50;
	int j = y / 50;
	while (j >= 0 && (0 <= i && i <= 4)) {
		if (map[j][i] == 1)
			break;
		if (tan(degree * M_PI / 180) * amariy > amarix) {
			amariy -= amarix / tan(degree * M_PI / 180);
			amarix = 50;
			i--;
		}
		else {
			amarix -= tan(degree * M_PI / 180) * amariy;
			amariy = 50;
			j--;
		}
	}
	return sqrt(pow(x - i * 50 - amarix, 2) + pow(y - j * 50 - amariy, 2));
}

static int repaint(t_window *tmp) {
	int display = 80;
	for (int i = 0; i < 1000; i++) {
		double tall = 500 * display / getDistance(-(double)(i - 500) / 500 * 70);
		int color = getColor(-(double)(i - 500) / 500 * 70);
		for (int j = 0; j < tall; j++) {
			mlx_pixel_put(tmp->mlx, tmp->win, i, 500 + j - tall / 2, color);
		}
	}
	for (int i = 490; i < 510; i++) {
		for (int j = 490; j < 510; j++) {
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
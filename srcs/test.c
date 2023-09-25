/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:16:39 by wchen             #+#    #+#             */
/*   Updated: 2023/09/25 22:53:12 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

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

static int repaint(t_window *tmp) {
	for (int i = 0; i < 1000; i++)
		mlx_pixel_put(tmp->mlx, tmp->win, 100, i, 0xFF00FF);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:16:39 by wchen             #+#    #+#             */
/*   Updated: 2023/09/30 17:21:40 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void test(void)
{
	void *mlx_ptr;
	//void *mlx_wind;
	mlx_ptr = mlx_init();
	printf("test01");
	mlx_new_window(mlx_ptr, 1000, 1000, "abc");
	mlx_loop(mlx_ptr);
}
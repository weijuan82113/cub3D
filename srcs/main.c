/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:37:49 by wchen             #+#    #+#             */
/*   Updated: 2023/10/29 18:09:46 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q cub3d");
}

int main (int argc, char **argv)
{
	t_mlx	*mlx;

	if (!(mlx = mlx_initial()))
	{
		free_all(mlx);
		exit(ft_error(MLX_INIT_ERR));
	}
	if (validation(mlx, argc, argv))
	{
		free_all(mlx);
		exit(EXIT_FAILURE);
	}
	mlx_key_hook(mlx->p_win, key_hook, mlx);
	mlx_hook(mlx->p_win, 17, 1L << 17, destroy_hook, mlx);
	mlx_loop(mlx->p_mlx);
	return (EXIT_SUCCESS);
}
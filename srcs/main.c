/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:37:49 by wchen             #+#    #+#             */
/*   Updated: 2023/10/28 19:17:06 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main (int argc, char **argv)
{
	t_mlx	*mlx;

	if (!(mlx = mlx_initial()))
		exit(ft_error(MLX_INIT_ERR));
	if (validation(mlx, argc, argv))
		exit(EXIT_FAILURE);
	mlx_key_hook(mlx->p_win, key_hook, mlx);
	mlx_hook(mlx->p_win, 17, 1L << 17, destroy_hook, mlx);
	mlx_loop(mlx->p_mlx);
	return (EXIT_SUCCESS);
}
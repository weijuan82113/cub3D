/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:37:49 by wchen             #+#    #+#             */
/*   Updated: 2023/11/02 22:08:40 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	mlx = mlx_initial();
	if (!mlx)
	{
		free_all(mlx);
		exit(ft_error(MLX_INIT_ERR));
	}
	if (validation(mlx, argc, argv))
	{
		free_all(mlx);
		exit(EXIT_FAILURE);
	}
	draw(mlx);
	// mlx_key_hook(mlx->p_win, key_hook, mlx);
	// mlx_hook(mlx->p_win, 17, 1L << 17, destroy_hook, mlx);
	// mlx_loop(mlx->p_mlx);
	return (EXIT_SUCCESS);
}

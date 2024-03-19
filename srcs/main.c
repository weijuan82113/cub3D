/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:37:49 by wchen             #+#    #+#             */
/*   Updated: 2024/03/19 23:03:36 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


__attribute__((destructor))
static void destructor() {
    system("leaks -q cub3D");
	//system("leaks -q cub3D_bonus");
}


int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (mlx_initial(&mlx) || validation(mlx, argc, argv))
	{
		free_all(mlx);
		exit(EXIT_FAILURE);
	}
	draw(mlx);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:37:49 by wchen             #+#    #+#             */
/*   Updated: 2023/11/12 22:03:45 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

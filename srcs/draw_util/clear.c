/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:24:11 by kitsuki           #+#    #+#             */
/*   Updated: 2023/11/12 21:20:51 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_draw_util.h"

int	clear(t_mlx *mlx)
{
	mlx_loop_end(mlx->p_mlx);
	mlx_destroy_image(mlx->p_mlx, mlx->image);
	free_all(mlx);
	system("leaks cub3D");
	exit(0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:24:11 by kitsuki           #+#    #+#             */
/*   Updated: 2023/11/07 22:06:13 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_draw_util.h"

int	clear(t_mlx *mlx)
{
	mlx_loop_end(mlx->p_mlx);
	mlx_destroy_image(mlx->p_mlx, mlx->image);
	free_all(mlx);
	exit(0);
	return (0);
}

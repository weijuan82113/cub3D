/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:24:11 by kitsuki           #+#    #+#             */
/*   Updated: 2023/11/05 12:27:38 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_draw_util.h"

int	clear(t_mlx *mlx)
{
	mlx_loop_end(mlx->p_mlx);
	mlx_destroy_image(mlx->p_mlx, mlx->image);
	mlx_destroy_window(mlx->p_mlx, mlx->p_win);
	mlx_destroy_display(mlx->p_mlx);
	exit(0);
	return (0);
}

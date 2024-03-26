/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:24:11 by kitsuki           #+#    #+#             */
/*   Updated: 2024/02/08 21:33:13 by wchen            ###   ########.fr       */
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

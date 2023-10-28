/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:44:38 by wchen             #+#    #+#             */
/*   Updated: 2023/10/28 20:52:27 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool line_check(char* line, t_mlx *mlx, int *x, int *y)
{

	if (mlx->g->t_count < identifier_amount && ft_isstrempty(line) == 0)
		return (identifier_judge(mlx, line));
	else if (mlx->g->t_count == identifier_amount)
		return (line_judge(mlx->g, line, x, y));
	return (false);
}
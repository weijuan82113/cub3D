/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:44:38 by wchen             #+#    #+#             */
/*   Updated: 2023/11/09 23:03:12 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	line_check(char *line, t_mlx *mlx, int *x, int *y)
{
	if (mlx->g->t_count < IDENTIFIER_NUM && ft_isstrempty(line) == 0)
		return (identifier_judge(mlx, line));
	else if (mlx->g->t_count == IDENTIFIER_NUM)
	{
		bool f = line_judge(mlx->g, line, x, y);
		return (f);
	}
	return (false);
}

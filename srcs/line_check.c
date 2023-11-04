/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:44:38 by wchen             #+#    #+#             */
/*   Updated: 2023/11/04 00:12:59 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	line_check(char *line, t_mlx *mlx, int *x, int *y)
{
	if (mlx->g->t_count < IDENTIFIER_NUM && ft_isstrempty(line) == 0)
		return (identifier_judge(mlx, line));
	else if (mlx->g->t_count == IDENTIFIER_NUM)
		return (line_judge(mlx->g, line, x, y));
	return (false);
}

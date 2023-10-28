/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:44:38 by wchen             #+#    #+#             */
/*   Updated: 2023/10/28 19:17:37 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool line_check(char* line, t_mlx *mlx)
{

	if (mlx->g->t_count < identifier_amount && ft_isstrempty(line) == 0)
		return (identifier_judge(mlx, line));
	else if (mlx->g->t_count == identifier_amount)
		return (line_judge(mlx->g, line));
	return (false);
}
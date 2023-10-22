/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:44:38 by wchen             #+#    #+#             */
/*   Updated: 2023/10/22 22:35:40 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool line_check(char* line, t_g_board *g_board)
{
	//printf("t_count:%d\n", g_board->t_count);
	//printf("ft_isstrempty:%d\n", ft_isstrempty(line));
	if (g_board->t_count < 6 && ft_isstrempty(line) == 0)
		return (identifier_judge(g_board, line));
	else if (g_board->t_count == 6)
		return (line_judge(g_board, line));
	return (false);
}
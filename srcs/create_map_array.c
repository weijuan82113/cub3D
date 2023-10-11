/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:46:27 by wchen             #+#    #+#             */
/*   Updated: 2023/10/11 21:05:35 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool create_map_array(t_g_board *g_board)
{
	if(g_board->m_info->h < 3 || g_board->m_info->w < 3)
		return (ft_error(MAP_SIZE_ERR));
	return (false);
}
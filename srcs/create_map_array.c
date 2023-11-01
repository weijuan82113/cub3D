/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:46:27 by wchen             #+#    #+#             */
/*   Updated: 2023/11/01 22:17:44 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_the_map_array(char *content, char *map, int w)
{
	int	i;

	i = 0;
	while (i < w && content[i] && content[i] != '\n')
	{
		map[i] = content[i];
		i++;
	}
	while (i < w)
	{
		map[i] = ' ';
		i++;
	}
}

bool	initial_map_array(t_g_board *g)
{
	t_node	*temp_node;
	int		i;

	g->m_info->map = malloc(sizeof(char *) * (*g->m_info->h + 1));
	if (!g->m_info->map)
		return (false);
	i = 0;
	temp_node = g->line_lst;
	while (temp_node)
	{
		g->m_info->map[i] = malloc(sizeof(char) * (*g->m_info->w + 1));
		if (!g->m_info->map[i])
			return (false);
		fill_the_map_array(temp_node->content, g->m_info->map[i],
			*g->m_info->w);
		temp_node = temp_node->next;
		i++;
	}
	g->m_info->map[i] = NULL;
	return (true);
}

bool	map_check(t_g_board *g_board)
{
	if (wall_check(g_board->line_lst, *g_board->m_info->h))
		return (ft_error(WALL_ERR));
	if (!initial_map_array(g_board))
		return (ft_error(INITIAL_MAP_ERR));
	//debug_print_map_array(g_board->m_info->map);
	if (wall_bfs_check(g_board))
		return (true);
	return (false);
}

bool	create_map_array(t_g_board *g_board)
{
	if (*g_board->m_info->h < 3 || *g_board->m_info->w < 3)
		return (ft_error(MAP_SIZE_ERR));
	if (map_check(g_board))
		return (true);
	return (false);
}
